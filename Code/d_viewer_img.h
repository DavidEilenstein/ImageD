#ifndef D_VIEWER_IMG_H
#define D_VIEWER_IMG_H

//own
#include <d_enum.h>
#include <scenemousetrack.h>
#include <d_img_proc.h>
#include <d_error_handler.h>

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

//Qt-Charts

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_Viewer_Img : public QGraphicsView
{
    Q_OBJECT

public:
    D_Viewer_Img();

    //setter
    void                    set_Name(QString viewer_name)       {QS_Name = viewer_name;}
    void                    clear_Image();

    //get pointers to members
    Mat                     *MA()                               {return &MA_View;}
    QImage                  *QI()                               {return &QI_View;}
    QPixmap                 *PX()                               {return &PX_View;}
    SceneMouseTrack         *SC()                               {return &SC_View;}

    //image attributes
    QString                 Type_MA()                           {return D_Img_Proc::Type_of_Mat(&MA_View);}
    QString                 Type_QI()                           {return D_Img_Proc::Type_of_QImage(&QI_View);}
    int                     img_width()                         {return MA_View.cols;}
    int                     img_height()                        {return MA_View.rows;}
    double                  img_val_min();
    double                  img_val_max();
    double                  img_val_range();

    //view attributes
    double                  scale_f_x()                         {return scale_x;}
    double                  scale_f_y()                         {return scale_y;}

private:
    void        Init                    ();

    //Processing image->view
    void        Proc_MA_2_QI            ();
    void        Proc_QI_2_PX            ();
    void        Proc_PX_Scale           ();
    void        Proc_PX_2_SC            ();

    //check if mouse is over image
    bool        Is_MouseOverScene       (int x, int y);

    //Error Handling
    D_Error_Handler ER;
    void            ERR                 (int err, QString func = "not specified", QString detail = "not specified");

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
    void        Set_Transformation_Mode (bool smooth);
    void        Set_Aspect_Mode         (bool keep);
    void        Set_GammaSpread         (int gammaspread = 1)           {gs_active = (bool) gammaspread;    Proc_MA_2_QI();}
    void        Set_Gamma               (double gamma = 1)              {gs_gamma = gamma;                  Proc_MA_2_QI();}
    void        Set_SpreadInMin         (double spread_min = 0)         {gs_in_min = spread_min;            Proc_MA_2_QI();}
    void        Set_SpreadInMax         (double spread_max = 255)       {gs_in_max = spread_max;            Proc_MA_2_QI();}
    void        Set_SpreadOutMin        (double spread_min = 0)         {gs_out_min = spread_min;           Proc_MA_2_QI();}
    void        Set_SpreadOutMax        (double spread_max = 255)       {gs_out_max = spread_max;           Proc_MA_2_QI();}
    void        Set_Zomm                (int x, int y, double factor);

    //slots recieved on actions in scene
    void        MouseMoved              (int x, int y);
    void        MouseClicked            (int x, int y);
    void        MouseScrolled           (int x, int y, int delta);
    void        MouseScrolled_Ctrl      (int x, int y, int delta);

    //zoom
    void        Update_Zoom();

signals:

    //mouse event
    void MouseMoved         ();
    void MouseMoved_Pos     (int x, int y);
    void MouseMoved_Pos     (QString pos);
    void MouseMoved_Value   (vector<double> val);
    void MouseMoved_Value   (QString val);
    void MouseClicked       ();
    void MouseClicked_Pos   (int x, int y);
    void MouseClicked_Pos   (QString pos);
    void MouseClicked_Value (vector<double> val);
    void MouseClicked_Value (QString val);

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
    void Zoomed             (int x, int y, double factor);

    //times
    void Time_View_Update   (unsigned int time_ms);
    void Time_Image_Cvt     (unsigned int time_ms);

    //saved
    void Image_Saved        ();
    void Image_Saved        (QString path);

private:
    //basic elements
    Mat                     MA_View;
    Mat                     MA_View_GS;
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

    bool                    zoom_active;
    int                     zoom_at_x       = 0;
    int                     zoom_at_y       = 0;
    double                  zoom_factor     = 1.00;
    double                  zoom_step       = 0.25;

    bool                    gs_active       = false;
    double                  gs_gamma        = 1;
    double                  gs_in_min       = 0;
    double                  gs_in_max       = 255;
    double                  gs_out_min      = 0;
    double                  gs_out_max      = 255;

    //other
    QString                 QS_Name = "Viewer";

    //times
    QElapsedTimer           QET_view;
    unsigned int            time_view;
    QElapsedTimer           QET_convert;
    unsigned int            time_convert;
};

#endif // D_VIEWER_IMG_H
