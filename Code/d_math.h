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
using namespace cv;

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

    static function<double (double x, double y, double z, double t, double s, double p)> Function_6D_to_1D(int type, double sx, double ox, double sy, double oy, double sz, double oz, double st, double ot, double ss, double os, double sp, double op, double a = 1, double b = 0, double c = 1, double d = 0, double e = 0, double f = 0, double nan_val = 0, double inf_val = 0);


    static int                                      Distance_Transformation_1D  (vector<double> *v_edt, vector<double> v_line, double spacing = 1);

    static function<double (double x, double a, double b, double c, double d, double e, double f)> Curve_Array(int prototype);

    //static double                                   RandomNumberDistribution(int type, double min, double max, double a, double b, double c, double d, double e, double f);

    static double                                   Binomial_Coefficient        (double n, double k);
    static double                                   Distance                    (Point   pt1, Point   pt2);
    static double                                   Distance                    (Point2f pt1, Point   pt2);
    static double                                   Distance                    (Point   pt1, Point2f pt2);
    static double                                   Distance                    (Point2f pt1, Point2f pt2);
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

private:


};

#endif // D_MATH_H
