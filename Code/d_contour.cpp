/************************************
 *   added:     20.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_contour.h"

D_Contour::D_Contour()
{

}

D_Contour::D_Contour(vector<Point> contour)
{
    set_contour(contour);
}

D_Contour D_Contour::offset(Point PO)
{
    return D_Contour(contour(PO));
}

void D_Contour::set_contour(vector<Point> contour)
{
    m_contour_points = contour;
    m_n = contour.size();
    state_contour_set = true;
}

vector<Point> D_Contour::contour(Point P_Offset)
{
    vector<Point> vContourWithOffset(m_contour_points.size());
    for(size_t i = 0; i < m_contour_points.size(); i++)
        vContourWithOffset[i] = m_contour_points[i] + P_Offset;

    return vContourWithOffset;
}

QString D_Contour::contour_string()
{
    QString QS_Contour;
    for(size_t i = 0; i < m_contour_points.size(); i++)
    {
        if(i > 0)
            QS_Contour.append(",");
        QS_Contour.append("(" + QString::number(m_contour_points[i].x) + "|" + QString::number(m_contour_points[i].y) + ")");
    }

    return QS_Contour;
}

int D_Contour::l()
{
    if(!state_contour_set)
        return INT_MIN;

    if(!state_calced_left)
        calc_left_right();

    return m_left;
}

int D_Contour::r()
{
    if(!state_contour_set)
        return INT_MAX;

    if(!state_calced_right)
        calc_left_right();

    return m_right;
}

int D_Contour::b()
{
    if(!state_contour_set)
        return INT_MAX;

    if(!state_calced_bottom)
        calc_top_bottom();

    return m_bottom;
}

int D_Contour::t()
{
    if(!state_contour_set)
        return INT_MIN;

    if(!state_calced_top)
        calc_top_bottom();

    return m_top;
}

double D_Contour::area()
{
    if(!state_contour_set)
        return 0;

    if(!state_calced_area)
    {
        m_area = contourArea(m_contour_points);
        state_calced_area = true;
    }

    return m_area;
}

double D_Contour::perimeter()
{
    if(!state_contour_set)
        return 0;

    if(!state_calced_perimeter)
    {
        m_perimeter = arcLength(m_contour_points, true);
        state_calced_perimeter = true;
    }

    return m_perimeter;
}

vector<D_Contour> D_Contour::intersections(D_Contour C2)
{
    //contour of intersection
    vector<D_Contour> vIntersect;

    //bounding boxes of contours
    int l1 = l();
    int l2 = C2.l();
    int r1 = r();
    int r2 = C2.r();
    int t1 = t();
    int t2 = C2.t();
    int b1 = b();
    int b2 = C2.b();

    //check if bounding boxes are distinct
    if(r2 < l1 || r1 < l2 || b2 < t1 || b1 < t2)
        return vIntersect;

    //calc bouding box of possible intersection
    int li = min(l1, l2);
    int ri = max(r1, r2);
    int ti = min(t1, t2);
    int bi = max(b1, b2);
    int wi = ri - li;
    int hi = bi - ti;

    //offset
    Point PO(li, ti);

    //create mats of contours
    Mat MA_tmp_1 = Mat::zeros(hi, wi, CV_8UC1);
    Mat MA_tmp_2 = Mat::zeros(hi, wi, CV_8UC1);

    //draw filled countours
    drawContours(MA_tmp_1, vector<vector<Point>>(1, contour(-PO)), -1, Scalar(255), -1);
    drawContours(MA_tmp_2, vector<vector<Point>>(1, C2.contour(-PO)), -1, Scalar(255), -1);

    //calc intersection of contours
    Mat MA_tmp_I;
    bitwise_and(MA_tmp_1, MA_tmp_2, MA_tmp_I);

    //get countours of intersection
    vector<vector<Point>> vvContours;
    vector<Vec4i> hierarchy;
    findContours(MA_tmp_I, vvContours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, PO);

    //release Mat memory
    MA_tmp_1.release();
    MA_tmp_2.release();
    MA_tmp_I.release();

    //check, if there are no intersections
    if(vvContours.empty())
        return vIntersect;

    //create contours for intersections
    size_t ni = vvContours.size();
    vIntersect.resize(ni);
    for(size_t i = 0; i < ni; i++)
        vIntersect[i] = D_Contour(vvContours[i]);

    //return detected contours
    return vIntersect;
}

double D_Contour::intersection_area(D_Contour C2)
{
    //bounding boxes of contours
    int l1 = l();
    int l2 = C2.l();
    int r1 = r();
    int r2 = C2.r();
    int t1 = t();
    int t2 = C2.t();
    int b1 = b();
    int b2 = C2.b();

    //check if bounding boxes are distinct
    if(r2 < l1 || r1 < l2 || b2 < t1 || b1 < t2)
        return 0.0;

    //calc bouding box of possible intersection
    int li = min(l1, l2);
    int ri = max(r1, r2);
    int ti = min(t1, t2);
    int bi = max(b1, b2);
    int wi = ri - li;
    int hi = bi - ti;

    //offset
    Point PO(li, ti);

    //create mats of contours
    Mat MA_tmp_1 = Mat::zeros(hi, wi, CV_8UC1);
    Mat MA_tmp_2 = Mat::zeros(hi, wi, CV_8UC1);

    //draw filled countours
    drawContours(MA_tmp_1, vector<vector<Point>>(1, contour(-PO)), -1, Scalar(255), -1);
    drawContours(MA_tmp_2, vector<vector<Point>>(1, C2.contour(-PO)), -1, Scalar(255), -1);

    //calc intersection of contours
    Mat MA_tmp_I;
    bitwise_and(MA_tmp_1, MA_tmp_2, MA_tmp_I);

    //get countours of intersection
    vector<vector<Point>> vvContours;
    vector<Vec4i> hierarchy;
    findContours(MA_tmp_I, vvContours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, PO);

    //release Mat memory
    MA_tmp_1.release();
    MA_tmp_2.release();
    MA_tmp_I.release();

    //check, if there are no intersections
    if(vvContours.empty())
        return 0.0;

    //calc sum of areas of intersections
    size_t ni = vvContours.size();
    double area = 0.0;
    for(size_t i = 0; i < ni; i++)
        area += contourArea(vvContours[i]);

    //return detected contours
    return area;
}

double D_Contour::intersection_area_relative(D_Contour C2)
{
    double area_sum = (area() + C2.area());
    if(area_sum == 0.0)
        return 0.0;
    else
        return (2 * intersection_area(C2)) / area_sum;
}

void D_Contour::calc_left_right()
{
    if(!state_contour_set)
        return;

    if(state_calced_left && state_calced_right)
        return;

    m_left = INT_MAX;
    m_right = INT_MIN;

    for(size_t i = 0; i < m_n; i++)
    {
        int x = m_contour_points[i].x;
        if(x < m_left)
            m_left = x;
        if(x > m_right)
            m_right = x;
    }

    state_calced_left = true;
    state_calced_right = true;
}

void D_Contour::calc_top_bottom()
{
    if(!state_contour_set)
        return;

    if(state_calced_top && state_calced_bottom)
        return;

    m_top = INT_MAX;
    m_bottom = INT_MIN;

    for(size_t i = 0; i < m_n; i++)
    {
        int y = m_contour_points[i].y;
        if(y < m_top)
            m_top = y;
        if(y > m_bottom)
            m_bottom = y;
    }

    state_calced_top = true;
    state_calced_bottom = true;
}
