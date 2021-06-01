/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_FOCUS_H
#define D_BIO_FOCUS_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_bio_enum.h>

//Qt
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QInputDialog>
#include <QTextStream>

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

class D_Bio_Focus
{
public:
    D_Bio_Focus();
    //D_Bio_Focus(QString QS_PathLoad);
    D_Bio_Focus(vector<Point> contour_points, Point Offset = Point(0, 0));
    D_Bio_Focus(vector<Point> contour_points, vector<vector<double>> SignalStats_StatChannel, Point Offset = Point(0, 0));
    D_Bio_Focus(Point2f centroid, double area, double compactness, double convexity, vector<vector<double>> SignalStats_StatChannel);

    void            set_value_channels(size_t channels)             {vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(channels, 0));}
  //void            set_values_stat(size_t stat_local_id, vector<double> vSignals_Stat);
  //void            set_values_medians(vector<double> vMedian)      {vvSignalStats[VAL_STAT_MEDIAN] = vMedian;}
  //void            set_values_devs2med(vector<double> vMedDev)     {vSignalMedDevs = vMedDev;}
  //void            set_value_median(size_t channel, double Median) {if(channel < vSignalMedians.size()) vSignalMedians[channel] = Median;}
  //void            set_value_dev2med(size_t channel, double MedDev){if(channel < vSignalMedDevs.size()) vSignalMedDevs[channel] = MedDev;}

    Point2f         centroid()                                      {return m_centroid;}
    double          area()                                          {return m_area;}
    double          compactness()                                   {return m_compactness;}
    double          convexity()                                     {return m_convexity;}
    double          radius_circle_equivalent()                      {return sqrt(m_area / PI);}

    double          dist2centroid(Point2f point)                    {return norm(point - m_centroid);}
    double          dist2contour_circle_equivalent(Point2f point)   {return dist2centroid(point) - radius_circle_equivalent();}

    size_t          channels();
    double          signal_stat(size_t channel, size_t stat_local_id);
    double          signal_median(size_t channel)                   {return signal_stat(channel, VAL_STAT_MEDIAN);}
    double          signal_dev2med(size_t channel)                  {return signal_stat(channel, VAL_STAT_MEDIAN_DEVIATION);}

    //int             save(QString path);

private:

    //bool            load(QString QS_PathLoad);

    bool            state_feats_calced = false;
    void            CalcFeats(vector<Point> contour);

    Point2f         m_centroid      = Point2f(0, 0);
    double          m_area          = 0;
    double          m_compactness   = 0;
    double          m_convexity     = 0;

    vector<vector<double>> vvSignalStats_StatChannel = vector<vector<double>>(VAL_STAT_NUMBER_OF, vector<double>(1, 0));
};

#endif // D_BIO_FOCUS_H
