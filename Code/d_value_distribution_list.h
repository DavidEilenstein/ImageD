/************************************
 *   added:     12.12.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VALUE_DISTRIBUTION_LIST_H
#define D_VALUE_DISTRIBUTION_LIST_H

//own
#include <d_enum.h>
#include <d_component_list.h>
#include <d_stat.h>

//general
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

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

class D_Value_Distribution_List
{
public:
    D_Value_Distribution_List();
    D_Value_Distribution_List(Mat *pMA_Label, Mat *pMA_Value, int connectivity = 8);

    //set
    int                                     set_Mats(Mat *pMA_Label, Mat *pMA_Value, int connectivity = 8);

    //get
    D_Component_List                        *get_CompList()             {return &m_CompList;}
    size_t                                  get_size()                  {return m_CompList.get_size();}
    double                                  get_Values(int comp, int axe, int cla, int val);
    vector<double>                          get_Values(int comp, int axe, int cla);
    vector<vector<double>>                  get_Values(int comp, int axe);
    vector<vector<vector<double>>>          get_Values(int comp);
    vector<vector<vector<vector<double>>>>  get_Values();
    double                                  get_Stat(int comp, int axe, int cla, int stat);
    vector<double>                          get_Stat(int comp, int axe, int cla);
    vector<vector<double>>                  get_Stat(int comp, int axe);
    vector<vector<vector<double>>>          get_Stat(int comp);
    vector<vector<vector<vector<double>>>>  get_Stat();
    vector<vector<double>>                  get_Axe(int axe, int stat = c_STAT_MEAN_ARITMETIC);



    //calc
    void                                    calc_All();
    void                                    calc_ComAxeClaVal();
    void                                    calc_ComAxeClaSta();

private:
    bool                                    m_Mats_Set = false;
    bool                                    Calced_All = false;

    D_Component_List                        m_CompList;
    Mat                                     MA_Values;

    bool                                    Calced_ComAxeClaVal = false;
    bool                                    Calced_ComAxeClaSta = false;
    vector<vector<vector<vector<double>>>>  vvvv_ComAxeClaVal;   //Component, Axis, Class, Value
    vector<vector<vector<vector<double>>>>  vvvv_ComAxeClaSta;   //Component, Axis, Class, Stat
};

#endif // D_VALUE_DISTRIBUTION_LIST_H
