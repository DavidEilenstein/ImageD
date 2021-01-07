/************************************
 *   added:     04.01.2020          *
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

class D_Bio_NucleusBlob : public D_Bio_Focus //Foucus is used to describe pos, shape abd values the same way
{
public:
    D_Bio_NucleusBlob();
    D_Bio_NucleusBlob(vector<Point> contour_points);
    D_Bio_NucleusBlob(vector<Point> contour_points, double time);
    D_Bio_NucleusBlob(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs);
    D_Bio_NucleusBlob(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs, double time);

    //set/add foic
    void                            set_FociChannels(size_t channels)                       {vvFoci.resize(channels);}
    void                            set_Foci(size_t channel, vector<D_Bio_Focus> v_foci)    {if(channel < vvFoci.size()) vvFoci[channel] = v_foci;}
    void                            set_Foci(vector<vector<D_Bio_Focus>> vv_foci)           {vvFoci = vv_foci;}
    void                            add_Focus(size_t channel, D_Bio_Focus focus)            {if(channel < vvFoci.size()) vvFoci[channel].push_back(focus);}

    //get foci or describing info
    size_t                          get_FociChannels()                                      {return vvFoci.size();}
    vector<vector<D_Bio_Focus>>     get_Foci()                                              {return vvFoci;}
    size_t                          get_FociCount(size_t channel)                           {return channel < vvFoci.size() ? vvFoci[channel].size() : 0;}
    vector<D_Bio_Focus>             get_Foci(size_t channel)                                {return channel < vvFoci.size() ? vvFoci[channel] : vector<D_Bio_Focus>{};}
    D_Bio_Focus                     get_Focus(size_t channel, size_t index)                 {return channel < vvFoci.size() ? (index < vvFoci[channel].size() ? vvFoci[channel][index] : D_Bio_Focus()) : D_Bio_Focus();}

    int                             save(QString path);

private:
    double                          m_time = 0;
    vector<vector<D_Bio_Focus>>     vvFoci;
    QStringList                     QSL_FociChannelNames;

};

#endif // D_BIO_NUCLEUSBLOB_H
