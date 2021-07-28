/************************************
 *   added:     29.03.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_GEO_POINT_2D_H
#define D_GEO_POINT_2D_H

//own
#include <d_enum.h>
#include <d_geo_line_2d.h>

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
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

//predeclaration, because points are needed for lines and vice versa
class D_Geo_Line_2D;

/*!
 * \brief The D_Geo_Point_2D class represents a 2D point and offers usefulls methods for standard tasks for 2D points and lines.
 *  \details Supports homogenious coodinates. Calculation is done homogenious/inhomogenious, whichever is easier. From user perspektive, this is irelevant and handled internally.
 */
class D_Geo_Point_2D
{
public:
    //constructors
    D_Geo_Point_2D();
    D_Geo_Point_2D(double angle_rad);
    D_Geo_Point_2D(double x, double y);
    D_Geo_Point_2D(double u, double v, double w);
    D_Geo_Point_2D(D_Geo_Line_2D L);    //Dualism with lines
    D_Geo_Point_2D(D_Geo_Line_2D L1, D_Geo_Line_2D L2);

    //pseudo constructors
    void            set_point(D_Geo_Point_2D P);
    void            set_angle_unifrom(double angle_rad);
    void            set_angle_normal_unifrom(double angle_rad);

    //getter
    double          u()                                     {return m_u;}
    double          v()                                     {return m_v;}
    double          w()                                     {return m_w;}
    double          x()                                     {return m_u / m_w;}
    double          y()                                     {return m_v / m_w;}
    Mat             Mat_homo();
    Mat             Mat_inhomo();
    Point           CV_Point()                              {return Point(x(), y());}
    Point2f         CV_Point2f()                            {return Point2f(x(), y());}
    Point2d         CV_Point2d()                            {return Point2d(x(), y());}

    //basic operations
    bool            equal(D_Geo_Point_2D P);
    D_Geo_Point_2D  negate();
    D_Geo_Point_2D  scale(double factor);
    D_Geo_Point_2D  unifrom();
    D_Geo_Point_2D  add_inhomo(D_Geo_Point_2D P);
    D_Geo_Point_2D  dif_inhomo(D_Geo_Point_2D P);
    double          mult_scalar_inhomo(D_Geo_Point_2D P);
    double          mult_scalar_homo(D_Geo_Point_2D P);
    D_Geo_Line_2D   mult_cross_homo(D_Geo_Point_2D P);

    //other operations
    bool            vanishing(double delta = 0);
    double          length();
    double          angle();
    double          angle(D_Geo_Point_2D P);
    D_Geo_Line_2D   connection(D_Geo_Point_2D P);
    double          distance(D_Geo_Point_2D P);
    bool            in_rect(size_t t, size_t b, size_t l, size_t r);
    bool            in_rect(size_t t, size_t b, size_t l, size_t r, double *min_dist, double *max_dist);
    bool            in_rect(Rect *rect);
    bool            in_rect(Mat *img);

private:

    //members
    double m_u;
    double m_v;
    double m_w;
};

#endif // D_GEO_POINT_2D_H
