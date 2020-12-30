/************************************
 *   added:     17.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_pxlink_2d_group.h"

D_PxLink_2D_Group::D_PxLink_2D_Group(double value)
{
    v = value;
}

void D_PxLink_2D_Group::add_px(size_t x, size_t y)
{
    vPX.push_back(D_PxLink_2D_Pixel(x, y, v));
}
