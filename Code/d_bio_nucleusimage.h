/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_NUCLEUSIMAGE_H
#define D_BIO_NUCLEUSIMAGE_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>
#include <d_bio_nucleusblob.h>
#include <d_bio_focus.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>
#include <d_component_list.h>

//Qt
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QInputDialog>

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
using namespace cv;

class D_Bio_NucleusImage
{
public:
    D_Bio_NucleusImage();
    D_Bio_NucleusImage(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    D_Bio_NucleusImage(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    D_Bio_NucleusImage(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);

    int calc_NucleiDecomposition(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    int calc_NucleiDecomposition(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    int calc_NucleiDecomposition(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);

    int save(QString path);

    vector<D_Bio_NucleusBlob> get_nuclei() {return vNuclei;}

private:
    size_t m_time = 0;
    Point m_Offset = Point(0, 0);
    vector<D_Bio_NucleusBlob>   vNuclei;
};

#endif // D_BIO_NUCLEUSIMAGE_H
