/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/


#include "d_visdat_slice_nd.h"


D_VisDat_Slice_Nd::D_VisDat_Slice_Nd()
{
    //qDebug() << "D_VisDat_Slice_Nd";
    //Init();
}

/*
D_VisDat_Slice_Nd::D_VisDat_Slice_Nd(int X, int Y, int Z, int T, int S, int P)
{
    qDebug() << "D_VisDat_Slice_Nd";
    Init();
    set_Pos(X, Y, Z, T, S, P);
}

D_VisDat_Slice_Nd::D_VisDat_Slice_Nd(vector<int> vPositions)
{
    qDebug() << "D_VisDat_Slice_Nd";
    Init();
    set_Pos(vPositions);
}
*/

Vec<int, c_DIM_NUMBER_OF> D_VisDat_Slice_Nd::pos_Dims()
{
    Vec<int, c_DIM_NUMBER_OF> v_pos;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        v_pos[d] = pos_Dim(d);

    //qDebug() << info();
    return v_pos;
}

void D_VisDat_Slice_Nd::set_Dimensionality(int dims)
{
    if(dims >= c_DIM_NUMBER_OF)
        return;

    EXT_DIMS = dims;
    vExt.resize(EXT_DIMS, 0);
    for(size_t d_ext = 0; d_ext < vExt.size(); d_ext++)
        vExt[d_ext] = d_ext;
}

bool D_VisDat_Slice_Nd::isExtendedDim(int dim)
{
    for(size_t d_ext = 0; d_ext < vExt.size(); d_ext++)
        if(vExt[d_ext] == dim)
            return true;

    return false;
}

bool D_VisDat_Slice_Nd::inRangeOf(D_VisDat_Dim dim_container)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vPos[d] >= dim_container.size_Dim(d))
            return false;

    return true;
}

int D_VisDat_Slice_Nd::dimOutOfRange(D_VisDat_Dim dim_container)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vPos[d] >= dim_container.size_Dim(d))
            return d;

    return -1;
}

int D_VisDat_Slice_Nd::ER_OutOfrange(D_VisDat_Dim dim_container)
{
    switch (dimOutOfRange(dim_container)) {
    case c_DIM_X:   return ER_dim_X_out_of_range;   break;
    case c_DIM_Y:   return ER_dim_Y_out_of_range;   break;
    case c_DIM_Z:   return ER_dim_Z_out_of_range;   break;
    case c_DIM_T:   return ER_dim_T_out_of_range;   break;
    case c_DIM_S:   return ER_dim_S_out_of_range;   break;
    case c_DIM_P:   return ER_dim_P_out_of_range;   break;
    default:        return ER_okay;                 break;}
}

void D_VisDat_Slice_Nd::forceToBeInRangeOf(D_VisDat_Dim dim_container)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vPos[d] >= dim_container.size_Dim(d))
            vPos[d] = 0;

    force_Dimensionality();
}

void D_VisDat_Slice_Nd::force_Dimensionality()
{
    //qDebug() << "force_Dimensionality start - ExtDims:" << EXT_DIMS << "-" << info() << "-" << vExt;

    //check extended dims
    int ext_dims = 0;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        //qDebug() << "force_Dimensionality loop start " << QSL_DimIndices[d] << "- ExtDims:" << EXT_DIMS << "-" << info() << "-" << vExt;

        int dim_pos = vPos[d];
        bool dim_extended = dim_pos < 0;

        if(dim_extended) //count extended dims
            ext_dims++;

        if(dim_extended && ext_dims > EXT_DIMS) //set extended dims more than EXT_DIMS to non extended
        {
            dim_pos = 0;
            dim_extended = false;
            vPos[d] = dim_pos;
        }

        if(dim_extended) //legal extended dim?
        {
            vPos[d] = -1;
            vExt[ext_dims - 1] = d;
        }

        //qDebug() << "force_Dimensionality loop end  " << QSL_DimIndices[d] << "- ExtDims:" << EXT_DIMS << "-" << info() << "-" << vExt;
    }

    //qDebug() << "force_Dimensionality mid  - ExtDims:" << EXT_DIMS << "-" << info() << "-" << vExt;

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(ext_dims < EXT_DIMS)                                //not enough extended dims
            if(vPos[d] >= 0)                        //current dim not extended
            {
                vPos[d] = -1;
                ext_dims++;
                vExt[ext_dims - 1] = d;
            }

    //exactly EXT_DIMS dims are extended
    //if initially more: reduce all after the EXT_DIMS legal ext dims
    //if initially less: force the first missing ones to be fake extended

    //qDebug() << "force_Dimensionality end  - ExtDims:" << EXT_DIMS << "-" << info() << "-" << vExt;
}

QString D_VisDat_Slice_Nd::QS_pos()
{
    QString QS_position = QString::number(EXT_DIMS) + "d_";

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vPos[d] < 0)
            QS_position.append(QSL_DimIndices[d]);

    QS_position.append("_at_");

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vPos[d] >= 0)
            QS_position.append(QSL_DimIndices[d] + QString::number(vPos[d]));

    return QS_position;
}

QString D_VisDat_Slice_Nd::QS_pos_nonProcOnly()
{
    QString QS_position = "";
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vPos[d] >= 0)
            QS_position.append(QSL_DimIndices[d] + QString::number(vPos[d]));

    return QS_position;
}

QString D_VisDat_Slice_Nd::info()
{
    QString QS_info = QString::number(EXT_DIMS) + "DSLICE_INFO: " + QS_pos();

    return QS_info;
}

void D_VisDat_Slice_Nd::Init()
{
    vPos.resize(c_DIM_NUMBER_OF, 0);
}
