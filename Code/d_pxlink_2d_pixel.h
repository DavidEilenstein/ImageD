/************************************
 *   added:     17.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_PXLINK_2D_PIXEL_H
#define D_PXLINK_2D_PIXEL_H

//own

//general
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
using namespace cv;

class D_PxLink_2D_Pixel
{
public:
    D_PxLink_2D_Pixel(size_t pos_x, size_t pos_y, double value);

private:
    size_t x;
    size_t y;
    double v;
};

#endif // D_PXLINK_2D_PIXEL_H
