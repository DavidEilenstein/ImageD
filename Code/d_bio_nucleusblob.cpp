/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleusblob.h"

D_Bio_NucleusBlob::D_Bio_NucleusBlob()
{
    matching_InitMatching();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(QString QS_PathLoad)
{
    if(load_simple(QS_PathLoad, true))
        CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, Point Offset)
{
    matching_InitMatching();

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, size_t time, Point Offset)
{
    matching_InitMatching();

    //save data
    m_time = time;

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double> > SignalStats_StatChannel, Point Offset)
{
    matching_InitMatching();

    //save data
    if(SignalStats_StatChannel.size() == VAL_STAT_NUMBER_OF)
        vvSignalStats_StatChannel = SignalStats_StatChannel;
    else
        vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(1, 0));

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double> > SignalStats_StatChannel, size_t time, Point Offset)
{
    matching_InitMatching();

    //save data
    m_time = time;
    if(SignalStats_StatChannel.size() == VAL_STAT_NUMBER_OF)
        vvSignalStats_StatChannel = SignalStats_StatChannel;
    else
        vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF, vector<double>(1, 0));

    //apply offset to contour
    m_contour.resize(contour_points.size());
    for(size_t i = 0; i < m_contour.size(); i++)
        m_contour[i] = contour_points[i] + Offset;

    //calc feats
    CalcFeats();
}

void D_Bio_NucleusBlob::set_Foci(size_t channel, vector<D_Bio_Focus> v_foci)
{
    if(channel < vvFoci.size())
        vvFoci[channel] = v_foci;

    for(size_t i = 0; i < vvFoci[channel].size(); i++)
        vvFoci[channel][i].set_pNucOwner(this);
}

void D_Bio_NucleusBlob::set_Foci(vector<vector<D_Bio_Focus> > vv_foci)
{
    vvFoci = vv_foci;

    for(size_t ch = 0; ch < vvFoci.size(); ch++)
        for(size_t i = 0; i < vvFoci[ch].size(); i++)
            vvFoci[ch][i].set_pNucOwner(this);
}

void D_Bio_NucleusBlob::add_Focus(size_t channel, D_Bio_Focus focus)
{
    focus.set_detected_in_channel(channel);
    focus.set_pNucOwner(this);

    if(channel < vvFoci.size())
        vvFoci[channel].push_back(focus);}

double D_Bio_NucleusBlob::attribute(size_t i_attrib, size_t ch_val, double scale_px2um)
{
    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return 0;

    switch (i_attrib) {

    case ATTRIB_NUC_TIME_INDEX:                 return double(m_time);
    case ATTRIB_NUC_TIME_DIFF_TO_IRRADIATION:   return double(m_time) - double(m_time_irradiation);
    case ATTRIB_NUC_TIME_AGE_PAST:              return matching_Age();
    case ATTRIB_NUC_TIME_AGE_TOGO:              return matching_AgeToGo();
    case ATTRIB_NUC_TIME_AGE_FULL:              return matching_AgeFull();

    case ATTRIB_NUC_CENTER_X_PX:                return centroid().x;
    case ATTRIB_NUC_CENTER_Y_PX:                return centroid().y;
    case ATTRIB_NUC_AREA_PX:                    return area();
    case ATTRIB_NUC_CENTER_X_UM:                return centroid().x * scale_px2um;
    case ATTRIB_NUC_CENTER_Y_UM:                return centroid().y * scale_px2um;
    case ATTRIB_NUC_AREA_UM:                    return area() * scale_px2um * scale_px2um;
    case ATTRIB_NUC_CONVEXITY:                  return convexity();
    case ATTRIB_NUC_COMPACTNESS:                return compactness();

    case ATTRIB_NUC_SHIFT_PX:                   return Nuc_Parent == nullptr ? 0 : D_Math::Distance(centroid(), Nuc_Parent->centroid());
    case ATTRIB_NUC_SHIFT_UM:                   return Nuc_Parent == nullptr ? 0 : D_Math::Distance(centroid(), Nuc_Parent->centroid()) * scale_px2um;

    case ATTRIB_NUC_COUNT_CHX:                  return signal_stat(ch_val, VAL_STAT_COUNT);
    case ATTRIB_NUC_MEAN_CHX:                   return signal_stat(ch_val, VAL_STAT_MEAN);
    case ATTRIB_NUC_STD_CHX:                    return signal_stat(ch_val, VAL_STAT_STD);
    case ATTRIB_NUC_SKEWNESS_CHX:               return signal_stat(ch_val, VAL_STAT_SKEW);
    case ATTRIB_NUC_KURTOSIS_CHX:               return signal_stat(ch_val, VAL_STAT_KURTOSIS);
    case ATTRIB_NUC_MEDIAN_CHX:                 return signal_stat(ch_val, VAL_STAT_MEDIAN);
    case ATTRIB_NUC_ABSDEVMED_CHX:              return signal_stat(ch_val, VAL_STAT_MEDIAN_DEVIATION);

    case ATTRIB_NUC_FOCI_COUNT_CHX:             return get_FociCount(ch_val);
    case ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_PX: return area() != 0.0 ? get_FociCount(ch_val) / area() : 0.0;
    case ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_UM: return get_FociCount(ch_val) / (area() * scale_px2um * scale_px2um);
    case ATTRIB_NUC_FOCI_COUNT_ALL:
    {
        size_t n_ch_foc = get_FociChannels();

        double foci_sum = 0;
        for(size_t ch = 0; ch < n_ch_foc; ch++)
            foci_sum += get_FociCount(ch);

        return foci_sum;
    }
    case ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX: return area() != 0.0 ? attribute(ATTRIB_NUC_FOCI_COUNT_ALL, ch_val, scale_px2um) / area() : 0;
    case ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_UM: return (area() != 0.0 && scale_px2um > 0) ? attribute(ATTRIB_NUC_FOCI_COUNT_ALL, ch_val, scale_px2um) / (area() * scale_px2um * scale_px2um) : 0;

    case ATTRIB_NUC_FOCI_AREA_SUM_CHX_PX:
    {
        size_t n_ch_foc = get_FociChannels();
        if(ch_val >= n_ch_foc)
            return 0;

        double area_sum = 0;
        for(size_t f = 0; f < get_FociCount(ch_val); f++)
            area_sum += get_pFocus(ch_val, f)->area();

        return area_sum;
    }
    case ATTRIB_NUC_FOCI_AREA_SUM_CHX_UM:           return attribute(ATTRIB_NUC_FOCI_AREA_SUM_CHX_PX, ch_val, scale_px2um) * scale_px2um * scale_px2um;
    case ATTRIB_NUC_FOCI_AREA_SUM_CHX_REL_TO_NUC:   return area() != 0.0 ? attribute(ATTRIB_NUC_FOCI_AREA_SUM_CHX_PX, ch_val, scale_px2um) / area() : 0.0;

    case ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_PX:
    {
        const size_t ch0 = 0;
        const size_t ch1 = 1;

        if(get_FociChannels() <= ch1)
            return 0;

        double overlap_area_sum = 0;
        for(size_t f = 0; f < get_FociCount(ch0); f++)
            overlap_area_sum += get_pFocus(ch0, f)->overlap_area_any_focus(ch1);

        return overlap_area_sum;
    }
    case ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_UM:            return attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_PX, ch_val, scale_px2um) * scale_px2um * scale_px2um;
    case ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_NUC:    return area() != 0.0 ? attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_PX, ch_val, scale_px2um) / area() : 0.0;
    case ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_PROB:
    {
        const size_t ch0 = 0;
        const size_t ch1 = 1;

        double A_ch0_rel = attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_NUC, ch0, scale_px2um);
        double A_ch1_rel = attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_NUC, ch1, scale_px2um);

        return A_ch0_rel * A_ch1_rel;
    }
    case ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_RAND:
    {
        double overlap_rel  = attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_NUC, 0, scale_px2um);
        double overlap_prob = attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_PROB, 0, scale_px2um);

        return overlap_prob != 0.0 ? overlap_rel / overlap_prob : 0.0;
    }
    case ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_RAND_INV:
    {
        double att = attribute(ATTRIB_NUC_FOCI_OVERLAP_CH0_CH1_REL_TO_RAND, 0, scale_px2um);
        return att != 0.0 ? 1.0 / att : 0;
    }

    default:                                    return 0;
    }
}

bool D_Bio_NucleusBlob::attribute_is_value_channel_dependent(size_t i_attrib)
{
    switch (i_attrib) {

    //case ATTRIB_NUC_COUNT_CHX: formally, but not really dependent
    case ATTRIB_NUC_MEAN_CHX:
    case ATTRIB_NUC_STD_CHX:
    case ATTRIB_NUC_SKEWNESS_CHX:
    case ATTRIB_NUC_KURTOSIS_CHX:
    case ATTRIB_NUC_MEDIAN_CHX:
    case ATTRIB_NUC_ABSDEVMED_CHX:
        return true;

    default:
        return false;
    }
}

bool D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(size_t i_attrib)
{
    switch (i_attrib) {

    case ATTRIB_NUC_FOCI_COUNT_CHX:
    case ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_PX:
    case ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_UM:
    case ATTRIB_NUC_FOCI_AREA_SUM_CHX_PX:
    case ATTRIB_NUC_FOCI_AREA_SUM_CHX_UM:
    case ATTRIB_NUC_FOCI_AREA_SUM_CHX_REL_TO_NUC:
        return true;

    default:
        return false;
    }
}

int D_Bio_NucleusBlob::get_Contours_append(vector<vector<Point> > *pvScaledContours, double scale)
{
    vector<Point> ContourScaled(m_contour.size());
    for(size_t pt = 0; pt < m_contour.size(); pt++)
        ContourScaled[pt] = m_contour[pt] * scale;

    pvScaledContours->push_back(ContourScaled);

    return  ER_okay;
}

int D_Bio_NucleusBlob::get_Contours_append(vector<D_Contour> *pvContours)
{
    pvContours->push_back(D_Contour(m_contour));
    return ER_okay;
}

int D_Bio_NucleusBlob::get_FociCount_append(QStringList *pQSL_FociCounts)
{
    QString QS_FociCount;
    for(size_t fc = 0; fc < vvFoci.size(); fc++)
    {
        if(fc != 0)
            QS_FociCount.append("/");
        QS_FociCount.append(QString::number(vvFoci[fc].size()));
    }

    pQSL_FociCounts->push_back(QS_FociCount);

    return ER_okay;
}

int D_Bio_NucleusBlob::get_ShapeInfo_append(QStringList *pQSL_ShapeInfo)
{
    QString QS_ShapeInfo;
    QS_ShapeInfo.append(QString::number(static_cast<int>(area())));
    QS_ShapeInfo.append("/" + QString::number(convexity(), 'g', 2));
    QS_ShapeInfo.append("/" + QString::number(compactness(), 'g', 2));

    pQSL_ShapeInfo->push_back(QS_ShapeInfo);

    return ER_okay;
}

int D_Bio_NucleusBlob::get_ChannelStat_append(QStringList *pQSL_Stat, size_t stat_index_bio_enum)
{
    if(stat_index_bio_enum >= VAL_STAT_NUMBER_OF)
        return ER_index_out_of_range;

    QString QS_ChannelStats;
    for(size_t c = 0; c < channels(); c++)
    {
        if(c != 0)
            QS_ChannelStats.append("/");
        QS_ChannelStats.append(QString::number(signal_stat(c, stat_index_bio_enum), 'g', 3));
    }

    pQSL_Stat->push_back(QS_ChannelStats);

    return ER_okay;
}

/*
int D_Bio_NucleusBlob::save(QString path, bool simple)
{
    if(simple)
        return save_simple(path);
    else
        return save_detailed(path);
}
*/

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

/*
int D_Bio_NucleusBlob::save_detailed(QString path)
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
*/

int D_Bio_NucleusBlob::save_simple(QString path_of_dir_to_save_in, bool save_foci)
{
    //qDebug() << "D_Bio_NucleusBlob::save_simple" << "start";

    //only save if not part of neigbour image (stichting)
    if(block_stitching_border)
        if(leftmost() > block_stitching_border_x || topmost() > block_stitching_border_y)
            return ER_okay;

    //parent directory
    QDir DIR_Save(path_of_dir_to_save_in);
    if(!DIR_Save.exists())
    {
        QDir().mkdir(DIR_Save.path());
        if(!DIR_Save.exists())
            return ER_file_not_exist;
    }

    //TYX coordinate
    QString QS_Coordinate_TYX = "_T" + QString::number(m_time) + "_Y" + QString::number(static_cast<int>(m_centroid.y)) + "_X" + QString::number(static_cast<int>(m_centroid.x));

    //File
    QFileInfo FI_Nucleus(path_of_dir_to_save_in + "/Nucleus" + QS_Coordinate_TYX + ".txt");

    //stream to text file
    //qDebug() << "D_Bio_NucleusBlob::save_simple" << "init stream";
    ofstream OS_NucleusFile(FI_Nucleus.absoluteFilePath().toStdString());
    if(!OS_NucleusFile.is_open())
    {
        qDebug() << "D_Bio_NucleusBlob::save_simple" << "error: file can't be streamed to";
        return ER_StreamNotOpen;
    }

    //meta info
    //qDebug() << "D_Bio_NucleusBlob::save_simple" << "meta info";
    OS_NucleusFile << QSL_FileSections[FILE_SECTION_META_INFO].toStdString();
    OS_NucleusFile << "\n" << "File" << ";" << FI_Nucleus.baseName().toStdString();

    //value stats
    //qDebug() << "D_Bio_NucleusBlob::save_simple" << "value stats";
    OS_NucleusFile << "\n" << QSL_FileSections[FILE_SECTION_VALUES].toStdString();
    for(size_t stat = 0; stat < vvSignalStats_StatChannel.size(); stat++)
    {
        //qDebug() << stat;
        //qDebug() << QSL_ValueStat_Subsection[stat];
        OS_NucleusFile << "\n" << QSL_ValueStat_Subsection[static_cast<int>(stat)].toStdString();
        for(size_t ch = 0; ch < vvSignalStats_StatChannel[stat].size(); ch++)
            OS_NucleusFile << ";" << vvSignalStats_StatChannel[stat][ch];
    }

    //contour
    //qDebug() << "D_Bio_NucleusBlob::save_simple" << "contour";
    OS_NucleusFile << "\n" << QSL_FileSections[FILE_SECTION_CONTOUR_PIXELS].toStdString();
    for(size_t i = 0; i < m_contour.size(); i++)
        OS_NucleusFile << "\n" << m_contour[i].x << ";" << m_contour[i].y;

    if(save_foci)
    {
        //qDebug() << "D_Bio_NucleusBlob::save_simple" << "save_foci";

        //Foci
        OS_NucleusFile << "\n" << QSL_FileSections[FILE_SECTION_FOCI].toStdString();

        //loop foci channels
        for(size_t i_cf = 0; i_cf < vvFoci.size(); i_cf++)
        {
            OS_NucleusFile << "\n" << QSL_FileSubsections[FILE_SUBSECTION_NEW_FOCI_CHANNEL].toStdString() << ";" << i_cf;

            for(size_t i_fo = 0; i_fo < vvFoci[i_cf].size(); i_fo++)
            {
                OS_NucleusFile << "\n" << QSL_FileSubsections[FILE_SUBSECTION_FOCUS_BEGIN].toStdString();

                D_Bio_Focus focus = vvFoci[i_cf][i_fo];
                OS_NucleusFile << "\n" << QSL_FileSubsections[FILE_SUBSECTION_POSITION].toStdString() << ";" << focus.centroid().x << ";" << focus.centroid().y;
                OS_NucleusFile << "\n" << QSL_FileSubsections[FILE_SUBSECTION_SHAPE].toStdString() << ";" << focus.area() << ";" << focus.convexity() << ";" << focus.compactness();

                for(size_t stat = 0; stat < VAL_STAT_NUMBER_OF; stat++)
                {
                    OS_NucleusFile << "\n" << QSL_ValueStat_Subsection[static_cast<int>(stat)].toStdString();
                    for(size_t ch = 0; ch < focus.channels(); ch++)
                        OS_NucleusFile << ";" << focus.signal_stat(ch, stat);
                }

                OS_NucleusFile << "\n" << QSL_FileSubsections[FILE_SUBSECTION_FOCUS_END].toStdString();
            }
        }
    }

    //end
    OS_NucleusFile << "\n" << QSL_FileSections[FILE_SECTION_END].toStdString();
    OS_NucleusFile.close();

    //qDebug() << "D_Bio_NucleusBlob::save_simple" << "end";
    return ER_okay;
}

bool D_Bio_NucleusBlob::load_simple(QString nucleus_file, bool load_foci_from_file)
{
  //qDebug() << "D_Bio_NucleusBlob::load_simple - read:" << nucleus_file << "--------------------------------";

    //File
    QFileInfo FI_Nucleus(nucleus_file);
    if(!FI_Nucleus.exists())
        return false;
    if(FI_Nucleus.suffix() != "txt")
        return false;

    //file
    QFile F_Nucleus(FI_Nucleus.absoluteFilePath());
    if(!F_Nucleus.open(QIODevice::ReadOnly))
        return false;

    //save load file name
    QS_path_abs_loaded_from = FI_Nucleus.absoluteFilePath();

    //text stream
    QTextStream TS_Nucleus(&F_Nucleus);

    //clear old
    vvSignalStats_StatChannel.clear();
    vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF);
    m_contour.clear();
    if(load_foci_from_file)
        vvFoci.clear();

    //info needed for interpretation
    size_t section = FILE_SECTION_BEGIN;

    //read line by line
  //qDebug() << "start loop";
    bool end_loop = false;
    for(size_t l = 0; !TS_Nucleus.atEnd() && !end_loop; l++)
    {
        //line and entrys in line
        QString QS_Line = TS_Nucleus.readLine();
        QStringList QSL_LineEntrys = QS_Line.split(";");
        QString QS_LineFirst = QSL_LineEntrys.empty() ? "" : QSL_LineEntrys.first();
      //qDebug() << "Line:" << QSL_LineEntrys << "..........................................................................";


        //check for new section
        bool new_section = false;
        for(size_t i = 0; i < FILE_SECTION_NUMBER_OF && !new_section; i++)
            if(QS_LineFirst == QSL_FileSections[static_cast<int>(i)])
            {
                section = i;
                new_section = true;
              //qDebug() << "Section found:" << i << QSL_FileSections[i];
            }
        if(!new_section)
        {
          //qDebug() << "No new section found";
        }

        //new section
        if(new_section)
        {
            switch (section) {
            case FILE_SECTION_END:      end_loop = true;                    break;
            case FILE_SECTION_FOCI:     end_loop = !load_foci_from_file;    break;
            default:                                                        break;}
          //qDebug() << "end loop?" << end_loop;
        }
        else
        {
            //not a new section but a new line

            //get subsection in this line
            bool subsection_found = false;
            size_t subsection = FILE_SUBSECTION_DEFAULT;
            for(size_t i = 0; i < FILE_SUBSECTION_NUMBER_OF && !subsection_found; i++)
                if(QS_LineFirst == QSL_FileSubsections[static_cast<int>(i)])
                {
                    subsection = i;
                    subsection_found = true;
                  //qDebug() << "Subsection found:" << i << QSL_FileSubsections[i];
                }
            if(!subsection_found)
            {
              //qDebug() << "No new subsection found";
            }



            //check section to select action
            switch (section)
            {

            case FILE_SECTION_END:                  //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            {
                end_loop = true;
              //qDebug() << "2nd section switch:" << "end loop";
            }
                break;

            case FILE_SECTION_VALUES:               //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            {
                bool stat_found = true;
                size_t stat_index = VAL_STAT_NUMBER_OF;
                switch (subsection) {
                case FILE_SUBSECTION_VAL_COUNT:         stat_index = VAL_STAT_COUNT;            break;
                case FILE_SUBSECTION_MEAN:              stat_index = VAL_STAT_MEAN;             break;
                case FILE_SUBSECTION_STD:               stat_index = VAL_STAT_STD;              break;
                case FILE_SUBSECTION_SKEW:              stat_index = VAL_STAT_SKEW;             break;
                case FILE_SUBSECTION_KURTOSIS:          stat_index = VAL_STAT_KURTOSIS;         break;
                case FILE_SUBSECTION_MEDIAN:            stat_index = VAL_STAT_MEDIAN;           break;
                case FILE_SUBSECTION_MEDIAN_DEVIATION:  stat_index = VAL_STAT_MEDIAN_DEVIATION; break;
                default:                                stat_found = false;                     break;}

                if(stat_found)
                {
                  //qDebug() << "2nd section switch: section " << QSL_FileSections[FILE_SECTION_VALUES] << "stat" << QSL_ValueStat_Subsection[stat_index];

                    for(int ch = 1; ch < QSL_LineEntrys.size(); ch++)
                    {
                        bool ok;
                        double value = QSL_LineEntrys[ch].toDouble(&ok);
                        vvSignalStats_StatChannel[stat_index].push_back(ok ? value : 0);
                    }
                  //qDebug() << QSL_ValueStat_Subsection[stat_index] << "loaded:" << vvSignalStats_StatChannel[stat_index];
                }
                else
                {
                    qDebug() << "subsection index" << subsection << "does not match any stat index!";
                }
            }
                break;

            case FILE_SECTION_CONTOUR_PIXELS:       //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                if(QSL_LineEntrys.size() == 2)
                {
                  //qDebug() << "contour";
                    bool ok_x;
                    double x = QSL_LineEntrys[0].toDouble(&ok_x);
                    bool ok_y;
                    double y = QSL_LineEntrys[1].toDouble(&ok_y);
                    if(ok_x && ok_y)
                    {
                        m_contour.push_back(Point2f(x, y));
                      //qDebug() << "Add contour pixel" << x << y;
                    }
                }
                break;

            case FILE_SECTION_FOCI:                 //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
                if(load_foci_from_file)
                {
                    load_foci(&TS_Nucleus);
                }
                else
                {
                    end_loop = true;
                }
                break;

            case FILE_SECTION_BEGIN:                //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            case FILE_SECTION_META_INFO:
            default:
            {
                //do nothing
            }
                break;
            }
        }
    }

    //--------------------------------------------------- end
    F_Nucleus.close();

    //calc features based on loaded data
    CalcFeats();

    return true;
}

bool D_Bio_NucleusBlob::load_foci(QTextStream* pTS_NucTxtContent)
{
    //foci channel current
    int foci_channel_current = 0;

    //loop lines
    while(!pTS_NucTxtContent->atEnd())
    {
        //line and entrys in line in focus
        QString QS_Line = pTS_NucTxtContent->readLine();
        //qDebug() << "Line in focus:" << QS_Line;
        QStringList QSL_LineEntrys = QS_Line.split(";");
        QString QS_LineFirst = QSL_LineEntrys.empty() ? "" : QSL_LineEntrys.first();

        //get subsection in focus
        bool subsection_found = false;
        size_t subsection = FILE_SUBSECTION_DEFAULT;
        for(size_t i = 0; i < FILE_SUBSECTION_NUMBER_OF && !subsection_found; i++)
        {
            if(QS_LineFirst == QSL_FileSubsections[int(i)])
            {
                subsection = i;
                subsection_found = true;
            }
        }

        //end?
        if(QS_LineFirst == QSL_FileSections[FILE_SECTION_END])
            return true;

        if(subsection_found)
        {
            switch (subsection)
            {

            case FILE_SUBSECTION_NEW_FOCI_CHANNEL:
            {
                if(QSL_LineEntrys.size() == 2)
                {
                    bool ok;
                    int ch = QSL_LineEntrys[1].toInt(&ok);
                    if(ok)
                        foci_channel_current = ch;

                    //qDebug() << "D_Bio_NucleusBlob::load_simple" << "FILE_SUBSECTION_NEW_FOCI_CHANNEL increased foci channel index to:" << foci_channel_current << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
                }
            }
                break;

            case FILE_SUBSECTION_FOCUS_BEGIN:
            {                
                //dirty fix: FILE_SUBSECTION_NEW_FOCI_CHANNEL is not executed for ch=0. This way it is made sure that every loaded focus is stored in correct channel (as long as file starts with ch=0).
                while(size_t(foci_channel_current) >= vvFoci.size())
                    vvFoci.push_back(vector<D_Bio_Focus>());

                //load focus
                D_Bio_Focus FocRead;
                if(load_focus(pTS_NucTxtContent, &FocRead, foci_channel_current))
                    vvFoci[size_t(foci_channel_current)].push_back(FocRead);
            }
                break;

            case FILE_SUBSECTION_FOCUS_END:
            {
                //should not be reached in this loop
            }
                break;

            default:
            {
                //do nothing
            }
                break;

            }
        }

    }




    return true;
}

bool D_Bio_NucleusBlob::load_focus(QTextStream *pTS_NucTxtContent, D_Bio_Focus *pFoc, size_t ch)
{
    //qDebug() << "D_Bio_NucleusBlob::load_focus" << "--------------------------------- new focus";

    //data of new focus
    Point2f focus_centroid(0, 0);
    double focus_area = 0;
    double focus_compactness = 0;
    double focus_convexity = 0;
    vector<vector<double>> focus_StatsChannels(VAL_STAT_NUMBER_OF);

    //focus end
    bool focus_end = false;

    //loop lines
    while(!pTS_NucTxtContent->atEnd() && !focus_end)
    {
        //line and entrys in line in focus
        QString QS_Line = pTS_NucTxtContent->readLine();
        //qDebug() << "Line in focus:" << QS_Line << ".........................";
        QStringList QSL_LineEntrys = QS_Line.split(";");
        QString QS_LineFirst = QSL_LineEntrys.empty() ? "" : QSL_LineEntrys.first();

        //get subsection in focus
        bool subsection_found = false;
        size_t subsection = FILE_SUBSECTION_DEFAULT;
        for(size_t i = 0; i < FILE_SUBSECTION_NUMBER_OF && !subsection_found; i++)
            if(QS_LineFirst == QSL_FileSubsections[static_cast<int>(i)])
            {
                subsection = i;
                subsection_found = true;
                //qDebug() << QS_LineFirst << "matches subsection index" << subsection;
            }

        if(subsection_found)
        {
            switch (subsection)
            {

            case FILE_SUBSECTION_POSITION:
            {
                //qDebug() << "FILE_SUBSECTION_POSITION";
                //example:
                //Position;2582;328
                //0        1    2       n=3

                if(QSL_LineEntrys.size() == 3)
                {
                    bool ok_x;
                    double x = QSL_LineEntrys[1].toDouble(&ok_x);
                    bool ok_y;
                    double y = QSL_LineEntrys[2].toDouble(&ok_y);
                    if(ok_x && ok_y)
                        focus_centroid = Point2f(x, y);
                }
            }
                break;

            case FILE_SUBSECTION_SHAPE:
            {
                //qDebug() << "FILE_SUBSECTION_SHAPE";
                //example:
                //ShapeAreaConvexCompact;66;0.93887;0.762959
                //0                      1  2       3          n=4

                if(QSL_LineEntrys.size() == 4)
                {
                    bool ok;
                    double val;

                    val = QSL_LineEntrys[1].toDouble(&ok);
                    if(ok)
                        focus_area = val;

                    val = QSL_LineEntrys[2].toDouble(&ok);
                    if(ok)
                        focus_compactness = val;

                    val = QSL_LineEntrys[3].toDouble(&ok);
                    if(ok)
                        focus_convexity = val;
                }
            }
                break;

            case FILE_SUBSECTION_VAL_COUNT:
            case FILE_SUBSECTION_MEAN:
            case FILE_SUBSECTION_STD:
            case FILE_SUBSECTION_SKEW:
            case FILE_SUBSECTION_KURTOSIS:
            case FILE_SUBSECTION_MEDIAN:
            case FILE_SUBSECTION_MEDIAN_DEVIATION:
            {
                //qDebug() << "FILE_SUBSECTION_<VALUE_STAT>" << subsection;
                //example:
                //Skewness;-0.0206295;0.762137;-0.0610303
                //0        1          2        3          n=channel_count+1 (3 channels + 1 section = 4 entrys in this case)

                size_t stat_index;
                switch (subsection) {//found at index 0 ("Skewness"->FILE_SUBSECTION_SKEW->VAL_STAT_SKEW in example above)
                case FILE_SUBSECTION_VAL_COUNT:         stat_index = VAL_STAT_COUNT;            break;
                case FILE_SUBSECTION_MEAN:              stat_index = VAL_STAT_MEAN;             break;
                case FILE_SUBSECTION_STD:               stat_index = VAL_STAT_STD;              break;
                case FILE_SUBSECTION_SKEW:              stat_index = VAL_STAT_SKEW;             break;
                case FILE_SUBSECTION_KURTOSIS:          stat_index = VAL_STAT_KURTOSIS;         break;
                case FILE_SUBSECTION_MEDIAN:            stat_index = VAL_STAT_MEDIAN;           break;
                case FILE_SUBSECTION_MEDIAN_DEVIATION:  stat_index = VAL_STAT_MEDIAN_DEVIATION; break;
                default:                                stat_index = VAL_STAT_NUMBER_OF;        break;}

                for(int i = 1; i < QSL_LineEntrys.size(); i++)//index 1 is 1st number, index 0 is subsection keyword -> start at 1
                {
                    bool ok;
                    double val = QSL_LineEntrys[i].toDouble(&ok);
                    focus_StatsChannels[stat_index].push_back(ok ? val : 0);
                }
            }
                break;

            case FILE_SUBSECTION_FOCUS_END:
            {
                focus_end = true;
            }
                break;

            default:
            {
                //do nothing
            }
                break;

            }
        }
    }

    //create new focus
    *pFoc = D_Bio_Focus(
                focus_centroid,
                focus_area,
                focus_compactness,
                focus_convexity,
                focus_StatsChannels,
                ch);

    //finish
    //qDebug() << "D_Bio_NucleusBlob::load_focus" << "--------------------------------- end focus";
    return true;
}

bool D_Bio_NucleusBlob::set_path_relative(QString path_rel)
{
    if(path_rel.isEmpty())
        return false;

    if(path_rel[0] != "/")
        return false;

    QS_path_relative = path_rel;
    return true;
}

bool D_Bio_NucleusBlob::set_path_absolute(QString path_abs, QDir master_dir)
{
    if(!path_abs.contains(master_dir.path()))
        return false;

    int n_rel = path_abs.length() - master_dir.path().length();
    return set_path_relative(path_abs.right(n_rel));
}

Rect D_Bio_NucleusBlob::bounding_box()
{
    return boundingRect(m_contour);
}

vector<Point2f> D_Bio_NucleusBlob::contour_f(double scale, Point P_offset_scaled)
{
    size_t n = m_contour.size();

    vector<Point2f> vContourOut(n);

    for(size_t i = 0; i < n; i++)
        vContourOut[i] = (m_contour[i] * scale) + P_offset_scaled;

    return vContourOut;
}

vector<Point> D_Bio_NucleusBlob::contour(double scale, Point P_offset_scaled)
{
    size_t n = m_contour.size();

    vector<Point> vContourOut(n);

    for(size_t i = 0; i < n; i++)
        vContourOut[i] = (m_contour[i] * scale) + P_offset_scaled;

    return vContourOut;
}

Point2f D_Bio_NucleusBlob::centroid(double scale, Point P_offset_scaled)
{
    if(!state_feats_calced) CalcFeats();

    return Point2f(
                (scale * m_centroid.x) + P_offset_scaled.x,
                (scale * m_centroid.y) + P_offset_scaled.y);
}

/*
vector<vector<Point> > D_Bio_NucleusBlob::merge_contours_with_other_nucleus(D_Bio_NucleusBlob nuc_merge, int merging_distance)
{
    ///calc merged bounding box
    Rect R0 = bounding_box();
    Rect R1 = nuc_merge.bounding_box();
    int x_min = min(R0.tl().x, R1.tl().x);
    int y_min = min(R0.tl().y, R1.tl().y);
    int x_max = max(R0.br().x, R1.br().x);
    int y_max = max(R0.br().y, R1.br().y);
    int dx = x_max - x_min;
    int dy = y_max - y_min;

    ///generate tmp img
    int offset = merging_distance;
    int w_img = dx + 2 * offset;
    int h_img = dy + 2 * offset;
    Mat MA_tmp_contours = Mat::zeros(h_img, w_img, CV_8UC1);

    ///get and scale contours
    vector<vector<Point>> vContours = {m_contour, nuc_merge.contour()};
    Point P_Offset(x_min - offset, y_min - offset);
    vector<vector<Point>> vContoursShifted(vContours.size());
    for(size_t c = 0; c < vContours.size(); c++)
    {
        vContoursShifted[c].reserve(vContours[c].size());
        for(size_t p = 0; p < vContours[c].size(); p++)
            vContoursShifted[c][p] = vContours[c][p] - P_Offset;
    }

    ///draw contours
    drawContours(MA_tmp_contours, vContours, -1, 255, -1);

    ///closing blobs
    int diameter = 2 * offset + 1;
    Mat MA_Kernel = getStructuringElement(
                MORPH_ELLIPSE,
                Size(diameter, diameter),
                Point(offset, offset));

    Mat MA_tmp_closed;
    morphologyEx(
                MA_tmp_contours,
                MA_tmp_closed,
                MORPH_CLOSE,
                MA_Kernel,
                Point(-1, -1),
                1,
                BORDER_DEFAULT);

    vector<vector<Point>> vContoursNew;

    MA_Kernel.release();
}
*/

bool D_Bio_NucleusBlob::is_duplicate(vector<D_Bio_NucleusBlob> v_other_nucs, double rel_overlap_for_duplicate)
{
    D_Contour C1(m_contour);
    for(size_t i = 0; i < v_other_nucs.size(); i++)
    {
        D_Contour C2(v_other_nucs[i].contour());
        if(C1.intersection_area_relative(C2) >= rel_overlap_for_duplicate)
            return false;
    }

    return true;
}

QString D_Bio_NucleusBlob::info()
{
    return "D_Bio_NucleusBlob::info - " + QString::number(area()) + "px area - " + QString::number(get_FociChannels()) + " foci channels";
}

void D_Bio_NucleusBlob::CalcFeats()
{
    //empty?
    if(m_contour.empty())
    {
        qDebug() << "D_Bio_NucleusBlob::CalcFeats()" << "WARNING Contour empty";
        m_centroid      = Point2f(0, 0);
        m_area          = 0;
        m_compactness   = 0;
        m_convexity     = 0;
        return;
    }

    //calc moments
    Moments moments_tmp = moments(m_contour);

    //calc centroids
    if(moments_tmp.m00 == 0.0)
    {
        double center_x = m_contour[0].x;
        double center_y = m_contour[0].y;
        //qDebug() << "D_Bio_NucleusBlob::CalcFeats() centroid x/y" << center_x << center_y << "WARNING No mass!";
        m_centroid = Point2f(float(center_x), float(center_y));
    }
    else
    {
        double center_x = moments_tmp.m10 / moments_tmp.m00;
        double center_y = moments_tmp.m01 / moments_tmp.m00;
        //qDebug() << "D_Bio_NucleusBlob::CalcFeats() centroid x/y" << center_x << center_y;
        m_centroid = Point2f(float(center_x), float(center_y));
    }

    //Area
    if(moments_tmp.m00 == 0.0)
        m_area = 0;
    else
        m_area = contourArea(m_contour);

    //Perimeter
    double perimeter = arcLength(m_contour, true);

    //convex hull
    convexHull(m_contour, m_convex_hull);
    double hull_perimeter = arcLength(m_convex_hull, true);

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

void D_Bio_NucleusBlob::matching_InitMatching()
{
    state_FoundParent = false;
    state_FoundChild1 = false;
    state_FoundChild2 = false;

    Score_Parent = -INFINITY;
    Score_Child1 = -INFINITY;
    Score_Child2 = -INFINITY;

    Nuc_Parent = nullptr;
    Nuc_Child1 = nullptr;
    Nuc_Child2 = nullptr;
}

double D_Bio_NucleusBlob::matching_Score(D_Bio_NucleusBlob *nuc_calc_score, vector<size_t> *pvScoreRelevantCriteria, vector<double> *pvScoreWeights, vector<double> *pvScoreMax, double max_area_increase_to_rel, double max_area_decrease_to_rel, double max_shift)
{
    size_t n = pvScoreRelevantCriteria->size();

    if(pvScoreWeights->size() != n)
        return -INFINITY;

    if(pvScoreMax->size() != n)
        return -INFINITY;

    //best score is 1 (calculation decreses this value step by step)
    double score_all = 1;

    //loop score criteria
    for(size_t c = 0; c < n; c++)
    {
        //get criterium
        size_t criterium = (*pvScoreRelevantCriteria)[c];

        //criterium valid?
        if(criterium < SCORE_NUMBER_OF)
        {
            //difference for this criterium
            double diff_part = 0;

            switch (criterium) {

            case SCORE_SHIFT:
            {
                double dist = D_Math::Distance(centroid(), nuc_calc_score->centroid());
                diff_part = dist;
                if(dist > max_shift)
                {
                    //qDebug() << "no match, broken shift limit (" << diff_part << ", limit is" << match_thresh_max_shift << ")";
                    return -INFINITY;
                }
            }
                break;

            case SCORE_AREA:
            {
                double area_this = area();
                double area_other = nuc_calc_score->area();
                bool earlier_this = time_index() < nuc_calc_score->time_index();
                double area_earlier = earlier_this ? area_this : area_other;
                double area_later = earlier_this ? area_other : area_this;

                if(area_later > max_area_increase_to_rel * area_earlier)
                {
                    //qDebug() << "mo match, too much growth (" << area_earlier << "->" << area_later << ", factor " << match_thresh_max_area_increase_to << "allowed)";
                    return -INFINITY;
                }

                if(area_later < max_area_decrease_to_rel * area_earlier)
                {
                    //qDebug() << "mo match, too much shrink (" << area_earlier << "->" << area_later << ", factor " << match_thresh_max_area_decrease_to << "allowed)";
                    return -INFINITY;
                }

                diff_part = abs(area_this - area_other);
            }
                break;

            case SCORE_CONVEXITY:
                diff_part = abs(convexity() - nuc_calc_score->convexity());
                break;

            case SCORE_COMPACTNESS:
                diff_part = abs(compactness() - nuc_calc_score->compactness());
                break;

            default:
            {
                //channel index
                size_t channel = size_t(INFINITY);
                switch (criterium) {

                case SCORE_MEAN_CH0:
                case SCORE_STD_CH0:
                    channel = 0;
                    break;

                case SCORE_MEAN_CH1:
                case SCORE_STD_CH1:
                    channel = 1;
                    break;

                case SCORE_MEAN_CH2:
                case SCORE_STD_CH2:
                    channel = 2;
                    break;

                default:
                    channel = size_t(INFINITY);
                    break;
                }


                //stat index
                size_t stat = size_t(INFINITY);
                switch (criterium) {

                case SCORE_MEAN_CH0:
                case SCORE_MEAN_CH1:
                case SCORE_MEAN_CH2:
                    stat = VAL_STAT_MEAN;
                    break;

                case SCORE_STD_CH0:
                case SCORE_STD_CH1:
                case SCORE_STD_CH2:
                    stat = VAL_STAT_STD;
                    break;

                default:
                    channel = size_t(INFINITY);
                    break;
                }

                //calc stat difference, if indices are valid
                if(stat < vvSignalStats_StatChannel.size())
                    if(channel < vvSignalStats_StatChannel[stat].size())
                        diff_part = abs(vvSignalStats_StatChannel[stat][channel] - nuc_calc_score->signal_stat(channel, stat));
            }
                break;
            }

            double diff_part_inRange = max(0.0, min(diff_part, (*pvScoreMax)[criterium]));
            double diff_part_0to1 = (*pvScoreMax)[criterium] > 0 ? diff_part_inRange / (*pvScoreMax)[criterium] : 1;
            double diff_part_0to1_weighted = diff_part_0to1 * (*pvScoreWeights)[criterium];
            score_all -= diff_part_0to1_weighted;
        }
    }

    return score_all;
}

void D_Bio_NucleusBlob::matching_SetAsChild(D_Bio_NucleusBlob *nuc_set_child, double score)
{
    if((nuc_set_child == Nuc_Child1) || (nuc_set_child == Nuc_Child2))
        return;

    if(Score_Child1 < Score_Child2)
    {
        Nuc_Child1 = nuc_set_child;
        Score_Child1 = score;
        state_FoundChild1 = true;
        nuc_set_child->matching_SetAsParent(this, score);
    }
    else
    {
        Nuc_Child2 = nuc_set_child;
        Score_Child2 = score;
        state_FoundChild2 = true;
        nuc_set_child->matching_SetAsParent(this, score);
    }

    state_triedAtLeastOnceToMatch = true;
}

void D_Bio_NucleusBlob::matching_SetAsParent(D_Bio_NucleusBlob *nuc_set_parent, double score)
{
    if(nuc_set_parent == Nuc_Parent)
    {
        //qDebug() << "matching_SetAsParent" << "did not set identical parent again";
        return;
    }

    //qDebug() << "matching_SetAsParent" << "found new best parent (score" << score << ")";
    Nuc_Parent = nuc_set_parent;
    Score_Parent = score;
    state_FoundParent = true;

    state_triedAtLeastOnceToMatch = true;
    nuc_set_parent->matching_SetAsChild(this, Score_Parent);
}

bool D_Bio_NucleusBlob::matching_RemoveChild(D_Bio_NucleusBlob *nuc_remove_child)
{
    if(nuc_remove_child == Nuc_Child1)
    {
        Nuc_Child1 = nullptr;
        Score_Child1 = -INFINITY;
        state_FoundChild1 = false;
        return true;
    }

    if(nuc_remove_child == Nuc_Child2)
    {
        Nuc_Child2 = nullptr;
        Score_Child2 = -INFINITY;
        state_FoundChild2 = false;
        return true;
    }

    return false;
}

bool D_Bio_NucleusBlob::matching_RemoveParent(D_Bio_NucleusBlob *nuc_remove_parent)
{
    if(nuc_remove_parent == Nuc_Parent)
    {
        Nuc_Parent = nullptr;
        Score_Parent = -INFINITY;
        state_FoundParent = false;
        return true;
    }

    return false;
}

bool D_Bio_NucleusBlob::matching_excluded_check_forward()
{
    if(matching_excluded_this())
        return true;

    if(matching_foundNoChild())
        return false;

    if(matching_isMitosis())
        return false;

    return matching_ChildFavorite()->matching_excluded_check_forward();
}

bool D_Bio_NucleusBlob::matching_excluded_check_backward()
{
    if(matching_excluded_this())
        return true;

    if(matching_foundNoParent())
        return false;

    if(matching_parent_isMitosis())
        return false;

    return matching_Parent()->matching_excluded_check_backward();
}

D_Bio_NucleusBlob *D_Bio_NucleusBlob::matching_excluded_seek_pNucMarked_forward()
{
    if(matching_excluded_this())
        return this;

    if(matching_foundNoChild())
        return nullptr;

    if(matching_isMitosis())
        return nullptr;

    return matching_ChildFavorite()->matching_excluded_seek_pNucMarked_forward();
}

D_Bio_NucleusBlob *D_Bio_NucleusBlob::matching_excluded_seek_pNucMarked_backward()
{
    if(matching_excluded_this())
        return this;

    if(matching_foundNoParent())
        return nullptr;

    if(matching_parent_isMitosis())
        return nullptr;

    return matching_Parent()->matching_excluded_seek_pNucMarked_backward();
}

int D_Bio_NucleusBlob::matching_Type(Rect FrameNotNearBorder, double t_begin, double t_end)
{
    //check, if at border
    Point center = centroid();
    int x = center.x;
    int y = center.y;
    Point tl = FrameNotNearBorder.tl();
    Point br = FrameNotNearBorder.br();
    bool at_border = (x < tl.x) || (x > br.x) || (y < tl.y) || (y > br.y);

    //check if in time interval
    size_t t = time_index();
    bool at_begin = t <= t_begin;
    bool at_end = t >= t_end;

    //calc binary attributes
    bool mitosis = matching_isMitosis();
    bool linear = matching_isLinear();
    bool appear = !matching_foundParent();
    bool disappear = !matching_foundAtLeastOneChild();
    bool isolated = appear && disappear;

    //return nucleus type
    if(!state_triedAtLeastOnceToMatch)      return NUC_TYPE_UNKNOWN;
    else if(isolated && at_end)             return NUC_TYPE_ISOLATED_END;
    else if(isolated && at_begin)           return NUC_TYPE_ISOLATED_BEGIN;
    else if(isolated && at_border)          return NUC_TYPE_ISOLATED_BORDER;
    else if(isolated)                       return NUC_TYPE_ISOLATED_MYSTERY;
    else if(linear)                         return NUC_TYPE_LINEAR;
    else if(mitosis && !appear)             return NUC_TYPE_MITOSIS_REGULAR;
    else if(mitosis && appear && at_begin)  return NUC_TYPE_MITOSIS_APPEARED_BEGIN;
    else if(mitosis && appear && at_border) return NUC_TYPE_MITOSIS_APPEARED_BORDER;
    else if(mitosis && appear)              return NUC_TYPE_MITOSIS_APPEARED_MYSTERY;
    else if(appear && at_begin)             return NUC_TYPE_APPEAR_BEGIN;
    else if(appear && at_border)            return NUC_TYPE_APPEAR_BORDER;
    else if(appear)                         return NUC_TYPE_APPEAR_MYSTERY;
    else if(disappear && at_end)            return NUC_TYPE_DISAPPEAR_END;
    else if(disappear && at_border)         return NUC_TYPE_DISAPPEAR_BORDER;
    else if(disappear)                      return NUC_TYPE_DISAPPEAR_DYING;
    else                                    return NUC_TYPE_UNDEFINED;
}

QColor D_Bio_NucleusBlob::matching_TypeColor(Rect FrameNotNearBorder, double t_begin, double t_end)
{
    switch (matching_Type(FrameNotNearBorder, t_begin, t_end)) {
    case NUC_TYPE_UNKNOWN:                      return QColor(192, 192, 192);

    case NUC_TYPE_ISOLATED_MYSTERY:             return QColor(255, 0,   255);
    case NUC_TYPE_ISOLATED_BEGIN:               return QColor(128, 0,   128);
    case NUC_TYPE_ISOLATED_END:                 return QColor(128, 0,   128);
    case NUC_TYPE_ISOLATED_BORDER:              return QColor(128, 0,   128);

    case NUC_TYPE_LINEAR:                       return QColor(0,   0,   0  );

    case NUC_TYPE_MITOSIS_REGULAR:              return QColor(0,   255, 0  );
    case NUC_TYPE_MITOSIS_APPEARED_MYSTERY:     return QColor(0,   128, 0  );
    case NUC_TYPE_MITOSIS_APPEARED_BEGIN:       return QColor(0,   128, 0  );
    case NUC_TYPE_MITOSIS_APPEARED_BORDER:      return QColor(0,   128, 0  );

    case NUC_TYPE_APPEAR_MYSTERY:               return QColor(0,   0,   255);
    case NUC_TYPE_APPEAR_BEGIN:                 return QColor(0,   0,   128);
    case NUC_TYPE_APPEAR_BORDER:                return QColor(0,   0,   128);

    case NUC_TYPE_DISAPPEAR_DYING:              return QColor(255, 0,   0  );
    case NUC_TYPE_DISAPPEAR_END:                return QColor(128, 0,   0  );
    case NUC_TYPE_DISAPPEAR_BORDER:             return QColor(128, 0,   0  );

    default:                                    return QColor(255, 192, 200);}
}

size_t D_Bio_NucleusBlob::matching_TimeIndexOfOldestAncestor()
{
    if(!state_FoundParent)
        return time_index();

    if(Nuc_Parent->matching_isMitosis())
        return time_index();

    return Nuc_Parent->matching_TimeIndexOfOldestAncestor();
}

bool D_Bio_NucleusBlob::matching_HasAncestorInRange(size_t t_oldest, double y_min_px, double y_max_px, double x_min_px, double x_max_px)
{
    if(time_index() <= t_oldest)
    {
        return ((y_min_px <= m_centroid.y && y_max_px >= m_centroid.y) && (x_min_px <= m_centroid.x && x_max_px >= m_centroid.x));
    }
    else
    {
        if(state_FoundParent)
            return Nuc_Parent->matching_HasAncestorInRange(t_oldest, y_min_px, y_max_px, x_min_px, x_max_px);
        else
            return ((y_min_px <= m_centroid.y && y_max_px >= m_centroid.y) && (x_min_px <= m_centroid.x && x_max_px >= m_centroid.x));
    }
}


