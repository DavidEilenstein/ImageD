/************************************
 *   added:     30.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_COMPONENT_H
#define D_COMPONENT_H

//own
#include <d_enum.h>

//general
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//Qt
#include <QString>
#include <QDebug>
#include <QStringList>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_Component
{
public:
    //constuctors
    D_Component();
    D_Component(int number);
    D_Component(vector<Point> points2init);
    D_Component(vector<Point> points2init, int number);

    //basic functions
    void            add_Point(Point point2add)          {vp_Coordinates.push_back(point2add);   Need2Updated();}
    void            add_Point(int x, int y)             {vp_Coordinates.push_back(Point(x, y)); Need2Updated();}
    void            clear()                             {vp_Coordinates.clear();                Need2Updated();}
    size_t          get_Size()                          {return vp_Coordinates.size();}

    //calc
    void            Calc_All();
    void            Calc_Mat();
    void            Calc_Contour();
    void            Calc_Distance();
    void            Calc_Features();    

    //get
    Mat             *get_pMat()                         {return &MA_Cropped;}
    Mat             get_Mat()                           {return MA_Cropped;}
    double          get_Feature(int feature)            {return (feature < vd_Features.size() && feature >= 0) ? vd_Features[feature] : 0;}
    vector<Point>   get_Coordinates()                   {return vp_Coordinates;}
    vector<Point>   get_Contour()                       {return vp_Contour;}
    Point2f         get_Centroid()                      {return p_Centroid;}
    vector<Point>   get_Contour_ConvexHull()            {return vp_ConvexHull;}
    //Rect          get_CropRect()                      {return r_CropRect;}
    Point           get_Offset()                        {return p_Offset;}
    Rect            get_BndBox_Rect()                   {return r_BoundingBox_Rect;}
    RotatedRect     get_BndBox_Rotate()                 {return r_BoundingBox_Rotate;}
    RotatedRect     get_Ellipse_Fitted()                {return r_EllipseFit;}

    //setter
    void            set_Name(QString name)              {QS_Name = name;}
    void            set_Number(int number)              {i_Number = number;}


private:

    //elements
    int                     top     = 0;
    int                     bottom  = 0;
    int                     left    = 0;
    int                     right   = 0;
    int                     width   = 0;
    int                     height  = 0;
    vector<Point>           vp_Coordinates;
    Mat                     MA_Cropped;
    Mat                     MA_Distance;
    Point                   p_Offset;
    vector<Point>           vp_Contour;
    vector<double>          vd_Features;
    Moments                 m_Moments;
    double                  m_HuMoments[7];
    Point2f                 p_Centroid;
    int                     i_Holes;
    Rect                    r_BoundingBox_Rect;
    RotatedRect             r_BoundingBox_Rotate;
    Point2f                 p_EnclosingCircle_Center;
    float                   f_EnclosingCircle_Radius = 0.0;
    Point                   p_InclosingCircle_Center;
    float                   f_InclosingCircle_Radius = 0.0;
    vector<Point>           vp_ConvexHull;
    RotatedRect             r_EllipseFit;


    //checks
    void                    Need2Updated();
    bool                    calced_features = false;
    bool                    calced_contour = false;
    bool                    calced_mat = false;

    //context
    int                     i_Number = 0;
    QString                 QS_Name = "";

};

#endif // D_COMPONENT_H
