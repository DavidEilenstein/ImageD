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

D_VisDat_Obj D_DataVolume_3D::calc_stats(size_t stat, bool linear, Point3i mask_size, double default_value, int min_elements)
{
    if(linear && stat >= c_STAT_NUMBER_OF_STATS)    return D_VisDat_Obj();
    if(!linear && stat >= c_STAT_CIRC_NUMBER_OF)    return D_VisDat_Obj();

    function<double (vector<double>)> F_stat = linear ? D_Stat::Function_SingleStat(stat) : D_Stat::Function_SingleStat_Circ_Rad(stat);

    //CONTINUE HERE

    return true;
}

bool D_DataVolume_3D::calc_stats_thread(vector<vector<vector<vector<double> > > > *pvvvvDataIn_ZYXI, D_VisDat_Obj *pVD_StatOut, function<double (vector<double>)> F_stat, Point3i mask_size, Point3i P_start, Point3i P_end)
{

    return true;
}
