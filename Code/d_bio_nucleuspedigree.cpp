/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleuspedigree.h"

D_Bio_NucleusPedigree::D_Bio_NucleusPedigree()
{
    //init score weights
    vScoreWeights.resize(SCORE_NUMBER_OF, 0);
    vScoreWeights[SCORE_SHIFT] = 1;
}

void D_Bio_NucleusPedigree::clear()
{
    size_time = 0;
    vvNucBlobs_T.clear();
}

void D_Bio_NucleusPedigree::set_size_time(size_t t_size)
{
    clear();

    size_time = t_size;
    vvNucBlobs_T.resize(size_time);
}

bool D_Bio_NucleusPedigree::add_nucleus_blob(size_t t, D_Bio_NucleusBlob nuc)
{
    if(!state_ScoreWeightsAndMaxSet)
        return false;

    if(t < vvNucBlobs_T.size())
    {
        //set time
        nuc.set_time(t);

        //set matching params
        nuc.matching_InitMatching(
                    vScoreWeights,
                    vScoreMaxima,
                    match_thresh_max_shift,
                    match_thresh_max_area_increase_to,
                    match_thresh_max_area_decrease_to);

        //add nucleus to stack of nuclei to be matched
        vvNucBlobs_T[t].push_back(nuc);
        return true;
    }
    else
    {
        return false;
    }
}

void D_Bio_NucleusPedigree::initMatching()
{
    vScoreWeights.resize(SCORE_NUMBER_OF, 0);
    vScoreWeights[SCORE_SHIFT] = 1;

    vScoreMaxima.resize(SCORE_NUMBER_OF, 1);

    match_thresh_max_area_increase_to = 1.25;
    match_thresh_max_area_decrease_to = 0.35;
    match_thresh_max_shift = 1500;

    state_ScoreWeightsAndMaxSet = true;
}

bool D_Bio_NucleusPedigree::initMatching(vector<double> score_weights, vector<double> score_maxima, double shift_limit, double max_rel_area_inc_to, double max_rel_area_dec_to, double max_age, double thres_tm1_go1, double thres_tm2_go1, double thres_tm1_go2, double thres_tm2_go2)
{
    if((score_weights.size() != SCORE_NUMBER_OF) || (score_maxima.size() != SCORE_NUMBER_OF))
        return false;

    double weight_sum = 0;
    for(size_t i = 0; i < score_weights.size(); i++)
        weight_sum += score_weights[i];

    if(weight_sum <= 0.0)
        return false;

    for(size_t i = 0; i < score_maxima.size(); i++)
        if(score_maxima[i] <= 0.0)
            return false;

    initMatching();

    vScoreWeights.resize(SCORE_NUMBER_OF, 0);
    vScoreMaxima.resize(SCORE_NUMBER_OF, 1);
    for(size_t i = 0; i < score_weights.size(); i++)
    {
        vScoreWeights[i] = score_weights[i] / weight_sum;
        vScoreMaxima[i] = score_maxima[i];
    }

    match_thresh_max_area_increase_to   = max_rel_area_inc_to;
    match_thresh_max_area_decrease_to   = max_rel_area_dec_to;
    match_thresh_max_shift              = shift_limit;
    match_max_age                       = max_age;
    match_score_thres_tm1_go1           = thres_tm1_go1;
    match_score_thres_tm2_go1           = thres_tm2_go2;
    match_score_thres_tm1_go2           = thres_tm1_go2;
    match_score_thres_tm2_go2           = thres_tm2_go2;

    return true;
}

int D_Bio_NucleusPedigree::setPedigreePlotViewer(D_Viewer_Plot_3D *viewer)
{
    if(!viewer)
        return ER_UiNotInit;

    pViewerPedigreePlot = viewer;
    state_PlotViewerSet = true;

    return ER_okay;
}

int D_Bio_NucleusPedigree::updatePedigreePlot(size_t points_per_edge)
{
    if(!state_PlotViewerSet)
        return ER_UiNotInit;

    //cosmetic params
    size_t          shadow = c_VIEWER_PLOT_3D_SHADOW_NONE;
    bool            background = false;
    bool            grid = true;
    bool            smooth = false;
    QString         axis_x = "X/um";
    QString         axis_y = "Y/um";
    QString         axis_z = "T/h";

    //node data
    vector<Point3d> vNodesCoord;
    vector<QColor>  vNodeColor;
    QStringList     QSL_NodeNames;

    //edge data
    vector<Point3d> vEdgeCoordBegins;
    vector<Point3d> vEdgeCoordEnds;
    vector<QColor>  vEdgeColor;
    QStringList     QSL_EdgeNames;

    //score norming
    double score_min = min(match_score_thres_tm1_go2, match_score_thres_tm2_go2);
    double score_range = 1 - score_min;

    for(size_t t = 0; t < vvNucBlobs_T.size(); t++)
    {
        //qDebug() << t << "--------------------------------------------------------------------------";
        for(size_t i = 0; i < vvNucBlobs_T[t].size(); i++)
        {
            //qDebug() << i;

            //add node coord
            Point3d P_NucCoord = Point3d(
                        float(vvNucBlobs_T[t][i].centroid().x * scale_px_to_um),
                        float(vvNucBlobs_T[t][i].centroid().y * scale_px_to_um),
                        float(vvNucBlobs_T[t][i].time()       * scale_t_to_h));
            vNodesCoord.push_back(P_NucCoord);

            //add node color
            vNodeColor.push_back(vvNucBlobs_T[t][i].matching_TypeColor(FrameInRegularRangeXY, 0, vvNucBlobs_T.size() - 1));

            //add node name
            QSL_NodeNames.append(
                        "A=" + QString::number(vvNucBlobs_T[t][i].area() * scale_px_to_um * scale_px_to_um) + "um^2\n"
                        "age=" + QString::number(vvNucBlobs_T[t][i].matching_Age() * scale_t_to_h) + "h");

            //get Ancestor and calc edge
            if(vvNucBlobs_T[t][i].matching_foundParent())
            {
                //position of ancestor
                Point3d P_AncestorCoord = Point3d(
                            float(vvNucBlobs_T[t][i].matching_Parent()->centroid().x * scale_px_to_um),
                            float(vvNucBlobs_T[t][i].matching_Parent()->centroid().y * scale_px_to_um),
                            float(vvNucBlobs_T[t][i].matching_Parent()->time() * scale_t_to_h));

                //match score to ancestor
                double score = vvNucBlobs_T[t][i].matching_Score_Parent();
                score = max(0.0, min(score, 1.0));
                double score_rel = (score - score_min) / score_range;

                //age of nuc
                double age = vvNucBlobs_T[t][i].matching_Age();
                age = max(0.0, min(age, match_max_age));
                double age_rel = match_max_age > 0 ? age / match_max_age : 0;

                //calc color
                QColor EdgeColor;
                EdgeColor.setHsv(
                            int(240.0 * (1.0 - score_rel)),
                            255,
                            255);
                EdgeColor = EdgeColor.toRgb();

                //add edge
                vEdgeCoordBegins.push_back(P_AncestorCoord);
                vEdgeCoordEnds.push_back(P_NucCoord);
                vEdgeColor.push_back(EdgeColor);
                QSL_EdgeNames.append("Score=" + QString::number(int(score * 100)) + "%");

                //qDebug() << "Nuc at" << P_NucCoord.x << P_NucCoord.y << P_NucCoord.z << "with parent at" << P_AncestorCoord.x << P_AncestorCoord.y << P_AncestorCoord.z << "(score" << score << ")";
            }
            else
            {
                //qDebug() << "Nuc at" << P_NucCoord.x << P_NucCoord.y << P_NucCoord.z << "with no parent" << "(highest parent score" << vvNucBlobs_T[t][i].matching_Score_Parent() << ")";
            }
        }
    }

    return pViewerPedigreePlot->plot_Tree(
                vNodesCoord,
                vEdgeCoordBegins,
                vEdgeCoordEnds,
                vNodeColor,
                vEdgeColor,
                shadow,
                background,
                grid,
                smooth,
                axis_x,
                axis_y,
                axis_z,
                points_per_edge,
                scale_nodes,
                scale_edges);
}

int D_Bio_NucleusPedigree::updatePedigreePlot(D_Viewer_Plot_3D *viewer, size_t points_per_edge)
{
    int err = setPedigreePlotViewer(viewer);
    if(err != ER_okay)
        return err;

    return updatePedigreePlot(points_per_edge);
}

void D_Bio_NucleusPedigree::match_all()
{
    match_all_go1();
    match_all_go2();
}

void D_Bio_NucleusPedigree::match_all_go1()
{
    for(size_t t = 0; t < vvNucBlobs_T.size(); t++)
        match_time_go1(t);
}

void D_Bio_NucleusPedigree::match_all_go2()
{
    for(size_t t = 0; t < vvNucBlobs_T.size(); t++)
        match_time_go2(t);
}

void D_Bio_NucleusPedigree::match_time_go1(size_t t)
{
    match_times(t - 1, t, match_score_thres_tm1_go1, true);
    match_times(t - 2, t, match_score_thres_tm2_go1, false);
}

void D_Bio_NucleusPedigree::match_time_go2(size_t t)
{
    match_times(t - 1, t, match_score_thres_tm1_go2, true);
    match_times(t - 2, t, match_score_thres_tm2_go2, false);
}

void D_Bio_NucleusPedigree::match_time_tm1_tm2_mixed(size_t t)
{
    if(t >= vvNucBlobs_T.size())
        return;

    //score table as point list (for easy sorting)
    vector<vector<double>> vScores_parent_child_score;

    //find matches t-1
    if(t > 0)
        match_find_matches(
                    &vScores_parent_child_score,
                    t - 1,
                    t,
                    match_score_thres_tm1_go1,
                    true);

    //find matches t-2
    if(t > 1)
        match_find_matches(
                    &vScores_parent_child_score,
                    t - 2,
                    t,
                    match_score_thres_tm2_go1,
                    false);

    //accept matches
    match_accept_matches(&vScores_parent_child_score, true);
}

void D_Bio_NucleusPedigree::match_time_tm1_tm2_consecutive(size_t t)
{
    match_to_tm1(t);
    match_to_tm2_to_ends_only(t);
}

void D_Bio_NucleusPedigree::match_time_ends_tm2_then_normal_tm1(size_t t)
{
    match_to_tm2_to_ends_only(t);
    match_to_tm1(t);
}

void D_Bio_NucleusPedigree::match_to_tm1(size_t t)
{
    if(t <= 0 && t >= vvNucBlobs_T.size())
        return;

    match_times(t - 1, t, match_score_thres_tm1_go1, true);
}

void D_Bio_NucleusPedigree::match_to_tm2_to_ends_only(size_t t)
{
    if(t <= 1 && t >= vvNucBlobs_T.size())
        return;

    match_times(t - 2, t, match_score_thres_tm2_go1, false);
}

void D_Bio_NucleusPedigree::match_times(size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis)
{
    if(t_parents >= vvNucBlobs_T.size() || t_childs >= vvNucBlobs_T.size() || t_parents >= t_childs)
        return;

    //score table as point list (for easy sorting)
    vector<vector<double>> vScores_parent_child_score;

    //find matches
    match_find_matches(
                &vScores_parent_child_score,
                t_parents,
                t_childs,
                score_thresh,
                allow_new_mitosis);

    //accept matches
    match_accept_matches(
                &vScores_parent_child_score,
                allow_new_mitosis);
}

void D_Bio_NucleusPedigree::match_find_matches(vector<vector<double>> *vvMatches, size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis)
{
    if(t_parents >= vvNucBlobs_T.size() || t_childs >= vvNucBlobs_T.size() || t_parents >= t_childs)
        return;

    //nuc counts
    size_t n_parents = vvNucBlobs_T[t_parents].size();
    size_t n_childs = vvNucBlobs_T[t_childs].size();

    //loop all child candidates (later time index)
    for(size_t i_child = 0; i_child < n_childs; i_child++)
    {
        //loop all parent candidates (earlier time index)
        for(size_t i_parent = 0; i_parent < n_parents; i_parent++)
        {
            //calc match?
            bool calc_score = true;

            //possible parent is mitosis?
            if(vvNucBlobs_T[t_parents][i_parent].matching_isMitosis())
                calc_score = false;

            //possible child allready found a parent?
            if(vvNucBlobs_T[t_childs][i_child].matching_foundParent())
                calc_score = false;

            //calc score only if potential parent is not yet matched (1 child accepted)?
            if(!allow_new_mitosis && vvNucBlobs_T[t_parents][i_parent].matching_foundAtLeastOneChild())
                calc_score = false;

            //calc score candidate
            if(calc_score)
            {
                double score = vvNucBlobs_T[t_childs][i_child].matching_Score(&(vvNucBlobs_T[t_parents][i_parent]));
                if(score >= score_thresh)
                {
                    vector<double> vMatch(MATCH_ATTRIB_INDEX_NUMBER_OF, 0);
                    vMatch[MATCH_ATTRIB_INDEX_SCORE] = score;
                    vMatch[MATCH_ATTRIB_INDEX_PARENT_T] = t_parents;
                    vMatch[MATCH_ATTRIB_INDEX_PARENT_I] = i_parent;
                    vMatch[MATCH_ATTRIB_INDEX_CHILD_T] = t_childs;
                    vMatch[MATCH_ATTRIB_INDEX_CHILD_I] = i_child;
                    vvMatches->push_back(vMatch);
                }
            }
        }

        vvNucBlobs_T[t_childs][i_child].matching_setTriedToMatchAtLeastOnce(true);
    }
}

void D_Bio_NucleusPedigree::match_accept_matches(vector<vector<double> > *vvMatches, bool allow_new_mitosis)
{
    //sort matches by score
    struct score_higher {
        bool operator ()(vector<double> const& match1, vector<double> const& match2) const
        {
            return match1[MATCH_ATTRIB_INDEX_SCORE] > match2[MATCH_ATTRIB_INDEX_SCORE];
        }
    };

    sort(vvMatches->begin(), vvMatches->end(), score_higher());

    //accept matches from highest to lowest score
    for(size_t m = 0; m < vvMatches->size(); m++)
    {
        //match parameters
        vector<double> vMatch = (*vvMatches)[m];
        //score
        double score = vMatch[MATCH_ATTRIB_INDEX_SCORE];
        //time
        size_t t_parent = vMatch[MATCH_ATTRIB_INDEX_PARENT_T];
        size_t t_child = vMatch[MATCH_ATTRIB_INDEX_CHILD_T];
        //nucleus index
        size_t i_parent = vMatch[MATCH_ATTRIB_INDEX_PARENT_I];
        size_t i_child = vMatch[MATCH_ATTRIB_INDEX_CHILD_I];

        //match?
        bool match_possible = true;

        //score is no catastrophy
        if(score < 0)
            match_possible = false;

        //possible parent is mitosis?
        if(vvNucBlobs_T[t_parent][i_parent].matching_isMitosis())
            match_possible = false;

        //possible child allready found a parent?
        if(vvNucBlobs_T[t_child][i_child].matching_foundParent())
            match_possible = false;

        //creating new mitosis forbidden?
        if(!allow_new_mitosis && vvNucBlobs_T[t_parent][i_parent].matching_foundAtLeastOneChild())
            match_possible = false;

        //accept match, if no conditions are violated
        if(match_possible)
            vvNucBlobs_T[t_child][i_child].matching_SetAsParent(&(vvNucBlobs_T[t_parent][i_parent]), score);
    }
}


