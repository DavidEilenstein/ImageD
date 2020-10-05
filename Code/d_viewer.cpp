/************************************
 *   added:     02.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_viewer.h"

D_Viewer::D_Viewer()
{
    //Standard-Construktor
    //(only exist for beeing able to create Viwer-Object in headers)

    v_ConnectedViewersZoom.push_back(this);
}

D_Viewer::D_Viewer(QGraphicsView *GV_ui)
{
    Init(GV_ui);
}

D_Viewer::D_Viewer(QGraphicsView *GV_ui, QString viewer_name)
{
    QS_Name = viewer_name;

    Init(GV_ui);
}

D_Viewer::D_Viewer(QGraphicsView *GV_ui, QDir default_dir)
{
    DIR_Default = default_dir;
    FI_LastSaved.setFile(DIR_Default.absoluteFilePath(QS_Name + ".jpg"));

    Init(GV_ui);
}

D_Viewer::D_Viewer(QGraphicsView *GV_ui, QDir default_dir, QString viewer_name)
{
    QS_Name = viewer_name;
    DIR_Default = default_dir;
    FI_LastSaved.setFile(DIR_Default.absoluteFilePath(QS_Name + ".jpg"));

    Init(GV_ui);
}

void D_Viewer::set_GV(QGraphicsView *GV_ui)
{
    Init(GV_ui);
}

void D_Viewer::set_CV(QChartView *CV_ui)
{
    CV_View = CV_ui;

    state_CV_set = true;

    CV_View->setRenderHint(QPainter::Antialiasing);
    CV_View->setRubberBand(QChartView::RectangleRubberBand);
    CV_View->setInteractive(true);

    D_Plot::Plot_Empty(
                CV_View,
                QS_Name + " Plot Init");
}

void D_Viewer::set_Name(QString viewer_name)
{
    QS_Name = viewer_name;
}

void D_Viewer::clear_Image()
{
    MA_Data         = Mat(3, 3, CV_8UC1, Scalar(127));
    MA_Zoom         = Mat(3, 3, CV_8UC1, Scalar(127));
    MA_VisTrafo     = Mat(3, 3, CV_8UC1, Scalar(127));
    Proc_MA_2_QI();
}

void D_Viewer::connect_Zoom(D_Viewer *viewer)
{
    v_ConnectedViewersZoom.push_back(viewer);

    for(size_t v1 = 0; v1 < v_ConnectedViewersZoom.size(); v1++)
        for(size_t v2 = 0; v2 < v_ConnectedViewersZoom.size(); v2++)
            if(v1 != v2)
            {
                connect(v_ConnectedViewersZoom[v1],     SIGNAL(Zoomed(double,double,double)),   v_ConnectedViewersZoom[v2],     SLOT(Set_Zomm(double,double,double)));
                connect(v_ConnectedViewersZoom[v1],     SIGNAL(Zoomed_Reset()),                 v_ConnectedViewersZoom[v2],     SLOT(Set_ZoomReset()));
            }
}

double D_Viewer::img_val_min()
{
    double min;
    double max;

    D_Img_Proc::MinMax_of_Mat(
                &MA_Data,
                &min,
                &max);

    return min;
}

double D_Viewer::img_val_max()
{
    double min;
    double max;

    D_Img_Proc::MinMax_of_Mat(
                &MA_Data,
                &min,
                &max);

    return max;
}

double D_Viewer::img_val_range()
{
    double min;
    double max;

    D_Img_Proc::MinMax_of_Mat(
                &MA_Data,
                &min,
                &max);

    return max - min;
}

void D_Viewer::Init(QGraphicsView *GV_ui)
{
    //connector list
    v_ConnectedViewersZoom.clear();
    v_ConnectedViewersZoom.resize(1);
    v_ConnectedViewersZoom[0] = this;

    //Graphicsview
    GV_View = GV_ui;
    GV_View->setScene(&SC_View);
    GV_View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    GV_View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    GV_View->setInteractive(true);

    //Scale
    scale = true;
    TransMode = Qt::SmoothTransformation;
    AspectMode = Qt::KeepAspectRatio;

    //Mat
    MA_Data     = Mat(3, 3, CV_8UC1, Scalar(127));
    MA_Zoom     = Mat(3, 3, CV_8UC1, Scalar(127));
    MA_VisTrafo = Mat(3, 3, CV_8UC1, Scalar(127));

    //connects
    //general mouse
    connect(&SC_View,   SIGNAL(mouseMoved(int,int)),                    this,       SLOT(MouseMoved(int,int)));
    connect(&SC_View,   SIGNAL(MouseClickedAtPos(int,int)),             this,       SLOT(MouseClicked(int,int)));
    connect(&SC_View,   SIGNAL(MouseClickedAtPos_Left(int,int)),        this,       SLOT(MouseClicked_Left(int,int)));
    connect(&SC_View,   SIGNAL(MouseClickedAtPos_Right(int,int)),       this,       SLOT(MouseClicked_Right(int,int)));
    connect(&SC_View,   SIGNAL(MouseClickedAtPos_Mid(int,int)),         this,       SLOT(MouseClicked_Mid(int,int)));
    //zoom
    connect(&SC_View,   SIGNAL(mouseMoved_Ctrl(int,int)),               this,       SLOT(Zoom_Pos(int,int)));
    connect(&SC_View,   SIGNAL(KeyPressed_Plus_Ctrl()),                 this,       SLOT(Zoom_In()));
    connect(&SC_View,   SIGNAL(MouseClicked_Left_Ctrl()),               this,       SLOT(Zoom_In()));
    connect(&SC_View,   SIGNAL(KeyPressed_Minus_Ctrl()),                this,       SLOT(Zoom_Out()));
    connect(&SC_View,   SIGNAL(MouseClicked_Right_Ctrl()),              this,       SLOT(Zoom_Out()));
    connect(&SC_View,   SIGNAL(MouseClicked_Mid_Ctrl()),                this,       SLOT(Zoom_Reset()));

    //QImage, Pixmap, Scene
    Proc_MA_2_QI();
}

void D_Viewer::Proc_ShowImgOrPlot()
{
    if(ViewerMode == c_VIEWER_MODE_IMG)
        Proc_MA_2_QI();
    else if(ViewerMode == c_VIEWER_MODE_PLOT)
        Proc_Plot();
}

void D_Viewer::Proc_MA_2_QI()
{
    int ER;

    QET_convert.start();

    if(zoom_active && vis_trafo_active)
    {
        //qDebug() << "zoom" << cursor_x_rel << cursor_y_rel << zoom_factor;
        //MA_Data->MA_Zoom
        //MA_Zoom->MA_GS

        ER = D_Img_Proc::Zoom(
                    &MA_Zoom,
                    &MA_Data,
                    cursor_x_rel,
                    cursor_y_rel,
                    zoom_factor_cur,
                    &zoom_offset_x,
                    &zoom_offset_y,
                    &zoom_width,
                    &zoom_height);
        if(ER == ER_size_bad)
        {
            qDebug() << "Proc_MA_2_QI(zoom_active && gs_active): ER == ER_size_bad -> Set_ZoomReset";
            Set_ZoomReset();
            return;
        }
        else if(ER != ER_okay && ER != ER_size_bad)
            ERR(ER,
                "Proc_MA_2_QI - zoom active, vis trafo active",
                "D_Img_Proc::Zoom");

        ERR(D_Img_Proc::Visualize_to8bit(
                &MA_VisTrafo,
                &MA_Zoom,
                vis_trafo_mode_crop,
                vis_trafo_mode_trafo,
                vis_trafo_mode_anchor,
                vis_trafo_mode_range,
                vis_trafo_anchor,
                vis_trafo_range,
                vis_trafo_in_min,
                vis_trafo_in_max,
                vis_trafo_gamma,
                vis_trafo_center,
                vis_trafo_divisor,
                false,
                vis_trafo_mode_complex),
            "Proc_MA_2_QI - zoom active, vis trafo active",
            "Visualize_to8bit");

        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &QI_View,
                &MA_VisTrafo),
            "Proc_MA_2_QI - zoom active, vis trafo active",
            "D_Img_Proc::Convert_Mat_to_QImage");
    }
    else if(zoom_active && !vis_trafo_active)
    {
        //qDebug() << "zoom" << cursor_x_rel << cursor_y_rel << zoom_factor;
        //MA_Data->MA_Zoom

        ER = D_Img_Proc::Zoom(
                &MA_Zoom,
                &MA_Data,
                cursor_x_rel,
                cursor_y_rel,
                zoom_factor_cur,
                &zoom_offset_x,
                &zoom_offset_y,
                &zoom_width,
                &zoom_height);
        if(ER == ER_size_bad)
        {
            qDebug() << "Proc_MA_2_QI(zoom_active && !gs_active): ER == ER_size_bad -> Set_ZoomReset";
            Set_ZoomReset();
            return;
        }
        else if(ER != ER_okay && ER != ER_size_bad)
            ERR(ER,
                "Proc_MA_2_QI - zoom active, vis trafo inactive",
                "D_Img_Proc::Zoom");

        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &QI_View,
                &MA_Zoom),
            "Proc_MA_2_QI - zoom active, vis trafo inactive",
            "D_Img_Proc::Convert_Mat_to_QImage");
    }
    else if(!zoom_active && vis_trafo_active)
    {
        //MA_Data->MA_GS
        ERR(D_Img_Proc::Visualize_to8bit(
                &MA_VisTrafo,
                &MA_Data,
                vis_trafo_mode_crop,
                vis_trafo_mode_trafo,
                vis_trafo_mode_anchor,
                vis_trafo_mode_range,
                vis_trafo_anchor,
                vis_trafo_range,
                vis_trafo_in_min,
                vis_trafo_in_max,
                vis_trafo_gamma,
                vis_trafo_center,
                vis_trafo_divisor,
                false,
                vis_trafo_mode_complex),
            "Proc_MA_2_QI",
            "D_Img_Proc::Visualize_to8bit");

        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &QI_View,
                &MA_VisTrafo),
            "Proc_MA_2_QI - zoom inactive, vis trafo active",
            "D_Img_Proc::Convert_Mat_to_QImage");
    }
    else if(!zoom_active && !vis_trafo_active)
    {
        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &QI_View,
                &MA_Data),
            "Proc_MA_2_QI - zoom inactive, vis trafo inactive",
            "D_Img_Proc::Convert_Mat_to_QImage");
    }

    time_convert = static_cast<unsigned int>(QET_convert.elapsed());

    emit Time_Image_Cvt(time_convert);
    emit TypeChanged();
    emit TypeChanged_QI();
    emit TypeChanged_QI(D_Img_Proc::Type_of_QImage(&QI_View));

    //zoom?
    if(zoom_active || zoom_changed)
        emit Zoomed(cursor_x_rel, cursor_y_rel, zoom_factor_cur);

    //zoom reset?
    if(zoom_changed && zoom_factor_cur == 1.0)
        emit Zoom_Reset();

    Proc_QI_2_PX();
}

void D_Viewer::Proc_QI_2_PX()
{
    QET_view.start();

    PX_View = QPixmap::fromImage(QI_View);

    if(scale)
        Proc_PX_Scale();

    Proc_PX_2_SC();
}

void D_Viewer::Proc_PX_Scale()
{
    PX_View = PX_View.scaled(
                GV_View->width() - 2,
                GV_View->height() - 2,
                AspectMode,
                TransMode);

    scale_x = static_cast<double>(PX_View.width() / QI_View.width());
    scale_y = static_cast<double>(PX_View.height() / QI_View.height());

    emit Scaled();

    emit Scaled_Factor(
                scale_x,
                scale_y);

    emit Scaled_Factor(
                QString::number(scale_x, 'g', 2) + "/" +
                QString::number(scale_y, 'g', 2));

    emit Scaled_Factor_Prz(
                QString::number(static_cast<int>(scale_x * 100.0)) + "%/" +
                QString::number(static_cast<int>(scale_y * 100.0)) + "%");
}

void D_Viewer::Proc_PX_2_SC()
{
    SC_View.clear();
    SC_View.addPixmap(PX_View);

    time_view = static_cast<unsigned int>(QET_view.elapsed());

    emit Time_View_Update(time_view);
    emit View_Updated();
}

void D_Viewer::Proc_Plot()
{
    //basic dims
    size_t channels = MA_Data.channels();
    size_t rows = MA_Data.rows;

    //check dimensionality
    if(channels > 1 && rows > 1)
        return;

    //get min/max
    double min, max;
    int ER = D_Img_Proc::MinMax_of_Mat(
                &MA_Data,
                &min,
                &max);
    if(ER != ER_okay)
        return;

    //min max used (croped or not)
    if(vis_trafo_mode_crop == c_VIS_TRAFO_CROP_FIXED)
    {
        min = vis_trafo_in_min;
        max = vis_trafo_in_max;
    }

    //function object to do the transformation
    function<double(double)> F_Trafo = D_Math::CopyValue();
    QString QS_TrafoDescription = "Showed linear";
    if(vis_trafo_active)
        switch (vis_trafo_mode_trafo) {

        case c_VIS_TRAFO_LINEAR:
            F_Trafo = D_Math::CopyValue();
            QS_TrafoDescription = "Showed linear";
            break;

        case c_VIS_TRAFO_GAMMA:
            F_Trafo = D_Math::GammaCorrect_to01(min, max, vis_trafo_gamma);
            if(vis_trafo_mode_crop == c_VIS_TRAFO_CROP_FIXED)
                QS_TrafoDescription = "Showed gamma (" + QString::number(vis_trafo_gamma) + ") corrected in range " +  QString::number(min) + " to " + QString::number(max);
            else
                QS_TrafoDescription = "Showed gamma (" + QString::number(vis_trafo_gamma) + ") corrected";
            break;

        case c_VIS_TRAFO_LOG:
            F_Trafo = D_Math::Log_Centered(min, max, vis_trafo_center, vis_trafo_divisor);
            if(vis_trafo_mode_crop == c_VIS_TRAFO_CROP_FIXED)
                QS_TrafoDescription = "Showed logarithmic (divisor=" + QString::number(vis_trafo_divisor) + ", center=" + QString::number(vis_trafo_center) + ") in range " +  QString::number(min) + " to " + QString::number(max);
            else
                QS_TrafoDescription = "Showed logarithmic (divisor=" + QString::number(vis_trafo_divisor) + ", center=" + QString::number(vis_trafo_center) + ")";
            break;

        default:
            return;
        }

    //clear old content
    D_Plot::Free_Memory(CV_View);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle("<b>" + QS_Name + "</b><br>" + QS_TrafoDescription);

    //Axis
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(QS_DimX);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(QS_DimY);
    chart->setAxisY(y_axis);
    y_axis->setMin(F_Trafo(min));
    y_axis->setMax(F_Trafo(max));

    //sizes
    size_t series_count = rows;
    if(channels > rows)
        series_count = channels;
    size_t x_count = MA_Data.cols;

    //Names of Series
    QStringList QSL_Series;
    if(channels > rows)
        for(size_t c = 0; c < channels; c++)
            QSL_Series.push_back("channel_" + QString::number(c));
    else if(rows > channels)
        for(size_t r = 0; r < rows; r++)
            QSL_Series.push_back("row_" + QString::number(r));
    else
        QSL_Series.push_back("data");

    //series
    switch (PlotType) {

    case c_IMG2PLOT_POINT://========================================Point
    {
        //series (for all img types)
        vector<QScatterSeries*> v_series(series_count);
        for(size_t s = 0; s < series_count; s++)
        {
            //create series
            v_series[s] = new QScatterSeries;
            v_series[s]->setName(QSL_Series[static_cast<int>(s)]);
            //v_series[s]->setUseOpenGL(true);
            if(channels > rows)
            {
                switch (s) {
                case 0:     v_series[s]->setColor(Qt::blue);    break;
                case 1:     v_series[s]->setColor(Qt::green);   break;
                case 2:     v_series[s]->setColor(Qt::red);     break;
                default:    v_series[s]->setColor(Qt::gray);    break;}
            }
            else
            {
                QColor series_color;
                series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
                v_series[s]->setColor(series_color);
            }
        }

        //get data
        switch (MA_Data.type()) {

        case CV_8UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<uchar>(static_cast<int>(s), static_cast<int>(x))));
        }
            break;

        case CV_8SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<char>(static_cast<int>(s), static_cast<int>(x))));
        }
            break;

        case CV_16UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<ushort>(static_cast<int>(s), static_cast<int>(x))));
        }
            break;

        case CV_16SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<short>(static_cast<int>(s), static_cast<int>(x))));
        }
            break;

        case CV_32SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<int>(static_cast<int>(s), static_cast<int>(x))));
        }
            break;

        case CV_32FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(static_cast<double>(MA_Data.at<float>(static_cast<int>(s), static_cast<int>(x)))));
        }
            break;

        case CV_64FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<double>(static_cast<int>(s), static_cast<int>(x))));
        }
            break;

        case CV_8UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2b>(0, x)[s]));
        }
            break;

        case CV_8UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3b>(0, x)[s]));
        }
            break;

        case CV_8UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4b>(0, x)[s]));
        }
            break;

        case CV_16UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2w>(0, x)[s]));
        }
            break;

        case CV_16UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3w>(0, x)[s]));
        }
            break;

        case CV_16UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4w>(0, x)[s]));
        }
            break;

        case CV_16SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2s>(0, x)[s]));
        }
            break;

        case CV_16SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3s>(0, x)[s]));
        }
            break;

        case CV_16SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4s>(0, x)[s]));
        }
            break;

        case CV_32SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2i>(0, x)[s]));
        }
            break;

        case CV_32SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3i>(0, x)[s]));
        }
            break;

        case CV_32SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4i>(0, x)[s]));
        }
            break;

        case CV_32FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2f>(0, x)[s]));
        }
            break;

        case CV_32FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3f>(0, x)[s]));
        }
            break;

        case CV_32FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4f>(0, x)[s]));
        }
            break;

        case CV_64FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2d>(0, x)[s]));
        }
            break;

        case CV_64FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3d>(0, x)[s]));
        }
            break;

        case CV_64FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4d>(0, x)[s]));
        }
            break;

        default://---------------------------------------------
            return;
        }

        //add stuff (for all img types)
        for(size_t s = 0; s < series_count; s++)
        {
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }
        break;

    case c_IMG2PLOT_LINE://========================================Line
    {
        //series (for all img types)
        vector<QLineSeries*> v_series(series_count);
        for(size_t s = 0; s < series_count; s++)
        {
            //create series
            v_series[s] = new QLineSeries;
            v_series[s]->setName(QSL_Series[s]);
            //v_series[s]->setUseOpenGL(true);
            if(channels > rows)
            {
                switch (s) {
                case 0:     v_series[s]->setColor(Qt::blue);    break;
                case 1:     v_series[s]->setColor(Qt::green);   break;
                case 2:     v_series[s]->setColor(Qt::red);     break;
                default:    v_series[s]->setColor(Qt::gray);    break;}
            }
            else
            {
                QColor series_color;
                series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
                v_series[s]->setColor(series_color);
            }
        }

        //get data
        switch (MA_Data.type()) {

        case CV_8UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<uchar>(s, x)));
        }
            break;

        case CV_8SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<char>(s, x)));
        }
            break;

        case CV_16UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<ushort>(s, x)));
        }
            break;

        case CV_16SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<short>(s, x)));
        }
            break;

        case CV_32SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<int>(s, x)));
        }
            break;

        case CV_32FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<float>(s, x)));
        }
            break;

        case CV_64FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<double>(s, x)));
        }
            break;

        case CV_8UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2b>(0, x)[s]));
        }
            break;

        case CV_8UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3b>(0, x)[s]));
        }
            break;

        case CV_8UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4b>(0, x)[s]));
        }
            break;

        case CV_16UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2w>(0, x)[s]));
        }
            break;

        case CV_16UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3w>(0, x)[s]));
        }
            break;

        case CV_16UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4w>(0, x)[s]));
        }
            break;

        case CV_16SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2s>(0, x)[s]));
        }
            break;

        case CV_16SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3s>(0, x)[s]));
        }
            break;

        case CV_16SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4s>(0, x)[s]));
        }
            break;

        case CV_32SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2i>(0, x)[s]));
        }
            break;

        case CV_32SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3i>(0, x)[s]));
        }
            break;

        case CV_32SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4i>(0, x)[s]));
        }
            break;

        case CV_32FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2f>(0, x)[s]));
        }
            break;

        case CV_32FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3f>(0, x)[s]));
        }
            break;

        case CV_32FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4f>(0, x)[s]));
        }
            break;

        case CV_64FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2d>(0, x)[s]));
        }
            break;

        case CV_64FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3d>(0, x)[s]));
        }
            break;

        case CV_64FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4d>(0, x)[s]));
        }
            break;

        default://---------------------------------------------
            return;
        }

        //add stuff (for all img types)
        for(size_t s = 0; s < series_count; s++)
        {
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }
        break;

    case c_IMG2PLOT_LINE_POINT://========================================Line Point
    {
        //series (for all img types)
        vector<QLineSeries*> v_series(series_count);
        for(size_t s = 0; s < series_count; s++)
        {
            //create series
            v_series[s] = new QLineSeries;
            v_series[s]->setName(QSL_Series[s]);
            //v_series[s]->setUseOpenGL(true);
            v_series[s]->setPointsVisible(true);
            if(channels > rows)
            {
                switch (s) {
                case 0:     v_series[s]->setColor(Qt::blue);    break;
                case 1:     v_series[s]->setColor(Qt::green);   break;
                case 2:     v_series[s]->setColor(Qt::red);     break;
                default:    v_series[s]->setColor(Qt::gray);    break;}
            }
            else
            {
                QColor series_color;
                series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
                v_series[s]->setColor(series_color);
            }
        }

        //get data
        switch (MA_Data.type()) {

        case CV_8UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<uchar>(s, x)));
        }
            break;

        case CV_8SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<char>(s, x)));
        }
            break;

        case CV_16UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<ushort>(s, x)));
        }
            break;

        case CV_16SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<short>(s, x)));
        }
            break;

        case CV_32SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<int>(s, x)));
        }
            break;

        case CV_32FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<float>(s, x)));
        }
            break;

        case CV_64FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<double>(s, x)));
        }
            break;

        case CV_8UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2b>(0, x)[s]));
        }
            break;

        case CV_8UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3b>(0, x)[s]));
        }
            break;

        case CV_8UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4b>(0, x)[s]));
        }
            break;

        case CV_16UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2w>(0, x)[s]));
        }
            break;

        case CV_16UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3w>(0, x)[s]));
        }
            break;

        case CV_16UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4w>(0, x)[s]));
        }
            break;

        case CV_16SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2s>(0, x)[s]));
        }
            break;

        case CV_16SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3s>(0, x)[s]));
        }
            break;

        case CV_16SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4s>(0, x)[s]));
        }
            break;

        case CV_32SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2i>(0, x)[s]));
        }
            break;

        case CV_32SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3i>(0, x)[s]));
        }
            break;

        case CV_32SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4i>(0, x)[s]));
        }
            break;

        case CV_32FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2f>(0, x)[s]));
        }
            break;

        case CV_32FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3f>(0, x)[s]));
        }
            break;

        case CV_32FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4f>(0, x)[s]));
        }
            break;

        case CV_64FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2d>(0, x)[s]));
        }
            break;

        case CV_64FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3d>(0, x)[s]));
        }
            break;

        case CV_64FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4d>(0, x)[s]));
        }
            break;

        default://---------------------------------------------
            return;
        }

        //add stuff (for all img types)
        for(size_t s = 0; s < series_count; s++)
        {
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }
        break;

    case c_IMG2PLOT_SPLINE://========================================Spline
    {
        //series (for all img types)
        vector<QSplineSeries*> v_series(series_count);
        for(size_t s = 0; s < series_count; s++)
        {
            //create series
            v_series[s] = new QSplineSeries;
            v_series[s]->setName(QSL_Series[s]);
            //v_series[s]->setUseOpenGL(true);
            if(channels > rows)
            {
                switch (s) {
                case 0:     v_series[s]->setColor(Qt::blue);    break;
                case 1:     v_series[s]->setColor(Qt::green);   break;
                case 2:     v_series[s]->setColor(Qt::red);     break;
                default:    v_series[s]->setColor(Qt::gray);    break;}
            }
            else
            {
                QColor series_color;
                series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
                v_series[s]->setColor(series_color);
            }
        }

        //get data
        switch (MA_Data.type()) {

        case CV_8UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<uchar>(s, x)));
        }
            break;

        case CV_8SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<char>(s, x)));
        }
            break;

        case CV_16UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<ushort>(s, x)));
        }
            break;

        case CV_16SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<short>(s, x)));
        }
            break;

        case CV_32SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<int>(s, x)));
        }
            break;

        case CV_32FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<float>(s, x)));
        }
            break;

        case CV_64FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<double>(s, x)));
        }
            break;

        case CV_8UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2b>(0, x)[s]));
        }
            break;

        case CV_8UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3b>(0, x)[s]));
        }
            break;

        case CV_8UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4b>(0, x)[s]));
        }
            break;

        case CV_16UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2w>(0, x)[s]));
        }
            break;

        case CV_16UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3w>(0, x)[s]));
        }
            break;

        case CV_16UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4w>(0, x)[s]));
        }
            break;

        case CV_16SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2s>(0, x)[s]));
        }
            break;

        case CV_16SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3s>(0, x)[s]));
        }
            break;

        case CV_16SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4s>(0, x)[s]));
        }
            break;

        case CV_32SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2i>(0, x)[s]));
        }
            break;

        case CV_32SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3i>(0, x)[s]));
        }
            break;

        case CV_32SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4i>(0, x)[s]));
        }
            break;

        case CV_32FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2f>(0, x)[s]));
        }
            break;

        case CV_32FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3f>(0, x)[s]));
        }
            break;

        case CV_32FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4f>(0, x)[s]));
        }
            break;

        case CV_64FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2d>(0, x)[s]));
        }
            break;

        case CV_64FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3d>(0, x)[s]));
        }
            break;

        case CV_64FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4d>(0, x)[s]));
        }
            break;

        default://---------------------------------------------
            return;
        }

        //add stuff (for all img types)
        for(size_t s = 0; s < series_count; s++)
        {
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }
        break;

    case c_IMG2PLOT_SPLINE_POINT://========================================Spline Points
    {
        //series (for all img types)
        vector<QSplineSeries*> v_series(series_count);
        for(size_t s = 0; s < series_count; s++)
        {
            //create series
            v_series[s] = new QSplineSeries;
            v_series[s]->setName(QSL_Series[s]);
            //v_series[s]->setUseOpenGL(true);
            v_series[s]->setPointsVisible(true);
            if(channels > rows)
            {
                switch (s) {
                case 0:     v_series[s]->setColor(Qt::blue);    break;
                case 1:     v_series[s]->setColor(Qt::green);   break;
                case 2:     v_series[s]->setColor(Qt::red);     break;
                default:    v_series[s]->setColor(Qt::gray);    break;}
            }
            else
            {
                QColor series_color;
                series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
                v_series[s]->setColor(series_color);
            }
        }

        //get data
        switch (MA_Data.type()) {

        case CV_8UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<uchar>(s, x)));
        }
            break;

        case CV_8SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<char>(s, x)));
        }
            break;

        case CV_16UC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<ushort>(s, x)));
        }
            break;

        case CV_16SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<short>(s, x)));
        }
            break;

        case CV_32SC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<int>(s, x)));
        }
            break;

        case CV_32FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<float>(s, x)));
        }
            break;

        case CV_64FC1://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<double>(s, x)));
        }
            break;

        case CV_8UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2b>(0, x)[s]));
        }
            break;

        case CV_8UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3b>(0, x)[s]));
        }
            break;

        case CV_8UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4b>(0, x)[s]));
        }
            break;

        case CV_16UC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2w>(0, x)[s]));
        }
            break;

        case CV_16UC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3w>(0, x)[s]));
        }
            break;

        case CV_16UC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4w>(0, x)[s]));
        }
            break;

        case CV_16SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2s>(0, x)[s]));
        }
            break;

        case CV_16SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3s>(0, x)[s]));
        }
            break;

        case CV_16SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4s>(0, x)[s]));
        }
            break;

        case CV_32SC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2i>(0, x)[s]));
        }
            break;

        case CV_32SC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3i>(0, x)[s]));
        }
            break;

        case CV_32SC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4i>(0, x)[s]));
        }
            break;

        case CV_32FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2f>(0, x)[s]));
        }
            break;

        case CV_32FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3f>(0, x)[s]));
        }
            break;

        case CV_32FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4f>(0, x)[s]));
        }
            break;

        case CV_64FC2://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec2d>(0, x)[s]));
        }
            break;

        case CV_64FC3://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec3d>(0, x)[s]));
        }
            break;

        case CV_64FC4://---------------------------------------------
        {
            for(size_t s = 0; s < series_count; s++)
                for(size_t x = 0; x < x_count; x++)
                    v_series[s]->append(x * PlotX_Step + PlotX_Offset, F_Trafo(MA_Data.at<Vec4d>(0, static_cast<int>(x))[static_cast<int>(s)]));
        }
            break;

        default://---------------------------------------------
            return;
        }

        //add stuff (for all img types)
        for(size_t s = 0; s < series_count; s++)
        {
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }
        break;

    default:
        return;
    }

    //cosmetic
    chart->legend()->setVisible(true);
    //chart->legend()->setAlignment(legend_pos);

    //attach chart
    CV_View->setChart(chart);
}

bool D_Viewer::Is_MouseOverScene(int x, int y)
{
    if(zoom_active)
        return (x >= 0) && (x < MA_Zoom.cols) && (y >= 0) && (y < MA_Zoom.rows);
    else
        return (x >= 0) && (x < MA_Data.cols) && (y >= 0) && (y < MA_Data.rows);
}

bool D_Viewer::CalcRelativePos(int x, int y)
{
    //relative position
    cursor_x_rel = x / (static_cast<double>(QI_View.width())  * scale_x);
    cursor_y_rel = y / (static_cast<double>(QI_View.height()) * scale_y);
    return true;
}

bool D_Viewer::Scene2OriginalXY_Scale(int *x, int *y)
{
    //scaling of scene
    *x /= scale_x;
    *y /= scale_y;

    //mouse over scene?
    return Is_MouseOverScene(*x, *y);
}

bool D_Viewer::Scene2OriginalXY_Offset(int *x, int *y)
{
    //offset of zoom
    if(zoom_active)
    {
        *x += zoom_offset_x;
        *y += zoom_offset_y;
    }

    return true;
}

bool D_Viewer::Scene2OriginalXY_Transform(int *x, int *y)
{
    //Scale
    if(!Scene2OriginalXY_Scale(x, y))
        return false;

    //Offset
    return Scene2OriginalXY_Offset(x, y);
}

void D_Viewer::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Vievwer", func, detail);
}

void D_Viewer::Set_Image(Mat *MA_new)
{
    MA_Data = MA_new->clone();

    emit TypeChanged();
    emit TypeChanged_MA();
    emit TypeChanged_MA(D_Img_Proc::Type_of_Mat(&MA_Data));

    emit Image_Size_Changed();
    emit Image_Size_Changed(
                MA_Data.cols,
                MA_Data.rows);
    emit Image_Size_Changed(
                QString::number(MA_Data.cols) + "/" +
                QString::number(MA_Data.rows));
}

void D_Viewer::Update_Image(Mat *MA_new)
{
    Set_Image(MA_new);
    Update_Image();
}

void D_Viewer::Update_Image()
{
    Proc_ShowImgOrPlot();
}

void D_Viewer::Update_View()
{
    Proc_QI_2_PX();
}

QString D_Viewer::Save_Image_Dialog()
{
    QString name_default = FI_LastSaved.dir().path() + "/" + FI_LastSaved.baseName();

    QFileInfo FI_save(name_default + ".jpg");
    int count = 1;
    while(FI_save.exists())
        FI_save.setFile(name_default + "_" + QString::number(count) + ".jpg");

    QString path = QFileDialog::getSaveFileName(
                this,
                "Save Image: " + QS_Name,
                name_default,
                tr("Images (*.png *.jpg *.bmp *.tif)"));

    if(path == 0)
        return path;

    return Save_Image(path);
}

QString D_Viewer::Save_Image_Dialog(QString path_default)
{
    QFileInfo FI_saveDefault(path_default);
    QString name_default = FI_saveDefault.dir().path() + "/" + FI_saveDefault.baseName();

    QFileInfo FI_save(name_default + ".jpg");
    int count = 1;
    while(FI_save.exists())
        FI_save.setFile(name_default + "_" + QString::number(count) + ".jpg");

    QString path = QFileDialog::getSaveFileName(
                this,
                "Save Image: " + QS_Name,
                name_default,
                tr("Images (*.png *.jpg *.bmp *.tif)"));

    if(path == 0)
        return path;

    return Save_Image(path);
}

QString D_Viewer::Save_Image()
{
    return Save_Image(FI_LastSaved.absoluteFilePath());
}

QString D_Viewer::Save_Image(QString path)
{
    if(path == 0)
        return path;

    if(QI_View.save(path, 0, -1))
        FI_LastSaved.setFile(path);

    emit Image_Saved();
    emit Image_Saved(path);

    return path;
}

void D_Viewer::Set_ViewerMode(int mode)
{
    if(mode < 0 || mode >= c_VIEWER_MODE_NUMBER_OF)
    {
        ERR(
                    ER_parameter_bad,
                    "Set_ViewerMode " + QString::number(mode),
                    "Bad viewer mode");
        return;
    }

    if(!state_CV_set)
    {
        ERR(
                    ER_other,
                    "Set_ViewerMode " + QSL_ViewerMode[mode],
                    "ChartView not init");
        return;
    }

    ViewerMode = mode;
    Proc_ShowImgOrPlot();
}

void D_Viewer::Set_Transformation_Mode(bool smooth)
{
    if(smooth)
        TransMode = Qt::SmoothTransformation;
    else
        TransMode = Qt::FastTransformation;

    Update_View();
}

void D_Viewer::Set_Aspect_Mode(bool keep)
{
    if(keep)
        AspectMode = Qt::KeepAspectRatio;
    else
        AspectMode = Qt::IgnoreAspectRatio;

    Update_View();
}

void D_Viewer::Set_Zomm(double x_rel, double y_rel, double factor)
{
    cursor_x_rel = x_rel;
    cursor_y_rel = y_rel;
    zoom_factor_old = zoom_factor_cur;
    zoom_factor_cur = factor;

    blockSignals(true);
    Zoom_Update();
    blockSignals(false);
}

void D_Viewer::Set_ZoomReset()
{
    zoom_factor_old = zoom_factor_cur;
    zoom_factor_cur = 1.0;

    blockSignals(true);
    Zoom_Update();
    blockSignals(false);
}

void D_Viewer::MouseMoved(int x, int y)
{
    if(!Scene2OriginalXY_Scale(&x, &y))
        return;

    if(!Scene2OriginalXY_Offset(&x, &y))
        return;

    emit MouseMoved();

    emit MouseMoved_Pos(
                x,
                y);

    emit MouseMoved_Pos(
                "@" +
                QString::number(static_cast<int>(x)) + "/" +
                QString::number(static_cast<int>(y)));

    vector<double> vd_val;
    ERR(D_Img_Proc::ValAtPix(
            &vd_val,
            &MA_Data,
            x,
            y),
        "MouseMoved",
        "D_Img_Proc::ValAtPix Type:" + D_Img_Proc::Type_of_Mat(&MA_Data));
    emit MouseMoved_Value(vd_val);

    QString qs_val;
    ERR(D_Img_Proc::ValAtPix(
            &qs_val,
            &MA_Data,
            x,
            y),
        "MouseMoved",
        "D_Img_Proc::ValAtPix Type:" + D_Img_Proc::Type_of_Mat(&MA_Data));
    emit MouseMoved_Value(qs_val);
}

void D_Viewer::MouseClicked(int x, int y)
{
    if(!Scene2OriginalXY_Transform(&x, &y))
        return;

    emit MouseClicked();

    emit MouseClicked_Pos(
                x,
                y);

    emit MouseClicked_Pos(
                "@" +
                QString::number(static_cast<int>(x)) + "/" +
                QString::number(static_cast<int>(y)));

    vector<double> vd_val;
    ERR(D_Img_Proc::ValAtPix(
            &vd_val,
            &MA_Data,
            x,
            y),
        "MouseClicked",
        "D_Img_Proc::ValAtPix Type:" + D_Img_Proc::Type_of_Mat(&MA_Data));
    emit MouseClicked_Value(vd_val);

    QString qs_val;
    ERR(D_Img_Proc::ValAtPix(
            &qs_val,
            &MA_Data,
            x,
            y),
        "MouseClicked",
        "D_Img_Proc::ValAtPix Type:" + D_Img_Proc::Type_of_Mat(&MA_Data));
    emit MouseClicked_Value(qs_val);
}

void D_Viewer::MouseClicked_Left(int x, int y)
{
    if(!Scene2OriginalXY_Transform(&x, &y))
        return;

    emit MouseClickedLeft();

    emit MouseClickedLeft_Pos(
                x,
                y);
}

void D_Viewer::MouseClicked_Right(int x, int y)
{
    if(!Scene2OriginalXY_Transform(&x, &y))
        return;

    emit MouseClickedRight();

    emit MouseClickedRight_Pos(
                x,
                y);
}

void D_Viewer::MouseClicked_Mid(int x, int y)
{
    if(!Scene2OriginalXY_Transform(&x, &y))
        return;

    emit MouseClickedMid();

    emit MouseClickedMid_Pos(
                x,
                y);
}

void D_Viewer::Zoom_Pos(int x, int y)
{
    CalcRelativePos(x, y);
    if(!Scene2OriginalXY_Scale(&x, &y))
        return;

    if(zoom_active)
        Zoom_Update();
}

void D_Viewer::Zoom_In()
{
    zoom_factor_old = zoom_factor_cur;
    zoom_factor_cur /= zoom_step;
    Zoom_Update();
}

void D_Viewer::Zoom_Out()
{
    zoom_factor_old = zoom_factor_cur;
    zoom_factor_cur *= zoom_step;
    Zoom_Update();
}

void D_Viewer::Zoom_Reset()
{
    zoom_factor_old = zoom_factor_cur;
    zoom_factor_cur = 1.0;
    Zoom_Update();
}

void D_Viewer::Zoom_Update()
{
    if(zoom_factor_cur < zoom_factor_min)   zoom_factor_cur = zoom_factor_min;
    if(zoom_factor_cur > 1.0)               zoom_factor_cur = 1.0;

    //zoomed?
    if(zoom_factor_cur < 1.0)
        zoom_active = true;
    else
        zoom_active = false;

    if(zoom_factor_cur != zoom_factor_old)
        zoom_changed = true;
    else
        zoom_changed = false;

    //show
    Proc_ShowImgOrPlot();

    zoom_factor_old = zoom_factor_cur;
}
