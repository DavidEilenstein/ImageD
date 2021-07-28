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

//general
#include <iostream>
#include <vector>

//Qt
#include <QObject>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QElapsedTimer>
#include <QScrollBar>

//Qt-Datavisualization
#include <QtDataVisualization/Q3DScatter>

//openCV
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>
//using namespace QtDataVisualization;

class D_Viewer_3D
{
public:
    D_Viewer_3D();

private:

    //QtDataVisualization::Q3DScatter *m_graph;
};

#endif // D_VIEWER_3D_H
