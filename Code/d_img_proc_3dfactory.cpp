/************************************
 *   added:     05.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/


#include "d_img_proc_3dfactory.h"

D_Img_Proc_3dFactory::D_Img_Proc_3dFactory()
{

}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Duplicate()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Duplicate(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Pad_Border(int border_size_x, int border_size_y, int border_size_z, int border_type, double border_val)
{
    return
            [border_size_x, border_size_y, border_size_z, border_type, border_val](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Pad_Border(
                    pMA_Out,
                    pMA_In,
                    border_size_x,
                    border_size_y,
                    border_size_z,
                    border_type,
                    border_val);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_3dFactory::Filter_Function(function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    return
            [F1_CenterImage, F2_f1mask, F3_Combine, F4_f3center, border_type, DoNonZeroMaskOnly](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc_3D::Filter_Function(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    border_type,
                    DoNonZeroMaskOnly);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_3dFactory::Filter_Function_8bit(function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    return
            [F1_CenterImage, F2_f1mask, F3_Combine, F4_f3center, border_type, DoNonZeroMaskOnly](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc_3D::Filter_Function_8bit(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    border_type,
                    DoNonZeroMaskOnly);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Filter_Median(int size_x, int size_y, int size_z)
{
    return
            [size_x, size_y, size_z](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Filter_Median(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    size_z);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Filter_Eilenstein_Greater_Sum(int size_x, int size_y, int size_z)
{
    return
            [size_x, size_y, size_z](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Filter_Eilenstein_Greater_Sum(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    size_z);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Morphology_Dilation(int size_x, int size_y, int size_z)
{
    return
            [size_x, size_y, size_z](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Morphology_Dilation(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    size_z);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Morphology_Erosion(int size_x, int size_y, int size_z)
{
    return
            [size_x, size_y, size_z](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Morphology_Erosion(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    size_z);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Neighborhood_Configs()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Neighborhood_Configs(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Euler_Number(double *euler_number)
{
    return
            [euler_number](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::EulerNumber(
                    euler_number,
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_3dFactory::Distance_Transformation_EDT(double spacing_x, double spacing_y, double spacing_z)
{
    return
            [spacing_x, spacing_y, spacing_z](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc_3D::Distance_Transformation_EDT(
                    pMA_Out,
                    pMA_In,
                    spacing_x,
                    spacing_y,
                    spacing_z);
    };
}

function<int (Mat *)> D_Img_Proc_3dFactory::InterferometerMichelson(int scene_size_x_px, int scene_size_y_px, int scene_size_z_px, double scale_px2um, double wavelength_um, double dist_source_um, double dist_detector_um, double dist_mirror1_um, double dist_mirror2_um, double angle_mirror1_x, double angle_mirror1_y, double angle_mirror2_x, double angle_mirror2_y)
{
    return
            [scene_size_x_px, scene_size_y_px, scene_size_z_px, scale_px2um, wavelength_um, dist_source_um, dist_detector_um, dist_mirror1_um, dist_mirror2_um, angle_mirror1_x, angle_mirror1_y, angle_mirror2_x, angle_mirror2_y](Mat *pMA_Out)
    {
        return D_Img_Proc_3D::InterferometerMichelson(
                    pMA_Out,
                    scene_size_x_px,
                    scene_size_y_px,
                    scene_size_z_px,
                    scale_px2um,
                    wavelength_um,
                    dist_source_um,
                    dist_detector_um,
                    dist_mirror1_um,
                    dist_mirror2_um,
                    angle_mirror1_x,
                    angle_mirror1_y,
                    angle_mirror2_x,
                    angle_mirror2_y);
    };
}
