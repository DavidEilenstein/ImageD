/************************************
 *   added:     07.04.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_GEO_POINTSET_2D_H
#define D_GEO_POINTSET_2D_H

//own
#include <d_enum.h>
#include <d_geo_point_2d.h>
#include <d_geo_line_2d.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <random>

//Qt
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_Geo_PointSet_2D
{
public:
    //constructors
    D_Geo_PointSet_2D();
    D_Geo_PointSet_2D(vector<D_Geo_Point_2D> points);

    //add points
    void add_point(D_Geo_Point_2D P)                    {v_points.push_back(P);}
    void add_point(double x, double y)                  {add_point(D_Geo_Point_2D(x, y));}
    void add_point(double u, double v, double w)        {add_point(D_Geo_Point_2D(u, v, w));}
    void add_point(D_Geo_Line_2D L1, D_Geo_Line_2D L2)  {add_point(D_Geo_Point_2D(L1, L2));}

    //getter & info about
    size_t                  size()                          {return v_points.size();}
    vector<D_Geo_Point_2D>  points()                        {return v_points;}
    D_Geo_Point_2D          point(size_t i)                 {return i < size() ? v_points[i] : D_Geo_Point_2D(0, 0, 0);}
    D_Geo_Point_2D          point_random();
    D_Geo_PointSet_2D       subset_random(double rel_size);
    RotatedRect             ellipse_fitted();
    RotatedRect             ellipse_pca_deviations();

    //naive center/std
    D_Geo_Point_2D center();
    D_Geo_Point_2D center(double *std);
    D_Geo_Point_2D center(double *std, vector<double> *v_residuals);
    double standard_deviation(D_Geo_Point_2D P_reference);
    double standard_deviation();
    double standard_deviation(D_Geo_Point_2D P_reference, vector<double> *v_residuals);

    //k-means culstering
    D_Geo_PointSet_2D centers_clusters_kmeans(size_t k, size_t iterations, double *deviation);
    D_Geo_PointSet_2D centers_clusters_kmeans(size_t k, double *deviation);
    D_Geo_PointSet_2D centers_clusters_kmeans(D_Geo_PointSet_2D centers_initial, double *deviation);

private:
    vector<D_Geo_PointSet_2D> clusters_kmeans_iteration(vector<D_Geo_PointSet_2D> clusters_in, bool *something_changed);

    //members
    vector<D_Geo_Point_2D> v_points;
};

#endif // D_GEO_POINTSET_2D_H
