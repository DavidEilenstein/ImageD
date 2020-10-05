/************************************
 *   added:     30.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_COMPONENT_LIST_H
#define D_COMPONENT_LIST_H

//own
#include <d_enum.h>
#include <d_component.h>

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

class D_Component_List
{
public:
    //contructor
    D_Component_List();
    D_Component_List(Mat *pMA_BinaryOrLabel, int connectivity = 8);

    //init
    int                     set_Mat(Mat *pMA_BinaryOrLabel, int connectivity = 8);

    //get
    D_Component             get_Component(int index)            {return (index >= 0 && index < m_Components.size()) ? m_Components[index] : m_Components[0];}
    size_t                  get_size()                          {return m_Components.size();}
    vector<D_Component>     get_ComponentVector()               {return m_Components;}

    double                  get_Feature(int comp, int feat)     {return m_Components[comp].get_Feature(feat);}
    vector<double>          get_FeatureVector(int feature);
    vector<double>          get_FeatureVector_BG(int feature);

    Mat                     get_MatBinary()                     {return MA_Binary;}
    Mat                     *get_pMatBinary()                   {return &MA_Binary;}
    Mat                     get_MatLabels()                     {return MA_Labels;}
    Mat                     *get_pMatLabels()                   {return &MA_Labels;}

    Point2f                 get_Centroid(int comp)              {return m_Components[comp].get_Centroid();}
    vector<Point2f>         get_CentroidVector();
    vector<Point2f>         get_CentroidVector_BG();

    Point                   get_Offset(int comp)                {return m_Components[comp].get_Offset();}
    vector<Point>           get_OffsetVector();
    vector<Point2f>         get_OffsetVector_2f();
    vector<Point>           get_OffsetVector_BG();

    vector<vector<Point>>   get_ContourVector();
    vector<vector<Point>>   get_ContourVector_BG();
    vector<vector<Point>>   get_ContourVector_ConvexHull();

    vector<Rect>            get_BndBox_Rect_Vector();
    Rect                    get_BndBox_Rect(int comp)       {return m_Components[comp].get_BndBox_Rect();}
    vector<RotatedRect>     get_BndBox_Rotate_Vector();
    RotatedRect             get_BndBox_Rotate(int comp)     {return m_Components[comp].get_BndBox_Rotate();}
    vector<RotatedRect>     get_Ellipse_Fitted_Vector();
    RotatedRect             get_Ellipse_Fitted(int comp)    {return m_Components[comp].get_Ellipse_Fitted();}

    vector<Point>           get_Coordinates(int comp)           {return m_Components[comp].get_Coordinates();}


    //basics
    void                    Components_Updated();
    int                     size()                              {return static_cast<int>(m_Components.size());}
    void                    clear()                             {m_Components.clear();}

    //save
    void                    save_all(QString path_dir);

private:

    Mat                     MA_Binary;
    Mat                     MA_Labels;

    bool                    initialized = false;
    int                     Split_Labels_2_Components();


    vector<D_Component>     m_Components;
    bool                    b_Components()                  {return static_cast<bool>(m_Components.size());}

    //stream and save
    ofstream                OS_Save;
    QDir                    DIR_Save;

};

#endif // D_COMPONENT_LIST_H
