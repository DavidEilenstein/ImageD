/************************************
 *   added:     22.05.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VISDAT_HEADER_H
#define D_VISDAT_HEADER_H

//own
#include <d_enum.h>

//general
#include <vector>

//Qt
#include <QString>
#include <QDateTime>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_VisDat_Header
{
public:
    D_VisDat_Header();
    D_VisDat_Header(vector<int> v_sizes, int type);

  //bool            isValid()                   {return magic_identifier == "8128" ? true : false;}
    int             Type_of_mat()               {return type_of_mat;}
    int             Dim_size_x()                {return dim_size_x;}
    int             Dim_size_y()                {return dim_size_y;}
    int             Dim_size_z()                {return dim_size_z;}
    int             Dim_size_t()                {return dim_size_t;}
    int             Dim_size_s()                {return dim_size_s;}
    int             Dim_size_p()                {return dim_size_p;}
    int             Time_Year()                 {return t_year;}
    int             Time_Month()                {return t_year;}
    int             Time_Day()                  {return t_year;}
    int             Time_Hour()                 {return t_year;}
    int             Time_Minute()               {return t_year;}
    int             Time_Second()               {return t_year;}
    QString         SaveTime();

    int             set_Size(vector<int> v_sizes);

private:

    //decorative stuff
    const char      magic_identifier[5]         = "8128"; //NEVER CHANGE THIS (trust me, it's perfect)
    const char      header_text[256]            = "***May the force be with you my hacker friend ;-) ImageD visual data file. Read with ImageD > AddStep > Source > Load > Load VisDat.                                                                                                                        ***";
                                                //"Header Text Length---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    //Type
    int             type_of_mat                 = CV_8UC1;

    //Dimensions
    int             dim_size_x                  = 1;
    int             dim_size_y                  = 1;
    int             dim_size_z                  = 1;
    int             dim_size_t                  = 1;
    int             dim_size_s                  = 1;
    int             dim_size_p                  = 1;

    //date and time of saving
    int             t_year                      = 33;
    int             t_month                     = 4;
    int             t_day                       = 3;
    int             t_hour                      = 9;
    int             t_minute                    = 0;
    int             t_second                    = 0;
};

#endif // D_VISDAT_HEADER_H
