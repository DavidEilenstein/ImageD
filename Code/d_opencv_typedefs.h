/************************************
 *   added:     27.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_OPENCV_TYPEDEFS_H
#define D_OPENCV_TYPEDEFS_H

/*!
 * \brief typdef all commonly used OpenCV types
 * \details needed, because a simple "using namespace cv" is not possible, because of ambigious names with qtdatavisualization (added in v1.8.3)
 */

//includes
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/stitching.hpp"

//video/camera
typedef cv::VideoCapture VideoCapture;
typedef cv::VideoWriter VideoWriter;

//Mat and related stuff
typedef cv::Mat Mat;
typedef cv::Range Range;
typedef cv::Scalar Scalar;
typedef cv::Size Size;
typedef cv::Size2f Size2f;

//points
typedef cv::Point Point;
typedef cv::Point2f Point2f;
typedef cv::Point2f Point2d;
typedef cv::Point Point3;
typedef cv::Point3f Point3f;
typedef cv::Point3f Point3d;

//vectors
template <class T , size_t N> using Vec = cv::Vec<T, N>;
typedef cv::Vec2b Vec2b;
typedef cv::Vec2d Vec2d;
typedef cv::Vec2f Vec2f;
typedef cv::Vec2i Vec2i;
typedef cv::Vec2s Vec2s;
typedef cv::Vec2w Vec2w;
typedef cv::Vec3b Vec3b;
typedef cv::Vec3d Vec3d;
typedef cv::Vec3f Vec3f;
typedef cv::Vec3i Vec3i;
typedef cv::Vec3s Vec3s;
typedef cv::Vec3w Vec3w;
typedef cv::Vec4b Vec4b;
typedef cv::Vec4d Vec4d;
typedef cv::Vec4f Vec4f;
typedef cv::Vec4i Vec4i;
typedef cv::Vec4s Vec4s;
typedef cv::Vec4w Vec4w;

//other geometry
typedef cv::Rect Rect;
typedef cv::RotatedRect RotatedRect;

//math stuff
typedef  cv::PCA PCA;

//other
typedef cv::Moments Moments;
typedef cv::Stitcher Stitcher;

//enums
//border
const int BORDER_CONSTANT = cv::BORDER_CONSTANT;
const int BORDER_DEFAULT = cv::BORDER_DEFAULT;
const int BORDER_REFLECT = cv::BORDER_REFLECT;
const int BORDER_REFLECT101 = cv::BORDER_REFLECT101;
const int BORDER_REFLECT_101 = cv::BORDER_REFLECT_101;
const int BORDER_REPLICATE = cv::BORDER_REPLICATE;
const int BORDER_ISOLATED = cv::BORDER_ISOLATED;
//morphology
const int MORPH_CROSS = cv::MORPH_CROSS;
const int MORPH_RECT = cv::MORPH_RECT;
const int MORPH_ELLIPSE = cv::MORPH_ELLIPSE;
const int MORPH_DILATE = cv::MORPH_DILATE;
const int MORPH_ERODE = cv::MORPH_ERODE;
const int MORPH_GRADIENT = cv::MORPH_GRADIENT;
const int MORPH_OPEN = cv::MORPH_OPEN;
const int MORPH_CLOSE = cv::MORPH_CLOSE;
const int MORPH_BLACKHAT = cv::MORPH_BLACKHAT;
const int MORPH_TOPHAT = cv::MORPH_TOPHAT;
const int MORPH_HITMISS = cv::MORPH_HITMISS;
//contours
const int RETR_TREE = cv::RETR_TREE;
const int RETR_CCOMP = cv::RETR_CCOMP;
const int CHAIN_APPROX_NONE = cv::CHAIN_APPROX_NONE;
const int CHAIN_APPROX_SIMPLE = cv::CHAIN_APPROX_SIMPLE;
//videocapture
const int CAP_PROP_FPS = cv::CAP_PROP_FPS;
const int CAP_PROP_FRAME_WIDTH = cv::CAP_PROP_FRAME_WIDTH;
const int CAP_PROP_FRAME_HEIGHT = cv::CAP_PROP_FRAME_HEIGHT;
const int CAP_PROP_FRAME_COUNT = cv::CAP_PROP_FRAME_COUNT;
const int CAP_PROP_POS_FRAMES = cv::CAP_PROP_POS_FRAMES;
//load img
const int IMREAD_ANYCOLOR = cv::IMREAD_ANYCOLOR;
const int IMREAD_ANYDEPTH = cv::IMREAD_ANYDEPTH;
const int IMREAD_COLOR = cv::IMREAD_COLOR;
const int IMREAD_GRAYSCALE = cv::IMREAD_GRAYSCALE;
//dist
const int DIST_L1 = cv::DIST_L1;
const int DIST_L2 = cv::DIST_L2;
const int DIST_L12 = cv::DIST_L12;
const int DIST_C = cv::DIST_C;
const int DIST_FAIR = cv::DIST_FAIR;
const int DIST_WELSCH = cv::DIST_WELSCH;
const int DIST_HUBER = cv::DIST_HUBER;
const int DIST_MASK_3 = cv::DIST_MASK_3;
const int DIST_MASK_5 = cv::DIST_MASK_5;
const int DIST_MASK_PRECISE = cv::DIST_MASK_PRECISE;
//dft
const int DFT_REAL_OUTPUT = cv::DFT_REAL_OUTPUT;
const int DFT_COMPLEX_INPUT = cv::DFT_COMPLEX_INPUT;
const int DFT_COMPLEX_OUTPUT = cv::DFT_COMPLEX_OUTPUT;
const int DFT_INVERSE = cv::DFT_INVERSE;
const int DFT_SCALE = cv::DFT_SCALE;
//compare
const int CMP_EQ = cv::CMP_EQ;
const int CMP_GT = cv::CMP_GT;
const int CMP_GE = cv::CMP_GE;
const int CMP_LT = cv::CMP_LT;
const int CMP_LE = cv::CMP_LE;
const int CMP_NE = cv::CMP_NE;
//font
const int FONT_HERSHEY_COMPLEX_SMALL = cv::FONT_HERSHEY_COMPLEX_SMALL;
const int FONT_HERSHEY_TRIPLEX = cv::FONT_HERSHEY_TRIPLEX;
//draw
const int LINE_4 = cv::LINE_4;
const int LINE_8 = cv::LINE_8;
const int LINE_AA = cv::LINE_AA;
const int FILLED = cv::FILLED;
//img proc params
const int ADAPTIVE_THRESH_MEAN_C = cv::ADAPTIVE_THRESH_MEAN_C;
const int ADAPTIVE_THRESH_GAUSSIAN_C = cv::ADAPTIVE_THRESH_GAUSSIAN_C;
const int THRESH_OTSU = cv::THRESH_OTSU;
//math
const int NORM_MINMAX = cv::NORM_MINMAX;
const int INTER_LINEAR = cv::INTER_LINEAR;


#endif // D_OPENCV_TYPEDEFS_H
