/************************************
 *   added:     17.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_pxlink_2d_image.h"

D_PxLink_2D_Image::D_PxLink_2D_Image(Mat *pMA)
{
    if(pMA->channels() != 1)
    {
        valid = false;
        return;
    }

    valid = true;
    sx = pMA->cols;
    sy = pMA->rows;
    type = pMA->type();

    decompose_image(pMA);
}

void D_PxLink_2D_Image::decompose_image(Mat *pMA)
{
    //for(size_t y = 0; y < sy; y++)
}
