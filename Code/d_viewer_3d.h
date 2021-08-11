/************************************
 *   added:     11.08.2021          *
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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
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
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurfaceDataArray>
#include <QtDataVisualization/QCustom3DVolume>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of ambigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>
using namespace QtDataVisualization;

class D_Viewer_3D : public QWidget
{
    Q_OBJECT

public:
    D_Viewer_3D();
    D_Viewer_3D(QGridLayout *target_layout);
    ~D_Viewer_3D();

    //init
    void init(QGridLayout *target_layout);

signals:


private:

   //error handler
    D_Error_Handler ER;
    void ERR(int err, QString func, QString detail);

    //ui elements
    //layouts
    QGridLayout     *ui_layout_target;
    QHBoxLayout     *ui_layoutH_main;
    QGroupBox       *ui_GroupBox_3D_graph;
    QGroupBox       *ui_GroupBox_2D_slices;
    QGroupBox       *ui_GroupBox_Settings;
    QGroupBox       *ui_GroupBox_Settings_Volume;
    QGroupBox       *ui_GroupBox_Settings_DrawCondition;
    QGroupBox       *ui_GroupBox_Settings_Alpha;
    QGroupBox       *ui_GroupBox_Settings_Graphics;




    //graph elements
    Q3DScatter      *graph_scatter;
    QWidget         *container_widget_scatter;

    //VD to be displayed
    D_VisDat_Obj    *pVD_Data;

    //states
    bool            state_ui_init = false;
    bool            state_VD_set = false;
};



#endif // D_VIEWER_3D_H
