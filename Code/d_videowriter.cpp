/************************************
 *   added:     21.04.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_videowriter.h"

D_VideoWriter::D_VideoWriter()
{

}

int D_VideoWriter::set_Size(Size size_out)
{
    if(size_out.width <= 0)
        return ER_parameter_bad;
    if(size_out.height <= 0)
        return ER_parameter_bad;

    prop_SizeOut = size_out;
    state_isSet_FrameSize = true;

    if(is_ready2write())
        return init_VideoWriter();
    else
        return ER_okay;
}

int D_VideoWriter::set_Size(int width, int height)
{
    if(width <= 0)
        return ER_parameter_bad;
    if(height <= 0)
        return ER_parameter_bad;

    return set_Size(Size(width, height));
}

int D_VideoWriter::set_FPS(double fps)
{
    if(fps <= 0)
        return ER_parameter_bad;

    prop_FPS = fps;
    state_isSet_FPS = true;

    if(is_ready2write())
        return init_VideoWriter();
    else
        return ER_okay;
}

int D_VideoWriter::set_isColor(bool is_color)
{
    prop_isColor = is_color;
    state_isSet_isColor = true;

    if(is_ready2write())
        return init_VideoWriter();
    else
        return ER_okay;
}

int D_VideoWriter::init_VideoWriter()
{
    if(!is_ready2write())
        return ER_other;

    VW_Destination.release();
    VW_Destination = VideoWriter(
                FI_Out.absoluteFilePath().toStdString(),
                prop_FourCC,
                prop_FPS,
                prop_SizeOut,
                prop_isColor);

    state_isInit = VW_Destination.isOpened();
    if(state_isInit)
        return ER_okay;
    else
    {
        qDebug() << "D_VideoWriter::init_VideoWriter() - !VW_Destination.isOpened(); - but props are set";
        return ER_other;
    }
}

bool D_VideoWriter::is_Init()
{
    qDebug() << "state_isSet_DestinationPath" << state_isSet_DestinationPath
             << "state_isSet_FourCC" << state_isSet_FourCC
             << "state_isSet_FrameSize" << state_isSet_FrameSize
             << "state_isSet_FPS" << state_isSet_FPS
             << "state_isSet_isColor" << state_isSet_isColor;

    return state_isInit;
}

int D_VideoWriter::AddFrame(Mat frame2add)
{
    if(!state_isInit)
        return ER_file_not_exist;

    if(frame2add.size() != prop_SizeOut)
        return ER_size_missmatch;

    if(prop_isColor)
    {
        if(frame2add.channels() != 3)
            return ER_channel_missmatch;
    }
    else
    {
        if(frame2add.channels() != 1)
            return ER_channel_missmatch;
    }

    if(frame2add.empty())
        return ER_empty;

    VW_Destination.write(frame2add);

    return ER_okay;
}

int D_VideoWriter::AddFrame(Mat *frame2add)
{
    return AddFrame(*frame2add);
}

int D_VideoWriter::EndVideoWriting()
{
    VW_Destination.release();
    state_isInit = false;
    return ER_okay;
}

int D_VideoWriter::set_PathOut(string S_OutPath)
{
    return set_PathOut(QString::fromStdString(S_OutPath));
}

int D_VideoWriter::set_PathOut(QString QS_OutPath)
{
    return set_PathOut(QFileInfo(QS_OutPath));
}

int D_VideoWriter::set_PathOut(QFileInfo FI_OutPath)
{
    FI_Out = FI_OutPath;
    DIR_Out = FI_Out.dir();
    state_isSet_DestinationPath = true;
    is_ready2write();
    return ER_okay;
}

bool D_VideoWriter::is_ready2write()
{
    state_ready2write = state_isSet_DestinationPath && state_isSet_FrameSize && state_isSet_FourCC && state_isSet_FPS && state_isSet_isColor;
    return state_ready2write;
}
