/************************************
 *   added:     08.12.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_featureset.h"

D_FeatureSet::D_FeatureSet()
{

}

/*!
 * \brief D_FeatureSet::detect_Harris Uses <a href="https://docs.opencv.org/3.4/dd/d1a/group__imgproc__feature.html#gac1fc3598018010880e370e2f709b4345">cornerHarris</a> to detect keypoints.
 * \param pMA_In Input image
 * \param blockSize neighborhood size
 * \param sobelAperture bluring strength
 * \param harrisParam harris free param k
 * \param thres threshhold value to accpect feature points
 * \return error code
 */
int D_FeatureSet::detect_Harris(Mat *pMA_In, int blockSize, int sobelAperture, double harrisParam, double thres)
{
    //Errors
    if(pMA_In->empty())                                         return ER_empty;
    if(pMA_In->depth() != CV_8U && pMA_In->depth() != CV_32F)   return ER_bitdepth_bad;
    if(pMA_In->channels() != 1)                                 return ER_channel_bad;
    if(harrisParam < 0 || harrisParam > 1)                      return ER_parameter_bad;
    if(blockSize < 0)                                           return ER_parameter_bad;
    if(sobelAperture < 1)                                       return ER_parameter_bad;

    //set size
    img_width = pMA_In->cols;
    img_heigts = pMA_In->rows;
    state_size_set = true;

    //detect features
    Mat MA_tmp_corners;
    cornerHarris(
                *pMA_In,
                MA_tmp_corners,
                blockSize,
                sobelAperture,
                harrisParam,
                BORDER_DEFAULT);

    //save features
    for(int y = 0; y < MA_tmp_corners.rows; y++)
        for(int x = 0; x < MA_tmp_corners.cols; x++)
            if(MA_tmp_corners.at<float>(y, x) > thres)
                vPoints.push_back(Point(x, y));
    state_points_set = true;

    return ER_okay;
}

int D_FeatureSet::detect_ShiTomasi(Mat *pMA_In, int maxCorners, double qualityLevel, double minDist, int blockSize, int sobelAperture, double harrisParam, double thres)
{
    //Errors
    if(pMA_In->empty())                                         return ER_empty;
    if(pMA_In->depth() != CV_8U && pMA_In->depth() != CV_32F)   return ER_bitdepth_bad;
    if(pMA_In->channels() != 1)                                 return ER_channel_bad;
    if(qualityLevel < 0 || qualityLevel > 1)                    return ER_parameter_bad;
    if(maxCorners < 0)                                          return ER_parameter_bad;
    if(minDist < 0)                                             return ER_parameter_bad;
    if(harrisParam < 0 || harrisParam > 1)                      return ER_parameter_bad;
    if(blockSize < 0)                                           return ER_parameter_bad;
    if(sobelAperture < 1)                                       return ER_parameter_bad;

    //goodFeaturesToTrack(


    return ER_okay;
}


