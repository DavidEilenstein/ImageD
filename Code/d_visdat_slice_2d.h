/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_SLICE_2D_H
#define D_VISDAT_SLICE_2D_H

#include <d_visdat_slice_nd.h>

/*!
 * \brief The D_VisDat_Slice_2D class Represents a 2D slice through a D_VisDat_Obj
 */
class D_VisDat_Slice_2D : public D_VisDat_Slice_Nd
{
public:
    D_VisDat_Slice_2D();
    D_VisDat_Slice_2D(int X, int Y, int Z, int T, int S, int P);
    D_VisDat_Slice_2D(vector<int> vPositions);
    D_VisDat_Slice_2D(Vec<int, 6> vPositions);
};

#endif // D_VISDAT_SLICE_2D_H
