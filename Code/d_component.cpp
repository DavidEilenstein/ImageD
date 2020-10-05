/************************************
 *   added:     30.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_component.h"

D_Component::D_Component()
{
    vd_Features.resize(c_FEAT_NUMBER_OF_FEATS, 0.0);
}

D_Component::D_Component(int number)
{
    i_Number = number;
    vd_Features.resize(c_FEAT_NUMBER_OF_FEATS, 0.0);
}

D_Component::D_Component(vector<Point> points2init)
{
    vp_Contour = points2init;
    vd_Features.resize(c_FEAT_NUMBER_OF_FEATS, 0.0);
}

D_Component::D_Component(vector<Point> points2init, int number)
{
    vp_Contour = points2init;
    i_Number = number;
    vd_Features.resize(c_FEAT_NUMBER_OF_FEATS, 0.0);
}

void D_Component::Calc_All()
{
    Calc_Mat();
}

void D_Component::Calc_Mat()
{
    //qDebug() << "D_Component - calc mat";

    if(calced_mat)              return;
    if(vp_Coordinates.empty())  return;

    //max/min
    top     = vp_Coordinates[0].y;
    bottom  = vp_Coordinates[vp_Coordinates.size() - 1].y;
    left    = vp_Coordinates[0].x;
    right   = vp_Coordinates[vp_Coordinates.size() - 1].x;

    //check left/right
    for(int px = 0; px < vp_Coordinates.size(); px++)
    {
        int x = vp_Coordinates[px].x;
        if(x < left)    left = x;
        if(x > right)   right = x;
    }

    //Position
    width = right - left + 1;
    height = bottom - top + 1;
    p_Offset = Point(left, top);
    //r_CropRect = Rect(left, top, width, height);

    //Mat
    MA_Cropped = Mat::zeros(
                    height,
                    width,
                    CV_8UC1);

    for(int px = 0; px < vp_Coordinates.size(); px++)
    {
        int x = vp_Coordinates[px].x - p_Offset.x;
        int y = vp_Coordinates[px].y - p_Offset.y;
        //qDebug() << "img w/h" << MA_Cropped.cols << MA_Cropped.rows << "x/y" << x << y << "px" << px << "of" << vp_Coordinates.size();
        MA_Cropped.at<uchar>(y, x) = static_cast<uchar>(255);
    }

    //imwrite(("D:/David_Eilenstein/ImageD/StepsStream/stack_test/Croped Mat" + QString::number(i_Number).toStdString() + ".jpg"), MA_Cropped);

    calced_mat = true;
    Calc_Contour();
}

void D_Component::Calc_Contour()
{
    //qDebug() << "D_Component - calc contour";

    if(calced_contour)      return;
    if(MA_Cropped.empty())  return;

    //qDebug() << "count:" << sum(MA_Cropped)[0] / 255;


    //qDebug() << "D_Component - contour find";
    vector<vector<Point>> vvp_Contours_tmp;
    findContours(
                MA_Cropped,
                vvp_Contours_tmp,
                RETR_CCOMP,
                CV_CHAIN_APPROX_NONE);
    //qDebug() << "D_Component - contour export";

    vp_Contour = vvp_Contours_tmp[0];
    i_Holes = static_cast<int>(vvp_Contours_tmp.size() - 1);

    //get rid of offset
    for(int cpx = 0; cpx < vp_Contour.size(); cpx++)
        vp_Contour[cpx] = Point(
                    vp_Contour[cpx].x + p_Offset.x,
                    vp_Contour[cpx].y + p_Offset.y);

    //qDebug() << "D_Component - contour finished";
    calced_contour = true;
    Calc_Distance();
    Calc_Features();
}

void D_Component::Calc_Distance()
{
    //pad with 0 to avoid images with no background (would lead to undefined values in distance transform)
    copyMakeBorder(
                MA_Cropped,
                MA_Distance,
                1,
                1,
                1,
                1,
                BORDER_CONSTANT);

    distanceTransform(
                MA_Distance,
                MA_Distance,
                CV_DIST_L2,
                CV_DIST_MASK_3);
}

void D_Component::Calc_Features()
{
    //qDebug() << "D_Component - calc features";

    if(!calced_mat)         return;
    if(calced_features)     return;

    if(vp_Contour.empty())
        return;

    //INIT---------------------------------------
    vd_Features.clear();
    vd_Features.resize(c_FEAT_NUMBER_OF_FEATS, 0.0);

    //to avoid crash on strange shapes where calculation does not work
    p_Centroid  = Point2f(vp_Coordinates[0]);

    //CALC---------------------------------------

    //size
    double px_contour       = vp_Contour.size();
    double px_coordinates   = vp_Coordinates.size();

    //moments
    m_Moments               = moments(vp_Contour);
    HuMoments(m_Moments, m_HuMoments);

    //Spatial moments
    double m00              = m_Moments.m00;
    double m10              = m_Moments.m10;
    double m01              = m_Moments.m01;
    double m20              = m_Moments.m20;
    double m11              = m_Moments.m11;
    double m02              = m_Moments.m02;
    double m30              = m_Moments.m30;
    double m21              = m_Moments.m21;
    double m12              = m_Moments.m12;
    double m03              = m_Moments.m03;

    //Central Moments
    double mu20             = m_Moments.mu20;
    double mu11             = m_Moments.mu11;
    double mu02             = m_Moments.mu02;
    double mu30             = m_Moments.mu30;
    double mu21             = m_Moments.mu21;
    double mu12             = m_Moments.mu12;
    double mu03             = m_Moments.mu03;

    //Central Moments normed
    double nu20             = m_Moments.nu20;
    double nu11             = m_Moments.nu11;
    double nu02             = m_Moments.nu02;
    double nu30             = m_Moments.nu30;
    double nu21             = m_Moments.nu21;
    double nu12             = m_Moments.nu12;
    double nu03             = m_Moments.nu03;

    //invariant moments
    double hu0              = m_HuMoments[0];
    double hu1              = m_HuMoments[1];
    double hu2              = m_HuMoments[2];
    double hu3              = m_HuMoments[3];
    double hu4              = m_HuMoments[4];
    double hu5              = m_HuMoments[5];
    double hu6              = m_HuMoments[6];


    //Centroid
    double mass_center_x;
    double mass_center_y;
    if(m00 == 0)
    {
        mass_center_x       = vp_Contour[0].x;
        mass_center_y       = vp_Contour[0].y;
    }
    else
    {
        mass_center_x       = m10 / m00;
        mass_center_y       = m01 / m00;
    }
    p_Centroid              = Point2f(mass_center_x, mass_center_y);
    double dist_cent2cont   = pointPolygonTest(vp_Contour, p_Centroid, true);


    //Area
    double area             = contourArea(vp_Contour);

    //Perimeter
    double perimeter        = arcLength(vp_Contour, true);

    //Bounding Box Rect
    r_BoundingBox_Rect          = boundingRect(vp_Contour);
    double bndBox_Rect_left     = r_BoundingBox_Rect.x;
    double bndBox_Rect_top      = r_BoundingBox_Rect.y;
    double bndBox_Rect_width    = r_BoundingBox_Rect.width;
    double bndBox_Rect_height   = r_BoundingBox_Rect.height;
    double bndBox_Rect_bottom   = bndBox_Rect_top   + bndBox_Rect_height;
    double bndBox_Rect_right    = bndBox_Rect_left  + bndBox_Rect_width;
    double bndBox_Rect_area     = r_BoundingBox_Rect.area();
    double bndBox_Rect_center_x = bndBox_Rect_left + (bndBox_Rect_right - bndBox_Rect_left) / 2.0;
    double bndBox_Rect_center_y = bndBox_Rect_top + (bndBox_Rect_bottom - bndBox_Rect_top) / 2.0;
    double bndBox_Rect_perimeter= 2 * bndBox_Rect_width + 2 * bndBox_Rect_height;                       //maybe correction for subpixel precision is needed

    double bndBox_Rect_side_long;
    double bndBox_Rect_side_short;
    if(bndBox_Rect_height < bndBox_Rect_width)
    {
        bndBox_Rect_side_long    = bndBox_Rect_width;
        bndBox_Rect_side_short   = bndBox_Rect_height;
    }
    else
    {
        bndBox_Rect_side_long    = bndBox_Rect_height;
        bndBox_Rect_side_short   = bndBox_Rect_width;
    }

    double bndBox_Rect_aspect_r = bndBox_Rect_side_short / bndBox_Rect_side_long;
    double bndBox_Rect_aspect_r_inv = 1 / bndBox_Rect_aspect_r;

    //Bounding Box Rotate
    r_BoundingBox_Rotate        = minAreaRect(vp_Contour);
    double bndBox_Rot_area      = r_BoundingBox_Rotate.size.area();
    double bndBox_Rot_angle     = r_BoundingBox_Rotate.angle;
    double bndBox_Rot_height    = r_BoundingBox_Rotate.size.height;
    double bndBox_Rot_width     = r_BoundingBox_Rotate.size.width;
    double bndBox_Rot_center_x  = r_BoundingBox_Rotate.center.x;
    double bndBox_Rot_center_y  = r_BoundingBox_Rotate.center.y;
    double bndBox_Rot_perimeter = 2 * bndBox_Rot_width + 2 * bndBox_Rot_height;

    double bndBox_Rot_side_long;
    double bndBox_Rot_side_short;
    if(bndBox_Rot_height < bndBox_Rot_width)
    {
        bndBox_Rot_side_long    = bndBox_Rot_width;
        bndBox_Rot_side_short   = bndBox_Rot_height;
    }
    else
    {
        bndBox_Rot_side_long    = bndBox_Rot_height;
        bndBox_Rot_side_short   = bndBox_Rot_width;
    }

    //min enclosing circle
    p_EnclosingCircle_Center    = p_Centroid;
    minEnclosingCircle(vp_Contour, p_EnclosingCircle_Center, f_EnclosingCircle_Radius);
    double encCirc_radius       = f_EnclosingCircle_Radius;
    double encCirc_center_x     = p_EnclosingCircle_Center.x;
    double encCirc_center_y     = p_EnclosingCircle_Center.y;
    double encCirc_diameter     = 2 * encCirc_radius;
    double encCirc_area         = PI * encCirc_radius * encCirc_radius;
    double encCirc_perimeter    = PI * encCirc_diameter;

    //fit ellipse
    double fitEll_center_x      = 0;
    double fitEll_center_y      = 0;
    double fitEll_major_semiaxis= 0;
    double fitEll_minor_semiaxis= 0;
    double fitEll_angle         = 0;
    double fitEll_area          = 0;
    double fitELL_perimeter     = 0;

    if(px_coordinates >= 5) //ellipse fit only works with 5 or more points
    {
        r_EllipseFit            = fitEllipse(vp_Coordinates);
        fitEll_center_x         = r_EllipseFit.center.x;
        fitEll_center_y         = r_EllipseFit.center.y;
        fitEll_major_semiaxis   = r_EllipseFit.size.width / 2.0;
        fitEll_minor_semiaxis   = r_EllipseFit.size.height / 2.0;
        fitEll_angle            = r_EllipseFit.angle;
        fitEll_area             = PI * fitEll_major_semiaxis * fitEll_minor_semiaxis;
        fitELL_perimeter        = PI * ((3 * (fitEll_major_semiaxis + fitEll_minor_semiaxis)) - sqrt(((3 * fitEll_major_semiaxis) + fitEll_minor_semiaxis) * (fitEll_major_semiaxis + (3 * fitEll_minor_semiaxis))));
    }


    //inscribing/circumscribing circle
    Point2f p_Contour_first = vp_Contour[0];
    double circumCirc_Radius  = norm(p_Centroid - p_Contour_first);
    double inscriCirc_Radius  = norm(p_Centroid - p_Contour_first);
    for(int p = 0; p < vp_Contour.size(); p++)
    {
        Point2f p_Contour_current = vp_Contour[p];
        double r = norm(p_Centroid - p_Contour_current);
        if(r < inscriCirc_Radius) inscriCirc_Radius = r;
        if(r > circumCirc_Radius) circumCirc_Radius = r;
    }

    if(dist_cent2cont < 0)      inscriCirc_Radius = 0;  //check, if centroid is in contour

    double circumCirc_Diameter  = 2  * circumCirc_Radius;
    double circumCirc_Area      = PI * circumCirc_Radius * circumCirc_Radius;
    double circumCirc_Perimeter = PI * circumCirc_Diameter;
    double inscriCirc_Diameter  = 2  * inscriCirc_Radius;
    double inscriCirc_Area      = PI * inscriCirc_Radius * inscriCirc_Radius;
    double inscriCirc_Perimeter = PI * inscriCirc_Diameter;

    //inclosing circle (distance tranbsform: max_val = r, max_pos = center)
    f_InclosingCircle_Radius = 0.0;
    p_InclosingCircle_Center = Point(1, 1); // 0,0 -> 1,1 because of padding
    for(int y = 0; y < MA_Distance.rows; y++)
    {
        for(int x = 0; x < MA_Distance.cols; x++)
        {
            float val = MA_Distance.at<float>(y, x);
            if(val > f_InclosingCircle_Radius)
            {
                f_InclosingCircle_Radius = val;
                p_InclosingCircle_Center = Point(x - 1, y - 1); // -1,-1 because of padding
            }
        }
    }
    p_InclosingCircle_Center += p_Offset;

    double inclosingCirc_Center_X   = p_InclosingCircle_Center.x;
    double inclosingCirc_Center_Y   = p_InclosingCircle_Center.y;
    double inclosingCirc_Diameter   = f_InclosingCircle_Radius * 2;
    double inclosingCirc_Perimeter  = inclosingCirc_Diameter * PI;
    double inclosingCirc_Area       = f_InclosingCircle_Radius * f_InclosingCircle_Radius * PI;

    //convex hull
    convexHull(vp_Contour, vp_ConvexHull);
    double cvxHull_Area         = contourArea(vp_ConvexHull);
    double cvxHull_Perimeter    = arcLength(vp_ConvexHull, true);

    //other cool features
    double compactness          = (PI_4_0 * area) / (perimeter * perimeter);
    double compactness_inv      = 1.0 / compactness;
    double solidity             = area / cvxHull_Area;
    double solidity_inv         = 1 / solidity;
    double equivalent_diameter  = sqrt((4 * area)/(PI));
    double equivalent_radius    = equivalent_diameter / 2.0;
    double equivalent_area      = PI * equivalent_radius * equivalent_radius;
    double equivalent_perimeter = PI * equivalent_diameter;
    double major_axis           = fitEll_major_semiaxis * 2;    //?
    double minor_axis           = fitEll_minor_semiaxis * 2;    //?
    double elongation_rect      = bndBox_Rect_side_short / bndBox_Rect_side_long;
    double elongation_rot       = bndBox_Rot_side_short / bndBox_Rot_side_long;
    double elongation_rect_inv  = 1 / elongation_rect;
    double elongation_rot_inv   = 1 / elongation_rot;
    double eccentricity         = fitEll_minor_semiaxis / fitEll_major_semiaxis;
    double eccentricity_inv     = 1 / eccentricity;
    double roundness            = (PI_4_0 * area) / (cvxHull_Perimeter * cvxHull_Perimeter);
    double roundness_inv        = 1 / roundness;
    double sphericity           = inscriCirc_Radius / circumCirc_Radius;
    double sphericity_inv       = 1 / sphericity;
    double convexity            = cvxHull_Perimeter / perimeter;
    double convexity_inv        = 1 / convexity;
    //double feret_min          = //to be done
    double fibre_length         = (perimeter - sqrt((perimeter * perimeter) - (16 * area))) / (4);
    double fibre_width          = area / fibre_length;
    double curl                 = bndBox_Rot_side_long / fibre_length;
    double curl_inv             = 1 / curl;
    double rectangularity       = area / bndBox_Rot_area;
    double rectangularity_inv   = 1 / rectangularity;
    double direction            = 0.5 * atan((2 * mu11) / (mu20 - mu02));
    double equivalent_volume_sph= (4.0/3.0) * PI * equivalent_radius * equivalent_radius * equivalent_radius;










    //EXPORT----------------------------------------

    vd_Features[c_FEAT_LABEL]                   = i_Number;

    vd_Features[c_FEAT_COUNT_PIXEL]             = px_coordinates;
    vd_Features[c_FEAT_AREA]                    = area;

    vd_Features[c_FEAT_COUNT_CONTOUR]           = px_contour;
    vd_Features[c_FEAT_PERIMETER]               = perimeter;

    vd_Features[c_FEAT_HOLES]                   = i_Holes;

    vd_Features[c_FEAT_MOMENT_SPATIAL_m00]      = m00;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m10]      = m10;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m01]      = m01;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m20]      = m20;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m11]      = m11;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m02]      = m02;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m30]      = m30;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m21]      = m21;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m12]      = m12;
    vd_Features[c_FEAT_MOMENT_SPATIAL_m03]      = m03;

    vd_Features[c_FEAT_MOMENT_CENTRAL_mu20]     = mu20;
    vd_Features[c_FEAT_MOMENT_CENTRAL_mu11]     = mu11;
    vd_Features[c_FEAT_MOMENT_CENTRAL_mu02]     = mu02;
    vd_Features[c_FEAT_MOMENT_CENTRAL_mu30]     = mu30;
    vd_Features[c_FEAT_MOMENT_CENTRAL_mu21]     = mu21;
    vd_Features[c_FEAT_MOMENT_CENTRAL_mu12]     = mu12;
    vd_Features[c_FEAT_MOMENT_CENTRAL_mu03]     = mu03;

    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu20]= nu20;
    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu11]= nu11;
    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu02]= nu02;
    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu30]= nu30;
    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu21]= nu21;
    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu12]= nu12;
    vd_Features[c_FEAT_MOMENT_CENTRAL_NORM_nu03]= nu03;

    vd_Features[c_FEAT_MOMENT_INVARIANT_hu0]    = hu0;
    vd_Features[c_FEAT_MOMENT_INVARIANT_hu1]    = hu1;
    vd_Features[c_FEAT_MOMENT_INVARIANT_hu2]    = hu2;
    vd_Features[c_FEAT_MOMENT_INVARIANT_hu3]    = hu3;
    vd_Features[c_FEAT_MOMENT_INVARIANT_hu4]    = hu4;
    vd_Features[c_FEAT_MOMENT_INVARIANT_hu5]    = hu5;
    vd_Features[c_FEAT_MOMENT_INVARIANT_hu6]    = hu6;

    vd_Features[c_FEAT_RECT_AXEPAR_LEFT]        = bndBox_Rect_left;
    vd_Features[c_FEAT_RECT_AXEPAR_RIGHT]       = bndBox_Rect_right;
    vd_Features[c_FEAT_RECT_AXEPAR_TOP]         = bndBox_Rect_top;
    vd_Features[c_FEAT_RECT_AXEPAR_BOTTOM]      = bndBox_Rect_bottom;
    vd_Features[c_FEAT_RECT_AXEPAR_WIDTH]       = bndBox_Rect_width;
    vd_Features[c_FEAT_RECT_AXEPAR_HEIGHT]      = bndBox_Rect_height;
    vd_Features[c_FEAT_RECT_AXEPAR_AREA]        = bndBox_Rect_area;
    vd_Features[c_FEAT_RECT_AXEPAR_ASPECT_RATIO]    = bndBox_Rect_aspect_r;
    vd_Features[c_FEAT_RECT_AXEPAR_ASPECT_RATIO_INV]=bndBox_Rect_aspect_r_inv;
    vd_Features[c_FEAT_RECT_AXEPAR_CENTER_X]    = bndBox_Rect_center_x;
    vd_Features[c_FEAT_RECT_AXEPAR_CENTER_Y]    = bndBox_Rect_center_y;
    vd_Features[c_FEAT_RECT_AXEPAR_PERIMETER]   = bndBox_Rect_perimeter;
    vd_Features[c_FEAT_RECT_AXEPAR_SIDE_SHORT]  = bndBox_Rect_side_short;
    vd_Features[c_FEAT_RECT_AXEPAR_SIDE_LONG]   = bndBox_Rect_side_long;

    vd_Features[c_FEAT_RECT_ROTATE_CENTER_X]    = bndBox_Rot_center_x;
    vd_Features[c_FEAT_RECT_ROTATE_CENTER_Y]    = bndBox_Rot_center_y;
    vd_Features[c_FEAT_RECT_ROTATE_WIDTH]       = bndBox_Rot_width;
    vd_Features[c_FEAT_RECT_ROTATE_HEIGHT]      = bndBox_Rot_height;
    vd_Features[c_FEAT_RECT_ROTATE_SIDE_SHORT]  =bndBox_Rot_side_short;
    vd_Features[c_FEAT_RECT_ROTATE_SIDE_LONG]   = bndBox_Rot_side_long;
    vd_Features[c_FEAT_RECT_ROTATE_AREA]        = bndBox_Rot_area;
    vd_Features[c_FEAT_RECT_ROTATE_PERIMETER]   = bndBox_Rot_perimeter;
    vd_Features[c_FEAT_RECT_ROTATE_ANGLE]       = bndBox_Rot_angle;

    vd_Features[c_FEAT_CIRC_ENCLOSE_CENTER_X]   = encCirc_center_x;
    vd_Features[c_FEAT_CIRC_ENCLOSE_CENTER_Y]   = encCirc_center_y;
    vd_Features[c_FEAT_CIRC_ENCLOSE_RADIUS]     = encCirc_radius;
    vd_Features[c_FEAT_CIRC_ENCLOSE_DIAMETER]   = encCirc_diameter;
    vd_Features[c_FEAT_CIRC_ENCLOSE_AREA]       = encCirc_area;
    vd_Features[c_FEAT_CIRC_ENCLOSE_PERIMETER]  = encCirc_perimeter;

    vd_Features[c_FEAT_CIRC_INCLOSE_CENTER_X]   = inclosingCirc_Center_X;
    vd_Features[c_FEAT_CIRC_INCLOSE_CENTER_Y]   = inclosingCirc_Center_Y;
    vd_Features[c_FEAT_CIRC_INCLOSE_RADIUS]     = f_InclosingCircle_Radius;
    vd_Features[c_FEAT_CIRC_INCLOSE_DIAMETER]   = inclosingCirc_Diameter;
    vd_Features[c_FEAT_CIRC_INCLOSE_AREA]       = inclosingCirc_Area;
    vd_Features[c_FEAT_CIRC_INCLOSE_PERIMETER]  = inclosingCirc_Perimeter;

    vd_Features[c_FEAT_CIRC_INSCRIB_RADIUS]     = inscriCirc_Radius;
    vd_Features[c_FEAT_CIRC_INSCRIB_DIAMETER]   = inscriCirc_Diameter;
    vd_Features[c_FEAT_CIRC_INSCRIB_AREA]       = inscriCirc_Area;
    vd_Features[c_FEAT_CIRC_INSCRIB_PERIMETER]  = inscriCirc_Perimeter;

    vd_Features[c_FEAT_CIRC_CIRCUMS_RADIUS]     = circumCirc_Radius;
    vd_Features[c_FEAT_CIRC_CIRCUMS_DIAMETER]   = circumCirc_Diameter;
    vd_Features[c_FEAT_CIRC_CIRCUMS_AREA]       = circumCirc_Area;
    vd_Features[c_FEAT_CIRC_CIRCUMS_PERIMETER]  = circumCirc_Perimeter;

    vd_Features[c_FEAT_ELLIPSE_FIT_CENTER_X]    = fitEll_center_x;
    vd_Features[c_FEAT_ELLIPSE_FIT_CENTER_Y]    = fitEll_center_y;
    vd_Features[c_FEAT_ELLIPSE_FIT_MAJOR_AXIS]  = fitEll_major_semiaxis;
    vd_Features[c_FEAT_ELLIPSE_FIT_MINOR_AXIS]  = fitEll_minor_semiaxis;
    vd_Features[c_FEAT_ELLIPSE_FIT_ANGLE]       = fitEll_angle;
    vd_Features[c_FEAT_ELLIPSE_FIT_AREA]        = fitEll_area;
    vd_Features[c_FEAT_ELLIPSE_FIT_PERIMETER]   = fitELL_perimeter;

    vd_Features[c_FEAT_CONVEX_AREA]             = cvxHull_Area;
    vd_Features[c_FEAT_CONVEX_PERIMETER]        = cvxHull_Perimeter;

    vd_Features[c_FEAT_MASS_CENTER_X]           = mass_center_x;
    vd_Features[c_FEAT_MASS_CENTER_Y]           = mass_center_y;

    vd_Features[c_FEAT_COMPACTNESS]             = compactness;
    vd_Features[c_FEAT_COMPACTNESS_INV]         = compactness_inv;

    vd_Features[c_FEAT_SOLIDITY]                = solidity;
    vd_Features[c_FEAT_SOLIDITY_INV]            = solidity_inv;

    vd_Features[c_FEAT_CIRC_EQUIVAL_AREA]       = equivalent_area;
    vd_Features[c_FEAT_CIRC_EQUIVAL_PERIMETER]  = equivalent_perimeter;
    vd_Features[c_FEAT_CIRC_EQUIVAL_DIAMETER]   = equivalent_diameter;
    vd_Features[c_FEAT_CIRC_EQUIVAL_RADIUS]     = equivalent_radius;

    vd_Features[c_FEAT_MAJOR_AXIS]              = major_axis;
    vd_Features[c_FEAT_MINOR_AXIS]              = minor_axis;

    vd_Features[c_FEAT_ELONGATION_RECT]         = elongation_rect;
    vd_Features[c_FEAT_ELONGATION_RECT_INV]     = elongation_rect_inv;
    vd_Features[c_FEAT_ELONGATION_ROT]          = elongation_rot;
    vd_Features[c_FEAT_ELONGATION_ROT_INV]      = elongation_rot_inv;

    vd_Features[c_FEAT_EXCENTRICITY]            = eccentricity;
    vd_Features[c_FEAT_EXCENTRICITY_INV]        = eccentricity_inv;
    vd_Features[c_FEAT_ROUNDNESS]               = roundness;
    vd_Features[c_FEAT_ROUNDNESS_INV]           = roundness_inv;
    vd_Features[c_FEAT_SPHERICITY]              = sphericity;
    vd_Features[c_FEAT_SPHERICITY_INV]          = sphericity_inv;
    vd_Features[C_FEAT_CONVEXITY]               = convexity;
    vd_Features[c_FEAT_CONVEXITY_INV]           = convexity_inv;

    vd_Features[c_FEAT_FIBRE_LENGTH]            = fibre_length;
    vd_Features[c_FEAT_FIBRE_WIDTH]             = fibre_width;
    vd_Features[c_FEAT_CURL]                    = curl;
    vd_Features[c_FEAT_CURL_INV]                = curl_inv;

    vd_Features[c_FEAT_RECTANGULARITY]          = rectangularity;
    vd_Features[c_FEAT_RECTANGULARITY_INV]      = rectangularity_inv;

    vd_Features[c_FEAT_DIRECTION]               = direction;

    vd_Features[c_FEAT_DIST_CENTROID_2_CONTOUR] = dist_cent2cont;
    vd_Features[c_FEAT_SPHERE_EQUIV_VOL]        = equivalent_volume_sph;

    calced_features = true;
}



void D_Component::Need2Updated()
{
    calced_contour = false;
    calced_features = false;
    calced_mat = false;
}

