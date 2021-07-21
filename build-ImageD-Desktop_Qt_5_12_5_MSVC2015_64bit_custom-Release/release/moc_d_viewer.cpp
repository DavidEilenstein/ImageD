/****************************************************************************
** Meta object code from reading C++ file 'd_viewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Code/d_viewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'd_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_D_Viewer_t {
    QByteArrayData data[146];
    char stringdata0[2275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_D_Viewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_D_Viewer_t qt_meta_stringdata_D_Viewer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "D_Viewer"
QT_MOC_LITERAL(1, 9, 10), // "MouseMoved"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "MouseMoved_Pos"
QT_MOC_LITERAL(4, 36, 1), // "x"
QT_MOC_LITERAL(5, 38, 1), // "y"
QT_MOC_LITERAL(6, 40, 3), // "pos"
QT_MOC_LITERAL(7, 44, 16), // "MouseMoved_Value"
QT_MOC_LITERAL(8, 61, 14), // "vector<double>"
QT_MOC_LITERAL(9, 76, 3), // "val"
QT_MOC_LITERAL(10, 80, 12), // "MouseClicked"
QT_MOC_LITERAL(11, 93, 16), // "MouseClickedLeft"
QT_MOC_LITERAL(12, 110, 17), // "MouseClickedRight"
QT_MOC_LITERAL(13, 128, 15), // "MouseClickedMid"
QT_MOC_LITERAL(14, 144, 16), // "MouseClicked_Pos"
QT_MOC_LITERAL(15, 161, 20), // "MouseClickedLeft_Pos"
QT_MOC_LITERAL(16, 182, 21), // "MouseClickedRight_Pos"
QT_MOC_LITERAL(17, 204, 19), // "MouseClickedMid_Pos"
QT_MOC_LITERAL(18, 224, 18), // "MouseClicked_Value"
QT_MOC_LITERAL(19, 243, 11), // "TypeChanged"
QT_MOC_LITERAL(20, 255, 14), // "TypeChanged_QI"
QT_MOC_LITERAL(21, 270, 4), // "type"
QT_MOC_LITERAL(22, 275, 14), // "TypeChanged_MA"
QT_MOC_LITERAL(23, 290, 18), // "Image_Size_Changed"
QT_MOC_LITERAL(24, 309, 5), // "width"
QT_MOC_LITERAL(25, 315, 6), // "height"
QT_MOC_LITERAL(26, 322, 4), // "size"
QT_MOC_LITERAL(27, 327, 12), // "View_Updated"
QT_MOC_LITERAL(28, 340, 6), // "Scaled"
QT_MOC_LITERAL(29, 347, 13), // "Scaled_Factor"
QT_MOC_LITERAL(30, 361, 3), // "f_x"
QT_MOC_LITERAL(31, 365, 3), // "f_y"
QT_MOC_LITERAL(32, 369, 5), // "scale"
QT_MOC_LITERAL(33, 375, 17), // "Scaled_Factor_Prz"
QT_MOC_LITERAL(34, 393, 9), // "scale_prz"
QT_MOC_LITERAL(35, 403, 6), // "Zoomed"
QT_MOC_LITERAL(36, 410, 5), // "x_rel"
QT_MOC_LITERAL(37, 416, 5), // "y_rel"
QT_MOC_LITERAL(38, 422, 6), // "factor"
QT_MOC_LITERAL(39, 429, 12), // "Zoomed_Reset"
QT_MOC_LITERAL(40, 442, 16), // "Time_View_Update"
QT_MOC_LITERAL(41, 459, 7), // "time_ms"
QT_MOC_LITERAL(42, 467, 14), // "Time_Image_Cvt"
QT_MOC_LITERAL(43, 482, 11), // "Image_Saved"
QT_MOC_LITERAL(44, 494, 4), // "path"
QT_MOC_LITERAL(45, 499, 23), // "ClickRecordSignal_Start"
QT_MOC_LITERAL(46, 523, 24), // "ClickRecordSignal_Record"
QT_MOC_LITERAL(47, 548, 37), // "ClickRecordSignal_RecordedPoi..."
QT_MOC_LITERAL(48, 586, 6), // "size_t"
QT_MOC_LITERAL(49, 593, 5), // "count"
QT_MOC_LITERAL(50, 599, 23), // "ClickRecordSignal_Clear"
QT_MOC_LITERAL(51, 623, 22), // "ClickRecordSignal_Quit"
QT_MOC_LITERAL(52, 646, 27), // "ClickRecordSignal_GetPoints"
QT_MOC_LITERAL(53, 674, 13), // "vector<Point>"
QT_MOC_LITERAL(54, 688, 7), // "vPoints"
QT_MOC_LITERAL(55, 696, 35), // "ClickRecordSignal_GetPoints_E..."
QT_MOC_LITERAL(56, 732, 14), // "vPointsEllipse"
QT_MOC_LITERAL(57, 747, 35), // "ClickRecordSignal_GetPoints_P..."
QT_MOC_LITERAL(58, 783, 14), // "vPointsPolygon"
QT_MOC_LITERAL(59, 798, 38), // "ClickRecordSignal_GetPoints_C..."
QT_MOC_LITERAL(60, 837, 17), // "vPointsConvexHull"
QT_MOC_LITERAL(61, 855, 35), // "ClickRecordSignal_GetPoints_C..."
QT_MOC_LITERAL(62, 891, 22), // "vector<vector<Point> >"
QT_MOC_LITERAL(63, 914, 15), // "vvPointsCircles"
QT_MOC_LITERAL(64, 930, 25), // "ClickRecordSignal_Ellipse"
QT_MOC_LITERAL(65, 956, 11), // "RotatedRect"
QT_MOC_LITERAL(66, 968, 7), // "ellipse"
QT_MOC_LITERAL(67, 976, 8), // "Zoom_Pos"
QT_MOC_LITERAL(68, 985, 7), // "Zoom_In"
QT_MOC_LITERAL(69, 993, 8), // "Zoom_Out"
QT_MOC_LITERAL(70, 1002, 10), // "Zoom_Reset"
QT_MOC_LITERAL(71, 1013, 11), // "Zoom_Update"
QT_MOC_LITERAL(72, 1025, 23), // "ClickRecord_DrawOverlay"
QT_MOC_LITERAL(73, 1049, 12), // "ScaleContour"
QT_MOC_LITERAL(74, 1062, 8), // "vContour"
QT_MOC_LITERAL(75, 1071, 5), // "Point"
QT_MOC_LITERAL(76, 1077, 13), // "scaled_offset"
QT_MOC_LITERAL(77, 1091, 13), // "ScaleContours"
QT_MOC_LITERAL(78, 1105, 10), // "vvContours"
QT_MOC_LITERAL(79, 1116, 9), // "Set_Image"
QT_MOC_LITERAL(80, 1126, 4), // "Mat*"
QT_MOC_LITERAL(81, 1131, 6), // "MA_new"
QT_MOC_LITERAL(82, 1138, 12), // "Update_Image"
QT_MOC_LITERAL(83, 1151, 11), // "Update_View"
QT_MOC_LITERAL(84, 1163, 17), // "Save_Image_Dialog"
QT_MOC_LITERAL(85, 1181, 12), // "path_default"
QT_MOC_LITERAL(86, 1194, 10), // "Save_Image"
QT_MOC_LITERAL(87, 1205, 14), // "Set_ViewerMode"
QT_MOC_LITERAL(88, 1220, 4), // "mode"
QT_MOC_LITERAL(89, 1225, 23), // "Set_Transformation_Mode"
QT_MOC_LITERAL(90, 1249, 6), // "smooth"
QT_MOC_LITERAL(91, 1256, 15), // "Set_Aspect_Mode"
QT_MOC_LITERAL(92, 1272, 4), // "keep"
QT_MOC_LITERAL(93, 1277, 12), // "Set_PlotType"
QT_MOC_LITERAL(94, 1290, 22), // "Set_VisTrafo_ActiveInt"
QT_MOC_LITERAL(95, 1313, 6), // "active"
QT_MOC_LITERAL(96, 1320, 23), // "Set_VisTrafo_ActiveBool"
QT_MOC_LITERAL(97, 1344, 18), // "Set_VisTrafo_Gamma"
QT_MOC_LITERAL(98, 1363, 5), // "gamma"
QT_MOC_LITERAL(99, 1369, 24), // "Set_VisTrafo_SpreadInMin"
QT_MOC_LITERAL(100, 1394, 10), // "spread_min"
QT_MOC_LITERAL(101, 1405, 24), // "Set_VisTrafo_SpreadInMax"
QT_MOC_LITERAL(102, 1430, 10), // "spread_max"
QT_MOC_LITERAL(103, 1441, 19), // "Set_VisTrafo_Center"
QT_MOC_LITERAL(104, 1461, 6), // "center"
QT_MOC_LITERAL(105, 1468, 20), // "Set_VisTrafo_Divisor"
QT_MOC_LITERAL(106, 1489, 7), // "divisor"
QT_MOC_LITERAL(107, 1497, 19), // "Set_VisTrafo_Anchor"
QT_MOC_LITERAL(108, 1517, 6), // "anchor"
QT_MOC_LITERAL(109, 1524, 18), // "Set_VisTrafo_Range"
QT_MOC_LITERAL(110, 1543, 5), // "range"
QT_MOC_LITERAL(111, 1549, 22), // "Set_VisTrafo_Mode_Crop"
QT_MOC_LITERAL(112, 1572, 23), // "Set_VisTrafo_Mode_Trafo"
QT_MOC_LITERAL(113, 1596, 24), // "Set_VisTrafo_Mode_Anchor"
QT_MOC_LITERAL(114, 1621, 23), // "Set_VisTrafo_Mode_Range"
QT_MOC_LITERAL(115, 1645, 25), // "Set_VisTrafo_Mode_Complex"
QT_MOC_LITERAL(116, 1671, 8), // "Set_Zoom"
QT_MOC_LITERAL(117, 1680, 15), // "Set_Zoom_Extern"
QT_MOC_LITERAL(118, 1696, 13), // "Set_ZoomReset"
QT_MOC_LITERAL(119, 1710, 20), // "Set_ZoomReset_Extern"
QT_MOC_LITERAL(120, 1731, 8), // "Set_Name"
QT_MOC_LITERAL(121, 1740, 4), // "name"
QT_MOC_LITERAL(122, 1745, 17), // "MouseClicked_Left"
QT_MOC_LITERAL(123, 1763, 18), // "MouseClicked_Right"
QT_MOC_LITERAL(124, 1782, 16), // "MouseClicked_Mid"
QT_MOC_LITERAL(125, 1799, 17), // "ClickRecord_Start"
QT_MOC_LITERAL(126, 1817, 29), // "ClickRecord_Start_RecieveOnly"
QT_MOC_LITERAL(127, 1847, 18), // "ClickRecord_Record"
QT_MOC_LITERAL(128, 1866, 1), // "P"
QT_MOC_LITERAL(129, 1868, 30), // "ClickRecord_Record_RecieveOnly"
QT_MOC_LITERAL(130, 1899, 17), // "ClickRecord_Clear"
QT_MOC_LITERAL(131, 1917, 29), // "ClickRecord_Clear_RecieveOnly"
QT_MOC_LITERAL(132, 1947, 16), // "ClickRecord_Quit"
QT_MOC_LITERAL(133, 1964, 28), // "ClickRecord_Quit_RecieveOnly"
QT_MOC_LITERAL(134, 1993, 21), // "ClickRecord_GetPoints"
QT_MOC_LITERAL(135, 2015, 29), // "ClickRecord_GetPoints_Ellipse"
QT_MOC_LITERAL(136, 2045, 29), // "ClickRecord_GetPoints_Polygon"
QT_MOC_LITERAL(137, 2075, 32), // "ClickRecord_GetPoints_ConvexHull"
QT_MOC_LITERAL(138, 2108, 29), // "ClickRecord_GetPoints_Circles"
QT_MOC_LITERAL(139, 2138, 6), // "radius"
QT_MOC_LITERAL(140, 2145, 19), // "ClickRecord_Ellipse"
QT_MOC_LITERAL(141, 2165, 30), // "ClickRecord_ChangeOverlayColor"
QT_MOC_LITERAL(142, 2196, 5), // "color"
QT_MOC_LITERAL(143, 2202, 38), // "ClickRecord_ChangeOverlayPoin..."
QT_MOC_LITERAL(144, 2241, 1), // "d"
QT_MOC_LITERAL(145, 2243, 31) // "ClickRecord_RecordedPointsCount"

    },
    "D_Viewer\0MouseMoved\0\0MouseMoved_Pos\0"
    "x\0y\0pos\0MouseMoved_Value\0vector<double>\0"
    "val\0MouseClicked\0MouseClickedLeft\0"
    "MouseClickedRight\0MouseClickedMid\0"
    "MouseClicked_Pos\0MouseClickedLeft_Pos\0"
    "MouseClickedRight_Pos\0MouseClickedMid_Pos\0"
    "MouseClicked_Value\0TypeChanged\0"
    "TypeChanged_QI\0type\0TypeChanged_MA\0"
    "Image_Size_Changed\0width\0height\0size\0"
    "View_Updated\0Scaled\0Scaled_Factor\0f_x\0"
    "f_y\0scale\0Scaled_Factor_Prz\0scale_prz\0"
    "Zoomed\0x_rel\0y_rel\0factor\0Zoomed_Reset\0"
    "Time_View_Update\0time_ms\0Time_Image_Cvt\0"
    "Image_Saved\0path\0ClickRecordSignal_Start\0"
    "ClickRecordSignal_Record\0"
    "ClickRecordSignal_RecordedPointsCount\0"
    "size_t\0count\0ClickRecordSignal_Clear\0"
    "ClickRecordSignal_Quit\0"
    "ClickRecordSignal_GetPoints\0vector<Point>\0"
    "vPoints\0ClickRecordSignal_GetPoints_Ellipse\0"
    "vPointsEllipse\0ClickRecordSignal_GetPoints_Polygon\0"
    "vPointsPolygon\0ClickRecordSignal_GetPoints_ConvexHull\0"
    "vPointsConvexHull\0ClickRecordSignal_GetPoints_Circles\0"
    "vector<vector<Point> >\0vvPointsCircles\0"
    "ClickRecordSignal_Ellipse\0RotatedRect\0"
    "ellipse\0Zoom_Pos\0Zoom_In\0Zoom_Out\0"
    "Zoom_Reset\0Zoom_Update\0ClickRecord_DrawOverlay\0"
    "ScaleContour\0vContour\0Point\0scaled_offset\0"
    "ScaleContours\0vvContours\0Set_Image\0"
    "Mat*\0MA_new\0Update_Image\0Update_View\0"
    "Save_Image_Dialog\0path_default\0"
    "Save_Image\0Set_ViewerMode\0mode\0"
    "Set_Transformation_Mode\0smooth\0"
    "Set_Aspect_Mode\0keep\0Set_PlotType\0"
    "Set_VisTrafo_ActiveInt\0active\0"
    "Set_VisTrafo_ActiveBool\0Set_VisTrafo_Gamma\0"
    "gamma\0Set_VisTrafo_SpreadInMin\0"
    "spread_min\0Set_VisTrafo_SpreadInMax\0"
    "spread_max\0Set_VisTrafo_Center\0center\0"
    "Set_VisTrafo_Divisor\0divisor\0"
    "Set_VisTrafo_Anchor\0anchor\0"
    "Set_VisTrafo_Range\0range\0"
    "Set_VisTrafo_Mode_Crop\0Set_VisTrafo_Mode_Trafo\0"
    "Set_VisTrafo_Mode_Anchor\0"
    "Set_VisTrafo_Mode_Range\0"
    "Set_VisTrafo_Mode_Complex\0Set_Zoom\0"
    "Set_Zoom_Extern\0Set_ZoomReset\0"
    "Set_ZoomReset_Extern\0Set_Name\0name\0"
    "MouseClicked_Left\0MouseClicked_Right\0"
    "MouseClicked_Mid\0ClickRecord_Start\0"
    "ClickRecord_Start_RecieveOnly\0"
    "ClickRecord_Record\0P\0"
    "ClickRecord_Record_RecieveOnly\0"
    "ClickRecord_Clear\0ClickRecord_Clear_RecieveOnly\0"
    "ClickRecord_Quit\0ClickRecord_Quit_RecieveOnly\0"
    "ClickRecord_GetPoints\0"
    "ClickRecord_GetPoints_Ellipse\0"
    "ClickRecord_GetPoints_Polygon\0"
    "ClickRecord_GetPoints_ConvexHull\0"
    "ClickRecord_GetPoints_Circles\0radius\0"
    "ClickRecord_Ellipse\0ClickRecord_ChangeOverlayColor\0"
    "color\0ClickRecord_ChangeOverlayPointDiameter\0"
    "d\0ClickRecord_RecordedPointsCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_D_Viewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     129,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      46,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  659,    2, 0x06 /* Public */,
       3,    2,  660,    2, 0x06 /* Public */,
       3,    1,  665,    2, 0x06 /* Public */,
       7,    1,  668,    2, 0x06 /* Public */,
       7,    1,  671,    2, 0x06 /* Public */,
      10,    0,  674,    2, 0x06 /* Public */,
      11,    0,  675,    2, 0x06 /* Public */,
      12,    0,  676,    2, 0x06 /* Public */,
      13,    0,  677,    2, 0x06 /* Public */,
      14,    2,  678,    2, 0x06 /* Public */,
      15,    2,  683,    2, 0x06 /* Public */,
      16,    2,  688,    2, 0x06 /* Public */,
      17,    2,  693,    2, 0x06 /* Public */,
      14,    1,  698,    2, 0x06 /* Public */,
      18,    1,  701,    2, 0x06 /* Public */,
      18,    1,  704,    2, 0x06 /* Public */,
      19,    0,  707,    2, 0x06 /* Public */,
      20,    0,  708,    2, 0x06 /* Public */,
      20,    1,  709,    2, 0x06 /* Public */,
      22,    0,  712,    2, 0x06 /* Public */,
      22,    1,  713,    2, 0x06 /* Public */,
      23,    0,  716,    2, 0x06 /* Public */,
      23,    2,  717,    2, 0x06 /* Public */,
      23,    1,  722,    2, 0x06 /* Public */,
      27,    0,  725,    2, 0x06 /* Public */,
      28,    0,  726,    2, 0x06 /* Public */,
      29,    2,  727,    2, 0x06 /* Public */,
      29,    1,  732,    2, 0x06 /* Public */,
      33,    1,  735,    2, 0x06 /* Public */,
      35,    3,  738,    2, 0x06 /* Public */,
      39,    0,  745,    2, 0x06 /* Public */,
      40,    1,  746,    2, 0x06 /* Public */,
      42,    1,  749,    2, 0x06 /* Public */,
      43,    0,  752,    2, 0x06 /* Public */,
      43,    1,  753,    2, 0x06 /* Public */,
      45,    0,  756,    2, 0x06 /* Public */,
      46,    2,  757,    2, 0x06 /* Public */,
      47,    1,  762,    2, 0x06 /* Public */,
      50,    0,  765,    2, 0x06 /* Public */,
      51,    0,  766,    2, 0x06 /* Public */,
      52,    1,  767,    2, 0x06 /* Public */,
      55,    1,  770,    2, 0x06 /* Public */,
      57,    1,  773,    2, 0x06 /* Public */,
      59,    1,  776,    2, 0x06 /* Public */,
      61,    1,  779,    2, 0x06 /* Public */,
      64,    1,  782,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      67,    2,  785,    2, 0x08 /* Private */,
      68,    0,  790,    2, 0x08 /* Private */,
      69,    0,  791,    2, 0x08 /* Private */,
      70,    0,  792,    2, 0x08 /* Private */,
      71,    0,  793,    2, 0x08 /* Private */,
      72,    0,  794,    2, 0x08 /* Private */,
      73,    3,  795,    2, 0x08 /* Private */,
      77,    3,  802,    2, 0x08 /* Private */,
      79,    1,  809,    2, 0x0a /* Public */,
      82,    1,  812,    2, 0x0a /* Public */,
      82,    0,  815,    2, 0x0a /* Public */,
      83,    0,  816,    2, 0x0a /* Public */,
      84,    0,  817,    2, 0x0a /* Public */,
      84,    1,  818,    2, 0x0a /* Public */,
      86,    0,  821,    2, 0x0a /* Public */,
      86,    1,  822,    2, 0x0a /* Public */,
      87,    1,  825,    2, 0x0a /* Public */,
      89,    1,  828,    2, 0x0a /* Public */,
      91,    1,  831,    2, 0x0a /* Public */,
      93,    1,  834,    2, 0x0a /* Public */,
      94,    1,  837,    2, 0x0a /* Public */,
      94,    0,  840,    2, 0x2a /* Public | MethodCloned */,
      96,    1,  841,    2, 0x0a /* Public */,
      96,    0,  844,    2, 0x2a /* Public | MethodCloned */,
      97,    1,  845,    2, 0x0a /* Public */,
      97,    0,  848,    2, 0x2a /* Public | MethodCloned */,
      99,    1,  849,    2, 0x0a /* Public */,
      99,    0,  852,    2, 0x2a /* Public | MethodCloned */,
     101,    1,  853,    2, 0x0a /* Public */,
     101,    0,  856,    2, 0x2a /* Public | MethodCloned */,
     103,    1,  857,    2, 0x0a /* Public */,
     103,    0,  860,    2, 0x2a /* Public | MethodCloned */,
     105,    1,  861,    2, 0x0a /* Public */,
     105,    0,  864,    2, 0x2a /* Public | MethodCloned */,
     107,    1,  865,    2, 0x0a /* Public */,
     107,    0,  868,    2, 0x2a /* Public | MethodCloned */,
     109,    1,  869,    2, 0x0a /* Public */,
     109,    0,  872,    2, 0x2a /* Public | MethodCloned */,
     111,    1,  873,    2, 0x0a /* Public */,
     111,    0,  876,    2, 0x2a /* Public | MethodCloned */,
     112,    1,  877,    2, 0x0a /* Public */,
     112,    0,  880,    2, 0x2a /* Public | MethodCloned */,
     113,    1,  881,    2, 0x0a /* Public */,
     113,    0,  884,    2, 0x2a /* Public | MethodCloned */,
     114,    1,  885,    2, 0x0a /* Public */,
     114,    0,  888,    2, 0x2a /* Public | MethodCloned */,
     115,    1,  889,    2, 0x0a /* Public */,
     115,    0,  892,    2, 0x2a /* Public | MethodCloned */,
     116,    3,  893,    2, 0x0a /* Public */,
     117,    3,  900,    2, 0x0a /* Public */,
     118,    0,  907,    2, 0x0a /* Public */,
     119,    0,  908,    2, 0x0a /* Public */,
     120,    1,  909,    2, 0x0a /* Public */,
       1,    2,  912,    2, 0x0a /* Public */,
      10,    2,  917,    2, 0x0a /* Public */,
     122,    2,  922,    2, 0x0a /* Public */,
     123,    2,  927,    2, 0x0a /* Public */,
     124,    2,  932,    2, 0x0a /* Public */,
     125,    0,  937,    2, 0x0a /* Public */,
     126,    0,  938,    2, 0x0a /* Public */,
     127,    1,  939,    2, 0x0a /* Public */,
     127,    2,  942,    2, 0x0a /* Public */,
     129,    1,  947,    2, 0x0a /* Public */,
     129,    2,  950,    2, 0x0a /* Public */,
     130,    0,  955,    2, 0x0a /* Public */,
     131,    0,  956,    2, 0x0a /* Public */,
     132,    0,  957,    2, 0x0a /* Public */,
     133,    0,  958,    2, 0x0a /* Public */,
     134,    0,  959,    2, 0x0a /* Public */,
     134,    2,  960,    2, 0x0a /* Public */,
     135,    0,  965,    2, 0x0a /* Public */,
     135,    2,  966,    2, 0x0a /* Public */,
     136,    0,  971,    2, 0x0a /* Public */,
     136,    2,  972,    2, 0x0a /* Public */,
     137,    0,  977,    2, 0x0a /* Public */,
     137,    2,  978,    2, 0x0a /* Public */,
     138,    1,  983,    2, 0x0a /* Public */,
     138,    3,  986,    2, 0x0a /* Public */,
     140,    0,  993,    2, 0x0a /* Public */,
     140,    2,  994,    2, 0x0a /* Public */,
     141,    1,  999,    2, 0x0a /* Public */,
     143,    1, 1002,    2, 0x0a /* Public */,
     145,    0, 1005,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   30,   31,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   36,   37,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   41,
    QMetaType::Void, QMetaType::UInt,   41,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 48,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53,   54,
    QMetaType::Void, 0x80000000 | 53,   56,
    QMetaType::Void, 0x80000000 | 53,   58,
    QMetaType::Void, 0x80000000 | 53,   60,
    QMetaType::Void, 0x80000000 | 62,   63,
    QMetaType::Void, 0x80000000 | 65,   66,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 53, 0x80000000 | 53, QMetaType::Double, 0x80000000 | 75,   74,   32,   76,
    0x80000000 | 62, 0x80000000 | 62, QMetaType::Double, 0x80000000 | 75,   78,   32,   76,
    QMetaType::Void, 0x80000000 | 80,   81,
    QMetaType::Void, 0x80000000 | 80,   81,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,   85,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void, QMetaType::Bool,   90,
    QMetaType::Void, QMetaType::Bool,   92,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void, QMetaType::Int,   95,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   95,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   98,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  100,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  102,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  104,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  106,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  108,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  110,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   36,   37,   38,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   36,   37,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  121,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 75,  128,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Bool, 0x80000000 | 75,  128,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 53,
    0x80000000 | 53, QMetaType::Double, 0x80000000 | 75,   32,   76,
    0x80000000 | 53,
    0x80000000 | 53, QMetaType::Double, 0x80000000 | 75,   32,   76,
    0x80000000 | 53,
    0x80000000 | 53, QMetaType::Double, 0x80000000 | 75,   32,   76,
    0x80000000 | 53,
    0x80000000 | 53, QMetaType::Double, 0x80000000 | 75,   32,   76,
    0x80000000 | 62, QMetaType::Double,  139,
    0x80000000 | 62, QMetaType::Double, QMetaType::Double, 0x80000000 | 75,  139,   32,   76,
    0x80000000 | 65,
    0x80000000 | 65, QMetaType::Double, 0x80000000 | 75,   32,   76,
    QMetaType::Void, QMetaType::QColor,  142,
    QMetaType::Void, QMetaType::Int,  144,
    0x80000000 | 48,

       0        // eod
};

void D_Viewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<D_Viewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MouseMoved(); break;
        case 1: _t->MouseMoved_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->MouseMoved_Pos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->MouseMoved_Value((*reinterpret_cast< vector<double>(*)>(_a[1]))); break;
        case 4: _t->MouseMoved_Value((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->MouseClicked(); break;
        case 6: _t->MouseClickedLeft(); break;
        case 7: _t->MouseClickedRight(); break;
        case 8: _t->MouseClickedMid(); break;
        case 9: _t->MouseClicked_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->MouseClickedLeft_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->MouseClickedRight_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->MouseClickedMid_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->MouseClicked_Pos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->MouseClicked_Value((*reinterpret_cast< vector<double>(*)>(_a[1]))); break;
        case 15: _t->MouseClicked_Value((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->TypeChanged(); break;
        case 17: _t->TypeChanged_QI(); break;
        case 18: _t->TypeChanged_QI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->TypeChanged_MA(); break;
        case 20: _t->TypeChanged_MA((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->Image_Size_Changed(); break;
        case 22: _t->Image_Size_Changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->Image_Size_Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->View_Updated(); break;
        case 25: _t->Scaled(); break;
        case 26: _t->Scaled_Factor((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 27: _t->Scaled_Factor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->Scaled_Factor_Prz((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->Zoomed((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 30: _t->Zoomed_Reset(); break;
        case 31: _t->Time_View_Update((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 32: _t->Time_Image_Cvt((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 33: _t->Image_Saved(); break;
        case 34: _t->Image_Saved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->ClickRecordSignal_Start(); break;
        case 36: _t->ClickRecordSignal_Record((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: _t->ClickRecordSignal_RecordedPointsCount((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 38: _t->ClickRecordSignal_Clear(); break;
        case 39: _t->ClickRecordSignal_Quit(); break;
        case 40: _t->ClickRecordSignal_GetPoints((*reinterpret_cast< vector<Point>(*)>(_a[1]))); break;
        case 41: _t->ClickRecordSignal_GetPoints_Ellipse((*reinterpret_cast< vector<Point>(*)>(_a[1]))); break;
        case 42: _t->ClickRecordSignal_GetPoints_Polygon((*reinterpret_cast< vector<Point>(*)>(_a[1]))); break;
        case 43: _t->ClickRecordSignal_GetPoints_ConvexHull((*reinterpret_cast< vector<Point>(*)>(_a[1]))); break;
        case 44: _t->ClickRecordSignal_GetPoints_Circles((*reinterpret_cast< vector<vector<Point> >(*)>(_a[1]))); break;
        case 45: _t->ClickRecordSignal_Ellipse((*reinterpret_cast< RotatedRect(*)>(_a[1]))); break;
        case 46: _t->Zoom_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 47: _t->Zoom_In(); break;
        case 48: _t->Zoom_Out(); break;
        case 49: _t->Zoom_Reset(); break;
        case 50: _t->Zoom_Update(); break;
        case 51: _t->ClickRecord_DrawOverlay(); break;
        case 52: { vector<Point> _r = _t->ScaleContour((*reinterpret_cast< vector<Point>(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 53: { vector<vector<Point> > _r = _t->ScaleContours((*reinterpret_cast< vector<vector<Point> >(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< vector<vector<Point> >*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->Set_Image((*reinterpret_cast< Mat*(*)>(_a[1]))); break;
        case 55: _t->Update_Image((*reinterpret_cast< Mat*(*)>(_a[1]))); break;
        case 56: _t->Update_Image(); break;
        case 57: _t->Update_View(); break;
        case 58: { QString _r = _t->Save_Image_Dialog();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 59: { QString _r = _t->Save_Image_Dialog((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 60: { QString _r = _t->Save_Image();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 61: { QString _r = _t->Save_Image((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 62: _t->Set_ViewerMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->Set_Transformation_Mode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 64: _t->Set_Aspect_Mode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 65: _t->Set_PlotType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->Set_VisTrafo_ActiveInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: _t->Set_VisTrafo_ActiveInt(); break;
        case 68: _t->Set_VisTrafo_ActiveBool((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 69: _t->Set_VisTrafo_ActiveBool(); break;
        case 70: _t->Set_VisTrafo_Gamma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 71: _t->Set_VisTrafo_Gamma(); break;
        case 72: _t->Set_VisTrafo_SpreadInMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 73: _t->Set_VisTrafo_SpreadInMin(); break;
        case 74: _t->Set_VisTrafo_SpreadInMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 75: _t->Set_VisTrafo_SpreadInMax(); break;
        case 76: _t->Set_VisTrafo_Center((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 77: _t->Set_VisTrafo_Center(); break;
        case 78: _t->Set_VisTrafo_Divisor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 79: _t->Set_VisTrafo_Divisor(); break;
        case 80: _t->Set_VisTrafo_Anchor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 81: _t->Set_VisTrafo_Anchor(); break;
        case 82: _t->Set_VisTrafo_Range((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 83: _t->Set_VisTrafo_Range(); break;
        case 84: _t->Set_VisTrafo_Mode_Crop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->Set_VisTrafo_Mode_Crop(); break;
        case 86: _t->Set_VisTrafo_Mode_Trafo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 87: _t->Set_VisTrafo_Mode_Trafo(); break;
        case 88: _t->Set_VisTrafo_Mode_Anchor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 89: _t->Set_VisTrafo_Mode_Anchor(); break;
        case 90: _t->Set_VisTrafo_Mode_Range((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 91: _t->Set_VisTrafo_Mode_Range(); break;
        case 92: _t->Set_VisTrafo_Mode_Complex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 93: _t->Set_VisTrafo_Mode_Complex(); break;
        case 94: _t->Set_Zoom((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 95: _t->Set_Zoom_Extern((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 96: _t->Set_ZoomReset(); break;
        case 97: _t->Set_ZoomReset_Extern(); break;
        case 98: _t->Set_Name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 99: _t->MouseMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 100: _t->MouseClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 101: _t->MouseClicked_Left((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 102: _t->MouseClicked_Right((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 103: _t->MouseClicked_Mid((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 104: _t->ClickRecord_Start(); break;
        case 105: _t->ClickRecord_Start_RecieveOnly(); break;
        case 106: { bool _r = _t->ClickRecord_Record((*reinterpret_cast< Point(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 107: { bool _r = _t->ClickRecord_Record((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 108: { bool _r = _t->ClickRecord_Record_RecieveOnly((*reinterpret_cast< Point(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 109: { bool _r = _t->ClickRecord_Record_RecieveOnly((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 110: _t->ClickRecord_Clear(); break;
        case 111: _t->ClickRecord_Clear_RecieveOnly(); break;
        case 112: _t->ClickRecord_Quit(); break;
        case 113: _t->ClickRecord_Quit_RecieveOnly(); break;
        case 114: { vector<Point> _r = _t->ClickRecord_GetPoints();
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 115: { vector<Point> _r = _t->ClickRecord_GetPoints((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 116: { vector<Point> _r = _t->ClickRecord_GetPoints_Ellipse();
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 117: { vector<Point> _r = _t->ClickRecord_GetPoints_Ellipse((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 118: { vector<Point> _r = _t->ClickRecord_GetPoints_Polygon();
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 119: { vector<Point> _r = _t->ClickRecord_GetPoints_Polygon((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 120: { vector<Point> _r = _t->ClickRecord_GetPoints_ConvexHull();
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 121: { vector<Point> _r = _t->ClickRecord_GetPoints_ConvexHull((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< vector<Point>*>(_a[0]) = std::move(_r); }  break;
        case 122: { vector<vector<Point> > _r = _t->ClickRecord_GetPoints_Circles((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<vector<Point> >*>(_a[0]) = std::move(_r); }  break;
        case 123: { vector<vector<Point> > _r = _t->ClickRecord_GetPoints_Circles((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< vector<vector<Point> >*>(_a[0]) = std::move(_r); }  break;
        case 124: { RotatedRect _r = _t->ClickRecord_Ellipse();
            if (_a[0]) *reinterpret_cast< RotatedRect*>(_a[0]) = std::move(_r); }  break;
        case 125: { RotatedRect _r = _t->ClickRecord_Ellipse((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< RotatedRect*>(_a[0]) = std::move(_r); }  break;
        case 126: _t->ClickRecord_ChangeOverlayColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 127: _t->ClickRecord_ChangeOverlayPointDiameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 128: { size_t _r = _t->ClickRecord_RecordedPointsCount();
            if (_a[0]) *reinterpret_cast< size_t*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseMoved)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseMoved_Pos)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseMoved_Pos)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseMoved_Value)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseMoved_Value)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClickedLeft)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClickedRight)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClickedMid)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClicked_Pos)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClickedLeft_Pos)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClickedRight_Pos)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClickedMid_Pos)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClicked_Pos)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClicked_Value)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::MouseClicked_Value)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::TypeChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::TypeChanged_QI)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::TypeChanged_QI)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::TypeChanged_MA)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::TypeChanged_MA)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Image_Size_Changed)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Image_Size_Changed)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Image_Size_Changed)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::View_Updated)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Scaled)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Scaled_Factor)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Scaled_Factor)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Scaled_Factor_Prz)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Zoomed)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Zoomed_Reset)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Time_View_Update)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Time_Image_Cvt)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Image_Saved)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::Image_Saved)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_Start)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_Record)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_RecordedPointsCount)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_Clear)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_Quit)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<Point> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_GetPoints)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<Point> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_GetPoints_Ellipse)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<Point> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_GetPoints_Polygon)) {
                *result = 42;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<Point> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_GetPoints_ConvexHull)) {
                *result = 43;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(vector<vector<Point>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_GetPoints_Circles)) {
                *result = 44;
                return;
            }
        }
        {
            using _t = void (D_Viewer::*)(RotatedRect );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_Viewer::ClickRecordSignal_Ellipse)) {
                *result = 45;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject D_Viewer::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_D_Viewer.data,
    qt_meta_data_D_Viewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *D_Viewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *D_Viewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_D_Viewer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int D_Viewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 129)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 129;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 129)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 129;
    }
    return _id;
}

// SIGNAL 0
void D_Viewer::MouseMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void D_Viewer::MouseMoved_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void D_Viewer::MouseMoved_Pos(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void D_Viewer::MouseMoved_Value(vector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void D_Viewer::MouseMoved_Value(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void D_Viewer::MouseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void D_Viewer::MouseClickedLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void D_Viewer::MouseClickedRight()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void D_Viewer::MouseClickedMid()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void D_Viewer::MouseClicked_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void D_Viewer::MouseClickedLeft_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void D_Viewer::MouseClickedRight_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void D_Viewer::MouseClickedMid_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void D_Viewer::MouseClicked_Pos(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void D_Viewer::MouseClicked_Value(vector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void D_Viewer::MouseClicked_Value(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void D_Viewer::TypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void D_Viewer::TypeChanged_QI()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void D_Viewer::TypeChanged_QI(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void D_Viewer::TypeChanged_MA()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void D_Viewer::TypeChanged_MA(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void D_Viewer::Image_Size_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void D_Viewer::Image_Size_Changed(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void D_Viewer::Image_Size_Changed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void D_Viewer::View_Updated()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void D_Viewer::Scaled()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void D_Viewer::Scaled_Factor(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void D_Viewer::Scaled_Factor(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void D_Viewer::Scaled_Factor_Prz(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void D_Viewer::Zoomed(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void D_Viewer::Zoomed_Reset()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void D_Viewer::Time_View_Update(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void D_Viewer::Time_Image_Cvt(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void D_Viewer::Image_Saved()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void D_Viewer::Image_Saved(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void D_Viewer::ClickRecordSignal_Start()
{
    QMetaObject::activate(this, &staticMetaObject, 35, nullptr);
}

// SIGNAL 36
void D_Viewer::ClickRecordSignal_Record(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void D_Viewer::ClickRecordSignal_RecordedPointsCount(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void D_Viewer::ClickRecordSignal_Clear()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void D_Viewer::ClickRecordSignal_Quit()
{
    QMetaObject::activate(this, &staticMetaObject, 39, nullptr);
}

// SIGNAL 40
void D_Viewer::ClickRecordSignal_GetPoints(vector<Point> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void D_Viewer::ClickRecordSignal_GetPoints_Ellipse(vector<Point> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 42
void D_Viewer::ClickRecordSignal_GetPoints_Polygon(vector<Point> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 42, _a);
}

// SIGNAL 43
void D_Viewer::ClickRecordSignal_GetPoints_ConvexHull(vector<Point> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 43, _a);
}

// SIGNAL 44
void D_Viewer::ClickRecordSignal_GetPoints_Circles(vector<vector<Point>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 44, _a);
}

// SIGNAL 45
void D_Viewer::ClickRecordSignal_Ellipse(RotatedRect _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 45, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
