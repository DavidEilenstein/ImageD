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

class D_Geo_Line_2D
{
public:
    //constructors
    D_Geo_Line_2D()                                     {m_u = 0; m_v = 0; m_w = 0;}
    D_Geo_Line_2D(double u, double v, double w)         {m_u = u; m_v = v; m_w = w;}
    D_Geo_Line_2D(D_Geo_Point_2D P)                     {m_u = P.u(); m_v = P.v(); m_w = P.w();}    //Dualism with points
    D_Geo_Line_2D(D_Geo_Point_2D P1, D_Geo_Point_2D P2) {set_line(P1.connection(P2));}

    //pseudo constructors
    void set_line(D_Geo_Line_2D L)                                          {m_u = L.u(); m_v = L.v(); m_w = L.w();}
    bool set_point_point(D_Geo_Point_2D P1, D_Geo_Point_2D P2)              {set_line(P1.connection(P2)); return P1.equal(P2) ? false : true;}
    //bool set_point_direction(D_Geo_Point_2D P, D_Geo_Point_2D direction);
    //bool set_point_slope(D_Geo_Point_2D P, double slope);
    //bool set_point_dist(D_Geo_Point_2D P, double dist);

    //getter
    double          u()                 {return m_u;}
    double          v()                 {return m_v;}
    double          w()                 {return m_w;}
    Mat             Mat_homogenius()    {Mat V(3, 1, CV_64FC1);     V.at<double>(0, 0) = m_u;   V.at<double>(1, 0) = m_v;   V.at<double>(2, 0) = m_w;   return V;}
    D_Geo_Point_2D  direction()         {D_Geo_Point_2D(v(), -u());}
    D_Geo_Point_2D  support()           {D_Geo_Line_2D Y(1, 0, 0); D_Geo_Line_2D X(0, 1, 0); return parallel(Y) ? intersection(X) : intersection(Y);}

    //basic operations
    double          mult_scalar_homo(D_Geo_Line_2D L)   {return u() * L.u() + v() * L.v() + w() * L.w();}
    D_Geo_Point_2D  mult_cross_homo(D_Geo_Line_2D L)    {return D_Geo_Point_2D((v()*L.w() - w()*L.v()), (w()*L.u() - u()*L.w()), (u()*L.v() - v()*L.u()));}

    //other operations
    D_Geo_Point_2D  intersection(D_Geo_Line_2D L)                           {return mult_cross_homo(L);}
    bool            parallel(D_Geo_Line_2D L, double delta = 0)             {return intersection(L).vanishing(delta);}
    double          angle()                                                 {return direction().angle();}
    double          angle(D_Geo_Line_2D L)                                  {return direction().angle(L.direction());}
    double          dist(D_Geo_Point_2D P)                                  {return P.dif_inhomo(support()).mult_cross_homo(direction()).length() / (direction().length());}
    bool            point_on_line(D_Geo_Point_2D P, double dist_max = 0)    {return abs(dist(P)) <= dist_max;}


private:
    //member
    double m_u;
    double m_v;
    double m_w;
};

#endif // D_GEO_LINE_2D_H
