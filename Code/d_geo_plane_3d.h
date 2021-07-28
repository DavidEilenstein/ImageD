/************************************
 *   added:     29.03.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_GEO_PLANE_3D_H
#define D_GEO_PLANE_3D_H

//own
#include <d_enum.h>
#include <d_geo_point_3d.h>
#include <d_geo_line_3d.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

//Qt
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Geo_Plane_3D
{
public:
    D_Geo_Plane_3D();
};

#endif // D_GEO_PLANE_3D_H
