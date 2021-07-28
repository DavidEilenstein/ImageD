/************************************
 *   added:     08.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_FEATURESET_H
#define D_FEATURESET_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QString>
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_FeatureSet
{
public:
    D_FeatureSet();

    int         detect_Harris(Mat *pMA_In, int blockSize, int sobelAperture, double harrisParam, double thres);
    int         detect_ShiTomasi(Mat *pMA_In, int maxCorners, double qualityLevel, double minDist, int blockSize, int sobelAperture, double harrisParam, double thres);


private:
    bool                state_size_set = false;
    bool                state_points_set = false;
    bool                state_descriptors_set = false;

    int                 img_width = 1;
    int                 img_heigts = 1;
    vector<Point>       vPoints;

};

#endif // D_FEATURESET_H
