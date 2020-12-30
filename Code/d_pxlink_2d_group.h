/************************************
 *   added:     17.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_PXLINK_2D_GROUP_H
#define D_PXLINK_2D_GROUP_H

//own
#include <d_pxlink_2d_pixel.h>

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

class D_PxLink_2D_Group
{
public:
    D_PxLink_2D_Group(double value);

    void add_px(size_t x, size_t y);

private:
    double v;

    vector<D_PxLink_2D_Pixel> vPX;
};

#endif // D_PXLINK_2D_GROUP_H
