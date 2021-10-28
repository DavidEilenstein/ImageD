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
#include <d_bio_enum.h>
#include <d_contour.h>

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
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Bio_NucleusImage
{
public:
    D_Bio_NucleusImage();
    D_Bio_NucleusImage(vector<D_Bio_NucleusImage> vNucImgs2Merge, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time);
    D_Bio_NucleusImage(Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time);
    D_Bio_NucleusImage(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset_coordinates = Point(0, 0), Point P_Offset_mosaicgrid = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    D_Bio_NucleusImage(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset_coordinates = Point(0, 0), Point P_Offset_mosaicgrid = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    D_Bio_NucleusImage(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset_coordinates = Point(0, 0), Point P_Offset_mosaicgrid = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);

    int calc_NucleiDecomposition(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset_coordinates = Point(0, 0), Point P_Offset_mosaicgrid = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    int calc_NucleiDecomposition(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset_coordinates = Point(0, 0), Point P_Offset_mosaicgrid = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);
    int calc_NucleiDecomposition(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset_coordinates = Point(0, 0), Point P_Offset_mosaicgrid = Point(0, 0), size_t time = 0, int neighborhood = 4, bool blockSave_StichBorder_BottomRight = false, size_t block_x_right = INFINITY, size_t block_y_bottom = INFINITY);

    int load(QString path);
    int load_foci(QFileInfoList FIL_foci);
    int save(QString path, bool save_foci_in_nuclei, bool save_foci_separate, bool save_name_mosaic_not_coordiante);
    int save_PathExactDir(QString path, bool save_foci_in_nuclei, bool save_foci_separate, size_t x, size_t y, size_t t);

    void set_OffsetMosaicGrid(Point OffsetMosaicGrid)   {m_Offset_Grid = OffsetMosaicGrid;}
    void set_OffsetPixels(Point OffsetPixels)           {m_Offset_Coord = OffsetPixels;}

    int get_Contours_append(vector<vector<Point>> *pvScaledContours, double scale);
    vector<Point2f> get_Centroids(double scale, Point2f scaled_offset);
    int get_Centroids_append(vector<Point2f> *pvScaledCentroids, double scale);
    QStringList get_FociCounts();
    int get_FociCount_append(QStringList *pQSL_FociCounts);
    int get_ShapeInfo_append(QStringList *pQSL_ShapeInfo);
    int get_ChannelStat_append(QStringList *pQSL_Stat, size_t stat_index_bio_enum);

    vector<D_Contour> get_nuclei_contour_objects();
    void get_nuclei_contour_objects_append(vector<D_Contour> *pvContours);

    size_t get_nuclei_count()                       {return vNuclei.size();}
    size_t get_foci_channel_count()                 {return vvFoci.size();}
    size_t get_foci_count(size_t foci_channel)      {return foci_channel < get_foci_channel_count() ? vvFoci[foci_channel].size() : 0;}

    vector<vector<Point>>       get_nuclei_contours(double scale = 1, Point scaled_offset = Point(0, 0));
    vector<Point2f>             get_nuclei_centers(double scale = 1, Point scaled_offset = Point(0, 0));
    vector<Point2f>             get_foci_centers(size_t channel, double scale = 1, Point scaled_offset = Point(0, 0));
    vector<double>              get_foci_radii(size_t channel, double scale = 1);
    vector<double>              get_foci_diameters(size_t channel, double scale = 1);

    vector<D_Bio_NucleusBlob>   get_nuclei()                        {return vNuclei;}
    D_Bio_NucleusBlob           get_nucleus(size_t nuc)             {return nuc < vNuclei.size() ? vNuclei[nuc] : D_Bio_NucleusBlob();}
    D_Bio_Focus                 get_focus(size_t ch, size_t foc)    {return ch < vvFoci.size() ? (foc < vvFoci[ch].size() ? (vvFoci[ch][foc]) : (D_Bio_Focus())) : (D_Bio_Focus());}

    QString info();

    void    add_focus               (size_t channel, D_Bio_Focus Foc);
    void    add_foci                (size_t channel, vector<D_Bio_Focus> vFoc);
    void    add_nucleus             (D_Bio_NucleusBlob Nuc);
    void    add_nuclei              (vector<D_Bio_NucleusBlob> vNuc);

    bool    remove_focus            (Point P,           size_t channel,     double margin = 0);
    void    remove_foci             (vector<Point> vP,  size_t channel,     double margin = 0);
    bool    remove_nucleus          (Point P,                               double margin = 0);
    void    remove_nuclei           (vector<Point> vP,                      double margin = 0);
    void    remove_nuclei_foci_all  ();
    void    remove_foci_all         ();
    void    remove_nuclei_all       ();
    void    remove_nuclei_dulicates (vector<D_Bio_NucleusImage> vNucImgOther, double min_rel_intersection_for_remove = 0.5);

private:

    bool            load_focus(D_Bio_Focus *FocusLoad, QTextStream *pTS_FociChannel);

    size_t m_time = 0;
    Point m_Offset_Coord = Point(0, 0);
    Point m_Offset_Grid  = Point(0, 0);
    vector<D_Bio_NucleusBlob>   vNuclei;
    vector<vector<D_Bio_Focus>> vvFoci;
};

#endif // D_BIO_NUCLEUSIMAGE_H
