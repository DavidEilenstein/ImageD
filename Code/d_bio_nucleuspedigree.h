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
#include <d_bio_enum.h>
#include <d_viewer_plot_3d.h>

//Qt
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

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Bio_NucleusPedigree
{
public:
    D_Bio_NucleusPedigree();

    void clear();
    void set_size_time(size_t t_size);

    bool add_nucleus_blob(size_t t, D_Bio_NucleusBlob nuc);

    void initMatching();
    bool initMatching(vector<double> score_weights, vector<double> score_maxima, double shift_limit, double max_rel_area_inc_to, double max_rel_area_dec_to, double max_age, double thres_tm1_go1, double thres_tm2_go1, double thres_tm1_go2, double thres_tm2_go2);

    int setPedigreePlotViewer(D_Viewer_Plot_3D *viewer);
    int updatePedigreePlot(size_t points_per_edge);
    int updatePedigreePlot(D_Viewer_Plot_3D *viewer, size_t points_per_edge);

    void set_scale_px2um(double scale)                              {if(scale > 0) scale_px_to_um = scale;}
    void set_scale_T2h(double scale)                                {if(scale > 0) scale_t_to_h = scale;}
    void set_scale_nodes(double scale)                              {if(scale > 0 && scale <= 1) scale_nodes = scale;}
    void set_scale_edges(double scale)                              {if(scale > 0 && scale <= 1) scale_edges = scale;}
    void set_range_XY(int x_min, int x_max, int y_min, int y_max)   {int w = x_max - x_min; int h = y_max - y_min; if(w > 0 && h > 0) FrameInRegularRangeXY = Rect(x_min, y_min, w, h);}

    void match_all();
    void match_all_go1();
    void match_all_go2();
    void match_time_go1(size_t t);
    void match_time_go2(size_t t);
    void match_time_tm1_tm2_mixed(size_t t);
    void match_time_tm1_tm2_consecutive(size_t t);
    void match_time_ends_tm2_then_normal_tm1(size_t t);
    void match_to_tm1(size_t t);
    void match_to_tm2_to_ends_only(size_t t);

private:

    void match_times(size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis);
    void match_find_matches(vector<vector<double> > *vvMatches, size_t t_parents, size_t t_childs, double score_thresh, bool allow_new_mitosis);
    void match_accept_matches(vector<vector<double>> *vvMatches, bool allow_new_mitosis);

    //viewer
    D_Viewer_Plot_3D *pViewerPedigreePlot;

    //dimension
    size_t size_time = 0;

    //data
    vector<vector<D_Bio_NucleusBlob>> vvNucBlobs_T;

    //weights for score calc
    vector<double>                  vScoreWeights;
    vector<double>                  vScoreMaxima;
    double                          match_thresh_max_area_increase_to = 1.25;
    double                          match_thresh_max_area_decrease_to = 0.35;
    double                          match_thresh_max_shift = 200;
    double                          match_max_age = 35;
    double                          match_score_thres_tm1_go1 = 0.9;
    double                          match_score_thres_tm2_go1 = 0.9;
    double                          match_score_thres_tm1_go2 = 0.7;
    double                          match_score_thres_tm2_go2 = 0.7;

    //scaling XYT to rteal world coords
    double                          scale_px_to_um = 0.1;
    double                          scale_t_to_h = 1.0;
    double                          scale_nodes = 1;
    double                          scale_edges = 1;

    //XY range no border
    Rect                            FrameInRegularRangeXY = Rect(-INT_MAX/2, -INT_MAX/2, INT_MAX, INT_MAX);

    //states
    bool                            state_ScoreWeightsAndMaxSet = false;
    bool                            state_PlotViewerSet = false;

    enum MATCH_ATTRIB_INDEX {
        MATCH_ATTRIB_INDEX_SCORE,
        MATCH_ATTRIB_INDEX_PARENT_T,
        MATCH_ATTRIB_INDEX_PARENT_I,
        MATCH_ATTRIB_INDEX_CHILD_T,
        MATCH_ATTRIB_INDEX_CHILD_I,
        MATCH_ATTRIB_INDEX_NUMBER_OF
    };
};

#endif // D_BIO_NUCLEUSPEDIGREE_H
