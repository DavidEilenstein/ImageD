/************************************
 *   added:     04.01.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleusblob.h"

D_Bio_NucleusBlob::D_Bio_NucleusBlob()
{

}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(QString QS_PathLoad)
{
    if(load(QS_PathLoad))
        CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, Point Offset)
{
    //save data

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, double time, Point Offset)
{
    //save data
    m_time = time;

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs, Point Offset)
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

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<double> signal_medians, vector<double> signal_meddevs, double time, Point Offset)
{
    //save data
    m_time = time;
    vSignalMedians = signal_medians;
    vSignalMedDevs = signal_meddevs;

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

size_t D_Bio_NucleusBlob::leftmost()
{
    int l = INFINITY;
    for(size_t i = 0; i < m_contour.size(); i++)
        if(m_contour[i].x < l)
            l = m_contour[i].x;

    return l;
}

size_t D_Bio_NucleusBlob::topmost()
{
    int t = INFINITY;
    for(size_t i = 0; i < m_contour.size(); i++)
        if(m_contour[i].y < t)
            t = m_contour[i].y;

    return t;
}

int D_Bio_NucleusBlob::save(QString path)
{
    //only save if not part of neigbour image (stichting)
    if(block_stitching_border)
        if(leftmost() > block_stitching_border_x || topmost() > block_stitching_border_y)
            return ER_okay;

    //qDebug() << "D_Bio_NucleusBlob::save";

    //TYX coordinate
    QString QS_Coordinate_TYX = "_T" + QString::number(m_time) + "_Y" + QString::number(static_cast<int>(m_centroid.y)) + "_X" + QString::number(static_cast<int>(m_centroid.x));

    //add nucleus ID
    path += "/Nucleus" + QS_Coordinate_TYX;

    //directory
    QDir DIR_Save(path);
    if(!DIR_Save.exists())
    {
        QDir().mkdir(DIR_Save.path());
        if(!DIR_Save.exists())
            return ER_file_not_exist;
    }

    //stream to text file
    ofstream OS_NucleusFile((DIR_Save.path() + "/Nucleus_" + QS_Coordinate_TYX + ".txt").toStdString());
    if(!OS_NucleusFile.is_open())
    {
        //qDebug() << "D_Bio_NucleusBlob::save" << "ERROR Stream not open:" << DIR_Save.path() + "/Nucleus_T" + QString::number(m_time) + "_X" + QString::number(static_cast<int>(m_centroid.x)) + "_Y" + QString::number(static_cast<int>(m_centroid.y))+ ".txt";
        return ER_StreamNotOpen;
    }

    //values
    OS_NucleusFile << "Median";
    for(size_t i = 0; i < vSignalMedians.size(); i++)
    {
        OS_NucleusFile << ";";
        OS_NucleusFile << vSignalMedians[i];
    }
    OS_NucleusFile << "\n";
    OS_NucleusFile << "AverageAbsoluteDeviationFromMedian";
    for(size_t i = 0; i < vSignalMedDevs.size(); i++)
    {
        OS_NucleusFile << ";";
        OS_NucleusFile << vSignalMedDevs[i];
    }

    //contour
    OS_NucleusFile << "\n";
    OS_NucleusFile << "CountourPixels";
    for(size_t i = 0; i < m_contour.size(); i++)
        OS_NucleusFile << "\n" << m_contour[i].x << ";" << m_contour[i].y;

    //close stream
    OS_NucleusFile.close();

    //Foci
    for(size_t i_c = 0; i_c < vvFoci.size(); i_c++)
    {
        //qDebug() << "D_Bio_NucleusBlob::save" << "Save foci channel" << i_c;

        //directory
        QDir DIR_FocusChannel(path + "/Foci_" + QString::number(i_c));
        if(!DIR_FocusChannel.exists())
        {
            QDir().mkdir(DIR_FocusChannel.path());
            if(!DIR_FocusChannel.exists())
                return ER_file_not_exist;
        }

        for(size_t i_f = 0; i_f < vvFoci[i_c].size(); i_f++)
        {
            //qDebug() << "D_Bio_NucleusBlob::save" << "Save foci channel" << i_c << "focus" << i_f;
            int ER = vvFoci[i_c][i_f].save(DIR_FocusChannel.path());
            if(ER != ER_okay)
            {
                //qDebug() << "D_Bio_NucleusBlob::save" << "Save foci channel" << i_c << "focus " << i_f << "ERROR:" << QSL_Errors[ER];
                return ER;
            }
        }
    }

    return ER_okay;
}

bool D_Bio_NucleusBlob::load(QString QS_DirLoad)
{
    //Dir
    QDir DIR(QS_DirLoad);
    if(!DIR.exists())
        return false;

    //--------------------------------------------------- Nucleus File

    //decompose entries
    QStringList QSL_Nucleus = DIR.entryList(QDir::Files | QDir::NoDotAndDotDot);

    //check file
    QFileInfo FI;
    bool found_txt;
    for(int i = 0; i < QSL_Nucleus.size() && !found_txt; i++)
    {
        FI = QFileInfo(QSL_Nucleus[i]);
        if(FI.exists())
            if(FI.suffix() == "txt")
                if(FI.absoluteFilePath().contains("Nucleus"))
                    found_txt = true;
    }
    if(!found_txt)
        return false;

    //file
    QFile F(FI.absoluteFilePath());
    if (!F.open(QIODevice::ReadOnly))
        return false;

    //text stream
    QTextStream TS(&F);

    //clear old
    vSignalMedians.clear();
    vSignalMedDevs.clear();
    m_contour.clear();

    //read line by line
    for(size_t l = 0; !TS.atEnd(); l++)
    {
        //line and blocks in line
        QString QS_line = TS.readLine();
        QStringList QSL_Line = QS_line.split(";");

        //check if string->number conversion works (used below)
        bool ok;

        //line empty?
        if(!QSL_Line.empty())
        {
            //line type
            QString QS_FirstEntry = QSL_Line[0];
            if(QS_FirstEntry == "Median")
            {
                for(int i = 1; i < QSL_Line.size(); i++)
                {
                    double median = QSL_Line[i].toDouble(&ok);
                    if(ok)
                        vSignalMedians.push_back(median);
                    else
                        return false;
                }

            }
            else if(QS_FirstEntry == "AverageAbsoluteDeviationFromMedian")
            {
                for(int i = 1; i < QSL_Line.size(); i++)
                {
                    double meddev = QSL_Line[i].toDouble(&ok);
                    if(ok)
                        vSignalMedDevs.push_back(meddev);
                    else
                        return false;
                }
            }
            else if(QS_FirstEntry == "CountourPixels")
            {
                //do nothing, this line is just a description
            }
            else
            {
                //read ContourPoint
                if(QSL_Line.size() == 2)
                {
                    int x = QSL_Line[0].toUInt(&ok);
                    if(!ok)
                        return false;

                    int y = QSL_Line[1].toUInt(&ok);
                    if(!ok)
                        return false;

                    m_contour.push_back(Point(x, y));
                }
                else
                    return false;
            }
        }
    }

    //close file
    F.close();

    //--------------------------------------------------- Foci File

    //decompose entries
    QStringList QSL_Foci    = DIR.entryList(QDir::Dirs  | QDir::NoDotAndDotDot);

    //Foci dirs
    vector<QDir> vDirsFoci;
    for(int i = 0; i < QSL_Foci.size(); i++)
    {
        QDir DIR_Focus(QSL_Foci[i]);
        if(DIR_Focus.exists())
            if(DIR_Focus.path().contains("Foci"))
                vDirsFoci.push_back(DIR_Focus);
    }

    //set foci channels
    set_FociChannels(vDirsFoci.size());

    //get foci
    for(size_t c = 0; c < vDirsFoci.size(); c++)
    {
        //decompose entries
        QStringList QSL_Foci = vDirsFoci[c].entryList(QDir::Files | QDir::NoDotAndDotDot);

        //check if files are valid foci files
        for(int i = 0; i < QSL_Foci.size(); i++)
        {
            QFileInfo FI_Focus = QFileInfo(QSL_Foci[i]);
            if(FI_Focus.exists())
                if(FI_Focus.suffix() == "txt")
                    if(FI_Focus.absoluteFilePath().contains("Focus"))
                        add_Focus(c, D_Bio_Focus(FI_Focus.absoluteFilePath()));
        }
    }



    //--------------------------------------------------- end

    //finish
    return true;
}

void D_Bio_NucleusBlob::CalcFeats()
{
    //empty?
    if(m_contour.empty())
    {
        //qDebug() << "D_Bio_NucleusBlob::CalcFeats()" << "WARNING Contour empty";
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
        //qDebug() << "D_Bio_NucleusBlob::CalcFeats() centroid x/y" << center_x << center_y << "WARNING No mass!";
        m_centroid = Point2f(center_x, center_y);
    }
    else
    {
        double center_x = moments_tmp.m10 / moments_tmp.m00;
        double center_y = moments_tmp.m01 / moments_tmp.m00;
        //qDebug() << "D_Bio_NucleusBlob::CalcFeats() centroid x/y" << center_x << center_y;
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
