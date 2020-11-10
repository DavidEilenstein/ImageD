/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_PROC_H
#define D_VISDAT_PROC_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_component_list_context.h>
#include <d_component_analysis.h>
#include <d_img_proc.h>
#include <d_img_proc_3d.h>
#include <d_img_proc_2dfactory.h>
#include <d_img_proc_3dfactory.h>
#include <d_value_distribution_list.h>
#include <d_visdat_header.h>
#include <d_visdat_obj.h>
#include <d_visdat_dim.h>
#include <d_visdat_range.h>
#include <d_visdat_slicing.h>
#include <d_visdat_slice_1d.h>
#include <d_visdat_slice_2d.h>
#include <d_visdat_slice_3d.h>

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
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
using namespace cv;

/*!
 * \brief The D_VisDat_Proc class 6D image processing and efficeint loops of image processing performed on stacks of 2D or 3D images.
 * \details Some methods are implemented right in this class. These are the more complex ones that are about multiple dimensions.
 * Other methods (that is true for most methods here) just wrap the methods from D_Img_Proc and D_Img_Proc_3D .
 *
 * The factories D_Img_Proc_2dFactory and D_Img_Proc_3dFactory are used to create a function object, that is used multiple times on the independent 2D/3D slices of the 6D image.
 * This way performance is increased using automatic multithreading. D_VisDat_Slicing describes how a D_VisDat_Obj shall be sliced.
 *
 * D_StepWindow uses the methods from this class to perform image processing steps.
 */
class D_VisDat_Proc
{
public:
    D_VisDat_Proc();

    //Wrapper for img proc function to be executed with VDs
    static int  Wrap_VD              (D_VisDat_Slicing slice, function<int (Mat *pMA_Out)> img_proc,                                                         D_VisDat_Obj *pVD_Out);
    static int  Wrap_VD              (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In)> img_proc,                                            D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Wrap_VD              (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)> img_proc,                             D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Wrap_VD              (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)> img_proc,               D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static int  Wrap_VD              (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4);
    static int  Wrap_VD_SameSizeType (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In)> img_proc,                                            D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Wrap_VD_SameSizeType (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)> img_proc,                             D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Wrap_VD_SameSizeType (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)> img_proc,               D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static int  Wrap_VD_SameSizeType (D_VisDat_Slicing slice, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4);


    //Wrapper from D_Img_Proc to be used in threads
    static void Wrap_2D_img0            (int *ER, D_VisDat_Slice_2D plane, function<int (Mat *pMA_Out)> img_proc,                                                            D_VisDat_Obj *pVD_Out);
    static void Wrap_2D_img1            (int *ER, D_VisDat_Slice_2D plane, function<int (Mat *pMA_Out, Mat *pMA_In)> img_proc,                                               D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static void Wrap_2D_img2            (int *ER, D_VisDat_Slice_2D plane, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)> img_proc,                                D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static void Wrap_2D_img3            (int *ER, D_VisDat_Slice_2D plane, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)> img_proc,                  D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static void Wrap_2D_img4            (int *ER, D_VisDat_Slice_2D plane, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)> img_proc,    D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4);

    static void Wrap_3D_img0            (int *ER, D_VisDat_Slice_3D plane, function<int (Mat *pMA_Out)> img_proc,                                                            D_VisDat_Obj *pVD_Out);
    static void Wrap_3D_img1            (int *ER, D_VisDat_Slice_3D plane, function<int (Mat *pMA_Out, Mat *pMA_In)> img_proc,                                               D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static void Wrap_3D_img2            (int *ER, D_VisDat_Slice_3D plane, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)> img_proc,                                D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static void Wrap_3D_img3            (int *ER, D_VisDat_Slice_3D plane, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)> img_proc,                  D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static void Wrap_3D_img4            (int *ER, D_VisDat_Slice_3D plane, function<int (Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)> img_proc,    D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4);

    //save VD->files
    static int  Save_VD_ToBinaryFile    (D_VisDat_Obj *pVD_Save, QString QS_SavePath);
    static int  Save_VD_Single          (D_VisDat_Obj *pVD_Save, QString QS_SavePath, D_VisDat_Slice_2D slice);
    static int  Save_VD_List            (D_VisDat_Obj *pVD_Save, QString QS_Dir, QString QS_ImgName, QString QS_Suffix, int DimList = c_DIM_S,                   int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Save_VD_ListFull        (D_VisDat_Obj *pVD_Save, QString QS_Dir, QString QS_ImgName, QString QS_Suffix, int plane2D, bool transVis, int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max = false);

    //create files->VD
    static int  Create_VD_Single_Constant   (D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, int type = CV_8UC1, double value = 0);
    static int  Create_VD_Single            (D_VisDat_Obj *pVD_New, QString QS_Path,                                                            int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_Single            (D_VisDat_Obj *pVD_New, QFileInfo FI_Path,                                                          int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_Single_Raw        (D_VisDat_Obj *pVD_New, string path,                int width, int height, int out_type);
    static int  Create_VD_SinglePaged       (D_VisDat_Obj *pVD_New, QString QS_Path,                                   int DimPage = c_DIM_P,   int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_SinglePaged       (D_VisDat_Obj *pVD_New, QFileInfo FI_Path,                                 int DimPage = c_DIM_P,   int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_List              (D_VisDat_Obj *pVD_New, QStringList QSL_InPaths,    int DimList = c_DIM_S,                          int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_List              (D_VisDat_Obj *pVD_New, QFileInfoList FIL_InPaths,  int DimList = c_DIM_S,                          int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_ListPaged         (D_VisDat_Obj *pVD_New, QStringList QSL_InPaths,    int DimList = c_DIM_S,  int DimPage = c_DIM_P,  int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_ListPaged         (D_VisDat_Obj *pVD_New, QFileInfoList FIL_InPaths,  int DimList = c_DIM_S,  int DimPage = c_DIM_P,  int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_Video             (D_VisDat_Obj *pVD_New, QString QS_VideoPath,       int DimTime = c_DIM_T,                          int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y, bool force8UC1 = false);
    static int  Create_VD_Video             (D_VisDat_Obj *pVD_New, QFileInfo FI_VideoPath,     int DimTime = c_DIM_T,                          int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y, bool force8UC1 = false);
    static int  Create_VD_Video_Proc        (D_VisDat_Obj *pVD_New, QFileInfo FI_VideoPath, int blur_size, double blur_sigma, int t1_size, function<double (vector<double>)> f_stat_t1, int t2_size, function<double (vector<double>)> f_stat_t2, int t_offset, function<double (double, double)> f_combi, bool force8bit);
    static int  Create_VD_PageVector        (D_VisDat_Obj *pVD_New, QFileInfo FI_Path, D_VisDat_Dim DimNew, vector<int> vI_Pages2Load, vector<D_VisDat_Slice_2D> v2D_PageSource_DimsPosTarget, int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y);
    static int  Create_VD_PageVector_or0    (D_VisDat_Obj *pVD_New, QFileInfo FI_Path, D_VisDat_Dim DimNew, vector<int> vI_Pages2Load, vector<D_VisDat_Slice_2D> v2D_PageSource_DimsPosTarget, int DimImgX = c_DIM_X, int DimImgY = c_DIM_Y, bool full_0_instead = false, int type_if_full_0 = CV_8UC1);
    static int  Create_VD_ValueFunction             (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, function<double (double, double)> value_function);
    static int  Create_VD_ValueFunction_Complex     (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, function<complex<double> (complex<double> x, complex<double> y)> value_function);
    static int  Create_VD_ValueFunction_6D          (D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, function<double (double, double, double, double, double, double)> value_function);
    static int  Create_VD_Random                    (D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, int type, double min, double max, double a, double b, double c, double d, double e, double f);
    static int  Create_VD_FromBinaryFile            (D_VisDat_Obj *pVD_New, QString QS_Path);


    //write Mat->VD
    static int  Write_2D_Plane          (D_VisDat_Obj *pVD_Out, Mat *pMA_In, D_VisDat_Slice_2D OutPlane);
    static int  Write_2D_Plane          (D_VisDat_Obj *pVD_Out, QString path, D_VisDat_Slice_2D OutPlane);
    static int  Write_3D_Cuboid         (D_VisDat_Obj *pVD_Out, Mat *pMA_In, D_VisDat_Slice_3D OutPlane);
    static int  Instert_atPos           (D_VisDat_Obj *pVD_Target, D_VisDat_Obj *pVD_Source, vector<int> vOffset);

    //read VD->Mat
    static int  Read_2D_Plane           (Mat *pMA_Out, D_VisDat_Obj *pVD_In, D_VisDat_Slice_2D InPlane);
    static int  Read_3D_Cuboid          (Mat *pMA_Out, D_VisDat_Obj *pVD_In, D_VisDat_Slice_3D InPlane);

    //Copy
    static int  Copy                    (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);

    //Dimension
    static int  Dim_Pick                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, vector<int> pick_pos);
    static int  Dim_Crop                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Range crop_range);
    static int  Dim_Project             (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_project = c_DIM_X, int stat = c_STAT_MEAN_ARITMETIC, bool out_8bit = false);
    static int  Dim_Deserialise         (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_from = c_DIM_P, int dim_to = c_DIM_P, int spacing = 1);
    static int  Dim_Pages2Color         (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int p_red = 0, int p_green = 1, int p_blue = 2);
  //static int  Dim_Stitching           (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_source = c_DIM_S, Stitcher::Mode mode = Stitcher::PANORAMA, bool divide_images = false);
    static int  Stitch_Border_abs       (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, int border_R, int border_B, int overlap_R, int overlap_B, Stitcher::Mode mode = Stitcher::SCANS);
    static int  Stitch_Border_rel       (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, double border_R, double border_B, double overlap_R, double overlap_B, Stitcher::Mode mode = Stitcher::SCANS);
    static int  Stitch_Border_abs_custom(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, int border_R, int border_B, int overlap_R, int overlap_B);
    static int  Stitch_Border_rel_custom(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, double border_R, double border_B, double overlap_R, double overlap_B);


    //Edit
    static int  Crop_Rect_Rel           (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double x1_rel, double y1_rel, double x2_rel, double y2_rel);
    static int  Crop_Rect_Abs           (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int x, int y, int width, int height);
    static int  Crop_Rect_Rot           (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int x, int y, int width, int height, double angle);
    static int  Crop_Circle             (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int x, int y, int r);
    static int  Pad_Border              (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int size_z, int type = BORDER_CONSTANT, double border_value = 0);
    static int  ForceSize               (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int width, int heigth, int border_type = BORDER_CONSTANT);
    static int  Floodfill_Border        (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double new_val);
    static int  Floodfill_Delta         (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int seed_x, int seed_y, uchar val_new, uchar val_delta);
    static int  Scale_Factor            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double scale_dim_0, double scale_dim_1);
    static int  Scale_ToSize            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_dim_0, int size_dim_1);

    //Convert
    static int  Convert_Color           (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int cvt_mode);
    static int  Convert_Color2Mono      (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int col2mono_code);
    static int  Normalize               (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int norm, int type, double min, double max);
    static int  Convert_Double          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Channels_Merge          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, int channels_count, bool channels_use[4]);
    static int  Channels_Merge          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Channels_Split          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int channel);
    static int  Convert_8UC1_binary     (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Visualize_to8bit        (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max = false);
    static int  Convert_Angle2Color_Rad (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_InAngleRad, uchar Saturation = 255, uchar Value = 255);

    //Threshold
    static int  Threshold_Auto          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max, int auto_type);
    static int  Threshold_Auto_Otsu     (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max);
    static int  Threshold_Absolute_8U   (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max, int thresh);
    static int  Threshold_Absolute      (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double thresh);
    static int  Threshold_Relative_8U   (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double thresh_rel);
    static int  Threshold_Relative      (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double base, double thresh_rel);
    static int  Threshold_Adaptive      (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max, int mask_type, int mask_size, double offset);
    static int  Threshold_Adaptive_Gauss(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, double sigma, double offset);

    //Grab Color
    static int  Color_Grab              (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int color_space, int out_mode, vector<uchar> min, vector<uchar> max);

    //Labeling
    static int  Labeling                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int connecivity, int out_depth);

    //Fill Holes
    static int  Fill_Holes              (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);

    //Shading
    static int  Shading_Correct         (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Ref);
    
    //Filter
    static int  Filter_Mean                     (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, int out_depth, bool norm);
    static int  Filter_RootMeanSquare           (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, int out_depth, bool norm);
    static int  Filter_Gauss                    (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, double sigma_x, double sigma_y);
    static int  Filter_Median                   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x3d_or_xy2d, int size_y = 3, int size_z = 3);
    static int  Filter_Median                   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask);
    static int  Filter_Laplace                  (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size,               int border, int out_depth, double scale, double delta);
    static int  Filter_Sobel                    (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size,               int border, int out_depth, double scale, double delta, int d_x, int d_y);
    static int  Filter_Canny                    (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, double thres_low, double thres_high, bool L2_gradient);
    static int  Filter_Bilateral                (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int diameter,           int border,                double sigma_color, double sigma_space);
    static int  Filter_Gabor                    (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, int out_depth, double sigma, double theta, double lambda, double gamma, double psi, double delta);
    static int  Filter_Eilenstein               (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int comp, int size_x, int size_y, bool normalized, double constant);
    static int  Filter_Eilenstein               (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, function<double (double cur, double nei)> response_CurNei, function<double (double res, double wei)> weight_ResWeigth, function<double (vector<double> v_res)> combine_Responses);
    static int  Filter_Eilenstein_Greater_Sum   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x = 3, int size_y = 3, int size_z = 3);
    static int  Filter_Function                 (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static int  Filter_Function_8bit            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, function<uchar  (double cur, double nei)> F1_CenterImage, function<uchar  (double f1r, double msk)> F2_f1mask, function<uchar  (vector<double> vf2r)> F3_Combine, function<uchar  (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static int  Filter_Stat                     (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, int stat, int border_type = BORDER_CONSTANT);
    static int  Filter_Stat_Circular            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double radius, int stat, int border_type = BORDER_CONSTANT);

    //Morphology
    static int  Morphology_Elemental            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int morph_type, int elem_type, int elem_size_X, int elem_size_Y, int border_type, int iterations);
    static int  Morphology_Skeleton             (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In,                 int elem_type, int elem_size_X, int elem_size_Y, int border_type);
    static int  Morphology_Dilation             (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_size_X, int elem_size_Y, int elem_size_Z);
    static int  Morphology_Erosion              (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_size_X, int elem_size_Y, int elem_size_Z);
    static int  Morphology_LocMax_Rect          (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_size_X = 3, int elem_size_Y = 3);



    //Math
    static int  Math_1img_Inversion                 (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Math_1img_Addition                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double summmand);
    static int  Math_1img_Subtraction               (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double subtrahend);
    static int  Math_1img_Multiplication            (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double factor);
    static int  Math_1img_Division                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double divisor);
    static int  Math_1img_Power                     (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double power);
    static int  Math_1img_Root                      (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Math_1img_Log                       (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Math_2img_Addition                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_AdditionWeighted          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, double weight_1, double weight_2, double weight_sum);
    static int  Math_2img_Subtraction               (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_SubtractionAbsolute       (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_Multiplication            (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, double scale);
    static int  Math_2img_Division                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, double scale);
    static int  Math_2img_BitwiseAnd                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_BitwiseOr                 (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_BitwiseXor                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_Minimum                   (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_Maximum                   (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1);
    static int  Math_2img_Compare                   (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, int comp);
    static int  Math_2img_Function                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<double (double, double)> function_img1_img2);
    static int  Math_2img_Function_Complex          (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<complex<double> (complex<double> x, complex<double> y)> function_img1_img2);
    static int  Math_2img_Function_8bit             (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<uchar  (double, double)> function_img1_img2);
    static int  Math_2img_Function_UnequalSize      (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<double (double, double)> function_img1_img2);
    static int  Math_2img_Function_UnequalSize_8bit (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<uchar  (double, double)> function_img1_img2);
    static int  Math_3img_Addition                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Math_3img_Addition                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, double summand);
    static int  Math_3img_Multiplication            (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Math_3img_Multiplication            (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, double factor);
    static int  Math_3img_BitwiseAnd                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Math_3img_BitwiseOr                 (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2);
    static int  Math_4img_Addition                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static int  Math_4img_Addition                  (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, double summand);
    static int  Math_4img_Multiplication            (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static int  Math_4img_Multiplication            (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, double factor);
    static int  Math_4img_BitwiseAnd                (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);
    static int  Math_4img_BitwiseOr                 (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3);

    //Transformation
    static int  Transformation_Distance         (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int metric, int precision, double spacing_x3d = 1.0, double spacing_y3d = 1.0, double spacing_z3d = 1.0);
    static int  Transformation_Fourier          (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Re, D_VisDat_Obj *pVD_In_Im, bool complex_input = true, bool invers = false, bool force_fft = true, bool out_real = false, int out_complex_mode = c_COMPLEX2REAL_ABS, bool out_scale = false, bool out_center = true, bool out_nof0 = true);
    static int  Transformation_Watershed        (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Marker);
    static int  Transformation_Watershed_Auto   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Marker, bool include_not_seeded, bool conv_8bit, bool exclude_border);
    static int  Transformation_Watershed_Auto   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border);
    static int  Transformation_Watershed_Auto   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, double sigma, bool include_not_seeded, bool conv_8bit, bool exclude_border);

    //Feature
    static int  Feature_Value                   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int feature,                              int connectivity);
    static int  FeatureContext_Value            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, int connectivity = 4);
    static int  Feature_Select                  (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int feature, double f_min, double f_max,  int connectivity);
    static int  FeatureContext_Select           (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, double t_min, double t_max, int connectivity = 4);
    static int  Feature_Visualize               (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int feature,                              int connectivity, int thickness, double scale);
    static int  Feature_Connect                 (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat1, int feat2, function<bool(double, double)> comp, int connect_mode = c_CONNECT_CLOSEST, int connectivity = 4, int thickness = 2);


    //Geometric
    static int  Geometric_Reduce                (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int geometric,                            int connectivity, int thickness, uchar value);

    //Comsmetic
    static int  Histogram_Equalize              (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  GammaSpread                     (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double gamma, double in_min, double in_max, double out_min, double out_max, bool force_8bit);
    static int  Draw_Label_Numbers              (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Label, double scale, double thickness, bool center);

    //Other
    static int  Neighborhood_Configs            (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In);
    static int  Euler_Number                    (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, double *euler_number, D_VisDat_Obj *pVD_In);
    static int  MotionField/*  BUGGY!!! :-(   */(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_space = 5, int size_time = 3);
    static int  ClassBorder_kNN                 (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_Class0, D_VisDat_Obj *pVD_Class1, int n);
    static int  HDR                             (D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_exposures = c_DIM_S, double exp_min = 20, double exp_fac = 2, bool project_do = true, int stat = c_STAT_MEAN_ARITMETIC, bool thres_do = true, double thres_low = 16, double thres_high = 240, double val_default = 0);
    static int  DistancesStat                   (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, function<double (vector<double>)> F_Stat);
    static int  ZernikeStack                    (D_VisDat_Obj *pVD_Out, int r_max, int j_max);
    static int  RadiometricStereo               (D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, double S1X, double S1Y, double S1Z, double S2X, double S2Y, double S2Z, double S3X, double S3Y, double S3Z, int out_mode);


    //Calc
    static int Calc_MinMax                      (D_VisDat_Obj *pVD_In, double *min_ext, double *max_ext);
    static int Calc_Hist_Multi                  (vector<vector<double>> *vv_hist, D_VisDat_Obj *pVD_In, bool uniform, bool accum, unsigned int class_count, vector<double> *v_min_ext, vector<double> *v_max_ext, vector<double> *v_step_ext);
    static int Calc_Hist_1C                     (vector<double> *v_hist, D_VisDat_Obj *pVD_In, bool uniform, bool accum, unsigned int class_count, double *min_ext, double *max_ext, double *step_ext);
    static int Calc_Hist_1C_8bit                (vector<double> *v_hist, D_VisDat_Obj *pVD_In, bool uniform, bool accum);
    static int Calc_DataVector_1C               (vector<double> *v_data_out, D_VisDat_Obj *pVD_In, bool ignore_zeros);

};

#endif // D_VISDAT_PROC_H
