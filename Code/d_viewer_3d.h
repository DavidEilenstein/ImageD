/************************************
 *   added:     27.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIEWER_3D_H
#define D_VIEWER_3D_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QWidget>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QElapsedTimer>
#include <QScrollBar>
#include <QGridLayout>
#include <QWidget>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtWidgets/QComboBox>

//Qt-Datavisualization
#include <QtDataVisualization>
#include <QtDataVisualization/q3dscatter.h>
#include <QtDataVisualization/qabstract3dseries.h>
#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/q3dtheme.h>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>
using namespace QtDataVisualization;

class D_Viewer_3D : public QWidget
{
    Q_OBJECT

public:
    D_Viewer_3D();
    D_Viewer_3D(QGridLayout *target_layout);
    ~D_Viewer_3D();

    //init basic stuff and ui
    void init(QGridLayout *target_layout);

    //clear
    void    clear();
    void    plot_test();
    int     plot_img2D_gray(Mat *pMA_img);

    int     plot_VD_custom(D_VisDat_Obj *pVD, size_t mode, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v);
    int     plot_ScatterData_4D(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vV, size_t color_handle);

private:

    //error handler
    D_Error_Handler ER;
    void ERR(int err, QString func, QString detail);

    //ui
    QWidget *container_widget;

    //data
    Q3DScatter *scatter_graph;

    //cosmetic stuff
    int                             style_font_size = 40;
    Q3DTheme::Theme                 style_theme = Q3DTheme::ThemeEbony;
    QAbstract3DGraph::ShadowQuality style_shadow_quality = QAbstract3DGraph::ShadowQualityNone;
    bool                            style_smooth = false;

    //states
    bool state_ui_init = false;
};

#endif // D_VIEWER_3D_H
