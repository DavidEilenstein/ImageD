/************************************
 *   added:     29.03.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

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

bool D_Geo_Line_2D::set_point_direction(D_Geo_Point_2D P_support, D_Geo_Point_2D direction)
{
    return set_point_point(P_support, P_support.add_inhomo(direction));
}

bool D_Geo_Line_2D::set_point_angle(D_Geo_Point_2D P_support, double angle_rad)
{
    //qDebug() << "D_Geo_Line_2D::set_point_angle x/y/a" << P_support.x() << P_support.y() << angle_rad * Rad2Grad;
    return set_point_direction(P_support, D_Geo_Point_2D(angle_rad));
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
    D_Geo_Line_2D X(0, 1, 0);
    D_Geo_Line_2D Y(1, 0, 0);

    bool par_x = parallel(X);
    bool par_y = parallel(Y);

    if(!par_x && !par_y)
    {
        D_Geo_Point_2D inter_x = intersection(X);
        D_Geo_Point_2D inter_y = intersection(Y);

        D_Geo_Point_2D O(0, 0);

        double dist_x = inter_x.distance(O);
        double dist_y = inter_y.distance(O);

        //return the point which is closer to 0|0 to avoid nearly infinity values if nearly parallel to an axis
        return dist_x < dist_y ? inter_x : inter_y;
    }
    else if(par_x)
    {
        return intersection(Y);
    }
    else//pary
    {
        return intersection(X);
    }
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

bool D_Geo_Line_2D::intersection_rect(D_Geo_Point_2D *P1, D_Geo_Point_2D *P2, double t, double b, double l, double r)
{
    //corners
    D_Geo_Point_2D P_lt(l+1, t+1);
    D_Geo_Point_2D P_rt(r-1, t+1);
    D_Geo_Point_2D P_lb(l+1, b-1);
    D_Geo_Point_2D P_rb(r-1, b-1);

    //edges
    vector<D_Geo_Line_2D> vL_edges(4);
    vL_edges[0] = D_Geo_Line_2D(P_lt, P_lb);
    vL_edges[1] = D_Geo_Line_2D(P_rt, P_rb);
    vL_edges[2] = D_Geo_Line_2D(P_lt, P_rt);
    vL_edges[3] = D_Geo_Line_2D(P_lb, P_rb);

    //intersections
    vector<D_Geo_Point_2D> vP_intersections_valid;
    for(size_t i = 0; i < vL_edges.size(); i++)
    {
        D_Geo_Point_2D P_check = intersection(vL_edges[i]);
        double x = P_check.x();
        double y = P_check.y();

        if(!P_check.vanishing() && x >= l && x <= r && y >= t && y <= b)
        {
            vP_intersections_valid.push_back(P_check);
            //qDebug() << "accepted" << x << y;
        }
        else
        {
            //qDebug() << "DECLINED" << x << y << "vanishing" << P_check.vanishing() << "l" << (x >= l) << "r" << (x <= r) << "t" << (y >= t) << "b" << (y <= b);
        }
    }

    //check success
    if(vP_intersections_valid.size() < 2)
    {
        //qDebug() << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        //qDebug() << "D_Geo_Line_2D::intersection_rect" << "t/b/l/r" << t << b << l << r << "support" << support().x() << support().y() << "direction" << direction().x() << direction().y() << "-"                 << "only" << vP_intersections_valid.size() << "points found";
        //qDebug() << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        return false;
    }

    //exactly 2?
    if(vP_intersections_valid.size() == 2)
    {
        *P1 = vP_intersections_valid[0];
        *P2 = vP_intersections_valid[1];
        //qDebug() << "D_Geo_Line_2D::intersection_rect" << "t/b/l/r" << t << b << l << r << "support" << support().x() << support().y() << "direction" << direction().x() << direction().y() << "-"                 <<  "2 valid intersections:" << P1->x() << P1->y() << "and" << P2->x() << P2->y() << "with distance" << P1->distance(*P2);
        return true;
    }

    //more than 2 (i.e. if line hits corner) --> select the 2 most distant points
    size_t i1_top = 0;
    size_t i2_top = 1;
    double dist_top = 0.0;
    for(size_t i1 = 0; i1 < vP_intersections_valid.size(); i1++)
        for(size_t i2 = i1+1; i2 < vP_intersections_valid.size(); i2++)
        {
            double dist = vP_intersections_valid[i1].distance(vP_intersections_valid[i2]);
            if(dist > dist_top)
            {
                i1_top = i1;
                i2_top = i2;
                dist_top = dist;
            }
        }

    if(dist_top > 0)
    {
        *P1 = vP_intersections_valid[i1_top];
        *P2 = vP_intersections_valid[i2_top];
        //qDebug() << "D_Geo_Line_2D::intersection_rect" << "t/b/l/r" << t << b << l << r << "support" << support().x() << support().y() << "direction" << direction().x() << direction().y() << "-" << vP_intersections_valid.size() << "valid intersections. Selected:" << P1->x() << P1->y() << "and" << P2->x() << P2->y() << "with distance" << P1->distance(*P2);
        return true;
    }

    //qDebug() << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    //qDebug() << "D_Geo_Line_2D::intersection_rect" << "t/b/l/r" << t << b << l << r << "support" << support().x() << support().y() << "direction" << direction().x() << direction().y() << "-" << "distance" << dist_top;
    //qDebug() << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    return false;
}

bool D_Geo_Line_2D::intersection_rect(D_Geo_Point_2D *P1, D_Geo_Point_2D *P2, Rect R)
{
    return intersection_rect(P1, P2, R.tl().y, R.br().y, R.tl().x, R.br().x);
}

bool D_Geo_Line_2D::intersection_rect(D_Geo_Point_2D *P1, D_Geo_Point_2D *P2, Mat *M)
{
    return intersection_rect(P1, P2, 0, M->rows, 0, M->cols);
}
