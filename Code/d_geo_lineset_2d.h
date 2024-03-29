/************************************
 *   added:     07.04.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_GEO_LINESET_2D_H
#define D_GEO_LINESET_2D_H

//own
#include <d_enum.h>
#include <d_geo_point_2d.h>
#include <d_geo_line_2d.h>
#include <d_geo_pointset_2d.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <thread>
#include <time.h>

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

class D_Geo_LineSet_2D
{
public:
    //constructors
    D_Geo_LineSet_2D();
    D_Geo_LineSet_2D(vector<D_Geo_Line_2D> lines);

    //add lines
    void add_line(D_Geo_Line_2D line);
    void add_line_point_point(D_Geo_Point_2D P1, D_Geo_Point_2D P2);
    void add_line_point_direction(D_Geo_Point_2D P_support, D_Geo_Point_2D direction);
    void add_line_point_angle(D_Geo_Point_2D P_support, double angle_rad);

    //getter
    D_Geo_LineSet_2D    subset_random(double rel_size);
    D_Geo_Line_2D       line(size_t i);
    size_t              size();

    //intersections

    //pairwise intersections
    D_Geo_PointSet_2D intersections_pairwise();

    //center of intersections
    D_Geo_Point_2D intersection(double *deviation);
    D_Geo_Point_2D intersection(double *deviation, vector<double> *v_residuals);
    D_Geo_Point_2D intersection_ransac(double *least_deviation, double lines_needed_for_modell_rel, double p_good_guess, double p_outliers, bool subset_of_points_not_lines);
    D_Geo_Point_2D intersection_ransac(double *least_deviation, double subset_size_rel, size_t iterations, bool subset_of_points_not_lines);
    D_Geo_Point_2D intersection_ransac(double *least_deviation, D_Geo_PointSet_2D *IntersectionsUsed, vector<double> *v_residuals, double subset_size_rel, size_t iterations, bool subset_of_points_not_lines);

    //k-means clustering of pairwise intersections
    D_Geo_PointSet_2D intersections_clustered_kmeans(double *deviation, size_t k, size_t iterations);
    D_Geo_PointSet_2D intersections_clustered_kmeans_ransac(double *deviation, size_t clustering_k, size_t clustering_iterations, double ransac_subset_size_rel, size_t ransac_iterations);

private:
    vector<D_Geo_Line_2D> v_lines;

    //threaded ransac
    static void intersection_ransac_thread(D_Geo_LineSet_2D *line_set, D_Geo_Point_2D *center_best, double *least_deviation, D_Geo_PointSet_2D *IntersectionsUsed, vector<double> *v_residuals, double subset_size_rel, size_t iterations, bool subset_of_points_not_lines);

};

#endif // D_GEO_LINESET_2D_H
