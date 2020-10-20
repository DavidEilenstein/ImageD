/****************************************************************************
** Meta object code from reading C++ file 'd_stepwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Code/d_stepwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'd_stepwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_D_StepWindow_t {
    QByteArrayData data[185];
    char stringdata0[4763];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_D_StepWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_D_StepWindow_t qt_meta_stringdata_D_StepWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "D_StepWindow"
QT_MOC_LITERAL(1, 13, 19), // "ViewPlanePosChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "vector<int>"
QT_MOC_LITERAL(4, 46, 15), // "ViewZoomChanged"
QT_MOC_LITERAL(5, 62, 5), // "x_rel"
QT_MOC_LITERAL(6, 68, 5), // "y_rel"
QT_MOC_LITERAL(7, 74, 6), // "factor"
QT_MOC_LITERAL(8, 81, 5), // "plane"
QT_MOC_LITERAL(9, 87, 9), // "Update_Ui"
QT_MOC_LITERAL(10, 97, 18), // "Update_from_extern"
QT_MOC_LITERAL(11, 116, 15), // "set_need_Update"
QT_MOC_LITERAL(12, 132, 11), // "update_need"
QT_MOC_LITERAL(13, 144, 19), // "set_ClosingPossible"
QT_MOC_LITERAL(14, 164, 9), // "closeable"
QT_MOC_LITERAL(15, 174, 13), // "set_chain_pos"
QT_MOC_LITERAL(16, 188, 3), // "pos"
QT_MOC_LITERAL(17, 192, 16), // "set_ViewPlanePos"
QT_MOC_LITERAL(18, 209, 12), // "set_ViewZoom"
QT_MOC_LITERAL(19, 222, 12), // "needs_Update"
QT_MOC_LITERAL(20, 235, 7), // "sources"
QT_MOC_LITERAL(21, 243, 13), // "vector<uint>*"
QT_MOC_LITERAL(22, 257, 12), // "destinations"
QT_MOC_LITERAL(23, 270, 15), // "add_destination"
QT_MOC_LITERAL(24, 286, 4), // "dest"
QT_MOC_LITERAL(25, 291, 15), // "pop_destination"
QT_MOC_LITERAL(26, 307, 17), // "Update_Chain_Info"
QT_MOC_LITERAL(27, 325, 14), // "update_sources"
QT_MOC_LITERAL(28, 340, 17), // "get_root_toUpdate"
QT_MOC_LITERAL(29, 358, 18), // "get_pQI_Step_Image"
QT_MOC_LITERAL(30, 377, 7), // "QImage*"
QT_MOC_LITERAL(31, 385, 18), // "Update_Source_Info"
QT_MOC_LITERAL(32, 404, 10), // "Save_Steps"
QT_MOC_LITERAL(33, 415, 5), // "QDir*"
QT_MOC_LITERAL(34, 421, 8), // "dir_save"
QT_MOC_LITERAL(35, 430, 9), // "ofstream*"
QT_MOC_LITERAL(36, 440, 9), // "os_stream"
QT_MOC_LITERAL(37, 450, 9), // "get_Title"
QT_MOC_LITERAL(38, 460, 12), // "Update_Image"
QT_MOC_LITERAL(39, 473, 11), // "Update_View"
QT_MOC_LITERAL(40, 485, 15), // "Update_Img_Proc"
QT_MOC_LITERAL(41, 501, 20), // "Update_ParameterList"
QT_MOC_LITERAL(42, 522, 11), // "Update_Hist"
QT_MOC_LITERAL(43, 534, 12), // "Update_Title"
QT_MOC_LITERAL(44, 547, 24), // "Update_Type_Descriptions"
QT_MOC_LITERAL(45, 572, 21), // "Update_Source_Preview"
QT_MOC_LITERAL(46, 594, 19), // "Update_Descriptions"
QT_MOC_LITERAL(47, 614, 19), // "Update_HistSettings"
QT_MOC_LITERAL(48, 634, 29), // "Update_vSources_vDestinations"
QT_MOC_LITERAL(49, 664, 24), // "Update_Destinations_Info"
QT_MOC_LITERAL(50, 689, 17), // "Update_Range_Info"
QT_MOC_LITERAL(51, 707, 16), // "Update_Size_Info"
QT_MOC_LITERAL(52, 724, 12), // "Update_Times"
QT_MOC_LITERAL(53, 737, 19), // "Update_Time_Img_Cvt"
QT_MOC_LITERAL(54, 757, 1), // "t"
QT_MOC_LITERAL(55, 759, 23), // "Update_Time_View_Update"
QT_MOC_LITERAL(56, 783, 13), // "Dim_GetFromVD"
QT_MOC_LITERAL(57, 797, 18), // "ProcDimCountFromUi"
QT_MOC_LITERAL(58, 816, 19), // "ProcDimCountAdaptUi"
QT_MOC_LITERAL(59, 836, 27), // "Emitter_ViewPlanePosChanged"
QT_MOC_LITERAL(60, 864, 23), // "Emitter_ViewZoomChanged"
QT_MOC_LITERAL(61, 888, 15), // "Save_Image_Step"
QT_MOC_LITERAL(62, 904, 19), // "Save_ImageList_Step"
QT_MOC_LITERAL(63, 924, 11), // "Save_VisDat"
QT_MOC_LITERAL(64, 936, 20), // "Save_Screenshot_Step"
QT_MOC_LITERAL(65, 957, 17), // "Save_Feature_List"
QT_MOC_LITERAL(66, 975, 13), // "Save_Analysis"
QT_MOC_LITERAL(67, 989, 33), // "Connect_HistSettings_2_Update..."
QT_MOC_LITERAL(68, 1023, 3), // "con"
QT_MOC_LITERAL(69, 1027, 35), // "Connect_TimesSettings_2_Updat..."
QT_MOC_LITERAL(70, 1063, 39), // "Connect_ImgProcSettings_2_Upd..."
QT_MOC_LITERAL(71, 1103, 18), // "Connect_OtherSteps"
QT_MOC_LITERAL(72, 1122, 14), // "Activate_Makro"
QT_MOC_LITERAL(73, 1137, 18), // "CO_Depth_Set_Range"
QT_MOC_LITERAL(74, 1156, 4), // "prec"
QT_MOC_LITERAL(75, 1161, 3), // "min"
QT_MOC_LITERAL(76, 1165, 3), // "max"
QT_MOC_LITERAL(77, 1169, 19), // "FI_General_Adapt_Ui"
QT_MOC_LITERAL(78, 1189, 5), // "index"
QT_MOC_LITERAL(79, 1195, 16), // "FI_Blur_Adapt_Ui"
QT_MOC_LITERAL(80, 1212, 16), // "FI_Edge_Adapt_Ui"
QT_MOC_LITERAL(81, 1229, 16), // "FI_Spec_Adapt_Ui"
QT_MOC_LITERAL(82, 1246, 21), // "FI_Function_RandomAll"
QT_MOC_LITERAL(83, 1268, 26), // "FI_Function_RandomFunction"
QT_MOC_LITERAL(84, 1295, 28), // "FI_Function_RandomParameters"
QT_MOC_LITERAL(85, 1324, 16), // "MA_1Img_Adapt_Ui"
QT_MOC_LITERAL(86, 1341, 16), // "MA_2Img_Adapt_Ui"
QT_MOC_LITERAL(87, 1358, 29), // "AdaptUi_SourceNumber_ProcDims"
QT_MOC_LITERAL(88, 1388, 26), // "ViewerPlanePosChange_Block"
QT_MOC_LITERAL(89, 1415, 5), // "block"
QT_MOC_LITERAL(90, 1421, 15), // "Populate_CB_All"
QT_MOC_LITERAL(91, 1437, 18), // "Populate_CB_Single"
QT_MOC_LITERAL(92, 1456, 10), // "QComboBox*"
QT_MOC_LITERAL(93, 1467, 2), // "CB"
QT_MOC_LITERAL(94, 1470, 3), // "QSL"
QT_MOC_LITERAL(95, 1474, 10), // "init_index"
QT_MOC_LITERAL(96, 1485, 22), // "Populate_CB_Statistics"
QT_MOC_LITERAL(97, 1508, 20), // "Populate_CB_Features"
QT_MOC_LITERAL(98, 1529, 22), // "Populate_CB_Geometrics"
QT_MOC_LITERAL(99, 1552, 16), // "Populate_CB_Math"
QT_MOC_LITERAL(100, 1569, 18), // "Populate_CB_Planes"
QT_MOC_LITERAL(101, 1588, 16), // "Populate_CB_Dims"
QT_MOC_LITERAL(102, 1605, 21), // "Populate_CB_LoadModes"
QT_MOC_LITERAL(103, 1627, 22), // "Populate_CB_Color2Mono"
QT_MOC_LITERAL(104, 1650, 20), // "Populate_CB_CompDist"
QT_MOC_LITERAL(105, 1671, 20), // "Populate_CB_VisTrafo"
QT_MOC_LITERAL(106, 1692, 17), // "Populate_CB_Other"
QT_MOC_LITERAL(107, 1710, 22), // "Test_Feature_Visualize"
QT_MOC_LITERAL(108, 1733, 17), // "Measure_SaveClick"
QT_MOC_LITERAL(109, 1751, 1), // "x"
QT_MOC_LITERAL(110, 1753, 1), // "y"
QT_MOC_LITERAL(111, 1755, 20), // "Measure_LineDistance"
QT_MOC_LITERAL(112, 1776, 36), // "on_spinBox_Source_Pos_1_value..."
QT_MOC_LITERAL(113, 1813, 4), // "arg1"
QT_MOC_LITERAL(114, 1818, 36), // "on_spinBox_Source_Pos_2_value..."
QT_MOC_LITERAL(115, 1855, 36), // "on_spinBox_Source_Pos_3_value..."
QT_MOC_LITERAL(116, 1892, 36), // "on_spinBox_Source_Pos_4_value..."
QT_MOC_LITERAL(117, 1929, 44), // "on_comboBox_00_Load_Mode_curr..."
QT_MOC_LITERAL(118, 1974, 45), // "on_comboBox_02_Depth_Type_cur..."
QT_MOC_LITERAL(119, 2020, 46), // "on_comboBox_Type_04_Filter_cu..."
QT_MOC_LITERAL(120, 2067, 34), // "on_spinBox_04_Edge_dX_valueCh..."
QT_MOC_LITERAL(121, 2102, 34), // "on_spinBox_04_Edge_dY_valueCh..."
QT_MOC_LITERAL(122, 2137, 34), // "on_tabWidget_Output_currentCh..."
QT_MOC_LITERAL(123, 2172, 35), // "on_pushButton_00_Load_Image_c..."
QT_MOC_LITERAL(124, 2208, 17), // "Scan_Examples_Dir"
QT_MOC_LITERAL(125, 2226, 41), // "on_spinBox_02_Merge_Channels_..."
QT_MOC_LITERAL(126, 2268, 42), // "on_checkBox_07_Watershed_Auto..."
QT_MOC_LITERAL(127, 2311, 32), // "on_action_Change_Title_triggered"
QT_MOC_LITERAL(128, 2344, 7), // "checked"
QT_MOC_LITERAL(129, 2352, 48), // "on_pushButton_00_Sample_Selec..."
QT_MOC_LITERAL(130, 2401, 55), // "on_comboBox_03_GrabColor_Colo..."
QT_MOC_LITERAL(131, 2457, 45), // "on_doubleSpinBox_01_Crop_Rect..."
QT_MOC_LITERAL(132, 2503, 45), // "on_doubleSpinBox_01_Crop_Rect..."
QT_MOC_LITERAL(133, 2549, 45), // "on_doubleSpinBox_01_Crop_Rect..."
QT_MOC_LITERAL(134, 2595, 45), // "on_doubleSpinBox_01_Crop_Rect..."
QT_MOC_LITERAL(135, 2641, 19), // "block_signals_thres"
QT_MOC_LITERAL(136, 2661, 47), // "on_doubleSpinBox_03_Thres_Rel..."
QT_MOC_LITERAL(137, 2709, 52), // "on_doubleSpinBox_03_Thres_Rel..."
QT_MOC_LITERAL(138, 2762, 53), // "on_doubleSpinBox_03_Thres_Rel..."
QT_MOC_LITERAL(139, 2816, 56), // "on_horizontalSlider_03_Thres_..."
QT_MOC_LITERAL(140, 2873, 5), // "value"
QT_MOC_LITERAL(141, 2879, 45), // "on_comboBox_03_Thres_Type_cur..."
QT_MOC_LITERAL(142, 2925, 44), // "on_doubleSpinBox_08_Select_St..."
QT_MOC_LITERAL(143, 2970, 42), // "on_spinBox_08_Select_Decimals..."
QT_MOC_LITERAL(144, 3013, 42), // "on_spinBox_04_Edge_Thresh_Low..."
QT_MOC_LITERAL(145, 3056, 43), // "on_spinBox_04_Edge_Thresh_Hig..."
QT_MOC_LITERAL(146, 3100, 37), // "on_pushButton_00_CastRaw_Path..."
QT_MOC_LITERAL(147, 3138, 37), // "on_spinBox_10_Crop_Min_X_valu..."
QT_MOC_LITERAL(148, 3176, 37), // "on_spinBox_10_Crop_Min_Y_valu..."
QT_MOC_LITERAL(149, 3214, 37), // "on_spinBox_10_Crop_Min_Z_valu..."
QT_MOC_LITERAL(150, 3252, 37), // "on_spinBox_10_Crop_Min_T_valu..."
QT_MOC_LITERAL(151, 3290, 37), // "on_spinBox_10_Crop_Min_S_valu..."
QT_MOC_LITERAL(152, 3328, 37), // "on_spinBox_10_Crop_Min_P_valu..."
QT_MOC_LITERAL(153, 3366, 37), // "on_spinBox_10_Crop_Max_X_valu..."
QT_MOC_LITERAL(154, 3404, 37), // "on_spinBox_10_Crop_Max_Y_valu..."
QT_MOC_LITERAL(155, 3442, 37), // "on_spinBox_10_Crop_Max_Z_valu..."
QT_MOC_LITERAL(156, 3480, 37), // "on_spinBox_10_Crop_Max_T_valu..."
QT_MOC_LITERAL(157, 3518, 37), // "on_spinBox_10_Crop_Max_S_valu..."
QT_MOC_LITERAL(158, 3556, 37), // "on_spinBox_10_Crop_Max_P_valu..."
QT_MOC_LITERAL(159, 3594, 50), // "on_comboBox_05_Elem_Morph_Typ..."
QT_MOC_LITERAL(160, 3645, 47), // "on_spinBox_00_VideoStream_T_O..."
QT_MOC_LITERAL(161, 3693, 48), // "on_spinBox_00_VideoStream_T1_..."
QT_MOC_LITERAL(162, 3742, 48), // "on_spinBox_00_VideoStream_T2_..."
QT_MOC_LITERAL(163, 3791, 43), // "on_pushButton_00_VideoStream_..."
QT_MOC_LITERAL(164, 3835, 42), // "on_comboBox_View_Plane_curren..."
QT_MOC_LITERAL(165, 3878, 54), // "on_comboBox_08_FeatContextVal..."
QT_MOC_LITERAL(166, 3933, 57), // "on_comboBox_08_FeatContextSel..."
QT_MOC_LITERAL(167, 3991, 33), // "on_checkBox_06_4Img_Value_cli..."
QT_MOC_LITERAL(168, 4025, 33), // "on_checkBox_06_3Img_Value_cli..."
QT_MOC_LITERAL(169, 4059, 44), // "on_comboBox_06_3Img_Type_curr..."
QT_MOC_LITERAL(170, 4104, 44), // "on_comboBox_06_4Img_Type_curr..."
QT_MOC_LITERAL(171, 4149, 38), // "on_checkBox_09_HDR_Thresh_sta..."
QT_MOC_LITERAL(172, 4188, 39), // "on_checkBox_09_HDR_Project_st..."
QT_MOC_LITERAL(173, 4228, 47), // "on_doubleSpinBox_09_HDR_Thres..."
QT_MOC_LITERAL(174, 4276, 48), // "on_doubleSpinBox_09_HDR_Thres..."
QT_MOC_LITERAL(175, 4325, 51), // "on_checkBox_07_Fourier_Output..."
QT_MOC_LITERAL(176, 4377, 41), // "on_comboBox_View_Crop_current..."
QT_MOC_LITERAL(177, 4419, 46), // "on_comboBox_View_Transform_cu..."
QT_MOC_LITERAL(178, 4466, 43), // "on_comboBox_View_Anchor_curre..."
QT_MOC_LITERAL(179, 4510, 42), // "on_comboBox_View_Range_curren..."
QT_MOC_LITERAL(180, 4553, 38), // "on_checkBox_View_VisTrafo_sta..."
QT_MOC_LITERAL(181, 4592, 38), // "on_doubleSpinBox_View_Min_val..."
QT_MOC_LITERAL(182, 4631, 38), // "on_doubleSpinBox_View_Max_val..."
QT_MOC_LITERAL(183, 4670, 47), // "on_radioButton_09_RelationSta..."
QT_MOC_LITERAL(184, 4718, 44) // "on_radioButton_09_RelationSta..."

    },
    "D_StepWindow\0ViewPlanePosChanged\0\0"
    "vector<int>\0ViewZoomChanged\0x_rel\0"
    "y_rel\0factor\0plane\0Update_Ui\0"
    "Update_from_extern\0set_need_Update\0"
    "update_need\0set_ClosingPossible\0"
    "closeable\0set_chain_pos\0pos\0"
    "set_ViewPlanePos\0set_ViewZoom\0"
    "needs_Update\0sources\0vector<uint>*\0"
    "destinations\0add_destination\0dest\0"
    "pop_destination\0Update_Chain_Info\0"
    "update_sources\0get_root_toUpdate\0"
    "get_pQI_Step_Image\0QImage*\0"
    "Update_Source_Info\0Save_Steps\0QDir*\0"
    "dir_save\0ofstream*\0os_stream\0get_Title\0"
    "Update_Image\0Update_View\0Update_Img_Proc\0"
    "Update_ParameterList\0Update_Hist\0"
    "Update_Title\0Update_Type_Descriptions\0"
    "Update_Source_Preview\0Update_Descriptions\0"
    "Update_HistSettings\0Update_vSources_vDestinations\0"
    "Update_Destinations_Info\0Update_Range_Info\0"
    "Update_Size_Info\0Update_Times\0"
    "Update_Time_Img_Cvt\0t\0Update_Time_View_Update\0"
    "Dim_GetFromVD\0ProcDimCountFromUi\0"
    "ProcDimCountAdaptUi\0Emitter_ViewPlanePosChanged\0"
    "Emitter_ViewZoomChanged\0Save_Image_Step\0"
    "Save_ImageList_Step\0Save_VisDat\0"
    "Save_Screenshot_Step\0Save_Feature_List\0"
    "Save_Analysis\0Connect_HistSettings_2_UpdateHist\0"
    "con\0Connect_TimesSettings_2_UpdateTimes\0"
    "Connect_ImgProcSettings_2_UpdateImgProc\0"
    "Connect_OtherSteps\0Activate_Makro\0"
    "CO_Depth_Set_Range\0prec\0min\0max\0"
    "FI_General_Adapt_Ui\0index\0FI_Blur_Adapt_Ui\0"
    "FI_Edge_Adapt_Ui\0FI_Spec_Adapt_Ui\0"
    "FI_Function_RandomAll\0FI_Function_RandomFunction\0"
    "FI_Function_RandomParameters\0"
    "MA_1Img_Adapt_Ui\0MA_2Img_Adapt_Ui\0"
    "AdaptUi_SourceNumber_ProcDims\0"
    "ViewerPlanePosChange_Block\0block\0"
    "Populate_CB_All\0Populate_CB_Single\0"
    "QComboBox*\0CB\0QSL\0init_index\0"
    "Populate_CB_Statistics\0Populate_CB_Features\0"
    "Populate_CB_Geometrics\0Populate_CB_Math\0"
    "Populate_CB_Planes\0Populate_CB_Dims\0"
    "Populate_CB_LoadModes\0Populate_CB_Color2Mono\0"
    "Populate_CB_CompDist\0Populate_CB_VisTrafo\0"
    "Populate_CB_Other\0Test_Feature_Visualize\0"
    "Measure_SaveClick\0x\0y\0Measure_LineDistance\0"
    "on_spinBox_Source_Pos_1_valueChanged\0"
    "arg1\0on_spinBox_Source_Pos_2_valueChanged\0"
    "on_spinBox_Source_Pos_3_valueChanged\0"
    "on_spinBox_Source_Pos_4_valueChanged\0"
    "on_comboBox_00_Load_Mode_currentIndexChanged\0"
    "on_comboBox_02_Depth_Type_currentIndexChanged\0"
    "on_comboBox_Type_04_Filter_currentIndexChanged\0"
    "on_spinBox_04_Edge_dX_valueChanged\0"
    "on_spinBox_04_Edge_dY_valueChanged\0"
    "on_tabWidget_Output_currentChanged\0"
    "on_pushButton_00_Load_Image_clicked\0"
    "Scan_Examples_Dir\0"
    "on_spinBox_02_Merge_Channels_valueChanged\0"
    "on_checkBox_07_Watershed_Auto_stateChanged\0"
    "on_action_Change_Title_triggered\0"
    "checked\0on_pushButton_00_Sample_Select_Directory_clicked\0"
    "on_comboBox_03_GrabColor_ColorSpace_currentIndexChanged\0"
    "on_doubleSpinBox_01_Crop_Rect_X1_valueChanged\0"
    "on_doubleSpinBox_01_Crop_Rect_Y1_valueChanged\0"
    "on_doubleSpinBox_01_Crop_Rect_X2_valueChanged\0"
    "on_doubleSpinBox_01_Crop_Rect_Y2_valueChanged\0"
    "block_signals_thres\0"
    "on_doubleSpinBox_03_Thres_Rel_Base_valueChanged\0"
    "on_doubleSpinBox_03_Thres_Rel_Thres_Rel_valueChanged\0"
    "on_doubleSpinBox_03_Thres_Rel_Thresh_Abs_valueChanged\0"
    "on_horizontalSlider_03_Thres_Rel_Thresh_Rel_valueChanged\0"
    "value\0on_comboBox_03_Thres_Type_currentIndexChanged\0"
    "on_doubleSpinBox_08_Select_Step_valueChanged\0"
    "on_spinBox_08_Select_Decimals_valueChanged\0"
    "on_spinBox_04_Edge_Thresh_Low_valueChanged\0"
    "on_spinBox_04_Edge_Thresh_High_valueChanged\0"
    "on_pushButton_00_CastRaw_Path_clicked\0"
    "on_spinBox_10_Crop_Min_X_valueChanged\0"
    "on_spinBox_10_Crop_Min_Y_valueChanged\0"
    "on_spinBox_10_Crop_Min_Z_valueChanged\0"
    "on_spinBox_10_Crop_Min_T_valueChanged\0"
    "on_spinBox_10_Crop_Min_S_valueChanged\0"
    "on_spinBox_10_Crop_Min_P_valueChanged\0"
    "on_spinBox_10_Crop_Max_X_valueChanged\0"
    "on_spinBox_10_Crop_Max_Y_valueChanged\0"
    "on_spinBox_10_Crop_Max_Z_valueChanged\0"
    "on_spinBox_10_Crop_Max_T_valueChanged\0"
    "on_spinBox_10_Crop_Max_S_valueChanged\0"
    "on_spinBox_10_Crop_Max_P_valueChanged\0"
    "on_comboBox_05_Elem_Morph_Type_currentIndexChanged\0"
    "on_spinBox_00_VideoStream_T_Offset_valueChanged\0"
    "on_spinBox_00_VideoStream_T1_Frames_valueChanged\0"
    "on_spinBox_00_VideoStream_T2_Frames_valueChanged\0"
    "on_pushButton_00_VideoStream_Browse_clicked\0"
    "on_comboBox_View_Plane_currentIndexChanged\0"
    "on_comboBox_08_FeatContextVal_Stat_currentIndexChanged\0"
    "on_comboBox_08_FeatContextSelect_Stat_currentIndexChanged\0"
    "on_checkBox_06_4Img_Value_clicked\0"
    "on_checkBox_06_3Img_Value_clicked\0"
    "on_comboBox_06_3Img_Type_currentIndexChanged\0"
    "on_comboBox_06_4Img_Type_currentIndexChanged\0"
    "on_checkBox_09_HDR_Thresh_stateChanged\0"
    "on_checkBox_09_HDR_Project_stateChanged\0"
    "on_doubleSpinBox_09_HDR_Thresh_Low_valueChanged\0"
    "on_doubleSpinBox_09_HDR_Thresh_High_valueChanged\0"
    "on_checkBox_07_Fourier_Output_RealOnly_stateChanged\0"
    "on_comboBox_View_Crop_currentIndexChanged\0"
    "on_comboBox_View_Transform_currentIndexChanged\0"
    "on_comboBox_View_Anchor_currentIndexChanged\0"
    "on_comboBox_View_Range_currentIndexChanged\0"
    "on_checkBox_View_VisTrafo_stateChanged\0"
    "on_doubleSpinBox_View_Min_valueChanged\0"
    "on_doubleSpinBox_View_Max_valueChanged\0"
    "on_radioButton_09_RelationStat_Distance_clicked\0"
    "on_radioButton_09_RelationStat_Angle_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_D_StepWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     152,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  774,    2, 0x06 /* Public */,
       4,    4,  777,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  786,    2, 0x0a /* Public */,
      10,    0,  787,    2, 0x0a /* Public */,
      11,    1,  788,    2, 0x0a /* Public */,
      13,    1,  791,    2, 0x0a /* Public */,
      15,    1,  794,    2, 0x0a /* Public */,
      17,    1,  797,    2, 0x0a /* Public */,
      18,    4,  800,    2, 0x0a /* Public */,
      19,    0,  809,    2, 0x0a /* Public */,
      20,    0,  810,    2, 0x0a /* Public */,
      22,    0,  811,    2, 0x0a /* Public */,
      23,    1,  812,    2, 0x0a /* Public */,
      25,    1,  815,    2, 0x0a /* Public */,
      26,    1,  818,    2, 0x0a /* Public */,
      28,    0,  821,    2, 0x0a /* Public */,
      29,    0,  822,    2, 0x0a /* Public */,
      31,    0,  823,    2, 0x0a /* Public */,
      32,    2,  824,    2, 0x0a /* Public */,
      37,    0,  829,    2, 0x0a /* Public */,
      38,    0,  830,    2, 0x08 /* Private */,
      39,    0,  831,    2, 0x08 /* Private */,
      40,    0,  832,    2, 0x08 /* Private */,
      41,    0,  833,    2, 0x08 /* Private */,
      42,    0,  834,    2, 0x08 /* Private */,
      43,    0,  835,    2, 0x08 /* Private */,
      44,    0,  836,    2, 0x08 /* Private */,
      45,    0,  837,    2, 0x08 /* Private */,
      46,    0,  838,    2, 0x08 /* Private */,
      47,    0,  839,    2, 0x08 /* Private */,
      48,    0,  840,    2, 0x08 /* Private */,
      49,    0,  841,    2, 0x08 /* Private */,
      50,    0,  842,    2, 0x08 /* Private */,
      51,    0,  843,    2, 0x08 /* Private */,
      52,    0,  844,    2, 0x08 /* Private */,
      53,    1,  845,    2, 0x08 /* Private */,
      55,    1,  848,    2, 0x08 /* Private */,
      56,    0,  851,    2, 0x08 /* Private */,
      57,    0,  852,    2, 0x08 /* Private */,
      58,    0,  853,    2, 0x08 /* Private */,
      59,    0,  854,    2, 0x08 /* Private */,
      60,    0,  855,    2, 0x08 /* Private */,
      61,    0,  856,    2, 0x08 /* Private */,
      62,    0,  857,    2, 0x08 /* Private */,
      63,    0,  858,    2, 0x08 /* Private */,
      64,    0,  859,    2, 0x08 /* Private */,
      65,    0,  860,    2, 0x08 /* Private */,
      66,    0,  861,    2, 0x08 /* Private */,
      67,    1,  862,    2, 0x08 /* Private */,
      69,    1,  865,    2, 0x08 /* Private */,
      70,    1,  868,    2, 0x08 /* Private */,
      71,    0,  871,    2, 0x08 /* Private */,
      72,    0,  872,    2, 0x08 /* Private */,
      73,    3,  873,    2, 0x08 /* Private */,
      77,    1,  880,    2, 0x08 /* Private */,
      79,    1,  883,    2, 0x08 /* Private */,
      80,    1,  886,    2, 0x08 /* Private */,
      81,    1,  889,    2, 0x08 /* Private */,
      82,    0,  892,    2, 0x08 /* Private */,
      83,    0,  893,    2, 0x08 /* Private */,
      84,    0,  894,    2, 0x08 /* Private */,
      85,    1,  895,    2, 0x08 /* Private */,
      86,    1,  898,    2, 0x08 /* Private */,
      87,    0,  901,    2, 0x08 /* Private */,
      88,    1,  902,    2, 0x08 /* Private */,
      90,    0,  905,    2, 0x08 /* Private */,
      91,    3,  906,    2, 0x08 /* Private */,
      91,    2,  913,    2, 0x28 /* Private | MethodCloned */,
      96,    0,  918,    2, 0x08 /* Private */,
      97,    0,  919,    2, 0x08 /* Private */,
      98,    0,  920,    2, 0x08 /* Private */,
      99,    0,  921,    2, 0x08 /* Private */,
     100,    0,  922,    2, 0x08 /* Private */,
     101,    0,  923,    2, 0x08 /* Private */,
     102,    0,  924,    2, 0x08 /* Private */,
     103,    0,  925,    2, 0x08 /* Private */,
     104,    0,  926,    2, 0x08 /* Private */,
     105,    0,  927,    2, 0x08 /* Private */,
     106,    0,  928,    2, 0x08 /* Private */,
     107,    0,  929,    2, 0x08 /* Private */,
     108,    2,  930,    2, 0x08 /* Private */,
     111,    0,  935,    2, 0x08 /* Private */,
     112,    1,  936,    2, 0x08 /* Private */,
     114,    1,  939,    2, 0x08 /* Private */,
     115,    1,  942,    2, 0x08 /* Private */,
     116,    1,  945,    2, 0x08 /* Private */,
     117,    1,  948,    2, 0x08 /* Private */,
     118,    1,  951,    2, 0x08 /* Private */,
     119,    1,  954,    2, 0x08 /* Private */,
     120,    1,  957,    2, 0x08 /* Private */,
     121,    1,  960,    2, 0x08 /* Private */,
     122,    1,  963,    2, 0x08 /* Private */,
     123,    0,  966,    2, 0x08 /* Private */,
     124,    0,  967,    2, 0x08 /* Private */,
     125,    1,  968,    2, 0x08 /* Private */,
     126,    1,  971,    2, 0x08 /* Private */,
     127,    1,  974,    2, 0x08 /* Private */,
     129,    0,  977,    2, 0x08 /* Private */,
     130,    1,  978,    2, 0x08 /* Private */,
     131,    1,  981,    2, 0x08 /* Private */,
     132,    1,  984,    2, 0x08 /* Private */,
     133,    1,  987,    2, 0x08 /* Private */,
     134,    1,  990,    2, 0x08 /* Private */,
     135,    1,  993,    2, 0x08 /* Private */,
     136,    1,  996,    2, 0x08 /* Private */,
     137,    1,  999,    2, 0x08 /* Private */,
     138,    1, 1002,    2, 0x08 /* Private */,
     139,    1, 1005,    2, 0x08 /* Private */,
     141,    1, 1008,    2, 0x08 /* Private */,
     142,    1, 1011,    2, 0x08 /* Private */,
     143,    1, 1014,    2, 0x08 /* Private */,
     144,    1, 1017,    2, 0x08 /* Private */,
     145,    1, 1020,    2, 0x08 /* Private */,
     146,    0, 1023,    2, 0x08 /* Private */,
     147,    1, 1024,    2, 0x08 /* Private */,
     148,    1, 1027,    2, 0x08 /* Private */,
     149,    1, 1030,    2, 0x08 /* Private */,
     150,    1, 1033,    2, 0x08 /* Private */,
     151,    1, 1036,    2, 0x08 /* Private */,
     152,    1, 1039,    2, 0x08 /* Private */,
     153,    1, 1042,    2, 0x08 /* Private */,
     154,    1, 1045,    2, 0x08 /* Private */,
     155,    1, 1048,    2, 0x08 /* Private */,
     156,    1, 1051,    2, 0x08 /* Private */,
     157,    1, 1054,    2, 0x08 /* Private */,
     158,    1, 1057,    2, 0x08 /* Private */,
     159,    1, 1060,    2, 0x08 /* Private */,
     160,    1, 1063,    2, 0x08 /* Private */,
     161,    1, 1066,    2, 0x08 /* Private */,
     162,    1, 1069,    2, 0x08 /* Private */,
     163,    0, 1072,    2, 0x08 /* Private */,
     164,    1, 1073,    2, 0x08 /* Private */,
     165,    1, 1076,    2, 0x08 /* Private */,
     166,    1, 1079,    2, 0x08 /* Private */,
     167,    1, 1082,    2, 0x08 /* Private */,
     168,    1, 1085,    2, 0x08 /* Private */,
     169,    1, 1088,    2, 0x08 /* Private */,
     170,    1, 1091,    2, 0x08 /* Private */,
     171,    1, 1094,    2, 0x08 /* Private */,
     172,    1, 1097,    2, 0x08 /* Private */,
     173,    1, 1100,    2, 0x08 /* Private */,
     174,    1, 1103,    2, 0x08 /* Private */,
     175,    1, 1106,    2, 0x08 /* Private */,
     176,    1, 1109,    2, 0x08 /* Private */,
     177,    1, 1112,    2, 0x08 /* Private */,
     178,    1, 1115,    2, 0x08 /* Private */,
     179,    1, 1118,    2, 0x08 /* Private */,
     180,    1, 1121,    2, 0x08 /* Private */,
     181,    1, 1124,    2, 0x08 /* Private */,
     182,    1, 1127,    2, 0x08 /* Private */,
     183,    1, 1130,    2, 0x08 /* Private */,
     184,    1, 1133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::UInt,   16,
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Bool,
    0x80000000 | 21,
    0x80000000 | 21,
    QMetaType::Void, QMetaType::UInt,   24,
    QMetaType::Void, QMetaType::UInt,   24,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::UInt,
    0x80000000 | 30,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33, 0x80000000 | 35,   34,   36,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   54,
    QMetaType::Void, QMetaType::UInt,   54,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,   74,   75,   76,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   89,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 92, QMetaType::QStringList, QMetaType::Int,   93,   94,   95,
    QMetaType::Void, 0x80000000 | 92, QMetaType::QStringList,   93,   94,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  109,  110,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Bool,  128,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Bool,   89,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Int,  140,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Bool,  128,
    QMetaType::Void, QMetaType::Bool,  128,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Bool,  128,
    QMetaType::Void, QMetaType::Bool,  128,

       0        // eod
};

void D_StepWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<D_StepWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ViewPlanePosChanged((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 1: _t->ViewZoomChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->Update_Ui(); break;
        case 3: _t->Update_from_extern(); break;
        case 4: _t->set_need_Update((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->set_ClosingPossible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->set_chain_pos((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->set_ViewPlanePos((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 8: _t->set_ViewZoom((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 9: { bool _r = _t->needs_Update();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { vector<uint>* _r = _t->sources();
            if (_a[0]) *reinterpret_cast< vector<uint>**>(_a[0]) = std::move(_r); }  break;
        case 11: { vector<uint>* _r = _t->destinations();
            if (_a[0]) *reinterpret_cast< vector<uint>**>(_a[0]) = std::move(_r); }  break;
        case 12: _t->add_destination((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: _t->pop_destination((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 14: _t->Update_Chain_Info((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: { uint _r = _t->get_root_toUpdate();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 16: { QImage* _r = _t->get_pQI_Step_Image();
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = std::move(_r); }  break;
        case 17: _t->Update_Source_Info(); break;
        case 18: _t->Save_Steps((*reinterpret_cast< QDir*(*)>(_a[1])),(*reinterpret_cast< ofstream*(*)>(_a[2]))); break;
        case 19: { QString _r = _t->get_Title();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->Update_Image(); break;
        case 21: _t->Update_View(); break;
        case 22: _t->Update_Img_Proc(); break;
        case 23: _t->Update_ParameterList(); break;
        case 24: _t->Update_Hist(); break;
        case 25: _t->Update_Title(); break;
        case 26: _t->Update_Type_Descriptions(); break;
        case 27: _t->Update_Source_Preview(); break;
        case 28: _t->Update_Descriptions(); break;
        case 29: _t->Update_HistSettings(); break;
        case 30: _t->Update_vSources_vDestinations(); break;
        case 31: _t->Update_Destinations_Info(); break;
        case 32: _t->Update_Range_Info(); break;
        case 33: _t->Update_Size_Info(); break;
        case 34: _t->Update_Times(); break;
        case 35: _t->Update_Time_Img_Cvt((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 36: _t->Update_Time_View_Update((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 37: _t->Dim_GetFromVD(); break;
        case 38: { int _r = _t->ProcDimCountFromUi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->ProcDimCountAdaptUi(); break;
        case 40: _t->Emitter_ViewPlanePosChanged(); break;
        case 41: _t->Emitter_ViewZoomChanged(); break;
        case 42: _t->Save_Image_Step(); break;
        case 43: _t->Save_ImageList_Step(); break;
        case 44: _t->Save_VisDat(); break;
        case 45: _t->Save_Screenshot_Step(); break;
        case 46: _t->Save_Feature_List(); break;
        case 47: _t->Save_Analysis(); break;
        case 48: _t->Connect_HistSettings_2_UpdateHist((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->Connect_TimesSettings_2_UpdateTimes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->Connect_ImgProcSettings_2_UpdateImgProc((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->Connect_OtherSteps(); break;
        case 52: _t->Activate_Makro(); break;
        case 53: _t->CO_Depth_Set_Range((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 54: _t->FI_General_Adapt_Ui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->FI_Blur_Adapt_Ui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->FI_Edge_Adapt_Ui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->FI_Spec_Adapt_Ui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->FI_Function_RandomAll(); break;
        case 59: _t->FI_Function_RandomFunction(); break;
        case 60: _t->FI_Function_RandomParameters(); break;
        case 61: _t->MA_1Img_Adapt_Ui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: _t->MA_2Img_Adapt_Ui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->AdaptUi_SourceNumber_ProcDims(); break;
        case 64: _t->ViewerPlanePosChange_Block((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 65: _t->Populate_CB_All(); break;
        case 66: _t->Populate_CB_Single((*reinterpret_cast< QComboBox*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 67: _t->Populate_CB_Single((*reinterpret_cast< QComboBox*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 68: _t->Populate_CB_Statistics(); break;
        case 69: _t->Populate_CB_Features(); break;
        case 70: _t->Populate_CB_Geometrics(); break;
        case 71: _t->Populate_CB_Math(); break;
        case 72: _t->Populate_CB_Planes(); break;
        case 73: _t->Populate_CB_Dims(); break;
        case 74: _t->Populate_CB_LoadModes(); break;
        case 75: _t->Populate_CB_Color2Mono(); break;
        case 76: _t->Populate_CB_CompDist(); break;
        case 77: _t->Populate_CB_VisTrafo(); break;
        case 78: _t->Populate_CB_Other(); break;
        case 79: _t->Test_Feature_Visualize(); break;
        case 80: _t->Measure_SaveClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 81: _t->Measure_LineDistance(); break;
        case 82: _t->on_spinBox_Source_Pos_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 83: _t->on_spinBox_Source_Pos_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 84: _t->on_spinBox_Source_Pos_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->on_spinBox_Source_Pos_4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 86: _t->on_comboBox_00_Load_Mode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 87: _t->on_comboBox_02_Depth_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 88: _t->on_comboBox_Type_04_Filter_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 89: _t->on_spinBox_04_Edge_dX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 90: _t->on_spinBox_04_Edge_dY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 91: _t->on_tabWidget_Output_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 92: _t->on_pushButton_00_Load_Image_clicked(); break;
        case 93: _t->Scan_Examples_Dir(); break;
        case 94: _t->on_spinBox_02_Merge_Channels_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 95: _t->on_checkBox_07_Watershed_Auto_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 96: _t->on_action_Change_Title_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 97: _t->on_pushButton_00_Sample_Select_Directory_clicked(); break;
        case 98: _t->on_comboBox_03_GrabColor_ColorSpace_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: _t->on_doubleSpinBox_01_Crop_Rect_X1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 100: _t->on_doubleSpinBox_01_Crop_Rect_Y1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 101: _t->on_doubleSpinBox_01_Crop_Rect_X2_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 102: _t->on_doubleSpinBox_01_Crop_Rect_Y2_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 103: _t->block_signals_thres((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 104: _t->on_doubleSpinBox_03_Thres_Rel_Base_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 105: _t->on_doubleSpinBox_03_Thres_Rel_Thres_Rel_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 106: _t->on_doubleSpinBox_03_Thres_Rel_Thresh_Abs_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 107: _t->on_horizontalSlider_03_Thres_Rel_Thresh_Rel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 108: _t->on_comboBox_03_Thres_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 109: _t->on_doubleSpinBox_08_Select_Step_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 110: _t->on_spinBox_08_Select_Decimals_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 111: _t->on_spinBox_04_Edge_Thresh_Low_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 112: _t->on_spinBox_04_Edge_Thresh_High_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 113: _t->on_pushButton_00_CastRaw_Path_clicked(); break;
        case 114: _t->on_spinBox_10_Crop_Min_X_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 115: _t->on_spinBox_10_Crop_Min_Y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 116: _t->on_spinBox_10_Crop_Min_Z_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 117: _t->on_spinBox_10_Crop_Min_T_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 118: _t->on_spinBox_10_Crop_Min_S_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 119: _t->on_spinBox_10_Crop_Min_P_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 120: _t->on_spinBox_10_Crop_Max_X_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 121: _t->on_spinBox_10_Crop_Max_Y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 122: _t->on_spinBox_10_Crop_Max_Z_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 123: _t->on_spinBox_10_Crop_Max_T_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 124: _t->on_spinBox_10_Crop_Max_S_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 125: _t->on_spinBox_10_Crop_Max_P_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 126: _t->on_comboBox_05_Elem_Morph_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 127: _t->on_spinBox_00_VideoStream_T_Offset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 128: _t->on_spinBox_00_VideoStream_T1_Frames_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 129: _t->on_spinBox_00_VideoStream_T2_Frames_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 130: _t->on_pushButton_00_VideoStream_Browse_clicked(); break;
        case 131: _t->on_comboBox_View_Plane_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 132: _t->on_comboBox_08_FeatContextVal_Stat_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 133: _t->on_comboBox_08_FeatContextSelect_Stat_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 134: _t->on_checkBox_06_4Img_Value_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 135: _t->on_checkBox_06_3Img_Value_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 136: _t->on_comboBox_06_3Img_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 137: _t->on_comboBox_06_4Img_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 138: _t->on_checkBox_09_HDR_Thresh_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 139: _t->on_checkBox_09_HDR_Project_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 140: _t->on_doubleSpinBox_09_HDR_Thresh_Low_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 141: _t->on_doubleSpinBox_09_HDR_Thresh_High_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 142: _t->on_checkBox_07_Fourier_Output_RealOnly_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 143: _t->on_comboBox_View_Crop_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 144: _t->on_comboBox_View_Transform_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 145: _t->on_comboBox_View_Anchor_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 146: _t->on_comboBox_View_Range_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 147: _t->on_checkBox_View_VisTrafo_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 148: _t->on_doubleSpinBox_View_Min_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 149: _t->on_doubleSpinBox_View_Max_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 150: _t->on_radioButton_09_RelationStat_Distance_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 151: _t->on_radioButton_09_RelationStat_Angle_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 66:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        case 67:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (D_StepWindow::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_StepWindow::ViewPlanePosChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (D_StepWindow::*)(double , double , double , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&D_StepWindow::ViewZoomChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject D_StepWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_D_StepWindow.data,
    qt_meta_data_D_StepWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *D_StepWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *D_StepWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_D_StepWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int D_StepWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 152)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 152;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 152)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 152;
    }
    return _id;
}

// SIGNAL 0
void D_StepWindow::ViewPlanePosChanged(vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void D_StepWindow::ViewZoomChanged(double _t1, double _t2, double _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
