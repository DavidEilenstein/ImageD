/************************************
 *   added:     16.05.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_IMG_PROC_2DFACTORY_H
#define D_IMG_PROC_2DFACTORY_H

//own
#include <d_enum.h>
#include <d_img_proc.h>
#include <d_stat.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_value_distribution_list.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_Img_Proc_2dFactory class Factory that turns methods from D_Img_Proc into function objects.
 * \details The generated function objects can be passed to other methods. Mostly use in D_VisDat_Proc.
 */
class D_Img_Proc_2dFactory
{
public:
    D_Img_Proc_2dFactory();


    //0 Input -> 1 Output
    static function<int (Mat *)>                                Generate_byValueFunction            (int width, int height, function<double (double x, double y)> value_function);
    static function<int (Mat *)>                                Generate_byValueFunction_Complex    (int width, int height, function<complex<double> (complex<double> x, complex<double> y)> value_function);
    static function<int (Mat *)>                                Load_From_Path_Raw                  (string path, int width, int height, int out_type);
    static function<int (Mat *)>                                Draw_Contours                       (vector<vector<Point>> vContours, int line_thickness, double value);

    //1 Input -> 1 Output
    static function<int (Mat *, Mat *)>                         Convert_Color                       (int cvt_mode);
    static function<int (Mat *, Mat *)>                         Convert_Color2Mono                  (int col2mono_code);
    static function<int (Mat *, Mat *)>                         Normalize                           (int norm, int type, double min, double max);
    static function<int (Mat *, Mat *)>                         Convert_Depth_NoScaling             (int depth);
    static function<int (Mat *, Mat *)>                         Channel_Split                       (int channel);
    static function<int (Mat *, Mat *)>                         Channel_Supression                  (bool use_r = true, bool use_g = true, bool use_b = true, bool force_3ch = false);
    static function<int (Mat *, Mat *)>                         Convert_8UC1_binary                 ();
    static function<int (Mat *, Mat *)>                         Visualize_to8bit                    (int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max = false);

    static function<int (Mat *, Mat *)>                         Threshold_Auto                      (int mode, int max, int auto_type);
    static function<int (Mat *, Mat *)>                         Threshold_Value                     (int mode, int max, int thresh);
    static function<int (Mat *, Mat *)>                         Threshold_Absolute                  (double thresh);
    static function<int (Mat *, Mat *)>                         Threshold_Realtive                  (double base, double thresh_rel);
    static function<int (Mat *, Mat *)>                         Threshold_Adaptive                  (int mode, int max, int mask_type, int mask_size, double offset);
    static function<int (Mat *, Mat *)>                         Threshold_Adaptive_Gauss            (int size, double sigma, double offset, double scale);
    static function<int (Mat *, Mat *)>                         Threshold_RankOrderOffsetHysteresis (double radius, double quantile, double thresh_offset_indicator, double thresh_offset_hysteresis, bool labeling = false);

    static function<int (Mat *, Mat *)>                         Labeling                        (int connectivity, int out_depth);
    static function<int (Mat *, Mat *)>                         Grab_Color                      (int color_space, int out_mode, vector<uchar> min, vector<uchar> max);
    static function<int (Mat *, Mat *)>                         Fill_Holes                      ();

    static function<int (Mat *, Mat *)>                         Crop_Rect_Rel                   (double x1_rel, double y1_rel, double x2_rel, double y2_rel);
    static function<int (Mat *, Mat *)>                         Crop_Rect_Abs                   (int x, int y, int width, int height);
    static function<int (Mat *, Mat *)>                         Crop_Rect_Rot                   (int x, int y, int width, int height, double angle);
    static function<int (Mat *, Mat *)>                         Crop_Circle                     (int x, int y, int r);
    static function<int (Mat *, Mat *)>                         Scale_Factor                    (double scale_x, double scale_y);
    static function<int (Mat *, Mat *)>                         Scale_ToSize                    (int size_x, int size_y);
    static function<int (Mat *, Mat *)>                         Pad_Border                      (int size_x, int size_y, int type = BORDER_CONSTANT);
    static function<int (Mat *, Mat *)>                         ForceSize                       (int width, int heigth, int border_type = BORDER_CONSTANT);
    static function<int (Mat *, Mat *)>                         Floodfill_Border                (double new_val);
    static function<int (Mat *, Mat *)>                         Floodfill_Delta                 (int seed_x, int seed_y, uchar val_new, uchar val_delta);

    static function<int (Mat *, Mat *)>                         Morphology_Elemental            (int morph_type, int elem_type, int elem_size_X, int elem_size_Y, int border_type, int iterations);
    static function<int (Mat *, Mat *)>                         Morphology_Skeleton             (int elem_type, int elem_size_X, int elem_size_Y, int border_type);
    static function<int (Mat *, Mat *)>                         Morphology_LocMax_Rect          (int elem_size_X = 3, int elem_size_Y = 3);
    static function<int (Mat *, Mat *)>                         Filter_Maximum_1C               (size_t mask_size_x, size_t mask_size_y);


    static function<int (Mat *, Mat *)>                         Filter_Mean                     (int size_x, int size_y, int border, int out_depth, bool norm);
    static function<int (Mat *, Mat *)>                         Filter_RootMeanSquare           (int size_x, int size_y, int border, int out_depth, bool norm);
    static function<int (Mat *, Mat *)>                         Filter_Gauss                    (int size_x, int size_y, int border, double sigma_x, double sigma_y);
    static function<int (Mat *, Mat *)>                         Filter_Median                   (int size);
    static function<int (Mat *, Mat *)>                         Filter_Laplace                  (int size,               int border, int out_depth, double scale, double delta);
    static function<int (Mat *, Mat *)>                         Filter_Sobel                    (int size,               int border, int out_depth, double scale, double delta, int d_x, int d_y);
    static function<int (Mat *, Mat *)>                         Filter_Canny                    (int size, double thres_low, double thres_high, bool L2_gradient);
    static function<int (Mat *, Mat *)>                         Filter_Bilateral                (int diameter,           int border,                double sigma_color, double sigma_space);
    static function<int (Mat *, Mat *)>                         Filter_Gabor                    (int size_x, int size_y, int border, int out_depth, double sigma, double theta, double lambda, double gamma, double psi, double delta);
    static function<int (Mat *, Mat *)>                         Filter_Eilenstein               (int comp, int size_x, int size_y, bool normalized, double constant);
    static function<int (Mat *, Mat *)>                         Filter_Stat_Circular            (double radius, int stat, int border_type = BORDER_CONSTANT);
    static function<int (Mat *, Mat *)>                         Filter_Stat_Rect                (int size_x, int size_y, int stat, int border_type = BORDER_CONSTANT);

    static function<int (Mat *, Mat *)>                         Filter_RankOrder_Circular       (double quantil, double radius);
    static function<int (Mat *, Mat *)>                         Filter_RankOrder_Rect           (double quantil, int size_x, int size_y);

    static function<int (Mat *, Mat *)>                         Math_1img_Inversion             ();
    static function<int (Mat *, Mat *)>                         Math_1img_Addition              (double summmand);
    static function<int (Mat *, Mat *)>                         Math_1img_Subtraction           (double subtrahend);
    static function<int (Mat *, Mat *)>                         Math_1img_Multiplication        (double factor);
    static function<int (Mat *, Mat *)>                         Math_1img_Division              (double divisor);
    static function<int (Mat *, Mat *)>                         Math_1img_Power                 (double power);
    static function<int (Mat *, Mat *)>                         Math_1img_Root                  ();
    static function<int (Mat *, Mat *)>                         Math_1img_Log                   ();

    static function<int (Mat *, Mat *)>                         Transformation_Distance         (int metric, int precision);

    static function<int (Mat *, Mat *)>                         Transformation_Watershed_Auto   (double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border);
    static function<int (Mat *, Mat *)>                         Transformation_Watershed_Auto   (int size, double sigma, bool include_not_seeded, bool conv_8bit, bool exclude_border);

    static function<int (Mat *, Mat *)>                         Feature_Value                   (int feature,                              int connectivity);
    static function<int (Mat *, Mat *)>                         FeatureContext_Value            (int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, int connectivity = 4);
    static function<int (Mat *, Mat *)>                         Feature_Select                  (int feature, double f_min, double f_max,  int connectivity);
    static function<int (Mat *, Mat *)>                         FeatureContext_Select           (int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, double t_min, double t_max, int connectivity = 4);
    static function<int (Mat *, Mat *)>                         Feature_Visualize               (int feature,                              int connectivity, int thickness, double scale);
    static function<int (Mat *, Mat *)>                         Feature_Connect                 (int pt_type1, int pt_type2, double dist_min, double dist_max, int feat1, int feat2, function<bool(double, double)> comp, int connect_mode = c_CONNECT_CLOSEST, int connectivity = 4, int thickness = 2);

    static function<int (Mat *, Mat *)>                         Geometric_Reduce                (int geometric,                            int connectivity, int thickness, uchar value);

    static function<int (Mat *, Mat *)>                         Histogram_Equalize              ();
    static function<int (Mat *, Mat *)>                         GammaSpread                     (double gamma, double in_min, double in_max, double out_min, double out_max, bool force_8bit);
    static function<int (Mat *, Mat *)>                         GammaSpread_Quantiles           (double gamma, double quantile_low, double quantile_high, double out_min = 0, double out_max = 255, bool force_8bit = false, bool ignore_zeros = true);
    static function<int (Mat *, Mat *)>                         DistancesStat                   (function<double (vector<double>)> F_Stat);
    static function<int (Mat *, Mat *)>                         Convert_Angle2Color_Rad          (uchar Saturation = 255, uchar Value = 255);

    //2 Input -> 1 Output
    static function<int (Mat *, Mat *, Mat *)>                  Shading_Correct                 ();

    static function<int (Mat *, Mat *, Mat *)>                  Hysteresis                      (bool labeling = false);

    static function<int (Mat *, Mat *, Mat *)>                  Filter_RankOrder                (double quantil);
    static function<int (Mat *, Mat *, Mat *)>                  Filter_Median                   ();
    static function<int (Mat *, Mat *, Mat *)>                  Filter_Eilenstein               (function<double (double cur, double nei)> response_CurNei, function<double (double res, double wei)> weight_ResWeigth, function<double (vector<double> v_res)> combine_Responses);
    static function<int (Mat *, Mat *, Mat *)>                  Filter_Function                 (function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static function<int (Mat *, Mat *, Mat *)>                  Filter_Function_8bit            (function<uchar  (double cur, double nei)> F1_CenterImage, function<uchar  (double f1r, double msk)> F2_f1mask, function<uchar  (vector<double> vf2r)> F3_Combine, function<uchar  (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static function<int (Mat *, Mat *, Mat *)>                  Filter_Stat                     (int stat, int border_type = BORDER_CONSTANT);

    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Addition              ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_AdditionWeighted      (double weight_1, double weight_2, double weight_sum);
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Subtraction           ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_SubtractionAbsolute   ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Multiplication        (double scale);
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Division              (double scale);
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_BitwiseAnd            ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_BitwiseOr             ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_BitwiseXor            ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Minimum               ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Maximum               ();
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Compare               (int comp);
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Function              (function<double (double x, double y)> function_img1_img2);
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Function_8bit         (function<uchar  (double x, double y)> function_img1_img2);
    static function<int (Mat *, Mat *, Mat *)>                  Math_2img_Function_Complex      (function<complex<double> (complex<double> x, complex<double> y)> function_img1_img2);

    static function<int (Mat *, Mat *, Mat *)>                  Transformation_Fourier          (bool complex_input = true, bool invers = false, bool force_fft = true, bool out_real = false, int out_complex_mode = c_COMPLEX2REAL_ABS, bool out_scale = false, bool out_center = true, bool out_nof0 = true);
    static function<int (Mat *, Mat *, Mat *)>                  Transformation_Watershed        ();
    static function<int (Mat *, Mat *, Mat *)>                  Transformation_Watershed_Auto   (bool include_not_seeded, bool conv_8bit, bool exclude_border);

    static function<int (Mat *, Mat *, Mat *)>                  Draw_Label_Numbers              (double scale, double thickness, bool center);
    static function<int (Mat *, Mat *, Mat *)>                  Draw_Label_Numbers_LUT          (vector<double> v_LUT, bool border, double scale, double thickness, bool center, int precision, uchar r = 0, uchar g = 0, uchar b = 0);
    static function<int (Mat *, Mat *, Mat *)>                  Draw_Label_Text                 (QStringList QSL_LabelTexts, bool border, double scale, double thickness, bool center, uchar r = 0, uchar g = 0, uchar b = 0, int connectivity = 4);
    static function<int (Mat *, Mat *, Mat *)>                  ClassBorder_kNN                 (int n);

    static function<int (Mat *, Mat *, Mat *)>                  OverlayOverwrite                (double intensity_overlay = 1.0, double intensity_backgr = 1.0);

    static function<int (Mat *, Mat *, Mat *)>                  ValueStat                       (int stat, int connectivity = 8);
    static function<int (Mat *, Mat *, Mat *)>                  ValueStat_Select                (int stat, double thresh_min, double thresh_max, int connectivity = 8);


    //3 Input -> 1 Output
    static function<int (Mat *, Mat *, Mat *, Mat*)>            Transformation_Watershed_Custom (int connectivity = 8);

    static function<int (Mat *, Mat *, Mat *, Mat*)>            Math_3img_Addition              ();
    static function<int (Mat *, Mat *, Mat *, Mat*)>            Math_3img_Addition              (double summand);
    static function<int (Mat *, Mat *, Mat *, Mat*)>            Math_3img_Multiplication        ();
    static function<int (Mat *, Mat *, Mat *, Mat*)>            Math_3img_Multiplication        (double factor);
    static function<int (Mat *, Mat *, Mat *, Mat*)>            Math_3img_BitwiseAnd            ();
    static function<int (Mat *, Mat *, Mat *, Mat*)>            Math_3img_BitwiseOr             ();

    static function<int (Mat *, Mat *, Mat *, Mat *)>           Channel_Merge                   ();
    static function<int (Mat *, Mat *, Mat *, Mat *)>           RadiometricStereo               (double S1X, double S1Y, double S1Z, double S2X, double S2Y, double S2Z, double S3X, double S3Y, double S3Z, int out_mode);

    static function<int (Mat *, Mat *, Mat *, Mat *)>           Morphology_Reconstruction       (double quantil = 1);

    //4 Input -> 2 Output
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Channel_Merge                   (int channel_count, bool channels_use[4]);

    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Math_4img_Addition              ();
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Math_4img_Addition              (double summand);
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Math_4img_Multiplication        ();
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Math_4img_Multiplication        (double factor);
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Math_4img_BitwiseAnd            ();
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Math_4img_BitwiseOr             ();

    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Stitch_Border_abs               (int border_R, int border_B, int overlap_R, int overlap_B, Stitcher::Mode mode = Stitcher::SCANS);
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Stitch_Border_rel               (double border_R, double border_B, double overlap_R, double overlap_B, Stitcher::Mode mode = Stitcher::SCANS);
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Stitch_Border_abs_custom        (int border_R, int border_B, int overlap_R, int overlap_B);
    static function<int (Mat *, Mat *, Mat *, Mat *, Mat *)>    Stitch_Border_rel_custom        (double border_R, double border_B, double overlap_R, double overlap_B);

};

#endif // D_IMG_PROC_2DFACTORY_H
