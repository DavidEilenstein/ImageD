/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_visdat_slicing.h"

D_VisDat_Slicing::D_VisDat_Slicing()
{
    Init_Slicing();
}

D_VisDat_Slicing::D_VisDat_Slicing(int SlicingPrototype)
{
    Init_Slicing();

    switch (SlicingPrototype) {

    case c_SLICE_1D_X:
        v_ProcDims[c_DIM_X] = 1;
        break;

    case c_SLICE_1D_Y:
        v_ProcDims[c_DIM_Y] = 1;
        break;

    case c_SLICE_1D_Z:
        v_ProcDims[c_DIM_Z] = 1;
        break;

    case c_SLICE_1D_T:
        v_ProcDims[c_DIM_T] = 1;
        break;

    case c_SLICE_1D_S:
        v_ProcDims[c_DIM_S] = 1;
        break;

    case c_SLICE_1D_P:
        v_ProcDims[c_DIM_P] = 1;
        break;

    case c_SLICE_2D_XY:
        v_ProcDims[c_DIM_X] = 1;
        v_ProcDims[c_DIM_Y] = 1;
        break;

    case c_SLICE_2D_XZ:
        v_ProcDims[c_DIM_X] = 1;
        v_ProcDims[c_DIM_Z] = 1;
        break;

    case c_SLICE_2D_YZ:
        v_ProcDims[c_DIM_Y] = 1;
        v_ProcDims[c_DIM_Z] = 1;
        break;

    case c_SLICE_3D_XYZ:
        v_ProcDims[c_DIM_X] = 1;
        v_ProcDims[c_DIM_Y] = 1;
        v_ProcDims[c_DIM_Z] = 1;
        break;

    case c_SLICE_3D_XYT:
        v_ProcDims[c_DIM_X] = 1;
        v_ProcDims[c_DIM_Y] = 1;
        v_ProcDims[c_DIM_T] = 1;
        break;

    case c_SLICE_4D_XYZT:
        v_ProcDims[c_DIM_X] = 1;
        v_ProcDims[c_DIM_Y] = 1;
        v_ProcDims[c_DIM_Z] = 1;
        v_ProcDims[c_DIM_T] = 1;
        break;

    default:
        break;
    }
}

D_VisDat_Slicing::D_VisDat_Slicing(int Dims, int SlicingPrototype)
{
    Init_Slicing();

    switch (Dims) {

    case 2:
    {
        switch (SlicingPrototype) {

        case c_PLANE_XY:
            v_ProcDims[c_DIM_X] = 1;
            v_ProcDims[c_DIM_Y] = 1;
            break;

        case c_PLANE_XZ:
            v_ProcDims[c_DIM_X] = 1;
            v_ProcDims[c_DIM_Z] = 1;
            break;

        case c_PLANE_XT:
            v_ProcDims[c_DIM_X] = 1;
            v_ProcDims[c_DIM_T] = 1;
            break;

        case c_PLANE_XS:
            v_ProcDims[c_DIM_X] = 1;
            v_ProcDims[c_DIM_S] = 1;
            break;

        case c_PLANE_XP:
            v_ProcDims[c_DIM_X] = 1;
            v_ProcDims[c_DIM_P] = 1;
            break;

        case c_PLANE_YZ:
            v_ProcDims[c_DIM_Y] = 1;
            v_ProcDims[c_DIM_Z] = 1;
            break;

        case c_PLANE_YT:
            v_ProcDims[c_DIM_Y] = 1;
            v_ProcDims[c_DIM_T] = 1;
            break;

        case c_PLANE_YS:
            v_ProcDims[c_DIM_Y] = 1;
            v_ProcDims[c_DIM_S] = 1;
            break;

        case c_PLANE_YP:
            v_ProcDims[c_DIM_Y] = 1;
            v_ProcDims[c_DIM_P] = 1;
            break;

        case c_PLANE_ZT:
            v_ProcDims[c_DIM_Z] = 1;
            v_ProcDims[c_DIM_T] = 1;
            break;

        case c_PLANE_ZS:
            v_ProcDims[c_DIM_Z] = 1;
            v_ProcDims[c_DIM_S] = 1;
            break;

        case c_PLANE_ZP:
            v_ProcDims[c_DIM_Z] = 1;
            v_ProcDims[c_DIM_P] = 1;
            break;

        case c_PLANE_TS:
            v_ProcDims[c_DIM_T] = 1;
            v_ProcDims[c_DIM_S] = 1;
            break;

        case c_PLANE_TP:
            v_ProcDims[c_DIM_T] = 1;
            v_ProcDims[c_DIM_P] = 1;
            break;

        case c_PLANE_SP:
            v_ProcDims[c_DIM_S] = 1;
            v_ProcDims[c_DIM_P] = 1;
            break;

        default:
            break;
        }
    }
        break;

    default:
        break;
    }
}

int D_VisDat_Slicing::ProcDims_Count()
{
    int proc_dims = 0;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(v_ProcDims[d])
            proc_dims++;

    return proc_dims;
}

int D_VisDat_Slicing::ProcDim(int p)
{
    int proc_dims_count = 0;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if(v_ProcDims[d])
        {
            if(p == proc_dims_count)
                return d;               //dim index of proced dim number p
            else
                proc_dims_count++;      //count proc dims
        }
    }

    return -1;                          //proc dim number p doesnt extist -> too few proc dims
}

QString D_VisDat_Slicing::QS_info()
{
    QString QS_position = QString::number(ProcDims_Count()) + "d_proc";

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(v_ProcDims[d] == 1)
            QS_position.append(QSL_DimIndices[d]);

    QS_position.append("_fix_");

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(v_ProcDims[d] == 0)
            QS_position.append(QSL_DimIndices[d]);

    return QS_position;
}


bool D_VisDat_Slicing::loop_Init(D_VisDat_Dim dim2loop)
{
    //only init sucessful if 2D/3D slicing
    if(!is_2D() && !is_3D())
    {
        Loop_Init = false;
        return Loop_Init;
    }

    //init max(dim) and cur(0) - range ignored, always full range of dim2loop is looped
    v_LoopCur.clear();
    v_LoopCur.resize(c_DIM_NUMBER_OF);
    v_LoopSize.clear();
    v_LoopSize.resize(c_DIM_NUMBER_OF);
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if(is_proc_Dim(d))
        {
            v_LoopCur[d] = -1;
            v_LoopSize[d] = -1;
        }
        else
        {
            v_LoopSize[d] = dim2loop.size_Dim(d);
            v_LoopCur[d] = 0;
        }
    }

    //sucessfully inited
    Loop_Init = true;
    return Loop_Init;
}

bool D_VisDat_Slicing::loop_Next()
{
    if(!Loop_Init)
        return false;

    for(int d_check = 0; d_check < c_DIM_NUMBER_OF; d_check++)      //loop dims
        if(!is_proc_Dim(d_check))                                   //skip proc dims
            if(v_LoopCur[d_check] < (v_LoopSize[d_check] - 1))      //first dim that is not at max
            {
                for(int d_do = 0; d_do < d_check; d_do++)           //loop dims that are lower order
                    if(!is_proc_Dim(d_check))                       //skip proc dims
                        v_LoopCur[d_do] = 0;                         //reset lesser significant dims to 0

                v_LoopCur[d_check]++;                               //increase least siginificant dim that is not at max
                return true;                                        //return true (next step found)
            }

    return false;                                                   //end of slicing reached
}

int D_VisDat_Slicing::loop_SliceCount()
{
    if(!Loop_Init)
        return 0;

    int slices_count = 1;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(!is_proc_Dim(d))
            slices_count *= v_LoopSize[d];

    return slices_count;
}

D_VisDat_Slice_1D D_VisDat_Slicing::loop1D_SliceCurrent()
{
    if(Loop_Init && is_1D())
        return D_VisDat_Slice_1D(v_LoopCur);
    else
        return D_VisDat_Slice_1D();
}

D_VisDat_Slice_2D D_VisDat_Slicing::loop2D_SliceCurrent()
{
    if(Loop_Init && is_2D())
        return D_VisDat_Slice_2D(v_LoopCur);
    else
        return D_VisDat_Slice_2D();
}

D_VisDat_Slice_3D D_VisDat_Slicing::loop3D_SliceCurrent()
{
    if(Loop_Init && is_3D())
        return D_VisDat_Slice_3D(v_LoopCur);
    else
        return D_VisDat_Slice_3D();
}

D_VisDat_Slice_1D D_VisDat_Slicing::loop1D_SliceByIndex(int i)
{
    if(i < 0 || i >= loop_SliceCount() || !Loop_Init)       //check, if index is valid and looping is inited
        return D_VisDat_Slice_1D();

    vector<int> v_PosAtIndex(c_DIM_NUMBER_OF, 0);           //coordiantes of slice1d i in dataset (to be calculated)

    int step_weight = loop_SliceCount();                    //single steps caused by a step in current dim
    int pos_max_allowed_by_dim;
    int pos_max_allowed_by_math;
    int pos_calculated;
    int steps_to_be_done = i;

    for(int d = c_DIM_NUMBER_OF - 1; d >= 0; d--)           //loop dims (most sigificant to least significant)
    {
        if(!is_proc_Dim(d))                                 //skip dims that are processed/extended
        {
            //effect of a single step in current dim
            step_weight /= v_LoopSize[d];

            //max allowed pos in current dim
            pos_max_allowed_by_dim  = v_LoopSize[d];
            pos_max_allowed_by_math = steps_to_be_done / step_weight;

            //max pos possible in current dim
            pos_calculated = min(pos_max_allowed_by_dim, pos_max_allowed_by_math);
            v_PosAtIndex[d] = pos_calculated;

            //steps to be done in lesser significant dims
            steps_to_be_done -= pos_calculated * step_weight;
        }
        else
        {
            v_PosAtIndex[d] = -1;                           //processed/extended dims have pos -1 by definition
        }
    }

    return D_VisDat_Slice_1D(v_PosAtIndex);                 //return Slice at current pos
}

D_VisDat_Slice_2D D_VisDat_Slicing::loop2D_SliceByIndex(int i)
{
    if(i < 0 || i >= loop_SliceCount() || !Loop_Init)       //check, if index is valid and looping is inited
        return D_VisDat_Slice_2D();

    vector<int> v_PosAtIndex(c_DIM_NUMBER_OF, 0);           //coordiantes of slice2d i in dataset (to be calculated)

    int step_weight = loop_SliceCount();                    //single steps caused by a step in current dim
    int pos_max_allowed_by_dim;
    int pos_max_allowed_by_math;
    int pos_calculated;
    int steps_to_be_done = i;

    for(int d = c_DIM_NUMBER_OF - 1; d >= 0; d--)           //loop dims (most sigificant to least significant)
    {
        if(!is_proc_Dim(d))                                 //skip dims that are processed/extended
        {
            //effect of a single step in current dim
            step_weight /= v_LoopSize[d];

            //max allowed pos in current dim
            pos_max_allowed_by_dim  = v_LoopSize[d];
            pos_max_allowed_by_math = steps_to_be_done / step_weight;

            //max pos possible in current dim
            pos_calculated = min(pos_max_allowed_by_dim, pos_max_allowed_by_math);
            v_PosAtIndex[d] = pos_calculated;

            //steps to be done in lesser significant dims
            steps_to_be_done -= pos_calculated * step_weight;
        }
        else
        {
            v_PosAtIndex[d] = -1;                           //processed/extended dims have pos -1 by definition
        }
    }

    return D_VisDat_Slice_2D(v_PosAtIndex);                 //return Slice at current pos
}

D_VisDat_Slice_3D D_VisDat_Slicing::loop3D_SliceByIndex(int i)
{
    if(i < 0 || i >= loop_SliceCount() || !Loop_Init)       //check, if index is valid and looping is inited
        return D_VisDat_Slice_3D();

    vector<int> v_PosAtIndex(c_DIM_NUMBER_OF, 0);           //coordiantes of slice3d i in dataset (to be calculated)

    int step_weight = loop_SliceCount();                    //single steps caused by a step in current dim
    int pos_max_allowed_by_dim;
    int pos_max_allowed_by_math;
    int pos_calculated;
    int steps_to_be_done = i;

    for(int d = c_DIM_NUMBER_OF - 1; d >= 0; d--)           //loop dims (most sigificant to least significant)
    {
        if(!is_proc_Dim(d))                                 //skip dims that are processed/extended
        {
            //effect of a single step in current dim
            step_weight /= v_LoopSize[d];

            //max allowed pos in current dim
            pos_max_allowed_by_dim  = v_LoopSize[d];
            pos_max_allowed_by_math = steps_to_be_done / step_weight;

            //max pos possible in current dim
            pos_calculated = min(pos_max_allowed_by_dim, pos_max_allowed_by_math);
            v_PosAtIndex[d] = pos_calculated;

            //steps to be done in lesser significant dims
            steps_to_be_done -= pos_calculated * step_weight;
        }
        else
        {
            v_PosAtIndex[d] = -1;                           //processed/extended dims have pos -1 by definition
        }
    }

    return D_VisDat_Slice_3D(v_PosAtIndex);                 //return Slice at current pos
}




void D_VisDat_Slicing::Init_Slicing()
{
    Init(); //from parent ranges
    v_ProcDims.resize(c_DIM_NUMBER_OF, 0);
}
