/************************************
 *   added:     05.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/


#ifndef D_IMG_PROC_3D_H
#define D_IMG_PROC_3D_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>
#include <d_img_proc.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <thread>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

/*!
 * \brief The D_Img_Proc_3D class static 3D image processing functions.
 * \details Most methods take pointers to input and/or ouput <a href="https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html">cv::Mat</a> plus additional parameters.
 * Basic 3D funcionality comes from <a href="https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html">cv::Mat</a> but most of the logic is selfmade.
 */
class D_Img_Proc_3D
{
public:
    D_Img_Proc_3D();

    static int      Duplicate                       (Mat *pMA_Out, Mat *pMA_In);

    static int      Convert_Uchar_1C                (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_Double_1C               (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_Double                  (Mat *pMA_Out, Mat *pMA_In);

    static int      Pad_Border                      (Mat *pMA_Out, Mat *pMA_In, int border_size_x, int border_size_y, int border_size_z, int border_type = BORDER_CONSTANT, double border_val = 0);

    static int      Filter_Function                 (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_1C              (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, int thread_number = 8, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_1C_Thread       (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int z_start, int z_end, int y_start, int y_end, int x_start, int x_end, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_8bit            (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double cur, double nei)> F1_CenterImage, function<uchar (double f1r, double msk)> F2_f1mask, function<uchar (vector<double> vf2r)> F3_Combine, function<uchar (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_8bit_1C         (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double cur, double nei)> F1_CenterImage, function<uchar (double f1r, double msk)> F2_f1mask, function<uchar (vector<double> vf2r)> F3_Combine, function<uchar (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, int thread_number = 8, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_8bit_1C_Thread  (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double cur, double nei)> F1_CenterImage, function<uchar (double f1r, double msk)> F2_f1mask, function<uchar (vector<double> vf2r)> F3_Combine, function<uchar (double f3r, double cen)> F4_f3center, int z_start, int z_end, int y_start, int y_end, int x_start, int x_end, bool DoNonZeroMaskOnly = false);

    static int      Filter_Median                   (Mat *pMA_Out, Mat *pMA_In, int size_x = 3, int size_y = 3, int size_z = 3);
    static int      Filter_Eilenstein_Greater_Sum   (Mat *pMA_Out, Mat *pMA_In, int size_x = 3, int size_y = 3, int size_z = 3);

    static int      Morphology_Dilation             (Mat *pMA_Out, Mat *pMA_In, int size_x = 3, int size_y = 3, int size_z = 3);
    static int      Morphology_Erosion              (Mat *pMA_Out, Mat *pMA_In, int size_x = 3, int size_y = 3, int size_z = 3);

    static int      Neighborhood_Configs            (Mat *pMA_Out, Mat *pMA_In);

    static int      Distance_Transformation_EDT     (Mat *pMA_Out, Mat *pMA_In, double spacing_x = 1, double spacing_y = 1, double spacing_z = 1);

    static int      EulerNumber                     (double *euler_number, Mat *pMA_In);
    static int      EulerNumber                     (double *euler_number, Mat *pMA_Out, Mat *pMA_In);

    static int      Calc_Hist_8bit_1C               (vector<double> *v_hist, Mat *pMA_In, bool uniform, bool accum);
};

#endif // D_IMG_PROC_3D_H
