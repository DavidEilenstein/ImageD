/************************************
 *   added:     20.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_CONTOUR_H
#define D_CONTOUR_H

//own
#include <d_enum.h>

//general
#include <vector>
#include <thread>

//Qt
#include <QString>
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_Contour class represents a contour of a 2D object and offers several methods for gaining information about it
 * \details Very similar functionality to D_Component but with less functions and better performance.
 */
class D_Contour
{
public:
    D_Contour();
    D_Contour(vector<Point> contour);
    D_Contour(Rect box);

    D_Contour           offset(Point PO);

    void                set_contour(vector<Point> contour);

    vector<Point>       contour()                                   {return m_contour_points;}
    vector<Point>       contour(Point P_Offset);
    QString             contour_string();

    bool                empty()                                     {return m_n <= 0;}
    size_t              size()                                      {return m_n;}

    int                 l();
    int                 r();
    int                 b();
    int                 t();
    int                 w()                                         {return r() - l();}
    int                 h()                                         {return b() - t();}
    Point               tl()                                        {return Point(l(), t());}
    Point               tr()                                        {return Point(r(), t());}
    Point               bl()                                        {return Point(l(), b());}
    Point               br()                                        {return Point(r(), b());}
    Point               point(size_t i)                             {return i < m_n ? m_contour_points[i] : Point(0, 0);}
    Point               point(size_t i, Point offset)               {return point(i) + offset;}
    Point               point(size_t i, double scale)               {return point(i) * scale;}
    Point               point(size_t i, double scale, Point offset) {return point(i, scale) + offset;}

    Rect                bounding_box()                              {return Rect(tl(), br());}
    Rect                bounding_box(D_Contour contour_merge);

    double              area();
    double              perimeter();

    vector<D_Contour>   intersections(D_Contour C2);
    double              intersection_area(D_Contour C2);
    double              intersection_area_relative(D_Contour C2);

private:

    void                calc_left_right();
    void                calc_top_bottom();

    vector<Point>       m_contour_points;
    size_t              m_n                     = 0;
    int                 m_left                  = INT_MIN;
    int                 m_right                 = INT_MAX;
    int                 m_top                   = INT_MIN;
    int                 m_bottom                = INT_MAX;
    double              m_area                  = 0;
    double              m_perimeter             = 0;

    bool                state_contour_set       = false;
    bool                state_calced_left       = false;
    bool                state_calced_right      = false;
    bool                state_calced_top        = false;
    bool                state_calced_bottom     = false;
    bool                state_calced_area       = false;
    bool                state_calced_perimeter  = false;
};

#endif // D_CONTOUR_H
