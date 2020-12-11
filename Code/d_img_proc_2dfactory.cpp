#include "d_img_proc_2dfactory.h"

D_Img_Proc_2dFactory::D_Img_Proc_2dFactory()
{

}

function<int (Mat *)> D_Img_Proc_2dFactory::Generate_byValueFunction(int width, int height, function<double (double, double)> value_function)
{
    return
            [width, height, value_function](Mat *pMA_Out)
    {
        return D_Img_Proc::Generate_byValueFunction(
                    pMA_Out,
                    width,
                    height,
                    value_function);
    };
}

function<int (Mat *)> D_Img_Proc_2dFactory::Generate_byValueFunction_Complex(int width, int height, function<complex<double> (complex<double> x, complex<double> y)> value_function)
{
    return
            [width, height, value_function](Mat *pMA_Out)
    {
        return D_Img_Proc::Generate_byValueFunction_Complex(
                    pMA_Out,
                    width,
                    height,
                    value_function);
    };
}

function<int (Mat *)> D_Img_Proc_2dFactory::Load_From_Path_Raw(string path, int width, int height, int out_type)
{
    return
            [path, width, height, out_type](Mat *pMA_Out)
    {
        return D_Img_Proc::Load_From_Path_Raw(
                    pMA_Out,
                    path,
                    width,
                    height,
                    out_type);
    };
}



function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Convert_Color(int cvt_mode)
{
    return
            [cvt_mode](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Convert_Color(
                    pMA_Out,
                    pMA_In,
                    cvt_mode);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Convert_Color2Mono(int col2mono_code)
{
    return
            [col2mono_code](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Convert_Color2Mono(
                    pMA_Out,
                    pMA_In,
                    col2mono_code);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Normalize(int norm, int type, double min, double max)
{
    return
            [norm, type, min, max](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Normalize(
                    pMA_Out,
                    pMA_In,
                    norm,
                    type,
                    min,
                    max);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Convert_Double()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Convert_Double(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Channel_Split(int channel)
{
    return
            [channel](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Split(
                    pMA_Out,
                    pMA_In,
                    channel);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Convert_8UC1_binary()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Combi_8UC1_binary(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Visualize_to8bit(int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max)
{
    return
            [mode_crop, mode_trafo, mode_anchor, mode_range, val_anchor, val_range, val_min, val_max, val_gamma, val_center, val_scale, keep_min_max](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Visualize_to8bit(
                    pMA_Out,
                    pMA_In,
                    mode_crop,
                    mode_trafo,
                    mode_anchor,
                    mode_range,
                    val_anchor,
                    val_range,
                    val_min,
                    val_max,
                    val_gamma,
                    val_center,
                    val_scale,
                    keep_min_max);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Threshold_Auto(int mode, int max, int auto_type)
{
    return
            [mode, max, auto_type](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Threshold_Auto(
                    pMA_Out,
                    pMA_In,
                    mode,
                    max,
                    auto_type);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Threshold_Value(int mode, int max, int thresh)
{
    return
            [mode, max, thresh](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Threshold_Value(
                    pMA_Out,
                    pMA_In,
                    mode,
                    max,
                    thresh);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Threshold_Absolute(double thresh)
{
    return
            [thresh](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Threshold_Absolute(
                    pMA_Out,
                    pMA_In,
                    thresh);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Threshold_Realtive(double base, double thresh_rel)
{
    return
            [base, thresh_rel](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Threshold_Relative(
                    pMA_Out,
                    pMA_In,
                    base,
                    thresh_rel);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Threshold_Adaptive(int mode, int max, int mask_type, int mask_size, double offset)
{
    return
            [mode, max, mask_type, mask_size, offset](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Threshold_Adaptive(
                    pMA_Out,
                    pMA_In,
                    mode,
                    max,
                    mask_type,
                    mask_size,
                    offset);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Threshold_Adaptive_Gauss(int size, double sigma, double offset)
{
    return
            [size, sigma, offset](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Threshold_Adaptive_Gauss(
                    pMA_Out,
                    pMA_In,
                    size,
                    sigma,
                    offset);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Labeling(int connectivity, int out_depth)
{
    return
            [connectivity, out_depth](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Labeling(
                    pMA_Out,
                    pMA_In,
                    connectivity,
                    out_depth);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Grab_Color(int color_space, int out_mode, vector<uchar> min, vector<uchar> max)
{
    return
            [color_space, out_mode, min, max](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Color_Grab(
                    pMA_Out,
                    pMA_In,
                    color_space,
                    out_mode,
                    min,
                    max);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Fill_Holes()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Fill_Holes(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Mean(int size_x, int size_y, int border, int out_depth, bool norm)
{
    return
            [size_x, size_y, border, out_depth, norm](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Box(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    border,
                    out_depth,
                    norm);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_RootMeanSquare(int size_x, int size_y, int border, int out_depth, bool norm)
{
    return
            [size_x, size_y, border, out_depth, norm](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Box_RMS(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    border,
                    out_depth,
                    norm);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Gauss(int size_x, int size_y, int border, double sigma_x, double sigma_y)
{
    return
            [size_x, size_y, border, sigma_x, sigma_y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Gauss(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    border,
                    sigma_x,
                    sigma_y);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Median(int size)
{
    return
            [size](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Median(
                    pMA_Out,
                    pMA_In,
                    size);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Laplace(int size, int border, int out_depth, double scale, double delta)
{
    return
            [size, border, out_depth, scale, delta](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Laplace(
                    pMA_Out,
                    pMA_In,
                    size,
                    border,
                    out_depth,
                    scale,
                    delta);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Sobel(int size, int border, int out_depth, double scale, double delta, int d_x, int d_y)
{
    return
            [size, border, out_depth, scale, delta, d_x, d_y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Sobel(
                    pMA_Out,
                    pMA_In,
                    size,
                    border,
                    out_depth,
                    scale,
                    delta,
                    d_x,
                    d_y);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Canny(int size, double thres_low, double thres_high, bool L2_gradient)
{
    return
            [size, thres_low, thres_high, L2_gradient](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Canny(
                    pMA_Out,
                    pMA_In,
                    size,
                    thres_low,
                    thres_high,
                    L2_gradient);
    };
}


function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Bilateral(int diameter, int border, double sigma_color, double sigma_space)
{
    return
            [diameter, border, sigma_color, sigma_space](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Bilateral(
                    pMA_Out,
                    pMA_In,
                    diameter,
                    border,
                    sigma_color,
                    sigma_space);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Gabor(int size_x, int size_y, int border, int out_depth, double sigma, double theta, double lambda, double gamma, double psi, double delta)
{
    return
            [size_x, size_y, border, out_depth, sigma, theta, lambda, gamma, psi, delta](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Gabor(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    border,
                    out_depth,
                    sigma,
                    theta,
                    lambda,
                    gamma,
                    psi,
                    delta);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Eilenstein(int comp, int size_x, int size_y, bool normalized, double constant)
{
    return
            [comp, size_x, size_y, normalized, constant](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Eilenstein(
                    pMA_Out,
                    pMA_In,
                    comp,
                    size_x,
                    size_y,
                    normalized,
                    constant);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Stat_Circular(double radius, int stat, int border_type)
{
    return
            [radius, stat, border_type](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Stat_Circular(
                    pMA_Out,
                    pMA_In,
                    radius,
                    stat,
                    border_type);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Stat_Rect(int size_x, int size_y, int stat, int border_type)
{
    return
            [size_x, size_y, stat, border_type](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Stat_Rect(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    stat,
                    border_type);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_RankOrder_Circular(double quantil, double radius)
{
    return
                [quantil, radius](Mat *pMA_Out, Mat *pMA_In)
        {
            return D_Img_Proc::Filter_RankOrder_Circular(
                        pMA_Out,
                        pMA_In,
                        quantil,
                        radius);
        };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_RankOrder_Rect(double quantil, int size_x, int size_y)
{
    return
            [quantil, size_x, size_y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_RankOrder_Rect(
                    pMA_Out,
                    pMA_In,
                    quantil,
                    size_x,
                    size_y);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Inversion()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgSelf_Not(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Addition(double summmand)
{
    return
            [summmand](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Add(
                    pMA_Out,
                    pMA_In,
                    summmand);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Subtraction(double subtrahend)
{
    return
            [subtrahend](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Sub(
                    pMA_Out,
                    pMA_In,
                    subtrahend);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Multiplication(double factor)
{
    return
            [factor](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Mult(
                    pMA_Out,
                    pMA_In,
                    factor);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Division(double divisor)
{
    return
            [divisor](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Div(
                    pMA_Out,
                    pMA_In,
                    divisor);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Power(double power)
{
    return
            [power](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Pow(
                    pMA_Out,
                    pMA_In,
                    power);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Root()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Root(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Math_1img_Log()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Math_ImgScal_Log(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Transformation_Distance(int metric, int precision)
{
    return
            [metric, precision](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Transformation_Distance(
                    pMA_Out,
                    pMA_In,
                    metric,
                    precision);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Transformation_Watershed_Auto(double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    return
            [distance, include_not_seeded, conv_8bit, exclude_border](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Transformation_Watershed_Auto(
                    pMA_Out,
                    pMA_In,
                    distance,
                    include_not_seeded,
                    conv_8bit,
                    exclude_border);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Transformation_Watershed_Auto(int size, double sigma, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    return
            [size, sigma, include_not_seeded, conv_8bit, exclude_border](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Transformation_Watershed_Auto(
                    pMA_Out,
                    pMA_In,
                    size,
                    sigma,
                    include_not_seeded,
                    conv_8bit,
                    exclude_border);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Feature_Value(int feature, int connectivity)
{
    return
            [feature, connectivity](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Feature_Value(
                    pMA_Out,
                    pMA_In,
                    feature,
                    connectivity);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::FeatureContext_Value(int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, int connectivity)
{
    return
            [pt_type1, pt_type2, dist_min, dist_max, feat, stat, connectivity](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::FeatureContext_Value(
                    pMA_Out,
                    pMA_In,
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat,
                    stat,
                    connectivity);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Feature_Select(int feature, double f_min, double f_max, int connectivity)
{
    return
            [feature, f_min, f_max, connectivity](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Feature_Select(
                    pMA_Out,
                    pMA_In,
                    feature,
                    f_min,
                    f_max,
                    connectivity);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::FeatureContext_Select(int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, double t_min, double t_max, int connectivity)
{
    return
            [pt_type1, pt_type2, dist_min, dist_max, feat, stat, t_min, t_max, connectivity](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::FeatureContext_Select(
                    pMA_Out,
                    pMA_In,
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat,
                    stat,
                    t_min,
                    t_max,
                    connectivity);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Feature_Visualize(int feature, int connectivity, int thickness, double scale)
{
    return
            [feature, connectivity, thickness, scale](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Feature_Visualize(
                    pMA_Out,
                    pMA_In,
                    feature,
                    connectivity,
                    thickness,
                    scale);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Feature_Connect(int pt_type1, int pt_type2, double dist_min, double dist_max, int feat1, int feat2, function<bool (double, double)> comp, int connect_mode, int connectivity, int thickness)
{
    return
            [pt_type1, pt_type2, dist_min, dist_max, feat1, feat2, comp, connect_mode, connectivity, thickness](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Feature_Connect(
                    pMA_Out,
                    pMA_In,
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat1,
                    feat2,
                    comp,
                    connect_mode,
                    connectivity,
                    thickness);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Geometric_Reduce(int geometric, int connectivity, int thickness, uchar value)
{
    return
            [geometric, connectivity, thickness, value](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Reduce_Geometric(
                    pMA_Out,
                    pMA_In,
                    geometric,
                    connectivity,
                    thickness,
                    value);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Histogram_Equalize()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Histo_Equal(
                    pMA_Out,
                    pMA_In);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::GammaSpread(double gamma, double in_min, double in_max, double out_min, double out_max, bool force_8bit)
{
    return
            [gamma, in_min, in_max, out_min, out_max, force_8bit](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::GammaSpread(
                    pMA_Out,
                    pMA_In,
                    gamma,
                    in_min,
                    in_max,
                    out_min,
                    out_max,
                    force_8bit);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::DistancesStat(function<double (vector<double>)> F_Stat)
{
    return
            [F_Stat](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::DistancesStat(
                    pMA_Out,
                    pMA_In,
                    F_Stat);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Convert_Angle2Color_Rad(uchar Saturation, uchar Value)
{
    return
            [Saturation, Value](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Convert_Angle2Color_Rad(
                    pMA_Out,
                    pMA_In,
                    Saturation,
                    Value);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Crop_Rect_Rel(double x1_rel, double y1_rel, double x2_rel, double y2_rel)
{
    return
            [x1_rel, y1_rel, x2_rel, y2_rel](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Crop_Rect_Rel(
                    pMA_Out,
                    pMA_In,
                    x1_rel,
                    y1_rel,
                    x2_rel,
                    y2_rel);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Crop_Rect_Abs(int x, int y, int width, int height)
{
    return
            [x, y, width, height](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Crop_Rect_Abs(
                    pMA_Out,
                    pMA_In,
                    x,
                    y,
                    width,
                    height);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Crop_Rect_Rot(int x, int y, int width, int height, double angle)
{
    return
            [x, y, width, height, angle](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Crop_Rect_Rot(
                    pMA_Out,
                    pMA_In,
                    x,
                    y,
                    width,
                    height,
                    angle);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Crop_Circle(int x, int y, int r)
{
    return
            [x, y, r](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Crop_Circle(
                    pMA_Out,
                    pMA_In,
                    x,
                    y,
                    r);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Scale_Factor(double scale_x, double scale_y)
{
    return
            [scale_x, scale_y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Scale_Factor(
                    pMA_Out,
                    pMA_In,
                    scale_x,
                    scale_y);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Scale_ToSize(int size_x, int size_y)
{
    return
            [size_x, size_y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Scale_ToSize(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Pad_Border(int size_x, int size_y, int type)
{
    return
            [size_x, size_y, type](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Padding(
                    pMA_Out,
                    pMA_In,
                    size_x,
                    size_y,
                    type);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::ForceSize(int width, int heigth, int border_type)
{
    return
            [width, heigth, border_type](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::ForceSize(
                    pMA_Out,
                    pMA_In,
                    width,
                    heigth,
                    border_type);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Floodfill_Border(double new_val)
{
    return
            [new_val](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Floodfill_Boundary(
                    pMA_Out,
                    pMA_In,
                    new_val);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Floodfill_Delta(int seed_x, int seed_y, uchar val_new, uchar val_delta)
{
    return
            [seed_x, seed_y, val_new, val_delta](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Floodfill_Delta(
                    pMA_Out,
                    pMA_In,
                    seed_x,
                    seed_y,
                    val_new,
                    val_delta);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Morphology_Elemental(int morph_type, int elem_type, int elem_size_X, int elem_size_Y, int border_type, int iterations)
{
    return
            [morph_type, elem_type, elem_size_X, elem_size_Y, border_type, iterations](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Morphology_Elemental(
                    pMA_Out,
                    pMA_In,
                    morph_type,
                    elem_type,
                    elem_size_X,
                    elem_size_Y,
                    border_type,
                    iterations);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Morphology_Skeleton(int elem_type, int elem_size_X, int elem_size_Y, int border_type)
{
    return
            [elem_type, elem_size_X, elem_size_Y, border_type](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Morphology_Skeleton(
                    pMA_Out,
                    pMA_In,
                    elem_type,
                    elem_size_X,
                    elem_size_Y,
                    border_type);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Morphology_LocMax_Rect(int elem_size_X, int elem_size_Y)
{
    return
            [elem_size_X, elem_size_Y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Morphology_LocMax_Rect(
                    pMA_Out,
                    pMA_In,
                    elem_size_X,
                    elem_size_Y);
    };
}

function<int (Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Maximum_1C(size_t mask_size_x, size_t mask_size_y)
{
    return
            [mask_size_x, mask_size_y](Mat *pMA_Out, Mat *pMA_In)
    {
        return D_Img_Proc::Filter_Maximum_1C(
                    pMA_Out,
                    pMA_In,
                    mask_size_x,
                    mask_size_y);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Shading_Correct()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Ref)
    {
        return D_Img_Proc::Shading_Correct(
                    pMA_Out,
                    pMA_In,
                    pMA_Ref);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_RankOrder(double quantil)
{
    return
            [quantil](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc::Filter_RankOrder(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    quantil);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Median()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc::Filter_Median(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Eilenstein(function<double (double, double)> response_CurNei, function<double (double, double)> weight_ResWeigth, function<double (vector<double>)> combine_Responses)
{
    return
            [response_CurNei, weight_ResWeigth, combine_Responses](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc::Filter_Eilenstein(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    response_CurNei,
                    weight_ResWeigth,
                    combine_Responses);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Function(function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    return
            [F1_CenterImage, F2_f1mask, F3_Combine, F4_f3center, border_type, DoNonZeroMaskOnly](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc::Filter_Function(
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

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Function_8bit(function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    return
            [F1_CenterImage, F2_f1mask, F3_Combine, F4_f3center, border_type, DoNonZeroMaskOnly](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc::Filter_Function_8bit(
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

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Filter_Stat(int stat, int border_type)
{
    return
            [stat, border_type](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
    {
        return D_Img_Proc::Filter_Stat(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    stat,
                    border_type);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Addition()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Add(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_AdditionWeighted(double weight_1, double weight_2, double weight_sum)
{
    return
            [weight_1, weight_2, weight_sum](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_AddWeighted(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    weight_1,
                    weight_2,
                    weight_sum);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Subtraction()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Diff(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_SubtractionAbsolute()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_DiffAbs(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Multiplication(double scale)
{
    return
            [scale](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Mult(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    scale);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Division(double scale)
{
    return
            [scale](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Div(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    scale);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_BitwiseAnd()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_BitAnd(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_BitwiseOr()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_BitOr(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_BitwiseXor()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_BitXor(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Minimum()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Min(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Maximum()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Max(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Compare(int comp)
{
    return
            [comp](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Comp(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    comp);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Function(function<double (double, double)> function_img1_img2)
{
    return
            [function_img1_img2](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Function(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    function_img1_img2);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Function_8bit(function<uchar (double, double)> function_img1_img2)
{
    return
            [function_img1_img2](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Function_8bit(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    function_img1_img2);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_2img_Function_Complex(function<complex<double> (complex<double> x, complex<double> y)> function_img1_img2)
{
    return
            [function_img1_img2](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1)
    {
        return D_Img_Proc::Math_ImgImg_Function_Complex(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    function_img1_img2);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Transformation_Fourier(bool complex_input, bool invers, bool force_fft, bool out_real, int out_complex_mode, bool out_scale, bool out_center, bool out_nof0)
{
    return
            [complex_input, invers, force_fft, out_real, out_complex_mode, out_scale, out_center, out_nof0](Mat *pMA_Out, Mat *pMA_In_Re, Mat *pMA_In_Im)
    {
        return D_Img_Proc::Transformation_Fourier(
                    pMA_Out,
                    pMA_In_Re,
                    pMA_In_Im,
                    complex_input,
                    invers,
                    force_fft,
                    out_real,
                    out_complex_mode,
                    out_scale,
                    out_center,
                    out_nof0);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Transformation_Watershed()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Marker)
    {
        return D_Img_Proc::Transformation_Watershed(
                    pMA_Out,
                    pMA_In,
                    pMA_Marker);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Transformation_Watershed_Auto(bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    return
            [include_not_seeded, conv_8bit, exclude_border](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Marker)
    {
        return D_Img_Proc::Transformation_Watershed_Auto(
                    pMA_Out,
                    pMA_In,
                    pMA_Marker,
                    include_not_seeded,
                    conv_8bit,
                    exclude_border);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Draw_Label_Numbers(double scale, double thickness, bool center)
{
    return
            [scale, thickness, center](Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label)
    {
        return D_Img_Proc::Draw_Label_Numbers(
                    pMA_Out,
                    pMA_In,
                    pMA_Label,
                    scale,
                    thickness,
                    center);
    };
}

function<int (Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::ClassBorder_kNN(int n)
{
    return
            [n](Mat *pMA_Out, Mat *pMA_Class0, Mat *pMA_Class1)
    {
        return D_Img_Proc::ClassBorder_kNN(
                    pMA_Out,
                    pMA_Class0,
                    pMA_Class1,
                    n);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_3img_Addition()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Math_Add(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_3img_Addition(double summand)
{
    return
            [summand](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Math_Add(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    summand);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_3img_Multiplication()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Math_Mult(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_3img_Multiplication(double factor)
{
    return
            [factor](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Math_Mult(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    factor);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_3img_BitwiseAnd()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Math_And(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_3img_BitwiseOr()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Math_Or(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Channel_Merge()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::Merge(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::RadiometricStereo(double S1X, double S1Y, double S1Z, double S2X, double S2Y, double S2Z, double S3X, double S3Y, double S3Z, int out_mode)
{
    return
            [S1X, S1Y, S1Z, S2X, S2Y, S2Z, S3X, S3Y, S3Z, out_mode](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
    {
        return D_Img_Proc::RadiometricStereo(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    S1X, S1Y, S1Z, S2X, S2Y, S2Z, S3X, S3Y, S3Z,
                    out_mode);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Morphology_Reconstruction(double quantil)
{
    return
            [quantil](Mat *pMA_Out, Mat *pMA_Seed, Mat *pMA_Limit, Mat *pMA_Mask)
    {
        return D_Img_Proc::Morphology_Reconstruction(
                    pMA_Out,
                    pMA_Seed,
                    pMA_Limit,
                    pMA_Mask,
                    quantil);
    };
}



function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Channel_Merge(int channel_count, bool channels_use[])
{
    return
            [channel_count, channels_use](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Merge(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    channel_count,
                    channels_use);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_4img_Addition()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Math_Add(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_4img_Addition(double summand)
{
    return
            [summand](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Math_Add(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    summand);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_4img_Multiplication()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Math_Mult(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_4img_Multiplication(double factor)
{
    return
            [factor](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Math_Mult(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    factor);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_4img_BitwiseAnd()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Math_And(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Math_4img_BitwiseOr()
{
    return
            [](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Math_Or(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Stitch_Border_abs(int border_R, int border_B, int overlap_R, int overlap_B, Stitcher::Mode mode)
{
    return
            [border_R, border_B, overlap_R, overlap_B, mode](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Stitch_Border_abs(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B,
                    mode);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Stitch_Border_rel(double border_R, double border_B, double overlap_R, double overlap_B, Stitcher::Mode mode)
{
    return
            [border_R, border_B, overlap_R, overlap_B, mode](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Stitch_Border_rel(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B,
                    mode);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Stitch_Border_abs_custom(int border_R, int border_B, int overlap_R, int overlap_B)
{
    return
            [border_R, border_B, overlap_R, overlap_B](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Stitch_Border_abs_custom(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B);
    };
}

function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> D_Img_Proc_2dFactory::Stitch_Border_rel_custom(double border_R, double border_B, double overlap_R, double overlap_B)
{
    return
            [border_R, border_B, overlap_R, overlap_B](Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
    {
        return D_Img_Proc::Stitch_Border_rel_custom(
                    pMA_Out,
                    pMA_In0,
                    pMA_In1,
                    pMA_In2,
                    pMA_In3,
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B);
    };
}
