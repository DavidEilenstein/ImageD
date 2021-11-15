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


#endif // D_BIO_ENUM_H
