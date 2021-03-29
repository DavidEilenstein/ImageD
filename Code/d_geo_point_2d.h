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
using namespace cv;

class D_Geo_Point_2D
{
public:
    //constructors
    D_Geo_Point_2D()                                    {m_u = 0; m_v = 0; m_w = 0;}
    D_Geo_Point_2D(double x, double y)                  {m_u = x; m_v = y; m_w = 1;}
    D_Geo_Point_2D(double u, double v, double w)        {m_u = u; m_v = v; m_w = w;}
    D_Geo_Point_2D(D_Geo_Line_2D L)                     {m_u = L.u(); m_v = L.v(); m_w = L.w();}    //Dualism with lines
    D_Geo_Point_2D(D_Geo_Line_2D L1, D_Geo_Line_2D L2)  {set_point(L1.intersection(L2));}

    //pseudo constructors
    void            set_point(D_Geo_Point_2D P)             {m_u = P.u(); m_v = P.v(); m_w = P.w();}

    //getter
    double          u()                                     {return m_u;}
    double          v()                                     {return m_v;}
    double          w()                                     {return m_w;}
    double          x()                                     {return m_u / m_w;}
    double          y()                                     {return m_v / m_w;}
    Mat             Mat_homo()                              {Mat V(3, 1, CV_64FC1);     V.at<double>(0, 0) = m_u;   V.at<double>(1, 0) = m_v;   V.at<double>(2, 0) = m_w;   return V;}
    Mat             Mat_inhomo()                            {Mat V(2, 1, CV_64FC1);     V.at<double>(0, 0) = x();   V.at<double>(1, 0) = y();   return V;}

    //basic operations
    bool            equal(D_Geo_Point_2D P)                 {return u() == P.u() && v() == P.v() && w() == P.w();}
    D_Geo_Point_2D  negate()                                {return D_Geo_Point_2D(-x(), -y());}
    D_Geo_Point_2D  add_inhomo(D_Geo_Point_2D P)            {return D_Geo_Point_2D(x() + P.x(), y() + P.y());}
    D_Geo_Point_2D  dif_inhomo(D_Geo_Point_2D P)            {return add_inhomo(P.negate());}
    double          mult_scalar_inhomo(D_Geo_Point_2D P)    {return x() * P.x() + y() * P.y();}
    double          mult_scalar_homo(D_Geo_Point_2D P)      {return u() * P.u() + v() * P.v() + w() * P.w();}
    D_Geo_Line_2D   mult_cross_homo(D_Geo_Point_2D P)       {return D_Geo_Line_2D((v()*P.w() - w()*P.v()), (w()*P.u() - u()*P.w()), (u()*P.v() - v()*P.u()));}

    //other operations
    bool            vanishing(double delta = 0)             {return abs(m_w) <= delta;}
    double          length()                                {return sqrt(x() * x() + y() * y());}
    double          angle()                                 {return atan2(y(), x());}
    double          angle(D_Geo_Point_2D P)                 {return acos(mult_scalar_inhomo(P) / (length() * P.length()));}
    D_Geo_Line_2D   connection(D_Geo_Point_2D P)            {return mult_cross_homo(P);}

private:
    //members
    double m_u;
    double m_v;
    double m_w;
};

#endif // D_GEO_POINT_2D_H
