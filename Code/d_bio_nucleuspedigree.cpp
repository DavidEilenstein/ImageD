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
                        size_mosaik_x, vector<D_Bio_NucleusBlob>())));
}

void D_Bio_NucleusPedigree::set_time_irradiation(double t_irr)
{
    time_irradiation = t_irr;

    //existent nucs (not yet split into nuc lifes)
    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
                for(size_t i = 0; i < vvvvNucBlobs_TYXI[t][y][x].size(); i++)
                    vvvvNucBlobs_TYXI[t][y][x][i].set_time_irradiation(time_irradiation);


}

size_t D_Bio_NucleusPedigree::nuclei_blob_count(size_t t, size_t y, size_t x)
{
    if(t >= size_time)      return 0;
    if(y >= size_mosaik_y)  return 0;
    if(x >= size_mosaik_x)  return 0;

    return vvvvNucBlobs_TYXI[t][y][x].size();
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

size_t D_Bio_NucleusPedigree::mosaik_index_non_empty_min_x()
{
    size_t min_x = size_mosaik_x;

    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
                if(!vvvvNucBlobs_TYXI[t][y][x].empty())
                    if(x < min_x)
                        min_x = x;

    return min_x;
}

size_t D_Bio_NucleusPedigree::mosaik_index_non_empty_max_x()
{
    size_t max_x = 0;

    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
                if(!vvvvNucBlobs_TYXI[t][y][x].empty())
                    if(x > max_x)
                        max_x = x;

    return max_x;
}

size_t D_Bio_NucleusPedigree::mosaik_index_non_empty_min_y()
{
    size_t min_y = size_mosaik_y;

    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
                if(!vvvvNucBlobs_TYXI[t][y][x].empty())
                    if(y < min_y)
                        min_y = y;

    return min_y;
}

size_t D_Bio_NucleusPedigree::mosaik_index_non_empty_max_y()
{
    size_t max_y = 0;

    for(size_t t = 0; t < vvvvNucBlobs_TYXI.size(); t++)
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
                if(!vvvvNucBlobs_TYXI[t][y][x].empty())
                    if(y > max_y)
                        max_y = y;

    return max_y;
}

QString D_Bio_NucleusPedigree::info()
{
    QString info = "D_Bio_NucleusPedigree::info\n";

    if(state_NucLifesCalced)
    {
        const size_t n_max = 3;

        if(state_NucLifesFilteredCalced)
            info.append("Nuc lifes calced and filtered\n");
        else
            info.append("No nuc lifes calced\n");

        info.append("Mosaic size: T=" + QString::number(size_T()) + ", Y=" + QString::number(size_Y()) + ", X=" + QString::number(size_X()) + "\n");

        info.append("=============================================\n");
        size_t nl = vNucLifes.size();
        size_t nl_max = min(nl, n_max);
        for(size_t l = 0; l < nl_max; l++)
        {
            D_Bio_NucleusLife* pNucLife = &(vNucLifes[l]);

            if(pNucLife != nullptr)
            {
                info.append("::::::::::::::::::::::::::::::::::::: NucLife " + QString::number(l) + "/" + QString::number(nl) + "\n");

                size_t nb = pNucLife->members_count();
                size_t nb_max = min(nb, n_max);
                for(size_t b = 0; b < nb_max; b++)
                {
                    D_Bio_NucleusBlob* pNucBlob = pNucLife->pNuc_member(b);

                    if(pNucBlob != nullptr)
                    {
                        info.append("_____________________________ NucBlob " + QString::number(b) + "/" + QString::number(nb) + "\n");

                        size_t nc = pNucBlob->get_FociChannels();
                        for(size_t c = 0; c < nc; c++)
                        {
                            info.append("......................... Channel " + QString::number(c) + "/" + QString::number(nc) + "\n");

                            size_t nf = pNucBlob->get_FociCount(c);
                            size_t nf_max = min(nf, n_max);
                            for(size_t f = 0; f < nf_max; f++)
                            {
                                D_Bio_Focus* pFoc = pNucBlob->get_pFocus(c, f);

                                if(pFoc != nullptr)
                                {
                                    info.append("----------------- Focus " + QString::number(f) + "/" + QString::number(nf) + "\n");
                                }
                            }
                        }
                    }
                }
            }
        }
        info.append("\n");
    }
    else
    {
        info.append("No nuc lifes calced\n");
        info.append("Mosaic size: T=" + QString::number(size_T()) + ", Y=" + QString::number(size_Y()) + ", X=" + QString::number(size_X()) + "\n");
    }

    return info;
}

void D_Bio_NucleusPedigree::info_debug()
{
    //qDebug() << info();

    qDebug() << "D_Bio_NucleusPedigree::info() XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    if(state_NucLifesCalced && state_NucLifesFilteredCalced)
        qDebug() << "STATE: Nuc lifes calced and filtered";
    else if(state_NucLifesCalced)
        qDebug() << "STATE: Nuc lifes calced but not filtered";
    else
        qDebug() << "STATE: No nuc lifes calced\n";

    qDebug() << "Mosaic size: T=" << size_T() << ", Y=" << size_Y() << ", X=" << size_X();
    if(size_T() > 0 && size_Y() > 0 && size_X() > 0)
    {
        if(vvvvNucBlobs_TYXI[0][0][0].size() > 0)
        {
            qDebug() << "1st NucBlob of all (vvvvNucBlobs_TYXI[0][0][0][0])";
            size_t nc = vvvvNucBlobs_TYXI[0][0][0][0].get_FociChannels();

            qDebug() << "foci channels:" << nc;
            for(size_t c = 0; c < nc; c++)
                qDebug() << "focus channel" << c << "has" << vvvvNucBlobs_TYXI[0][0][0][0].get_FociCount(c) << "foci";
        }
        else
        {
            qDebug() << "1st mosaic cell is empty";
        }
    }
    else
    {
        qDebug() << "Mosaic is not init with non empty size !!!!!!!!!!!!!!";
    }

    if(state_NucLifesCalced)
    {
        const size_t n_max = 3;

        qDebug() << "=============================================";
        size_t nl = vNucLifes.size();
        size_t nl_max = min(nl, n_max);
        for(size_t l = 0; l < nl_max; l++)
        {
            D_Bio_NucleusLife* pNucLife = &(vNucLifes[l]);

            if(pNucLife == nullptr)
            {
                qDebug() << "::::::::::::::::::::::::::::::::::::: NucLife " << l << "/" << nl << "!!! NULLPTR !!!";
            }
            else
            {
                qDebug() << "::::::::::::::::::::::::::::::::::::: NucLife " << l << "/" << nl;

                size_t nb = pNucLife->members_count();
                size_t nb_max = min(nb, n_max);
                for(size_t b = 0; b < nb_max; b++)
                {
                    D_Bio_NucleusBlob* pNucBlob = pNucLife->pNuc_member(b);

                    if(pNucBlob == nullptr)
                    {
                        qDebug() << "_____________________________ NucBlob " << b << "/" << nb << "!!! NULLPTR !!!";
                    }
                    else
                    {
                        qDebug() << "_____________________________ NucBlob " << b << "/" << nb;

                        size_t nc = pNucBlob->get_FociChannels();

                        if(nc <= 0)
                        {
                            qDebug() << "......................... No foci channels exist";
                        }
                        else
                        {
                            for(size_t c = 0; c < nc; c++)
                            {
                                qDebug() << "......................... Channel " << c << "/" << nc;

                                size_t nf = pNucBlob->get_FociCount(c);
                                size_t nf_max = min(nf, n_max);
                                for(size_t f = 0; f < nf_max; f++)
                                {
                                    D_Bio_Focus* pFoc = pNucBlob->get_pFocus(c, f);

                                    if(pFoc == nullptr)
                                    {
                                        qDebug() << "----------------- Focus " << f << "/" << nf << "!!! NULLPTR !!!";
                                    }
                                    else
                                    {
                                        qDebug() << "----------------- Focus " << f << "/" << nf;
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

void D_Bio_NucleusPedigree::info_popup()
{
    QMessageBox::information(
                nullptr,
                "D_Bio_NucleusPedigree::info_popup()",
                info());
}

D_Bio_NucleusBlob *D_Bio_NucleusPedigree::get_pNucleus(size_t t, size_t y_mosaic, size_t x_mosaic, size_t i)
{
    if(t >= size_time)                                          return nullptr;
    if(y_mosaic >= size_mosaik_y)                               return nullptr;
    if(x_mosaic >= size_mosaik_x)                               return nullptr;
    if(i >= vvvvNucBlobs_TYXI[t][y_mosaic][x_mosaic].size())    return nullptr;

    return &(vvvvNucBlobs_TYXI[t][y_mosaic][x_mosaic][i]);
}

D_Bio_NucleusBlob *D_Bio_NucleusPedigree::get_pNucleus(size_t t, size_t y_mosaic_min, size_t x_mosaic_min, size_t y_mosaic_max, size_t x_mosaic_max, size_t y_pos_px, size_t x_pos_px)
{
    //time range
    if(t >= size_time)
        return nullptr;

    //mosaic ROI
    size_t ym_min = min(max(size_t(0), y_mosaic_min), size_mosaik_y);
    size_t xm_min = min(max(size_t(0), x_mosaic_min), size_mosaik_x);
    size_t ym_max = min(max(size_t(0), y_mosaic_max), size_mosaik_y);
    size_t xm_max = min(max(size_t(0), x_mosaic_max), size_mosaik_x);

    //Point to find
    Point2f P_Find(x_pos_px, y_pos_px);

    //best hit found
    double dist_best = INFINITY;
    D_Bio_NucleusBlob* pNucBest = nullptr;

    //loop mosaic range
    for(size_t ym = ym_min; ym < ym_max; ym++)
    {
        for(size_t xm = xm_min; xm < xm_max; xm++)
        {
            size_t ni = vvvvNucBlobs_TYXI[t][ym][xm].size();
            for(size_t i = 0; i < ni; i++)
            {
                //nuc to be tested
                D_Bio_NucleusBlob* pNucTest = &(vvvvNucBlobs_TYXI[t][ym][xm][i]);

                //dist to contour
                double dist = pNucTest->dist2contour(P_Find);

                //point inside contour?
                if(dist <= 0)
                {
                    //closer then previous best
                    if(abs(dist) < dist_best)
                    {
                        dist_best = abs(dist);
                        pNucBest = pNucTest;
                    }
                }
            }
        }
    }

    return pNucBest;
}

bool D_Bio_NucleusPedigree::load_nuclei_data(QString QS_path_NucDataMaster, QString QS_path_NucData, size_t nt, size_t ny, size_t nx, bool forget_contour, bool foci_are_part_of_nuc_files)
{
    QDir DIR_LoadNucDataMaster(QS_path_NucDataMaster);
    QDir DIR_LoadNucData(QS_path_NucData);

    if(!DIR_LoadNucDataMaster.exists() || !DIR_LoadNucData.exists())
        return false;

    //clear and resize
    clear();
    set_size_time_and_mosaik(nt, ny, nx);

    //load data
    vector<std::thread> vThreadsData(nt);
    for(size_t t = 0; t < nt; t++)
        vThreadsData[t] = std::thread(
                    load_time_nuclei_data_thread,
                    &vvvvNucBlobs_TYXI,
                    DIR_LoadNucDataMaster,
                    DIR_LoadNucData,
                    t,
                    forget_contour,
                    foci_are_part_of_nuc_files);

    for(size_t t = 0; t < nt; t++)
        vThreadsData[t].join();

    //qDebug() << "D_Bio_NucleusPedigree::load_nuclei_data" << "end";
    return true;
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
                        vNodeColor.push_back(pNucChild->matching_TypeColor(FrameInMarginXY, 0, vvvvNucBlobs_TYXI.size() - 1));

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
    vector<std::thread> vThreads(nt_threads);

    ///start threads
    //qDebug() << "updatePedigreeView_Volumetric" << "start" << nt_threads << "threads";
    for(size_t t_thread = 0; t_thread < nt_threads; t_thread++)
    {
        //start the thread
        vThreads[t_thread] = std::thread(
                    updatePedigreeView_Volumetric_TimeThread,
                    &VD_PlotVol,
                    &vvvvNucBlobs_TYXI,
                    score_range,
                    score_min,
                    size_Node_px,
                    size_Edge_px,
                    size_Y_px_original,
                    size_X_px_original,
                    FrameInMarginXY,
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

void D_Bio_NucleusPedigree::set_FrameBorder_XY(Rect FrameBorder)
{
    FrameBorderXY = FrameBorder;

    for(size_t l = 0; l < vNucLifes.size(); l++)
        vNucLifes[l].set_FrameBorder_XY(FrameBorderXY);

    for(size_t l = 0; l < vNucLifes_Filtered.size(); l++)
        vNucLifes_Filtered[l].set_FrameBorder_XY(FrameBorderXY);
}

bool D_Bio_NucleusPedigree::set_attrib_filter_ui(QGroupBox *box_foci, QGroupBox *box_nucblobs, QGroupBox *box_nuclifes)
{
    if(state_AttribFiltersSet)
        return false;

    //foci
    pAttribFilter_Foci = new D_Bio_Attribute_Filter(box_foci);
    pAttribFilter_Foci->set_filter_mode(ATTRIB_FILTER_MODE_FOCI);
    connect(pAttribFilter_Foci, SIGNAL(FilterParamsChanged()), this, SLOT(SetAttribFilterToNeedUpdate()));

    //nuc blobs
    pAttribFilter_NucBlobs   = new D_Bio_Attribute_Filter(box_nucblobs);
    pAttribFilter_NucBlobs->set_filter_mode(ATTRIB_FILTER_MODE_NUC_BLOB);
    connect(pAttribFilter_NucBlobs, SIGNAL(FilterParamsChanged()), this, SLOT(SetAttribFilterToNeedUpdate()));

    //nuc lifes
    pAttribFilter_NucLifes  = new D_Bio_Attribute_Filter(box_nuclifes);
    pAttribFilter_NucLifes->set_filter_mode(ATTRIB_FILTER_MODE_NUC_LIFE);
    connect(pAttribFilter_NucLifes, SIGNAL(FilterParamsChanged()), this, SLOT(SetAttribFilterToNeedUpdate()));

    state_AttribFiltersSet = true;
    return true;
}

bool D_Bio_NucleusPedigree::set_attrib_filter_channels(QStringList channels_foc, QStringList channels_val)
{
    if(!state_AttribFiltersSet)
        return false;

    pAttribFilter_Foci->set_channels(channels_foc, channels_val);
    pAttribFilter_NucBlobs->set_channels(channels_foc, channels_val);
    pAttribFilter_NucLifes->set_channels(channels_foc, channels_val);

    return true;
}

bool D_Bio_NucleusPedigree::set_attrib_filter_scaling()
{
    if(!state_AttribFiltersSet)
        return false;

    pAttribFilter_Foci->set_ScalePx2Um(scale_px_to_um);
    pAttribFilter_NucBlobs->set_ScalePx2Um(scale_px_to_um);
    pAttribFilter_NucLifes->set_ScalePx2Um(scale_px_to_um);

    return true;
}

bool D_Bio_NucleusPedigree::set_attrib_filter(size_t filter_mode, size_t i_filt, bool is_active, size_t i_att, size_t i_comp, size_t i_ch, double thres_val)
{
    D_Bio_Attribute_Filter* pAttFilter;

    switch (filter_mode) {
    case ATTRIB_FILTER_MODE_FOCI:       pAttFilter = pAttribFilter_Foci;        break;
    case ATTRIB_FILTER_MODE_NUC_BLOB:   pAttFilter = pAttribFilter_NucBlobs;    break;
    case ATTRIB_FILTER_MODE_NUC_LIFE:   pAttFilter = pAttribFilter_NucLifes;    break;
    default:                                                                    return false;}

    if(pAttFilter == nullptr)
        return false;

    return pAttFilter->set_filter(
                i_filt,
                is_active,
                i_att,
                i_comp,
                i_ch,
                thres_val);
}

bool D_Bio_NucleusPedigree::calc_NucLifes()
{
    //clear nuc lifes
    vNucLifes.clear();
    state_NucLifesCalced = false;

    // loop all nucs
    for(size_t t = 0; t < size_time; t++)
    {
        for(size_t y = 0; y < vvvvNucBlobs_TYXI[t].size(); y++)
        {
            for(size_t x = 0; x < vvvvNucBlobs_TYXI[t][y].size(); x++)
            {
                for(size_t i = 0; i < vvvvNucBlobs_TYXI[t][y][x].size(); i++)
                {
                    D_Bio_NucleusBlob* pNuc = &(vvvvNucBlobs_TYXI[t][y][x][i]);

                    //Nucleus is begin of new tracking?
                    if(pNuc->matching_foundNoParent() || pNuc->matching_parent_isMitosis())
                    {
                        D_Bio_NucleusLife NewNucLife;

                        if(pNuc->matching_foundParent())
                            NewNucLife.set_Parent(pNuc->matching_Parent());

                        //loop member nucs
                        NewNucLife.add_Member(*pNuc);
                        while(pNuc->matching_foundExactlyOneChild())
                        {
                            pNuc = pNuc->matching_ChildFavorite();
                            NewNucLife.add_Member(*pNuc);
                        }

                        //childs
                        if(pNuc->matching_isMitosis())
                        {
                            NewNucLife.set_Child1(pNuc->matching_Child1());
                            NewNucLife.set_Child2(pNuc->matching_Child2());
                        }

                        //set other params
                        NewNucLife.set_sizeTime(size_time);
                        NewNucLife.set_FrameInMargin_XY(FrameInMarginXY);
                        NewNucLife.set_FrameBorder_XY(FrameBorderXY);
                        NewNucLife.set_ScalePx2Um(scale_px_to_um);
                        NewNucLife.set_time_irradiation(time_irradiation);

                        //add nuc life to vector
                        vNucLifes.push_back(NewNucLife);
                    }
                }
            }
        }
    }

    state_NucLifesCalced = true;
    return true;
}

bool D_Bio_NucleusPedigree::calc_NucLifes_Filtered()
{
    //don't start new filtering, if old one is still running
    if(state_NucLifeFilteringRunning)
        return false;

    //calc initial nuc lifes, if not done yet
    if(!state_NucLifesCalced)
        calc_NucLifes();
    if(!state_NucLifesCalced)
        return false;

    //qDebug() << "D_Bio_NucleusPedigree::calc_NucLifes_Filtered" << "start with unfiltered nuc lifes: n =" << vNucLifes.size();

    //start filtering
    state_NucLifeFilteringRunning = true;

    //clear old filtered nuc lifes
    vNucLifes_Filtered.clear();
    state_NucLifesFilteredCalced = false;

    //loop nuc lifes
    for(size_t l = 0; l < vNucLifes.size(); l++)
    {
        //nuc life to be filtered
        D_Bio_NucleusLife* pNucLifeOriginal = &(vNucLifes[l]);

        //nuc life accepted?
        if(pAttribFilter_NucLifes->accept_NucLife(pNucLifeOriginal))
        {
            //Filtered nuc life
            D_Bio_NucleusLife NucLifeFiltered;

            //copy parent/childs (these are not filtered because that would change the context of the nuc in the tracking)
            if(pNucLifeOriginal->has_Parent())  NucLifeFiltered.set_Parent(pNucLifeOriginal->pNuc_parent());
            if(pNucLifeOriginal->has_Child1())  NucLifeFiltered.set_Child1(pNucLifeOriginal->pNuc_child1());
            if(pNucLifeOriginal->has_Child2())  NucLifeFiltered.set_Child2(pNucLifeOriginal->pNuc_child2());

            //loop nuc blobs (member nuc blobs only - from 1st after mistosis to end or mitosis)
            for(size_t b = 0; b < pNucLifeOriginal->members_count(); b++)
            {
                //nuc blob to be filtered
                D_Bio_NucleusBlob* pNucBlobOriginal = pNucLifeOriginal->pNuc_member(b);

                //nuc blob accepted?
                if(pAttribFilter_NucBlobs->accept_NucBlob(pNucBlobOriginal))
                {
                    //Filtered nuc blob (init with copy to preserve tracking context info etc.)
                    D_Bio_NucleusBlob NucBlobFiltered = *pNucBlobOriginal;

                    //clear original foci from copy (they are filtered next)
                    NucBlobFiltered.clear_Foci();
                    NucBlobFiltered.set_FociChannels(pNucBlobOriginal->get_FociChannels());

                    //set filter independednt infos
                    NucBlobFiltered.set_time_irradiation(time_irradiation);

                    //loop foci channels
                    for(size_t ch = 0; ch < pNucBlobOriginal->get_FociChannels(); ch++)
                    {
                        //loop foci
                        for(size_t f = 0; f < pNucBlobOriginal->get_FociCount(ch); f++)
                        {
                            //foc to be filtered
                            D_Bio_Focus* pFoc = pNucBlobOriginal->get_pFocus(ch, f);

                            //foc accepted?
                            if(pAttribFilter_Foci->accept_Foc(pFoc))
                            {
                                //add filtered focus to filtered nuc
                                NucBlobFiltered.add_Focus(ch, *pFoc);
                            }
                        }
                    }

                    //add filtered nuc to nuc life
                    NucLifeFiltered.add_Member(NucBlobFiltered);
                }
            }

            //set other attribs
            NucLifeFiltered.set_sizeTime(size_time);
            NucLifeFiltered.set_FrameInMargin_XY(FrameInMarginXY);
            NucLifeFiltered.set_FrameBorder_XY(FrameBorderXY);
            NucLifeFiltered.set_ScalePx2Um(scale_px_to_um);
            NucLifeFiltered.set_time_irradiation(time_irradiation);

            //add filtered nuc life to list of filtered nuc lifes (only contains nuc blobs that passed and these only contain foci that passed)
            vNucLifes_Filtered.push_back(NucLifeFiltered);
        }
    }

    //set correct owner nucs of foci (needed to avoid adress of temporary)
    size_t nl = vNucLifes_Filtered.size();
    for(size_t l = 0; l < nl; l++)
    {
        D_Bio_NucleusLife* pNucLife = &(vNucLifes_Filtered[l]);
        size_t nb = pNucLife->members_count();
        for(size_t b = 0; b < nb; b++)
        {
            D_Bio_NucleusBlob* pNucBlob = pNucLife->pNuc_member(b);
            size_t nc = pNucBlob->get_FociChannels();
            for(size_t c = 0; c < nc; c++)
            {
                size_t nf = pNucBlob->get_FociCount(c);
                for(size_t f = 0; f < nf; f++)
                {
                    pNucBlob->get_pFocus(c, f)->set_pNucOwner(pNucBlob);
                }
            }
        }
    }

    //qDebug() << "D_Bio_NucleusPedigree::calc_NucLifes_Filtered" << "end with filtered nuc lifes: n =" << vNucLifes_Filtered.size();

    //finish
    state_NucLifesFilteredCalced = true;
    state_NucLifeFilteringRunning = false;
    return true;
}

vector<double> D_Bio_NucleusPedigree::attrib_data(size_t i_data_pt_lvl, size_t i_att_lvl_nuclife, size_t i_att_lvl_nucblob, size_t i_att_nuclife, size_t i_att_nucblob, size_t i_att_foc, size_t ch_val, size_t ch_foc, size_t stat_low, size_t stat_high)
{
    vector<double> vRes;

    //filter nuc lifes if needed
    if(!state_NucLifesFilteredCalced)
        calc_NucLifes_Filtered();
    if(!state_NucLifesFilteredCalced)
    {
        qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "failed to filter nuc lifes";
        return vRes;
    }

    switch (i_data_pt_lvl) {

    case DATAPOINT_LEVEL_NUCLIFE://------------------------------------------------------------------------
    {
        switch (i_att_lvl_nuclife) {

        case DATA_LEVEL_NUCLIFE_ATTRIB://.....................................................
            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "return nuc life attribs";
            return attrib_nuclife(i_att_nuclife);

        case DATA_LEVEL_NUCLIFE_STAT_NUCBLOB://.....................................................
        {
            function<double (vector<double>)> F_stat_low = D_Stat::Function_SingleStat(int(stat_low));

            size_t nl = vNucLifes_Filtered.size();
            vRes.resize(nl);

            for(size_t l = 0; l < nl; l++)
                vRes[l] = F_stat_low(vNucLifes[l].attrib_nuc(i_att_nucblob, ch_val));

            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "return stat of nuc blob attribs";
            return vRes;
        }

        case DATA_LEVEL_NUCLIFE_STAT_STAT_FOC://.....................................................
        {
            function<double (vector<double>)> F_stat_low  = D_Stat::Function_SingleStat(int(stat_low));
            function<double (vector<double>)> F_stat_high = D_Stat::Function_SingleStat(int(stat_high));

            size_t nl = vNucLifes_Filtered.size();
            vRes.resize(nl);

            for(size_t l = 0; l < nl; l++)
            {
                D_Bio_NucleusLife* pNucLife = &(vNucLifes_Filtered[l]);
                size_t nb = pNucLife->members_count();
                vector<double> vDataNucBlobMembers(nb);

                for(size_t b = 0; b < nb; b++)
                {
                    D_Bio_NucleusBlob* pNucBlob = pNucLife->pNuc_member(b);
                    size_t nf = pNucBlob->get_FociCount(ch_foc);
                    vector<double> vDataFoci(nf);

                    for(size_t f = 0; f < nf; f++)
                        vDataFoci[f] = pNucBlob->get_pFocus(ch_foc, f)->attribute(i_att_foc, ch_val, scale_px_to_um);

                    vDataNucBlobMembers[b] = F_stat_low(vDataFoci);
                }

                vRes[l] = F_stat_high(vDataNucBlobMembers);
            }

            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "return stat of stat of foci attribs";
            return vRes;
        }

        default://.....................................................
            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "nuc life default case - ERROR";
            return vRes;
        }
    }
        break;

    case DATAPOINT_LEVEL_NUCBLOB://------------------------------------------------------------------------
    {
        switch (i_att_lvl_nucblob) {

        case DATA_LEVEL_NUCBLOB_ATTRIB://.....................................................
            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "return nuc blob attribs";
            return attrib_nucblob(i_att_nucblob, ch_val);

        case DATA_LEVEL_NUCBLOB_STAT_FOC://.....................................................
        {
            function<double (vector<double>)> F_stat_low  = D_Stat::Function_SingleStat(int(stat_low));

            size_t nl = vNucLifes_Filtered.size();

            for(size_t l = 0; l < nl; l++)
            {
                D_Bio_NucleusLife* pNucLife = &(vNucLifes_Filtered[l]);
                size_t nb = pNucLife->members_count();

                for(size_t b = 0; b < nb; b++)
                {
                    D_Bio_NucleusBlob* pNucBlob = pNucLife->pNuc_member(b);
                    size_t nf = pNucBlob->get_FociCount(ch_foc);
                    vector<double> vDataFoci(nf);

                    for(size_t f = 0; f < nf; f++)
                        vDataFoci[f] = pNucBlob->get_pFocus(ch_foc, f)->attribute(i_att_foc, ch_val, scale_px_to_um);

                    vRes.push_back(F_stat_low(vDataFoci));
                }
            }

            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "return stat of foci attribs";
            return vRes;
        }

        default://.....................................................
            qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "nuc blob default case - ERROR";
            return vRes;
        }
    }
        break;

    case DATAPOINT_LEVEL_FOC://------------------------------------------------------------------------
        qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "return foci attribs";
        return attrib_foci(i_att_foc, ch_val, ch_foc);

    default://------------------------------------------------------------------------
        qDebug() << "D_Bio_NucleusPedigree::attrib_data" << "data level default case - ERROR";
        return vRes;
    }
}

/*
vector<double> D_Bio_NucleusPedigree::attrib_data(size_t i_data_point_level, size_t i_attrib_level, size_t i_attrib, size_t ch_val, size_t ch_foc, size_t stat_low, size_t stat_high)
{
    //in this function it is assumed, that the passed index params fit to each other - it needs to be managed outside of this function
    return attrib_data(
                i_data_point_level,
                i_attrib_level,
                i_attrib_level,
                i_attrib_level,
                i_attrib,
                i_attrib,
                i_attrib,
                ch_val,
                ch_foc,
                stat_low,
                stat_high);
}
*/

vector<double> D_Bio_NucleusPedigree::attrib_nuclife(size_t i_attrib)
{
    //resulting attribs
    vector<double> vAttribs;

    //attrib valid
    if(i_attrib >= ATTRIB_NUCLIFE_NUMBER_OF)
        return vAttribs;

    //filter nuc lifes if needed
    if(!state_NucLifesFilteredCalced)
        calc_NucLifes_Filtered();
    if(!state_NucLifesFilteredCalced)
        return vAttribs;

    //loop nuc lifes that passed the filter
    for(size_t l = 0; l < vNucLifes_Filtered.size(); l++)
        vAttribs.push_back(vNucLifes_Filtered[l].attrib_nuclife(i_attrib));

    //finish
    return vAttribs;
}

vector<double> D_Bio_NucleusPedigree::attrib_nucblob(size_t i_attrib, size_t ch_val)
{
    //resulting attribs
    vector<double> vAttribs;

    //attrib valid
    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return vAttribs;

    //filter nuc lifes if needed
    if(!state_NucLifesFilteredCalced)
        calc_NucLifes_Filtered();
    if(!state_NucLifesFilteredCalced)
        return vAttribs;

    //loop nuc lifes that passed the filter
    for(size_t l = 0; l < vNucLifes_Filtered.size(); l++)
        vNucLifes_Filtered[l].attrib_nuc(&vAttribs, i_attrib, ch_val);

    //finish
    return vAttribs;
}

vector<double> D_Bio_NucleusPedigree::attrib_foci(size_t i_attrib, size_t ch_val)
{
    //resulting attribs
    vector<double> vAttribs;

    //attrib valid
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return vAttribs;

    //filter nuc lifes if needed
    if(!state_NucLifesFilteredCalced)
        calc_NucLifes_Filtered();
    if(!state_NucLifesFilteredCalced)
        return vAttribs;

    //loop nuc lifes that passed the filter
    for(size_t l = 0; l < vNucLifes_Filtered.size(); l++)
        vNucLifes_Filtered[l].attrib_foc(&vAttribs, i_attrib, ch_val);

    //finish
    return vAttribs;
}

vector<double> D_Bio_NucleusPedigree::attrib_foci(size_t i_attrib, size_t ch_val, size_t ch_foc)
{
    //resulting attribs
    vector<double> vAttribs;

    //attrib valid
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return vAttribs;

    //filter nuc lifes if needed
    if(!state_NucLifesFilteredCalced)
        calc_NucLifes_Filtered();
    if(!state_NucLifesFilteredCalced)
        return vAttribs;

    //loop nuc lifes that passed the filter
    for(size_t l = 0; l < vNucLifes_Filtered.size(); l++)
        vNucLifes_Filtered[l].attrib_foc(&vAttribs, i_attrib, ch_val, ch_foc);

    //finish
    return vAttribs;
}

bool D_Bio_NucleusPedigree::save_analysis(QString QS_SavePath)
{
    if(QS_SavePath.isEmpty())
        return false;

    QDir DIR_SaveMaster(QS_SavePath);
    if(DIR_SaveMaster.exists())
        return false;
    QDir().mkdir(DIR_SaveMaster.path());
    if(!DIR_SaveMaster.exists())
        return false;

    if(!save_attribs_raw(DIR_SaveMaster))
        return false;

    return true;
}

bool D_Bio_NucleusPedigree::data_filtered_exists(size_t data_level)
{
    switch (data_level) {

    case DATAPOINT_LEVEL_FOC:
    {
        size_t nl = vNucLifes_Filtered.size();
        if(nl == 0)
            return false;

        for(size_t l = 0; l < nl; l++)
        {
            size_t nb = vNucLifes_Filtered[l].members_count();
            for(size_t b = 0; b < nb; b++)
            {
                size_t nc = vNucLifes_Filtered[l].pNuc_member(b)->get_FociChannels();
                for(size_t c = 0; c < nc; c++)
                {
                    size_t nf = vNucLifes_Filtered[l].pNuc_member(b)->get_FociCount(c);
                    if(nf > 0)
                        return true;
                }
            }
        }
    }
        return false;

    case DATAPOINT_LEVEL_NUCBLOB:
    {
        size_t nl = vNucLifes_Filtered.size();
        if(nl == 0)
            return false;

        for(size_t l = 0; l < nl; l++)
        {
            size_t nb = vNucLifes_Filtered[l].members_count();
            if(nb > 0)
                return true;
        }
    }
        return false;

    case DATAPOINT_LEVEL_NUCLIFE:
    {
        size_t nl = vNucLifes_Filtered.size();
        if(nl > 0)
            return true;
    }
        return false;

    default:
        return false;
    }
}

bool D_Bio_NucleusPedigree::save_attribs_raw(QDir DIR_SaveMaster)
{
    if(!DIR_SaveMaster.exists())
        return false;

    QDir DIR_SaveAttribsRaw(DIR_SaveMaster.path() + "/Attribs raw");
    QDir().mkdir(DIR_SaveAttribsRaw.path());
    if(!DIR_SaveAttribsRaw.exists())
        return false;

    if(!save_attribs_raw(QFileInfo(DIR_SaveAttribsRaw.path() + "/Attribs_raw_Foci.csv"), DATAPOINT_LEVEL_FOC))
        return false;

    if(!save_attribs_raw(QFileInfo(DIR_SaveAttribsRaw.path() + "/Attribs_raw_NucBlobs.csv"), DATAPOINT_LEVEL_NUCBLOB))
        return false;

    if(!save_attribs_raw(QFileInfo(DIR_SaveAttribsRaw.path() + "/Attribs_raw_NucLifes.csv"), DATAPOINT_LEVEL_NUCLIFE))
        return false;

    return true;
}

bool D_Bio_NucleusPedigree::save_attribs_raw(QFileInfo FI_SaveCsv, size_t data_level)
{
    if(data_level >= DATAPOINT_LEVEL_NUMBER_OF)
        return false;

    if(FI_SaveCsv.suffix() != "csv")
        return false;

    //filter data
    if(!state_NucLifesFilteredCalced)
        calc_NucLifes_Filtered();
    if(!state_NucLifesFilteredCalced)
        return false;

    //stream
    ofstream OS;
    OS.open(FI_SaveCsv.absoluteFilePath().toStdString());
    if(!OS.is_open())
        return false;

    //header
    OS << "Raw Attributes;" << QSL_DatapointLevel[data_level].toStdString();
    OS << "\n" << FI_SaveCsv.absoluteFilePath().toStdString();
    OS << "\n" << QDateTime::currentDateTime().toString().toStdString();
    OS << "\n" << "ImageD version;" << D_QS_Version.toStdString() << ";" << D_QS_Release.toStdString();
    OS << "\n";

    //data exists?
    if(!data_filtered_exists(data_level))
    {
        OS << "\n" << "No " << QSL_DatapointLevel[data_level].toStdString() << " exists!!!";
        OS.close();
        return true;
    }

    //data
    switch (data_level) {

    case DATAPOINT_LEVEL_FOC:
    {
        //attribs (column headers)
        OS << "\n";
        size_t n_a = ATTRIB_FOC_NUMBER_OF;
        for(size_t a = 0; a < n_a; a++)
        {
            if(D_Bio_Focus::attribute_is_focus_channel_dependent(a))
            {
                size_t n_ch = QSL_Channels_Foci.size();
                for(size_t ch = 0; ch < n_ch; ch++)
                    OS << ";" << QSL_Attrib_Foc[a].toStdString() << " (" << QSL_Channels_Foci[ch].toStdString() << ")";
            }
            else if(D_Bio_Focus::attribute_is_value_channel_dependent(a))
            {
                size_t n_ch = QSL_Channels_Values.size();
                for(size_t ch = 0; ch < n_ch; ch++)
                    OS << ";" << QSL_Attrib_Foc[a].toStdString() << " (" << QSL_Channels_Values[ch].toStdString() << ")";
            }
            else
            {
                OS << ";" << QSL_Attrib_Foc[a].toStdString();
            }
        }
    }
        break;

    case DATAPOINT_LEVEL_NUCBLOB:
    {
        //attribs (column headers)
        OS << "\n";
        size_t n_a = ATTRIB_NUC_NUMBER_OF;
        for(size_t a = 0; a < n_a; a++)
        {
            if(D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(a))
            {
                size_t n_ch = QSL_Channels_Foci.size();
                for(size_t ch = 0; ch < n_ch; ch++)
                    OS << ";" << QSL_Attrib_Nuc[a].toStdString() << " (" << QSL_Channels_Foci[ch].toStdString() << ")";
            }
            else if(D_Bio_NucleusBlob::attribute_is_value_channel_dependent(a))
            {
                size_t n_ch = QSL_Channels_Values.size();
                for(size_t ch = 0; ch < n_ch; ch++)
                    OS << ";" << QSL_Attrib_Nuc[a].toStdString() << " (" << QSL_Channels_Values[ch].toStdString() << ")";
            }
            else
            {
                OS << ";" << QSL_Attrib_Nuc[a].toStdString();
            }
        }
    }
        break;

    case DATAPOINT_LEVEL_NUCLIFE:
    {
        //attribs (column headers)
        OS << "\n";
        size_t n_a = ATTRIB_NUCLIFE_NUMBER_OF;
        for(size_t a = 0; a < n_a; a++)
        {
            if(D_Bio_NucleusLife::attribute_is_focus_channel_dependent(a))
            {
                size_t n_ch = QSL_Channels_Foci.size();
                for(size_t ch = 0; ch < n_ch; ch++)
                    OS << ";" << QSL_Attrib_NucLife[a].toStdString() << " (" << QSL_Channels_Foci[ch].toStdString() << ")";
            }
            else if(D_Bio_NucleusLife::attribute_is_value_channel_dependent(a))
            {
                size_t n_ch = QSL_Channels_Values.size();
                for(size_t ch = 0; ch < n_ch; ch++)
                    OS << ";" << QSL_Attrib_NucLife[a].toStdString() << " (" << QSL_Channels_Values[ch].toStdString() << ")";
            }
            else
            {
                OS << ";" << QSL_Attrib_NucLife[a].toStdString();
            }
        }
    }
        break;

    default:
        return false;
    }

    OS.close();
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
    vector<std::thread> vThreads(nt);
    for(size_t t = 0; t < nt; t++)
        vThreads[t] = std::thread(
                    match_save_results_time_thread,
                    &vvvvNucBlobs_TYXI,
                    DIR_SaveMaster,
                    t);

    for(size_t t = 0; t < nt; t++)
        vThreads[t].join();

    return true;
}

bool D_Bio_NucleusPedigree::match_load_data_and_matches(QString QS_path_NucDataMaster, QString QS_path_NucData, QString QS_path_NucLifes, size_t nt, size_t ny, size_t nx, bool forget_contour, bool foci_are_part_of_nuc_files)
{    
    if(!load_nuclei_data(QS_path_NucDataMaster, QS_path_NucData, nt, ny, nx, forget_contour, foci_are_part_of_nuc_files))
        return false;

    if(!match_load_matches(QS_path_NucLifes))
        return false;

    return true;
}

bool D_Bio_NucleusPedigree::match_load_matches(QString QS_path_NucLifes)
{
    QDir DIR_LoadNucLifes(QS_path_NucLifes);
    if(!DIR_LoadNucLifes.exists())
        return false;

    //load matches
    vector<std::thread> vThreadsMatch(size_time);
    for(size_t t = 0; t < size_time; t++)
        vThreadsMatch[t] = std::thread(
                    load_time_nuclei_matches_thread,
                    &vvvvNucBlobs_TYXI,
                    DIR_LoadNucLifes,
                    t);

    for(size_t t = 0; t < size_time; t++)
        vThreadsMatch[t].join();

    return true;
}

void D_Bio_NucleusPedigree::SetAttribFilterToNeedUpdate()
{
    state_NucLifesFilteredCalced = false;
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

bool D_Bio_NucleusPedigree::load_time_nuclei_data_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, QDir DirLoadMaster, QDir DirLoadNucs, size_t t_thread, bool forget_contour, bool foci_are_part_of_nuc_files)
{
    //CONTINUE HERE: Make this method load foci too and not only nuclei !!!

    //sizes
    size_t nt = (*pvvvvNucsTYXI).size();
    if(nt <= 0 || t_thread >= nt)
        return false;

    size_t ny = (*pvvvvNucsTYXI)[0].size();
    if(ny <= 0)
        return false;

    size_t nx = (*pvvvvNucsTYXI)[0][0].size();
    if(nx <= 0)
        return false;

    //dirs exist?
    if(!DirLoadMaster.exists())
        return false;

    //detections dir time t
    QDir DIR_t(DirLoadNucs.path() + "/Time_" + QString::number(t_thread));
    if(!DIR_t.exists())
        return false;

    if(DIR_t.exists())
    {
        //get image directories
        QStringList QSL_ImageDirs = DIR_t.entryList(QDir::Dirs | QDir::NoDot | QDir::NoDotDot);

        //loop image dirs
        for(int d = 0; d < QSL_ImageDirs.size(); d++)
        {
            //image dir
            QString QS_ImageDirName = QSL_ImageDirs[d];
            QDir DIR_ImageTYX(DIR_t.path() + "/" + QS_ImageDirName);

            //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << QS_ImageDirName;
            //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "DIR" << DIR_ImageTYX.path();
            if(DIR_ImageTYX.exists())
            {
                //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "dir exists";

                //check if indicatros contained
                if(QS_ImageDirName.contains("Image_T" + QString::number(t_thread)) && QS_ImageDirName.contains("_Y") && QS_ImageDirName.contains("_X"))
                {
                    //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "indicator strings contained" << QS_ImageDirName;

                    //blocks in dir name
                    QStringList QSL_ImageDirBlocks = QS_ImageDirName.split("_");
                    if(QSL_ImageDirBlocks.size() == 4)  //Image _ T* _ Y* _ X*
                    {                                   //0       1    2    3
                        //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "correct block count of name" << QSL_ImageDirBlocks;

                        //get x
                        bool ok_x;
                        QString QS_BlockX = QSL_ImageDirBlocks[3];
                        QS_BlockX = QS_BlockX.remove(0, 1);
                        int dir_x = QS_BlockX.toInt(&ok_x);

                        //get y
                        bool ok_y;
                        QString QS_BlockY = QSL_ImageDirBlocks[2];
                        QS_BlockY = QS_BlockY.remove(0, 1);
                        int dir_y = QS_BlockY.toInt(&ok_y);

                        //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "read x/y" << QSL_ImageDirBlocks[3] << QSL_ImageDirBlocks[2] << "reduced to" << QS_BlockX << QS_BlockY;

                        //conversion to numbers worked?
                        if(ok_x && ok_y)
                        {
                            //mosaik indices
                            size_t ix = dir_x;
                            size_t iy = dir_y;

                            //indices in range?
                            if(ix < nx && iy < ny)
                            {
                                //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "mosaic coordinates in range";

                                //load nucleus image
                                D_Bio_NucleusImage NucImg;
                                if(NucImg.load(DIR_ImageTYX.path(), foci_are_part_of_nuc_files) == ER_okay)
                                {
                                    //set mosaic offset
                                    NucImg.set_OffsetMosaicGrid(Point(ix, iy));

                                    //test
                                    //qDebug() << "D_MAKRO_MegaFoci::MS4_LoadDetections" << "Loaded x/y" << ix << iy << NucImg.info();

                                    //loop nuclei
                                    size_t n_nuc = NucImg.get_nuclei_count();
                                    //qDebug() << "D_Bio_NucleusPedigree::load_time_nuclei_data_thread" << n_nuc << "nuclei in t/y/x" << t_thread << iy << ix;
                                    for(size_t nuc = 0; nuc < n_nuc; nuc++)
                                    {
                                        //get Nuc
                                        D_Bio_NucleusBlob NucBlob = NucImg.get_nucleus(nuc);

                                        //forget contour to save memory in this step
                                        if(forget_contour)
                                            NucBlob.forget_contour_and_calc_feats();

                                        //set path (needed for beeing able to save the pedigree as relative paths lists after reconstruction)
                                        NucBlob.set_path_absolute(
                                                    NucBlob.get_path_absolute_loaded_from(),
                                                    DirLoadMaster);

                                        //set time
                                        NucBlob.set_time_index(t_thread);

                                        //add nucleus to stack of nuclei to be matched
                                        (*pvvvvNucsTYXI)[t_thread][iy][ix].push_back(NucBlob);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool D_Bio_NucleusPedigree::load_time_nuclei_matches_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, QDir DirLoadNucLifes, size_t t_thread)
{
    if(!DirLoadNucLifes.exists())
            return false;

    if(t_thread >= pvvvvNucsTYXI->size())
        return false;

    //load dir for time
    QDir DirLoadTime;
    DirLoadTime.setPath(DirLoadNucLifes.path() + "/Time_" + QString::number(t_thread));
    //if(t_thread == 0) qDebug() << "time dir    " << DirLoadTime.path();

    //Sub Dirs
    QFileInfoList FIL_ImgDirs = DirLoadTime.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(int d = 0; d < FIL_ImgDirs.size(); d++)
    {
        //entry in time dir
        QFileInfo FI_ThingInTimeDir = FIL_ImgDirs[d];
        //if(t_thread == 0) qDebug() << "Time entry  " << FI_ThingInTimeDir.absoluteFilePath() << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

        //check, if it is a dir
        if(FI_ThingInTimeDir.isDir())
        {
            //Sub dir for img
            QDir DIR_ImageYX(FI_ThingInTimeDir.absoluteFilePath());
            //if(t_thread == 0) qDebug() << "Image Dir   " << DIR_ImageYX.path() << "========================================";

            //check existance
            if(DIR_ImageYX.exists())
            {
                //nuc life files
                QStringList QSl_NameFilterTxt = {"*txt", "*.TXT"};
                QFileInfoList FIL_NucLifeTxts = DIR_ImageYX.entryInfoList(QSl_NameFilterTxt);
                for(int f = 0; f < FIL_NucLifeTxts.size(); f++)
                {
                    //file info
                    QFileInfo FI_NucLifeTxt = FIL_NucLifeTxts[f];
                    //if(t_thread == 0) qDebug() << "Nuc Life txt" << FI_NucLifeTxt.absoluteFilePath() << "-------------------------";

                    //check, if txt
                    if(FI_NucLifeTxt.suffix() == "txt" || FI_NucLifeTxt.suffix() == "TXT")
                    {
                        //check existance
                        if(FI_NucLifeTxt.exists())
                        {
                            //is nuc life file?
                            if(FI_NucLifeTxt.baseName().contains("NucleusLife_T") && FI_NucLifeTxt.baseName().contains("_Y") && FI_NucLifeTxt.baseName().contains("_X"))
                            {
                                //File
                                QFile F_NucLife(FI_NucLifeTxt.absoluteFilePath());
                                //if(t_thread == 0) qDebug() << "open file" << F_NucLife;
                                if(F_NucLife.open(QIODevice::ReadOnly))
                                {
                                    //nucs found before (used to create a match, when nuc after this is found)
                                    bool nuc_before_found = false;
                                    D_Bio_NucleusBlob* nuc_before_ptr = nullptr;

                                    //section indicator
                                    int section_indicator = -1;

                                    //stream
                                    QTextStream TS_NucLife(&F_NucLife);
                                    while(!TS_NucLife.atEnd())
                                    {
                                        //read line
                                        QString QS_Line = TS_NucLife.readLine();
                                        //if(t_thread == 0) qDebug() << "Line" << QS_Line << "..............";
                                        //example of path line: "/DetectionsAssigned/Time_2/Image_T2_Y0_X1/Nucleus_T2_Y715_X2290.txt"

                                        //check for new section
                                        bool new_section_indicator_found = false;
                                        for(int s = 0; s < NUC_LIFE_FILE_SECTION_NUMBER_OF && !new_section_indicator_found; s++)
                                        {
                                            if(QS_Line == QSL_NucLifeFileSections[s])
                                            {
                                                section_indicator = s;
                                                new_section_indicator_found = true;
                                                //if(t_thread == 0) qDebug() << "Section" << QSL_NucLifeFileSections[s] << "found";
                                            }
                                        }

                                        //no new section? -> line contains info that needs to be loaded
                                        if(!new_section_indicator_found)
                                        {
                                            //section with paths
                                            if(section_indicator == NUC_LIFE_FILE_SECTION_PARENT || section_indicator == NUC_LIFE_FILE_SECTION_MEMBERS || section_indicator == NUC_LIFE_FILE_SECTION_CHILDS)
                                            {
                                                //if(t_thread == 0) qDebug() << "Path section";

                                                //is not empty?
                                                if(!QS_Line.isEmpty())
                                                {
                                                    //is relative path?
                                                    if(QS_Line[0] == "/")
                                                    {
                                                        //txt path?
                                                        if(QS_Line.endsWith(".txt") || QS_Line.endsWith(".TXT"))
                                                        {
                                                            //if(t_thread == 0) qDebug() << "is rel path text file";

                                                            //dirs and file name blocks
                                                            QStringList QSL_Blocks = QS_Line.split("/");
                                                            //if(t_thread == 0) qDebug() << "path blocks" << QSL_Blocks;

                                                            //enough blocs to find identifiers?
                                                            int n_blocks = QSL_Blocks.size();
                                                            if(n_blocks >= 3)
                                                            {
                                                                //relevant blocks
                                                                //example of path line: "/DetectionsAssigned/Time_2/Image_T2_Y0_X1/Nucleus_T2_Y715_X2290.txt"
                                                              //QString QS_BlockName    = QSL_Blocks[n_blocks - 1]; //Nucleus_T2_Y715_X2290.txt
                                                                QString QS_BlockImage   = QSL_Blocks[n_blocks - 2]; //Image_T2_Y0_X1
                                                              //QString QS_BlockTime    = QSL_Blocks[n_blocks - 3]; //Time_2

                                                                //time blocks
                                                                QStringList QSl_BlocksImg = QS_BlockImage.split("_");
                                                                //if(t_thread == 0) qDebug() << "img name blocks" << QSl_BlocksImg;
                                                                if(QSl_BlocksImg.size() == 4)
                                                                {
                                                                    //get coordinates of image in mosaic
                                                                    bool ok_t;
                                                                    size_t nuc_new_t = QSl_BlocksImg[1].right(QSl_BlocksImg[1].size() - 1).toInt(&ok_t);
                                                                    bool ok_y;
                                                                    size_t nuc_new_y = QSl_BlocksImg[2].right(QSl_BlocksImg[2].size() - 1).toInt(&ok_y);
                                                                    bool ok_x;
                                                                    size_t nuc_new_x = QSl_BlocksImg[3].right(QSl_BlocksImg[3].size() - 1).toInt(&ok_x);

                                                                    //if(t_thread == 0) qDebug() << "blocks croped t/y/x" << QSl_BlocksImg[1].right(QSl_BlocksImg[1].size() - 1) << QSl_BlocksImg[1].right(QSl_BlocksImg[2].size() - 2) << QSl_BlocksImg[3].right(QSl_BlocksImg[3].size() - 1);
                                                                    //if(t_thread == 0) qDebug() << "pos t/y/x" << nuc_new_t << nuc_new_y << nuc_new_x;

                                                                    //pos ok?
                                                                    if(ok_t && ok_y && ok_x)
                                                                    {
                                                                        //t in range?
                                                                        size_t nt = pvvvvNucsTYXI->size();
                                                                        if(nuc_new_t < nt)
                                                                        {
                                                                            //y in range?
                                                                            size_t ny = (*pvvvvNucsTYXI)[nuc_new_t].size();
                                                                            if(nuc_new_y < ny)
                                                                            {
                                                                                //x in range?
                                                                                size_t nx = (*pvvvvNucsTYXI)[nuc_new_t][nuc_new_y].size();
                                                                                if(nuc_new_x < nx)
                                                                                {
                                                                                    //if(t_thread == 0) qDebug() << "t/y/x ok";

                                                                                    //find nuc
                                                                                    D_Bio_NucleusBlob* pNucNew = nullptr;
                                                                                    bool nuc_new_found = false;
                                                                                    size_t ni = (*pvvvvNucsTYXI)[nuc_new_t][nuc_new_y][nuc_new_x].size();
                                                                                    for(size_t i = 0; i < ni && !nuc_new_found; i++)
                                                                                    {
                                                                                        D_Bio_NucleusBlob* pNucNewCandidate = &((*pvvvvNucsTYXI)[nuc_new_t][nuc_new_y][nuc_new_x][i]);
                                                                                        if(pNucNewCandidate->is_path_relative(QS_Line))
                                                                                        {
                                                                                            //if(t_thread == 0) qDebug() << "found nuc in pedigree";
                                                                                            nuc_new_found = true;
                                                                                            pNucNew = pNucNewCandidate;
                                                                                        }
                                                                                    }

                                                                                    //connect, if nuc before was found
                                                                                    if(nuc_before_found)
                                                                                    {
                                                                                        //set new as child for old (reversed setting don internally)
                                                                                        nuc_before_ptr->matching_SetAsChild(pNucNew, 1);
                                                                                        //if(t_thread == 0) qDebug() << "connected nuclei <3 <3 <3";
                                                                                    }

                                                                                    //save current new as old for next, if it is no child after mitosis
                                                                                    if(section_indicator != NUC_LIFE_FILE_SECTION_CHILDS)
                                                                                    {
                                                                                        nuc_before_found = true;
                                                                                        nuc_before_ptr = pNucNew;
                                                                                        //if(t_thread == 0) qDebug() << "saved nuc as new previous nuc";
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
    vector<std::thread> vThreads_FindPossibleMatches(ny_threads);

    //calc borders and start threads
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        //start the thread
        vThreads_FindPossibleMatches[y_thread] = std::thread(
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
    vector<std::thread> vThreads_FindPossibleMitosisCorrections(ny_threads);

    //calc borders and start threads
    for(size_t y_thread = 0; y_thread < ny_threads; y_thread++)
    {
        //start the thread
        vThreads_FindPossibleMitosisCorrections[y_thread] = std::thread(
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


