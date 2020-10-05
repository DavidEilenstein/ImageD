/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_visdat_slice_1d.h"

D_VisDat_Slice_1D::D_VisDat_Slice_1D()
{
    set_Dimensionality(1);
    Init();
}

D_VisDat_Slice_1D::D_VisDat_Slice_1D(int X, int Y, int Z, int T, int S, int P)
{
    set_Dimensionality(1);
    Init();
    set_Pos(X, Y, Z, T, S, P);
}

D_VisDat_Slice_1D::D_VisDat_Slice_1D(vector<int> vPositions)
{
    set_Dimensionality(1);
    Init();
    set_Pos(vPositions);
}
