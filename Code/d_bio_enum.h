/************************************
 *   added:     01.06.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_ENUM_H
#define D_BIO_ENUM_H

#include <QStringList>


const QStringList QSL_FileSections = {
     ":::: Begin",
     ":::: MetaInfo",
     ":::: Values",
     ":::: CountourPixels",
     ":::: Foci",
     ":::: End"
 };
 enum FILE_SECTIONS {
     FILE_SECTION_BEGIN,
     FILE_SECTION_META_INFO,
     FILE_SECTION_VALUES,
     FILE_SECTION_CONTOUR_PIXELS,
     FILE_SECTION_FOCI,
     FILE_SECTION_END,
     FILE_SECTION_NUMBER_OF
 };


 const QStringList QSL_FileSubsections = {
     "Default",
     ".... Channel",
     "---- Focus Begin",
     "---- Focus End",
     "Count",
     "Mean",
     "STD",
     "Skewness",
     "Kurtosis",
     "Median",
     "AvAbsDevMed",
     "Position",
     "ShapeAreaConvexCompact"
 };
 enum FILE_SUBSECTIONS {
     FILE_SUBSECTION_DEFAULT,
     FILE_SUBSECTION_NEW_FOCI_CHANNEL,
     FILE_SUBSECTION_FOCUS_BEGIN,
     FILE_SUBSECTION_FOCUS_END,
     FILE_SUBSECTION_VAL_COUNT,
     FILE_SUBSECTION_MEAN,
     FILE_SUBSECTION_STD,
     FILE_SUBSECTION_SKEW,
     FILE_SUBSECTION_KURTOSIS,
     FILE_SUBSECTION_MEDIAN,
     FILE_SUBSECTION_MEDIAN_DEVIATION,
     FILE_SUBSECTION_POSITION,
     FILE_SUBSECTION_SHAPE,
     FILE_SUBSECTION_NUMBER_OF
 };


 const QStringList QSL_ValueStat_Subsection = {
     "Count",
     "Mean",
     "STD",
     "Skewness",
     "Kurtosis",
     "Median",
     "AvAbsDevMed"
 };
 enum VALUE_STAT {
     VAL_STAT_COUNT,
     VAL_STAT_MEAN,
     VAL_STAT_STD,
     VAL_STAT_SKEW,
     VAL_STAT_KURTOSIS,
     VAL_STAT_MEDIAN,
     VAL_STAT_MEDIAN_DEVIATION,
     VAL_STAT_NUMBER_OF
 };

const QStringList QSL_NucLifeFileSections = {
    ":::: PathInfo",
    ":::: Parent",
    ":::: Members",
    ":::: Childs",
    ":::: End"
};
enum NUC_LIFE_FILE_SECTIONS {
    NUC_LIFE_FILE_SECTION_PATH_INFO,
    NUC_LIFE_FILE_SECTION_PARENT,
    NUC_LIFE_FILE_SECTION_MEMBERS,
    NUC_LIFE_FILE_SECTION_CHILDS,
    NUC_LIFE_FILE_SECTION_END,
    NUC_LIFE_FILE_SECTION_NUMBER_OF
};

 enum SCORES {
     SCORE_SHIFT,
     SCORE_AREA,
     SCORE_CONVEXITY,
     SCORE_COMPACTNESS,
     SCORE_MEAN_CH0,
     SCORE_MEAN_CH1,
     SCORE_MEAN_CH2,
     SCORE_STD_CH0,
     SCORE_STD_CH1,
     SCORE_STD_CH2,
     SCORE_NUMBER_OF
 };

 enum NUC_TYPE {
     NUC_TYPE_UNKNOWN,                  //gray
     NUC_TYPE_ISOLATED_BEGIN,           //dark magenta
     NUC_TYPE_ISOLATED_END,             //dark magenta
     NUC_TYPE_ISOLATED_BORDER,          //dark magenta
     NUC_TYPE_ISOLATED_MYSTERY,         //intense magenta
     NUC_TYPE_LINEAR,                   //black
     NUC_TYPE_MITOSIS_REGULAR,          //intense green
     NUC_TYPE_MITOSIS_APPEARED_MYSTERY, //intense cyan
     NUC_TYPE_MITOSIS_APPEARED_BEGIN,   //dark cyan
     NUC_TYPE_MITOSIS_APPEARED_BORDER,  //dark cyan
     NUC_TYPE_APPEAR_BEGIN,             //dark blue
     NUC_TYPE_APPEAR_BORDER,            //dark blue
     NUC_TYPE_APPEAR_MYSTERY,           //intense blue
     NUC_TYPE_DISAPPEAR_END,            //dark red
     NUC_TYPE_DISAPPEAR_BORDER,         //dark red
     NUC_TYPE_DISAPPEAR_DYING,          //intense red
     NUC_TYPE_UNDEFINED,                //intense pink
     NUC_TYPE_NUMBER_OF
 };


 enum ATTRIB_GEO {
     ATTRIB_GEO_CENTER_X_PX,
     ATTRIB_GEO_CENTER_Y_PX,
     ATTRIB_GEO_AREA_PX,
     ATTRIB_GEO_CENTER_X_UM,
     ATTRIB_GEO_CENTER_Y_UM,
     ATTRIB_GEO_AREA_UM,
     ATTRIB_GEO_CONVEXITY,
     ATTRIB_GEO_COMPACTNESS,
     ATTRIB_GEO_NUMBER_OF
 };

 enum ATTRIB_FOC {
     ATTRIB_FOC_CENTER_X_PX,
     ATTRIB_FOC_CENTER_X_UM,
     ATTRIB_FOC_CENTER_Y_PX,
     ATTRIB_FOC_CENTER_Y_UM,
     ATTRIB_FOC_AREA_PX,
     ATTRIB_FOC_AREA_UM,
     ATTRIB_FOC_CONVEXITY,
     ATTRIB_FOC_COMPACTNESS,
     ATTRIB_FOC_COUNT_CHX,
     ATTRIB_FOC_MEAN_CHX,
     ATTRIB_FOC_STD_CHX,
     ATTRIB_FOC_SKEWNESS_CHX,
     ATTRIB_FOC_KURTOSIS_CHX,
     ATTRIB_FOC_MEDIAN_CHX,
     ATTRIB_FOC_ABSDEVMED_CHX,
     ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_PX,
     ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_UM,
     ATTRIB_FOC_OVERLAP_FOCI_CHANNEL_REL,
     ATTRIB_FOC_OVERLAP_FOCI_CHANNELS_OTHER_PX,
     ATTRIB_FOC_OVERLAP_FOCI_CHANNELS_OTHER_UM,
     ATTRIB_FOC_OVERLAP_FOCI_CHANNELS_OTHER_REL,
     ATTRIB_FOC_DETECTED_IN_CH,
     ATTRIB_FOC_NUMBER_OF
 };
 const QStringList QSL_Attrib_Foc = {
     "Center x /px",
     "Center x /um",
     "Center y /px",
     "Center y /um",
     "Area /px",
     "Area /um",
     "Convexity",
     "Compactness",
     "Pixel count",
     "Channel mean",
     "Channel STD",
     "Channel skewness",
     "Channel kurtosis",
     "Channel median",
     "Channel abs. med. dev.",
     "Overlap Foci channel /px^2",
     "Overlap Foci channel /um^2",
     "Overlap Foci channel relative",
     "Overlap Foci other channels /px^2",
     "Overlap Foci other channels /um^2",
     "Overlap Foci other channels relative",
     "Detected in channel"
 };

 enum ATTRIB_NUC {
     ATTRIB_NUC_TIME_INDEX,
     ATTRIB_NUC_TIME_DIFF_TO_IRRADIATION,
     ATTRIB_NUC_TIME_AGE_PAST,
     ATTRIB_NUC_TIME_AGE_TOGO,
     ATTRIB_NUC_TIME_AGE_FULL,
     ATTRIB_NUC_CENTER_X_PX,
     ATTRIB_NUC_CENTER_X_UM,
     ATTRIB_NUC_CENTER_Y_PX,
     ATTRIB_NUC_CENTER_Y_UM,
     ATTRIB_NUC_AREA_PX,
     ATTRIB_NUC_AREA_UM,
     ATTRIB_NUC_CONVEXITY,
     ATTRIB_NUC_COMPACTNESS,
     ATTRIB_NUC_SHIFT_PX,
     ATTRIB_NUC_SHIFT_UM,
     ATTRIB_NUC_COUNT_CHX,
     ATTRIB_NUC_MEAN_CHX,
     ATTRIB_NUC_STD_CHX,
     ATTRIB_NUC_SKEWNESS_CHX,
     ATTRIB_NUC_KURTOSIS_CHX,
     ATTRIB_NUC_MEDIAN_CHX,
     ATTRIB_NUC_ABSDEVMED_CHX,
     ATTRIB_NUC_FOCI_COUNT_CHX,
     ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_PX,
     ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_UM,
     ATTRIB_NUC_FOCI_COUNT_ALL,
     ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX,
     ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_UM,
     ATTRIB_NUC_NUMBER_OF
 };
 const QStringList QSL_Attrib_Nuc = {
     "Time index global /h",
     "Time since irradiation /h",
     "Age (past) /h",
     "Age (to go) /h",
     "Age (full) /h",
     "Center x /px",
     "Center x /um",
     "Center y /px",
     "Center y /um",
     "Area /px",
     "Area /um",
     "Convexity",
     "Compactness",
     "Shift /px",
     "Shift /um",
     "Pixel count",
     "Channel mean",
     "Channel STD",
     "Channel skewness",
     "Channel kurtosis",
     "Channel median",
     "Channel abs. med. dev.",
     "Foci in channel",
     "Foci/Area /(1/px^2) in channel",
     "Foci/Area /(1/um^2) in channel",
     "Foci in all channels",
     "Foci/Area /(1/px^2) in all channels",
     "Foci/Area /(1/um^2) in all channels"
 };

 enum ATTRIB_NUCLIFE {
     ATTRIB_NUCLIFE_AGE,
     ATTRIB_NUCLIFE_START,
     ATTRIB_NUCLIFE_END,
     ATTRIB_NUCLIFE_MID,
     ATTRIB_NUCLIFE_SHIFT_PX,
     ATTRIB_NUCLIFE_SHIFT_UM,
     ATTRIB_NUCLIFE_PATHLENGTH_PX,
     ATTRIB_NUCLIFE_PATHLENGTH_UM,
     ATTRIB_NUCLIFE_SHIFT_PX_PER_T,
     ATTRIB_NUCLIFE_SHIFT_UM_PER_T,
     ATTRIB_NUCLIFE_PATHLENGTH_PX_PER_T,
     ATTRIB_NUCLIFE_PATHLENGTH_UM_PER_T,
     ATTRIB_NUCLIFE_AREA_GROWTH,
     ATTRIB_NUCLIFE_AREA_GROWTH_PER_T,
     ATTRIB_NUCLIFE_FOCICOUNT_GROWTH,
     ATTRIB_NUCLIFE_FOCICOUNT_GROWTH_PER_T,
     ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_GROWTH,
     ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_GROWTH_PER_T,
     ATTRIB_NUCLIFE_CLOSTEST_DIST_TO_BORDER_PX,
     ATTRIB_NUCLIFE_CLOSTEST_DIST_TO_BORDER_UM,
     ATTRIB_NUCLIFE_IN_RANGE_PERMANENT,
     ATTRIB_NUCLIFE_MITOSIS_STARTS_WITH,
     ATTRIB_NUCLIFE_MITOSIS_ENDS_WITH,
     ATTRIB_NUCLIFE_MITOSIS_STARTS_ENDS_WITH,
     ATTRIB_NUCLIFE_NUMBER_OF
 };
 const QStringList QSL_Attrib_NucLife = {
     "Age /h",
     "Time begin /h",
     "Time end /h",
     "Time mid /h",
     "Shift /px",
     "Shift /um",
     "Pathlength /px",
     "Pathlength /um",
     "Shift/Time /(px/h)",
     "Shift/Time /(um/h)",
     "Pathlength/Time /(px/h)",
     "Pathlength/Time /(um/h)",
     "Area increase",
     "Area increase/Time /(1/h)",
     "Foci increase",
     "Foci increase/Time /(1/h)",
     "Foci/Area increase",
     "Foci/Area increase/Time /(1/h)",
     "Closest distance to border /px",
     "Closest distance to border /um",
     "Is permanently in range",
     "Starts with mitosis",
     "Ends with mitosis",
     "Starts and ends with mitosis"
 };

 //filter modi
 enum ATTRIB_FILTER_MODE {
     ATTRIB_FILTER_MODE_FOCI,
     ATTRIB_FILTER_MODE_NUC_BLOB,
     ATTRIB_FILTER_MODE_NUC_LIFE,
     ATTRIB_FILTER_MODE_NUMBER_OF
 };

 //data point level
 enum DATAPOINT_LEVEL {
     DATAPOINT_LEVEL_NUCLIFE,
     DATAPOINT_LEVEL_NUCBLOB,
     DATAPOINT_LEVEL_FOC,
     DATAPOINT_LEVEL_NUMBER_OF
 };
 const QStringList QSL_DatapointLevel = {
     "Nucleus lifes",
     "Nucleus blobs",
     "Foci"
 };

 //data lvl nuc lifes
 enum DATA_LEVEL_NUCLIFE {
     DATA_LEVEL_NUCLIFE_ATTRIB,
     DATA_LEVEL_NUCLIFE_STAT_NUCBLOB,
     DATA_LEVEL_NUCLIFE_STAT_STAT_FOC,
     DATA_LEVEL_NUCLIFE_NUMBER_OF
 };
 const QStringList QSL_DataLevel_NucLife = {
     "Nucleus life",
     "Nucleus blob",
     "Focus"
 };

 //data lvl nuc blobs
 enum DATA_LEVEL_NUCBLOB {
     DATA_LEVEL_NUCBLOB_ATTRIB,
     DATA_LEVEL_NUCBLOB_STAT_FOC,
     DATA_LEVEL_NUCBLOB_NUMBER_OF
 };
 const QStringList QSL_DataLevel_NucBlob = {
     "Nucleus blob",
     "Focus"
 };

 //data lvl foci
 enum DATA_LEVEL_FOC {
     DATA_LEVEL_FOC_ATTRIB,
     DATA_LEVEL_FOC_NUMBER_OF
 };
 const QStringList QSL_DataLevel_Foc = {
     "Focus"
 };



#endif // D_BIO_ENUM_H
