#include "d_viewer_plot_3d.h"

D_Viewer_Plot_3D::D_Viewer_Plot_3D()
{

}

D_Viewer_Plot_3D::D_Viewer_Plot_3D(QGridLayout *target_layout)
{
    init(target_layout);
}

D_Viewer_Plot_3D::~D_Viewer_Plot_3D()
{
    clear_layout();
}

int D_Viewer_Plot_3D::init(QGridLayout *target_layout)
{
    //qDebug() << "init" << "start";

    if(state_ui_init)
    {
        //qDebug() << "init" << "state_ui_init allready";
        ERR(ER_other, "init_ui", "Graph was put in ui before");
        return ER_UiAllreadyInit;
    }

    //save pointer to ui layout
    //qDebug() << "init" << "save layout pointer";
    layout_in_ui = target_layout;

    //init scatter plot
    //qDebug() << "init" << "scatter";
    graph_scatter = new Q3DScatter();
    container_widget_scatter = createWindowContainer(graph_scatter);
    //container_widget_scatter->setVisible(true);
    layout_in_ui->addWidget(container_widget_scatter, c_VIEWER_PLOT_3D_MODE_SCATTER, 0);
    graph_scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFrontHigh);

    //init heightmap plot
    //qDebug() << "init" << "heightmap";
    graph_heightmap = new Q3DSurface();
    container_widget_heightmap = createWindowContainer(graph_heightmap);
    //container_widget_heightmap->setVisible(false);
    layout_in_ui->addWidget(container_widget_heightmap, c_VIEWER_PLOT_3D_MODE_HEIGHTMAP, 0);
    graph_heightmap->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFrontHigh);

    //finish
    //qDebug() << "init" << "finish";
    state_ui_init = true;
    return ER_okay;
}

void D_Viewer_Plot_3D::clear_graph_all()
{
    clear_graph_scatter();
    clear_graph_heightmap();
}

void D_Viewer_Plot_3D::clear_graph_scatter()
{
    while(!graph_scatter->seriesList().isEmpty())
    {
        QScatter3DSeries *series = graph_scatter->seriesList().at(0);
        graph_scatter->removeSeries(series);
        series->dataProxy()->deleteLater();
        series->deleteLater();
    }
}

void D_Viewer_Plot_3D::clear_graph_heightmap()
{
    while(!graph_heightmap->seriesList().isEmpty())
    {
        QSurface3DSeries *series = graph_heightmap->seriesList().at(0);
        graph_heightmap->removeSeries(series);
        series->dataProxy()->deleteLater();
        series->deleteLater();
    }
}

bool D_Viewer_Plot_3D::save(QString QS_Save)
{
    if(container_widget_scatter != nullptr)
        if(container_widget_scatter->isVisible())
            return graph_scatter->renderToImage(4).save(QS_Save);

    if(container_widget_heightmap != nullptr)
        if(container_widget_heightmap->isVisible())
            return graph_heightmap->renderToImage(4).save(QS_Save);

    return false;
}

int D_Viewer_Plot_3D::plot_VD_custom(D_VisDat_Obj *pVD, size_t mode, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v, size_t plane_index_xy, size_t dim_index_surfaces, size_t surface_mode, size_t texture_mode, size_t marker, size_t shadow, bool background, bool grid, bool smooth, bool draw_surface, bool draw_wireframe)
{
    /*
    qDebug() << "D_Viewer_Plot_3D::plot_VD_custom" << "params:";
    qDebug() << "mode" << mode << QSL_Viewer3D_Mode[mode];
    qDebug() << "cond" << cond << QSL_Viewer3D_Condition[cond];
    qDebug() << "val_handle" << val_handle << QSL_Viewer3D_ValueHandling[val_handle];
    qDebug() << "axis_x" << axis_x << QSL_Viewer3D_Axis[axis_x];
    qDebug() << "axis_y" << axis_y << QSL_Viewer3D_Axis[axis_y];
    qDebug() << "axis_z" << axis_z << QSL_Viewer3D_Axis[axis_z];
    qDebug() << "axis_v" << axis_v << QSL_Viewer3D_Axis[axis_v];
    qDebug() << "plane_index_xy" << plane_index_xy << QSL_Planes[plane_index_xy];
    qDebug() << "dim_index_surfaces" << dim_index_surfaces << QSL_DimIndices[dim_index_surfaces];
    qDebug() << "surface_mode" << surface_mode << QSL_Viewer_3D_SurfaceMode[surface_mode];
    qDebug() << "texture_mode" << texture_mode << QSL_Viewer3D_Texture[texture_mode];
    qDebug() << "marker" << marker << QSL_Marker_3D[marker];
    qDebug() << "shadow" << shadow << QSL_ShadowQuality_3D[shadow];
    qDebug() << "background" << background;
    qDebug() << "grid" << grid;
    qDebug() << "smooth" << smooth;
    */

    switch (mode)
    {

    case c_VIEWER_PLOT_3D_MODE_SCATTER:
        return plot_VD_Scatter(
                    pVD,
                    cond,
                    val_handle,
                    axis_x,
                    axis_y,
                    axis_z,
                    axis_v,
                    marker,
                    shadow,
                    background,
                    grid,
                    smooth,
                    true);

    case c_VIEWER_PLOT_3D_MODE_HEIGHTMAP:
        return plot_VD_Heightmap(
                    pVD,
                    plane_index_xy,
                    dim_index_surfaces,
                    axis_z,
                    axis_v,
                    surface_mode,
                    texture_mode,
                    shadow,
                    background,
                    grid,
                    draw_surface,
                    draw_wireframe,
                    true);

    default:
        return ER_parameter_bad;
    }
}

int D_Viewer_Plot_3D::plot_VD_Scatter(D_VisDat_Obj *pVD, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v, size_t marker, size_t shadow, bool background, bool grid, bool smooth, bool called_internally)
{
    //empty?
    if(pVD->pMA_full()->empty())            return ER_empty;

    //avoid thread issues
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //dimension
    D_VisDat_Dim dim = pVD->Dim();

    //data needed
    vector<vector<double>> vvData(4);//x, y, z, v

    //axis involved
    vector<size_t>  vAxis = {axis_x, axis_y, axis_z, axis_v};

    //check axis index valid
    for(size_t i = 0; i < vAxis.size(); i++)
        if(vAxis[i] >= c_VIEWER_PLOT_3D_AXIS_NUMBER_OF)
        {
            qDebug() << "D_Viewer_Plot_3D::plot_VD_custom" << "axis index" << i << "witth value" << vAxis[i] << "is invalid";
            state_plotting = false;
            return ER_parameter_bad;
        }

    //check channels
    for(size_t i = 0; i < vAxis.size(); i++)
        switch (vAxis[i]) {
        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_1:  if(pVD->channels() < 2) {state_plotting = false;    return ER_channel_missmatch;}   break;
        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_2:  if(pVD->channels() < 3) {state_plotting = false;    return ER_channel_missmatch;}   break;
        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_3:  if(pVD->channels() < 4) {state_plotting = false;    return ER_channel_missmatch;}   break;
        default:                                                                                                                break;}

    //Loop VD
    dim.loop_Reset();
    while(dim.loop_Next())
    {
        //posisition
        Vec<int, c_DIM_NUMBER_OF> pos = dim.loop_PosCurrent();

        //value at position
        vector<double> val = pVD->at(pos);

        //condition
        bool use_this_pixel = false;
        switch (cond)
        {

        case c_VIEWER_PLOT_3D_CONDITION_ALL:
            use_this_pixel = true;
            break;

        case c_VIEWER_PLOT_3D_CONDITION_NOT_ZERO:
            for(size_t ch = 0; ch < val.size() && !use_this_pixel; ch++)
                if(val[ch] != 0.0)
                    use_this_pixel = true;
            break;

        default:
            qDebug() << "D_Viewer_Plot_3D::plot_VD_custom" << "condition with index" << cond << "is invalid";
            state_plotting = false;
            return ER_parameter_bad;
        }

        //add data
        if(use_this_pixel)
            for(size_t i = 0; i < vAxis.size(); i++)
                switch (vAxis[i]) {
                case c_VIEWER_PLOT_3D_AXIS_EMPTY:      vvData[i].push_back(0);                 break;
                case c_VIEWER_PLOT_3D_AXIS_IMG_X:      vvData[i].push_back(pos[c_DIM_X]);      break;
                case c_VIEWER_PLOT_3D_AXIS_IMG_Y:      vvData[i].push_back(pos[c_DIM_Y]);      break;
                case c_VIEWER_PLOT_3D_AXIS_IMG_Z:      vvData[i].push_back(pos[c_DIM_Z]);      break;
                case c_VIEWER_PLOT_3D_AXIS_IMG_T:      vvData[i].push_back(pos[c_DIM_T]);      break;
                case c_VIEWER_PLOT_3D_AXIS_IMG_S:      vvData[i].push_back(pos[c_DIM_S]);      break;
                case c_VIEWER_PLOT_3D_AXIS_IMG_P:      vvData[i].push_back(pos[c_DIM_P]);      break;
                case c_VIEWER_PLOT_3D_AXIS_CHANNEL_0:  vvData[i].push_back(val[0]);            break;
                case c_VIEWER_PLOT_3D_AXIS_CHANNEL_1:  vvData[i].push_back(val[1]);            break;
                case c_VIEWER_PLOT_3D_AXIS_CHANNEL_2:  vvData[i].push_back(val[2]);            break;
                case c_VIEWER_PLOT_3D_AXIS_CHANNEL_3:  vvData[i].push_back(val[3]);            break;
                default:                            state_plotting = false;                 return ER_parameter_bad;}
    }

    //plot
    return plot_ScatterData_Color(
            vvData[0],
            vvData[1],
            vvData[2],
            vvData[3],
            val_handle,
            marker,
            shadow,
            background,
            grid,
            smooth,
            QSL_Viewer3D_Axis[static_cast<int>(axis_x)],
            QSL_Viewer3D_Axis[static_cast<int>(axis_y)],
            QSL_Viewer3D_Axis[static_cast<int>(axis_z)],
            QSL_Viewer3D_Axis[static_cast<int>(axis_v)],
            true);
}

int D_Viewer_Plot_3D::plot_VD_Heightmap(D_VisDat_Obj *pVD, size_t plane_index_xy, size_t dim_index_surfaces, size_t axis_z, size_t axis_v, size_t surface_mode, size_t texture_mode, size_t shadow, bool background, bool grid, bool draw_surface, bool draw_wireframe, bool called_internally)
{
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "start";

    //errors 1
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "errors 1";
    if(plane_index_xy >= c_PLANE_NUMBER_OF)                                                                 return ER_parameter_bad;

    //plane dims
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "plane dims";
    size_t dim_index_x = D_VisDat_Proc::PlaneDim_1st(plane_index_xy);
    size_t dim_index_y = D_VisDat_Proc::PlaneDim_2nd(plane_index_xy);

    //errors 2
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "errors 2";
    if(surface_mode == c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION && (dim_index_surfaces == dim_index_x))      return ER_dim_missmatch;
    if(surface_mode == c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION && (dim_index_surfaces == dim_index_y))      return ER_dim_missmatch;


    //avoid thread issues
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "thread check";
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //series count
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "image count";
    size_t n;
    switch(surface_mode) {
    case c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE:          n = 1;                                          break;
    case c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS:        n = pVD->channels();                            break;
    case c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION:       n = pVD->pDim()->size_Dim(dim_index_surfaces);  break;
    default:                                            state_plotting = false;                         return ER_parameter_bad;}

    //heightmats & texture images
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "img containers";
    vector<Mat> vMA_Heights(n);
    //vector<Mat> vMA_Textures(n);
    vector<QImage> vQI_Textures(n);

    //surface modi
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "surface mode switch";
    switch (surface_mode)
    {

    case c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE:
    {
        //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE";

        //pos
        Vec<int, c_DIM_NUMBER_OF> slice_pos = {0, 0, 0, 0, 0, 0};
        slice_pos[dim_index_x] = -1;
        slice_pos[dim_index_y] = -1;

        //get slice
        Mat MA_tmp_slice2D;
        int err = D_VisDat_Proc::Read_2D_Plane(
                    &MA_tmp_slice2D,
                    pVD,
                    D_VisDat_Slice_2D(slice_pos));
        if(err != ER_okay)
        {
            qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE" << "D_VisDat_Proc::Read_2D_Plane";
            MA_tmp_slice2D.release();
            state_plotting = false;
            return err;
        }

        //calc heights
        err = ValueAxisMat(
                &(vMA_Heights[0]),
                &MA_tmp_slice2D,
                axis_z,
                slice_pos,
                0);
        if(err != ER_okay)
        {
            qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE" << "ValueAxisMat";
            MA_tmp_slice2D.release();
            state_plotting = false;
            return err;
        }


        //calc texture
        err = SurfaceTextureImage(
                &(vQI_Textures[0]),
                &MA_tmp_slice2D,
                texture_mode,
                axis_v,
                slice_pos,
                0);
        MA_tmp_slice2D.release();
        if(err != ER_okay)
        {
            qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE" << "SurfaceTextureImage";
            state_plotting = false;
            return err;
        }
    }
        break;

    case c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS:
    {
        //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS";

        //pos
        Vec<int, c_DIM_NUMBER_OF> slice_pos = {0, 0, 0, 0, 0, 0};
        slice_pos[dim_index_x] = -1;
        slice_pos[dim_index_y] = -1;

        //get slice
        Mat MA_tmp_slice2D;
        int err = D_VisDat_Proc::Read_2D_Plane(
                    &MA_tmp_slice2D,
                    pVD,
                    D_VisDat_Slice_2D(slice_pos));
        if(err != ER_okay)
        {
            qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS" << "D_VisDat_Proc::Read_2D_Plane";
            MA_tmp_slice2D.release();
            state_plotting = false;
            return err;
        }

        //loop channels
        for(int ch = 0; ch < MA_tmp_slice2D.channels(); ch++)
        {
            //height
            err = D_Img_Proc::Split(
                        &(vMA_Heights[ch]),
                        &MA_tmp_slice2D,
                        ch);
            if(err != ER_okay)
            {
                qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS" << "D_Img_Proc::Split";
                MA_tmp_slice2D.release();
                state_plotting = false;
                return err;
            }

            //texture
            vQI_Textures[ch] = QImage(MA_tmp_slice2D.cols, MA_tmp_slice2D.rows, QImage::Format_RGBA8888);
            switch (ch) {
            case 0:     vQI_Textures[ch].fill(Qt::blue);    break;
            case 1:     vQI_Textures[ch].fill(Qt::green);   break;
            case 2:     vQI_Textures[ch].fill(Qt::red);     break;
            case 3:     vQI_Textures[ch].fill(Qt::gray);    break;
            default:    vQI_Textures[ch].fill(Qt::black);   break;}
        }
    }
        break;

    case c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION:
    {
        //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION";

        //dim of vis dat
        D_VisDat_Dim dim = pVD->Dim();

        //loop surface dim
        for(size_t i = 0; i < n; i++)
        {
            //pos
            Vec<int, c_DIM_NUMBER_OF> slice_pos = {0, 0, 0, 0, 0, 0};
            slice_pos[int(dim_index_x)]         = -1;
            slice_pos[int(dim_index_y)]         = -1;
            slice_pos[int(dim_index_surfaces)]  = int(i);

            //get slice
            Mat MA_tmp_slice2D;
            int err = D_VisDat_Proc::Read_2D_Plane(
                        &MA_tmp_slice2D,
                        pVD,
                        D_VisDat_Slice_2D(slice_pos));
            if(err != ER_okay)
            {
                qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION" << "D_VisDat_Proc::Read_2D_Plane";
                MA_tmp_slice2D.release();
                state_plotting = false;
                return err;
            }

            //calc heights
            err = ValueAxisMat(
                    &(vMA_Heights[i]),
                    &MA_tmp_slice2D,
                    axis_z,
                    slice_pos,
                    0);
            if(err != ER_okay)
            {
                qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION" << "ValueAxisMat";
                MA_tmp_slice2D.release();
                state_plotting = false;
                return err;
            }

            //check if, texture is an image wide constant value because it is a dim index or if needs to be calced pixelwise
            bool texture_easy_because_fix_dim = false;
            if(texture_mode == c_VIEWER_PLOT_3D_TEXTURE_GRAY || texture_mode == c_VIEWER_PLOT_3D_TEXTURE_HUE)
                if(slice_pos[dimIndex_FromAxisIndex(axis_v)] >= 0)
                    texture_easy_because_fix_dim = true;

            //calc texture
            if(texture_easy_because_fix_dim)
            {
                //init img
                vQI_Textures[i] = QImage(MA_tmp_slice2D.cols, MA_tmp_slice2D.rows, QImage::Format_RGBA8888);

                //dim index relative
                double dim_index_rel = (n <= 1) ? (0) : (double(i) / (n-1));

                //check texture mode and calc color
                QColor color;
                if(texture_mode == c_VIEWER_PLOT_3D_TEXTURE_GRAY)
                    color.setRgb(uchar(dim_index_rel * 255), uchar(dim_index_rel * 255), uchar(dim_index_rel * 255));
                else
                    color.setHsv(uchar(dim_index_rel * 240), 255, 255);
                vQI_Textures[i].fill(color);
            }
            else
            {
                err = SurfaceTextureImage(
                        &(vQI_Textures[i]),
                        &MA_tmp_slice2D,
                        texture_mode,
                        axis_v,
                        slice_pos,
                        0);
                MA_tmp_slice2D.release();
                if(err != ER_okay)
                {
                    qDebug() << "plot_VD_Heightmap" << "c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION" << "SurfaceTextureImage";
                    state_plotting = false;
                    return err;
                }
            }
        }
    }
        break;

    default:
        qDebug() << "plot_VD_Heightmap" << "surface mode not supported";
        state_ui_init = false;
        return ER_parameter_bad;
    }

    //plot
    //qDebug() << "D_Viewer_Plot_3D::plot_VD_Heightmap" << "plot";
    return plot_Heightmap(
                &vMA_Heights,
                &vQI_Textures,
                shadow,
                background,
                grid,
                QSL_DimIndices[dim_index_x],
                QSL_DimIndices[dim_index_y],
                QSL_Viewer3D_Axis[axis_z],
                draw_surface,
                draw_wireframe,
                true);
}

int D_Viewer_Plot_3D::plot_Heatmap(vector<double> vData_X, double min_x, double max_x, bool auto_range_x, size_t classes_x, QString name_x, vector<double> vData_Y, double min_y, double max_y, bool auto_range_y, size_t classes_y, QString name_y, vector<double> vData_Z, size_t stat_z, QString name_z, bool draw_height, bool draw_wireframe, bool man_axis_style_x, bool man_axis_style_y, bool man_axis_style_z, double man_min_x, double man_max_x, double man_min_y, double man_max_y, double man_min_z, double man_max_z, bool called_internally)
{
    //---------------------------------------------------------- errors

    //errors
    if(vData_X.empty())                             return ER_empty;
    if(vData_Y.empty())                             return ER_empty;
    if(vData_Z.empty())                             return ER_empty;
    if(vData_X.size() != vData_Y.size())            return ER_size_missmatch;
    if(vData_X.size() != vData_Z.size())            return ER_size_missmatch;
    if(min_x >= max_x)                              return ER_parameter_missmatch;
    if(min_y >= max_y)                              return ER_parameter_missmatch;
    if(classes_x <= 1)                              return ER_parameter_bad;
    if(classes_y <= 1)                              return ER_parameter_bad;
    if(stat_z >= c_STAT_NUMBER_OF_STATS)            return ER_index_out_of_range;

    //avoid thread issues
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //---------------------------------------------------------- size and scale

    //sizes
    size_t n_data = vData_X.size();
    size_t n_x = classes_x;
    size_t n_y = classes_y;
    //qDebug() << "size data/x/y" << n_data << n_x << n_y;

    //calc min/max x/y
    if(auto_range_x)
    {
        min_x = INFINITY;
        max_x = -INFINITY;
        for(size_t i = 0; i < n_data; i++)
        {
            double val = vData_X[i];
            if(val < min_x)     min_x = val;
            if(val > max_x)     max_x = val;
        }
    }

    if(auto_range_y)
    {
        min_y = INFINITY;
        max_y = -INFINITY;
        for(size_t i = 0; i < n_data; i++)
        {
            double val = vData_Y[i];
            if(val < min_y)     min_y = val;
            if(val > max_y)     max_y = val;
        }
    }

    //ranges
    double range_x = max_x - min_x;
    double range_y = max_y - min_y;
    //qDebug() << "min/max x" << min_x << max_x << "min/max y" << min_y << max_y;

    //---------------------------------------------------------- data calculation

    //3D stacked data field
    vector<vector<vector<double>>> vvvData_XYI(n_x, vector<vector<double>>(n_y, vector<double>(0)));

    //pooling
    for(size_t i = 0; i < n_data; i++)
    {
        size_t i_x = D_Stat::Value2PoolIndex(vData_X[i], min_x, range_x, n_x);
        size_t i_y = D_Stat::Value2PoolIndex(vData_Y[i], min_y, range_y, n_y);
        double val = vData_Z[i];

        vvvData_XYI[i_x][i_y].push_back(val);
    }

    //2D data field result
    Mat MA_tmp_value = Mat::zeros(n_y, n_x, CV_64FC1);

    //calc stat
    function<double (vector<double>)> F_Stat = D_Stat::Function_SingleStat(int(stat_z));
    for(size_t x = 0; x < n_x; x++)
        for(size_t y = 0; y < n_y; y++)
            if(!vvvData_XYI[x][y].empty())
            {
                //qDebug() << "x/y/val" << y << x << F_Stat(vvvData_XYI[x][y]);
                MA_tmp_value.at<double>(y, x) = F_Stat(vvvData_XYI[x][y]);
            }


    //---------------------------------------------------------- surface

    //clear old content
    clear_graph_all();

    //show correct graph
    show_graph_type(c_VIEWER_PLOT_3D_MODE_HEIGHTMAP);

    //series
    QSurface3DSeries* pSeries;

    //create series
    pSeries = new QSurface3DSeries();//(texture_proxy);

    //loop rows
    for(size_t y = 0; y < n_y; y++)
    {
        //new row
        QSurfaceDataRow *Row = new QSurfaceDataRow(n_x);

        //loop cols in row
        for(size_t x = 0; x < n_x; x++)
        {
            double val_x = ((double(x) / double(n_x)) * range_x) + min_x;
            double val_y = ((double(y) / double(n_y)) * range_y) + min_y;
            double val_h = draw_height ? MA_tmp_value.at<double>(y, x) : 0;
            //qDebug() << "x/y/h" << val_x << val_y << val_h;

            (*Row)[x].setPosition(QVector3D(val_x, val_h, val_y));
        }

        //add row to array
        pSeries->dataProxy()->addRow(Row);
    }

    //---------------------------------------------------------- texture

    //texture img
    QImage QI_tmp_texture;

    //calc texture as color heatmap
    Mat MA_tmp_useless_alpha_img = Mat::zeros(MA_tmp_value.size(), CV_8UC1);
    int err = D_Img_Proc::Convert_toQImage4Ch(
                &QI_tmp_texture,
                &MA_tmp_value,
                &MA_tmp_useless_alpha_img,
                true);
    MA_tmp_useless_alpha_img.release();
    if(err != ER_okay)
    {
        MA_tmp_value.release();
        state_plotting = false;
        return err;
    }

    //pixels with no data to light gray
    for(size_t x = 0; x < n_x; x++)
        for(size_t y = 0; y < n_y; y++)
            if(vvvData_XYI[x][y].empty())
                QI_tmp_texture.setPixel(int(x), int(y), qRgb(224, 224, 224));

    //mirror image
    QI_tmp_texture = QI_tmp_texture.mirrored(false, true);

    //scale and set texture
    const int texture_scale = 1;
    QI_tmp_texture = QI_tmp_texture.scaled(QI_tmp_texture.width() * texture_scale, QI_tmp_texture.height() * texture_scale);
    pSeries->setTexture(QI_tmp_texture);

    //draw mode
    if(draw_wireframe)
        pSeries->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    else
        pSeries->setDrawMode(QSurface3DSeries::DrawSurface);

    //add series to graph
    graph_heightmap->addSeries(pSeries);

    //---------------------------------------------------------- axis

    graph_heightmap->axisX()->setTitle(name_x);                                     //default x axis
    graph_heightmap->axisY()->setTitle(QSL_StatList[stat_z] + " of " + name_z);     //graph z axis is img y axis
    graph_heightmap->axisZ()->setTitle(name_y);                                     //graph y axis is img z axis

    graph_heightmap->axisX()->setTitleVisible(true);
    graph_heightmap->axisY()->setTitleVisible(true);
    graph_heightmap->axisZ()->setTitleVisible(true);

    //graph_heightmap->axisX()->setReversed(true);
    //graph_heightmap->axisZ()->setReversed(true);                                    //graph z / img y axis is reversed (0,0 is in the top left of an img)

    graph_heightmap->axisX()->setMin(man_axis_style_x ? man_min_x : min_x);
    graph_heightmap->axisX()->setMax(man_axis_style_x ? man_max_x : max_x);

    graph_heightmap->axisZ()->setMin(man_axis_style_y ? man_min_y : min_y);
    graph_heightmap->axisZ()->setMax(man_axis_style_y ? man_max_y : max_y);

    if(man_axis_style_z)
    {
        graph_heightmap->axisY()->setMin(man_min_z);
        graph_heightmap->axisY()->setMax(man_max_z);
    }

    //---------------------------------------------------------- style

    //style
    graph_heightmap->activeTheme()->setGridEnabled(true);
    graph_heightmap->activeTheme()->setBackgroundEnabled(true);
    graph_heightmap->setShadowQuality(QAbstract3DGraph::ShadowQuality(0));
    graph_heightmap->setReflection(false);

    //graph_heightmap->setAspectRatio(1);
    graph_heightmap->setHorizontalAspectRatio(1);


    //---------------------------------------------------------- show


    MA_tmp_value.release();
    state_plotting = false;
    return ER_okay;
}

int D_Viewer_Plot_3D::plot_ScatterData_Color(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vV, size_t color_handle, size_t marker, size_t shadow, bool background, bool grid, bool smooth, QString axis_x, QString axis_y, QString axis_z, QString axis_v, bool called_internally)
{
    if(!state_ui_init)                                              return ER_UiNotInit;
    if(vX.empty())                                                  return ER_empty;
    if(vX.size() != vY.size())                                      return ER_size_missmatch;
    if(vX.size() != vZ.size())                                      return ER_size_missmatch;
    if(vX.size() != vV.size())                                      return ER_size_missmatch;
    if(color_handle >= c_VIEWER_PLOT_3D_VALUE_HANDLING_NUMBER_OF)   return ER_parameter_bad;

    //avoid thread issues
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //clear old content
    clear_graph_all();

    //show correct graph
    show_graph_type(c_VIEWER_PLOT_3D_MODE_SCATTER);

    //sizes
    size_t n_all = vX.size();
    size_t n_series = series_count_from_color_handle_id(color_handle);
    if(n_series == 0)
    {
        state_plotting = false;
        return ER_parameter_bad;
    }

    //data range for grouping into different series
    double min_v = +INFINITY;
    double max_v = -INFINITY;
    double range_v = 0.0;
    if(n_series > 1)
    {
        for(size_t i = 0; i < n_all; i++)
        {
            double v = vV[i];
            min_v = min(min_v, v);
            max_v = max(max_v, v);
        }
        range_v = max_v - min_v;
    }

    //series
    vector<QScatter3DSeries *>  vSeries(n_series);
    for(size_t i = 0; i < n_series; i++)
    {
        //create series
        vSeries[i] = new QScatter3DSeries;

        //style
        vSeries[i]->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
        vSeries[i]->setMeshSmooth(smooth);
        vSeries[i]->setMesh(marker_from_id(marker));
        vSeries[i]->setBaseColor(series_color(n_series, i, color_handle));

        //series to graph
        graph_scatter->addSeries(vSeries[i]);
    }

    //axis
    graph_scatter->axisX()->setTitle(axis_x);   //default x axis
    graph_scatter->axisY()->setTitle(axis_z);   //graph z axis is img y axis
    graph_scatter->axisZ()->setTitle(axis_y);   //graph y axis is img z axis
    graph_scatter->axisX()->setTitleVisible(true);
    graph_scatter->axisY()->setTitleVisible(true);
    graph_scatter->axisZ()->setTitleVisible(true);
    graph_scatter->axisZ()->setReversed(true);  //graph z / img y axis is reversed (0,0 is in the top left of an img)

    //style
    graph_scatter->activeTheme()->setGridEnabled(grid);
    graph_scatter->activeTheme()->setBackgroundEnabled(background);
    graph_scatter->setShadowQuality(QAbstract3DGraph::ShadowQuality(shadow));

    //data to arrays
    vector<QScatterDataArray> vDataArray(n_series);
    for(size_t i = 0; i < n_all; i++)
    {
        //calc group
        double i_rel = range_v == 0.0 ? 0 : (vV[i] - min_v) / range_v;
        size_t i_group = static_cast<size_t>(i_rel * (n_series - 1));

        //push to group
        vDataArray[i_group].append(
                    QVector3D(
                        static_cast<float>(vX[i]),
                        static_cast<float>(vZ[i]),
                        static_cast<float>(vY[i])));
    }

    //add data to series
    for(size_t s = 0; s < n_series; s++)
        vSeries[s]->dataProxy()->addItems(vDataArray[s]);

    //finish
    state_plot_active = true;
    state_plotting = false;
    return ER_okay;
}

int D_Viewer_Plot_3D::plot_Tree(vector<Point3d> vNodesCoord, vector<Point3d> vEdgeCoordBegins, vector<Point3d> vEdgeCoordEnds, vector<QColor> vNodeColor, vector<QColor> vEdgeColor, size_t shadow, bool background, bool grid, bool smooth, QString axis_x, QString axis_y, QString axis_z, size_t points_per_edge, double size_nodes, double size_edge, bool called_internally)
{
    if(!state_ui_init)                                              return ER_UiNotInit;
    if(vNodesCoord.size() != vNodeColor.size())                     return ER_size_missmatch;
    if(vEdgeCoordBegins.size() != vEdgeCoordEnds.size())            return ER_size_missmatch;
    if(vEdgeCoordBegins.size() != vEdgeColor.size())                return ER_size_missmatch;
    if(points_per_edge <= 0)                                        return ER_parameter_bad;

    //avoid thread issues
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //clear old content
    clear_graph_all();

    //show correct graph
    show_graph_type(c_VIEWER_PLOT_3D_MODE_SCATTER);

    //sizes
    size_t n_nodes = vNodesCoord.size();
    size_t n_edges = vEdgeCoordBegins.size();
    size_t n_points = points_per_edge;
    size_t n_all = n_nodes + n_edges * n_points;
    size_t i_all = 0;

    //scatter data array for saving coords
    vector<QScatterDataArray> vDataArray_Nodes1st_Edges2nd(n_all);

    //series/data of nodes
    vector<QScatter3DSeries*> vSeries_Nodes1st_Edges2nd(n_all);

    //loop nodes
    for(size_t i_node = 0; i_node < n_nodes; i_node++)
    {
        //create series
        vSeries_Nodes1st_Edges2nd[i_all] = new QScatter3DSeries;

        //style
        vSeries_Nodes1st_Edges2nd[i_all]->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @zTitle: @zLabel @yTitle: @yLabel"));
        vSeries_Nodes1st_Edges2nd[i_all]->setMeshSmooth(smooth);
        vSeries_Nodes1st_Edges2nd[i_all]->setMesh(QAbstract3DSeries::Mesh::MeshSphere);
        vSeries_Nodes1st_Edges2nd[i_all]->setBaseColor(vNodeColor[i_node]);
        vSeries_Nodes1st_Edges2nd[i_all]->setItemSize(size_nodes);

        //series to graph
        graph_scatter->addSeries(vSeries_Nodes1st_Edges2nd[i_all]);

        //data
        vDataArray_Nodes1st_Edges2nd[i_all].append(
                    QVector3D(
                        static_cast<float>(vNodesCoord[i_node].x),
                        static_cast<float>(vNodesCoord[i_node].z),
                        static_cast<float>(vNodesCoord[i_node].y)));

        //increment counter
        i_all++;
    }

    //series/data of edges
    for(size_t i_edge = 0; i_edge < n_edges; i_edge++)
    {
        //points describing edge
        Point3d P0 = vEdgeCoordBegins[i_edge];
        Point3d P1 = vEdgeCoordEnds[i_edge];

        //draw points to create a line
        for(size_t i_pt = 0; i_pt < points_per_edge; i_pt++)
        {
            //create series
            vSeries_Nodes1st_Edges2nd[i_all] = new QScatter3DSeries;

            //style
            vSeries_Nodes1st_Edges2nd[i_all]->setItemLabelVisible(false);
            vSeries_Nodes1st_Edges2nd[i_all]->setMeshSmooth(false);
            vSeries_Nodes1st_Edges2nd[i_all]->setMesh(QAbstract3DSeries::Mesh::MeshSphere);
            vSeries_Nodes1st_Edges2nd[i_all]->setBaseColor(vEdgeColor[i_edge]);
            vSeries_Nodes1st_Edges2nd[i_all]->setItemSize(size_edge);

            //series to graph
            graph_scatter->addSeries(vSeries_Nodes1st_Edges2nd[i_all]);

            //data (point on edge)
            double fP0 = (i_pt + 1) / double(points_per_edge + 1.0);
            double fP1 = 1 - fP0;
            Point3d PE(fP0 * P0.x + fP1 * P1.x,
                       fP0 * P0.y + fP1 * P1.y,
                       fP0 * P0.z + fP1 * P1.z);
            vDataArray_Nodes1st_Edges2nd[i_all].append(QVector3D(PE.x, PE.z, PE.y));

            //increment counter
            i_all++;
        }
    }


    //axis
    graph_scatter->axisX()->setTitle(axis_x);       //default x axis
    graph_scatter->axisY()->setTitle(axis_z);       //graph z axis is img y axis
    graph_scatter->axisZ()->setTitle(axis_y);       //graph y axis is img z axis

    graph_scatter->axisX()->setTitleVisible(true);
    graph_scatter->axisY()->setTitleVisible(true);
    graph_scatter->axisZ()->setTitleVisible(true);

    graph_scatter->axisZ()->setReversed(true);      //graph z / img y axis is reversed (0,0 is in the top left of an img)
    graph_scatter->axisY()->setReversed(true);      //top to down tree


    //style
    graph_scatter->activeTheme()->setGridEnabled(grid);
    graph_scatter->activeTheme()->setBackgroundEnabled(background);
    graph_scatter->setShadowQuality(QAbstract3DGraph::ShadowQuality(shadow));


    //add data to series
    for(size_t i = 0; i < n_all; i++)
        vSeries_Nodes1st_Edges2nd[i]->dataProxy()->addItems(vDataArray_Nodes1st_Edges2nd[i]);

    //finish
    state_plot_active = true;
    state_plotting = false;
    return ER_okay;
}

int D_Viewer_Plot_3D::plot_Heightmap(vector<Mat> *pvMA_Height, vector<QImage> *pvQI_Texture, size_t shadow, bool background, bool grid, QString axis_x, QString axis_y, QString axis_z, bool draw_surface, bool draw_wireframe, bool called_internally)
{
    //error checks
    if(!state_ui_init)                                              {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "ui not init";                                return ER_UiNotInit;}
    if(!draw_surface && !draw_wireframe)                            {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "draw modi disabled";                         return ER_parameter_missmatch;}
    if(pvMA_Height->empty())                                        {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "heightmat empty";                            return ER_empty;}
    if(pvMA_Height->size() != pvQI_Texture->size())                 {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "height and texture count mismatch";          return ER_size_missmatch;}
    for(size_t i = 0; i < pvMA_Height->size(); i++)
    {
        if((*pvMA_Height)[i].channels() != 1)                       {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "heightmat not ch1";                          return ER_channel_bad;}
        if((*pvMA_Height)[i].size() != (*pvMA_Height)[0].size())    {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "heightmat size differs 0 to" << i;           return ER_size_missmatch;}
        if((*pvMA_Height)[i].cols != (*pvQI_Texture)[i].width())    {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "heightmat and texture width differ" << i;    return ER_size_missmatch;}
        if((*pvMA_Height)[i].rows != (*pvQI_Texture)[i].height())   {qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "heightmat and texture height differ" << i;   return ER_size_missmatch;}
    }

    //avoid thread issues
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //clear old content
    clear_graph_all();

    //show correct graph
    show_graph_type(c_VIEWER_PLOT_3D_MODE_HEIGHTMAP);

    //sizes
    size_t n = pvMA_Height->size();
    int w = (*pvMA_Height)[0].cols;
    int h = (*pvMA_Height)[0].rows;

    //series
    vector<QSurface3DSeries *> vSeries(n);

    //loop images
    for(size_t i = 0; i < n; i++)
    {
        //create series based on texture
        vSeries[i] = new QSurface3DSeries();//(texture_proxy);

        //loop rows
        for(int y = 0; y < h; y++)
        {
            //new row
            QSurfaceDataRow *Row = new QSurfaceDataRow(w);

            //loop cols in row
            for(int x = 0; x < w; x++)
            {
                //get value
                float val;
                switch ((*pvMA_Height)[i].type()) {
                case CV_8UC1:   val = (*pvMA_Height)[i].at<uchar>(y, x);            break;
                case CV_8SC1:   val = (*pvMA_Height)[i].at<char>(y, x);             break;
                case CV_16UC1:  val = (*pvMA_Height)[i].at<ushort>(y, x);           break;
                case CV_16SC1:  val = (*pvMA_Height)[i].at<short>(y, x);            break;
                case CV_32SC1:  val = (*pvMA_Height)[i].at<int>(y, x);              break;
                case CV_32FC1:  val = (*pvMA_Height)[i].at<float>(y, x);            break;
                case CV_64FC1:  val = float((*pvMA_Height)[i].at<double>(y, x));    break;
                default:        state_plotting = false;                             return ER_type_bad;}

                //set point in row
                //qDebug() << "D_Viewer_Plot_3D::plot_Heightmap" << "add point x/y/val" << x << y << val;
                (*Row)[x].setPosition(QVector3D(x, val, y));
            }

            //add row to array
            vSeries[i]->dataProxy()->addRow(Row);
        }

        //set texture
        vSeries[i]->setTexture((*pvQI_Texture)[i]);

        //draw mode
        if(draw_surface && draw_wireframe)
            vSeries[i]->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
        else if(draw_surface)
            vSeries[i]->setDrawMode(QSurface3DSeries::DrawSurface);
        else if(draw_wireframe)
            vSeries[i]->setDrawMode(QSurface3DSeries::DrawWireframe);
        //else: default draw mode

        //add series to graph
        graph_heightmap->addSeries(vSeries[i]);
    }

    //axis
    graph_heightmap->axisX()->setTitle(axis_x);   //default x axis
    graph_heightmap->axisY()->setTitle(axis_z);   //graph z axis is img y axis
    graph_heightmap->axisZ()->setTitle(axis_y);   //graph y axis is img z axis
    graph_heightmap->axisX()->setTitleVisible(true);
    graph_heightmap->axisY()->setTitleVisible(true);
    graph_heightmap->axisZ()->setTitleVisible(true);
    //graph_heightmap->axisX()->setReversed(true);
    graph_heightmap->axisZ()->setReversed(true);  //graph z / img y axis is reversed (0,0 is in the top left of an img)

    //style
    graph_heightmap->activeTheme()->setGridEnabled(grid);
    graph_heightmap->activeTheme()->setBackgroundEnabled(background);
    graph_heightmap->setShadowQuality(QAbstract3DGraph::ShadowQuality(shadow));

    //finish
    state_plot_active = true;
    state_plotting = false;
    return ER_okay;
}

QAbstract3DSeries::Mesh D_Viewer_Plot_3D::marker_from_id(int marker_id)
{
    switch (marker_id) {
    case c_VIEWER_PLOT_3D_MARKER_POINT:         return QAbstract3DSeries::Mesh::MeshPoint;
    case c_VIEWER_PLOT_3D_MARKER_MINIMAL:       return QAbstract3DSeries::Mesh::MeshMinimal;
    case c_VIEWER_PLOT_3D_MARKER_PYRAMID:       return QAbstract3DSeries::Mesh::MeshPyramid;
    case c_VIEWER_PLOT_3D_MARKER_CUBE:          return QAbstract3DSeries::Mesh::MeshCube;
    case c_VIEWER_PLOT_3D_MARKER_CYLINDER:      return QAbstract3DSeries::Mesh::MeshCylinder;
    case c_VIEWER_PLOT_3D_MARKER_SPHERE:        return QAbstract3DSeries::Mesh::MeshSphere;
    case c_VIEWER_PLOT_3D_MARKER_ARROW:         return QAbstract3DSeries::Mesh::MeshArrow;
    default:                                    return QAbstract3DSeries::Mesh::MeshPoint;}
}

size_t D_Viewer_Plot_3D::series_count_from_color_handle_id(size_t color_handle_id)
{
    switch (color_handle_id) {
    case c_VIEWER_PLOT_3D_VALUE_HANDLING_MONO:  return 1;
    case c_VIEWER_PLOT_3D_VALUE_HANDLING_GRAY:  return 256;
    case c_VIEWER_PLOT_3D_VALUE_HANDLING_HUE:   return 240;
    default:                                    return 0;}
}

QColor D_Viewer_Plot_3D::series_color(size_t series_count, size_t series_index, size_t color_handle)
{
    QColor color;
    switch (color_handle) {
    case c_VIEWER_PLOT_3D_VALUE_HANDLING_MONO:      color.setRgb(128, 128, 128);                                break;
    case c_VIEWER_PLOT_3D_VALUE_HANDLING_GRAY:      color.setRgb(series_index, series_index, series_index);     break;
    case c_VIEWER_PLOT_3D_VALUE_HANDLING_HUE:       color.setHsv(series_count - 1 - series_index, 255, 255);    break;
    default:                                        color.setRgb(0, 0, 0);                                      break;}

    return color;
}

void D_Viewer_Plot_3D::show_graph_type(size_t graph_type_id)
{
    container_widget_scatter->setVisible(graph_type_id == c_VIEWER_PLOT_3D_MODE_SCATTER);
    container_widget_heightmap->setVisible(graph_type_id == c_VIEWER_PLOT_3D_MODE_HEIGHTMAP);
}

void D_Viewer_Plot_3D::clear_layout()
{
    qDebug() << "D_Viewer_Plot_3D::clear_layout" << "start";

    //anything to delete
    if(!state_ui_init)
        return;

    //empty layout?
    int i = 0;
    qDebug() << "D_Viewer_Plot_3D::clear_layout" << "start remove loop" << "isempty" << layout_in_ui->isEmpty() << "count" << layout_in_ui->count();
    while(layout_in_ui->count() > 0)
    {
        qDebug() << "D_Viewer_Plot_3D::clear_layout" << "remove item" << i;

        //old content
        QLayoutItem *old_layout_item = layout_in_ui->layout()->takeAt(0);
        QWidget *old_container = old_layout_item->widget();

        //replace
        layout_in_ui->layout()->removeWidget(old_container);

        //delete old content
        delete old_layout_item;
        delete old_container;

        i++;
    }

    state_container_widget_exists = false;
}

int D_Viewer_Plot_3D::dimIndex_FromAxisIndex(size_t axis_index)
{
    switch (axis_index) {

    case c_VIEWER_PLOT_3D_AXIS_IMG_X:  return c_DIM_X;
    case c_VIEWER_PLOT_3D_AXIS_IMG_Y:  return c_DIM_Y;
    case c_VIEWER_PLOT_3D_AXIS_IMG_Z:  return c_DIM_Z;
    case c_VIEWER_PLOT_3D_AXIS_IMG_T:  return c_DIM_T;
    case c_VIEWER_PLOT_3D_AXIS_IMG_S:  return c_DIM_S;
    case c_VIEWER_PLOT_3D_AXIS_IMG_P:  return c_DIM_P;
    default:                        return -1;}
}

int D_Viewer_Plot_3D::ValueAxisMat(Mat *pMA_Out, Mat *pMA_In, size_t axis_index, Vec<int, c_DIM_NUMBER_OF> slice_pos, double default_value, bool force_double)
{
    if(force_double)
    {
        Mat MA_tmp_out_non_force_double;
        int err = ValueAxisMat(
                    &MA_tmp_out_non_force_double,
                    pMA_In,
                    axis_index,
                    slice_pos,
                    default_value,
                    false);
        if(err != ER_okay)
        {
            MA_tmp_out_non_force_double.release();
            *pMA_Out = Mat(pMA_In->size(), CV_64FC1, Scalar(default_value));
            return err;
        }

        if(MA_tmp_out_non_force_double.depth() == CV_64F)
        {
            *pMA_Out = MA_tmp_out_non_force_double.clone();
            return ER_okay;
        }
        else
        {
            err = D_Img_Proc::Convert_Depth_NoScaling(
                        pMA_Out,
                        &MA_tmp_out_non_force_double,
                        CV_64F);
            MA_tmp_out_non_force_double.release();
            if(err != ER_okay)
                *pMA_Out = Mat(pMA_In->size(), CV_64FC1, Scalar(default_value));

            return err;
        }
    }
    else
    {
        switch (axis_index) {

        case c_VIEWER_PLOT_3D_AXIS_IMG_X:
        case c_VIEWER_PLOT_3D_AXIS_IMG_Y:
        case c_VIEWER_PLOT_3D_AXIS_IMG_Z:
        case c_VIEWER_PLOT_3D_AXIS_IMG_T:
        case c_VIEWER_PLOT_3D_AXIS_IMG_S:
        case c_VIEWER_PLOT_3D_AXIS_IMG_P:
        {
            //get dim index
            int dim_axis = dimIndex_FromAxisIndex(axis_index);
            if(dim_axis < 0)
            {
                *pMA_Out = Mat(pMA_In->size(), CV_64FC1, Scalar(default_value));
                return ER_parameter_bad;
            }

            //check if dim is constant
            if(slice_pos[dim_axis] >= 0)
            {
                //constant dim
                //--> constant Mat
                *pMA_Out = Mat(pMA_In->size(), CV_64FC1, Scalar(slice_pos[dim_axis]));
                return ER_okay;
            }
            else
            {
                //non constant dim
                //--> gradient Mat

                //check, if axis is 1st or 2nd extended dim
                size_t ext_dims_count = 0;
                for(int d = 0; d <= dim_axis; d++)
                    if(slice_pos[d] < 0)
                        ext_dims_count++;

                //axis is 1st extended dim --> x gradient
                if(ext_dims_count == 1)
                    return D_Img_Proc::Generate_byValueFunction(pMA_Out, pMA_In->cols, pMA_In->rows, D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X));
                else if(ext_dims_count == 2)
                    return D_Img_Proc::Generate_byValueFunction(pMA_Out, pMA_In->cols, pMA_In->rows, D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y));
                else
                {
                    *pMA_Out = Mat(pMA_In->size(), CV_64FC1, Scalar(default_value));
                    return ER_parameter_bad;
                }
            }
        }

        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_0:
            return D_Img_Proc::Split(pMA_Out, pMA_In, 0);

        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_1:
            return D_Img_Proc::Split(pMA_Out, pMA_In, 1);

        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_2:
            return D_Img_Proc::Split(pMA_Out, pMA_In, 2);

        case c_VIEWER_PLOT_3D_AXIS_CHANNEL_3:
            return D_Img_Proc::Split(pMA_Out, pMA_In, 3);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_GRAY:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_GRAY);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_BLUE:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_BLUE);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_GREEN:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_GREEN);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_RED:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_RED);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_HUE:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_HUE);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_SATURATION:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_SATURATION);

        case c_VIEWER_PLOT_3D_AXIS_COLOR_VALUE:
            return D_Img_Proc::Convert_Color2Mono(pMA_Out, pMA_In, c_COL2MONO_VALUE);

        case c_VIEWER_PLOT_3D_AXIS_EMPTY:
        default:
            *pMA_Out = Mat(pMA_In->size(), CV_64FC1, Scalar(default_value));
            return ER_okay;
        }
    }
}

int D_Viewer_Plot_3D::SurfaceTextureImage(QImage *pQI_Out, Mat *pMA_In, size_t texture_mode, size_t axis_index_value, Vec<int, c_DIM_NUMBER_OF> slice_pos, double default_value, bool use_fix_crop_range, double in_min, double in_max)
{
    //img size
    int w = pMA_In->cols;
    int h = pMA_In->rows;

    //value
    Mat MA_tmp_value;
    int err = ValueAxisMat(
                &MA_tmp_value,
                pMA_In,
                axis_index_value,
                slice_pos,
                default_value,
                false);
    if(err != ER_okay)
    {
        qDebug() << "D_Viewer_Plot_3D::SurfaceTextureImage" << "ValueAxisMat value";
        MA_tmp_value.release();
        *pQI_Out = QImage(w, h, QImage::Format_RGBA8888);
        pQI_Out->fill(Qt::red);
        return err;
    }



    //calc texture img
    switch (texture_mode) {

    case c_VIEWER_PLOT_3D_TEXTURE_MONO:
        *pQI_Out = QImage(w, h, QImage::Format_RGBA8888);
        pQI_Out->fill(Qt::red);
        break;

    case c_VIEWER_PLOT_3D_TEXTURE_IMAGE:
        err = D_Img_Proc::Convert_Mat_to_QImage(
                    pQI_Out,
                    pMA_In,
                    use_fix_crop_range,
                    in_min,
                    in_max);
        break;

    case c_VIEWER_PLOT_3D_TEXTURE_GRAY:
        err = D_Img_Proc::Convert_Mat_to_QImage(
                    pQI_Out,
                    &MA_tmp_value,
                    use_fix_crop_range,
                    in_min,
                    in_max);
        break;

    case c_VIEWER_PLOT_3D_TEXTURE_HUE:
    {
        Mat MA_tmp_useless_alpha_img = Mat::zeros(MA_tmp_value.size(), CV_8UC1);
        err = D_Img_Proc::Convert_toQImage4Ch(
                    pQI_Out,
                    &MA_tmp_value,
                    &MA_tmp_useless_alpha_img,
                    true);
        MA_tmp_useless_alpha_img.release();
    }
        break;

    default:
        err = D_Img_Proc::Convert_Mat_to_QImage(
                    pQI_Out,
                    &MA_tmp_value);
        break;
    }

    MA_tmp_value.release();
    if(err != ER_okay)
    {
        qDebug() << "D_Viewer_Plot_3D::SurfaceTextureImage" << "D_Img_Proc::Convert_toQImage4Ch";
        *pQI_Out = QImage(w, h, QImage::Format_RGBA8888);
        pQI_Out->fill(Qt::red);
    }

    return err;
}

void D_Viewer_Plot_3D::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Viewer_Plot_3D", func, detail);
}
