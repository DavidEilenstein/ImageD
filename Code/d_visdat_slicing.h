/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_SLICING_H
#define D_VISDAT_SLICING_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_dim.h>
#include <d_visdat_range.h>
#include <d_visdat_slice_1d.h>
#include <d_visdat_slice_2d.h>
#include <d_visdat_slice_3d.h>

//Qt
#include <QDateTime>
#include <QString>
#include <QStringList>

//Qt::Charts

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

/*!
 * \brief The D_VisDat_Slicing class Describes how a D_VisDat_Obj shall be sliced.
 * \details D_VisDat_Proc uses objects of this class to determine how to slice 6D images.
 */
class D_VisDat_Slicing : D_VisDat_Range
{
public:
    D_VisDat_Slicing();
    D_VisDat_Slicing(int SlicingPrototype);
    D_VisDat_Slicing(int Dims, int SlicingPrototype);

    //inherits from D_VisDat_Range -> range definition is implemented in range class

    int                     ProcDims_Count      ();
    bool                    is_0D               ()      {return (ProcDims_Count() == 0);}
    bool                    is_1D               ()      {return (ProcDims_Count() == 1);}
    bool                    is_2D               ()      {return (ProcDims_Count() == 2);}
    bool                    is_3D               ()      {return (ProcDims_Count() == 3);}
    bool                    is_4D               ()      {return (ProcDims_Count() == 4);}
    bool                    is_5D               ()      {return (ProcDims_Count() == 5);}
    bool                    is_6D               ()      {return (ProcDims_Count() == 6);}
    bool                    is_proc_X           ()      {return static_cast<bool>(v_ProcDims[c_DIM_X]);}
    bool                    is_proc_Y           ()      {return static_cast<bool>(v_ProcDims[c_DIM_Y]);}
    bool                    is_proc_Z           ()      {return static_cast<bool>(v_ProcDims[c_DIM_Z]);}
    bool                    is_proc_T           ()      {return static_cast<bool>(v_ProcDims[c_DIM_T]);}
    bool                    is_proc_S           ()      {return static_cast<bool>(v_ProcDims[c_DIM_S]);}
    bool                    is_proc_P           ()      {return static_cast<bool>(v_ProcDims[c_DIM_P]);}
    bool                    is_proc_Dim         (int d) {return static_cast<bool>(d >= 0 && d < c_DIM_NUMBER_OF ? v_ProcDims[d] : 0);}
    bool                    is_proc_XY          ()      {return static_cast<bool>(v_ProcDims[c_DIM_X]) && static_cast<bool>(v_ProcDims[c_DIM_Y]);}
    bool                    is_proc_XYZ         ()      {return static_cast<bool>(v_ProcDims[c_DIM_X]) && static_cast<bool>(v_ProcDims[c_DIM_Y]) && static_cast<bool>(v_ProcDims[c_DIM_Z]);}
    bool                    is_proc_XYT         ()      {return static_cast<bool>(v_ProcDims[c_DIM_X]) && static_cast<bool>(v_ProcDims[c_DIM_Y]) && static_cast<bool>(v_ProcDims[c_DIM_T]);}

    vector<int>             ProcDims            ()  	{return v_ProcDims;}
    int                     ProcDim             (int p);

    void                    set_proc_X          (bool proc)             {v_ProcDims[c_DIM_X] = proc;}
    void                    set_proc_Y          (bool proc)             {v_ProcDims[c_DIM_Y] = proc;}
    void                    set_proc_Z          (bool proc)             {v_ProcDims[c_DIM_Z] = proc;}
    void                    set_proc_T          (bool proc)             {v_ProcDims[c_DIM_T] = proc;}
    void                    set_proc_S          (bool proc)             {v_ProcDims[c_DIM_S] = proc;}
    void                    set_proc_P          (bool proc)             {v_ProcDims[c_DIM_P] = proc;}
    void                    set_proc_Dim        (int d, bool proc)      {if(d >= 0 && d < c_DIM_NUMBER_OF) v_ProcDims[d] = proc;}
    void                    set_proc_Dims       (vector<int> v_proc)    {if(v_proc.size() == v_ProcDims.size()) v_ProcDims = v_proc;}

    QString                 QS_info             ();

    bool                    loop_Init           (D_VisDat_Dim dim2loop);
    bool                    loop_Next           ();
    int                     loop_SliceCount     ();

    D_VisDat_Slice_1D       loop1D_SliceCurrent ();
    D_VisDat_Slice_2D       loop2D_SliceCurrent ();
    D_VisDat_Slice_3D       loop3D_SliceCurrent();
    D_VisDat_Slice_1D       loop1D_SliceByIndex (int i);
    D_VisDat_Slice_2D       loop2D_SliceByIndex (int i);
    D_VisDat_Slice_3D       loop3D_SliceByIndex (int i);



private:
    vector<int>             v_ProcDims;
    void                    Init_Slicing        ();

    vector<int>             v_LoopSize;
    vector<int>             v_LoopCur;
    bool                    Loop_Init = false;
};

#endif // D_VISDAT_SLICING_H
