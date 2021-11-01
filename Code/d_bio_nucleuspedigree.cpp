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
    vScoreWeights[SCORE_SPEED] = 1;
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
                    match_thresh_max_speed,
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
    vScoreWeights[SCORE_SPEED] = 1;

    vScoreMaxima.resize(SCORE_NUMBER_OF, 1);

    match_thresh_max_area_increase_to = 1.25;
    match_thresh_max_area_decrease_to = 0.35;
    match_thresh_max_speed = 1500;

    state_ScoreWeightsAndMaxSet = true;
}

bool D_Bio_NucleusPedigree::initMatching(vector<double> score_weights, vector<double> score_maxima, double speed_limit, double max_rel_area_inc_to, double max_rel_area_dec_to, double max_age, double thres_tm1, double thres_tm2)
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
    match_thresh_max_speed              = speed_limit;
    match_max_age                       = max_age;
    match_score_thres_tm1               = thres_tm1;
    match_score_thres_tm2               = thres_tm2;

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
    double score_min = min(match_score_thres_tm1, match_score_thres_tm2);
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
                            int(240.0 * (1.0 - age_rel)),
                            255,
                            int(255.0 * score_rel));
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
    for(size_t t = 0; t < vvNucBlobs_T.size(); t++)
        match_time(t);

    //updatePedigreePlot(10);
}

void D_Bio_NucleusPedigree::match_time(size_t t)
{
    match_step1_to_tm1(t);
    match_step2_to_tm2(t);
    //updatePedigreePlot(10);
}

void D_Bio_NucleusPedigree::match_step1_to_tm1(size_t t)
{
    if(t <= 0 && t >= vvNucBlobs_T.size())
        return;

    match_times(t - 1, t, match_score_thres_tm1, false);
}

void D_Bio_NucleusPedigree::match_step2_to_tm2(size_t t)
{
    if(t <= 1 && t >= vvNucBlobs_T.size())
        return;

    match_times(t - 2, t, match_score_thres_tm2, true);
}

void D_Bio_NucleusPedigree::match_times(size_t t_parents, size_t t_childs, double score_thresh, bool dont_change_previous_mitosis)
{
    if(t_parents >= vvNucBlobs_T.size() || t_childs >= vvNucBlobs_T.size() || t_parents >= t_childs)
        return;

    //nuc counts
    size_t n_parents = vvNucBlobs_T[t_parents].size();
    size_t n_childs = vvNucBlobs_T[t_childs].size();

    //score table as point list (for easy sorting)
    //x: parent index
    //y: child index
    //z: match score
    vector<Point3d> vScores_parent_child_score;

    //loop all child candidates (later time index)
    for(size_t i_child = 0; i_child < n_childs; i_child++)
    {
        //loop all parent candidates (earlier time index)
        for(size_t i_parent = 0; i_parent < n_parents; i_parent++)
        {
            //calc score only if potential parent is no succesfull mitosis (2 childs accepted)?
            bool calc_score = true;
            if(dont_change_previous_mitosis)
            {
                //parent candidate is allready happy with two children?
                if(vvNucBlobs_T[t_parents][i_parent].matching_isMitosis())
                {
                    //->leave the happy family alone...
                    calc_score = false;
                }
            }

            //calc score candidate
            if(calc_score)
            {
                double score = vvNucBlobs_T[t_childs][i_child].matching_Score(&(vvNucBlobs_T[t_parents][i_parent]));
                if(score >= score_thresh)
                    vScores_parent_child_score.push_back(Point3d(i_parent, i_child, score));
            }
        }

        if(n_parents > 0)
            vvNucBlobs_T[t_childs][i_child].matching_setTriedToMatchAtLeastOnce(true);
    }

    //sort matches by score
    struct score_higher {
        bool operator ()(Point3d const& m1, Point3d const& m2) const
        {
            return m1.z > m2.z;
        }
    };

    sort(vScores_parent_child_score.begin(), vScores_parent_child_score.end(), score_higher());

    //accept matches from highest to lowest score
    for(size_t m = 0; m < vScores_parent_child_score.size(); m++)
    {
        //match parameters
        Point3d P_match = vScores_parent_child_score[m];
        double score = P_match.z;
        size_t i_parent = P_match.x;
        size_t i_child = P_match.y;

        //match possible?
        bool parent_allready_has_two_childs = vvNucBlobs_T[t_parents][i_parent].matching_isMitosis();
        bool child_allready_has_parent = vvNucBlobs_T[t_childs][i_child].matching_foundParent();

        if(!parent_allready_has_two_childs && !child_allready_has_parent)
            vvNucBlobs_T[t_childs][i_child].matching_SetAsParent(&(vvNucBlobs_T[t_parents][i_parent]), score);
    }




    /*
    //loop all child candidates (later time index)
    for(size_t i1 = 0; i1 < n1; i1++)
    {
        //nucleus, that seeks a parent / tries to match to an earlier nucleus
        D_Bio_NucleusBlob Nuc_SeekingParent = vvNucBlobs_T[t1][i1];

        //only try matching, if no parent found and accepted yet
        if(!(Nuc_SeekingParent.matching_foundParent_Accepted()))
        {
            //loop all parent candidates (earlier time index)
            for(size_t i0 = 0; i0 < n0; i0++)
            {
                //parent candidate
                D_Bio_NucleusBlob Nuc_ParentCandidate = vvNucBlobs_T[t0][i0];

                //test only if potential parent is no succesfull mitosis (2 childs accepted)?
                bool test_nuc = true;
                if(dont_change_previous_mitosis)
                {
                    //parent candidate is allready happy with two children?
                    if(Nuc_ParentCandidate.matching_isMitosis_Accepted())
                    {
                        //->leave the happy family alone...
                        test_nuc = false;
                    }
                }

                //test parent candidate
                if(test_nuc)
                    Nuc_SeekingParent.matching_TestAsParent_Candidate(&Nuc_ParentCandidate, score_thresh);
            }
        }
    }

    //after the casting show is over best matches are accepted, if there are any
    for(size_t i1 = 0; i1 < n1; i1++)
        vvNucBlobs_T[t1][i1].matching_AcceptAndTellParent();
        */
}


