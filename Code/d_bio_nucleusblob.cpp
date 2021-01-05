/************************************
 *   added:     04.01.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleusblob.h"

D_Bio_NucleusBlob::D_Bio_NucleusBlob()
    : D_Bio_Focus()
{

}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points)
    : D_Bio_Focus(contour_points)
{

}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, double time)
    : D_Bio_Focus(contour_points)
{
    //save data
    m_time = time;
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs)
    : D_Bio_Focus(contour_points, signal_medians, signal_meddevs)
{

}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs, double time)
    : D_Bio_Focus(contour_points, signal_medians, signal_meddevs)
{
    //save data
    m_time = time;
}
