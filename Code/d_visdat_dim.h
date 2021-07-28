/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_DIM_H
#define D_VISDAT_DIM_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_header.h>

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
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_VisDat_Dim class Represents a 6D volume.
 * \details There are basic functionalities describing and changing the 6D volume.
 * This is used to describe the size of a multidimensional image D_VisDat_Obj .
 * There is a method for looping through such a volume pixel by pixel.
 *
 * The six dimensions are: Spacial X, spacial Y, spacial Z, time T, stack S and pages P. See: D_DIM_INDICES
 */
class D_VisDat_Dim
{

public:
    D_VisDat_Dim();
    D_VisDat_Dim(int X, int Y, int Z = 1, int T = 1, int S = 1, int P = 1);
    D_VisDat_Dim(vector<int> vDims);
    D_VisDat_Dim(Vec<int, c_DIM_NUMBER_OF> vDims);
    D_VisDat_Dim(D_VisDat_Header source_header);

    int             size_PixelCount     ();
    int             size_X              ()                      {return vSizes[c_DIM_X];}
    int             size_Y              ()                      {return vSizes[c_DIM_Y];}
    int             size_Z              ()                      {return vSizes[c_DIM_Z];}
    int             size_T              ()                      {return vSizes[c_DIM_T];}
    int             size_S              ()                      {return vSizes[c_DIM_S];}
    int             size_P              ()                      {return vSizes[c_DIM_P];}
    int             size_Dim            (int idx)               {return idx < vSizes.size() && idx >= 0 ? vSizes[idx] : 1;}
    vector<int>     size_DimsVec        ()                      {return vSizes;}
    Size            size_XY             ()                      {return Size(vSizes[c_DIM_X], vSizes[c_DIM_Y]);}
    Size            size_XZ             ()                      {return Size(vSizes[c_DIM_X], vSizes[c_DIM_Z]);}
    Size            size_YZ             ()                      {return Size(vSizes[c_DIM_Y], vSizes[c_DIM_Z]);}
    Size            size_Plane          (int i, int j)          {return i < c_DIM_NUMBER_OF && i >= 0 && j < c_DIM_NUMBER_OF && j >= 0 ? Size(vSizes[i], vSizes[j]) : size_XY();}

    QString         unit_X              ()                      {return QSL_Units[c_DIM_X];}
    QString         unit_Y              ()                      {return QSL_Units[c_DIM_Y];}
    QString         unit_Z              ()                      {return QSL_Units[c_DIM_Z];}
    QString         unit_T              ()                      {return QSL_Units[c_DIM_T];}
    QString         unit_S              ()                      {return QSL_Units[c_DIM_S];}
    QString         unit_P              ()                      {return QSL_Units[c_DIM_P];}
    QString         unit_Dim            (int d)                 {return d < c_DIM_NUMBER_OF && d >= 0 ? QSL_Units[d] : "error";}
    QStringList     unit_Dims           ()                      {return QSL_Units;}

    double          step_X              ()                      {return vSteps[c_DIM_X];}
    double          step_Y              ()                      {return vSteps[c_DIM_Y];}
    double          step_Z              ()                      {return vSteps[c_DIM_Z];}
    double          step_T              ()                      {return vSteps[c_DIM_T];}
    double          step_S              ()                      {return vSteps[c_DIM_S];}
    double          step_P              ()                      {return vSteps[c_DIM_P];}
    double          step_Dim            (int d)                 {return d < c_DIM_NUMBER_OF && d >= 0 ? vSteps[d] : 1;}
    double          step_Dims           ()                      {return vSteps[c_DIM_X];}

    void            set_size_X          (int X)                 {vSizes[c_DIM_X] = X;}
    void            set_size_Y          (int Y)                 {vSizes[c_DIM_Y] = Y;}
    void            set_size_Z          (int Z)                 {vSizes[c_DIM_Z] = Z;}
    void            set_size_T          (int T)                 {vSizes[c_DIM_T] = T;}
    void            set_size_S          (int S)                 {vSizes[c_DIM_S] = S;}
    void            set_size_P          (int P)                 {vSizes[c_DIM_P] = P;}
    void            set_size_Dim        (int idx, int val)      {if(idx < vSizes.size() && idx >= 0) vSizes[idx] = val;}
    void            set_size_Dims       (vector<int> sizes)     {if(sizes.size() == vSizes.size()) vSizes = sizes;}

    void            set_unit_X          (double step = 1, QString unit = "px")          {if(step > 0)   {vSteps[c_DIM_X] = step;    QSL_Units[c_DIM_X] = unit;}}
    void            set_unit_Y          (double step = 1, QString unit = "px")          {if(step > 0)   {vSteps[c_DIM_X] = step;    QSL_Units[c_DIM_X] = unit;}}
    void            set_unit_Z          (double step = 1, QString unit = "px")          {if(step > 0)   {vSteps[c_DIM_X] = step;    QSL_Units[c_DIM_X] = unit;}}
    void            set_unit_T          (double step = 1, QString unit = "px")          {if(step > 0)   {vSteps[c_DIM_X] = step;    QSL_Units[c_DIM_X] = unit;}}
    void            set_unit_S          (double step = 1, QString unit = "px")          {if(step > 0)   {vSteps[c_DIM_X] = step;    QSL_Units[c_DIM_X] = unit;}}
    void            set_unit_P          (double step = 1, QString unit = "px")          {if(step > 0)   {vSteps[c_DIM_X] = step;    QSL_Units[c_DIM_X] = unit;}}
    void            set_unit_Dim        (int d, double step = 1, QString unit = "u")    {if(step > 0 && d < c_DIM_NUMBER_OF && d >= 0)   {vSteps[d] = step;    QSL_Units[d] = unit;}}

    int                         extended_DimsCount  ();
    QString                     extended_DimsString ();
    bool                        is_Dims             (int dims)                      {return extended_DimsCount() == dims ? true : false;}
    bool                        is_DimsAtLeast      (int dims)                      {return extended_DimsCount() >= dims ? true : false;}
    bool                        is_1D               ()                              {return is_Dims(1);}
    bool                        is_2D               ()                              {return is_Dims(2);}
    bool                        is_3D               ()                              {return is_Dims(3);}
    bool                        is_4D               ()                              {return is_Dims(4);}
    bool                        is_5D               ()                              {return is_Dims(5);}
    bool                        is_6D               ()                              {return is_Dims(6);}
    bool                        inRangeOf           (D_VisDat_Dim VD_container);
    Vec<int, c_DIM_NUMBER_OF>   ForcePosInRange     (Vec<int, c_DIM_NUMBER_OF> pos);
    int                         DimOutRanged        (D_VisDat_Dim VD_container);
    bool                        isEqual             (D_VisDat_Dim VD_compare);

    QString         info                ();

    //loop positions
    void                        loop_Reset              ()                                  {v_LoopCurPos = {0, 0, 0, 0, 0, 0};}
    void                        loop_SetOffset          (Vec<int, c_DIM_NUMBER_OF> offset)  {v_LoopOffset = offset;}
    bool                        loop_Next               ();
    Vec<int, c_DIM_NUMBER_OF>   loop_PosCurrent         ()                                  {return v_LoopCurPos;}
    Vec<int, c_DIM_NUMBER_OF>   loop_PosCurrent_Offset  ();
private:
    Vec<int, c_DIM_NUMBER_OF>   v_LoopCurPos = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF>   v_LoopOffset = {0, 0, 0, 0, 0, 0};

private:

    vector<int>     vSizes = {1, 1, 1, 1, 1, 1};
    vector<double>  vSteps = {1, 1, 1, 1, 1, 1};
    QStringList     QSL_Units = {"px", "px", "px", "f", "", ""};

};

#endif // D_VISDAT_DIM_H
