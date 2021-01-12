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

D_Bio_Focus::D_Bio_Focus(vector<Point> contour_points, Point Offset)
{
    //save data
    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

D_Bio_Focus::D_Bio_Focus(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs, Point Offset)
{
    //save data
    vSignalMedians = signal_medians;
    vSignalMedDevs = signal_meddevs;

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

int D_Bio_Focus::save(QString path)
{
    //qDebug() << "D_Bio_Focus::save";

    //feats calced?
    //qDebug << "D_Bio_Focus::save" << "Feat calced:" << state_feats_calced;
    if(!state_feats_calced)
    {
        //qDebug() << "D_Bio_Focus::save" << "feats not calced (now trying to)";
        CalcFeats();
        if(!state_feats_calced)
        {
            //qDebug() << "D_Bio_Focus::save" << "calc feats failed";
            return ER_other;
        }
        //qDebug() << "D_Bio_Focus::save" << "calc feats sucess";
    }
    //qDebug() << "D_Bio_Focus::save" << "feats are calced";

    //directory
    //qDebug() << "D_Bio_Focus::save" << "Directory";
    QDir DIR_Save(path);
    if(!DIR_Save.exists())
    {
        //qDebug() << "D_Bio_Focus::save" << "Directory" << DIR_Save.path() << "not exists";
        QDir().mkdir(DIR_Save.path());
        //qDebug() << "D_Bio_Focus::save" << "Directory" << DIR_Save.path() << "tried to create";
        if(!DIR_Save.exists())
        {
            //qDebug() << "D_Bio_Focus::save" << "Directory" << DIR_Save.path() << "creation failed";
            return ER_file_not_exist;
        }
        //qDebug() << "D_Bio_Focus::save" << "Directory" << DIR_Save.path() << "created";
    }

    //stream to text file
    //qDebug() << "D_Bio_Focus::save" << "Save Path";
    //qDebug() << "D_Bio_Focus::save" << "Save Path" << DIR_Save.path();
    //qDebug() << "D_Bio_Focus::save" << "Save Path" << m_centroid.x;
    //qDebug() << "D_Bio_Focus::save" << "Save Path" << QString::number(static_cast<int>(m_centroid.x));
    //qDebug() << "D_Bio_Focus::save" << "Save Path" << m_centroid.y;
    //qDebug() << "D_Bio_Focus::save" << "Save Path" << QString::number(static_cast<int>(m_centroid.y));
    QString QS_PathFocusFile = DIR_Save.path() + "/Focus_X" + QString::number(static_cast<int>(m_centroid.x)) + "_Y" + QString::number(static_cast<int>(m_centroid.y)) + ".txt";
    //qDebug() << "D_Bio_Focus::save" << "Start Stream" << QS_PathFocusFile;
    ofstream OS_FocusFile(QS_PathFocusFile.toStdString());
    if(!OS_FocusFile.is_open())
    {
        //qDebug() << "D_Bio_NucleusBlob::save" << "ERROR Stream not open:" << QS_PathFocusFile;
        return ER_StreamNotOpen;
    }

    //values
    //qDebug() << "D_Bio_Focus::save" << "Values Median";
    OS_FocusFile << "Median";
    for(size_t i = 0; i < vSignalMedians.size(); i++)
    {
        OS_FocusFile << ";";
        OS_FocusFile << vSignalMedians[i];
    }
    OS_FocusFile << "\n";
    //qDebug() << "D_Bio_Focus::save" << "Values MedianDeviation";
    OS_FocusFile << "AverageAbsoluteDeviationFromMedian";
    for(size_t i = 0; i < vSignalMedDevs.size(); i++)
    {
        OS_FocusFile << ";";
        OS_FocusFile << vSignalMedDevs[i];
    }

    //contour
    //qDebug() << "D_Bio_Focus::save" << "Countour";
    OS_FocusFile << "\n";
    OS_FocusFile << "CountourPixels";
    for(size_t i = 0; i < m_contour.size(); i++)
        OS_FocusFile << "\n" << m_contour[i].x << ";" << m_contour[i].y;

    //close stream
    //qDebug() << "D_Bio_Focus::save" << "Close Stream";
    OS_FocusFile.close();
    //OS_FocusFile.clear();

    return ER_okay;
}

void D_Bio_Focus::CalcFeats()
{
    //empty?
    if(m_contour.empty())
    {
        //qDebug() << "D_Bio_Focus::CalcFeats()" << "WARNING Contour empty";
        m_centroid      = Point2f(0, 0);
        m_area          = 0;
        m_compactness   = 0;
        m_convexity     = 0;
        return;
    }

    //calc moments
    Moments moments_tmp = moments(m_contour);

    //calc centroids
    if(moments_tmp.m00 == 0)
    {
        double center_x = m_contour[0].x;
        double center_y = m_contour[0].y;
        //qDebug() << "D_Bio_Focus::CalcFeats() centroid x/y" << center_x << center_y << "WARNING No mass!";
        m_centroid = Point2f(center_x, center_y);
    }
    else
    {
        double center_x = moments_tmp.m10 / moments_tmp.m00;
        double center_y = moments_tmp.m01 / moments_tmp.m00;
        //qDebug() << "D_Bio_Focus::CalcFeats() centroid x/y" << center_x << center_y;
        m_centroid = Point2f(center_x, center_y);
    }

    //Area
    if(moments_tmp.m00 == 0)
        m_area = 0;
    else
        m_area = contourArea(m_contour);

    //Perimeter
    double perimeter = arcLength(m_contour, true);

    //convex hull
    convexHull(m_contour, m_convex_hull);
    double hull_perimeter = arcLength(m_convex_hull, true);

    //other features
    if(perimeter == 0)
    {
        m_compactness   = 0;
        m_convexity     = 0;
    }
    else
    {
        m_compactness   = (PI_4_0 * m_area) / (perimeter * perimeter);
        m_convexity     = hull_perimeter / perimeter;
    }

    state_feats_calced = true;
}
