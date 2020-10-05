/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_visdat_dim.h"

D_VisDat_Dim::D_VisDat_Dim()
{

}

D_VisDat_Dim::D_VisDat_Dim(int X, int Y, int Z, int T, int S, int P)
{
    vSizes[c_DIM_X] = X;
    vSizes[c_DIM_Y] = Y;
    vSizes[c_DIM_Z] = Z;
    vSizes[c_DIM_T] = T;
    vSizes[c_DIM_S] = S;
    vSizes[c_DIM_P] = P;
}

D_VisDat_Dim::D_VisDat_Dim(vector<int> vDims)
{
    vSizes[c_DIM_X] = vDims[c_DIM_X];
    vSizes[c_DIM_Y] = vDims[c_DIM_Y];
    vSizes[c_DIM_Z] = vDims[c_DIM_Z];
    vSizes[c_DIM_T] = vDims[c_DIM_T];
    vSizes[c_DIM_S] = vDims[c_DIM_S];
    vSizes[c_DIM_P] = vDims[c_DIM_P];
}

D_VisDat_Dim::D_VisDat_Dim(Vec<int, c_DIM_NUMBER_OF> vDims)
{
    vSizes[c_DIM_X] = vDims[c_DIM_X];
    vSizes[c_DIM_Y] = vDims[c_DIM_Y];
    vSizes[c_DIM_Z] = vDims[c_DIM_Z];
    vSizes[c_DIM_T] = vDims[c_DIM_T];
    vSizes[c_DIM_S] = vDims[c_DIM_S];
    vSizes[c_DIM_P] = vDims[c_DIM_P];
}

D_VisDat_Dim::D_VisDat_Dim(D_VisDat_Header source_header)
{
    vSizes[c_DIM_X] = source_header.Dim_size_x();
    vSizes[c_DIM_Y] = source_header.Dim_size_y();
    vSizes[c_DIM_Z] = source_header.Dim_size_z();
    vSizes[c_DIM_T] = source_header.Dim_size_t();
    vSizes[c_DIM_S] = source_header.Dim_size_s();
    vSizes[c_DIM_P] = source_header.Dim_size_p();
}

int D_VisDat_Dim::size_PixelCount()
{
    int px = 1;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        px *= vSizes[d];

    return px;
}

int D_VisDat_Dim::extended_DimsCount()
{
    int extended_dims = 0;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vSizes[d] > 1)
            extended_dims++;

    return extended_dims;
}

QString D_VisDat_Dim::extended_DimsString()
{
    int ext_dims_count = extended_DimsCount();

    QString QS_ExtDim = "";
    int d_counter = 0;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if(vSizes[d] > 1)
        {
            d_counter++;

            if(d_counter != 1)
            {
                if(d_counter == ext_dims_count)
                    QS_ExtDim.append(" and ");
                else
                    QS_ExtDim.append(", ");
            }

            QS_ExtDim.append(QSL_DimIndices[d]);
        }
    }

    return QS_ExtDim;
}

bool D_VisDat_Dim::inRangeOf(D_VisDat_Dim VD_container)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(size_Dim(d) > VD_container.size_Dim(d))
            return false;

    return true;
}

Vec<int, c_DIM_NUMBER_OF> D_VisDat_Dim::ForcePosInRange(Vec<int, c_DIM_NUMBER_OF> pos)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(pos[d] >= vSizes[d])
            pos[d] = vSizes[d] - 1;

    return pos;
}

int D_VisDat_Dim::DimOutRanged(D_VisDat_Dim VD_container)
{
    if(size_X() > VD_container.size_X())    return ER_dim_X_out_of_range;
    if(size_Y() > VD_container.size_Y())    return ER_dim_Y_out_of_range;
    if(size_Z() > VD_container.size_Z())    return ER_dim_Z_out_of_range;
    if(size_T() > VD_container.size_T())    return ER_dim_T_out_of_range;
    if(size_S() > VD_container.size_S())    return ER_dim_S_out_of_range;
    if(size_P() > VD_container.size_P())    return ER_dim_P_out_of_range;

    return ER_okay;
}

bool D_VisDat_Dim::isEqual(D_VisDat_Dim VD_compare)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vSizes[d] != VD_compare.size_Dim(d))
            return false;

    return true;
}

QString D_VisDat_Dim::info()
{
    QString QS_info = "DIM_INFO: ";

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        QS_info.append(QSL_DimIndices[d] + QString::number(size_Dim(d)));

    return QS_info;
}

bool D_VisDat_Dim::loop_Next()
{
    for(int d_check = 0; d_check < c_DIM_NUMBER_OF; d_check++)  //loop dims
    {
        if(v_LoopCurPos[d_check] < size_Dim(d_check) - 1)       //first dim that is not at max
        {
            for(int d_res = 0; d_res < d_check; d_res++)        //loop dims that are lesser significant
                v_LoopCurPos[d_res] = 0;                        //reset lesser significant dims to 0

            v_LoopCurPos[d_check]++;                            //increase least siginificant dim that is not at max
            return true;                                        //return true (next step found)
        }
    }

    return false;                                               //end of loop reached
}

Vec<int, c_DIM_NUMBER_OF> D_VisDat_Dim::loop_PosCurrent_Offset()
{
    Vec<int, c_DIM_NUMBER_OF> pos = loop_PosCurrent();

    Vec<int, c_DIM_NUMBER_OF> pos_off;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        pos_off[d] = pos[d] + v_LoopOffset[d];

    return pos_off;
}
