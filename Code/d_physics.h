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

class D_Physics
{
public:
    D_Physics();

    //scalar forces
    static function<double (double v)>              Force_Drag              (double rho, double A, double cw);
    double                                          Force_Gravity           (double m);
    double                                          Force_Upthrust          (double V, double rho);
};

#endif // D_PHYSICS_H
