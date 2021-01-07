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

int D_Bio_NucleusBlob::save(QString path)
{
    qDebug() << "D_Bio_NucleusBlob::save";

    //add nucleus ID
    path += "/Nucleus_T" + QString::number(m_time) + "_X" + QString::number(static_cast<int>(m_centroid.x)) + "_Y" + QString::number(static_cast<int>(m_centroid.y));

    //directory
    QDir DIR_Save(path);
    if(!DIR_Save.exists())
        QDir().mkdir(DIR_Save.path());
    if(!DIR_Save.exists())
        return ER_file_not_exist;

    //stream to text file
    ofstream OS_NucleusFile((DIR_Save.path() + "/Nucleus_T" + QString::number(m_time) + "_X" + QString::number(static_cast<int>(m_centroid.x)) + "_Y" + QString::number(static_cast<int>(m_centroid.y))+ ".txt").toStdString());

    //values
    for(size_t i = 0; i < vSignalMedians.size(); i++)
    {
        if(i > 0)
            OS_NucleusFile << ";";
        OS_NucleusFile << vSignalMedians[i];
    }
    OS_NucleusFile << "\n";
    for(size_t i = 0; i < vSignalMedDevs.size(); i++)
    {
        if(i > 0)
            OS_NucleusFile << ";";
        OS_NucleusFile << vSignalMedDevs[i];
    }

    //contour
    for(size_t i = 0; i < m_contour.size(); i++)
        OS_NucleusFile << "\n" << m_contour[i].x << ";" << m_contour[i].y;

    //close stream
    OS_NucleusFile.close();

    //Foci
    for(size_t c = 0; c < vvFoci.size(); c++)
    {
        //directory
        QDir DIR_FocusChannel(path + "/Foci_" + QString::number(c));
        if(!DIR_FocusChannel.exists())
            QDir().mkdir(DIR_FocusChannel.path());
        if(!DIR_FocusChannel.exists())
            return ER_file_not_exist;

        for(size_t f = 0; f < vvFoci[c].size(); f++)
            vvFoci[f][c].save(DIR_FocusChannel.path());
    }

    return ER_okay;
}
