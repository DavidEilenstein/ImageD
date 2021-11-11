/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_NUCLEUSBLOB_H
#define D_BIO_NUCLEUSBLOB_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>
#include <d_bio_focus.h>
#include <d_bio_enum.h>
#include <d_contour.h>

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

class D_Bio_NucleusBlob
{
public:
    D_Bio_NucleusBlob();
    D_Bio_NucleusBlob(QString QS_PathLoad);
    D_Bio_NucleusBlob(vector<Point> contour_points, Point Offset = Point(0, 0));
    D_Bio_NucleusBlob(vector<Point> contour_points, size_t time, Point Offset = Point(0, 0));
    D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double>> SignalStats_StatChannel, Point Offset = Point(0, 0));
    D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double>> SignalStats_StatChannel, size_t time, Point Offset = Point(0, 0));

    //set/add foic
    void                            set_FociChannels(size_t channels)                           {vvFoci.resize(channels);}
    void                            set_Foci(size_t channel, vector<D_Bio_Focus> v_foci)        {if(channel < vvFoci.size()) vvFoci[channel] = v_foci;}
    void                            set_Foci(vector<vector<D_Bio_Focus>> vv_foci)               {vvFoci = vv_foci;}
    void                            add_Focus(size_t channel, D_Bio_Focus focus)                {if(channel < vvFoci.size()) vvFoci[channel].push_back(focus);}

    //get foci or describing info
    size_t                          get_FociChannels()                                          {return vvFoci.size();}
    vector<vector<D_Bio_Focus>>     get_Foci()                                                  {return vvFoci;}
    size_t                          get_FociCount(size_t channel)                               {return channel < vvFoci.size() ? vvFoci[channel].size() : 0;}
    vector<D_Bio_Focus>             get_Foci(size_t channel)                                    {return channel < vvFoci.size() ? vvFoci[channel] : vector<D_Bio_Focus>{};}
    D_Bio_Focus                     get_Focus(size_t channel, size_t index)                     {return channel < vvFoci.size() ? (index < vvFoci[channel].size() ? vvFoci[channel][index] : D_Bio_Focus()) : D_Bio_Focus();}
    int                             get_Contours_append(vector<vector<Point>> *pvScaledContours, double scale);
    int                             get_Contours_append(vector<D_Contour> *pvContours);
    int                             get_FociCount_append(QStringList *pQSL_FociCounts);
    int                             get_ShapeInfo_append(QStringList *pQSL_ShapeInfo);
    int                             get_ChannelStat_append(QStringList *pQSL_Stat, size_t stat_index_bio_enum);

    //block save
    void                            block_save_StitchingBorder_BottomRight(size_t x, size_t y)  {block_stitching_border = true; block_stitching_border_x = x; block_stitching_border_y = y;}

    //save
    //int                           save(QString path, bool simple);
    //int                           save_detailed(QString path);
    int                             save_simple(QString path_of_dir_to_save_in, bool save_foci);
    bool                            load_simple(QString nucleus_file, bool load_foci);

    Rect                            bounding_box();

    vector<vector<Point>>           merge_contours_with_other_nucleus(D_Bio_NucleusBlob nuc_merge, int merging_distance);

    //copied from D_BioFocus because inhering causes problems...

    void            set_value_channels(size_t channels)                 {vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(channels, 0));}
  //void            set_values_medians(vector<double> vMedian)          {vSignalMedians = vMedian;}
  //void            set_values_devs2med(vector<double> vMedDev)         {vSignalMedDevs = vMedDev;}
  //void            set_value_median(size_t channel, double Median)     {if(channel < vSignalMedians.size()) vSignalMedians[channel] = Median;}
  //void            set_value_dev2med(size_t channel, double MedDev)    {if(channel < vSignalMedDevs.size()) vSignalMedDevs[channel] = MedDev;}

    vector<Point>   contour()                                           {                                       return m_contour;}
    void            forget_contour_and_calc_feats()                     {if(!state_feats_calced) CalcFeats();   m_contour.clear();}
    double          dist2contour(Point2f point)                         {                                       return m_contour.empty() ? INFINITY :  - pointPolygonTest(m_contour, point, true);}
    double          dist2centroid(Point2f point)                        {if(!state_feats_calced) CalcFeats();   return m_contour.empty() ? INFINITY :  norm(point - m_centroid);}
    bool            contains_point(Point P, double margin = 0)          {return dist2contour(P) <= margin;}

    Point2f         centroid()                                          {if(!state_feats_calced) CalcFeats();   return m_centroid;}
    double          area()                                              {if(!state_feats_calced) CalcFeats();   return m_area;}
    double          compactness()                                       {if(!state_feats_calced) CalcFeats();   return m_compactness;}
    double          convexity()                                         {if(!state_feats_calced) CalcFeats();   return m_convexity;}

    size_t          time_index()                                        {return m_time;}
    void            set_time_index(size_t t)                            {m_time = t;}

    size_t          channels()                                          {return vvSignalStats_StatChannel.empty() ? 0 : vvSignalStats_StatChannel[0].size();}
    double          signal_stat(size_t channel, size_t stat_local_id)   {return stat_local_id < vvSignalStats_StatChannel.size() ? (channel < vvSignalStats_StatChannel[stat_local_id].size() ? vvSignalStats_StatChannel[stat_local_id][channel] : 0) : 0;}
    double          signal_median(size_t channel)                       {return signal_stat(channel, VAL_STAT_MEDIAN);}
    double          signal_dev2med(size_t channel)                      {return signal_stat(channel, VAL_STAT_MEDIAN_DEVIATION);}

    bool            is_duplicate(vector<D_Bio_NucleusBlob> v_other_nucs, double rel_overlap_for_duplicate = 0.5);

    QString         info();



    //matching with other nucleus
    void                matching_InitMatching();

    double              matching_Score(D_Bio_NucleusBlob *nuc_calc_score, vector<size_t> *pvScoreRelevantCriteria, vector<double> *pvScoreWeights, vector<double> *pvScoreMax, double max_area_increase_to_rel, double max_area_decrease_to_rel, double max_shift);

    double              matching_Score_Parent()                         {return Score_Parent;}
    double              matching_Score_Child1()                         {return Score_Child1;}
    double              matching_Score_Child2()                         {return Score_Child2;}

    void                matching_SetAsChild(D_Bio_NucleusBlob *nuc_set_child, double score);
    void                matching_SetAsParent(D_Bio_NucleusBlob *nuc_set_parent, double score);

    bool                matching_RemoveChild(D_Bio_NucleusBlob *nuc_remove_child);

    /*
    bool                matching_TestAsChild_Candidate(D_Bio_NucleusBlob *nuc_test_child, double score_thresh);
    bool                matching_TestAsParent_Candidate(D_Bio_NucleusBlob *nuc_test_parent, double score_thresh);
    bool                matching_AcceptAndTellParent();
    bool                matching_AcceptAndTellChilds();
    */

    //matching
    D_Bio_NucleusBlob*  matching_Child1()                               {return state_FoundChild1 ? Nuc_Child1 : nullptr;}
    D_Bio_NucleusBlob*  matching_Child2()                               {return state_FoundChild2 ? Nuc_Child2 : nullptr;}
    D_Bio_NucleusBlob*  matching_Parent()                               {return state_FoundParent ? Nuc_Parent : nullptr;}
    bool                matching_foundChild1()                          {return state_FoundChild1;}
    bool                matching_foundChild2()                          {return state_FoundChild2;}
    bool                matching_foundParent()                          {return state_FoundParent;}
    bool                matching_foundNoParent()                        {return !state_FoundParent;}
    bool                matching_foundNoChild()                         {return (!state_FoundChild1) && (!state_FoundChild2);}
    bool                matching_foundAtMostOneChild()                  {return !(state_FoundChild1 && state_FoundChild2);}
    bool                matching_isNoMitosis()                          {return !(state_FoundChild1 && state_FoundChild2);}
    bool                matching_foundAtLeastOneChild()                 {return state_FoundChild1 || state_FoundChild2;}
    bool                matching_foundExactlyOneChild()                 {return (state_FoundChild1 && !state_FoundChild2) || (!state_FoundChild1 && state_FoundChild2);}
    bool                matching_isMitosis()                            {return state_FoundChild1 && state_FoundChild2;}
    bool                matching_isLinear()                             {return state_FoundParent && ((state_FoundChild1 && !state_FoundChild2) || (!state_FoundChild1 && state_FoundChild2));}

    int                 matching_Type(Rect FrameNotNearBorder, double t_begin, double t_end);
    QColor              matching_TypeColor(Rect FrameNotNearBorder, double t_begin, double t_end);
    size_t              matching_Age();
    size_t              matching_TimeIndexOfOldestAncestor();
    bool                matching_HasAncestorInRange(size_t t_oldest, double y_min_px, double y_max_px, double x_min_px, double x_max_px);

    void                matching_setTriedToMatchAtLeastOnce(bool tried)         {state_triedAtLeastOnceToMatch = tried;}


private:

    //bool            load(QString QS_DirLoad);

    size_t                          m_time = 0;
    vector<vector<D_Bio_Focus>>     vvFoci;

    size_t                          leftmost();
    size_t                          topmost();
    bool                            block_stitching_border = false;
    size_t                          block_stitching_border_x = size_t(INFINITY);
    size_t                          block_stitching_border_y = size_t(INFINITY);

    //copied from D_BioFocus because inhering causes problems...

    bool                            state_feats_calced  = false;
    void                            CalcFeats();

    vector<Point>                   m_contour;
    vector<Point>                   m_convex_hull;

    Point2f                         m_centroid          = Point2f(0, 0);
    double                          m_area              = 0;
    double                          m_compactness       = 0;
    double                          m_convexity         = 0;

    vector<vector<double>>          vvSignalStats_StatChannel = vector<vector<double>>(VAL_STAT_NUMBER_OF, vector<double>(1, 0));

    //matching with other nucleus
    D_Bio_NucleusBlob               *Nuc_Parent = nullptr;
    D_Bio_NucleusBlob               *Nuc_Child1 = nullptr;
    D_Bio_NucleusBlob               *Nuc_Child2 = nullptr;
    double                          Score_Parent = -INFINITY;
    double                          Score_Child1 = -INFINITY;
    double                          Score_Child2 = -INFINITY;
    bool                            state_FoundParent = false;
    bool                            state_FoundChild1 = false;
    bool                            state_FoundChild2 = false;
    bool                            state_triedAtLeastOnceToMatch = false;
};

#endif // D_BIO_NUCLEUSBLOB_H
