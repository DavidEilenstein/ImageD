/************************************
 *   added:     29.03.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_geo_point_2d.h"

D_Geo_Point_2D::D_Geo_Point_2D()
{
    m_u = 0;
    m_v = 0;
    m_w = 0;
}

D_Geo_Point_2D::D_Geo_Point_2D(double angle_rad)
{
    set_angle_unifrom(angle_rad);
}

D_Geo_Point_2D::D_Geo_Point_2D(double x, double y)
{
    m_u = x;
    m_v = y;
    m_w = 1;
}

D_Geo_Point_2D::D_Geo_Point_2D(double u, double v, double w)
{
    m_u = u;
    m_v = v;
    m_w = w;
}

D_Geo_Point_2D::D_Geo_Point_2D(D_Geo_Line_2D L)
{
    m_u = L.u();
    m_v = L.v();
    m_w = L.w();
}

D_Geo_Point_2D::D_Geo_Point_2D(D_Geo_Line_2D L1, D_Geo_Line_2D L2)
{
    set_point(L1.intersection(L2));
}

void D_Geo_Point_2D::set_point(D_Geo_Point_2D P)
{
    m_u = P.u();
    m_v = P.v();
    m_w = P.w();
}

void D_Geo_Point_2D::set_angle_unifrom(double angle_rad)
{
    m_u = sin(angle_rad);
    m_v = cos(angle_rad);
    m_w = 1;
}

void D_Geo_Point_2D::set_angle_normal_unifrom(double angle_rad)
{
    return set_angle_unifrom(angle_rad - PI);
}

Mat D_Geo_Point_2D::Mat_homo()
{
    Mat V(3, 1, CV_64FC1);
    V.at<double>(0, 0) = m_u;
    V.at<double>(1, 0) = m_v;
    V.at<double>(2, 0) = m_w;
    return V;
}

Mat D_Geo_Point_2D::Mat_inhomo()
{
    Mat V(2, 1, CV_64FC1);
    V.at<double>(0, 0) = x();
    V.at<double>(1, 0) = y();
    return V;
}

bool D_Geo_Point_2D::equal(D_Geo_Point_2D P)
{
    return u() == P.u() && v() == P.v() && w() == P.w();
}

D_Geo_Point_2D D_Geo_Point_2D::negate()
{
    return D_Geo_Point_2D(-x(), -y());
}

D_Geo_Point_2D D_Geo_Point_2D::scale(double factor)
{
    return D_Geo_Point_2D(
                x() * factor,
                y() * factor);
}

D_Geo_Point_2D D_Geo_Point_2D::unifrom()
{
    return scale(1.0 / length());
}

D_Geo_Point_2D D_Geo_Point_2D::add_inhomo(D_Geo_Point_2D P)
{
    return D_Geo_Point_2D(x() + P.x(), y() + P.y());
}

D_Geo_Point_2D D_Geo_Point_2D::dif_inhomo(D_Geo_Point_2D P)
{
    return add_inhomo(P.negate());
}

double D_Geo_Point_2D::mult_scalar_inhomo(D_Geo_Point_2D P)
{
    return x() * P.x() + y() * P.y();
}

double D_Geo_Point_2D::mult_scalar_homo(D_Geo_Point_2D P)
{
    return u() * P.u() + v() * P.v() + w() * P.w();
}

D_Geo_Line_2D D_Geo_Point_2D::mult_cross_homo(D_Geo_Point_2D P)
{
    return D_Geo_Line_2D(
                v()*P.w() - w()*P.v(),
                w()*P.u() - u()*P.w(),
                u()*P.v() - v()*P.u());
}

bool D_Geo_Point_2D::vanishing(double delta)
{
    return abs(m_w) <= delta;
}

double D_Geo_Point_2D::length()
{
    return sqrt(x() * x() + y() * y());
}

double D_Geo_Point_2D::angle()
{
    return atan2(y(), x());
}

double D_Geo_Point_2D::angle(D_Geo_Point_2D P)
{
    return acos(mult_scalar_inhomo(P) / (length() * P.length()));
}

D_Geo_Line_2D D_Geo_Point_2D::connection(D_Geo_Point_2D P)
{
    return mult_cross_homo(P);
}

double D_Geo_Point_2D::distance(D_Geo_Point_2D P)
{
    double dx = x() - P.x();
    double dy = y() - P.y();
    return sqrt(dx * dx + dy * dy);
}
