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

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, double time, Point Offset)
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

D_Bio_NucleusBlob::D_Bio_NucleusBlob(vector<Point> contour_points, vector<vector<double> > SignalStats_StatChannel, double time, Point Offset)
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

bool D_Bio_NucleusBlob::load_simple(QString nucleus_file, bool load_foci)
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
    if (!F_Nucleus.open(QIODevice::ReadOnly))
        return false;

    //text stream
    QTextStream TS_Nucleus(&F_Nucleus);

    //clear old
    vvSignalStats_StatChannel.clear();
    vvSignalStats_StatChannel.resize(VAL_STAT_NUMBER_OF);
    m_contour.clear();
    if(load_foci)
        vvFoci.clear();

    //info needed for interpretation
    size_t section = FILE_SECTION_BEGIN;
    int foci_channel_current = -1;

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
            case FILE_SECTION_END:      end_loop = true;        break;
            case FILE_SECTION_FOCI:     end_loop = !load_foci;  break;
            default:                                            break;}
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
                if(load_foci)
                {
                  //qDebug() << "load foci";
                    switch (subsection)
                    {

                    case FILE_SUBSECTION_NEW_FOCI_CHANNEL:
                    {
                        foci_channel_current++;
                        vvFoci.push_back(vector<D_Bio_Focus>());
                    }
                        break;

                    case FILE_SUBSECTION_FOCUS_BEGIN:
                    {
                        //data of new focus
                        Point2f focus_centroid(0, 0);
                        double focus_area = 0;
                        double focus_compactness = 0;
                        double focus_convexity = 0;
                        vector<vector<double>> focus_StatsChannels;

                        bool focus_end = false;
                        while(!TS_Nucleus.atEnd() && !focus_end)
                        {
                            //line and entrys in line in focus
                            QString QS_Line_focus = TS_Nucleus.readLine();
                            QStringList QSL_LineEntrys_focus = QS_Line_focus.split(";");
                            QString QS_LineFirst_focus = QSL_LineEntrys_focus.empty() ? "" : QSL_LineEntrys_focus.first();

                            //get subsection in focus
                            bool subsection_found_focus = false;
                            size_t subsection_focus = FILE_SUBSECTION_DEFAULT;
                            for(size_t i = 0; i < FILE_SECTION_NUMBER_OF && !subsection_found_focus; i++)
                                if(QS_LineFirst_focus == QSL_FileSubsections[static_cast<int>(i)])
                                {
                                    subsection_focus = i;
                                    subsection_found_focus = true;
                                }

                            //add data to focus
                            switch (subsection_focus) {

                            case FILE_SUBSECTION_POSITION:
                            {
                                if(QSL_LineEntrys_focus.size() == 3)
                                {
                                    bool ok_x;
                                    double x = QSL_LineEntrys_focus[1].toDouble(&ok_x);
                                    bool ok_y;
                                    double y = QSL_LineEntrys_focus[2].toDouble(&ok_y);
                                    if(ok_x && ok_y)
                                        focus_centroid = Point2f(x, y);
                                }
                            }
                                break;

                            case FILE_SUBSECTION_SHAPE:
                            {
                                if(QSL_LineEntrys_focus.size() == 4)
                                {
                                    bool ok_area;
                                    focus_area = QSL_LineEntrys_focus[1].toDouble(&ok_area);

                                    bool ok_compactness;
                                    focus_compactness = QSL_LineEntrys_focus[2].toDouble(&ok_compactness);

                                    bool ok_convexity;
                                    focus_convexity = QSL_LineEntrys_focus[3].toDouble(&ok_convexity);
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
                                size_t stat_index;
                                switch (subsection_focus) {
                                case FILE_SUBSECTION_VAL_COUNT:         stat_index = VAL_STAT_COUNT;            break;
                                case FILE_SUBSECTION_MEAN:              stat_index = VAL_STAT_MEAN;             break;
                                case FILE_SUBSECTION_STD:               stat_index = VAL_STAT_STD;              break;
                                case FILE_SUBSECTION_SKEW:              stat_index = VAL_STAT_SKEW;             break;
                                case FILE_SUBSECTION_KURTOSIS:          stat_index = VAL_STAT_KURTOSIS;         break;
                                case FILE_SUBSECTION_MEDIAN:            stat_index = VAL_STAT_MEDIAN;           break;
                                case FILE_SUBSECTION_MEDIAN_DEVIATION:  stat_index = VAL_STAT_MEDIAN_DEVIATION; break;
                                default:                                stat_index = VAL_STAT_NUMBER_OF;        break;}

                                for(int ch = 1; ch < QSL_LineEntrys_focus.size(); ch++)
                                {
                                    bool ok;
                                    double value = QSL_LineEntrys_focus[ch].toDouble(&ok);
                                    focus_StatsChannels[stat_index].push_back(ok ? value : 0);
                                }
                            }
                                break;

                            case FILE_SUBSECTION_FOCUS_END:
                            default:
                                focus_end = true;
                            }
                        }

                        //Add new focus
                        vvFoci[foci_channel_current].push_back(D_Bio_Focus(
                                                                   focus_centroid,
                                                                   focus_area,
                                                                   focus_compactness,
                                                                   focus_convexity,
                                                                   focus_StatsChannels));
                    }
                        break;

                    default:
                        //do nothing
                        break;
                    }
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

Rect D_Bio_NucleusBlob::bounding_box()
{
    return boundingRect(m_contour);
}

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



/*
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
*/

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
    vScoreWeights.resize(SCORE_NUMBER_OF, 0);
    vScoreWeights[SCORE_SPEED] = 1;

    vScoreMaxima.resize(SCORE_NUMBER_OF, 1);

    match_thresh_max_area_increase_to = 1.25;
    match_thresh_max_area_decrease_to = 0.35;
    match_thresh_max_speed = 1500;

    state_FoundParent_Accepted = false;
    state_FoundChild1_Accepted = false;
    state_FoundChild2_Accepted = false;

    state_FoundParent_Candidate = false;
    state_FoundChild1_Candidate = false;
    state_FoundChild2_Candidate = false;

    Score_Parent = -INFINITY;
    Score_Child1 = -INFINITY;
    Score_Child2 = -INFINITY;

    state_ScoreWeightsAndMaxSet = true;
}

bool D_Bio_NucleusBlob::matching_InitMatching(vector<double> score_weights, vector<double> score_maxima, double speed_limit, double max_rel_area_inc_to, double max_rel_area_dec_to)
{
    if((score_weights.size() != SCORE_NUMBER_OF) || (score_maxima.size() != SCORE_NUMBER_OF))
        return false;

    double weight_sum = 0;
    for(size_t i = 0; i < score_weights.size(); i++)
        weight_sum += score_weights[i];

    if(weight_sum <= 0.0)
        return false;

    for(size_t i = 0; i < score_maxima.size(); i++)
        if(score_maxima[i] <= 0.0)
            return false;

    matching_InitMatching();

    vScoreWeights.resize(SCORE_NUMBER_OF, 0);
    vScoreMaxima.resize(SCORE_NUMBER_OF, 1);
    for(size_t i = 0; i < score_weights.size(); i++)
    {
        vScoreWeights[i] = score_weights[i] / weight_sum;
        vScoreMaxima[i] = score_maxima[i];
    }

    match_thresh_max_area_increase_to = max_rel_area_inc_to;
    match_thresh_max_area_decrease_to = max_rel_area_dec_to;
    match_thresh_max_speed = speed_limit;

    return true;
}

double D_Bio_NucleusBlob::matching_Score(D_Bio_NucleusBlob *nuc_calc_score)
{
    double score_all = 1;

    for(size_t i = 0; i < SCORE_NUMBER_OF; i++)
    {
        double diff_part = 0;

        switch (i) {

        case SCORE_SPEED:
            diff_part = D_Math::Distance(centroid(), nuc_calc_score->centroid()) / abs(time() - nuc_calc_score->time());
            if(diff_part > match_thresh_max_speed)
            {
                //qDebug() << "no match, broken speed limit (" << diff_part << ", limit is" << match_thresh_max_speed << ")";
                return -INFINITY;
            }
            break;

        case SCORE_AREA:
        {
            double area_this = area();
            double area_other = nuc_calc_score->area();
            bool earlier_this = time() < nuc_calc_score->time();
            double area_earlier = earlier_this ? area_this : area_other;
            double area_later = earlier_this ? area_other :area_this;

            if(area_later > match_thresh_max_area_increase_to * area_earlier)
            {
                //qDebug() << "mo match, too much growth (" << area_earlier << "->" << area_later << ", factor " << match_thresh_max_area_increase_to << "allowed)";
                return -INFINITY;
            }

            if(area_later < match_thresh_max_area_decrease_to * area_earlier)
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
            switch (i) {

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
            switch (i) {

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

        diff_part = max(0.0, min(diff_part, vScoreMaxima[i]));
        diff_part /= vScoreMaxima[i];
        diff_part *= vScoreWeights[i];
        score_all -= diff_part;
    }

    return score_all;
}

void D_Bio_NucleusBlob::matching_SetAsChild_Candidate(D_Bio_NucleusBlob *nuc_set_child, double score)
{
    if((nuc_set_child == Nuc_Child1) || (nuc_set_child == Nuc_Child2))
        return;

    if(Score_Child1 < Score_Child2)
    {
        Nuc_Child1 = nuc_set_child;
        Score_Child1 = score;
        state_FoundChild1_Candidate = true;
    }
    else
    {
        Nuc_Child2 = nuc_set_child;
        Score_Child2 = score;
        state_FoundChild2_Candidate = true;
    }

    state_triedAtLeastOnceToMatch = true;
    nuc_set_child->matching_setTriedToMatchAtLeastOnce(true);
}

void D_Bio_NucleusBlob::matching_SetAsParent_Candidate(D_Bio_NucleusBlob *nuc_set_parent, double score)
{
    if(nuc_set_parent == Nuc_Parent)
    {
        //qDebug() << "matching_SetAsParent" << "did not set identical parent again";
        return;
    }

    //qDebug() << "matching_SetAsParent" << "found new best parent (score" << score << ")";
    Nuc_Parent = nuc_set_parent;
    Score_Parent = score;
    state_FoundParent_Candidate = true;

    state_triedAtLeastOnceToMatch = true;
    nuc_set_parent->matching_setTriedToMatchAtLeastOnce(true);
}

bool D_Bio_NucleusBlob::matching_TestAsChild_Candidate(D_Bio_NucleusBlob *nuc_test_child, double score_thresh)
{
    state_triedAtLeastOnceToMatch = true;
    nuc_test_child->matching_setTriedToMatchAtLeastOnce(true);
    double score = matching_Score(nuc_test_child);

    if(score < score_thresh)
        return false;

    if(score <= Score_Child1 && score <= Score_Child2)
        return false;

    matching_SetAsChild_Candidate(nuc_test_child, score);
    return true;
}

bool D_Bio_NucleusBlob::matching_TestAsParent_Candidate(D_Bio_NucleusBlob *nuc_test_parent, double score_thresh)
{
    state_triedAtLeastOnceToMatch = true;
    nuc_test_parent->matching_setTriedToMatchAtLeastOnce(true);
    double score = matching_Score(nuc_test_parent);

    if(score < score_thresh)
    {
        //qDebug() << "matching_TestAsParent no match score lower that thres (" << score << "<" << score_thresh << ")";
        return false;
    }

    if(score <= Score_Parent)
    {
        //qDebug() << "matching_TestAsParent no match score lower then current parent score (" << score << "<" << score_thresh << ")";
        return false;
    }

    //qDebug() << "matching_TestAsParent MATCHED with score" << score << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    matching_SetAsParent_Candidate(nuc_test_parent, score);
    return true;
}

bool D_Bio_NucleusBlob::matching_AcceptAndTellParent()
{
    if(matching_foundNoParent_Candidate())
        return false;

    Nuc_Parent->matching_SetAsChild_Candidate(this, Score_Parent);
    Nuc_Parent->matching_AcceptAndTellChilds();
    state_FoundParent_Accepted = true;
    return true;
}

bool D_Bio_NucleusBlob::matching_AcceptAndTellChilds()
{
    if(matching_foundNoChild_Candidate())
        return false;

    if(matching_foundChild1_Candidate())
    {
        Nuc_Child1->matching_SetAsParent_Candidate(this, Score_Child1);
        Nuc_Child1->matching_AcceptAndTellParent();
        state_FoundChild1_Accepted = true;
    }

    if(matching_foundChild2_Candidate())
    {
        Nuc_Child2->matching_SetAsParent_Candidate(this, Score_Child2);
        Nuc_Child2->matching_AcceptAndTellParent();
        state_FoundChild2_Accepted = true;
    }

    return true;
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
    double t = time();
    bool at_begin = t <= t_begin;
    bool at_end = t >= t_end;

    //calc binary attributes
    bool mitosis = matching_isMitosis_Accepted();
    bool linear = matching_isLinear_Accepted();
    bool appear = !matching_foundParent_Accepted();
    bool disappear = !matching_foundAtLeastOneChild_Accepted();
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
    case NUC_TYPE_ISOLATED_BEGIN:               return QColor(192, 0,   192);
    case NUC_TYPE_ISOLATED_END:                 return QColor(192, 0,   192);
    case NUC_TYPE_ISOLATED_BORDER:              return QColor(192, 0,   192);

    case NUC_TYPE_LINEAR:                       return QColor(0,   0,   0  );

    case NUC_TYPE_MITOSIS_REGULAR:              return QColor(0,   255, 0  );
    case NUC_TYPE_MITOSIS_APPEARED_MYSTERY:     return QColor(0,   192, 0  );
    case NUC_TYPE_MITOSIS_APPEARED_BEGIN:       return QColor(0,   192, 0  );
    case NUC_TYPE_MITOSIS_APPEARED_BORDER:      return QColor(0,   192, 0  );

    case NUC_TYPE_APPEAR_MYSTERY:               return QColor(0,   0,   255);
    case NUC_TYPE_APPEAR_BEGIN:                 return QColor(0,   0,   192);
    case NUC_TYPE_APPEAR_BORDER:                return QColor(0,   0,   192);

    case NUC_TYPE_DISAPPEAR_DYING:              return QColor(255, 0,   0  );
    case NUC_TYPE_DISAPPEAR_END:                return QColor(192, 0,   0  );
    case NUC_TYPE_DISAPPEAR_BORDER:             return QColor(192, 0,   0  );

    default:                                    return QColor(255, 192, 200);}
}

double D_Bio_NucleusBlob::matching_Age()
{
    return matching_TimeOfOldestAncestor() - time();
}

double D_Bio_NucleusBlob::matching_TimeOfOldestAncestor()
{
    if(state_FoundParent_Accepted)
        return Nuc_Parent->matching_TimeOfOldestAncestor();
    else
        return time();
}


