/************************************
 *   added:     04.01.2020          *
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
    D_Bio_NucleusImage(Mat *pMA_NucleiBinary, vector<Mat*> vpMA_FociBinary, vector<Mat*> vpMA_Values, Point P_Offset = Point(0, 0), double time = 0, int neighborhood = 4);

    int calc_NucleiDecomposition(Mat *pMA_NucleiBinary, vector<Mat*> vpMA_FociBinary, vector<Mat*> vpMA_Values, Point P_Offset = Point(0, 0), double time = 0, int neighborhood = 4);

private:
    double m_time = 0;
    vector<D_Bio_NucleusBlob>   vNuclei;

};

#endif // D_BIO_NUCLEUSIMAGE_H
