/************************************
 *   added:     11.02.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MATH_H
#define D_MATH_H

//own
#include <d_enum.h>

//general
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <complex>

//Qt
#include <QString>
#include <QDebug>
#include <QStringList>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_Math class Mathematic functionalities.
 * \details Mathematic functions for static use and some factory methods for function objects taking enums: D_MATH_1D_TO_1D , D_MATH_2D_TO_1D , D_MATH_2D_TO_1D_COMPLEX , D_MATH_6D_TO_1D and D_COND_2D
 */
class D_Math
{
public:
    //constructor (never call it)
    D_Math();

    static function<double (double x)>                                      Function_1D_to_1D           (int type, double a = 1, double b = 0, double c = 0, double d = 0);
    static function<double (double x, double y)>                            Function_2D_to_1D           (int type, double a = 1, double b = 0, double c = 1, double d = 0, double e = 0, double f = 0, double nan_val = 0, double inf_val = 0);
    static function<uchar  (double x, double y)>                            Function_2D_to_1D_8bit      (int type, double a = 1, double b = 0, double c = 1, double d = 0, double e = 0, double f = 0, uchar nan_val = 0, uchar inf_val = 0);
    static function<complex<double> (complex<double> x, complex<double> y)> Function_2D_to_1D_Complex   (int type, double sx, double ox, double sy, double oy, double a = 1, double b = 0, double c = 1, double d = 0, double e = 0, double f = 0, double nan_val = 0, double inf_val = 0);
    static function<bool   (double x, double y)>                            Condition_2D                (int type, double a = 1, double b = 0, double c = 1, double d = 0, double e = 0, double f = 0, double g = 0, double h = 0);

    static function<double (double x, double y, double z, double t, double s, double p)>            Function_6D_to_1D(int type, double sx, double ox, double sy, double oy, double sz, double oz, double st, double ot, double ss, double os, double sp, double op, double a = 1, double b = 0, double c = 1, double d = 0, double e = 0, double f = 0, double nan_val = 0, double inf_val = 0);
    static function<double (double x, double a, double b, double c, double d, double e, double f)>  Curve_Array(int prototype);

    static bool Compare(size_t compare_index, double v1, double v2);

    static int                                      Distance_Transformation_1D  (vector<double> *v_edt, vector<double> v_line, double spacing = 1);

  //static double                                   RandomNumberDistribution(int type, double min, double max, double a, double b, double c, double d, double e, double f);

    static double                                   Binomial_Coefficient        (double n, double k);
    static double                                   Distance                    (Point   pt1, Point   pt2);
    static double                                   Distance                    (Point2f pt1, Point   pt2);
    static double                                   Distance                    (Point   pt1, Point2f pt2);
    static double                                   Distance                    (Point2f pt1, Point2f pt2);
    static double                                   Distance                    (Point2d pt1, Point2d pt2);
    static double                                   Distance                    (Point2f pt, Rect r);
    static double                                   Distance                    (Point pt, Rect r);
    static double                                   AngleRad                    (Point2f pt1, Point2f pt2);
    static double                                   Pythagoras                  (double x, double y);
    static Point2f                                  Center                      (Point2f pt1, Point2f pt2);

    static double                                   Difference_AngleRad                 (double a1, double a2);
    static double                                   Distance_AngleRad_Shortest_Unsigned (double a1, double a2);
    static double                                   Distance_AngleRad_Shortest_Signed   (double a1, double a2);
    static double                                   Sum_AngleRad                        (double a1, double a2);

    static double                                   Complex_Real            (complex<double> c)     {return c.real();}
    static double                                   Complex_Imaginary       (complex<double> c)     {return c.imag();}
    static double                                   Complex_Absolute        (complex<double> c)     {return sqrt(c.real() * c.real() + c.imag() * c.imag());}
    static double                                   Complex_Absolute        (double r, double i)    {return sqrt(r * r + i * i);}
    static double                                   Complex_Phase           (complex<double> c)     {return atan2(c.imag(), c.real());}
    static double                                   Complex_Phase           (double r, double i)    {return atan2(i, r);}
    static double                                   Complex_Absolute_Square (complex<double> c)     {double a = Complex_Absolute(c); return a * a;}
    static double                                   Complex_Absolute_Square (double r, double i)    {double a = Complex_Absolute(r, i); return a * a;}
    static complex<double>                          Complex_Conjugated      (complex<double> c)     {return complex<double>(c.real(), -c.imag());}
    static complex<double>                          Complex_Conjugated      (double r, double i)    {return complex<double>(r, -i);}

    static function<double (double val_in)>         CopyValue               ();
    static function<double (double val_in)>         LimitRange              (double min, double max);
    static function<uchar  (double val_in)>         Spread_2_8bit           (double min, double max, function<double (double val_in)> F);
    static function<double (double val_in)>         GammaCorrect_to01       (double min, double max, double gamma);
    static function<double (double val_in)>         Log_Centered            (double center, double divisor);
    static function<double (double val_in)>         Log_Centered            (double min, double max, double center, double divisor);


    static bool                                     Points_Are_Neighbors_8          (Point P0, Point P1);
    static vector<Point>                            Line_Bresenham_8                (Point P0, Point P1);
private:
    static vector<Point>                            Line_Bresenham_8_Low            (int x0, int y0, int x1, int y1);
    static vector<Point>                            Line_Bresenham_8_High           (int x0, int y0, int x1, int y1);
public:
    static int                                      Close_Contour_Gaps_With_Lines_8 (vector<Point> *pvContour);
    static int                                      Close_Contour_Gaps_With_Lines_8 (vector<vector<Point>> *pvvContours);

    static Point                                    Minimum_TrisectionInterval      (function<double (double)> F, double start_border_low, double start_border_high, double resolution_needed);
    static int                                      MedianRunning                   (vector<uchar> *vDataOut, vector<uchar> vDataIn, size_t mask_size);
    static int                                      QuantilRunning                  (vector<uchar> *vDataOut, vector<uchar> vDataIn, size_t mask_size, double quantil_lower);
    static int                                      Maximum_Gil                     (vector<double> *vDataOut, vector<double> *vDataIn, size_t mask_size);

    static Mat  Homogenious_2D              (double x, double y);
    static Mat  Homogenious_2D              (double u, double v, double w);
    static Mat  Homogenious_2D              (Mat V_inhomo);
    static Mat  Homogenious_3D              (double x, double y, double z);
    static Mat  Homogenious_3D              (double u, double v, double w, double q);
    static Mat  Homogenious_3D              (Mat V_inhomo);

    static Mat  Inhomogenious_2D            (double x, double y);
    static Mat  Inhomogenious_2D            (double u, double v, double w);
    static Mat  Inhomogenious_2D            (Mat V_homo);
    static Mat  Inhomogenious_3D            (double x, double y, double z);
    static Mat  Inhomogenious_3D            (double u, double v, double w, double q);
    static Mat  Inhomogenious_3D            (Mat V_homo);

    static Mat  Shift_2D_h                  (double shift_x, double shift_y);
    static Mat  Shift_3D_h                  (double shift_x, double shift_y, double shift_z);
    static Mat  Rotation_2D_i_deg           (double angle);
    static Mat  Rotation_3D_i_deg           (double angle_x, double angle_y, double angle_z);
    static Mat  Rotation_2D_i_rad           (double angle);
    static Mat  Rotation_3D_i_rad           (double angle_x, double angle_y, double angle_z);
    static Mat  Rotation_2D_h_deg           (double angle);
    static Mat  Rotation_2D_h_deg           (double angle, double center_x, double center_y);
    static Mat  Rotation_3D_h_deg           (double angle_x, double angle_y, double angle_z);
    static Mat  Rotation_3D_h_deg           (double angle_x, double angle_y, double angle_z, double center_x, double center_y, double center_z);
    static Mat  Rotation_2D_h_rad           (double angle);
    static Mat  Rotation_2D_h_rad           (double angle, double center_x, double center_y);
    static Mat  Rotation_3D_h_rad           (double angle_x, double angle_y, double angle_z);
    static Mat  Rotation_3D_h_rad           (double angle_x, double angle_y, double angle_z, double center_x, double center_y, double center_z);
    static Mat  Euclidean_2D_h_deg          (double shift_x, double shift_y, double angle);
    static Mat  Euclidean_3D_h_deg          (double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z);
    static Mat  Euclidean_2D_h_rad          (double shift_x, double shift_y, double angle);
    static Mat  Euclidean_3D_h_rad          (double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z);
    static Mat  Similarity_2D_h_deg         (double shift_x, double shift_y, double angle, double scale);
    static Mat  Similarity_3D_h_deg         (double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z, double scale);
    static Mat  Similarity_2D_h_rad         (double shift_x, double shift_y, double angle, double scale);
    static Mat  Similarity_3D_h_rad         (double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z, double scale);
    static Mat  Affinity_2D_h               (double shift_x, double shift_y, double a11, double a12, double a21, double a22);
    static Mat  Affinity_3D_h               (double shift_x, double shift_y, double shift_z, double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
    static Mat  Projektion_2D_h             (double shift_x, double shift_y, double a11, double a12, double a21, double a22, double p1, double p2);
    static Mat  Projektion_3D_h             (double shift_x, double shift_y, double shift_z, double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33, double p1, double p2, double p3);
    static Mat  Projektion_ND_h             (Mat A, Mat t, Mat P);

private:


};

#endif // D_MATH_H
