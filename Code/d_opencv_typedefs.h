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
const size_t BORDER_CONSTANT = cv::BORDER_CONSTANT;
const size_t BORDER_DEFAULT = cv::BORDER_DEFAULT;
const size_t BORDER_REFLECT = cv::BORDER_REFLECT;
const size_t BORDER_REFLECT101 = cv::BORDER_REFLECT101;
const size_t BORDER_REFLECT_101 = cv::BORDER_REFLECT_101;
const size_t BORDER_REPLICATE = cv::BORDER_REPLICATE;
const size_t BORDER_ISOLATED = cv::BORDER_ISOLATED;
//morphology
const size_t MORPH_CROSS = cv::MORPH_CROSS;
const size_t MORPH_RECT = cv::MORPH_RECT;
const size_t MORPH_ELLIPSE = cv::MORPH_ELLIPSE;
const size_t MORPH_DILATE = cv::MORPH_DILATE;
const size_t MORPH_ERODE = cv::MORPH_ERODE;
const size_t MORPH_GRADIENT = cv::MORPH_GRADIENT;
const size_t MORPH_OPEN = cv::MORPH_OPEN;
const size_t MORPH_CLOSE = cv::MORPH_CLOSE;
const size_t MORPH_BLACKHAT = cv::MORPH_BLACKHAT;
const size_t MORPH_TOPHAT = cv::MORPH_TOPHAT;
const size_t MORPH_HITMISS = cv::MORPH_HITMISS;
//contours
const size_t RETR_TREE = cv::RETR_TREE;
const size_t RETR_CCOMP = cv::RETR_CCOMP;
const size_t CHAIN_APPROX_NONE = cv::CHAIN_APPROX_NONE;
const size_t CHAIN_APPROX_SIMPLE = cv::CHAIN_APPROX_SIMPLE;
//videocapture
const size_t CAP_PROP_FPS = cv::CAP_PROP_FPS;
const size_t CAP_PROP_FRAME_WIDTH = cv::CAP_PROP_FRAME_WIDTH;
const size_t CAP_PROP_FRAME_HEIGHT = cv::CAP_PROP_FRAME_HEIGHT;
const size_t CAP_PROP_FRAME_COUNT = cv::CAP_PROP_FRAME_COUNT;
const size_t CAP_PROP_POS_FRAMES = cv::CAP_PROP_POS_FRAMES;
//load img
const size_t IMREAD_ANYCOLOR = cv::IMREAD_ANYCOLOR;
const size_t IMREAD_ANYDEPTH = cv::IMREAD_ANYDEPTH;
const size_t IMREAD_COLOR = cv::IMREAD_COLOR;
const size_t IMREAD_GRAYSCALE = cv::IMREAD_GRAYSCALE;
//dist
const size_t DIST_L1 = cv::DIST_L1;
const size_t DIST_L2 = cv::DIST_L2;
const size_t DIST_L12 = cv::DIST_L12;
const size_t DIST_C = cv::DIST_C;
const size_t DIST_FAIR = cv::DIST_FAIR;
const size_t DIST_WELSCH = cv::DIST_WELSCH;
const size_t DIST_HUBER = cv::DIST_HUBER;
const size_t DIST_MASK_3 = cv::DIST_MASK_3;
const size_t DIST_MASK_5 = cv::DIST_MASK_5;
const size_t DIST_MASK_PRECISE = cv::DIST_MASK_PRECISE;
//dft
const size_t DFT_REAL_OUTPUT = cv::DFT_REAL_OUTPUT;
const size_t DFT_COMPLEX_INPUT = cv::DFT_COMPLEX_INPUT;
const size_t DFT_COMPLEX_OUTPUT = cv::DFT_COMPLEX_OUTPUT;
const size_t DFT_INVERSE = cv::DFT_INVERSE;
const size_t DFT_SCALE = cv::DFT_SCALE;
//compare
const size_t CMP_EQ = cv::CMP_EQ;
const size_t CMP_GT = cv::CMP_GT;
const size_t CMP_GE = cv::CMP_GE;
const size_t CMP_LT = cv::CMP_LT;
const size_t CMP_LE = cv::CMP_LE;
const size_t CMP_NE = cv::CMP_NE;
//font
const size_t FONT_HERSHEY_COMPLEX_SMALL = cv::FONT_HERSHEY_COMPLEX_SMALL;
const size_t FONT_HERSHEY_TRIPLEX = cv::FONT_HERSHEY_TRIPLEX;
//draw
const size_t LINE_4 = cv::LINE_4;
const size_t LINE_8 = cv::LINE_8;
const size_t LINE_AA = cv::LINE_AA;
const size_t FILLED = cv::FILLED;
//img proc params
const size_t ADAPTIVE_THRESH_MEAN_C = cv::ADAPTIVE_THRESH_MEAN_C;
const size_t ADAPTIVE_THRESH_GAUSSIAN_C = cv::ADAPTIVE_THRESH_GAUSSIAN_C;
const size_t THRESH_OTSU = cv::THRESH_OTSU;
//math
const size_t NORM_MINMAX = cv::NORM_MINMAX;
const size_t INTER_LINEAR = cv::INTER_LINEAR;


#endif // D_OPENCV_TYPEDEFS_H
