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
#include <QLabel>

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
    int init(QGridLayout *target_layout);

    //clear

    //plot boring
    int     plot_empty();
    int     plot_test();
    int     plot_img2D_gray(Mat *pMA_img);

    //plot cool
    int     plot_VD_custom(D_VisDat_Obj *pVD, size_t mode, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v, int marker, int shadow, bool background, bool grid, bool smooth);
    int     plot_ScatterData_4D(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vV, size_t color_handle, int marker, int shadow, bool background, bool grid, bool smooth, bool called_internally = false);

signals:


private:
    void    clear_layout();
    bool    PutGraphInLayout(Q3DScatter *graph);
    void    PutContainerInLayout(QWidget *container_widget);

    //error handler
    D_Error_Handler ER;
    void ERR(int err, QString func, QString detail);

    //ui
    QGridLayout *layout_in_ui;
    //QWidget *container_widget;

    //data
    //Q3DScatter *scatter_graph;

    //states
    bool state_ui_init = false;
    bool state_container_widget_exists = false;
    bool state_plot_active = false;
    bool state_plotting = false;
};

enum MARKER_3D {
    MARKER_3D_POINT,
    MARKER_3D_MINIMAL,
    MARKER_3D_PYRAMID,
    MARKER_3D_CUBE,
    MARKER_3D_CYLINDER,
    MARKER_3D_SPHERE,
    MARKER_3D_ARROW,
    MARKER_3D_NUMBER_OF
};
const QStringList QSL_Marker_3D = {
    "Point",
    "Minimal",
    "Pyramid",
    "Cube",
    "Cylinder",
    "Sphere",
    "Arrow"
};

const QStringList QSL_ShadowQuality_3D = {
    "None",
    "Low",
    "Medium",
    "High",
    "Soft Low",
    "Soft Medium",
    "Soft High"
};

#endif // D_VIEWER_3D_H
