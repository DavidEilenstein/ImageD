/************************************
 *   added:     17.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_PXLINK_2D_IMAGE_H
#define D_PXLINK_2D_IMAGE_H

//own
#include <d_pxlink_2d_pixel.h>
#include <d_pxlink_2d_group.h>

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

class D_PxLink_2D_Image
{
public:
    D_PxLink_2D_Image(Mat *pMA);

private:

    int type;
    size_t sx;
    size_t sy;
    bool valid;

    vector<D_PxLink_2D_Group> vPXG;

    void decompose_image(Mat *pMA);
};

#endif // D_PXLINK_2D_IMAGE_H
