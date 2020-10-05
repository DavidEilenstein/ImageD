/************************************
 *   added:     05.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_IMG_PROC_3DFACTORY_H
#define D_IMG_PROC_3DFACTORY_H

//own
#include <d_enum.h>
#include <d_img_proc_3d.h>
#include <d_stat.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_value_distribution_list.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <thread>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_Img_Proc_3dFactory
{
public:
    D_Img_Proc_3dFactory();

    static function<int (Mat *, Mat *)>                         Duplicate                       ();
    static function<int (Mat *, Mat *)>                         Pad_Border                      (int border_size_x, int border_size_y, int border_size_z, int border_type = BORDER_CONSTANT, double border_val = 0);

    static function<int (Mat *, Mat *, Mat*)>                   Filter_Function                 (function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);
    static function<int (Mat *, Mat *, Mat*)>                   Filter_Function_8bit            (function<uchar  (double cur, double nei)> F1_CenterImage, function<uchar  (double f1r, double msk)> F2_f1mask, function<uchar  (vector<double> vf2r)> F3_Combine, function<uchar  (double f3r, double cen)> F4_f3center, int border_type = BORDER_CONSTANT, bool DoNonZeroMaskOnly = false);


    static function<int (Mat *, Mat *)>                         Filter_Median                   (int size_x = 3, int size_y = 3, int size_z = 3);
    static function<int (Mat *, Mat *)>                         Filter_Eilenstein_Greater_Sum   (int size_x = 3, int size_y = 3, int size_z = 3);

    static function<int (Mat *, Mat *)>                         Morphology_Dilation             (int size_x = 3, int size_y = 3, int size_z = 3);
    static function<int (Mat *, Mat *)>                         Morphology_Erosion              (int size_x = 3, int size_y = 3, int size_z = 3);

    static function<int (Mat *, Mat *)>                         Neighborhood_Configs            ();
    static function<int (Mat *, Mat *)>                         Euler_Number                    (double *euler_number);

    static function<int (Mat *, Mat *)>                         Distance_Transformation_EDT     (double spacing_x = 1, double spacing_y = 1, double spacing_z = 1);



};

#endif // D_IMG_PROC_3DFACTORY_H
