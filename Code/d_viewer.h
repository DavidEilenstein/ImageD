/************************************
 *   added:     02.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIEWER_H
#define D_VIEWER_H

//own
#include <d_enum.h>
#include <scenemousetrack.h>
#include <d_img_proc.h>
#include <d_error_handler.h>
#include <d_plot.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QElapsedTimer>
#include <QScrollBar>

//Qt-Charts
#include <QChartView>
#include <QChart>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_Viewer : public QWidget
{
    Q_OBJECT

public:

    //constructors
    D_Viewer();
    D_Viewer(QGraphicsView *GV_ui);
    D_Viewer(QGraphicsView *GV_ui, QString viewer_name);
    D_Viewer(QGraphicsView *GV_ui, QDir default_dir);
    D_Viewer(QGraphicsView *GV_ui, QDir default_dir, QString viewer_name);

    //setter
    void                    set_GV(QGraphicsView *GV_ui);
    void                    set_CV(QtCharts::QChartView *CV_ui);
    void                    set_Name(QString viewer_name);
    void                    clear_Image();

    //connector
    void                    connect_Zoom(D_Viewer *viewer);

    //get pointers to members
    Mat                     *MA()           {return &MA_Data;}
    QImage                  *QI()           {return &QI_View;}
    QPixmap                 *PX()           {return &PX_View;}
    SceneMouseTrack         *SC()           {return &SC_View;}
    QGraphicsView           *GV()           {return GV_View;}

    //image attributes
    QString                 Type_MA()       {return D_Img_Proc::Type_of_Mat(&MA_Data);}
    QString                 Type_QI()       {return D_Img_Proc::Type_of_QImage(&QI_View);}
    unsigned int            img_width()     {return MA_Data.cols;}
    unsigned int            img_height()    {return MA_Data.rows;}
    double                  img_val_min();
    double                  img_val_max();
    double                  img_val_range();

    //view attributes
    double                  scale_f_x()     {return scale_x;}
    double                  scale_f_y()     {return scale_y;}
    double                  zoom_x_rel()    {return cursor_x_rel;}
    double                  zoom_y_rel()    {return cursor_y_rel;}
    double                  zoom_fact()     {return zoom_factor_cur;}

private:
    void        Init                        (QGraphicsView *GV_ui);

    //Processing image->view
    void        Proc_ShowImgOrPlot          ();
    void        Proc_MA_2_QI                ();
    void        Proc_QI_2_PX                ();
    void        Proc_PX_Scale               ();
    void        Proc_PX_2_SC                ();
    void        Proc_Plot                  ();

    //check if mouse is over image
    bool        Is_MouseOverScene           (int x,  int y);
    bool        CalcRelativePos             (int x,  int y);
    bool        Scene2OriginalXY_Scale      (int *x, int *y);
    bool        Scene2OriginalXY_Offset     (int *x, int *y);
    bool        Scene2OriginalXY_Transform  (int *x, int *y);

    //Error Handling
    D_Error_Handler ER;
    void            ERR                     (int err, QString func = "not specified", QString detail = "not specified");

private slots:

    //zoom (connected with signals of scene while ctrl is pressed)
    void        Zoom_Pos                (int x, int y);
    void        Zoom_In                 ();
    void        Zoom_Out                ();
    void        Zoom_Reset              ();
    void        Zoom_Update             ();

public slots:

    //Update image/view
    void        Set_Image               (Mat *MA_new);
    void        Update_Image            (Mat *MA_new);
    void        Update_Image            ();
    void        Update_View             ();

    //save image
    QString     Save_Image_Dialog       ();
    QString     Save_Image_Dialog       (QString path_default);
    QString     Save_Image              ();
    QString     Save_Image              (QString path);

    //Viewer options
    void        Set_ViewerMode          (int mode);
    void        Set_Transformation_Mode (bool smooth);
    void        Set_Aspect_Mode         (bool keep);
    void        Set_PlotType            (int mode)                                  {PlotType = mode;                           Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_ActiveInt  (int active = 1)                            {Set_VisTrafo_ActiveBool(active);}
    void        Set_VisTrafo_ActiveBool (bool active = true)                        {vis_trafo_active = active;                 Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Gamma      (double gamma = 1)                          {vis_trafo_gamma = gamma;                   Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_SpreadInMin(double spread_min = 0)                     {vis_trafo_in_min = spread_min;             Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_SpreadInMax(double spread_max = 255)                   {vis_trafo_in_max = spread_max;             Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Center     (double center = 0)                         {vis_trafo_center = center;                 Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Divisor    (double divisor = 0)                        {vis_trafo_divisor = divisor;               Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Anchor     (double anchor = 127.5)                     {vis_trafo_anchor = anchor;                 Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Range      (double range = 127.5)                      {vis_trafo_range = range;                   Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Mode_Crop  (int mode = c_VIS_TRAFO_CROP_DYNAMIC)       {vis_trafo_mode_crop = mode;                Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Mode_Trafo (int mode = c_VIS_TRAFO_LINEAR)             {vis_trafo_mode_trafo = mode;               Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Mode_Anchor(int mode = c_VIS_TRAFO_ANCHOR_DYNAMIC)     {vis_trafo_mode_anchor = mode;              Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Mode_Range (int mode = c_VIS_TRAFO_RANGE_DYNAMIC)      {vis_trafo_mode_range = mode;               Proc_ShowImgOrPlot();}
    void        Set_VisTrafo_Mode_Complex(int mode = c_COMPLEX2REAL_RE_IM)          {vis_trafo_mode_complex = mode;             Proc_ShowImgOrPlot();}
    void        Set_Zomm                (double x_rel, double y_rel, double factor);
    void        Set_ZoomReset           ();

    //slots recieved on actions in scene
    void        MouseMoved              (int x, int y);
    void        MouseClicked            (int x, int y);
    void        MouseClicked_Left       (int x, int y);
    void        MouseClicked_Right      (int x, int y);
    void        MouseClicked_Mid        (int x, int y);

signals:

    //mouse event
    void MouseMoved             ();
    void MouseMoved_Pos         (int x, int y);
    void MouseMoved_Pos         (QString pos);
    void MouseMoved_Value       (vector<double> val);
    void MouseMoved_Value       (QString val);
    void MouseClicked           ();
    void MouseClickedLeft       ();
    void MouseClickedRight      ();
    void MouseClickedMid        ();
    void MouseClicked_Pos       (int x, int y);
    void MouseClickedLeft_Pos   (int x, int y);
    void MouseClickedRight_Pos  (int x, int y);
    void MouseClickedMid_Pos    (int x, int y);
    void MouseClicked_Pos       (QString pos);
    void MouseClicked_Value     (vector<double> val);
    void MouseClicked_Value     (QString val);

    //image event
    void TypeChanged        ();
    void TypeChanged_QI     ();
    void TypeChanged_QI     (QString type);
    void TypeChanged_MA     ();
    void TypeChanged_MA     (QString type);
    void Image_Size_Changed ();
    void Image_Size_Changed (int width, int height);
    void Image_Size_Changed (QString size);

    //view event
    void View_Updated       ();
    void Scaled             ();
    void Scaled_Factor      (double f_x, double f_y);
    void Scaled_Factor      (QString scale);
    void Scaled_Factor_Prz  (QString scale_prz);
    void Zoomed             (double x_rel, double y_rel, double factor);
    void Zoomed_Reset       ();

    //times
    void Time_View_Update   (unsigned int time_ms);
    void Time_Image_Cvt     (unsigned int time_ms);

    //saved
    void Image_Saved        ();
    void Image_Saved        (QString path);

private:    //members

    //mode
    int ViewerMode          = c_VIEWER_MODE_IMG;

    //======================Plot======================== (newer than Image version)

    QtCharts::QChartView    *CV_View;
    bool                    state_CV_set = false;
    int                     PlotType = c_IMG2PLOT_LINE;
    QString                 QS_DimX = "X";
    double                  PlotX_Offset = 0;
    double                  PlotX_Step = 1;
    QString                 QS_DimY = "Data";



    //======================Image=======================

    //basic elements
    Mat                     MA_Data;
    Mat                     MA_Zoom;
    Mat                     MA_VisTrafo;
    QImage                  QI_View;
    QPixmap                 PX_View;
    SceneMouseTrack         SC_View;
    QGraphicsView           *GV_View;

    //paths
    QDir                    DIR_Default;
    QFileInfo               FI_LastSaved;

    //view attributes
    bool                    scale;
    double                  scale_x;
    double                  scale_y;

    Qt::TransformationMode  TransMode;
    Qt::AspectRatioMode     AspectMode;

    double                  cursor_x_rel = 0;
    double                  cursor_y_rel = 0;
    int                     zoom_offset_x = 0;
    int                     zoom_offset_y = 0;
    int                     zoom_width = 1;
    int                     zoom_height = 1;

    bool                    zoom_active     = false;
    bool                    zoom_changed    = false;
    const double            zoom_step       = 1.10;
    double                  zoom_factor_cur = 1.00;
    double                  zoom_factor_old = 1.00;
    double                  zoom_factor_min = 0.01;
    vector<D_Viewer*>       v_ConnectedViewersZoom;

    bool                    vis_trafo_active       = false;
    double                  vis_trafo_in_min       = 0;
    double                  vis_trafo_in_max       = 255;
    double                  vis_trafo_gamma        = 1.0;
    double                  vis_trafo_center       = 0.0;
    double                  vis_trafo_divisor      = 1.0;
    double                  vis_trafo_anchor       = 0;
    double                  vis_trafo_range        = 1;
    int                     vis_trafo_mode_crop    = c_VIS_TRAFO_CROP_DYNAMIC;
    int                     vis_trafo_mode_trafo   = c_VIS_TRAFO_LINEAR;
    int                     vis_trafo_mode_anchor  = c_VIS_TRAFO_ANCHOR_DYNAMIC;
    int                     vis_trafo_mode_range   = c_VIS_TRAFO_RANGE_DYNAMIC;
    int                     vis_trafo_mode_complex = c_COMPLEX2REAL_RE_IM;

    //other
    QString                 QS_Name = "Viewer";

    //times
    QElapsedTimer           QET_view;
    unsigned int            time_view;
    QElapsedTimer           QET_convert;
    unsigned int            time_convert;



};

#endif // D_VIEWER_H
