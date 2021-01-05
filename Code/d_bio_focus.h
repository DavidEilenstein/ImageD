/************************************
 *   added:     04.01.2020          *
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
    D_Bio_Focus(vector<Point> contour_points);
    D_Bio_Focus(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs);

    //void            set_contour(vector<Point> contour_points)       {m_contour = contour_points;}
    //void            add_contour_point(Point point)                  {m_contour.push_back(point);}

    void            set_value_channels(size_t channels)             {vSignalMedians.resize(channels); vSignalMedDevs.resize(channels);}
    void            set_values_medians(vector<double> vMedian)      {vSignalMedians = vMedian;}
    void            set_values_devs2med(vector<double> vMedDev)     {vSignalMedDevs = vMedDev;}
    void            set_value_median(size_t channel, double Median) {if(channel < vSignalMedians.size()) vSignalMedians[channel] = Median;}
    void            set_value_dev2med(size_t channel, double MedDev){if(channel < vSignalMedDevs.size()) vSignalMedDevs[channel] = MedDev;}

    vector<Point>   contour()                                       {return m_contour;}
    double          dist2contour(Point2f point)                     {return m_contour.empty() ? INFINITY :  pointPolygonTest(m_contour, point, true);}
    double          dist2centroid(Point2f point)                    {return m_contour.empty() ? INFINITY :  norm(point - m_centroid);}

    Point2f         centroid()                                      {return m_centroid;}
    double          area()                                          {return m_area;}
    double          compactness()                                   {return m_compactness;}
    double          convexity()                                     {return m_convexity;}

    double          signal_median(size_t channel)                   {return channel < vSignalMedians.size() ? vSignalMedians[channel] : 0;}
    double          signal_dev2med(size_t channel)                  {return channel < vSignalMedDevs.size() ? vSignalMedDevs[channel] : 0;}



protected:
    void            CalcFeats();

    vector<Point>   m_contour;
    vector<Point>   m_convex_hull;
    Moments         m_moments;

    Point2f         m_centroid = Point2f(0, 0);
    double          m_area = 0;
    double          m_compactness = 0;
    double          m_convexity = 0;

    vector<double> vSignalMedians;
    vector<double> vSignalMedDevs;
};

#endif // D_BIO_FOCUS_H
