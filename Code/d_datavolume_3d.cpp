#include "d_datavolume_3d.h"

D_DataVolume_3D::D_DataVolume_3D()
{

}

bool D_DataVolume_3D::init_VolumeSize(size_t sz, size_t sy, size_t sx)
{
    vvvvData_ZYXI.clear();
    vvvvData_ZYXI.resize(
                sz, vector<vector<vector<double>>>(
                    sy, vector<vector<double>>(
                        sx)));

    return true;
}

bool D_DataVolume_3D::add_Value(size_t z, size_t y, size_t x, double value)
{
    if(z < vvvvData_ZYXI.size())        return false;
    if(y < vvvvData_ZYXI[z].size())     return false;
    if(x < vvvvData_ZYXI[z][y].size())  return false;

    vvvvData_ZYXI[z][y][x].push_back(value);
    return true;
}

bool D_DataVolume_3D::add_Values(size_t z, size_t y, size_t x, vector<double> v_values)
{
    if(z < vvvvData_ZYXI.size())        return false;
    if(y < vvvvData_ZYXI[z].size())     return false;
    if(x < vvvvData_ZYXI[z][y].size())  return false;

    vvvvData_ZYXI[z][y][x].insert(
                vvvvData_ZYXI[z][y][x].end(),
                v_values.begin(),
                v_values.end());

    return true;
}

double D_DataVolume_3D::get_Value(size_t z, size_t y, size_t x, size_t i)
{
    if(z < vvvvData_ZYXI.size())            return false;
    if(y < vvvvData_ZYXI[z].size())         return false;
    if(x < vvvvData_ZYXI[z][y].size())      return false;
    if(i < vvvvData_ZYXI[z][y][x].size())   return false;

    return vvvvData_ZYXI[z][y][x][i];
}

vector<double> D_DataVolume_3D::get_Values(size_t z, size_t y, size_t x)
{
    if(z < vvvvData_ZYXI.size())            return vector<double>();
    if(y < vvvvData_ZYXI[z].size())         return vector<double>();
    if(x < vvvvData_ZYXI[z][y].size())      return vector<double>();

    return vvvvData_ZYXI[z][y][x];
}

/*!
 * \brief D_DataVolume_3D::calc_stats reduces the data volume to a D_VisDat_Obj where the px values describe the stat in the mask area
 * \param pVD_Out locally calculated stats
 * \param stat stat to use for calc
 * \param linear true: linear statistics, false: circular statistics
 * \param mask_size mask size to calc stats for (negative indices induce a full range calculation. In this case the resulting VD's size in this dim is 1)
 * \param default_value value to use when there are not enough values in range to perform a calculation
 * \param min_elements_thres min numbero of values in range to perform a calculation
 * \return error code
 */
int D_DataVolume_3D::calc_stats(D_VisDat_Obj *pVD_Out, size_t stat, bool linear, Point3i mask_size, double default_value, int min_elements_thres)
{
    //errors
    qDebug() << "D_DataVolume_3D::calc_stats" << "errors";
    if(linear && stat >= c_STAT_NUMBER_OF_STATS)    return ER_index_out_of_range;
    if(!linear && stat >= c_STAT_CIRC_NUMBER_OF)    return ER_index_out_of_range;

    //sizes
    qDebug() << "D_DataVolume_3D::calc_stats" << "sizes";
    int nz = int(vvvvData_ZYXI.size());
    if(nz <= 0)                                     return ER_empty;
    int ny = int(vvvvData_ZYXI[0].size());
    if(ny <= 0)                                     return ER_empty;
    int nx = int(vvvvData_ZYXI[0][0].size());
    if(nx <= 0)                                     return ER_empty;

    //calc all elements in dim?
    qDebug() << "D_DataVolume_3D::calc_stats" << "full range?";
    bool fz = mask_size.z <= 0;
    bool fy = mask_size.y <= 0;
    bool fx = mask_size.x <= 0;

    //stat function
    qDebug() << "D_DataVolume_3D::calc_stats" << "stat function";
    function<double (vector<double>)> F_stat = linear ? D_Stat::Function_SingleStat(int(stat)) : D_Stat::Function_SingleStat_Circ_Rad(int(stat));

    //create VD
    qDebug() << "D_DataVolume_3D::calc_stats" << "create VD";
    D_VisDat_Dim Dim(
                fx ? 1 : nx,
                fy ? 1 : ny,
                fz ? 1 : nz,
                1,
                1,
                1);
    *pVD_Out = D_VisDat_Obj(Dim, CV_64FC1, default_value);
    qDebug() << "D_DataVolume_3D::calc_stats" << "VD:" << pVD_Out->info();

    //find max extended dim to thread in
    qDebug() << "D_DataVolume_3D::calc_stats" << "find thread dim";
    int thread_dim = c_DIM_Z;

    if(!fx)
        if(nx > ny || fy)
            if(nx > nz || fz)
                thread_dim = c_DIM_X;

    if(!fy)
        if(ny > nx || fx)
            if(ny > nz || fz)
                thread_dim = c_DIM_Y;

    int n_size_in_thread_dim = Dim.size_Dim(thread_dim);
    int n_thread = fz && fy && fx ? 1 : cv::getNumberOfCPUs();
    qDebug() << "D_DataVolume_3D::calc_stats" << "thread dim" << QSL_DimIndices[thread_dim] << "size in dim" << n_size_in_thread_dim << "threads" << n_thread;

    //create threads
    qDebug() << "D_DataVolume_3D::calc_stats" << "create and start threads";
    vector<thread> vThreads(n_thread);
    for(int t = 0; t < n_thread; t++)
    {
        //thread borders
        int i_start  = (((t    ) / static_cast<double>(n_thread))) * n_size_in_thread_dim;
        int i_end    = (((t + 1) / static_cast<double>(n_thread))) * n_size_in_thread_dim;
        Point3i P_start = (thread_dim == c_DIM_X) ? Point3i(i_start, 0 , 0 ) : (thread_dim == c_DIM_Y ? Point3i(0 , i_start, 0 ) : Point3i(0 , 0 , i_start));
        Point3i P_end   = (thread_dim == c_DIM_X) ? Point3i(i_end  , ny, nz) : (thread_dim == c_DIM_Y ? Point3i(nx, i_end  , nz) : Point3i(nx, ny, i_end  ));

        //start thread
        qDebug() << "D_DataVolume_3D::calc_stats" << "start thread" << t << "from" << P_start.x << P_start.y << P_start.z << "to" << P_end.x << P_end.y << P_end.z;
        vThreads[t] = thread(
                    calc_stats_thread,
                    pVD_Out,
                    &vvvvData_ZYXI,
                    F_stat,
                    min_elements_thres,
                    mask_size,
                    P_start,
                    P_end);
    }

    //synch threads
    qDebug() << "D_DataVolume_3D::calc_stats" << "synch threads";
    for(int t = 0; t < n_thread; t++)
    {
        vThreads[t].join();
    }

    qDebug() << "D_DataVolume_3D::calc_stats" << "finished";
    return ER_okay;
}

bool D_DataVolume_3D::calc_stats_thread(D_VisDat_Obj *pVD_StatOut, vector<vector<vector<vector<double> > > > *pvvvvDataIn_ZYXI, function<double (vector<double>)> F_stat, size_t min_elements_thres, Point3i mask_size, Point3i P_start, Point3i P_end)
{
    //volume size
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "sizes";
    int nz = int(pvvvvDataIn_ZYXI->size());
    if(nz <= 0)                                     return false;
    int ny = int((*pvvvvDataIn_ZYXI)[0].size());
    if(ny <= 0)                                     return false;
    int nx = int((*pvvvvDataIn_ZYXI)[0][0].size());
    if(nx <= 0)                                     return false;

    //range
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "range";
    int z0 = P_start.z;
    int y0 = P_start.y;
    int x0 = P_start.x;
    int z1 = P_end.z;
    int y1 = P_end.y;
    int x1 = P_end.x;
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "range" << x0 << y0 << z0 << "to" << x1 << y1 << z1;

    //mask size
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "mask size";
    int mz = mask_size.z;
    int my = mask_size.y;
    int mx = mask_size.x;
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "mask size" << mx << my << mz;

    //calc all elements in dim?
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "full size?";
    bool fz = mz <= 0;
    bool fy = my <= 0;
    bool fx = mx <= 0;
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "full size" << fx << fy << fz;

    //corrections if full dim calc
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "size and range correction";
    if(fz)  {mz = 2 * nz;   z0 = 0; z1 = 1;}
    if(fy)  {my = 2 * nx;   y0 = 0; y1 = 1;}
    if(fx)  {mx = 2 * ny;   x0 = 0; x1 = 1;}
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "mask size" << mx << my << mz << "from" << x0 << y0 << z0 << "to" << x1 << y1 << z1;

    //mask offset
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "mask offset";
    int oz = mz / 2;
    int oy = my / 2;
    int ox = mx / 2;
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "mask offset" << ox << oy << oz;


    //loop thread range
    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "loop range";
    for(int z = z0; z < z1; z++)
    {
        for(int y = y0; y < y1; y++)
        {
            for(int x = x0; x < x1; x++)
            {
                //vector of values in range
                vector<double> vVal;

                //loop mask range
                for(int zi = max(0, z - oz); zi < min(nz - 1, z + oz); zi++)
                {
                    for(int yi = max(0, y - oy); yi < min(ny - 1, y + oy); yi++)
                    {
                        for(int xi = max(0, x - ox); xi < min(nx - 1, x + ox); xi++)
                        {
                            //insert values in range
                            if(!(*pvvvvDataIn_ZYXI)[zi][yi][xi].empty())
                            {
                                vVal.insert(
                                            vVal.end(),
                                            (*pvvvvDataIn_ZYXI)[zi][yi][xi].begin(),
                                            (*pvvvvDataIn_ZYXI)[zi][yi][xi].end());
                            }
                        }
                    }
                }

                //enough values detected?
                if(vVal.size() >= min_elements_thres)
                {
                    Vec<int, c_DIM_NUMBER_OF> pos_out{x, y, z, 0, 0, 0};
                    pVD_StatOut->pMA_full()->at<double>(pos_out) = F_stat(vVal);
                }
            }
        }
    }

    qDebug() << "D_DataVolume_3D::calc_stats_thread" << "thread end";
    return true;
}
