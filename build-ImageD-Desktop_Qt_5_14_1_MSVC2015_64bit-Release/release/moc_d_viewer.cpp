/****************************************************************************
** Meta object code from reading C++ file 'd_viewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Code/d_viewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'd_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_D_Viewer_t {
    QByteArrayData data[92];
    char stringdata0[1180];
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
QT_MOC_LITERAL(45, 499, 8), // "Zoom_Pos"
QT_MOC_LITERAL(46, 508, 7), // "Zoom_In"
QT_MOC_LITERAL(47, 516, 8), // "Zoom_Out"
QT_MOC_LITERAL(48, 525, 10), // "Zoom_Reset"
QT_MOC_LITERAL(49, 536, 11), // "Zoom_Update"
QT_MOC_LITERAL(50, 548, 9), // "Set_Image"
QT_MOC_LITERAL(51, 558, 4), // "Mat*"
QT_MOC_LITERAL(52, 563, 6), // "MA_new"
QT_MOC_LITERAL(53, 570, 12), // "Update_Image"
QT_MOC_LITERAL(54, 583, 11), // "Update_View"
QT_MOC_LITERAL(55, 595, 17), // "Save_Image_Dialog"
QT_MOC_LITERAL(56, 613, 12), // "path_default"
QT_MOC_LITERAL(57, 626, 10), // "Save_Image"
QT_MOC_LITERAL(58, 637, 14), // "Set_ViewerMode"
QT_MOC_LITERAL(59, 652, 4), // "mode"
QT_MOC_LITERAL(60, 657, 23), // "Set_Transformation_Mode"
QT_MOC_LITERAL(61, 681, 6), // "smooth"
QT_MOC_LITERAL(62, 688, 15), // "Set_Aspect_Mode"
QT_MOC_LITERAL(63, 704, 4), // "keep"
QT_MOC_LITERAL(64, 709, 12), // "Set_PlotType"
QT_MOC_LITERAL(65, 722, 22), // "Set_VisTrafo_ActiveInt"
QT_MOC_LITERAL(66, 745, 6), // "active"
QT_MOC_LITERAL(67, 752, 23), // "Set_VisTrafo_ActiveBool"
QT_MOC_LITERAL(68, 776, 18), // "Set_VisTrafo_Gamma"
QT_MOC_LITERAL(69, 795, 5), // "gamma"
QT_MOC_LITERAL(70, 801, 24), // "Set_VisTrafo_SpreadInMin"
QT_MOC_LITERAL(71, 826, 10), // "spread_min"
QT_MOC_LITERAL(72, 837, 24), // "Set_VisTrafo_SpreadInMax"
QT_MOC_LITERAL(73, 862, 10), // "spread_max"
QT_MOC_LITERAL(74, 873, 19), // "Set_VisTrafo_Center"
QT_MOC_LITERAL(75, 893, 6), // "center"
QT_MOC_LITERAL(76, 900, 20), // "Set_VisTrafo_Divisor"
QT_MOC_LITERAL(77, 921, 7), // "divisor"
QT_MOC_LITERAL(78, 929, 19), // "Set_VisTrafo_Anchor"
QT_MOC_LITERAL(79, 949, 6), // "anchor"
QT_MOC_LITERAL(80, 956, 18), // "Set_VisTrafo_Range"
QT_MOC_LITERAL(81, 975, 5), // "range"
QT_MOC_LITERAL(82, 981, 22), // "Set_VisTrafo_Mode_Crop"
QT_MOC_LITERAL(83, 1004, 23), // "Set_VisTrafo_Mode_Trafo"
QT_MOC_LITERAL(84, 1028, 24), // "Set_VisTrafo_Mode_Anchor"
QT_MOC_LITERAL(85, 1053, 23), // "Set_VisTrafo_Mode_Range"
QT_MOC_LITERAL(86, 1077, 25), // "Set_VisTrafo_Mode_Complex"
QT_MOC_LITERAL(87, 1103, 8), // "Set_Zomm"
QT_MOC_LITERAL(88, 1112, 13), // "Set_ZoomReset"
QT_MOC_LITERAL(89, 1126, 17), // "MouseClicked_Left"
QT_MOC_LITERAL(90, 1144, 18), // "MouseClicked_Right"
QT_MOC_LITERAL(91, 1163, 16) // "MouseClicked_Mid"

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
    "Image_Saved\0path\0Zoom_Pos\0Zoom_In\0"
    "Zoom_Out\0Zoom_Reset\0Zoom_Update\0"
    "Set_Image\0Mat*\0MA_new\0Update_Image\0"
    "Update_View\0Save_Image_Dialog\0"
    "path_default\0Save_Image\0Set_ViewerMode\0"
    "mode\0Set_Transformation_Mode\0smooth\0"
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
    "Set_VisTrafo_Mode_Complex\0Set_Zomm\0"
    "Set_ZoomReset\0MouseClicked_Left\0"
    "MouseClicked_Right\0MouseClicked_Mid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_D_Viewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      87,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      35,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  449,    2, 0x06 /* Public */,
       3,    2,  450,    2, 0x06 /* Public */,
       3,    1,  455,    2, 0x06 /* Public */,
       7,    1,  458,    2, 0x06 /* Public */,
       7,    1,  461,    2, 0x06 /* Public */,
      10,    0,  464,    2, 0x06 /* Public */,
      11,    0,  465,    2, 0x06 /* Public */,
      12,    0,  466,    2, 0x06 /* Public */,
      13,    0,  467,    2, 0x06 /* Public */,
      14,    2,  468,    2, 0x06 /* Public */,
      15,    2,  473,    2, 0x06 /* Public */,
      16,    2,  478,    2, 0x06 /* Public */,
      17,    2,  483,    2, 0x06 /* Public */,
      14,    1,  488,    2, 0x06 /* Public */,
      18,    1,  491,    2, 0x06 /* Public */,
      18,    1,  494,    2, 0x06 /* Public */,
      19,    0,  497,    2, 0x06 /* Public */,
      20,    0,  498,    2, 0x06 /* Public */,
      20,    1,  499,    2, 0x06 /* Public */,
      22,    0,  502,    2, 0x06 /* Public */,
      22,    1,  503,    2, 0x06 /* Public */,
      23,    0,  506,    2, 0x06 /* Public */,
      23,    2,  507,    2, 0x06 /* Public */,
      23,    1,  512,    2, 0x06 /* Public */,
      27,    0,  515,    2, 0x06 /* Public */,
      28,    0,  516,    2, 0x06 /* Public */,
      29,    2,  517,    2, 0x06 /* Public */,
      29,    1,  522,    2, 0x06 /* Public */,
      33,    1,  525,    2, 0x06 /* Public */,
      35,    3,  528,    2, 0x06 /* Public */,
      39,    0,  535,    2, 0x06 /* Public */,
      40,    1,  536,    2, 0x06 /* Public */,
      42,    1,  539,    2, 0x06 /* Public */,
      43,    0,  542,    2, 0x06 /* Public */,
      43,    1,  543,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      45,    2,  546,    2, 0x08 /* Private */,
      46,    0,  551,    2, 0x08 /* Private */,
      47,    0,  552,    2, 0x08 /* Private */,
      48,    0,  553,    2, 0x08 /* Private */,
      49,    0,  554,    2, 0x08 /* Private */,
      50,    1,  555,    2, 0x0a /* Public */,
      53,    1,  558,    2, 0x0a /* Public */,
      53,    0,  561,    2, 0x0a /* Public */,
      54,    0,  562,    2, 0x0a /* Public */,
      55,    0,  563,    2, 0x0a /* Public */,
      55,    1,  564,    2, 0x0a /* Public */,
      57,    0,  567,    2, 0x0a /* Public */,
      57,    1,  568,    2, 0x0a /* Public */,
      58,    1,  571,    2, 0x0a /* Public */,
      60,    1,  574,    2, 0x0a /* Public */,
      62,    1,  577,    2, 0x0a /* Public */,
      64,    1,  580,    2, 0x0a /* Public */,
      65,    1,  583,    2, 0x0a /* Public */,
      65,    0,  586,    2, 0x2a /* Public | MethodCloned */,
      67,    1,  587,    2, 0x0a /* Public */,
      67,    0,  590,    2, 0x2a /* Public | MethodCloned */,
      68,    1,  591,    2, 0x0a /* Public */,
      68,    0,  594,    2, 0x2a /* Public | MethodCloned */,
      70,    1,  595,    2, 0x0a /* Public */,
      70,    0,  598,    2, 0x2a /* Public | MethodCloned */,
      72,    1,  599,    2, 0x0a /* Public */,
      72,    0,  602,    2, 0x2a /* Public | MethodCloned */,
      74,    1,  603,    2, 0x0a /* Public */,
      74,    0,  606,    2, 0x2a /* Public | MethodCloned */,
      76,    1,  607,    2, 0x0a /* Public */,
      76,    0,  610,    2, 0x2a /* Public | MethodCloned */,
      78,    1,  611,    2, 0x0a /* Public */,
      78,    0,  614,    2, 0x2a /* Public | MethodCloned */,
      80,    1,  615,    2, 0x0a /* Public */,
      80,    0,  618,    2, 0x2a /* Public | MethodCloned */,
      82,    1,  619,    2, 0x0a /* Public */,
      82,    0,  622,    2, 0x2a /* Public | MethodCloned */,
      83,    1,  623,    2, 0x0a /* Public */,
      83,    0,  626,    2, 0x2a /* Public | MethodCloned */,
      84,    1,  627,    2, 0x0a /* Public */,
      84,    0,  630,    2, 0x2a /* Public | MethodCloned */,
      85,    1,  631,    2, 0x0a /* Public */,
      85,    0,  634,    2, 0x2a /* Public | MethodCloned */,
      86,    1,  635,    2, 0x0a /* Public */,
      86,    0,  638,    2, 0x2a /* Public | MethodCloned */,
      87,    3,  639,    2, 0x0a /* Public */,
      88,    0,  646,    2, 0x0a /* Public */,
       1,    2,  647,    2, 0x0a /* Public */,
      10,    2,  652,    2, 0x0a /* Public */,
      89,    2,  657,    2, 0x0a /* Public */,
      90,    2,  662,    2, 0x0a /* Public */,
      91,    2,  667,    2, 0x0a /* Public */,

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

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,   56,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, QMetaType::Bool,   63,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   69,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   71,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   73,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   75,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   77,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   79,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   81,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   36,   37,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

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
        case 35: _t->Zoom_Pos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->Zoom_In(); break;
        case 37: _t->Zoom_Out(); break;
        case 38: _t->Zoom_Reset(); break;
        case 39: _t->Zoom_Update(); break;
        case 40: _t->Set_Image((*reinterpret_cast< Mat*(*)>(_a[1]))); break;
        case 41: _t->Update_Image((*reinterpret_cast< Mat*(*)>(_a[1]))); break;
        case 42: _t->Update_Image(); break;
        case 43: _t->Update_View(); break;
        case 44: { QString _r = _t->Save_Image_Dialog();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 45: { QString _r = _t->Save_Image_Dialog((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 46: { QString _r = _t->Save_Image();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 47: { QString _r = _t->Save_Image((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->Set_ViewerMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->Set_Transformation_Mode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->Set_Aspect_Mode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->Set_PlotType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->Set_VisTrafo_ActiveInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->Set_VisTrafo_ActiveInt(); break;
        case 54: _t->Set_VisTrafo_ActiveBool((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->Set_VisTrafo_ActiveBool(); break;
        case 56: _t->Set_VisTrafo_Gamma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 57: _t->Set_VisTrafo_Gamma(); break;
        case 58: _t->Set_VisTrafo_SpreadInMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 59: _t->Set_VisTrafo_SpreadInMin(); break;
        case 60: _t->Set_VisTrafo_SpreadInMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 61: _t->Set_VisTrafo_SpreadInMax(); break;
        case 62: _t->Set_VisTrafo_Center((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 63: _t->Set_VisTrafo_Center(); break;
        case 64: _t->Set_VisTrafo_Divisor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 65: _t->Set_VisTrafo_Divisor(); break;
        case 66: _t->Set_VisTrafo_Anchor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 67: _t->Set_VisTrafo_Anchor(); break;
        case 68: _t->Set_VisTrafo_Range((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 69: _t->Set_VisTrafo_Range(); break;
        case 70: _t->Set_VisTrafo_Mode_Crop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->Set_VisTrafo_Mode_Crop(); break;
        case 72: _t->Set_VisTrafo_Mode_Trafo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: _t->Set_VisTrafo_Mode_Trafo(); break;
        case 74: _t->Set_VisTrafo_Mode_Anchor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 75: _t->Set_VisTrafo_Mode_Anchor(); break;
        case 76: _t->Set_VisTrafo_Mode_Range((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->Set_VisTrafo_Mode_Range(); break;
        case 78: _t->Set_VisTrafo_Mode_Complex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 79: _t->Set_VisTrafo_Mode_Complex(); break;
        case 80: _t->Set_Zomm((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 81: _t->Set_ZoomReset(); break;
        case 82: _t->MouseMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 83: _t->MouseClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 84: _t->MouseClicked_Left((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 85: _t->MouseClicked_Right((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 86: _t->MouseClicked_Mid((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
    }
}

QT_INIT_METAOBJECT const QMetaObject D_Viewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
        if (_id < 87)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 87;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 87)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 87;
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void D_Viewer::MouseMoved_Pos(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void D_Viewer::MouseMoved_Value(vector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void D_Viewer::MouseMoved_Value(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void D_Viewer::MouseClickedLeft_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void D_Viewer::MouseClickedRight_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void D_Viewer::MouseClickedMid_Pos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void D_Viewer::MouseClicked_Pos(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void D_Viewer::MouseClicked_Value(vector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void D_Viewer::MouseClicked_Value(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void D_Viewer::Image_Size_Changed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void D_Viewer::Scaled_Factor(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void D_Viewer::Scaled_Factor_Prz(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void D_Viewer::Zoomed(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void D_Viewer::Time_Image_Cvt(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
