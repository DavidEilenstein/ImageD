/************************************
 *   added:     07.04.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_geo_lineset_2d.h"

D_Geo_LineSet_2D::D_Geo_LineSet_2D()
{

}

D_Geo_LineSet_2D::D_Geo_LineSet_2D(vector<D_Geo_Line_2D> lines)
{
    v_lines = lines;
}

void D_Geo_LineSet_2D::add_line(D_Geo_Line_2D line)
{
    v_lines.push_back(line);
}

void D_Geo_LineSet_2D::add_line_point_point(D_Geo_Point_2D P1, D_Geo_Point_2D P2)
{
    v_lines.push_back(D_Geo_Line_2D(P1, P2));
}

void D_Geo_LineSet_2D::add_line_point_direction(D_Geo_Point_2D P_support, D_Geo_Point_2D direction)
{
    D_Geo_Line_2D line;
    line.set_point_direction(P_support, direction);
    return add_line(line);
}

void D_Geo_LineSet_2D::add_line_point_angle(D_Geo_Point_2D P_support, double angle_rad)
{
    D_Geo_Line_2D line;
    line.set_point_angle(P_support, angle_rad);
    return add_line(line);
}

/*!
 * \brief D_Geo_LineSet_2D::subset_random takes a subset of the line set for i.e. RANSAC methods
 * \param percent percentage of elemenets --> subset size
 * \return subset of lines
 */
D_Geo_LineSet_2D D_Geo_LineSet_2D::subset_random(double rel_size)
{
    ///make sure rel_size is in range (0,1)
    rel_size < 0 ? rel_size = 0 : rel_size > 1 ? rel_size = 1 : rel_size;

    ///calc subset size
    size_t n_new = v_lines.size() * rel_size;

    ///shuffel lines
    random_shuffle(v_lines.begin(), v_lines.end());

    ///create line subset
    D_Geo_LineSet_2D subset;
    for(size_t i = 0; i < n_new; i++)
        subset.add_line(v_lines[i]);

    ///return subset
    return subset;
}

D_Geo_Line_2D D_Geo_LineSet_2D::line(size_t i)
{
    return i < v_lines.size() ? v_lines[i] : D_Geo_Line_2D();
}

/*!
 * \brief D_Geo_LineSet_2D::size number of lines in line set
 * \return number of lines
 */
size_t D_Geo_LineSet_2D::size()
{
    return v_lines.size();
}

/*!
 * \brief D_Geo_LineSet_2D::intersections_pairwise calc pairwise intersections of lines in set
 * \return set of intersection points
 */
D_Geo_PointSet_2D D_Geo_LineSet_2D::intersections_pairwise()
{
    D_Geo_PointSet_2D intersections;

    size_t n = v_lines.size();
    for(size_t i = 0; i < n; i++)
        for(size_t j = i + 1; j < n; j++)
            intersections.add_point(D_Geo_Point_2D(v_lines[i], v_lines[j]));

    return intersections;
}

D_Geo_Point_2D D_Geo_LineSet_2D::intersection(double *deviation)
{
    return intersections_pairwise().center(deviation);
}

/*!
 * \brief D_Geo_LineSet_2D::intersection_ransac Find best guess for intersections center of line set
 * \param least_deviation remaining deviation in subset
 * \param lines_needed_for_modell_rel relative amount of lines needed for a good modell
 * \param p_good_guess probability of getting a good modell (greater than 0, lower than 1)
 * \param p_outliers probability of outliers
 * \return best guess for intersection of line set
 */
D_Geo_Point_2D D_Geo_LineSet_2D::intersection_ransac(double *least_deviation, double lines_needed_for_modell_rel, double p_good_guess, double p_outliers, bool subset_of_points_not_lines)
{
    ///parameters needed for try count calculation
    double m = v_lines.size();                      //number of elements
    double s = m * lines_needed_for_modell_rel;     //line count needed for modell
    double e = p_outliers;                          //probability of outliers
    double p = p_good_guess;                        //probability of a resulting modell not using outliers

    ///needed number of tries
    double n = log(1.0 - p) / log(1.0 - pow((1.0 - e), s));

    return intersection_ransac(least_deviation, lines_needed_for_modell_rel, ceil(n), subset_of_points_not_lines);
}

/*!
 * \brief D_Geo_LineSet_2D::intersection_ransac Find best guess for intersections center of line set
 * \param least_deviation remaining deviation in subset
 * \param subset_size_rel realtive subset size
 * \param iterations number of trys (= count of subsets) to find center
 * \return best guess for intersection of line set
 */
D_Geo_Point_2D D_Geo_LineSet_2D::intersection_ransac(double *least_deviation, double subset_size_rel, size_t iterations, bool subset_of_points_not_lines)
{
    D_Geo_PointSet_2D PS;
    return intersection_ransac(least_deviation, &PS, subset_size_rel, iterations, subset_of_points_not_lines);
}

D_Geo_Point_2D D_Geo_LineSet_2D::intersection_ransac(double *least_deviation, D_Geo_PointSet_2D *IntersectionsUsed, double subset_size_rel, size_t iterations, bool subset_of_points_not_lines)
{
    ///init centers & stds top/current
    D_Geo_Point_2D center_best = D_Geo_Point_2D(0, 0, 0);
    *least_deviation = INFINITY;
    double std_current;

    ///try iterations subsets
    for(size_t i = 0; i < iterations; i++)
    {
        ///use subset of lines or intersection points
        D_Geo_PointSet_2D Point_subset;
        if(subset_of_points_not_lines)
            Point_subset = intersections_pairwise().subset_random(subset_size_rel);
        else
            Point_subset = subset_random(subset_size_rel).intersections_pairwise();

        ///find best guess for center
        D_Geo_Point_2D center_current = Point_subset.center(&std_current);

        ///save as new best guess, if better than old best guess
        if(std_current < *least_deviation)
        {
            center_best = center_current;
            *least_deviation = std_current;
            *IntersectionsUsed = Point_subset;
        }
    }

    ///return best guess
    return center_best;
}

D_Geo_PointSet_2D D_Geo_LineSet_2D::intersections_clustered_kmeans(double *deviation, size_t k, size_t iterations)
{
    return intersections_pairwise().centers_clusters_kmeans(k, iterations, deviation);
}

D_Geo_PointSet_2D D_Geo_LineSet_2D::intersections_clustered_kmeans_ransac(double *deviation, size_t clustering_k, size_t clustering_iterations, double ransac_subset_size_rel, size_t ransac_iterations)
{
    ///init centers & stds top/current
    D_Geo_PointSet_2D centers_best(vector<D_Geo_Point_2D>(clustering_k, D_Geo_Point_2D(0, 0, 0)));
    *deviation = INFINITY;
    double std_current;

    ///try iterations subsets
    for(size_t i = 0; i < ransac_iterations; i++)
    {
        ///find best guesses for centers (k-means)
        D_Geo_PointSet_2D centers_current = subset_random(ransac_subset_size_rel).intersections_clustered_kmeans(&std_current, clustering_k, clustering_iterations);
        if(std_current < *deviation)
        {
            centers_best = centers_current;
            *deviation = std_current;
        }
    }

    ///return best guess
    return centers_best;
}

