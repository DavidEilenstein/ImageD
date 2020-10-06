/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_SLICE_1D_H
#define D_VISDAT_SLICE_1D_H

#include <d_visdat_slice_nd.h>

/*!
 * \brief The D_VisDat_Slice_1D class Represents a 1D slice from a D_VisDat_Obj
 */
class D_VisDat_Slice_1D : public D_VisDat_Slice_Nd
{
public:
    D_VisDat_Slice_1D();
    D_VisDat_Slice_1D(int X, int Y, int Z, int T, int S, int P);
    D_VisDat_Slice_1D(vector<int> vPositions);
};

#endif // D_VISDAT_SLICE_1D_H
