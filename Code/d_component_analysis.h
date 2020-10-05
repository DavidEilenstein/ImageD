/************************************
 *   added:     25.09.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_COMPONENT_ANALYSIS_H
#define D_COMPONENT_ANALYSIS_H

//own
#include <d_enum.h>
#include <d_component.h>
#include <d_component_list_context.h>
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
using namespace cv;

class D_Component_Analysis
{
public:
    D_Component_Analysis();
};

#endif // D_COMPONENT_ANALYSIS_H
