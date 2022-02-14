/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_NUCLEUSPEDIGREE_H
#define D_BIO_NUCLEUSPEDIGREE_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>
#include <d_bio_nucleuslife.h>
#include <d_bio_nucleusblob.h>
#include <d_bio_nucleusimage.h>
#include <d_bio_enum.h>
#include <d_bio_attribute_filter.h>
#include <d_viewer_plot_3d.h>
#include <d_viewer_3d.h>

//Qt
#include <QObject>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QInputDialog>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Bio_NucleusPedigree : public QObject
{
    Q_OBJECT

public:
    D_Bio_NucleusPedigree();

    void clear();

    void set_size_time_and_mosaik(size_t t_size, size_t y_size, size_t x_size);
    void set_time_irradiation(double t_irr)                 {time_irradiation = t_irr;}
    size_t size_T()                                         {return size_time;}
    size_t size_Y()                                         {return size_mosaik_y;}
    size_t size_X()                                         {return size_mosaik_x;}
    Rect rect_RegularRange_px()                             {return FrameInRegularRangeXY;}
    size_t nuclei_blob_count(size_t t, size_t y, size_t x);
    size_t nuclei_blob_count(size_t t);
    size_t nuclei_blob_count();

    QString info();

    D_Bio_NucleusBlob* get_pNucleus(size_t t, size_t y_mosaic, size_t x_mosaic, size_t i);
    D_Bio_NucleusBlob *get_pNucleus(size_t t, size_t y_mosaic_min, size_t x_mosaic_min, size_t y_mosaic_max, size_t x_mosaic_max, size_t y_pos_px, size_t x_pos_px);

    bool load_nuclei_data(QString QS_path_NucDataMaster, QString QS_path_NucData, size_t nt, size_t ny, size_t nx, bool forget_contour);
    bool add_nucleus_blob(size_t t, size_t y, size_t x, D_Bio_NucleusBlob nuc);

    bool initMatching(vector<double> score_weights, vector<double> score_maxima, double shift_limit, double max_rel_area_inc_to, double max_rel_area_dec_to, double max_age, double thres_tm1_go1, double thres_tm2_go1, double thres_tm3_go1, double thres_tm1_go2, double thres_tm2_go2, double thres_tm3_go2, double mitosis_mult_go1, double mitosis_mult_go2);

    int setPedigreeViewer_Plot3D( D_Viewer_Plot_3D *viewer);
    int updatePedigreeView_Plot3D(                          size_t points_per_edge, size_t t_min = 0, size_t t_max = size_t(INFINITY), double y_min_um = -INFINITY, double y_max_um = INFINITY, double x_min_um = -INFINITY, double x_max_um = INFINITY);
    int updatePedigreeView_Plot3D(D_Viewer_Plot_3D *viewer, size_t points_per_edge, size_t t_min = 0, size_t t_max = size_t(INFINITY), double y_min_um = -INFINITY, double y_max_um = INFINITY, double x_min_um = -INFINITY, double x_max_um = INFINITY);

    int setPedigreeViewer_Volumetric( D_Viewer_3D *viewer);
    int updatePedigreeView_Volumetric(                      size_t size_volT_px, size_t size_volY_px, size_t size_volX_px, size_t size_Node_px, size_t size_Edge_px, size_t size_Y_px_original, size_t size_X_px_original);
    int updatePedigreeView_Volumetric(D_Viewer_3D *viewer,  size_t size_volT_px, size_t size_volY_px, size_t size_volX_px, size_t size_Node_px, size_t size_Edge_px, size_t size_Y_px_original, size_t size_X_px_original);
private:
    static int updatePedigreeView_Volumetric_TimeThread(D_VisDat_Obj *pVD_Target, vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, double score_range, double score_min, size_t size_Node_px, size_t size_Edge_px, size_t size_Y_px_original, size_t size_X_px_original, Rect frame_legit, size_t t_plane);
public:

    void set_scale_px2um(double scale)                              {if(scale > 0) scale_px_to_um = scale;}
    void set_scale_T2h(double scale)                                {if(scale > 0) scale_t_to_h = scale;}
    void set_scale_nodes(double scale)                              {if(scale > 0 && scale <= 1) scale_nodes = scale;}
    void set_scale_edges(double scale)                              {if(scale > 0 && scale <= 1) scale_edges = scale;}
    void set_range_XY(int x_min, int x_max, int y_min, int y_max)   {int w = x_max - x_min; int h = y_max - y_min; if(w > 0 && h > 0) FrameInRegularRangeXY = Rect(x_min, y_min, w, h);}
    void set_earliest_mitoses_allowed(size_t t_earliest)            {match_earliest_mitosis_allowed = t_earliest;}

    bool set_attrib_filter_ui(QGroupBox* box_foci, QGroupBox* box_nucblobs, QGroupBox* box_nuclifes);
    bool set_attrib_filter_channels(QStringList channels);
    bool set_attrib_filter_scaling();

    bool calc_NucLifes();
    bool calc_NucLifes_Filtered();

    vector<double>  attrib_data(size_t i_data_pt_lvl, size_t i_att_lvl_nuclife, size_t i_att_lvl_nucblob, /*size_t i_att_lvl_foc,*/ size_t i_att_nuclife, size_t i_att_nucblob, size_t i_att_foc, size_t ch_val, size_t ch_foc, size_t stat_low, size_t stat_high);
    //vector<double>  attrib_data(size_t i_data_point_level, size_t i_attrib_level, size_t i_attrib, size_t ch_val, size_t ch_foc, size_t stat_low, size_t stat_high);
    vector<double>  attrib_nuclife(size_t i_attrib);
    vector<double>  attrib_nucblob(size_t i_attrib, size_t ch_val);
    vector<double>  attrib_foci(size_t i_attrib, size_t ch_val);
    vector<double>  attrib_foci(size_t i_attrib, size_t ch_val, size_t ch_foc);

    void match_all();
    void match_all_go1();
    void match_all_go2();

    void match_time_go1(size_t t);
    void match_time_go2(size_t t);
    void match_time_correct_mitosis_go1(size_t t);
    void match_time_correct_mitosis_go2(size_t t);

    bool match_save_results(QString QS_path);
    bool match_load_data_and_matches(QString QS_path_NucDataMaster, QString QS_path_NucData, QString QS_path_NucLifes, size_t nt, size_t ny, size_t nx, bool forget_contour);
    bool match_load_matches(QString QS_path_NucLifes);

public slots:
    void SetAttribFilterToNeedUpdate();

private:

    static bool match_save_results_time_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, QDir DirSaveMaster, size_t t_thread);
    static bool load_time_nuclei_data_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, QDir DirLoadMaster, QDir DirLoadNucs, size_t t_thread, bool forget_contour);
    static bool load_time_nuclei_matches_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, QDir DirLoadNucLifes, size_t t_thread);

    void        match_correct_mitosis(  size_t t_parents, size_t t_childs, double score_multiplier, bool allow_new_mitosis);
    void        match_times(            size_t t_parents, size_t t_childs, double score_thresh,     bool allow_new_mitosis);

    void        match_find_possible_matches(            vector<vector<double>> *vvPossibleMatches,              size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis);
    void        match_find_possible_mitosis_corrections(vector<vector<double>> *vvPossibleMitosisCorrections,   size_t t_parents, size_t t_childs, double score_multiplier, bool allow_new_mitoses);

    static void match_find_possible_matches_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, vector<vector<double>> *vvPossibleMatches,                         size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis, vector<size_t> *pvScoreRelevantCriteria, vector<double> *pvScoreWeights, vector<double> *pvScoreMax, double max_area_increase_to_rel, double max_area_decrease_to_rel, double max_shift, size_t y_toProc);
    static void match_find_possible_mitosis_corrections_thread(vector<vector<vector<vector<D_Bio_NucleusBlob>>>> *pvvvvNucsTYXI, vector<vector<double>> *vvPossibleMitosisCorrections, size_t t_parents, size_t t_childs, double mitosis_score_muliplier, bool allow_new_mitoses,              vector<size_t> *pvScoreRelevantCriteria, vector<double> *pvScoreWeights, vector<double> *pvScoreMax, double max_area_increase_to_rel, double max_area_decrease_to_rel, double max_shift, size_t y_toProc);

    void        match_accept_matches(vector<vector<double>> *vvPossibleMatches, bool allow_new_mitosis);
    void        match_accept_mitosis_corrections(vector<vector<double>> *vvPossibleMitosisCorrections, bool allow_new_mitosis);

    void        calc_PlotVol(vector<Point3d> vNodesCoord, vector<Point3d> vEdgeCoordBegins, vector<Point3d> vEdgeCoordEnds, vector<QColor> vNodeColor, vector<QColor> vEdgeColor, int size_T_px, int size_Y_px, int size_X_px, int size_nodes = 3, int size_edge = 1);

    //viewer
    D_Viewer_Plot_3D *pViewerPedigree_Plot3D;
    D_Viewer_3D *pViewerPedigree_Volumetric;

    //Plot_Volume for volumetric plot
    D_VisDat_Obj VD_PlotVol;

    //dimension
    size_t size_time = 0;
    size_t size_mosaik_y = 0;
    size_t size_mosaik_x = 0;

    //irradiation
    double time_irradiation = 0;

    //data
    vector<vector<vector<vector<D_Bio_NucleusBlob>>>> vvvvNucBlobs_TYXI;
    vector<D_Bio_NucleusLife> vNucLifes;
    vector<D_Bio_NucleusLife> vNucLifes_Filtered;

    //weights for score calc
    vector<size_t>                  vScoreCriteria_Relevant;
    vector<double>                  vScoreWeights_Relevant;
    vector<double>                  vScoreMaxima_Relevant;
    double                          match_thresh_max_area_increase_to = 1.25;
    double                          match_thresh_max_area_decrease_to = 0.35;
    double                          match_thresh_max_shift = 200;
    double                          match_max_age = 35;
    double                          match_score_thres_tm1_go1 = 0.50;
    double                          match_score_thres_tm2_go1 = 0.55;
    double                          match_score_thres_tm3_go1 = 0.60;
    double                          match_score_thres_tm1_go2 = 0.20;
    double                          match_score_thres_tm2_go2 = 0.25;
    double                          match_score_thres_tm3_go2 = 0.30;
    double                          match_score_multiplier_mitosis_go1 = 0.20;
    double                          match_score_multiplier_mitosis_go2 = 0.70;
    size_t                          match_earliest_mitosis_allowed = 0;

    //scaling XYT to rteal world coords
    double                          scale_px_to_um = 0.1;
    double                          scale_t_to_h = 1.0;
    double                          scale_nodes = 1;
    double                          scale_edges = 1;

    //XY range no border
    Rect                            FrameInRegularRangeXY = Rect(-INT_MAX/2, -INT_MAX/2, INT_MAX, INT_MAX);

    //states
    bool                            state_ScoreWeightsAndMaxSet = false;
    bool                            state_PedigreeViewer_Plot3D_Set = false;
    bool                            state_PedigreeViewer_Volumetric_Set = false;
    bool                            state_AttribFiltersSet = false;
    bool                            state_NucLifesCalced = false;
    bool                            state_NucLifesFilteredCalced = false;
    bool                            state_NucLifeFilteringRunning = false;

    //attribute filter
    D_Bio_Attribute_Filter*         pAttribFilter_Foci = nullptr;
    D_Bio_Attribute_Filter*         pAttribFilter_NucBlobs = nullptr;
    D_Bio_Attribute_Filter*         pAttribFilter_NucLifes = nullptr;

    //match attribs
    enum MATCH_ATTRIB_INDEX {
        MATCH_ATTRIB_INDEX_SCORE,
        MATCH_ATTRIB_INDEX_PARENT_T,
        MATCH_ATTRIB_INDEX_PARENT_Y,
        MATCH_ATTRIB_INDEX_PARENT_X,
        MATCH_ATTRIB_INDEX_PARENT_I,
        MATCH_ATTRIB_INDEX_CHILD_T,
        MATCH_ATTRIB_INDEX_CHILD_Y,
        MATCH_ATTRIB_INDEX_CHILD_X,
        MATCH_ATTRIB_INDEX_CHILD_I,
        MATCH_ATTRIB_INDEX_NUMBER_OF
    };
};

#endif // D_BIO_NUCLEUSPEDIGREE_H
