/************************************
 *   added:     25.09.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_COMPONENT_LIST_CONTEXT_H
#define D_COMPONENT_LIST_CONTEXT_H

//own
#include <d_enum.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_stat.h>
#include <d_math.h>

//general
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <thread>

//Qt
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QDir>
#include <QFileInfo>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_Component_List_Context class inherits D_Component_List and calculates features of the blobs depending on the relation to other blobs in the same represented 2D binary image.
 * \details Takes a distance interval and two point/line types (D_COMPDIST) to measure the distance from/to.
 * For each blob (D_Component) a list with each blob within that distance is created.
 * A feature (D_FEATURE_ENUM) is selected.
 * For each blob in the mentioned list this feature is determined.
 * The values in this list are summarized using the chosen statistic quantity (D_STATISTIC_ENUM)
 */
class D_Component_List_Context
{
public:
    D_Component_List_Context                                ();
    D_Component_List_Context                                (Mat *pMA_BinaryOrLabel, int connectivity = 8);

    int                     set_Mat                         (Mat *pMA_BinaryOrLabel, int connectivity = 8);

    bool                    InDist_Comp2Comp                (int c1, int pt_type1, int c2, int pt_type2, double dist_min, double dist_max);
    vector<int>             InDist_CompsIndices             (int c1, int pt_type1,         int pt_type2, double dist_min, double dist_max);

    vector<double>          get_AllComps_StatFeatInDist     (int type1,                    int type2,    double dist_min, double dist_max, int feat, int stat);
    vector<double>          get_AllComps_StatFeatInDist_BG  (int type1,                    int type2,    double dist_min, double dist_max, int feat, int stat);

    bool                    IsCouple_CompareFeats           (int c1,                int c2,                          int feat1, int feat2, function<bool(double, double)> comparison);

    vector<vector<Point>>   get_PointCouples_Closest        (int type1, int type2, double dist_min, double dist_max, int feat1, int feat2, function<bool(double, double)> comparison);
    vector<vector<Point>>   get_PointCouples_AllInRange     (int type1, int type2, double dist_min, double dist_max, int feat1, int feat2, function<bool(double, double)> comparison);

    //Member acces
    D_Component_List        *get_pCompList()    {return &CompList;}

private:

    Point                   Point_Comp          (int c,  int type);
    Point2f                 Point2f_Comp        (int c,  int type);
    double                  Dist_Comp2Comp      (int c1, int type1, int c2, int type2);

    int                     CompCount           = 0;
    bool                    CompList_Calced     = false;
    D_Component_List        CompList;
};

#endif // D_COMPONENT_LIST_CONTEXT_H
