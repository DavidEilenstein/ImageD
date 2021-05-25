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
    D_Bio_Focus(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs, Point Offset = Point(0, 0));
    D_Bio_Focus(Point2f centroid, double area, double compactness, double convexity, vector<double> signal_medians, vector<double> signal_meddevs);

    void            set_value_channels(size_t channels)             {vSignalMedians.resize(channels); vSignalMedDevs.resize(channels);}
    void            set_values_medians(vector<double> vMedian)      {vSignalMedians = vMedian;}
    void            set_values_devs2med(vector<double> vMedDev)     {vSignalMedDevs = vMedDev;}
    void            set_value_median(size_t channel, double Median) {if(channel < vSignalMedians.size()) vSignalMedians[channel] = Median;}
    void            set_value_dev2med(size_t channel, double MedDev){if(channel < vSignalMedDevs.size()) vSignalMedDevs[channel] = MedDev;}

    Point2f         centroid()                                      {return m_centroid;}
    double          area()                                          {return m_area;}
    double          compactness()                                   {return m_compactness;}
    double          convexity()                                     {return m_convexity;}
    double          radius_circle_equivalent()                      {return sqrt(m_area / PI);}

    double          dist2centroid(Point2f point)                    {return norm(point - m_centroid);}
    double          dist2contour_circle_equivalent(Point2f point)   {return dist2centroid(point) - radius_circle_equivalent();}

    size_t          channels()                                      {return min(vSignalMedDevs.size(), vSignalMedians.size());}
    double          signal_median(size_t channel)                   {return channel < vSignalMedians.size() ? vSignalMedians[channel] : 0;}
    double          signal_dev2med(size_t channel)                  {return channel < vSignalMedDevs.size() ? vSignalMedDevs[channel] : 0;}

    //int             save(QString path);

private:

    //bool            load(QString QS_PathLoad);

    bool            state_feats_calced = false;
    void            CalcFeats(vector<Point> contour);

    Point2f         m_centroid      = Point2f(0, 0);
    double          m_area          = 0;
    double          m_compactness   = 0;
    double          m_convexity     = 0;

    vector<double> vSignalMedians   = vector<double> {};
    vector<double> vSignalMedDevs   = vector<double> {};
};

#endif // D_BIO_FOCUS_H
