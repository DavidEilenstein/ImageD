#include "d_geo_line_2d.h"

D_Geo_Line_2D::D_Geo_Line_2D()
{
    m_u = 0;
    m_v = 0;
    m_w = 0;
}

D_Geo_Line_2D::D_Geo_Line_2D(double u, double v, double w)
{
    m_u = u;
    m_v = v;
    m_w = w;
}

D_Geo_Line_2D::D_Geo_Line_2D(D_Geo_Point_2D P)
{
    m_u = P.u();
    m_v = P.v();
    m_w = P.w();
}

D_Geo_Line_2D::D_Geo_Line_2D(D_Geo_Point_2D P1, D_Geo_Point_2D P2)
{
    set_line(P1.connection(P2));
}

void D_Geo_Line_2D::set_line(D_Geo_Line_2D L)
{
    m_u = L.u();
    m_v = L.v();
    m_w = L.w();
}

bool D_Geo_Line_2D::set_point_point(D_Geo_Point_2D P1, D_Geo_Point_2D P2)
{
    set_line(P1.connection(P2));
    return P1.equal(P2) ? false : true;
}

Mat D_Geo_Line_2D::Mat_homogenius()
{
    Mat V(3, 1, CV_64FC1);
    V.at<double>(0, 0) = m_u;
    V.at<double>(1, 0) = m_v;
    V.at<double>(2, 0) = m_w;
    return V;
}

D_Geo_Point_2D D_Geo_Line_2D::direction()
{
    D_Geo_Point_2D d(v(), -u());
    return d.unifrom();
}

D_Geo_Point_2D D_Geo_Line_2D::support()
{
    D_Geo_Line_2D Y(1, 0, 0); D_Geo_Line_2D X(0, 1, 0);
    return parallel(Y) ? intersection(X) : intersection(Y);
}

D_Geo_Point_2D D_Geo_Line_2D::normal()
{
    D_Geo_Point_2D n(u(), v());
    return n.unifrom();
}

double D_Geo_Line_2D::mult_scalar_homo(D_Geo_Line_2D L)
{
    return u() * L.u() + v() * L.v() + w() * L.w();
}

D_Geo_Point_2D D_Geo_Line_2D::mult_cross_homo(D_Geo_Line_2D L)
{
    return D_Geo_Point_2D(
                v()*L.w() - w()*L.v(),
                w()*L.u() - u()*L.w(),
                u()*L.v() - v()*L.u());
}

D_Geo_Point_2D D_Geo_Line_2D::intersection(D_Geo_Line_2D L)
{
    return mult_cross_homo(L);
}

bool D_Geo_Line_2D::parallel(D_Geo_Line_2D L, double delta)
{
    return intersection(L).vanishing(delta);
}

double D_Geo_Line_2D::angle()
{
    return direction().angle();
}

double D_Geo_Line_2D::angle(D_Geo_Line_2D L)
{
    return direction().angle(L.direction());
}

double D_Geo_Line_2D::dist(D_Geo_Point_2D P)
{
    return abs(u() * P.x() + v() * P.y() + w()) / sqrt(u() * u() + v() * v());
}

bool D_Geo_Line_2D::point_on_line(D_Geo_Point_2D P, double dist_max)
{
    return abs(dist(P)) <= dist_max;
}
