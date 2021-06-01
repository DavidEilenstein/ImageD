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



#endif // D_BIO_ENUM_H
