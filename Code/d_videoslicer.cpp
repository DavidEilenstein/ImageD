/************************************
 *   added:     ??.??.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_videoslicer.h"

D_VideoSlicer::D_VideoSlicer()
{

}

D_VideoSlicer::D_VideoSlicer(string S_VideoPath)
{
    set_VideoPath(S_VideoPath);
}

D_VideoSlicer::D_VideoSlicer(QString QS_VideoPath)
{
    set_VideoPath(QS_VideoPath);
}

D_VideoSlicer::D_VideoSlicer(QFileInfo FI_VideoPath)
{
    set_VideoPath(FI_VideoPath);
}

int D_VideoSlicer::set_VideoPath(string S_VideoPath)
{
    return set_VideoPath(QString::fromStdString(S_VideoPath));
}

int D_VideoSlicer::set_VideoPath(QString QS_VideoPath)
{
    return set_VideoPath(QFileInfo(QS_VideoPath));
}

int D_VideoSlicer::set_VideoPath(QFileInfo FI_VideoPath)
{
    FI_Source = FI_VideoPath;
    VC_Source = VideoCapture(FI_Source.absoluteFilePath().toStdString());

    //success?
    if(!VC_Source.isOpened())
    {
        qDebug() << "Failed to load Video:" << FI_Source.absoluteFilePath();
        state_FileValid = false;
        return ER_VideoCaptureClosed;
    }

    prop_Name       = FI_Source.baseName();
    prop_Suffix     = FI_Source.suffix();
    prop_Width      = static_cast<int>(VC_Source.get(CAP_PROP_FRAME_WIDTH));
    prop_Height     = static_cast<int>(VC_Source.get(CAP_PROP_FRAME_HEIGHT));
    prop_FrameSize  = Size(prop_Width, prop_Height);
    prop_FrameCount = static_cast<int>(VC_Source.get(CAP_PROP_FRAME_COUNT));
    prop_Framerate  = VC_Source.get(CAP_PROP_FPS);
    prop_FrameTime  = 1.0 / prop_Framerate;
    prop_Duration   = prop_FrameTime * prop_FrameCount;

    //sucess :-)
    state_FileValid = true;
    return ER_okay;
}

bool D_VideoSlicer::is_NextFrameExistent()
{
    if(!state_FileValid)                            return false;
    if(cursor_FrameCurrent >= prop_FrameCount - 1)  return false;

    return true;
}

Mat D_VideoSlicer::get_FrameNext()
{
    if(!is_NextFrameExistent())
        return Mat();

    cursor_FrameCurrent++;
    return get_FramePos(cursor_FrameCurrent);
}

int D_VideoSlicer::get_FrameNext(Mat *MA_Frame)
{
    if(!is_NextFrameExistent())
        return ER_index_out_of_range;

    cursor_FrameCurrent++;
    return get_FramePos(MA_Frame, cursor_FrameCurrent);
}

Mat D_VideoSlicer::get_FramePos(int frame_number)
{
    if(!state_FileValid)                                        return Mat();
    if(frame_number < 0 || frame_number >= prop_FrameCount)     return Mat();

    VC_Source.set(CAP_PROP_POS_FRAMES, frame_number);
    Mat MA_tmp_frame;
    VC_Source.read(MA_tmp_frame);
    return  MA_tmp_frame;
}

int D_VideoSlicer::get_FramePos(Mat *MA_Frame, int frame_number)
{
    if(!state_FileValid)                                        return ER_VideoCaptureClosed;
    if(frame_number < 0 || frame_number >= prop_FrameCount)     return ER_index_out_of_range;

    *MA_Frame = get_FramePos(frame_number);
    return ER_okay;
}
