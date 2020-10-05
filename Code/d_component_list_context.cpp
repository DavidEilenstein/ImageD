/************************************
 *   added:     25.09.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_component_list_context.h"

D_Component_List_Context::D_Component_List_Context()
{

}

D_Component_List_Context::D_Component_List_Context(Mat *pMA_BinaryOrLabel, int connectivity)
{
    set_Mat(pMA_BinaryOrLabel, connectivity);
}

int D_Component_List_Context::set_Mat(Mat *pMA_BinaryOrLabel, int connectivity)
{
    int ER = CompList.set_Mat(pMA_BinaryOrLabel, connectivity); //triggers calculate all features of all compenents internaly
    if(ER == ER_okay)
    {
        CompList_Calced = true;
        CompCount = CompList.size();
    }

    return ER;
}

bool D_Component_List_Context::InDist_Comp2Comp(int c1, int pt_type1, int c2, int pt_type2, double dist_min, double dist_max)
{
    if(!CompList_Calced)
        return false;

    if(c1 < 0 || c1 >= CompCount)                           return false;
    if(c2 < 0 || c2 >= CompCount)                           return false;
    if(pt_type1 < 0 || pt_type1 >= c_COMPDIST_NUMBER_OF)    return false;
    if(pt_type1 < 0 || pt_type1 >= c_COMPDIST_NUMBER_OF)    return false;

    //how many thing to measure dist to are lines?
    bool type1_is_line = (pt_type1 == c_COMPDIST_CONTOUR) || (pt_type1 == c_COMPDIST_CONVEX_HULL);
    bool type2_is_line = (pt_type2 == c_COMPDIST_CONTOUR) || (pt_type2 == c_COMPDIST_CONVEX_HULL);
    int  line_count = static_cast<int>(type1_is_line) + static_cast<int>(type2_is_line);

    if(line_count == 0)
    {
        double dist = Dist_Comp2Comp(c1, pt_type1, c2, pt_type2);
        return (dist >= dist_min) && (dist <= dist_max);
    }
    else if(line_count == 1)
    {
        //which one is line?
        int c_fix = c1;
        int type_fix = pt_type1;
        int c_line = c2;
        int type_line = pt_type2;
        if(type1_is_line)
        {
            c_fix = c2;
            type_fix = pt_type2;
            c_line = c1;
            type_line = pt_type1;
        }

        //approximate with enclosing circle first for faster calculation
        double dist_approx_center   = Dist_Comp2Comp(c_fix, type_fix, c_line, c_COMPDIST_CENTER_CIRC_ENCLOSE);
        double dist_approx_radius   = CompList.get_Feature(c_line, c_FEAT_CIRC_ENCLOSE_RADIUS);
        double dist_approx_min      = dist_approx_center - dist_approx_radius;                      //anything closer would be outside the enclosing circle
        double dist_approx_max      = D_Math::Pythagoras(dist_approx_center, dist_approx_radius);   //anything farer  would shift the enclosing circle (extreme object: line of a half circle opened towards c_fix)

        //sure accept/decline?
        if(dist_min < dist_approx_min && dist_max > dist_approx_max)    return true;    //object must be in interval of interest
        else if(dist_max < dist_approx_min)                             return false;   //object must be too close
        else if(dist_min > dist_approx_max)                             return false;   //object must be too far
        else                                                                            //aproximation is not precise enough -> loop points
        {
            double dist = Dist_Comp2Comp(c_fix, type_fix, c_line, type_line);
            return (dist >= dist_min) && (dist <= dist_max);
        }
    }
    else if(line_count == 2)
    {
        //approximate with enclosing circle first for faster calculation
        double dist_approx_centers  = Dist_Comp2Comp(c1, c_COMPDIST_CENTER_CIRC_ENCLOSE, c2, c_COMPDIST_CENTER_CIRC_ENCLOSE);
        double dist_approx_radius_1 = CompList.get_Feature(c1, c_FEAT_CIRC_ENCLOSE_RADIUS);
        double dist_approx_radius_2 = CompList.get_Feature(c2, c_FEAT_CIRC_ENCLOSE_RADIUS);
        double dist_approx_min      = dist_approx_centers - dist_approx_radius_1 - dist_approx_radius_2;    //anything closer would be outside the enclosing circle
        double dist_approx_max      = dist_approx_centers + dist_approx_radius_1 + dist_approx_radius_2;    //bad approximation but i'm to stupid to solve the geometrics... -.- This aprox is pesimistic, so it works

        //sure accept/decline?
        if(dist_min < dist_approx_min && dist_max > dist_approx_max)    return true;    //object must be in interval of interest
        else if(dist_max < dist_approx_min)                             return false;   //object must be too close
        else if(dist_min > dist_approx_max)                             return false;   //object must be too far
        else                                                                            //aproximation is not precise enough -> loop points
        {
            double dist = Dist_Comp2Comp(c1, pt_type1, c2, pt_type2);
            return (dist >= dist_min) && (dist <= dist_max);
        }
    }

    return false;
}

vector<int> D_Component_List_Context::InDist_CompsIndices(int c1, int pt_type1, int pt_type2, double dist_min, double dist_max)
{
    vector<int> v_InDist;
    if(!CompList_Calced)
        return v_InDist;

    for(int c2 = 0; c2 < CompCount; c2++)
        if(c2 != c1)
            if(InDist_Comp2Comp(c1, pt_type1, c2, pt_type2, dist_min, dist_max))
                v_InDist.push_back(c2);

    return v_InDist;
}

vector<double> D_Component_List_Context::get_AllComps_StatFeatInDist(int type1, int type2, double dist_min, double dist_max, int feat, int stat)
{
    vector<double> vd_StatFeatPerComp;
    if(!CompList_Calced)
        return vd_StatFeatPerComp;
    vd_StatFeatPerComp.resize(CompCount);

    //stats function
    function<double (vector<double>)> f_stat = D_Stat::Function_SingleStat(stat);

    //loop comps
    for(int c1 = 0; c1 < CompCount; c1++)
    {
        //Comps of interest
        vector<int>         vCompsOfInterest     = InDist_CompsIndices(c1, type1, type2, dist_min, dist_max);
        size_t              n_interest           = vCompsOfInterest.size();

        //get feats
        vector<double>      vFeatsOfInterest(n_interest);
        for(int c2 = 0; c2 < n_interest; c2++)
            vFeatsOfInterest[c2] = CompList.get_Feature(vCompsOfInterest[c2], feat);

        //calc stat of them
        vd_StatFeatPerComp[c1] = f_stat(vFeatsOfInterest);
    }

    return vd_StatFeatPerComp;
}

vector<double> D_Component_List_Context::get_AllComps_StatFeatInDist_BG(int type1, int type2, double dist_min, double dist_max, int feat, int stat)
{
    vector<double> vd_StatFeatPerComp;
    if(!CompList_Calced)
        return vd_StatFeatPerComp;
    vd_StatFeatPerComp.resize(CompCount + 1, 0);

    //stats function
    function<double (vector<double>)> f_stat = D_Stat::Function_SingleStat(stat);

    //loop comps
    for(int c1 = 0; c1 < CompCount; c1++)
    {
        //Comps of interest
        vector<int>         vCompsOfInterest     = InDist_CompsIndices(c1, type1, type2, dist_min, dist_max);
        size_t              n_interest           = vCompsOfInterest.size();

        //get feats
        vector<double>      vFeatsOfInterest(n_interest);
        for(int c2 = 0; c2 < n_interest; c2++)
            vFeatsOfInterest[c2] = CompList.get_Feature(vCompsOfInterest[c2], feat);

        //calc stat of them
        vd_StatFeatPerComp[c1 + 1] = f_stat(vFeatsOfInterest);
    }

    return vd_StatFeatPerComp;
}

bool D_Component_List_Context::IsCouple_CompareFeats(int c1, int c2, int feat1, int feat2, function<bool (double, double)> comparison)
{
    if(!CompList_Calced)
        return false;

    return comparison(CompList.get_Feature(c1, feat1), CompList.get_Feature(c2, feat2));
}

vector<vector<Point>> D_Component_List_Context::get_PointCouples_Closest(int type1, int type2, double dist_min, double dist_max, int feat1, int feat2, function<bool (double, double)> comparison)
{
    //allocate
    vector<vector<Point>> vvPointsClosest;

    //error?
    if(!CompList_Calced)
        return vvPointsClosest;
    if(type1 < 0 || type1 >= c_COMPDIST_NUMBER_OF)    return vvPointsClosest;
    if(type1 < 0 || type1 >= c_COMPDIST_NUMBER_OF)    return vvPointsClosest;

    //vector to remember/pushback
    vector<Point> vPointCoupleClosest(2);

    //how many thing to measure dist to are lines?
    bool type1_is_line = (type1 == c_COMPDIST_CONTOUR) || (type1 == c_COMPDIST_CONVEX_HULL);
    bool type2_is_line = (type2 == c_COMPDIST_CONTOUR) || (type2 == c_COMPDIST_CONVEX_HULL);
    int  line_count = static_cast<int>(type1_is_line) + static_cast<int>(type2_is_line);

    //loop components
    for(int c1 = 0; c1 < CompList.size(); c1++)
        for(int c2 = 0; c2 < CompList.size(); c2++)
            if(c1 != c2)
            {
                //feature combination fits?
                if(comparison(CompList.get_Feature(c1, feat1), CompList.get_Feature(c2, feat2)))
                {
                    //in range?

                    if(line_count == 0)
                    {
                        vPointCoupleClosest[0] = Point_Comp(c1, type1);
                        vPointCoupleClosest[1] = Point_Comp(c2, type2);

                        double dist = D_Math::Distance(vPointCoupleClosest[0], vPointCoupleClosest[1]);
                        if((dist >= dist_min) && (dist <= dist_max))
                            vvPointsClosest.push_back(vPointCoupleClosest);
                    }
                    else if(line_count == 1)
                    {
                        //which one is line?
                        int c_fix = c1;
                        int type_fix = type1;
                        int c_line = c2;
                        int type_line = type2;
                        if(type1_is_line)
                        {
                            c_fix = c2;
                            type_fix = type2;
                            c_line = c1;
                            type_line = type1;
                        }

                        //approximate with enclosing circle first for faster calculation
                        double dist_approx_center   = Dist_Comp2Comp(c_fix, type_fix, c_line, c_COMPDIST_CENTER_CIRC_ENCLOSE);
                        double dist_approx_radius   = CompList.get_Feature(c_line, c_FEAT_CIRC_ENCLOSE_RADIUS);
                        double dist_approx_min      = dist_approx_center - dist_approx_radius;                      //anything closer would be outside the enclosing circle
                        double dist_approx_max      = D_Math::Pythagoras(dist_approx_center, dist_approx_radius);   //anything farer  would shift the enclosing circle (extreme object: line of a half circle opened towards c_fix)

                        //sure not in range?
                        if(!(dist_max < dist_approx_min))                               //object must be too close
                            if(!(dist_min > dist_approx_max))                           //object must be too far
                            {
                                //fix
                                Point Pt_fix = Point_Comp(c_fix, type_fix);

                                //line
                                vector<Point> ContourLine;
                                if(type_line == c_COMPDIST_CONTOUR)
                                    ContourLine = CompList.get_Component(c_line).get_Contour();
                                else
                                    ContourLine = CompList.get_Component(c_line).get_Contour_ConvexHull();
                                size_t n_px = ContourLine.size();

                                //find colseset
                                vector<Point> vPointCoupleCandidate(2);
                                vector<vector<Point>> vvPointsInRange_Candidates;
                                double dist_closest = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                                for(size_t px = 0; px < n_px; px++)
                                {
                                    double dist = D_Math::Distance(Pt_fix, ContourLine[px]);

                                    //new closest? -> clear old ones
                                    if((dist >= dist_min) && (dist <= dist_max) && (dist < dist_closest))
                                    {
                                        dist_closest = dist;
                                        vvPointsInRange_Candidates.clear();
                                    }

                                    //candidate?
                                    if((dist >= dist_min) && (dist <= dist_max) && (dist <= dist_closest))
                                    {
                                        vPointCoupleCandidate[0] = Pt_fix;
                                        vPointCoupleCandidate[1] = ContourLine[px];
                                        vvPointsInRange_Candidates.push_back(vPointCoupleCandidate);
                                    }
                                }

                                //closest dist in range? -> add candidates to output
                                if((dist_closest >= dist_min) && (dist_closest <= dist_max))
                                    for(int i = 0; i < vvPointsInRange_Candidates.size(); i++)
                                        vvPointsClosest.push_back(vvPointsInRange_Candidates[i]);


                                /*
                                //find closest (only one of possible multiple closetst dists)
                                double dist_closest = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                                for(size_t px = 0; px < n_px; px++)
                                {
                                    double dist = D_Math::Distance(Pt_fix, ContourLine[px]);
                                    if(dist < dist_closest)
                                    {
                                        dist_closest = dist;
                                        vPointCoupleClosest[0] = Pt_fix;
                                        vPointCoupleClosest[1] = ContourLine[px];
                                    }
                                }

                                //in range?
                                if((dist_closest >= dist_min) && (dist_closest <= dist_max))
                                    vvPointsClosest.push_back(vPointCoupleClosest);
                                    */
                            }
                    }
                    else if(line_count == 2)
                    {
                        //approximate with enclosing circle first for faster calculation
                        double dist_approx_centers  = Dist_Comp2Comp(c1, c_COMPDIST_CENTER_CIRC_ENCLOSE, c2, c_COMPDIST_CENTER_CIRC_ENCLOSE);
                        double dist_approx_radius_1 = CompList.get_Feature(c1, c_FEAT_CIRC_ENCLOSE_RADIUS);
                        double dist_approx_radius_2 = CompList.get_Feature(c2, c_FEAT_CIRC_ENCLOSE_RADIUS);
                        double dist_approx_min      = dist_approx_centers - dist_approx_radius_1 - dist_approx_radius_2;    //anything closer would be outside the enclosing circle
                        double dist_approx_max      = dist_approx_centers + dist_approx_radius_1 + dist_approx_radius_2;    //bad approximation but i'm to stupid to solve the geometrics... -.- This aprox is pesimistic, so it works

                        //sure not in range?
                        if(!(dist_max < dist_approx_min))                               //object must be too close
                            if(!(dist_min > dist_approx_max))                           //object must be too far
                            {
                                //line1
                                vector<Point> ContourLine1;
                                if(type1 == c_COMPDIST_CONTOUR)
                                    ContourLine1 = CompList.get_Component(c1).get_Contour();
                                else
                                    ContourLine1 = CompList.get_Component(c1).get_Contour_ConvexHull();
                                size_t n_px1 = ContourLine1.size();

                                //line2
                                vector<Point> ContourLine2;
                                if(type2 == c_COMPDIST_CONTOUR)
                                    ContourLine2 = CompList.get_Component(c2).get_Contour();
                                else
                                    ContourLine2 = CompList.get_Component(c2).get_Contour_ConvexHull();
                                size_t n_px2 = ContourLine2.size();

                                //find colseset
                                vector<Point> vPointCoupleCandidate(2);
                                vector<vector<Point>> vvPointsInRange_Candidates;
                                double dist_closest = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                                for(size_t px1 = 0; px1 < n_px1; px1++)
                                    for(size_t px2 = 0; px2 < n_px2; px2++)
                                    {
                                        double dist = D_Math::Distance(ContourLine1[px1], ContourLine2[px2]);

                                        //new closest? -> clear old ones
                                        if((dist >= dist_min) && (dist <= dist_max) && (dist < dist_closest))
                                        {
                                            dist_closest = dist;
                                            vvPointsInRange_Candidates.clear();
                                        }

                                        //candidate?
                                        if((dist >= dist_min) && (dist <= dist_max) && (dist <= dist_closest))
                                        {
                                            vPointCoupleCandidate[0] = ContourLine1[px1];
                                            vPointCoupleCandidate[1] = ContourLine2[px2];
                                            vvPointsInRange_Candidates.push_back(vPointCoupleCandidate);
                                        }
                                    }

                                //closest dist in range? -> add candidates to output
                                if((dist_closest >= dist_min) && (dist_closest <= dist_max))
                                    for(int i = 0; i < vvPointsInRange_Candidates.size(); i++)
                                        vvPointsClosest.push_back(vvPointsInRange_Candidates[i]);

                                /*
                                //find closest (only one of possible multiple closetst dists)
                                double dist_closest = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                                for(size_t px1 = 0; px1 < n_px1; px1++)
                                    for(size_t px2 = 0; px2 < n_px2; px2++)
                                    {
                                        double dist = D_Math::Distance(ContourLine1[px1], ContourLine2[px2]);
                                        if(dist < dist_closest)
                                        {
                                            dist_closest = dist;
                                            vPointCoupleClosest[0] = ContourLine1[px1];
                                            vPointCoupleClosest[1] = ContourLine2[px2];
                                        }
                                    }

                                //in range?
                                if((dist_closest >= dist_min) && (dist_closest <= dist_max))
                                    vvPointsClosest.push_back(vPointCoupleClosest);
                                    */
                            }
                    }
                }
            }

    return vvPointsClosest;
}

vector<vector<Point> > D_Component_List_Context::get_PointCouples_AllInRange(int type1, int type2, double dist_min, double dist_max, int feat1, int feat2, function<bool (double, double)> comparison)
{
    //allocate
    vector<vector<Point>> vvPointsInRange;

    //error?
    if(!CompList_Calced)
        return vvPointsInRange;
    if(type1 < 0 || type1 >= c_COMPDIST_NUMBER_OF)    return vvPointsInRange;
    if(type1 < 0 || type1 >= c_COMPDIST_NUMBER_OF)    return vvPointsInRange;

    //vector to remember/pushback
    vector<Point> vPointCoupleClosest(2);

    //how many thing to measure dist to are lines?
    bool type1_is_line = (type1 == c_COMPDIST_CONTOUR) || (type1 == c_COMPDIST_CONVEX_HULL);
    bool type2_is_line = (type2 == c_COMPDIST_CONTOUR) || (type2 == c_COMPDIST_CONVEX_HULL);
    int  line_count = static_cast<int>(type1_is_line) + static_cast<int>(type2_is_line);

    //loop components
    for(int c1 = 0; c1 < CompList.size(); c1++)
        for(int c2 = 0; c2 < CompList.size(); c2++)
            if(c1 != c2)
            {
                //feature combination fits?
                if(comparison(CompList.get_Feature(c1, feat1), CompList.get_Feature(c2, feat2)))
                {
                    //in range?

                    if(line_count == 0)
                    {
                        vPointCoupleClosest[0] = Point_Comp(c1, type1);
                        vPointCoupleClosest[1] = Point_Comp(c2, type2);

                        double dist = D_Math::Distance(vPointCoupleClosest[0], vPointCoupleClosest[1]);
                        if((dist >= dist_min) && (dist <= dist_max))
                            vvPointsInRange.push_back(vPointCoupleClosest);
                    }
                    else if(line_count == 1)
                    {
                        //which one is line?
                        int c_fix = c1;
                        int type_fix = type1;
                        int c_line = c2;
                        int type_line = type2;
                        if(type1_is_line)
                        {
                            c_fix = c2;
                            type_fix = type2;
                            c_line = c1;
                            type_line = type1;
                        }

                        //approximate with enclosing circle first for faster calculation
                        double dist_approx_center   = Dist_Comp2Comp(c_fix, type_fix, c_line, c_COMPDIST_CENTER_CIRC_ENCLOSE);
                        double dist_approx_radius   = CompList.get_Feature(c_line, c_FEAT_CIRC_ENCLOSE_RADIUS);
                        double dist_approx_min      = dist_approx_center - dist_approx_radius;                      //anything closer would be outside the enclosing circle
                        double dist_approx_max      = D_Math::Pythagoras(dist_approx_center, dist_approx_radius);   //anything farer  would shift the enclosing circle (extreme object: line of a half circle opened towards c_fix)

                        //sure not in range?
                        if(!(dist_max < dist_approx_min))                               //object must be too close
                            if(!(dist_min > dist_approx_max))                           //object must be too far
                            {
                                //fix
                                Point Pt_fix = Point_Comp(c_fix, type_fix);

                                //line
                                vector<Point> ContourLine;
                                if(type_line == c_COMPDIST_CONTOUR)
                                    ContourLine = CompList.get_Component(c_line).get_Contour();
                                else
                                    ContourLine = CompList.get_Component(c_line).get_Contour_ConvexHull();
                                size_t n_px = ContourLine.size();

                                //find closest & save in range points
                                vector<Point> vPointCoupleCandidate(2);
                                vector<vector<Point>> vvPointsInRange_Candidates;
                                double dist_closest = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                                for(size_t px = 0; px < n_px; px++)
                                {
                                    double dist = D_Math::Distance(Pt_fix, ContourLine[px]);

                                    //candidate?
                                    if((dist >= dist_min) && (dist <= dist_max))
                                    {
                                        vPointCoupleCandidate[0] = Pt_fix;
                                        vPointCoupleCandidate[1] = ContourLine[px];
                                        vvPointsInRange_Candidates.push_back(vPointCoupleCandidate);
                                    }

                                    //new closest?
                                    if(dist < dist_closest)
                                    {
                                        dist_closest = dist;
                                        vPointCoupleClosest[0] = Pt_fix;
                                        vPointCoupleClosest[1] = ContourLine[px];
                                    }
                                }

                                //closest dist in range? -> add candidates to output
                                if((dist_closest >= dist_min) && (dist_closest <= dist_max))
                                    for(int i = 0; i < vvPointsInRange_Candidates.size(); i++)
                                        vvPointsInRange.push_back(vvPointsInRange_Candidates[i]);
                            }
                    }
                    else if(line_count == 2)
                    {
                        //approximate with enclosing circle first for faster calculation
                        double dist_approx_centers  = Dist_Comp2Comp(c1, c_COMPDIST_CENTER_CIRC_ENCLOSE, c2, c_COMPDIST_CENTER_CIRC_ENCLOSE);
                        double dist_approx_radius_1 = CompList.get_Feature(c1, c_FEAT_CIRC_ENCLOSE_RADIUS);
                        double dist_approx_radius_2 = CompList.get_Feature(c2, c_FEAT_CIRC_ENCLOSE_RADIUS);
                        double dist_approx_min      = dist_approx_centers - dist_approx_radius_1 - dist_approx_radius_2;    //anything closer would be outside the enclosing circle
                        double dist_approx_max      = dist_approx_centers + dist_approx_radius_1 + dist_approx_radius_2;    //bad approximation but i'm to stupid to solve the geometrics... -.- This aprox is pesimistic, so it works

                        //sure not in range?
                        if(!(dist_max < dist_approx_min))                               //object must be too close
                            if(!(dist_min > dist_approx_max))                           //object must be too far
                            {
                                //line1
                                vector<Point> ContourLine1;
                                if(type1 == c_COMPDIST_CONTOUR)
                                    ContourLine1 = CompList.get_Component(c1).get_Contour();
                                else
                                    ContourLine1 = CompList.get_Component(c1).get_Contour_ConvexHull();
                                size_t n_px1 = ContourLine1.size();

                                //line2
                                vector<Point> ContourLine2;
                                if(type2 == c_COMPDIST_CONTOUR)
                                    ContourLine2 = CompList.get_Component(c2).get_Contour();
                                else
                                    ContourLine2 = CompList.get_Component(c2).get_Contour_ConvexHull();
                                size_t n_px2 = ContourLine2.size();

                                //find closest & save in range points
                                vector<Point> vPointCoupleCandidate(2);
                                vector<vector<Point>> vvPointsInRange_Candidates;
                                double dist_closest = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                                for(size_t px1 = 0; px1 < n_px1; px1++)
                                    for(size_t px2 = 0; px2 < n_px2; px2++)
                                    {
                                        double dist = D_Math::Distance(ContourLine1[px1], ContourLine2[px2]);

                                        //candidate?
                                        if((dist >= dist_min) && (dist <= dist_max))
                                        {
                                            vPointCoupleCandidate[0] = ContourLine1[px1];
                                            vPointCoupleCandidate[1] = ContourLine2[px2];
                                            vvPointsInRange_Candidates.push_back(vPointCoupleCandidate);
                                        }

                                        //new closest?
                                        if(dist < dist_closest)
                                        {
                                            dist_closest = dist;
                                            vPointCoupleClosest[0] = ContourLine1[px1];
                                            vPointCoupleClosest[1] = ContourLine2[px2];
                                        }
                                    }

                                //closest dist in range? -> add candidates to output
                                if((dist_closest >= dist_min) && (dist_closest <= dist_max))
                                    for(int i = 0; i < vvPointsInRange_Candidates.size(); i++)
                                        vvPointsInRange.push_back(vvPointsInRange_Candidates[i]);
                            }
                    }
                }
            }

    return vvPointsInRange;
}

Point D_Component_List_Context::Point_Comp(int c, int type)
{
    Point2f Ptf = Point2f_Comp(c, type);
    return Point(
                static_cast<int>(Ptf.x),
                static_cast<int>(Ptf.y));
}

Point2f D_Component_List_Context::Point2f_Comp(int c, int type)
{
    float x = INFINITY;
    float y = INFINITY;

    if(c < 0 || c >= CompCount)                     return Point2f(x, y);
    if(type < 0 || type >= c_COMPDIST_NUMBER_OF)    return Point2f(x, y);
    if(type == c_COMPDIST_CONTOUR)                  return Point2f(x, y);
    if(type == c_COMPDIST_CONVEX_HULL)              return Point2f(x, y);

    switch (type) {

    case c_COMPDIST_OFFSET:
        x = CompList.get_Offset(c).x;
        y = CompList.get_Offset(c).y;
        break;

    case c_COMPDIST_CENTER_MASS:
        x = CompList.get_Centroid(c).x;
        y = CompList.get_Centroid(c).y;
        break;

    case c_COMPDIST_CENTER_RECT_AXEPAR:
        x = CompList.get_Feature(c, c_FEAT_RECT_AXEPAR_CENTER_X);
        y = CompList.get_Feature(c, c_FEAT_RECT_AXEPAR_CENTER_Y);
        break;

    case c_COMPDIST_CENTER_RECT_ROTATE:
        x = CompList.get_Feature(c, c_FEAT_RECT_ROTATE_CENTER_X);
        y = CompList.get_Feature(c, c_FEAT_RECT_ROTATE_CENTER_Y);
        break;

    case c_COMPDIST_CENTER_CIRC_INCLOSE:
        x = CompList.get_Feature(c, c_FEAT_CIRC_INCLOSE_CENTER_X);
        y = CompList.get_Feature(c, c_FEAT_CIRC_INCLOSE_CENTER_Y);
        break;

    case c_COMPDIST_CENTER_CIRC_ENCLOSE:
        x = CompList.get_Feature(c, c_FEAT_CIRC_ENCLOSE_CENTER_X);
        y = CompList.get_Feature(c, c_FEAT_CIRC_ENCLOSE_CENTER_Y);
        break;

    case c_COMPDIST_CENTER_ELLIPSE_FIT:
        x = CompList.get_Feature(c, c_FEAT_ELLIPSE_FIT_CENTER_X);
        y = CompList.get_Feature(c, c_FEAT_ELLIPSE_FIT_CENTER_Y);
        break;

    default:
        break;
    }

    return Point2f(x, y);
}

double D_Component_List_Context::Dist_Comp2Comp(int c1, int type1, int c2, int type2)
{
    if(c1 < 0 || c1 >= CompCount)                   return INFINITY;
    if(c2 < 0 || c2 >= CompCount)                   return INFINITY;
    if(type1 < 0 || type1 >= c_COMPDIST_NUMBER_OF)  return INFINITY;
    if(type1 < 0 || type1 >= c_COMPDIST_NUMBER_OF)  return INFINITY;

    bool type1_line = (type1 == c_COMPDIST_CONTOUR) || (type1 == c_COMPDIST_CONVEX_HULL);
    bool type2_line = (type2 == c_COMPDIST_CONTOUR) || (type2 == c_COMPDIST_CONVEX_HULL);
    int  line_count = static_cast<int>(type1_line) + static_cast<int>(type2_line);

    if(line_count == 0)
    {
        return D_Math::Distance(
                    Point2f_Comp(c1, type1),
                    Point2f_Comp(c2, type2));
    }
    else if(line_count == 1)
    {
        //which one is line?
        int c_fix = c1;
        int type_fix = type1;
        int c_line = c2;
        int type_line = type2;
        if(type1_line)
        {
            c_fix = c2;
            type_fix = type2;
            c_line = c1;
            type_line = type1;
        }

        //fix
        Point2f Pt_fix = Point2f_Comp(c_fix, type_fix);

        //line
        vector<Point> ContourLine;
        if(type_line == c_COMPDIST_CONTOUR)
            ContourLine = CompList.get_Component(c_line).get_Contour();
        else
            ContourLine = CompList.get_Component(c_line).get_Contour_ConvexHull();
        size_t n_px = ContourLine.size();

        //optimize
        double dist_min = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
        for(size_t px = 0; px < n_px; px++)
            D_Stat::Optimize(
                        D_Math::Distance(
                            Pt_fix,
                            ContourLine[px]),
                        &dist_min,
                        c_OPT_1D_MINIMUM);

        //result
        return dist_min;
    }
    else if(line_count == 2)
    {
        //line1
        vector<Point> ContourLine1;
        if(type1 == c_COMPDIST_CONTOUR)
            ContourLine1 = CompList.get_Component(c1).get_Contour();
        else
            ContourLine1 = CompList.get_Component(c1).get_Contour_ConvexHull();
        size_t n_px1 = ContourLine1.size();

        //line2
        vector<Point> ContourLine2;
        if(type2 == c_COMPDIST_CONTOUR)
            ContourLine2 = CompList.get_Component(c2).get_Contour();
        else
            ContourLine2 = CompList.get_Component(c2).get_Contour_ConvexHull();
        size_t n_px2 = ContourLine2.size();

        //optimize
        double dist_min = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
        for(size_t px1 = 0; px1 < n_px1; px1++)
            for(size_t px2 = 0; px2 < n_px2; px2++)
                D_Stat::Optimize(
                            D_Math::Distance(
                                ContourLine1[px1],
                                ContourLine2[px2]),
                            &dist_min,
                            c_OPT_1D_MINIMUM);

        //result
        return dist_min;
    }

    return INFINITY;
}
