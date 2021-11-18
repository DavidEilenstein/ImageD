#ifndef D_DATAVOLUME_3D_H
#define D_DATAVOLUME_3D_H

//own
#include <d_enum.h>
#include <d_visdat_obj.h>
#include <d_stat.h>

//general
#include <vector>
#include <thread>

//Qt
#include <QObject>
#include <QString>
#include <QDebug>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_DataVolume_3D
{
    //Q_OBJECT
public:
    D_DataVolume_3D();

    bool init_VolumeSize            (size_t sz, size_t sy, size_t sx);

    bool add_Value                  (size_t z, size_t y, size_t x, double value);
    bool add_Values                 (size_t z, size_t y, size_t x, vector<double> v_values);
    double get_Value                (size_t z, size_t y, size_t x, size_t i);
    vector<double> get_Values       (size_t z, size_t y, size_t x);

   D_VisDat_Obj calc_stats          (size_t stat, bool linear, Point3i mask_size, double default_value, int min_elements);

private:

    //raw data
    vector<vector<vector<vector<double>>>> vvvvData_ZYXI;

    static bool calc_stats_thread   (vector<vector<vector<vector<double>>>>* pvvvvDataIn_ZYXI, D_VisDat_Obj *pVD_StatOut, function<double (vector<double>)> F_stat, Point3i mask_size, Point3i P_start, Point3i P_end);

};

#endif // D_DATAVOLUME_3D_H
