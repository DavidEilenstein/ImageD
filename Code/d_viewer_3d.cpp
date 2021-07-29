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
    delete scatter_graph;
    delete container_widget;
}

void D_Viewer_3D::init(QGridLayout *target_layout)
{
    if(state_ui_init)
    {
        ERR(ER_other, "init_ui", "Graph was put in ui before");
        return;
    }

    //create new scatter graph
    scatter_graph = new Q3DScatter();

    //create widget that contains the graph
    container_widget = QWidget::createWindowContainer(scatter_graph);
    if(!scatter_graph->hasContext())
    {
        ERR(ER_other, "init_ui", "Failed to put graph in ui");
        return;
    }

    //put the container widget to the ui
    target_layout->addWidget(container_widget);

    //set some cosmetic stuff just to look nicer
    scatter_graph->activeTheme()->setType(style_theme);
    QFont font = scatter_graph->activeTheme()->font();
    font.setPointSize(style_font_size);
    scatter_graph->activeTheme()->setFont(font);
    scatter_graph->setShadowQuality(style_shadow_quality);
    scatter_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);

    //update state
    state_ui_init = true;
}

void D_Viewer_3D::clear()
{
    QScatterDataArray *dataArray = new QScatterDataArray;
    scatter_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);
}

void D_Viewer_3D::plot_test()
{
    //params
    qDebug() << "D_Viewer_3D::plot_test" << "params";
    int n = 900;
    double curve_divider = 0.75;
    double limit = qSqrt(n) / 2.0f;

    //data model
    QScatterDataProxy *proxy = new QScatterDataProxy;
    QScatter3DSeries *series = new QScatter3DSeries(proxy);
    series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
    series->setMeshSmooth(style_smooth);
    scatter_graph->addSeries(series);

    //axis
    qDebug() << "D_Viewer_3D::plot_test" << "axis";
    scatter_graph->axisX()->setTitle("X");
    scatter_graph->axisY()->setTitle("Y");
    scatter_graph->axisZ()->setTitle("Z");

    //data handler
    qDebug() << "D_Viewer_3D::plot_test" << "data handler";
    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(n);

    //loop and create data
    qDebug() << "D_Viewer_3D::plot_test" << "loop and create data";
    QScatterDataItem *ptrToDataArray = &dataArray->first();
    for(double x = -limit; x < limit; x++)
    {
        for(double y = -limit; y < limit; y++)
        {
            ptrToDataArray->setPosition(
                        QVector3D(
                            x + 0.5,                                            //x
                            qCos(qDegreesToRadians((x * y) / curve_divider)),   //y
                            y + 0.5));                                          //z
            ptrToDataArray++;
        }
    }

    //add data handler to graph
    qDebug() << "D_Viewer_3D::plot_test" << "add data to graph";
    scatter_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);

    qDebug() << "D_Viewer_3D::plot_test" << "finish";
}

int D_Viewer_3D::plot_img2D_gray(Mat *pMA_img)
{
    if(pMA_img->empty())            return ER_empty;
    if(pMA_img->channels() != 1)    return ER_channel_bad;

    //params
    int nx = pMA_img->cols;
    int ny = pMA_img->rows;
    int nxy = nx * ny;

    //data model
    QScatterDataProxy *proxy = new QScatterDataProxy;
    QScatter3DSeries *series = new QScatter3DSeries(proxy);
    series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
    series->setMeshSmooth(style_smooth);
    scatter_graph->addSeries(series);

    //axis
    scatter_graph->axisX()->setTitle("X");
    scatter_graph->axisY()->setTitle("Y");
    scatter_graph->axisZ()->setTitle("Z");

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
        return ER_type_bad;
    }


    //add data handler to graph
    scatter_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);

    return ER_okay;
}

int D_Viewer_3D::plot_VD_custom(D_VisDat_Obj *pVD, size_t mode, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v)
{
    //empty?
    if(pVD->pMA_full()->empty())            return ER_empty;

    //dimension
    D_VisDat_Dim dim = pVD->Dim();

    //data needed
    vector<double> vX;
    vector<double> vY;
    vector<double> vZ;
    vector<double> vV;

    //CONTINUE HERE

    return plot_ScatterData_4D(vX, vY, vZ, vV, val_handle);
}

int D_Viewer_3D::plot_ScatterData_4D(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vV, size_t color_handle)
{
    if(vX.empty())                                              return ER_empty;
    if(vX.size() != vY.size())                                  return ER_size_missmatch;
    if(vX.size() != vZ.size())                                  return ER_size_missmatch;
    if(vX.size() != vV.size())                                  return ER_size_missmatch;
    if(color_handle >= c_VIEWER_3D_VALUE_HANDLING_NUMBER_OF)    return ER_parameter_bad;

    //sizes
    size_t n_all = vX.size();
    size_t n_series;
    switch (color_handle) {
    case c_VIEWER_3D_VALUE_HANDLING_MONO:   n_series = 1;       break;
    case c_VIEWER_3D_VALUE_HANDLING_GRAY:   n_series = 256;     break;
    case c_VIEWER_3D_VALUE_HANDLING_HUE:    n_series = 240;     break;
    default:                                                    return ER_parameter_bad;}

    //data range for groups
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

    //data models
    vector<QScatterDataProxy *> vProxys(n_series);
    vector<QScatter3DSeries *>  vSeries(n_series);
    for(size_t i = 0; i < n_series; i++)
    {
        //proxy
        vProxys[i] = new QScatterDataProxy();

        //series
        vSeries[i] = new QScatter3DSeries(vProxys[i]);
        vSeries[i]->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
        vSeries[i]->setMeshSmooth(style_smooth);

        //color
        switch (color_handle)
        {
        case c_VIEWER_3D_VALUE_HANDLING_GRAY:
        {
            QColor color(i, i, i);
            vSeries[i]->setBaseColor(color);
        }
            break;
        case c_VIEWER_3D_VALUE_HANDLING_HUE:
        {
            QColor color;
            color.setHsv(n_series - 1 - i, 255, 255);
            vSeries[i]->setBaseColor(color);
        }
            break;

        default:
            return ER_parameter_bad;
        }

        //series to graph
        scatter_graph->addSeries(vSeries[i]);
    }

    //axis
    scatter_graph->axisX()->setTitle("X");
    scatter_graph->axisY()->setTitle("Y");
    scatter_graph->axisZ()->setTitle("Z");

    //data handler
    vector<QScatterDataArray *> vDataArray;
    for(size_t i = 0; i < n_series; i++)
    {
        vDataArray[i] = new QScatterDataArray;
        vDataArray[i]->resize(vvX[i].size());
    }

    //loop series
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
        scatter_graph->seriesList().at(s)->dataProxy()->resetArray(vDataArray[s]);
    }

    return ER_okay;
}

void D_Viewer_3D::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Viewer_3D", func, detail);
}


