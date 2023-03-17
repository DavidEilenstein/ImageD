/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_focus.h"

#include "d_bio_nucleusblob.h" //(included here to avoid circular include in headers)

D_Bio_Focus::D_Bio_Focus()
{

}

/*
D_Bio_Focus::D_Bio_Focus(QString QS_PathLoad)
{
     load(QS_PathLoad);
}
*/

D_Bio_Focus::D_Bio_Focus(vector<Point> contour_points, Point Offset)
{
    //apply offset to contour
    vector<Point> countour_with_offset(contour_points.size());
    for(size_t i = 0; i < countour_with_offset.size(); i++)
        countour_with_offset[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats(countour_with_offset);
}

D_Bio_Focus::D_Bio_Focus(vector<Point> contour_points, vector<vector<double> > SignalStats_StatChannel, Point Offset)
{
    //save data
    if(SignalStats_StatChannel.size() == VAL_STAT_NUMBER_OF)
        vvSignalStats_StatChannel = SignalStats_StatChannel;
    else
        vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(1, 0));

    //apply offset to contour
    vector<Point> countour_with_offset(contour_points.size());
    for(size_t i = 0; i < countour_with_offset.size(); i++)
        countour_with_offset[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats(countour_with_offset);
}

D_Bio_Focus::D_Bio_Focus(Point2f centroid, double area, double compactness, double convexity, vector<vector<double>> SignalStats_StatChannel, size_t ch_detected_in)
{
    //save data
    if(SignalStats_StatChannel.size() == VAL_STAT_NUMBER_OF)
        vvSignalStats_StatChannel = SignalStats_StatChannel;
    else
        vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(1, 0));

    m_centroid      = centroid;
    m_area          = area;
    m_compactness   = compactness;
    m_convexity     = convexity;

    m_channel_detected_in = ch_detected_in;

    //no stats need to be calced
    state_feats_calced = true;
}

void D_Bio_Focus::apply_shift(int shift_x, int shift_y)
{
    //shift centroid
    m_centroid += Point2f(shift_x, shift_y);
}

double D_Bio_Focus::attribute(size_t i_attrib, size_t ch_val, double scale_px2um)
{
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return 0;

    switch (i_attrib) {

    case ATTRIB_FOC_CENTER_X_PX:                    return centroid().x;
    case ATTRIB_FOC_CENTER_Y_PX:                    return centroid().y;
    case ATTRIB_FOC_AREA_PX:                        return area();
    case ATTRIB_FOC_CENTER_X_UM:                    return centroid().x * scale_px2um;
    case ATTRIB_FOC_CENTER_Y_UM:                    return centroid().y * scale_px2um;
    case ATTRIB_FOC_AREA_UM:                        return area() * scale_px2um * scale_px2um;
    case ATTRIB_FOC_CONVEXITY:                      return convexity();
    case ATTRIB_FOC_COMPACTNESS:                    return compactness();

    case ATTRIB_FOC_COUNT_CHX:                      return signal_stat(ch_val, VAL_STAT_COUNT);
    case ATTRIB_FOC_MEAN_CHX:                       return signal_stat(ch_val, VAL_STAT_MEAN);
    case ATTRIB_FOC_STD_CHX:                        return signal_stat(ch_val, VAL_STAT_STD);
    case ATTRIB_FOC_SKEWNESS_CHX:                   return signal_stat(ch_val, VAL_STAT_SKEW);
    case ATTRIB_FOC_KURTOSIS_CHX:                   return signal_stat(ch_val, VAL_STAT_KURTOSIS);
    case ATTRIB_FOC_MEDIAN_CHX:                     return signal_stat(ch_val, VAL_STAT_MEDIAN);
    case ATTRIB_FOC_ABSDEVMED_CHX:                  return signal_stat(ch_val, VAL_STAT_MEDIAN_DEVIATION);

    case ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_PX:        return overlap_area_any_focus(ch_val);
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_UM:        return overlap_area_any_focus(ch_val) * scale_px2um * scale_px2um;
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_REL:       return area() != 0.0 ? overlap_area_any_focus(ch_val) / area() : 0.0;
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNELS_OTHER_PX: return overlap_area_any_focus();
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNELS_OTHER_UM: return overlap_area_any_focus() * scale_px2um * scale_px2um;
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNELS_OTHER_REL:return area() != 0.0 ? overlap_area_any_focus() / area() : 0.0;

    case ATTRIB_FOC_DETECTED_IN_CH:                 return double(m_channel_detected_in);
    default:                                        return 0;}
}

bool D_Bio_Focus::attribute_is_value_channel_dependent(size_t i_attrib)
{
    switch (i_attrib) {

    //case ATTRIB_FOC_COUNT_CHX: formally dependent, but not really
    case ATTRIB_FOC_MEAN_CHX:
    case ATTRIB_FOC_STD_CHX:
    case ATTRIB_FOC_SKEWNESS_CHX:
    case ATTRIB_FOC_KURTOSIS_CHX:
    case ATTRIB_FOC_MEDIAN_CHX:
    case ATTRIB_FOC_ABSDEVMED_CHX:
        return true;

    default:
        return false;
    }
}

bool D_Bio_Focus::attribute_is_focus_channel_dependent(size_t i_attrib)
{
    switch (i_attrib) {

    case ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_PX:
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_UM:
    case ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_REL:
        return true;

    default:
        return false;
    }
}

double D_Bio_Focus::overlap_area(D_Bio_Focus *pFocOther)
{
    //qDebug() << "overlap_area" << "start";

    if(pFocOther == nullptr)
        return 0;

    //qDebug() << "overlap_area" << "try";

    //distance
    double d = D_Math::Distance(centroid(), pFocOther->centroid());

    //radii
    double r1 = radius_circle_equivalent();
    double r2 = pFocOther->radius_circle_equivalent();

    //overlap area
    //qDebug() << "overlap_area" << "end";
    return D_Math::AreaOverlapCircles(r1, r2, d);
}

double D_Bio_Focus::overlap_area_any_focus(size_t ch_foc)
{
    //qDebug() << "overlap_area_any_focus(" << ch_foc << ")" << "start";

    //unkown owner nuc
    if(pNucOwner == nullptr)
        return 0;

    //same channel as this foc is detected in
    if(ch_foc == m_channel_detected_in)
        return 0;

    //invalid focus channel
    if(ch_foc >= pNucOwner->get_FociChannels())
        return 0;

    //qDebug() << "overlap_area_any_focus(" << ch_foc << ")" << "try";

    //loop foci
    double overlap_sum = 0;
    //qDebug() << pNucOwner << nullptr;
    size_t n = pNucOwner->get_FociCount(ch_foc);
    //qDebug() << "overlap_area_any_focus(" << ch_foc << ")" << "start loop";
    for(size_t i = 0; i < n; i++)
    {
        //qDebug() << "overlap_area_any_focus(" << ch_foc << ")" << "get pFoc" << i;
        D_Bio_Focus* pFocOther = pNucOwner->get_pFocus(ch_foc, i);
        if(pFocOther != nullptr)
        {
            //qDebug() << "overlap_area_any_focus(" << ch_foc << ")" << "pFoc is not nullptr";
            overlap_sum += pFocOther->overlap_area(this);
        }
    }

    //sum of overlap area
    //qDebug() << "overlap_area_any_focus(" << ch_foc << ")" << "end";
    return overlap_sum;
}

double D_Bio_Focus::overlap_area_any_focus()
{
    //qDebug() << "overlap_area_any_focus" << "start";

    double overlap_sum = 0;
    for(size_t ch = 0; ch < pNucOwner->get_FociChannels(); ch++)
        overlap_sum += overlap_area_any_focus(ch);

    //qDebug() << "overlap_area_any_focus" << "end";
    return overlap_sum;
}

size_t D_Bio_Focus::channels()
{
    if(vvSignalStats_StatChannel.empty())
        return 0;
    else
        return vvSignalStats_StatChannel[0].size();
}

double D_Bio_Focus::signal_stat(size_t channel, size_t stat_local_id)
{
    if(stat_local_id >= vvSignalStats_StatChannel.size())
        return 0;

    if(channel >= vvSignalStats_StatChannel[stat_local_id].size())
        return 0;

    return vvSignalStats_StatChannel[stat_local_id][channel];
}

/*
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
    QString QS_PathFocusFile = DIR_Save.path() + "/Focus_Y" + QString::number(static_cast<int>(m_centroid.y)) + "_X" + QString::number(static_cast<int>(m_centroid.x)) + ".txt";
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
*/

/*
bool D_Bio_Focus::load(QString QS_PathLoad)
{
    //check file
    QFileInfo FI(QS_PathLoad);
    if(!FI.exists())
        return false;
    if(FI.suffix() != "txt")
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

    //finish
    return true;
}
*/

void D_Bio_Focus::CalcFeats(vector<Point> contour)
{
    //empty?
    if(contour.empty())
    {
        //qDebug() << "D_Bio_Focus::CalcFeats()" << "WARNING Contour empty";
        m_centroid      = Point2f(0, 0);
        m_area          = 0;
        m_compactness   = 0;
        m_convexity     = 0;
        return;
    }

    //calc moments
    Moments moments_tmp = moments(contour);

    //calc centroids
    if(moments_tmp.m00 == 0.0)
    {
        double center_x = contour[0].x;
        double center_y = contour[0].y;
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
    if(moments_tmp.m00 == 0.0)
        m_area = 0;
    else
        m_area = contourArea(contour);

    //Perimeter
    double perimeter = arcLength(contour, true);

    //convex hull
    vector<Point> convex_hull;
    convexHull(contour, convex_hull);
    double hull_perimeter = arcLength(convex_hull, true);

    //other features
    if(perimeter == 0.0)
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
