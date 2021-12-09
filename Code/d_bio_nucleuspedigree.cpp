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

}

void D_Bio_NucleusPedigree::clear()
{
    size_time       = 0;
    size_mosaik_y   = 0;
    size_mosaik_x   = 0;

    vvvvNucBlobs_TYXI.clear();
}

void D_Bio_NucleusPedigree::set_size_time_and_mosaik(size_t t_size, size_t y_size, size_t x_size)
{
    clear();

    size_time       = t_size;
    size_mosaik_y   = y_size;
    size_mosaik_x   = x_size;

    vvvvNucBlobs_TYXI.resize(
                size_time, vector<vector<vector<D_Bio_NucleusBlob>>>(
                    size_mosaik_y, vector<vector<D_Bio_NucleusBlob>>(
                        size_mosaik_y, vector<D_Bio_NucleusBlob>())));
}

size_t D_Bio_NucleusPedigree::nuclei_blob_count(size_t t)
{
    if(t >= vvvvNucBlobs_TYXI.size())
        return 0;

    size_t nuclei_count_in_t = 0;
    for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
        for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
            nuclei_count_in_t += vvvvNucBlobs_TYXI[t][y][x].size();

    return nuclei_count_in_t;
}

size_t D_Bio_NucleusPedigree::nuclei_blob_count()
{
    size_t nuclei_count_total = 0;
    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        nuclei_count_total += nuclei_blob_count(t);

    return nuclei_count_total;
}

bool D_Bio_NucleusPedigree::add_nucleus_blob(size_t t, size_t y, size_t x, D_Bio_NucleusBlob nuc)
{
    if(t >= vvvvNucBlobs_TYXI.size())
        return false;

    if(y >= vvvvNucBlobs_TYXI[t].size())
        return false;

    if(x >= vvvvNucBlobs_TYXI[t][y].size())
        return false;

    //set time
    nuc.set_time_index(t);

    //add nucleus to stack of nuclei to be matched
    vvvvNucBlobs_TYXI[t][y][x].push_back(nuc);

    return true;
}

bool D_Bio_NucleusPedigree::initMatching(vector<double> score_weights, vector<double> score_maxima, double shift_limit, double max_rel_area_inc_to, double max_rel_area_dec_to, double max_age, double thres_tm1_go1, double thres_tm2_go1, double thres_tm3_go1, double thres_tm1_go2, double thres_tm2_go2, double thres_tm3_go2, double mitosis_mult_go1, double mitosis_mult_go2)
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

    //scores and weights
    vector<double> vScoreWeights_All(SCORE_NUMBER_OF, 0);
    vector<double> vScoreMaxima_All(SCORE_NUMBER_OF, 1);
    for(size_t i = 0; i < score_weights.size(); i++)
    {
        vScoreWeights_All[i] = score_weights[i] / weight_sum;
        vScoreMaxima_All[i] = score_maxima[i];
    }

    //save only relevant score criteria
    vScoreCriteria_Relevant.clear();
    vScoreWeights_Relevant.clear();
    vScoreMaxima_Relevant.clear();
    for(size_t c = 0; c < score_weights.size(); c++)
    {
        double w = vScoreWeights_All[c];
        double m = vScoreMaxima_All[c];

        bool relevant = false;

        if(w > 0 && m > 0)
            relevant = true;

        if(c == SCORE_SHIFT)
            if(shift_limit < INFINITY)
                relevant = true;

        if(c == SCORE_AREA)
            if(max_rel_area_inc_to < INFINITY || max_rel_area_dec_to > 0)
                relevant = true;

        if(relevant)
        {
            vScoreCriteria_Relevant.push_back(c);
            vScoreWeights_Relevant.push_back(w);
            vScoreMaxima_Relevant.push_back(m);
        }
    }


    state_ScoreWeightsAndMaxSet = true;

    match_thresh_max_area_increase_to   = max_rel_area_inc_to;
    match_thresh_max_area_decrease_to   = max_rel_area_dec_to;

    match_thresh_max_shift              = shift_limit;

    match_max_age                       = max_age;

    match_score_thres_tm1_go1           = thres_tm1_go1;
    match_score_thres_tm2_go1           = thres_tm2_go2;
    match_score_thres_tm3_go1           = thres_tm3_go2;

    match_score_thres_tm1_go2           = thres_tm1_go2;
    match_score_thres_tm2_go2           = thres_tm2_go2;
    match_score_thres_tm3_go2           = thres_tm3_go2;

    match_score_multiplier_mitosis_go1  = mitosis_mult_go1;
    match_score_multiplier_mitosis_go2  = mitosis_mult_go1;

    return true;
}

int D_Bio_NucleusPedigree::setPedigreeViewer_Volumetric(D_Viewer_3D *viewer)
{
    if(!viewer)
        return ER_UiNotInit;

    if(viewer == pViewerPedigree_Volumetric)
        return ER_okay;

    pViewerPedigree_Volumetric = viewer;
    pViewerPedigree_Volumetric->Set_Volume(c_VOLUME_XYT);
    pViewerPedigree_Volumetric->Set_backgroundColor(Qt::white);
    pViewerPedigree_Volumetric->Set_AlphaMode(c_VIEWER_3D_ALPHA_MAX_IS_TRANSPARENT);

    state_PedigreeViewer_Volumetric_Set = true;

    return ER_okay;
}

int D_Bio_NucleusPedigree::setPedigreeViewer_Plot3D(D_Viewer_Plot_3D *viewer)
{
    if(!viewer)
        return ER_UiNotInit;

    if(viewer == pViewerPedigree_Plot3D)
        return ER_okay;

    pViewerPedigree_Plot3D = viewer;
    state_PedigreeViewer_Plot3D_Set = true;

    return ER_okay;
}

int D_Bio_NucleusPedigree::updatePedigreeView_Plot3D(size_t points_per_edge, size_t t_min, size_t t_max, double y_min_um, double y_max_um, double x_min_um, double x_max_um)
{
    if(!state_PedigreeViewer_Plot3D_Set)
        return ER_UiNotInit;

    //cosmetic params
    size_t          shadow = c_VIEWER_PLOT_3D_SHADOW_NONE;
    bool            background = false;
    bool            grid = true;
    bool            smooth = false;
    QString         axis_x = "X/um";
    QString         axis_y = "Y/um";
    QString         axis_z = "T/h";

    //scale ROI to px cooridantes
    double y_min_px = y_min_um / scale_px_to_um;
    double y_max_px = y_max_um / scale_px_to_um;
    double x_min_px = x_min_um / scale_px_to_um;
    double x_max_px = x_max_um / scale_px_to_um;

    //node data
    vector<Point3d> vNodesCoord;
    vector<QColor>  vNodeColor;

    //edge data
    vector<Point3d> vEdgeCoordBegins;
    vector<Point3d> vEdgeCoordEnds;
    vector<QColor>  vEdgeColor;

    //score norming
    double score_min = min(min(min(match_score_thres_tm1_go1, match_score_thres_tm2_go1), match_score_thres_tm3_go1), min(min(match_score_thres_tm1_go2, match_score_thres_tm2_go2), match_score_thres_tm3_go2));
    double score_range = 1.0 - score_min;

    //loop nuclei
    for(size_t t = max(size_t(0), t_min); t < min(t_max, vvvvNucBlobs_TYXI.size()); t++)
    {
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
        {
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
            {
                //qDebug() << t << "--------------------------------------------------------------------------";
                for(size_t i = 0; i < vvvvNucBlobs_TYXI[t][y][x].size(); i++)
                {
                    //child nuc/node
                    D_Bio_NucleusBlob *pNucChild = &(vvvvNucBlobs_TYXI[t][y][x][i]);

                    //ancestor is in plot range?
                    if(pNucChild->matching_HasAncestorInRange(t_min, y_min_px, y_max_px, x_min_px, x_max_px))
                    {
                        //add node coord
                        Point3d P_NucCoord = Point3d(
                                    float(pNucChild->centroid().x * scale_px_to_um),
                                    float(pNucChild->centroid().y * scale_px_to_um),
                                    float(pNucChild->time_index() * scale_t_to_h));
                        vNodesCoord.push_back(P_NucCoord);

                        //add node color
                        vNodeColor.push_back(pNucChild->matching_TypeColor(FrameInRegularRangeXY, 0, vvvvNucBlobs_TYXI.size() - 1));

                        //get Ancestor and calc edge
                        if(pNucChild->matching_foundParent())
                        {
                            //parent nuc/node
                            D_Bio_NucleusBlob *pNucParent = pNucChild->matching_Parent();

                            //position of ancestor
                            Point3d P_AncestorCoord = Point3d(
                                        float(pNucParent->centroid().x * scale_px_to_um),
                                        float(pNucParent->centroid().y * scale_px_to_um),
                                        float(pNucParent->time_index() * scale_t_to_h));

                            //match score to ancestor
                            double score = pNucChild->matching_Score_Parent();
                            score = max(0.0, min(score, 1.0));
                            double score_rel = (score - score_min) / score_range;

                            //age of nuc
                            //double age = pNucChild->matching_Age();
                            //age = max(0.0, min(age, match_max_age));
                            //double age_rel = match_max_age > 0 ? age / match_max_age : 0;

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

                            //qDebug() << "Nuc at" << P_NucCoord.x << P_NucCoord.y << P_NucCoord.z << "with parent at" << P_AncestorCoord.x << P_AncestorCoord.y << P_AncestorCoord.z << "(score" << score << ")";
                        }
                        else
                        {
                            //qDebug() << "Nuc at" << P_NucCoord.x << P_NucCoord.y << P_NucCoord.z << "with no parent" << "(highest parent score" << vvNucBlobs_T[t][i].matching_Score_Parent() << ")";
                        }
                    }
                }
            }
        }
    }

    return pViewerPedigree_Plot3D->plot_Tree(
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

int D_Bio_NucleusPedigree::updatePedigreeView_Volumetric(size_t size_volT_px, size_t size_volY_px, size_t size_volX_px, size_t size_Node_px, size_t size_Edge_px, size_t size_Y_px_original, size_t size_X_px_original)
{
    if(!state_PedigreeViewer_Volumetric_Set)
        return ER_UiNotInit;

    ///make sure node and edge sizes are odd
    if(size_Node_px % 2 != 1)   size_Node_px++;
    if(size_Edge_px % 2 != 1)   size_Edge_px++;

    ///define dimension
    D_VisDat_Dim Dim(
                int(size_volX_px),
                int(size_volY_px),
                1,
                int(size_volT_px),
                1,
                1);

    ///init black volume as plot background
    //qDebug() << "updatePedigreeView_Volumetric" << "create volume";
    D_VisDat_Proc::Create_VD_Single_Constant(
                &VD_PlotVol,
                Dim,
                CV_8UC3,
                255);

    ///cosmetic params
    QString         axis_x = "X/um";
    QString         axis_y = "Y/um";
    QString         axis_z = "T/h";

    ///score norming
    //qDebug() << "updatePedigreeView_Volumetric" << "calc score norming";
    double score_min = min(
                min(min(match_score_thres_tm1_go1, match_score_thres_tm2_go1), match_score_thres_tm3_go1),
                min(min(match_score_thres_tm1_go2, match_score_thres_tm2_go2), match_score_thres_tm3_go2));
    double score_range = 1.0 - score_min;

    ///create threads
    size_t nt_threads = vvvvNucBlobs_TYXI.size();
    vector<thread> vThreads(nt_threads);

    ///start threads
    //qDebug() << "updatePedigreeView_Volumetric" << "start" << nt_threads << "threads";
    for(size_t t_thread = 0; t_thread < nt_threads; t_thread++)
    {
        //start the thread
        vThreads[t_thread] = thread(
                    updatePedigreeView_Volumetric_TimeThread,
                    &VD_PlotVol,
                    &vvvvNucBlobs_TYXI,
                    score_range,
                    score_min,
                    size_Node_px,
                    size_Edge_px,
                    size_Y_px_original,
                    size_X_px_original,
                    FrameInRegularRangeXY,
                    t_thread);
    }

    ///wait for all threads to finish
    //qDebug() << "updatePedigreeView_Volumetric" << "join threads";
    for(size_t t_thread = 0; t_thread < nt_threads; t_thread++)
    {
        vThreads[t_thread].join();
    }

    ///show plot
    //qDebug() << "updatePedigreeView_Volumetric" << "Show plot";
    pViewerPedigree_Volumetric->set_VisDat(&VD_PlotVol);

    ///finish
    return ER_okay;
}

int D_Bio_NucleusPedigree::updatePedigreeView_Volumetric_TimeThread(D_VisDat_Obj *pVD_Target, vector<vector<vector<vector<D_Bio_NucleusBlob> > > > *pvvvvNucsTYXI, double score_range, double score_min, size_t size_Node_px, size_t size_Edge_px, size_t size_Y_px_original, size_t size_X_px_original, Rect frame_legit, size_t t_plane)
{
    if(pvvvvNucsTYXI->empty())
        return ER_empty;

    ///size of dataset
    size_t nt_plane             = pvvvvNucsTYXI->size();
    size_t nt_px                = pVD_Target->pDim()->size_T();
    //size_t t_plane_max        = nt_plane - 1;
    //size_t t_px_max           = nt_px - 1;
    size_t nt_plane_thicknes_px = nt_px / nt_plane;
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "got sizes";

    ///check time index existence
    if(t_plane >= nt_plane)
        return ER_index_out_of_range;
    if(nt_plane_thicknes_px <= 0)
        return ER_size_bad;
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "t thickness ok";

    ///check node thickeness fit to plane thickness
    if(size_Node_px >= nt_plane_thicknes_px)
        return ER_size_missmatch;
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "node size fits to plane";

    ///object radii
    int node_radius = int(size_Node_px / 2);
    int edge_radius = int(size_Edge_px /2);
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "object radii node/edge" << node_radius << edge_radius;

    ///position of t-plane and elements in time
    size_t t_px_begin           = t_plane * nt_plane_thicknes_px;
    size_t t_px_end             = t_px_begin + nt_plane_thicknes_px - 1;
    size_t t_px_node_center     = t_px_end - node_radius;
    size_t t_px_node_top        = t_px_node_center - node_radius;
    //size_t t_px_node_bottom     = t_px_end;
    size_t t_px_edge_begin      = t_px_begin;
    size_t t_px_edge_end        = t_px_node_top - 1;
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "pos of t plane begin/end" << t_px_begin << t_px_end << "node top/center" << t_px_node_top << t_px_node_center << "egde begin/end" << t_px_edge_begin << t_px_edge_end;

    ///xy size
    size_t nx_px = pVD_Target->pDim()->size_X();
    size_t ny_px = pVD_Target->pDim()->size_Y();
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "VD size x/y" << nx_px << ny_px;

    ///factors from original px to VD px
    float factor_original_px_2_VD_px_X = float(nx_px) / float(size_X_px_original);
    float factor_original_px_2_VD_px_Y = float(ny_px) / float(size_Y_px_original);
    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "scale original->VD x/y" << factor_original_px_2_VD_px_X << factor_original_px_2_VD_px_Y;


    ///functor to calc node position in px
    function<Point3i (D_Bio_NucleusBlob*)> node_pos = [t_px_node_center, factor_original_px_2_VD_px_Y, factor_original_px_2_VD_px_X](D_Bio_NucleusBlob* nuc)
    {
        int x = int(nuc->centroid().x * factor_original_px_2_VD_px_X);
        int y = int(nuc->centroid().y * factor_original_px_2_VD_px_Y);
        int t = t_px_node_center;
        return Point3i(x, y, t);
    };


    ///functor to calc node color
    function<Vec3b (D_Bio_NucleusBlob*)> node_color = [frame_legit, nt_plane](D_Bio_NucleusBlob* nuc)
    {
        QColor color =  nuc->matching_TypeColor(frame_legit, 0, nt_plane);

        return Vec3b(
                    uchar(color.blue()),
                    uchar(color.green()),
                    uchar(color.red()));
    };


    ///functor to calc edge begin in px
    function<Point3i (D_Bio_NucleusBlob*)> edge_begin = [t_px_edge_begin, nt_plane_thicknes_px, factor_original_px_2_VD_px_Y, factor_original_px_2_VD_px_X](D_Bio_NucleusBlob* nuc)
    {
        if(nuc->matching_foundParent())
        {
            int x = int(nuc->matching_Parent()->centroid().x * factor_original_px_2_VD_px_X);
            int y = int(nuc->matching_Parent()->centroid().y * factor_original_px_2_VD_px_Y);

            int dt = nuc->time_index() - nuc->matching_Parent()->time_index();

            int t;
            if(dt == 1)
            {
                t = t_px_edge_begin;
            }
            else
            {
                t = t_px_edge_begin - ((dt - 1) * nt_plane_thicknes_px);
            }

            return Point3i(x, y, t);
        }
        else
        {
            return  Point3i(0, 0, 0);
        }
    };


    ///functor to calc edge end in px
    function<Point3i (D_Bio_NucleusBlob*)> edge_end = [t_px_edge_end, factor_original_px_2_VD_px_Y, factor_original_px_2_VD_px_X](D_Bio_NucleusBlob* nuc)
    {
        int x = int(nuc->centroid().x * factor_original_px_2_VD_px_X);
        int y = int(nuc->centroid().y * factor_original_px_2_VD_px_Y);
        int t = int(t_px_edge_end);
        return Point3i(x, y, t);
    };


    ///functor to calc edge color
    function<Vec3b (D_Bio_NucleusBlob*)> edge_color = [score_range, score_min](D_Bio_NucleusBlob* nuc)
    {
        if(nuc->matching_foundParent())
        {
            //match score to ancestor
            double score = nuc->matching_Score_Parent();
            score = max(0.0, min(score, 1.0));
            double score_rel = (score - score_min) / score_range;

            //color
            QColor color;
            color.setHsv(
                        int(240.0 * (1.0 - score_rel)),
                        255,
                        255);
            color = color.toRgb();

            return Vec3b(
                        uchar(color.blue()),
                        uchar(color.green()),
                        uchar(color.red()));
        }
        else
        {
            return Vec3b(0, 0, 0);
        }
    };


    ///functor to draw node
    function<void (D_Bio_NucleusBlob*)> draw_node = [node_color, node_pos, node_radius, nt_px, ny_px, nx_px, pVD_Target](D_Bio_NucleusBlob* nuc)
    {
        //center
        Point3i P = node_pos(nuc);

        //color
        Vec3b color = node_color(nuc);

        //loop pixels to draw to
        Vec<int, c_DIM_NUMBER_OF> pos = {0, 0, 0, 0, 0, 0};
        for(        pos[c_DIM_T] = max(int(P.z - node_radius), int(0)); pos[c_DIM_T] <= min(int(P.z + node_radius), int(nt_px - 1)); pos[c_DIM_T]++)
            for(    pos[c_DIM_Y] = max(int(P.y - node_radius), int(0)); pos[c_DIM_Y] <= min(int(P.y + node_radius), int(ny_px - 1)); pos[c_DIM_Y]++)
                for(pos[c_DIM_X] = max(int(P.x - node_radius), int(0)); pos[c_DIM_X] <= min(int(P.x + node_radius), int(nx_px - 1)); pos[c_DIM_X]++)
                    pVD_Target->pMA_full()->at<Vec3b>(pos) = color;
    };

    ///functor to draw edge
    function<void (D_Bio_NucleusBlob*)> draw_edge = [edge_color, edge_begin, edge_end, edge_radius, nt_px, ny_px, nx_px, pVD_Target](D_Bio_NucleusBlob* nuc)
    {
        //begin/end point
        Point3i P_begin = edge_begin(nuc);
        Point3i P_end   = edge_end(nuc);

        //color
        Vec3b color = edge_color(nuc);

        //time range
        int t_begin = int(P_begin.z);
        int t_end   = int(P_end.z);
        int t_range = t_end - t_begin;

        //loop pixels to draw to
        Vec<int, c_DIM_NUMBER_OF> pos = {0, 0, 0, 0, 0, 0};
        int t_local = 0;
        for(pos[c_DIM_T] = max(t_begin, 0); pos[c_DIM_T] <= min(int(t_end), int(nt_px - 1)); pos[c_DIM_T]++)
        {
            //calc line pos at time
            float t_rel_e = (t_range > 0.f) ? (float(t_local) / float(t_range)) : (0.f);
            float t_rel_b = 1.f - t_rel_e;
            Point3d P_center(
                        P_begin.x * t_rel_b + P_end.x * t_rel_e,
                        P_begin.y * t_rel_b + P_end.y * t_rel_e,
                        P_begin.z * t_rel_b + P_end.z * t_rel_e);

            //loop pixles to color
            for(pos[c_DIM_Y] = max(int(P_center.y - edge_radius), int(0)); pos[c_DIM_Y] <= min(int(P_center.y + edge_radius), int(ny_px - 1)); pos[c_DIM_Y]++)
            {
                for(pos[c_DIM_X] = max(int(P_center.x - edge_radius), int(0)); pos[c_DIM_X] <= min(int(P_center.x + edge_radius), int(nx_px - 1)); pos[c_DIM_X]++)
                {
                    pVD_Target->pMA_full()->at<Vec3b>(pos) = color;
                }
            }

            //increment local t index
            t_local++;
        }
    };


    //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "functors created";


    ///loop lines of images (mosaik)
    for(size_t y = 0; y < (*pvvvvNucsTYXI)[t_plane].size(); y++)
    {
        for(size_t x = 0; x < (*pvvvvNucsTYXI)[t_plane][y].size(); x++)
        {
            //qDebug() << t << "--------------------------------------------------------------------------";
            for(size_t i = 0; i < (*pvvvvNucsTYXI)[t_plane][y][x].size(); i++)
            {
                //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "proc nuc y/x/i" << y << x << i;

                //child nuc/node
                D_Bio_NucleusBlob *pNucChild = &((*pvvvvNucsTYXI)[t_plane][y][x][i]);

                //draw node
                draw_node(pNucChild);

                //get Ancestor and calc edge
                if(pNucChild->matching_foundParent())
                {
                     draw_edge(pNucChild);
                }
            }
        }
    }

  //qDebug() << "updatePedigreeView_Volumetric_TimeThread" << "finished";
    return true;
}

int D_Bio_NucleusPedigree::updatePedigreeView_Plot3D(D_Viewer_Plot_3D *viewer, size_t points_per_edge, size_t t_min, size_t t_max, double y_min_um, double y_max_um, double x_min_um, double x_max_um)
{
    int err = setPedigreeViewer_Plot3D(viewer);
    if(err != ER_okay)
        return err;

    return updatePedigreeView_Plot3D(points_per_edge, t_min, t_max, y_min_um, y_max_um, x_min_um, x_max_um);
}

int D_Bio_NucleusPedigree::updatePedigreeView_Volumetric(D_Viewer_3D *viewer, size_t size_volT_px, size_t size_volY_px, size_t size_volX_px, size_t size_Node_px, size_t size_Edge_px, size_t size_Y_px_original, size_t size_X_px_original)
{
    int err = setPedigreeViewer_Volumetric(viewer);
    if(err != ER_okay)
        return err;

    return updatePedigreeView_Volumetric(size_volT_px, size_volY_px, size_volX_px, size_Node_px, size_Edge_px, size_Y_px_original, size_X_px_original);
}

void D_Bio_NucleusPedigree::match_all()
{
    match_all_go1();
    match_all_go2();
}

void D_Bio_NucleusPedigree::match_all_go1()
{
    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        match_time_go1(t);
}

void D_Bio_NucleusPedigree::match_all_go2()
{
    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        match_time_go2(t);
}

void D_Bio_NucleusPedigree::match_time_go1(size_t t)
{
    if(t > 0)   match_times(t - 1, t, match_score_thres_tm1_go1, (t - 1) >= match_earliest_mitosis_allowed);
    if(t > 1)   match_times(t - 2, t, match_score_thres_tm2_go1, false);
    if(t > 2)   match_times(t - 3, t, match_score_thres_tm3_go1, false);
}

void D_Bio_NucleusPedigree::match_time_go2(size_t t)
{
    if(t > 0)   match_times(t - 1, t, match_score_thres_tm1_go2, (t - 1) >= match_earliest_mitosis_allowed);
    if(t > 1)   match_times(t - 2, t, match_score_thres_tm2_go2, false);
    if(t > 2)   match_times(t - 3, t, match_score_thres_tm3_go2, false);
}

void D_Bio_NucleusPedigree::match_time_correct_mitosis_go1(size_t t)
{
    if(t > 0)   match_correct_mitosis(t - 1, t, match_score_multiplier_mitosis_go1, false);
    if(t > 1)   match_correct_mitosis(t - 2, t, match_score_multiplier_mitosis_go1, false);
    if(t > 2)   match_correct_mitosis(t - 3, t, match_score_multiplier_mitosis_go1, false);
}

void D_Bio_NucleusPedigree::match_time_correct_mitosis_go2(size_t t)
{
    if(t > 0)   match_correct_mitosis(t - 1, t, match_score_multiplier_mitosis_go2, true);
    if(t > 1)   match_correct_mitosis(t - 2, t, match_score_multiplier_mitosis_go2, true);
    if(t > 2)   match_correct_mitosis(t - 3, t, match_score_multiplier_mitosis_go2, true);
}

bool D_Bio_NucleusPedigree::match_save_results(QString QS_path)
{
    QDir DIR_SaveMaster;
    DIR_SaveMaster.setPath(QS_path);

    if(!DIR_SaveMaster.exists())
        QDir().mkdir(DIR_SaveMaster.path());
    if(!DIR_SaveMaster.exists())
        return false;

    size_t nt = vvvvNucBlobs_TYXI.size();
    vector<thread> vThreads(nt);
    for(size_t t = 0; t < nt; t++)
        vThreads[t] = thread(
                    match_save_results_time_thread,
                    &vvvvNucBlobs_TYXI,
                    DIR_SaveMaster,
                    t);

    for(size_t t = 0; t < nt; t++)
        vThreads[t].join();

    return true;
}

bool D_Bio_NucleusPedigree::match_load_and_apply_matching(QString QS_path)
{


    return true;
}

bool D_Bio_NucleusPedigree::match_save_results_time_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, QDir DirSaveMaster, size_t t_thread)
{
    if(!DirSaveMaster.exists())
        return false;

    if(t_thread >= pvvvvNucsTYXI->size())
        return false;

    //save dir for time
    QDir DirSaveTime;
    DirSaveTime.setPath(DirSaveMaster.path() + "/Time_" + QString::number(t_thread));

    for(size_t y = 0; y < (*pvvvvNucsTYXI)[t_thread].size(); y++)
    {
        for(size_t x = 0; x < (*pvvvvNucsTYXI)[t_thread][y].size(); x++)
        {
            QDir DirSaveTimeSpace(DirSaveTime.path() + "/Image_Y"+ QString::number(y) + "_X" + QString::number(x));

            for(size_t i = 0; i < (*pvvvvNucsTYXI)[t_thread][y][x].size(); i++)
            {
                D_Bio_NucleusBlob* pNuc = &((*pvvvvNucsTYXI)[t_thread][y][x][i]);

                //Nucleus is begin of new tracking?
                if(pNuc->matching_foundNoParent() || pNuc->matching_parent_isMitosis())
                {
                    //make sure save dir exists
                    if(!DirSaveTime.exists())
                        QDir().mkdir(DirSaveTime.path());
                    if(!DirSaveTimeSpace.exists())
                        QDir().mkdir(DirSaveTimeSpace.path());

                    //save dir exists?
                    if(DirSaveTimeSpace.exists())
                    {
                        //save file
                        Point center = pNuc->centroid();
                        QFileInfo FI_NucLife;
                        FI_NucLife.setFile(DirSaveTimeSpace.path() + "/NucleusLife_T" + QString::number(t_thread) + "_Y" + QString::number(center.y) + "_X" + QString::number(center.x) + ".txt");

                        //stream
                        ofstream OF_NucLife;
                        OF_NucLife.open(FI_NucLife.absoluteFilePath().toStdString());

                        //open?
                        if(true)//OF_NucLife.is_open())
                        {
                            //header
                            OF_NucLife << QSL_NucLifeFileSections[NUC_LIFE_FILE_SECTION_PATH_INFO].toStdString() << "\n";
                            OF_NucLife << "Original absolute path of this file;" << FI_NucLife.path().toStdString() << "\n";
                            OF_NucLife << "Original absolute path of 1st nucleus blob file;" << pNuc->get_path_absolute_loaded_from().toStdString() << "\n";
                            OF_NucLife << "\n";

                            //parent
                            OF_NucLife << QSL_NucLifeFileSections[NUC_LIFE_FILE_SECTION_PARENT].toStdString() << "\n";
                            if(pNuc->matching_foundParent())
                                OF_NucLife << pNuc->matching_Parent()->get_path_relative().toStdString() + "\n";

                            //save member nucleus files
                            OF_NucLife << QSL_NucLifeFileSections[NUC_LIFE_FILE_SECTION_MEMBERS].toStdString() << "\n";
                            OF_NucLife << pNuc->get_path_relative().toStdString() + "\n";
                            while(pNuc->matching_foundExactlyOneChild())
                            {
                                pNuc = pNuc->matching_ChildFavorite();
                                OF_NucLife << pNuc->get_path_relative().toStdString() + "\n";
                            }

                            //childs
                            OF_NucLife << QSL_NucLifeFileSections[NUC_LIFE_FILE_SECTION_CHILDS].toStdString() << "\n";
                            if(pNuc->matching_isMitosis())
                            {
                                OF_NucLife << pNuc->matching_Child1()->get_path_relative().toStdString() + "\n";
                                OF_NucLife << pNuc->matching_Child2()->get_path_relative().toStdString() + "\n";
                            }

                            //end
                            OF_NucLife << QSL_NucLifeFileSections[NUC_LIFE_FILE_SECTION_END].toStdString();
                        }

                        //close;
                        OF_NucLife.close();
                    }
                }
            }
        }
    }

    return true;
}

void D_Bio_NucleusPedigree::match_times(size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis)
{
    size_t nt = vvvvNucBlobs_TYXI.size();
    if(t_parents >= nt || t_childs >= nt || t_parents >= t_childs)
        return;

    //possible matches
    vector<vector<double>> vvPossibleMatches_MatchAttrib;

    //find matches
    match_find_possible_matches(
                &vvPossibleMatches_MatchAttrib,
                t_parents,
                t_childs,
                score_thresh,
                allow_new_mitosis);

    //accept matches
    match_accept_matches(
                &vvPossibleMatches_MatchAttrib,
                allow_new_mitosis);
}

void D_Bio_NucleusPedigree::match_correct_mitosis(size_t t_parents, size_t t_childs, double score_multiplier, bool allow_new_mitosis)
{
    size_t nt = vvvvNucBlobs_TYXI.size();
    if(t_parents >= nt || t_childs >= nt || t_parents >= t_childs)
        return;

    //possible matches
    vector<vector<double>> vvPossibleMitosisCorrections_MatchAttrib;

    //find matches
    match_find_possible_mitosis_corrections(
                &vvPossibleMitosisCorrections_MatchAttrib,
                t_parents,
                t_childs,
                score_multiplier,
                allow_new_mitosis);

    //accept matches
    match_accept_mitosis_corrections(
                &vvPossibleMitosisCorrections_MatchAttrib,
                allow_new_mitosis);
}

void D_Bio_NucleusPedigree::match_find_possible_matches(vector<vector<double> > *vvPossibleMatches, size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis)
{
    //clear possible old content in output vector
    vvPossibleMatches->clear();

    //thread count (one thread per mosaik line)
    size_t ny_threads = size_mosaik_y;

    //score table as point list (for easy sorting)
    vector<vector<vector<double>>> vvvPossibleMatches_ThreadMatchAttrib(ny_threads);

    //threads
    vector<thread> vThreads_FindPossibleMatches(ny_threads);

    //calc borders and start threads
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        //start the thread
        vThreads_FindPossibleMatches[y_thread] = thread(
                    match_find_possible_matches_thread,
                    &vvvvNucBlobs_TYXI,
                    &(vvvPossibleMatches_ThreadMatchAttrib[y_thread]),
                    t_parents,
                    t_childs,
                    score_thresh,
                    allow_new_mitosis,
                    &vScoreCriteria_Relevant,
                    &vScoreWeights_Relevant,
                    &vScoreMaxima_Relevant,
                    match_thresh_max_area_increase_to,
                    match_thresh_max_area_decrease_to,
                    match_thresh_max_shift,
                    y_thread);
    }

    //wait for all threads to finish
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        vThreads_FindPossibleMatches[y_thread].join();
    }

    //merge threat results to one vector (the output vector)
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        vvPossibleMatches->insert(
                    vvPossibleMatches->end(),
                    vvvPossibleMatches_ThreadMatchAttrib[y_thread].begin(),
                    vvvPossibleMatches_ThreadMatchAttrib[y_thread].end());
    }
}

void D_Bio_NucleusPedigree::match_find_possible_mitosis_corrections(vector<vector<double> > *vvPossibleMitosisCorrections, size_t t_parents, size_t t_childs, double score_multiplier, bool allow_new_mitoses)
{
    //clear possible old content in output vector
    vvPossibleMitosisCorrections->clear();

    //thread count (one thread per mosaik line)
    size_t ny_threads = size_mosaik_y;

    //score table as point list (for easy sorting)
    vector<vector<vector<double>>> vvvPossibleMitosisCorrections_ThreadMatchAttrib(ny_threads);

    //threads
    vector<thread> vThreads_FindPossibleMitosisCorrections(ny_threads);

    //calc borders and start threads
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        //start the thread
        vThreads_FindPossibleMitosisCorrections[y_thread] = thread(
                    match_find_possible_mitosis_corrections_thread,
                    &vvvvNucBlobs_TYXI,
                    &(vvvPossibleMitosisCorrections_ThreadMatchAttrib[y_thread]),
                    t_parents,
                    t_childs,
                    score_multiplier,
                    allow_new_mitoses,
                    &vScoreCriteria_Relevant,
                    &vScoreWeights_Relevant,
                    &vScoreMaxima_Relevant,
                    match_thresh_max_area_increase_to,
                    match_thresh_max_area_decrease_to,
                    match_thresh_max_shift,
                    y_thread);
    }

    //wait for all threads to finish
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        vThreads_FindPossibleMitosisCorrections[y_thread].join();
    }

    //merge threat results to one vector (the output vector)
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        vvPossibleMitosisCorrections->insert(
                    vvPossibleMitosisCorrections->end(),
                    vvvPossibleMitosisCorrections_ThreadMatchAttrib[y_thread].begin(),
                    vvvPossibleMitosisCorrections_ThreadMatchAttrib[y_thread].end());
    }
}

void D_Bio_NucleusPedigree::match_find_possible_matches_thread(
        vector<vector<vector<vector<D_Bio_NucleusBlob> > > > *pvvvvNucsTYXI,
        vector<vector<double> > *vvPossibleMatches,
        size_t t_parents,
        size_t t_childs,
        double score_thresh,
        bool allow_new_mitosis,
        vector<size_t> *pvScoreRelevantCriteria,
        vector<double> *pvScoreWeights,
        vector<double> *pvScoreMax,
        double max_area_increase_to_rel,
        double max_area_decrease_to_rel,
        double max_shift,
        size_t y_toProc)
{
    //check time integrity
    size_t nt = pvvvvNucsTYXI->size();
    if(t_parents >= nt || t_childs >= nt || t_parents >= t_childs)
        return;

    //check line existance
    size_t ny = min((*pvvvvNucsTYXI)[t_childs].size(), (*pvvvvNucsTYXI)[t_parents].size());
    if(y_toProc >= ny)
        return;

    //number of images in line
    size_t nx_childs = (*pvvvvNucsTYXI)[t_childs][y_toProc].size();

    //loop images to check childs in it
    for(size_t x_childs = 0; x_childs < nx_childs; x_childs++)
    {
        //nuc count
        size_t n_childs = (*pvvvvNucsTYXI)[t_childs][y_toProc][x_childs].size();

        //loop all child candidates (later time index)
        for(size_t i_child = 0; i_child < n_childs; i_child++)
        {
            //get child to check
            D_Bio_NucleusBlob *pNucChild = &((*pvvvvNucsTYXI)[t_childs][y_toProc][x_childs][i_child]);

            //child did not find a parent yet?
            if(pNucChild->matching_foundNoParent())
            {
                //images rows in possible parent time
                size_t ny_parents = (*pvvvvNucsTYXI)[t_parents].size();

                //images to look for parents in: y
                size_t y_min_parents = y_toProc > 0                 ? y_toProc - 1 : y_toProc;
                size_t y_max_parents = y_toProc < ny_parents - 1    ? y_toProc + 1 : y_toProc;

                //loop lines to check for parent
                for(size_t y_parents = y_min_parents; y_parents <= y_max_parents; y_parents++)
                {
                    //images in possible parent image row
                    size_t nx_parents = (*pvvvvNucsTYXI)[t_parents][y_parents].size();

                    //images to look for parents in: x
                    size_t x_min_parents = x_childs > 0                 ? x_childs - 1 : x_childs;
                    size_t x_max_parents = x_childs < nx_parents - 1    ? x_childs + 1 : x_childs;

                    //loop lines to check for parent
                    for(size_t x_parents = x_min_parents; x_parents <= x_max_parents; x_parents++)
                    {
                        //number of parents to check in this img
                        size_t n_parents = (*pvvvvNucsTYXI)[t_parents][y_parents][x_parents].size();

                        //loop all parent candidates (earlier time index)
                        for(size_t i_parent = 0; i_parent < n_parents; i_parent++)
                        {
                            //get parent to check
                            D_Bio_NucleusBlob *pNucParent = &((*pvvvvNucsTYXI)[t_parents][y_parents][x_parents][i_parent]);

                            //tell parent that it was tried to match at least once
                            pNucParent->matching_setTriedToMatchAtLeastOnce(true);

                            //possible parent has at least one child spot free?
                            if(pNucParent->matching_foundAtMostOneChild())
                            {
                                //if relevant, check if new mitosis is allowed
                                if(allow_new_mitosis || pNucParent->matching_foundNoChild())
                                {
                                    //calc score
                                    double score = pNucChild->matching_Score(
                                                pNucParent,
                                                pvScoreRelevantCriteria,
                                                pvScoreWeights,
                                                pvScoreMax,
                                                max_area_increase_to_rel,
                                                max_area_decrease_to_rel,
                                                max_shift);

                                    //score passes thres?
                                    if(score >= score_thresh)
                                    {
                                        //create possible match
                                        vector<double> vPossibleMatch(MATCH_ATTRIB_INDEX_NUMBER_OF, 0);

                                        //save match attribs
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_SCORE]    = score;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_PARENT_T] = t_parents;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_PARENT_Y] = y_parents;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_PARENT_X] = x_parents;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_PARENT_I] = i_parent;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_CHILD_T]  = t_childs;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_CHILD_Y]  = y_toProc;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_CHILD_X]  = x_childs;
                                        vPossibleMatch[MATCH_ATTRIB_INDEX_CHILD_I]  = i_child;

                                        //export possible match
                                        vvPossibleMatches->push_back(vPossibleMatch);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void D_Bio_NucleusPedigree::match_find_possible_mitosis_corrections_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, vector<vector<double>> *vvPossibleMitosisCorrections, size_t t_parents, size_t t_childs, double mitosis_score_muliplier, bool allow_new_mitoses, vector<size_t> *pvScoreRelevantCriteria, vector<double> *pvScoreWeights, vector<double> *pvScoreMax, double max_area_increase_to_rel, double max_area_decrease_to_rel, double max_shift, size_t y_toProc)
{
    //check time integrity
    size_t nt = pvvvvNucsTYXI->size();
    if(t_parents >= nt || t_childs >= nt || t_parents >= t_childs)
        return;

    //check line existance
    size_t ny = min((*pvvvvNucsTYXI)[t_childs].size(), (*pvvvvNucsTYXI)[t_parents].size());
    if(y_toProc >= ny)
        return;

    //number of images in line
    size_t nx_childs = (*pvvvvNucsTYXI)[t_childs][y_toProc].size();

    //loop images to check childs in it
    for(size_t x_childs = 0; x_childs < nx_childs; x_childs++)
    {
        //nuc count
        size_t n_childs = (*pvvvvNucsTYXI)[t_childs][y_toProc][x_childs].size();

        //loop all child candidates (later time index)
        for(size_t i_child = 0; i_child < n_childs; i_child++)
        {
            //get child to check
            D_Bio_NucleusBlob *pNucChild = &((*pvvvvNucsTYXI)[t_childs][y_toProc][x_childs][i_child]);

            //child allready found a parent?
            if(pNucChild->matching_foundParent())
            {
                //get current parent
                D_Bio_NucleusBlob *pNucParentCurrent = pNucChild->matching_Parent();

                //current parent is a mitosis (and therefore is a candidate for correction)?
                if(pNucParentCurrent->matching_isMitosis())
                {
                    //score to assigned mitosis parent
                    double score_mitosis_parent = pNucChild->matching_Score_Parent();

                    //modify score to make false mitosis less likely (score decreases)
                    double score_mitosis_parent_modified = score_mitosis_parent * mitosis_score_muliplier;

                    //images rows in possible possible new parent time
                    size_t ny_parents = (*pvvvvNucsTYXI)[t_parents].size();

                    //images to look for possible new parents in: y
                    size_t y_min_parents = y_toProc > 0                 ? y_toProc - 1 : y_toProc;
                    size_t y_max_parents = y_toProc < ny_parents - 1    ? y_toProc + 1 : y_toProc;

                    //loop lines to check for possible new parent
                    for(size_t y_parents = y_min_parents; y_parents <= y_max_parents; y_parents++)
                    {
                        //images in possible possible new parent image row
                        size_t nx_parents = (*pvvvvNucsTYXI)[t_parents][y_parents].size();

                        //images to look for possible new parents in: x
                        size_t x_min_parents = x_childs > 0                 ? x_childs - 1 : x_childs;
                        size_t x_max_parents = x_childs < nx_parents - 1    ? x_childs + 1 : x_childs;

                        //loop lines to check for possible new parent
                        for(size_t x_parents = x_min_parents; x_parents <= x_max_parents; x_parents++)
                        {
                            //number of possible new parents to check in this img
                            size_t n_parents = (*pvvvvNucsTYXI)[t_parents][y_parents][x_parents].size();

                            //loop all parent candidates (earlier time index)
                            for(size_t i_parent = 0; i_parent < n_parents; i_parent++)
                            {
                                //get parent to check
                                D_Bio_NucleusBlob *pNucParentPossibleNew = &((*pvvvvNucsTYXI)[t_parents][y_parents][x_parents][i_parent]);

                                //only check possible new parents that don't have a child yet?
                                if((allow_new_mitoses && pNucParentPossibleNew->matching_isNoMitosis()) || (pNucParentPossibleNew->matching_foundNoChild()))
                                {
                                    //calc score to new possible parent
                                    double score_new_ending_parent = pNucChild->matching_Score(
                                                pNucParentPossibleNew,
                                                pvScoreRelevantCriteria,
                                                pvScoreWeights,
                                                pvScoreMax,
                                                max_area_increase_to_rel,
                                                max_area_decrease_to_rel,
                                                max_shift);

                                    //score is better than modified mitosis parent score?
                                    if(score_new_ending_parent > score_mitosis_parent_modified)
                                    {
                                        //create possible mitosis correction
                                        vector<double> vPossibleMitosisCorrection(MATCH_ATTRIB_INDEX_NUMBER_OF, 0);

                                        //save mitosis correction attribs
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_SCORE]    = score_new_ending_parent;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_T] = t_parents;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_Y] = y_parents;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_X] = x_parents;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_I] = i_parent;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_T]  = t_childs;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_Y]  = y_toProc;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_X]  = x_childs;
                                        vPossibleMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_I]  = i_child;

                                        //export possible mitosis correction
                                        vvPossibleMitosisCorrections->push_back(vPossibleMitosisCorrection);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void D_Bio_NucleusPedigree::match_accept_matches(vector<vector<double>> *vvPossibleMatches, bool allow_new_mitosis)
{
    //sort criteria
    struct score_higher {
        bool operator ()(vector<double> const& match1, vector<double> const& match2) const
        {
            return match1[MATCH_ATTRIB_INDEX_SCORE] > match2[MATCH_ATTRIB_INDEX_SCORE];
        }
    };

    //sort matches by score
    sort(
                vvPossibleMatches->begin(),
                vvPossibleMatches->end(),
                score_higher());


    //accept matches from highest to lowest score
    for(size_t m = 0; m < vvPossibleMatches->size(); m++)
    {
        //get match
        vector<double> vMatch = (*vvPossibleMatches)[m];

        //get score
        double score = vMatch[MATCH_ATTRIB_INDEX_SCORE];

        //score is no catastrophy
        if(score >= 0)
        {
            //child
            size_t t_child = size_t(vMatch[MATCH_ATTRIB_INDEX_CHILD_T]);
            size_t i_child = size_t(vMatch[MATCH_ATTRIB_INDEX_CHILD_I]);
            size_t y_child = size_t(vMatch[MATCH_ATTRIB_INDEX_CHILD_Y]);
            size_t x_child = size_t(vMatch[MATCH_ATTRIB_INDEX_CHILD_X]);
            D_Bio_NucleusBlob *pNucChild = &(vvvvNucBlobs_TYXI[t_child][y_child][x_child][i_child]);

            //possible child did not find a parent yet?
            if(pNucChild->matching_foundNoParent())
            {
                //parent
                size_t t_parent = size_t(vMatch[MATCH_ATTRIB_INDEX_PARENT_T]);
                size_t i_parent = size_t(vMatch[MATCH_ATTRIB_INDEX_PARENT_I]);
                size_t y_parent = size_t(vMatch[MATCH_ATTRIB_INDEX_PARENT_Y]);
                size_t x_parent = size_t(vMatch[MATCH_ATTRIB_INDEX_PARENT_X]);
                D_Bio_NucleusBlob *pNucParent = &(vvvvNucBlobs_TYXI[t_parent][y_parent][x_parent][i_parent]);

                //possible parent is not a mitosis yet?
                if(pNucParent->matching_isNoMitosis())
                {
                    //creation of new mitosis is allowed? (allowed -> pass anyway, not allowed -> pass only if no mitosis would be created)
                    if(allow_new_mitosis || pNucParent->matching_foundNoChild())
                    {
                        //accept child/parent pair (parent sets child as child internally)
                        pNucChild->matching_SetAsParent(pNucParent, score);
                    }
                }
            }
        }
    }
}

void D_Bio_NucleusPedigree::match_accept_mitosis_corrections(vector<vector<double> > *vvPossibleMitosisCorrections, bool allow_new_mitosis)
{
    //sort criteria
    struct score_higher {
        bool operator ()(vector<double> const& correction1, vector<double> const& correction2) const
        {
            return correction1[MATCH_ATTRIB_INDEX_SCORE] > correction2[MATCH_ATTRIB_INDEX_SCORE];
        }
    };

    //sort corrections by score
    sort(
                vvPossibleMitosisCorrections->begin(),
                vvPossibleMitosisCorrections->end(),
                score_higher());


    //accept mitosis corrections from highest to lowest score
    for(size_t c = 0; c < vvPossibleMitosisCorrections->size(); c++)
    {
        //get match
        vector<double> vMitosisCorrection = (*vvPossibleMitosisCorrections)[c];

        //get score
        double score = vMitosisCorrection[MATCH_ATTRIB_INDEX_SCORE];

        //score is no catastrophy
        if(score >= 0)
        {
            //child
            size_t t_child = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_T]);
            size_t i_child = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_I]);
            size_t y_child = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_Y]);
            size_t x_child = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_CHILD_X]);
            D_Bio_NucleusBlob *pNucChild = &(vvvvNucBlobs_TYXI[t_child][y_child][x_child][i_child]);

            //child found a parent? (otherwise there is nothing to replace)
            if(pNucChild->matching_foundParent())
            {
                //childs current parent
                D_Bio_NucleusBlob *pNucParentCurrent = pNucChild->matching_Parent();

                //current parent is still a mitosis (not allready corrected with a better alternative)?
                if(pNucParentCurrent->matching_isMitosis())
                {
                    //possible new parent
                    size_t t_parent = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_T]);
                    size_t i_parent = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_I]);
                    size_t y_parent = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_Y]);
                    size_t x_parent = size_t(vMitosisCorrection[MATCH_ATTRIB_INDEX_PARENT_X]);
                    D_Bio_NucleusBlob *pNucParentNew = &(vvvvNucBlobs_TYXI[t_parent][y_parent][x_parent][i_parent]);

                    //possible new parent is non_mitosis / open_ending? (could have found a better child before)
                    if((allow_new_mitosis && pNucParentNew->matching_isNoMitosis()) || pNucParentNew->matching_foundNoChild())
                    {
                        //remove child from current parent
                        pNucParentCurrent->matching_RemoveChild(pNucChild);

                        //set new parent for child (parent sets child as child internally)
                        pNucChild->matching_SetAsParent(pNucParentNew, score);
                    }
                }
            }
        }
    }
}


