/************************************
 *   added:     29.03.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_GEO_LINE_2D_H
#define D_GEO_LINE_2D_H

//own
#include <d_enum.h>
#include <d_geo_point_2d.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

//Qt
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

//predeclaration, because points are needed for lines and vice versa
class D_Geo_Point_2D;

/*!
 * \brief The D_Geo_Line_2D class represents a 2D line and offers usefulls methods for standard tasks for 2D points and lines.
 *  \details Supports homogenious coodinates. Calculation is done homogenious/inhomogenious, whichever is easier. From user perspektive, this is irelevant and handled internally.
 */
class D_Geo_Line_2D
{
public:
    //constructors
    D_Geo_Line_2D();
    D_Geo_Line_2D(double u, double v, double w);
    D_Geo_Line_2D(D_Geo_Point_2D P);    //Dualism with points
    D_Geo_Line_2D(D_Geo_Point_2D P1, D_Geo_Point_2D P2);

    //pseudo constructors
    void set_line           (D_Geo_Line_2D L);
    bool set_point_point    (D_Geo_Point_2D P1,         D_Geo_Point_2D P2);
    bool set_point_direction(D_Geo_Point_2D P_support,  D_Geo_Point_2D direction);
    bool set_point_angle    (D_Geo_Point_2D P_support,  double angle_rad);

    //getter
    double          u()                 {return m_u;}
    double          v()                 {return m_v;}
    double          w()                 {return m_w;}
    Mat             Mat_homogenius();
    D_Geo_Point_2D  direction();
    D_Geo_Point_2D  support();
    D_Geo_Point_2D  normal();

    //basic operations
    double          mult_scalar_homo(D_Geo_Line_2D L);
    D_Geo_Point_2D  mult_cross_homo(D_Geo_Line_2D L);

    //other operations
    D_Geo_Point_2D  intersection(D_Geo_Line_2D L);
    bool            parallel(D_Geo_Line_2D L, double delta = 0);
    double          angle();
    double          angle(D_Geo_Line_2D L);
    double          dist(D_Geo_Point_2D P);
    bool            point_on_line(D_Geo_Point_2D P, double dist_max = 0);


private:
    //member
    double m_u;
    double m_v;
    double m_w;
};

#endif // D_GEO_LINE_2D_H
