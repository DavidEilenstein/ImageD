/************************************
 *   added:     27.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_viewer_3d.h"

D_Viewer_3D::D_Viewer_3D()
{

}

D_Viewer_3D::D_Viewer_3D(QGridLayout *target_layout)
{
    init(target_layout);
}

D_Viewer_3D::~D_Viewer_3D()
{
    clear_layout();
}

int D_Viewer_3D::init(QGridLayout *target_layout)
{
    if(state_ui_init)
    {
        ERR(ER_other, "init_ui", "Graph was put in ui before");
        return ER_UiAllreadyInit;
    }

    //save pointer to ui layout
    layout_in_ui = target_layout;
    state_ui_init = true;

    //init with empty plot
    plot_empty();
    return ER_okay;
}

int D_Viewer_3D::plot_empty()
{
    //avoid thread issues
    if(state_plotting)
        return ER_ThreadIssue;
    state_plotting = true;

    //new plot
    Q3DScatter *graph = new Q3DScatter();

    //put in ui
    PutGraphInLayout(graph);

    //finish
    state_plotting = false;
    return ER_okay;
}

int D_Viewer_3D::plot_test()
{
    //avoid thread issues
    if(state_plotting)
        return ER_ThreadIssue;
    state_plotting = true;

    //new plot
    qDebug() << "D_Viewer_3D::plot_test" << "new plot" << "=====================================================================";
    Q3DScatter *graph = new Q3DScatter();
    if(!PutGraphInLayout(graph))
    {
        state_plotting = false;
        return ER_UiPutInFail;
    }

    //data model
    qDebug() << "D_Viewer_3D::plot_test" << "data model";
    QScatterDataProxy *proxy = new QScatterDataProxy;
    QScatter3DSeries *series = new QScatter3DSeries(proxy);
    series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
    series->setMeshSmooth(false);
    graph->addSeries(series);

    //axis
    qDebug() << "D_Viewer_3D::plot_test" << "axis";
    graph->axisX()->setTitle("X");
    graph->axisY()->setTitle("Y");
    graph->axisZ()->setTitle("Z");

    //data handler
    qDebug() << "D_Viewer_3D::plot_test" << "data handler";
    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(2);

    //create data 2 example points
    qDebug() << "D_Viewer_3D::plot_test" << "loop and create data";
    QScatterDataItem *ptrToDataArray = &dataArray->first();
    ptrToDataArray->setPosition(QVector3D(42, 69, 666));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(1, static_cast<float>(c_E), static_cast<float>(PI)));

    //add data handler to graph
    qDebug() << "D_Viewer_3D::plot_test" << "add data to graph";
    graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);

    //style
    qDebug() << "D_Viewer_3D::plot_test" << "theme";
    graph->activeTheme()->setType(Q3DTheme::ThemeQt);

    qDebug() << "D_Viewer_3D::plot_test" << "finish";
    state_plot_active = true;
    state_plotting = false;
    return ER_okay;
}

int D_Viewer_3D::plot_img2D_gray(Mat *pMA_img)
{
    if(pMA_img->empty())            return ER_empty;
    if(pMA_img->channels() != 1)    return ER_channel_bad;

    //avoid thread issues
    if(state_plotting)
        return ER_ThreadIssue;
    state_plotting = true;

    //new plot
    Q3DScatter *graph = new Q3DScatter();
    if(!PutGraphInLayout(graph))
    {
        state_plotting = false;
        return ER_UiPutInFail;
    }

    //params
    int nx = pMA_img->cols;
    int ny = pMA_img->rows;
    int nxy = nx * ny;

    //data model
    QScatterDataProxy *proxy = new QScatterDataProxy;
    QScatter3DSeries *series = new QScatter3DSeries(proxy);
    series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
    series->setMeshSmooth(false);
    graph->addSeries(series);

    //axis
    graph->axisX()->setTitle("X");
    graph->axisY()->setTitle("Y");
    graph->axisZ()->setTitle("Z");

    //data handler
    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(nxy);

    //loop and create data
    QScatterDataItem *ptrToDataArray = &dataArray->first();
    switch (pMA_img->type())
    {

    case CV_8UC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, pMA_img->at<uchar>(y, x), y));
                ptrToDataArray++;
            }
    }
        break;

    case CV_8SC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, pMA_img->at<char>(y, x), y));
                ptrToDataArray++;
            }
    }
        break;

    case CV_16UC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, pMA_img->at<ushort>(y, x), y));
                ptrToDataArray++;
            }
    }
        break;

    case CV_16SC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, pMA_img->at<short>(y, x), y));
                ptrToDataArray++;
            }
    }
        break;

    case CV_32SC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, pMA_img->at<int>(y, x), y));
                ptrToDataArray++;
            }
    }
        break;

    case CV_32FC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, pMA_img->at<float>(y, x), y));
                ptrToDataArray++;
            }
    }
        break;

    case CV_64FC1:
    {
        for(int x = 0; x < nx; x++)
            for(int y = 0; y < ny; y++)
            {
                ptrToDataArray->setPosition(QVector3D(x, static_cast<float>(pMA_img->at<double>(y, x)), y));
                ptrToDataArray++;
            }
    }
        break;

    default:
        state_plotting = false;
        return ER_type_bad;
    }


    //add data handler to graph
    graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);

    state_plot_active = true;
    state_plotting = false;
    return ER_okay;
}

int D_Viewer_3D::plot_VD_custom(D_VisDat_Obj *pVD, size_t mode, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v, int marker, int shadow, bool background, bool grid, bool smooth)
{
    //empty?
    if(pVD->pMA_full()->empty())            return ER_empty;

    //avoid thread issues
    if(state_plotting)
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
        if(vAxis[i] >= c_D_VIEWER_3D_AXIS_NUMBER_OF)
        {
            qDebug() << "D_Viewer_3D::plot_VD_custom" << "axis index" << i << "witth value" << vAxis[i] << "is invalid";
            state_plotting = false;
            return ER_parameter_bad;
        }

    //check channels
    for(size_t i = 0; i < vAxis.size(); i++)
        switch (vAxis[i]) {
        case c_D_VIEWER_3D_AXIS_CHANNEL_1:  if(pVD->channels() < 2) {state_plotting = false;    return ER_channel_missmatch;}   break;
        case c_D_VIEWER_3D_AXIS_CHANNEL_2:  if(pVD->channels() < 3) {state_plotting = false;    return ER_channel_missmatch;}   break;
        case c_D_VIEWER_3D_AXIS_CHANNEL_3:  if(pVD->channels() < 4) {state_plotting = false;    return ER_channel_missmatch;}   break;
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

        case c_VIEWER_3D_CONDITION_ALL:
            use_this_pixel = true;
            break;

        case c_VIEWER_3D_CONDITION_NOT_ZERO:
            for(size_t ch = 0; ch < val.size() && !use_this_pixel; ch++)
                if(val[ch] != 0.0)
                    use_this_pixel = true;
            break;

        default:
            qDebug() << "D_Viewer_3D::plot_VD_custom" << "condition with index" << cond << "is invalid";
            state_plotting = false;
            return ER_parameter_bad;
        }

        //add data
        if(use_this_pixel)
            for(size_t i = 0; i < vAxis.size(); i++)
                switch (vAxis[i]) {
                case c_D_VIEWER_3D_AXIS_EMPTY:      vvData[i].push_back(0);                 break;
                case c_D_VIEWER_3D_AXIS_IMG_X:      vvData[i].push_back(pos[c_DIM_X]);      break;
                case c_D_VIEWER_3D_AXIS_IMG_Y:      vvData[i].push_back(pos[c_DIM_Y]);      break;
                case c_D_VIEWER_3D_AXIS_IMG_Z:      vvData[i].push_back(pos[c_DIM_Z]);      break;
                case c_D_VIEWER_3D_AXIS_IMG_T:      vvData[i].push_back(pos[c_DIM_T]);      break;
                case c_D_VIEWER_3D_AXIS_IMG_S:      vvData[i].push_back(pos[c_DIM_S]);      break;
                case c_D_VIEWER_3D_AXIS_IMG_P:      vvData[i].push_back(pos[c_DIM_P]);      break;
                case c_D_VIEWER_3D_AXIS_CHANNEL_0:  vvData[i].push_back(val[0]);            break;
                case c_D_VIEWER_3D_AXIS_CHANNEL_1:  vvData[i].push_back(val[1]);            break;
                case c_D_VIEWER_3D_AXIS_CHANNEL_2:  vvData[i].push_back(val[2]);            break;
                case c_D_VIEWER_3D_AXIS_CHANNEL_3:  vvData[i].push_back(val[3]);            break;
                default:                            state_plotting = false;                 return ER_parameter_bad;}
    }

    //modi
    switch (mode) {
    case c_VIEWER_3D_MODE_SCATTER:      return plot_ScatterData_4D(vvData[0], vvData[1], vvData[2], vvData[3], val_handle, marker, shadow, background, grid, smooth, true);
    default:                            qDebug() << "D_Viewer_3D::plot_VD_custom" << "mode invalid"; state_plotting = false; return ER_parameter_bad;}
}

int D_Viewer_3D::plot_ScatterData_4D(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vV, size_t color_handle, int marker, int shadow, bool background, bool grid, bool smooth, bool called_internally)
{
    if(!state_ui_init)                                          return ER_UiNotInit;

    qDebug() << "plot_ScatterData_4D" << "start";
    if(vX.empty())                                              return ER_empty;
    if(vX.size() != vY.size())                                  return ER_size_missmatch;
    if(vX.size() != vZ.size())                                  return ER_size_missmatch;
    if(vX.size() != vV.size())                                  return ER_size_missmatch;
    if(color_handle >= c_VIEWER_3D_VALUE_HANDLING_NUMBER_OF)    return ER_parameter_bad;

    //avoid thread issues
    if(state_plotting && !called_internally)
        return ER_ThreadIssue;
    state_plotting = true;

    //new plot
    Q3DScatter *graph = new Q3DScatter();
    QWidget *container_widget = QWidget::createWindowContainer(graph);
    PutContainerInLayout(container_widget);

    //sizes
    qDebug() << "plot_ScatterData_4D" << "sizes";
    size_t n_all = vX.size();
    size_t n_series;
    switch (color_handle) {
    case c_VIEWER_3D_VALUE_HANDLING_MONO:   n_series = 1;               break;
    case c_VIEWER_3D_VALUE_HANDLING_GRAY:   n_series = 256;             break;
    case c_VIEWER_3D_VALUE_HANDLING_HUE:    n_series = 240;             break;
    default:                                state_plotting = false;     return ER_parameter_bad;}

    //data range for groups
    qDebug() << "plot_ScatterData_4D" << "data range";
    double min_v = +INFINITY;
    double max_v = -INFINITY;
    for(size_t i = 0; i < n_all; i++)
    {
        double v = vV[i];
        min_v = min(min_v, v);
        max_v = max(max_v, v);
    }
    double range_v = max_v - min_v;

    //group data
    qDebug() << "plot_ScatterData_4D" << "group data";
    vector<vector<double>> vvX(n_series);
    vector<vector<double>> vvY(n_series);
    vector<vector<double>> vvZ(n_series);
    vector<vector<double>> vvV(n_series);
    for(size_t i = 0; i < n_all; i++)
    {
        //calc group
        double i_rel = (vV[i] - min_v) / range_v;
        size_t i_group = static_cast<size_t>(i_rel * (n_series - 1));
        //push to group
        vvX[i_group].push_back(vX[i]);
        vvY[i_group].push_back(vY[i]);
        vvZ[i_group].push_back(vZ[i]);
        vvV[i_group].push_back(vV[i]);
    }

    //marker style
    QAbstract3DSeries::Mesh marker_mesh;
    switch (marker) {
    case MARKER_3D_POINT:       marker_mesh = QAbstract3DSeries::Mesh::MeshPoint;       break;
    case MARKER_3D_MINIMAL:     marker_mesh = QAbstract3DSeries::Mesh::MeshMinimal;     break;
    case MARKER_3D_PYRAMID:     marker_mesh = QAbstract3DSeries::Mesh::MeshPyramid;     break;
    case MARKER_3D_CUBE:        marker_mesh = QAbstract3DSeries::Mesh::MeshCube;        break;
    case MARKER_3D_CYLINDER:    marker_mesh = QAbstract3DSeries::Mesh::MeshCylinder;    break;
    case MARKER_3D_SPHERE:      marker_mesh = QAbstract3DSeries::Mesh::MeshSphere;      break;
    case MARKER_3D_ARROW:       marker_mesh = QAbstract3DSeries::Mesh::MeshArrow;       break;
    default:                    state_plotting = false;                                 return ER_parameter_bad;}

    //data models
    qDebug() << "plot_ScatterData_4D" << "data models";
    vector<QScatterDataProxy *> vProxys(n_series);
    vector<QScatter3DSeries *>  vSeries(n_series);
    for(size_t i = 0; i < n_series; i++)
    {
        //proxy
        vProxys[i] = new QScatterDataProxy();

        //create series
        vSeries[i] = new QScatter3DSeries(vProxys[i]);

        //style
        vSeries[i]->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
        vSeries[i]->setMeshSmooth(smooth);
        vSeries[i]->setMesh(marker_mesh);

        //color
        QColor color;
        switch (color_handle) {
        case c_VIEWER_3D_VALUE_HANDLING_MONO:       color.setRgb(128, 128, 128);                break;
        case c_VIEWER_3D_VALUE_HANDLING_GRAY:       color.setRgb(i, i, i);                      break;
        case c_VIEWER_3D_VALUE_HANDLING_HUE:        color.setHsv(n_series - 1 - i, 255, 255);   break;
        default:                                    state_plotting = false;                     return ER_parameter_bad;}
        vSeries[i]->setBaseColor(color);

        //series to graph
        graph->addSeries(vSeries[i]);
    }

    //axis
    qDebug() << "plot_ScatterData_4D" << "axis";
    graph->axisX()->setTitle("X");
    graph->axisY()->setTitle("Y");
    graph->axisZ()->setTitle("Z");

    //style
    graph->activeTheme()->setGridEnabled(grid);
    graph->activeTheme()->setBackgroundEnabled(background);
    graph->setShadowQuality(QAbstract3DGraph::ShadowQuality(shadow));

    //data handler
    qDebug() << "plot_ScatterData_4D" << "data handler";
    vector<QScatterDataArray *> vDataArray(n_series);
    for(size_t i = 0; i < n_series; i++)
    {
        vDataArray[i] = new QScatterDataArray;
        vDataArray[i]->resize(vvX[i].size());
    }

    //loop series
    qDebug() << "plot_ScatterData_4D" << "loop series and add data";
    for(size_t s = 0; s < n_series; s++)
    {
        //add data
        QScatterDataItem *ptrToDataArray = &(vDataArray[s])->first();
        for(size_t i = 0; i < vvX[s].size(); i++)
        {
            ptrToDataArray->setPosition(
                        QVector3D(
                            static_cast<float>(vvX[s][i]),
                            static_cast<float>(vvZ[s][i]),
                            static_cast<float>(vvY[s][i])));
            ptrToDataArray++;
        }

        //add data handler to series in graph
        graph->seriesList().at(s)->dataProxy()->resetArray(vDataArray[s]);
    }

    qDebug() << "plot_ScatterData_4D" << "finish";
    state_plot_active = true;
    state_plotting = false;
    return ER_okay;
}

void D_Viewer_3D::clear_layout()
{
    qDebug() << "D_Viewer_3D::clear_layout" << "start";

    //anything to delete
    if(!state_ui_init)
        return;

    //empty layout?
    int i = 0;
    qDebug() << "D_Viewer_3D::clear_layout" << "start remove loop" << "isempty" << layout_in_ui->isEmpty() << "count" << layout_in_ui->count();
    while(layout_in_ui->count() > 0)
    {
        qDebug() << "D_Viewer_3D::clear_layout" << "remove item" << i;

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

bool D_Viewer_3D::PutGraphInLayout(Q3DScatter *graph)
{
    //delete old content
    //clear_layout();

    //create container widget
    QWidget *container_widget = QWidget::createWindowContainer(graph);
    state_container_widget_exists = true;
    if(!graph->hasContext())
    {
        ERR(ER_other, "init_ui", "Failed to put graph in ui");
        container_widget->close();
        state_container_widget_exists = false;
        return false;
    }

    //put the container widget to the ui
    layout_in_ui->addWidget(container_widget);

    //delete older graph containing widgets
    while (layout_in_ui->rowCount() > 1)
    {
        QLayoutItem* item = layout_in_ui->layout()->takeAt(0);
        delete item->widget();
        delete item;
    }

    //set camera position
    graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetDirectlyAbove);

    //finish
    return true;
}

void D_Viewer_3D::PutContainerInLayout(QWidget *container_widget)
{
    if(!state_ui_init)
        return;

    //empty layout
    clear_layout();

    //QGridLayout dummy_layout
    QLabel *label = new QLabel("test text bla bla");
    layout_in_ui->addWidget(label);

    layout_in_ui->layout()->addWidget(container_widget);
}

void D_Viewer_3D::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Viewer_3D", func, detail);
}


