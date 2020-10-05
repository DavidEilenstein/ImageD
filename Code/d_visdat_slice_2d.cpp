/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/


#include "d_visdat_slice_2d.h"

D_VisDat_Slice_2D::D_VisDat_Slice_2D()
{
    //qDebug() << "D_VisDat_Slice_2D";
    set_Dimensionality(2);
    Init();
}

D_VisDat_Slice_2D::D_VisDat_Slice_2D(int X, int Y, int Z, int T, int S, int P)
{
    //qDebug() << "D_VisDat_Slice_2D" << X << Y << Z << T << S << P;
    set_Dimensionality(2);
    Init();
    set_Pos(X, Y, Z, T, S, P);
}

D_VisDat_Slice_2D::D_VisDat_Slice_2D(vector<int> vPositions)
{
    //qDebug() << "D_VisDat_Slice_2D" << vPositions;
    set_Dimensionality(2);
    Init();
    set_Pos(vPositions);
}

D_VisDat_Slice_2D::D_VisDat_Slice_2D(Vec<int, 6> vPositions)
{
    set_Dimensionality(2);
    Init();
    set_Pos(
                vPositions[c_DIM_X],
                vPositions[c_DIM_Y],
                vPositions[c_DIM_Z],
                vPositions[c_DIM_T],
                vPositions[c_DIM_S],
                vPositions[c_DIM_P]);
}
