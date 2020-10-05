/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_SLICE_3D_H
#define D_VISDAT_SLICE_3D_H

#include <d_visdat_slice_nd.h>

class D_VisDat_Slice_3D : public D_VisDat_Slice_Nd
{
public:
    D_VisDat_Slice_3D();
    D_VisDat_Slice_3D(int X, int Y, int Z, int T, int S, int P);
    D_VisDat_Slice_3D(vector<int> vPositions);
};

#endif // D_VISDAT_SLICE_3D_H
