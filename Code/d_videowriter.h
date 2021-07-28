/************************************
 *   added:     21.04.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIDEOWRITER_H
#define D_VIDEOWRITER_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_component_list_context.h>
#include <d_value_distribution_list.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <thread>

//Qt
#include <QObject>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_VideoWriter class Creates a video from a sequence of images and saves it as a file.
 */
class D_VideoWriter
{
public:
    D_VideoWriter();

    //setter
    int         set_PathOut(string S_OutPath);
    int         set_PathOut(QString QS_OutPath);
    int         set_PathOut(QFileInfo FI_OutPath);
    int         set_Size(Size size_out);
    int         set_Size(int width, int height);
    int         set_FPS(double fps);
    int         set_isColor(bool is_color);

    int         init_VideoWriter();
    bool        is_Init();

    int         AddFrame(Mat frame2add);
    int         AddFrame(Mat *frame2add);
    int         EndVideoWriting();

private:

    //Destination Information
    QFileInfo           FI_Out;
    QDir                DIR_Out;
    Size                prop_SizeOut = Size(1,1);
    double              prop_FPS = 24;
    int                 prop_FourCC = CV_FOURCC('M','J','P','G');
    bool                prop_isColor = true;

    //read video
    VideoWriter         VW_Destination;

    //States
    bool                state_isSet_DestinationPath = false;
    bool                state_isSet_FourCC = true;
    bool                state_isSet_FrameSize = false;
    bool                state_isSet_FPS = false;
    bool                state_isSet_isColor = false;
    bool                state_ready2write = false;
    bool                is_ready2write();
    bool                state_isInit = false;
};

#endif // D_VIDEOWRITER_H
