/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_RANGE_H
#define D_VISDAT_RANGE_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_dim.h>
#include <D_VisDat_Slice_2D.h>

//Qt
#include <QString>
#include <QStringList>

//Qt::Charts

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

/*!
 * \brief The D_VisDat_Range class Describes the intersect of two D_VisDat_Dim , so it is a 6D subvolume.
 * \details Can be used to set 6D hyper cuboid regions of interest.
 */
class D_VisDat_Range
{
public:
    D_VisDat_Range();
    D_VisDat_Range(int X1, int X2, int Y1, int Y2, int Z1, int Z2, int T1, int T2, int S1, int S2, int P1, int P2);
    D_VisDat_Range(D_VisDat_Slice_2D Slice_2d);

    vector<int>                 Min             ()                                      {return vMin;}
    vector<int>                 Max             ()                                      {return vMax;}
    vector<Range>               Ranges          ();
    vector<Range>               Ranges          (D_VisDat_Dim VD_Dim_Source);

  //bool                        isInrangeOf

    int                         min_X           ()                                      {return vMin[c_DIM_X];}
    int                         min_Y           ()                                      {return vMin[c_DIM_Y];}
    int                         min_Z           ()                                      {return vMin[c_DIM_Z];}
    int                         min_T           ()                                      {return vMin[c_DIM_T];}
    int                         min_S           ()                                      {return vMin[c_DIM_S];}
    int                         min_P           ()                                      {return vMin[c_DIM_P];}
    int                         min_Dim         (size_t d)                              {return d < c_DIM_NUMBER_OF ? vMin[d] : -1;}
    vector<int>                 min_Dims        ()                                      {return vMin;}

    int                         max_X           ()                                      {return vMax[c_DIM_X];}
    int                         max_Y           ()                                      {return vMax[c_DIM_Y];}
    int                         max_Z           ()                                      {return vMax[c_DIM_Z];}
    int                         max_T           ()                                      {return vMax[c_DIM_T];}
    int                         max_S           ()                                      {return vMax[c_DIM_S];}
    int                         max_P           ()                                      {return vMax[c_DIM_P];}
    int                         max_Dim         (size_t d)                              {return d < c_DIM_NUMBER_OF ? vMax[d] : -1;}
    vector<int>                 max_Dims        ()                                      {return vMax;}

    int                         range_X         ()                                      {return range_Dim(c_DIM_X);}
    int                         range_Y         ()                                      {return range_Dim(c_DIM_X);}
    int                         range_Z         ()                                      {return range_Dim(c_DIM_X);}
    int                         range_T         ()                                      {return range_Dim(c_DIM_X);}
    int                         range_S         ()                                      {return range_Dim(c_DIM_X);}
    int                         range_P         ()                                      {return range_Dim(c_DIM_X);}
    int                         range_Dim       (size_t d)                              {return (d < c_DIM_NUMBER_OF && vMin[d] >= 0 && vMax[d] >= 0) ? (vMax[d] - vMin[d]) : -1;}

    void                        set_Range_X     (int min, int max)                      {vMin[c_DIM_X] = min; vMax[c_DIM_X] = max;}
    void                        set_Range_Y     (int min, int max)                      {vMin[c_DIM_Y] = min; vMax[c_DIM_Y] = max;}
    void                        set_Range_Z     (int min, int max)                      {vMin[c_DIM_Z] = min; vMax[c_DIM_Z] = max;}
    void                        set_Range_T     (int min, int max)                      {vMin[c_DIM_T] = min; vMax[c_DIM_T] = max;}
    void                        set_Range_S     (int min, int max)                      {vMin[c_DIM_S] = min; vMax[c_DIM_S] = max;}
    void                        set_Range_P     (int min, int max)                      {vMin[c_DIM_P] = min; vMax[c_DIM_P] = max;}
    void                        set_Range_Dim   (int d, int min, int max)               {if(d < c_DIM_NUMBER_OF) {vMin[d] = min; vMax[d] = max;}}
    void                        set_Range_Dims  (vector<int> vmin, vector<int> vmax)    {if(vmin.size() == c_DIM_NUMBER_OF && vmax.size() == c_DIM_NUMBER_OF) {vMin = vmin; vMax = vmax;}}

    void                        Dim4Range_Init          (D_VisDat_Dim *range_in_this_dim);
    D_VisDat_Dim                Dim4Range_DimIntersect  ()                              {return D_VisDat_Dim(Dim4Range_Size());}
    vector<int>                 Dim4Range_Size          ();
    Vec<int, c_DIM_NUMBER_OF>   Dim4Range_Offset        ()                              {return vMin_inDim;}

    QString                     info();

protected:
    void                        Init();

private:
    vector<int>                 vMin;
    vector<int>                 vMax;
    Vec<int, c_DIM_NUMBER_OF>   vMin_inDim;
    Vec<int, c_DIM_NUMBER_OF>   vMax_inDim;

};

#endif // D_VISDAT_RANGE_H
