/************************************
 *   added:     03.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_SLICE_ND_H
#define D_VISDAT_SLICE_ND_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_dim.h>

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
 * \brief The D_VisDat_Slice_Nd class Represents a nD slice through a D_VisDat_Obj
 * \details Never used directly.
 * There are child versions of this class that have a fix dimensionality: D_VisDat_Slice_3d , D_VisDat_Slice_2d and D_VisDat_Slice_1d
 */
class D_VisDat_Slice_Nd
{
public:
    D_VisDat_Slice_Nd                   ();
    //D_VisDat_Slice_Nd                   (int X, int Y, int Z, int T, int S, int P);
    //D_VisDat_Slice_Nd                   (vector<int> vPositions);

    int                         pos_X               ()                                              {return vPos[c_DIM_X];}
    int                         pos_Y               ()                                              {return vPos[c_DIM_Y];}
    int                         pos_Z               ()                                              {return vPos[c_DIM_Z];}
    int                         pos_T               ()                                              {return vPos[c_DIM_T];}
    int                         pos_S               ()                                              {return vPos[c_DIM_S];}
    int                         pos_P               ()                                              {return vPos[c_DIM_P];}
    int                         pos_Dim             (int d)                                         {return d >= 0 && d < c_DIM_NUMBER_OF ? vPos[d] : 0;}
    Vec<int, c_DIM_NUMBER_OF>   pos_Dims();

    int                         extended_Dim_Count  ()                                              {return EXT_DIMS;}
    int                         dimensionality      ()                                              {return extended_Dim_Count();}
    int                         extended_Dim        (int ext_number)                                {return ext_number < vExt.size() ? vExt[ext_number] : vExt[0];}
    vector<int>                 extended_Dims       ()                                              {return vExt;}

    void                        set_Dimensionality  (int dims);

    void                        set_Pos_X           (int X)                                         {vPos[c_DIM_X] = X;}
    void                        set_Pos_Y           (int Y)                                         {vPos[c_DIM_Y] = Y;}
    void                        set_Pos_Z           (int Z)                                         {vPos[c_DIM_Z] = Z;}
    void                        set_Pos_T           (int T)                                         {vPos[c_DIM_T] = T;}
    void                        set_Pos_S           (int S)                                         {vPos[c_DIM_S] = S;}
    void                        set_Pos_P           (int P)                                         {vPos[c_DIM_P] = P;}
    void                        set_Pos_Dim         (int d, int pos)                                {vPos[d] = pos;}
    void                        set_Pos             (int X, int Y, int Z, int T, int S, int P)      {vPos = {X, Y, Z, T, S, P}; force_Dimensionality();}
    void                        set_Pos             (vector<int> vPositions)                        {if(vPos.size() == vPositions.size()) vPos = vPositions; force_Dimensionality();}

    bool                        isExtendedDim       (int dim);

    bool                        inRangeOf           (D_VisDat_Dim dim_container);
    int                         dimOutOfRange       (D_VisDat_Dim dim_container);
    int                         ER_OutOfrange       (D_VisDat_Dim dim_container);
    void                        forceToBeInRangeOf  (D_VisDat_Dim dim_container);
    void                        force_Dimensionality();

    QString                     QS_pos              ();
    QString                     QS_pos_nonProcOnly  ();

    QString                     info                ();

//protected:
    int                         EXT_DIMS = 2;

    void                        Init();

    vector<int>                 vPos = {0, 0, 0, 0, 0, 0};
    vector<int>                 vExt = {};
};

#endif // D_VISDAT_SLICE_ND_H
