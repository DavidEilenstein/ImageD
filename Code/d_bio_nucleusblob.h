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
using namespace cv;

class D_Bio_NucleusBlob
{
public:
    D_Bio_NucleusBlob();
    D_Bio_NucleusBlob(QString QS_PathLoad);
    D_Bio_NucleusBlob(vector<Point> contour_points, Point Offset = Point(0, 0));
    D_Bio_NucleusBlob(vector<Point> contour_points, double time, Point Offset = Point(0, 0));
    D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double>> SignalStats_StatChannel, Point Offset = Point(0, 0));
    D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double>> SignalStats_StatChannel, double time, Point Offset = Point(0, 0));

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
    int                             get_FociCount_append(QStringList *pQSL_FociCounts);

    //block save
    void                            block_save_StitchingBorder_BottomRight(size_t x, size_t y)  {block_stitching_border = true; block_stitching_border_x = x; block_stitching_border_y = y;}

    //save
    //int                           save(QString path, bool simple);
    //int                           save_detailed(QString path);
    int                             save_simple(QString path_of_dir_to_save_in, bool save_foci);
    bool                            load_simple(QString nucleus_file, bool load_foci);

    //copied from D_BioFocus because inhering causes problems...

    void            set_value_channels(size_t channels)             {vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(channels, 0));}
  //void            set_values_medians(vector<double> vMedian)      {vSignalMedians = vMedian;}
  //void            set_values_devs2med(vector<double> vMedDev)     {vSignalMedDevs = vMedDev;}
  //void            set_value_median(size_t channel, double Median) {if(channel < vSignalMedians.size()) vSignalMedians[channel] = Median;}
  //void            set_value_dev2med(size_t channel, double MedDev){if(channel < vSignalMedDevs.size()) vSignalMedDevs[channel] = MedDev;}

    vector<Point>   contour()                                       {                                       return m_contour;}
    double          dist2contour(Point2f point)                     {                                       return m_contour.empty() ? INFINITY :  - pointPolygonTest(m_contour, point, true);}
    double          dist2centroid(Point2f point)                    {if(state_feats_calced) CalcFeats();    return m_contour.empty() ? INFINITY :  norm(point - m_centroid);}

    Point2f         centroid()                                      {if(state_feats_calced) CalcFeats();    return m_centroid;}
    double          area()                                          {if(state_feats_calced) CalcFeats();    return m_area;}
    double          compactness()                                   {if(state_feats_calced) CalcFeats();    return m_compactness;}
    double          convexity()                                     {if(state_feats_calced) CalcFeats();    return m_convexity;}

    size_t          channels()                                      {return vvSignalStats_StatChannel.empty() ? 0 : vvSignalStats_StatChannel[0].size();}
    double          signal_stat(size_t channel, size_t stat_local_id){return stat_local_id < vvSignalStats_StatChannel.size() ? (channel < vvSignalStats_StatChannel[stat_local_id].size() ? vvSignalStats_StatChannel[stat_local_id][channel] : 0) : 0;}
    double          signal_median(size_t channel)                   {return signal_stat(channel, VAL_STAT_MEDIAN);}
    double          signal_dev2med(size_t channel)                  {return signal_stat(channel, VAL_STAT_MEDIAN_DEVIATION);}

private:

    //bool            load(QString QS_DirLoad);

    double                          m_time = 0;
    vector<vector<D_Bio_Focus>>     vvFoci;

    size_t                          leftmost();
    size_t                          topmost();
    bool                            block_stitching_border = false;
    size_t                          block_stitching_border_x = INFINITY;
    size_t                          block_stitching_border_y = INFINITY;

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



};

#endif // D_BIO_NUCLEUSBLOB_H
