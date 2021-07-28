/************************************
 *   added:     ??.??.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIDEOSLICER_H
#define D_VIDEOSLICER_H

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
 * \brief The D_VideoSlicer class Extracts frames from videos as images.
 * \details Used do process videos in a memory saving way.
 */
class D_VideoSlicer
{
public:
    D_VideoSlicer();
    D_VideoSlicer(string S_VideoPath);
    D_VideoSlicer(QString QS_VideoPath);
    D_VideoSlicer(QFileInfo FI_VideoPath);

    //setter
    int         set_VideoPath(string S_VideoPath);
    int         set_VideoPath(QString QS_VideoPath);
    int         set_VideoPath(QFileInfo FI_VideoPath);

    //getter: frame
    bool        is_NextFrameExistent();
    Mat         get_FramePos(int frame_number);
    int         get_FramePos(Mat* MA_Frame, int frame_number);
    Mat         get_FrameNext();
    int         get_FrameNext(Mat* MA_Frame);

    //getter: information
    double      get_FrameRateHz()       {return state_FileValid ? prop_Framerate : -1;}
    double      get_FrameRateFps()      {return state_FileValid ? prop_Framerate : -1;}
    double      get_FrameRateFpm()      {return state_FileValid ? prop_Framerate * 60.0 : -1;}
    double      get_FrameTimeSec()      {return state_FileValid ? prop_FrameTime : -1;}
    double      get_FrameTimeMin()      {return state_FileValid ? prop_FrameTime / 60.0 : -1;}
    double      get_DurationSec()       {return state_FileValid ? prop_Duration : -1;}
    double      get_DurationMin()       {return state_FileValid ? prop_Duration / 60.0 : -1;}
    long int    get_FrameCount()        {return state_FileValid ? prop_FrameCount : -1;}
    int         get_Width()             {return state_FileValid ? prop_Width : -1;}
    int         get_Height()            {return state_FileValid ? prop_Height : -1;}
    Size        get_FrameSize()         {return state_FileValid ? prop_FrameSize : Size(1, 1);}
    QString     get_Name()              {return state_FileValid ? prop_Name : "not_set";}
    QString     get_Suffix()            {return state_FileValid ? prop_Suffix : "not_set";}
    QString     get_PathSourceFull()    {return state_FileValid ? FI_Source.absoluteFilePath() : "not_set";}
    double      get_timeSec_2_frame()   {return state_FileValid ? prop_Framerate : -1;}
    double      get_frame_2_timeSec()   {return state_FileValid ? prop_FrameTime : -1;}

private:

    //File to process
    QFileInfo           FI_Source;
    QDir                DIR_Source;

    //read video
    VideoCapture        VC_Source;

    //Frame cursor
    int                 cursor_FrameCurrent = 0;

    //File properties
    double              prop_Framerate = 24.0;
    double              prop_FrameTime = 1 / 24.0;
    long int            prop_FrameCount = 1;
    int                 prop_Width = 1;
    int                 prop_Height = 1;
    Size                prop_FrameSize = Size(1, 1);
    double              prop_Duration = 1 / 24.0;
    QString             prop_Name = "";
    QString             prop_Suffix = "";

    //States
    bool                state_FileValid = false;
};

#endif // D_VIDEOSLICER_H
