/************************************
 *   added:     04.01.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_focus.h"

D_Bio_Focus::D_Bio_Focus()
{

}

D_Bio_Focus::D_Bio_Focus(vector<Point> contour_points)
{
    //save data
    m_contour = contour_points;

    CalcFeats();
}

D_Bio_Focus::D_Bio_Focus(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs)
{
    //save data
    m_contour = contour_points;
    vSignalMedians = signal_medians;
    vSignalMedDevs = signal_meddevs;

    CalcFeats();
}

int D_Bio_Focus::save(QString path)
{
    qDebug() << "D_Bio_Focus::save";

    //directory
    QDir DIR_Save(path);
    if(!DIR_Save.exists())
        QDir().mkdir(DIR_Save.path());
    if(!DIR_Save.exists())
        return ER_file_not_exist;

    //stream to text file
    ofstream OS_FocusFile((DIR_Save.path() + "/Focus_X" + QString::number(static_cast<int>(m_centroid.x)) + "_Y" + QString::number(static_cast<int>(m_centroid.y)) + ".txt").toStdString());

    //values
    for(size_t i = 0; i < vSignalMedians.size(); i++)
    {
        if(i > 0)
            OS_FocusFile << ";";
        OS_FocusFile << vSignalMedians[i];
    }
    OS_FocusFile << "\n";
    for(size_t i = 0; i < vSignalMedDevs.size(); i++)
    {
        if(i > 0)
            OS_FocusFile << ";";
        OS_FocusFile << vSignalMedDevs[i];
    }

    //contour
    for(size_t i = 0; i < m_contour.size(); i++)
        OS_FocusFile << "\n" << m_contour[i].x << ";" << m_contour[i].y;

    //close stream
    OS_FocusFile.close();

    return ER_okay;
}

void D_Bio_Focus::CalcFeats()
{
    //calc moments
    m_moments = moments(m_contour);

    //calc centroids
    if(m_moments.m00 == 0)
        m_centroid = Point2f(m_contour[0].x, m_contour[0].y);
    else
       m_centroid = Point2f(m_moments.m10 / m_moments.m00, m_moments.m01 / m_moments.m10);

    //Area
    m_area = contourArea(m_contour);

    //Perimeter
    double perimeter = arcLength(m_contour, true);

    //convex hull
    convexHull(m_contour, m_convex_hull);
    double hull_perimeter = arcLength(m_convex_hull, true);

    //other cool features
    m_compactness          = (PI_4_0 * m_area) / (perimeter * perimeter);
    m_convexity            = hull_perimeter / perimeter;
}
