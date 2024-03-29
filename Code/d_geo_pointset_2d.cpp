/************************************
 *   added:     07.04.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_geo_pointset_2d.h"

D_Geo_PointSet_2D::D_Geo_PointSet_2D()
{

}

D_Geo_PointSet_2D::D_Geo_PointSet_2D(vector<D_Geo_Point_2D> points)
{
    v_points = points;
}

/*!
 * \brief D_Geo_PointSet_2D::random_subset takes a subset of the line set for i.e. RANSAC methods
 * \param percent percentage of elemenets --> subset size
 * \return subset of points
 */
D_Geo_PointSet_2D D_Geo_PointSet_2D::subset_random(double rel_size)
{
    ///make sure rel_size is in range (0,1)
    rel_size < 0 ? rel_size = 0 : rel_size > 1 ? rel_size = 1 : rel_size;

    ///calc subset size
    size_t n_all = v_points.size();
    size_t n_sub = ceil(n_all * rel_size);

    ///create vector of indices and shuffel it
    vector<size_t> v_indices(n_all);
    iota(v_indices.begin(), v_indices.end(), 0);
    std::random_device rd;
    auto rng = std::default_random_engine {rd()};
    shuffle(v_indices.begin(), v_indices.end(), rng);

    ///create line subset
    D_Geo_PointSet_2D subset;
    for(size_t i = 0; i < n_sub; i++)
        subset.add_point(v_points[v_indices[i]]);

    ///return subset
    return subset;
}

/*!
 * \brief D_Geo_PointSet_2D::ellipse_fitted fit an ellipse to the point set
 * \return fitted ellipse
 */
RotatedRect D_Geo_PointSet_2D::ellipse_fitted()
{
    ///convert points to CV style points
    vector<Point2f> vPoints;
    for(size_t i = 0; i < size(); i++)
        vPoints.push_back(v_points[i].CV_Point2f());

    ///calc fitted ellipse
    return fitEllipse(vPoints);
}

RotatedRect D_Geo_PointSet_2D::ellipse_pca_deviations()
{
    //Construct a buffer used by the pca analysis
    Mat MA_points = Mat(static_cast<int>(size()), 2, CV_64FC1);
    for(int i = 0; i < MA_points.rows; i++)
    {
        MA_points.at<double>(i, 0) = v_points[i].x();
        MA_points.at<double>(i, 1) = v_points[i].y();
    }

    //Perform PCA analysis
    PCA pca_analysis(MA_points, Mat(), PCA::DATA_AS_ROW);

    //Store center
    Point2f center = Point2f(static_cast<int>(pca_analysis.mean.at<double>(0, 0)),
                             static_cast<int>(pca_analysis.mean.at<double>(0, 1)));

    //Store the eigenvalues and eigenvectors
    vector<Point2d> eigen_vecs(2);
    vector<double> eigen_vals(2);
    for (int i = 0; i < 2; i++)
    {
        eigen_vecs[i] = Point2d(pca_analysis.eigenvectors.at<double>(i, 0),
                                pca_analysis.eigenvectors.at<double>(i, 1));
        eigen_vals[i] = pca_analysis.eigenvalues.at<double>(i);
    }

    return RotatedRect(
                center,
                Size2f(eigen_vals[0], eigen_vals[1]),
                atan2(eigen_vecs[0].y, eigen_vecs[0].y));
}

/*!
 * \brief D_Geo_PointSet_2D::point_random returns a random point from the point set
 * \return a random point from the point set
 */
D_Geo_Point_2D D_Geo_PointSet_2D::point_random()
{
    ///uniform distibution (range fitting to index max)
    uniform_int_distribution<size_t> generator(0, size() - 1);

    ///seed random generator
    mt19937 seed(time(NULL));

    ///return a random point
    return v_points[generator(seed)];
}

/*!
 * \brief D_Geo_PointSet_2D::center calc center of the point set
 * \return center
 */
D_Geo_Point_2D D_Geo_PointSet_2D::center()
{
    double sum_x = 0;
    double sum_y = 0;
    for(size_t i = 0; i < v_points.size(); i++)
    {
        sum_x += v_points[i].x();
        sum_y += v_points[i].y();
    }

    return D_Geo_Point_2D(sum_x / v_points.size(), sum_y / v_points.size());
}

D_Geo_Point_2D D_Geo_PointSet_2D::center(double *std)
{
    vector<double> v_residuals;
    return center(std, &v_residuals);
}

D_Geo_Point_2D D_Geo_PointSet_2D::center(double *std, vector<double> *v_residuals)
{
    D_Geo_Point_2D P_mean = center();
    *std = standard_deviation(P_mean, v_residuals);
    return P_mean;
}


double D_Geo_PointSet_2D::standard_deviation(D_Geo_Point_2D P_reference)
{
    vector<double> v_residuals;
    return standard_deviation(P_reference, &v_residuals);
}

/*!
 * \brief D_Geo_PointSet_2D::standard_deviation calcs the standard deviation to the center
 * \return distance standard deviation to mean
 */
double D_Geo_PointSet_2D::standard_deviation()
{
    return standard_deviation(center());
}

double D_Geo_PointSet_2D::standard_deviation(D_Geo_Point_2D P_reference, vector<double> *v_residuals)
{
    if(v_points.size() <= 0)
        return 0;

    v_residuals->clear();

    double x_ref = P_reference.x();
    double y_ref = P_reference.y();

    double sum_dist_pow2 = 0;
    for(size_t i = 0; i < v_points.size(); i++)
    {
        double dx = x_ref - v_points[i].x();
        double dy = y_ref - v_points[i].y();
        double dist_pow2 = dx * dx + dy * dy;
        sum_dist_pow2 += dist_pow2;
        double dist = sqrt(dist_pow2);
        v_residuals->push_back(dist);
    }

    return sqrt(sum_dist_pow2 / v_points.size());
}

D_Geo_PointSet_2D D_Geo_PointSet_2D::centers_clusters_kmeans(size_t k, size_t iterations, double *deviation)
{
    ///init best clustering
    D_Geo_PointSet_2D centers_best;
    *deviation = INFINITY;

    ///try iterations clusterings with different initializations
    for(size_t i = 0; i < iterations; i++)
    {
        double deviation_current;
        D_Geo_PointSet_2D clusters_current = centers_clusters_kmeans(k, &deviation_current);
        if(deviation_current < *deviation)
        {
            *deviation = deviation_current;
            centers_best = clusters_current;
        }
    }

    ///return best cluster centers
    return centers_best;
}

/*!
 * \brief D_Geo_PointSet_2D::centers_clusters_kmeans uses k-means to estimate k cluster centers
 * \details guesses inital center points using simplified <a href="http://ilpubs.stanford.edu:8090/778/1/2006-13.pdf">k-means++</a>
 * \details (see <a href="https://medium.com/analytics-vidhya/comparison-of-initialization-strategies-for-k-means-d5ddd8b0350e">this aticle</a> for short explanation)
 * \details This implementation is simplified: As initial centers the beyond the first, always the furthest point from the remaining distribution is chosen.
 * \param k number of clusters
 * \param deviation remaining deviation
 * \return cluster centers
 */
D_Geo_PointSet_2D D_Geo_PointSet_2D::centers_clusters_kmeans(size_t k, double *deviation)
{
    ///init inital centers guess with a random point from the point set
    D_Geo_PointSet_2D centers_initial;
    centers_initial.add_point(point_random());

    ///other centers are the furthest point to all others (max dist to closest center)
    //calc center guess for all clusters but the 1st clusters
    for(size_t c_guess = 1; c_guess < k; c_guess++)
    {
        //find the point with the greatest distance to the closets existing center guess
        double dist_furthest_closest_center = 0;
        size_t p_best_next_guess = 0;
        for(size_t p = 0; p < size(); p++)
        {
            //find the min dist to an existing center guess
            D_Geo_Point_2D P = v_points[p];
            double dist_closest_center = INFINITY;
            for(size_t c_check = 0; c_check < centers_initial.size(); c_check++)
                dist_closest_center = min(dist_closest_center, P.distance(centers_initial.point(c_check)));

            //check, if distance to closest center is new maximum of those
            if(dist_closest_center > dist_furthest_closest_center)
            {
                p_best_next_guess = p;
                dist_furthest_closest_center = dist_closest_center;
            }
        }

        //add the point with greatest distance to clostes existing center as new center guess
        centers_initial.add_point(v_points[p_best_next_guess]);
    }

    ///execute k-means with given inital centers
    return centers_clusters_kmeans(centers_initial, deviation);
}

D_Geo_PointSet_2D D_Geo_PointSet_2D::centers_clusters_kmeans(D_Geo_PointSet_2D centers_initial, double *deviation)
{
    ///clusters
    size_t k = centers_initial.size();
    vector<D_Geo_PointSet_2D> clusters(k);

    ///initial clustering
    for(size_t i = 0; i < size(); i++)
    {
        double dist_nearest = INFINITY;
        size_t j_nearest = 0;
        for(size_t j = 0; j < k; j++)
        {
            double dist = v_points[j].distance(centers_initial.point(j));
            if(dist < dist_nearest)
            {
                dist_nearest = dist;
                j_nearest = j;
            }
        }
        clusters[j_nearest].add_point(v_points[i]);
    }

    ///iterate until optimum
    bool something_changed = true;
    while(something_changed)
        clusters = clusters_kmeans_iteration(clusters, &something_changed);

    ///calc resulting centers and remaining deviation
    D_Geo_PointSet_2D centers_resulting;
    *deviation = 0;
    for(size_t j = 0; j < k; j++)
    {
        double cluster_deviation;
        centers_resulting.add_point(clusters[j].center(&cluster_deviation));
        *deviation += cluster_deviation;
    }

    ///return resulting centers
    return centers_resulting;
}

vector<D_Geo_PointSet_2D> D_Geo_PointSet_2D::clusters_kmeans_iteration(vector<D_Geo_PointSet_2D> clusters_in, bool *something_changed)
{
    ///clusters out
    size_t k = clusters_in.size();
    vector<D_Geo_PointSet_2D> clusters_out(k);

    ///calc centers of clusters
    D_Geo_PointSet_2D centers;
    for(size_t j = 0; j < k; j++)
        centers.add_point(clusters_in[j].center());

    ///loop input clusters
    for(size_t c_in = 0; c_in < k; c_in++)
    {
        ///loop points in cluster c_in
        for(size_t p = 0; p < size(); p++)
        {
            ///find min distance cluster centers
            double dist_nearest = INFINITY;
            size_t c_nearest = 0;
            for(size_t c_out = 0; c_out < k; c_out++)
            {
                double dist = clusters_in[c_in].point(p).distance(centers.point(c_out));
                if(dist < dist_nearest)
                {
                    dist_nearest = dist;
                    c_nearest = c_out;
                }
            }

            ///assign point to (new) cluster and check if something changed
            clusters_out[c_nearest].add_point(clusters_in[c_in].point(p));
            if(c_nearest != c_in)
                *something_changed = true;
        }
    }

    ///return new clustering
    return clusters_out;
}
