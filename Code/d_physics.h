/************************************
 *   added:     18.06.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_PHYSICS_H
#define D_PHYSICS_H

//own
#include <d_enum.h>
#include <d_math.h>

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
 * \brief The D_Physics class Basic physics formulas.
 */
class D_Physics
{
public:
    D_Physics();

    //interference
    static double                                   FieldStrength           (Mat Position, Mat Source, double fieldstrength, double phaseoffset_rad, double wavelength_m);
    static double                                   FieldStrength           (Point3d Position, Point3d Source, double fieldstrength, double phaseoffset_rad, double wavelength_m);
    static double                                   Interference            (Mat     Position, vector<Mat>     v_Source, vector<double> v_fieldstrength, vector<double> v_phaseoffset_rad, double wavelength_m);
    static double                                   Interference            (Point3d Position, vector<Point3d> v_Source, vector<double> v_fieldstrength, vector<double> v_phaseoffset_rad, double wavelength_m);

    //scalar forces
    static function<double (double v)>              Force_Drag              (double rho, double A, double cw);
    static double                                   Force_Gravity           (double m);
    static double                                   Force_Upthrust          (double V, double rho);
};

#endif // D_PHYSICS_H
