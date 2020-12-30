/************************************
 *   added:     17.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_pxlink_2d_pixel.h"

D_PxLink_2D_Pixel::D_PxLink_2D_Pixel(size_t pos_x, size_t pos_y, double value)
{
    x = pos_x;
    y = pos_y;
    v = value;
}
