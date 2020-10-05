#include "d_viewer_img.h"

D_Viewer_Img::D_Viewer_Img()
{
    Init();
}

void D_Viewer_Img::clear_Image()
{
    MA_View = Mat(3, 3, CV_8UC1, Scalar(127));
    MA_View_GS = Mat(3, 3, CV_8UC1, Scalar(127));
    Proc_MA_2_QI();
}

double D_Viewer_Img::img_val_min()
{
    double min;
    double max;

    D_Img_Proc::MinMax_of_Mat(
                &MA_View,
                &min,
                &max);

    return min;
}

double D_Viewer_Img::img_val_max()
{
    double min;
    double max;

    D_Img_Proc::MinMax_of_Mat(
                &MA_View,
                &min,
                &max);

    return max;
}

double D_Viewer_Img::img_val_range()
{
    double min;
    double max;

    D_Img_Proc::MinMax_of_Mat(
                &MA_View,
                &min,
                &max);

    return max - min;
}

void D_Viewer_Img::Init()
{
    setScene(&SC_View);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setInteractive(true);

    clear_Image();

    connect(&SC_View,   SIGNAL(mouseMoved(int,int)),                        this,       SLOT(MouseMoved(int,int)));
    connect(&SC_View,   SIGNAL(MouseClickedAtPos(int,int)),                 this,       SLOT(MouseClicked(int,int)));
    connect(&SC_View,   SIGNAL(MouseScrolledAtPos(int,int,int)),            this,       SLOT(MouseScrolled(int,int,int)));
    connect(&SC_View,   SIGNAL(MouseScrolledAtPos_Ctrl(int,int,int)),       this,       SLOT(MouseScrolled_Ctrl(int,int,int)));
}

void D_Viewer_Img::Proc_MA_2_QI()
{
    QET_convert.start();

    if(gs_active)
    {
        ERR(D_Img_Proc::GammaSpread(
                &MA_View_GS,
                &MA_View,
                gs_gamma,
                gs_in_min,
                gs_in_max,
                gs_out_min,
                gs_out_max));

        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &QI_View,
                &MA_View_GS));
    }
    else
    {
        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &QI_View,
                &MA_View));
    }

    time_convert = static_cast<unsigned int>(QET_convert.elapsed());

    emit Time_Image_Cvt(time_convert);
    emit TypeChanged();
    emit TypeChanged_QI();
    emit TypeChanged_QI(D_Img_Proc::Type_of_QImage(&QI_View));

    Proc_QI_2_PX();
}

void D_Viewer_Img::Proc_QI_2_PX()
{
    QET_view.start();

    PX_View = QPixmap::fromImage(QI_View);

    if(scale)
        Proc_PX_Scale();

    Proc_PX_2_SC();
}

void D_Viewer_Img::Proc_PX_Scale()
{
    PX_View = PX_View.scaled(
                GV_View->width() - 2,
                GV_View->height() - 2,
                AspectMode,
                TransMode);

    scale_x = (double) PX_View.width() / QI_View.width();
    scale_y = (double) PX_View.height() / QI_View.height();

    emit Scaled();

    emit Scaled_Factor(
                scale_x,
                scale_y);

    emit Scaled_Factor(
                QString::number(scale_x, 'g', 2) + "/" +
                QString::number(scale_y, 'g', 2));

    emit Scaled_Factor_Prz(
                QString::number((int)(scale_x * 100.0)) + "%/" +
                QString::number((int)(scale_y * 100.0)) + "%");
}

void D_Viewer_Img::Proc_PX_2_SC()
{
    SC_View.clear();
    SC_View.setSceneRect(this->rect());//???
    SC_View.addPixmap(PX_View);

    time_view = static_cast<unsigned int>(QET_view.elapsed());

    emit Time_View_Update(time_view);
    emit View_Updated();
}

bool D_Viewer_Img::Is_MouseOverScene(int x, int y)
{
    return (x >= 0) && (x < MA_View.cols) && (y >= 0) && (y < MA_View.rows);
}

void D_Viewer_Img::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Viewer: " + QS_Name, func, detail);
}

void D_Viewer_Img::Set_Image(Mat *MA_new)
{
    MA_View = MA_new->clone();

    emit TypeChanged();
    emit TypeChanged_MA();
    emit TypeChanged_MA(D_Img_Proc::Type_of_Mat(&MA_View));

    emit Image_Size_Changed();
    emit Image_Size_Changed(
                MA_View.cols,
                MA_View.rows);
    emit Image_Size_Changed(
                QString::number(MA_View.cols) + "/" +
                QString::number(MA_View.rows));
}

void D_Viewer_Img::Update_Image(Mat *MA_new)
{
    Set_Image(MA_new);
    Update_Image();
}

void D_Viewer_Img::Update_Image()
{
    Proc_MA_2_QI();
}

void D_Viewer_Img::Update_View()
{
    Proc_QI_2_PX();
}

QString D_Viewer_Img::Save_Image_Dialog()
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

QString D_Viewer_Img::Save_Image_Dialog(QString path_default)
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

QString D_Viewer_Img::Save_Image()
{
    return Save_Image(FI_LastSaved.absoluteFilePath());
}

QString D_Viewer_Img::Save_Image(QString path)
{
    if(path == 0)
        return path;

    if(QI_View.save(path, 0, -1))
        FI_LastSaved.setFile(path);

    emit Image_Saved();
    emit Image_Saved(path);

    return path;
}

void D_Viewer_Img::Set_Transformation_Mode(bool smooth)
{
    if(smooth)
        TransMode = Qt::SmoothTransformation;
    else
        TransMode = Qt::FastTransformation;

    Update_View();
}

void D_Viewer_Img::Set_Aspect_Mode(bool keep)
{
    if(keep)
        AspectMode = Qt::KeepAspectRatio;
    else
        AspectMode = Qt::IgnoreAspectRatio;

    Update_View();
}

void D_Viewer_Img::Set_Zomm(int x, int y, double factor)
{

}

void D_Viewer_Img::MouseMoved(int x, int y)
{
    x /= scale_x;
    y /= scale_y;

    if(!Is_MouseOverScene(x, y))
        return;

    emit MouseMoved();

    emit MouseMoved_Pos(
                x,
                y);

    emit MouseMoved_Pos(
                "@" +
                QString::number((int)x) + "/" +
                QString::number((int)y));

    vector<double> vd_val;
    ERR(D_Img_Proc::ValAtPix(
            &vd_val,
            &MA_View,
            x,
            y));
    emit MouseMoved_Value(vd_val);

    QString qs_val;
    ERR(D_Img_Proc::ValAtPix(
            &qs_val,
            &MA_View,
            x,
            y));
    emit MouseMoved_Value(qs_val);
}

void D_Viewer_Img::MouseClicked(int x, int y)
{
    x /= scale_x;
    y /= scale_y;

    if(!Is_MouseOverScene(x, y))
        return;

    emit MouseClicked();

    emit MouseClicked_Pos(
                x,
                y);

    emit MouseClicked_Pos(
                "@" +
                QString::number((int)x) + "/" +
                QString::number((int)y));

    vector<double> vd_val;
    ERR(D_Img_Proc::ValAtPix(
            &vd_val,
            &MA_View,
            x,
            y));
    emit MouseClicked_Value(vd_val);

    QString qs_val;
    ERR(D_Img_Proc::ValAtPix(
            &qs_val,
            &MA_View,
            x,
            y));
    emit MouseClicked_Value(qs_val);
}

void D_Viewer_Img::MouseScrolled(int x, int y, int delta)
{

}

void D_Viewer_Img::MouseScrolled_Ctrl(int x, int y, int delta)
{
    //scale
    x /= scale_x;
    y /= scale_y;

    if(!Is_MouseOverScene(x, y))
        return;

    //pos
    zoom_at_x   = x;
    zoom_at_y   = y;

    //factor
    double zoom_factor_new = zoom_factor - delta * zoom_step;
    if(zoom_factor_new > 1.0)
        zoom_factor = zoom_factor_new;
    else
        zoom_factor = 1.0;

     if(zoom_factor > 1.0)
        zoom_active = true;
    else
        zoom_active = false;

     if(zoom_active)
         Update_Zoom();
}

void D_Viewer_Img::Update_Zoom()
{
    qDebug() << "zoom" << zoom_at_x << zoom_at_y << zoom_factor;



    emit Zoomed(zoom_at_x, zoom_at_y, zoom_factor);
}
