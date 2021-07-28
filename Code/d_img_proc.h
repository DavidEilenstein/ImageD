/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_IMG_PROC_H
#define D_IMG_PROC_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_component_list_context.h>
#include <d_value_distribution_list.h>
#include <d_featureset.h>
#include <d_geo_point_2d.h>
#include <d_geo_line_2d.h>
#include <d_contour.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <thread>
#include <complex>

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
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_Img_Proc class static 2D image processing functions.
 * \details Most methods take pointers to input and/or ouput <a href="https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html">Mat</a> plus additional parameters.
 * This class is where you find most of the image processing functions in ImageD.
 * Some are just wrapped from <a href="https://docs.opencv.org/master/index.html">OpenCV</a> others are selfmade.
 */
class D_Img_Proc
{
public:
    D_Img_Proc();

    static int      Load_From_Path              (Mat *pMA_Out, QFileInfo FI_path);
    static int      Load_From_Path              (Mat *pMA_Out, QString path);
    static int      Load_From_Path              (Mat *pMA_Out, string path);
    static int      Load_From_Path_Gray         (Mat *pMA_Out, QFileInfo FI_path);
    static int      Load_From_Path_Gray         (Mat *pMA_Out, QString path);
    static int      Load_From_Path_Gray         (Mat *pMA_Out, string path);
    static int      Load_From_Path_Text         (Mat *pMA_Out, string path);
    static int      Load_From_Path_Raw          (Mat *pMA_Out, string path, int width, int height, int out_type);
    static int      Load_From_Path_Multi        (Mat *pMA_Out, QString path, unsigned int page);

    static int      Generate_byValueFunction            (Mat *pMA_Out, int width, int height, function<double (double x, double y)> value_function);
    static int      Generate_byValueFunction_Complex    (Mat *pMA_Out, int width, int height, function<complex<double> (complex<double> x, complex<double> y)> value_function);

    static QString  Type_of_QImage              (QImage *pQI_In);
    static QString  Type_of_Mat                 (Mat *pMA_In);
    static QString  Type_of_Mat                 (int channels, int depth);
    static int      TypeIndex_of_Mat            (int channels, int depth);
    static int      Channels_of_MatType         (int type);
    static Scalar   Scalar_EqualInAllChannels   (int channels = 1, double value = 0);

    static int      Stat_ofPixelvalues          (double *value, Mat *pMA_In, int stat, bool ignore_zeros);
    static int      Quantiles_ofPixelvalues     (double *q_low, double *q_high, Mat *pMA_In, double low_rel, double high_rel, bool ignore_zeros);
    static int      Quantiles_ofPixelvalues     (vector<double> *v_q_low, vector<double> *v_q_high, Mat *pMA_In, double low_rel, double high_rel, bool ignore_zeros);

    static int      Convert_Mat_to_QImage       (QImage *pQI_Out, Mat *pMA_In);
    static int      Convert_QImage_to_Mat       (Mat *pMA_Out, QImage *pQI_In);

    static int      MinMax_of_Mat               (Mat *pMA_In, double *min_ext, double *max_ext);
    static int      MinMax_of_Mat_1C            (Mat *pMA_In, double *min_ext, double *max_ext);
    static int      ValAtPix                    (vector<double> *v_value, Mat *pMA_In, size_t x_pos, size_t y_pos);
    static int      ValAtPix                    (QString *QS_value, Mat *pMA_In, unsigned int x_pos, unsigned int y_pos);

    static int      Duplicate                   (Mat *pMA_Out, Mat *pMA_In);
    static int      Insert                      (Mat *pMA_Target, Mat *pMA_Insert, int offset_x, int offset_y);
    static int      Insert                      (Mat *pMA_Target, Mat *pMA_Insert, int offset_x, int offset_Y, double scale);

    static int      Invert                      (Mat *pMA_Out, Mat *pMA_In);

    static int      Convert_Color               (Mat *pMA_Out, Mat *pMA_In, int cvt_mode);
    static int      Convert_Color_RGBA          (Mat *pMA_Out, Mat *pMA_In, double r, double g, double b, double a, double range_rgba = 255.0);
    static int      Convert_Color2Mono          (Mat *pMA_Out, Mat *pMA_In, int col2mono_code);
    static int      Convert_Double_1C           (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_Double              (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_UChar_1C            (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_UChar               (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_8UC1                (Mat *pMA_Out, Mat *pMA_In);
    static int      Convert_Complex2Real_1C     (Mat *pMA_Out, Mat *pMA_InRe, Mat *pMA_InIm, int mode);
    static int      Convert_Complex2Real_1C     (Mat *pMA_Out, Mat *pMA_InComplexChannels, int mode);
    static int      Convert_Angle2Color_Rad     (Mat *pMA_Out, Mat *pMA_InAngleRad, uchar Saturation = 255, uchar Value = 255);
    static int      Normalize                   (Mat *pMA_Out, Mat *pMA_In, unsigned int norm, unsigned int type, double min, double max);
    static int      Spread_16_bit_to_8bit       (Mat *pMA_Out, Mat *pMA_In, double in_max, double out_max);
    static int      Spread_8bit_to_float01      (Mat *pMA_Out, Mat *pMA_In);
    static int      Channel_Supression          (Mat *pMA_Out, Mat *pMA_In, bool use_r = true, bool use_g = true, bool use_b = true, bool force_3ch = false);
    static int      Split                       (Mat *pMA_Out, Mat *pMA_In, unsigned int channel);
    static int      Merge                       (Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, unsigned int channels, bool channel_use[4]);
    static int      Duplicate2Channels          (Mat *pMA_Out, Mat *pMA_In, int channels);
    static int      Merge                       (Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2);
    static int      Merge                       (Mat *pMA_Out, vector<Mat> vMA_in, vector<int> v_R, vector<int> v_G, vector<int> v_B, vector<int> v_A);
    static int      Combi_8UC1_binary           (Mat *pMA_Out, Mat *pMA_In);
    static int      GammaSpread_1C              (Mat *pMA_Out, Mat *pMA_In, double gamma, double in_min, double in_max, double out_min = 0, double out_max = 255, bool force_8bit = false);
    static int      GammaSpread                 (Mat *pMA_Out, Mat *pMA_In, double gamma, double in_min, double in_max, double out_min = 0, double out_max = 255, bool force_8bit = false);
    static int      GammaSpread                 (Mat *pMA_Out, Mat *pMA_In, double gamma, vector<double> v_in_min, vector<double> v_in_max, double out_min = 0, double out_max = 255, bool force_8bit = false);
    static int      GammaSpread_Quantiles       (Mat *pMA_Out, Mat *pMA_In, double gamma, double quantile_low, double quantile_high, double out_min = 0, double out_max = 255, bool force_8bit = false, bool ignore_zeros = true);
    static int      Visualize_to8bit            (Mat *pMA_Out, Mat *pMA_In, int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max = false, int mode_complex = c_COMPLEX2REAL_RE_IM);
    static int      Visualize_to8bit_1C         (Mat *pMA_Out, Mat *pMA_In, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double crop_min, double crop_max, double val_gamma, double val_center, double val_scale);

    static int      Crop_Rect_Rel               (Mat *pMA_Out, Mat *pMA_In, double x1_rel, double y1_rel, double x2_rel, double y2_rel);
    static int      Crop_Rect_Rel               (Mat *pMA_Out, Mat *pMA_In, double x1_rel, double y1_rel, double x2_rel, double y2_rel, int *offset_x, int *offset_y, int *width, int *heigth);
    static int      Crop_Rect_Abs               (Mat *pMA_Out, Mat *pMA_In, int x, int y, int width, int height);
    static int      Crop_Rect_Rot               (Mat *pMA_Out, Mat *pMA_In, int x, int y, int width, int height, double angle);
    static int      Crop_Rect_Rot               (Mat *pMA_Out, Mat *pMA_In, RotatedRect rrect);
    static int      Crop_Circle                 (Mat *pMA_Out, Mat *pMA_In, int x, int y, int r);
    static int      Zoom                        (Mat *pMA_Out, Mat *pMA_In, double x_rel, double y_rel, double factor);
    static int      Zoom                        (Mat *pMA_Out, Mat *pMA_In, double x_rel, double y_rel, double factor, int *offset_x, int *offset_y, int *width, int *heigth);
    static int      Padding                     (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int type = BORDER_CONSTANT);
    static int      Padding                     (Mat *pMA_Out, Mat *pMA_In, int right, int left, int top, int bottom, int type = BORDER_CONSTANT);
    static int      Padding_1C                  (Mat *pMA_Out, Mat *pMA_In, int right, int left, int top, int bottom, int type = BORDER_CONSTANT);
    static int      ForceSize                   (Mat *pMA_Out, Mat *pMA_In, int width, int heigth, int border_type = BORDER_CONSTANT);
    static int      Stitch_Border_abs           (Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, int border_R, int border_B, int overlap_R, int overlap_B, Stitcher::Mode mode = Stitcher::SCANS);
    static int      Stitch_Border_rel           (Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, double border_R, double border_B, double overlap_R, double overlap_B, Stitcher::Mode mode = Stitcher::SCANS);
    static int      Stitch_Border_abs_custom    (Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, int border_R, int border_B, int overlap_R, int overlap_B);
    static int      Stitch_Border_rel_custom    (Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, double border_R, double border_B, double overlap_R, double overlap_B);

    static int      Scale_Factor                (Mat *pMA_Out, Mat *pMA_In, double scale_x, double scale_y);
    static int      Scale_ToSize                (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y);

    static int      Threshold_Relative          (Mat *pMA_Out, Mat *pMA_In, double max_val, double thres_rel);
    static int      Threshold_Relative_1C       (Mat *pMA_Out, Mat *pMA_In, double max_val, double thres_rel);
    static int      Threshold_Absolute          (Mat *pMA_Out, Mat *pMA_In, double thres_abs);
    static int      Threshold_Absolute_1C       (Mat *pMA_Out, Mat *pMA_In, double thres_abs);
    static int      Threshold_Value             (Mat *pMA_Out, Mat *pMA_In, int out_mode, double max_val, double thres);
    static int      Threshold_Auto              (Mat *pMA_Out, Mat *pMA_In, int out_mode, double max_val, int auto_mode);
    static int      Threshold_Adaptive          (Mat *pMA_Out, Mat *pMA_In, int out_mode, double max_val, int adapt_mode, unsigned int mask_size, double offset);
    static int      Threshold_Adaptive_Gauss    (Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double offset, double scale);
    static int      Threshold_Adaptive_Gauss_1C (Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double offset, double scale);
    static int      Threshold_BlurThres         (Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double thres);
    static int      Color_Grab                  (Mat *pMA_Out, Mat *pMA_In, int color_space, int out_mode, vector<uchar> min, vector<uchar> max);

    static int      Morphology_Elemental        (Mat *pMA_Out, Mat *pMA_In, int morph_type, int elem_type, unsigned int elem_size_X, unsigned int elem_size_Y, int border_type, unsigned int iterations);
    static int      Morphology_Skeleton         (Mat *pMA_Out, Mat *pMA_In, int elem_type, unsigned int elem_size_X, unsigned int elem_size_Y, int border_type);
    static int      Morphology_Thinning         (Mat *pMA_Out, Mat *pMA_In, int thinning_type);
    static int      Morphology_Thinning_Iteration(Mat img, int iter, int thinning_type);
    static int      Morphology_Erode_Rect       (Mat *pMA_Out, Mat *pMA_In, int elem_size_X, int elem_size_Y);
    static int      Morphology_Dilate_Rect      (Mat *pMA_Out, Mat *pMA_In, int elem_size_X, int elem_size_Y);
    static int      Morphology_LocMax_Rect      (Mat *pMA_Out, Mat *pMA_In, int elem_size_X = 3, int elem_size_Y = 3);
    static int      Morphology_LocMax_Rect_1C   (Mat *pMA_Out, Mat *pMA_In, int elem_size_X = 3, int elem_size_Y = 3);
    static int      Morphology_Reconstruction   (Mat *pMA_Out, Mat *pMA_InSeed, Mat *pMA_InLimit, Mat *pMA_Mask, double quantil = 1);

    static int      Transformation_Distance         (Mat *pMA_Out, Mat *pMA_In, int metric, int precision);
  //static int      Transformation_Distance_Rel     (Mat *pMA_Out, Mat *pMA_In, int metric, int precision);
    static int      Transformation_Watershed        (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Marker);
    static int      Transformation_Watershed_Auto   (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Marker, bool include_not_seeded, bool conv_8bit, bool exclude_border);
    static int      Transformation_Watershed_Auto   (Mat *pMA_Out, Mat *pMA_In, double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border);
    static int      Transformation_Watershed_Auto   (Mat *pMA_Out, Mat *pMA_In, int size, double sigma, bool include_not_seeded, bool conv_8bit, bool exclude_border);
    static int      Transformation_Watershed_Custom (Mat *pMA_Out, Mat *pMA_In2Fill, Mat *pMA_InMarker, Mat *pMA_FG_Mask, int mode_flood, int mode_marker, int mode_mask, int connectivity = 8, int gauss_size = 5, double gauss_sigma = 2, int morphgrad_elem = MORPH_ELLIPSE, int morphgrad_size = 3, double thresh = 127, bool exclude_border = true, bool include_non_seeded = true, bool draw_watersheds = true);
    static int      Transformation_Watershed_Custom (Mat *pMA_Out, Mat *pMA_In2Fill, Mat *pMA_InMarker, Mat *pMA_FG_Mask, int connectivity = 8);
    static int      Transformation_Fourier          (Mat *pMA_Out, Mat *pMA_In, bool invers);
    static int      Transformation_Fourier          (Mat *pMA_Out, Mat *pMA_In_Re, bool invers = false, bool force_fft = true, bool out_real = false, int out_complex_mode = c_COMPLEX2REAL_ABS, bool out_scale = false, bool out_center = true, bool out_nof0 = true);
    static int      Transformation_Fourier          (Mat *pMA_Out, Mat *pMA_In_Re, Mat *pMA_In_Im, bool complex_input, bool invers = false, bool force_fft = true, bool out_real = false, int out_complex_mode = c_COMPLEX2REAL_ABS, bool out_scale = false, bool out_center = true, bool out_nof0 = true);
    static int      Transformation_Fourier_1C       (Mat *pMA_Out, Mat *pMA_In_Re, Mat *pMA_In_Im, bool invers = false, bool force_fft = true, bool out_real = false, int out_complex_mode = c_COMPLEX2REAL_ABS, bool out_scale = false, bool out_center = true, bool out_nof0 = true);

    static int      Segmentation_GaussDistWater (Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double thres, double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border);

    static int      Filter_Box                  (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, int out_depth, bool norm);
    static int      Filter_Box_RMS              (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, int out_depth, bool norm);
    static int      Filter_Gauss                (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border,                double sigma_x, double sigma_y);
    static int      Filter_Median               (Mat *pMA_Out, Mat *pMA_In, int size);
    static int      Filter_Median               (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask);
    static int      Filter_RankOrder            (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, double quantil_relPos);
    static int      Filter_RankOrder_Circular   (Mat *pMA_Out, Mat *pMA_In, double quantil_relPos, double radius);
    static int      Filter_RankOrder_Rect       (Mat *pMA_Out, Mat *pMA_In, double quantil_relPos, int size_x, int size_y);
    static int      Filter_RankOrder_1C         (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, double quantil_relPos);
    static int      Filter_RankOrder_1C_Thread  (Mat *pMA_Out, Mat *pMA_InPadded, Mat *pMA_Mask, double quantil_relPos, size_t img_in_sx, size_t y_start, size_t y_end, double val_max, size_t mask_relevant_px_count, vector<Point> *vBorderL, vector<Point> *vBorderR, vector<Point> *vBorderT, vector<Point> *vBorderB);
    static int      Filter_Maximum_1C           (Mat *pMA_Out, Mat *pMA_In, size_t mask_size_x, size_t mask_size_y);
    static int      Filter_Maximum_1C_Thread_X  (Mat *pMA_Out, Mat *pMA_In, size_t mask_size_x, size_t n_in_x, size_t y_start, size_t y_end);
    static int      Filter_Maximum_1C_Thread_Y  (Mat *pMA_Out, Mat *pMA_In, size_t mask_size_x, size_t mask_size_y, size_t n_in_y, size_t x_start, size_t x_end);

    static int      Filter_Laplace              (Mat *pMA_Out, Mat *pMA_In, int size,               int border, int out_depth, double scale, double delta);
    static int      Filter_LaplaceOfGaussian    (Mat *pMA_Out, Mat *pMA_In, int size_g, double sigma_g, int size_l, int border, int out_depth, double scale, double delta);
    static int      Filter_Sobel                (Mat *pMA_Out, Mat *pMA_In, int size,               int border, int out_depth, double scale, double delta, int d_x, int d_y);
    static int      Filter_Scharr               (Mat *pMA_Out, Mat *pMA_In,                         int border, int out_depth, double scale, double delta, int d_x, int d_y);
    static int      Filter_Canny                (Mat *pMA_Out, Mat *pMA_In, int size, double thres_low, double thres_high, bool L2_gradient);
    static int      Filter_Bilateral            (Mat *pMA_Out, Mat *pMA_In, int diameter,           int border,                double sigma_color, double sigma_space);
    static int      Filter_Gabor                (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, int out_depth, double sigma, double theta, double lambda, double gamma, double psi, double delta);

    static int      Filter_Eilenstein_Prototype (Mat *pMA_Out, Mat *pMA_In, bool cmp_fkt(double, double, double), unsigned int size_x, unsigned int size_y, bool normalized, double constant);
    static int      Filter_Eilenstein_1C        (Mat *pMA_Out, Mat *pMA_In, int comp, unsigned int size_x, unsigned int size_y, bool normalized, double constant);
    static int      Filter_Eilenstein           (Mat *pMA_Out, Mat *pMA_In, int comp, unsigned int size_x, unsigned int size_y, bool normalized, double constant);
    static int      Filter_Eilenstein           (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> response_CurNei, function<double (double res, double wei)> weight_ResWeigth, function<double (vector<double> v_res)> combine_Responses);
    static int      Filter_Eilenstein_1C        (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> response_CurNei, function<double (double res, double wei)> weight_ResWeigth, function<double (vector<double> v_res)> combine_Responses);

    static int      Filter_Function                 (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_1C              (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, int thread_number = 8, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_1C_Thread       (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int row_start, int row_end, int col_start, int col_end, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_8bit            (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar  (double cur, double nei)> F1_CenterImage, function<uchar  (double f1r, double msk)> F2_f1mask, function<uchar  (vector<double> vf2r)> F3_Combine, function<uchar  (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_8bit_1C         (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar  (double cur, double nei)> F1_CenterImage, function<uchar  (double f1r, double msk)> F2_f1mask, function<uchar  (vector<double> vf2r)> F3_Combine, function<uchar  (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, int thread_number = 8, bool DoNonZeroMaskOnly = false);
    static int      Filter_Function_8bit_1C_Thread  (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar  (double cur, double nei)> F1_CenterImage, function<uchar  (double f1r, double msk)> F2_f1mask, function<uchar  (vector<double> vf2r)> F3_Combine, function<uchar  (double f3r, double cen)> F4_f3center, int row_start, int row_end, int col_start, int col_end, bool DoNonZeroMaskOnly = false);

    static int      Filter_Stat                     (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, int stat, int border_type = BORDER_CONSTANT);
    static int      Filter_Stat_Circular            (Mat *pMA_Out, Mat *pMA_In, double radius, int stat, int border_type = BORDER_CONSTANT);
    static int      Filter_Stat_Rect                (Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int stat, int border_type = BORDER_CONSTANT);

    static int      Fill_Holes                  (Mat *pMA_Out, Mat *pMA_In);
    static int      Exclude_BorderConnected     (Mat *pMA_Out, Mat *pMA_In);
    static int      Labeling                    (Mat *pMA_Out, Mat *pMA_In, int connectivity, int out_depth);

    //simple nomenclatur math functions (WIP)
    /*static int      Math_Not                    (Mat *pMA_Out, Mat *pMA_In1);
    static int      Math_Invert                 (Mat *pMA_Out, Mat *pMA_In1);
    static int      Math_Subtract               (Mat *pMA_Out, Mat *pMA_In1, double subtrahend);
    static int      Math_Subtract               (Mat *pMA_Out, double minuend, Mat *pMA_In1);
    static int      Math_Subtract               (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Subtract_Absolute      (Mat *pMA_Out, Mat *pMA_In1, double subtrahend);
    static int      Math_Subtract_Absolute      (Mat *pMA_Out, double minuend, Mat *pMA_In1);
    static int      Math_Subtract_Absolute      (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Divide                 (Mat *pMA_Out, Mat *pMA_In1, double divisor);
    static int      Math_Divide                 (Mat *pMA_Out, double dividend, Mat *pMA_In1);
    static int      Math_Power                  (Mat *pMA_Out, Mat *pMA_In1, double power);
    static int      Math_Power                  (Mat *pMA_Out, double base, Mat *pMA_In1);
    static int      Math_Root2                  (Mat *pMA_Out, Mat *pMA_In1);
    static int      Math_LogE                   (Mat *pMA_Out, Mat *pMA_In1);
    static int      Math_Add_Weighted           (Mat *pMA_Out, double weight_1, Mat *pMA_In1, double weight_2, Mat *pMA_In2, double weight_sum);
    static int      Math_Xor                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Min                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Max                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Comp                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, int comp);
    static int      Math_Function               (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<double (double x, double y)> function_img1_img2);
    static int      Math_Function_8bit          (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<uchar  (double x, double y)> function_img1_img2);
    */
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, double summand);
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double summand);
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3);
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, double summand);
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4);
    static int      Math_Add                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4, double summand);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, double factor);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double factor);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, double factor);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4);
    static int      Math_Mult                   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4, double factor);
    static int      Math_And                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_And                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3);
    static int      Math_And                    (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4);
    static int      Math_Or                     (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Or                     (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3);
    static int      Math_Or                     (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4);
    static int      Math_Magnitude              (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_MagnitudeSquared       (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Phase                  (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_LimitTop               (Mat *pMA_Out, Mat *pMA_InThresh, Mat *pMA_InToLimit);
    static int      Math_LimitTop               (Mat *pMA_Target, Mat *pMA_InThresh);

    static bool     Check_IsSimilar             (Mat *pMA_In1, Mat *pMA_In2);
    static bool     Check_GreaterValue          (Mat *pMA_InSmaller, Mat *pMA_InGreater);

    //old complicated math function names (from here) - kept to avoid version conflicts
    static int      Math_ImgSelf_Not            (Mat *pMA_Out, Mat *pMA_In);
    static int      Math_ImgScal_Add            (Mat *pMA_Out, Mat *pMA_In, double summmand);
    static int      Math_ImgScal_Sub            (Mat *pMA_Out, Mat *pMA_In, double subtrahend);
    static int      Math_ScalImg_Sub            (Mat *pMA_Out, Mat *pMA_In, double minuend);
    static int      Math_ImgScal_Mult           (Mat *pMA_Out, Mat *pMA_In, double factor);
    static int      Math_ImgScal_Div            (Mat *pMA_Out, Mat *pMA_In, double divisor);
    static int      Math_ImgScal_Pow            (Mat *pMA_Out, Mat *pMA_In, double power);
    static int      Math_ImgScal_Root           (Mat *pMA_Out, Mat *pMA_In);
    static int      Math_ImgScal_Log            (Mat *pMA_Out, Mat *pMA_In);
    static int      Math_ImgImg_Add             (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_AddWeighted     (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double weight_1, double weight_2, double weight_sum);
    static int      Math_ImgImg_Diff            (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_DiffAbs         (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_Mult            (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double scale);
    static int      Math_ImgImg_Div             (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double scale);
    static int      Math_ImgImg_BitAnd          (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_BitOr           (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_BitXor          (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_Min             (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_Max             (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_ImgImg_Comp            (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, int comp);
    static int      Math_ImgImg_Function        (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<double (double x, double y)> function_img1_img2);
    static int      Math_ImgImg_Function_8bit   (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<uchar  (double x, double y)> function_img1_img2);
    static int      Math_ImgImg_Function_Complex(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<complex<double> (complex<double> x, complex<double> y)> function_img1_img2);
    static int      Math_ImgStack_Project               (Mat *pMA_Out, vector<Mat> *pvMA_In, int stat = c_STAT_MEAN_ARITMETIC);
    static int      Math_ImgStack_StatCombine           (Mat *pMA_Out, vector<Mat> *pvMA_In0, vector<Mat> *pvMA_In1, function<double (vector<double>)> f_stat_0, function<double (vector<double>)> f_stat_1, function<double (double, double)> f_combi, bool force8bit);
    static int      Math_ImgStack_StatCombine_Thread    (Mat *pMA_Out, vector<Mat> *pvMA_In0, vector<Mat> *pvMA_In1, function<double (vector<double>)> f_stat_0, function<double (vector<double>)> f_stat_1, function<double (double, double)> f_combi, bool force8bit, int row_start, int row_end);
    static int      Math_Special_Add_Color      (Mat *pMA_Out, Mat *pMA_In_Color, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2);
    static int      Math_Special_NADH           (Mat *pMA_NADH,  Mat *pMA_I, Mat *pMA_A2, Mat *pMA_T1, Mat *pMA_T2, float k, bool ignore_0, float T2_Max_Thres, float T2_Max_Const);
    static int      Math_Special_NADPH          (Mat *pMA_NADPH, Mat *pMA_I, Mat *pMA_A2, Mat *pMA_T1, Mat *pMA_T2, float k, bool ignore_0, float T2_Min_Thres, float T2_Min_Const);
    static int      Math_Special_NADPH_NADH     (Mat *pMA_NADPH_NADH, Mat *pMA_T2, bool ignore_0, float T2_Min_Thres, float T2_Max_Thres, float T2_Min_Const, float T2_Max_Const);
    static int      Math_Special_Trans2Count    (Mat *pMA_Count, Mat *pMA_Trans, float base, float scale);
    static int      Math_Special_IncreaseIfSet  (Mat *pMA_Count, Mat *pMA_Check);
    //old complicated math function names (until here)

    static int      Shading_Correct             (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Reference);

    static int      Mask                        (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask);
    static int      Mask_1C                     (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask);
    static int      Value_to_MinOrMax           (Mat *pMA_Out, Mat *pMA_In, double val_src, bool to_min);
    static int      Value_to_Value              (Mat *pMA_Out, Mat *pMA_In, double val_src, double val_dst);

    static int      Histo_Equal                 (Mat *pMA_Out, Mat *pMA_In);

    static int      Calc_Hist                   (Mat *pMA_Hist, Mat *pMA_In, bool uniform, bool accum);             //buggy! use the other one...
    static int      Calc_Hist                   (vector<vector<double>> *vv_hist, Mat *pMA_In, bool uniform, bool accum);
    static int      Calc_Hist_1C                (vector<double> *v_hist, Mat *pMA_In, bool uniform, bool accum, unsigned int class_count, double *min_ext, double *max_ext, double *step_ext);
    static int      Calc_Hist_Multi             (vector<vector<double>> *vv_hist, Mat *pMA_In, bool uniform, bool accum, unsigned int class_count, vector<double> *v_min_ext, vector<double> *v_max_ext, vector<double> *v_step_ext);

    static int      Calc_LUT                    (vector<int> *vLUT, Mat *pMA_Label);
    static int      Split_img2vv_value          (vector<vector<double>> *vv_data_LabPix, Mat *pMA_Value, Mat *pMA_Label, bool ignore_0);
    static int      Split_img2vv_coord          (vector<vector<Point>> *vvp_data_LabCooPt, Mat *pMA_Label);
    static int      Split_img2components        (D_Component_List *pCompList, Mat *pMA_In, int connectivity = 8);
    static int      Split_ObjectAreas           (vector<double> *v_objects, vector<double> *v_areas, Mat *pMA_Label, Mat *pMA_Objects, int connectivity);

    static int      LUT_Apply_to_Label_Int      (Mat *pMA_Out, Mat *pMA_Label, vector<int> vLUT);
    static int      LUT_Apply_to_Label_Double   (Mat *pMA_Out, Mat *pMA_Label, vector<double> vLUT);
    static int      LUT_Apply_to_Label_Binary   (Mat *pMA_Out, Mat *pMA_Label, vector<int> vLUT, bool ignore_BG = true);
    static int      LUT_Apply_to_Label_TrueFalse(Mat *pMA_Out_true, Mat *pMA_Out_false, Mat *pMA_Label, vector<int> vLUT, bool edges = true, bool ignore_BG = true);
    static int      LUT_Apply_to_Label_Color    (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, vector<int> vLUT, int channel_true, int channel_false, bool edges = true, bool ignore_BG = true);

    static int      Feature_Value               (Mat *pMA_Out, Mat *pMA_In, int feature, int connectivity = 4);
    static int      FeatureContext_Value        (Mat *pMA_Out, Mat *pMA_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, int connectivity = 4);
    static int      Feature_Select              (Mat *pMA_Out, Mat *pMA_In, int feature, double f_min, double f_max, int connectivity = 4);
    static int      FeatureContext_Select       (Mat *pMA_Out, Mat *pMA_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, double t_min, double t_max, int connectivity = 4);
    static int      Feature_Visualize           (Mat *pMA_Out, Mat *pMA_In, int feature, int connectivity = 4, int thickness = 1, double scale = 1);
    static int      Feature_Connect             (Mat *pMA_Out, Mat *pMA_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat1, int feat2, function<bool(double, double)> comp, int connect_mode = c_CONNECT_CLOSEST, int connectivity = 4, int thickness = 2);

    static int      Detect_CornerHarris         (Mat *pMA_Out, Mat *pMA_In, int blockSize, int sobelAperture, double harrisParam, double thres);

    static int      Select_Area                 (Mat *pMA_Out, Mat *pMA_In, unsigned int area_min, unsigned int area_max, int connectivity);

    static int      Reduce_Geometric            (Mat *pMA_Out, Mat *pMA_In, int geometric, int connectivity = 8, int thickness = 1, uchar value = 255);
    static int      Reduce_Outlines             (Mat *pMA_Out, Mat *pMA_In, int neighborhood = 8, int thickness = 1);
    static int      Reduce_Centroid             (Mat *pMA_Out, Mat *pMA_In, int thickness = 1);
    static int      Reduce_Contours             (Mat *pMA_Out, Mat *pMA_In, int thickness = 1);

    static int      Calc_Centroids              (vector<Point2f> *pvCentroids, Mat *pMA_In, int connectivity = 8);

    static int      Floodfill                   (Mat *pMA_Out, Mat *pMA_In, unsigned int seed_x, unsigned int seed_y, double new_val);
    static int      Floodfill                   (Mat *pMA_Target, unsigned int seed_x, unsigned int seed_y, double new_val);
    static int      Floodfill_Boundary          (Mat *pMA_Out, Mat *pMA_In, double new_val);
    static int      Floodfill_Delta             (Mat *pMA_Out, Mat *pMA_In, int seed_x, int seed_y, uchar val_new, uchar val_delta);
    static bool     Floodfill_Delta_Step        (Mat *pMA_Target, Mat *pMA_Check, int x, int y, int dx, int dy, int val_new, int val_delta, int val_origin);

    static int      Draw_Dot                    (Mat *pMA_Target, int x, int y, int d, uchar val);
    static int      Draw_Dots                   (Mat *pMA_Target, vector<Point2f> vCenters, vector<double> vDiameters, uchar val);
    static int      Draw_Dots                   (Mat *pMA_Target, vector<Point> vCenters, vector<double> vDiameters, uchar val);
    static int      Draw_Dot                    (Mat *pMA_Target, int x, int y, int r, uchar val_r, uchar val_g, uchar val_b);
    static int      Draw_Line                   (Mat *pMA_Target, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int thickness = 1, double value = 255);
    static int      Draw_Line                   (Mat *pMA_Target, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int thickness, double val_r, double val_g, double val_b);
    static int      Draw_Line                   (Mat *pMA_Target, Point P1, Point P2, unsigned int thickness, double val_r, double val_g, double val_b);
    static int      Draw_Line_Bresenham         (Mat *pMA_Target, Point P1, Point P2, double val);
    static int      Draw_Line_Angle             (Mat *pMA_Target, double length, double center_x, double center_y, double angle, unsigned int thickness = 1, double value = 255);
    static int      Draw_Vector                 (Mat *pMA_Target, int offset_x, int offset_y, double length_value, double angle_value, double length_error = 0, double angle_error = 0, int vector_thickness = 1, uchar value = 255, int error_steps = 360, int error_thickness = 1);
    static int      Draw_Arc                    (Mat *pMA_Target, int offset_x, int offset_y, double arc_angle, double arc_orientation, double radius, int line_thickness = 1, uchar value = 255, int draw_arc_steps = 360);
    static int      Draw_Arc                    (Mat *pMA_Target, int offset_x, int offset_y, double arc_angle_value, double arc_angle_error, double arc_orientation, double radius, int line_thickness = 1, uchar value = 255, int draw_arc_steps = 360);
    static int      Draw_VectorField            (Mat *pMA_Target, vector<vector<double>> vv_XY_length_value, vector<vector<double>> vv_XY_angle_value, vector<vector<double>> vv_XY_length_error, vector<vector<double>> vv_XY_angle_error, uchar value = 255, int vector_thickness = 3, int error_steps = 360, int error_thickness = 1, bool grid_add = true, int grid_thicknes = 2, bool label_add = false, int label_thickness = 2, double label_scale = 1.0);
    static int      Draw_ArcField               (Mat *pMA_Target, vector<vector<double>> vv_XY_arc_angle_value, vector<vector<double>> vv_XY_arc_angle_error, vector<vector<double>> vv_XY_arc_orientation_value, vector<vector<double>> vv_XY_arc_radius_value, vector<vector<size_t> > vv_XY_draw_if_non_zero, uchar value = 255, int thickness = 3, int arc_draw_steps = 360, bool grid_add = true, int grid_thicknes = 2, bool label_add = false, int label_thickness = 2, double label_scale = 1.0);
    static int      Draw_CircleField            (Mat *pMA_Target, vector<vector<double>> vv_XY_radius_value, vector<vector<double>> vv_XY_radius_error, uchar value = 255, int circle_thickness = 1, bool circles_filled = true, bool grid_add = false, int grid_thicknes = 2, bool label_add = false, int label_thickness = 2, double label_scale = 1.0);
    static int      Draw_Rect                   (Mat *pMA_Target, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int thickness = 1, double val = 255);
    static int      Draw_Rect_Rotate            (Mat *pMA_Target, RotatedRect rrect, int thickness = 1, double value = 255);
    static int      Draw_GridSimple             (Mat *pMA_Target, int nx, int ny, Scalar value = 255, int thickness = 1);
    static int      Draw_Grid                   (Mat *pMA_Target, int nx, int ny, bool lines_add, int grid_thickness = 1, bool label_add = true, int label_thickness = 1, double label_scale = 1.0, double value = 255);
    static int      Draw_Boundaries             (Mat *pMA_Target, int width = 1, int val = 255);
    static int      Draw_Circle                 (Mat *pMA_Out, Mat *pMA_In, int x, int y, int r, int val = 255, int thickness = 1, bool filled = false);
    static int      Draw_Circle                 (Mat *pMA_Target, int x, int y, int r, int val, int thickness = 1, bool filled = false);
    static int      Draw_Circle                 (Mat *pMA_Target, int x, int y, int r, int val_r, int val_g, int val_b, int thickness = 1, bool filled = false);
    static int      Draw_Ellipse                (Mat *pMA_Target, RotatedRect ell, double val_r, double val_g, double val_b, int thickness = 1);
    static int      Draw_MarkerSymbol           (Mat *pMA_Target, int x1, int y1, int x2, int y2, int symbol_id, uchar r, uchar g, uchar b, double scale = 1);
    static int      Draw_Text                   (QImage *pQI_Target, QString text_tl, QString text_tr, QString text_bl, QString text_br, unsigned int size, QColor color);
    static int      Draw_Text                   (Mat *pMA_Target, QString text,int x = 0, int y = 0, int thickness = 1, double scale = 1.0, double value = 255);
    static int      Draw_Text_ContrastColor     (Mat *pMA_Target, QString text,int x = 0, int y = 0, int thickness = 1, double scale = 1.0);
    static int      Draw_Label_Numbers_LUT      (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, vector<double> v_LUT, bool border, double scale, double thickness, bool center, int precision, uchar r = 0, uchar g = 0, uchar b = 0);
    static int      Draw_Label_Text             (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, QStringList QSL_LabelTexts, bool border, double scale, double thickness, bool center, uchar r = 0, uchar g = 0, uchar b = 0, int connectivity = 4);
    static int      Draw_Label_Numbers_LUT_Gray (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, vector<double> v_LUT, int geometric, double scale, int thickness, bool center, int precision);
    static int      Draw_Label_Numbers          (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, double scale, double thickness, bool center);
    static int      Draw_Label_Numbers          (Mat *pMA_Out, Mat *pMA_Label, double scale, double thickness, bool center);
    static int      Draw_Label_Numbers_Corner   (Mat *pMA_Out, Mat *pMA_Label, double scale, double thickness);
    static int      Draw_Label_Numbers_Center   (Mat *pMA_Out, Mat *pMA_Label, double scale, double thickness);
    static int      Draw_Contours               (Mat *pMA_Target, vector<vector<Point>> vContours, int line_thickness, double value);
    static int      Draw_ContourText            (Mat *pMA_Target, vector<vector<Point>> vContours, QStringList QSL_Texts, vector<Point2f> vTextOrigins, int line_thickness, int text_thickness, double text_scale, double value);
    //static int    Draw_Contours               (Mat *pMA_Out, Mat *pMA_In, int thickness = 1, uchar value = 255);
    static QColor   Contrast_Color              (QColor col_in, bool force_black_and_white = true, bool mirror_hue = true, bool force_light2blue = true);
    static Scalar   Contrast_Color              (Vec3d val_BGR, bool force_black_and_white = true, bool mirror_hue = true, bool force_light2blue = true);
    static QString  Color2Text4StyleSheet       (QColor col_in);
    static int      Highlight_NumericalProblems (Mat *pMA_Out, Mat *pMA_In);


    static int      OverlayImage                (Mat *pMA_Out, Mat *pMA_BaseR, Mat *pMA_BaseG, Mat *pMA_BaseB, Mat *pMA_OverR, Mat *pMA_OverG, Mat *pMA_OverB, uchar thresh_overlay = 0);
    static int      OverlayOverwrite            (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Overlay, double intensity_overlay = 1.0, double intensity_backgr = 1.0);
    static int      OverlayOverwrite            (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Overlay, QColor color, double intensity_overlay = 1.0, double intensity_backgr = 1.0);
    static int      OverlayOverwrite            (Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Overlay, uchar r, uchar g, uchar b, double intensity_overlay = 1.0, double intensity_backgr = 1.0);
    static int      ExtremeValuesColor          (Mat *pMA_Out, Mat *pMA_In, double rel_low = 0.1, double rel_high = 0.9, double gamma = 1.0, bool color_low = false, bool color_high = true, bool zero_as_lowest = true);
    static int      Legend_HSV                  (Mat *pMA_Out, int width, int height, QStringList QSL_H, QStringList QSL_S, QStringList QSL_V, QString QS_H, QString QS_S, QString QS_V, double H_angle_min, double H_angle_range, double scale = 1, double thickness = 1);

    static int      ClassBorder_kNN             (Mat *pMA_Out, Mat *pMA_Class0, Mat *pMA_Class1, int n);

    static int      ObjectsMovement             (vector<double> *pvShift_PxPerFrame, vector<double> *pvDirection_Rad, vector<Point2f> *pvPositions, vector<Mat> *pvMA_In, vector<vector<Point2f>> *pvvCentroids, double max_Shift_PxPerFrame = INFINITY, size_t index_NewImg = 0, int connectivity = 8);
    static int      ObjectsMovement_Heatmap     (Mat *pMA_OutHeatmap, Mat *pMA_OutLegend, Mat *pMA_InValue, vector<vector<Point2f>> vv_FrmObjPositions, vector<vector<double>> vv_FrmObjShifts, vector<vector<double>> vv_FrmObjAngles, Point2f P_VortexCenter, double shift_scale, double value_scale, int blur_size_x, int blur_size_y, int mode, int legend_width, int legend_height, double legend_scale, double legend_thickness, size_t legend_examples = 5, double min_rel = 0.1, double max_rel = 0.9, double frame2time = 0.0417);

    static int      DistancesStat               (Mat *pMA_Out, Mat *pMA_In, function<double (vector<double>)> F_Stat);
    static int      RadiometricStereo           (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, double S1X, double S1Y, double S1Z, double S2X, double S2Y, double S2Z, double S3X, double S3Y, double S3Z, int out_mode);
    static int      RadiometricStereo           (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat S, int out_mode);

    static int      InterferometerMichelson     (Mat *pMA_Out, int scene_size_x_px, int scene_size_y_px, int scale_px, double scale_m, double wavelength_m, double dist_source_m, double dist_detector_m, double dist_mirror1_m, double dist_mirror2_m, double angle_mirror1_x, double angle_mirror1_y, double angle_mirror2_x, double angle_mirror2_y);

};

#endif // D_IMG_PROC_H
