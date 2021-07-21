/********************************************************************************
** Form generated from reading UI file 'd_stepwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_STEPWINDOW_H
#define UI_D_STEPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_StepWindow
{
public:
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Show_STUD;
    QAction *action_Show_Settings;
    QAction *action_Show_ViewOptions;
    QAction *action_Show_Output;
    QAction *action_Update_Step;
    QAction *action_Skip_Chain_Update;
    QAction *action_Save_Image;
    QAction *action_Show_Minimized;
    QAction *action_Show_Maximize;
    QAction *action_Show_Normal;
    QAction *action_Show_Fullscreen;
    QAction *action_Update_Hist;
    QAction *action_Autoupdate_Hist_on_Step;
    QAction *action_Autoupdate_Hist_on_HistSettings;
    QAction *action_Autoupdate_Times_on_Step;
    QAction *action_Update_Times;
    QAction *action_Autoupdate_Times_on_TimesSettings;
    QAction *action_Autoupdate_Next_Step;
    QAction *action_Autoupdate_ImgProc_on_Settings;
    QAction *action_Change_Title;
    QAction *action_Features_Visualisation;
    QAction *action_SaveScreenshot;
    QAction *action_Measure_Line_Distance;
    QAction *action_Save_Feature_List;
    QAction *action_connect_plane_position_to_other_steps;
    QAction *action_Connect_Steps_Zoom;
    QAction *action_Zoom_In;
    QAction *action_Zoom_Out;
    QAction *action_Zoom_Reset;
    QAction *action_Save_Analysis;
    QAction *action_Save_Image_List;
    QAction *action_Save_asBinary;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Settings;
    QGridLayout *gridLayout_7;
    QStackedWidget *stackedWidget_Main_Settings;
    QWidget *page_Settings_00_Source;
    QGridLayout *gridLayout_17;
    QStackedWidget *stackedWidget_Settings_00_Source;
    QWidget *page_00_Load;
    QGridLayout *gridLayout_28;
    QComboBox *comboBox_00_Load_Mode;
    QComboBox *comboBox_00_Load_Source_Dim_List;
    QLabel *label_00_Load__Dim_Target;
    QComboBox *comboBox_00_Load_Source_Dim_X;
    QLabel *label_00_Load_Pages;
    QLabel *label_00_Load_Dim_Source;
    QLabel *label_00_Load_X_Img;
    QComboBox *comboBox_00_Load_Source_Dim_Y;
    QComboBox *comboBox_00_Load_Source_Dim_Pages;
    QPushButton *pushButton_00_Load_Image;
    QSpacerItem *verticalSpacer_00_Load;
    QFrame *line_00_Load_1;
    QFrame *line_00_Load_2;
    QLabel *label_00_Load_List;
    QLabel *label_00_Load_Browse;
    QLabel *label_00_Load_Mode;
    QLabel *label_00_Load_Y_Img;
    QComboBox *comboBox_00_Load_Source_Dim_T;
    QSpacerItem *horizontalSpacer_00_Load;
    QLabel *label_2;
    QCheckBox *checkBox_00_Load_Force8UC1;
    QWidget *page_00_Duplicate;
    QGridLayout *gridLayout_34;
    QFrame *line_00_Dupl;
    QSpacerItem *horizontalSpacer_00_Dupl;
    QWidget *page_00_Sample;
    QGridLayout *gridLayout_6;
    QFrame *line_00_Sample;
    QPushButton *pushButton_00_Sample_Select_Directory;
    QSpacerItem *verticalSpacer_00_Sample;
    QComboBox *comboBox_00_Sample_Paths;
    QLabel *label_00_Sample_Directory;
    QWidget *page_00_Generate;
    QGridLayout *gridLayout_77;
    QLabel *label_00_Generate_DimVar;
    QSpacerItem *verticalSpacer_00_Generate;
    QFrame *line_00_Generate_2;
    QLabel *label_00_Generate_Size;
    QComboBox *comboBox_00_Generate_DimVar;
    QFrame *line_00_Generate_1;
    QGridLayout *gridLayout_00_Generate_Size;
    QSpinBox *spinBox_00_Generate_Size_Z;
    QSpinBox *spinBox_00_Generate_Size_Y;
    QSpinBox *spinBox_00_Generate_Size_X;
    QSpinBox *spinBox_00_Generate_Size_T;
    QSpinBox *spinBox_00_Generate_Size_S;
    QSpinBox *spinBox_00_Generate_Size_P;
    QStackedWidget *stackedWidget_00_Generate_DimVar;
    QWidget *page_00_Generate_DimVar_2D;
    QGridLayout *gridLayout_102;
    QGridLayout *gridLayout_00_Generate_Parameters_2D;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_a;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_e;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_inf;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_c;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_nan;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_f;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_b;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_d;
    QLabel *label_00_Generate_Parameters;
    QComboBox *comboBox_00_Generate_ValueFunction_2D;
    QLabel *label_00_Generate_ValuesFunction;
    QSpacerItem *verticalSpacer_00_Generate_2D;
    QWidget *page_00_Generate_00_Parameters_2D_Complex;
    QGridLayout *gridLayout_118;
    QComboBox *comboBox_00_Generate_ValueFunction_2D_Complex;
    QLabel *label_00_Generate_Parameters_Complex;
    QLabel *label_00_Generate_ValuesFunction_Complex;
    QGridLayout *gridLayout_00_Generate_Parameters_2D_Complex;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_e;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_sy;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_ox;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_f;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_b;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_a;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_d;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_nan;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_inf;
    QFrame *line_00_Generate_2D_Complex;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_oy;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_c;
    QDoubleSpinBox *doubleSpinBox_00_Generate_2D_Complex_sx;
    QSpacerItem *verticalSpacer_00_Generate_2D_Complex;
    QWidget *page_00_Generate_DimVar_6D;
    QGridLayout *gridLayout_103;
    QLabel *label_00_Generate_ValueFunction_6D;
    QComboBox *comboBox_00_Generate_ValueFunction_6D;
    QLabel *label_00_Generate_Parameters_6D;
    QGridLayout *gridLayout_00_Generate_Parameters_6D;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_b;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_ox;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_oy;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_st;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_sy;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_ot;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_sz;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_sx;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_nan;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_oz;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_e;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_inf;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_sp;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_op;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_ss;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_d;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_c;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_os;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_f;
    QDoubleSpinBox *doubleSpinBox_00_Generate_6D_a;
    QFrame *line_00_Generate_6D;
    QLabel *label_00_Generate_ScaleOffset;
    QLabel *label_00_Generate_ScaleOffset_Description;
    QWidget *page_00_Random;
    QGridLayout *gridLayout_104;
    QLabel *label_00_Random_Parameters;
    QLabel *label_00_Random_Distribution;
    QSpacerItem *verticalSpacer_00_Random;
    QDoubleSpinBox *doubleSpinBox_00_Random_Min;
    QGridLayout *gridLayout_00_Random_Parameters;
    QDoubleSpinBox *doubleSpinBox_00_Random_b;
    QDoubleSpinBox *doubleSpinBox_00_Random_a;
    QDoubleSpinBox *doubleSpinBox_00_Random_c;
    QDoubleSpinBox *doubleSpinBox_00_Random_d;
    QDoubleSpinBox *doubleSpinBox_00_Random_e;
    QDoubleSpinBox *doubleSpinBox_00_Random_f;
    QDoubleSpinBox *doubleSpinBox_00_Random_Max;
    QFrame *line_00_Random;
    QLabel *label_00_Random_Range;
    QComboBox *comboBox_00_Random_Type;
    QLabel *label_8;
    QGridLayout *gridLayout_00_Random_Size;
    QSpinBox *spinBox_00_Random_Size_Z;
    QSpinBox *spinBox_00_Random_Size_X;
    QSpinBox *spinBox_00_Random_Size_Y;
    QSpinBox *spinBox_00_Random_Size_T;
    QSpinBox *spinBox_00_Random_Size_S;
    QSpinBox *spinBox_00_Random_Size_P;
    QWidget *page_00_CastRaw;
    QGridLayout *gridLayout_86;
    QLabel *label_00_CastRaw_Width;
    QLabel *label_00_CastRaw_Path;
    QFrame *line_00_CastRaw;
    QComboBox *comboBox_00_CastRaw_BitPerPixel;
    QLabel *label_00_CastRaw_Height;
    QLabel *label_00_CastRaw_Type;
    QSpacerItem *verticalSpacer_00_CastRaw;
    QPushButton *pushButton_00_CastRaw_Path;
    QSpinBox *spinBox_00_CastRaw_Height;
    QSpinBox *spinBox_00_CastRaw_Width;
    QSpacerItem *horizontalSpacer_00_CastRaw;
    QLabel *label_00_CastRaw_Channel;
    QWidget *page_00_VideoStream;
    QGridLayout *gridLayout_92;
    QLabel *label_00_VideoStream_File;
    QSpacerItem *verticalSpacer_00_VideoStream;
    QFrame *line_00_VideoStream_1;
    QLabel *label_00_VideoStream_Combi_X;
    QFrame *line_00_VideoStream_2;
    QLabel *label_00_VideoStream_T2;
    QLabel *label_00_VideoStream_T1;
    QLabel *label_00_VideoStream_Blur;
    QGridLayout *gridLayout_00_VideoStream_TimeFrames;
    QSpinBox *spinBox_00_VideoStream_T1_Frames;
    QSpinBox *spinBox_00_VideoStream_T2_Frames;
    QComboBox *comboBox_00_VideoStream_T1_Stat;
    QComboBox *comboBox_00_VideoStream_T2_Stat;
    QSpinBox *spinBox_00_VideoStream_T_Offset;
    QGridLayout *gridLayout_00_VideoStream_Blur;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_Blur_Sigma;
    QSpinBox *spinBox_00_VideoStream_Blur_Size;
    QGridLayout *gridLayout_00_VideoStream_Combination;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_nan;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_b;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_inf;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_f;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_c;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_a;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_e;
    QDoubleSpinBox *doubleSpinBox_00_VideoStream_CombiFunction_d;
    QComboBox *comboBox_00_VideoStream_CombiFunction;
    QCheckBox *checkBox_00_VideoStream_Force_8bit;
    QLabel *label_00_VideoStream_Combi_Y;
    QLabel *label_00_VideoStream_Offset;
    QLabel *label_00_VideoStream_Combi;
    QFrame *line_00_VideoStream_3;
    QFrame *line;
    QGridLayout *gridLayout_00_VideoStream_File;
    QPushButton *pushButton_00_VideoStream_Browse;
    QLabel *label_00_VideoStream_Path;
    QWidget *page_Settings_01_Edit;
    QGridLayout *gridLayout_18;
    QStackedWidget *stackedWidget_Settings_01_Edit;
    QWidget *page_01_Crop;
    QGridLayout *gridLayout_64;
    QLabel *label_01_Crop_Shape;
    QSpacerItem *horizontalSpacer_01_Crop;
    QFrame *line01_Crop;
    QComboBox *comboBox_01_Crop_Shape;
    QStackedWidget *stackedWidget_01_Crop_Shape;
    QWidget *page_01_Crop_RectRel;
    QGridLayout *gridLayout_65;
    QLabel *label_01_Crop_Rect_Y;
    QSpacerItem *verticalSpacer_01_Crop_Rect;
    QLabel *label_01_Crop_Rect_X;
    QDoubleSpinBox *doubleSpinBox_01_Crop_Rect_Y2;
    QSpacerItem *horizontalSpacer_01_Crop_Rect;
    QDoubleSpinBox *doubleSpinBox_01_Crop_Rect_X2;
    QLabel *label_01_Crop_Rect_1;
    QLabel *label_01_Crop_Rect_2;
    QDoubleSpinBox *doubleSpinBox_01_Crop_Rect_X1;
    QDoubleSpinBox *doubleSpinBox_01_Crop_Rect_Y1;
    QLabel *label_01_Crop_Rect_Prz1;
    QLabel *label_01_Crop_Rect_Prz2;
    QWidget *page_01_Crop_RectAbs;
    QGridLayout *gridLayout_79;
    QSpinBox *spinBox_01_Crop_RectAbs_Offset_Y;
    QSpinBox *spinBox_01_Crop_RectAbs_Offset_X;
    QSpacerItem *horizontalSpacer_01_Crop_RectAbs;
    QLabel *label_01_Crop_RectAbs_Offset;
    QLabel *label_01_Crop_RectAbs_X;
    QSpinBox *spinBox_01_Crop_RectAbs_Size_Y;
    QLabel *label_01_Crop_RectAbs_Size;
    QSpacerItem *verticalSpacer_01_Crop_RectAbs;
    QSpinBox *spinBox_01_Crop_RectAbs_Size_X;
    QLabel *label_01_Crop_RectAbs_Y;
    QLabel *label_01_Crop_RectAbs_Offset_Unit;
    QLabel *label_01_Crop_RectAbs_Size_Unit;
    QWidget *page_01_Crop_RectRot;
    QGridLayout *gridLayout_81;
    QSpinBox *spinBox_01_Crop_RectRot_Height;
    QLabel *label_01_Crop_RectRot_X;
    QSpinBox *spinBox_01_Crop_RectRot_Width;
    QLabel *label_01_Crop_RectRot_Size_Unit;
    QSpinBox *spinBox_01_Crop_RectRot_Center_Y;
    QLabel *label_01_Crop_RectRot_Y;
    QLabel *label_01_Crop_RectRot_Center;
    QSpinBox *spinBox_01_Crop_RectRot_Center_X;
    QLabel *label_01_Crop_RectRot_Center_Unit;
    QLabel *label_01_Crop_RectRot_Size;
    QDoubleSpinBox *doubleSpinBox_01_Crop_RectRot_Rotation;
    QLabel *label_01_Crop_RectRot_Rotation_Unit;
    QLabel *label_01_Crop_RectRot_Rotation;
    QSpacerItem *horizontalSpacer_01_Crop_RectRot;
    QSpacerItem *verticalSpacer_01_Crop_RectRot;
    QWidget *page_01_Crop_Circle;
    QGridLayout *gridLayout_82;
    QLabel *label_01_Crop_Circle_X;
    QLabel *label_01_Crop_Circle_Y;
    QLabel *label_01_Crop_Circle_Center;
    QSpinBox *spinBox_01_Crop_Circle_Center_X;
    QSpinBox *spinBox_01_Crop_Circle_Center_Y;
    QLabel *label_01_Crop_Circle_Center_Unit;
    QLabel *label_01_Crop_Circle_Radius;
    QLabel *label_01_Crop_Circle_Radius_Unit;
    QSpacerItem *verticalSpacer_01_Crop_Circle;
    QSpacerItem *horizontalSpacer_01_Crop_Circle;
    QSpinBox *spinBox_01_Crop_Circle_Radius;
    QWidget *page_01_Crop_Ellipse;
    QGridLayout *gridLayout_83;
    QLabel *label_01_Crop_Ellipse_X;
    QLabel *label_01_Crop_Ellipse_Y;
    QLabel *label_01_Crop_Ellipse_Center;
    QSpinBox *spinBox_01_Crop_Ellipse_Center_X;
    QSpinBox *spinBox_01_Crop_Ellipse_Center_Y;
    QLabel *label_01_Crop_Ellipse_Center_Unit;
    QLabel *label_01_Crop_Ellipse_Size;
    QSpinBox *spinBox_01_Crop_Ellipse_Width;
    QSpinBox *spinBox_01_Crop_Ellipse_Height;
    QLabel *label_01_Crop_Ellipse_Size_Unit;
    QLabel *label_01_Crop_Ellipse_Rotation;
    QDoubleSpinBox *doubleSpinBox_01_Crop_Ellipse_Rotation;
    QLabel *label_01_Crop_Ellipse_Rotation_Unit;
    QSpacerItem *verticalSpacer_01_Crop_Ellipse;
    QSpacerItem *horizontalSpacer_01_Crop_Ellipse;
    QWidget *page_01_Floodfill;
    QGridLayout *gridLayout_72;
    QLabel *label_01_Floodfill_Type;
    QFrame *line_01_Floodfill;
    QSpacerItem *horizontalSpacer_01_Floodfill;
    QStackedWidget *stackedWidget_01_Floodfill_Type;
    QWidget *page_01_Floodfill_Border;
    QGridLayout *gridLayout_71;
    QSpacerItem *horizontalSpacer_01_Floodfill_Border;
    QSpacerItem *verticalSpacer_01_Floodfill_Border;
    QWidget *page_01_Floodfill_Delta;
    QGridLayout *gridLayout_120;
    QSpacerItem *horizontalSpacer_01_Floodfill_Delta;
    QLabel *label_01_Floodfill_Delta_Seed;
    QDoubleSpinBox *doubleSpinBox_01_Floodfill_Delta_Delta;
    QSpinBox *spinBox_01_Floodfill_Delta_SeedX;
    QSpacerItem *verticalSpacer_01_Floodfill_Delta;
    QLabel *label_01_Floodfill_Delta_Delta;
    QSpinBox *spinBox_01_Floodfill_Delta_SeedY;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *comboBox_01_Floodfill_Type;
    QLabel *label_01_Floodfill_Fill;
    QDoubleSpinBox *doubleSpinBox_01_Floodfill_Value_Fill;
    QWidget *page_01_Padding;
    QGridLayout *gridLayout_73;
    QLabel *label_01_Padding_Width_X;
    QSpinBox *spinBox_01_Padding_Width_X;
    QSpacerItem *horizontalSpacer_01_Padding;
    QLabel *label_01_Padding_Type;
    QSpacerItem *verticalSpacer_01_Padding;
    QFrame *line_01_Padding;
    QComboBox *comboBox_01_Padding_Type;
    QLabel *label_01_Padding_Width_Z;
    QLabel *label_01_Padding_Value;
    QLabel *label_01_Padding_Width_Y;
    QSpinBox *spinBox_01_Padding_Width_Y;
    QSpinBox *spinBox_01_Padding_Width_Z;
    QDoubleSpinBox *doubleSpinBox_01_Padding_Value;
    QWidget *page_01_ForceSize;
    QGridLayout *gridLayout_116;
    QSpinBox *spinBox_01_ForceSize_Height;
    QSpinBox *spinBox_01_ForceSize_Width;
    QLabel *label_01_ForceSize_Width;
    QSpacerItem *horizontalSpacer_01_ForceSize;
    QSpacerItem *verticalSpacer_01_ForceSize;
    QLabel *label_01_ForceSize_Height;
    QLabel *label_01_ForceSize_Border;
    QComboBox *comboBox_01_ForceSize_Border;
    QWidget *page_Settings_02_Convert;
    QGridLayout *gridLayout_19;
    QStackedWidget *stackedWidget_Settings_02_Convert;
    QWidget *page_02_Color2Mono;
    QGridLayout *gridLayout_94;
    QLabel *label_02_Color2Mono_Reduction;
    QSpacerItem *verticalSpacer_02_Color2Mono;
    QFrame *line_02_Color2Mono;
    QComboBox *comboBox_02_Color2Mono_Reduction;
    QSpacerItem *horizontalSpacer_02_Color2Mono;
    QWidget *page_02_Color;
    QGridLayout *gridLayout_30;
    QLabel *label_02_Color_HSL;
    QLabel *label_02_Color_BGR_1;
    QLabel *label_02_Color_Luv;
    QLabel *label_02_Color_RGB_1;
    QLabel *label_02_Color_Lab;
    QLabel *label_02_Color_Grey;
    QRadioButton *radioButton_02_Color_YCrCb_BGR;
    QRadioButton *radioButton_02_Color_XYZ_BGR;
    QRadioButton *radioButton_02_Color_RGB_BGR;
    QRadioButton *radioButton_02_Color_HSL_BGR;
    QLabel *label_02_Color_RGB_2;
    QRadioButton *radioButton_02_Color_Lab_BGR;
    QRadioButton *radioButton_02_Color_HSV_BGR;
    QSpacerItem *horizontalSpacer_02_Color;
    QRadioButton *radioButton_02_Color_Grey_BGR;
    QLabel *label_02_Color_BGR_2;
    QRadioButton *radioButton_02_Color_Lab_RGB;
    QRadioButton *radioButton_02_Color_BGR_RGB;
    QRadioButton *radioButton_02_Color_HSV_RGB;
    QRadioButton *radioButton_02_Color_Luv_BGR;
    QRadioButton *radioButton_02_Color_HSL_RGB;
    QRadioButton *radioButton_02_Color_Luv_RGB;
    QFrame *line_02_Color;
    QRadioButton *radioButton_02_Color_Grey_RGB;
    QRadioButton *radioButton_02_Color_XYZ_RGB;
    QRadioButton *radioButton_02_Color_YCrCb_RGB;
    QLabel *label_02_Color_HSV;
    QLabel *label_02_Color_XYZ;
    QLabel *label_02_Color_YCrCb;
    QComboBox *comboBox_02_Color_Direction_Top;
    QRadioButton *radioButton_02_Color_RGB_RGB;
    QRadioButton *_Color_BGR_BGR;
    QSpacerItem *verticalSpacer_02_Color;
    QComboBox *comboBox_02_Color_Direction_Left;
    QWidget *page_02_Double;
    QGridLayout *gridLayout_59;
    QFrame *line_02_Double;
    QLabel *label_02_Double_Description;
    QSpacerItem *horizontalSpacer_02_Double;
    QSpacerItem *verticalSpacer_02_Double;
    QWidget *page_02_Depth;
    QGridLayout *gridLayout_29;
    QLabel *label_02_Depth_Maximum;
    QSpacerItem *horizontalSpacer_02_Depth;
    QSpacerItem *verticalSpacer_02_Depth;
    QLabel *label_02_Depth_Norm;
    QFrame *line_02_Depth;
    QLabel *label_02_Depth_Minimum;
    QComboBox *comboBox_02_Depth_Type;
    QLabel *label_02_Depth_Type;
    QDoubleSpinBox *doubleSpinBox_02_Depth_Minimum;
    QDoubleSpinBox *doubleSpinBox_02_Depth_Maximum;
    QComboBox *comboBox_02_Depth_Norm;
    QWidget *page_02_Merge;
    QGridLayout *gridLayout_53;
    QSpinBox *spinBox_02_Merge_Channels;
    QLabel *label_02_Merge_Ch1;
    QLabel *label_02_Merge_Channels;
    QLabel *label_02_Merge_Ch0;
    QCheckBox *checkBox_02_Merge_Ch0;
    QFrame *line_02_Merge;
    QLabel *label_02_Merge_Ch2;
    QCheckBox *checkBox_02_Merge_Ch1;
    QCheckBox *checkBox_02_Merge_Ch3;
    QCheckBox *checkBox_02_Merge_Ch2;
    QLabel *label_02_Merge_Ch3;
    QSpacerItem *verticalSpacer_02_Merge;
    QSpacerItem *horizontalSpacer_02_Merge;
    QWidget *page_02_Split;
    QGridLayout *gridLayout_62;
    QFrame *line_02_Split;
    QLabel *label_02_Split_Channel;
    QSpinBox *spinBox_02_Split_Channel;
    QSpacerItem *horizontalSpacer_02_Split;
    QSpacerItem *verticalSpacer_02_Split;
    QWidget *page_02_Combi;
    QGridLayout *gridLayout_55;
    QLabel *label_02_Combi_Format;
    QComboBox *comboBox_02_Combi_Type;
    QSpacerItem *horizontalSpacer_02_Combi;
    QSpacerItem *verticalSpacer_02_Combi;
    QFrame *line_02_Combi;
    QWidget *page_02_Angle2Color;
    QGridLayout *gridLayout_117;
    QSpacerItem *horizontalSpacer_02_Angle2Color;
    QLabel *label_02_Angle2Color_V;
    QLabel *label_02_Angle2Color_H;
    QSpacerItem *verticalSpacer_02_Angle2Color;
    QLabel *label_02_Angle2Color_S;
    QSpinBox *spinBox_02_Angle2Color_V;
    QSpinBox *spinBox_02_Angle2Color_S;
    QComboBox *comboBox_02_Angle2Color_Mode;
    QWidget *page_Settings_03_Elemental;
    QGridLayout *gridLayout_20;
    QStackedWidget *stackedWidget_Settings_03_Elemental;
    QWidget *page_03_Threshold;
    QGridLayout *gridLayout_31;
    QStackedWidget *stackedWidget_03_Thres;
    QWidget *page_03_Thres_Otsu;
    QGridLayout *gridLayout_69;
    QLabel *label_03_Thres_Otsu;
    QSpacerItem *verticalSpacer_03_Thres_Otsu;
    QWidget *page_03_Thres_Abs;
    QGridLayout *gridLayout_68;
    QLabel *label_03_Thres_Thres_Value;
    QSlider *horizontalSlider_03_Thres_Abs_Thres_Value;
    QSpinBox *spinBox_03_Thres_Thres_Value_Abs;
    QSpacerItem *verticalSpacer_03_Thres_Abs;
    QWidget *page_03_Thres_Rel;
    QGridLayout *gridLayout_67;
    QSpacerItem *horizontalSpacer_03_Thres_Rel;
    QSlider *horizontalSlider_03_Thres_Rel_Thresh_Rel;
    QLabel *label_03_Thres_Real_Thres;
    QDoubleSpinBox *doubleSpinBox_03_Thres_Rel_Thres_Rel;
    QLabel *label_03_Thres_Rel_Base;
    QSpacerItem *verticalSpacer_03_Thres_Rel;
    QDoubleSpinBox *doubleSpinBox_03_Thres_Rel_Base;
    QDoubleSpinBox *doubleSpinBox_03_Thres_Rel_Thresh_Abs;
    QWidget *page_03_Thres_Loc;
    QGridLayout *gridLayout_66;
    QDoubleSpinBox *doubleSpinBox_03_Thres_Adapt_Offset;
    QSpinBox *spinBox_03_Thres_Mask_Size;
    QLabel *label_03_Thres_Adapt_Offset;
    QComboBox *comboBox_03_Thres_Adapt_Type;
    QLabel *label_03_Thres_Adapt_Type;
    QLabel *label_03_Thres_Mask_Size;
    QSpacerItem *verticalSpacer_03_Thres_Local;
    QSpacerItem *horizontalSpacer_03_Thres_Local;
    QComboBox *comboBox_03_Thres_Type;
    QFrame *line_03_Thres_1;
    QFrame *line_03_Thres_2;
    QComboBox *comboBox_03_Thres_Output_Mode;
    QLabel *label_03_Thres_Max_Value;
    QLabel *label_03_Thres_Output_Type;
    QDoubleSpinBox *doubleSpinBox_03_Thres_Max_Value_Out;
    QLabel *label_03_Thres_Type;
    QWidget *page_03_Labeling;
    QGridLayout *gridLayout_40;
    QLabel *label_03_Labeling_Depth;
    QFrame *line03_Labeling;
    QSpacerItem *horizontalSpacer_03_Labeling;
    QSpacerItem *verticalSpacer_03_Labeling;
    QLabel *label_03_Labeling_Type;
    QComboBox *comboBox_03_Labeling_Type;
    QComboBox *comboBox_03_Labeling_Connectivity;
    QLabel *label_03_Labeling_Connectivity;
    QComboBox *comboBox_03_Labeling_Depth;
    QWidget *page_03_ShadeCorr;
    QGridLayout *gridLayout_52;
    QLabel *label_03_ShadeCorr_Dst_Titel;
    QSpacerItem *horizontalSpacer_03_ShadeCorr;
    QLabel *label_03_ShadeCorr_Src2_Titel;
    QFrame *line_03_ShadeCorr;
    QSpacerItem *verticalSpacer_03_ShadeCorr;
    QLabel *label_03_ShadeCorr_Src1_Titel;
    QLabel *label_03_ShadeCorr_Src1_Descr;
    QLabel *label_03_ShadeCorr_Src2_Descr;
    QLabel *label_03_ShadeCorr_Dst_Descr;
    QWidget *page_03_GrabColor;
    QGridLayout *gridLayout_56;
    QLabel *label_03_GrabColor_Ch2_Max;
    QSpinBox *spinBox_03_GrabColor_Ch2_Max;
    QComboBox *comboBox_03_GrabColor_ColorSpace;
    QLabel *label_03_GrabColor_Ch2_Min;
    QSlider *horizontalSlider_03_GrabColor_Ch2_Max;
    QSlider *horizontalSlider_03_GrabColor_Ch3_Min;
    QSlider *horizontalSlider_03_GrabColor_Ch2_Min;
    QSpacerItem *horizontalSpacer_03_GrabColor;
    QLabel *label_03_GrabColor_Ch3_Min;
    QSpinBox *spinBox_03_GrabColor_Ch3_Min;
    QSlider *horizontalSlider_03_GrabColor_Ch3_Max;
    QLabel *label_03_GrabColor_Ch3_Max;
    QSpinBox *spinBox_03_GrabColor_Ch1_Max;
    QSlider *horizontalSlider_03_GrabColor_Ch1_Max;
    QSpinBox *spinBox_03_GrabColor_Ch3_Max;
    QSpinBox *spinBox_03_GrabColor_Ch2_Min;
    QComboBox *comboBox_03_GrabColor_Output;
    QFrame *line_03_GrabColor_1;
    QLabel *label_03_GrabColor_Output;
    QLabel *label_03_GrabColor_Ch1_Min;
    QSpinBox *spinBox_03_GrabColor_Ch1_Min;
    QSlider *horizontalSlider_03_GrabColor_Ch1_Min;
    QLabel *label_03_GrabColor_Ch1_Max;
    QLabel *label_03_GrabColor_Ch1;
    QLabel *label_03_GrabColor_Ch2;
    QLabel *label_03_GrabColor_Ch3;
    QFrame *line_03_GrabColor_2;
    QLabel *label_03_GrabColor_ColorSpace;
    QFrame *line_03_GrabColor_3;
    QFrame *line_03_GrabColor_4;
    QWidget *page_03_FillHoles;
    QGridLayout *gridLayout_5;
    QFrame *line_03_FillHoles;
    QLabel *label_03_FillHoles_Description;
    QSpacerItem *verticalSpacer_03_FillHoles;
    QWidget *page_Settings_04_Filter;
    QGridLayout *gridLayout_21;
    QStackedWidget *stackedWidget_Settings_04_Filter;
    QWidget *page_04_Blur;
    QGridLayout *gridLayout_35;
    QFrame *line_04_Blur;
    QSpinBox *spinBox_04_Blur_Size_X;
    QLabel *label_04_Blur_Size_XY;
    QSpacerItem *horizontalSpacer_04_Blur;
    QSpacerItem *verticalSpacer_04_Blur;
    QLabel *label_04_Blur_Type;
    QComboBox *comboBox_04_Blur_Type;
    QLabel *label_04_Blur_Size;
    QSpinBox *spinBox_04_Blur_Size_Y;
    QSpinBox *spinBox_04_Blur_Size;
    QDoubleSpinBox *doubleSpinBox_04_Blur_Sigma_Y;
    QDoubleSpinBox *doubleSpinBox_04_Blur_Sigma_X;
    QLabel *label_04_Blur_Sigma_XY;
    QLabel *label_04_Blur_Depth;
    QComboBox *comboBox_04_Blur_Depth;
    QLabel *label_04_Blur_Normalized;
    QCheckBox *checkBox_04_Blur_Normalized;
    QWidget *page_04_Edge;
    QGridLayout *gridLayout_36;
    QSpinBox *spinBox_04_Edge_Thresh_High;
    QSpinBox *spinBox_04_Edge_Thresh_Low;
    QLabel *label_04_Edge_Thesh;
    QLabel *label_04_Edge_Size;
    QSpacerItem *verticalSpacer_04_Edge;
    QLabel *label_04_Edge_Scale;
    QComboBox *comboBox_04_Edge_Type;
    QLabel *label_04_Edge_Delta;
    QFrame *line_04_Edge;
    QLabel *label_04_Edge_dXdY;
    QSpinBox *spinBox_04_Edge_dY;
    QSpinBox *spinBox_04_Edge_Size;
    QDoubleSpinBox *doubleSpinBox_04_Edge_Delta;
    QSpinBox *spinBox_04_Edge_dX;
    QLabel *label_04_Edge_Type;
    QDoubleSpinBox *doubleSpinBox_04_Edge_Scale;
    QSpacerItem *horizontalSpacer_04_Edge;
    QLabel *label_04_Edge_Depth;
    QComboBox *comboBox_04_Edge_Depth;
    QLabel *label_04_Edge_Options;
    QCheckBox *checkBox_04_Edge_L2_Gradient;
    QWidget *page_04_Special;
    QGridLayout *gridLayout_37;
    QLabel *label_04_Special_Depth;
    QSpinBox *spinBox_04_Special_Size_X;
    QComboBox *comboBox_04_Special_Type;
    QSpinBox *spinBox_04_Special_Diameter;
    QSpacerItem *horizontalSpacer_04_Special;
    QLabel *label_04_Special_Diameter;
    QLabel *label_04_Special_Type;
    QFrame *line_04_Special;
    QStackedWidget *stackedWidget_04_Special;
    QWidget *page_04_Special_Bilateral;
    QGridLayout *gridLayout_38;
    QLabel *label_04_Special_Sigma_Color;
    QSpacerItem *verticalSpacer_04_Special_Bilateral;
    QSpacerItem *horizontalSpacer_04_Special_Bilateral;
    QLabel *label_04_Special_Sigma_Space;
    QDoubleSpinBox *doubleSpinBox_04_Special_Sigma_Color;
    QDoubleSpinBox *doubleSpinBox_04_Special_Sigma_Space;
    QWidget *page_04_Special_Gabor;
    QGridLayout *gridLayout_39;
    QDoubleSpinBox *doubleSpinBox_04_Special_Sigma;
    QLabel *label_04_Special_Lambda;
    QSpacerItem *horizontalSpacer_04_Special_Gabor;
    QDoubleSpinBox *doubleSpinBox_04_Special_Lambda;
    QLabel *label_04_Special_Sigma;
    QDoubleSpinBox *doubleSpinBox_04_Special_Psi;
    QLabel *label_04_Special_Psi;
    QLabel *label_04_Special_Theta;
    QDoubleSpinBox *doubleSpinBox_04_Special_Delta;
    QLabel *label_04_Special_Delta;
    QSpacerItem *verticalSpacer_04_Special;
    QDoubleSpinBox *doubleSpinBox_04_Special_Gamma;
    QDoubleSpinBox *doubleSpinBox_04_Special_Theta;
    QLabel *label_04_Special_Gamma;
    QSpinBox *spinBox_04_Special_Size_Y;
    QLabel *label_04_Special_Size_XY;
    QComboBox *comboBox_04_Special_Depth;
    QWidget *page_04_Eilenstein;
    QGridLayout *gridLayout_54;
    QStackedWidget *stackedWidget_04_Eilenstein_Type;
    QWidget *page_04_Eilenstein_Comp;
    QGridLayout *gridLayout_70;
    QLabel *label_04_Eilenstein_Size;
    QLabel *label_04_Eilenstein_Comparator;
    QCheckBox *checkBox_04_Eilenstein_Normalized;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_Delta;
    QLabel *label_04_Eilenstein_Normalized;
    QSpinBox *spinBox_04_Eilenstein_Size_Y;
    QSpacerItem *horizontalSpacer_04_Eilenstein;
    QLabel *label_04_Eilenstein_Delta;
    QComboBox *comboBox_04_Eilenstein_Comparator;
    QSpinBox *spinBox_04_Eilenstein_Size_X;
    QSpacerItem *verticalSpacer_04_Eilenstein;
    QWidget *page_04_Eilenstein_Gen;
    QGridLayout *gridLayout_76;
    QComboBox *comboBox_04_Eilenstein_PixelCenter;
    QComboBox *comboBox_04_Eilenstein_PixelMask;
    QComboBox *comboBox_04_Eilenstein_Response;
    QSpacerItem *verticalSpacer_04_Eilenstein_2;
    QFrame *line_04_Eilenstein_2;
    QFrame *line_04_Eilenstein_3;
    QLabel *label_04_Eilenstein_Response_Title;
    QLabel *label_04_Eilenstein_PixelCenter_Y;
    QGridLayout *gridLayout_04_Eilenstein_PixelCenter;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_a;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_b;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_d;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_c;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_e;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_f;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_nan;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelCenter_inf;
    QLabel *label_04_Eilenstein_PixelCenter_X;
    QGridLayout *gridLayout_04_Eilenstein_PixelMask;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_d;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_a;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_b;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_c;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_e;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_f;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_nan;
    QDoubleSpinBox *doubleSpinBox_04_Eilenstein_PixelMask_inf;
    QLabel *label_04_Eilenstein_PixelMask_Y;
    QLabel *label_04_Eilenstein_PixelMask_X;
    QLabel *label_04_Eilenstein_PixelCenter_Titel;
    QLabel *label_04_Eilenstein_PixelMask_Title;
    QLabel *label_04_Eilenstein_Type;
    QComboBox *comboBox_04_Eilenstein_Type;
    QFrame *line_04_Eilenstein;
    QSpacerItem *horizontalSpacer;
    QWidget *page_04_Function;
    QGridLayout *gridLayout_80;
    QGridLayout *gridLayout_04_Function_Functions;
    QLabel *label_04_Function_f_f2_y;
    QLabel *label_04_Function_f_f4_x;
    QLabel *label_04_Function_f_f2_x;
    QLabel *label_04_Function_f_f1_y;
    QLabel *label_04_Function_f_f4_y;
    QLabel *label_04_Function_f_f3;
    QLabel *label_04_Function_f_y;
    QComboBox *comboBox_04_Function_f3_vF2;
    QComboBox *comboBox_04_Function_f4_CenterF3;
    QLabel *label_04_Function_f_f1;
    QComboBox *comboBox_04_Function_f1_CenterImage;
    QComboBox *comboBox_04_Function_f2_F1Mask;
    QLabel *label_04_Function_f_f4;
    QLabel *label_04_Function_f_f2;
    QLabel *label_04_Function_f_f1_x;
    QLabel *label_04_Function_f_x;
    QLabel *label_04_Function_f_f3_data;
    QLabel *label_04_Function_f_prototype;
    QCheckBox *checkBox_04_Function_OnlyNonZero;
    QGridLayout *gridLayout_04_Function_Parameters;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_inf;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_nan;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_f;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_e;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_d;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_c;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_b;
    QDoubleSpinBox *doubleSpinBox_04_Function_f4_a;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_inf;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_nan;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_f;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_e;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_d;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_c;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_b;
    QDoubleSpinBox *doubleSpinBox_04_Function_f2_a;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_inf;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_nan;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_f;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_e;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_d;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_c;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_b;
    QDoubleSpinBox *doubleSpinBox_04_Function_f1_a;
    QLabel *label_04_Function_inf;
    QLabel *label_04_Function_nan;
    QLabel *label_04_Function_f;
    QLabel *label_04_Function_e;
    QLabel *label_04_Function_d;
    QLabel *label_04_Function_c;
    QLabel *label_04_Function_b;
    QLabel *label_04_Function_f4;
    QLabel *label_04_Function_f2;
    QLabel *label_04_Function_f1;
    QLabel *label_04_Function_a;
    QFrame *line_04_Function;
    QWidget *page_04_RankOrder;
    QGridLayout *gridLayout_122;
    QLabel *label_04_RankOrder_MaskType;
    QComboBox *comboBox_04_RankOrder_MaskType;
    QLabel *label_04_RankOrder_Stat;
    QDoubleSpinBox *doubleSpinBox_04_RankOrder_Quantil;
    QSlider *horizontalSlider_04_RankOrder_Quantil;
    QLabel *label_04_RankOrder_Radius;
    QDoubleSpinBox *doubleSpinBox_04_RankOrder_Radius;
    QLabel *label_04_RankOrder_Size;
    QSpinBox *spinBox_04_RankOrder_Size_x;
    QSpinBox *spinBox_04_RankOrder_Size_y;
    QSpacerItem *verticalSpacer_04_RankOrder;
    QSpacerItem *horizontalSpacer_04_RankOrder;
    QWidget *page_04_Statistic;
    QGridLayout *gridLayout_121;
    QSpacerItem *verticalSpacer_04_Statistic;
    QLabel *label_04_Statistic_Stat;
    QLabel *label_04_Statistic_MaskType;
    QSpinBox *spinBox_04_Statistic_Size_x;
    QLabel *label_04_Statistic_Radius;
    QSpinBox *spinBox_04_Statistic_Size_y;
    QLabel *label_04_Statistic_Size;
    QComboBox *comboBox_04_Statistic_MaskType;
    QComboBox *comboBox_04_Statistic_Stat;
    QSpacerItem *horizontalSpacer_04_Statistic;
    QDoubleSpinBox *doubleSpinBox_04_Statistic_Radius;
    QLabel *label_04_Border_Type;
    QComboBox *comboBox_04_Border_Type;
    QSpacerItem *horizontalSpacer_04;
    QCheckBox *checkBox_04_Force_8bit;
    QSpacerItem *horizontalSpacer_04_2;
    QWidget *page_Settings_05_Morphology;
    QGridLayout *gridLayout_22;
    QStackedWidget *stackedWidget_Settings_05_Morphology;
    QWidget *page_05_Elemental;
    QGridLayout *gridLayout_32;
    QLabel *label_05_Elem_Border_Type;
    QLabel *label_05_Elem_Morph_Type;
    QComboBox *comboBox_05_Elem_Elem_Type;
    QFrame *line_05_Elem;
    QLabel *label_05_Elem_Elem_Type;
    QSpacerItem *horizontalSpacer_05_Elem;
    QLabel *label_05_Elem_Elem_Size;
    QComboBox *comboBox_05_Elem_Morph_Type;
    QSpinBox *spinBox_05_Elem_Elem_Size_X;
    QSpinBox *spinBox_05_Elem_Elem_Size_Y;
    QComboBox *comboBox_05_Elem_Border_Type;
    QLabel *label_05_Elem_Iterations;
    QSpinBox *spinBox_05_Elem_Iterations;
    QSpacerItem *verticalSpacer_05_Elem;
    QWidget *page_05_MinMaxGil;
    QGridLayout *gridLayout_123;
    QSpacerItem *verticalSpacer_05_MinMaxGil;
    QComboBox *comboBox_05_MinMaxGil_MinMax;
    QSpinBox *spinBox_05_MinMaxGil_SizeX;
    QSpinBox *spinBox_05_MinMaxGil_SizeY;
    QLabel *label_05_MinMaxGil_MinMax;
    QLabel *label_05_MinMaxGil_Size;
    QSpacerItem *horizontalSpacer_05_MinMaxGil;
    QWidget *page_05_Reconstruction;
    QGridLayout *gridLayout_124;
    QLabel *label_05_Reconstruction_Limit_Header;
    QLabel *label_05_Reconstruction_Elem_Header;
    QLabel *label_05_Reconstruction_Limit_Source;
    QSpacerItem *verticalSpacer_05_Reconstruction;
    QLabel *label_05_Reconstruction_Elem_Source;
    QLabel *label_05_Reconstruction_Seed_Source;
    QLabel *label_05_Reconstruction_Seed_Header;
    QLabel *label_05_Reconstruction_Quantil;
    QDoubleSpinBox *doubleSpinBox_05_Reconstruction_Quantil;
    QSpacerItem *horizontalSpacer_05_Reconstruction;
    QWidget *page_05_LocalMaxima;
    QGridLayout *gridLayout_98;
    QFrame *line_05_LocalMaxima;
    QSpacerItem *horizontalSpacer_05_LocalMaxima;
    QLabel *label_05_LocalMaxima_Size;
    QSpacerItem *verticalSpacer_05_LocalMaxima;
    QSpinBox *spinBox_05_LocalMaxima_Size_X;
    QSpinBox *spinBox_05_LocalMaxima_Size_Y;
    QWidget *page_Settings_06_Math;
    QGridLayout *gridLayout_23;
    QStackedWidget *stackedWidget_Settings_06_Math;
    QWidget *page_06_1Img;
    QGridLayout *gridLayout_42;
    QSpacerItem *verticalSpacer_06_1Img;
    QSpacerItem *horizontalSpacer_06_1Img;
    QFrame *line_06_1Img;
    QLabel *label_06_1Img_Type;
    QComboBox *comboBox_06_1Img_Type;
    QDoubleSpinBox *doubleSpinBox_06_1Img_Arg;
    QLabel *label_06_1Img_Arg;
    QWidget *page_06_2Img;
    QGridLayout *gridLayout_43;
    QComboBox *comboBox_06_2Img_Comparator;
    QSpacerItem *verticalSpacer_06_2Img;
    QDoubleSpinBox *doubleSpinBox_06_2Img_Weight_Sum;
    QLabel *label_06_2Img_Weight_Sum;
    QLabel *label_06_2Img_Weight_Source;
    QDoubleSpinBox *doubleSpinBox_06_2Img_Weight_1;
    QLabel *label_06_2Img_Scale;
    QDoubleSpinBox *doubleSpinBox_06_2Img_Scale;
    QLabel *label_06_2Img_Comparator;
    QFrame *line_06_2Img;
    QLabel *label_06_2Img_Type;
    QDoubleSpinBox *doubleSpinBox_06_2Img_Weight_2;
    QComboBox *comboBox_06_2Img_Type;
    QSpacerItem *horizontalSpacer_06_2Img;
    QWidget *page_06_2ImgFunction;
    QGridLayout *gridLayout_88;
    QComboBox *comboBox_06_2ImgFunction_Function;
    QLabel *label_06_2ImgFunction_Function;
    QLabel *label_06_2ImgFunction_Parameters;
    QGridLayout *gridLayout_06_2ImgFunction_Parameters;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_b;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_c;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_d;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_a;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_e;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_f;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_nan;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_inf;
    QSpacerItem *verticalSpacer_06_2ImgFunction;
    QFrame *line_06_2ImgFunction;
    QCheckBox *checkBox_06_2ImgFunction_Force_8bit;
    QLabel *label_06_2ImgFunction_Force_8bit;
    QWidget *gridLayout_06_2ImgFunction_Complex;
    QGridLayout *gridLayout_119;
    QLabel *label_06_2ImgFunction_Complex_Function;
    QSpacerItem *verticalSpacer_06_2ImgFunction_Complex;
    QComboBox *comboBox_06_2ImgFunction_Complex_Function;
    QLabel *label_06_2ImgFunction_Complex_Parameters;
    QFrame *line_06_2ImgFunction_Complex;
    QGridLayout *gridLayout_06_2ImgFunction_Complex_Parameters;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_e;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_c;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_oy;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_d;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_sx;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_nan;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_f;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_b;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_ox;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_inf;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_a;
    QDoubleSpinBox *doubleSpinBox_06_2ImgFunction_Complex_sy;
    QFrame *line_06_2ImgFunction_Complex_2;
    QWidget *page_06_3Img;
    QGridLayout *gridLayout_106;
    QFrame *line_06_3Img;
    QLabel *label_06_3Img_Type;
    QComboBox *comboBox_06_3Img_Type;
    QSpacerItem *horizontalSpacer_06_3Img;
    QLabel *label_06_3Img_Value;
    QCheckBox *checkBox_06_3Img_Value;
    QDoubleSpinBox *doubleSpinBox_06_3Img_Value;
    QSpacerItem *verticalSpacer_06_3Img;
    QWidget *page_06_4Img;
    QGridLayout *gridLayout_105;
    QFrame *line_06_4Img;
    QLabel *label_06_4Img_Type;
    QComboBox *comboBox_06_4Img_Type;
    QSpacerItem *horizontalSpacer_06_4Img;
    QLabel *label_06_4Img_Value;
    QCheckBox *checkBox_06_4Img_Value;
    QDoubleSpinBox *doubleSpinBox_06_4Img_Value;
    QSpacerItem *verticalSpacer_06_4Img;
    QWidget *page_Settings_07_Transform;
    QGridLayout *gridLayout_24;
    QStackedWidget *stackedWidget_Settings_07_Transform;
    QWidget *page_07_Dist;
    QGridLayout *gridLayout_33;
    QLabel *label_07_Dist_Norm;
    QLabel *label_07_Dist_Precision;
    QSpacerItem *verticalSpacer_07_Dist;
    QComboBox *comboBox_07_Dist_Precision;
    QComboBox *comboBox_07_Dist_Metric;
    QSpacerItem *horizontalSpacer_07_Dist;
    QFrame *line_07_Dist;
    QWidget *page_07_Watershade;
    QGridLayout *gridLayout_41;
    QComboBox *comboBox_07_Watershed_Implementation;
    QLabel *label_07_Watershed_Implementation;
    QSpacerItem *horizontalSpacer_07_Watershed_3;
    QStackedWidget *stackedWidget_07_Watershed;
    QWidget *page_07_WatershedCustom;
    QGridLayout *gridLayout_126;
    QComboBox *comboBox_07_WatershedCustom_Mask;
    QLabel *label_07_WatershedCustom_Connectivity_3;
    QSpacerItem *verticalSpacer_07_WatershedCustom_3;
    QLabel *label_07_WatershedCustom_Border;
    QComboBox *comboBox_07_WatershedCustom_Flood;
    QLabel *label_07_WatershedCustom_NonSeed;
    QLabel *label_07_WatershedCustom_Mask_3;
    QStackedWidget *stackedWidget_07_WatershedCustom_Flood;
    QWidget *page_07_WatershedCustom_Flood_Empty;
    QWidget *page_07_WatershedCustom_Flood_Gauss;
    QGridLayout *gridLayout_127;
    QSpinBox *spinBox_07_WatershedCustom_Flood_GaussSize;
    QDoubleSpinBox *doubleSpinBox_07_WatershedCustom_Flood_GaussSigma;
    QWidget *page_07_WatershedCustom_Flood_Morph;
    QGridLayout *gridLayout_128;
    QComboBox *comboBox_07_WatershedCustom_Flood_Morph_Elem;
    QSpinBox *spinBox_07_WatershedCustom_Flood_Morph_Size;
    QComboBox *comboBox_07_WatershedCustom_Marker;
    QLabel *label_07_WatershedCustom_Marker_3;
    QLabel *label_07_WatershedCustom_Flood_3;
    QCheckBox *checkBox_07_WatershedCustom_IncludeNonSeed;
    QStackedWidget *stackedWidget_07_WatershedCustom_Marker;
    QWidget *page_07_WatershedCustom_Marker_Empty;
    QWidget *page_07_WatershedCustom_Marker_Label;
    QGridLayout *gridLayout_130;
    QComboBox *comboBox_07_WatershedCustom_Marker_LabelNeighborhood;
    QComboBox *comboBox_07_WatershedCustom_Connectivity;
    QCheckBox *checkBox_07_WatershedCustom_ExcludeBorder;
    QStackedWidget *stackedWidget_07_WatershedCustom_Mask;
    QWidget *page_07_WatershedCustom_Mask_Empty;
    QWidget *page_07_WatershedCustom_Mask_Thres;
    QGridLayout *gridLayout_132;
    QDoubleSpinBox *doubleSpinBox_07_WatershedCustom_Mask_Thres;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_07_WatershedCustom;
    QHBoxLayout *horizontalLayout_07_WatershedCustom_DrawWatershed;
    QCheckBox *checkBox_07_WatershedCustom_DrawWatershed;
    QStackedWidget *stackedWidget_07_WatershedCustom_DrawWatershed;
    QWidget *page_07_WatershedCustom_DrawWatershed_No;
    QWidget *page_07_WatershedCustom_DrawWatershed_Yes;
    QGridLayout *gridLayout_129;
    QComboBox *comboBox_07_WatershedCustom_DrawWatershed_Neighborhood;
    QWidget *page_07_Watershed_OpenCV;
    QGridLayout *gridLayout_125;
    QLabel *label_07_Watershed_8bit_Description;
    QLabel *label_07_Watershed_8bit;
    QComboBox *comboBox_07_Watershed_Connectivity;
    QLabel *label_07_Watershed_InclNonSeed_Description;
    QLabel *label_07_Watershed_Markers_Desription;
    QLabel *label_07_Watershed_InclNonSeed;
    QCheckBox *checkBox_07_Watershed_InclNonSeed;
    QLabel *label_07_Watersehd_Input;
    QLabel *label_07_Watershed_Markers_Source;
    QLabel *label_07_Watershed_Auto_Description;
    QCheckBox *checkBox_07_Watershed_ExclBorder;
    QLabel *label_07_Watershed_Input_Source;
    QLabel *label_07_Watershed_Connectivity;
    QLabel *label_07_Watershed_Markers;
    QLabel *label_07_Watershed_ExclBor;
    QFrame *line_07_Watershed_2;
    QCheckBox *checkBox_07_Watershed_8bit;
    QFrame *line_07_Watershed_3;
    QSpacerItem *horizontalSpacer_07_Watershed;
    QLabel *label_07_Watershed_Input_Desciption;
    QSpacerItem *verticalSpacer_07_Watershed;
    QLabel *label_07_Watershed_Auto;
    QLabel *label_07_Watershed_Connectivity_2;
    QCheckBox *checkBox_07_Watershed_Auto;
    QLabel *label_07_Watershed_ExclBorder_Description;
    QWidget *page_07_Fourier;
    QGridLayout *gridLayout_45;
    QLabel *label_07_Fourier_Input_Complex;
    QCheckBox *checkBox_07_Fourier_Output_Scale;
    QFrame *line_07_Fourier_2;
    QCheckBox *checkBox_07_Fourier_Input_Complex;
    QComboBox *comboBox_07_Fourier_Output_ComplexMode;
    QLabel *label_07_Fourier_Output_Centered;
    QCheckBox *checkBox_07_Fourier_ForceFFT;
    QLabel *label_07_Fourier_OptimalSize;
    QFrame *line_07_Fourier;
    QSpacerItem *horizontalSpacer_07_Fourier;
    QCheckBox *checkBox_07_Fourier_Invers;
    QCheckBox *checkBox_07_Fourier_Output_RealOnly;
    QLabel *label_07_Fourier_Output_no_f0;
    QLabel *label_07_Fourier_Output_ComplexMode;
    QLabel *label_07_Fourier_Output_RealOnly;
    QLabel *label_07_Fourier_Invers;
    QCheckBox *checkBox_07_Fourier_Output_Centered;
    QFrame *line_07_Fourier_1;
    QCheckBox *checkBox_07_Fourier_Output_no_f0;
    QLabel *label_07_Fourier_Output_Scale;
    QSpacerItem *verticalSpacer_07_Fourier;
    QWidget *page_07_Radon;
    QWidget *page_Settings_08_Features;
    QGridLayout *gridLayout_25;
    QStackedWidget *stackedWidget_Settings_08_Features;
    QWidget *page_08_FeatVal;
    QGridLayout *gridLayout_74;
    QFrame *line_08_FeatVal;
    QSpacerItem *horizontalSpacer_08_FeatVal;
    QLabel *label_08_FeatVal_Connectivity;
    QComboBox *comboBox_08_FeatVal_Connectivity;
    QSpacerItem *verticalSpacer_08_FeatVal;
    QComboBox *comboBox_08_FeatVal_Feature;
    QLabel *label_08_FeatVal_Feature;
    QWidget *page_08_FeatContextVal;
    QGridLayout *gridLayout_95;
    QLabel *label_08_FeatContextVal_Connectivity;
    QFrame *line_08_FeatContextVal_1;
    QComboBox *comboBox_08_FeatContextVal_Connectivity;
    QComboBox *comboBox_08_FeatContextVal_Stat;
    QSpacerItem *verticalSpacer_08_FeatContextVal;
    QSpacerItem *horizontalSpacer_08_FeatContextVal;
    QFrame *line_08_FeatContextVal_2;
    QComboBox *comboBox_08_FeatContextVal_Feat;
    QDoubleSpinBox *doubleSpinBox_08_FeatContextVal_DistMax;
    QFrame *line_08_FeatContextVal_3;
    QLabel *label_08_FeatContextVal_DistanceFrom;
    QDoubleSpinBox *doubleSpinBox_08_FeatContextVal_DistMin;
    QLabel *label_08_FeatContextVal_Feat;
    QLabel *label_08_FeatContextVal_Stat;
    QLabel *label_08_FeatContextVal_DistanceRange;
    QLabel *label_08_FeatContextVal_DistanceTo;
    QComboBox *comboBox_08_FeatContextVal_DistPt2;
    QComboBox *comboBox_08_FeatContextVal_DistPt1;
    QWidget *page_08_Select;
    QGridLayout *gridLayout_60;
    QDoubleSpinBox *doubleSpinBox_08_Select_Max;
    QLabel *label_08_Select_Connectivity;
    QLabel *label_08_Select_Range;
    QFrame *line_08_Select_1;
    QComboBox *comboBox_08_Select_Connectivity;
    QDoubleSpinBox *doubleSpinBox_08_Select_Step;
    QFrame *line_08_Select_2;
    QLabel *label_08_Select_Decimals;
    QLabel *label_08_Select_Step;
    QSpacerItem *verticalSpacer_08_Select;
    QFrame *line_08_Select_3;
    QSpinBox *spinBox_08_Select_Decimals;
    QComboBox *comboBox_08_Select_Type;
    QLabel *label_08_Select_Type;
    QSpacerItem *horizontalSpacer_08_Select;
    QDoubleSpinBox *doubleSpinBox_08_Select_Min;
    QWidget *page_08_SelectContext;
    QGridLayout *gridLayout_96;
    QComboBox *comboBox_08_FeatContextSelect_Connectivity;
    QSpacerItem *verticalSpacer_08_FeatContextSelect;
    QFrame *line_08_FeatContextSelect_4;
    QLabel *label_08_FeatContextSelect_Stat;
    QComboBox *comboBox_08_FeatContextSelect_Feat;
    QLabel *label_08_FeatContextSelect_Range;
    QDoubleSpinBox *doubleSpinBox_08_FeatContextSelect_ThresMin;
    QDoubleSpinBox *doubleSpinBox_08_FeatContextSelect_DistMin;
    QLabel *label_08_FeatContextSelect_DistanceRange;
    QFrame *line_08_FeatContextSelect_2;
    QSpacerItem *horizontalSpacer_08_FeatContextSelect;
    QLabel *label_08_FeatContextSelect_Feat;
    QDoubleSpinBox *doubleSpinBox_08_FeatContextSelect_ThresMax;
    QDoubleSpinBox *doubleSpinBox_08_FeatContextSelect_DistMax;
    QFrame *line_08_FeatContextSelect_1;
    QFrame *line_08_FeatContextSelect_3;
    QLabel *label_08_FeatContextSelect_Connectivity;
    QComboBox *comboBox_08_FeatContextSelect_Stat;
    QLabel *label_08_FeatContextSelect_DistanceFrom;
    QComboBox *comboBox_08_FeatContextSelect_DistPt2;
    QComboBox *comboBox_08_FeatContextSelect_DistPt1;
    QLabel *label_08_FeatContextSelectDistanceTo;
    QWidget *page_08_Connect;
    QGridLayout *gridLayout_97;
    QLabel *label_08_Connect_Cond;
    QComboBox *comboBox_08_Connect_Feat2;
    QGridLayout *gridLayout_100;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_h;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_e;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_c;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_a;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_d;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_g;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_f;
    QDoubleSpinBox *doubleSpinBox_08_Connect_Cond_b;
    QSpacerItem *horizontalSpacer_08_FeatContextVal_2;
    QLabel *label_08_Connect_Object2_Feat;
    QComboBox *comboBox_08_Connect_Cond;
    QLabel *label_08_Connect_Object1_Feat;
    QLabel *label_08_Connect_DistanceFrom;
    QDoubleSpinBox *doubleSpinBox_08_Connect_DistMin;
    QLabel *label_08_Connect_Connectivity;
    QFrame *line_08_Connect_2;
    QLabel *label_08_Connect_DistanceTo;
    QDoubleSpinBox *doubleSpinBox_08_Connect_DistMax;
    QFrame *line_08_Connect_3;
    QComboBox *comboBox_08_Connect_DistPt2;
    QComboBox *comboBox_08_Connect_DistPt1;
    QLabel *label_08_Connect_DistanceRange;
    QFrame *line_08_Connect_1;
    QFrame *line_08_Connect_4;
    QComboBox *comboBox_08_Connect_Feat1;
    QSpacerItem *verticalSpacer_08_Connect;
    QGridLayout *gridLayout_101;
    QComboBox *comboBox_08_Connect_ConnectType;
    QComboBox *comboBox_08_Connect_Connectivity;
    QSpinBox *spinBox_08_Connect_Thickness;
    QWidget *page_08_Reduce;
    QGridLayout *gridLayout_58;
    QLabel *label_08_Reduce_Type;
    QComboBox *comboBox_08_Reduce_Type;
    QLabel *label_08_Reduce_Thickness;
    QSpinBox *spinBox_08_Reduce_Thickness;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox_08_Reduce_Connectivity;
    QLabel *label_08_Reduce_Connectivity;
    QFrame *line_08_Reduce;
    QSpacerItem *horizontalSpacer_08_Reduce;
    QSpinBox *spinBox_08_Reduce_Value;
    QLabel *label_08_Reduce_Value;
    QWidget *page_08_Visualize;
    QGridLayout *gridLayout_75;
    QComboBox *comboBox_08_Visualize_Connectivity;
    QLabel *label_08_Visualize_Scale;
    QLabel *label_08_Visualize_Thickness;
    QDoubleSpinBox *doubleSpinBox_08_Visualize_Scale;
    QLabel *label_08_Visualize_Connectivity;
    QFrame *line_08_Visualize;
    QLabel *label_08_Visualize_Feature;
    QComboBox *comboBox_08_Visualize_Feature;
    QSpacerItem *verticalSpacer_08_Visualize;
    QSpacerItem *horizontalSpacer_08_Visualize;
    QSpinBox *spinBox_08_Visualize_Thickness;
    QWidget *page_08_Extract;
    QGridLayout *gridLayout_111;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_5;
    QFrame *line_5;
    QLabel *label_11;
    QComboBox *comboBox_5;
    QComboBox *comboBox_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_9;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *page_Settings_09_Other;
    QGridLayout *gridLayout_26;
    QStackedWidget *stackedWidget_Settings_09_Other;
    QWidget *page_09_Equal_Hist;
    QGridLayout *gridLayout_47;
    QSpacerItem *horizontalSpacer_09_Equal_Hist;
    QFrame *line_09_Equal_Hist;
    QSpacerItem *verticalSpacer_09_Equal_Hist;
    QLabel *label_09_Equal_Hist_1;
    QLabel *label_09_Equal_Hist_2;
    QWidget *page_09_GammaSpread;
    QGridLayout *gridLayout_78;
    QDoubleSpinBox *doubleSpinBox_09_GammaSpread_OutMax;
    QDoubleSpinBox *doubleSpinBox_09_GammaSpread_OutMin;
    QSpacerItem *horizontalSpacer_09_GammaSpread;
    QLabel *label_09_GammaSpread_OutMax;
    QLabel *label_09_GammaSpread_InMax;
    QLabel *label_09_GammaSpread_OutMin;
    QDoubleSpinBox *doubleSpinBox_09_GammaSpread_InMax;
    QDoubleSpinBox *doubleSpinBox_09_GammaSpread_InMin;
    QFrame *line_09_GammaSpread_1;
    QFrame *line_09_GammaSpread_2;
    QDoubleSpinBox *doubleSpinBox_09_GammaSpread_Gamma;
    QSpacerItem *verticalSpacer_09_GammaSpread;
    QFrame *line_09_GammaSpread_3;
    QLabel *label_09_GammaSpread_InMin;
    QLabel *label_09_GammaSpread_Gamma;
    QFrame *line_09_GammaSpread_4;
    QLabel *label_09_GammaSpread_Force8bit;
    QCheckBox *checkBox_09_GammaSpread_Force8bit;
    QWidget *page_09_LabelNo;
    QGridLayout *gridLayout_61;
    QFrame *line_09_LabelNo_1;
    QLabel *label_09_LabelNo_Src1_Title;
    QLabel *label_09_LabelNo_Src1_Desc;
    QSpacerItem *horizontalSpacer_09_LabelNo;
    QLabel *label_09_LabelNo_Src2_Title;
    QLabel *label_09_LabelNo_Src2_Desc;
    QLabel *label_09_LabelNo_Scale;
    QDoubleSpinBox *doubleSpinBox_09_LabelNo_Scale;
    QLabel *label_09_LabelNo_Thickness;
    QSpinBox *spinBox_09_LabelNo_Thickness;
    QLabel *label_09_LabelNo_Position;
    QCheckBox *checkBox_09_LabelNo_Position;
    QFrame *line_09_LabelNo_2;
    QLabel *label_09_LabelNo_Ch1_Title;
    QLabel *label_09_LabelNo_Ch1_Desc;
    QLabel *label_09_LabelNo_Ch2_Title;
    QLabel *label_09_LabelNo_Ch2_Desc;
    QLabel *label_09_LabelNo_Ch3_Title;
    QLabel *label_09_LabelNo_Ch3_Desc;
    QSpacerItem *verticalSpacer_09_LabelNo;
    QWidget *page_09_NeighborhoodConfig;
    QGridLayout *gridLayout_91;
    QFrame *line_09_NeighborhoodConfig;
    QLabel *label_09_NeighborhoodConfig_Euler_Description;
    QLabel *label_09_NeighborhoodConfig_Euler_Number;
    QSpacerItem *verticalSpacer_09_NeighborhoodConfig;
    QSpacerItem *horizontalSpacer_09_NeighborhoodConfig;
    QLabel *label_09_NeighborhoodConfig;
    QWidget *page_09_MotionField;
    QGridLayout *gridLayout_93;
    QSpacerItem *horizontalSpacer_09_MotionField;
    QSpacerItem *verticalSpacer_09_MotionField;
    QFrame *line_09_MotionField;
    QLabel *label_09_MotionField_SizeSpace;
    QLabel *label_09_MotionField_SizeTime;
    QSpinBox *spinBox_09_MotionField_SizeSpace;
    QSpinBox *spinBox_09_MotionField_SizeTime;
    QWidget *page_09_Classifier_kNN;
    QGridLayout *gridLayout_99;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox_09_kNN_n;
    QWidget *page_09_HDR;
    QGridLayout *gridLayout_109;
    QLabel *label_09_HDR_Dimension;
    QDoubleSpinBox *doubleSpinBox_09_HDR_Exposure_Min;
    QLabel *label_09_HDR_ExpFirst_Description;
    QFrame *line_09_HDR_2;
    QComboBox *comboBox_09_HDR_ProjectStat;
    QLabel *label_09_HDR_Project_Description;
    QLabel *label_09_HDR_Range_Description;
    QLabel *label_09_HDR_Dim_Description;
    QLabel *label_09_HDR_Projection;
    QSpacerItem *horizontalSpacer_09_HDR;
    QDoubleSpinBox *doubleSpinBox_09_HDR_Thresh_High;
    QDoubleSpinBox *doubleSpinBox_09_HDR_Exposure_Factor;
    QLabel *label_09_HDR_ExpFactor_Description;
    QFrame *line_09_HDR_1;
    QLabel *label_09_HDR_Thres;
    QComboBox *comboBox_09_HDR_Dim;
    QLabel *label_09_HDR_Stat_Description;
    QLabel *label_09_HDR_Thres_Description;
    QDoubleSpinBox *doubleSpinBox_09_HDR_Thresh_Low;
    QCheckBox *checkBox_09_HDR_Thresh;
    QSpacerItem *verticalSpacer_09_HDR;
    QCheckBox *checkBox_09_HDR_Project;
    QFrame *line_09_HDR_3;
    QLabel *label_09_HDR_Exp;
    QWidget *page_09_RelationStat;
    QGridLayout *gridLayout_112;
    QComboBox *comboBox_09_RelationStat_StatAngle;
    QComboBox *comboBox_09_RelationStat_StatDistance;
    QRadioButton *radioButton_09_RelationStat_Angle;
    QRadioButton *radioButton_09_RelationStat_Distance;
    QLabel *label_09_RelationStat_Distance;
    QLabel *label_09_RelationStat_Angle;
    QSpacerItem *verticalSpacer_09_RelationStat;
    QSpacerItem *horizontalSpacer_09_RelationStat;
    QWidget *page_09_ZernikeStack;
    QGridLayout *gridLayout_114;
    QLabel *label_09_ZernikeStack_Radius;
    QSpinBox *spinBox_09_ZernikeStack_Radius;
    QSpacerItem *horizontalSpacer_09_ZernikeStack;
    QLabel *label_09_ZernikeStack_J;
    QSpinBox *spinBox_09_ZernikeStack_J;
    QSpacerItem *verticalSpacer_09_ZernikeStack;
    QWidget *page_09_InterferometerMichelson;
    QGridLayout *gridLayout_131;
    QGroupBox *groupBox_09_Michelson_Scene_px;
    QGridLayout *gridLayout_136;
    QSpinBox *spinBox_09_Michelson_Scene_Size_X;
    QSpinBox *spinBox_09_Michelson_Scene_Size_Y;
    QSpinBox *spinBox_09_Michelson_Scene_Size_Z;
    QGroupBox *groupBox_09_Michelson_SP;
    QGridLayout *gridLayout_135;
    QLabel *label_09_Michelson_Splitter;
    QSpacerItem *verticalSpacer_09_Michelson;
    QGroupBox *groupBox_09_Michelson_Axis;
    QGridLayout *gridLayout_141;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_22;
    QGroupBox *groupBox_09_Michelson_M1;
    QGridLayout *gridLayout_139;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Mirror1_angle_y;
    QVBoxLayout *verticalLayout_09_Michelson_M1;
    QCheckBox *checkBox_09_Michelson_Beam_atM1_SO;
    QCheckBox *checkBox_09_Michelson_Beam_atM1_M1_SO;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Mirror1_distance;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Mirror1_angle_x;
    QGroupBox *groupBox_09_Michelson_DE;
    QGridLayout *gridLayout_134;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Detector_distance;
    QVBoxLayout *verticalLayout_09_Michelson_DE;
    QCheckBox *checkBox_09_Michelson_Beam_atDE_SP_M1_SO;
    QCheckBox *checkBox_09_Michelson_Beam_atDE_M2_SP_SO;
    QGroupBox *groupBox_09_MichelsonScene_um;
    QGridLayout *gridLayout_137;
    QLabel *label_09_Michelson_SceneSize_Y;
    QLabel *label_09_Michelson_SceneSize_X;
    QLabel *label_09_Michelson_SceneSize_Z;
    QGroupBox *groupBox_09_Michelson_M2;
    QGridLayout *gridLayout_140;
    QVBoxLayout *verticalLayout_09_Michelson_M2;
    QCheckBox *checkBox_09_Michelson_Beam_atM2_SP_SO;
    QCheckBox *checkBox_09_Michelson_Beam_atM2_M2_SP_SO;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Mirror2_distance;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Mirror2_angle_y;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Mirror2_angle_x;
    QGroupBox *groupBox_09_Michelson_SO;
    QGridLayout *gridLayout_133;
    QVBoxLayout *verticalLayout_09_Michelson_SO;
    QCheckBox *checkBox_09_Michelson_Beam_atSO_SO;
    QCheckBox *checkBox_09_Michelson_Beam_atSO_M1_SO;
    QCheckBox *checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Wavelength;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Source_distance;
    QGroupBox *groupBox_09_MichelsonScale;
    QGridLayout *gridLayout_138;
    QDoubleSpinBox *doubleSpinBox_09_Michelson_Scale_um;
    QSpinBox *spinBox_09_Michelson_Scale_px;
    QSpacerItem *horizontalSpacer_09_Michelson;
    QComboBox *comboBox_09_Michelson_Show_IorE;
    QWidget *page_09_RadiometricStereo;
    QGridLayout *gridLayout_115;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_X1;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Y1;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Z3;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Y4;
    QFrame *line_09_RadiometricStereo;
    QLabel *label_09_RadiometricStereo_S4;
    QLabel *label_09_RadiometricStereo_X;
    QLabel *label_09_RadiometricStereo_Y;
    QLabel *label_09_RadiometricStereo_S3;
    QLabel *label_09_RadiometricStereo_S;
    QLabel *label_09_RadiometricStereo_S1;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_X2;
    QLabel *label_09_RadiometricStereo_S2;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Z2;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Y3;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Z1;
    QSpacerItem *horizontalSpacer_09_RadiometricStereo;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Y2;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_X3;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_Z4;
    QLabel *label_09_RadiometricStereo_Z;
    QDoubleSpinBox *doubleSpinBox_09_RadiometricStereo_X4;
    QSpacerItem *verticalSpacer_09_RadiometricStereo;
    QLabel *label_09_RadiometricStereo_OutMode;
    QComboBox *comboBox_09_RadiometricStereo_OutMode;
    QWidget *page_Settings_10_Dimension;
    QGridLayout *gridLayout_50;
    QStackedWidget *stackedWidget_Settings_10_Dimension;
    QWidget *page_10_Dimension_Pick;
    QGridLayout *gridLayout_57;
    QFrame *line_10_Pick;
    QSpacerItem *verticalSpacer_10_Pick;
    QGridLayout *gridLayout_10_Pick;
    QSpinBox *spinBox_10_Pick_Z;
    QCheckBox *checkBox_10_Pick_Z;
    QCheckBox *checkBox_10_Pick_P;
    QSpinBox *spinBox_10_Pick_T;
    QCheckBox *checkBox_10_Pick_X;
    QSpinBox *spinBox_10_Pick_P;
    QCheckBox *checkBox_10_Pick_Y;
    QLabel *label_10_Pick_Pos;
    QSpinBox *spinBox_10_Pick_Y;
    QSpinBox *spinBox_10_Pick_X;
    QCheckBox *checkBox_10_Pick_T;
    QSpinBox *spinBox_10_Pick_S;
    QCheckBox *checkBox_10_Pick_S;
    QLabel *label_10_Pick_Dim;
    QWidget *page_10_Dimension_Crop;
    QGridLayout *gridLayout_51;
    QGridLayout *gridLayout_10_Crop;
    QCheckBox *checkBox_10_Crop_Z;
    QCheckBox *checkBox_10_Crop_X;
    QLabel *label_10_Crop_Min;
    QCheckBox *checkBox_10_Crop_T;
    QSpinBox *spinBox_10_Crop_Min_Y;
    QSpinBox *spinBox_10_Crop_Min_X;
    QLabel *label_10_Crop_Dim;
    QSpinBox *spinBox_10_Crop_Min_S;
    QCheckBox *checkBox_10_Crop_S;
    QCheckBox *checkBox_10_Crop_Y;
    QCheckBox *checkBox_10_Crop_P;
    QSpinBox *spinBox_10_Crop_Min_Z;
    QSpinBox *spinBox_10_Crop_Min_P;
    QSpinBox *spinBox_10_Crop_Min_T;
    QSpinBox *spinBox_10_Crop_Max_X;
    QSpinBox *spinBox_10_Crop_Max_Y;
    QSpinBox *spinBox_10_Crop_Max_Z;
    QSpinBox *spinBox_10_Crop_Max_T;
    QSpinBox *spinBox_10_Crop_Max_S;
    QSpinBox *spinBox_10_Crop_Max_P;
    QLabel *label_10_Crop_Max;
    QSpacerItem *verticalSpacer_10_Crop;
    QFrame *line_10_Crop;
    QWidget *page_10_Dimension_Project;
    QGridLayout *gridLayout_90;
    QFrame *line_10_Project;
    QLabel *label_10_Project_Dimension;
    QComboBox *comboBox_10_Project_Dimension;
    QSpacerItem *horizontalSpacer_10_Project;
    QLabel *label_10_Project_Stat;
    QComboBox *comboBox_10_Project_Stat;
    QSpacerItem *verticalSpacer_10_Project;
    QLabel *label_10_Project_8bit;
    QCheckBox *checkBox_10_Project_8bit;
    QWidget *page_10_Dimension_Deserialise;
    QGridLayout *gridLayout_107;
    QComboBox *comboBox_10_Deserialise_Dimension_In;
    QSpacerItem *verticalSpacer_10_Deserialise;
    QLabel *label_10_Deserialise_Spacing;
    QLabel *label_10_Deserialise_Dimension_In;
    QSpacerItem *horizontalSpacer_10_Deserialise;
    QLabel *label_10_Deserialise_Dimension_Out;
    QComboBox *comboBox_10_Deserialise_Dimension_Out;
    QSpinBox *spinBox_10_Deserialise_Spacing;
    QWidget *page_10_Dimension_Pages2Color;
    QGridLayout *gridLayout_108;
    QLabel *label_10_Page2Color_R;
    QSpinBox *spinBox_10_Page2Color_R;
    QLabel *label_10_Page2Color_G;
    QSpinBox *spinBox_10_Page2Color_G;
    QLabel *label_10_Page2Color_B;
    QSpinBox *spinBox_10_Page2Color_B;
    QSpacerItem *horizontalSpacer_10_Page2Color;
    QSpacerItem *verticalSpacer_10_Page2Color;
    QWidget *page_10_Dimension_Stitching;
    QGridLayout *gridLayout_113;
    QSpacerItem *horizontalSpacer_10_Stitching;
    QLabel *label_10_Stitching_Border_R;
    QSpacerItem *verticalSpacer_10_Stitching;
    QDoubleSpinBox *doubleSpinBox_10_Stitching_Border_R;
    QLabel *label_10_Stitching_Mode;
    QLabel *label_10_Stitching_Border_B;
    QDoubleSpinBox *doubleSpinBox_10_Stitching_Border_B;
    QDoubleSpinBox *doubleSpinBox_10_Stitching_Overlap_R;
    QDoubleSpinBox *doubleSpinBox_10_Stitching_Overlap_B;
    QComboBox *comboBox_10_Stitching_Mode;
    QWidget *page_10_Dimension_Extend;
    QGridLayout *gridLayout_63;
    QFrame *line_2;
    QGridLayout *gridLayout_10_Pick_3;
    QSpinBox *spinBox_10_Pick_Z_3;
    QCheckBox *checkBox_10_Pick_Z_3;
    QCheckBox *checkBox_10_Pick_P_3;
    QSpinBox *spinBox_10_Pick_T_3;
    QCheckBox *checkBox_10_Pick_X_3;
    QSpinBox *spinBox_10_Pick_P_3;
    QCheckBox *checkBox_10_Pick_Y_3;
    QLabel *label_10_Pick_Pos_3;
    QSpinBox *spinBox_10_Pick_Y_3;
    QSpinBox *spinBox_10_Pick_X_3;
    QCheckBox *checkBox_10_Pick_T_3;
    QSpinBox *spinBox_10_Pick_S_3;
    QCheckBox *checkBox_10_Pick_S_3;
    QLabel *label_10_Pick_Dim_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_10_Dimension_Flip;
    QGridLayout *gridLayout_89;
    QFrame *line_3;
    QLabel *label;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_ProcDims;
    QGridLayout *gridLayout_87;
    QCheckBox *checkBox_ProcDims_Z_Proc;
    QCheckBox *checkBox_ProcDims_T_Proc;
    QCheckBox *checkBox_ProcDims_Y_Proc;
    QCheckBox *checkBox_ProcDims_P_Proc;
    QCheckBox *checkBox_ProcDims_X_Proc;
    QCheckBox *checkBox_ProcDims_S_Proc;
    QLabel *label_ProcDims_X;
    QLabel *label_ProcDims_Y;
    QLabel *label_ProcDims_Z;
    QLabel *label_ProcDims_T;
    QLabel *label_ProcDims_S;
    QLabel *label_ProcDims_P;
    QGroupBox *groupBox_Source;
    QGridLayout *gridLayout_2;
    QLabel *label_Source_1;
    QLabel *label_Source_3;
    QSpinBox *spinBox_Source_Pos_3;
    QLabel *label_Source_2;
    QLabel *label_Source_Type_2;
    QSpinBox *spinBox_Source_Pos_2;
    QLabel *label_Source_Type_1;
    QSpinBox *spinBox_Source_Pos_1;
    QLabel *label_Source_Type_3;
    QLabel *label_Source_4;
    QSpinBox *spinBox_Source_Pos_4;
    QLabel *label_Source_Type_4;
    QGroupBox *groupBox_Type_Update;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget_Type_Main;
    QWidget *page_Type_00_Source;
    QGridLayout *gridLayout_4;
    QComboBox *comboBox_Type_00_Source;
    QWidget *page_Type_01_Edit;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox_Type_01_Edit;
    QWidget *page_Type_02_Convert;
    QGridLayout *gridLayout_9;
    QComboBox *comboBox_Type_02_Convert;
    QWidget *page_Type_03_Elemental;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_Type_03_Elemental;
    QWidget *page_Type_04_Filter;
    QGridLayout *gridLayout_11;
    QComboBox *comboBox_Type_04_Filter;
    QWidget *page_Type_05_Morphology;
    QGridLayout *gridLayout_12;
    QComboBox *comboBox_Type_05_Morphology;
    QWidget *page_Type_06_Math;
    QGridLayout *gridLayout_13;
    QComboBox *comboBox_Type_06_Math;
    QWidget *page_Type_07_Transform;
    QGridLayout *gridLayout_14;
    QComboBox *comboBox_Type_07_Transform;
    QWidget *page_Type_08_Feature;
    QGridLayout *gridLayout_15;
    QComboBox *comboBox_Type_08_Feature;
    QWidget *page_Type_09_Other;
    QGridLayout *gridLayout_16;
    QComboBox *comboBox_Type_09_Other;
    QWidget *page_Type_10_Dimension;
    QGridLayout *gridLayout_49;
    QComboBox *comboBox_Type_10_Dimension;
    QComboBox *comboBox_Type_Main;
    QPushButton *pushButton_Update_Step;
    QGroupBox *groupBox_View_Plane;
    QGridLayout *gridLayout_85;
    QComboBox *comboBox_View_Plane;
    QDoubleSpinBox *doubleSpinBox_View_Plane_X;
    QDoubleSpinBox *doubleSpinBox_View_Plane_Y;
    QDoubleSpinBox *doubleSpinBox_View_Plane_Z;
    QDoubleSpinBox *doubleSpinBox_View_Plane_T;
    QDoubleSpinBox *doubleSpinBox_View_Plane_S;
    QDoubleSpinBox *doubleSpinBox_View_Plane_P;
    QSpacerItem *verticalSpacer_View;
    QGroupBox *groupBox_View_Contrast;
    QGridLayout *gridLayout_84;
    QComboBox *comboBox_View_Crop;
    QComboBox *comboBox_View_Transform;
    QDoubleSpinBox *doubleSpinBox_View_Divisor;
    QCheckBox *checkBox_View_VisTrafo;
    QDoubleSpinBox *doubleSpinBox_View_Range;
    QDoubleSpinBox *doubleSpinBox_View_Max;
    QDoubleSpinBox *doubleSpinBox_View_Anchor;
    QComboBox *comboBox_View_Anchor;
    QDoubleSpinBox *doubleSpinBox_View_Gamma;
    QDoubleSpinBox *doubleSpinBox_View_Min;
    QComboBox *comboBox_View_Range;
    QDoubleSpinBox *doubleSpinBox_View_Center;
    QComboBox *comboBox_View_Complex;
    QTabWidget *tabWidget_Output;
    QWidget *tab_Output_Image;
    QGridLayout *gridLayout_27;
    QGraphicsView *graphicsView_Viewer;
    QWidget *tab_Output_Hist;
    QGridLayout *gridLayout_48;
    QGridLayout *gridLayout_Output_Hist;
    QFrame *line_Output_Hist_3;
    QCheckBox *checkBox_Output_Hist_Accumulate;
    QSpacerItem *horizontalSpacer_Output_Hist;
    QCheckBox *checkBox_Output_Hist_Uniform;
    QPushButton *pushButton_Update_Hist;
    QLabel *label_HistClasses;
    QFrame *line_Hist;
    QSpinBox *spinBox_HistClasses;
    QCheckBox *checkBox_Output_Hist_Full6D;
    QWidget *tab_Output_Times;
    QGridLayout *gridLayout_46;
    QFrame *line_Output_Times;
    QSpacerItem *horizontalSpacer_Output_Times;
    QPushButton *pushButton_Update_Times;
    QGridLayout *gridLayout_Output_Times;
    QCheckBox *checkBox_Output_Times_Processing;
    QCheckBox *checkBox_Output_Times_Hist;
    QCheckBox *checkBox_Output_Times_Show;
    QCheckBox *checkBox_Output_Times_Conversion;
    QWidget *tab_Output_Chain_Info;
    QGridLayout *gridLayout_44;
    QLabel *label_Cahin_Pos;
    QLabel *label_Chain_Source_of;
    QLabel *label_Chain_Sources_Used;
    QLabel *label_Chain_Sources_Used_List;
    QLabel *label_Chain_Source_of_List;
    QSpacerItem *verticalSpacer_Chain;
    QSpacerItem *horizontalSpacer_Chain;
    QLabel *label_Chain_Pos_Val;
    QLabel *label_Chain_Updated;
    QLabel *label_Chain_Updated_Val;
    QWidget *tab_Output_FunctionView;
    QGridLayout *gridLayout_110;
    QComboBox *comboBox_FunctionView_Mode;
    QGridLayout *gridLayout_FunctionView;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QMenu *menuViewer;
    QMenu *menuLayout;
    QMenu *menuUpdate;
    QMenu *menuData;
    QMenu *menuWindow;
    QMenu *menuHistogram;
    QMenu *menuTimes;
    QMenu *menuTest;
    QMenu *menuMeasure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_StepWindow)
    {
        if (D_StepWindow->objectName().isEmpty())
            D_StepWindow->setObjectName(QString::fromUtf8("D_StepWindow"));
        D_StepWindow->resize(594, 759);
        action_Smooth_Transformation = new QAction(D_StepWindow);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_StepWindow);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Show_STUD = new QAction(D_StepWindow);
        action_Show_STUD->setObjectName(QString::fromUtf8("action_Show_STUD"));
        action_Show_STUD->setCheckable(true);
        action_Show_STUD->setChecked(true);
        action_Show_Settings = new QAction(D_StepWindow);
        action_Show_Settings->setObjectName(QString::fromUtf8("action_Show_Settings"));
        action_Show_Settings->setCheckable(true);
        action_Show_Settings->setChecked(true);
        action_Show_ViewOptions = new QAction(D_StepWindow);
        action_Show_ViewOptions->setObjectName(QString::fromUtf8("action_Show_ViewOptions"));
        action_Show_ViewOptions->setCheckable(true);
        action_Show_ViewOptions->setChecked(true);
        action_Show_Output = new QAction(D_StepWindow);
        action_Show_Output->setObjectName(QString::fromUtf8("action_Show_Output"));
        action_Show_Output->setCheckable(true);
        action_Show_Output->setChecked(true);
        action_Update_Step = new QAction(D_StepWindow);
        action_Update_Step->setObjectName(QString::fromUtf8("action_Update_Step"));
        action_Skip_Chain_Update = new QAction(D_StepWindow);
        action_Skip_Chain_Update->setObjectName(QString::fromUtf8("action_Skip_Chain_Update"));
        action_Skip_Chain_Update->setCheckable(true);
        action_Save_Image = new QAction(D_StepWindow);
        action_Save_Image->setObjectName(QString::fromUtf8("action_Save_Image"));
        action_Show_Minimized = new QAction(D_StepWindow);
        action_Show_Minimized->setObjectName(QString::fromUtf8("action_Show_Minimized"));
        action_Show_Maximize = new QAction(D_StepWindow);
        action_Show_Maximize->setObjectName(QString::fromUtf8("action_Show_Maximize"));
        action_Show_Normal = new QAction(D_StepWindow);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Fullscreen = new QAction(D_StepWindow);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Update_Hist = new QAction(D_StepWindow);
        action_Update_Hist->setObjectName(QString::fromUtf8("action_Update_Hist"));
        action_Autoupdate_Hist_on_Step = new QAction(D_StepWindow);
        action_Autoupdate_Hist_on_Step->setObjectName(QString::fromUtf8("action_Autoupdate_Hist_on_Step"));
        action_Autoupdate_Hist_on_Step->setCheckable(true);
        action_Autoupdate_Hist_on_HistSettings = new QAction(D_StepWindow);
        action_Autoupdate_Hist_on_HistSettings->setObjectName(QString::fromUtf8("action_Autoupdate_Hist_on_HistSettings"));
        action_Autoupdate_Hist_on_HistSettings->setCheckable(true);
        action_Autoupdate_Hist_on_HistSettings->setChecked(true);
        action_Autoupdate_Times_on_Step = new QAction(D_StepWindow);
        action_Autoupdate_Times_on_Step->setObjectName(QString::fromUtf8("action_Autoupdate_Times_on_Step"));
        action_Autoupdate_Times_on_Step->setCheckable(true);
        action_Update_Times = new QAction(D_StepWindow);
        action_Update_Times->setObjectName(QString::fromUtf8("action_Update_Times"));
        action_Autoupdate_Times_on_TimesSettings = new QAction(D_StepWindow);
        action_Autoupdate_Times_on_TimesSettings->setObjectName(QString::fromUtf8("action_Autoupdate_Times_on_TimesSettings"));
        action_Autoupdate_Times_on_TimesSettings->setCheckable(true);
        action_Autoupdate_Times_on_TimesSettings->setChecked(true);
        action_Autoupdate_Next_Step = new QAction(D_StepWindow);
        action_Autoupdate_Next_Step->setObjectName(QString::fromUtf8("action_Autoupdate_Next_Step"));
        action_Autoupdate_Next_Step->setCheckable(true);
        action_Autoupdate_Next_Step->setChecked(false);
        action_Autoupdate_Next_Step->setEnabled(true);
        action_Autoupdate_ImgProc_on_Settings = new QAction(D_StepWindow);
        action_Autoupdate_ImgProc_on_Settings->setObjectName(QString::fromUtf8("action_Autoupdate_ImgProc_on_Settings"));
        action_Autoupdate_ImgProc_on_Settings->setCheckable(true);
        action_Autoupdate_ImgProc_on_Settings->setChecked(true);
        action_Change_Title = new QAction(D_StepWindow);
        action_Change_Title->setObjectName(QString::fromUtf8("action_Change_Title"));
        action_Change_Title->setCheckable(true);
        action_Features_Visualisation = new QAction(D_StepWindow);
        action_Features_Visualisation->setObjectName(QString::fromUtf8("action_Features_Visualisation"));
        action_SaveScreenshot = new QAction(D_StepWindow);
        action_SaveScreenshot->setObjectName(QString::fromUtf8("action_SaveScreenshot"));
        action_Measure_Line_Distance = new QAction(D_StepWindow);
        action_Measure_Line_Distance->setObjectName(QString::fromUtf8("action_Measure_Line_Distance"));
        action_Save_Feature_List = new QAction(D_StepWindow);
        action_Save_Feature_List->setObjectName(QString::fromUtf8("action_Save_Feature_List"));
        action_connect_plane_position_to_other_steps = new QAction(D_StepWindow);
        action_connect_plane_position_to_other_steps->setObjectName(QString::fromUtf8("action_connect_plane_position_to_other_steps"));
        action_connect_plane_position_to_other_steps->setCheckable(true);
        action_connect_plane_position_to_other_steps->setChecked(true);
        action_Connect_Steps_Zoom = new QAction(D_StepWindow);
        action_Connect_Steps_Zoom->setObjectName(QString::fromUtf8("action_Connect_Steps_Zoom"));
        action_Connect_Steps_Zoom->setCheckable(true);
        action_Connect_Steps_Zoom->setChecked(true);
        action_Zoom_In = new QAction(D_StepWindow);
        action_Zoom_In->setObjectName(QString::fromUtf8("action_Zoom_In"));
        action_Zoom_Out = new QAction(D_StepWindow);
        action_Zoom_Out->setObjectName(QString::fromUtf8("action_Zoom_Out"));
        action_Zoom_Reset = new QAction(D_StepWindow);
        action_Zoom_Reset->setObjectName(QString::fromUtf8("action_Zoom_Reset"));
        action_Save_Analysis = new QAction(D_StepWindow);
        action_Save_Analysis->setObjectName(QString::fromUtf8("action_Save_Analysis"));
        action_Save_Image_List = new QAction(D_StepWindow);
        action_Save_Image_List->setObjectName(QString::fromUtf8("action_Save_Image_List"));
        action_Save_Image_List->setEnabled(true);
        action_Save_asBinary = new QAction(D_StepWindow);
        action_Save_asBinary->setObjectName(QString::fromUtf8("action_Save_asBinary"));
        centralwidget = new QWidget(D_StepWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, -1);
        groupBox_Settings = new QGroupBox(centralwidget);
        groupBox_Settings->setObjectName(QString::fromUtf8("groupBox_Settings"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Settings->sizePolicy().hasHeightForWidth());
        groupBox_Settings->setSizePolicy(sizePolicy);
        groupBox_Settings->setMinimumSize(QSize(0, 253));
        groupBox_Settings->setMaximumSize(QSize(16777215, 253));
        gridLayout_7 = new QGridLayout(groupBox_Settings);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(3, 3, 3, 3);
        stackedWidget_Main_Settings = new QStackedWidget(groupBox_Settings);
        stackedWidget_Main_Settings->setObjectName(QString::fromUtf8("stackedWidget_Main_Settings"));
        stackedWidget_Main_Settings->setLineWidth(1);
        page_Settings_00_Source = new QWidget();
        page_Settings_00_Source->setObjectName(QString::fromUtf8("page_Settings_00_Source"));
        gridLayout_17 = new QGridLayout(page_Settings_00_Source);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_00_Source = new QStackedWidget(page_Settings_00_Source);
        stackedWidget_Settings_00_Source->setObjectName(QString::fromUtf8("stackedWidget_Settings_00_Source"));
        page_00_Load = new QWidget();
        page_00_Load->setObjectName(QString::fromUtf8("page_00_Load"));
        gridLayout_28 = new QGridLayout(page_00_Load);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        comboBox_00_Load_Mode = new QComboBox(page_00_Load);
        comboBox_00_Load_Mode->setObjectName(QString::fromUtf8("comboBox_00_Load_Mode"));

        gridLayout_28->addWidget(comboBox_00_Load_Mode, 1, 2, 1, 3);

        comboBox_00_Load_Source_Dim_List = new QComboBox(page_00_Load);
        comboBox_00_Load_Source_Dim_List->setObjectName(QString::fromUtf8("comboBox_00_Load_Source_Dim_List"));
        comboBox_00_Load_Source_Dim_List->setEnabled(false);
        comboBox_00_Load_Source_Dim_List->setMinimumSize(QSize(100, 0));
        comboBox_00_Load_Source_Dim_List->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(comboBox_00_Load_Source_Dim_List, 6, 2, 1, 1);

        label_00_Load__Dim_Target = new QLabel(page_00_Load);
        label_00_Load__Dim_Target->setObjectName(QString::fromUtf8("label_00_Load__Dim_Target"));
        label_00_Load__Dim_Target->setMinimumSize(QSize(100, 0));
        label_00_Load__Dim_Target->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(label_00_Load__Dim_Target, 3, 2, 1, 1);

        comboBox_00_Load_Source_Dim_X = new QComboBox(page_00_Load);
        comboBox_00_Load_Source_Dim_X->setObjectName(QString::fromUtf8("comboBox_00_Load_Source_Dim_X"));
        comboBox_00_Load_Source_Dim_X->setMinimumSize(QSize(100, 0));
        comboBox_00_Load_Source_Dim_X->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(comboBox_00_Load_Source_Dim_X, 4, 2, 1, 1);

        label_00_Load_Pages = new QLabel(page_00_Load);
        label_00_Load_Pages->setObjectName(QString::fromUtf8("label_00_Load_Pages"));
        label_00_Load_Pages->setEnabled(true);

        gridLayout_28->addWidget(label_00_Load_Pages, 7, 1, 1, 1);

        label_00_Load_Dim_Source = new QLabel(page_00_Load);
        label_00_Load_Dim_Source->setObjectName(QString::fromUtf8("label_00_Load_Dim_Source"));

        gridLayout_28->addWidget(label_00_Load_Dim_Source, 3, 1, 1, 1);

        label_00_Load_X_Img = new QLabel(page_00_Load);
        label_00_Load_X_Img->setObjectName(QString::fromUtf8("label_00_Load_X_Img"));

        gridLayout_28->addWidget(label_00_Load_X_Img, 4, 1, 1, 1);

        comboBox_00_Load_Source_Dim_Y = new QComboBox(page_00_Load);
        comboBox_00_Load_Source_Dim_Y->setObjectName(QString::fromUtf8("comboBox_00_Load_Source_Dim_Y"));
        comboBox_00_Load_Source_Dim_Y->setMinimumSize(QSize(100, 0));
        comboBox_00_Load_Source_Dim_Y->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(comboBox_00_Load_Source_Dim_Y, 5, 2, 1, 1);

        comboBox_00_Load_Source_Dim_Pages = new QComboBox(page_00_Load);
        comboBox_00_Load_Source_Dim_Pages->setObjectName(QString::fromUtf8("comboBox_00_Load_Source_Dim_Pages"));
        comboBox_00_Load_Source_Dim_Pages->setEnabled(false);
        comboBox_00_Load_Source_Dim_Pages->setMinimumSize(QSize(100, 0));
        comboBox_00_Load_Source_Dim_Pages->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(comboBox_00_Load_Source_Dim_Pages, 7, 2, 1, 1);

        pushButton_00_Load_Image = new QPushButton(page_00_Load);
        pushButton_00_Load_Image->setObjectName(QString::fromUtf8("pushButton_00_Load_Image"));
        sizePolicy.setHeightForWidth(pushButton_00_Load_Image->sizePolicy().hasHeightForWidth());
        pushButton_00_Load_Image->setSizePolicy(sizePolicy);
        pushButton_00_Load_Image->setMinimumSize(QSize(100, 0));
        pushButton_00_Load_Image->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(pushButton_00_Load_Image, 0, 2, 1, 1);

        verticalSpacer_00_Load = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(verticalSpacer_00_Load, 9, 1, 1, 1);

        line_00_Load_1 = new QFrame(page_00_Load);
        line_00_Load_1->setObjectName(QString::fromUtf8("line_00_Load_1"));
        line_00_Load_1->setFrameShape(QFrame::VLine);
        line_00_Load_1->setFrameShadow(QFrame::Sunken);

        gridLayout_28->addWidget(line_00_Load_1, 0, 0, 10, 1);

        line_00_Load_2 = new QFrame(page_00_Load);
        line_00_Load_2->setObjectName(QString::fromUtf8("line_00_Load_2"));
        line_00_Load_2->setFrameShape(QFrame::HLine);
        line_00_Load_2->setFrameShadow(QFrame::Sunken);

        gridLayout_28->addWidget(line_00_Load_2, 2, 1, 1, 4);

        label_00_Load_List = new QLabel(page_00_Load);
        label_00_Load_List->setObjectName(QString::fromUtf8("label_00_Load_List"));
        label_00_Load_List->setEnabled(true);

        gridLayout_28->addWidget(label_00_Load_List, 6, 1, 1, 1);

        label_00_Load_Browse = new QLabel(page_00_Load);
        label_00_Load_Browse->setObjectName(QString::fromUtf8("label_00_Load_Browse"));
        label_00_Load_Browse->setMinimumSize(QSize(75, 0));
        label_00_Load_Browse->setMaximumSize(QSize(75, 16777215));

        gridLayout_28->addWidget(label_00_Load_Browse, 0, 1, 1, 1);

        label_00_Load_Mode = new QLabel(page_00_Load);
        label_00_Load_Mode->setObjectName(QString::fromUtf8("label_00_Load_Mode"));

        gridLayout_28->addWidget(label_00_Load_Mode, 1, 1, 1, 1);

        label_00_Load_Y_Img = new QLabel(page_00_Load);
        label_00_Load_Y_Img->setObjectName(QString::fromUtf8("label_00_Load_Y_Img"));

        gridLayout_28->addWidget(label_00_Load_Y_Img, 5, 1, 1, 1);

        comboBox_00_Load_Source_Dim_T = new QComboBox(page_00_Load);
        comboBox_00_Load_Source_Dim_T->setObjectName(QString::fromUtf8("comboBox_00_Load_Source_Dim_T"));
        comboBox_00_Load_Source_Dim_T->setEnabled(false);
        comboBox_00_Load_Source_Dim_T->setMinimumSize(QSize(100, 0));
        comboBox_00_Load_Source_Dim_T->setMaximumSize(QSize(100, 16777215));

        gridLayout_28->addWidget(comboBox_00_Load_Source_Dim_T, 8, 2, 1, 1);

        horizontalSpacer_00_Load = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_28->addItem(horizontalSpacer_00_Load, 5, 4, 1, 1);

        label_2 = new QLabel(page_00_Load);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_28->addWidget(label_2, 8, 1, 1, 1);

        checkBox_00_Load_Force8UC1 = new QCheckBox(page_00_Load);
        checkBox_00_Load_Force8UC1->setObjectName(QString::fromUtf8("checkBox_00_Load_Force8UC1"));
        checkBox_00_Load_Force8UC1->setEnabled(false);

        gridLayout_28->addWidget(checkBox_00_Load_Force8UC1, 0, 3, 1, 1);

        stackedWidget_Settings_00_Source->addWidget(page_00_Load);
        page_00_Duplicate = new QWidget();
        page_00_Duplicate->setObjectName(QString::fromUtf8("page_00_Duplicate"));
        gridLayout_34 = new QGridLayout(page_00_Duplicate);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        line_00_Dupl = new QFrame(page_00_Duplicate);
        line_00_Dupl->setObjectName(QString::fromUtf8("line_00_Dupl"));
        line_00_Dupl->setFrameShape(QFrame::VLine);
        line_00_Dupl->setFrameShadow(QFrame::Sunken);

        gridLayout_34->addWidget(line_00_Dupl, 0, 0, 1, 1);

        horizontalSpacer_00_Dupl = new QSpacerItem(605, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_34->addItem(horizontalSpacer_00_Dupl, 0, 1, 1, 1);

        stackedWidget_Settings_00_Source->addWidget(page_00_Duplicate);
        page_00_Sample = new QWidget();
        page_00_Sample->setObjectName(QString::fromUtf8("page_00_Sample"));
        gridLayout_6 = new QGridLayout(page_00_Sample);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        line_00_Sample = new QFrame(page_00_Sample);
        line_00_Sample->setObjectName(QString::fromUtf8("line_00_Sample"));
        line_00_Sample->setFrameShape(QFrame::VLine);
        line_00_Sample->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_00_Sample, 0, 0, 3, 1);

        pushButton_00_Sample_Select_Directory = new QPushButton(page_00_Sample);
        pushButton_00_Sample_Select_Directory->setObjectName(QString::fromUtf8("pushButton_00_Sample_Select_Directory"));
        pushButton_00_Sample_Select_Directory->setMinimumSize(QSize(100, 0));
        pushButton_00_Sample_Select_Directory->setMaximumSize(QSize(100, 16777215));

        gridLayout_6->addWidget(pushButton_00_Sample_Select_Directory, 1, 2, 1, 1);

        verticalSpacer_00_Sample = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_00_Sample, 2, 2, 1, 1);

        comboBox_00_Sample_Paths = new QComboBox(page_00_Sample);
        comboBox_00_Sample_Paths->setObjectName(QString::fromUtf8("comboBox_00_Sample_Paths"));
        comboBox_00_Sample_Paths->setMaximumSize(QSize(394, 16777215));

        gridLayout_6->addWidget(comboBox_00_Sample_Paths, 0, 2, 1, 3);

        label_00_Sample_Directory = new QLabel(page_00_Sample);
        label_00_Sample_Directory->setObjectName(QString::fromUtf8("label_00_Sample_Directory"));
        label_00_Sample_Directory->setMaximumSize(QSize(288, 16777215));

        gridLayout_6->addWidget(label_00_Sample_Directory, 1, 3, 1, 2);

        stackedWidget_Settings_00_Source->addWidget(page_00_Sample);
        page_00_Generate = new QWidget();
        page_00_Generate->setObjectName(QString::fromUtf8("page_00_Generate"));
        gridLayout_77 = new QGridLayout(page_00_Generate);
        gridLayout_77->setSpacing(3);
        gridLayout_77->setObjectName(QString::fromUtf8("gridLayout_77"));
        gridLayout_77->setContentsMargins(6, 6, 6, 6);
        label_00_Generate_DimVar = new QLabel(page_00_Generate);
        label_00_Generate_DimVar->setObjectName(QString::fromUtf8("label_00_Generate_DimVar"));
        label_00_Generate_DimVar->setMinimumSize(QSize(75, 0));
        label_00_Generate_DimVar->setMaximumSize(QSize(75, 16777215));

        gridLayout_77->addWidget(label_00_Generate_DimVar, 1, 1, 1, 1);

        verticalSpacer_00_Generate = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_77->addItem(verticalSpacer_00_Generate, 8, 2, 1, 1);

        line_00_Generate_2 = new QFrame(page_00_Generate);
        line_00_Generate_2->setObjectName(QString::fromUtf8("line_00_Generate_2"));
        line_00_Generate_2->setFrameShape(QFrame::HLine);
        line_00_Generate_2->setFrameShadow(QFrame::Sunken);

        gridLayout_77->addWidget(line_00_Generate_2, 3, 1, 1, 3);

        label_00_Generate_Size = new QLabel(page_00_Generate);
        label_00_Generate_Size->setObjectName(QString::fromUtf8("label_00_Generate_Size"));
        label_00_Generate_Size->setMinimumSize(QSize(75, 0));
        label_00_Generate_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_77->addWidget(label_00_Generate_Size, 2, 1, 1, 1);

        comboBox_00_Generate_DimVar = new QComboBox(page_00_Generate);
        comboBox_00_Generate_DimVar->addItem(QString());
        comboBox_00_Generate_DimVar->addItem(QString());
        comboBox_00_Generate_DimVar->addItem(QString());
        comboBox_00_Generate_DimVar->setObjectName(QString::fromUtf8("comboBox_00_Generate_DimVar"));

        gridLayout_77->addWidget(comboBox_00_Generate_DimVar, 1, 2, 1, 2);

        line_00_Generate_1 = new QFrame(page_00_Generate);
        line_00_Generate_1->setObjectName(QString::fromUtf8("line_00_Generate_1"));
        line_00_Generate_1->setFrameShape(QFrame::VLine);
        line_00_Generate_1->setFrameShadow(QFrame::Sunken);

        gridLayout_77->addWidget(line_00_Generate_1, 0, 0, 9, 1);

        gridLayout_00_Generate_Size = new QGridLayout();
        gridLayout_00_Generate_Size->setSpacing(1);
        gridLayout_00_Generate_Size->setObjectName(QString::fromUtf8("gridLayout_00_Generate_Size"));
        spinBox_00_Generate_Size_Z = new QSpinBox(page_00_Generate);
        spinBox_00_Generate_Size_Z->setObjectName(QString::fromUtf8("spinBox_00_Generate_Size_Z"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_00_Generate_Size_Z->sizePolicy().hasHeightForWidth());
        spinBox_00_Generate_Size_Z->setSizePolicy(sizePolicy1);
        spinBox_00_Generate_Size_Z->setMinimumSize(QSize(0, 18));
        spinBox_00_Generate_Size_Z->setMaximumSize(QSize(16777215, 18));
        spinBox_00_Generate_Size_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Generate_Size_Z->setMinimum(1);
        spinBox_00_Generate_Size_Z->setMaximum(999999);

        gridLayout_00_Generate_Size->addWidget(spinBox_00_Generate_Size_Z, 0, 2, 1, 1);

        spinBox_00_Generate_Size_Y = new QSpinBox(page_00_Generate);
        spinBox_00_Generate_Size_Y->setObjectName(QString::fromUtf8("spinBox_00_Generate_Size_Y"));
        sizePolicy1.setHeightForWidth(spinBox_00_Generate_Size_Y->sizePolicy().hasHeightForWidth());
        spinBox_00_Generate_Size_Y->setSizePolicy(sizePolicy1);
        spinBox_00_Generate_Size_Y->setMinimumSize(QSize(0, 18));
        spinBox_00_Generate_Size_Y->setMaximumSize(QSize(16777215, 18));
        spinBox_00_Generate_Size_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Generate_Size_Y->setMinimum(1);
        spinBox_00_Generate_Size_Y->setMaximum(999999);
        spinBox_00_Generate_Size_Y->setValue(10);

        gridLayout_00_Generate_Size->addWidget(spinBox_00_Generate_Size_Y, 0, 1, 1, 1);

        spinBox_00_Generate_Size_X = new QSpinBox(page_00_Generate);
        spinBox_00_Generate_Size_X->setObjectName(QString::fromUtf8("spinBox_00_Generate_Size_X"));
        sizePolicy1.setHeightForWidth(spinBox_00_Generate_Size_X->sizePolicy().hasHeightForWidth());
        spinBox_00_Generate_Size_X->setSizePolicy(sizePolicy1);
        spinBox_00_Generate_Size_X->setMinimumSize(QSize(0, 18));
        spinBox_00_Generate_Size_X->setMaximumSize(QSize(16777215, 18));
        spinBox_00_Generate_Size_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Generate_Size_X->setMinimum(1);
        spinBox_00_Generate_Size_X->setMaximum(999999);
        spinBox_00_Generate_Size_X->setValue(10);

        gridLayout_00_Generate_Size->addWidget(spinBox_00_Generate_Size_X, 0, 0, 1, 1);

        spinBox_00_Generate_Size_T = new QSpinBox(page_00_Generate);
        spinBox_00_Generate_Size_T->setObjectName(QString::fromUtf8("spinBox_00_Generate_Size_T"));
        sizePolicy1.setHeightForWidth(spinBox_00_Generate_Size_T->sizePolicy().hasHeightForWidth());
        spinBox_00_Generate_Size_T->setSizePolicy(sizePolicy1);
        spinBox_00_Generate_Size_T->setMinimumSize(QSize(0, 18));
        spinBox_00_Generate_Size_T->setMaximumSize(QSize(16777215, 18));
        spinBox_00_Generate_Size_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Generate_Size_T->setMinimum(1);
        spinBox_00_Generate_Size_T->setMaximum(999999);

        gridLayout_00_Generate_Size->addWidget(spinBox_00_Generate_Size_T, 0, 3, 1, 1);

        spinBox_00_Generate_Size_S = new QSpinBox(page_00_Generate);
        spinBox_00_Generate_Size_S->setObjectName(QString::fromUtf8("spinBox_00_Generate_Size_S"));
        sizePolicy1.setHeightForWidth(spinBox_00_Generate_Size_S->sizePolicy().hasHeightForWidth());
        spinBox_00_Generate_Size_S->setSizePolicy(sizePolicy1);
        spinBox_00_Generate_Size_S->setMinimumSize(QSize(0, 18));
        spinBox_00_Generate_Size_S->setMaximumSize(QSize(16777215, 18));
        spinBox_00_Generate_Size_S->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Generate_Size_S->setMinimum(1);
        spinBox_00_Generate_Size_S->setMaximum(999999);

        gridLayout_00_Generate_Size->addWidget(spinBox_00_Generate_Size_S, 0, 4, 1, 1);

        spinBox_00_Generate_Size_P = new QSpinBox(page_00_Generate);
        spinBox_00_Generate_Size_P->setObjectName(QString::fromUtf8("spinBox_00_Generate_Size_P"));
        sizePolicy1.setHeightForWidth(spinBox_00_Generate_Size_P->sizePolicy().hasHeightForWidth());
        spinBox_00_Generate_Size_P->setSizePolicy(sizePolicy1);
        spinBox_00_Generate_Size_P->setMinimumSize(QSize(0, 18));
        spinBox_00_Generate_Size_P->setMaximumSize(QSize(16777215, 18));
        spinBox_00_Generate_Size_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Generate_Size_P->setMinimum(1);
        spinBox_00_Generate_Size_P->setMaximum(999999);

        gridLayout_00_Generate_Size->addWidget(spinBox_00_Generate_Size_P, 0, 5, 1, 1);


        gridLayout_77->addLayout(gridLayout_00_Generate_Size, 2, 2, 1, 2);

        stackedWidget_00_Generate_DimVar = new QStackedWidget(page_00_Generate);
        stackedWidget_00_Generate_DimVar->setObjectName(QString::fromUtf8("stackedWidget_00_Generate_DimVar"));
        page_00_Generate_DimVar_2D = new QWidget();
        page_00_Generate_DimVar_2D->setObjectName(QString::fromUtf8("page_00_Generate_DimVar_2D"));
        gridLayout_102 = new QGridLayout(page_00_Generate_DimVar_2D);
        gridLayout_102->setSpacing(3);
        gridLayout_102->setObjectName(QString::fromUtf8("gridLayout_102"));
        gridLayout_102->setContentsMargins(0, 0, 0, 0);
        gridLayout_00_Generate_Parameters_2D = new QGridLayout();
        gridLayout_00_Generate_Parameters_2D->setSpacing(1);
        gridLayout_00_Generate_Parameters_2D->setObjectName(QString::fromUtf8("gridLayout_00_Generate_Parameters_2D"));
        doubleSpinBox_00_Generate_2D_a = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_a->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_a->setFrame(false);
        doubleSpinBox_00_Generate_2D_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_a->setDecimals(3);
        doubleSpinBox_00_Generate_2D_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_a->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_a, 0, 0, 1, 1);

        doubleSpinBox_00_Generate_2D_e = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_e->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_e->setFrame(false);
        doubleSpinBox_00_Generate_2D_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_e->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_e, 1, 0, 1, 1);

        doubleSpinBox_00_Generate_2D_inf = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_inf->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_inf->setFrame(false);
        doubleSpinBox_00_Generate_2D_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_inf->setDecimals(3);
        doubleSpinBox_00_Generate_2D_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_inf->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_inf, 1, 3, 1, 1);

        doubleSpinBox_00_Generate_2D_c = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_c->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_c->setFrame(false);
        doubleSpinBox_00_Generate_2D_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_c->setDecimals(3);
        doubleSpinBox_00_Generate_2D_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_c->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_c, 0, 2, 1, 1);

        doubleSpinBox_00_Generate_2D_nan = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_nan->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_nan->setFrame(false);
        doubleSpinBox_00_Generate_2D_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_nan->setDecimals(3);
        doubleSpinBox_00_Generate_2D_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_nan->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_nan, 1, 2, 1, 1);

        doubleSpinBox_00_Generate_2D_f = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_f->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_f->setFrame(false);
        doubleSpinBox_00_Generate_2D_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_f->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_f, 1, 1, 1, 1);

        doubleSpinBox_00_Generate_2D_b = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_b->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_b->setFrame(false);
        doubleSpinBox_00_Generate_2D_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_b->setDecimals(3);
        doubleSpinBox_00_Generate_2D_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_b->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_b->setValue(0.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_b, 0, 1, 1, 1);

        doubleSpinBox_00_Generate_2D_d = new QDoubleSpinBox(page_00_Generate_DimVar_2D);
        doubleSpinBox_00_Generate_2D_d->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_d->setFrame(false);
        doubleSpinBox_00_Generate_2D_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_d->setDecimals(3);
        doubleSpinBox_00_Generate_2D_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_d->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_d->setValue(0.000000000000000);

        gridLayout_00_Generate_Parameters_2D->addWidget(doubleSpinBox_00_Generate_2D_d, 0, 3, 1, 1);


        gridLayout_102->addLayout(gridLayout_00_Generate_Parameters_2D, 1, 1, 1, 1);

        label_00_Generate_Parameters = new QLabel(page_00_Generate_DimVar_2D);
        label_00_Generate_Parameters->setObjectName(QString::fromUtf8("label_00_Generate_Parameters"));
        label_00_Generate_Parameters->setMinimumSize(QSize(75, 0));
        label_00_Generate_Parameters->setMaximumSize(QSize(75, 16777215));

        gridLayout_102->addWidget(label_00_Generate_Parameters, 1, 0, 1, 1);

        comboBox_00_Generate_ValueFunction_2D = new QComboBox(page_00_Generate_DimVar_2D);
        comboBox_00_Generate_ValueFunction_2D->setObjectName(QString::fromUtf8("comboBox_00_Generate_ValueFunction_2D"));

        gridLayout_102->addWidget(comboBox_00_Generate_ValueFunction_2D, 0, 1, 1, 1);

        label_00_Generate_ValuesFunction = new QLabel(page_00_Generate_DimVar_2D);
        label_00_Generate_ValuesFunction->setObjectName(QString::fromUtf8("label_00_Generate_ValuesFunction"));
        label_00_Generate_ValuesFunction->setMinimumSize(QSize(75, 0));
        label_00_Generate_ValuesFunction->setMaximumSize(QSize(75, 16777215));

        gridLayout_102->addWidget(label_00_Generate_ValuesFunction, 0, 0, 1, 1);

        verticalSpacer_00_Generate_2D = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_102->addItem(verticalSpacer_00_Generate_2D, 2, 0, 1, 2);

        stackedWidget_00_Generate_DimVar->addWidget(page_00_Generate_DimVar_2D);
        page_00_Generate_00_Parameters_2D_Complex = new QWidget();
        page_00_Generate_00_Parameters_2D_Complex->setObjectName(QString::fromUtf8("page_00_Generate_00_Parameters_2D_Complex"));
        gridLayout_118 = new QGridLayout(page_00_Generate_00_Parameters_2D_Complex);
        gridLayout_118->setSpacing(1);
        gridLayout_118->setObjectName(QString::fromUtf8("gridLayout_118"));
        gridLayout_118->setContentsMargins(0, 0, 0, 0);
        comboBox_00_Generate_ValueFunction_2D_Complex = new QComboBox(page_00_Generate_00_Parameters_2D_Complex);
        comboBox_00_Generate_ValueFunction_2D_Complex->setObjectName(QString::fromUtf8("comboBox_00_Generate_ValueFunction_2D_Complex"));

        gridLayout_118->addWidget(comboBox_00_Generate_ValueFunction_2D_Complex, 0, 1, 1, 1);

        label_00_Generate_Parameters_Complex = new QLabel(page_00_Generate_00_Parameters_2D_Complex);
        label_00_Generate_Parameters_Complex->setObjectName(QString::fromUtf8("label_00_Generate_Parameters_Complex"));
        label_00_Generate_Parameters_Complex->setMinimumSize(QSize(75, 0));
        label_00_Generate_Parameters_Complex->setMaximumSize(QSize(75, 16777215));

        gridLayout_118->addWidget(label_00_Generate_Parameters_Complex, 1, 0, 1, 1);

        label_00_Generate_ValuesFunction_Complex = new QLabel(page_00_Generate_00_Parameters_2D_Complex);
        label_00_Generate_ValuesFunction_Complex->setObjectName(QString::fromUtf8("label_00_Generate_ValuesFunction_Complex"));
        label_00_Generate_ValuesFunction_Complex->setMinimumSize(QSize(75, 0));
        label_00_Generate_ValuesFunction_Complex->setMaximumSize(QSize(75, 16777215));

        gridLayout_118->addWidget(label_00_Generate_ValuesFunction_Complex, 0, 0, 1, 1);

        gridLayout_00_Generate_Parameters_2D_Complex = new QGridLayout();
        gridLayout_00_Generate_Parameters_2D_Complex->setSpacing(1);
        gridLayout_00_Generate_Parameters_2D_Complex->setObjectName(QString::fromUtf8("gridLayout_00_Generate_Parameters_2D_Complex"));
        doubleSpinBox_00_Generate_2D_Complex_e = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_e->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_e->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_e->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_e, 3, 0, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_sy = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_sy->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_sy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_sy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_sy->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_sy->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_sy->setMinimum(-1000000000000000072531436381529235126158374409646521955518210155479040.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_sy->setMaximum(10000000000000000725314363815292351261583744096465219555182101554790400.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_sy->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_sy, 0, 2, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_ox = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_ox->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_ox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_ox->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_ox->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_ox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_ox->setMinimum(-1000000000000000072531436381529235126158374409646521955518210155479040.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_ox->setMaximum(10000000000000000725314363815292351261583744096465219555182101554790400.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_ox, 0, 1, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_f = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_f->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_f->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_f->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_f, 3, 1, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_b = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_b->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_b->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_b->setDecimals(3);
        doubleSpinBox_00_Generate_2D_Complex_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_b->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_b->setValue(0.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_b, 2, 1, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_a = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_a->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_a->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_a->setDecimals(3);
        doubleSpinBox_00_Generate_2D_Complex_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_a->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_a, 2, 0, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_d = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_d->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_d->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_d->setDecimals(3);
        doubleSpinBox_00_Generate_2D_Complex_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_d->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_d->setValue(0.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_d, 2, 3, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_nan = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_nan->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_nan->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_nan->setDecimals(3);
        doubleSpinBox_00_Generate_2D_Complex_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_nan->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_nan, 3, 2, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_inf = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_inf->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_inf->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_inf->setDecimals(3);
        doubleSpinBox_00_Generate_2D_Complex_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_inf->setMaximum(999999999999.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_inf, 3, 3, 1, 1);

        line_00_Generate_2D_Complex = new QFrame(page_00_Generate_00_Parameters_2D_Complex);
        line_00_Generate_2D_Complex->setObjectName(QString::fromUtf8("line_00_Generate_2D_Complex"));
        line_00_Generate_2D_Complex->setFrameShape(QFrame::HLine);
        line_00_Generate_2D_Complex->setFrameShadow(QFrame::Sunken);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(line_00_Generate_2D_Complex, 1, 0, 1, 4);

        doubleSpinBox_00_Generate_2D_Complex_oy = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_oy->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_oy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_oy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_oy->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_oy->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_oy->setMinimum(-1000000000000000072531436381529235126158374409646521955518210155479040.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_oy->setMaximum(10000000000000000725314363815292351261583744096465219555182101554790400.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_oy, 0, 3, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_c = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_c->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_c->setFrame(false);
        doubleSpinBox_00_Generate_2D_Complex_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_c->setDecimals(3);
        doubleSpinBox_00_Generate_2D_Complex_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_c->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_c, 2, 2, 1, 1);

        doubleSpinBox_00_Generate_2D_Complex_sx = new QDoubleSpinBox(page_00_Generate_00_Parameters_2D_Complex);
        doubleSpinBox_00_Generate_2D_Complex_sx->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_2D_Complex_sx"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_2D_Complex_sx->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_2D_Complex_sx->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_2D_Complex_sx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_2D_Complex_sx->setMinimum(-1000000000000000072531436381529235126158374409646521955518210155479040.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_sx->setMaximum(10000000000000000725314363815292351261583744096465219555182101554790400.000000000000000);
        doubleSpinBox_00_Generate_2D_Complex_sx->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_2D_Complex->addWidget(doubleSpinBox_00_Generate_2D_Complex_sx, 0, 0, 1, 1);


        gridLayout_118->addLayout(gridLayout_00_Generate_Parameters_2D_Complex, 1, 1, 1, 1);

        verticalSpacer_00_Generate_2D_Complex = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_118->addItem(verticalSpacer_00_Generate_2D_Complex, 2, 1, 1, 1);

        stackedWidget_00_Generate_DimVar->addWidget(page_00_Generate_00_Parameters_2D_Complex);
        page_00_Generate_DimVar_6D = new QWidget();
        page_00_Generate_DimVar_6D->setObjectName(QString::fromUtf8("page_00_Generate_DimVar_6D"));
        gridLayout_103 = new QGridLayout(page_00_Generate_DimVar_6D);
        gridLayout_103->setSpacing(3);
        gridLayout_103->setObjectName(QString::fromUtf8("gridLayout_103"));
        gridLayout_103->setContentsMargins(0, 0, 0, 0);
        label_00_Generate_ValueFunction_6D = new QLabel(page_00_Generate_DimVar_6D);
        label_00_Generate_ValueFunction_6D->setObjectName(QString::fromUtf8("label_00_Generate_ValueFunction_6D"));
        label_00_Generate_ValueFunction_6D->setMinimumSize(QSize(75, 0));
        label_00_Generate_ValueFunction_6D->setMaximumSize(QSize(75, 16777215));

        gridLayout_103->addWidget(label_00_Generate_ValueFunction_6D, 0, 0, 1, 1);

        comboBox_00_Generate_ValueFunction_6D = new QComboBox(page_00_Generate_DimVar_6D);
        comboBox_00_Generate_ValueFunction_6D->setObjectName(QString::fromUtf8("comboBox_00_Generate_ValueFunction_6D"));

        gridLayout_103->addWidget(comboBox_00_Generate_ValueFunction_6D, 0, 1, 1, 1);

        label_00_Generate_Parameters_6D = new QLabel(page_00_Generate_DimVar_6D);
        label_00_Generate_Parameters_6D->setObjectName(QString::fromUtf8("label_00_Generate_Parameters_6D"));
        label_00_Generate_Parameters_6D->setMinimumSize(QSize(75, 0));
        label_00_Generate_Parameters_6D->setMaximumSize(QSize(75, 16777215));

        gridLayout_103->addWidget(label_00_Generate_Parameters_6D, 1, 0, 1, 1);

        gridLayout_00_Generate_Parameters_6D = new QGridLayout();
        gridLayout_00_Generate_Parameters_6D->setSpacing(1);
        gridLayout_00_Generate_Parameters_6D->setObjectName(QString::fromUtf8("gridLayout_00_Generate_Parameters_6D"));
        doubleSpinBox_00_Generate_6D_b = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_b->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_b->setDecimals(3);
        doubleSpinBox_00_Generate_6D_b->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_b->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_b, 4, 1, 1, 1);

        doubleSpinBox_00_Generate_6D_ox = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_ox->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_ox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_ox->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_ox->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_ox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_ox->setDecimals(3);
        doubleSpinBox_00_Generate_6D_ox->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_ox->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_ox, 0, 1, 1, 1);

        doubleSpinBox_00_Generate_6D_oy = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_oy->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_oy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_oy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_oy->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_oy->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_oy->setDecimals(3);
        doubleSpinBox_00_Generate_6D_oy->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_oy->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_oy, 0, 3, 1, 1);

        doubleSpinBox_00_Generate_6D_st = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_st->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_st"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_st->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_st->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_st->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_st->setDecimals(3);
        doubleSpinBox_00_Generate_6D_st->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_st->setMaximum(10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_00_Generate_6D_st->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_st, 1, 2, 1, 1);

        doubleSpinBox_00_Generate_6D_sy = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_sy->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_sy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_sy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_sy->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_sy->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_sy->setDecimals(3);
        doubleSpinBox_00_Generate_6D_sy->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_sy->setMaximum(10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_00_Generate_6D_sy->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_sy, 0, 2, 1, 1);

        doubleSpinBox_00_Generate_6D_ot = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_ot->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_ot"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_ot->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_ot->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_ot->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_ot->setDecimals(3);
        doubleSpinBox_00_Generate_6D_ot->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_ot->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_ot, 1, 3, 1, 1);

        doubleSpinBox_00_Generate_6D_sz = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_sz->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_sz"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_sz->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_sz->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_sz->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_sz->setDecimals(3);
        doubleSpinBox_00_Generate_6D_sz->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_sz->setMaximum(10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_00_Generate_6D_sz->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_sz, 1, 0, 1, 1);

        doubleSpinBox_00_Generate_6D_sx = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_sx->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_sx"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_sx->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_sx->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_sx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_sx->setDecimals(3);
        doubleSpinBox_00_Generate_6D_sx->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_sx->setMaximum(10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_00_Generate_6D_sx->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_sx, 0, 0, 1, 1);

        doubleSpinBox_00_Generate_6D_nan = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_nan->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_nan->setDecimals(3);
        doubleSpinBox_00_Generate_6D_nan->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_nan->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_nan, 5, 3, 1, 1);

        doubleSpinBox_00_Generate_6D_oz = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_oz->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_oz"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_oz->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_oz->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_oz->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_oz->setDecimals(3);
        doubleSpinBox_00_Generate_6D_oz->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_oz->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_oz, 1, 1, 1, 1);

        doubleSpinBox_00_Generate_6D_e = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_e->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_e->setDecimals(3);
        doubleSpinBox_00_Generate_6D_e->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_e->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_e, 5, 0, 1, 1);

        doubleSpinBox_00_Generate_6D_inf = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_inf->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_inf->setDecimals(3);
        doubleSpinBox_00_Generate_6D_inf->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_inf->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_inf, 5, 2, 1, 1);

        doubleSpinBox_00_Generate_6D_sp = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_sp->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_sp"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_sp->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_sp->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_sp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_sp->setDecimals(3);
        doubleSpinBox_00_Generate_6D_sp->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_sp->setMaximum(10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_00_Generate_6D_sp->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_sp, 2, 2, 1, 1);

        doubleSpinBox_00_Generate_6D_op = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_op->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_op"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_op->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_op->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_op->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_op->setDecimals(3);
        doubleSpinBox_00_Generate_6D_op->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_op->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_op, 2, 3, 1, 1);

        doubleSpinBox_00_Generate_6D_ss = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_ss->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_ss"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_ss->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_ss->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_ss->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_ss->setDecimals(3);
        doubleSpinBox_00_Generate_6D_ss->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_ss->setMaximum(10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_00_Generate_6D_ss->setValue(1.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_ss, 2, 0, 1, 1);

        doubleSpinBox_00_Generate_6D_d = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_d->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_d->setDecimals(3);
        doubleSpinBox_00_Generate_6D_d->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_d->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_d, 4, 3, 1, 1);

        doubleSpinBox_00_Generate_6D_c = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_c->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_c->setDecimals(3);
        doubleSpinBox_00_Generate_6D_c->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_c->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_c, 4, 2, 1, 1);

        doubleSpinBox_00_Generate_6D_os = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_os->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_os"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_os->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_os->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_os->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_os->setDecimals(3);
        doubleSpinBox_00_Generate_6D_os->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_os->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_os, 2, 1, 1, 1);

        doubleSpinBox_00_Generate_6D_f = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_f->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_f->setDecimals(3);
        doubleSpinBox_00_Generate_6D_f->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_f->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_f, 5, 1, 1, 1);

        doubleSpinBox_00_Generate_6D_a = new QDoubleSpinBox(page_00_Generate_DimVar_6D);
        doubleSpinBox_00_Generate_6D_a->setObjectName(QString::fromUtf8("doubleSpinBox_00_Generate_6D_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Generate_6D_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Generate_6D_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Generate_6D_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Generate_6D_a->setDecimals(3);
        doubleSpinBox_00_Generate_6D_a->setMinimum(-9999999999999999583119736832.000000000000000);
        doubleSpinBox_00_Generate_6D_a->setMaximum(10000000000000000139372116959414099130712064.000000000000000);

        gridLayout_00_Generate_Parameters_6D->addWidget(doubleSpinBox_00_Generate_6D_a, 4, 0, 1, 1);

        line_00_Generate_6D = new QFrame(page_00_Generate_DimVar_6D);
        line_00_Generate_6D->setObjectName(QString::fromUtf8("line_00_Generate_6D"));
        line_00_Generate_6D->setFrameShape(QFrame::HLine);
        line_00_Generate_6D->setFrameShadow(QFrame::Sunken);

        gridLayout_00_Generate_Parameters_6D->addWidget(line_00_Generate_6D, 3, 0, 1, 4);


        gridLayout_103->addLayout(gridLayout_00_Generate_Parameters_6D, 1, 1, 1, 1);

        label_00_Generate_ScaleOffset = new QLabel(page_00_Generate_DimVar_6D);
        label_00_Generate_ScaleOffset->setObjectName(QString::fromUtf8("label_00_Generate_ScaleOffset"));

        gridLayout_103->addWidget(label_00_Generate_ScaleOffset, 2, 0, 1, 1);

        label_00_Generate_ScaleOffset_Description = new QLabel(page_00_Generate_DimVar_6D);
        label_00_Generate_ScaleOffset_Description->setObjectName(QString::fromUtf8("label_00_Generate_ScaleOffset_Description"));

        gridLayout_103->addWidget(label_00_Generate_ScaleOffset_Description, 2, 1, 1, 1);

        stackedWidget_00_Generate_DimVar->addWidget(page_00_Generate_DimVar_6D);

        gridLayout_77->addWidget(stackedWidget_00_Generate_DimVar, 4, 1, 1, 3);

        stackedWidget_Settings_00_Source->addWidget(page_00_Generate);
        page_00_Random = new QWidget();
        page_00_Random->setObjectName(QString::fromUtf8("page_00_Random"));
        gridLayout_104 = new QGridLayout(page_00_Random);
        gridLayout_104->setObjectName(QString::fromUtf8("gridLayout_104"));
        label_00_Random_Parameters = new QLabel(page_00_Random);
        label_00_Random_Parameters->setObjectName(QString::fromUtf8("label_00_Random_Parameters"));
        label_00_Random_Parameters->setMinimumSize(QSize(75, 0));
        label_00_Random_Parameters->setMaximumSize(QSize(75, 16777215));

        gridLayout_104->addWidget(label_00_Random_Parameters, 3, 1, 1, 1);

        label_00_Random_Distribution = new QLabel(page_00_Random);
        label_00_Random_Distribution->setObjectName(QString::fromUtf8("label_00_Random_Distribution"));
        label_00_Random_Distribution->setMinimumSize(QSize(75, 0));
        label_00_Random_Distribution->setMaximumSize(QSize(75, 16777215));

        gridLayout_104->addWidget(label_00_Random_Distribution, 0, 1, 1, 1);

        verticalSpacer_00_Random = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_104->addItem(verticalSpacer_00_Random, 4, 1, 1, 1);

        doubleSpinBox_00_Random_Min = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_Min->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_Min"));
        doubleSpinBox_00_Random_Min->setDecimals(3);
        doubleSpinBox_00_Random_Min->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_Min->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_104->addWidget(doubleSpinBox_00_Random_Min, 2, 2, 1, 1);

        gridLayout_00_Random_Parameters = new QGridLayout();
        gridLayout_00_Random_Parameters->setSpacing(1);
        gridLayout_00_Random_Parameters->setObjectName(QString::fromUtf8("gridLayout_00_Random_Parameters"));
        doubleSpinBox_00_Random_b = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_b->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Random_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Random_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Random_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Random_b->setDecimals(3);
        doubleSpinBox_00_Random_b->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_b->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_00_Random_Parameters->addWidget(doubleSpinBox_00_Random_b, 0, 1, 1, 1);

        doubleSpinBox_00_Random_a = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_a->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Random_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Random_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Random_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Random_a->setDecimals(3);
        doubleSpinBox_00_Random_a->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_a->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_00_Random_Parameters->addWidget(doubleSpinBox_00_Random_a, 0, 0, 1, 1);

        doubleSpinBox_00_Random_c = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_c->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Random_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Random_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Random_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Random_c->setDecimals(3);
        doubleSpinBox_00_Random_c->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_c->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_00_Random_Parameters->addWidget(doubleSpinBox_00_Random_c, 0, 2, 1, 1);

        doubleSpinBox_00_Random_d = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_d->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Random_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Random_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Random_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Random_d->setDecimals(3);
        doubleSpinBox_00_Random_d->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_d->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_00_Random_Parameters->addWidget(doubleSpinBox_00_Random_d, 1, 0, 1, 1);

        doubleSpinBox_00_Random_e = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_e->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Random_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Random_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Random_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Random_e->setDecimals(3);
        doubleSpinBox_00_Random_e->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_e->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_00_Random_Parameters->addWidget(doubleSpinBox_00_Random_e, 1, 1, 1, 1);

        doubleSpinBox_00_Random_f = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_f->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_Random_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_Random_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_Random_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_Random_f->setDecimals(3);
        doubleSpinBox_00_Random_f->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_f->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);

        gridLayout_00_Random_Parameters->addWidget(doubleSpinBox_00_Random_f, 1, 2, 1, 1);


        gridLayout_104->addLayout(gridLayout_00_Random_Parameters, 3, 2, 1, 2);

        doubleSpinBox_00_Random_Max = new QDoubleSpinBox(page_00_Random);
        doubleSpinBox_00_Random_Max->setObjectName(QString::fromUtf8("doubleSpinBox_00_Random_Max"));
        doubleSpinBox_00_Random_Max->setDecimals(3);
        doubleSpinBox_00_Random_Max->setMinimum(-100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_Max->setMaximum(100000000000000004384584304507619735463404765184.000000000000000);
        doubleSpinBox_00_Random_Max->setValue(255.000000000000000);

        gridLayout_104->addWidget(doubleSpinBox_00_Random_Max, 2, 3, 1, 1);

        line_00_Random = new QFrame(page_00_Random);
        line_00_Random->setObjectName(QString::fromUtf8("line_00_Random"));
        line_00_Random->setFrameShape(QFrame::VLine);
        line_00_Random->setFrameShadow(QFrame::Sunken);

        gridLayout_104->addWidget(line_00_Random, 0, 0, 5, 1);

        label_00_Random_Range = new QLabel(page_00_Random);
        label_00_Random_Range->setObjectName(QString::fromUtf8("label_00_Random_Range"));
        label_00_Random_Range->setMinimumSize(QSize(75, 0));
        label_00_Random_Range->setMaximumSize(QSize(75, 16777215));

        gridLayout_104->addWidget(label_00_Random_Range, 2, 1, 1, 1);

        comboBox_00_Random_Type = new QComboBox(page_00_Random);
        comboBox_00_Random_Type->setObjectName(QString::fromUtf8("comboBox_00_Random_Type"));

        gridLayout_104->addWidget(comboBox_00_Random_Type, 0, 2, 1, 2);

        label_8 = new QLabel(page_00_Random);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_104->addWidget(label_8, 1, 1, 1, 1);

        gridLayout_00_Random_Size = new QGridLayout();
        gridLayout_00_Random_Size->setSpacing(1);
        gridLayout_00_Random_Size->setObjectName(QString::fromUtf8("gridLayout_00_Random_Size"));
        spinBox_00_Random_Size_Z = new QSpinBox(page_00_Random);
        spinBox_00_Random_Size_Z->setObjectName(QString::fromUtf8("spinBox_00_Random_Size_Z"));
        sizePolicy1.setHeightForWidth(spinBox_00_Random_Size_Z->sizePolicy().hasHeightForWidth());
        spinBox_00_Random_Size_Z->setSizePolicy(sizePolicy1);
        spinBox_00_Random_Size_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Random_Size_Z->setMinimum(1);
        spinBox_00_Random_Size_Z->setMaximum(999999999);

        gridLayout_00_Random_Size->addWidget(spinBox_00_Random_Size_Z, 0, 2, 1, 1);

        spinBox_00_Random_Size_X = new QSpinBox(page_00_Random);
        spinBox_00_Random_Size_X->setObjectName(QString::fromUtf8("spinBox_00_Random_Size_X"));
        sizePolicy1.setHeightForWidth(spinBox_00_Random_Size_X->sizePolicy().hasHeightForWidth());
        spinBox_00_Random_Size_X->setSizePolicy(sizePolicy1);
        spinBox_00_Random_Size_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Random_Size_X->setMinimum(1);
        spinBox_00_Random_Size_X->setMaximum(999999999);
        spinBox_00_Random_Size_X->setValue(5);

        gridLayout_00_Random_Size->addWidget(spinBox_00_Random_Size_X, 0, 0, 1, 1);

        spinBox_00_Random_Size_Y = new QSpinBox(page_00_Random);
        spinBox_00_Random_Size_Y->setObjectName(QString::fromUtf8("spinBox_00_Random_Size_Y"));
        sizePolicy1.setHeightForWidth(spinBox_00_Random_Size_Y->sizePolicy().hasHeightForWidth());
        spinBox_00_Random_Size_Y->setSizePolicy(sizePolicy1);
        spinBox_00_Random_Size_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Random_Size_Y->setMinimum(1);
        spinBox_00_Random_Size_Y->setMaximum(999999999);
        spinBox_00_Random_Size_Y->setValue(5);

        gridLayout_00_Random_Size->addWidget(spinBox_00_Random_Size_Y, 0, 1, 1, 1);

        spinBox_00_Random_Size_T = new QSpinBox(page_00_Random);
        spinBox_00_Random_Size_T->setObjectName(QString::fromUtf8("spinBox_00_Random_Size_T"));
        sizePolicy1.setHeightForWidth(spinBox_00_Random_Size_T->sizePolicy().hasHeightForWidth());
        spinBox_00_Random_Size_T->setSizePolicy(sizePolicy1);
        spinBox_00_Random_Size_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Random_Size_T->setMinimum(1);
        spinBox_00_Random_Size_T->setMaximum(999999999);

        gridLayout_00_Random_Size->addWidget(spinBox_00_Random_Size_T, 1, 0, 1, 1);

        spinBox_00_Random_Size_S = new QSpinBox(page_00_Random);
        spinBox_00_Random_Size_S->setObjectName(QString::fromUtf8("spinBox_00_Random_Size_S"));
        sizePolicy1.setHeightForWidth(spinBox_00_Random_Size_S->sizePolicy().hasHeightForWidth());
        spinBox_00_Random_Size_S->setSizePolicy(sizePolicy1);
        spinBox_00_Random_Size_S->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Random_Size_S->setMinimum(1);
        spinBox_00_Random_Size_S->setMaximum(999999999);

        gridLayout_00_Random_Size->addWidget(spinBox_00_Random_Size_S, 1, 1, 1, 1);

        spinBox_00_Random_Size_P = new QSpinBox(page_00_Random);
        spinBox_00_Random_Size_P->setObjectName(QString::fromUtf8("spinBox_00_Random_Size_P"));
        sizePolicy1.setHeightForWidth(spinBox_00_Random_Size_P->sizePolicy().hasHeightForWidth());
        spinBox_00_Random_Size_P->setSizePolicy(sizePolicy1);
        spinBox_00_Random_Size_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_Random_Size_P->setMinimum(1);
        spinBox_00_Random_Size_P->setMaximum(999999999);

        gridLayout_00_Random_Size->addWidget(spinBox_00_Random_Size_P, 1, 2, 1, 1);


        gridLayout_104->addLayout(gridLayout_00_Random_Size, 1, 2, 1, 2);

        stackedWidget_Settings_00_Source->addWidget(page_00_Random);
        page_00_CastRaw = new QWidget();
        page_00_CastRaw->setObjectName(QString::fromUtf8("page_00_CastRaw"));
        gridLayout_86 = new QGridLayout(page_00_CastRaw);
        gridLayout_86->setObjectName(QString::fromUtf8("gridLayout_86"));
        label_00_CastRaw_Width = new QLabel(page_00_CastRaw);
        label_00_CastRaw_Width->setObjectName(QString::fromUtf8("label_00_CastRaw_Width"));
        label_00_CastRaw_Width->setMinimumSize(QSize(75, 0));
        label_00_CastRaw_Width->setMaximumSize(QSize(75, 16777215));

        gridLayout_86->addWidget(label_00_CastRaw_Width, 2, 1, 1, 1);

        label_00_CastRaw_Path = new QLabel(page_00_CastRaw);
        label_00_CastRaw_Path->setObjectName(QString::fromUtf8("label_00_CastRaw_Path"));

        gridLayout_86->addWidget(label_00_CastRaw_Path, 0, 1, 1, 1);

        line_00_CastRaw = new QFrame(page_00_CastRaw);
        line_00_CastRaw->setObjectName(QString::fromUtf8("line_00_CastRaw"));
        line_00_CastRaw->setFrameShape(QFrame::VLine);
        line_00_CastRaw->setFrameShadow(QFrame::Sunken);

        gridLayout_86->addWidget(line_00_CastRaw, 0, 0, 5, 1);

        comboBox_00_CastRaw_BitPerPixel = new QComboBox(page_00_CastRaw);
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->addItem(QString());
        comboBox_00_CastRaw_BitPerPixel->setObjectName(QString::fromUtf8("comboBox_00_CastRaw_BitPerPixel"));
        comboBox_00_CastRaw_BitPerPixel->setMinimumSize(QSize(100, 0));
        comboBox_00_CastRaw_BitPerPixel->setMaximumSize(QSize(100, 16777215));

        gridLayout_86->addWidget(comboBox_00_CastRaw_BitPerPixel, 1, 2, 1, 1);

        label_00_CastRaw_Height = new QLabel(page_00_CastRaw);
        label_00_CastRaw_Height->setObjectName(QString::fromUtf8("label_00_CastRaw_Height"));
        label_00_CastRaw_Height->setMinimumSize(QSize(75, 0));
        label_00_CastRaw_Height->setMaximumSize(QSize(75, 16777215));

        gridLayout_86->addWidget(label_00_CastRaw_Height, 3, 1, 1, 1);

        label_00_CastRaw_Type = new QLabel(page_00_CastRaw);
        label_00_CastRaw_Type->setObjectName(QString::fromUtf8("label_00_CastRaw_Type"));
        label_00_CastRaw_Type->setMinimumSize(QSize(75, 0));
        label_00_CastRaw_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_86->addWidget(label_00_CastRaw_Type, 1, 1, 1, 1);

        verticalSpacer_00_CastRaw = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_86->addItem(verticalSpacer_00_CastRaw, 4, 1, 1, 4);

        pushButton_00_CastRaw_Path = new QPushButton(page_00_CastRaw);
        pushButton_00_CastRaw_Path->setObjectName(QString::fromUtf8("pushButton_00_CastRaw_Path"));

        gridLayout_86->addWidget(pushButton_00_CastRaw_Path, 0, 2, 1, 1);

        spinBox_00_CastRaw_Height = new QSpinBox(page_00_CastRaw);
        spinBox_00_CastRaw_Height->setObjectName(QString::fromUtf8("spinBox_00_CastRaw_Height"));
        spinBox_00_CastRaw_Height->setMinimumSize(QSize(100, 0));
        spinBox_00_CastRaw_Height->setMaximumSize(QSize(100, 16777215));
        spinBox_00_CastRaw_Height->setMinimum(1);
        spinBox_00_CastRaw_Height->setMaximum(999999);
        spinBox_00_CastRaw_Height->setSingleStep(100);
        spinBox_00_CastRaw_Height->setValue(2062);

        gridLayout_86->addWidget(spinBox_00_CastRaw_Height, 3, 2, 1, 1);

        spinBox_00_CastRaw_Width = new QSpinBox(page_00_CastRaw);
        spinBox_00_CastRaw_Width->setObjectName(QString::fromUtf8("spinBox_00_CastRaw_Width"));
        spinBox_00_CastRaw_Width->setMinimumSize(QSize(100, 0));
        spinBox_00_CastRaw_Width->setMaximumSize(QSize(100, 16777215));
        spinBox_00_CastRaw_Width->setMinimum(1);
        spinBox_00_CastRaw_Width->setMaximum(999999);
        spinBox_00_CastRaw_Width->setSingleStep(100);
        spinBox_00_CastRaw_Width->setValue(2331);

        gridLayout_86->addWidget(spinBox_00_CastRaw_Width, 2, 2, 1, 1);

        horizontalSpacer_00_CastRaw = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_86->addItem(horizontalSpacer_00_CastRaw, 0, 4, 4, 1);

        label_00_CastRaw_Channel = new QLabel(page_00_CastRaw);
        label_00_CastRaw_Channel->setObjectName(QString::fromUtf8("label_00_CastRaw_Channel"));

        gridLayout_86->addWidget(label_00_CastRaw_Channel, 1, 3, 1, 1);

        stackedWidget_Settings_00_Source->addWidget(page_00_CastRaw);
        page_00_VideoStream = new QWidget();
        page_00_VideoStream->setObjectName(QString::fromUtf8("page_00_VideoStream"));
        gridLayout_92 = new QGridLayout(page_00_VideoStream);
        gridLayout_92->setObjectName(QString::fromUtf8("gridLayout_92"));
        gridLayout_92->setVerticalSpacing(3);
        label_00_VideoStream_File = new QLabel(page_00_VideoStream);
        label_00_VideoStream_File->setObjectName(QString::fromUtf8("label_00_VideoStream_File"));
        label_00_VideoStream_File->setMinimumSize(QSize(75, 0));
        label_00_VideoStream_File->setMaximumSize(QSize(75, 16777215));

        gridLayout_92->addWidget(label_00_VideoStream_File, 0, 1, 1, 1);

        verticalSpacer_00_VideoStream = new QSpacerItem(393, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_92->addItem(verticalSpacer_00_VideoStream, 12, 1, 1, 3);

        line_00_VideoStream_1 = new QFrame(page_00_VideoStream);
        line_00_VideoStream_1->setObjectName(QString::fromUtf8("line_00_VideoStream_1"));
        line_00_VideoStream_1->setFrameShape(QFrame::VLine);
        line_00_VideoStream_1->setFrameShadow(QFrame::Sunken);

        gridLayout_92->addWidget(line_00_VideoStream_1, 0, 0, 13, 1);

        label_00_VideoStream_Combi_X = new QLabel(page_00_VideoStream);
        label_00_VideoStream_Combi_X->setObjectName(QString::fromUtf8("label_00_VideoStream_Combi_X"));
        label_00_VideoStream_Combi_X->setMinimumSize(QSize(75, 0));
        label_00_VideoStream_Combi_X->setMaximumSize(QSize(75, 16777215));

        gridLayout_92->addWidget(label_00_VideoStream_Combi_X, 9, 1, 1, 1);

        line_00_VideoStream_2 = new QFrame(page_00_VideoStream);
        line_00_VideoStream_2->setObjectName(QString::fromUtf8("line_00_VideoStream_2"));
        line_00_VideoStream_2->setFrameShape(QFrame::HLine);
        line_00_VideoStream_2->setFrameShadow(QFrame::Sunken);

        gridLayout_92->addWidget(line_00_VideoStream_2, 3, 1, 1, 3);

        label_00_VideoStream_T2 = new QLabel(page_00_VideoStream);
        label_00_VideoStream_T2->setObjectName(QString::fromUtf8("label_00_VideoStream_T2"));
        label_00_VideoStream_T2->setMinimumSize(QSize(75, 0));
        label_00_VideoStream_T2->setMaximumSize(QSize(75, 16777215));

        gridLayout_92->addWidget(label_00_VideoStream_T2, 5, 1, 1, 1);

        label_00_VideoStream_T1 = new QLabel(page_00_VideoStream);
        label_00_VideoStream_T1->setObjectName(QString::fromUtf8("label_00_VideoStream_T1"));
        label_00_VideoStream_T1->setMinimumSize(QSize(75, 0));
        label_00_VideoStream_T1->setMaximumSize(QSize(75, 16777215));

        gridLayout_92->addWidget(label_00_VideoStream_T1, 4, 1, 1, 1);

        label_00_VideoStream_Blur = new QLabel(page_00_VideoStream);
        label_00_VideoStream_Blur->setObjectName(QString::fromUtf8("label_00_VideoStream_Blur"));

        gridLayout_92->addWidget(label_00_VideoStream_Blur, 2, 1, 1, 1);

        gridLayout_00_VideoStream_TimeFrames = new QGridLayout();
        gridLayout_00_VideoStream_TimeFrames->setSpacing(1);
        gridLayout_00_VideoStream_TimeFrames->setObjectName(QString::fromUtf8("gridLayout_00_VideoStream_TimeFrames"));
        spinBox_00_VideoStream_T1_Frames = new QSpinBox(page_00_VideoStream);
        spinBox_00_VideoStream_T1_Frames->setObjectName(QString::fromUtf8("spinBox_00_VideoStream_T1_Frames"));
        sizePolicy1.setHeightForWidth(spinBox_00_VideoStream_T1_Frames->sizePolicy().hasHeightForWidth());
        spinBox_00_VideoStream_T1_Frames->setSizePolicy(sizePolicy1);
        spinBox_00_VideoStream_T1_Frames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_VideoStream_T1_Frames->setMinimum(1);
        spinBox_00_VideoStream_T1_Frames->setMaximum(9999);
        spinBox_00_VideoStream_T1_Frames->setValue(1);

        gridLayout_00_VideoStream_TimeFrames->addWidget(spinBox_00_VideoStream_T1_Frames, 0, 1, 1, 1);

        spinBox_00_VideoStream_T2_Frames = new QSpinBox(page_00_VideoStream);
        spinBox_00_VideoStream_T2_Frames->setObjectName(QString::fromUtf8("spinBox_00_VideoStream_T2_Frames"));
        sizePolicy1.setHeightForWidth(spinBox_00_VideoStream_T2_Frames->sizePolicy().hasHeightForWidth());
        spinBox_00_VideoStream_T2_Frames->setSizePolicy(sizePolicy1);
        spinBox_00_VideoStream_T2_Frames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_VideoStream_T2_Frames->setMinimum(1);
        spinBox_00_VideoStream_T2_Frames->setMaximum(9999);
        spinBox_00_VideoStream_T2_Frames->setValue(9);

        gridLayout_00_VideoStream_TimeFrames->addWidget(spinBox_00_VideoStream_T2_Frames, 1, 1, 1, 1);

        comboBox_00_VideoStream_T1_Stat = new QComboBox(page_00_VideoStream);
        comboBox_00_VideoStream_T1_Stat->setObjectName(QString::fromUtf8("comboBox_00_VideoStream_T1_Stat"));
        sizePolicy1.setHeightForWidth(comboBox_00_VideoStream_T1_Stat->sizePolicy().hasHeightForWidth());
        comboBox_00_VideoStream_T1_Stat->setSizePolicy(sizePolicy1);

        gridLayout_00_VideoStream_TimeFrames->addWidget(comboBox_00_VideoStream_T1_Stat, 0, 0, 1, 1);

        comboBox_00_VideoStream_T2_Stat = new QComboBox(page_00_VideoStream);
        comboBox_00_VideoStream_T2_Stat->setObjectName(QString::fromUtf8("comboBox_00_VideoStream_T2_Stat"));
        sizePolicy1.setHeightForWidth(comboBox_00_VideoStream_T2_Stat->sizePolicy().hasHeightForWidth());
        comboBox_00_VideoStream_T2_Stat->setSizePolicy(sizePolicy1);

        gridLayout_00_VideoStream_TimeFrames->addWidget(comboBox_00_VideoStream_T2_Stat, 1, 0, 1, 1);

        spinBox_00_VideoStream_T_Offset = new QSpinBox(page_00_VideoStream);
        spinBox_00_VideoStream_T_Offset->setObjectName(QString::fromUtf8("spinBox_00_VideoStream_T_Offset"));
        spinBox_00_VideoStream_T_Offset->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_00_VideoStream_TimeFrames->addWidget(spinBox_00_VideoStream_T_Offset, 2, 0, 1, 2);


        gridLayout_92->addLayout(gridLayout_00_VideoStream_TimeFrames, 4, 2, 3, 2);

        gridLayout_00_VideoStream_Blur = new QGridLayout();
        gridLayout_00_VideoStream_Blur->setSpacing(1);
        gridLayout_00_VideoStream_Blur->setObjectName(QString::fromUtf8("gridLayout_00_VideoStream_Blur"));
        doubleSpinBox_00_VideoStream_Blur_Sigma = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_Blur_Sigma"));
        doubleSpinBox_00_VideoStream_Blur_Sigma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_Blur_Sigma->setMaximum(999.000000000000000);
        doubleSpinBox_00_VideoStream_Blur_Sigma->setSingleStep(0.250000000000000);
        doubleSpinBox_00_VideoStream_Blur_Sigma->setValue(1.000000000000000);

        gridLayout_00_VideoStream_Blur->addWidget(doubleSpinBox_00_VideoStream_Blur_Sigma, 0, 1, 1, 1);

        spinBox_00_VideoStream_Blur_Size = new QSpinBox(page_00_VideoStream);
        spinBox_00_VideoStream_Blur_Size->setObjectName(QString::fromUtf8("spinBox_00_VideoStream_Blur_Size"));
        spinBox_00_VideoStream_Blur_Size->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_00_VideoStream_Blur_Size->setMinimum(1);
        spinBox_00_VideoStream_Blur_Size->setMaximum(999);
        spinBox_00_VideoStream_Blur_Size->setSingleStep(2);
        spinBox_00_VideoStream_Blur_Size->setValue(3);

        gridLayout_00_VideoStream_Blur->addWidget(spinBox_00_VideoStream_Blur_Size, 0, 0, 1, 1);


        gridLayout_92->addLayout(gridLayout_00_VideoStream_Blur, 2, 2, 1, 2);

        gridLayout_00_VideoStream_Combination = new QGridLayout();
        gridLayout_00_VideoStream_Combination->setSpacing(1);
        gridLayout_00_VideoStream_Combination->setObjectName(QString::fromUtf8("gridLayout_00_VideoStream_Combination"));
        doubleSpinBox_00_VideoStream_CombiFunction_nan = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_nan, 2, 2, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_b = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_b->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_b->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_b->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_b->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_b->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_b, 1, 1, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_inf = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_inf, 2, 3, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_f = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_f->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_f->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_f->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_f->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_f->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_f, 2, 1, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_c = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_c->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_c->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_c->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_c->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_c->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_c->setValue(1.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_c, 1, 2, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_a = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_a->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_a->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_a->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_a->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_a->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_a->setValue(1.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_a, 1, 0, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_e = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_e->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_e->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_e->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_e->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_e->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_e, 2, 0, 1, 1);

        doubleSpinBox_00_VideoStream_CombiFunction_d = new QDoubleSpinBox(page_00_VideoStream);
        doubleSpinBox_00_VideoStream_CombiFunction_d->setObjectName(QString::fromUtf8("doubleSpinBox_00_VideoStream_CombiFunction_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_00_VideoStream_CombiFunction_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_00_VideoStream_CombiFunction_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_00_VideoStream_CombiFunction_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_00_VideoStream_CombiFunction_d->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_00_VideoStream_CombiFunction_d->setDecimals(3);
        doubleSpinBox_00_VideoStream_CombiFunction_d->setMinimum(-9999999999999999932209486743616279764617084419440640.000000000000000);
        doubleSpinBox_00_VideoStream_CombiFunction_d->setMaximum(9999999999999999932209486743616279764617084419440640.000000000000000);

        gridLayout_00_VideoStream_Combination->addWidget(doubleSpinBox_00_VideoStream_CombiFunction_d, 1, 3, 1, 1);

        comboBox_00_VideoStream_CombiFunction = new QComboBox(page_00_VideoStream);
        comboBox_00_VideoStream_CombiFunction->setObjectName(QString::fromUtf8("comboBox_00_VideoStream_CombiFunction"));
        sizePolicy1.setHeightForWidth(comboBox_00_VideoStream_CombiFunction->sizePolicy().hasHeightForWidth());
        comboBox_00_VideoStream_CombiFunction->setSizePolicy(sizePolicy1);

        gridLayout_00_VideoStream_Combination->addWidget(comboBox_00_VideoStream_CombiFunction, 0, 0, 1, 2);

        checkBox_00_VideoStream_Force_8bit = new QCheckBox(page_00_VideoStream);
        checkBox_00_VideoStream_Force_8bit->setObjectName(QString::fromUtf8("checkBox_00_VideoStream_Force_8bit"));
        sizePolicy1.setHeightForWidth(checkBox_00_VideoStream_Force_8bit->sizePolicy().hasHeightForWidth());
        checkBox_00_VideoStream_Force_8bit->setSizePolicy(sizePolicy1);
        checkBox_00_VideoStream_Force_8bit->setChecked(true);

        gridLayout_00_VideoStream_Combination->addWidget(checkBox_00_VideoStream_Force_8bit, 0, 2, 1, 2);


        gridLayout_92->addLayout(gridLayout_00_VideoStream_Combination, 8, 2, 3, 2);

        label_00_VideoStream_Combi_Y = new QLabel(page_00_VideoStream);
        label_00_VideoStream_Combi_Y->setObjectName(QString::fromUtf8("label_00_VideoStream_Combi_Y"));
        label_00_VideoStream_Combi_Y->setMinimumSize(QSize(75, 0));
        label_00_VideoStream_Combi_Y->setMaximumSize(QSize(75, 16777215));

        gridLayout_92->addWidget(label_00_VideoStream_Combi_Y, 10, 1, 1, 1);

        label_00_VideoStream_Offset = new QLabel(page_00_VideoStream);
        label_00_VideoStream_Offset->setObjectName(QString::fromUtf8("label_00_VideoStream_Offset"));

        gridLayout_92->addWidget(label_00_VideoStream_Offset, 6, 1, 1, 1);

        label_00_VideoStream_Combi = new QLabel(page_00_VideoStream);
        label_00_VideoStream_Combi->setObjectName(QString::fromUtf8("label_00_VideoStream_Combi"));

        gridLayout_92->addWidget(label_00_VideoStream_Combi, 8, 1, 1, 1);

        line_00_VideoStream_3 = new QFrame(page_00_VideoStream);
        line_00_VideoStream_3->setObjectName(QString::fromUtf8("line_00_VideoStream_3"));
        line_00_VideoStream_3->setFrameShape(QFrame::HLine);
        line_00_VideoStream_3->setFrameShadow(QFrame::Sunken);

        gridLayout_92->addWidget(line_00_VideoStream_3, 7, 1, 1, 3);

        line = new QFrame(page_00_VideoStream);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_92->addWidget(line, 1, 1, 1, 3);

        gridLayout_00_VideoStream_File = new QGridLayout();
        gridLayout_00_VideoStream_File->setSpacing(1);
        gridLayout_00_VideoStream_File->setObjectName(QString::fromUtf8("gridLayout_00_VideoStream_File"));
        pushButton_00_VideoStream_Browse = new QPushButton(page_00_VideoStream);
        pushButton_00_VideoStream_Browse->setObjectName(QString::fromUtf8("pushButton_00_VideoStream_Browse"));
        pushButton_00_VideoStream_Browse->setMinimumSize(QSize(75, 0));
        pushButton_00_VideoStream_Browse->setMaximumSize(QSize(75, 20));

        gridLayout_00_VideoStream_File->addWidget(pushButton_00_VideoStream_Browse, 0, 0, 1, 1);

        label_00_VideoStream_Path = new QLabel(page_00_VideoStream);
        label_00_VideoStream_Path->setObjectName(QString::fromUtf8("label_00_VideoStream_Path"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_00_VideoStream_Path->sizePolicy().hasHeightForWidth());
        label_00_VideoStream_Path->setSizePolicy(sizePolicy2);

        gridLayout_00_VideoStream_File->addWidget(label_00_VideoStream_Path, 0, 1, 1, 1);


        gridLayout_92->addLayout(gridLayout_00_VideoStream_File, 0, 2, 1, 2);

        stackedWidget_Settings_00_Source->addWidget(page_00_VideoStream);

        gridLayout_17->addWidget(stackedWidget_Settings_00_Source, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_00_Source);
        page_Settings_01_Edit = new QWidget();
        page_Settings_01_Edit->setObjectName(QString::fromUtf8("page_Settings_01_Edit"));
        gridLayout_18 = new QGridLayout(page_Settings_01_Edit);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_01_Edit = new QStackedWidget(page_Settings_01_Edit);
        stackedWidget_Settings_01_Edit->setObjectName(QString::fromUtf8("stackedWidget_Settings_01_Edit"));
        page_01_Crop = new QWidget();
        page_01_Crop->setObjectName(QString::fromUtf8("page_01_Crop"));
        gridLayout_64 = new QGridLayout(page_01_Crop);
        gridLayout_64->setObjectName(QString::fromUtf8("gridLayout_64"));
        label_01_Crop_Shape = new QLabel(page_01_Crop);
        label_01_Crop_Shape->setObjectName(QString::fromUtf8("label_01_Crop_Shape"));
        label_01_Crop_Shape->setMinimumSize(QSize(75, 0));

        gridLayout_64->addWidget(label_01_Crop_Shape, 0, 1, 1, 1);

        horizontalSpacer_01_Crop = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_64->addItem(horizontalSpacer_01_Crop, 0, 3, 1, 1);

        line01_Crop = new QFrame(page_01_Crop);
        line01_Crop->setObjectName(QString::fromUtf8("line01_Crop"));
        line01_Crop->setFrameShape(QFrame::VLine);
        line01_Crop->setFrameShadow(QFrame::Sunken);

        gridLayout_64->addWidget(line01_Crop, 0, 0, 2, 1);

        comboBox_01_Crop_Shape = new QComboBox(page_01_Crop);
        comboBox_01_Crop_Shape->addItem(QString());
        comboBox_01_Crop_Shape->addItem(QString());
        comboBox_01_Crop_Shape->addItem(QString());
        comboBox_01_Crop_Shape->addItem(QString());
        comboBox_01_Crop_Shape->setObjectName(QString::fromUtf8("comboBox_01_Crop_Shape"));
        comboBox_01_Crop_Shape->setMinimumSize(QSize(100, 0));

        gridLayout_64->addWidget(comboBox_01_Crop_Shape, 0, 2, 1, 1);

        stackedWidget_01_Crop_Shape = new QStackedWidget(page_01_Crop);
        stackedWidget_01_Crop_Shape->setObjectName(QString::fromUtf8("stackedWidget_01_Crop_Shape"));
        page_01_Crop_RectRel = new QWidget();
        page_01_Crop_RectRel->setObjectName(QString::fromUtf8("page_01_Crop_RectRel"));
        gridLayout_65 = new QGridLayout(page_01_Crop_RectRel);
        gridLayout_65->setSpacing(3);
        gridLayout_65->setObjectName(QString::fromUtf8("gridLayout_65"));
        gridLayout_65->setContentsMargins(0, 0, 0, 0);
        label_01_Crop_Rect_Y = new QLabel(page_01_Crop_RectRel);
        label_01_Crop_Rect_Y->setObjectName(QString::fromUtf8("label_01_Crop_Rect_Y"));
        label_01_Crop_Rect_Y->setMinimumSize(QSize(47, 0));
        label_01_Crop_Rect_Y->setMaximumSize(QSize(50, 16777215));

        gridLayout_65->addWidget(label_01_Crop_Rect_Y, 0, 2, 1, 1);

        verticalSpacer_01_Crop_Rect = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_65->addItem(verticalSpacer_01_Crop_Rect, 3, 0, 1, 1);

        label_01_Crop_Rect_X = new QLabel(page_01_Crop_RectRel);
        label_01_Crop_Rect_X->setObjectName(QString::fromUtf8("label_01_Crop_Rect_X"));
        label_01_Crop_Rect_X->setMinimumSize(QSize(47, 0));
        label_01_Crop_Rect_X->setMaximumSize(QSize(50, 16777215));

        gridLayout_65->addWidget(label_01_Crop_Rect_X, 0, 1, 1, 1);

        doubleSpinBox_01_Crop_Rect_Y2 = new QDoubleSpinBox(page_01_Crop_RectRel);
        doubleSpinBox_01_Crop_Rect_Y2->setObjectName(QString::fromUtf8("doubleSpinBox_01_Crop_Rect_Y2"));
        doubleSpinBox_01_Crop_Rect_Y2->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Crop_Rect_Y2->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Crop_Rect_Y2->setMinimum(0.010000000000000);
        doubleSpinBox_01_Crop_Rect_Y2->setMaximum(100.000000000000000);
        doubleSpinBox_01_Crop_Rect_Y2->setValue(75.000000000000000);

        gridLayout_65->addWidget(doubleSpinBox_01_Crop_Rect_Y2, 2, 2, 1, 1);

        horizontalSpacer_01_Crop_Rect = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_65->addItem(horizontalSpacer_01_Crop_Rect, 1, 4, 1, 1);

        doubleSpinBox_01_Crop_Rect_X2 = new QDoubleSpinBox(page_01_Crop_RectRel);
        doubleSpinBox_01_Crop_Rect_X2->setObjectName(QString::fromUtf8("doubleSpinBox_01_Crop_Rect_X2"));
        doubleSpinBox_01_Crop_Rect_X2->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Crop_Rect_X2->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Crop_Rect_X2->setMinimum(0.010000000000000);
        doubleSpinBox_01_Crop_Rect_X2->setMaximum(100.000000000000000);
        doubleSpinBox_01_Crop_Rect_X2->setValue(75.000000000000000);

        gridLayout_65->addWidget(doubleSpinBox_01_Crop_Rect_X2, 2, 1, 1, 1);

        label_01_Crop_Rect_1 = new QLabel(page_01_Crop_RectRel);
        label_01_Crop_Rect_1->setObjectName(QString::fromUtf8("label_01_Crop_Rect_1"));
        label_01_Crop_Rect_1->setMinimumSize(QSize(75, 0));
        label_01_Crop_Rect_1->setMaximumSize(QSize(75, 16777215));

        gridLayout_65->addWidget(label_01_Crop_Rect_1, 1, 0, 1, 1);

        label_01_Crop_Rect_2 = new QLabel(page_01_Crop_RectRel);
        label_01_Crop_Rect_2->setObjectName(QString::fromUtf8("label_01_Crop_Rect_2"));
        label_01_Crop_Rect_2->setMinimumSize(QSize(75, 0));
        label_01_Crop_Rect_2->setMaximumSize(QSize(75, 16777215));

        gridLayout_65->addWidget(label_01_Crop_Rect_2, 2, 0, 1, 1);

        doubleSpinBox_01_Crop_Rect_X1 = new QDoubleSpinBox(page_01_Crop_RectRel);
        doubleSpinBox_01_Crop_Rect_X1->setObjectName(QString::fromUtf8("doubleSpinBox_01_Crop_Rect_X1"));
        doubleSpinBox_01_Crop_Rect_X1->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Crop_Rect_X1->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Crop_Rect_X1->setMaximum(99.989999999999995);
        doubleSpinBox_01_Crop_Rect_X1->setValue(25.000000000000000);

        gridLayout_65->addWidget(doubleSpinBox_01_Crop_Rect_X1, 1, 1, 1, 1);

        doubleSpinBox_01_Crop_Rect_Y1 = new QDoubleSpinBox(page_01_Crop_RectRel);
        doubleSpinBox_01_Crop_Rect_Y1->setObjectName(QString::fromUtf8("doubleSpinBox_01_Crop_Rect_Y1"));
        doubleSpinBox_01_Crop_Rect_Y1->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Crop_Rect_Y1->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Crop_Rect_Y1->setMaximum(99.989999999999995);
        doubleSpinBox_01_Crop_Rect_Y1->setValue(25.000000000000000);

        gridLayout_65->addWidget(doubleSpinBox_01_Crop_Rect_Y1, 1, 2, 1, 1);

        label_01_Crop_Rect_Prz1 = new QLabel(page_01_Crop_RectRel);
        label_01_Crop_Rect_Prz1->setObjectName(QString::fromUtf8("label_01_Crop_Rect_Prz1"));
        label_01_Crop_Rect_Prz1->setMinimumSize(QSize(20, 0));
        label_01_Crop_Rect_Prz1->setMaximumSize(QSize(20, 16777215));

        gridLayout_65->addWidget(label_01_Crop_Rect_Prz1, 1, 3, 1, 1);

        label_01_Crop_Rect_Prz2 = new QLabel(page_01_Crop_RectRel);
        label_01_Crop_Rect_Prz2->setObjectName(QString::fromUtf8("label_01_Crop_Rect_Prz2"));
        label_01_Crop_Rect_Prz2->setMinimumSize(QSize(20, 0));
        label_01_Crop_Rect_Prz2->setMaximumSize(QSize(20, 16777215));

        gridLayout_65->addWidget(label_01_Crop_Rect_Prz2, 2, 3, 1, 1);

        stackedWidget_01_Crop_Shape->addWidget(page_01_Crop_RectRel);
        page_01_Crop_RectAbs = new QWidget();
        page_01_Crop_RectAbs->setObjectName(QString::fromUtf8("page_01_Crop_RectAbs"));
        gridLayout_79 = new QGridLayout(page_01_Crop_RectAbs);
        gridLayout_79->setSpacing(3);
        gridLayout_79->setObjectName(QString::fromUtf8("gridLayout_79"));
        gridLayout_79->setContentsMargins(0, 0, 0, 0);
        spinBox_01_Crop_RectAbs_Offset_Y = new QSpinBox(page_01_Crop_RectAbs);
        spinBox_01_Crop_RectAbs_Offset_Y->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectAbs_Offset_Y"));
        spinBox_01_Crop_RectAbs_Offset_Y->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_RectAbs_Offset_Y->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_RectAbs_Offset_Y->setMaximum(999999999);
        spinBox_01_Crop_RectAbs_Offset_Y->setValue(10);

        gridLayout_79->addWidget(spinBox_01_Crop_RectAbs_Offset_Y, 1, 2, 1, 1);

        spinBox_01_Crop_RectAbs_Offset_X = new QSpinBox(page_01_Crop_RectAbs);
        spinBox_01_Crop_RectAbs_Offset_X->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectAbs_Offset_X"));
        spinBox_01_Crop_RectAbs_Offset_X->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_RectAbs_Offset_X->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_RectAbs_Offset_X->setMaximum(999999999);
        spinBox_01_Crop_RectAbs_Offset_X->setValue(10);

        gridLayout_79->addWidget(spinBox_01_Crop_RectAbs_Offset_X, 1, 1, 1, 1);

        horizontalSpacer_01_Crop_RectAbs = new QSpacerItem(94, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_79->addItem(horizontalSpacer_01_Crop_RectAbs, 2, 4, 1, 1);

        label_01_Crop_RectAbs_Offset = new QLabel(page_01_Crop_RectAbs);
        label_01_Crop_RectAbs_Offset->setObjectName(QString::fromUtf8("label_01_Crop_RectAbs_Offset"));
        label_01_Crop_RectAbs_Offset->setMinimumSize(QSize(75, 0));
        label_01_Crop_RectAbs_Offset->setMaximumSize(QSize(75, 16777215));

        gridLayout_79->addWidget(label_01_Crop_RectAbs_Offset, 1, 0, 1, 1);

        label_01_Crop_RectAbs_X = new QLabel(page_01_Crop_RectAbs);
        label_01_Crop_RectAbs_X->setObjectName(QString::fromUtf8("label_01_Crop_RectAbs_X"));

        gridLayout_79->addWidget(label_01_Crop_RectAbs_X, 0, 1, 1, 1);

        spinBox_01_Crop_RectAbs_Size_Y = new QSpinBox(page_01_Crop_RectAbs);
        spinBox_01_Crop_RectAbs_Size_Y->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectAbs_Size_Y"));
        spinBox_01_Crop_RectAbs_Size_Y->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_RectAbs_Size_Y->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_RectAbs_Size_Y->setMinimum(1);
        spinBox_01_Crop_RectAbs_Size_Y->setMaximum(999999999);
        spinBox_01_Crop_RectAbs_Size_Y->setValue(10);

        gridLayout_79->addWidget(spinBox_01_Crop_RectAbs_Size_Y, 2, 2, 1, 1);

        label_01_Crop_RectAbs_Size = new QLabel(page_01_Crop_RectAbs);
        label_01_Crop_RectAbs_Size->setObjectName(QString::fromUtf8("label_01_Crop_RectAbs_Size"));
        label_01_Crop_RectAbs_Size->setMinimumSize(QSize(75, 0));
        label_01_Crop_RectAbs_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_79->addWidget(label_01_Crop_RectAbs_Size, 2, 0, 1, 1);

        verticalSpacer_01_Crop_RectAbs = new QSpacerItem(97, 111, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_79->addItem(verticalSpacer_01_Crop_RectAbs, 3, 2, 1, 1);

        spinBox_01_Crop_RectAbs_Size_X = new QSpinBox(page_01_Crop_RectAbs);
        spinBox_01_Crop_RectAbs_Size_X->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectAbs_Size_X"));
        spinBox_01_Crop_RectAbs_Size_X->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_RectAbs_Size_X->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_RectAbs_Size_X->setMinimum(1);
        spinBox_01_Crop_RectAbs_Size_X->setMaximum(999999999);
        spinBox_01_Crop_RectAbs_Size_X->setValue(10);

        gridLayout_79->addWidget(spinBox_01_Crop_RectAbs_Size_X, 2, 1, 1, 1);

        label_01_Crop_RectAbs_Y = new QLabel(page_01_Crop_RectAbs);
        label_01_Crop_RectAbs_Y->setObjectName(QString::fromUtf8("label_01_Crop_RectAbs_Y"));

        gridLayout_79->addWidget(label_01_Crop_RectAbs_Y, 0, 2, 1, 1);

        label_01_Crop_RectAbs_Offset_Unit = new QLabel(page_01_Crop_RectAbs);
        label_01_Crop_RectAbs_Offset_Unit->setObjectName(QString::fromUtf8("label_01_Crop_RectAbs_Offset_Unit"));

        gridLayout_79->addWidget(label_01_Crop_RectAbs_Offset_Unit, 1, 3, 1, 1);

        label_01_Crop_RectAbs_Size_Unit = new QLabel(page_01_Crop_RectAbs);
        label_01_Crop_RectAbs_Size_Unit->setObjectName(QString::fromUtf8("label_01_Crop_RectAbs_Size_Unit"));

        gridLayout_79->addWidget(label_01_Crop_RectAbs_Size_Unit, 2, 3, 1, 1);

        stackedWidget_01_Crop_Shape->addWidget(page_01_Crop_RectAbs);
        page_01_Crop_RectRot = new QWidget();
        page_01_Crop_RectRot->setObjectName(QString::fromUtf8("page_01_Crop_RectRot"));
        gridLayout_81 = new QGridLayout(page_01_Crop_RectRot);
        gridLayout_81->setSpacing(3);
        gridLayout_81->setObjectName(QString::fromUtf8("gridLayout_81"));
        gridLayout_81->setContentsMargins(0, 0, 0, 0);
        spinBox_01_Crop_RectRot_Height = new QSpinBox(page_01_Crop_RectRot);
        spinBox_01_Crop_RectRot_Height->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectRot_Height"));
        spinBox_01_Crop_RectRot_Height->setMinimum(1);
        spinBox_01_Crop_RectRot_Height->setMaximum(999999999);
        spinBox_01_Crop_RectRot_Height->setValue(10);

        gridLayout_81->addWidget(spinBox_01_Crop_RectRot_Height, 2, 2, 1, 1);

        label_01_Crop_RectRot_X = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_X->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_X"));

        gridLayout_81->addWidget(label_01_Crop_RectRot_X, 0, 1, 1, 1);

        spinBox_01_Crop_RectRot_Width = new QSpinBox(page_01_Crop_RectRot);
        spinBox_01_Crop_RectRot_Width->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectRot_Width"));
        spinBox_01_Crop_RectRot_Width->setMinimum(1);
        spinBox_01_Crop_RectRot_Width->setMaximum(999999999);
        spinBox_01_Crop_RectRot_Width->setValue(10);

        gridLayout_81->addWidget(spinBox_01_Crop_RectRot_Width, 2, 1, 1, 1);

        label_01_Crop_RectRot_Size_Unit = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Size_Unit->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Size_Unit"));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Size_Unit, 2, 3, 1, 1);

        spinBox_01_Crop_RectRot_Center_Y = new QSpinBox(page_01_Crop_RectRot);
        spinBox_01_Crop_RectRot_Center_Y->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectRot_Center_Y"));
        spinBox_01_Crop_RectRot_Center_Y->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_RectRot_Center_Y->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_RectRot_Center_Y->setMaximum(999999999);
        spinBox_01_Crop_RectRot_Center_Y->setValue(10);

        gridLayout_81->addWidget(spinBox_01_Crop_RectRot_Center_Y, 1, 2, 1, 1);

        label_01_Crop_RectRot_Y = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Y->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Y"));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Y, 0, 2, 1, 1);

        label_01_Crop_RectRot_Center = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Center->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Center"));
        label_01_Crop_RectRot_Center->setMinimumSize(QSize(75, 0));
        label_01_Crop_RectRot_Center->setMaximumSize(QSize(75, 16777215));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Center, 1, 0, 1, 1);

        spinBox_01_Crop_RectRot_Center_X = new QSpinBox(page_01_Crop_RectRot);
        spinBox_01_Crop_RectRot_Center_X->setObjectName(QString::fromUtf8("spinBox_01_Crop_RectRot_Center_X"));
        spinBox_01_Crop_RectRot_Center_X->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_RectRot_Center_X->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_RectRot_Center_X->setMaximum(999999999);
        spinBox_01_Crop_RectRot_Center_X->setValue(10);

        gridLayout_81->addWidget(spinBox_01_Crop_RectRot_Center_X, 1, 1, 1, 1);

        label_01_Crop_RectRot_Center_Unit = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Center_Unit->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Center_Unit"));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Center_Unit, 1, 3, 1, 1);

        label_01_Crop_RectRot_Size = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Size->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Size"));
        label_01_Crop_RectRot_Size->setMinimumSize(QSize(75, 0));
        label_01_Crop_RectRot_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Size, 2, 0, 1, 1);

        doubleSpinBox_01_Crop_RectRot_Rotation = new QDoubleSpinBox(page_01_Crop_RectRot);
        doubleSpinBox_01_Crop_RectRot_Rotation->setObjectName(QString::fromUtf8("doubleSpinBox_01_Crop_RectRot_Rotation"));
        doubleSpinBox_01_Crop_RectRot_Rotation->setMaximum(360.000000000000000);

        gridLayout_81->addWidget(doubleSpinBox_01_Crop_RectRot_Rotation, 3, 1, 1, 2);

        label_01_Crop_RectRot_Rotation_Unit = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Rotation_Unit->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Rotation_Unit"));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Rotation_Unit, 3, 3, 1, 1);

        label_01_Crop_RectRot_Rotation = new QLabel(page_01_Crop_RectRot);
        label_01_Crop_RectRot_Rotation->setObjectName(QString::fromUtf8("label_01_Crop_RectRot_Rotation"));

        gridLayout_81->addWidget(label_01_Crop_RectRot_Rotation, 3, 0, 1, 1);

        horizontalSpacer_01_Crop_RectRot = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_81->addItem(horizontalSpacer_01_Crop_RectRot, 3, 4, 1, 1);

        verticalSpacer_01_Crop_RectRot = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_81->addItem(verticalSpacer_01_Crop_RectRot, 4, 0, 1, 3);

        stackedWidget_01_Crop_Shape->addWidget(page_01_Crop_RectRot);
        page_01_Crop_Circle = new QWidget();
        page_01_Crop_Circle->setObjectName(QString::fromUtf8("page_01_Crop_Circle"));
        gridLayout_82 = new QGridLayout(page_01_Crop_Circle);
        gridLayout_82->setSpacing(3);
        gridLayout_82->setObjectName(QString::fromUtf8("gridLayout_82"));
        gridLayout_82->setContentsMargins(0, 0, 0, 0);
        label_01_Crop_Circle_X = new QLabel(page_01_Crop_Circle);
        label_01_Crop_Circle_X->setObjectName(QString::fromUtf8("label_01_Crop_Circle_X"));

        gridLayout_82->addWidget(label_01_Crop_Circle_X, 0, 1, 1, 1);

        label_01_Crop_Circle_Y = new QLabel(page_01_Crop_Circle);
        label_01_Crop_Circle_Y->setObjectName(QString::fromUtf8("label_01_Crop_Circle_Y"));

        gridLayout_82->addWidget(label_01_Crop_Circle_Y, 0, 2, 1, 1);

        label_01_Crop_Circle_Center = new QLabel(page_01_Crop_Circle);
        label_01_Crop_Circle_Center->setObjectName(QString::fromUtf8("label_01_Crop_Circle_Center"));
        label_01_Crop_Circle_Center->setMinimumSize(QSize(75, 0));
        label_01_Crop_Circle_Center->setMaximumSize(QSize(75, 16777215));

        gridLayout_82->addWidget(label_01_Crop_Circle_Center, 1, 0, 1, 1);

        spinBox_01_Crop_Circle_Center_X = new QSpinBox(page_01_Crop_Circle);
        spinBox_01_Crop_Circle_Center_X->setObjectName(QString::fromUtf8("spinBox_01_Crop_Circle_Center_X"));
        spinBox_01_Crop_Circle_Center_X->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_Circle_Center_X->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_Circle_Center_X->setMaximum(999999999);
        spinBox_01_Crop_Circle_Center_X->setValue(10);

        gridLayout_82->addWidget(spinBox_01_Crop_Circle_Center_X, 1, 1, 1, 1);

        spinBox_01_Crop_Circle_Center_Y = new QSpinBox(page_01_Crop_Circle);
        spinBox_01_Crop_Circle_Center_Y->setObjectName(QString::fromUtf8("spinBox_01_Crop_Circle_Center_Y"));
        spinBox_01_Crop_Circle_Center_Y->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_Circle_Center_Y->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_Circle_Center_Y->setMaximum(999999999);
        spinBox_01_Crop_Circle_Center_Y->setValue(10);

        gridLayout_82->addWidget(spinBox_01_Crop_Circle_Center_Y, 1, 2, 1, 1);

        label_01_Crop_Circle_Center_Unit = new QLabel(page_01_Crop_Circle);
        label_01_Crop_Circle_Center_Unit->setObjectName(QString::fromUtf8("label_01_Crop_Circle_Center_Unit"));

        gridLayout_82->addWidget(label_01_Crop_Circle_Center_Unit, 1, 3, 1, 1);

        label_01_Crop_Circle_Radius = new QLabel(page_01_Crop_Circle);
        label_01_Crop_Circle_Radius->setObjectName(QString::fromUtf8("label_01_Crop_Circle_Radius"));
        label_01_Crop_Circle_Radius->setMinimumSize(QSize(75, 0));
        label_01_Crop_Circle_Radius->setMaximumSize(QSize(75, 16777215));

        gridLayout_82->addWidget(label_01_Crop_Circle_Radius, 2, 0, 1, 1);

        label_01_Crop_Circle_Radius_Unit = new QLabel(page_01_Crop_Circle);
        label_01_Crop_Circle_Radius_Unit->setObjectName(QString::fromUtf8("label_01_Crop_Circle_Radius_Unit"));

        gridLayout_82->addWidget(label_01_Crop_Circle_Radius_Unit, 2, 3, 1, 1);

        verticalSpacer_01_Crop_Circle = new QSpacerItem(278, 110, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_82->addItem(verticalSpacer_01_Crop_Circle, 4, 0, 1, 3);

        horizontalSpacer_01_Crop_Circle = new QSpacerItem(94, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_82->addItem(horizontalSpacer_01_Crop_Circle, 2, 4, 2, 1);

        spinBox_01_Crop_Circle_Radius = new QSpinBox(page_01_Crop_Circle);
        spinBox_01_Crop_Circle_Radius->setObjectName(QString::fromUtf8("spinBox_01_Crop_Circle_Radius"));
        spinBox_01_Crop_Circle_Radius->setMinimum(1);
        spinBox_01_Crop_Circle_Radius->setMaximum(999999999);
        spinBox_01_Crop_Circle_Radius->setValue(5);

        gridLayout_82->addWidget(spinBox_01_Crop_Circle_Radius, 2, 1, 1, 2);

        stackedWidget_01_Crop_Shape->addWidget(page_01_Crop_Circle);
        page_01_Crop_Ellipse = new QWidget();
        page_01_Crop_Ellipse->setObjectName(QString::fromUtf8("page_01_Crop_Ellipse"));
        gridLayout_83 = new QGridLayout(page_01_Crop_Ellipse);
        gridLayout_83->setSpacing(3);
        gridLayout_83->setObjectName(QString::fromUtf8("gridLayout_83"));
        gridLayout_83->setContentsMargins(0, 0, 0, 0);
        label_01_Crop_Ellipse_X = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_X->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_X"));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_X, 0, 1, 1, 1);

        label_01_Crop_Ellipse_Y = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Y->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Y"));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Y, 0, 2, 1, 1);

        label_01_Crop_Ellipse_Center = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Center->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Center"));
        label_01_Crop_Ellipse_Center->setMinimumSize(QSize(75, 0));
        label_01_Crop_Ellipse_Center->setMaximumSize(QSize(75, 16777215));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Center, 1, 0, 1, 1);

        spinBox_01_Crop_Ellipse_Center_X = new QSpinBox(page_01_Crop_Ellipse);
        spinBox_01_Crop_Ellipse_Center_X->setObjectName(QString::fromUtf8("spinBox_01_Crop_Ellipse_Center_X"));
        spinBox_01_Crop_Ellipse_Center_X->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_Ellipse_Center_X->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_Ellipse_Center_X->setMaximum(999999999);
        spinBox_01_Crop_Ellipse_Center_X->setValue(10);

        gridLayout_83->addWidget(spinBox_01_Crop_Ellipse_Center_X, 1, 1, 1, 1);

        spinBox_01_Crop_Ellipse_Center_Y = new QSpinBox(page_01_Crop_Ellipse);
        spinBox_01_Crop_Ellipse_Center_Y->setObjectName(QString::fromUtf8("spinBox_01_Crop_Ellipse_Center_Y"));
        spinBox_01_Crop_Ellipse_Center_Y->setMinimumSize(QSize(100, 0));
        spinBox_01_Crop_Ellipse_Center_Y->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Crop_Ellipse_Center_Y->setMaximum(999999999);
        spinBox_01_Crop_Ellipse_Center_Y->setValue(10);

        gridLayout_83->addWidget(spinBox_01_Crop_Ellipse_Center_Y, 1, 2, 1, 1);

        label_01_Crop_Ellipse_Center_Unit = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Center_Unit->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Center_Unit"));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Center_Unit, 1, 3, 1, 1);

        label_01_Crop_Ellipse_Size = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Size->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Size"));
        label_01_Crop_Ellipse_Size->setMinimumSize(QSize(75, 0));
        label_01_Crop_Ellipse_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Size, 2, 0, 1, 1);

        spinBox_01_Crop_Ellipse_Width = new QSpinBox(page_01_Crop_Ellipse);
        spinBox_01_Crop_Ellipse_Width->setObjectName(QString::fromUtf8("spinBox_01_Crop_Ellipse_Width"));
        spinBox_01_Crop_Ellipse_Width->setMinimum(1);
        spinBox_01_Crop_Ellipse_Width->setMaximum(999999999);
        spinBox_01_Crop_Ellipse_Width->setValue(10);

        gridLayout_83->addWidget(spinBox_01_Crop_Ellipse_Width, 2, 1, 1, 1);

        spinBox_01_Crop_Ellipse_Height = new QSpinBox(page_01_Crop_Ellipse);
        spinBox_01_Crop_Ellipse_Height->setObjectName(QString::fromUtf8("spinBox_01_Crop_Ellipse_Height"));
        spinBox_01_Crop_Ellipse_Height->setMinimum(1);
        spinBox_01_Crop_Ellipse_Height->setMaximum(999999999);
        spinBox_01_Crop_Ellipse_Height->setValue(10);

        gridLayout_83->addWidget(spinBox_01_Crop_Ellipse_Height, 2, 2, 1, 1);

        label_01_Crop_Ellipse_Size_Unit = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Size_Unit->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Size_Unit"));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Size_Unit, 2, 3, 1, 1);

        label_01_Crop_Ellipse_Rotation = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Rotation->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Rotation"));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Rotation, 3, 0, 1, 1);

        doubleSpinBox_01_Crop_Ellipse_Rotation = new QDoubleSpinBox(page_01_Crop_Ellipse);
        doubleSpinBox_01_Crop_Ellipse_Rotation->setObjectName(QString::fromUtf8("doubleSpinBox_01_Crop_Ellipse_Rotation"));
        doubleSpinBox_01_Crop_Ellipse_Rotation->setMaximum(360.000000000000000);

        gridLayout_83->addWidget(doubleSpinBox_01_Crop_Ellipse_Rotation, 3, 1, 1, 2);

        label_01_Crop_Ellipse_Rotation_Unit = new QLabel(page_01_Crop_Ellipse);
        label_01_Crop_Ellipse_Rotation_Unit->setObjectName(QString::fromUtf8("label_01_Crop_Ellipse_Rotation_Unit"));

        gridLayout_83->addWidget(label_01_Crop_Ellipse_Rotation_Unit, 3, 3, 1, 1);

        verticalSpacer_01_Crop_Ellipse = new QSpacerItem(278, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_83->addItem(verticalSpacer_01_Crop_Ellipse, 4, 0, 1, 3);

        horizontalSpacer_01_Crop_Ellipse = new QSpacerItem(94, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_83->addItem(horizontalSpacer_01_Crop_Ellipse, 3, 4, 1, 1);

        stackedWidget_01_Crop_Shape->addWidget(page_01_Crop_Ellipse);

        gridLayout_64->addWidget(stackedWidget_01_Crop_Shape, 1, 1, 1, 3);

        stackedWidget_Settings_01_Edit->addWidget(page_01_Crop);
        page_01_Floodfill = new QWidget();
        page_01_Floodfill->setObjectName(QString::fromUtf8("page_01_Floodfill"));
        gridLayout_72 = new QGridLayout(page_01_Floodfill);
        gridLayout_72->setSpacing(3);
        gridLayout_72->setObjectName(QString::fromUtf8("gridLayout_72"));
        label_01_Floodfill_Type = new QLabel(page_01_Floodfill);
        label_01_Floodfill_Type->setObjectName(QString::fromUtf8("label_01_Floodfill_Type"));
        label_01_Floodfill_Type->setMinimumSize(QSize(75, 0));

        gridLayout_72->addWidget(label_01_Floodfill_Type, 0, 1, 1, 1);

        line_01_Floodfill = new QFrame(page_01_Floodfill);
        line_01_Floodfill->setObjectName(QString::fromUtf8("line_01_Floodfill"));
        line_01_Floodfill->setFrameShape(QFrame::VLine);
        line_01_Floodfill->setFrameShadow(QFrame::Sunken);

        gridLayout_72->addWidget(line_01_Floodfill, 0, 0, 3, 1);

        horizontalSpacer_01_Floodfill = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_72->addItem(horizontalSpacer_01_Floodfill, 0, 3, 1, 1);

        stackedWidget_01_Floodfill_Type = new QStackedWidget(page_01_Floodfill);
        stackedWidget_01_Floodfill_Type->setObjectName(QString::fromUtf8("stackedWidget_01_Floodfill_Type"));
        page_01_Floodfill_Border = new QWidget();
        page_01_Floodfill_Border->setObjectName(QString::fromUtf8("page_01_Floodfill_Border"));
        gridLayout_71 = new QGridLayout(page_01_Floodfill_Border);
        gridLayout_71->setSpacing(6);
        gridLayout_71->setObjectName(QString::fromUtf8("gridLayout_71"));
        gridLayout_71->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_01_Floodfill_Border = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_71->addItem(horizontalSpacer_01_Floodfill_Border, 1, 1, 1, 1);

        verticalSpacer_01_Floodfill_Border = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_71->addItem(verticalSpacer_01_Floodfill_Border, 2, 0, 1, 1);

        stackedWidget_01_Floodfill_Type->addWidget(page_01_Floodfill_Border);
        page_01_Floodfill_Delta = new QWidget();
        page_01_Floodfill_Delta->setObjectName(QString::fromUtf8("page_01_Floodfill_Delta"));
        gridLayout_120 = new QGridLayout(page_01_Floodfill_Delta);
        gridLayout_120->setSpacing(3);
        gridLayout_120->setObjectName(QString::fromUtf8("gridLayout_120"));
        gridLayout_120->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_01_Floodfill_Delta = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_120->addItem(horizontalSpacer_01_Floodfill_Delta, 0, 3, 1, 1);

        label_01_Floodfill_Delta_Seed = new QLabel(page_01_Floodfill_Delta);
        label_01_Floodfill_Delta_Seed->setObjectName(QString::fromUtf8("label_01_Floodfill_Delta_Seed"));
        label_01_Floodfill_Delta_Seed->setMinimumSize(QSize(75, 0));
        label_01_Floodfill_Delta_Seed->setMaximumSize(QSize(75, 16777215));

        gridLayout_120->addWidget(label_01_Floodfill_Delta_Seed, 0, 0, 1, 1);

        doubleSpinBox_01_Floodfill_Delta_Delta = new QDoubleSpinBox(page_01_Floodfill_Delta);
        doubleSpinBox_01_Floodfill_Delta_Delta->setObjectName(QString::fromUtf8("doubleSpinBox_01_Floodfill_Delta_Delta"));
        doubleSpinBox_01_Floodfill_Delta_Delta->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Floodfill_Delta_Delta->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Floodfill_Delta_Delta->setDecimals(0);
        doubleSpinBox_01_Floodfill_Delta_Delta->setMaximum(255.000000000000000);
        doubleSpinBox_01_Floodfill_Delta_Delta->setValue(5.000000000000000);

        gridLayout_120->addWidget(doubleSpinBox_01_Floodfill_Delta_Delta, 1, 1, 1, 2);

        spinBox_01_Floodfill_Delta_SeedX = new QSpinBox(page_01_Floodfill_Delta);
        spinBox_01_Floodfill_Delta_SeedX->setObjectName(QString::fromUtf8("spinBox_01_Floodfill_Delta_SeedX"));
        spinBox_01_Floodfill_Delta_SeedX->setMinimumSize(QSize(48, 0));
        spinBox_01_Floodfill_Delta_SeedX->setMaximumSize(QSize(48, 16777215));
        spinBox_01_Floodfill_Delta_SeedX->setMaximum(999999);

        gridLayout_120->addWidget(spinBox_01_Floodfill_Delta_SeedX, 0, 1, 1, 1);

        verticalSpacer_01_Floodfill_Delta = new QSpacerItem(20, 116, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_120->addItem(verticalSpacer_01_Floodfill_Delta, 4, 3, 1, 1);

        label_01_Floodfill_Delta_Delta = new QLabel(page_01_Floodfill_Delta);
        label_01_Floodfill_Delta_Delta->setObjectName(QString::fromUtf8("label_01_Floodfill_Delta_Delta"));
        label_01_Floodfill_Delta_Delta->setMinimumSize(QSize(75, 0));
        label_01_Floodfill_Delta_Delta->setMaximumSize(QSize(75, 16777215));

        gridLayout_120->addWidget(label_01_Floodfill_Delta_Delta, 1, 0, 1, 1);

        spinBox_01_Floodfill_Delta_SeedY = new QSpinBox(page_01_Floodfill_Delta);
        spinBox_01_Floodfill_Delta_SeedY->setObjectName(QString::fromUtf8("spinBox_01_Floodfill_Delta_SeedY"));
        spinBox_01_Floodfill_Delta_SeedY->setMinimumSize(QSize(48, 0));
        spinBox_01_Floodfill_Delta_SeedY->setMaximumSize(QSize(48, 16777215));
        spinBox_01_Floodfill_Delta_SeedY->setMaximum(999999);

        gridLayout_120->addWidget(spinBox_01_Floodfill_Delta_SeedY, 0, 2, 1, 1);

        label_13 = new QLabel(page_01_Floodfill_Delta);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("color: red"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_120->addWidget(label_13, 2, 1, 1, 3);

        label_14 = new QLabel(page_01_Floodfill_Delta);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("color: red"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_120->addWidget(label_14, 3, 1, 1, 3);

        stackedWidget_01_Floodfill_Type->addWidget(page_01_Floodfill_Delta);

        gridLayout_72->addWidget(stackedWidget_01_Floodfill_Type, 2, 1, 1, 3);

        comboBox_01_Floodfill_Type = new QComboBox(page_01_Floodfill);
        comboBox_01_Floodfill_Type->addItem(QString());
        comboBox_01_Floodfill_Type->addItem(QString());
        comboBox_01_Floodfill_Type->setObjectName(QString::fromUtf8("comboBox_01_Floodfill_Type"));
        comboBox_01_Floodfill_Type->setMinimumSize(QSize(200, 0));
        comboBox_01_Floodfill_Type->setMaximumSize(QSize(200, 16777215));

        gridLayout_72->addWidget(comboBox_01_Floodfill_Type, 0, 2, 1, 1);

        label_01_Floodfill_Fill = new QLabel(page_01_Floodfill);
        label_01_Floodfill_Fill->setObjectName(QString::fromUtf8("label_01_Floodfill_Fill"));
        label_01_Floodfill_Fill->setMinimumSize(QSize(75, 0));

        gridLayout_72->addWidget(label_01_Floodfill_Fill, 1, 1, 1, 1);

        doubleSpinBox_01_Floodfill_Value_Fill = new QDoubleSpinBox(page_01_Floodfill);
        doubleSpinBox_01_Floodfill_Value_Fill->setObjectName(QString::fromUtf8("doubleSpinBox_01_Floodfill_Value_Fill"));
        doubleSpinBox_01_Floodfill_Value_Fill->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Floodfill_Value_Fill->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Floodfill_Value_Fill->setDecimals(3);
        doubleSpinBox_01_Floodfill_Value_Fill->setMinimum(-1000000.000000000000000);
        doubleSpinBox_01_Floodfill_Value_Fill->setMaximum(1000000.000000000000000);
        doubleSpinBox_01_Floodfill_Value_Fill->setValue(255.000000000000000);

        gridLayout_72->addWidget(doubleSpinBox_01_Floodfill_Value_Fill, 1, 2, 1, 1);

        stackedWidget_Settings_01_Edit->addWidget(page_01_Floodfill);
        page_01_Padding = new QWidget();
        page_01_Padding->setObjectName(QString::fromUtf8("page_01_Padding"));
        gridLayout_73 = new QGridLayout(page_01_Padding);
        gridLayout_73->setObjectName(QString::fromUtf8("gridLayout_73"));
        label_01_Padding_Width_X = new QLabel(page_01_Padding);
        label_01_Padding_Width_X->setObjectName(QString::fromUtf8("label_01_Padding_Width_X"));
        label_01_Padding_Width_X->setMinimumSize(QSize(75, 0));
        label_01_Padding_Width_X->setMaximumSize(QSize(75, 16777215));

        gridLayout_73->addWidget(label_01_Padding_Width_X, 0, 1, 1, 1);

        spinBox_01_Padding_Width_X = new QSpinBox(page_01_Padding);
        spinBox_01_Padding_Width_X->setObjectName(QString::fromUtf8("spinBox_01_Padding_Width_X"));
        spinBox_01_Padding_Width_X->setMinimumSize(QSize(100, 0));
        spinBox_01_Padding_Width_X->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Padding_Width_X->setMaximum(10000);
        spinBox_01_Padding_Width_X->setValue(1);

        gridLayout_73->addWidget(spinBox_01_Padding_Width_X, 0, 2, 1, 1);

        horizontalSpacer_01_Padding = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_73->addItem(horizontalSpacer_01_Padding, 0, 3, 1, 1);

        label_01_Padding_Type = new QLabel(page_01_Padding);
        label_01_Padding_Type->setObjectName(QString::fromUtf8("label_01_Padding_Type"));
        label_01_Padding_Type->setEnabled(true);
        label_01_Padding_Type->setMinimumSize(QSize(75, 0));
        label_01_Padding_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_73->addWidget(label_01_Padding_Type, 3, 1, 1, 1);

        verticalSpacer_01_Padding = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_73->addItem(verticalSpacer_01_Padding, 5, 1, 1, 1);

        line_01_Padding = new QFrame(page_01_Padding);
        line_01_Padding->setObjectName(QString::fromUtf8("line_01_Padding"));
        line_01_Padding->setFrameShape(QFrame::VLine);
        line_01_Padding->setFrameShadow(QFrame::Sunken);

        gridLayout_73->addWidget(line_01_Padding, 0, 0, 6, 1);

        comboBox_01_Padding_Type = new QComboBox(page_01_Padding);
        comboBox_01_Padding_Type->addItem(QString());
        comboBox_01_Padding_Type->addItem(QString());
        comboBox_01_Padding_Type->addItem(QString());
        comboBox_01_Padding_Type->addItem(QString());
        comboBox_01_Padding_Type->addItem(QString());
        comboBox_01_Padding_Type->setObjectName(QString::fromUtf8("comboBox_01_Padding_Type"));
        comboBox_01_Padding_Type->setMinimumSize(QSize(100, 0));
        comboBox_01_Padding_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_73->addWidget(comboBox_01_Padding_Type, 3, 2, 1, 1);

        label_01_Padding_Width_Z = new QLabel(page_01_Padding);
        label_01_Padding_Width_Z->setObjectName(QString::fromUtf8("label_01_Padding_Width_Z"));
        label_01_Padding_Width_Z->setEnabled(false);

        gridLayout_73->addWidget(label_01_Padding_Width_Z, 2, 1, 1, 1);

        label_01_Padding_Value = new QLabel(page_01_Padding);
        label_01_Padding_Value->setObjectName(QString::fromUtf8("label_01_Padding_Value"));

        gridLayout_73->addWidget(label_01_Padding_Value, 4, 1, 1, 1);

        label_01_Padding_Width_Y = new QLabel(page_01_Padding);
        label_01_Padding_Width_Y->setObjectName(QString::fromUtf8("label_01_Padding_Width_Y"));

        gridLayout_73->addWidget(label_01_Padding_Width_Y, 1, 1, 1, 1);

        spinBox_01_Padding_Width_Y = new QSpinBox(page_01_Padding);
        spinBox_01_Padding_Width_Y->setObjectName(QString::fromUtf8("spinBox_01_Padding_Width_Y"));
        spinBox_01_Padding_Width_Y->setMinimumSize(QSize(100, 0));
        spinBox_01_Padding_Width_Y->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Padding_Width_Y->setMaximum(10000);
        spinBox_01_Padding_Width_Y->setValue(1);

        gridLayout_73->addWidget(spinBox_01_Padding_Width_Y, 1, 2, 1, 1);

        spinBox_01_Padding_Width_Z = new QSpinBox(page_01_Padding);
        spinBox_01_Padding_Width_Z->setObjectName(QString::fromUtf8("spinBox_01_Padding_Width_Z"));
        spinBox_01_Padding_Width_Z->setEnabled(false);
        spinBox_01_Padding_Width_Z->setMinimumSize(QSize(100, 0));
        spinBox_01_Padding_Width_Z->setMaximumSize(QSize(100, 16777215));
        spinBox_01_Padding_Width_Z->setMaximum(10000);
        spinBox_01_Padding_Width_Z->setValue(1);

        gridLayout_73->addWidget(spinBox_01_Padding_Width_Z, 2, 2, 1, 1);

        doubleSpinBox_01_Padding_Value = new QDoubleSpinBox(page_01_Padding);
        doubleSpinBox_01_Padding_Value->setObjectName(QString::fromUtf8("doubleSpinBox_01_Padding_Value"));
        doubleSpinBox_01_Padding_Value->setMinimumSize(QSize(100, 0));
        doubleSpinBox_01_Padding_Value->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_01_Padding_Value->setDecimals(3);
        doubleSpinBox_01_Padding_Value->setMinimum(-1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_01_Padding_Value->setMaximum(100000000000000003080666323096525690777025204007643346346089744069413985291331436544.000000000000000);

        gridLayout_73->addWidget(doubleSpinBox_01_Padding_Value, 4, 2, 1, 1);

        stackedWidget_Settings_01_Edit->addWidget(page_01_Padding);
        page_01_ForceSize = new QWidget();
        page_01_ForceSize->setObjectName(QString::fromUtf8("page_01_ForceSize"));
        gridLayout_116 = new QGridLayout(page_01_ForceSize);
        gridLayout_116->setObjectName(QString::fromUtf8("gridLayout_116"));
        spinBox_01_ForceSize_Height = new QSpinBox(page_01_ForceSize);
        spinBox_01_ForceSize_Height->setObjectName(QString::fromUtf8("spinBox_01_ForceSize_Height"));
        spinBox_01_ForceSize_Height->setMinimumSize(QSize(100, 0));
        spinBox_01_ForceSize_Height->setMaximumSize(QSize(100, 16777215));
        spinBox_01_ForceSize_Height->setMinimum(1);
        spinBox_01_ForceSize_Height->setMaximum(999999);
        spinBox_01_ForceSize_Height->setSingleStep(50);
        spinBox_01_ForceSize_Height->setValue(1000);

        gridLayout_116->addWidget(spinBox_01_ForceSize_Height, 1, 1, 1, 1);

        spinBox_01_ForceSize_Width = new QSpinBox(page_01_ForceSize);
        spinBox_01_ForceSize_Width->setObjectName(QString::fromUtf8("spinBox_01_ForceSize_Width"));
        spinBox_01_ForceSize_Width->setMinimumSize(QSize(100, 0));
        spinBox_01_ForceSize_Width->setMaximumSize(QSize(100, 16777215));
        spinBox_01_ForceSize_Width->setMinimum(1);
        spinBox_01_ForceSize_Width->setMaximum(999999);
        spinBox_01_ForceSize_Width->setSingleStep(50);
        spinBox_01_ForceSize_Width->setValue(1000);

        gridLayout_116->addWidget(spinBox_01_ForceSize_Width, 0, 1, 1, 1);

        label_01_ForceSize_Width = new QLabel(page_01_ForceSize);
        label_01_ForceSize_Width->setObjectName(QString::fromUtf8("label_01_ForceSize_Width"));
        label_01_ForceSize_Width->setMinimumSize(QSize(75, 0));
        label_01_ForceSize_Width->setMaximumSize(QSize(75, 16777215));

        gridLayout_116->addWidget(label_01_ForceSize_Width, 0, 0, 1, 1);

        horizontalSpacer_01_ForceSize = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_116->addItem(horizontalSpacer_01_ForceSize, 0, 2, 1, 1);

        verticalSpacer_01_ForceSize = new QSpacerItem(20, 130, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_116->addItem(verticalSpacer_01_ForceSize, 3, 0, 1, 1);

        label_01_ForceSize_Height = new QLabel(page_01_ForceSize);
        label_01_ForceSize_Height->setObjectName(QString::fromUtf8("label_01_ForceSize_Height"));
        label_01_ForceSize_Height->setMinimumSize(QSize(75, 0));
        label_01_ForceSize_Height->setMaximumSize(QSize(75, 16777215));

        gridLayout_116->addWidget(label_01_ForceSize_Height, 1, 0, 1, 1);

        label_01_ForceSize_Border = new QLabel(page_01_ForceSize);
        label_01_ForceSize_Border->setObjectName(QString::fromUtf8("label_01_ForceSize_Border"));

        gridLayout_116->addWidget(label_01_ForceSize_Border, 2, 0, 1, 1);

        comboBox_01_ForceSize_Border = new QComboBox(page_01_ForceSize);
        comboBox_01_ForceSize_Border->addItem(QString());
        comboBox_01_ForceSize_Border->addItem(QString());
        comboBox_01_ForceSize_Border->addItem(QString());
        comboBox_01_ForceSize_Border->addItem(QString());
        comboBox_01_ForceSize_Border->addItem(QString());
        comboBox_01_ForceSize_Border->setObjectName(QString::fromUtf8("comboBox_01_ForceSize_Border"));

        gridLayout_116->addWidget(comboBox_01_ForceSize_Border, 2, 1, 1, 1);

        stackedWidget_Settings_01_Edit->addWidget(page_01_ForceSize);

        gridLayout_18->addWidget(stackedWidget_Settings_01_Edit, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_01_Edit);
        page_Settings_02_Convert = new QWidget();
        page_Settings_02_Convert->setObjectName(QString::fromUtf8("page_Settings_02_Convert"));
        gridLayout_19 = new QGridLayout(page_Settings_02_Convert);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_02_Convert = new QStackedWidget(page_Settings_02_Convert);
        stackedWidget_Settings_02_Convert->setObjectName(QString::fromUtf8("stackedWidget_Settings_02_Convert"));
        page_02_Color2Mono = new QWidget();
        page_02_Color2Mono->setObjectName(QString::fromUtf8("page_02_Color2Mono"));
        gridLayout_94 = new QGridLayout(page_02_Color2Mono);
        gridLayout_94->setObjectName(QString::fromUtf8("gridLayout_94"));
        label_02_Color2Mono_Reduction = new QLabel(page_02_Color2Mono);
        label_02_Color2Mono_Reduction->setObjectName(QString::fromUtf8("label_02_Color2Mono_Reduction"));
        label_02_Color2Mono_Reduction->setMinimumSize(QSize(75, 0));
        label_02_Color2Mono_Reduction->setMaximumSize(QSize(75, 16777215));

        gridLayout_94->addWidget(label_02_Color2Mono_Reduction, 0, 1, 1, 1);

        verticalSpacer_02_Color2Mono = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_94->addItem(verticalSpacer_02_Color2Mono, 1, 1, 1, 1);

        line_02_Color2Mono = new QFrame(page_02_Color2Mono);
        line_02_Color2Mono->setObjectName(QString::fromUtf8("line_02_Color2Mono"));
        line_02_Color2Mono->setFrameShape(QFrame::VLine);
        line_02_Color2Mono->setFrameShadow(QFrame::Sunken);

        gridLayout_94->addWidget(line_02_Color2Mono, 0, 0, 2, 1);

        comboBox_02_Color2Mono_Reduction = new QComboBox(page_02_Color2Mono);
        comboBox_02_Color2Mono_Reduction->setObjectName(QString::fromUtf8("comboBox_02_Color2Mono_Reduction"));
        comboBox_02_Color2Mono_Reduction->setMinimumSize(QSize(100, 0));
        comboBox_02_Color2Mono_Reduction->setMaximumSize(QSize(100, 16777215));

        gridLayout_94->addWidget(comboBox_02_Color2Mono_Reduction, 0, 2, 1, 1);

        horizontalSpacer_02_Color2Mono = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_94->addItem(horizontalSpacer_02_Color2Mono, 0, 3, 1, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Color2Mono);
        page_02_Color = new QWidget();
        page_02_Color->setObjectName(QString::fromUtf8("page_02_Color"));
        gridLayout_30 = new QGridLayout(page_02_Color);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        label_02_Color_HSL = new QLabel(page_02_Color);
        label_02_Color_HSL->setObjectName(QString::fromUtf8("label_02_Color_HSL"));
        label_02_Color_HSL->setMinimumSize(QSize(30, 0));
        label_02_Color_HSL->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_HSL, 2, 9, 1, 1);

        label_02_Color_BGR_1 = new QLabel(page_02_Color);
        label_02_Color_BGR_1->setObjectName(QString::fromUtf8("label_02_Color_BGR_1"));
        label_02_Color_BGR_1->setMinimumSize(QSize(30, 0));
        label_02_Color_BGR_1->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_BGR_1, 2, 4, 1, 1);

        label_02_Color_Luv = new QLabel(page_02_Color);
        label_02_Color_Luv->setObjectName(QString::fromUtf8("label_02_Color_Luv"));
        label_02_Color_Luv->setMinimumSize(QSize(30, 0));
        label_02_Color_Luv->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_Luv, 2, 11, 1, 1);

        label_02_Color_RGB_1 = new QLabel(page_02_Color);
        label_02_Color_RGB_1->setObjectName(QString::fromUtf8("label_02_Color_RGB_1"));
        label_02_Color_RGB_1->setMinimumSize(QSize(30, 0));
        label_02_Color_RGB_1->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_RGB_1, 2, 3, 1, 1);

        label_02_Color_Lab = new QLabel(page_02_Color);
        label_02_Color_Lab->setObjectName(QString::fromUtf8("label_02_Color_Lab"));
        label_02_Color_Lab->setMinimumSize(QSize(30, 0));
        label_02_Color_Lab->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_Lab, 2, 10, 1, 1);

        label_02_Color_Grey = new QLabel(page_02_Color);
        label_02_Color_Grey->setObjectName(QString::fromUtf8("label_02_Color_Grey"));
        label_02_Color_Grey->setMinimumSize(QSize(30, 0));
        label_02_Color_Grey->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_Grey, 2, 5, 1, 1);

        radioButton_02_Color_YCrCb_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_YCrCb_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_YCrCb_BGR"));
        radioButton_02_Color_YCrCb_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_YCrCb_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_YCrCb_BGR, 4, 7, 1, 1);

        radioButton_02_Color_XYZ_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_XYZ_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_XYZ_BGR"));
        radioButton_02_Color_XYZ_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_XYZ_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_XYZ_BGR, 4, 6, 1, 1);

        radioButton_02_Color_RGB_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_RGB_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_RGB_BGR"));
        radioButton_02_Color_RGB_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_RGB_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_RGB_BGR, 4, 3, 1, 1);

        radioButton_02_Color_HSL_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_HSL_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_HSL_BGR"));
        radioButton_02_Color_HSL_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_HSL_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_HSL_BGR, 4, 9, 1, 1);

        label_02_Color_RGB_2 = new QLabel(page_02_Color);
        label_02_Color_RGB_2->setObjectName(QString::fromUtf8("label_02_Color_RGB_2"));
        label_02_Color_RGB_2->setMinimumSize(QSize(30, 0));
        label_02_Color_RGB_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_RGB_2, 3, 2, 1, 1);

        radioButton_02_Color_Lab_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_Lab_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_Lab_BGR"));
        radioButton_02_Color_Lab_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_Lab_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_Lab_BGR, 4, 10, 1, 1);

        radioButton_02_Color_HSV_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_HSV_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_HSV_BGR"));
        radioButton_02_Color_HSV_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_HSV_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_HSV_BGR, 4, 8, 1, 1);

        horizontalSpacer_02_Color = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_30->addItem(horizontalSpacer_02_Color, 2, 12, 3, 1);

        radioButton_02_Color_Grey_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_Grey_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_Grey_BGR"));
        radioButton_02_Color_Grey_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_Grey_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_Grey_BGR, 4, 5, 1, 1);

        label_02_Color_BGR_2 = new QLabel(page_02_Color);
        label_02_Color_BGR_2->setObjectName(QString::fromUtf8("label_02_Color_BGR_2"));
        label_02_Color_BGR_2->setMinimumSize(QSize(30, 0));
        label_02_Color_BGR_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_BGR_2, 4, 2, 1, 1);

        radioButton_02_Color_Lab_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_Lab_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_Lab_RGB"));
        radioButton_02_Color_Lab_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_Lab_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_Lab_RGB, 3, 10, 1, 1);

        radioButton_02_Color_BGR_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_BGR_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_BGR_RGB"));
        radioButton_02_Color_BGR_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_BGR_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_BGR_RGB, 3, 4, 1, 1);

        radioButton_02_Color_HSV_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_HSV_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_HSV_RGB"));
        radioButton_02_Color_HSV_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_HSV_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_HSV_RGB, 3, 8, 1, 1);

        radioButton_02_Color_Luv_BGR = new QRadioButton(page_02_Color);
        radioButton_02_Color_Luv_BGR->setObjectName(QString::fromUtf8("radioButton_02_Color_Luv_BGR"));
        radioButton_02_Color_Luv_BGR->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_Luv_BGR->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_Luv_BGR, 4, 11, 1, 1);

        radioButton_02_Color_HSL_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_HSL_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_HSL_RGB"));
        radioButton_02_Color_HSL_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_HSL_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_HSL_RGB, 3, 9, 1, 1);

        radioButton_02_Color_Luv_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_Luv_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_Luv_RGB"));
        radioButton_02_Color_Luv_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_Luv_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_Luv_RGB, 3, 11, 1, 1);

        line_02_Color = new QFrame(page_02_Color);
        line_02_Color->setObjectName(QString::fromUtf8("line_02_Color"));
        line_02_Color->setFrameShape(QFrame::VLine);
        line_02_Color->setFrameShadow(QFrame::Sunken);

        gridLayout_30->addWidget(line_02_Color, 0, 0, 6, 1);

        radioButton_02_Color_Grey_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_Grey_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_Grey_RGB"));
        radioButton_02_Color_Grey_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_Grey_RGB->setMaximumSize(QSize(30, 16777215));
        radioButton_02_Color_Grey_RGB->setChecked(true);

        gridLayout_30->addWidget(radioButton_02_Color_Grey_RGB, 3, 5, 1, 1);

        radioButton_02_Color_XYZ_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_XYZ_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_XYZ_RGB"));
        radioButton_02_Color_XYZ_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_XYZ_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_XYZ_RGB, 3, 6, 1, 1);

        radioButton_02_Color_YCrCb_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_YCrCb_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_YCrCb_RGB"));
        radioButton_02_Color_YCrCb_RGB->setMinimumSize(QSize(30, 0));
        radioButton_02_Color_YCrCb_RGB->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(radioButton_02_Color_YCrCb_RGB, 3, 7, 1, 1);

        label_02_Color_HSV = new QLabel(page_02_Color);
        label_02_Color_HSV->setObjectName(QString::fromUtf8("label_02_Color_HSV"));
        label_02_Color_HSV->setMinimumSize(QSize(30, 0));
        label_02_Color_HSV->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_HSV, 2, 8, 1, 1);

        label_02_Color_XYZ = new QLabel(page_02_Color);
        label_02_Color_XYZ->setObjectName(QString::fromUtf8("label_02_Color_XYZ"));
        label_02_Color_XYZ->setMinimumSize(QSize(30, 0));
        label_02_Color_XYZ->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_XYZ, 2, 6, 1, 1);

        label_02_Color_YCrCb = new QLabel(page_02_Color);
        label_02_Color_YCrCb->setObjectName(QString::fromUtf8("label_02_Color_YCrCb"));
        label_02_Color_YCrCb->setMinimumSize(QSize(30, 0));
        label_02_Color_YCrCb->setMaximumSize(QSize(30, 16777215));

        gridLayout_30->addWidget(label_02_Color_YCrCb, 2, 7, 1, 1);

        comboBox_02_Color_Direction_Top = new QComboBox(page_02_Color);
        comboBox_02_Color_Direction_Top->addItem(QString());
        comboBox_02_Color_Direction_Top->addItem(QString());
        comboBox_02_Color_Direction_Top->setObjectName(QString::fromUtf8("comboBox_02_Color_Direction_Top"));

        gridLayout_30->addWidget(comboBox_02_Color_Direction_Top, 1, 3, 1, 9);

        radioButton_02_Color_RGB_RGB = new QRadioButton(page_02_Color);
        radioButton_02_Color_RGB_RGB->setObjectName(QString::fromUtf8("radioButton_02_Color_RGB_RGB"));
        radioButton_02_Color_RGB_RGB->setEnabled(false);
        radioButton_02_Color_RGB_RGB->setMinimumSize(QSize(30, 0));

        gridLayout_30->addWidget(radioButton_02_Color_RGB_RGB, 3, 3, 1, 1);

        _Color_BGR_BGR = new QRadioButton(page_02_Color);
        _Color_BGR_BGR->setObjectName(QString::fromUtf8("_Color_BGR_BGR"));
        _Color_BGR_BGR->setEnabled(false);
        _Color_BGR_BGR->setMinimumSize(QSize(30, 0));

        gridLayout_30->addWidget(_Color_BGR_BGR, 4, 4, 1, 1);

        verticalSpacer_02_Color = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_30->addItem(verticalSpacer_02_Color, 5, 2, 1, 11);

        comboBox_02_Color_Direction_Left = new QComboBox(page_02_Color);
        comboBox_02_Color_Direction_Left->addItem(QString());
        comboBox_02_Color_Direction_Left->addItem(QString());
        comboBox_02_Color_Direction_Left->setObjectName(QString::fromUtf8("comboBox_02_Color_Direction_Left"));
        comboBox_02_Color_Direction_Left->setMinimumSize(QSize(50, 0));
        comboBox_02_Color_Direction_Left->setMaximumSize(QSize(50, 16777215));

        gridLayout_30->addWidget(comboBox_02_Color_Direction_Left, 1, 2, 1, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Color);
        page_02_Double = new QWidget();
        page_02_Double->setObjectName(QString::fromUtf8("page_02_Double"));
        gridLayout_59 = new QGridLayout(page_02_Double);
        gridLayout_59->setObjectName(QString::fromUtf8("gridLayout_59"));
        line_02_Double = new QFrame(page_02_Double);
        line_02_Double->setObjectName(QString::fromUtf8("line_02_Double"));
        line_02_Double->setFrameShape(QFrame::VLine);
        line_02_Double->setFrameShadow(QFrame::Sunken);

        gridLayout_59->addWidget(line_02_Double, 0, 0, 2, 1);

        label_02_Double_Description = new QLabel(page_02_Double);
        label_02_Double_Description->setObjectName(QString::fromUtf8("label_02_Double_Description"));

        gridLayout_59->addWidget(label_02_Double_Description, 0, 1, 1, 1);

        horizontalSpacer_02_Double = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_59->addItem(horizontalSpacer_02_Double, 0, 2, 2, 1);

        verticalSpacer_02_Double = new QSpacerItem(20, 180, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_59->addItem(verticalSpacer_02_Double, 1, 1, 1, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Double);
        page_02_Depth = new QWidget();
        page_02_Depth->setObjectName(QString::fromUtf8("page_02_Depth"));
        gridLayout_29 = new QGridLayout(page_02_Depth);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        label_02_Depth_Maximum = new QLabel(page_02_Depth);
        label_02_Depth_Maximum->setObjectName(QString::fromUtf8("label_02_Depth_Maximum"));
        label_02_Depth_Maximum->setMinimumSize(QSize(75, 0));
        label_02_Depth_Maximum->setMaximumSize(QSize(75, 16777215));

        gridLayout_29->addWidget(label_02_Depth_Maximum, 3, 1, 1, 1);

        horizontalSpacer_02_Depth = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_29->addItem(horizontalSpacer_02_Depth, 5, 3, 1, 1);

        verticalSpacer_02_Depth = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_29->addItem(verticalSpacer_02_Depth, 5, 2, 1, 1);

        label_02_Depth_Norm = new QLabel(page_02_Depth);
        label_02_Depth_Norm->setObjectName(QString::fromUtf8("label_02_Depth_Norm"));
        label_02_Depth_Norm->setMinimumSize(QSize(75, 0));
        label_02_Depth_Norm->setMaximumSize(QSize(75, 16777215));

        gridLayout_29->addWidget(label_02_Depth_Norm, 0, 1, 1, 1);

        line_02_Depth = new QFrame(page_02_Depth);
        line_02_Depth->setObjectName(QString::fromUtf8("line_02_Depth"));
        line_02_Depth->setFrameShape(QFrame::VLine);
        line_02_Depth->setFrameShadow(QFrame::Sunken);

        gridLayout_29->addWidget(line_02_Depth, 0, 0, 6, 1);

        label_02_Depth_Minimum = new QLabel(page_02_Depth);
        label_02_Depth_Minimum->setObjectName(QString::fromUtf8("label_02_Depth_Minimum"));
        label_02_Depth_Minimum->setMinimumSize(QSize(75, 0));
        label_02_Depth_Minimum->setMaximumSize(QSize(75, 16777215));

        gridLayout_29->addWidget(label_02_Depth_Minimum, 2, 1, 1, 1);

        comboBox_02_Depth_Type = new QComboBox(page_02_Depth);
        comboBox_02_Depth_Type->addItem(QString());
        comboBox_02_Depth_Type->addItem(QString());
        comboBox_02_Depth_Type->addItem(QString());
        comboBox_02_Depth_Type->addItem(QString());
        comboBox_02_Depth_Type->setObjectName(QString::fromUtf8("comboBox_02_Depth_Type"));
        comboBox_02_Depth_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_29->addWidget(comboBox_02_Depth_Type, 1, 2, 1, 1);

        label_02_Depth_Type = new QLabel(page_02_Depth);
        label_02_Depth_Type->setObjectName(QString::fromUtf8("label_02_Depth_Type"));
        label_02_Depth_Type->setMinimumSize(QSize(75, 0));
        label_02_Depth_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_29->addWidget(label_02_Depth_Type, 1, 1, 1, 1);

        doubleSpinBox_02_Depth_Minimum = new QDoubleSpinBox(page_02_Depth);
        doubleSpinBox_02_Depth_Minimum->setObjectName(QString::fromUtf8("doubleSpinBox_02_Depth_Minimum"));
        doubleSpinBox_02_Depth_Minimum->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_02_Depth_Minimum->setDecimals(0);
        doubleSpinBox_02_Depth_Minimum->setMaximum(254.000000000000000);

        gridLayout_29->addWidget(doubleSpinBox_02_Depth_Minimum, 2, 2, 1, 1);

        doubleSpinBox_02_Depth_Maximum = new QDoubleSpinBox(page_02_Depth);
        doubleSpinBox_02_Depth_Maximum->setObjectName(QString::fromUtf8("doubleSpinBox_02_Depth_Maximum"));
        doubleSpinBox_02_Depth_Maximum->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_02_Depth_Maximum->setDecimals(0);
        doubleSpinBox_02_Depth_Maximum->setMinimum(1.000000000000000);
        doubleSpinBox_02_Depth_Maximum->setMaximum(255.000000000000000);
        doubleSpinBox_02_Depth_Maximum->setValue(255.000000000000000);

        gridLayout_29->addWidget(doubleSpinBox_02_Depth_Maximum, 3, 2, 1, 1);

        comboBox_02_Depth_Norm = new QComboBox(page_02_Depth);
        comboBox_02_Depth_Norm->addItem(QString());
        comboBox_02_Depth_Norm->setObjectName(QString::fromUtf8("comboBox_02_Depth_Norm"));
        comboBox_02_Depth_Norm->setMinimumSize(QSize(100, 0));
        comboBox_02_Depth_Norm->setMaximumSize(QSize(100, 16777215));

        gridLayout_29->addWidget(comboBox_02_Depth_Norm, 0, 2, 1, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Depth);
        page_02_Merge = new QWidget();
        page_02_Merge->setObjectName(QString::fromUtf8("page_02_Merge"));
        gridLayout_53 = new QGridLayout(page_02_Merge);
        gridLayout_53->setObjectName(QString::fromUtf8("gridLayout_53"));
        spinBox_02_Merge_Channels = new QSpinBox(page_02_Merge);
        spinBox_02_Merge_Channels->setObjectName(QString::fromUtf8("spinBox_02_Merge_Channels"));
        spinBox_02_Merge_Channels->setMinimumSize(QSize(150, 0));
        spinBox_02_Merge_Channels->setMinimum(1);
        spinBox_02_Merge_Channels->setMaximum(4);
        spinBox_02_Merge_Channels->setValue(3);

        gridLayout_53->addWidget(spinBox_02_Merge_Channels, 0, 2, 1, 1);

        label_02_Merge_Ch1 = new QLabel(page_02_Merge);
        label_02_Merge_Ch1->setObjectName(QString::fromUtf8("label_02_Merge_Ch1"));

        gridLayout_53->addWidget(label_02_Merge_Ch1, 2, 1, 1, 1);

        label_02_Merge_Channels = new QLabel(page_02_Merge);
        label_02_Merge_Channels->setObjectName(QString::fromUtf8("label_02_Merge_Channels"));
        label_02_Merge_Channels->setMinimumSize(QSize(75, 0));

        gridLayout_53->addWidget(label_02_Merge_Channels, 0, 1, 1, 1);

        label_02_Merge_Ch0 = new QLabel(page_02_Merge);
        label_02_Merge_Ch0->setObjectName(QString::fromUtf8("label_02_Merge_Ch0"));

        gridLayout_53->addWidget(label_02_Merge_Ch0, 1, 1, 1, 1);

        checkBox_02_Merge_Ch0 = new QCheckBox(page_02_Merge);
        checkBox_02_Merge_Ch0->setObjectName(QString::fromUtf8("checkBox_02_Merge_Ch0"));
        checkBox_02_Merge_Ch0->setChecked(true);

        gridLayout_53->addWidget(checkBox_02_Merge_Ch0, 1, 2, 1, 1);

        line_02_Merge = new QFrame(page_02_Merge);
        line_02_Merge->setObjectName(QString::fromUtf8("line_02_Merge"));
        line_02_Merge->setFrameShape(QFrame::VLine);
        line_02_Merge->setFrameShadow(QFrame::Sunken);

        gridLayout_53->addWidget(line_02_Merge, 0, 0, 6, 1);

        label_02_Merge_Ch2 = new QLabel(page_02_Merge);
        label_02_Merge_Ch2->setObjectName(QString::fromUtf8("label_02_Merge_Ch2"));

        gridLayout_53->addWidget(label_02_Merge_Ch2, 3, 1, 1, 1);

        checkBox_02_Merge_Ch1 = new QCheckBox(page_02_Merge);
        checkBox_02_Merge_Ch1->setObjectName(QString::fromUtf8("checkBox_02_Merge_Ch1"));
        checkBox_02_Merge_Ch1->setChecked(true);

        gridLayout_53->addWidget(checkBox_02_Merge_Ch1, 2, 2, 1, 1);

        checkBox_02_Merge_Ch3 = new QCheckBox(page_02_Merge);
        checkBox_02_Merge_Ch3->setObjectName(QString::fromUtf8("checkBox_02_Merge_Ch3"));
        checkBox_02_Merge_Ch3->setEnabled(false);

        gridLayout_53->addWidget(checkBox_02_Merge_Ch3, 4, 2, 1, 1);

        checkBox_02_Merge_Ch2 = new QCheckBox(page_02_Merge);
        checkBox_02_Merge_Ch2->setObjectName(QString::fromUtf8("checkBox_02_Merge_Ch2"));
        checkBox_02_Merge_Ch2->setChecked(true);

        gridLayout_53->addWidget(checkBox_02_Merge_Ch2, 3, 2, 1, 1);

        label_02_Merge_Ch3 = new QLabel(page_02_Merge);
        label_02_Merge_Ch3->setObjectName(QString::fromUtf8("label_02_Merge_Ch3"));
        label_02_Merge_Ch3->setEnabled(false);

        gridLayout_53->addWidget(label_02_Merge_Ch3, 4, 1, 1, 1);

        verticalSpacer_02_Merge = new QSpacerItem(391, 77, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_53->addItem(verticalSpacer_02_Merge, 5, 1, 1, 3);

        horizontalSpacer_02_Merge = new QSpacerItem(154, 109, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_53->addItem(horizontalSpacer_02_Merge, 0, 3, 5, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Merge);
        page_02_Split = new QWidget();
        page_02_Split->setObjectName(QString::fromUtf8("page_02_Split"));
        gridLayout_62 = new QGridLayout(page_02_Split);
        gridLayout_62->setObjectName(QString::fromUtf8("gridLayout_62"));
        line_02_Split = new QFrame(page_02_Split);
        line_02_Split->setObjectName(QString::fromUtf8("line_02_Split"));
        line_02_Split->setFrameShape(QFrame::VLine);
        line_02_Split->setFrameShadow(QFrame::Sunken);

        gridLayout_62->addWidget(line_02_Split, 0, 0, 2, 1);

        label_02_Split_Channel = new QLabel(page_02_Split);
        label_02_Split_Channel->setObjectName(QString::fromUtf8("label_02_Split_Channel"));
        label_02_Split_Channel->setMinimumSize(QSize(75, 0));

        gridLayout_62->addWidget(label_02_Split_Channel, 0, 1, 1, 1);

        spinBox_02_Split_Channel = new QSpinBox(page_02_Split);
        spinBox_02_Split_Channel->setObjectName(QString::fromUtf8("spinBox_02_Split_Channel"));
        spinBox_02_Split_Channel->setMinimumSize(QSize(100, 0));
        spinBox_02_Split_Channel->setMaximum(3);

        gridLayout_62->addWidget(spinBox_02_Split_Channel, 0, 2, 1, 1);

        horizontalSpacer_02_Split = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_62->addItem(horizontalSpacer_02_Split, 0, 3, 1, 1);

        verticalSpacer_02_Split = new QSpacerItem(20, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_62->addItem(verticalSpacer_02_Split, 1, 3, 1, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Split);
        page_02_Combi = new QWidget();
        page_02_Combi->setObjectName(QString::fromUtf8("page_02_Combi"));
        gridLayout_55 = new QGridLayout(page_02_Combi);
        gridLayout_55->setObjectName(QString::fromUtf8("gridLayout_55"));
        label_02_Combi_Format = new QLabel(page_02_Combi);
        label_02_Combi_Format->setObjectName(QString::fromUtf8("label_02_Combi_Format"));
        label_02_Combi_Format->setMinimumSize(QSize(75, 0));

        gridLayout_55->addWidget(label_02_Combi_Format, 0, 1, 1, 1);

        comboBox_02_Combi_Type = new QComboBox(page_02_Combi);
        comboBox_02_Combi_Type->addItem(QString());
        comboBox_02_Combi_Type->setObjectName(QString::fromUtf8("comboBox_02_Combi_Type"));
        comboBox_02_Combi_Type->setMinimumSize(QSize(100, 0));

        gridLayout_55->addWidget(comboBox_02_Combi_Type, 0, 2, 1, 1);

        horizontalSpacer_02_Combi = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_55->addItem(horizontalSpacer_02_Combi, 0, 3, 1, 1);

        verticalSpacer_02_Combi = new QSpacerItem(20, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_55->addItem(verticalSpacer_02_Combi, 1, 3, 1, 1);

        line_02_Combi = new QFrame(page_02_Combi);
        line_02_Combi->setObjectName(QString::fromUtf8("line_02_Combi"));
        line_02_Combi->setFrameShape(QFrame::VLine);
        line_02_Combi->setFrameShadow(QFrame::Sunken);

        gridLayout_55->addWidget(line_02_Combi, 0, 0, 2, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Combi);
        page_02_Angle2Color = new QWidget();
        page_02_Angle2Color->setObjectName(QString::fromUtf8("page_02_Angle2Color"));
        gridLayout_117 = new QGridLayout(page_02_Angle2Color);
        gridLayout_117->setObjectName(QString::fromUtf8("gridLayout_117"));
        horizontalSpacer_02_Angle2Color = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_117->addItem(horizontalSpacer_02_Angle2Color, 0, 2, 2, 1);

        label_02_Angle2Color_V = new QLabel(page_02_Angle2Color);
        label_02_Angle2Color_V->setObjectName(QString::fromUtf8("label_02_Angle2Color_V"));
        label_02_Angle2Color_V->setMinimumSize(QSize(75, 0));
        label_02_Angle2Color_V->setMaximumSize(QSize(75, 16777215));

        gridLayout_117->addWidget(label_02_Angle2Color_V, 2, 0, 1, 1);

        label_02_Angle2Color_H = new QLabel(page_02_Angle2Color);
        label_02_Angle2Color_H->setObjectName(QString::fromUtf8("label_02_Angle2Color_H"));
        label_02_Angle2Color_H->setMinimumSize(QSize(75, 0));
        label_02_Angle2Color_H->setMaximumSize(QSize(75, 16777215));

        gridLayout_117->addWidget(label_02_Angle2Color_H, 0, 0, 1, 1);

        verticalSpacer_02_Angle2Color = new QSpacerItem(20, 133, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_117->addItem(verticalSpacer_02_Angle2Color, 3, 0, 1, 1);

        label_02_Angle2Color_S = new QLabel(page_02_Angle2Color);
        label_02_Angle2Color_S->setObjectName(QString::fromUtf8("label_02_Angle2Color_S"));
        label_02_Angle2Color_S->setMinimumSize(QSize(75, 0));
        label_02_Angle2Color_S->setMaximumSize(QSize(75, 16777215));

        gridLayout_117->addWidget(label_02_Angle2Color_S, 1, 0, 1, 1);

        spinBox_02_Angle2Color_V = new QSpinBox(page_02_Angle2Color);
        spinBox_02_Angle2Color_V->setObjectName(QString::fromUtf8("spinBox_02_Angle2Color_V"));
        spinBox_02_Angle2Color_V->setMinimumSize(QSize(100, 0));
        spinBox_02_Angle2Color_V->setMaximumSize(QSize(100, 16777215));
        spinBox_02_Angle2Color_V->setMaximum(255);
        spinBox_02_Angle2Color_V->setValue(255);

        gridLayout_117->addWidget(spinBox_02_Angle2Color_V, 2, 1, 1, 1);

        spinBox_02_Angle2Color_S = new QSpinBox(page_02_Angle2Color);
        spinBox_02_Angle2Color_S->setObjectName(QString::fromUtf8("spinBox_02_Angle2Color_S"));
        spinBox_02_Angle2Color_S->setMinimumSize(QSize(100, 0));
        spinBox_02_Angle2Color_S->setMaximumSize(QSize(100, 16777215));
        spinBox_02_Angle2Color_S->setMaximum(255);
        spinBox_02_Angle2Color_S->setValue(255);

        gridLayout_117->addWidget(spinBox_02_Angle2Color_S, 1, 1, 1, 1);

        comboBox_02_Angle2Color_Mode = new QComboBox(page_02_Angle2Color);
        comboBox_02_Angle2Color_Mode->addItem(QString());
        comboBox_02_Angle2Color_Mode->setObjectName(QString::fromUtf8("comboBox_02_Angle2Color_Mode"));
        comboBox_02_Angle2Color_Mode->setMinimumSize(QSize(100, 0));
        comboBox_02_Angle2Color_Mode->setMaximumSize(QSize(100, 16777215));

        gridLayout_117->addWidget(comboBox_02_Angle2Color_Mode, 0, 1, 1, 1);

        stackedWidget_Settings_02_Convert->addWidget(page_02_Angle2Color);

        gridLayout_19->addWidget(stackedWidget_Settings_02_Convert, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_02_Convert);
        page_Settings_03_Elemental = new QWidget();
        page_Settings_03_Elemental->setObjectName(QString::fromUtf8("page_Settings_03_Elemental"));
        gridLayout_20 = new QGridLayout(page_Settings_03_Elemental);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_03_Elemental = new QStackedWidget(page_Settings_03_Elemental);
        stackedWidget_Settings_03_Elemental->setObjectName(QString::fromUtf8("stackedWidget_Settings_03_Elemental"));
        page_03_Threshold = new QWidget();
        page_03_Threshold->setObjectName(QString::fromUtf8("page_03_Threshold"));
        gridLayout_31 = new QGridLayout(page_03_Threshold);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        stackedWidget_03_Thres = new QStackedWidget(page_03_Threshold);
        stackedWidget_03_Thres->setObjectName(QString::fromUtf8("stackedWidget_03_Thres"));
        page_03_Thres_Otsu = new QWidget();
        page_03_Thres_Otsu->setObjectName(QString::fromUtf8("page_03_Thres_Otsu"));
        gridLayout_69 = new QGridLayout(page_03_Thres_Otsu);
        gridLayout_69->setObjectName(QString::fromUtf8("gridLayout_69"));
        label_03_Thres_Otsu = new QLabel(page_03_Thres_Otsu);
        label_03_Thres_Otsu->setObjectName(QString::fromUtf8("label_03_Thres_Otsu"));

        gridLayout_69->addWidget(label_03_Thres_Otsu, 0, 0, 1, 1);

        verticalSpacer_03_Thres_Otsu = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_69->addItem(verticalSpacer_03_Thres_Otsu, 1, 0, 1, 1);

        stackedWidget_03_Thres->addWidget(page_03_Thres_Otsu);
        page_03_Thres_Abs = new QWidget();
        page_03_Thres_Abs->setObjectName(QString::fromUtf8("page_03_Thres_Abs"));
        gridLayout_68 = new QGridLayout(page_03_Thres_Abs);
        gridLayout_68->setObjectName(QString::fromUtf8("gridLayout_68"));
        label_03_Thres_Thres_Value = new QLabel(page_03_Thres_Abs);
        label_03_Thres_Thres_Value->setObjectName(QString::fromUtf8("label_03_Thres_Thres_Value"));
        label_03_Thres_Thres_Value->setMinimumSize(QSize(75, 0));
        label_03_Thres_Thres_Value->setMaximumSize(QSize(75, 16777215));

        gridLayout_68->addWidget(label_03_Thres_Thres_Value, 0, 0, 1, 1);

        horizontalSlider_03_Thres_Abs_Thres_Value = new QSlider(page_03_Thres_Abs);
        horizontalSlider_03_Thres_Abs_Thres_Value->setObjectName(QString::fromUtf8("horizontalSlider_03_Thres_Abs_Thres_Value"));
        horizontalSlider_03_Thres_Abs_Thres_Value->setMaximum(255);
        horizontalSlider_03_Thres_Abs_Thres_Value->setSingleStep(8);
        horizontalSlider_03_Thres_Abs_Thres_Value->setPageStep(16);
        horizontalSlider_03_Thres_Abs_Thres_Value->setValue(127);
        horizontalSlider_03_Thres_Abs_Thres_Value->setOrientation(Qt::Horizontal);
        horizontalSlider_03_Thres_Abs_Thres_Value->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_03_Thres_Abs_Thres_Value->setTickInterval(16);

        gridLayout_68->addWidget(horizontalSlider_03_Thres_Abs_Thres_Value, 0, 2, 1, 1);

        spinBox_03_Thres_Thres_Value_Abs = new QSpinBox(page_03_Thres_Abs);
        spinBox_03_Thres_Thres_Value_Abs->setObjectName(QString::fromUtf8("spinBox_03_Thres_Thres_Value_Abs"));
        spinBox_03_Thres_Thres_Value_Abs->setMinimumSize(QSize(100, 0));
        spinBox_03_Thres_Thres_Value_Abs->setMaximumSize(QSize(100, 16777215));
        spinBox_03_Thres_Thres_Value_Abs->setMaximum(255);
        spinBox_03_Thres_Thres_Value_Abs->setValue(127);

        gridLayout_68->addWidget(spinBox_03_Thres_Thres_Value_Abs, 0, 1, 1, 1);

        verticalSpacer_03_Thres_Abs = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_68->addItem(verticalSpacer_03_Thres_Abs, 1, 0, 1, 3);

        stackedWidget_03_Thres->addWidget(page_03_Thres_Abs);
        page_03_Thres_Rel = new QWidget();
        page_03_Thres_Rel->setObjectName(QString::fromUtf8("page_03_Thres_Rel"));
        gridLayout_67 = new QGridLayout(page_03_Thres_Rel);
        gridLayout_67->setSpacing(3);
        gridLayout_67->setObjectName(QString::fromUtf8("gridLayout_67"));
        gridLayout_67->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_03_Thres_Rel = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_67->addItem(horizontalSpacer_03_Thres_Rel, 0, 2, 1, 1);

        horizontalSlider_03_Thres_Rel_Thresh_Rel = new QSlider(page_03_Thres_Rel);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setObjectName(QString::fromUtf8("horizontalSlider_03_Thres_Rel_Thresh_Rel"));
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setMaximum(1000000);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setSingleStep(10000);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setPageStep(100000);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setValue(500000);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setOrientation(Qt::Horizontal);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_03_Thres_Rel_Thresh_Rel->setTickInterval(100000);

        gridLayout_67->addWidget(horizontalSlider_03_Thres_Rel_Thresh_Rel, 1, 2, 2, 1);

        label_03_Thres_Real_Thres = new QLabel(page_03_Thres_Rel);
        label_03_Thres_Real_Thres->setObjectName(QString::fromUtf8("label_03_Thres_Real_Thres"));
        label_03_Thres_Real_Thres->setMinimumSize(QSize(75, 0));
        label_03_Thres_Real_Thres->setMaximumSize(QSize(75, 16777215));

        gridLayout_67->addWidget(label_03_Thres_Real_Thres, 1, 0, 2, 1);

        doubleSpinBox_03_Thres_Rel_Thres_Rel = new QDoubleSpinBox(page_03_Thres_Rel);
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setObjectName(QString::fromUtf8("doubleSpinBox_03_Thres_Rel_Thres_Rel"));
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setMinimumSize(QSize(100, 0));
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setDecimals(3);
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setMaximum(100.000000000000000);
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setSingleStep(1.000000000000000);
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setValue(50.000000000000000);

        gridLayout_67->addWidget(doubleSpinBox_03_Thres_Rel_Thres_Rel, 1, 1, 1, 1);

        label_03_Thres_Rel_Base = new QLabel(page_03_Thres_Rel);
        label_03_Thres_Rel_Base->setObjectName(QString::fromUtf8("label_03_Thres_Rel_Base"));
        label_03_Thres_Rel_Base->setMinimumSize(QSize(75, 0));
        label_03_Thres_Rel_Base->setMaximumSize(QSize(75, 16777215));

        gridLayout_67->addWidget(label_03_Thres_Rel_Base, 0, 0, 1, 1);

        verticalSpacer_03_Thres_Rel = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_67->addItem(verticalSpacer_03_Thres_Rel, 3, 0, 1, 3);

        doubleSpinBox_03_Thres_Rel_Base = new QDoubleSpinBox(page_03_Thres_Rel);
        doubleSpinBox_03_Thres_Rel_Base->setObjectName(QString::fromUtf8("doubleSpinBox_03_Thres_Rel_Base"));
        doubleSpinBox_03_Thres_Rel_Base->setDecimals(3);
        doubleSpinBox_03_Thres_Rel_Base->setMinimum(-1000000.000000000000000);
        doubleSpinBox_03_Thres_Rel_Base->setMaximum(1000000.000000000000000);
        doubleSpinBox_03_Thres_Rel_Base->setValue(255.000000000000000);

        gridLayout_67->addWidget(doubleSpinBox_03_Thres_Rel_Base, 0, 1, 1, 1);

        doubleSpinBox_03_Thres_Rel_Thresh_Abs = new QDoubleSpinBox(page_03_Thres_Rel);
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setObjectName(QString::fromUtf8("doubleSpinBox_03_Thres_Rel_Thresh_Abs"));
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setMinimumSize(QSize(100, 0));
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setDecimals(3);
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setMinimum(-1000000.000000000000000);
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setMaximum(1000000.000000000000000);
        doubleSpinBox_03_Thres_Rel_Thresh_Abs->setValue(127.500000000000000);

        gridLayout_67->addWidget(doubleSpinBox_03_Thres_Rel_Thresh_Abs, 2, 1, 1, 1);

        stackedWidget_03_Thres->addWidget(page_03_Thres_Rel);
        page_03_Thres_Loc = new QWidget();
        page_03_Thres_Loc->setObjectName(QString::fromUtf8("page_03_Thres_Loc"));
        gridLayout_66 = new QGridLayout(page_03_Thres_Loc);
        gridLayout_66->setSpacing(3);
        gridLayout_66->setObjectName(QString::fromUtf8("gridLayout_66"));
        gridLayout_66->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_03_Thres_Adapt_Offset = new QDoubleSpinBox(page_03_Thres_Loc);
        doubleSpinBox_03_Thres_Adapt_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_03_Thres_Adapt_Offset"));
        doubleSpinBox_03_Thres_Adapt_Offset->setMinimumSize(QSize(100, 0));
        doubleSpinBox_03_Thres_Adapt_Offset->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_03_Thres_Adapt_Offset->setDecimals(0);
        doubleSpinBox_03_Thres_Adapt_Offset->setMinimum(-256.000000000000000);
        doubleSpinBox_03_Thres_Adapt_Offset->setMaximum(255.000000000000000);

        gridLayout_66->addWidget(doubleSpinBox_03_Thres_Adapt_Offset, 2, 1, 1, 1);

        spinBox_03_Thres_Mask_Size = new QSpinBox(page_03_Thres_Loc);
        spinBox_03_Thres_Mask_Size->setObjectName(QString::fromUtf8("spinBox_03_Thres_Mask_Size"));
        spinBox_03_Thres_Mask_Size->setEnabled(true);
        spinBox_03_Thres_Mask_Size->setMinimumSize(QSize(100, 0));
        spinBox_03_Thres_Mask_Size->setMaximumSize(QSize(100, 16777215));
        spinBox_03_Thres_Mask_Size->setMinimum(3);
        spinBox_03_Thres_Mask_Size->setMaximum(100003);
        spinBox_03_Thres_Mask_Size->setSingleStep(2);

        gridLayout_66->addWidget(spinBox_03_Thres_Mask_Size, 1, 1, 1, 1);

        label_03_Thres_Adapt_Offset = new QLabel(page_03_Thres_Loc);
        label_03_Thres_Adapt_Offset->setObjectName(QString::fromUtf8("label_03_Thres_Adapt_Offset"));

        gridLayout_66->addWidget(label_03_Thres_Adapt_Offset, 2, 0, 1, 1);

        comboBox_03_Thres_Adapt_Type = new QComboBox(page_03_Thres_Loc);
        comboBox_03_Thres_Adapt_Type->addItem(QString());
        comboBox_03_Thres_Adapt_Type->addItem(QString());
        comboBox_03_Thres_Adapt_Type->setObjectName(QString::fromUtf8("comboBox_03_Thres_Adapt_Type"));
        comboBox_03_Thres_Adapt_Type->setEnabled(true);
        comboBox_03_Thres_Adapt_Type->setMinimumSize(QSize(100, 0));
        comboBox_03_Thres_Adapt_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_66->addWidget(comboBox_03_Thres_Adapt_Type, 0, 1, 1, 1);

        label_03_Thres_Adapt_Type = new QLabel(page_03_Thres_Loc);
        label_03_Thres_Adapt_Type->setObjectName(QString::fromUtf8("label_03_Thres_Adapt_Type"));
        label_03_Thres_Adapt_Type->setEnabled(true);
        label_03_Thres_Adapt_Type->setMinimumSize(QSize(75, 0));
        label_03_Thres_Adapt_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_66->addWidget(label_03_Thres_Adapt_Type, 0, 0, 1, 1);

        label_03_Thres_Mask_Size = new QLabel(page_03_Thres_Loc);
        label_03_Thres_Mask_Size->setObjectName(QString::fromUtf8("label_03_Thres_Mask_Size"));
        label_03_Thres_Mask_Size->setEnabled(true);
        label_03_Thres_Mask_Size->setMinimumSize(QSize(75, 0));
        label_03_Thres_Mask_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_66->addWidget(label_03_Thres_Mask_Size, 1, 0, 1, 1);

        verticalSpacer_03_Thres_Local = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_66->addItem(verticalSpacer_03_Thres_Local, 3, 0, 1, 3);

        horizontalSpacer_03_Thres_Local = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_66->addItem(horizontalSpacer_03_Thres_Local, 0, 2, 3, 1);

        stackedWidget_03_Thres->addWidget(page_03_Thres_Loc);

        gridLayout_31->addWidget(stackedWidget_03_Thres, 4, 1, 1, 3);

        comboBox_03_Thres_Type = new QComboBox(page_03_Threshold);
        comboBox_03_Thres_Type->addItem(QString());
        comboBox_03_Thres_Type->addItem(QString());
        comboBox_03_Thres_Type->addItem(QString());
        comboBox_03_Thres_Type->addItem(QString());
        comboBox_03_Thres_Type->setObjectName(QString::fromUtf8("comboBox_03_Thres_Type"));
        comboBox_03_Thres_Type->setMinimumSize(QSize(0, 0));
        comboBox_03_Thres_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_31->addWidget(comboBox_03_Thres_Type, 2, 2, 1, 1);

        line_03_Thres_1 = new QFrame(page_03_Threshold);
        line_03_Thres_1->setObjectName(QString::fromUtf8("line_03_Thres_1"));
        line_03_Thres_1->setFrameShape(QFrame::VLine);
        line_03_Thres_1->setFrameShadow(QFrame::Sunken);

        gridLayout_31->addWidget(line_03_Thres_1, 0, 0, 8, 1);

        line_03_Thres_2 = new QFrame(page_03_Threshold);
        line_03_Thres_2->setObjectName(QString::fromUtf8("line_03_Thres_2"));
        line_03_Thres_2->setFrameShape(QFrame::HLine);
        line_03_Thres_2->setFrameShadow(QFrame::Sunken);

        gridLayout_31->addWidget(line_03_Thres_2, 3, 1, 1, 3);

        comboBox_03_Thres_Output_Mode = new QComboBox(page_03_Threshold);
        comboBox_03_Thres_Output_Mode->addItem(QString());
        comboBox_03_Thres_Output_Mode->addItem(QString());
        comboBox_03_Thres_Output_Mode->addItem(QString());
        comboBox_03_Thres_Output_Mode->addItem(QString());
        comboBox_03_Thres_Output_Mode->addItem(QString());
        comboBox_03_Thres_Output_Mode->setObjectName(QString::fromUtf8("comboBox_03_Thres_Output_Mode"));
        comboBox_03_Thres_Output_Mode->setMinimumSize(QSize(100, 0));
        comboBox_03_Thres_Output_Mode->setMaximumSize(QSize(100, 16777215));

        gridLayout_31->addWidget(comboBox_03_Thres_Output_Mode, 0, 2, 1, 1);

        label_03_Thres_Max_Value = new QLabel(page_03_Threshold);
        label_03_Thres_Max_Value->setObjectName(QString::fromUtf8("label_03_Thres_Max_Value"));

        gridLayout_31->addWidget(label_03_Thres_Max_Value, 1, 1, 1, 1);

        label_03_Thres_Output_Type = new QLabel(page_03_Threshold);
        label_03_Thres_Output_Type->setObjectName(QString::fromUtf8("label_03_Thres_Output_Type"));
        label_03_Thres_Output_Type->setMinimumSize(QSize(75, 0));
        label_03_Thres_Output_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_31->addWidget(label_03_Thres_Output_Type, 0, 1, 1, 1);

        doubleSpinBox_03_Thres_Max_Value_Out = new QDoubleSpinBox(page_03_Threshold);
        doubleSpinBox_03_Thres_Max_Value_Out->setObjectName(QString::fromUtf8("doubleSpinBox_03_Thres_Max_Value_Out"));
        doubleSpinBox_03_Thres_Max_Value_Out->setMinimumSize(QSize(0, 0));
        doubleSpinBox_03_Thres_Max_Value_Out->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_03_Thres_Max_Value_Out->setDecimals(0);
        doubleSpinBox_03_Thres_Max_Value_Out->setMaximum(255.000000000000000);
        doubleSpinBox_03_Thres_Max_Value_Out->setValue(255.000000000000000);

        gridLayout_31->addWidget(doubleSpinBox_03_Thres_Max_Value_Out, 1, 2, 1, 1);

        label_03_Thres_Type = new QLabel(page_03_Threshold);
        label_03_Thres_Type->setObjectName(QString::fromUtf8("label_03_Thres_Type"));
        label_03_Thres_Type->setMinimumSize(QSize(75, 0));
        label_03_Thres_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_31->addWidget(label_03_Thres_Type, 2, 1, 1, 1);

        stackedWidget_Settings_03_Elemental->addWidget(page_03_Threshold);
        page_03_Labeling = new QWidget();
        page_03_Labeling->setObjectName(QString::fromUtf8("page_03_Labeling"));
        gridLayout_40 = new QGridLayout(page_03_Labeling);
        gridLayout_40->setObjectName(QString::fromUtf8("gridLayout_40"));
        label_03_Labeling_Depth = new QLabel(page_03_Labeling);
        label_03_Labeling_Depth->setObjectName(QString::fromUtf8("label_03_Labeling_Depth"));
        label_03_Labeling_Depth->setMinimumSize(QSize(75, 0));
        label_03_Labeling_Depth->setMaximumSize(QSize(75, 16777215));

        gridLayout_40->addWidget(label_03_Labeling_Depth, 0, 3, 1, 1);

        line03_Labeling = new QFrame(page_03_Labeling);
        line03_Labeling->setObjectName(QString::fromUtf8("line03_Labeling"));
        line03_Labeling->setFrameShape(QFrame::VLine);
        line03_Labeling->setFrameShadow(QFrame::Sunken);

        gridLayout_40->addWidget(line03_Labeling, 0, 0, 3, 1);

        horizontalSpacer_03_Labeling = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_40->addItem(horizontalSpacer_03_Labeling, 0, 5, 1, 1);

        verticalSpacer_03_Labeling = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_40->addItem(verticalSpacer_03_Labeling, 2, 1, 1, 1);

        label_03_Labeling_Type = new QLabel(page_03_Labeling);
        label_03_Labeling_Type->setObjectName(QString::fromUtf8("label_03_Labeling_Type"));
        label_03_Labeling_Type->setMinimumSize(QSize(75, 0));
        label_03_Labeling_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_40->addWidget(label_03_Labeling_Type, 0, 1, 1, 1);

        comboBox_03_Labeling_Type = new QComboBox(page_03_Labeling);
        comboBox_03_Labeling_Type->addItem(QString());
        comboBox_03_Labeling_Type->setObjectName(QString::fromUtf8("comboBox_03_Labeling_Type"));
        comboBox_03_Labeling_Type->setMinimumSize(QSize(100, 0));
        comboBox_03_Labeling_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_40->addWidget(comboBox_03_Labeling_Type, 0, 2, 1, 1);

        comboBox_03_Labeling_Connectivity = new QComboBox(page_03_Labeling);
        comboBox_03_Labeling_Connectivity->addItem(QString());
        comboBox_03_Labeling_Connectivity->addItem(QString());
        comboBox_03_Labeling_Connectivity->setObjectName(QString::fromUtf8("comboBox_03_Labeling_Connectivity"));
        comboBox_03_Labeling_Connectivity->setMinimumSize(QSize(0, 0));
        comboBox_03_Labeling_Connectivity->setMaximumSize(QSize(100, 16777215));

        gridLayout_40->addWidget(comboBox_03_Labeling_Connectivity, 1, 2, 1, 1);

        label_03_Labeling_Connectivity = new QLabel(page_03_Labeling);
        label_03_Labeling_Connectivity->setObjectName(QString::fromUtf8("label_03_Labeling_Connectivity"));

        gridLayout_40->addWidget(label_03_Labeling_Connectivity, 1, 1, 1, 1);

        comboBox_03_Labeling_Depth = new QComboBox(page_03_Labeling);
        comboBox_03_Labeling_Depth->addItem(QString());
        comboBox_03_Labeling_Depth->addItem(QString());
        comboBox_03_Labeling_Depth->setObjectName(QString::fromUtf8("comboBox_03_Labeling_Depth"));
        comboBox_03_Labeling_Depth->setMinimumSize(QSize(100, 0));
        comboBox_03_Labeling_Depth->setMaximumSize(QSize(100, 16777215));

        gridLayout_40->addWidget(comboBox_03_Labeling_Depth, 0, 4, 1, 1);

        stackedWidget_Settings_03_Elemental->addWidget(page_03_Labeling);
        page_03_ShadeCorr = new QWidget();
        page_03_ShadeCorr->setObjectName(QString::fromUtf8("page_03_ShadeCorr"));
        gridLayout_52 = new QGridLayout(page_03_ShadeCorr);
        gridLayout_52->setObjectName(QString::fromUtf8("gridLayout_52"));
        label_03_ShadeCorr_Dst_Titel = new QLabel(page_03_ShadeCorr);
        label_03_ShadeCorr_Dst_Titel->setObjectName(QString::fromUtf8("label_03_ShadeCorr_Dst_Titel"));
        label_03_ShadeCorr_Dst_Titel->setMinimumSize(QSize(75, 0));

        gridLayout_52->addWidget(label_03_ShadeCorr_Dst_Titel, 2, 1, 1, 1);

        horizontalSpacer_03_ShadeCorr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_52->addItem(horizontalSpacer_03_ShadeCorr, 0, 3, 1, 1);

        label_03_ShadeCorr_Src2_Titel = new QLabel(page_03_ShadeCorr);
        label_03_ShadeCorr_Src2_Titel->setObjectName(QString::fromUtf8("label_03_ShadeCorr_Src2_Titel"));
        label_03_ShadeCorr_Src2_Titel->setMinimumSize(QSize(75, 0));

        gridLayout_52->addWidget(label_03_ShadeCorr_Src2_Titel, 1, 1, 1, 1);

        line_03_ShadeCorr = new QFrame(page_03_ShadeCorr);
        line_03_ShadeCorr->setObjectName(QString::fromUtf8("line_03_ShadeCorr"));
        line_03_ShadeCorr->setFrameShape(QFrame::VLine);
        line_03_ShadeCorr->setFrameShadow(QFrame::Sunken);

        gridLayout_52->addWidget(line_03_ShadeCorr, 0, 0, 4, 1);

        verticalSpacer_03_ShadeCorr = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_52->addItem(verticalSpacer_03_ShadeCorr, 3, 1, 1, 1);

        label_03_ShadeCorr_Src1_Titel = new QLabel(page_03_ShadeCorr);
        label_03_ShadeCorr_Src1_Titel->setObjectName(QString::fromUtf8("label_03_ShadeCorr_Src1_Titel"));
        label_03_ShadeCorr_Src1_Titel->setMinimumSize(QSize(75, 0));

        gridLayout_52->addWidget(label_03_ShadeCorr_Src1_Titel, 0, 1, 1, 1);

        label_03_ShadeCorr_Src1_Descr = new QLabel(page_03_ShadeCorr);
        label_03_ShadeCorr_Src1_Descr->setObjectName(QString::fromUtf8("label_03_ShadeCorr_Src1_Descr"));

        gridLayout_52->addWidget(label_03_ShadeCorr_Src1_Descr, 0, 2, 1, 1);

        label_03_ShadeCorr_Src2_Descr = new QLabel(page_03_ShadeCorr);
        label_03_ShadeCorr_Src2_Descr->setObjectName(QString::fromUtf8("label_03_ShadeCorr_Src2_Descr"));

        gridLayout_52->addWidget(label_03_ShadeCorr_Src2_Descr, 1, 2, 1, 1);

        label_03_ShadeCorr_Dst_Descr = new QLabel(page_03_ShadeCorr);
        label_03_ShadeCorr_Dst_Descr->setObjectName(QString::fromUtf8("label_03_ShadeCorr_Dst_Descr"));

        gridLayout_52->addWidget(label_03_ShadeCorr_Dst_Descr, 2, 2, 1, 1);

        stackedWidget_Settings_03_Elemental->addWidget(page_03_ShadeCorr);
        page_03_GrabColor = new QWidget();
        page_03_GrabColor->setObjectName(QString::fromUtf8("page_03_GrabColor"));
        gridLayout_56 = new QGridLayout(page_03_GrabColor);
        gridLayout_56->setObjectName(QString::fromUtf8("gridLayout_56"));
        label_03_GrabColor_Ch2_Max = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch2_Max->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch2_Max"));
        label_03_GrabColor_Ch2_Max->setMinimumSize(QSize(20, 0));
        label_03_GrabColor_Ch2_Max->setMaximumSize(QSize(18, 20));

        gridLayout_56->addWidget(label_03_GrabColor_Ch2_Max, 6, 2, 1, 1);

        spinBox_03_GrabColor_Ch2_Max = new QSpinBox(page_03_GrabColor);
        spinBox_03_GrabColor_Ch2_Max->setObjectName(QString::fromUtf8("spinBox_03_GrabColor_Ch2_Max"));
        spinBox_03_GrabColor_Ch2_Max->setMinimumSize(QSize(75, 0));
        spinBox_03_GrabColor_Ch2_Max->setMaximumSize(QSize(75, 16777215));
        spinBox_03_GrabColor_Ch2_Max->setMaximum(255);
        spinBox_03_GrabColor_Ch2_Max->setValue(170);

        gridLayout_56->addWidget(spinBox_03_GrabColor_Ch2_Max, 6, 3, 1, 1);

        comboBox_03_GrabColor_ColorSpace = new QComboBox(page_03_GrabColor);
        comboBox_03_GrabColor_ColorSpace->addItem(QString());
        comboBox_03_GrabColor_ColorSpace->addItem(QString());
        comboBox_03_GrabColor_ColorSpace->addItem(QString());
        comboBox_03_GrabColor_ColorSpace->addItem(QString());
        comboBox_03_GrabColor_ColorSpace->addItem(QString());
        comboBox_03_GrabColor_ColorSpace->addItem(QString());
        comboBox_03_GrabColor_ColorSpace->setObjectName(QString::fromUtf8("comboBox_03_GrabColor_ColorSpace"));
        comboBox_03_GrabColor_ColorSpace->setMinimumSize(QSize(75, 0));
        comboBox_03_GrabColor_ColorSpace->setMaximumSize(QSize(75, 16777215));

        gridLayout_56->addWidget(comboBox_03_GrabColor_ColorSpace, 0, 3, 1, 1);

        label_03_GrabColor_Ch2_Min = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch2_Min->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch2_Min"));
        label_03_GrabColor_Ch2_Min->setMinimumSize(QSize(20, 0));
        label_03_GrabColor_Ch2_Min->setMaximumSize(QSize(18, 20));

        gridLayout_56->addWidget(label_03_GrabColor_Ch2_Min, 5, 2, 1, 1);

        horizontalSlider_03_GrabColor_Ch2_Max = new QSlider(page_03_GrabColor);
        horizontalSlider_03_GrabColor_Ch2_Max->setObjectName(QString::fromUtf8("horizontalSlider_03_GrabColor_Ch2_Max"));
        horizontalSlider_03_GrabColor_Ch2_Max->setMaximum(255);
        horizontalSlider_03_GrabColor_Ch2_Max->setPageStep(16);
        horizontalSlider_03_GrabColor_Ch2_Max->setValue(170);
        horizontalSlider_03_GrabColor_Ch2_Max->setOrientation(Qt::Horizontal);
        horizontalSlider_03_GrabColor_Ch2_Max->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_03_GrabColor_Ch2_Max->setTickInterval(32);

        gridLayout_56->addWidget(horizontalSlider_03_GrabColor_Ch2_Max, 6, 4, 1, 3);

        horizontalSlider_03_GrabColor_Ch3_Min = new QSlider(page_03_GrabColor);
        horizontalSlider_03_GrabColor_Ch3_Min->setObjectName(QString::fromUtf8("horizontalSlider_03_GrabColor_Ch3_Min"));
        horizontalSlider_03_GrabColor_Ch3_Min->setMaximum(255);
        horizontalSlider_03_GrabColor_Ch3_Min->setPageStep(16);
        horizontalSlider_03_GrabColor_Ch3_Min->setValue(85);
        horizontalSlider_03_GrabColor_Ch3_Min->setOrientation(Qt::Horizontal);
        horizontalSlider_03_GrabColor_Ch3_Min->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_03_GrabColor_Ch3_Min->setTickInterval(32);

        gridLayout_56->addWidget(horizontalSlider_03_GrabColor_Ch3_Min, 8, 4, 1, 3);

        horizontalSlider_03_GrabColor_Ch2_Min = new QSlider(page_03_GrabColor);
        horizontalSlider_03_GrabColor_Ch2_Min->setObjectName(QString::fromUtf8("horizontalSlider_03_GrabColor_Ch2_Min"));
        horizontalSlider_03_GrabColor_Ch2_Min->setMaximum(255);
        horizontalSlider_03_GrabColor_Ch2_Min->setPageStep(16);
        horizontalSlider_03_GrabColor_Ch2_Min->setValue(85);
        horizontalSlider_03_GrabColor_Ch2_Min->setOrientation(Qt::Horizontal);
        horizontalSlider_03_GrabColor_Ch2_Min->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_03_GrabColor_Ch2_Min->setTickInterval(32);

        gridLayout_56->addWidget(horizontalSlider_03_GrabColor_Ch2_Min, 5, 4, 1, 3);

        horizontalSpacer_03_GrabColor = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_56->addItem(horizontalSpacer_03_GrabColor, 0, 6, 1, 1);

        label_03_GrabColor_Ch3_Min = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch3_Min->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch3_Min"));
        label_03_GrabColor_Ch3_Min->setMinimumSize(QSize(20, 0));
        label_03_GrabColor_Ch3_Min->setMaximumSize(QSize(18, 20));

        gridLayout_56->addWidget(label_03_GrabColor_Ch3_Min, 8, 2, 1, 1);

        spinBox_03_GrabColor_Ch3_Min = new QSpinBox(page_03_GrabColor);
        spinBox_03_GrabColor_Ch3_Min->setObjectName(QString::fromUtf8("spinBox_03_GrabColor_Ch3_Min"));
        spinBox_03_GrabColor_Ch3_Min->setMinimumSize(QSize(75, 0));
        spinBox_03_GrabColor_Ch3_Min->setMaximumSize(QSize(75, 16777215));
        spinBox_03_GrabColor_Ch3_Min->setMaximum(255);
        spinBox_03_GrabColor_Ch3_Min->setValue(85);

        gridLayout_56->addWidget(spinBox_03_GrabColor_Ch3_Min, 8, 3, 1, 1);

        horizontalSlider_03_GrabColor_Ch3_Max = new QSlider(page_03_GrabColor);
        horizontalSlider_03_GrabColor_Ch3_Max->setObjectName(QString::fromUtf8("horizontalSlider_03_GrabColor_Ch3_Max"));
        horizontalSlider_03_GrabColor_Ch3_Max->setMaximum(255);
        horizontalSlider_03_GrabColor_Ch3_Max->setPageStep(16);
        horizontalSlider_03_GrabColor_Ch3_Max->setValue(170);
        horizontalSlider_03_GrabColor_Ch3_Max->setOrientation(Qt::Horizontal);
        horizontalSlider_03_GrabColor_Ch3_Max->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_03_GrabColor_Ch3_Max->setTickInterval(32);

        gridLayout_56->addWidget(horizontalSlider_03_GrabColor_Ch3_Max, 9, 4, 1, 3);

        label_03_GrabColor_Ch3_Max = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch3_Max->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch3_Max"));
        label_03_GrabColor_Ch3_Max->setMinimumSize(QSize(20, 0));
        label_03_GrabColor_Ch3_Max->setMaximumSize(QSize(18, 20));

        gridLayout_56->addWidget(label_03_GrabColor_Ch3_Max, 9, 2, 1, 1);

        spinBox_03_GrabColor_Ch1_Max = new QSpinBox(page_03_GrabColor);
        spinBox_03_GrabColor_Ch1_Max->setObjectName(QString::fromUtf8("spinBox_03_GrabColor_Ch1_Max"));
        spinBox_03_GrabColor_Ch1_Max->setMinimumSize(QSize(75, 0));
        spinBox_03_GrabColor_Ch1_Max->setMaximumSize(QSize(75, 16777215));
        spinBox_03_GrabColor_Ch1_Max->setMaximum(255);
        spinBox_03_GrabColor_Ch1_Max->setValue(170);

        gridLayout_56->addWidget(spinBox_03_GrabColor_Ch1_Max, 3, 3, 1, 1);

        horizontalSlider_03_GrabColor_Ch1_Max = new QSlider(page_03_GrabColor);
        horizontalSlider_03_GrabColor_Ch1_Max->setObjectName(QString::fromUtf8("horizontalSlider_03_GrabColor_Ch1_Max"));
        horizontalSlider_03_GrabColor_Ch1_Max->setMaximum(255);
        horizontalSlider_03_GrabColor_Ch1_Max->setPageStep(16);
        horizontalSlider_03_GrabColor_Ch1_Max->setValue(170);
        horizontalSlider_03_GrabColor_Ch1_Max->setOrientation(Qt::Horizontal);
        horizontalSlider_03_GrabColor_Ch1_Max->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_03_GrabColor_Ch1_Max->setTickInterval(32);

        gridLayout_56->addWidget(horizontalSlider_03_GrabColor_Ch1_Max, 3, 4, 1, 3);

        spinBox_03_GrabColor_Ch3_Max = new QSpinBox(page_03_GrabColor);
        spinBox_03_GrabColor_Ch3_Max->setObjectName(QString::fromUtf8("spinBox_03_GrabColor_Ch3_Max"));
        spinBox_03_GrabColor_Ch3_Max->setMinimumSize(QSize(75, 0));
        spinBox_03_GrabColor_Ch3_Max->setMaximumSize(QSize(75, 16777215));
        spinBox_03_GrabColor_Ch3_Max->setMaximum(255);
        spinBox_03_GrabColor_Ch3_Max->setValue(170);

        gridLayout_56->addWidget(spinBox_03_GrabColor_Ch3_Max, 9, 3, 1, 1);

        spinBox_03_GrabColor_Ch2_Min = new QSpinBox(page_03_GrabColor);
        spinBox_03_GrabColor_Ch2_Min->setObjectName(QString::fromUtf8("spinBox_03_GrabColor_Ch2_Min"));
        spinBox_03_GrabColor_Ch2_Min->setMinimumSize(QSize(75, 0));
        spinBox_03_GrabColor_Ch2_Min->setMaximumSize(QSize(75, 16777215));
        spinBox_03_GrabColor_Ch2_Min->setMaximum(255);
        spinBox_03_GrabColor_Ch2_Min->setValue(85);

        gridLayout_56->addWidget(spinBox_03_GrabColor_Ch2_Min, 5, 3, 1, 1);

        comboBox_03_GrabColor_Output = new QComboBox(page_03_GrabColor);
        comboBox_03_GrabColor_Output->addItem(QString());
        comboBox_03_GrabColor_Output->addItem(QString());
        comboBox_03_GrabColor_Output->setObjectName(QString::fromUtf8("comboBox_03_GrabColor_Output"));
        comboBox_03_GrabColor_Output->setMinimumSize(QSize(75, 0));
        comboBox_03_GrabColor_Output->setMaximumSize(QSize(75, 16777215));

        gridLayout_56->addWidget(comboBox_03_GrabColor_Output, 0, 5, 1, 1);

        line_03_GrabColor_1 = new QFrame(page_03_GrabColor);
        line_03_GrabColor_1->setObjectName(QString::fromUtf8("line_03_GrabColor_1"));
        line_03_GrabColor_1->setFrameShape(QFrame::VLine);
        line_03_GrabColor_1->setFrameShadow(QFrame::Sunken);

        gridLayout_56->addWidget(line_03_GrabColor_1, 0, 0, 10, 1);

        label_03_GrabColor_Output = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Output->setObjectName(QString::fromUtf8("label_03_GrabColor_Output"));
        label_03_GrabColor_Output->setMinimumSize(QSize(75, 0));
        label_03_GrabColor_Output->setMaximumSize(QSize(75, 16777215));

        gridLayout_56->addWidget(label_03_GrabColor_Output, 0, 4, 1, 1);

        label_03_GrabColor_Ch1_Min = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch1_Min->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch1_Min"));
        label_03_GrabColor_Ch1_Min->setMinimumSize(QSize(20, 0));
        label_03_GrabColor_Ch1_Min->setMaximumSize(QSize(18, 20));

        gridLayout_56->addWidget(label_03_GrabColor_Ch1_Min, 2, 2, 1, 1);

        spinBox_03_GrabColor_Ch1_Min = new QSpinBox(page_03_GrabColor);
        spinBox_03_GrabColor_Ch1_Min->setObjectName(QString::fromUtf8("spinBox_03_GrabColor_Ch1_Min"));
        spinBox_03_GrabColor_Ch1_Min->setMinimumSize(QSize(75, 0));
        spinBox_03_GrabColor_Ch1_Min->setMaximumSize(QSize(75, 16777215));
        spinBox_03_GrabColor_Ch1_Min->setMaximum(255);
        spinBox_03_GrabColor_Ch1_Min->setValue(85);

        gridLayout_56->addWidget(spinBox_03_GrabColor_Ch1_Min, 2, 3, 1, 1);

        horizontalSlider_03_GrabColor_Ch1_Min = new QSlider(page_03_GrabColor);
        horizontalSlider_03_GrabColor_Ch1_Min->setObjectName(QString::fromUtf8("horizontalSlider_03_GrabColor_Ch1_Min"));
        horizontalSlider_03_GrabColor_Ch1_Min->setMaximum(255);
        horizontalSlider_03_GrabColor_Ch1_Min->setPageStep(16);
        horizontalSlider_03_GrabColor_Ch1_Min->setValue(85);
        horizontalSlider_03_GrabColor_Ch1_Min->setOrientation(Qt::Horizontal);
        horizontalSlider_03_GrabColor_Ch1_Min->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_03_GrabColor_Ch1_Min->setTickInterval(32);

        gridLayout_56->addWidget(horizontalSlider_03_GrabColor_Ch1_Min, 2, 4, 1, 3);

        label_03_GrabColor_Ch1_Max = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch1_Max->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch1_Max"));
        label_03_GrabColor_Ch1_Max->setMinimumSize(QSize(20, 0));
        label_03_GrabColor_Ch1_Max->setMaximumSize(QSize(18, 20));

        gridLayout_56->addWidget(label_03_GrabColor_Ch1_Max, 3, 2, 1, 1);

        label_03_GrabColor_Ch1 = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch1->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch1"));
        label_03_GrabColor_Ch1->setMinimumSize(QSize(59, 0));
        label_03_GrabColor_Ch1->setMaximumSize(QSize(59, 16777215));

        gridLayout_56->addWidget(label_03_GrabColor_Ch1, 2, 1, 2, 1);

        label_03_GrabColor_Ch2 = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch2->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch2"));
        label_03_GrabColor_Ch2->setMinimumSize(QSize(59, 0));
        label_03_GrabColor_Ch2->setMaximumSize(QSize(59, 16777215));

        gridLayout_56->addWidget(label_03_GrabColor_Ch2, 5, 1, 2, 1);

        label_03_GrabColor_Ch3 = new QLabel(page_03_GrabColor);
        label_03_GrabColor_Ch3->setObjectName(QString::fromUtf8("label_03_GrabColor_Ch3"));
        label_03_GrabColor_Ch3->setMinimumSize(QSize(59, 0));
        label_03_GrabColor_Ch3->setMaximumSize(QSize(59, 16777215));

        gridLayout_56->addWidget(label_03_GrabColor_Ch3, 8, 1, 2, 1);

        line_03_GrabColor_2 = new QFrame(page_03_GrabColor);
        line_03_GrabColor_2->setObjectName(QString::fromUtf8("line_03_GrabColor_2"));
        line_03_GrabColor_2->setFrameShape(QFrame::HLine);
        line_03_GrabColor_2->setFrameShadow(QFrame::Sunken);

        gridLayout_56->addWidget(line_03_GrabColor_2, 1, 1, 1, 6);

        label_03_GrabColor_ColorSpace = new QLabel(page_03_GrabColor);
        label_03_GrabColor_ColorSpace->setObjectName(QString::fromUtf8("label_03_GrabColor_ColorSpace"));
        label_03_GrabColor_ColorSpace->setMinimumSize(QSize(85, 0));
        label_03_GrabColor_ColorSpace->setMaximumSize(QSize(85, 16777215));

        gridLayout_56->addWidget(label_03_GrabColor_ColorSpace, 0, 1, 1, 2);

        line_03_GrabColor_3 = new QFrame(page_03_GrabColor);
        line_03_GrabColor_3->setObjectName(QString::fromUtf8("line_03_GrabColor_3"));
        line_03_GrabColor_3->setFrameShape(QFrame::HLine);
        line_03_GrabColor_3->setFrameShadow(QFrame::Sunken);

        gridLayout_56->addWidget(line_03_GrabColor_3, 4, 1, 1, 6);

        line_03_GrabColor_4 = new QFrame(page_03_GrabColor);
        line_03_GrabColor_4->setObjectName(QString::fromUtf8("line_03_GrabColor_4"));
        line_03_GrabColor_4->setFrameShape(QFrame::HLine);
        line_03_GrabColor_4->setFrameShadow(QFrame::Sunken);

        gridLayout_56->addWidget(line_03_GrabColor_4, 7, 1, 1, 6);

        stackedWidget_Settings_03_Elemental->addWidget(page_03_GrabColor);
        page_03_FillHoles = new QWidget();
        page_03_FillHoles->setObjectName(QString::fromUtf8("page_03_FillHoles"));
        gridLayout_5 = new QGridLayout(page_03_FillHoles);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        line_03_FillHoles = new QFrame(page_03_FillHoles);
        line_03_FillHoles->setObjectName(QString::fromUtf8("line_03_FillHoles"));
        line_03_FillHoles->setFrameShape(QFrame::VLine);
        line_03_FillHoles->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_03_FillHoles, 0, 0, 2, 1);

        label_03_FillHoles_Description = new QLabel(page_03_FillHoles);
        label_03_FillHoles_Description->setObjectName(QString::fromUtf8("label_03_FillHoles_Description"));

        gridLayout_5->addWidget(label_03_FillHoles_Description, 0, 1, 1, 1);

        verticalSpacer_03_FillHoles = new QSpacerItem(20, 180, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_03_FillHoles, 1, 1, 1, 1);

        stackedWidget_Settings_03_Elemental->addWidget(page_03_FillHoles);

        gridLayout_20->addWidget(stackedWidget_Settings_03_Elemental, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_03_Elemental);
        page_Settings_04_Filter = new QWidget();
        page_Settings_04_Filter->setObjectName(QString::fromUtf8("page_Settings_04_Filter"));
        gridLayout_21 = new QGridLayout(page_Settings_04_Filter);
        gridLayout_21->setSpacing(0);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_04_Filter = new QStackedWidget(page_Settings_04_Filter);
        stackedWidget_Settings_04_Filter->setObjectName(QString::fromUtf8("stackedWidget_Settings_04_Filter"));
        page_04_Blur = new QWidget();
        page_04_Blur->setObjectName(QString::fromUtf8("page_04_Blur"));
        gridLayout_35 = new QGridLayout(page_04_Blur);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        line_04_Blur = new QFrame(page_04_Blur);
        line_04_Blur->setObjectName(QString::fromUtf8("line_04_Blur"));
        line_04_Blur->setFrameShape(QFrame::VLine);
        line_04_Blur->setFrameShadow(QFrame::Sunken);

        gridLayout_35->addWidget(line_04_Blur, 0, 0, 9, 1);

        spinBox_04_Blur_Size_X = new QSpinBox(page_04_Blur);
        spinBox_04_Blur_Size_X->setObjectName(QString::fromUtf8("spinBox_04_Blur_Size_X"));
        spinBox_04_Blur_Size_X->setMinimumSize(QSize(40, 0));
        spinBox_04_Blur_Size_X->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Blur_Size_X->setMinimum(1);
        spinBox_04_Blur_Size_X->setMaximum(1000003);
        spinBox_04_Blur_Size_X->setSingleStep(2);
        spinBox_04_Blur_Size_X->setValue(3);

        gridLayout_35->addWidget(spinBox_04_Blur_Size_X, 2, 2, 1, 1);

        label_04_Blur_Size_XY = new QLabel(page_04_Blur);
        label_04_Blur_Size_XY->setObjectName(QString::fromUtf8("label_04_Blur_Size_XY"));
        label_04_Blur_Size_XY->setMinimumSize(QSize(75, 0));
        label_04_Blur_Size_XY->setMaximumSize(QSize(75, 16777215));

        gridLayout_35->addWidget(label_04_Blur_Size_XY, 2, 1, 1, 1);

        horizontalSpacer_04_Blur = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_35->addItem(horizontalSpacer_04_Blur, 0, 7, 8, 1);

        verticalSpacer_04_Blur = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_35->addItem(verticalSpacer_04_Blur, 8, 1, 1, 1);

        label_04_Blur_Type = new QLabel(page_04_Blur);
        label_04_Blur_Type->setObjectName(QString::fromUtf8("label_04_Blur_Type"));
        label_04_Blur_Type->setMinimumSize(QSize(75, 0));
        label_04_Blur_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_35->addWidget(label_04_Blur_Type, 1, 1, 1, 1);

        comboBox_04_Blur_Type = new QComboBox(page_04_Blur);
        comboBox_04_Blur_Type->addItem(QString());
        comboBox_04_Blur_Type->addItem(QString());
        comboBox_04_Blur_Type->addItem(QString());
        comboBox_04_Blur_Type->addItem(QString());
        comboBox_04_Blur_Type->addItem(QString());
        comboBox_04_Blur_Type->setObjectName(QString::fromUtf8("comboBox_04_Blur_Type"));
        comboBox_04_Blur_Type->setMinimumSize(QSize(100, 0));
        comboBox_04_Blur_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_35->addWidget(comboBox_04_Blur_Type, 1, 2, 1, 2);

        label_04_Blur_Size = new QLabel(page_04_Blur);
        label_04_Blur_Size->setObjectName(QString::fromUtf8("label_04_Blur_Size"));
        label_04_Blur_Size->setMinimumSize(QSize(75, 0));
        label_04_Blur_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_35->addWidget(label_04_Blur_Size, 4, 1, 1, 1);

        spinBox_04_Blur_Size_Y = new QSpinBox(page_04_Blur);
        spinBox_04_Blur_Size_Y->setObjectName(QString::fromUtf8("spinBox_04_Blur_Size_Y"));
        spinBox_04_Blur_Size_Y->setMinimumSize(QSize(40, 0));
        spinBox_04_Blur_Size_Y->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Blur_Size_Y->setMinimum(1);
        spinBox_04_Blur_Size_Y->setMaximum(1000003);
        spinBox_04_Blur_Size_Y->setSingleStep(2);
        spinBox_04_Blur_Size_Y->setValue(3);

        gridLayout_35->addWidget(spinBox_04_Blur_Size_Y, 2, 3, 1, 1);

        spinBox_04_Blur_Size = new QSpinBox(page_04_Blur);
        spinBox_04_Blur_Size->setObjectName(QString::fromUtf8("spinBox_04_Blur_Size"));
        spinBox_04_Blur_Size->setMinimumSize(QSize(0, 0));
        spinBox_04_Blur_Size->setMaximumSize(QSize(100, 16777215));
        spinBox_04_Blur_Size->setMinimum(1);
        spinBox_04_Blur_Size->setMaximum(501);
        spinBox_04_Blur_Size->setSingleStep(2);
        spinBox_04_Blur_Size->setValue(3);

        gridLayout_35->addWidget(spinBox_04_Blur_Size, 4, 2, 1, 2);

        doubleSpinBox_04_Blur_Sigma_Y = new QDoubleSpinBox(page_04_Blur);
        doubleSpinBox_04_Blur_Sigma_Y->setObjectName(QString::fromUtf8("doubleSpinBox_04_Blur_Sigma_Y"));
        doubleSpinBox_04_Blur_Sigma_Y->setMinimumSize(QSize(40, 0));
        doubleSpinBox_04_Blur_Sigma_Y->setMaximumSize(QSize(47, 16777215));
        doubleSpinBox_04_Blur_Sigma_Y->setDecimals(2);
        doubleSpinBox_04_Blur_Sigma_Y->setMinimum(0.000000000000000);
        doubleSpinBox_04_Blur_Sigma_Y->setMaximum(1000000000.000000000000000);
        doubleSpinBox_04_Blur_Sigma_Y->setValue(1.000000000000000);

        gridLayout_35->addWidget(doubleSpinBox_04_Blur_Sigma_Y, 3, 3, 1, 1);

        doubleSpinBox_04_Blur_Sigma_X = new QDoubleSpinBox(page_04_Blur);
        doubleSpinBox_04_Blur_Sigma_X->setObjectName(QString::fromUtf8("doubleSpinBox_04_Blur_Sigma_X"));
        doubleSpinBox_04_Blur_Sigma_X->setMinimumSize(QSize(40, 0));
        doubleSpinBox_04_Blur_Sigma_X->setMaximumSize(QSize(47, 16777215));
        doubleSpinBox_04_Blur_Sigma_X->setDecimals(2);
        doubleSpinBox_04_Blur_Sigma_X->setMinimum(0.000000000000000);
        doubleSpinBox_04_Blur_Sigma_X->setMaximum(1000000000.000000000000000);
        doubleSpinBox_04_Blur_Sigma_X->setValue(1.000000000000000);

        gridLayout_35->addWidget(doubleSpinBox_04_Blur_Sigma_X, 3, 2, 1, 1);

        label_04_Blur_Sigma_XY = new QLabel(page_04_Blur);
        label_04_Blur_Sigma_XY->setObjectName(QString::fromUtf8("label_04_Blur_Sigma_XY"));

        gridLayout_35->addWidget(label_04_Blur_Sigma_XY, 3, 1, 1, 1);

        label_04_Blur_Depth = new QLabel(page_04_Blur);
        label_04_Blur_Depth->setObjectName(QString::fromUtf8("label_04_Blur_Depth"));
        label_04_Blur_Depth->setMinimumSize(QSize(75, 0));
        label_04_Blur_Depth->setMaximumSize(QSize(75, 16777215));

        gridLayout_35->addWidget(label_04_Blur_Depth, 1, 5, 1, 1);

        comboBox_04_Blur_Depth = new QComboBox(page_04_Blur);
        comboBox_04_Blur_Depth->addItem(QString());
        comboBox_04_Blur_Depth->setObjectName(QString::fromUtf8("comboBox_04_Blur_Depth"));
        comboBox_04_Blur_Depth->setMinimumSize(QSize(100, 0));
        comboBox_04_Blur_Depth->setMaximumSize(QSize(100, 16777215));

        gridLayout_35->addWidget(comboBox_04_Blur_Depth, 1, 6, 1, 1);

        label_04_Blur_Normalized = new QLabel(page_04_Blur);
        label_04_Blur_Normalized->setObjectName(QString::fromUtf8("label_04_Blur_Normalized"));
        label_04_Blur_Normalized->setMinimumSize(QSize(75, 0));
        label_04_Blur_Normalized->setMaximumSize(QSize(75, 16777215));

        gridLayout_35->addWidget(label_04_Blur_Normalized, 5, 1, 3, 1);

        checkBox_04_Blur_Normalized = new QCheckBox(page_04_Blur);
        checkBox_04_Blur_Normalized->setObjectName(QString::fromUtf8("checkBox_04_Blur_Normalized"));
        checkBox_04_Blur_Normalized->setMinimumSize(QSize(0, 0));
        checkBox_04_Blur_Normalized->setMaximumSize(QSize(100, 16777215));
        checkBox_04_Blur_Normalized->setChecked(true);

        gridLayout_35->addWidget(checkBox_04_Blur_Normalized, 5, 2, 3, 2);

        stackedWidget_Settings_04_Filter->addWidget(page_04_Blur);
        page_04_Edge = new QWidget();
        page_04_Edge->setObjectName(QString::fromUtf8("page_04_Edge"));
        gridLayout_36 = new QGridLayout(page_04_Edge);
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        spinBox_04_Edge_Thresh_High = new QSpinBox(page_04_Edge);
        spinBox_04_Edge_Thresh_High->setObjectName(QString::fromUtf8("spinBox_04_Edge_Thresh_High"));
        spinBox_04_Edge_Thresh_High->setMinimumSize(QSize(47, 0));
        spinBox_04_Edge_Thresh_High->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Edge_Thresh_High->setMinimum(1);
        spinBox_04_Edge_Thresh_High->setMaximum(255);
        spinBox_04_Edge_Thresh_High->setValue(200);

        gridLayout_36->addWidget(spinBox_04_Edge_Thresh_High, 7, 3, 1, 1);

        spinBox_04_Edge_Thresh_Low = new QSpinBox(page_04_Edge);
        spinBox_04_Edge_Thresh_Low->setObjectName(QString::fromUtf8("spinBox_04_Edge_Thresh_Low"));
        spinBox_04_Edge_Thresh_Low->setMinimumSize(QSize(47, 0));
        spinBox_04_Edge_Thresh_Low->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Edge_Thresh_Low->setMaximum(254);
        spinBox_04_Edge_Thresh_Low->setValue(100);

        gridLayout_36->addWidget(spinBox_04_Edge_Thresh_Low, 7, 2, 1, 1);

        label_04_Edge_Thesh = new QLabel(page_04_Edge);
        label_04_Edge_Thesh->setObjectName(QString::fromUtf8("label_04_Edge_Thesh"));

        gridLayout_36->addWidget(label_04_Edge_Thesh, 7, 1, 1, 1);

        label_04_Edge_Size = new QLabel(page_04_Edge);
        label_04_Edge_Size->setObjectName(QString::fromUtf8("label_04_Edge_Size"));
        label_04_Edge_Size->setMinimumSize(QSize(75, 0));
        label_04_Edge_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_36->addWidget(label_04_Edge_Size, 2, 1, 1, 1);

        verticalSpacer_04_Edge = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_36->addItem(verticalSpacer_04_Edge, 9, 7, 1, 1);

        label_04_Edge_Scale = new QLabel(page_04_Edge);
        label_04_Edge_Scale->setObjectName(QString::fromUtf8("label_04_Edge_Scale"));
        label_04_Edge_Scale->setMinimumSize(QSize(75, 0));
        label_04_Edge_Scale->setMaximumSize(QSize(75, 16777215));

        gridLayout_36->addWidget(label_04_Edge_Scale, 4, 1, 1, 1);

        comboBox_04_Edge_Type = new QComboBox(page_04_Edge);
        comboBox_04_Edge_Type->addItem(QString());
        comboBox_04_Edge_Type->addItem(QString());
        comboBox_04_Edge_Type->addItem(QString());
        comboBox_04_Edge_Type->addItem(QString());
        comboBox_04_Edge_Type->setObjectName(QString::fromUtf8("comboBox_04_Edge_Type"));
        comboBox_04_Edge_Type->setMinimumSize(QSize(100, 0));
        comboBox_04_Edge_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_36->addWidget(comboBox_04_Edge_Type, 0, 2, 1, 2);

        label_04_Edge_Delta = new QLabel(page_04_Edge);
        label_04_Edge_Delta->setObjectName(QString::fromUtf8("label_04_Edge_Delta"));
        label_04_Edge_Delta->setMinimumSize(QSize(75, 0));
        label_04_Edge_Delta->setMaximumSize(QSize(75, 16777215));

        gridLayout_36->addWidget(label_04_Edge_Delta, 5, 1, 1, 1);

        line_04_Edge = new QFrame(page_04_Edge);
        line_04_Edge->setObjectName(QString::fromUtf8("line_04_Edge"));
        line_04_Edge->setFrameShape(QFrame::VLine);
        line_04_Edge->setFrameShadow(QFrame::Sunken);

        gridLayout_36->addWidget(line_04_Edge, 0, 0, 11, 1);

        label_04_Edge_dXdY = new QLabel(page_04_Edge);
        label_04_Edge_dXdY->setObjectName(QString::fromUtf8("label_04_Edge_dXdY"));
        label_04_Edge_dXdY->setMinimumSize(QSize(75, 0));
        label_04_Edge_dXdY->setMaximumSize(QSize(75, 16777215));

        gridLayout_36->addWidget(label_04_Edge_dXdY, 6, 1, 1, 1);

        spinBox_04_Edge_dY = new QSpinBox(page_04_Edge);
        spinBox_04_Edge_dY->setObjectName(QString::fromUtf8("spinBox_04_Edge_dY"));
        spinBox_04_Edge_dY->setMinimumSize(QSize(47, 0));
        spinBox_04_Edge_dY->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Edge_dY->setMaximum(2);
        spinBox_04_Edge_dY->setValue(1);

        gridLayout_36->addWidget(spinBox_04_Edge_dY, 6, 3, 1, 1);

        spinBox_04_Edge_Size = new QSpinBox(page_04_Edge);
        spinBox_04_Edge_Size->setObjectName(QString::fromUtf8("spinBox_04_Edge_Size"));
        spinBox_04_Edge_Size->setMinimumSize(QSize(0, 0));
        spinBox_04_Edge_Size->setMaximumSize(QSize(100, 16777215));
        spinBox_04_Edge_Size->setMinimum(1);
        spinBox_04_Edge_Size->setMaximum(31);
        spinBox_04_Edge_Size->setSingleStep(2);
        spinBox_04_Edge_Size->setValue(3);

        gridLayout_36->addWidget(spinBox_04_Edge_Size, 2, 2, 1, 2);

        doubleSpinBox_04_Edge_Delta = new QDoubleSpinBox(page_04_Edge);
        doubleSpinBox_04_Edge_Delta->setObjectName(QString::fromUtf8("doubleSpinBox_04_Edge_Delta"));
        doubleSpinBox_04_Edge_Delta->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Edge_Delta->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Edge_Delta->setDecimals(3);
        doubleSpinBox_04_Edge_Delta->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Edge_Delta->setSingleStep(16.000000000000000);

        gridLayout_36->addWidget(doubleSpinBox_04_Edge_Delta, 5, 2, 1, 2);

        spinBox_04_Edge_dX = new QSpinBox(page_04_Edge);
        spinBox_04_Edge_dX->setObjectName(QString::fromUtf8("spinBox_04_Edge_dX"));
        spinBox_04_Edge_dX->setMinimumSize(QSize(47, 0));
        spinBox_04_Edge_dX->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Edge_dX->setMaximum(2);
        spinBox_04_Edge_dX->setValue(1);

        gridLayout_36->addWidget(spinBox_04_Edge_dX, 6, 2, 1, 1);

        label_04_Edge_Type = new QLabel(page_04_Edge);
        label_04_Edge_Type->setObjectName(QString::fromUtf8("label_04_Edge_Type"));
        label_04_Edge_Type->setMinimumSize(QSize(75, 0));
        label_04_Edge_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_36->addWidget(label_04_Edge_Type, 0, 1, 1, 1);

        doubleSpinBox_04_Edge_Scale = new QDoubleSpinBox(page_04_Edge);
        doubleSpinBox_04_Edge_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_04_Edge_Scale"));
        doubleSpinBox_04_Edge_Scale->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Edge_Scale->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Edge_Scale->setDecimals(3);
        doubleSpinBox_04_Edge_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_04_Edge_Scale->setValue(1.000000000000000);

        gridLayout_36->addWidget(doubleSpinBox_04_Edge_Scale, 4, 2, 1, 2);

        horizontalSpacer_04_Edge = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_36->addItem(horizontalSpacer_04_Edge, 0, 7, 7, 1);

        label_04_Edge_Depth = new QLabel(page_04_Edge);
        label_04_Edge_Depth->setObjectName(QString::fromUtf8("label_04_Edge_Depth"));
        label_04_Edge_Depth->setMinimumSize(QSize(75, 0));
        label_04_Edge_Depth->setMaximumSize(QSize(75, 16777215));

        gridLayout_36->addWidget(label_04_Edge_Depth, 0, 5, 1, 1);

        comboBox_04_Edge_Depth = new QComboBox(page_04_Edge);
        comboBox_04_Edge_Depth->addItem(QString());
        comboBox_04_Edge_Depth->setObjectName(QString::fromUtf8("comboBox_04_Edge_Depth"));
        comboBox_04_Edge_Depth->setMinimumSize(QSize(100, 0));
        comboBox_04_Edge_Depth->setMaximumSize(QSize(100, 16777215));

        gridLayout_36->addWidget(comboBox_04_Edge_Depth, 0, 6, 1, 1);

        label_04_Edge_Options = new QLabel(page_04_Edge);
        label_04_Edge_Options->setObjectName(QString::fromUtf8("label_04_Edge_Options"));

        gridLayout_36->addWidget(label_04_Edge_Options, 8, 1, 1, 1);

        checkBox_04_Edge_L2_Gradient = new QCheckBox(page_04_Edge);
        checkBox_04_Edge_L2_Gradient->setObjectName(QString::fromUtf8("checkBox_04_Edge_L2_Gradient"));
        checkBox_04_Edge_L2_Gradient->setMaximumSize(QSize(100, 16777215));

        gridLayout_36->addWidget(checkBox_04_Edge_L2_Gradient, 8, 2, 1, 2);

        stackedWidget_Settings_04_Filter->addWidget(page_04_Edge);
        page_04_Special = new QWidget();
        page_04_Special->setObjectName(QString::fromUtf8("page_04_Special"));
        gridLayout_37 = new QGridLayout(page_04_Special);
        gridLayout_37->setObjectName(QString::fromUtf8("gridLayout_37"));
        label_04_Special_Depth = new QLabel(page_04_Special);
        label_04_Special_Depth->setObjectName(QString::fromUtf8("label_04_Special_Depth"));
        label_04_Special_Depth->setMinimumSize(QSize(65, 0));

        gridLayout_37->addWidget(label_04_Special_Depth, 0, 4, 1, 1);

        spinBox_04_Special_Size_X = new QSpinBox(page_04_Special);
        spinBox_04_Special_Size_X->setObjectName(QString::fromUtf8("spinBox_04_Special_Size_X"));
        spinBox_04_Special_Size_X->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Special_Size_X->setMinimum(1);
        spinBox_04_Special_Size_X->setMaximum(100003);
        spinBox_04_Special_Size_X->setSingleStep(2);
        spinBox_04_Special_Size_X->setValue(3);

        gridLayout_37->addWidget(spinBox_04_Special_Size_X, 3, 2, 1, 1);

        comboBox_04_Special_Type = new QComboBox(page_04_Special);
        comboBox_04_Special_Type->addItem(QString());
        comboBox_04_Special_Type->addItem(QString());
        comboBox_04_Special_Type->setObjectName(QString::fromUtf8("comboBox_04_Special_Type"));
        comboBox_04_Special_Type->setMinimumSize(QSize(100, 0));
        comboBox_04_Special_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_37->addWidget(comboBox_04_Special_Type, 0, 2, 1, 2);

        spinBox_04_Special_Diameter = new QSpinBox(page_04_Special);
        spinBox_04_Special_Diameter->setObjectName(QString::fromUtf8("spinBox_04_Special_Diameter"));
        spinBox_04_Special_Diameter->setMinimumSize(QSize(0, 0));
        spinBox_04_Special_Diameter->setMaximumSize(QSize(100, 16777215));
        spinBox_04_Special_Diameter->setMinimum(0);
        spinBox_04_Special_Diameter->setMaximum(100000);
        spinBox_04_Special_Diameter->setSingleStep(1);
        spinBox_04_Special_Diameter->setValue(0);

        gridLayout_37->addWidget(spinBox_04_Special_Diameter, 2, 2, 1, 2);

        horizontalSpacer_04_Special = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_37->addItem(horizontalSpacer_04_Special, 0, 6, 2, 1);

        label_04_Special_Diameter = new QLabel(page_04_Special);
        label_04_Special_Diameter->setObjectName(QString::fromUtf8("label_04_Special_Diameter"));
        label_04_Special_Diameter->setMinimumSize(QSize(65, 0));

        gridLayout_37->addWidget(label_04_Special_Diameter, 2, 1, 1, 1);

        label_04_Special_Type = new QLabel(page_04_Special);
        label_04_Special_Type->setObjectName(QString::fromUtf8("label_04_Special_Type"));
        label_04_Special_Type->setMinimumSize(QSize(75, 0));

        gridLayout_37->addWidget(label_04_Special_Type, 0, 1, 1, 1);

        line_04_Special = new QFrame(page_04_Special);
        line_04_Special->setObjectName(QString::fromUtf8("line_04_Special"));
        line_04_Special->setFrameShape(QFrame::VLine);
        line_04_Special->setFrameShadow(QFrame::Sunken);

        gridLayout_37->addWidget(line_04_Special, 0, 0, 6, 1);

        stackedWidget_04_Special = new QStackedWidget(page_04_Special);
        stackedWidget_04_Special->setObjectName(QString::fromUtf8("stackedWidget_04_Special"));
        page_04_Special_Bilateral = new QWidget();
        page_04_Special_Bilateral->setObjectName(QString::fromUtf8("page_04_Special_Bilateral"));
        gridLayout_38 = new QGridLayout(page_04_Special_Bilateral);
        gridLayout_38->setObjectName(QString::fromUtf8("gridLayout_38"));
        label_04_Special_Sigma_Color = new QLabel(page_04_Special_Bilateral);
        label_04_Special_Sigma_Color->setObjectName(QString::fromUtf8("label_04_Special_Sigma_Color"));
        label_04_Special_Sigma_Color->setMinimumSize(QSize(65, 0));

        gridLayout_38->addWidget(label_04_Special_Sigma_Color, 1, 0, 1, 1);

        verticalSpacer_04_Special_Bilateral = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_38->addItem(verticalSpacer_04_Special_Bilateral, 3, 3, 1, 1);

        horizontalSpacer_04_Special_Bilateral = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_38->addItem(horizontalSpacer_04_Special_Bilateral, 1, 3, 1, 1);

        label_04_Special_Sigma_Space = new QLabel(page_04_Special_Bilateral);
        label_04_Special_Sigma_Space->setObjectName(QString::fromUtf8("label_04_Special_Sigma_Space"));
        label_04_Special_Sigma_Space->setMinimumSize(QSize(65, 0));

        gridLayout_38->addWidget(label_04_Special_Sigma_Space, 2, 0, 1, 1);

        doubleSpinBox_04_Special_Sigma_Color = new QDoubleSpinBox(page_04_Special_Bilateral);
        doubleSpinBox_04_Special_Sigma_Color->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Sigma_Color"));
        doubleSpinBox_04_Special_Sigma_Color->setMinimumSize(QSize(100, 0));
        doubleSpinBox_04_Special_Sigma_Color->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Sigma_Color->setMaximum(100000.000000000000000);
        doubleSpinBox_04_Special_Sigma_Color->setValue(20.000000000000000);

        gridLayout_38->addWidget(doubleSpinBox_04_Special_Sigma_Color, 1, 1, 1, 2);

        doubleSpinBox_04_Special_Sigma_Space = new QDoubleSpinBox(page_04_Special_Bilateral);
        doubleSpinBox_04_Special_Sigma_Space->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Sigma_Space"));
        doubleSpinBox_04_Special_Sigma_Space->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Special_Sigma_Space->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Sigma_Space->setMaximum(100000.000000000000000);
        doubleSpinBox_04_Special_Sigma_Space->setValue(20.000000000000000);

        gridLayout_38->addWidget(doubleSpinBox_04_Special_Sigma_Space, 2, 1, 1, 2);

        stackedWidget_04_Special->addWidget(page_04_Special_Bilateral);
        page_04_Special_Gabor = new QWidget();
        page_04_Special_Gabor->setObjectName(QString::fromUtf8("page_04_Special_Gabor"));
        gridLayout_39 = new QGridLayout(page_04_Special_Gabor);
        gridLayout_39->setObjectName(QString::fromUtf8("gridLayout_39"));
        doubleSpinBox_04_Special_Sigma = new QDoubleSpinBox(page_04_Special_Gabor);
        doubleSpinBox_04_Special_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Sigma"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(doubleSpinBox_04_Special_Sigma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Special_Sigma->setSizePolicy(sizePolicy3);
        doubleSpinBox_04_Special_Sigma->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Special_Sigma->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Sigma->setMaximum(10000.000000000000000);
        doubleSpinBox_04_Special_Sigma->setValue(1.000000000000000);

        gridLayout_39->addWidget(doubleSpinBox_04_Special_Sigma, 1, 1, 1, 1);

        label_04_Special_Lambda = new QLabel(page_04_Special_Gabor);
        label_04_Special_Lambda->setObjectName(QString::fromUtf8("label_04_Special_Lambda"));
        label_04_Special_Lambda->setMinimumSize(QSize(65, 0));

        gridLayout_39->addWidget(label_04_Special_Lambda, 2, 0, 1, 1);

        horizontalSpacer_04_Special_Gabor = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_39->addItem(horizontalSpacer_04_Special_Gabor, 1, 5, 4, 1);

        doubleSpinBox_04_Special_Lambda = new QDoubleSpinBox(page_04_Special_Gabor);
        doubleSpinBox_04_Special_Lambda->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Lambda"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_04_Special_Lambda->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Special_Lambda->setSizePolicy(sizePolicy3);
        doubleSpinBox_04_Special_Lambda->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Special_Lambda->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Lambda->setMaximum(10000.000000000000000);
        doubleSpinBox_04_Special_Lambda->setSingleStep(0.050000000000000);
        doubleSpinBox_04_Special_Lambda->setValue(1.000000000000000);

        gridLayout_39->addWidget(doubleSpinBox_04_Special_Lambda, 2, 1, 1, 1);

        label_04_Special_Sigma = new QLabel(page_04_Special_Gabor);
        label_04_Special_Sigma->setObjectName(QString::fromUtf8("label_04_Special_Sigma"));
        label_04_Special_Sigma->setMinimumSize(QSize(65, 0));

        gridLayout_39->addWidget(label_04_Special_Sigma, 1, 0, 1, 1);

        doubleSpinBox_04_Special_Psi = new QDoubleSpinBox(page_04_Special_Gabor);
        doubleSpinBox_04_Special_Psi->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Psi"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_04_Special_Psi->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Special_Psi->setSizePolicy(sizePolicy3);
        doubleSpinBox_04_Special_Psi->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Special_Psi->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Psi->setDecimals(3);
        doubleSpinBox_04_Special_Psi->setMaximum(359.999000000000024);
        doubleSpinBox_04_Special_Psi->setValue(45.000000000000000);

        gridLayout_39->addWidget(doubleSpinBox_04_Special_Psi, 2, 3, 1, 1);

        label_04_Special_Psi = new QLabel(page_04_Special_Gabor);
        label_04_Special_Psi->setObjectName(QString::fromUtf8("label_04_Special_Psi"));
        label_04_Special_Psi->setMinimumSize(QSize(65, 0));

        gridLayout_39->addWidget(label_04_Special_Psi, 2, 2, 1, 1);

        label_04_Special_Theta = new QLabel(page_04_Special_Gabor);
        label_04_Special_Theta->setObjectName(QString::fromUtf8("label_04_Special_Theta"));
        label_04_Special_Theta->setMinimumSize(QSize(65, 0));

        gridLayout_39->addWidget(label_04_Special_Theta, 1, 2, 1, 1);

        doubleSpinBox_04_Special_Delta = new QDoubleSpinBox(page_04_Special_Gabor);
        doubleSpinBox_04_Special_Delta->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Delta"));
        doubleSpinBox_04_Special_Delta->setMinimumSize(QSize(100, 0));
        doubleSpinBox_04_Special_Delta->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Delta->setMaximum(10000.000000000000000);

        gridLayout_39->addWidget(doubleSpinBox_04_Special_Delta, 0, 1, 1, 1);

        label_04_Special_Delta = new QLabel(page_04_Special_Gabor);
        label_04_Special_Delta->setObjectName(QString::fromUtf8("label_04_Special_Delta"));

        gridLayout_39->addWidget(label_04_Special_Delta, 0, 0, 1, 1);

        verticalSpacer_04_Special = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_39->addItem(verticalSpacer_04_Special, 5, 5, 1, 1);

        doubleSpinBox_04_Special_Gamma = new QDoubleSpinBox(page_04_Special_Gabor);
        doubleSpinBox_04_Special_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Gamma"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_04_Special_Gamma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Special_Gamma->setSizePolicy(sizePolicy3);
        doubleSpinBox_04_Special_Gamma->setMinimumSize(QSize(100, 0));
        doubleSpinBox_04_Special_Gamma->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Gamma->setMaximum(10000.000000000000000);

        gridLayout_39->addWidget(doubleSpinBox_04_Special_Gamma, 0, 3, 1, 1);

        doubleSpinBox_04_Special_Theta = new QDoubleSpinBox(page_04_Special_Gabor);
        doubleSpinBox_04_Special_Theta->setObjectName(QString::fromUtf8("doubleSpinBox_04_Special_Theta"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_04_Special_Theta->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Special_Theta->setSizePolicy(sizePolicy3);
        doubleSpinBox_04_Special_Theta->setMinimumSize(QSize(0, 0));
        doubleSpinBox_04_Special_Theta->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Special_Theta->setDecimals(3);
        doubleSpinBox_04_Special_Theta->setMaximum(359.999000000000024);

        gridLayout_39->addWidget(doubleSpinBox_04_Special_Theta, 1, 3, 1, 1);

        label_04_Special_Gamma = new QLabel(page_04_Special_Gabor);
        label_04_Special_Gamma->setObjectName(QString::fromUtf8("label_04_Special_Gamma"));
        label_04_Special_Gamma->setMinimumSize(QSize(65, 0));

        gridLayout_39->addWidget(label_04_Special_Gamma, 0, 2, 1, 1);

        stackedWidget_04_Special->addWidget(page_04_Special_Gabor);

        gridLayout_37->addWidget(stackedWidget_04_Special, 4, 1, 1, 6);

        spinBox_04_Special_Size_Y = new QSpinBox(page_04_Special);
        spinBox_04_Special_Size_Y->setObjectName(QString::fromUtf8("spinBox_04_Special_Size_Y"));
        spinBox_04_Special_Size_Y->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Special_Size_Y->setMinimum(1);
        spinBox_04_Special_Size_Y->setMaximum(100003);
        spinBox_04_Special_Size_Y->setSingleStep(2);
        spinBox_04_Special_Size_Y->setValue(3);

        gridLayout_37->addWidget(spinBox_04_Special_Size_Y, 3, 3, 1, 1);

        label_04_Special_Size_XY = new QLabel(page_04_Special);
        label_04_Special_Size_XY->setObjectName(QString::fromUtf8("label_04_Special_Size_XY"));

        gridLayout_37->addWidget(label_04_Special_Size_XY, 3, 1, 1, 1);

        comboBox_04_Special_Depth = new QComboBox(page_04_Special);
        comboBox_04_Special_Depth->addItem(QString());
        comboBox_04_Special_Depth->addItem(QString());
        comboBox_04_Special_Depth->setObjectName(QString::fromUtf8("comboBox_04_Special_Depth"));
        comboBox_04_Special_Depth->setMinimumSize(QSize(100, 0));
        comboBox_04_Special_Depth->setMaximumSize(QSize(100, 16777215));

        gridLayout_37->addWidget(comboBox_04_Special_Depth, 0, 5, 1, 1);

        stackedWidget_Settings_04_Filter->addWidget(page_04_Special);
        page_04_Eilenstein = new QWidget();
        page_04_Eilenstein->setObjectName(QString::fromUtf8("page_04_Eilenstein"));
        gridLayout_54 = new QGridLayout(page_04_Eilenstein);
        gridLayout_54->setSpacing(3);
        gridLayout_54->setObjectName(QString::fromUtf8("gridLayout_54"));
        gridLayout_54->setContentsMargins(-1, 9, -1, -1);
        stackedWidget_04_Eilenstein_Type = new QStackedWidget(page_04_Eilenstein);
        stackedWidget_04_Eilenstein_Type->setObjectName(QString::fromUtf8("stackedWidget_04_Eilenstein_Type"));
        page_04_Eilenstein_Comp = new QWidget();
        page_04_Eilenstein_Comp->setObjectName(QString::fromUtf8("page_04_Eilenstein_Comp"));
        gridLayout_70 = new QGridLayout(page_04_Eilenstein_Comp);
        gridLayout_70->setSpacing(3);
        gridLayout_70->setObjectName(QString::fromUtf8("gridLayout_70"));
        gridLayout_70->setContentsMargins(0, 3, 0, 0);
        label_04_Eilenstein_Size = new QLabel(page_04_Eilenstein_Comp);
        label_04_Eilenstein_Size->setObjectName(QString::fromUtf8("label_04_Eilenstein_Size"));
        label_04_Eilenstein_Size->setMinimumSize(QSize(75, 0));
        label_04_Eilenstein_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_70->addWidget(label_04_Eilenstein_Size, 2, 0, 1, 1);

        label_04_Eilenstein_Comparator = new QLabel(page_04_Eilenstein_Comp);
        label_04_Eilenstein_Comparator->setObjectName(QString::fromUtf8("label_04_Eilenstein_Comparator"));
        label_04_Eilenstein_Comparator->setMinimumSize(QSize(75, 0));
        label_04_Eilenstein_Comparator->setMaximumSize(QSize(75, 16777215));

        gridLayout_70->addWidget(label_04_Eilenstein_Comparator, 1, 0, 1, 1);

        checkBox_04_Eilenstein_Normalized = new QCheckBox(page_04_Eilenstein_Comp);
        checkBox_04_Eilenstein_Normalized->setObjectName(QString::fromUtf8("checkBox_04_Eilenstein_Normalized"));
        checkBox_04_Eilenstein_Normalized->setMinimumSize(QSize(100, 0));
        checkBox_04_Eilenstein_Normalized->setMaximumSize(QSize(100, 16777215));
        checkBox_04_Eilenstein_Normalized->setChecked(true);

        gridLayout_70->addWidget(checkBox_04_Eilenstein_Normalized, 4, 1, 1, 2);

        doubleSpinBox_04_Eilenstein_Delta = new QDoubleSpinBox(page_04_Eilenstein_Comp);
        doubleSpinBox_04_Eilenstein_Delta->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_Delta"));
        doubleSpinBox_04_Eilenstein_Delta->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Eilenstein_Delta->setDecimals(3);
        doubleSpinBox_04_Eilenstein_Delta->setMinimum(-65536.000000000000000);
        doubleSpinBox_04_Eilenstein_Delta->setMaximum(65535.000000000000000);

        gridLayout_70->addWidget(doubleSpinBox_04_Eilenstein_Delta, 3, 1, 1, 2);

        label_04_Eilenstein_Normalized = new QLabel(page_04_Eilenstein_Comp);
        label_04_Eilenstein_Normalized->setObjectName(QString::fromUtf8("label_04_Eilenstein_Normalized"));
        label_04_Eilenstein_Normalized->setMinimumSize(QSize(75, 0));
        label_04_Eilenstein_Normalized->setMaximumSize(QSize(75, 16777215));

        gridLayout_70->addWidget(label_04_Eilenstein_Normalized, 4, 0, 1, 1);

        spinBox_04_Eilenstein_Size_Y = new QSpinBox(page_04_Eilenstein_Comp);
        spinBox_04_Eilenstein_Size_Y->setObjectName(QString::fromUtf8("spinBox_04_Eilenstein_Size_Y"));
        spinBox_04_Eilenstein_Size_Y->setMinimumSize(QSize(47, 0));
        spinBox_04_Eilenstein_Size_Y->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Eilenstein_Size_Y->setMinimum(3);
        spinBox_04_Eilenstein_Size_Y->setMaximum(10000000);
        spinBox_04_Eilenstein_Size_Y->setSingleStep(2);

        gridLayout_70->addWidget(spinBox_04_Eilenstein_Size_Y, 2, 2, 1, 1);

        horizontalSpacer_04_Eilenstein = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_70->addItem(horizontalSpacer_04_Eilenstein, 2, 3, 1, 1);

        label_04_Eilenstein_Delta = new QLabel(page_04_Eilenstein_Comp);
        label_04_Eilenstein_Delta->setObjectName(QString::fromUtf8("label_04_Eilenstein_Delta"));
        label_04_Eilenstein_Delta->setMinimumSize(QSize(75, 0));
        label_04_Eilenstein_Delta->setMaximumSize(QSize(75, 16777215));

        gridLayout_70->addWidget(label_04_Eilenstein_Delta, 3, 0, 1, 1);

        comboBox_04_Eilenstein_Comparator = new QComboBox(page_04_Eilenstein_Comp);
        comboBox_04_Eilenstein_Comparator->addItem(QString());
        comboBox_04_Eilenstein_Comparator->addItem(QString());
        comboBox_04_Eilenstein_Comparator->addItem(QString());
        comboBox_04_Eilenstein_Comparator->addItem(QString());
        comboBox_04_Eilenstein_Comparator->addItem(QString());
        comboBox_04_Eilenstein_Comparator->addItem(QString());
        comboBox_04_Eilenstein_Comparator->setObjectName(QString::fromUtf8("comboBox_04_Eilenstein_Comparator"));
        comboBox_04_Eilenstein_Comparator->setMaximumSize(QSize(100, 16777215));

        gridLayout_70->addWidget(comboBox_04_Eilenstein_Comparator, 1, 1, 1, 2);

        spinBox_04_Eilenstein_Size_X = new QSpinBox(page_04_Eilenstein_Comp);
        spinBox_04_Eilenstein_Size_X->setObjectName(QString::fromUtf8("spinBox_04_Eilenstein_Size_X"));
        spinBox_04_Eilenstein_Size_X->setMinimumSize(QSize(47, 0));
        spinBox_04_Eilenstein_Size_X->setMaximumSize(QSize(47, 16777215));
        spinBox_04_Eilenstein_Size_X->setMinimum(3);
        spinBox_04_Eilenstein_Size_X->setMaximum(10000000);
        spinBox_04_Eilenstein_Size_X->setSingleStep(2);

        gridLayout_70->addWidget(spinBox_04_Eilenstein_Size_X, 2, 1, 1, 1);

        verticalSpacer_04_Eilenstein = new QSpacerItem(20, 140, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_70->addItem(verticalSpacer_04_Eilenstein, 5, 1, 1, 2);

        stackedWidget_04_Eilenstein_Type->addWidget(page_04_Eilenstein_Comp);
        page_04_Eilenstein_Gen = new QWidget();
        page_04_Eilenstein_Gen->setObjectName(QString::fromUtf8("page_04_Eilenstein_Gen"));
        gridLayout_76 = new QGridLayout(page_04_Eilenstein_Gen);
        gridLayout_76->setSpacing(3);
        gridLayout_76->setObjectName(QString::fromUtf8("gridLayout_76"));
        gridLayout_76->setContentsMargins(0, 3, 0, 0);
        comboBox_04_Eilenstein_PixelCenter = new QComboBox(page_04_Eilenstein_Gen);
        comboBox_04_Eilenstein_PixelCenter->setObjectName(QString::fromUtf8("comboBox_04_Eilenstein_PixelCenter"));
        comboBox_04_Eilenstein_PixelCenter->setMinimumSize(QSize(0, 18));

        gridLayout_76->addWidget(comboBox_04_Eilenstein_PixelCenter, 0, 1, 1, 1);

        comboBox_04_Eilenstein_PixelMask = new QComboBox(page_04_Eilenstein_Gen);
        comboBox_04_Eilenstein_PixelMask->setObjectName(QString::fromUtf8("comboBox_04_Eilenstein_PixelMask"));
        comboBox_04_Eilenstein_PixelMask->setMinimumSize(QSize(0, 18));

        gridLayout_76->addWidget(comboBox_04_Eilenstein_PixelMask, 4, 1, 1, 1);

        comboBox_04_Eilenstein_Response = new QComboBox(page_04_Eilenstein_Gen);
        comboBox_04_Eilenstein_Response->setObjectName(QString::fromUtf8("comboBox_04_Eilenstein_Response"));
        comboBox_04_Eilenstein_Response->setMinimumSize(QSize(0, 18));

        gridLayout_76->addWidget(comboBox_04_Eilenstein_Response, 11, 1, 1, 1);

        verticalSpacer_04_Eilenstein_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_76->addItem(verticalSpacer_04_Eilenstein_2, 12, 0, 1, 1);

        line_04_Eilenstein_2 = new QFrame(page_04_Eilenstein_Gen);
        line_04_Eilenstein_2->setObjectName(QString::fromUtf8("line_04_Eilenstein_2"));
        line_04_Eilenstein_2->setFrameShape(QFrame::HLine);
        line_04_Eilenstein_2->setFrameShadow(QFrame::Sunken);

        gridLayout_76->addWidget(line_04_Eilenstein_2, 7, 0, 1, 2);

        line_04_Eilenstein_3 = new QFrame(page_04_Eilenstein_Gen);
        line_04_Eilenstein_3->setObjectName(QString::fromUtf8("line_04_Eilenstein_3"));
        line_04_Eilenstein_3->setFrameShape(QFrame::HLine);
        line_04_Eilenstein_3->setFrameShadow(QFrame::Sunken);

        gridLayout_76->addWidget(line_04_Eilenstein_3, 3, 0, 1, 2);

        label_04_Eilenstein_Response_Title = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_Response_Title->setObjectName(QString::fromUtf8("label_04_Eilenstein_Response_Title"));
        label_04_Eilenstein_Response_Title->setMinimumSize(QSize(0, 18));

        gridLayout_76->addWidget(label_04_Eilenstein_Response_Title, 11, 0, 1, 1);

        label_04_Eilenstein_PixelCenter_Y = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_PixelCenter_Y->setObjectName(QString::fromUtf8("label_04_Eilenstein_PixelCenter_Y"));
        label_04_Eilenstein_PixelCenter_Y->setMinimumSize(QSize(75, 18));
        label_04_Eilenstein_PixelCenter_Y->setMaximumSize(QSize(75, 16777215));

        gridLayout_76->addWidget(label_04_Eilenstein_PixelCenter_Y, 2, 0, 1, 1);

        gridLayout_04_Eilenstein_PixelCenter = new QGridLayout();
        gridLayout_04_Eilenstein_PixelCenter->setSpacing(1);
        gridLayout_04_Eilenstein_PixelCenter->setObjectName(QString::fromUtf8("gridLayout_04_Eilenstein_PixelCenter"));
        doubleSpinBox_04_Eilenstein_PixelCenter_a = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setValue(1.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_a, 0, 0, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_b = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_b, 0, 1, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_d = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_d, 0, 3, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_c = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setValue(1.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_c, 0, 2, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_e = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_e, 1, 0, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_f = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_f, 1, 1, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_nan = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_nan, 1, 2, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelCenter_inf = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelCenter_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelCenter_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelCenter->addWidget(doubleSpinBox_04_Eilenstein_PixelCenter_inf, 1, 3, 1, 1);


        gridLayout_76->addLayout(gridLayout_04_Eilenstein_PixelCenter, 1, 1, 2, 1);

        label_04_Eilenstein_PixelCenter_X = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_PixelCenter_X->setObjectName(QString::fromUtf8("label_04_Eilenstein_PixelCenter_X"));
        label_04_Eilenstein_PixelCenter_X->setMinimumSize(QSize(0, 18));

        gridLayout_76->addWidget(label_04_Eilenstein_PixelCenter_X, 1, 0, 1, 1);

        gridLayout_04_Eilenstein_PixelMask = new QGridLayout();
        gridLayout_04_Eilenstein_PixelMask->setSpacing(1);
        gridLayout_04_Eilenstein_PixelMask->setObjectName(QString::fromUtf8("gridLayout_04_Eilenstein_PixelMask"));
        doubleSpinBox_04_Eilenstein_PixelMask_d = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_d->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_d->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_d, 0, 3, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_a = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_a->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_a->setValue(1.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_a, 0, 0, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_b = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_b->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_b->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_b, 0, 1, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_c = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_c->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_c->setValue(1.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_c, 0, 2, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_e = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_e->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_e->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_e, 1, 0, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_f = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_f->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_f->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_f, 1, 1, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_nan = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_nan, 1, 2, 1, 1);

        doubleSpinBox_04_Eilenstein_PixelMask_inf = new QDoubleSpinBox(page_04_Eilenstein_Gen);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setObjectName(QString::fromUtf8("doubleSpinBox_04_Eilenstein_PixelMask_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_04_Eilenstein_PixelMask_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setMinimumSize(QSize(75, 16));
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setWrapping(false);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setFrame(false);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setDecimals(3);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setValue(0.000000000000000);

        gridLayout_04_Eilenstein_PixelMask->addWidget(doubleSpinBox_04_Eilenstein_PixelMask_inf, 1, 3, 1, 1);


        gridLayout_76->addLayout(gridLayout_04_Eilenstein_PixelMask, 5, 1, 2, 1);

        label_04_Eilenstein_PixelMask_Y = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_PixelMask_Y->setObjectName(QString::fromUtf8("label_04_Eilenstein_PixelMask_Y"));
        label_04_Eilenstein_PixelMask_Y->setMinimumSize(QSize(75, 18));
        label_04_Eilenstein_PixelMask_Y->setMaximumSize(QSize(75, 16777215));

        gridLayout_76->addWidget(label_04_Eilenstein_PixelMask_Y, 6, 0, 1, 1);

        label_04_Eilenstein_PixelMask_X = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_PixelMask_X->setObjectName(QString::fromUtf8("label_04_Eilenstein_PixelMask_X"));
        label_04_Eilenstein_PixelMask_X->setMinimumSize(QSize(0, 18));

        gridLayout_76->addWidget(label_04_Eilenstein_PixelMask_X, 5, 0, 1, 1);

        label_04_Eilenstein_PixelCenter_Titel = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_PixelCenter_Titel->setObjectName(QString::fromUtf8("label_04_Eilenstein_PixelCenter_Titel"));

        gridLayout_76->addWidget(label_04_Eilenstein_PixelCenter_Titel, 0, 0, 1, 1);

        label_04_Eilenstein_PixelMask_Title = new QLabel(page_04_Eilenstein_Gen);
        label_04_Eilenstein_PixelMask_Title->setObjectName(QString::fromUtf8("label_04_Eilenstein_PixelMask_Title"));

        gridLayout_76->addWidget(label_04_Eilenstein_PixelMask_Title, 4, 0, 1, 1);

        stackedWidget_04_Eilenstein_Type->addWidget(page_04_Eilenstein_Gen);

        gridLayout_54->addWidget(stackedWidget_04_Eilenstein_Type, 1, 1, 1, 3);

        label_04_Eilenstein_Type = new QLabel(page_04_Eilenstein);
        label_04_Eilenstein_Type->setObjectName(QString::fromUtf8("label_04_Eilenstein_Type"));
        label_04_Eilenstein_Type->setMinimumSize(QSize(75, 0));
        label_04_Eilenstein_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_54->addWidget(label_04_Eilenstein_Type, 0, 1, 1, 1);

        comboBox_04_Eilenstein_Type = new QComboBox(page_04_Eilenstein);
        comboBox_04_Eilenstein_Type->addItem(QString());
        comboBox_04_Eilenstein_Type->addItem(QString());
        comboBox_04_Eilenstein_Type->setObjectName(QString::fromUtf8("comboBox_04_Eilenstein_Type"));
        comboBox_04_Eilenstein_Type->setMinimumSize(QSize(100, 0));
        comboBox_04_Eilenstein_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_54->addWidget(comboBox_04_Eilenstein_Type, 0, 2, 1, 1);

        line_04_Eilenstein = new QFrame(page_04_Eilenstein);
        line_04_Eilenstein->setObjectName(QString::fromUtf8("line_04_Eilenstein"));
        line_04_Eilenstein->setFrameShape(QFrame::VLine);
        line_04_Eilenstein->setFrameShadow(QFrame::Sunken);

        gridLayout_54->addWidget(line_04_Eilenstein, 0, 0, 4, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_54->addItem(horizontalSpacer, 0, 3, 1, 1);

        stackedWidget_Settings_04_Filter->addWidget(page_04_Eilenstein);
        page_04_Function = new QWidget();
        page_04_Function->setObjectName(QString::fromUtf8("page_04_Function"));
        gridLayout_80 = new QGridLayout(page_04_Function);
        gridLayout_80->setSpacing(3);
        gridLayout_80->setObjectName(QString::fromUtf8("gridLayout_80"));
        gridLayout_80->setContentsMargins(6, 6, 6, 6);
        gridLayout_04_Function_Functions = new QGridLayout();
        gridLayout_04_Function_Functions->setSpacing(2);
        gridLayout_04_Function_Functions->setObjectName(QString::fromUtf8("gridLayout_04_Function_Functions"));
        label_04_Function_f_f2_y = new QLabel(page_04_Function);
        label_04_Function_f_f2_y->setObjectName(QString::fromUtf8("label_04_Function_f_f2_y"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_04_Function_f_f2_y->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f2_y->setSizePolicy(sizePolicy4);
        label_04_Function_f_f2_y->setMinimumSize(QSize(40, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f2_y, 2, 2, 1, 1);

        label_04_Function_f_f4_x = new QLabel(page_04_Function);
        label_04_Function_f_f4_x->setObjectName(QString::fromUtf8("label_04_Function_f_f4_x"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f4_x->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f4_x->setSizePolicy(sizePolicy4);
        label_04_Function_f_f4_x->setMinimumSize(QSize(40, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f4_x, 4, 1, 1, 1);

        label_04_Function_f_f2_x = new QLabel(page_04_Function);
        label_04_Function_f_f2_x->setObjectName(QString::fromUtf8("label_04_Function_f_f2_x"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f2_x->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f2_x->setSizePolicy(sizePolicy4);
        label_04_Function_f_f2_x->setMinimumSize(QSize(40, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f2_x, 2, 1, 1, 1);

        label_04_Function_f_f1_y = new QLabel(page_04_Function);
        label_04_Function_f_f1_y->setObjectName(QString::fromUtf8("label_04_Function_f_f1_y"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f1_y->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f1_y->setSizePolicy(sizePolicy4);
        label_04_Function_f_f1_y->setMinimumSize(QSize(40, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f1_y, 1, 2, 1, 1);

        label_04_Function_f_f4_y = new QLabel(page_04_Function);
        label_04_Function_f_f4_y->setObjectName(QString::fromUtf8("label_04_Function_f_f4_y"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f4_y->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f4_y->setSizePolicy(sizePolicy4);
        label_04_Function_f_f4_y->setMinimumSize(QSize(40, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f4_y, 4, 2, 1, 1);

        label_04_Function_f_f3 = new QLabel(page_04_Function);
        label_04_Function_f_f3->setObjectName(QString::fromUtf8("label_04_Function_f_f3"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f3->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f3->setSizePolicy(sizePolicy4);
        label_04_Function_f_f3->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f3, 3, 0, 1, 1);

        label_04_Function_f_y = new QLabel(page_04_Function);
        label_04_Function_f_y->setObjectName(QString::fromUtf8("label_04_Function_f_y"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_04_Function_f_y->sizePolicy().hasHeightForWidth());
        label_04_Function_f_y->setSizePolicy(sizePolicy5);

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_y, 0, 2, 1, 1);

        comboBox_04_Function_f3_vF2 = new QComboBox(page_04_Function);
        comboBox_04_Function_f3_vF2->setObjectName(QString::fromUtf8("comboBox_04_Function_f3_vF2"));
        sizePolicy5.setHeightForWidth(comboBox_04_Function_f3_vF2->sizePolicy().hasHeightForWidth());
        comboBox_04_Function_f3_vF2->setSizePolicy(sizePolicy5);

        gridLayout_04_Function_Functions->addWidget(comboBox_04_Function_f3_vF2, 3, 3, 1, 2);

        comboBox_04_Function_f4_CenterF3 = new QComboBox(page_04_Function);
        comboBox_04_Function_f4_CenterF3->setObjectName(QString::fromUtf8("comboBox_04_Function_f4_CenterF3"));
        sizePolicy5.setHeightForWidth(comboBox_04_Function_f4_CenterF3->sizePolicy().hasHeightForWidth());
        comboBox_04_Function_f4_CenterF3->setSizePolicy(sizePolicy5);

        gridLayout_04_Function_Functions->addWidget(comboBox_04_Function_f4_CenterF3, 4, 3, 1, 2);

        label_04_Function_f_f1 = new QLabel(page_04_Function);
        label_04_Function_f_f1->setObjectName(QString::fromUtf8("label_04_Function_f_f1"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f1->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f1->setSizePolicy(sizePolicy4);
        label_04_Function_f_f1->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f1, 1, 0, 1, 1);

        comboBox_04_Function_f1_CenterImage = new QComboBox(page_04_Function);
        comboBox_04_Function_f1_CenterImage->setObjectName(QString::fromUtf8("comboBox_04_Function_f1_CenterImage"));
        sizePolicy5.setHeightForWidth(comboBox_04_Function_f1_CenterImage->sizePolicy().hasHeightForWidth());
        comboBox_04_Function_f1_CenterImage->setSizePolicy(sizePolicy5);

        gridLayout_04_Function_Functions->addWidget(comboBox_04_Function_f1_CenterImage, 1, 3, 1, 2);

        comboBox_04_Function_f2_F1Mask = new QComboBox(page_04_Function);
        comboBox_04_Function_f2_F1Mask->setObjectName(QString::fromUtf8("comboBox_04_Function_f2_F1Mask"));
        sizePolicy5.setHeightForWidth(comboBox_04_Function_f2_F1Mask->sizePolicy().hasHeightForWidth());
        comboBox_04_Function_f2_F1Mask->setSizePolicy(sizePolicy5);

        gridLayout_04_Function_Functions->addWidget(comboBox_04_Function_f2_F1Mask, 2, 3, 1, 2);

        label_04_Function_f_f4 = new QLabel(page_04_Function);
        label_04_Function_f_f4->setObjectName(QString::fromUtf8("label_04_Function_f_f4"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f4->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f4->setSizePolicy(sizePolicy4);
        label_04_Function_f_f4->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f4, 4, 0, 1, 1);

        label_04_Function_f_f2 = new QLabel(page_04_Function);
        label_04_Function_f_f2->setObjectName(QString::fromUtf8("label_04_Function_f_f2"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f2->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f2->setSizePolicy(sizePolicy4);
        label_04_Function_f_f2->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f2, 2, 0, 1, 1);

        label_04_Function_f_f1_x = new QLabel(page_04_Function);
        label_04_Function_f_f1_x->setObjectName(QString::fromUtf8("label_04_Function_f_f1_x"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_f1_x->sizePolicy().hasHeightForWidth());
        label_04_Function_f_f1_x->setSizePolicy(sizePolicy4);
        label_04_Function_f_f1_x->setMinimumSize(QSize(40, 0));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f1_x, 1, 1, 1, 1);

        label_04_Function_f_x = new QLabel(page_04_Function);
        label_04_Function_f_x->setObjectName(QString::fromUtf8("label_04_Function_f_x"));
        sizePolicy5.setHeightForWidth(label_04_Function_f_x->sizePolicy().hasHeightForWidth());
        label_04_Function_f_x->setSizePolicy(sizePolicy5);

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_x, 0, 1, 1, 1);

        label_04_Function_f_f3_data = new QLabel(page_04_Function);
        label_04_Function_f_f3_data->setObjectName(QString::fromUtf8("label_04_Function_f_f3_data"));

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_f3_data, 3, 1, 1, 2);

        label_04_Function_f_prototype = new QLabel(page_04_Function);
        label_04_Function_f_prototype->setObjectName(QString::fromUtf8("label_04_Function_f_prototype"));
        sizePolicy4.setHeightForWidth(label_04_Function_f_prototype->sizePolicy().hasHeightForWidth());
        label_04_Function_f_prototype->setSizePolicy(sizePolicy4);

        gridLayout_04_Function_Functions->addWidget(label_04_Function_f_prototype, 0, 3, 1, 1);

        checkBox_04_Function_OnlyNonZero = new QCheckBox(page_04_Function);
        checkBox_04_Function_OnlyNonZero->setObjectName(QString::fromUtf8("checkBox_04_Function_OnlyNonZero"));
        sizePolicy.setHeightForWidth(checkBox_04_Function_OnlyNonZero->sizePolicy().hasHeightForWidth());
        checkBox_04_Function_OnlyNonZero->setSizePolicy(sizePolicy);

        gridLayout_04_Function_Functions->addWidget(checkBox_04_Function_OnlyNonZero, 0, 4, 1, 1);


        gridLayout_80->addLayout(gridLayout_04_Function_Functions, 0, 1, 1, 1);

        gridLayout_04_Function_Parameters = new QGridLayout();
        gridLayout_04_Function_Parameters->setSpacing(1);
        gridLayout_04_Function_Parameters->setObjectName(QString::fromUtf8("gridLayout_04_Function_Parameters"));
        doubleSpinBox_04_Function_f4_inf = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_inf->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_inf"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_inf->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_inf->setWrapping(false);
        doubleSpinBox_04_Function_f4_inf->setFrame(false);
        doubleSpinBox_04_Function_f4_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_inf->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_inf->setDecimals(3);
        doubleSpinBox_04_Function_f4_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_inf->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_inf, 3, 8, 1, 1);

        doubleSpinBox_04_Function_f4_nan = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_nan->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_nan"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_nan->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_nan->setWrapping(false);
        doubleSpinBox_04_Function_f4_nan->setFrame(false);
        doubleSpinBox_04_Function_f4_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_nan->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_nan->setDecimals(3);
        doubleSpinBox_04_Function_f4_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_nan->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_nan, 3, 7, 1, 1);

        doubleSpinBox_04_Function_f4_f = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_f->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_f"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_f->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_f->setWrapping(false);
        doubleSpinBox_04_Function_f4_f->setFrame(false);
        doubleSpinBox_04_Function_f4_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_f->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_f->setDecimals(3);
        doubleSpinBox_04_Function_f4_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_f->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_f, 3, 6, 1, 1);

        doubleSpinBox_04_Function_f4_e = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_e->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_e"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_e->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_e->setWrapping(false);
        doubleSpinBox_04_Function_f4_e->setFrame(false);
        doubleSpinBox_04_Function_f4_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_e->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_e->setDecimals(3);
        doubleSpinBox_04_Function_f4_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_e->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_e, 3, 5, 1, 1);

        doubleSpinBox_04_Function_f4_d = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_d->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_d"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_d->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_d->setWrapping(false);
        doubleSpinBox_04_Function_f4_d->setFrame(false);
        doubleSpinBox_04_Function_f4_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_d->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_d->setDecimals(3);
        doubleSpinBox_04_Function_f4_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_d->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_d, 3, 4, 1, 1);

        doubleSpinBox_04_Function_f4_c = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_c->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_c"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_c->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_c->setWrapping(false);
        doubleSpinBox_04_Function_f4_c->setFrame(false);
        doubleSpinBox_04_Function_f4_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_c->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_c->setDecimals(3);
        doubleSpinBox_04_Function_f4_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_c->setValue(1.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_c, 3, 3, 1, 1);

        doubleSpinBox_04_Function_f4_b = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_b->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_b"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_b->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_b->setWrapping(false);
        doubleSpinBox_04_Function_f4_b->setFrame(false);
        doubleSpinBox_04_Function_f4_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_b->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_b->setDecimals(3);
        doubleSpinBox_04_Function_f4_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_b->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_b, 3, 2, 1, 1);

        doubleSpinBox_04_Function_f4_a = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f4_a->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f4_a"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f4_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f4_a->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f4_a->setWrapping(false);
        doubleSpinBox_04_Function_f4_a->setFrame(false);
        doubleSpinBox_04_Function_f4_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f4_a->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f4_a->setDecimals(3);
        doubleSpinBox_04_Function_f4_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Function_f4_a->setValue(1.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f4_a, 3, 1, 1, 1);

        doubleSpinBox_04_Function_f2_inf = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_inf->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_inf"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_inf->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_inf->setWrapping(false);
        doubleSpinBox_04_Function_f2_inf->setFrame(false);
        doubleSpinBox_04_Function_f2_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_inf->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_inf->setDecimals(3);
        doubleSpinBox_04_Function_f2_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_inf->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_inf, 2, 8, 1, 1);

        doubleSpinBox_04_Function_f2_nan = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_nan->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_nan"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_nan->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_nan->setWrapping(false);
        doubleSpinBox_04_Function_f2_nan->setFrame(false);
        doubleSpinBox_04_Function_f2_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_nan->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_nan->setDecimals(3);
        doubleSpinBox_04_Function_f2_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_nan->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_nan, 2, 7, 1, 1);

        doubleSpinBox_04_Function_f2_f = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_f->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_f"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_f->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_f->setWrapping(false);
        doubleSpinBox_04_Function_f2_f->setFrame(false);
        doubleSpinBox_04_Function_f2_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_f->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_f->setDecimals(3);
        doubleSpinBox_04_Function_f2_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_f->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_f, 2, 6, 1, 1);

        doubleSpinBox_04_Function_f2_e = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_e->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_e"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_e->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_e->setWrapping(false);
        doubleSpinBox_04_Function_f2_e->setFrame(false);
        doubleSpinBox_04_Function_f2_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_e->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_e->setDecimals(3);
        doubleSpinBox_04_Function_f2_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_e->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_e, 2, 5, 1, 1);

        doubleSpinBox_04_Function_f2_d = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_d->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_d"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_d->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_d->setWrapping(false);
        doubleSpinBox_04_Function_f2_d->setFrame(false);
        doubleSpinBox_04_Function_f2_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_d->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_d->setDecimals(3);
        doubleSpinBox_04_Function_f2_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_d->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_d, 2, 4, 1, 1);

        doubleSpinBox_04_Function_f2_c = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_c->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_c"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_c->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_c->setWrapping(false);
        doubleSpinBox_04_Function_f2_c->setFrame(false);
        doubleSpinBox_04_Function_f2_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_c->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_c->setDecimals(3);
        doubleSpinBox_04_Function_f2_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_c->setValue(1.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_c, 2, 3, 1, 1);

        doubleSpinBox_04_Function_f2_b = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_b->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_b"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_b->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_b->setWrapping(false);
        doubleSpinBox_04_Function_f2_b->setFrame(false);
        doubleSpinBox_04_Function_f2_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_b->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_b->setDecimals(3);
        doubleSpinBox_04_Function_f2_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_b->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_b, 2, 2, 1, 1);

        doubleSpinBox_04_Function_f2_a = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f2_a->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f2_a"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f2_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f2_a->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f2_a->setWrapping(false);
        doubleSpinBox_04_Function_f2_a->setFrame(false);
        doubleSpinBox_04_Function_f2_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f2_a->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f2_a->setDecimals(3);
        doubleSpinBox_04_Function_f2_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Function_f2_a->setValue(1.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f2_a, 2, 1, 1, 1);

        doubleSpinBox_04_Function_f1_inf = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_inf->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_inf"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_inf->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_inf->setWrapping(false);
        doubleSpinBox_04_Function_f1_inf->setFrame(false);
        doubleSpinBox_04_Function_f1_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_inf->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_inf->setDecimals(3);
        doubleSpinBox_04_Function_f1_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_inf->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_inf, 1, 8, 1, 1);

        doubleSpinBox_04_Function_f1_nan = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_nan->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_nan"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_nan->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_nan->setWrapping(false);
        doubleSpinBox_04_Function_f1_nan->setFrame(false);
        doubleSpinBox_04_Function_f1_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_nan->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_nan->setDecimals(3);
        doubleSpinBox_04_Function_f1_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_nan->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_nan, 1, 7, 1, 1);

        doubleSpinBox_04_Function_f1_f = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_f->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_f"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_f->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_f->setWrapping(false);
        doubleSpinBox_04_Function_f1_f->setFrame(false);
        doubleSpinBox_04_Function_f1_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_f->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_f->setDecimals(3);
        doubleSpinBox_04_Function_f1_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_f->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_f, 1, 6, 1, 1);

        doubleSpinBox_04_Function_f1_e = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_e->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_e"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_e->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_e->setWrapping(false);
        doubleSpinBox_04_Function_f1_e->setFrame(false);
        doubleSpinBox_04_Function_f1_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_e->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_e->setDecimals(3);
        doubleSpinBox_04_Function_f1_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_e->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_e, 1, 5, 1, 1);

        doubleSpinBox_04_Function_f1_d = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_d->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_d"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_d->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_d->setWrapping(false);
        doubleSpinBox_04_Function_f1_d->setFrame(false);
        doubleSpinBox_04_Function_f1_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_d->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_d->setDecimals(3);
        doubleSpinBox_04_Function_f1_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_d->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_d, 1, 4, 1, 1);

        doubleSpinBox_04_Function_f1_c = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_c->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_c"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_c->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_c->setWrapping(false);
        doubleSpinBox_04_Function_f1_c->setFrame(false);
        doubleSpinBox_04_Function_f1_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_c->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_c->setDecimals(3);
        doubleSpinBox_04_Function_f1_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_c->setValue(1.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_c, 1, 3, 1, 1);

        doubleSpinBox_04_Function_f1_b = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_b->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_b"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_b->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_b->setWrapping(false);
        doubleSpinBox_04_Function_f1_b->setFrame(false);
        doubleSpinBox_04_Function_f1_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_b->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_b->setDecimals(3);
        doubleSpinBox_04_Function_f1_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_b->setMaximum(999999999999.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_b, 1, 2, 1, 1);

        doubleSpinBox_04_Function_f1_a = new QDoubleSpinBox(page_04_Function);
        doubleSpinBox_04_Function_f1_a->setObjectName(QString::fromUtf8("doubleSpinBox_04_Function_f1_a"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_04_Function_f1_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_04_Function_f1_a->setSizePolicy(sizePolicy6);
        doubleSpinBox_04_Function_f1_a->setWrapping(false);
        doubleSpinBox_04_Function_f1_a->setFrame(false);
        doubleSpinBox_04_Function_f1_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_04_Function_f1_a->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_04_Function_f1_a->setDecimals(3);
        doubleSpinBox_04_Function_f1_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_04_Function_f1_a->setValue(1.000000000000000);

        gridLayout_04_Function_Parameters->addWidget(doubleSpinBox_04_Function_f1_a, 1, 1, 1, 1);

        label_04_Function_inf = new QLabel(page_04_Function);
        label_04_Function_inf->setObjectName(QString::fromUtf8("label_04_Function_inf"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_04_Function_inf->sizePolicy().hasHeightForWidth());
        label_04_Function_inf->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_inf, 0, 8, 1, 1);

        label_04_Function_nan = new QLabel(page_04_Function);
        label_04_Function_nan->setObjectName(QString::fromUtf8("label_04_Function_nan"));
        sizePolicy7.setHeightForWidth(label_04_Function_nan->sizePolicy().hasHeightForWidth());
        label_04_Function_nan->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_nan, 0, 7, 1, 1);

        label_04_Function_f = new QLabel(page_04_Function);
        label_04_Function_f->setObjectName(QString::fromUtf8("label_04_Function_f"));
        sizePolicy7.setHeightForWidth(label_04_Function_f->sizePolicy().hasHeightForWidth());
        label_04_Function_f->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_f, 0, 6, 1, 1);

        label_04_Function_e = new QLabel(page_04_Function);
        label_04_Function_e->setObjectName(QString::fromUtf8("label_04_Function_e"));
        sizePolicy7.setHeightForWidth(label_04_Function_e->sizePolicy().hasHeightForWidth());
        label_04_Function_e->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_e, 0, 5, 1, 1);

        label_04_Function_d = new QLabel(page_04_Function);
        label_04_Function_d->setObjectName(QString::fromUtf8("label_04_Function_d"));
        sizePolicy7.setHeightForWidth(label_04_Function_d->sizePolicy().hasHeightForWidth());
        label_04_Function_d->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_d, 0, 4, 1, 1);

        label_04_Function_c = new QLabel(page_04_Function);
        label_04_Function_c->setObjectName(QString::fromUtf8("label_04_Function_c"));
        sizePolicy7.setHeightForWidth(label_04_Function_c->sizePolicy().hasHeightForWidth());
        label_04_Function_c->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_c, 0, 3, 1, 1);

        label_04_Function_b = new QLabel(page_04_Function);
        label_04_Function_b->setObjectName(QString::fromUtf8("label_04_Function_b"));
        sizePolicy7.setHeightForWidth(label_04_Function_b->sizePolicy().hasHeightForWidth());
        label_04_Function_b->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_b, 0, 2, 1, 1);

        label_04_Function_f4 = new QLabel(page_04_Function);
        label_04_Function_f4->setObjectName(QString::fromUtf8("label_04_Function_f4"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Ignored);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_04_Function_f4->sizePolicy().hasHeightForWidth());
        label_04_Function_f4->setSizePolicy(sizePolicy8);
        label_04_Function_f4->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_f4, 3, 0, 1, 1);

        label_04_Function_f2 = new QLabel(page_04_Function);
        label_04_Function_f2->setObjectName(QString::fromUtf8("label_04_Function_f2"));
        sizePolicy8.setHeightForWidth(label_04_Function_f2->sizePolicy().hasHeightForWidth());
        label_04_Function_f2->setSizePolicy(sizePolicy8);
        label_04_Function_f2->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_f2, 2, 0, 1, 1);

        label_04_Function_f1 = new QLabel(page_04_Function);
        label_04_Function_f1->setObjectName(QString::fromUtf8("label_04_Function_f1"));
        sizePolicy8.setHeightForWidth(label_04_Function_f1->sizePolicy().hasHeightForWidth());
        label_04_Function_f1->setSizePolicy(sizePolicy8);
        label_04_Function_f1->setMinimumSize(QSize(20, 0));

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_f1, 1, 0, 1, 1);

        label_04_Function_a = new QLabel(page_04_Function);
        label_04_Function_a->setObjectName(QString::fromUtf8("label_04_Function_a"));
        sizePolicy7.setHeightForWidth(label_04_Function_a->sizePolicy().hasHeightForWidth());
        label_04_Function_a->setSizePolicy(sizePolicy7);

        gridLayout_04_Function_Parameters->addWidget(label_04_Function_a, 0, 1, 1, 1);


        gridLayout_80->addLayout(gridLayout_04_Function_Parameters, 1, 1, 1, 1);

        line_04_Function = new QFrame(page_04_Function);
        line_04_Function->setObjectName(QString::fromUtf8("line_04_Function"));
        line_04_Function->setFrameShape(QFrame::VLine);
        line_04_Function->setFrameShadow(QFrame::Sunken);

        gridLayout_80->addWidget(line_04_Function, 0, 0, 2, 1);

        stackedWidget_Settings_04_Filter->addWidget(page_04_Function);
        page_04_RankOrder = new QWidget();
        page_04_RankOrder->setObjectName(QString::fromUtf8("page_04_RankOrder"));
        gridLayout_122 = new QGridLayout(page_04_RankOrder);
        gridLayout_122->setObjectName(QString::fromUtf8("gridLayout_122"));
        label_04_RankOrder_MaskType = new QLabel(page_04_RankOrder);
        label_04_RankOrder_MaskType->setObjectName(QString::fromUtf8("label_04_RankOrder_MaskType"));
        label_04_RankOrder_MaskType->setMinimumSize(QSize(75, 0));
        label_04_RankOrder_MaskType->setMaximumSize(QSize(75, 16777215));

        gridLayout_122->addWidget(label_04_RankOrder_MaskType, 0, 0, 1, 1);

        comboBox_04_RankOrder_MaskType = new QComboBox(page_04_RankOrder);
        comboBox_04_RankOrder_MaskType->setObjectName(QString::fromUtf8("comboBox_04_RankOrder_MaskType"));
        comboBox_04_RankOrder_MaskType->setMinimumSize(QSize(100, 0));
        comboBox_04_RankOrder_MaskType->setMaximumSize(QSize(100, 16777215));

        gridLayout_122->addWidget(comboBox_04_RankOrder_MaskType, 0, 1, 1, 2);

        label_04_RankOrder_Stat = new QLabel(page_04_RankOrder);
        label_04_RankOrder_Stat->setObjectName(QString::fromUtf8("label_04_RankOrder_Stat"));
        label_04_RankOrder_Stat->setMinimumSize(QSize(75, 0));
        label_04_RankOrder_Stat->setMaximumSize(QSize(75, 16777215));

        gridLayout_122->addWidget(label_04_RankOrder_Stat, 1, 0, 1, 1);

        doubleSpinBox_04_RankOrder_Quantil = new QDoubleSpinBox(page_04_RankOrder);
        doubleSpinBox_04_RankOrder_Quantil->setObjectName(QString::fromUtf8("doubleSpinBox_04_RankOrder_Quantil"));
        doubleSpinBox_04_RankOrder_Quantil->setMinimumSize(QSize(100, 0));
        doubleSpinBox_04_RankOrder_Quantil->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_RankOrder_Quantil->setDecimals(2);
        doubleSpinBox_04_RankOrder_Quantil->setMaximum(100.000000000000000);
        doubleSpinBox_04_RankOrder_Quantil->setValue(50.000000000000000);

        gridLayout_122->addWidget(doubleSpinBox_04_RankOrder_Quantil, 1, 1, 1, 2);

        horizontalSlider_04_RankOrder_Quantil = new QSlider(page_04_RankOrder);
        horizontalSlider_04_RankOrder_Quantil->setObjectName(QString::fromUtf8("horizontalSlider_04_RankOrder_Quantil"));
        horizontalSlider_04_RankOrder_Quantil->setMaximum(10000);
        horizontalSlider_04_RankOrder_Quantil->setValue(5000);
        horizontalSlider_04_RankOrder_Quantil->setOrientation(Qt::Horizontal);
        horizontalSlider_04_RankOrder_Quantil->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_04_RankOrder_Quantil->setTickInterval(1000);

        gridLayout_122->addWidget(horizontalSlider_04_RankOrder_Quantil, 1, 3, 1, 1);

        label_04_RankOrder_Radius = new QLabel(page_04_RankOrder);
        label_04_RankOrder_Radius->setObjectName(QString::fromUtf8("label_04_RankOrder_Radius"));
        label_04_RankOrder_Radius->setMinimumSize(QSize(75, 0));
        label_04_RankOrder_Radius->setMaximumSize(QSize(75, 16777215));

        gridLayout_122->addWidget(label_04_RankOrder_Radius, 2, 0, 1, 1);

        doubleSpinBox_04_RankOrder_Radius = new QDoubleSpinBox(page_04_RankOrder);
        doubleSpinBox_04_RankOrder_Radius->setObjectName(QString::fromUtf8("doubleSpinBox_04_RankOrder_Radius"));
        doubleSpinBox_04_RankOrder_Radius->setMinimumSize(QSize(100, 0));
        doubleSpinBox_04_RankOrder_Radius->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_RankOrder_Radius->setMinimum(0.500000000000000);
        doubleSpinBox_04_RankOrder_Radius->setMaximum(9999.000000000000000);
        doubleSpinBox_04_RankOrder_Radius->setValue(1.000000000000000);

        gridLayout_122->addWidget(doubleSpinBox_04_RankOrder_Radius, 2, 1, 1, 2);

        label_04_RankOrder_Size = new QLabel(page_04_RankOrder);
        label_04_RankOrder_Size->setObjectName(QString::fromUtf8("label_04_RankOrder_Size"));
        label_04_RankOrder_Size->setEnabled(false);
        label_04_RankOrder_Size->setMinimumSize(QSize(75, 0));
        label_04_RankOrder_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_122->addWidget(label_04_RankOrder_Size, 3, 0, 1, 1);

        spinBox_04_RankOrder_Size_x = new QSpinBox(page_04_RankOrder);
        spinBox_04_RankOrder_Size_x->setObjectName(QString::fromUtf8("spinBox_04_RankOrder_Size_x"));
        spinBox_04_RankOrder_Size_x->setEnabled(false);
        spinBox_04_RankOrder_Size_x->setMinimumSize(QSize(46, 0));
        spinBox_04_RankOrder_Size_x->setMaximumSize(QSize(46, 16777215));
        spinBox_04_RankOrder_Size_x->setMinimum(1);
        spinBox_04_RankOrder_Size_x->setMaximum(999);
        spinBox_04_RankOrder_Size_x->setSingleStep(2);
        spinBox_04_RankOrder_Size_x->setValue(3);

        gridLayout_122->addWidget(spinBox_04_RankOrder_Size_x, 3, 1, 1, 1);

        spinBox_04_RankOrder_Size_y = new QSpinBox(page_04_RankOrder);
        spinBox_04_RankOrder_Size_y->setObjectName(QString::fromUtf8("spinBox_04_RankOrder_Size_y"));
        spinBox_04_RankOrder_Size_y->setEnabled(false);
        spinBox_04_RankOrder_Size_y->setMinimumSize(QSize(46, 0));
        spinBox_04_RankOrder_Size_y->setMaximumSize(QSize(46, 16777215));
        spinBox_04_RankOrder_Size_y->setMinimum(1);
        spinBox_04_RankOrder_Size_y->setMaximum(999);
        spinBox_04_RankOrder_Size_y->setSingleStep(2);
        spinBox_04_RankOrder_Size_y->setValue(3);

        gridLayout_122->addWidget(spinBox_04_RankOrder_Size_y, 3, 2, 1, 1);

        verticalSpacer_04_RankOrder = new QSpacerItem(150, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_122->addItem(verticalSpacer_04_RankOrder, 4, 3, 1, 1);

        horizontalSpacer_04_RankOrder = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_122->addItem(horizontalSpacer_04_RankOrder, 0, 3, 1, 1);

        stackedWidget_Settings_04_Filter->addWidget(page_04_RankOrder);
        page_04_Statistic = new QWidget();
        page_04_Statistic->setObjectName(QString::fromUtf8("page_04_Statistic"));
        gridLayout_121 = new QGridLayout(page_04_Statistic);
        gridLayout_121->setObjectName(QString::fromUtf8("gridLayout_121"));
        verticalSpacer_04_Statistic = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_121->addItem(verticalSpacer_04_Statistic, 4, 4, 1, 1);

        label_04_Statistic_Stat = new QLabel(page_04_Statistic);
        label_04_Statistic_Stat->setObjectName(QString::fromUtf8("label_04_Statistic_Stat"));
        label_04_Statistic_Stat->setMinimumSize(QSize(75, 0));
        label_04_Statistic_Stat->setMaximumSize(QSize(75, 16777215));

        gridLayout_121->addWidget(label_04_Statistic_Stat, 1, 0, 1, 1);

        label_04_Statistic_MaskType = new QLabel(page_04_Statistic);
        label_04_Statistic_MaskType->setObjectName(QString::fromUtf8("label_04_Statistic_MaskType"));
        label_04_Statistic_MaskType->setMinimumSize(QSize(75, 0));
        label_04_Statistic_MaskType->setMaximumSize(QSize(75, 16777215));

        gridLayout_121->addWidget(label_04_Statistic_MaskType, 0, 0, 1, 1);

        spinBox_04_Statistic_Size_x = new QSpinBox(page_04_Statistic);
        spinBox_04_Statistic_Size_x->setObjectName(QString::fromUtf8("spinBox_04_Statistic_Size_x"));
        spinBox_04_Statistic_Size_x->setEnabled(false);
        spinBox_04_Statistic_Size_x->setMinimumSize(QSize(46, 0));
        spinBox_04_Statistic_Size_x->setMaximumSize(QSize(46, 16777215));
        spinBox_04_Statistic_Size_x->setMinimum(1);
        spinBox_04_Statistic_Size_x->setMaximum(999);
        spinBox_04_Statistic_Size_x->setSingleStep(2);
        spinBox_04_Statistic_Size_x->setValue(3);

        gridLayout_121->addWidget(spinBox_04_Statistic_Size_x, 3, 1, 1, 1);

        label_04_Statistic_Radius = new QLabel(page_04_Statistic);
        label_04_Statistic_Radius->setObjectName(QString::fromUtf8("label_04_Statistic_Radius"));
        label_04_Statistic_Radius->setMinimumSize(QSize(75, 0));
        label_04_Statistic_Radius->setMaximumSize(QSize(75, 16777215));

        gridLayout_121->addWidget(label_04_Statistic_Radius, 2, 0, 1, 1);

        spinBox_04_Statistic_Size_y = new QSpinBox(page_04_Statistic);
        spinBox_04_Statistic_Size_y->setObjectName(QString::fromUtf8("spinBox_04_Statistic_Size_y"));
        spinBox_04_Statistic_Size_y->setEnabled(false);
        spinBox_04_Statistic_Size_y->setMinimumSize(QSize(46, 0));
        spinBox_04_Statistic_Size_y->setMaximumSize(QSize(46, 16777215));
        spinBox_04_Statistic_Size_y->setMinimum(1);
        spinBox_04_Statistic_Size_y->setMaximum(999);
        spinBox_04_Statistic_Size_y->setSingleStep(2);
        spinBox_04_Statistic_Size_y->setValue(3);

        gridLayout_121->addWidget(spinBox_04_Statistic_Size_y, 3, 2, 1, 1);

        label_04_Statistic_Size = new QLabel(page_04_Statistic);
        label_04_Statistic_Size->setObjectName(QString::fromUtf8("label_04_Statistic_Size"));
        label_04_Statistic_Size->setEnabled(false);
        label_04_Statistic_Size->setMinimumSize(QSize(75, 0));
        label_04_Statistic_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_121->addWidget(label_04_Statistic_Size, 3, 0, 1, 1);

        comboBox_04_Statistic_MaskType = new QComboBox(page_04_Statistic);
        comboBox_04_Statistic_MaskType->setObjectName(QString::fromUtf8("comboBox_04_Statistic_MaskType"));
        comboBox_04_Statistic_MaskType->setMinimumSize(QSize(200, 0));
        comboBox_04_Statistic_MaskType->setMaximumSize(QSize(200, 16777215));

        gridLayout_121->addWidget(comboBox_04_Statistic_MaskType, 0, 1, 1, 3);

        comboBox_04_Statistic_Stat = new QComboBox(page_04_Statistic);
        comboBox_04_Statistic_Stat->setObjectName(QString::fromUtf8("comboBox_04_Statistic_Stat"));
        comboBox_04_Statistic_Stat->setMinimumSize(QSize(200, 0));
        comboBox_04_Statistic_Stat->setMaximumSize(QSize(200, 16777215));

        gridLayout_121->addWidget(comboBox_04_Statistic_Stat, 1, 1, 1, 3);

        horizontalSpacer_04_Statistic = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_121->addItem(horizontalSpacer_04_Statistic, 0, 4, 3, 1);

        doubleSpinBox_04_Statistic_Radius = new QDoubleSpinBox(page_04_Statistic);
        doubleSpinBox_04_Statistic_Radius->setObjectName(QString::fromUtf8("doubleSpinBox_04_Statistic_Radius"));
        doubleSpinBox_04_Statistic_Radius->setMinimumSize(QSize(100, 0));
        doubleSpinBox_04_Statistic_Radius->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_04_Statistic_Radius->setMaximum(99.000000000000000);
        doubleSpinBox_04_Statistic_Radius->setValue(1.000000000000000);

        gridLayout_121->addWidget(doubleSpinBox_04_Statistic_Radius, 2, 1, 1, 2);

        stackedWidget_Settings_04_Filter->addWidget(page_04_Statistic);

        gridLayout_21->addWidget(stackedWidget_Settings_04_Filter, 1, 0, 1, 5);

        label_04_Border_Type = new QLabel(page_Settings_04_Filter);
        label_04_Border_Type->setObjectName(QString::fromUtf8("label_04_Border_Type"));
        label_04_Border_Type->setMinimumSize(QSize(100, 0));
        label_04_Border_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(label_04_Border_Type, 0, 0, 1, 1);

        comboBox_04_Border_Type = new QComboBox(page_Settings_04_Filter);
        comboBox_04_Border_Type->addItem(QString());
        comboBox_04_Border_Type->addItem(QString());
        comboBox_04_Border_Type->addItem(QString());
        comboBox_04_Border_Type->addItem(QString());
        comboBox_04_Border_Type->addItem(QString());
        comboBox_04_Border_Type->setObjectName(QString::fromUtf8("comboBox_04_Border_Type"));
        comboBox_04_Border_Type->setMinimumSize(QSize(100, 0));
        comboBox_04_Border_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(comboBox_04_Border_Type, 0, 1, 1, 1);

        horizontalSpacer_04 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_04, 0, 4, 1, 1);

        checkBox_04_Force_8bit = new QCheckBox(page_Settings_04_Filter);
        checkBox_04_Force_8bit->setObjectName(QString::fromUtf8("checkBox_04_Force_8bit"));
        checkBox_04_Force_8bit->setEnabled(false);

        gridLayout_21->addWidget(checkBox_04_Force_8bit, 0, 3, 1, 1);

        horizontalSpacer_04_2 = new QSpacerItem(11, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_04_2, 0, 2, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_04_Filter);
        page_Settings_05_Morphology = new QWidget();
        page_Settings_05_Morphology->setObjectName(QString::fromUtf8("page_Settings_05_Morphology"));
        gridLayout_22 = new QGridLayout(page_Settings_05_Morphology);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_05_Morphology = new QStackedWidget(page_Settings_05_Morphology);
        stackedWidget_Settings_05_Morphology->setObjectName(QString::fromUtf8("stackedWidget_Settings_05_Morphology"));
        page_05_Elemental = new QWidget();
        page_05_Elemental->setObjectName(QString::fromUtf8("page_05_Elemental"));
        gridLayout_32 = new QGridLayout(page_05_Elemental);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        label_05_Elem_Border_Type = new QLabel(page_05_Elemental);
        label_05_Elem_Border_Type->setObjectName(QString::fromUtf8("label_05_Elem_Border_Type"));
        label_05_Elem_Border_Type->setMinimumSize(QSize(75, 0));
        label_05_Elem_Border_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_32->addWidget(label_05_Elem_Border_Type, 4, 2, 1, 1);

        label_05_Elem_Morph_Type = new QLabel(page_05_Elemental);
        label_05_Elem_Morph_Type->setObjectName(QString::fromUtf8("label_05_Elem_Morph_Type"));
        label_05_Elem_Morph_Type->setMinimumSize(QSize(75, 0));
        label_05_Elem_Morph_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_32->addWidget(label_05_Elem_Morph_Type, 0, 2, 1, 1);

        comboBox_05_Elem_Elem_Type = new QComboBox(page_05_Elemental);
        comboBox_05_Elem_Elem_Type->addItem(QString());
        comboBox_05_Elem_Elem_Type->addItem(QString());
        comboBox_05_Elem_Elem_Type->addItem(QString());
        comboBox_05_Elem_Elem_Type->setObjectName(QString::fromUtf8("comboBox_05_Elem_Elem_Type"));
        comboBox_05_Elem_Elem_Type->setMinimumSize(QSize(0, 0));
        comboBox_05_Elem_Elem_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_32->addWidget(comboBox_05_Elem_Elem_Type, 1, 3, 1, 2);

        line_05_Elem = new QFrame(page_05_Elemental);
        line_05_Elem->setObjectName(QString::fromUtf8("line_05_Elem"));
        line_05_Elem->setFrameShape(QFrame::VLine);
        line_05_Elem->setFrameShadow(QFrame::Sunken);

        gridLayout_32->addWidget(line_05_Elem, 0, 0, 6, 1);

        label_05_Elem_Elem_Type = new QLabel(page_05_Elemental);
        label_05_Elem_Elem_Type->setObjectName(QString::fromUtf8("label_05_Elem_Elem_Type"));
        label_05_Elem_Elem_Type->setMinimumSize(QSize(75, 0));
        label_05_Elem_Elem_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_32->addWidget(label_05_Elem_Elem_Type, 1, 2, 1, 1);

        horizontalSpacer_05_Elem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_32->addItem(horizontalSpacer_05_Elem, 0, 5, 5, 1);

        label_05_Elem_Elem_Size = new QLabel(page_05_Elemental);
        label_05_Elem_Elem_Size->setObjectName(QString::fromUtf8("label_05_Elem_Elem_Size"));
        label_05_Elem_Elem_Size->setMinimumSize(QSize(75, 0));
        label_05_Elem_Elem_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_32->addWidget(label_05_Elem_Elem_Size, 2, 2, 1, 1);

        comboBox_05_Elem_Morph_Type = new QComboBox(page_05_Elemental);
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->addItem(QString());
        comboBox_05_Elem_Morph_Type->setObjectName(QString::fromUtf8("comboBox_05_Elem_Morph_Type"));
        comboBox_05_Elem_Morph_Type->setMinimumSize(QSize(100, 0));
        comboBox_05_Elem_Morph_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_32->addWidget(comboBox_05_Elem_Morph_Type, 0, 3, 1, 2);

        spinBox_05_Elem_Elem_Size_X = new QSpinBox(page_05_Elemental);
        spinBox_05_Elem_Elem_Size_X->setObjectName(QString::fromUtf8("spinBox_05_Elem_Elem_Size_X"));
        spinBox_05_Elem_Elem_Size_X->setMinimumSize(QSize(0, 0));
        spinBox_05_Elem_Elem_Size_X->setMaximumSize(QSize(47, 16777215));
        spinBox_05_Elem_Elem_Size_X->setMinimum(1);
        spinBox_05_Elem_Elem_Size_X->setMaximum(1000003);
        spinBox_05_Elem_Elem_Size_X->setSingleStep(2);

        gridLayout_32->addWidget(spinBox_05_Elem_Elem_Size_X, 2, 3, 1, 1);

        spinBox_05_Elem_Elem_Size_Y = new QSpinBox(page_05_Elemental);
        spinBox_05_Elem_Elem_Size_Y->setObjectName(QString::fromUtf8("spinBox_05_Elem_Elem_Size_Y"));
        spinBox_05_Elem_Elem_Size_Y->setMinimumSize(QSize(0, 0));
        spinBox_05_Elem_Elem_Size_Y->setMaximumSize(QSize(47, 16777215));
        spinBox_05_Elem_Elem_Size_Y->setMinimum(1);
        spinBox_05_Elem_Elem_Size_Y->setMaximum(1000003);
        spinBox_05_Elem_Elem_Size_Y->setSingleStep(2);

        gridLayout_32->addWidget(spinBox_05_Elem_Elem_Size_Y, 2, 4, 1, 1);

        comboBox_05_Elem_Border_Type = new QComboBox(page_05_Elemental);
        comboBox_05_Elem_Border_Type->addItem(QString());
        comboBox_05_Elem_Border_Type->addItem(QString());
        comboBox_05_Elem_Border_Type->addItem(QString());
        comboBox_05_Elem_Border_Type->addItem(QString());
        comboBox_05_Elem_Border_Type->addItem(QString());
        comboBox_05_Elem_Border_Type->setObjectName(QString::fromUtf8("comboBox_05_Elem_Border_Type"));
        comboBox_05_Elem_Border_Type->setMinimumSize(QSize(0, 0));
        comboBox_05_Elem_Border_Type->setMaximumSize(QSize(100, 16777215));

        gridLayout_32->addWidget(comboBox_05_Elem_Border_Type, 4, 3, 1, 2);

        label_05_Elem_Iterations = new QLabel(page_05_Elemental);
        label_05_Elem_Iterations->setObjectName(QString::fromUtf8("label_05_Elem_Iterations"));

        gridLayout_32->addWidget(label_05_Elem_Iterations, 3, 2, 1, 1);

        spinBox_05_Elem_Iterations = new QSpinBox(page_05_Elemental);
        spinBox_05_Elem_Iterations->setObjectName(QString::fromUtf8("spinBox_05_Elem_Iterations"));
        spinBox_05_Elem_Iterations->setMinimumSize(QSize(0, 0));
        spinBox_05_Elem_Iterations->setMaximumSize(QSize(100, 16777215));
        spinBox_05_Elem_Iterations->setMinimum(1);
        spinBox_05_Elem_Iterations->setMaximum(100000);

        gridLayout_32->addWidget(spinBox_05_Elem_Iterations, 3, 3, 1, 2);

        verticalSpacer_05_Elem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_32->addItem(verticalSpacer_05_Elem, 5, 2, 1, 4);

        stackedWidget_Settings_05_Morphology->addWidget(page_05_Elemental);
        page_05_MinMaxGil = new QWidget();
        page_05_MinMaxGil->setObjectName(QString::fromUtf8("page_05_MinMaxGil"));
        gridLayout_123 = new QGridLayout(page_05_MinMaxGil);
        gridLayout_123->setObjectName(QString::fromUtf8("gridLayout_123"));
        verticalSpacer_05_MinMaxGil = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_123->addItem(verticalSpacer_05_MinMaxGil, 2, 2, 1, 1);

        comboBox_05_MinMaxGil_MinMax = new QComboBox(page_05_MinMaxGil);
        comboBox_05_MinMaxGil_MinMax->addItem(QString());
        comboBox_05_MinMaxGil_MinMax->addItem(QString());
        comboBox_05_MinMaxGil_MinMax->setObjectName(QString::fromUtf8("comboBox_05_MinMaxGil_MinMax"));
        comboBox_05_MinMaxGil_MinMax->setEnabled(false);
        comboBox_05_MinMaxGil_MinMax->setMinimumSize(QSize(100, 0));
        comboBox_05_MinMaxGil_MinMax->setMaximumSize(QSize(100, 16777215));

        gridLayout_123->addWidget(comboBox_05_MinMaxGil_MinMax, 0, 1, 1, 2);

        spinBox_05_MinMaxGil_SizeX = new QSpinBox(page_05_MinMaxGil);
        spinBox_05_MinMaxGil_SizeX->setObjectName(QString::fromUtf8("spinBox_05_MinMaxGil_SizeX"));
        spinBox_05_MinMaxGil_SizeX->setMinimumSize(QSize(47, 0));
        spinBox_05_MinMaxGil_SizeX->setMaximumSize(QSize(47, 16777215));
        spinBox_05_MinMaxGil_SizeX->setMinimum(1);
        spinBox_05_MinMaxGil_SizeX->setMaximum(999);
        spinBox_05_MinMaxGil_SizeX->setSingleStep(2);
        spinBox_05_MinMaxGil_SizeX->setValue(3);

        gridLayout_123->addWidget(spinBox_05_MinMaxGil_SizeX, 1, 1, 1, 1);

        spinBox_05_MinMaxGil_SizeY = new QSpinBox(page_05_MinMaxGil);
        spinBox_05_MinMaxGil_SizeY->setObjectName(QString::fromUtf8("spinBox_05_MinMaxGil_SizeY"));
        spinBox_05_MinMaxGil_SizeY->setMinimumSize(QSize(47, 0));
        spinBox_05_MinMaxGil_SizeY->setMaximumSize(QSize(47, 16777215));
        spinBox_05_MinMaxGil_SizeY->setMinimum(1);
        spinBox_05_MinMaxGil_SizeY->setMaximum(999);
        spinBox_05_MinMaxGil_SizeY->setSingleStep(2);
        spinBox_05_MinMaxGil_SizeY->setValue(3);

        gridLayout_123->addWidget(spinBox_05_MinMaxGil_SizeY, 1, 2, 1, 1);

        label_05_MinMaxGil_MinMax = new QLabel(page_05_MinMaxGil);
        label_05_MinMaxGil_MinMax->setObjectName(QString::fromUtf8("label_05_MinMaxGil_MinMax"));
        label_05_MinMaxGil_MinMax->setMinimumSize(QSize(75, 0));
        label_05_MinMaxGil_MinMax->setMaximumSize(QSize(75, 16777215));

        gridLayout_123->addWidget(label_05_MinMaxGil_MinMax, 0, 0, 1, 1);

        label_05_MinMaxGil_Size = new QLabel(page_05_MinMaxGil);
        label_05_MinMaxGil_Size->setObjectName(QString::fromUtf8("label_05_MinMaxGil_Size"));
        label_05_MinMaxGil_Size->setMinimumSize(QSize(75, 0));
        label_05_MinMaxGil_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_123->addWidget(label_05_MinMaxGil_Size, 1, 0, 1, 1);

        horizontalSpacer_05_MinMaxGil = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_123->addItem(horizontalSpacer_05_MinMaxGil, 1, 3, 1, 1);

        stackedWidget_Settings_05_Morphology->addWidget(page_05_MinMaxGil);
        page_05_Reconstruction = new QWidget();
        page_05_Reconstruction->setObjectName(QString::fromUtf8("page_05_Reconstruction"));
        gridLayout_124 = new QGridLayout(page_05_Reconstruction);
        gridLayout_124->setObjectName(QString::fromUtf8("gridLayout_124"));
        label_05_Reconstruction_Limit_Header = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Limit_Header->setObjectName(QString::fromUtf8("label_05_Reconstruction_Limit_Header"));
        label_05_Reconstruction_Limit_Header->setMinimumSize(QSize(75, 0));
        label_05_Reconstruction_Limit_Header->setMaximumSize(QSize(75, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Limit_Header, 1, 0, 1, 1);

        label_05_Reconstruction_Elem_Header = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Elem_Header->setObjectName(QString::fromUtf8("label_05_Reconstruction_Elem_Header"));
        label_05_Reconstruction_Elem_Header->setMinimumSize(QSize(75, 0));
        label_05_Reconstruction_Elem_Header->setMaximumSize(QSize(75, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Elem_Header, 2, 0, 1, 1);

        label_05_Reconstruction_Limit_Source = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Limit_Source->setObjectName(QString::fromUtf8("label_05_Reconstruction_Limit_Source"));
        label_05_Reconstruction_Limit_Source->setMinimumSize(QSize(100, 0));
        label_05_Reconstruction_Limit_Source->setMaximumSize(QSize(100, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Limit_Source, 1, 1, 1, 1);

        verticalSpacer_05_Reconstruction = new QSpacerItem(416, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_124->addItem(verticalSpacer_05_Reconstruction, 4, 0, 1, 3);

        label_05_Reconstruction_Elem_Source = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Elem_Source->setObjectName(QString::fromUtf8("label_05_Reconstruction_Elem_Source"));
        label_05_Reconstruction_Elem_Source->setMinimumSize(QSize(100, 0));
        label_05_Reconstruction_Elem_Source->setMaximumSize(QSize(100, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Elem_Source, 2, 1, 1, 1);

        label_05_Reconstruction_Seed_Source = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Seed_Source->setObjectName(QString::fromUtf8("label_05_Reconstruction_Seed_Source"));
        label_05_Reconstruction_Seed_Source->setMinimumSize(QSize(100, 0));
        label_05_Reconstruction_Seed_Source->setMaximumSize(QSize(100, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Seed_Source, 0, 1, 1, 1);

        label_05_Reconstruction_Seed_Header = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Seed_Header->setObjectName(QString::fromUtf8("label_05_Reconstruction_Seed_Header"));
        label_05_Reconstruction_Seed_Header->setMinimumSize(QSize(75, 0));
        label_05_Reconstruction_Seed_Header->setMaximumSize(QSize(75, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Seed_Header, 0, 0, 1, 1);

        label_05_Reconstruction_Quantil = new QLabel(page_05_Reconstruction);
        label_05_Reconstruction_Quantil->setObjectName(QString::fromUtf8("label_05_Reconstruction_Quantil"));
        label_05_Reconstruction_Quantil->setMinimumSize(QSize(75, 0));
        label_05_Reconstruction_Quantil->setMaximumSize(QSize(75, 16777215));

        gridLayout_124->addWidget(label_05_Reconstruction_Quantil, 3, 0, 1, 1);

        doubleSpinBox_05_Reconstruction_Quantil = new QDoubleSpinBox(page_05_Reconstruction);
        doubleSpinBox_05_Reconstruction_Quantil->setObjectName(QString::fromUtf8("doubleSpinBox_05_Reconstruction_Quantil"));
        doubleSpinBox_05_Reconstruction_Quantil->setMinimumSize(QSize(100, 0));
        doubleSpinBox_05_Reconstruction_Quantil->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_05_Reconstruction_Quantil->setMaximum(100.000000000000000);
        doubleSpinBox_05_Reconstruction_Quantil->setValue(100.000000000000000);

        gridLayout_124->addWidget(doubleSpinBox_05_Reconstruction_Quantil, 3, 1, 1, 1);

        horizontalSpacer_05_Reconstruction = new QSpacerItem(229, 74, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_124->addItem(horizontalSpacer_05_Reconstruction, 0, 2, 4, 1);

        stackedWidget_Settings_05_Morphology->addWidget(page_05_Reconstruction);
        page_05_LocalMaxima = new QWidget();
        page_05_LocalMaxima->setObjectName(QString::fromUtf8("page_05_LocalMaxima"));
        gridLayout_98 = new QGridLayout(page_05_LocalMaxima);
        gridLayout_98->setObjectName(QString::fromUtf8("gridLayout_98"));
        line_05_LocalMaxima = new QFrame(page_05_LocalMaxima);
        line_05_LocalMaxima->setObjectName(QString::fromUtf8("line_05_LocalMaxima"));
        line_05_LocalMaxima->setFrameShape(QFrame::VLine);
        line_05_LocalMaxima->setFrameShadow(QFrame::Sunken);

        gridLayout_98->addWidget(line_05_LocalMaxima, 0, 0, 2, 1);

        horizontalSpacer_05_LocalMaxima = new QSpacerItem(206, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_98->addItem(horizontalSpacer_05_LocalMaxima, 0, 4, 1, 1);

        label_05_LocalMaxima_Size = new QLabel(page_05_LocalMaxima);
        label_05_LocalMaxima_Size->setObjectName(QString::fromUtf8("label_05_LocalMaxima_Size"));
        label_05_LocalMaxima_Size->setMinimumSize(QSize(75, 0));
        label_05_LocalMaxima_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_98->addWidget(label_05_LocalMaxima_Size, 0, 1, 1, 1);

        verticalSpacer_05_LocalMaxima = new QSpacerItem(20, 182, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_98->addItem(verticalSpacer_05_LocalMaxima, 1, 1, 1, 1);

        spinBox_05_LocalMaxima_Size_X = new QSpinBox(page_05_LocalMaxima);
        spinBox_05_LocalMaxima_Size_X->setObjectName(QString::fromUtf8("spinBox_05_LocalMaxima_Size_X"));
        spinBox_05_LocalMaxima_Size_X->setMinimumSize(QSize(47, 0));
        spinBox_05_LocalMaxima_Size_X->setMaximumSize(QSize(47, 16777215));
        spinBox_05_LocalMaxima_Size_X->setMinimum(1);
        spinBox_05_LocalMaxima_Size_X->setMaximum(999);
        spinBox_05_LocalMaxima_Size_X->setSingleStep(2);
        spinBox_05_LocalMaxima_Size_X->setValue(3);

        gridLayout_98->addWidget(spinBox_05_LocalMaxima_Size_X, 0, 2, 1, 1);

        spinBox_05_LocalMaxima_Size_Y = new QSpinBox(page_05_LocalMaxima);
        spinBox_05_LocalMaxima_Size_Y->setObjectName(QString::fromUtf8("spinBox_05_LocalMaxima_Size_Y"));
        spinBox_05_LocalMaxima_Size_Y->setMinimumSize(QSize(47, 0));
        spinBox_05_LocalMaxima_Size_Y->setMaximumSize(QSize(47, 16777215));
        spinBox_05_LocalMaxima_Size_Y->setMinimum(1);
        spinBox_05_LocalMaxima_Size_Y->setMaximum(999);
        spinBox_05_LocalMaxima_Size_Y->setSingleStep(2);
        spinBox_05_LocalMaxima_Size_Y->setValue(3);

        gridLayout_98->addWidget(spinBox_05_LocalMaxima_Size_Y, 0, 3, 1, 1);

        stackedWidget_Settings_05_Morphology->addWidget(page_05_LocalMaxima);

        gridLayout_22->addWidget(stackedWidget_Settings_05_Morphology, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_05_Morphology);
        page_Settings_06_Math = new QWidget();
        page_Settings_06_Math->setObjectName(QString::fromUtf8("page_Settings_06_Math"));
        gridLayout_23 = new QGridLayout(page_Settings_06_Math);
        gridLayout_23->setSpacing(0);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_06_Math = new QStackedWidget(page_Settings_06_Math);
        stackedWidget_Settings_06_Math->setObjectName(QString::fromUtf8("stackedWidget_Settings_06_Math"));
        page_06_1Img = new QWidget();
        page_06_1Img->setObjectName(QString::fromUtf8("page_06_1Img"));
        gridLayout_42 = new QGridLayout(page_06_1Img);
        gridLayout_42->setObjectName(QString::fromUtf8("gridLayout_42"));
        verticalSpacer_06_1Img = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_42->addItem(verticalSpacer_06_1Img, 2, 1, 1, 1);

        horizontalSpacer_06_1Img = new QSpacerItem(368, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_42->addItem(horizontalSpacer_06_1Img, 0, 3, 1, 1);

        line_06_1Img = new QFrame(page_06_1Img);
        line_06_1Img->setObjectName(QString::fromUtf8("line_06_1Img"));
        line_06_1Img->setFrameShape(QFrame::VLine);
        line_06_1Img->setFrameShadow(QFrame::Sunken);

        gridLayout_42->addWidget(line_06_1Img, 0, 0, 3, 1);

        label_06_1Img_Type = new QLabel(page_06_1Img);
        label_06_1Img_Type->setObjectName(QString::fromUtf8("label_06_1Img_Type"));
        label_06_1Img_Type->setMinimumSize(QSize(75, 0));
        label_06_1Img_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_42->addWidget(label_06_1Img_Type, 0, 1, 1, 1);

        comboBox_06_1Img_Type = new QComboBox(page_06_1Img);
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->addItem(QString());
        comboBox_06_1Img_Type->setObjectName(QString::fromUtf8("comboBox_06_1Img_Type"));
        comboBox_06_1Img_Type->setMinimumSize(QSize(150, 0));
        comboBox_06_1Img_Type->setMaximumSize(QSize(150, 16777215));

        gridLayout_42->addWidget(comboBox_06_1Img_Type, 0, 2, 1, 1);

        doubleSpinBox_06_1Img_Arg = new QDoubleSpinBox(page_06_1Img);
        doubleSpinBox_06_1Img_Arg->setObjectName(QString::fromUtf8("doubleSpinBox_06_1Img_Arg"));
        doubleSpinBox_06_1Img_Arg->setEnabled(false);
        doubleSpinBox_06_1Img_Arg->setMinimumSize(QSize(150, 0));
        doubleSpinBox_06_1Img_Arg->setMaximumSize(QSize(150, 16777215));
        doubleSpinBox_06_1Img_Arg->setDecimals(6);
        doubleSpinBox_06_1Img_Arg->setMinimum(-2147483648.000000000000000);
        doubleSpinBox_06_1Img_Arg->setMaximum(2147483647.000000000000000);
        doubleSpinBox_06_1Img_Arg->setValue(1.000000000000000);

        gridLayout_42->addWidget(doubleSpinBox_06_1Img_Arg, 1, 2, 1, 1);

        label_06_1Img_Arg = new QLabel(page_06_1Img);
        label_06_1Img_Arg->setObjectName(QString::fromUtf8("label_06_1Img_Arg"));
        label_06_1Img_Arg->setEnabled(false);

        gridLayout_42->addWidget(label_06_1Img_Arg, 1, 1, 1, 1);

        stackedWidget_Settings_06_Math->addWidget(page_06_1Img);
        page_06_2Img = new QWidget();
        page_06_2Img->setObjectName(QString::fromUtf8("page_06_2Img"));
        gridLayout_43 = new QGridLayout(page_06_2Img);
        gridLayout_43->setObjectName(QString::fromUtf8("gridLayout_43"));
        comboBox_06_2Img_Comparator = new QComboBox(page_06_2Img);
        comboBox_06_2Img_Comparator->addItem(QString());
        comboBox_06_2Img_Comparator->addItem(QString());
        comboBox_06_2Img_Comparator->addItem(QString());
        comboBox_06_2Img_Comparator->addItem(QString());
        comboBox_06_2Img_Comparator->addItem(QString());
        comboBox_06_2Img_Comparator->addItem(QString());
        comboBox_06_2Img_Comparator->setObjectName(QString::fromUtf8("comboBox_06_2Img_Comparator"));
        comboBox_06_2Img_Comparator->setMinimumSize(QSize(150, 0));
        comboBox_06_2Img_Comparator->setMaximumSize(QSize(150, 16777215));

        gridLayout_43->addWidget(comboBox_06_2Img_Comparator, 4, 2, 1, 2);

        verticalSpacer_06_2Img = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_43->addItem(verticalSpacer_06_2Img, 5, 1, 1, 1);

        doubleSpinBox_06_2Img_Weight_Sum = new QDoubleSpinBox(page_06_2Img);
        doubleSpinBox_06_2Img_Weight_Sum->setObjectName(QString::fromUtf8("doubleSpinBox_06_2Img_Weight_Sum"));
        doubleSpinBox_06_2Img_Weight_Sum->setMinimumSize(QSize(150, 0));
        doubleSpinBox_06_2Img_Weight_Sum->setMaximumSize(QSize(150, 16777215));
        doubleSpinBox_06_2Img_Weight_Sum->setDecimals(3);
        doubleSpinBox_06_2Img_Weight_Sum->setMinimum(0.000000000000000);
        doubleSpinBox_06_2Img_Weight_Sum->setMaximum(10000.000000000000000);
        doubleSpinBox_06_2Img_Weight_Sum->setSingleStep(0.100000000000000);
        doubleSpinBox_06_2Img_Weight_Sum->setValue(1.000000000000000);

        gridLayout_43->addWidget(doubleSpinBox_06_2Img_Weight_Sum, 2, 2, 1, 2);

        label_06_2Img_Weight_Sum = new QLabel(page_06_2Img);
        label_06_2Img_Weight_Sum->setObjectName(QString::fromUtf8("label_06_2Img_Weight_Sum"));

        gridLayout_43->addWidget(label_06_2Img_Weight_Sum, 2, 1, 1, 1);

        label_06_2Img_Weight_Source = new QLabel(page_06_2Img);
        label_06_2Img_Weight_Source->setObjectName(QString::fromUtf8("label_06_2Img_Weight_Source"));

        gridLayout_43->addWidget(label_06_2Img_Weight_Source, 1, 1, 1, 1);

        doubleSpinBox_06_2Img_Weight_1 = new QDoubleSpinBox(page_06_2Img);
        doubleSpinBox_06_2Img_Weight_1->setObjectName(QString::fromUtf8("doubleSpinBox_06_2Img_Weight_1"));
        doubleSpinBox_06_2Img_Weight_1->setMinimumSize(QSize(72, 0));
        doubleSpinBox_06_2Img_Weight_1->setMaximumSize(QSize(72, 16777215));
        doubleSpinBox_06_2Img_Weight_1->setDecimals(2);
        doubleSpinBox_06_2Img_Weight_1->setMaximum(10000.000000000000000);
        doubleSpinBox_06_2Img_Weight_1->setSingleStep(0.100000000000000);
        doubleSpinBox_06_2Img_Weight_1->setValue(1.000000000000000);

        gridLayout_43->addWidget(doubleSpinBox_06_2Img_Weight_1, 1, 2, 1, 1);

        label_06_2Img_Scale = new QLabel(page_06_2Img);
        label_06_2Img_Scale->setObjectName(QString::fromUtf8("label_06_2Img_Scale"));

        gridLayout_43->addWidget(label_06_2Img_Scale, 3, 1, 1, 1);

        doubleSpinBox_06_2Img_Scale = new QDoubleSpinBox(page_06_2Img);
        doubleSpinBox_06_2Img_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_06_2Img_Scale"));
        doubleSpinBox_06_2Img_Scale->setMinimumSize(QSize(150, 0));
        doubleSpinBox_06_2Img_Scale->setMaximumSize(QSize(150, 16777215));
        doubleSpinBox_06_2Img_Scale->setDecimals(6);
        doubleSpinBox_06_2Img_Scale->setMaximum(100000.000000000000000);
        doubleSpinBox_06_2Img_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_06_2Img_Scale->setValue(1.000000000000000);

        gridLayout_43->addWidget(doubleSpinBox_06_2Img_Scale, 3, 2, 1, 2);

        label_06_2Img_Comparator = new QLabel(page_06_2Img);
        label_06_2Img_Comparator->setObjectName(QString::fromUtf8("label_06_2Img_Comparator"));

        gridLayout_43->addWidget(label_06_2Img_Comparator, 4, 1, 1, 1);

        line_06_2Img = new QFrame(page_06_2Img);
        line_06_2Img->setObjectName(QString::fromUtf8("line_06_2Img"));
        line_06_2Img->setFrameShape(QFrame::VLine);
        line_06_2Img->setFrameShadow(QFrame::Sunken);

        gridLayout_43->addWidget(line_06_2Img, 0, 0, 6, 1);

        label_06_2Img_Type = new QLabel(page_06_2Img);
        label_06_2Img_Type->setObjectName(QString::fromUtf8("label_06_2Img_Type"));
        label_06_2Img_Type->setMinimumSize(QSize(75, 0));
        label_06_2Img_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_43->addWidget(label_06_2Img_Type, 0, 1, 1, 1);

        doubleSpinBox_06_2Img_Weight_2 = new QDoubleSpinBox(page_06_2Img);
        doubleSpinBox_06_2Img_Weight_2->setObjectName(QString::fromUtf8("doubleSpinBox_06_2Img_Weight_2"));
        doubleSpinBox_06_2Img_Weight_2->setMinimumSize(QSize(72, 0));
        doubleSpinBox_06_2Img_Weight_2->setMaximumSize(QSize(72, 16777215));
        doubleSpinBox_06_2Img_Weight_2->setDecimals(2);
        doubleSpinBox_06_2Img_Weight_2->setMaximum(10000.000000000000000);
        doubleSpinBox_06_2Img_Weight_2->setSingleStep(0.100000000000000);
        doubleSpinBox_06_2Img_Weight_2->setValue(1.000000000000000);

        gridLayout_43->addWidget(doubleSpinBox_06_2Img_Weight_2, 1, 3, 1, 1);

        comboBox_06_2Img_Type = new QComboBox(page_06_2Img);
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->addItem(QString());
        comboBox_06_2Img_Type->setObjectName(QString::fromUtf8("comboBox_06_2Img_Type"));
        comboBox_06_2Img_Type->setMinimumSize(QSize(150, 0));
        comboBox_06_2Img_Type->setMaximumSize(QSize(150, 16777215));

        gridLayout_43->addWidget(comboBox_06_2Img_Type, 0, 2, 1, 2);

        horizontalSpacer_06_2Img = new QSpacerItem(358, 195, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_43->addItem(horizontalSpacer_06_2Img, 0, 4, 6, 1);

        stackedWidget_Settings_06_Math->addWidget(page_06_2Img);
        page_06_2ImgFunction = new QWidget();
        page_06_2ImgFunction->setObjectName(QString::fromUtf8("page_06_2ImgFunction"));
        gridLayout_88 = new QGridLayout(page_06_2ImgFunction);
        gridLayout_88->setObjectName(QString::fromUtf8("gridLayout_88"));
        comboBox_06_2ImgFunction_Function = new QComboBox(page_06_2ImgFunction);
        comboBox_06_2ImgFunction_Function->setObjectName(QString::fromUtf8("comboBox_06_2ImgFunction_Function"));

        gridLayout_88->addWidget(comboBox_06_2ImgFunction_Function, 0, 2, 1, 1);

        label_06_2ImgFunction_Function = new QLabel(page_06_2ImgFunction);
        label_06_2ImgFunction_Function->setObjectName(QString::fromUtf8("label_06_2ImgFunction_Function"));
        label_06_2ImgFunction_Function->setMaximumSize(QSize(75, 16777215));

        gridLayout_88->addWidget(label_06_2ImgFunction_Function, 0, 1, 1, 1);

        label_06_2ImgFunction_Parameters = new QLabel(page_06_2ImgFunction);
        label_06_2ImgFunction_Parameters->setObjectName(QString::fromUtf8("label_06_2ImgFunction_Parameters"));
        label_06_2ImgFunction_Parameters->setMaximumSize(QSize(75, 16777215));

        gridLayout_88->addWidget(label_06_2ImgFunction_Parameters, 1, 1, 1, 1);

        gridLayout_06_2ImgFunction_Parameters = new QGridLayout();
        gridLayout_06_2ImgFunction_Parameters->setSpacing(1);
        gridLayout_06_2ImgFunction_Parameters->setObjectName(QString::fromUtf8("gridLayout_06_2ImgFunction_Parameters"));
        doubleSpinBox_06_2ImgFunction_b = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_b->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_b->setFrame(false);
        doubleSpinBox_06_2ImgFunction_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_b->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_b->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_b->setValue(0.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_b, 0, 1, 1, 1);

        doubleSpinBox_06_2ImgFunction_c = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_c->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_c->setFrame(false);
        doubleSpinBox_06_2ImgFunction_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_c->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_c->setValue(1.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_c, 0, 2, 1, 1);

        doubleSpinBox_06_2ImgFunction_d = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_d->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_d->setFrame(false);
        doubleSpinBox_06_2ImgFunction_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_d->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_d->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_d->setValue(0.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_d, 0, 3, 1, 1);

        doubleSpinBox_06_2ImgFunction_a = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_a->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_a->setFrame(false);
        doubleSpinBox_06_2ImgFunction_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_a->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_a->setValue(1.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_a, 0, 0, 1, 1);

        doubleSpinBox_06_2ImgFunction_e = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_e->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_e->setFrame(false);
        doubleSpinBox_06_2ImgFunction_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_e->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_e, 1, 0, 1, 1);

        doubleSpinBox_06_2ImgFunction_f = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_f->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_f->setFrame(false);
        doubleSpinBox_06_2ImgFunction_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_f->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_f, 1, 1, 1, 1);

        doubleSpinBox_06_2ImgFunction_nan = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_nan->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_nan->setFrame(false);
        doubleSpinBox_06_2ImgFunction_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_nan->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_nan->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_nan, 1, 2, 1, 1);

        doubleSpinBox_06_2ImgFunction_inf = new QDoubleSpinBox(page_06_2ImgFunction);
        doubleSpinBox_06_2ImgFunction_inf->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_inf->setFrame(false);
        doubleSpinBox_06_2ImgFunction_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_inf->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_inf->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_inf, 1, 3, 1, 1);


        gridLayout_88->addLayout(gridLayout_06_2ImgFunction_Parameters, 1, 2, 1, 1);

        verticalSpacer_06_2ImgFunction = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_88->addItem(verticalSpacer_06_2ImgFunction, 3, 2, 1, 1);

        line_06_2ImgFunction = new QFrame(page_06_2ImgFunction);
        line_06_2ImgFunction->setObjectName(QString::fromUtf8("line_06_2ImgFunction"));
        line_06_2ImgFunction->setFrameShape(QFrame::VLine);
        line_06_2ImgFunction->setFrameShadow(QFrame::Sunken);

        gridLayout_88->addWidget(line_06_2ImgFunction, 0, 0, 4, 1);

        checkBox_06_2ImgFunction_Force_8bit = new QCheckBox(page_06_2ImgFunction);
        checkBox_06_2ImgFunction_Force_8bit->setObjectName(QString::fromUtf8("checkBox_06_2ImgFunction_Force_8bit"));

        gridLayout_88->addWidget(checkBox_06_2ImgFunction_Force_8bit, 2, 2, 1, 1);

        label_06_2ImgFunction_Force_8bit = new QLabel(page_06_2ImgFunction);
        label_06_2ImgFunction_Force_8bit->setObjectName(QString::fromUtf8("label_06_2ImgFunction_Force_8bit"));

        gridLayout_88->addWidget(label_06_2ImgFunction_Force_8bit, 2, 1, 1, 1);

        stackedWidget_Settings_06_Math->addWidget(page_06_2ImgFunction);
        gridLayout_06_2ImgFunction_Complex = new QWidget();
        gridLayout_06_2ImgFunction_Complex->setObjectName(QString::fromUtf8("gridLayout_06_2ImgFunction_Complex"));
        gridLayout_119 = new QGridLayout(gridLayout_06_2ImgFunction_Complex);
        gridLayout_119->setObjectName(QString::fromUtf8("gridLayout_119"));
        label_06_2ImgFunction_Complex_Function = new QLabel(gridLayout_06_2ImgFunction_Complex);
        label_06_2ImgFunction_Complex_Function->setObjectName(QString::fromUtf8("label_06_2ImgFunction_Complex_Function"));
        label_06_2ImgFunction_Complex_Function->setMaximumSize(QSize(75, 16777215));

        gridLayout_119->addWidget(label_06_2ImgFunction_Complex_Function, 0, 2, 1, 1);

        verticalSpacer_06_2ImgFunction_Complex = new QSpacerItem(20, 115, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_119->addItem(verticalSpacer_06_2ImgFunction_Complex, 2, 3, 1, 1);

        comboBox_06_2ImgFunction_Complex_Function = new QComboBox(gridLayout_06_2ImgFunction_Complex);
        comboBox_06_2ImgFunction_Complex_Function->setObjectName(QString::fromUtf8("comboBox_06_2ImgFunction_Complex_Function"));

        gridLayout_119->addWidget(comboBox_06_2ImgFunction_Complex_Function, 0, 3, 1, 1);

        label_06_2ImgFunction_Complex_Parameters = new QLabel(gridLayout_06_2ImgFunction_Complex);
        label_06_2ImgFunction_Complex_Parameters->setObjectName(QString::fromUtf8("label_06_2ImgFunction_Complex_Parameters"));
        label_06_2ImgFunction_Complex_Parameters->setMaximumSize(QSize(75, 16777215));

        gridLayout_119->addWidget(label_06_2ImgFunction_Complex_Parameters, 1, 2, 1, 1);

        line_06_2ImgFunction_Complex = new QFrame(gridLayout_06_2ImgFunction_Complex);
        line_06_2ImgFunction_Complex->setObjectName(QString::fromUtf8("line_06_2ImgFunction_Complex"));
        line_06_2ImgFunction_Complex->setFrameShape(QFrame::VLine);
        line_06_2ImgFunction_Complex->setFrameShadow(QFrame::Sunken);

        gridLayout_119->addWidget(line_06_2ImgFunction_Complex, 0, 1, 3, 1);

        gridLayout_06_2ImgFunction_Complex_Parameters = new QGridLayout();
        gridLayout_06_2ImgFunction_Complex_Parameters->setSpacing(1);
        gridLayout_06_2ImgFunction_Complex_Parameters->setObjectName(QString::fromUtf8("gridLayout_06_2ImgFunction_Complex_Parameters"));
        doubleSpinBox_06_2ImgFunction_Complex_e = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_e->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_e->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_e->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_e->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_e, 3, 0, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_c = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_c->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_c->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_c->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_Complex_c->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_c->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_c->setValue(1.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_c, 2, 2, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_oy = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_oy->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_oy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_oy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_oy->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_oy->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_oy->setMinimum(-1000000000000000008493621433689702976148869924598760615894999102702796905906176.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_oy->setMaximum(999999999999999943801810948794571024057224129020550531544123892056457216.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_oy, 0, 3, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_d = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_d->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_d->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_d->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_Complex_d->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_d->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_d->setValue(0.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_d, 2, 3, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_sx = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_sx->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_sx"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_sx->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_sx->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_sx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_sx->setMinimum(-1000000000000000008493621433689702976148869924598760615894999102702796905906176.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_sx->setMaximum(999999999999999943801810948794571024057224129020550531544123892056457216.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_sx->setValue(1.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_sx, 0, 0, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_nan = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_nan->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_nan"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_nan->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_nan->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_nan->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_nan->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_nan->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_Complex_nan->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_nan->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_nan, 3, 2, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_f = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_f->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_f->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_f->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_f->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_f, 3, 1, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_b = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_b->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_b->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_b->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_Complex_b->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_b->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_b->setValue(0.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_b, 2, 1, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_ox = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_ox->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_ox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_ox->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_ox->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_ox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_ox->setMinimum(-1000000000000000008493621433689702976148869924598760615894999102702796905906176.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_ox->setMaximum(999999999999999943801810948794571024057224129020550531544123892056457216.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_ox, 0, 1, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_inf = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_inf->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_inf"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_inf->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_inf->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_inf->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_inf->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_inf->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_Complex_inf->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_inf->setMaximum(999999999999.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_inf, 3, 3, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_a = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_a->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_a->setFrame(false);
        doubleSpinBox_06_2ImgFunction_Complex_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_a->setDecimals(3);
        doubleSpinBox_06_2ImgFunction_Complex_a->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_a->setMaximum(999999999999.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_a->setValue(1.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_a, 2, 0, 1, 1);

        doubleSpinBox_06_2ImgFunction_Complex_sy = new QDoubleSpinBox(gridLayout_06_2ImgFunction_Complex);
        doubleSpinBox_06_2ImgFunction_Complex_sy->setObjectName(QString::fromUtf8("doubleSpinBox_06_2ImgFunction_Complex_sy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_06_2ImgFunction_Complex_sy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_06_2ImgFunction_Complex_sy->setSizePolicy(sizePolicy1);
        doubleSpinBox_06_2ImgFunction_Complex_sy->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_06_2ImgFunction_Complex_sy->setMinimum(-1000000000000000008493621433689702976148869924598760615894999102702796905906176.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_sy->setMaximum(999999999999999943801810948794571024057224129020550531544123892056457216.000000000000000);
        doubleSpinBox_06_2ImgFunction_Complex_sy->setValue(1.000000000000000);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(doubleSpinBox_06_2ImgFunction_Complex_sy, 0, 2, 1, 1);

        line_06_2ImgFunction_Complex_2 = new QFrame(gridLayout_06_2ImgFunction_Complex);
        line_06_2ImgFunction_Complex_2->setObjectName(QString::fromUtf8("line_06_2ImgFunction_Complex_2"));
        line_06_2ImgFunction_Complex_2->setFrameShape(QFrame::HLine);
        line_06_2ImgFunction_Complex_2->setFrameShadow(QFrame::Sunken);

        gridLayout_06_2ImgFunction_Complex_Parameters->addWidget(line_06_2ImgFunction_Complex_2, 1, 0, 1, 4);


        gridLayout_119->addLayout(gridLayout_06_2ImgFunction_Complex_Parameters, 1, 3, 1, 1);

        stackedWidget_Settings_06_Math->addWidget(gridLayout_06_2ImgFunction_Complex);
        page_06_3Img = new QWidget();
        page_06_3Img->setObjectName(QString::fromUtf8("page_06_3Img"));
        gridLayout_106 = new QGridLayout(page_06_3Img);
        gridLayout_106->setObjectName(QString::fromUtf8("gridLayout_106"));
        line_06_3Img = new QFrame(page_06_3Img);
        line_06_3Img->setObjectName(QString::fromUtf8("line_06_3Img"));
        line_06_3Img->setFrameShape(QFrame::VLine);
        line_06_3Img->setFrameShadow(QFrame::Sunken);

        gridLayout_106->addWidget(line_06_3Img, 0, 0, 3, 1);

        label_06_3Img_Type = new QLabel(page_06_3Img);
        label_06_3Img_Type->setObjectName(QString::fromUtf8("label_06_3Img_Type"));
        label_06_3Img_Type->setMinimumSize(QSize(75, 0));
        label_06_3Img_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_106->addWidget(label_06_3Img_Type, 0, 1, 1, 1);

        comboBox_06_3Img_Type = new QComboBox(page_06_3Img);
        comboBox_06_3Img_Type->addItem(QString());
        comboBox_06_3Img_Type->addItem(QString());
        comboBox_06_3Img_Type->addItem(QString());
        comboBox_06_3Img_Type->addItem(QString());
        comboBox_06_3Img_Type->setObjectName(QString::fromUtf8("comboBox_06_3Img_Type"));
        comboBox_06_3Img_Type->setMinimumSize(QSize(300, 0));
        comboBox_06_3Img_Type->setMaximumSize(QSize(300, 16777215));

        gridLayout_106->addWidget(comboBox_06_3Img_Type, 0, 2, 1, 2);

        horizontalSpacer_06_3Img = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_106->addItem(horizontalSpacer_06_3Img, 0, 4, 1, 1);

        label_06_3Img_Value = new QLabel(page_06_3Img);
        label_06_3Img_Value->setObjectName(QString::fromUtf8("label_06_3Img_Value"));
        label_06_3Img_Value->setMinimumSize(QSize(75, 0));
        label_06_3Img_Value->setMaximumSize(QSize(75, 16777215));

        gridLayout_106->addWidget(label_06_3Img_Value, 1, 1, 1, 1);

        checkBox_06_3Img_Value = new QCheckBox(page_06_3Img);
        checkBox_06_3Img_Value->setObjectName(QString::fromUtf8("checkBox_06_3Img_Value"));
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(checkBox_06_3Img_Value->sizePolicy().hasHeightForWidth());
        checkBox_06_3Img_Value->setSizePolicy(sizePolicy9);
        checkBox_06_3Img_Value->setChecked(false);

        gridLayout_106->addWidget(checkBox_06_3Img_Value, 1, 2, 1, 1);

        doubleSpinBox_06_3Img_Value = new QDoubleSpinBox(page_06_3Img);
        doubleSpinBox_06_3Img_Value->setObjectName(QString::fromUtf8("doubleSpinBox_06_3Img_Value"));
        doubleSpinBox_06_3Img_Value->setEnabled(false);
        doubleSpinBox_06_3Img_Value->setDecimals(9);
        doubleSpinBox_06_3Img_Value->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_3Img_Value->setMaximum(999999999999.000000000000000);

        gridLayout_106->addWidget(doubleSpinBox_06_3Img_Value, 1, 3, 1, 1);

        verticalSpacer_06_3Img = new QSpacerItem(198, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_106->addItem(verticalSpacer_06_3Img, 2, 1, 1, 3);

        stackedWidget_Settings_06_Math->addWidget(page_06_3Img);
        page_06_4Img = new QWidget();
        page_06_4Img->setObjectName(QString::fromUtf8("page_06_4Img"));
        gridLayout_105 = new QGridLayout(page_06_4Img);
        gridLayout_105->setObjectName(QString::fromUtf8("gridLayout_105"));
        line_06_4Img = new QFrame(page_06_4Img);
        line_06_4Img->setObjectName(QString::fromUtf8("line_06_4Img"));
        line_06_4Img->setFrameShape(QFrame::VLine);
        line_06_4Img->setFrameShadow(QFrame::Sunken);

        gridLayout_105->addWidget(line_06_4Img, 0, 0, 3, 1);

        label_06_4Img_Type = new QLabel(page_06_4Img);
        label_06_4Img_Type->setObjectName(QString::fromUtf8("label_06_4Img_Type"));
        label_06_4Img_Type->setMinimumSize(QSize(75, 0));
        label_06_4Img_Type->setMaximumSize(QSize(75, 16777215));

        gridLayout_105->addWidget(label_06_4Img_Type, 0, 1, 1, 1);

        comboBox_06_4Img_Type = new QComboBox(page_06_4Img);
        comboBox_06_4Img_Type->addItem(QString());
        comboBox_06_4Img_Type->addItem(QString());
        comboBox_06_4Img_Type->addItem(QString());
        comboBox_06_4Img_Type->addItem(QString());
        comboBox_06_4Img_Type->setObjectName(QString::fromUtf8("comboBox_06_4Img_Type"));
        comboBox_06_4Img_Type->setMinimumSize(QSize(300, 0));
        comboBox_06_4Img_Type->setMaximumSize(QSize(300, 16777215));

        gridLayout_105->addWidget(comboBox_06_4Img_Type, 0, 2, 1, 2);

        horizontalSpacer_06_4Img = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_105->addItem(horizontalSpacer_06_4Img, 0, 4, 1, 1);

        label_06_4Img_Value = new QLabel(page_06_4Img);
        label_06_4Img_Value->setObjectName(QString::fromUtf8("label_06_4Img_Value"));
        label_06_4Img_Value->setMinimumSize(QSize(75, 0));
        label_06_4Img_Value->setMaximumSize(QSize(75, 16777215));

        gridLayout_105->addWidget(label_06_4Img_Value, 1, 1, 1, 1);

        checkBox_06_4Img_Value = new QCheckBox(page_06_4Img);
        checkBox_06_4Img_Value->setObjectName(QString::fromUtf8("checkBox_06_4Img_Value"));
        sizePolicy9.setHeightForWidth(checkBox_06_4Img_Value->sizePolicy().hasHeightForWidth());
        checkBox_06_4Img_Value->setSizePolicy(sizePolicy9);
        checkBox_06_4Img_Value->setChecked(false);

        gridLayout_105->addWidget(checkBox_06_4Img_Value, 1, 2, 1, 1);

        doubleSpinBox_06_4Img_Value = new QDoubleSpinBox(page_06_4Img);
        doubleSpinBox_06_4Img_Value->setObjectName(QString::fromUtf8("doubleSpinBox_06_4Img_Value"));
        doubleSpinBox_06_4Img_Value->setEnabled(false);
        doubleSpinBox_06_4Img_Value->setDecimals(9);
        doubleSpinBox_06_4Img_Value->setMinimum(-999999999999.000000000000000);
        doubleSpinBox_06_4Img_Value->setMaximum(999999999999.000000000000000);

        gridLayout_105->addWidget(doubleSpinBox_06_4Img_Value, 1, 3, 1, 1);

        verticalSpacer_06_4Img = new QSpacerItem(198, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_105->addItem(verticalSpacer_06_4Img, 2, 1, 1, 3);

        stackedWidget_Settings_06_Math->addWidget(page_06_4Img);

        gridLayout_23->addWidget(stackedWidget_Settings_06_Math, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_06_Math);
        page_Settings_07_Transform = new QWidget();
        page_Settings_07_Transform->setObjectName(QString::fromUtf8("page_Settings_07_Transform"));
        gridLayout_24 = new QGridLayout(page_Settings_07_Transform);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_07_Transform = new QStackedWidget(page_Settings_07_Transform);
        stackedWidget_Settings_07_Transform->setObjectName(QString::fromUtf8("stackedWidget_Settings_07_Transform"));
        page_07_Dist = new QWidget();
        page_07_Dist->setObjectName(QString::fromUtf8("page_07_Dist"));
        gridLayout_33 = new QGridLayout(page_07_Dist);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        label_07_Dist_Norm = new QLabel(page_07_Dist);
        label_07_Dist_Norm->setObjectName(QString::fromUtf8("label_07_Dist_Norm"));
        label_07_Dist_Norm->setMinimumSize(QSize(75, 0));
        label_07_Dist_Norm->setMaximumSize(QSize(75, 16777215));

        gridLayout_33->addWidget(label_07_Dist_Norm, 0, 1, 1, 1);

        label_07_Dist_Precision = new QLabel(page_07_Dist);
        label_07_Dist_Precision->setObjectName(QString::fromUtf8("label_07_Dist_Precision"));
        label_07_Dist_Precision->setMinimumSize(QSize(75, 0));
        label_07_Dist_Precision->setMaximumSize(QSize(75, 16777215));

        gridLayout_33->addWidget(label_07_Dist_Precision, 1, 1, 1, 1);

        verticalSpacer_07_Dist = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_33->addItem(verticalSpacer_07_Dist, 2, 1, 1, 1);

        comboBox_07_Dist_Precision = new QComboBox(page_07_Dist);
        comboBox_07_Dist_Precision->addItem(QString());
        comboBox_07_Dist_Precision->addItem(QString());
        comboBox_07_Dist_Precision->addItem(QString());
        comboBox_07_Dist_Precision->setObjectName(QString::fromUtf8("comboBox_07_Dist_Precision"));
        comboBox_07_Dist_Precision->setMinimumSize(QSize(0, 0));
        comboBox_07_Dist_Precision->setMaximumSize(QSize(100, 16777215));

        gridLayout_33->addWidget(comboBox_07_Dist_Precision, 1, 2, 1, 1);

        comboBox_07_Dist_Metric = new QComboBox(page_07_Dist);
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->addItem(QString());
        comboBox_07_Dist_Metric->setObjectName(QString::fromUtf8("comboBox_07_Dist_Metric"));
        comboBox_07_Dist_Metric->setMinimumSize(QSize(100, 0));
        comboBox_07_Dist_Metric->setMaximumSize(QSize(100, 16777215));

        gridLayout_33->addWidget(comboBox_07_Dist_Metric, 0, 2, 1, 1);

        horizontalSpacer_07_Dist = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_33->addItem(horizontalSpacer_07_Dist, 2, 2, 1, 2);

        line_07_Dist = new QFrame(page_07_Dist);
        line_07_Dist->setObjectName(QString::fromUtf8("line_07_Dist"));
        line_07_Dist->setFrameShape(QFrame::VLine);
        line_07_Dist->setFrameShadow(QFrame::Sunken);

        gridLayout_33->addWidget(line_07_Dist, 0, 0, 3, 1);

        stackedWidget_Settings_07_Transform->addWidget(page_07_Dist);
        page_07_Watershade = new QWidget();
        page_07_Watershade->setObjectName(QString::fromUtf8("page_07_Watershade"));
        gridLayout_41 = new QGridLayout(page_07_Watershade);
        gridLayout_41->setObjectName(QString::fromUtf8("gridLayout_41"));
        comboBox_07_Watershed_Implementation = new QComboBox(page_07_Watershade);
        comboBox_07_Watershed_Implementation->addItem(QString());
        comboBox_07_Watershed_Implementation->addItem(QString());
        comboBox_07_Watershed_Implementation->setObjectName(QString::fromUtf8("comboBox_07_Watershed_Implementation"));
        comboBox_07_Watershed_Implementation->setMinimumSize(QSize(170, 20));
        comboBox_07_Watershed_Implementation->setMaximumSize(QSize(170, 20));

        gridLayout_41->addWidget(comboBox_07_Watershed_Implementation, 0, 1, 1, 1);

        label_07_Watershed_Implementation = new QLabel(page_07_Watershade);
        label_07_Watershed_Implementation->setObjectName(QString::fromUtf8("label_07_Watershed_Implementation"));
        label_07_Watershed_Implementation->setMinimumSize(QSize(75, 20));
        label_07_Watershed_Implementation->setMaximumSize(QSize(75, 20));

        gridLayout_41->addWidget(label_07_Watershed_Implementation, 0, 0, 1, 1);

        horizontalSpacer_07_Watershed_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_41->addItem(horizontalSpacer_07_Watershed_3, 0, 2, 1, 1);

        stackedWidget_07_Watershed = new QStackedWidget(page_07_Watershade);
        stackedWidget_07_Watershed->setObjectName(QString::fromUtf8("stackedWidget_07_Watershed"));
        page_07_WatershedCustom = new QWidget();
        page_07_WatershedCustom->setObjectName(QString::fromUtf8("page_07_WatershedCustom"));
        gridLayout_126 = new QGridLayout(page_07_WatershedCustom);
        gridLayout_126->setObjectName(QString::fromUtf8("gridLayout_126"));
        gridLayout_126->setContentsMargins(0, 0, 0, 0);
        comboBox_07_WatershedCustom_Mask = new QComboBox(page_07_WatershedCustom);
        comboBox_07_WatershedCustom_Mask->addItem(QString());
        comboBox_07_WatershedCustom_Mask->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_Mask"));
        comboBox_07_WatershedCustom_Mask->setMinimumSize(QSize(170, 0));
        comboBox_07_WatershedCustom_Mask->setMaximumSize(QSize(170, 16777215));

        gridLayout_126->addWidget(comboBox_07_WatershedCustom_Mask, 2, 1, 1, 1);

        label_07_WatershedCustom_Connectivity_3 = new QLabel(page_07_WatershedCustom);
        label_07_WatershedCustom_Connectivity_3->setObjectName(QString::fromUtf8("label_07_WatershedCustom_Connectivity_3"));
        label_07_WatershedCustom_Connectivity_3->setMinimumSize(QSize(75, 20));
        label_07_WatershedCustom_Connectivity_3->setMaximumSize(QSize(75, 20));

        gridLayout_126->addWidget(label_07_WatershedCustom_Connectivity_3, 3, 0, 1, 1);

        verticalSpacer_07_WatershedCustom_3 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_126->addItem(verticalSpacer_07_WatershedCustom_3, 7, 0, 1, 1);

        label_07_WatershedCustom_Border = new QLabel(page_07_WatershedCustom);
        label_07_WatershedCustom_Border->setObjectName(QString::fromUtf8("label_07_WatershedCustom_Border"));
        label_07_WatershedCustom_Border->setMinimumSize(QSize(75, 20));
        label_07_WatershedCustom_Border->setMaximumSize(QSize(75, 20));

        gridLayout_126->addWidget(label_07_WatershedCustom_Border, 4, 0, 1, 1);

        comboBox_07_WatershedCustom_Flood = new QComboBox(page_07_WatershedCustom);
        comboBox_07_WatershedCustom_Flood->addItem(QString());
        comboBox_07_WatershedCustom_Flood->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_Flood"));
        comboBox_07_WatershedCustom_Flood->setMinimumSize(QSize(170, 0));
        comboBox_07_WatershedCustom_Flood->setMaximumSize(QSize(170, 16777215));

        gridLayout_126->addWidget(comboBox_07_WatershedCustom_Flood, 0, 1, 1, 1);

        label_07_WatershedCustom_NonSeed = new QLabel(page_07_WatershedCustom);
        label_07_WatershedCustom_NonSeed->setObjectName(QString::fromUtf8("label_07_WatershedCustom_NonSeed"));
        label_07_WatershedCustom_NonSeed->setMinimumSize(QSize(75, 20));
        label_07_WatershedCustom_NonSeed->setMaximumSize(QSize(75, 20));

        gridLayout_126->addWidget(label_07_WatershedCustom_NonSeed, 5, 0, 1, 1);

        label_07_WatershedCustom_Mask_3 = new QLabel(page_07_WatershedCustom);
        label_07_WatershedCustom_Mask_3->setObjectName(QString::fromUtf8("label_07_WatershedCustom_Mask_3"));
        label_07_WatershedCustom_Mask_3->setMinimumSize(QSize(75, 20));
        label_07_WatershedCustom_Mask_3->setMaximumSize(QSize(75, 20));

        gridLayout_126->addWidget(label_07_WatershedCustom_Mask_3, 2, 0, 1, 1);

        stackedWidget_07_WatershedCustom_Flood = new QStackedWidget(page_07_WatershedCustom);
        stackedWidget_07_WatershedCustom_Flood->setObjectName(QString::fromUtf8("stackedWidget_07_WatershedCustom_Flood"));
        page_07_WatershedCustom_Flood_Empty = new QWidget();
        page_07_WatershedCustom_Flood_Empty->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Flood_Empty"));
        stackedWidget_07_WatershedCustom_Flood->addWidget(page_07_WatershedCustom_Flood_Empty);
        page_07_WatershedCustom_Flood_Gauss = new QWidget();
        page_07_WatershedCustom_Flood_Gauss->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Flood_Gauss"));
        gridLayout_127 = new QGridLayout(page_07_WatershedCustom_Flood_Gauss);
        gridLayout_127->setObjectName(QString::fromUtf8("gridLayout_127"));
        gridLayout_127->setContentsMargins(0, 0, 0, 0);
        spinBox_07_WatershedCustom_Flood_GaussSize = new QSpinBox(page_07_WatershedCustom_Flood_Gauss);
        spinBox_07_WatershedCustom_Flood_GaussSize->setObjectName(QString::fromUtf8("spinBox_07_WatershedCustom_Flood_GaussSize"));
        spinBox_07_WatershedCustom_Flood_GaussSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_07_WatershedCustom_Flood_GaussSize->setMinimum(1);
        spinBox_07_WatershedCustom_Flood_GaussSize->setSingleStep(2);
        spinBox_07_WatershedCustom_Flood_GaussSize->setValue(3);

        gridLayout_127->addWidget(spinBox_07_WatershedCustom_Flood_GaussSize, 0, 0, 1, 1);

        doubleSpinBox_07_WatershedCustom_Flood_GaussSigma = new QDoubleSpinBox(page_07_WatershedCustom_Flood_Gauss);
        doubleSpinBox_07_WatershedCustom_Flood_GaussSigma->setObjectName(QString::fromUtf8("doubleSpinBox_07_WatershedCustom_Flood_GaussSigma"));
        doubleSpinBox_07_WatershedCustom_Flood_GaussSigma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_07_WatershedCustom_Flood_GaussSigma->setSingleStep(0.250000000000000);
        doubleSpinBox_07_WatershedCustom_Flood_GaussSigma->setValue(2.000000000000000);

        gridLayout_127->addWidget(doubleSpinBox_07_WatershedCustom_Flood_GaussSigma, 0, 1, 1, 1);

        stackedWidget_07_WatershedCustom_Flood->addWidget(page_07_WatershedCustom_Flood_Gauss);
        page_07_WatershedCustom_Flood_Morph = new QWidget();
        page_07_WatershedCustom_Flood_Morph->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Flood_Morph"));
        gridLayout_128 = new QGridLayout(page_07_WatershedCustom_Flood_Morph);
        gridLayout_128->setObjectName(QString::fromUtf8("gridLayout_128"));
        gridLayout_128->setContentsMargins(0, 0, 0, 0);
        comboBox_07_WatershedCustom_Flood_Morph_Elem = new QComboBox(page_07_WatershedCustom_Flood_Morph);
        comboBox_07_WatershedCustom_Flood_Morph_Elem->addItem(QString());
        comboBox_07_WatershedCustom_Flood_Morph_Elem->addItem(QString());
        comboBox_07_WatershedCustom_Flood_Morph_Elem->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_Flood_Morph_Elem"));

        gridLayout_128->addWidget(comboBox_07_WatershedCustom_Flood_Morph_Elem, 0, 0, 1, 1);

        spinBox_07_WatershedCustom_Flood_Morph_Size = new QSpinBox(page_07_WatershedCustom_Flood_Morph);
        spinBox_07_WatershedCustom_Flood_Morph_Size->setObjectName(QString::fromUtf8("spinBox_07_WatershedCustom_Flood_Morph_Size"));
        spinBox_07_WatershedCustom_Flood_Morph_Size->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_07_WatershedCustom_Flood_Morph_Size->setMinimum(1);
        spinBox_07_WatershedCustom_Flood_Morph_Size->setSingleStep(2);
        spinBox_07_WatershedCustom_Flood_Morph_Size->setValue(3);

        gridLayout_128->addWidget(spinBox_07_WatershedCustom_Flood_Morph_Size, 0, 1, 1, 1);

        stackedWidget_07_WatershedCustom_Flood->addWidget(page_07_WatershedCustom_Flood_Morph);

        gridLayout_126->addWidget(stackedWidget_07_WatershedCustom_Flood, 0, 2, 1, 1);

        comboBox_07_WatershedCustom_Marker = new QComboBox(page_07_WatershedCustom);
        comboBox_07_WatershedCustom_Marker->addItem(QString());
        comboBox_07_WatershedCustom_Marker->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_Marker"));
        comboBox_07_WatershedCustom_Marker->setMinimumSize(QSize(170, 0));
        comboBox_07_WatershedCustom_Marker->setMaximumSize(QSize(170, 16777215));

        gridLayout_126->addWidget(comboBox_07_WatershedCustom_Marker, 1, 1, 1, 1);

        label_07_WatershedCustom_Marker_3 = new QLabel(page_07_WatershedCustom);
        label_07_WatershedCustom_Marker_3->setObjectName(QString::fromUtf8("label_07_WatershedCustom_Marker_3"));
        label_07_WatershedCustom_Marker_3->setMinimumSize(QSize(75, 20));
        label_07_WatershedCustom_Marker_3->setMaximumSize(QSize(75, 20));

        gridLayout_126->addWidget(label_07_WatershedCustom_Marker_3, 1, 0, 1, 1);

        label_07_WatershedCustom_Flood_3 = new QLabel(page_07_WatershedCustom);
        label_07_WatershedCustom_Flood_3->setObjectName(QString::fromUtf8("label_07_WatershedCustom_Flood_3"));
        label_07_WatershedCustom_Flood_3->setMinimumSize(QSize(75, 20));
        label_07_WatershedCustom_Flood_3->setMaximumSize(QSize(75, 20));

        gridLayout_126->addWidget(label_07_WatershedCustom_Flood_3, 0, 0, 1, 1);

        checkBox_07_WatershedCustom_IncludeNonSeed = new QCheckBox(page_07_WatershedCustom);
        checkBox_07_WatershedCustom_IncludeNonSeed->setObjectName(QString::fromUtf8("checkBox_07_WatershedCustom_IncludeNonSeed"));
        checkBox_07_WatershedCustom_IncludeNonSeed->setEnabled(true);
        checkBox_07_WatershedCustom_IncludeNonSeed->setChecked(true);

        gridLayout_126->addWidget(checkBox_07_WatershedCustom_IncludeNonSeed, 5, 1, 1, 1);

        stackedWidget_07_WatershedCustom_Marker = new QStackedWidget(page_07_WatershedCustom);
        stackedWidget_07_WatershedCustom_Marker->setObjectName(QString::fromUtf8("stackedWidget_07_WatershedCustom_Marker"));
        page_07_WatershedCustom_Marker_Empty = new QWidget();
        page_07_WatershedCustom_Marker_Empty->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Marker_Empty"));
        stackedWidget_07_WatershedCustom_Marker->addWidget(page_07_WatershedCustom_Marker_Empty);
        page_07_WatershedCustom_Marker_Label = new QWidget();
        page_07_WatershedCustom_Marker_Label->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Marker_Label"));
        gridLayout_130 = new QGridLayout(page_07_WatershedCustom_Marker_Label);
        gridLayout_130->setObjectName(QString::fromUtf8("gridLayout_130"));
        gridLayout_130->setContentsMargins(0, 0, 0, 0);
        comboBox_07_WatershedCustom_Marker_LabelNeighborhood = new QComboBox(page_07_WatershedCustom_Marker_Label);
        comboBox_07_WatershedCustom_Marker_LabelNeighborhood->addItem(QString());
        comboBox_07_WatershedCustom_Marker_LabelNeighborhood->addItem(QString());
        comboBox_07_WatershedCustom_Marker_LabelNeighborhood->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_Marker_LabelNeighborhood"));

        gridLayout_130->addWidget(comboBox_07_WatershedCustom_Marker_LabelNeighborhood, 0, 0, 1, 1);

        stackedWidget_07_WatershedCustom_Marker->addWidget(page_07_WatershedCustom_Marker_Label);

        gridLayout_126->addWidget(stackedWidget_07_WatershedCustom_Marker, 1, 2, 1, 1);

        comboBox_07_WatershedCustom_Connectivity = new QComboBox(page_07_WatershedCustom);
        comboBox_07_WatershedCustom_Connectivity->addItem(QString());
        comboBox_07_WatershedCustom_Connectivity->addItem(QString());
        comboBox_07_WatershedCustom_Connectivity->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_Connectivity"));
        comboBox_07_WatershedCustom_Connectivity->setMinimumSize(QSize(170, 0));
        comboBox_07_WatershedCustom_Connectivity->setMaximumSize(QSize(170, 16777215));

        gridLayout_126->addWidget(comboBox_07_WatershedCustom_Connectivity, 3, 1, 1, 1);

        checkBox_07_WatershedCustom_ExcludeBorder = new QCheckBox(page_07_WatershedCustom);
        checkBox_07_WatershedCustom_ExcludeBorder->setObjectName(QString::fromUtf8("checkBox_07_WatershedCustom_ExcludeBorder"));
        checkBox_07_WatershedCustom_ExcludeBorder->setEnabled(true);
        checkBox_07_WatershedCustom_ExcludeBorder->setChecked(true);

        gridLayout_126->addWidget(checkBox_07_WatershedCustom_ExcludeBorder, 4, 1, 1, 1);

        stackedWidget_07_WatershedCustom_Mask = new QStackedWidget(page_07_WatershedCustom);
        stackedWidget_07_WatershedCustom_Mask->setObjectName(QString::fromUtf8("stackedWidget_07_WatershedCustom_Mask"));
        page_07_WatershedCustom_Mask_Empty = new QWidget();
        page_07_WatershedCustom_Mask_Empty->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Mask_Empty"));
        stackedWidget_07_WatershedCustom_Mask->addWidget(page_07_WatershedCustom_Mask_Empty);
        page_07_WatershedCustom_Mask_Thres = new QWidget();
        page_07_WatershedCustom_Mask_Thres->setObjectName(QString::fromUtf8("page_07_WatershedCustom_Mask_Thres"));
        gridLayout_132 = new QGridLayout(page_07_WatershedCustom_Mask_Thres);
        gridLayout_132->setObjectName(QString::fromUtf8("gridLayout_132"));
        gridLayout_132->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_07_WatershedCustom_Mask_Thres = new QDoubleSpinBox(page_07_WatershedCustom_Mask_Thres);
        doubleSpinBox_07_WatershedCustom_Mask_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_07_WatershedCustom_Mask_Thres"));
        doubleSpinBox_07_WatershedCustom_Mask_Thres->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_07_WatershedCustom_Mask_Thres->setDecimals(3);
        doubleSpinBox_07_WatershedCustom_Mask_Thres->setMaximum(999999.000000000000000);
        doubleSpinBox_07_WatershedCustom_Mask_Thres->setValue(127.000000000000000);

        gridLayout_132->addWidget(doubleSpinBox_07_WatershedCustom_Mask_Thres, 0, 0, 1, 1);

        stackedWidget_07_WatershedCustom_Mask->addWidget(page_07_WatershedCustom_Mask_Thres);

        gridLayout_126->addWidget(stackedWidget_07_WatershedCustom_Mask, 2, 2, 1, 1);

        label_15 = new QLabel(page_07_WatershedCustom);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_126->addWidget(label_15, 6, 0, 1, 1);

        horizontalSpacer_07_WatershedCustom = new QSpacerItem(134, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_126->addItem(horizontalSpacer_07_WatershedCustom, 4, 2, 3, 1);

        horizontalLayout_07_WatershedCustom_DrawWatershed = new QHBoxLayout();
        horizontalLayout_07_WatershedCustom_DrawWatershed->setObjectName(QString::fromUtf8("horizontalLayout_07_WatershedCustom_DrawWatershed"));
        checkBox_07_WatershedCustom_DrawWatershed = new QCheckBox(page_07_WatershedCustom);
        checkBox_07_WatershedCustom_DrawWatershed->setObjectName(QString::fromUtf8("checkBox_07_WatershedCustom_DrawWatershed"));
        checkBox_07_WatershedCustom_DrawWatershed->setEnabled(true);
        sizePolicy9.setHeightForWidth(checkBox_07_WatershedCustom_DrawWatershed->sizePolicy().hasHeightForWidth());
        checkBox_07_WatershedCustom_DrawWatershed->setSizePolicy(sizePolicy9);
        checkBox_07_WatershedCustom_DrawWatershed->setChecked(true);

        horizontalLayout_07_WatershedCustom_DrawWatershed->addWidget(checkBox_07_WatershedCustom_DrawWatershed);

        stackedWidget_07_WatershedCustom_DrawWatershed = new QStackedWidget(page_07_WatershedCustom);
        stackedWidget_07_WatershedCustom_DrawWatershed->setObjectName(QString::fromUtf8("stackedWidget_07_WatershedCustom_DrawWatershed"));
        page_07_WatershedCustom_DrawWatershed_No = new QWidget();
        page_07_WatershedCustom_DrawWatershed_No->setObjectName(QString::fromUtf8("page_07_WatershedCustom_DrawWatershed_No"));
        stackedWidget_07_WatershedCustom_DrawWatershed->addWidget(page_07_WatershedCustom_DrawWatershed_No);
        page_07_WatershedCustom_DrawWatershed_Yes = new QWidget();
        page_07_WatershedCustom_DrawWatershed_Yes->setObjectName(QString::fromUtf8("page_07_WatershedCustom_DrawWatershed_Yes"));
        gridLayout_129 = new QGridLayout(page_07_WatershedCustom_DrawWatershed_Yes);
        gridLayout_129->setObjectName(QString::fromUtf8("gridLayout_129"));
        gridLayout_129->setContentsMargins(0, 0, 0, 0);
        comboBox_07_WatershedCustom_DrawWatershed_Neighborhood = new QComboBox(page_07_WatershedCustom_DrawWatershed_Yes);
        comboBox_07_WatershedCustom_DrawWatershed_Neighborhood->addItem(QString());
        comboBox_07_WatershedCustom_DrawWatershed_Neighborhood->addItem(QString());
        comboBox_07_WatershedCustom_DrawWatershed_Neighborhood->setObjectName(QString::fromUtf8("comboBox_07_WatershedCustom_DrawWatershed_Neighborhood"));

        gridLayout_129->addWidget(comboBox_07_WatershedCustom_DrawWatershed_Neighborhood, 0, 0, 1, 1);

        stackedWidget_07_WatershedCustom_DrawWatershed->addWidget(page_07_WatershedCustom_DrawWatershed_Yes);

        horizontalLayout_07_WatershedCustom_DrawWatershed->addWidget(stackedWidget_07_WatershedCustom_DrawWatershed);


        gridLayout_126->addLayout(horizontalLayout_07_WatershedCustom_DrawWatershed, 6, 1, 1, 1);

        stackedWidget_07_Watershed->addWidget(page_07_WatershedCustom);
        page_07_Watershed_OpenCV = new QWidget();
        page_07_Watershed_OpenCV->setObjectName(QString::fromUtf8("page_07_Watershed_OpenCV"));
        gridLayout_125 = new QGridLayout(page_07_Watershed_OpenCV);
        gridLayout_125->setObjectName(QString::fromUtf8("gridLayout_125"));
        gridLayout_125->setContentsMargins(0, 0, 0, 0);
        label_07_Watershed_8bit_Description = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_8bit_Description->setObjectName(QString::fromUtf8("label_07_Watershed_8bit_Description"));

        gridLayout_125->addWidget(label_07_Watershed_8bit_Description, 7, 2, 1, 1);

        label_07_Watershed_8bit = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_8bit->setObjectName(QString::fromUtf8("label_07_Watershed_8bit"));
        label_07_Watershed_8bit->setMinimumSize(QSize(100, 0));
        label_07_Watershed_8bit->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_8bit, 7, 0, 1, 1);

        comboBox_07_Watershed_Connectivity = new QComboBox(page_07_Watershed_OpenCV);
        comboBox_07_Watershed_Connectivity->addItem(QString());
        comboBox_07_Watershed_Connectivity->addItem(QString());
        comboBox_07_Watershed_Connectivity->setObjectName(QString::fromUtf8("comboBox_07_Watershed_Connectivity"));
        comboBox_07_Watershed_Connectivity->setMaximumSize(QSize(170, 16777215));

        gridLayout_125->addWidget(comboBox_07_Watershed_Connectivity, 5, 1, 1, 1);

        label_07_Watershed_InclNonSeed_Description = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_InclNonSeed_Description->setObjectName(QString::fromUtf8("label_07_Watershed_InclNonSeed_Description"));

        gridLayout_125->addWidget(label_07_Watershed_InclNonSeed_Description, 6, 2, 1, 1);

        label_07_Watershed_Markers_Desription = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Markers_Desription->setObjectName(QString::fromUtf8("label_07_Watershed_Markers_Desription"));
        label_07_Watershed_Markers_Desription->setMinimumSize(QSize(150, 0));

        gridLayout_125->addWidget(label_07_Watershed_Markers_Desription, 1, 2, 1, 1);

        label_07_Watershed_InclNonSeed = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_InclNonSeed->setObjectName(QString::fromUtf8("label_07_Watershed_InclNonSeed"));
        label_07_Watershed_InclNonSeed->setMinimumSize(QSize(100, 0));
        label_07_Watershed_InclNonSeed->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_InclNonSeed, 6, 0, 1, 1);

        checkBox_07_Watershed_InclNonSeed = new QCheckBox(page_07_Watershed_OpenCV);
        checkBox_07_Watershed_InclNonSeed->setObjectName(QString::fromUtf8("checkBox_07_Watershed_InclNonSeed"));
        checkBox_07_Watershed_InclNonSeed->setMaximumSize(QSize(170, 16777215));
        checkBox_07_Watershed_InclNonSeed->setChecked(true);

        gridLayout_125->addWidget(checkBox_07_Watershed_InclNonSeed, 6, 1, 1, 1);

        label_07_Watersehd_Input = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watersehd_Input->setObjectName(QString::fromUtf8("label_07_Watersehd_Input"));
        label_07_Watersehd_Input->setMinimumSize(QSize(100, 0));
        label_07_Watersehd_Input->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watersehd_Input, 0, 0, 1, 1);

        label_07_Watershed_Markers_Source = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Markers_Source->setObjectName(QString::fromUtf8("label_07_Watershed_Markers_Source"));
        label_07_Watershed_Markers_Source->setMinimumSize(QSize(0, 0));
        label_07_Watershed_Markers_Source->setMaximumSize(QSize(170, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_Markers_Source, 1, 1, 1, 1);

        label_07_Watershed_Auto_Description = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Auto_Description->setObjectName(QString::fromUtf8("label_07_Watershed_Auto_Description"));

        gridLayout_125->addWidget(label_07_Watershed_Auto_Description, 3, 2, 1, 1);

        checkBox_07_Watershed_ExclBorder = new QCheckBox(page_07_Watershed_OpenCV);
        checkBox_07_Watershed_ExclBorder->setObjectName(QString::fromUtf8("checkBox_07_Watershed_ExclBorder"));
        checkBox_07_Watershed_ExclBorder->setMaximumSize(QSize(170, 16777215));
        checkBox_07_Watershed_ExclBorder->setChecked(true);

        gridLayout_125->addWidget(checkBox_07_Watershed_ExclBorder, 8, 1, 1, 1);

        label_07_Watershed_Input_Source = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Input_Source->setObjectName(QString::fromUtf8("label_07_Watershed_Input_Source"));
        label_07_Watershed_Input_Source->setMinimumSize(QSize(100, 0));
        label_07_Watershed_Input_Source->setMaximumSize(QSize(170, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_Input_Source, 0, 1, 1, 1);

        label_07_Watershed_Connectivity = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Connectivity->setObjectName(QString::fromUtf8("label_07_Watershed_Connectivity"));
        label_07_Watershed_Connectivity->setMinimumSize(QSize(100, 0));
        label_07_Watershed_Connectivity->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_Connectivity, 5, 0, 1, 1);

        label_07_Watershed_Markers = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Markers->setObjectName(QString::fromUtf8("label_07_Watershed_Markers"));
        label_07_Watershed_Markers->setMinimumSize(QSize(100, 0));
        label_07_Watershed_Markers->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_Markers, 1, 0, 1, 1);

        label_07_Watershed_ExclBor = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_ExclBor->setObjectName(QString::fromUtf8("label_07_Watershed_ExclBor"));
        label_07_Watershed_ExclBor->setMinimumSize(QSize(100, 0));
        label_07_Watershed_ExclBor->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_ExclBor, 8, 0, 1, 1);

        line_07_Watershed_2 = new QFrame(page_07_Watershed_OpenCV);
        line_07_Watershed_2->setObjectName(QString::fromUtf8("line_07_Watershed_2"));
        line_07_Watershed_2->setFrameShape(QFrame::HLine);
        line_07_Watershed_2->setFrameShadow(QFrame::Sunken);

        gridLayout_125->addWidget(line_07_Watershed_2, 2, 0, 1, 4);

        checkBox_07_Watershed_8bit = new QCheckBox(page_07_Watershed_OpenCV);
        checkBox_07_Watershed_8bit->setObjectName(QString::fromUtf8("checkBox_07_Watershed_8bit"));
        checkBox_07_Watershed_8bit->setEnabled(true);
        checkBox_07_Watershed_8bit->setMaximumSize(QSize(170, 16777215));
        checkBox_07_Watershed_8bit->setChecked(false);

        gridLayout_125->addWidget(checkBox_07_Watershed_8bit, 7, 1, 1, 1);

        line_07_Watershed_3 = new QFrame(page_07_Watershed_OpenCV);
        line_07_Watershed_3->setObjectName(QString::fromUtf8("line_07_Watershed_3"));
        line_07_Watershed_3->setFrameShape(QFrame::HLine);
        line_07_Watershed_3->setFrameShadow(QFrame::Sunken);

        gridLayout_125->addWidget(line_07_Watershed_3, 4, 0, 1, 4);

        horizontalSpacer_07_Watershed = new QSpacerItem(16, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_125->addItem(horizontalSpacer_07_Watershed, 0, 3, 1, 1);

        label_07_Watershed_Input_Desciption = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Input_Desciption->setObjectName(QString::fromUtf8("label_07_Watershed_Input_Desciption"));
        label_07_Watershed_Input_Desciption->setMinimumSize(QSize(150, 0));

        gridLayout_125->addWidget(label_07_Watershed_Input_Desciption, 0, 2, 1, 1);

        verticalSpacer_07_Watershed = new QSpacerItem(0, 27, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_125->addItem(verticalSpacer_07_Watershed, 9, 2, 1, 1);

        label_07_Watershed_Auto = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Auto->setObjectName(QString::fromUtf8("label_07_Watershed_Auto"));
        label_07_Watershed_Auto->setMinimumSize(QSize(100, 0));
        label_07_Watershed_Auto->setMaximumSize(QSize(100, 16777215));

        gridLayout_125->addWidget(label_07_Watershed_Auto, 3, 0, 1, 1);

        label_07_Watershed_Connectivity_2 = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_Connectivity_2->setObjectName(QString::fromUtf8("label_07_Watershed_Connectivity_2"));

        gridLayout_125->addWidget(label_07_Watershed_Connectivity_2, 5, 2, 1, 1);

        checkBox_07_Watershed_Auto = new QCheckBox(page_07_Watershed_OpenCV);
        checkBox_07_Watershed_Auto->setObjectName(QString::fromUtf8("checkBox_07_Watershed_Auto"));
        checkBox_07_Watershed_Auto->setMaximumSize(QSize(170, 16777215));
        checkBox_07_Watershed_Auto->setChecked(true);

        gridLayout_125->addWidget(checkBox_07_Watershed_Auto, 3, 1, 1, 1);

        label_07_Watershed_ExclBorder_Description = new QLabel(page_07_Watershed_OpenCV);
        label_07_Watershed_ExclBorder_Description->setObjectName(QString::fromUtf8("label_07_Watershed_ExclBorder_Description"));

        gridLayout_125->addWidget(label_07_Watershed_ExclBorder_Description, 8, 2, 1, 1);

        stackedWidget_07_Watershed->addWidget(page_07_Watershed_OpenCV);

        gridLayout_41->addWidget(stackedWidget_07_Watershed, 1, 0, 1, 3);

        stackedWidget_Settings_07_Transform->addWidget(page_07_Watershade);
        page_07_Fourier = new QWidget();
        page_07_Fourier->setObjectName(QString::fromUtf8("page_07_Fourier"));
        gridLayout_45 = new QGridLayout(page_07_Fourier);
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_45->setVerticalSpacing(6);
        label_07_Fourier_Input_Complex = new QLabel(page_07_Fourier);
        label_07_Fourier_Input_Complex->setObjectName(QString::fromUtf8("label_07_Fourier_Input_Complex"));
        label_07_Fourier_Input_Complex->setEnabled(false);
        label_07_Fourier_Input_Complex->setMinimumSize(QSize(75, 0));
        label_07_Fourier_Input_Complex->setMaximumSize(QSize(75, 16777215));

        gridLayout_45->addWidget(label_07_Fourier_Input_Complex, 0, 1, 1, 1);

        checkBox_07_Fourier_Output_Scale = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_Output_Scale->setObjectName(QString::fromUtf8("checkBox_07_Fourier_Output_Scale"));
        checkBox_07_Fourier_Output_Scale->setMinimumSize(QSize(150, 0));
        checkBox_07_Fourier_Output_Scale->setMaximumSize(QSize(150, 20));

        gridLayout_45->addWidget(checkBox_07_Fourier_Output_Scale, 8, 2, 1, 1);

        line_07_Fourier_2 = new QFrame(page_07_Fourier);
        line_07_Fourier_2->setObjectName(QString::fromUtf8("line_07_Fourier_2"));
        line_07_Fourier_2->setFrameShape(QFrame::HLine);
        line_07_Fourier_2->setFrameShadow(QFrame::Sunken);

        gridLayout_45->addWidget(line_07_Fourier_2, 5, 1, 1, 3);

        checkBox_07_Fourier_Input_Complex = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_Input_Complex->setObjectName(QString::fromUtf8("checkBox_07_Fourier_Input_Complex"));
        checkBox_07_Fourier_Input_Complex->setEnabled(false);
        checkBox_07_Fourier_Input_Complex->setMinimumSize(QSize(150, 0));
        checkBox_07_Fourier_Input_Complex->setMaximumSize(QSize(150, 20));

        gridLayout_45->addWidget(checkBox_07_Fourier_Input_Complex, 0, 2, 1, 1);

        comboBox_07_Fourier_Output_ComplexMode = new QComboBox(page_07_Fourier);
        comboBox_07_Fourier_Output_ComplexMode->addItem(QString());
        comboBox_07_Fourier_Output_ComplexMode->setObjectName(QString::fromUtf8("comboBox_07_Fourier_Output_ComplexMode"));
        comboBox_07_Fourier_Output_ComplexMode->setEnabled(true);
        comboBox_07_Fourier_Output_ComplexMode->setMinimumSize(QSize(150, 0));
        comboBox_07_Fourier_Output_ComplexMode->setMaximumSize(QSize(150, 20));

        gridLayout_45->addWidget(comboBox_07_Fourier_Output_ComplexMode, 7, 2, 1, 1);

        label_07_Fourier_Output_Centered = new QLabel(page_07_Fourier);
        label_07_Fourier_Output_Centered->setObjectName(QString::fromUtf8("label_07_Fourier_Output_Centered"));

        gridLayout_45->addWidget(label_07_Fourier_Output_Centered, 9, 1, 1, 1);

        checkBox_07_Fourier_ForceFFT = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_ForceFFT->setObjectName(QString::fromUtf8("checkBox_07_Fourier_ForceFFT"));
        checkBox_07_Fourier_ForceFFT->setEnabled(false);
        checkBox_07_Fourier_ForceFFT->setMinimumSize(QSize(0, 0));
        checkBox_07_Fourier_ForceFFT->setMaximumSize(QSize(16777215, 20));
        checkBox_07_Fourier_ForceFFT->setChecked(false);

        gridLayout_45->addWidget(checkBox_07_Fourier_ForceFFT, 4, 2, 1, 1);

        label_07_Fourier_OptimalSize = new QLabel(page_07_Fourier);
        label_07_Fourier_OptimalSize->setObjectName(QString::fromUtf8("label_07_Fourier_OptimalSize"));
        label_07_Fourier_OptimalSize->setEnabled(false);

        gridLayout_45->addWidget(label_07_Fourier_OptimalSize, 4, 1, 1, 1);

        line_07_Fourier = new QFrame(page_07_Fourier);
        line_07_Fourier->setObjectName(QString::fromUtf8("line_07_Fourier"));
        line_07_Fourier->setFrameShape(QFrame::VLine);
        line_07_Fourier->setFrameShadow(QFrame::Sunken);

        gridLayout_45->addWidget(line_07_Fourier, 0, 0, 12, 1);

        horizontalSpacer_07_Fourier = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_45->addItem(horizontalSpacer_07_Fourier, 7, 3, 2, 1);

        checkBox_07_Fourier_Invers = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_Invers->setObjectName(QString::fromUtf8("checkBox_07_Fourier_Invers"));
        checkBox_07_Fourier_Invers->setMinimumSize(QSize(150, 0));
        checkBox_07_Fourier_Invers->setMaximumSize(QSize(150, 20));

        gridLayout_45->addWidget(checkBox_07_Fourier_Invers, 2, 2, 2, 1);

        checkBox_07_Fourier_Output_RealOnly = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_Output_RealOnly->setObjectName(QString::fromUtf8("checkBox_07_Fourier_Output_RealOnly"));
        checkBox_07_Fourier_Output_RealOnly->setMinimumSize(QSize(150, 0));
        checkBox_07_Fourier_Output_RealOnly->setMaximumSize(QSize(150, 20));
        checkBox_07_Fourier_Output_RealOnly->setChecked(false);

        gridLayout_45->addWidget(checkBox_07_Fourier_Output_RealOnly, 6, 2, 1, 1);

        label_07_Fourier_Output_no_f0 = new QLabel(page_07_Fourier);
        label_07_Fourier_Output_no_f0->setObjectName(QString::fromUtf8("label_07_Fourier_Output_no_f0"));
        label_07_Fourier_Output_no_f0->setEnabled(true);

        gridLayout_45->addWidget(label_07_Fourier_Output_no_f0, 10, 1, 1, 1);

        label_07_Fourier_Output_ComplexMode = new QLabel(page_07_Fourier);
        label_07_Fourier_Output_ComplexMode->setObjectName(QString::fromUtf8("label_07_Fourier_Output_ComplexMode"));
        label_07_Fourier_Output_ComplexMode->setEnabled(true);
        label_07_Fourier_Output_ComplexMode->setMinimumSize(QSize(75, 0));
        label_07_Fourier_Output_ComplexMode->setMaximumSize(QSize(75, 16777215));

        gridLayout_45->addWidget(label_07_Fourier_Output_ComplexMode, 7, 1, 1, 1);

        label_07_Fourier_Output_RealOnly = new QLabel(page_07_Fourier);
        label_07_Fourier_Output_RealOnly->setObjectName(QString::fromUtf8("label_07_Fourier_Output_RealOnly"));
        label_07_Fourier_Output_RealOnly->setMinimumSize(QSize(75, 0));
        label_07_Fourier_Output_RealOnly->setMaximumSize(QSize(75, 16777215));

        gridLayout_45->addWidget(label_07_Fourier_Output_RealOnly, 6, 1, 1, 1);

        label_07_Fourier_Invers = new QLabel(page_07_Fourier);
        label_07_Fourier_Invers->setObjectName(QString::fromUtf8("label_07_Fourier_Invers"));
        label_07_Fourier_Invers->setMinimumSize(QSize(75, 0));
        label_07_Fourier_Invers->setMaximumSize(QSize(75, 16777215));

        gridLayout_45->addWidget(label_07_Fourier_Invers, 2, 1, 2, 1);

        checkBox_07_Fourier_Output_Centered = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_Output_Centered->setObjectName(QString::fromUtf8("checkBox_07_Fourier_Output_Centered"));
        checkBox_07_Fourier_Output_Centered->setMinimumSize(QSize(0, 0));
        checkBox_07_Fourier_Output_Centered->setMaximumSize(QSize(16777215, 20));
        checkBox_07_Fourier_Output_Centered->setChecked(true);

        gridLayout_45->addWidget(checkBox_07_Fourier_Output_Centered, 9, 2, 1, 1);

        line_07_Fourier_1 = new QFrame(page_07_Fourier);
        line_07_Fourier_1->setObjectName(QString::fromUtf8("line_07_Fourier_1"));
        line_07_Fourier_1->setFrameShape(QFrame::HLine);
        line_07_Fourier_1->setFrameShadow(QFrame::Sunken);

        gridLayout_45->addWidget(line_07_Fourier_1, 1, 1, 1, 3);

        checkBox_07_Fourier_Output_no_f0 = new QCheckBox(page_07_Fourier);
        checkBox_07_Fourier_Output_no_f0->setObjectName(QString::fromUtf8("checkBox_07_Fourier_Output_no_f0"));
        checkBox_07_Fourier_Output_no_f0->setEnabled(true);
        checkBox_07_Fourier_Output_no_f0->setMinimumSize(QSize(0, 0));
        checkBox_07_Fourier_Output_no_f0->setMaximumSize(QSize(16777215, 20));
        checkBox_07_Fourier_Output_no_f0->setChecked(true);

        gridLayout_45->addWidget(checkBox_07_Fourier_Output_no_f0, 10, 2, 1, 1);

        label_07_Fourier_Output_Scale = new QLabel(page_07_Fourier);
        label_07_Fourier_Output_Scale->setObjectName(QString::fromUtf8("label_07_Fourier_Output_Scale"));
        label_07_Fourier_Output_Scale->setMinimumSize(QSize(75, 0));
        label_07_Fourier_Output_Scale->setMaximumSize(QSize(75, 16777215));

        gridLayout_45->addWidget(label_07_Fourier_Output_Scale, 8, 1, 1, 1);

        verticalSpacer_07_Fourier = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_45->addItem(verticalSpacer_07_Fourier, 11, 3, 1, 1);

        stackedWidget_Settings_07_Transform->addWidget(page_07_Fourier);
        page_07_Radon = new QWidget();
        page_07_Radon->setObjectName(QString::fromUtf8("page_07_Radon"));
        stackedWidget_Settings_07_Transform->addWidget(page_07_Radon);

        gridLayout_24->addWidget(stackedWidget_Settings_07_Transform, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_07_Transform);
        page_Settings_08_Features = new QWidget();
        page_Settings_08_Features->setObjectName(QString::fromUtf8("page_Settings_08_Features"));
        gridLayout_25 = new QGridLayout(page_Settings_08_Features);
        gridLayout_25->setSpacing(0);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_08_Features = new QStackedWidget(page_Settings_08_Features);
        stackedWidget_Settings_08_Features->setObjectName(QString::fromUtf8("stackedWidget_Settings_08_Features"));
        page_08_FeatVal = new QWidget();
        page_08_FeatVal->setObjectName(QString::fromUtf8("page_08_FeatVal"));
        gridLayout_74 = new QGridLayout(page_08_FeatVal);
        gridLayout_74->setSpacing(3);
        gridLayout_74->setObjectName(QString::fromUtf8("gridLayout_74"));
        gridLayout_74->setContentsMargins(6, 6, 6, 6);
        line_08_FeatVal = new QFrame(page_08_FeatVal);
        line_08_FeatVal->setObjectName(QString::fromUtf8("line_08_FeatVal"));
        line_08_FeatVal->setFrameShape(QFrame::VLine);
        line_08_FeatVal->setFrameShadow(QFrame::Sunken);

        gridLayout_74->addWidget(line_08_FeatVal, 0, 0, 4, 1);

        horizontalSpacer_08_FeatVal = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_74->addItem(horizontalSpacer_08_FeatVal, 0, 3, 2, 1);

        label_08_FeatVal_Connectivity = new QLabel(page_08_FeatVal);
        label_08_FeatVal_Connectivity->setObjectName(QString::fromUtf8("label_08_FeatVal_Connectivity"));
        label_08_FeatVal_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_FeatVal_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_74->addWidget(label_08_FeatVal_Connectivity, 1, 1, 1, 1);

        comboBox_08_FeatVal_Connectivity = new QComboBox(page_08_FeatVal);
        comboBox_08_FeatVal_Connectivity->addItem(QString());
        comboBox_08_FeatVal_Connectivity->addItem(QString());
        comboBox_08_FeatVal_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_FeatVal_Connectivity"));
        comboBox_08_FeatVal_Connectivity->setMinimumSize(QSize(300, 0));
        comboBox_08_FeatVal_Connectivity->setMaximumSize(QSize(250, 16777215));

        gridLayout_74->addWidget(comboBox_08_FeatVal_Connectivity, 1, 2, 1, 1);

        verticalSpacer_08_FeatVal = new QSpacerItem(20, 147, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_74->addItem(verticalSpacer_08_FeatVal, 3, 1, 1, 1);

        comboBox_08_FeatVal_Feature = new QComboBox(page_08_FeatVal);
        comboBox_08_FeatVal_Feature->setObjectName(QString::fromUtf8("comboBox_08_FeatVal_Feature"));
        comboBox_08_FeatVal_Feature->setMinimumSize(QSize(300, 0));
        comboBox_08_FeatVal_Feature->setMaximumSize(QSize(250, 16777215));

        gridLayout_74->addWidget(comboBox_08_FeatVal_Feature, 2, 2, 1, 1);

        label_08_FeatVal_Feature = new QLabel(page_08_FeatVal);
        label_08_FeatVal_Feature->setObjectName(QString::fromUtf8("label_08_FeatVal_Feature"));
        label_08_FeatVal_Feature->setMinimumSize(QSize(80, 0));
        label_08_FeatVal_Feature->setMaximumSize(QSize(80, 16777215));

        gridLayout_74->addWidget(label_08_FeatVal_Feature, 2, 1, 1, 1);

        stackedWidget_Settings_08_Features->addWidget(page_08_FeatVal);
        page_08_FeatContextVal = new QWidget();
        page_08_FeatContextVal->setObjectName(QString::fromUtf8("page_08_FeatContextVal"));
        gridLayout_95 = new QGridLayout(page_08_FeatContextVal);
        gridLayout_95->setSpacing(3);
        gridLayout_95->setObjectName(QString::fromUtf8("gridLayout_95"));
        gridLayout_95->setContentsMargins(6, 6, 6, 6);
        label_08_FeatContextVal_Connectivity = new QLabel(page_08_FeatContextVal);
        label_08_FeatContextVal_Connectivity->setObjectName(QString::fromUtf8("label_08_FeatContextVal_Connectivity"));
        label_08_FeatContextVal_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_FeatContextVal_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_95->addWidget(label_08_FeatContextVal_Connectivity, 0, 1, 1, 1);

        line_08_FeatContextVal_1 = new QFrame(page_08_FeatContextVal);
        line_08_FeatContextVal_1->setObjectName(QString::fromUtf8("line_08_FeatContextVal_1"));
        line_08_FeatContextVal_1->setFrameShape(QFrame::VLine);
        line_08_FeatContextVal_1->setFrameShadow(QFrame::Sunken);

        gridLayout_95->addWidget(line_08_FeatContextVal_1, 0, 0, 9, 1);

        comboBox_08_FeatContextVal_Connectivity = new QComboBox(page_08_FeatContextVal);
        comboBox_08_FeatContextVal_Connectivity->addItem(QString());
        comboBox_08_FeatContextVal_Connectivity->addItem(QString());
        comboBox_08_FeatContextVal_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_FeatContextVal_Connectivity"));

        gridLayout_95->addWidget(comboBox_08_FeatContextVal_Connectivity, 0, 2, 1, 2);

        comboBox_08_FeatContextVal_Stat = new QComboBox(page_08_FeatContextVal);
        comboBox_08_FeatContextVal_Stat->setObjectName(QString::fromUtf8("comboBox_08_FeatContextVal_Stat"));
        comboBox_08_FeatContextVal_Stat->setMinimumSize(QSize(300, 0));
        comboBox_08_FeatContextVal_Stat->setMaximumSize(QSize(300, 16777215));

        gridLayout_95->addWidget(comboBox_08_FeatContextVal_Stat, 7, 2, 1, 2);

        verticalSpacer_08_FeatContextVal = new QSpacerItem(20, 64, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_95->addItem(verticalSpacer_08_FeatContextVal, 8, 1, 1, 1);

        horizontalSpacer_08_FeatContextVal = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_95->addItem(horizontalSpacer_08_FeatContextVal, 0, 4, 1, 1);

        line_08_FeatContextVal_2 = new QFrame(page_08_FeatContextVal);
        line_08_FeatContextVal_2->setObjectName(QString::fromUtf8("line_08_FeatContextVal_2"));
        line_08_FeatContextVal_2->setFrameShape(QFrame::HLine);
        line_08_FeatContextVal_2->setFrameShadow(QFrame::Sunken);

        gridLayout_95->addWidget(line_08_FeatContextVal_2, 1, 1, 1, 4);

        comboBox_08_FeatContextVal_Feat = new QComboBox(page_08_FeatContextVal);
        comboBox_08_FeatContextVal_Feat->setObjectName(QString::fromUtf8("comboBox_08_FeatContextVal_Feat"));
        comboBox_08_FeatContextVal_Feat->setMinimumSize(QSize(300, 0));
        comboBox_08_FeatContextVal_Feat->setMaximumSize(QSize(300, 16777215));

        gridLayout_95->addWidget(comboBox_08_FeatContextVal_Feat, 6, 2, 1, 2);

        doubleSpinBox_08_FeatContextVal_DistMax = new QDoubleSpinBox(page_08_FeatContextVal);
        doubleSpinBox_08_FeatContextVal_DistMax->setObjectName(QString::fromUtf8("doubleSpinBox_08_FeatContextVal_DistMax"));
        doubleSpinBox_08_FeatContextVal_DistMax->setDecimals(3);
        doubleSpinBox_08_FeatContextVal_DistMax->setMaximum(100000000000000000.000000000000000);
        doubleSpinBox_08_FeatContextVal_DistMax->setValue(3.000000000000000);

        gridLayout_95->addWidget(doubleSpinBox_08_FeatContextVal_DistMax, 4, 3, 1, 1);

        line_08_FeatContextVal_3 = new QFrame(page_08_FeatContextVal);
        line_08_FeatContextVal_3->setObjectName(QString::fromUtf8("line_08_FeatContextVal_3"));
        line_08_FeatContextVal_3->setFrameShape(QFrame::HLine);
        line_08_FeatContextVal_3->setFrameShadow(QFrame::Sunken);

        gridLayout_95->addWidget(line_08_FeatContextVal_3, 5, 1, 1, 4);

        label_08_FeatContextVal_DistanceFrom = new QLabel(page_08_FeatContextVal);
        label_08_FeatContextVal_DistanceFrom->setObjectName(QString::fromUtf8("label_08_FeatContextVal_DistanceFrom"));
        label_08_FeatContextVal_DistanceFrom->setMinimumSize(QSize(80, 0));
        label_08_FeatContextVal_DistanceFrom->setMaximumSize(QSize(80, 16777215));

        gridLayout_95->addWidget(label_08_FeatContextVal_DistanceFrom, 2, 1, 1, 1);

        doubleSpinBox_08_FeatContextVal_DistMin = new QDoubleSpinBox(page_08_FeatContextVal);
        doubleSpinBox_08_FeatContextVal_DistMin->setObjectName(QString::fromUtf8("doubleSpinBox_08_FeatContextVal_DistMin"));
        doubleSpinBox_08_FeatContextVal_DistMin->setDecimals(3);
        doubleSpinBox_08_FeatContextVal_DistMin->setMaximum(100000000000000000.000000000000000);

        gridLayout_95->addWidget(doubleSpinBox_08_FeatContextVal_DistMin, 4, 2, 1, 1);

        label_08_FeatContextVal_Feat = new QLabel(page_08_FeatContextVal);
        label_08_FeatContextVal_Feat->setObjectName(QString::fromUtf8("label_08_FeatContextVal_Feat"));
        label_08_FeatContextVal_Feat->setMinimumSize(QSize(80, 0));
        label_08_FeatContextVal_Feat->setMaximumSize(QSize(80, 16777215));

        gridLayout_95->addWidget(label_08_FeatContextVal_Feat, 6, 1, 1, 1);

        label_08_FeatContextVal_Stat = new QLabel(page_08_FeatContextVal);
        label_08_FeatContextVal_Stat->setObjectName(QString::fromUtf8("label_08_FeatContextVal_Stat"));
        label_08_FeatContextVal_Stat->setMinimumSize(QSize(80, 0));
        label_08_FeatContextVal_Stat->setMaximumSize(QSize(80, 16777215));

        gridLayout_95->addWidget(label_08_FeatContextVal_Stat, 7, 1, 1, 1);

        label_08_FeatContextVal_DistanceRange = new QLabel(page_08_FeatContextVal);
        label_08_FeatContextVal_DistanceRange->setObjectName(QString::fromUtf8("label_08_FeatContextVal_DistanceRange"));
        label_08_FeatContextVal_DistanceRange->setMinimumSize(QSize(80, 0));
        label_08_FeatContextVal_DistanceRange->setMaximumSize(QSize(80, 16777215));

        gridLayout_95->addWidget(label_08_FeatContextVal_DistanceRange, 4, 1, 1, 1);

        label_08_FeatContextVal_DistanceTo = new QLabel(page_08_FeatContextVal);
        label_08_FeatContextVal_DistanceTo->setObjectName(QString::fromUtf8("label_08_FeatContextVal_DistanceTo"));

        gridLayout_95->addWidget(label_08_FeatContextVal_DistanceTo, 3, 1, 1, 1);

        comboBox_08_FeatContextVal_DistPt2 = new QComboBox(page_08_FeatContextVal);
        comboBox_08_FeatContextVal_DistPt2->setObjectName(QString::fromUtf8("comboBox_08_FeatContextVal_DistPt2"));

        gridLayout_95->addWidget(comboBox_08_FeatContextVal_DistPt2, 3, 2, 1, 2);

        comboBox_08_FeatContextVal_DistPt1 = new QComboBox(page_08_FeatContextVal);
        comboBox_08_FeatContextVal_DistPt1->setObjectName(QString::fromUtf8("comboBox_08_FeatContextVal_DistPt1"));

        gridLayout_95->addWidget(comboBox_08_FeatContextVal_DistPt1, 2, 2, 1, 2);

        stackedWidget_Settings_08_Features->addWidget(page_08_FeatContextVal);
        page_08_Select = new QWidget();
        page_08_Select->setObjectName(QString::fromUtf8("page_08_Select"));
        gridLayout_60 = new QGridLayout(page_08_Select);
        gridLayout_60->setSpacing(3);
        gridLayout_60->setObjectName(QString::fromUtf8("gridLayout_60"));
        gridLayout_60->setContentsMargins(6, 6, 6, 6);
        doubleSpinBox_08_Select_Max = new QDoubleSpinBox(page_08_Select);
        doubleSpinBox_08_Select_Max->setObjectName(QString::fromUtf8("doubleSpinBox_08_Select_Max"));
        doubleSpinBox_08_Select_Max->setMinimumSize(QSize(0, 0));
        doubleSpinBox_08_Select_Max->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_08_Select_Max->setDecimals(3);
        doubleSpinBox_08_Select_Max->setMinimum(-1000000000.000000000000000);
        doubleSpinBox_08_Select_Max->setMaximum(1000000000.000000000000000);
        doubleSpinBox_08_Select_Max->setValue(1000.000000000000000);

        gridLayout_60->addWidget(doubleSpinBox_08_Select_Max, 4, 3, 1, 1);

        label_08_Select_Connectivity = new QLabel(page_08_Select);
        label_08_Select_Connectivity->setObjectName(QString::fromUtf8("label_08_Select_Connectivity"));
        label_08_Select_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_Select_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_60->addWidget(label_08_Select_Connectivity, 1, 1, 1, 1);

        label_08_Select_Range = new QLabel(page_08_Select);
        label_08_Select_Range->setObjectName(QString::fromUtf8("label_08_Select_Range"));
        label_08_Select_Range->setMinimumSize(QSize(80, 0));
        label_08_Select_Range->setMaximumSize(QSize(80, 16777215));

        gridLayout_60->addWidget(label_08_Select_Range, 4, 1, 1, 1);

        line_08_Select_1 = new QFrame(page_08_Select);
        line_08_Select_1->setObjectName(QString::fromUtf8("line_08_Select_1"));
        line_08_Select_1->setFrameShape(QFrame::VLine);
        line_08_Select_1->setFrameShadow(QFrame::Sunken);

        gridLayout_60->addWidget(line_08_Select_1, 0, 0, 10, 1);

        comboBox_08_Select_Connectivity = new QComboBox(page_08_Select);
        comboBox_08_Select_Connectivity->addItem(QString());
        comboBox_08_Select_Connectivity->addItem(QString());
        comboBox_08_Select_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_Select_Connectivity"));
        comboBox_08_Select_Connectivity->setMinimumSize(QSize(300, 0));
        comboBox_08_Select_Connectivity->setMaximumSize(QSize(300, 16777215));

        gridLayout_60->addWidget(comboBox_08_Select_Connectivity, 1, 2, 1, 2);

        doubleSpinBox_08_Select_Step = new QDoubleSpinBox(page_08_Select);
        doubleSpinBox_08_Select_Step->setObjectName(QString::fromUtf8("doubleSpinBox_08_Select_Step"));
        doubleSpinBox_08_Select_Step->setMinimumSize(QSize(300, 0));
        doubleSpinBox_08_Select_Step->setMaximumSize(QSize(300, 16777215));
        doubleSpinBox_08_Select_Step->setDecimals(3);
        doubleSpinBox_08_Select_Step->setMinimum(0.000000000000000);
        doubleSpinBox_08_Select_Step->setMaximum(1000000000.000000000000000);
        doubleSpinBox_08_Select_Step->setValue(1.000000000000000);

        gridLayout_60->addWidget(doubleSpinBox_08_Select_Step, 6, 2, 1, 2);

        line_08_Select_2 = new QFrame(page_08_Select);
        line_08_Select_2->setObjectName(QString::fromUtf8("line_08_Select_2"));
        line_08_Select_2->setFrameShape(QFrame::HLine);
        line_08_Select_2->setFrameShadow(QFrame::Sunken);

        gridLayout_60->addWidget(line_08_Select_2, 5, 1, 1, 4);

        label_08_Select_Decimals = new QLabel(page_08_Select);
        label_08_Select_Decimals->setObjectName(QString::fromUtf8("label_08_Select_Decimals"));
        label_08_Select_Decimals->setMinimumSize(QSize(80, 0));
        label_08_Select_Decimals->setMaximumSize(QSize(80, 16777215));

        gridLayout_60->addWidget(label_08_Select_Decimals, 7, 1, 1, 1);

        label_08_Select_Step = new QLabel(page_08_Select);
        label_08_Select_Step->setObjectName(QString::fromUtf8("label_08_Select_Step"));
        label_08_Select_Step->setMinimumSize(QSize(80, 0));
        label_08_Select_Step->setMaximumSize(QSize(80, 16777215));

        gridLayout_60->addWidget(label_08_Select_Step, 6, 1, 1, 1);

        verticalSpacer_08_Select = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_60->addItem(verticalSpacer_08_Select, 8, 1, 1, 1);

        line_08_Select_3 = new QFrame(page_08_Select);
        line_08_Select_3->setObjectName(QString::fromUtf8("line_08_Select_3"));
        line_08_Select_3->setFrameShape(QFrame::HLine);
        line_08_Select_3->setFrameShadow(QFrame::Sunken);

        gridLayout_60->addWidget(line_08_Select_3, 3, 1, 1, 4);

        spinBox_08_Select_Decimals = new QSpinBox(page_08_Select);
        spinBox_08_Select_Decimals->setObjectName(QString::fromUtf8("spinBox_08_Select_Decimals"));
        spinBox_08_Select_Decimals->setMinimumSize(QSize(300, 0));
        spinBox_08_Select_Decimals->setMaximumSize(QSize(300, 16777215));
        spinBox_08_Select_Decimals->setMaximum(15);
        spinBox_08_Select_Decimals->setValue(3);

        gridLayout_60->addWidget(spinBox_08_Select_Decimals, 7, 2, 1, 2);

        comboBox_08_Select_Type = new QComboBox(page_08_Select);
        comboBox_08_Select_Type->setObjectName(QString::fromUtf8("comboBox_08_Select_Type"));
        comboBox_08_Select_Type->setMinimumSize(QSize(300, 0));
        comboBox_08_Select_Type->setMaximumSize(QSize(300, 16777215));

        gridLayout_60->addWidget(comboBox_08_Select_Type, 2, 2, 1, 2);

        label_08_Select_Type = new QLabel(page_08_Select);
        label_08_Select_Type->setObjectName(QString::fromUtf8("label_08_Select_Type"));
        label_08_Select_Type->setMinimumSize(QSize(80, 0));
        label_08_Select_Type->setMaximumSize(QSize(80, 16777215));

        gridLayout_60->addWidget(label_08_Select_Type, 2, 1, 1, 1);

        horizontalSpacer_08_Select = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_60->addItem(horizontalSpacer_08_Select, 1, 4, 2, 1);

        doubleSpinBox_08_Select_Min = new QDoubleSpinBox(page_08_Select);
        doubleSpinBox_08_Select_Min->setObjectName(QString::fromUtf8("doubleSpinBox_08_Select_Min"));
        doubleSpinBox_08_Select_Min->setMinimumSize(QSize(0, 0));
        doubleSpinBox_08_Select_Min->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_08_Select_Min->setDecimals(3);
        doubleSpinBox_08_Select_Min->setMinimum(-1000000000.000000000000000);
        doubleSpinBox_08_Select_Min->setMaximum(1000000000.000000000000000);

        gridLayout_60->addWidget(doubleSpinBox_08_Select_Min, 4, 2, 1, 1);

        stackedWidget_Settings_08_Features->addWidget(page_08_Select);
        page_08_SelectContext = new QWidget();
        page_08_SelectContext->setObjectName(QString::fromUtf8("page_08_SelectContext"));
        gridLayout_96 = new QGridLayout(page_08_SelectContext);
        gridLayout_96->setSpacing(3);
        gridLayout_96->setObjectName(QString::fromUtf8("gridLayout_96"));
        gridLayout_96->setContentsMargins(6, 6, 6, 6);
        comboBox_08_FeatContextSelect_Connectivity = new QComboBox(page_08_SelectContext);
        comboBox_08_FeatContextSelect_Connectivity->addItem(QString());
        comboBox_08_FeatContextSelect_Connectivity->addItem(QString());
        comboBox_08_FeatContextSelect_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_FeatContextSelect_Connectivity"));

        gridLayout_96->addWidget(comboBox_08_FeatContextSelect_Connectivity, 0, 2, 1, 2);

        verticalSpacer_08_FeatContextSelect = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_96->addItem(verticalSpacer_08_FeatContextSelect, 10, 1, 1, 1);

        line_08_FeatContextSelect_4 = new QFrame(page_08_SelectContext);
        line_08_FeatContextSelect_4->setObjectName(QString::fromUtf8("line_08_FeatContextSelect_4"));
        line_08_FeatContextSelect_4->setFrameShape(QFrame::HLine);
        line_08_FeatContextSelect_4->setFrameShadow(QFrame::Sunken);

        gridLayout_96->addWidget(line_08_FeatContextSelect_4, 8, 1, 1, 3);

        label_08_FeatContextSelect_Stat = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelect_Stat->setObjectName(QString::fromUtf8("label_08_FeatContextSelect_Stat"));
        label_08_FeatContextSelect_Stat->setMinimumSize(QSize(80, 0));
        label_08_FeatContextSelect_Stat->setMaximumSize(QSize(80, 16777215));

        gridLayout_96->addWidget(label_08_FeatContextSelect_Stat, 7, 1, 1, 1);

        comboBox_08_FeatContextSelect_Feat = new QComboBox(page_08_SelectContext);
        comboBox_08_FeatContextSelect_Feat->setObjectName(QString::fromUtf8("comboBox_08_FeatContextSelect_Feat"));
        comboBox_08_FeatContextSelect_Feat->setMinimumSize(QSize(300, 0));
        comboBox_08_FeatContextSelect_Feat->setMaximumSize(QSize(300, 16777215));

        gridLayout_96->addWidget(comboBox_08_FeatContextSelect_Feat, 6, 2, 1, 2);

        label_08_FeatContextSelect_Range = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelect_Range->setObjectName(QString::fromUtf8("label_08_FeatContextSelect_Range"));

        gridLayout_96->addWidget(label_08_FeatContextSelect_Range, 9, 1, 1, 1);

        doubleSpinBox_08_FeatContextSelect_ThresMin = new QDoubleSpinBox(page_08_SelectContext);
        doubleSpinBox_08_FeatContextSelect_ThresMin->setObjectName(QString::fromUtf8("doubleSpinBox_08_FeatContextSelect_ThresMin"));
        doubleSpinBox_08_FeatContextSelect_ThresMin->setDecimals(3);
        doubleSpinBox_08_FeatContextSelect_ThresMin->setMinimum(-999999999.000000000000000);
        doubleSpinBox_08_FeatContextSelect_ThresMin->setMaximum(999999999.000000000000000);

        gridLayout_96->addWidget(doubleSpinBox_08_FeatContextSelect_ThresMin, 9, 2, 1, 1);

        doubleSpinBox_08_FeatContextSelect_DistMin = new QDoubleSpinBox(page_08_SelectContext);
        doubleSpinBox_08_FeatContextSelect_DistMin->setObjectName(QString::fromUtf8("doubleSpinBox_08_FeatContextSelect_DistMin"));
        doubleSpinBox_08_FeatContextSelect_DistMin->setDecimals(3);
        doubleSpinBox_08_FeatContextSelect_DistMin->setMaximum(100000000000000000.000000000000000);

        gridLayout_96->addWidget(doubleSpinBox_08_FeatContextSelect_DistMin, 4, 2, 1, 1);

        label_08_FeatContextSelect_DistanceRange = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelect_DistanceRange->setObjectName(QString::fromUtf8("label_08_FeatContextSelect_DistanceRange"));
        label_08_FeatContextSelect_DistanceRange->setMinimumSize(QSize(80, 0));
        label_08_FeatContextSelect_DistanceRange->setMaximumSize(QSize(80, 16777215));

        gridLayout_96->addWidget(label_08_FeatContextSelect_DistanceRange, 4, 1, 1, 1);

        line_08_FeatContextSelect_2 = new QFrame(page_08_SelectContext);
        line_08_FeatContextSelect_2->setObjectName(QString::fromUtf8("line_08_FeatContextSelect_2"));
        line_08_FeatContextSelect_2->setFrameShape(QFrame::HLine);
        line_08_FeatContextSelect_2->setFrameShadow(QFrame::Sunken);

        gridLayout_96->addWidget(line_08_FeatContextSelect_2, 1, 1, 1, 4);

        horizontalSpacer_08_FeatContextSelect = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_96->addItem(horizontalSpacer_08_FeatContextSelect, 0, 4, 1, 1);

        label_08_FeatContextSelect_Feat = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelect_Feat->setObjectName(QString::fromUtf8("label_08_FeatContextSelect_Feat"));
        label_08_FeatContextSelect_Feat->setMinimumSize(QSize(80, 0));
        label_08_FeatContextSelect_Feat->setMaximumSize(QSize(80, 16777215));

        gridLayout_96->addWidget(label_08_FeatContextSelect_Feat, 6, 1, 1, 1);

        doubleSpinBox_08_FeatContextSelect_ThresMax = new QDoubleSpinBox(page_08_SelectContext);
        doubleSpinBox_08_FeatContextSelect_ThresMax->setObjectName(QString::fromUtf8("doubleSpinBox_08_FeatContextSelect_ThresMax"));
        doubleSpinBox_08_FeatContextSelect_ThresMax->setDecimals(3);
        doubleSpinBox_08_FeatContextSelect_ThresMax->setMinimum(-999999999.000000000000000);
        doubleSpinBox_08_FeatContextSelect_ThresMax->setMaximum(999999999.000000000000000);
        doubleSpinBox_08_FeatContextSelect_ThresMax->setValue(1000.000000000000000);

        gridLayout_96->addWidget(doubleSpinBox_08_FeatContextSelect_ThresMax, 9, 3, 1, 1);

        doubleSpinBox_08_FeatContextSelect_DistMax = new QDoubleSpinBox(page_08_SelectContext);
        doubleSpinBox_08_FeatContextSelect_DistMax->setObjectName(QString::fromUtf8("doubleSpinBox_08_FeatContextSelect_DistMax"));
        doubleSpinBox_08_FeatContextSelect_DistMax->setDecimals(3);
        doubleSpinBox_08_FeatContextSelect_DistMax->setMaximum(100000000000000000.000000000000000);
        doubleSpinBox_08_FeatContextSelect_DistMax->setValue(3.000000000000000);

        gridLayout_96->addWidget(doubleSpinBox_08_FeatContextSelect_DistMax, 4, 3, 1, 1);

        line_08_FeatContextSelect_1 = new QFrame(page_08_SelectContext);
        line_08_FeatContextSelect_1->setObjectName(QString::fromUtf8("line_08_FeatContextSelect_1"));
        line_08_FeatContextSelect_1->setFrameShape(QFrame::VLine);
        line_08_FeatContextSelect_1->setFrameShadow(QFrame::Sunken);

        gridLayout_96->addWidget(line_08_FeatContextSelect_1, 0, 0, 11, 1);

        line_08_FeatContextSelect_3 = new QFrame(page_08_SelectContext);
        line_08_FeatContextSelect_3->setObjectName(QString::fromUtf8("line_08_FeatContextSelect_3"));
        line_08_FeatContextSelect_3->setFrameShape(QFrame::HLine);
        line_08_FeatContextSelect_3->setFrameShadow(QFrame::Sunken);

        gridLayout_96->addWidget(line_08_FeatContextSelect_3, 5, 1, 1, 4);

        label_08_FeatContextSelect_Connectivity = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelect_Connectivity->setObjectName(QString::fromUtf8("label_08_FeatContextSelect_Connectivity"));
        label_08_FeatContextSelect_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_FeatContextSelect_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_96->addWidget(label_08_FeatContextSelect_Connectivity, 0, 1, 1, 1);

        comboBox_08_FeatContextSelect_Stat = new QComboBox(page_08_SelectContext);
        comboBox_08_FeatContextSelect_Stat->setObjectName(QString::fromUtf8("comboBox_08_FeatContextSelect_Stat"));
        comboBox_08_FeatContextSelect_Stat->setMinimumSize(QSize(300, 0));
        comboBox_08_FeatContextSelect_Stat->setMaximumSize(QSize(300, 16777215));

        gridLayout_96->addWidget(comboBox_08_FeatContextSelect_Stat, 7, 2, 1, 2);

        label_08_FeatContextSelect_DistanceFrom = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelect_DistanceFrom->setObjectName(QString::fromUtf8("label_08_FeatContextSelect_DistanceFrom"));
        label_08_FeatContextSelect_DistanceFrom->setMinimumSize(QSize(80, 0));
        label_08_FeatContextSelect_DistanceFrom->setMaximumSize(QSize(80, 16777215));

        gridLayout_96->addWidget(label_08_FeatContextSelect_DistanceFrom, 2, 1, 1, 1);

        comboBox_08_FeatContextSelect_DistPt2 = new QComboBox(page_08_SelectContext);
        comboBox_08_FeatContextSelect_DistPt2->setObjectName(QString::fromUtf8("comboBox_08_FeatContextSelect_DistPt2"));

        gridLayout_96->addWidget(comboBox_08_FeatContextSelect_DistPt2, 3, 2, 1, 2);

        comboBox_08_FeatContextSelect_DistPt1 = new QComboBox(page_08_SelectContext);
        comboBox_08_FeatContextSelect_DistPt1->setObjectName(QString::fromUtf8("comboBox_08_FeatContextSelect_DistPt1"));

        gridLayout_96->addWidget(comboBox_08_FeatContextSelect_DistPt1, 2, 2, 1, 2);

        label_08_FeatContextSelectDistanceTo = new QLabel(page_08_SelectContext);
        label_08_FeatContextSelectDistanceTo->setObjectName(QString::fromUtf8("label_08_FeatContextSelectDistanceTo"));

        gridLayout_96->addWidget(label_08_FeatContextSelectDistanceTo, 3, 1, 1, 1);

        stackedWidget_Settings_08_Features->addWidget(page_08_SelectContext);
        page_08_Connect = new QWidget();
        page_08_Connect->setObjectName(QString::fromUtf8("page_08_Connect"));
        gridLayout_97 = new QGridLayout(page_08_Connect);
        gridLayout_97->setSpacing(3);
        gridLayout_97->setObjectName(QString::fromUtf8("gridLayout_97"));
        gridLayout_97->setContentsMargins(6, 6, 6, 6);
        label_08_Connect_Cond = new QLabel(page_08_Connect);
        label_08_Connect_Cond->setObjectName(QString::fromUtf8("label_08_Connect_Cond"));

        gridLayout_97->addWidget(label_08_Connect_Cond, 9, 1, 2, 1);

        comboBox_08_Connect_Feat2 = new QComboBox(page_08_Connect);
        comboBox_08_Connect_Feat2->setObjectName(QString::fromUtf8("comboBox_08_Connect_Feat2"));
        comboBox_08_Connect_Feat2->setMinimumSize(QSize(300, 0));
        comboBox_08_Connect_Feat2->setMaximumSize(QSize(300, 16777215));

        gridLayout_97->addWidget(comboBox_08_Connect_Feat2, 7, 2, 1, 2);

        gridLayout_100 = new QGridLayout();
        gridLayout_100->setSpacing(1);
        gridLayout_100->setObjectName(QString::fromUtf8("gridLayout_100"));
        doubleSpinBox_08_Connect_Cond_h = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_h->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_h"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_h->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_h->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_h->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_h->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_h->setMinimum(-10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_08_Connect_Cond_h->setMaximum(100000000000000003502199685943161173046080317798311825604870144.000000000000000);
        doubleSpinBox_08_Connect_Cond_h->setValue(0.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_h, 1, 3, 1, 1);

        doubleSpinBox_08_Connect_Cond_e = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_e->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_e"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_e->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_e->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_e->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_e->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_e->setMinimum(-10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_08_Connect_Cond_e->setMaximum(100000000000000003502199685943161173046080317798311825604870144.000000000000000);
        doubleSpinBox_08_Connect_Cond_e->setValue(0.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_e, 1, 0, 1, 1);

        doubleSpinBox_08_Connect_Cond_c = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_c->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_c"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_c->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_c->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_c->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_c->setMinimum(-99999999999999997168788049560464200849936328366177157906432.000000000000000);
        doubleSpinBox_08_Connect_Cond_c->setMaximum(99999999999999995280522225138166806691251291352861698530421623488512.000000000000000);
        doubleSpinBox_08_Connect_Cond_c->setValue(1.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_c, 0, 2, 1, 1);

        doubleSpinBox_08_Connect_Cond_a = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_a->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_a"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_a->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_a->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_a->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_a->setMinimum(-10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_08_Connect_Cond_a->setMaximum(100000000000000003502199685943161173046080317798311825604870144.000000000000000);
        doubleSpinBox_08_Connect_Cond_a->setValue(1.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_a, 0, 0, 1, 1);

        doubleSpinBox_08_Connect_Cond_d = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_d->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_d"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_d->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_d->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_d->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_d->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_d->setMinimum(-10000000000000000139372116959414099130712064.000000000000000);
        doubleSpinBox_08_Connect_Cond_d->setMaximum(100000000000000003502199685943161173046080317798311825604870144.000000000000000);
        doubleSpinBox_08_Connect_Cond_d->setValue(0.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_d, 0, 3, 1, 1);

        doubleSpinBox_08_Connect_Cond_g = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_g->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_g"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_g->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_g->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_g->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_g->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_g->setMinimum(-99999999999999997168788049560464200849936328366177157906432.000000000000000);
        doubleSpinBox_08_Connect_Cond_g->setMaximum(99999999999999995280522225138166806691251291352861698530421623488512.000000000000000);
        doubleSpinBox_08_Connect_Cond_g->setValue(0.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_g, 1, 2, 1, 1);

        doubleSpinBox_08_Connect_Cond_f = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_f->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_f"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_f->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_f->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_f->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_f->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_f->setMinimum(-99999999999999997168788049560464200849936328366177157906432.000000000000000);
        doubleSpinBox_08_Connect_Cond_f->setMaximum(99999999999999995280522225138166806691251291352861698530421623488512.000000000000000);
        doubleSpinBox_08_Connect_Cond_f->setValue(0.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_f, 1, 1, 1, 1);

        doubleSpinBox_08_Connect_Cond_b = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_Cond_b->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_Cond_b"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_08_Connect_Cond_b->sizePolicy().hasHeightForWidth());
        doubleSpinBox_08_Connect_Cond_b->setSizePolicy(sizePolicy1);
        doubleSpinBox_08_Connect_Cond_b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_08_Connect_Cond_b->setDecimals(3);
        doubleSpinBox_08_Connect_Cond_b->setMinimum(-99999999999999997168788049560464200849936328366177157906432.000000000000000);
        doubleSpinBox_08_Connect_Cond_b->setMaximum(99999999999999995280522225138166806691251291352861698530421623488512.000000000000000);
        doubleSpinBox_08_Connect_Cond_b->setValue(0.000000000000000);

        gridLayout_100->addWidget(doubleSpinBox_08_Connect_Cond_b, 0, 1, 1, 1);


        gridLayout_97->addLayout(gridLayout_100, 10, 2, 1, 2);

        horizontalSpacer_08_FeatContextVal_2 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_97->addItem(horizontalSpacer_08_FeatContextVal_2, 0, 4, 1, 1);

        label_08_Connect_Object2_Feat = new QLabel(page_08_Connect);
        label_08_Connect_Object2_Feat->setObjectName(QString::fromUtf8("label_08_Connect_Object2_Feat"));

        gridLayout_97->addWidget(label_08_Connect_Object2_Feat, 7, 1, 1, 1);

        comboBox_08_Connect_Cond = new QComboBox(page_08_Connect);
        comboBox_08_Connect_Cond->setObjectName(QString::fromUtf8("comboBox_08_Connect_Cond"));
        comboBox_08_Connect_Cond->setMinimumSize(QSize(300, 0));
        comboBox_08_Connect_Cond->setMaximumSize(QSize(300, 16777215));
        comboBox_08_Connect_Cond->setInsertPolicy(QComboBox::InsertAtBottom);
        comboBox_08_Connect_Cond->setFrame(true);

        gridLayout_97->addWidget(comboBox_08_Connect_Cond, 9, 2, 1, 2);

        label_08_Connect_Object1_Feat = new QLabel(page_08_Connect);
        label_08_Connect_Object1_Feat->setObjectName(QString::fromUtf8("label_08_Connect_Object1_Feat"));

        gridLayout_97->addWidget(label_08_Connect_Object1_Feat, 6, 1, 1, 1);

        label_08_Connect_DistanceFrom = new QLabel(page_08_Connect);
        label_08_Connect_DistanceFrom->setObjectName(QString::fromUtf8("label_08_Connect_DistanceFrom"));
        label_08_Connect_DistanceFrom->setMinimumSize(QSize(80, 0));
        label_08_Connect_DistanceFrom->setMaximumSize(QSize(80, 16777215));

        gridLayout_97->addWidget(label_08_Connect_DistanceFrom, 2, 1, 1, 1);

        doubleSpinBox_08_Connect_DistMin = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_DistMin->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_DistMin"));
        doubleSpinBox_08_Connect_DistMin->setDecimals(3);
        doubleSpinBox_08_Connect_DistMin->setMaximum(100000000000000000.000000000000000);

        gridLayout_97->addWidget(doubleSpinBox_08_Connect_DistMin, 4, 2, 1, 1);

        label_08_Connect_Connectivity = new QLabel(page_08_Connect);
        label_08_Connect_Connectivity->setObjectName(QString::fromUtf8("label_08_Connect_Connectivity"));
        label_08_Connect_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_Connect_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_97->addWidget(label_08_Connect_Connectivity, 0, 1, 1, 1);

        line_08_Connect_2 = new QFrame(page_08_Connect);
        line_08_Connect_2->setObjectName(QString::fromUtf8("line_08_Connect_2"));
        line_08_Connect_2->setFrameShape(QFrame::HLine);
        line_08_Connect_2->setFrameShadow(QFrame::Sunken);

        gridLayout_97->addWidget(line_08_Connect_2, 1, 1, 1, 4);

        label_08_Connect_DistanceTo = new QLabel(page_08_Connect);
        label_08_Connect_DistanceTo->setObjectName(QString::fromUtf8("label_08_Connect_DistanceTo"));

        gridLayout_97->addWidget(label_08_Connect_DistanceTo, 3, 1, 1, 1);

        doubleSpinBox_08_Connect_DistMax = new QDoubleSpinBox(page_08_Connect);
        doubleSpinBox_08_Connect_DistMax->setObjectName(QString::fromUtf8("doubleSpinBox_08_Connect_DistMax"));
        doubleSpinBox_08_Connect_DistMax->setDecimals(3);
        doubleSpinBox_08_Connect_DistMax->setMaximum(100000000000000000.000000000000000);
        doubleSpinBox_08_Connect_DistMax->setValue(3.000000000000000);

        gridLayout_97->addWidget(doubleSpinBox_08_Connect_DistMax, 4, 3, 1, 1);

        line_08_Connect_3 = new QFrame(page_08_Connect);
        line_08_Connect_3->setObjectName(QString::fromUtf8("line_08_Connect_3"));
        line_08_Connect_3->setFrameShape(QFrame::HLine);
        line_08_Connect_3->setFrameShadow(QFrame::Sunken);

        gridLayout_97->addWidget(line_08_Connect_3, 5, 1, 1, 4);

        comboBox_08_Connect_DistPt2 = new QComboBox(page_08_Connect);
        comboBox_08_Connect_DistPt2->setObjectName(QString::fromUtf8("comboBox_08_Connect_DistPt2"));
        comboBox_08_Connect_DistPt2->setMinimumSize(QSize(300, 0));
        comboBox_08_Connect_DistPt2->setMaximumSize(QSize(300, 16777215));

        gridLayout_97->addWidget(comboBox_08_Connect_DistPt2, 3, 2, 1, 2);

        comboBox_08_Connect_DistPt1 = new QComboBox(page_08_Connect);
        comboBox_08_Connect_DistPt1->setObjectName(QString::fromUtf8("comboBox_08_Connect_DistPt1"));
        comboBox_08_Connect_DistPt1->setMinimumSize(QSize(300, 0));
        comboBox_08_Connect_DistPt1->setMaximumSize(QSize(300, 16777215));

        gridLayout_97->addWidget(comboBox_08_Connect_DistPt1, 2, 2, 1, 2);

        label_08_Connect_DistanceRange = new QLabel(page_08_Connect);
        label_08_Connect_DistanceRange->setObjectName(QString::fromUtf8("label_08_Connect_DistanceRange"));
        label_08_Connect_DistanceRange->setMinimumSize(QSize(80, 0));
        label_08_Connect_DistanceRange->setMaximumSize(QSize(80, 16777215));

        gridLayout_97->addWidget(label_08_Connect_DistanceRange, 4, 1, 1, 1);

        line_08_Connect_1 = new QFrame(page_08_Connect);
        line_08_Connect_1->setObjectName(QString::fromUtf8("line_08_Connect_1"));
        line_08_Connect_1->setFrameShape(QFrame::VLine);
        line_08_Connect_1->setFrameShadow(QFrame::Sunken);

        gridLayout_97->addWidget(line_08_Connect_1, 0, 0, 12, 1);

        line_08_Connect_4 = new QFrame(page_08_Connect);
        line_08_Connect_4->setObjectName(QString::fromUtf8("line_08_Connect_4"));
        line_08_Connect_4->setFrameShape(QFrame::HLine);
        line_08_Connect_4->setFrameShadow(QFrame::Sunken);

        gridLayout_97->addWidget(line_08_Connect_4, 8, 1, 1, 4);

        comboBox_08_Connect_Feat1 = new QComboBox(page_08_Connect);
        comboBox_08_Connect_Feat1->setObjectName(QString::fromUtf8("comboBox_08_Connect_Feat1"));
        comboBox_08_Connect_Feat1->setMinimumSize(QSize(300, 0));
        comboBox_08_Connect_Feat1->setMaximumSize(QSize(300, 16777215));

        gridLayout_97->addWidget(comboBox_08_Connect_Feat1, 6, 2, 1, 2);

        verticalSpacer_08_Connect = new QSpacerItem(380, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_97->addItem(verticalSpacer_08_Connect, 11, 1, 1, 3);

        gridLayout_101 = new QGridLayout();
        gridLayout_101->setSpacing(3);
        gridLayout_101->setObjectName(QString::fromUtf8("gridLayout_101"));
        comboBox_08_Connect_ConnectType = new QComboBox(page_08_Connect);
        comboBox_08_Connect_ConnectType->setObjectName(QString::fromUtf8("comboBox_08_Connect_ConnectType"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(2);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(comboBox_08_Connect_ConnectType->sizePolicy().hasHeightForWidth());
        comboBox_08_Connect_ConnectType->setSizePolicy(sizePolicy10);

        gridLayout_101->addWidget(comboBox_08_Connect_ConnectType, 0, 1, 1, 1);

        comboBox_08_Connect_Connectivity = new QComboBox(page_08_Connect);
        comboBox_08_Connect_Connectivity->addItem(QString());
        comboBox_08_Connect_Connectivity->addItem(QString());
        comboBox_08_Connect_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_Connect_Connectivity"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(3);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(comboBox_08_Connect_Connectivity->sizePolicy().hasHeightForWidth());
        comboBox_08_Connect_Connectivity->setSizePolicy(sizePolicy11);
        comboBox_08_Connect_Connectivity->setMinimumSize(QSize(0, 0));
        comboBox_08_Connect_Connectivity->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_101->addWidget(comboBox_08_Connect_Connectivity, 0, 0, 1, 1);

        spinBox_08_Connect_Thickness = new QSpinBox(page_08_Connect);
        spinBox_08_Connect_Thickness->setObjectName(QString::fromUtf8("spinBox_08_Connect_Thickness"));
        QSizePolicy sizePolicy12(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy12.setHorizontalStretch(1);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(spinBox_08_Connect_Thickness->sizePolicy().hasHeightForWidth());
        spinBox_08_Connect_Thickness->setSizePolicy(sizePolicy12);
        spinBox_08_Connect_Thickness->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_08_Connect_Thickness->setMinimum(1);
        spinBox_08_Connect_Thickness->setMaximum(9999);
        spinBox_08_Connect_Thickness->setValue(2);

        gridLayout_101->addWidget(spinBox_08_Connect_Thickness, 0, 2, 1, 1);


        gridLayout_97->addLayout(gridLayout_101, 0, 2, 1, 2);

        stackedWidget_Settings_08_Features->addWidget(page_08_Connect);
        page_08_Reduce = new QWidget();
        page_08_Reduce->setObjectName(QString::fromUtf8("page_08_Reduce"));
        gridLayout_58 = new QGridLayout(page_08_Reduce);
        gridLayout_58->setSpacing(3);
        gridLayout_58->setObjectName(QString::fromUtf8("gridLayout_58"));
        gridLayout_58->setContentsMargins(6, 6, 6, 6);
        label_08_Reduce_Type = new QLabel(page_08_Reduce);
        label_08_Reduce_Type->setObjectName(QString::fromUtf8("label_08_Reduce_Type"));
        label_08_Reduce_Type->setMinimumSize(QSize(80, 0));
        label_08_Reduce_Type->setMaximumSize(QSize(80, 16777215));

        gridLayout_58->addWidget(label_08_Reduce_Type, 1, 1, 1, 1);

        comboBox_08_Reduce_Type = new QComboBox(page_08_Reduce);
        comboBox_08_Reduce_Type->setObjectName(QString::fromUtf8("comboBox_08_Reduce_Type"));
        comboBox_08_Reduce_Type->setMinimumSize(QSize(300, 0));
        comboBox_08_Reduce_Type->setMaximumSize(QSize(300, 16777215));

        gridLayout_58->addWidget(comboBox_08_Reduce_Type, 1, 2, 1, 1);

        label_08_Reduce_Thickness = new QLabel(page_08_Reduce);
        label_08_Reduce_Thickness->setObjectName(QString::fromUtf8("label_08_Reduce_Thickness"));
        label_08_Reduce_Thickness->setMinimumSize(QSize(80, 0));
        label_08_Reduce_Thickness->setMaximumSize(QSize(80, 16777215));

        gridLayout_58->addWidget(label_08_Reduce_Thickness, 2, 1, 1, 1);

        spinBox_08_Reduce_Thickness = new QSpinBox(page_08_Reduce);
        spinBox_08_Reduce_Thickness->setObjectName(QString::fromUtf8("spinBox_08_Reduce_Thickness"));
        spinBox_08_Reduce_Thickness->setMinimumSize(QSize(300, 0));
        spinBox_08_Reduce_Thickness->setMaximumSize(QSize(300, 16777215));
        spinBox_08_Reduce_Thickness->setMinimum(1);
        spinBox_08_Reduce_Thickness->setMaximum(10000);
        spinBox_08_Reduce_Thickness->setSingleStep(1);
        spinBox_08_Reduce_Thickness->setValue(1);

        gridLayout_58->addWidget(spinBox_08_Reduce_Thickness, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_58->addItem(verticalSpacer, 5, 1, 1, 1);

        comboBox_08_Reduce_Connectivity = new QComboBox(page_08_Reduce);
        comboBox_08_Reduce_Connectivity->addItem(QString());
        comboBox_08_Reduce_Connectivity->addItem(QString());
        comboBox_08_Reduce_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_Reduce_Connectivity"));
        comboBox_08_Reduce_Connectivity->setMinimumSize(QSize(300, 0));
        comboBox_08_Reduce_Connectivity->setMaximumSize(QSize(300, 16777215));

        gridLayout_58->addWidget(comboBox_08_Reduce_Connectivity, 0, 2, 1, 1);

        label_08_Reduce_Connectivity = new QLabel(page_08_Reduce);
        label_08_Reduce_Connectivity->setObjectName(QString::fromUtf8("label_08_Reduce_Connectivity"));
        label_08_Reduce_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_Reduce_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_58->addWidget(label_08_Reduce_Connectivity, 0, 1, 1, 1);

        line_08_Reduce = new QFrame(page_08_Reduce);
        line_08_Reduce->setObjectName(QString::fromUtf8("line_08_Reduce"));
        line_08_Reduce->setFrameShape(QFrame::VLine);
        line_08_Reduce->setFrameShadow(QFrame::Sunken);

        gridLayout_58->addWidget(line_08_Reduce, 0, 0, 6, 1);

        horizontalSpacer_08_Reduce = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_58->addItem(horizontalSpacer_08_Reduce, 0, 3, 5, 1);

        spinBox_08_Reduce_Value = new QSpinBox(page_08_Reduce);
        spinBox_08_Reduce_Value->setObjectName(QString::fromUtf8("spinBox_08_Reduce_Value"));
        spinBox_08_Reduce_Value->setMinimumSize(QSize(300, 0));
        spinBox_08_Reduce_Value->setMaximumSize(QSize(300, 16777215));
        spinBox_08_Reduce_Value->setMaximum(255);
        spinBox_08_Reduce_Value->setValue(255);

        gridLayout_58->addWidget(spinBox_08_Reduce_Value, 3, 2, 2, 1);

        label_08_Reduce_Value = new QLabel(page_08_Reduce);
        label_08_Reduce_Value->setObjectName(QString::fromUtf8("label_08_Reduce_Value"));
        label_08_Reduce_Value->setMinimumSize(QSize(80, 0));
        label_08_Reduce_Value->setMaximumSize(QSize(80, 16777215));

        gridLayout_58->addWidget(label_08_Reduce_Value, 3, 1, 2, 1);

        stackedWidget_Settings_08_Features->addWidget(page_08_Reduce);
        page_08_Visualize = new QWidget();
        page_08_Visualize->setObjectName(QString::fromUtf8("page_08_Visualize"));
        gridLayout_75 = new QGridLayout(page_08_Visualize);
        gridLayout_75->setSpacing(3);
        gridLayout_75->setObjectName(QString::fromUtf8("gridLayout_75"));
        gridLayout_75->setContentsMargins(6, 6, 6, 6);
        comboBox_08_Visualize_Connectivity = new QComboBox(page_08_Visualize);
        comboBox_08_Visualize_Connectivity->addItem(QString());
        comboBox_08_Visualize_Connectivity->addItem(QString());
        comboBox_08_Visualize_Connectivity->setObjectName(QString::fromUtf8("comboBox_08_Visualize_Connectivity"));
        comboBox_08_Visualize_Connectivity->setMinimumSize(QSize(300, 0));
        comboBox_08_Visualize_Connectivity->setMaximumSize(QSize(300, 16777215));

        gridLayout_75->addWidget(comboBox_08_Visualize_Connectivity, 1, 3, 1, 1);

        label_08_Visualize_Scale = new QLabel(page_08_Visualize);
        label_08_Visualize_Scale->setObjectName(QString::fromUtf8("label_08_Visualize_Scale"));
        label_08_Visualize_Scale->setMinimumSize(QSize(80, 0));
        label_08_Visualize_Scale->setMaximumSize(QSize(80, 16777215));

        gridLayout_75->addWidget(label_08_Visualize_Scale, 4, 1, 1, 1);

        label_08_Visualize_Thickness = new QLabel(page_08_Visualize);
        label_08_Visualize_Thickness->setObjectName(QString::fromUtf8("label_08_Visualize_Thickness"));
        label_08_Visualize_Thickness->setMinimumSize(QSize(80, 0));
        label_08_Visualize_Thickness->setMaximumSize(QSize(80, 16777215));

        gridLayout_75->addWidget(label_08_Visualize_Thickness, 3, 1, 1, 2);

        doubleSpinBox_08_Visualize_Scale = new QDoubleSpinBox(page_08_Visualize);
        doubleSpinBox_08_Visualize_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_08_Visualize_Scale"));
        doubleSpinBox_08_Visualize_Scale->setMinimumSize(QSize(300, 0));
        doubleSpinBox_08_Visualize_Scale->setMaximumSize(QSize(300, 16777215));
        doubleSpinBox_08_Visualize_Scale->setMinimum(0.100000000000000);
        doubleSpinBox_08_Visualize_Scale->setMaximum(100.000000000000000);
        doubleSpinBox_08_Visualize_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_08_Visualize_Scale->setValue(1.000000000000000);

        gridLayout_75->addWidget(doubleSpinBox_08_Visualize_Scale, 4, 3, 1, 1);

        label_08_Visualize_Connectivity = new QLabel(page_08_Visualize);
        label_08_Visualize_Connectivity->setObjectName(QString::fromUtf8("label_08_Visualize_Connectivity"));
        label_08_Visualize_Connectivity->setMinimumSize(QSize(80, 0));
        label_08_Visualize_Connectivity->setMaximumSize(QSize(80, 16777215));

        gridLayout_75->addWidget(label_08_Visualize_Connectivity, 1, 1, 1, 2);

        line_08_Visualize = new QFrame(page_08_Visualize);
        line_08_Visualize->setObjectName(QString::fromUtf8("line_08_Visualize"));
        line_08_Visualize->setFrameShape(QFrame::VLine);
        line_08_Visualize->setFrameShadow(QFrame::Sunken);

        gridLayout_75->addWidget(line_08_Visualize, 0, 0, 7, 1);

        label_08_Visualize_Feature = new QLabel(page_08_Visualize);
        label_08_Visualize_Feature->setObjectName(QString::fromUtf8("label_08_Visualize_Feature"));
        label_08_Visualize_Feature->setMinimumSize(QSize(80, 0));
        label_08_Visualize_Feature->setMaximumSize(QSize(80, 16777215));

        gridLayout_75->addWidget(label_08_Visualize_Feature, 2, 1, 1, 1);

        comboBox_08_Visualize_Feature = new QComboBox(page_08_Visualize);
        comboBox_08_Visualize_Feature->setObjectName(QString::fromUtf8("comboBox_08_Visualize_Feature"));
        comboBox_08_Visualize_Feature->setMinimumSize(QSize(300, 0));
        comboBox_08_Visualize_Feature->setMaximumSize(QSize(300, 16777215));

        gridLayout_75->addWidget(comboBox_08_Visualize_Feature, 2, 3, 1, 1);

        verticalSpacer_08_Visualize = new QSpacerItem(20, 110, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_75->addItem(verticalSpacer_08_Visualize, 5, 1, 1, 3);

        horizontalSpacer_08_Visualize = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_75->addItem(horizontalSpacer_08_Visualize, 1, 4, 4, 1);

        spinBox_08_Visualize_Thickness = new QSpinBox(page_08_Visualize);
        spinBox_08_Visualize_Thickness->setObjectName(QString::fromUtf8("spinBox_08_Visualize_Thickness"));
        spinBox_08_Visualize_Thickness->setMinimumSize(QSize(300, 0));
        spinBox_08_Visualize_Thickness->setMaximumSize(QSize(300, 16777215));
        spinBox_08_Visualize_Thickness->setMinimum(1);
        spinBox_08_Visualize_Thickness->setMaximum(100);
        spinBox_08_Visualize_Thickness->setValue(1);

        gridLayout_75->addWidget(spinBox_08_Visualize_Thickness, 3, 3, 1, 1);

        stackedWidget_Settings_08_Features->addWidget(page_08_Visualize);
        page_08_Extract = new QWidget();
        page_08_Extract->setObjectName(QString::fromUtf8("page_08_Extract"));
        gridLayout_111 = new QGridLayout(page_08_Extract);
        gridLayout_111->setObjectName(QString::fromUtf8("gridLayout_111"));
        label_10 = new QLabel(page_08_Extract);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(75, 0));
        label_10->setMaximumSize(QSize(75, 16777215));

        gridLayout_111->addWidget(label_10, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(416, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_111->addItem(verticalSpacer_5, 6, 0, 1, 3);

        line_5 = new QFrame(page_08_Extract);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_111->addWidget(line_5, 3, 0, 1, 3);

        label_11 = new QLabel(page_08_Extract);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(75, 0));
        label_11->setMaximumSize(QSize(75, 16777215));

        gridLayout_111->addWidget(label_11, 4, 0, 1, 1);

        comboBox_5 = new QComboBox(page_08_Extract);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setMinimumSize(QSize(300, 0));
        comboBox_5->setMaximumSize(QSize(300, 16777215));

        gridLayout_111->addWidget(comboBox_5, 4, 1, 1, 1);

        comboBox_3 = new QComboBox(page_08_Extract);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(300, 0));
        comboBox_3->setMaximumSize(QSize(300, 16777215));

        gridLayout_111->addWidget(comboBox_3, 0, 1, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(29, 43, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_111->addItem(horizontalSpacer_4, 0, 2, 3, 1);

        label_9 = new QLabel(page_08_Extract);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(75, 0));
        label_9->setMaximumSize(QSize(75, 16777215));

        gridLayout_111->addWidget(label_9, 0, 0, 1, 1);

        label_12 = new QLabel(page_08_Extract);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_111->addWidget(label_12, 5, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(page_08_Extract);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_111->addWidget(doubleSpinBox, 5, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(page_08_Extract);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(100.000000000000000);
        doubleSpinBox_2->setValue(100.000000000000000);

        gridLayout_111->addWidget(doubleSpinBox_2, 2, 1, 1, 1);

        stackedWidget_Settings_08_Features->addWidget(page_08_Extract);

        gridLayout_25->addWidget(stackedWidget_Settings_08_Features, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_08_Features);
        page_Settings_09_Other = new QWidget();
        page_Settings_09_Other->setObjectName(QString::fromUtf8("page_Settings_09_Other"));
        gridLayout_26 = new QGridLayout(page_Settings_09_Other);
        gridLayout_26->setSpacing(0);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_09_Other = new QStackedWidget(page_Settings_09_Other);
        stackedWidget_Settings_09_Other->setObjectName(QString::fromUtf8("stackedWidget_Settings_09_Other"));
        page_09_Equal_Hist = new QWidget();
        page_09_Equal_Hist->setObjectName(QString::fromUtf8("page_09_Equal_Hist"));
        gridLayout_47 = new QGridLayout(page_09_Equal_Hist);
        gridLayout_47->setObjectName(QString::fromUtf8("gridLayout_47"));
        horizontalSpacer_09_Equal_Hist = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_47->addItem(horizontalSpacer_09_Equal_Hist, 0, 2, 1, 1);

        line_09_Equal_Hist = new QFrame(page_09_Equal_Hist);
        line_09_Equal_Hist->setObjectName(QString::fromUtf8("line_09_Equal_Hist"));
        line_09_Equal_Hist->setFrameShape(QFrame::VLine);
        line_09_Equal_Hist->setFrameShadow(QFrame::Sunken);

        gridLayout_47->addWidget(line_09_Equal_Hist, 0, 0, 3, 1);

        verticalSpacer_09_Equal_Hist = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_47->addItem(verticalSpacer_09_Equal_Hist, 2, 2, 1, 1);

        label_09_Equal_Hist_1 = new QLabel(page_09_Equal_Hist);
        label_09_Equal_Hist_1->setObjectName(QString::fromUtf8("label_09_Equal_Hist_1"));

        gridLayout_47->addWidget(label_09_Equal_Hist_1, 0, 1, 1, 1);

        label_09_Equal_Hist_2 = new QLabel(page_09_Equal_Hist);
        label_09_Equal_Hist_2->setObjectName(QString::fromUtf8("label_09_Equal_Hist_2"));

        gridLayout_47->addWidget(label_09_Equal_Hist_2, 1, 1, 1, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_Equal_Hist);
        page_09_GammaSpread = new QWidget();
        page_09_GammaSpread->setObjectName(QString::fromUtf8("page_09_GammaSpread"));
        gridLayout_78 = new QGridLayout(page_09_GammaSpread);
        gridLayout_78->setObjectName(QString::fromUtf8("gridLayout_78"));
        doubleSpinBox_09_GammaSpread_OutMax = new QDoubleSpinBox(page_09_GammaSpread);
        doubleSpinBox_09_GammaSpread_OutMax->setObjectName(QString::fromUtf8("doubleSpinBox_09_GammaSpread_OutMax"));
        doubleSpinBox_09_GammaSpread_OutMax->setMinimumSize(QSize(100, 0));
        doubleSpinBox_09_GammaSpread_OutMax->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_09_GammaSpread_OutMax->setDecimals(3);
        doubleSpinBox_09_GammaSpread_OutMax->setMinimum(-10000000000000000486475973287265010404848153099971055159735310397418651127357734700791903005570128910531738945888832142428584597165509708623196466454966148714674320981543085810557013220039375302073350623645891623631119178909006652304785408.000000000000000);
        doubleSpinBox_09_GammaSpread_OutMax->setMaximum(1000000000000000068957567536844582937679826098352437099093782830596656320642208754566186799616905285426599982929417458880300383900478261195703581718577367397759832385751351296.000000000000000);
        doubleSpinBox_09_GammaSpread_OutMax->setValue(255.000000000000000);

        gridLayout_78->addWidget(doubleSpinBox_09_GammaSpread_OutMax, 4, 2, 1, 1);

        doubleSpinBox_09_GammaSpread_OutMin = new QDoubleSpinBox(page_09_GammaSpread);
        doubleSpinBox_09_GammaSpread_OutMin->setObjectName(QString::fromUtf8("doubleSpinBox_09_GammaSpread_OutMin"));
        doubleSpinBox_09_GammaSpread_OutMin->setMinimumSize(QSize(100, 0));
        doubleSpinBox_09_GammaSpread_OutMin->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_09_GammaSpread_OutMin->setDecimals(3);
        doubleSpinBox_09_GammaSpread_OutMin->setMinimum(-10000000000000000486475973287265010404848153099971055159735310397418651127357734700791903005570128910531738945888832142428584597165509708623196466454966148714674320981543085810557013220039375302073350623645891623631119178909006652304785408.000000000000000);
        doubleSpinBox_09_GammaSpread_OutMin->setMaximum(1000000000000000068957567536844582937679826098352437099093782830596656320642208754566186799616905285426599982929417458880300383900478261195703581718577367397759832385751351296.000000000000000);

        gridLayout_78->addWidget(doubleSpinBox_09_GammaSpread_OutMin, 3, 2, 1, 1);

        horizontalSpacer_09_GammaSpread = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_78->addItem(horizontalSpacer_09_GammaSpread, 9, 3, 1, 1);

        label_09_GammaSpread_OutMax = new QLabel(page_09_GammaSpread);
        label_09_GammaSpread_OutMax->setObjectName(QString::fromUtf8("label_09_GammaSpread_OutMax"));
        label_09_GammaSpread_OutMax->setMinimumSize(QSize(75, 0));
        label_09_GammaSpread_OutMax->setMaximumSize(QSize(75, 16777215));

        gridLayout_78->addWidget(label_09_GammaSpread_OutMax, 4, 1, 1, 1);

        label_09_GammaSpread_InMax = new QLabel(page_09_GammaSpread);
        label_09_GammaSpread_InMax->setObjectName(QString::fromUtf8("label_09_GammaSpread_InMax"));
        label_09_GammaSpread_InMax->setMinimumSize(QSize(75, 0));
        label_09_GammaSpread_InMax->setMaximumSize(QSize(75, 16777215));

        gridLayout_78->addWidget(label_09_GammaSpread_InMax, 1, 1, 1, 1);

        label_09_GammaSpread_OutMin = new QLabel(page_09_GammaSpread);
        label_09_GammaSpread_OutMin->setObjectName(QString::fromUtf8("label_09_GammaSpread_OutMin"));
        label_09_GammaSpread_OutMin->setMinimumSize(QSize(75, 0));
        label_09_GammaSpread_OutMin->setMaximumSize(QSize(75, 16777215));

        gridLayout_78->addWidget(label_09_GammaSpread_OutMin, 3, 1, 1, 1);

        doubleSpinBox_09_GammaSpread_InMax = new QDoubleSpinBox(page_09_GammaSpread);
        doubleSpinBox_09_GammaSpread_InMax->setObjectName(QString::fromUtf8("doubleSpinBox_09_GammaSpread_InMax"));
        doubleSpinBox_09_GammaSpread_InMax->setMinimumSize(QSize(100, 0));
        doubleSpinBox_09_GammaSpread_InMax->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_09_GammaSpread_InMax->setDecimals(3);
        doubleSpinBox_09_GammaSpread_InMax->setMinimum(-10000000000000000486475973287265010404848153099971055159735310397418651127357734700791903005570128910531738945888832142428584597165509708623196466454966148714674320981543085810557013220039375302073350623645891623631119178909006652304785408.000000000000000);
        doubleSpinBox_09_GammaSpread_InMax->setMaximum(1000000000000000068957567536844582937679826098352437099093782830596656320642208754566186799616905285426599982929417458880300383900478261195703581718577367397759832385751351296.000000000000000);
        doubleSpinBox_09_GammaSpread_InMax->setValue(255.000000000000000);

        gridLayout_78->addWidget(doubleSpinBox_09_GammaSpread_InMax, 1, 2, 1, 1);

        doubleSpinBox_09_GammaSpread_InMin = new QDoubleSpinBox(page_09_GammaSpread);
        doubleSpinBox_09_GammaSpread_InMin->setObjectName(QString::fromUtf8("doubleSpinBox_09_GammaSpread_InMin"));
        doubleSpinBox_09_GammaSpread_InMin->setMinimumSize(QSize(100, 0));
        doubleSpinBox_09_GammaSpread_InMin->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_09_GammaSpread_InMin->setDecimals(3);
        doubleSpinBox_09_GammaSpread_InMin->setMinimum(-10000000000000000486475973287265010404848153099971055159735310397418651127357734700791903005570128910531738945888832142428584597165509708623196466454966148714674320981543085810557013220039375302073350623645891623631119178909006652304785408.000000000000000);
        doubleSpinBox_09_GammaSpread_InMin->setMaximum(1000000000000000068957567536844582937679826098352437099093782830596656320642208754566186799616905285426599982929417458880300383900478261195703581718577367397759832385751351296.000000000000000);

        gridLayout_78->addWidget(doubleSpinBox_09_GammaSpread_InMin, 0, 2, 1, 1);

        line_09_GammaSpread_1 = new QFrame(page_09_GammaSpread);
        line_09_GammaSpread_1->setObjectName(QString::fromUtf8("line_09_GammaSpread_1"));
        line_09_GammaSpread_1->setFrameShape(QFrame::VLine);
        line_09_GammaSpread_1->setFrameShadow(QFrame::Sunken);

        gridLayout_78->addWidget(line_09_GammaSpread_1, 0, 0, 10, 1);

        line_09_GammaSpread_2 = new QFrame(page_09_GammaSpread);
        line_09_GammaSpread_2->setObjectName(QString::fromUtf8("line_09_GammaSpread_2"));
        line_09_GammaSpread_2->setFrameShape(QFrame::HLine);
        line_09_GammaSpread_2->setFrameShadow(QFrame::Sunken);

        gridLayout_78->addWidget(line_09_GammaSpread_2, 2, 1, 1, 3);

        doubleSpinBox_09_GammaSpread_Gamma = new QDoubleSpinBox(page_09_GammaSpread);
        doubleSpinBox_09_GammaSpread_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_09_GammaSpread_Gamma"));
        doubleSpinBox_09_GammaSpread_Gamma->setMinimumSize(QSize(100, 0));
        doubleSpinBox_09_GammaSpread_Gamma->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_09_GammaSpread_Gamma->setDecimals(3);
        doubleSpinBox_09_GammaSpread_Gamma->setMinimum(-10000000000000000486475973287265010404848153099971055159735310397418651127357734700791903005570128910531738945888832142428584597165509708623196466454966148714674320981543085810557013220039375302073350623645891623631119178909006652304785408.000000000000000);
        doubleSpinBox_09_GammaSpread_Gamma->setMaximum(1000000000000000068957567536844582937679826098352437099093782830596656320642208754566186799616905285426599982929417458880300383900478261195703581718577367397759832385751351296.000000000000000);
        doubleSpinBox_09_GammaSpread_Gamma->setSingleStep(0.010000000000000);
        doubleSpinBox_09_GammaSpread_Gamma->setValue(1.000000000000000);

        gridLayout_78->addWidget(doubleSpinBox_09_GammaSpread_Gamma, 6, 2, 1, 1);

        verticalSpacer_09_GammaSpread = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_78->addItem(verticalSpacer_09_GammaSpread, 9, 1, 1, 1);

        line_09_GammaSpread_3 = new QFrame(page_09_GammaSpread);
        line_09_GammaSpread_3->setObjectName(QString::fromUtf8("line_09_GammaSpread_3"));
        line_09_GammaSpread_3->setFrameShape(QFrame::HLine);
        line_09_GammaSpread_3->setFrameShadow(QFrame::Sunken);

        gridLayout_78->addWidget(line_09_GammaSpread_3, 5, 1, 1, 3);

        label_09_GammaSpread_InMin = new QLabel(page_09_GammaSpread);
        label_09_GammaSpread_InMin->setObjectName(QString::fromUtf8("label_09_GammaSpread_InMin"));
        label_09_GammaSpread_InMin->setMinimumSize(QSize(75, 0));
        label_09_GammaSpread_InMin->setMaximumSize(QSize(75, 16777215));

        gridLayout_78->addWidget(label_09_GammaSpread_InMin, 0, 1, 1, 1);

        label_09_GammaSpread_Gamma = new QLabel(page_09_GammaSpread);
        label_09_GammaSpread_Gamma->setObjectName(QString::fromUtf8("label_09_GammaSpread_Gamma"));
        label_09_GammaSpread_Gamma->setMinimumSize(QSize(75, 0));
        label_09_GammaSpread_Gamma->setMaximumSize(QSize(75, 16777215));

        gridLayout_78->addWidget(label_09_GammaSpread_Gamma, 6, 1, 1, 1);

        line_09_GammaSpread_4 = new QFrame(page_09_GammaSpread);
        line_09_GammaSpread_4->setObjectName(QString::fromUtf8("line_09_GammaSpread_4"));
        line_09_GammaSpread_4->setFrameShape(QFrame::HLine);
        line_09_GammaSpread_4->setFrameShadow(QFrame::Sunken);

        gridLayout_78->addWidget(line_09_GammaSpread_4, 7, 1, 1, 3);

        label_09_GammaSpread_Force8bit = new QLabel(page_09_GammaSpread);
        label_09_GammaSpread_Force8bit->setObjectName(QString::fromUtf8("label_09_GammaSpread_Force8bit"));

        gridLayout_78->addWidget(label_09_GammaSpread_Force8bit, 8, 1, 1, 1);

        checkBox_09_GammaSpread_Force8bit = new QCheckBox(page_09_GammaSpread);
        checkBox_09_GammaSpread_Force8bit->setObjectName(QString::fromUtf8("checkBox_09_GammaSpread_Force8bit"));

        gridLayout_78->addWidget(checkBox_09_GammaSpread_Force8bit, 8, 2, 1, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_GammaSpread);
        page_09_LabelNo = new QWidget();
        page_09_LabelNo->setObjectName(QString::fromUtf8("page_09_LabelNo"));
        gridLayout_61 = new QGridLayout(page_09_LabelNo);
        gridLayout_61->setObjectName(QString::fromUtf8("gridLayout_61"));
        line_09_LabelNo_1 = new QFrame(page_09_LabelNo);
        line_09_LabelNo_1->setObjectName(QString::fromUtf8("line_09_LabelNo_1"));
        line_09_LabelNo_1->setFrameShape(QFrame::VLine);
        line_09_LabelNo_1->setFrameShadow(QFrame::Sunken);

        gridLayout_61->addWidget(line_09_LabelNo_1, 0, 0, 10, 1);

        label_09_LabelNo_Src1_Title = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Src1_Title->setObjectName(QString::fromUtf8("label_09_LabelNo_Src1_Title"));
        label_09_LabelNo_Src1_Title->setMinimumSize(QSize(75, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Src1_Title, 0, 1, 1, 1);

        label_09_LabelNo_Src1_Desc = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Src1_Desc->setObjectName(QString::fromUtf8("label_09_LabelNo_Src1_Desc"));
        label_09_LabelNo_Src1_Desc->setMinimumSize(QSize(100, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Src1_Desc, 0, 2, 1, 1);

        horizontalSpacer_09_LabelNo = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_61->addItem(horizontalSpacer_09_LabelNo, 0, 3, 1, 1);

        label_09_LabelNo_Src2_Title = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Src2_Title->setObjectName(QString::fromUtf8("label_09_LabelNo_Src2_Title"));
        label_09_LabelNo_Src2_Title->setMinimumSize(QSize(75, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Src2_Title, 1, 1, 1, 1);

        label_09_LabelNo_Src2_Desc = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Src2_Desc->setObjectName(QString::fromUtf8("label_09_LabelNo_Src2_Desc"));
        label_09_LabelNo_Src2_Desc->setMinimumSize(QSize(100, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Src2_Desc, 1, 2, 1, 1);

        label_09_LabelNo_Scale = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Scale->setObjectName(QString::fromUtf8("label_09_LabelNo_Scale"));

        gridLayout_61->addWidget(label_09_LabelNo_Scale, 2, 1, 1, 1);

        doubleSpinBox_09_LabelNo_Scale = new QDoubleSpinBox(page_09_LabelNo);
        doubleSpinBox_09_LabelNo_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_09_LabelNo_Scale"));
        doubleSpinBox_09_LabelNo_Scale->setMinimumSize(QSize(100, 0));
        doubleSpinBox_09_LabelNo_Scale->setDecimals(3);
        doubleSpinBox_09_LabelNo_Scale->setMinimum(0.100000000000000);
        doubleSpinBox_09_LabelNo_Scale->setMaximum(100000.000000000000000);
        doubleSpinBox_09_LabelNo_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_09_LabelNo_Scale->setValue(1.000000000000000);

        gridLayout_61->addWidget(doubleSpinBox_09_LabelNo_Scale, 2, 2, 1, 1);

        label_09_LabelNo_Thickness = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Thickness->setObjectName(QString::fromUtf8("label_09_LabelNo_Thickness"));

        gridLayout_61->addWidget(label_09_LabelNo_Thickness, 3, 1, 1, 1);

        spinBox_09_LabelNo_Thickness = new QSpinBox(page_09_LabelNo);
        spinBox_09_LabelNo_Thickness->setObjectName(QString::fromUtf8("spinBox_09_LabelNo_Thickness"));
        spinBox_09_LabelNo_Thickness->setMinimumSize(QSize(100, 0));
        spinBox_09_LabelNo_Thickness->setMinimum(1);
        spinBox_09_LabelNo_Thickness->setMaximum(100000);

        gridLayout_61->addWidget(spinBox_09_LabelNo_Thickness, 3, 2, 1, 1);

        label_09_LabelNo_Position = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Position->setObjectName(QString::fromUtf8("label_09_LabelNo_Position"));

        gridLayout_61->addWidget(label_09_LabelNo_Position, 4, 1, 1, 1);

        checkBox_09_LabelNo_Position = new QCheckBox(page_09_LabelNo);
        checkBox_09_LabelNo_Position->setObjectName(QString::fromUtf8("checkBox_09_LabelNo_Position"));
        checkBox_09_LabelNo_Position->setChecked(true);

        gridLayout_61->addWidget(checkBox_09_LabelNo_Position, 4, 2, 1, 1);

        line_09_LabelNo_2 = new QFrame(page_09_LabelNo);
        line_09_LabelNo_2->setObjectName(QString::fromUtf8("line_09_LabelNo_2"));
        line_09_LabelNo_2->setFrameShape(QFrame::HLine);
        line_09_LabelNo_2->setFrameShadow(QFrame::Sunken);

        gridLayout_61->addWidget(line_09_LabelNo_2, 5, 1, 1, 3);

        label_09_LabelNo_Ch1_Title = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Ch1_Title->setObjectName(QString::fromUtf8("label_09_LabelNo_Ch1_Title"));
        label_09_LabelNo_Ch1_Title->setMinimumSize(QSize(75, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Ch1_Title, 6, 1, 1, 1);

        label_09_LabelNo_Ch1_Desc = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Ch1_Desc->setObjectName(QString::fromUtf8("label_09_LabelNo_Ch1_Desc"));
        label_09_LabelNo_Ch1_Desc->setMinimumSize(QSize(100, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Ch1_Desc, 6, 2, 1, 1);

        label_09_LabelNo_Ch2_Title = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Ch2_Title->setObjectName(QString::fromUtf8("label_09_LabelNo_Ch2_Title"));
        label_09_LabelNo_Ch2_Title->setMinimumSize(QSize(75, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Ch2_Title, 7, 1, 1, 1);

        label_09_LabelNo_Ch2_Desc = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Ch2_Desc->setObjectName(QString::fromUtf8("label_09_LabelNo_Ch2_Desc"));
        label_09_LabelNo_Ch2_Desc->setMinimumSize(QSize(100, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Ch2_Desc, 7, 2, 1, 1);

        label_09_LabelNo_Ch3_Title = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Ch3_Title->setObjectName(QString::fromUtf8("label_09_LabelNo_Ch3_Title"));
        label_09_LabelNo_Ch3_Title->setMinimumSize(QSize(75, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Ch3_Title, 8, 1, 1, 1);

        label_09_LabelNo_Ch3_Desc = new QLabel(page_09_LabelNo);
        label_09_LabelNo_Ch3_Desc->setObjectName(QString::fromUtf8("label_09_LabelNo_Ch3_Desc"));
        label_09_LabelNo_Ch3_Desc->setMinimumSize(QSize(100, 0));

        gridLayout_61->addWidget(label_09_LabelNo_Ch3_Desc, 8, 2, 1, 1);

        verticalSpacer_09_LabelNo = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_61->addItem(verticalSpacer_09_LabelNo, 9, 1, 1, 3);

        stackedWidget_Settings_09_Other->addWidget(page_09_LabelNo);
        page_09_NeighborhoodConfig = new QWidget();
        page_09_NeighborhoodConfig->setObjectName(QString::fromUtf8("page_09_NeighborhoodConfig"));
        gridLayout_91 = new QGridLayout(page_09_NeighborhoodConfig);
        gridLayout_91->setObjectName(QString::fromUtf8("gridLayout_91"));
        line_09_NeighborhoodConfig = new QFrame(page_09_NeighborhoodConfig);
        line_09_NeighborhoodConfig->setObjectName(QString::fromUtf8("line_09_NeighborhoodConfig"));
        line_09_NeighborhoodConfig->setFrameShape(QFrame::VLine);
        line_09_NeighborhoodConfig->setFrameShadow(QFrame::Sunken);

        gridLayout_91->addWidget(line_09_NeighborhoodConfig, 0, 0, 3, 1);

        label_09_NeighborhoodConfig_Euler_Description = new QLabel(page_09_NeighborhoodConfig);
        label_09_NeighborhoodConfig_Euler_Description->setObjectName(QString::fromUtf8("label_09_NeighborhoodConfig_Euler_Description"));
        label_09_NeighborhoodConfig_Euler_Description->setMinimumSize(QSize(75, 0));
        label_09_NeighborhoodConfig_Euler_Description->setMaximumSize(QSize(75, 16777215));

        gridLayout_91->addWidget(label_09_NeighborhoodConfig_Euler_Description, 1, 1, 1, 1);

        label_09_NeighborhoodConfig_Euler_Number = new QLabel(page_09_NeighborhoodConfig);
        label_09_NeighborhoodConfig_Euler_Number->setObjectName(QString::fromUtf8("label_09_NeighborhoodConfig_Euler_Number"));
        label_09_NeighborhoodConfig_Euler_Number->setMinimumSize(QSize(100, 0));
        label_09_NeighborhoodConfig_Euler_Number->setMaximumSize(QSize(100, 16777215));

        gridLayout_91->addWidget(label_09_NeighborhoodConfig_Euler_Number, 1, 2, 1, 1);

        verticalSpacer_09_NeighborhoodConfig = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_91->addItem(verticalSpacer_09_NeighborhoodConfig, 2, 3, 1, 1);

        horizontalSpacer_09_NeighborhoodConfig = new QSpacerItem(210, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_91->addItem(horizontalSpacer_09_NeighborhoodConfig, 1, 3, 1, 1);

        label_09_NeighborhoodConfig = new QLabel(page_09_NeighborhoodConfig);
        label_09_NeighborhoodConfig->setObjectName(QString::fromUtf8("label_09_NeighborhoodConfig"));

        gridLayout_91->addWidget(label_09_NeighborhoodConfig, 0, 1, 1, 3);

        stackedWidget_Settings_09_Other->addWidget(page_09_NeighborhoodConfig);
        page_09_MotionField = new QWidget();
        page_09_MotionField->setObjectName(QString::fromUtf8("page_09_MotionField"));
        gridLayout_93 = new QGridLayout(page_09_MotionField);
        gridLayout_93->setObjectName(QString::fromUtf8("gridLayout_93"));
        horizontalSpacer_09_MotionField = new QSpacerItem(206, 43, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_93->addItem(horizontalSpacer_09_MotionField, 0, 3, 2, 1);

        verticalSpacer_09_MotionField = new QSpacerItem(20, 159, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_93->addItem(verticalSpacer_09_MotionField, 2, 3, 1, 1);

        line_09_MotionField = new QFrame(page_09_MotionField);
        line_09_MotionField->setObjectName(QString::fromUtf8("line_09_MotionField"));
        line_09_MotionField->setFrameShape(QFrame::VLine);
        line_09_MotionField->setFrameShadow(QFrame::Sunken);

        gridLayout_93->addWidget(line_09_MotionField, 0, 0, 3, 1);

        label_09_MotionField_SizeSpace = new QLabel(page_09_MotionField);
        label_09_MotionField_SizeSpace->setObjectName(QString::fromUtf8("label_09_MotionField_SizeSpace"));
        label_09_MotionField_SizeSpace->setMinimumSize(QSize(75, 0));
        label_09_MotionField_SizeSpace->setMaximumSize(QSize(75, 16777215));

        gridLayout_93->addWidget(label_09_MotionField_SizeSpace, 0, 1, 1, 1);

        label_09_MotionField_SizeTime = new QLabel(page_09_MotionField);
        label_09_MotionField_SizeTime->setObjectName(QString::fromUtf8("label_09_MotionField_SizeTime"));
        label_09_MotionField_SizeTime->setMinimumSize(QSize(75, 0));
        label_09_MotionField_SizeTime->setMaximumSize(QSize(75, 16777215));

        gridLayout_93->addWidget(label_09_MotionField_SizeTime, 1, 1, 1, 1);

        spinBox_09_MotionField_SizeSpace = new QSpinBox(page_09_MotionField);
        spinBox_09_MotionField_SizeSpace->setObjectName(QString::fromUtf8("spinBox_09_MotionField_SizeSpace"));
        spinBox_09_MotionField_SizeSpace->setMinimumSize(QSize(100, 0));
        spinBox_09_MotionField_SizeSpace->setMaximumSize(QSize(100, 16777215));
        spinBox_09_MotionField_SizeSpace->setMinimum(3);
        spinBox_09_MotionField_SizeSpace->setMaximum(999);
        spinBox_09_MotionField_SizeSpace->setSingleStep(2);
        spinBox_09_MotionField_SizeSpace->setValue(5);

        gridLayout_93->addWidget(spinBox_09_MotionField_SizeSpace, 0, 2, 1, 1);

        spinBox_09_MotionField_SizeTime = new QSpinBox(page_09_MotionField);
        spinBox_09_MotionField_SizeTime->setObjectName(QString::fromUtf8("spinBox_09_MotionField_SizeTime"));
        spinBox_09_MotionField_SizeTime->setMinimumSize(QSize(100, 0));
        spinBox_09_MotionField_SizeTime->setMaximumSize(QSize(100, 16777215));
        spinBox_09_MotionField_SizeTime->setMinimum(3);
        spinBox_09_MotionField_SizeTime->setMaximum(999);
        spinBox_09_MotionField_SizeTime->setSingleStep(2);

        gridLayout_93->addWidget(spinBox_09_MotionField_SizeTime, 1, 2, 1, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_MotionField);
        page_09_Classifier_kNN = new QWidget();
        page_09_Classifier_kNN->setObjectName(QString::fromUtf8("page_09_Classifier_kNN"));
        gridLayout_99 = new QGridLayout(page_09_Classifier_kNN);
        gridLayout_99->setObjectName(QString::fromUtf8("gridLayout_99"));
        verticalSpacer_2 = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_99->addItem(verticalSpacer_2, 3, 1, 1, 1);

        line_4 = new QFrame(page_09_Classifier_kNN);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_99->addWidget(line_4, 0, 0, 4, 1);

        label_3 = new QLabel(page_09_Classifier_kNN);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(75, 0));
        label_3->setMaximumSize(QSize(75, 16777215));

        gridLayout_99->addWidget(label_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(206, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_99->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_4 = new QLabel(page_09_Classifier_kNN);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(75, 0));
        label_4->setMaximumSize(QSize(75, 16777215));

        gridLayout_99->addWidget(label_4, 1, 1, 1, 1);

        label_5 = new QLabel(page_09_Classifier_kNN);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(75, 0));
        label_5->setMaximumSize(QSize(75, 16777215));

        gridLayout_99->addWidget(label_5, 2, 1, 1, 1);

        label_6 = new QLabel(page_09_Classifier_kNN);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setMaximumSize(QSize(100, 16777215));

        gridLayout_99->addWidget(label_6, 2, 2, 1, 1);

        label_7 = new QLabel(page_09_Classifier_kNN);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(100, 16777215));

        gridLayout_99->addWidget(label_7, 1, 2, 1, 1);

        spinBox_09_kNN_n = new QSpinBox(page_09_Classifier_kNN);
        spinBox_09_kNN_n->setObjectName(QString::fromUtf8("spinBox_09_kNN_n"));
        spinBox_09_kNN_n->setMinimumSize(QSize(100, 0));
        spinBox_09_kNN_n->setMaximumSize(QSize(100, 16777215));
        spinBox_09_kNN_n->setMinimum(1);
        spinBox_09_kNN_n->setMaximum(9999);
        spinBox_09_kNN_n->setValue(3);

        gridLayout_99->addWidget(spinBox_09_kNN_n, 0, 2, 1, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_Classifier_kNN);
        page_09_HDR = new QWidget();
        page_09_HDR->setObjectName(QString::fromUtf8("page_09_HDR"));
        gridLayout_109 = new QGridLayout(page_09_HDR);
        gridLayout_109->setObjectName(QString::fromUtf8("gridLayout_109"));
        label_09_HDR_Dimension = new QLabel(page_09_HDR);
        label_09_HDR_Dimension->setObjectName(QString::fromUtf8("label_09_HDR_Dimension"));
        label_09_HDR_Dimension->setMinimumSize(QSize(75, 0));
        label_09_HDR_Dimension->setMaximumSize(QSize(75, 16777215));

        gridLayout_109->addWidget(label_09_HDR_Dimension, 0, 0, 1, 1);

        doubleSpinBox_09_HDR_Exposure_Min = new QDoubleSpinBox(page_09_HDR);
        doubleSpinBox_09_HDR_Exposure_Min->setObjectName(QString::fromUtf8("doubleSpinBox_09_HDR_Exposure_Min"));
        doubleSpinBox_09_HDR_Exposure_Min->setMinimumSize(QSize(150, 0));
        doubleSpinBox_09_HDR_Exposure_Min->setMaximumSize(QSize(150, 16777215));
        doubleSpinBox_09_HDR_Exposure_Min->setDecimals(3);
        doubleSpinBox_09_HDR_Exposure_Min->setMinimum(0.001000000000000);
        doubleSpinBox_09_HDR_Exposure_Min->setValue(20.000000000000000);

        gridLayout_109->addWidget(doubleSpinBox_09_HDR_Exposure_Min, 2, 1, 1, 2);

        label_09_HDR_ExpFirst_Description = new QLabel(page_09_HDR);
        label_09_HDR_ExpFirst_Description->setObjectName(QString::fromUtf8("label_09_HDR_ExpFirst_Description"));

        gridLayout_109->addWidget(label_09_HDR_ExpFirst_Description, 2, 3, 1, 1);

        line_09_HDR_2 = new QFrame(page_09_HDR);
        line_09_HDR_2->setObjectName(QString::fromUtf8("line_09_HDR_2"));
        line_09_HDR_2->setFrameShape(QFrame::HLine);
        line_09_HDR_2->setFrameShadow(QFrame::Sunken);

        gridLayout_109->addWidget(line_09_HDR_2, 7, 0, 1, 5);

        comboBox_09_HDR_ProjectStat = new QComboBox(page_09_HDR);
        comboBox_09_HDR_ProjectStat->addItem(QString());
        comboBox_09_HDR_ProjectStat->setObjectName(QString::fromUtf8("comboBox_09_HDR_ProjectStat"));
        comboBox_09_HDR_ProjectStat->setMinimumSize(QSize(150, 0));
        comboBox_09_HDR_ProjectStat->setMaximumSize(QSize(150, 16777215));

        gridLayout_109->addWidget(comboBox_09_HDR_ProjectStat, 6, 1, 1, 2);

        label_09_HDR_Project_Description = new QLabel(page_09_HDR);
        label_09_HDR_Project_Description->setObjectName(QString::fromUtf8("label_09_HDR_Project_Description"));

        gridLayout_109->addWidget(label_09_HDR_Project_Description, 5, 3, 1, 1);

        label_09_HDR_Range_Description = new QLabel(page_09_HDR);
        label_09_HDR_Range_Description->setObjectName(QString::fromUtf8("label_09_HDR_Range_Description"));

        gridLayout_109->addWidget(label_09_HDR_Range_Description, 9, 3, 1, 1);

        label_09_HDR_Dim_Description = new QLabel(page_09_HDR);
        label_09_HDR_Dim_Description->setObjectName(QString::fromUtf8("label_09_HDR_Dim_Description"));

        gridLayout_109->addWidget(label_09_HDR_Dim_Description, 0, 3, 1, 1);

        label_09_HDR_Projection = new QLabel(page_09_HDR);
        label_09_HDR_Projection->setObjectName(QString::fromUtf8("label_09_HDR_Projection"));

        gridLayout_109->addWidget(label_09_HDR_Projection, 5, 0, 2, 1);

        horizontalSpacer_09_HDR = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_109->addItem(horizontalSpacer_09_HDR, 0, 4, 1, 1);

        doubleSpinBox_09_HDR_Thresh_High = new QDoubleSpinBox(page_09_HDR);
        doubleSpinBox_09_HDR_Thresh_High->setObjectName(QString::fromUtf8("doubleSpinBox_09_HDR_Thresh_High"));
        doubleSpinBox_09_HDR_Thresh_High->setMinimumSize(QSize(72, 0));
        doubleSpinBox_09_HDR_Thresh_High->setMaximumSize(QSize(72, 16777215));
        doubleSpinBox_09_HDR_Thresh_High->setMinimum(-999999999.000000000000000);
        doubleSpinBox_09_HDR_Thresh_High->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_HDR_Thresh_High->setValue(240.000000000000000);

        gridLayout_109->addWidget(doubleSpinBox_09_HDR_Thresh_High, 9, 2, 1, 1);

        doubleSpinBox_09_HDR_Exposure_Factor = new QDoubleSpinBox(page_09_HDR);
        doubleSpinBox_09_HDR_Exposure_Factor->setObjectName(QString::fromUtf8("doubleSpinBox_09_HDR_Exposure_Factor"));
        doubleSpinBox_09_HDR_Exposure_Factor->setMinimumSize(QSize(150, 0));
        doubleSpinBox_09_HDR_Exposure_Factor->setMaximumSize(QSize(150, 16777215));
        doubleSpinBox_09_HDR_Exposure_Factor->setDecimals(3);
        doubleSpinBox_09_HDR_Exposure_Factor->setMinimum(0.001000000000000);
        doubleSpinBox_09_HDR_Exposure_Factor->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_HDR_Exposure_Factor->setSingleStep(0.100000000000000);
        doubleSpinBox_09_HDR_Exposure_Factor->setValue(2.000000000000000);

        gridLayout_109->addWidget(doubleSpinBox_09_HDR_Exposure_Factor, 3, 1, 1, 2);

        label_09_HDR_ExpFactor_Description = new QLabel(page_09_HDR);
        label_09_HDR_ExpFactor_Description->setObjectName(QString::fromUtf8("label_09_HDR_ExpFactor_Description"));

        gridLayout_109->addWidget(label_09_HDR_ExpFactor_Description, 3, 3, 1, 1);

        line_09_HDR_1 = new QFrame(page_09_HDR);
        line_09_HDR_1->setObjectName(QString::fromUtf8("line_09_HDR_1"));
        line_09_HDR_1->setFrameShape(QFrame::HLine);
        line_09_HDR_1->setFrameShadow(QFrame::Sunken);

        gridLayout_109->addWidget(line_09_HDR_1, 4, 0, 1, 5);

        label_09_HDR_Thres = new QLabel(page_09_HDR);
        label_09_HDR_Thres->setObjectName(QString::fromUtf8("label_09_HDR_Thres"));

        gridLayout_109->addWidget(label_09_HDR_Thres, 8, 0, 2, 1);

        comboBox_09_HDR_Dim = new QComboBox(page_09_HDR);
        comboBox_09_HDR_Dim->addItem(QString());
        comboBox_09_HDR_Dim->setObjectName(QString::fromUtf8("comboBox_09_HDR_Dim"));
        comboBox_09_HDR_Dim->setMinimumSize(QSize(150, 0));
        comboBox_09_HDR_Dim->setMaximumSize(QSize(150, 16777215));

        gridLayout_109->addWidget(comboBox_09_HDR_Dim, 0, 1, 1, 2);

        label_09_HDR_Stat_Description = new QLabel(page_09_HDR);
        label_09_HDR_Stat_Description->setObjectName(QString::fromUtf8("label_09_HDR_Stat_Description"));

        gridLayout_109->addWidget(label_09_HDR_Stat_Description, 6, 3, 1, 1);

        label_09_HDR_Thres_Description = new QLabel(page_09_HDR);
        label_09_HDR_Thres_Description->setObjectName(QString::fromUtf8("label_09_HDR_Thres_Description"));

        gridLayout_109->addWidget(label_09_HDR_Thres_Description, 8, 3, 1, 1);

        doubleSpinBox_09_HDR_Thresh_Low = new QDoubleSpinBox(page_09_HDR);
        doubleSpinBox_09_HDR_Thresh_Low->setObjectName(QString::fromUtf8("doubleSpinBox_09_HDR_Thresh_Low"));
        doubleSpinBox_09_HDR_Thresh_Low->setMinimumSize(QSize(72, 0));
        doubleSpinBox_09_HDR_Thresh_Low->setMaximumSize(QSize(72, 16777215));
        doubleSpinBox_09_HDR_Thresh_Low->setMinimum(-999999999.000000000000000);
        doubleSpinBox_09_HDR_Thresh_Low->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_HDR_Thresh_Low->setValue(16.000000000000000);

        gridLayout_109->addWidget(doubleSpinBox_09_HDR_Thresh_Low, 9, 1, 1, 1);

        checkBox_09_HDR_Thresh = new QCheckBox(page_09_HDR);
        checkBox_09_HDR_Thresh->setObjectName(QString::fromUtf8("checkBox_09_HDR_Thresh"));
        checkBox_09_HDR_Thresh->setMinimumSize(QSize(150, 0));
        checkBox_09_HDR_Thresh->setMaximumSize(QSize(150, 16777215));
        checkBox_09_HDR_Thresh->setChecked(true);

        gridLayout_109->addWidget(checkBox_09_HDR_Thresh, 8, 1, 1, 2);

        verticalSpacer_09_HDR = new QSpacerItem(416, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_109->addItem(verticalSpacer_09_HDR, 10, 0, 1, 5);

        checkBox_09_HDR_Project = new QCheckBox(page_09_HDR);
        checkBox_09_HDR_Project->setObjectName(QString::fromUtf8("checkBox_09_HDR_Project"));
        checkBox_09_HDR_Project->setChecked(true);

        gridLayout_109->addWidget(checkBox_09_HDR_Project, 5, 1, 1, 2);

        line_09_HDR_3 = new QFrame(page_09_HDR);
        line_09_HDR_3->setObjectName(QString::fromUtf8("line_09_HDR_3"));
        line_09_HDR_3->setFrameShape(QFrame::HLine);
        line_09_HDR_3->setFrameShadow(QFrame::Sunken);

        gridLayout_109->addWidget(line_09_HDR_3, 1, 0, 1, 5);

        label_09_HDR_Exp = new QLabel(page_09_HDR);
        label_09_HDR_Exp->setObjectName(QString::fromUtf8("label_09_HDR_Exp"));
        label_09_HDR_Exp->setMinimumSize(QSize(75, 0));
        label_09_HDR_Exp->setMaximumSize(QSize(75, 16777215));

        gridLayout_109->addWidget(label_09_HDR_Exp, 2, 0, 2, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_HDR);
        page_09_RelationStat = new QWidget();
        page_09_RelationStat->setObjectName(QString::fromUtf8("page_09_RelationStat"));
        gridLayout_112 = new QGridLayout(page_09_RelationStat);
        gridLayout_112->setObjectName(QString::fromUtf8("gridLayout_112"));
        comboBox_09_RelationStat_StatAngle = new QComboBox(page_09_RelationStat);
        comboBox_09_RelationStat_StatAngle->setObjectName(QString::fromUtf8("comboBox_09_RelationStat_StatAngle"));
        comboBox_09_RelationStat_StatAngle->setEnabled(false);
        comboBox_09_RelationStat_StatAngle->setMinimumSize(QSize(285, 0));
        comboBox_09_RelationStat_StatAngle->setMaximumSize(QSize(285, 16777215));

        gridLayout_112->addWidget(comboBox_09_RelationStat_StatAngle, 1, 2, 1, 1);

        comboBox_09_RelationStat_StatDistance = new QComboBox(page_09_RelationStat);
        comboBox_09_RelationStat_StatDistance->setObjectName(QString::fromUtf8("comboBox_09_RelationStat_StatDistance"));
        comboBox_09_RelationStat_StatDistance->setMinimumSize(QSize(285, 0));
        comboBox_09_RelationStat_StatDistance->setMaximumSize(QSize(285, 16777215));

        gridLayout_112->addWidget(comboBox_09_RelationStat_StatDistance, 0, 2, 1, 1);

        radioButton_09_RelationStat_Angle = new QRadioButton(page_09_RelationStat);
        radioButton_09_RelationStat_Angle->setObjectName(QString::fromUtf8("radioButton_09_RelationStat_Angle"));
        radioButton_09_RelationStat_Angle->setMinimumSize(QSize(13, 0));
        radioButton_09_RelationStat_Angle->setMaximumSize(QSize(13, 16777215));

        gridLayout_112->addWidget(radioButton_09_RelationStat_Angle, 1, 1, 1, 1);

        radioButton_09_RelationStat_Distance = new QRadioButton(page_09_RelationStat);
        radioButton_09_RelationStat_Distance->setObjectName(QString::fromUtf8("radioButton_09_RelationStat_Distance"));
        radioButton_09_RelationStat_Distance->setMinimumSize(QSize(13, 0));
        radioButton_09_RelationStat_Distance->setMaximumSize(QSize(13, 16777215));
        radioButton_09_RelationStat_Distance->setChecked(true);

        gridLayout_112->addWidget(radioButton_09_RelationStat_Distance, 0, 1, 1, 1);

        label_09_RelationStat_Distance = new QLabel(page_09_RelationStat);
        label_09_RelationStat_Distance->setObjectName(QString::fromUtf8("label_09_RelationStat_Distance"));
        label_09_RelationStat_Distance->setMinimumSize(QSize(75, 0));
        label_09_RelationStat_Distance->setMaximumSize(QSize(75, 16777215));

        gridLayout_112->addWidget(label_09_RelationStat_Distance, 0, 0, 1, 1);

        label_09_RelationStat_Angle = new QLabel(page_09_RelationStat);
        label_09_RelationStat_Angle->setObjectName(QString::fromUtf8("label_09_RelationStat_Angle"));
        label_09_RelationStat_Angle->setMinimumSize(QSize(75, 0));
        label_09_RelationStat_Angle->setMaximumSize(QSize(75, 16777215));

        gridLayout_112->addWidget(label_09_RelationStat_Angle, 1, 0, 1, 1);

        verticalSpacer_09_RelationStat = new QSpacerItem(416, 159, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_112->addItem(verticalSpacer_09_RelationStat, 2, 0, 1, 4);

        horizontalSpacer_09_RelationStat = new QSpacerItem(25, 43, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_112->addItem(horizontalSpacer_09_RelationStat, 0, 3, 2, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_RelationStat);
        page_09_ZernikeStack = new QWidget();
        page_09_ZernikeStack->setObjectName(QString::fromUtf8("page_09_ZernikeStack"));
        gridLayout_114 = new QGridLayout(page_09_ZernikeStack);
        gridLayout_114->setObjectName(QString::fromUtf8("gridLayout_114"));
        label_09_ZernikeStack_Radius = new QLabel(page_09_ZernikeStack);
        label_09_ZernikeStack_Radius->setObjectName(QString::fromUtf8("label_09_ZernikeStack_Radius"));
        label_09_ZernikeStack_Radius->setMinimumSize(QSize(75, 0));
        label_09_ZernikeStack_Radius->setMaximumSize(QSize(75, 16777215));

        gridLayout_114->addWidget(label_09_ZernikeStack_Radius, 0, 0, 1, 1);

        spinBox_09_ZernikeStack_Radius = new QSpinBox(page_09_ZernikeStack);
        spinBox_09_ZernikeStack_Radius->setObjectName(QString::fromUtf8("spinBox_09_ZernikeStack_Radius"));
        spinBox_09_ZernikeStack_Radius->setMinimumSize(QSize(100, 0));
        spinBox_09_ZernikeStack_Radius->setMaximumSize(QSize(100, 16777215));
        spinBox_09_ZernikeStack_Radius->setMinimum(1);
        spinBox_09_ZernikeStack_Radius->setMaximum(99999);
        spinBox_09_ZernikeStack_Radius->setValue(100);

        gridLayout_114->addWidget(spinBox_09_ZernikeStack_Radius, 0, 1, 1, 1);

        horizontalSpacer_09_ZernikeStack = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_114->addItem(horizontalSpacer_09_ZernikeStack, 0, 2, 1, 1);

        label_09_ZernikeStack_J = new QLabel(page_09_ZernikeStack);
        label_09_ZernikeStack_J->setObjectName(QString::fromUtf8("label_09_ZernikeStack_J"));
        label_09_ZernikeStack_J->setMinimumSize(QSize(75, 0));
        label_09_ZernikeStack_J->setMaximumSize(QSize(75, 16777215));

        gridLayout_114->addWidget(label_09_ZernikeStack_J, 1, 0, 1, 1);

        spinBox_09_ZernikeStack_J = new QSpinBox(page_09_ZernikeStack);
        spinBox_09_ZernikeStack_J->setObjectName(QString::fromUtf8("spinBox_09_ZernikeStack_J"));
        spinBox_09_ZernikeStack_J->setMinimumSize(QSize(100, 0));
        spinBox_09_ZernikeStack_J->setMaximumSize(QSize(100, 16777215));
        spinBox_09_ZernikeStack_J->setMinimum(1);
        spinBox_09_ZernikeStack_J->setMaximum(9999);
        spinBox_09_ZernikeStack_J->setValue(35);

        gridLayout_114->addWidget(spinBox_09_ZernikeStack_J, 1, 1, 1, 1);

        verticalSpacer_09_ZernikeStack = new QSpacerItem(20, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_114->addItem(verticalSpacer_09_ZernikeStack, 2, 1, 1, 1);

        stackedWidget_Settings_09_Other->addWidget(page_09_ZernikeStack);
        page_09_InterferometerMichelson = new QWidget();
        page_09_InterferometerMichelson->setObjectName(QString::fromUtf8("page_09_InterferometerMichelson"));
        gridLayout_131 = new QGridLayout(page_09_InterferometerMichelson);
        gridLayout_131->setSpacing(2);
        gridLayout_131->setObjectName(QString::fromUtf8("gridLayout_131"));
        gridLayout_131->setContentsMargins(2, 2, 2, 2);
        groupBox_09_Michelson_Scene_px = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_Scene_px->setObjectName(QString::fromUtf8("groupBox_09_Michelson_Scene_px"));
        groupBox_09_Michelson_Scene_px->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_Scene_px->setMaximumSize(QSize(140, 16777215));
        gridLayout_136 = new QGridLayout(groupBox_09_Michelson_Scene_px);
        gridLayout_136->setObjectName(QString::fromUtf8("gridLayout_136"));
        gridLayout_136->setHorizontalSpacing(1);
        gridLayout_136->setVerticalSpacing(0);
        gridLayout_136->setContentsMargins(0, 0, 0, 2);
        spinBox_09_Michelson_Scene_Size_X = new QSpinBox(groupBox_09_Michelson_Scene_px);
        spinBox_09_Michelson_Scene_Size_X->setObjectName(QString::fromUtf8("spinBox_09_Michelson_Scene_Size_X"));
        QSizePolicy sizePolicy13(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(spinBox_09_Michelson_Scene_Size_X->sizePolicy().hasHeightForWidth());
        spinBox_09_Michelson_Scene_Size_X->setSizePolicy(sizePolicy13);
        spinBox_09_Michelson_Scene_Size_X->setMinimumSize(QSize(0, 0));
        spinBox_09_Michelson_Scene_Size_X->setMaximumSize(QSize(16777215, 16777215));
        spinBox_09_Michelson_Scene_Size_X->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        spinBox_09_Michelson_Scene_Size_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_09_Michelson_Scene_Size_X->setProperty("showGroupSeparator", QVariant(true));
        spinBox_09_Michelson_Scene_Size_X->setMinimum(1);
        spinBox_09_Michelson_Scene_Size_X->setMaximum(999999);
        spinBox_09_Michelson_Scene_Size_X->setValue(500);

        gridLayout_136->addWidget(spinBox_09_Michelson_Scene_Size_X, 0, 0, 1, 1);

        spinBox_09_Michelson_Scene_Size_Y = new QSpinBox(groupBox_09_Michelson_Scene_px);
        spinBox_09_Michelson_Scene_Size_Y->setObjectName(QString::fromUtf8("spinBox_09_Michelson_Scene_Size_Y"));
        sizePolicy13.setHeightForWidth(spinBox_09_Michelson_Scene_Size_Y->sizePolicy().hasHeightForWidth());
        spinBox_09_Michelson_Scene_Size_Y->setSizePolicy(sizePolicy13);
        spinBox_09_Michelson_Scene_Size_Y->setMinimumSize(QSize(0, 0));
        spinBox_09_Michelson_Scene_Size_Y->setMaximumSize(QSize(16777215, 16777215));
        spinBox_09_Michelson_Scene_Size_Y->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        spinBox_09_Michelson_Scene_Size_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_09_Michelson_Scene_Size_Y->setProperty("showGroupSeparator", QVariant(true));
        spinBox_09_Michelson_Scene_Size_Y->setMinimum(1);
        spinBox_09_Michelson_Scene_Size_Y->setMaximum(999999);
        spinBox_09_Michelson_Scene_Size_Y->setValue(500);

        gridLayout_136->addWidget(spinBox_09_Michelson_Scene_Size_Y, 1, 0, 1, 1);

        spinBox_09_Michelson_Scene_Size_Z = new QSpinBox(groupBox_09_Michelson_Scene_px);
        spinBox_09_Michelson_Scene_Size_Z->setObjectName(QString::fromUtf8("spinBox_09_Michelson_Scene_Size_Z"));
        sizePolicy13.setHeightForWidth(spinBox_09_Michelson_Scene_Size_Z->sizePolicy().hasHeightForWidth());
        spinBox_09_Michelson_Scene_Size_Z->setSizePolicy(sizePolicy13);
        spinBox_09_Michelson_Scene_Size_Z->setMinimumSize(QSize(0, 0));
        spinBox_09_Michelson_Scene_Size_Z->setMaximumSize(QSize(16777215, 16777215));
        spinBox_09_Michelson_Scene_Size_Z->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        spinBox_09_Michelson_Scene_Size_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_09_Michelson_Scene_Size_Z->setProperty("showGroupSeparator", QVariant(true));
        spinBox_09_Michelson_Scene_Size_Z->setMinimum(1);
        spinBox_09_Michelson_Scene_Size_Z->setMaximum(999999);
        spinBox_09_Michelson_Scene_Size_Z->setValue(1);

        gridLayout_136->addWidget(spinBox_09_Michelson_Scene_Size_Z, 2, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_Scene_px, 1, 0, 1, 1);

        groupBox_09_Michelson_SP = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_SP->setObjectName(QString::fromUtf8("groupBox_09_Michelson_SP"));
        groupBox_09_Michelson_SP->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_SP->setMaximumSize(QSize(140, 16777215));
        gridLayout_135 = new QGridLayout(groupBox_09_Michelson_SP);
        gridLayout_135->setObjectName(QString::fromUtf8("gridLayout_135"));
        gridLayout_135->setHorizontalSpacing(1);
        gridLayout_135->setVerticalSpacing(0);
        gridLayout_135->setContentsMargins(0, 0, 0, 2);
        label_09_Michelson_Splitter = new QLabel(groupBox_09_Michelson_SP);
        label_09_Michelson_Splitter->setObjectName(QString::fromUtf8("label_09_Michelson_Splitter"));
        QSizePolicy sizePolicy14(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(label_09_Michelson_Splitter->sizePolicy().hasHeightForWidth());
        label_09_Michelson_Splitter->setSizePolicy(sizePolicy14);
        label_09_Michelson_Splitter->setMinimumSize(QSize(0, 0));
        label_09_Michelson_Splitter->setMaximumSize(QSize(16777215, 16777215));
        label_09_Michelson_Splitter->setAlignment(Qt::AlignCenter);

        gridLayout_135->addWidget(label_09_Michelson_Splitter, 0, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_SP, 2, 1, 1, 1);

        verticalSpacer_09_Michelson = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_131->addItem(verticalSpacer_09_Michelson, 5, 1, 1, 1);

        groupBox_09_Michelson_Axis = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_Axis->setObjectName(QString::fromUtf8("groupBox_09_Michelson_Axis"));
        groupBox_09_Michelson_Axis->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_Axis->setMaximumSize(QSize(140, 16777215));
        gridLayout_141 = new QGridLayout(groupBox_09_Michelson_Axis);
        gridLayout_141->setObjectName(QString::fromUtf8("gridLayout_141"));
        gridLayout_141->setHorizontalSpacing(1);
        gridLayout_141->setVerticalSpacing(0);
        gridLayout_141->setContentsMargins(0, 0, 0, 2);
        label_18 = new QLabel(groupBox_09_Michelson_Axis);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_141->addWidget(label_18, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_09_Michelson_Axis);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_141->addWidget(label_16, 0, 0, 1, 1);

        label_19 = new QLabel(groupBox_09_Michelson_Axis);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_141->addWidget(label_19, 0, 2, 1, 1);

        label_21 = new QLabel(groupBox_09_Michelson_Axis);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_141->addWidget(label_21, 1, 0, 1, 1);

        label_20 = new QLabel(groupBox_09_Michelson_Axis);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_141->addWidget(label_20, 1, 1, 1, 1);

        label_22 = new QLabel(groupBox_09_Michelson_Axis);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_141->addWidget(label_22, 1, 2, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_Axis, 3, 2, 1, 1);

        groupBox_09_Michelson_M1 = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_M1->setObjectName(QString::fromUtf8("groupBox_09_Michelson_M1"));
        groupBox_09_Michelson_M1->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_M1->setMaximumSize(QSize(140, 16777215));
        gridLayout_139 = new QGridLayout(groupBox_09_Michelson_M1);
        gridLayout_139->setObjectName(QString::fromUtf8("gridLayout_139"));
        gridLayout_139->setHorizontalSpacing(1);
        gridLayout_139->setVerticalSpacing(0);
        gridLayout_139->setContentsMargins(0, 0, 0, 2);
        doubleSpinBox_09_Michelson_Mirror1_angle_y = new QDoubleSpinBox(groupBox_09_Michelson_M1);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Mirror1_angle_y"));
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setEnabled(false);
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Mirror1_angle_y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setDecimals(3);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setMinimum(-45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setMaximum(45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setSingleStep(0.250000000000000);
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setValue(0.000000000000000);

        gridLayout_139->addWidget(doubleSpinBox_09_Michelson_Mirror1_angle_y, 2, 0, 1, 1);

        verticalLayout_09_Michelson_M1 = new QVBoxLayout();
        verticalLayout_09_Michelson_M1->setSpacing(1);
        verticalLayout_09_Michelson_M1->setObjectName(QString::fromUtf8("verticalLayout_09_Michelson_M1"));
        checkBox_09_Michelson_Beam_atM1_SO = new QCheckBox(groupBox_09_Michelson_M1);
        checkBox_09_Michelson_Beam_atM1_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atM1_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atM1_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atM1_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atM1_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atM1_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atM1_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atM1_SO->setChecked(true);

        verticalLayout_09_Michelson_M1->addWidget(checkBox_09_Michelson_Beam_atM1_SO);

        checkBox_09_Michelson_Beam_atM1_M1_SO = new QCheckBox(groupBox_09_Michelson_M1);
        checkBox_09_Michelson_Beam_atM1_M1_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atM1_M1_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atM1_M1_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atM1_M1_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atM1_M1_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atM1_M1_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atM1_M1_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atM1_M1_SO->setChecked(true);

        verticalLayout_09_Michelson_M1->addWidget(checkBox_09_Michelson_Beam_atM1_M1_SO);


        gridLayout_139->addLayout(verticalLayout_09_Michelson_M1, 0, 1, 3, 1);

        doubleSpinBox_09_Michelson_Mirror1_distance = new QDoubleSpinBox(groupBox_09_Michelson_M1);
        doubleSpinBox_09_Michelson_Mirror1_distance->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Mirror1_distance"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Mirror1_distance->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Mirror1_distance->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Mirror1_distance->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Mirror1_distance->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Mirror1_distance->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Mirror1_distance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Mirror1_distance->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_09_Michelson_Mirror1_distance->setDecimals(3);
        doubleSpinBox_09_Michelson_Mirror1_distance->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_Michelson_Mirror1_distance->setSingleStep(0.010000000000000);
        doubleSpinBox_09_Michelson_Mirror1_distance->setValue(4.000000000000000);

        gridLayout_139->addWidget(doubleSpinBox_09_Michelson_Mirror1_distance, 0, 0, 1, 1);

        doubleSpinBox_09_Michelson_Mirror1_angle_x = new QDoubleSpinBox(groupBox_09_Michelson_M1);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Mirror1_angle_x"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Mirror1_angle_x->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setDecimals(3);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setMinimum(-45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setMaximum(45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setSingleStep(0.250000000000000);
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setValue(0.000000000000000);

        gridLayout_139->addWidget(doubleSpinBox_09_Michelson_Mirror1_angle_x, 1, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_M1, 1, 1, 1, 1);

        groupBox_09_Michelson_DE = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_DE->setObjectName(QString::fromUtf8("groupBox_09_Michelson_DE"));
        groupBox_09_Michelson_DE->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_DE->setMaximumSize(QSize(140, 16777215));
        gridLayout_134 = new QGridLayout(groupBox_09_Michelson_DE);
        gridLayout_134->setObjectName(QString::fromUtf8("gridLayout_134"));
        gridLayout_134->setHorizontalSpacing(1);
        gridLayout_134->setVerticalSpacing(0);
        gridLayout_134->setContentsMargins(0, 0, 0, 2);
        doubleSpinBox_09_Michelson_Detector_distance = new QDoubleSpinBox(groupBox_09_Michelson_DE);
        doubleSpinBox_09_Michelson_Detector_distance->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Detector_distance"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Detector_distance->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Detector_distance->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Detector_distance->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Detector_distance->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Detector_distance->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Detector_distance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Detector_distance->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_09_Michelson_Detector_distance->setDecimals(3);
        doubleSpinBox_09_Michelson_Detector_distance->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_Michelson_Detector_distance->setSingleStep(0.010000000000000);
        doubleSpinBox_09_Michelson_Detector_distance->setValue(2.500000000000000);

        gridLayout_134->addWidget(doubleSpinBox_09_Michelson_Detector_distance, 0, 0, 1, 1);

        verticalLayout_09_Michelson_DE = new QVBoxLayout();
        verticalLayout_09_Michelson_DE->setSpacing(1);
        verticalLayout_09_Michelson_DE->setObjectName(QString::fromUtf8("verticalLayout_09_Michelson_DE"));
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO = new QCheckBox(groupBox_09_Michelson_DE);
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atDE_SP_M1_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atDE_SP_M1_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setChecked(true);

        verticalLayout_09_Michelson_DE->addWidget(checkBox_09_Michelson_Beam_atDE_SP_M1_SO);

        checkBox_09_Michelson_Beam_atDE_M2_SP_SO = new QCheckBox(groupBox_09_Michelson_DE);
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atDE_M2_SP_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atDE_M2_SP_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setChecked(true);

        verticalLayout_09_Michelson_DE->addWidget(checkBox_09_Michelson_Beam_atDE_M2_SP_SO);


        gridLayout_134->addLayout(verticalLayout_09_Michelson_DE, 0, 1, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_DE, 2, 0, 1, 1);

        groupBox_09_MichelsonScene_um = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_MichelsonScene_um->setObjectName(QString::fromUtf8("groupBox_09_MichelsonScene_um"));
        groupBox_09_MichelsonScene_um->setMinimumSize(QSize(140, 0));
        groupBox_09_MichelsonScene_um->setMaximumSize(QSize(140, 16777215));
        gridLayout_137 = new QGridLayout(groupBox_09_MichelsonScene_um);
        gridLayout_137->setObjectName(QString::fromUtf8("gridLayout_137"));
        gridLayout_137->setHorizontalSpacing(1);
        gridLayout_137->setVerticalSpacing(0);
        gridLayout_137->setContentsMargins(0, 0, 0, 2);
        label_09_Michelson_SceneSize_Y = new QLabel(groupBox_09_MichelsonScene_um);
        label_09_Michelson_SceneSize_Y->setObjectName(QString::fromUtf8("label_09_Michelson_SceneSize_Y"));
        sizePolicy14.setHeightForWidth(label_09_Michelson_SceneSize_Y->sizePolicy().hasHeightForWidth());
        label_09_Michelson_SceneSize_Y->setSizePolicy(sizePolicy14);
        label_09_Michelson_SceneSize_Y->setMinimumSize(QSize(0, 0));
        label_09_Michelson_SceneSize_Y->setMaximumSize(QSize(16777215, 16777215));
        label_09_Michelson_SceneSize_Y->setAlignment(Qt::AlignCenter);

        gridLayout_137->addWidget(label_09_Michelson_SceneSize_Y, 1, 0, 1, 1);

        label_09_Michelson_SceneSize_X = new QLabel(groupBox_09_MichelsonScene_um);
        label_09_Michelson_SceneSize_X->setObjectName(QString::fromUtf8("label_09_Michelson_SceneSize_X"));
        sizePolicy14.setHeightForWidth(label_09_Michelson_SceneSize_X->sizePolicy().hasHeightForWidth());
        label_09_Michelson_SceneSize_X->setSizePolicy(sizePolicy14);
        label_09_Michelson_SceneSize_X->setMinimumSize(QSize(0, 0));
        label_09_Michelson_SceneSize_X->setMaximumSize(QSize(16777215, 16777215));
        label_09_Michelson_SceneSize_X->setAlignment(Qt::AlignCenter);

        gridLayout_137->addWidget(label_09_Michelson_SceneSize_X, 0, 0, 1, 1);

        label_09_Michelson_SceneSize_Z = new QLabel(groupBox_09_MichelsonScene_um);
        label_09_Michelson_SceneSize_Z->setObjectName(QString::fromUtf8("label_09_Michelson_SceneSize_Z"));
        sizePolicy14.setHeightForWidth(label_09_Michelson_SceneSize_Z->sizePolicy().hasHeightForWidth());
        label_09_Michelson_SceneSize_Z->setSizePolicy(sizePolicy14);
        label_09_Michelson_SceneSize_Z->setMinimumSize(QSize(0, 0));
        label_09_Michelson_SceneSize_Z->setMaximumSize(QSize(16777215, 16777215));
        label_09_Michelson_SceneSize_Z->setAlignment(Qt::AlignCenter);

        gridLayout_137->addWidget(label_09_Michelson_SceneSize_Z, 2, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_MichelsonScene_um, 3, 0, 1, 1);

        groupBox_09_Michelson_M2 = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_M2->setObjectName(QString::fromUtf8("groupBox_09_Michelson_M2"));
        groupBox_09_Michelson_M2->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_M2->setMaximumSize(QSize(140, 16777215));
        gridLayout_140 = new QGridLayout(groupBox_09_Michelson_M2);
        gridLayout_140->setObjectName(QString::fromUtf8("gridLayout_140"));
        gridLayout_140->setHorizontalSpacing(1);
        gridLayout_140->setVerticalSpacing(0);
        gridLayout_140->setContentsMargins(0, 0, 0, 2);
        verticalLayout_09_Michelson_M2 = new QVBoxLayout();
        verticalLayout_09_Michelson_M2->setSpacing(1);
        verticalLayout_09_Michelson_M2->setObjectName(QString::fromUtf8("verticalLayout_09_Michelson_M2"));
        checkBox_09_Michelson_Beam_atM2_SP_SO = new QCheckBox(groupBox_09_Michelson_M2);
        checkBox_09_Michelson_Beam_atM2_SP_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atM2_SP_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atM2_SP_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atM2_SP_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atM2_SP_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atM2_SP_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atM2_SP_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atM2_SP_SO->setChecked(true);

        verticalLayout_09_Michelson_M2->addWidget(checkBox_09_Michelson_Beam_atM2_SP_SO);

        checkBox_09_Michelson_Beam_atM2_M2_SP_SO = new QCheckBox(groupBox_09_Michelson_M2);
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atM2_M2_SP_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atM2_M2_SP_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setChecked(true);

        verticalLayout_09_Michelson_M2->addWidget(checkBox_09_Michelson_Beam_atM2_M2_SP_SO);


        gridLayout_140->addLayout(verticalLayout_09_Michelson_M2, 0, 1, 3, 1);

        doubleSpinBox_09_Michelson_Mirror2_distance = new QDoubleSpinBox(groupBox_09_Michelson_M2);
        doubleSpinBox_09_Michelson_Mirror2_distance->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Mirror2_distance"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Mirror2_distance->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Mirror2_distance->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Mirror2_distance->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Mirror2_distance->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Mirror2_distance->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Mirror2_distance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Mirror2_distance->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_09_Michelson_Mirror2_distance->setDecimals(3);
        doubleSpinBox_09_Michelson_Mirror2_distance->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_Michelson_Mirror2_distance->setSingleStep(0.010000000000000);
        doubleSpinBox_09_Michelson_Mirror2_distance->setValue(4.320000000000000);

        gridLayout_140->addWidget(doubleSpinBox_09_Michelson_Mirror2_distance, 0, 0, 1, 1);

        doubleSpinBox_09_Michelson_Mirror2_angle_y = new QDoubleSpinBox(groupBox_09_Michelson_M2);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Mirror2_angle_y"));
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setEnabled(false);
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Mirror2_angle_y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setDecimals(3);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setMinimum(-45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setMaximum(45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setSingleStep(0.250000000000000);
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setValue(0.000000000000000);

        gridLayout_140->addWidget(doubleSpinBox_09_Michelson_Mirror2_angle_y, 2, 0, 1, 1);

        doubleSpinBox_09_Michelson_Mirror2_angle_x = new QDoubleSpinBox(groupBox_09_Michelson_M2);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Mirror2_angle_x"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Mirror2_angle_x->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setDecimals(3);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setMinimum(-45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setMaximum(45.000000000000000);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setSingleStep(0.250000000000000);
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setValue(0.000000000000000);

        gridLayout_140->addWidget(doubleSpinBox_09_Michelson_Mirror2_angle_x, 1, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_M2, 2, 2, 1, 1);

        groupBox_09_Michelson_SO = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_Michelson_SO->setObjectName(QString::fromUtf8("groupBox_09_Michelson_SO"));
        groupBox_09_Michelson_SO->setMinimumSize(QSize(140, 0));
        groupBox_09_Michelson_SO->setMaximumSize(QSize(140, 16777215));
        gridLayout_133 = new QGridLayout(groupBox_09_Michelson_SO);
        gridLayout_133->setObjectName(QString::fromUtf8("gridLayout_133"));
        gridLayout_133->setHorizontalSpacing(1);
        gridLayout_133->setVerticalSpacing(0);
        gridLayout_133->setContentsMargins(0, 0, 0, 2);
        verticalLayout_09_Michelson_SO = new QVBoxLayout();
        verticalLayout_09_Michelson_SO->setSpacing(1);
        verticalLayout_09_Michelson_SO->setObjectName(QString::fromUtf8("verticalLayout_09_Michelson_SO"));
        checkBox_09_Michelson_Beam_atSO_SO = new QCheckBox(groupBox_09_Michelson_SO);
        checkBox_09_Michelson_Beam_atSO_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atSO_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atSO_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atSO_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atSO_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atSO_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atSO_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atSO_SO->setChecked(true);

        verticalLayout_09_Michelson_SO->addWidget(checkBox_09_Michelson_Beam_atSO_SO);

        checkBox_09_Michelson_Beam_atSO_M1_SO = new QCheckBox(groupBox_09_Michelson_SO);
        checkBox_09_Michelson_Beam_atSO_M1_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atSO_M1_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atSO_M1_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atSO_M1_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atSO_M1_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atSO_M1_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atSO_M1_SO->setStyleSheet(QString::fromUtf8("font-size: 10px\n"
""));
        checkBox_09_Michelson_Beam_atSO_M1_SO->setChecked(true);

        verticalLayout_09_Michelson_SO->addWidget(checkBox_09_Michelson_Beam_atSO_M1_SO);

        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO = new QCheckBox(groupBox_09_Michelson_SO);
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setObjectName(QString::fromUtf8("checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO"));
        sizePolicy.setHeightForWidth(checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->sizePolicy().hasHeightForWidth());
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setSizePolicy(sizePolicy);
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setMinimumSize(QSize(0, 15));
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setMaximumSize(QSize(16777215, 15));
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setChecked(true);

        verticalLayout_09_Michelson_SO->addWidget(checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO);


        gridLayout_133->addLayout(verticalLayout_09_Michelson_SO, 0, 1, 2, 1);

        doubleSpinBox_09_Michelson_Wavelength = new QDoubleSpinBox(groupBox_09_Michelson_SO);
        doubleSpinBox_09_Michelson_Wavelength->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Wavelength"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Wavelength->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Wavelength->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Wavelength->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Wavelength->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Wavelength->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Wavelength->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Wavelength->setDecimals(3);
        doubleSpinBox_09_Michelson_Wavelength->setMinimum(0.380000000000000);
        doubleSpinBox_09_Michelson_Wavelength->setMaximum(0.750000000000000);
        doubleSpinBox_09_Michelson_Wavelength->setSingleStep(0.001000000000000);
        doubleSpinBox_09_Michelson_Wavelength->setValue(0.633000000000000);

        gridLayout_133->addWidget(doubleSpinBox_09_Michelson_Wavelength, 1, 0, 1, 1);

        doubleSpinBox_09_Michelson_Source_distance = new QDoubleSpinBox(groupBox_09_Michelson_SO);
        doubleSpinBox_09_Michelson_Source_distance->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Source_distance"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Source_distance->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Source_distance->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Source_distance->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Source_distance->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Source_distance->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Source_distance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Source_distance->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_09_Michelson_Source_distance->setDecimals(3);
        doubleSpinBox_09_Michelson_Source_distance->setMaximum(999999999.000000000000000);
        doubleSpinBox_09_Michelson_Source_distance->setSingleStep(0.050000000000000);
        doubleSpinBox_09_Michelson_Source_distance->setValue(4.000000000000000);

        gridLayout_133->addWidget(doubleSpinBox_09_Michelson_Source_distance, 0, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_Michelson_SO, 3, 1, 1, 1);

        groupBox_09_MichelsonScale = new QGroupBox(page_09_InterferometerMichelson);
        groupBox_09_MichelsonScale->setObjectName(QString::fromUtf8("groupBox_09_MichelsonScale"));
        groupBox_09_MichelsonScale->setMinimumSize(QSize(140, 0));
        groupBox_09_MichelsonScale->setMaximumSize(QSize(140, 16777215));
        gridLayout_138 = new QGridLayout(groupBox_09_MichelsonScale);
        gridLayout_138->setObjectName(QString::fromUtf8("gridLayout_138"));
        gridLayout_138->setHorizontalSpacing(1);
        gridLayout_138->setVerticalSpacing(0);
        gridLayout_138->setContentsMargins(0, 0, 0, 2);
        doubleSpinBox_09_Michelson_Scale_um = new QDoubleSpinBox(groupBox_09_MichelsonScale);
        doubleSpinBox_09_Michelson_Scale_um->setObjectName(QString::fromUtf8("doubleSpinBox_09_Michelson_Scale_um"));
        sizePolicy13.setHeightForWidth(doubleSpinBox_09_Michelson_Scale_um->sizePolicy().hasHeightForWidth());
        doubleSpinBox_09_Michelson_Scale_um->setSizePolicy(sizePolicy13);
        doubleSpinBox_09_Michelson_Scale_um->setMinimumSize(QSize(0, 0));
        doubleSpinBox_09_Michelson_Scale_um->setMaximumSize(QSize(16777215, 16777215));
        doubleSpinBox_09_Michelson_Scale_um->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        doubleSpinBox_09_Michelson_Scale_um->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_09_Michelson_Scale_um->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_09_Michelson_Scale_um->setDecimals(3);
        doubleSpinBox_09_Michelson_Scale_um->setMinimum(0.001000000000000);
        doubleSpinBox_09_Michelson_Scale_um->setMaximum(999999.000000000000000);
        doubleSpinBox_09_Michelson_Scale_um->setSingleStep(0.010000000000000);
        doubleSpinBox_09_Michelson_Scale_um->setValue(1.000000000000000);

        gridLayout_138->addWidget(doubleSpinBox_09_Michelson_Scale_um, 1, 0, 1, 1);

        spinBox_09_Michelson_Scale_px = new QSpinBox(groupBox_09_MichelsonScale);
        spinBox_09_Michelson_Scale_px->setObjectName(QString::fromUtf8("spinBox_09_Michelson_Scale_px"));
        sizePolicy13.setHeightForWidth(spinBox_09_Michelson_Scale_px->sizePolicy().hasHeightForWidth());
        spinBox_09_Michelson_Scale_px->setSizePolicy(sizePolicy13);
        spinBox_09_Michelson_Scale_px->setMinimumSize(QSize(0, 0));
        spinBox_09_Michelson_Scale_px->setMaximumSize(QSize(16777215, 16777215));
        spinBox_09_Michelson_Scale_px->setStyleSheet(QString::fromUtf8("font-size: 10px"));
        spinBox_09_Michelson_Scale_px->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_09_Michelson_Scale_px->setProperty("showGroupSeparator", QVariant(true));
        spinBox_09_Michelson_Scale_px->setMinimum(1);
        spinBox_09_Michelson_Scale_px->setMaximum(999999);
        spinBox_09_Michelson_Scale_px->setValue(50);

        gridLayout_138->addWidget(spinBox_09_Michelson_Scale_px, 0, 0, 1, 1);


        gridLayout_131->addWidget(groupBox_09_MichelsonScale, 1, 2, 1, 1);

        horizontalSpacer_09_Michelson = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_131->addItem(horizontalSpacer_09_Michelson, 2, 3, 1, 1);

        comboBox_09_Michelson_Show_IorE = new QComboBox(page_09_InterferometerMichelson);
        comboBox_09_Michelson_Show_IorE->addItem(QString());
        comboBox_09_Michelson_Show_IorE->addItem(QString());
        comboBox_09_Michelson_Show_IorE->setObjectName(QString::fromUtf8("comboBox_09_Michelson_Show_IorE"));

        gridLayout_131->addWidget(comboBox_09_Michelson_Show_IorE, 0, 0, 1, 3);

        stackedWidget_Settings_09_Other->addWidget(page_09_InterferometerMichelson);
        page_09_RadiometricStereo = new QWidget();
        page_09_RadiometricStereo->setObjectName(QString::fromUtf8("page_09_RadiometricStereo"));
        gridLayout_115 = new QGridLayout(page_09_RadiometricStereo);
        gridLayout_115->setObjectName(QString::fromUtf8("gridLayout_115"));
        doubleSpinBox_09_RadiometricStereo_X1 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_X1->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_X1"));
        doubleSpinBox_09_RadiometricStereo_X1->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_X1->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_X1, 1, 1, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Y1 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Y1->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Y1"));
        doubleSpinBox_09_RadiometricStereo_Y1->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Y1->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Y1, 1, 2, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Z3 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Z3->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Z3"));
        doubleSpinBox_09_RadiometricStereo_Z3->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Z3->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Z3, 3, 3, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Y4 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Y4->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Y4"));
        doubleSpinBox_09_RadiometricStereo_Y4->setEnabled(false);
        doubleSpinBox_09_RadiometricStereo_Y4->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Y4->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Y4, 4, 2, 1, 1);

        line_09_RadiometricStereo = new QFrame(page_09_RadiometricStereo);
        line_09_RadiometricStereo->setObjectName(QString::fromUtf8("line_09_RadiometricStereo"));
        line_09_RadiometricStereo->setFrameShape(QFrame::HLine);
        line_09_RadiometricStereo->setFrameShadow(QFrame::Sunken);

        gridLayout_115->addWidget(line_09_RadiometricStereo, 5, 0, 1, 5);

        label_09_RadiometricStereo_S4 = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_S4->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_S4"));
        label_09_RadiometricStereo_S4->setEnabled(false);
        label_09_RadiometricStereo_S4->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_S4->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_S4, 4, 0, 1, 1);

        label_09_RadiometricStereo_X = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_X->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_X"));
        label_09_RadiometricStereo_X->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_X->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_X, 0, 1, 1, 1);

        label_09_RadiometricStereo_Y = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_Y->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_Y"));
        label_09_RadiometricStereo_Y->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_Y->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_Y, 0, 2, 1, 1);

        label_09_RadiometricStereo_S3 = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_S3->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_S3"));
        label_09_RadiometricStereo_S3->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_S3->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_S3, 3, 0, 1, 1);

        label_09_RadiometricStereo_S = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_S->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_S"));

        gridLayout_115->addWidget(label_09_RadiometricStereo_S, 0, 0, 1, 1);

        label_09_RadiometricStereo_S1 = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_S1->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_S1"));
        label_09_RadiometricStereo_S1->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_S1->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_S1, 1, 0, 1, 1);

        doubleSpinBox_09_RadiometricStereo_X2 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_X2->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_X2"));
        doubleSpinBox_09_RadiometricStereo_X2->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_X2->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_X2, 2, 1, 1, 1);

        label_09_RadiometricStereo_S2 = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_S2->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_S2"));
        label_09_RadiometricStereo_S2->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_S2->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_S2, 2, 0, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Z2 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Z2->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Z2"));
        doubleSpinBox_09_RadiometricStereo_Z2->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Z2->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Z2, 2, 3, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Y3 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Y3->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Y3"));
        doubleSpinBox_09_RadiometricStereo_Y3->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Y3->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Y3, 3, 2, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Z1 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Z1->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Z1"));
        doubleSpinBox_09_RadiometricStereo_Z1->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Z1->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Z1, 1, 3, 1, 1);

        horizontalSpacer_09_RadiometricStereo = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_115->addItem(horizontalSpacer_09_RadiometricStereo, 1, 4, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Y2 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Y2->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Y2"));
        doubleSpinBox_09_RadiometricStereo_Y2->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Y2->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Y2, 2, 2, 1, 1);

        doubleSpinBox_09_RadiometricStereo_X3 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_X3->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_X3"));
        doubleSpinBox_09_RadiometricStereo_X3->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_X3->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_X3, 3, 1, 1, 1);

        doubleSpinBox_09_RadiometricStereo_Z4 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_Z4->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_Z4"));
        doubleSpinBox_09_RadiometricStereo_Z4->setEnabled(false);
        doubleSpinBox_09_RadiometricStereo_Z4->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_Z4->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_Z4, 4, 3, 1, 1);

        label_09_RadiometricStereo_Z = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_Z->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_Z"));
        label_09_RadiometricStereo_Z->setMinimumSize(QSize(75, 0));
        label_09_RadiometricStereo_Z->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(label_09_RadiometricStereo_Z, 0, 3, 1, 1);

        doubleSpinBox_09_RadiometricStereo_X4 = new QDoubleSpinBox(page_09_RadiometricStereo);
        doubleSpinBox_09_RadiometricStereo_X4->setObjectName(QString::fromUtf8("doubleSpinBox_09_RadiometricStereo_X4"));
        doubleSpinBox_09_RadiometricStereo_X4->setEnabled(false);
        doubleSpinBox_09_RadiometricStereo_X4->setMinimumSize(QSize(75, 0));
        doubleSpinBox_09_RadiometricStereo_X4->setMaximumSize(QSize(75, 16777215));

        gridLayout_115->addWidget(doubleSpinBox_09_RadiometricStereo_X4, 4, 1, 1, 1);

        verticalSpacer_09_RadiometricStereo = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_115->addItem(verticalSpacer_09_RadiometricStereo, 7, 0, 1, 1);

        label_09_RadiometricStereo_OutMode = new QLabel(page_09_RadiometricStereo);
        label_09_RadiometricStereo_OutMode->setObjectName(QString::fromUtf8("label_09_RadiometricStereo_OutMode"));

        gridLayout_115->addWidget(label_09_RadiometricStereo_OutMode, 6, 0, 1, 1);

        comboBox_09_RadiometricStereo_OutMode = new QComboBox(page_09_RadiometricStereo);
        comboBox_09_RadiometricStereo_OutMode->setObjectName(QString::fromUtf8("comboBox_09_RadiometricStereo_OutMode"));

        gridLayout_115->addWidget(comboBox_09_RadiometricStereo_OutMode, 6, 1, 1, 3);

        stackedWidget_Settings_09_Other->addWidget(page_09_RadiometricStereo);

        gridLayout_26->addWidget(stackedWidget_Settings_09_Other, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_09_Other);
        page_Settings_10_Dimension = new QWidget();
        page_Settings_10_Dimension->setObjectName(QString::fromUtf8("page_Settings_10_Dimension"));
        gridLayout_50 = new QGridLayout(page_Settings_10_Dimension);
        gridLayout_50->setSpacing(0);
        gridLayout_50->setObjectName(QString::fromUtf8("gridLayout_50"));
        gridLayout_50->setContentsMargins(0, 0, 0, 0);
        stackedWidget_Settings_10_Dimension = new QStackedWidget(page_Settings_10_Dimension);
        stackedWidget_Settings_10_Dimension->setObjectName(QString::fromUtf8("stackedWidget_Settings_10_Dimension"));
        page_10_Dimension_Pick = new QWidget();
        page_10_Dimension_Pick->setObjectName(QString::fromUtf8("page_10_Dimension_Pick"));
        gridLayout_57 = new QGridLayout(page_10_Dimension_Pick);
        gridLayout_57->setObjectName(QString::fromUtf8("gridLayout_57"));
        line_10_Pick = new QFrame(page_10_Dimension_Pick);
        line_10_Pick->setObjectName(QString::fromUtf8("line_10_Pick"));
        line_10_Pick->setFrameShape(QFrame::VLine);
        line_10_Pick->setFrameShadow(QFrame::Sunken);

        gridLayout_57->addWidget(line_10_Pick, 0, 0, 2, 1);

        verticalSpacer_10_Pick = new QSpacerItem(20, 151, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_57->addItem(verticalSpacer_10_Pick, 1, 1, 1, 1);

        gridLayout_10_Pick = new QGridLayout();
        gridLayout_10_Pick->setSpacing(3);
        gridLayout_10_Pick->setObjectName(QString::fromUtf8("gridLayout_10_Pick"));
        spinBox_10_Pick_Z = new QSpinBox(page_10_Dimension_Pick);
        spinBox_10_Pick_Z->setObjectName(QString::fromUtf8("spinBox_10_Pick_Z"));
        spinBox_10_Pick_Z->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_Z->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_Z->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_Z->setMaximum(999999999);

        gridLayout_10_Pick->addWidget(spinBox_10_Pick_Z, 1, 3, 1, 1);

        checkBox_10_Pick_Z = new QCheckBox(page_10_Dimension_Pick);
        checkBox_10_Pick_Z->setObjectName(QString::fromUtf8("checkBox_10_Pick_Z"));

        gridLayout_10_Pick->addWidget(checkBox_10_Pick_Z, 0, 3, 1, 1);

        checkBox_10_Pick_P = new QCheckBox(page_10_Dimension_Pick);
        checkBox_10_Pick_P->setObjectName(QString::fromUtf8("checkBox_10_Pick_P"));

        gridLayout_10_Pick->addWidget(checkBox_10_Pick_P, 0, 6, 1, 1);

        spinBox_10_Pick_T = new QSpinBox(page_10_Dimension_Pick);
        spinBox_10_Pick_T->setObjectName(QString::fromUtf8("spinBox_10_Pick_T"));
        spinBox_10_Pick_T->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_T->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_T->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_T->setMaximum(999999999);

        gridLayout_10_Pick->addWidget(spinBox_10_Pick_T, 1, 4, 1, 1);

        checkBox_10_Pick_X = new QCheckBox(page_10_Dimension_Pick);
        checkBox_10_Pick_X->setObjectName(QString::fromUtf8("checkBox_10_Pick_X"));

        gridLayout_10_Pick->addWidget(checkBox_10_Pick_X, 0, 1, 1, 1);

        spinBox_10_Pick_P = new QSpinBox(page_10_Dimension_Pick);
        spinBox_10_Pick_P->setObjectName(QString::fromUtf8("spinBox_10_Pick_P"));
        spinBox_10_Pick_P->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_P->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_P->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_P->setMaximum(999999999);

        gridLayout_10_Pick->addWidget(spinBox_10_Pick_P, 1, 6, 1, 1);

        checkBox_10_Pick_Y = new QCheckBox(page_10_Dimension_Pick);
        checkBox_10_Pick_Y->setObjectName(QString::fromUtf8("checkBox_10_Pick_Y"));

        gridLayout_10_Pick->addWidget(checkBox_10_Pick_Y, 0, 2, 1, 1);

        label_10_Pick_Pos = new QLabel(page_10_Dimension_Pick);
        label_10_Pick_Pos->setObjectName(QString::fromUtf8("label_10_Pick_Pos"));
        label_10_Pick_Pos->setMinimumSize(QSize(75, 0));

        gridLayout_10_Pick->addWidget(label_10_Pick_Pos, 1, 0, 1, 1);

        spinBox_10_Pick_Y = new QSpinBox(page_10_Dimension_Pick);
        spinBox_10_Pick_Y->setObjectName(QString::fromUtf8("spinBox_10_Pick_Y"));
        spinBox_10_Pick_Y->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_Y->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_Y->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_Y->setMaximum(999999999);

        gridLayout_10_Pick->addWidget(spinBox_10_Pick_Y, 1, 2, 1, 1);

        spinBox_10_Pick_X = new QSpinBox(page_10_Dimension_Pick);
        spinBox_10_Pick_X->setObjectName(QString::fromUtf8("spinBox_10_Pick_X"));
        spinBox_10_Pick_X->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_X->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_X->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_X->setMaximum(999999999);

        gridLayout_10_Pick->addWidget(spinBox_10_Pick_X, 1, 1, 1, 1);

        checkBox_10_Pick_T = new QCheckBox(page_10_Dimension_Pick);
        checkBox_10_Pick_T->setObjectName(QString::fromUtf8("checkBox_10_Pick_T"));

        gridLayout_10_Pick->addWidget(checkBox_10_Pick_T, 0, 4, 1, 1);

        spinBox_10_Pick_S = new QSpinBox(page_10_Dimension_Pick);
        spinBox_10_Pick_S->setObjectName(QString::fromUtf8("spinBox_10_Pick_S"));
        spinBox_10_Pick_S->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_S->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_S->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_S->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_S->setMaximum(999999999);

        gridLayout_10_Pick->addWidget(spinBox_10_Pick_S, 1, 5, 1, 1);

        checkBox_10_Pick_S = new QCheckBox(page_10_Dimension_Pick);
        checkBox_10_Pick_S->setObjectName(QString::fromUtf8("checkBox_10_Pick_S"));

        gridLayout_10_Pick->addWidget(checkBox_10_Pick_S, 0, 5, 1, 1);

        label_10_Pick_Dim = new QLabel(page_10_Dimension_Pick);
        label_10_Pick_Dim->setObjectName(QString::fromUtf8("label_10_Pick_Dim"));
        label_10_Pick_Dim->setMinimumSize(QSize(75, 0));

        gridLayout_10_Pick->addWidget(label_10_Pick_Dim, 0, 0, 1, 1);


        gridLayout_57->addLayout(gridLayout_10_Pick, 0, 1, 1, 1);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Pick);
        page_10_Dimension_Crop = new QWidget();
        page_10_Dimension_Crop->setObjectName(QString::fromUtf8("page_10_Dimension_Crop"));
        gridLayout_51 = new QGridLayout(page_10_Dimension_Crop);
        gridLayout_51->setObjectName(QString::fromUtf8("gridLayout_51"));
        gridLayout_10_Crop = new QGridLayout();
        gridLayout_10_Crop->setSpacing(3);
        gridLayout_10_Crop->setObjectName(QString::fromUtf8("gridLayout_10_Crop"));
        checkBox_10_Crop_Z = new QCheckBox(page_10_Dimension_Crop);
        checkBox_10_Crop_Z->setObjectName(QString::fromUtf8("checkBox_10_Crop_Z"));

        gridLayout_10_Crop->addWidget(checkBox_10_Crop_Z, 0, 3, 1, 1);

        checkBox_10_Crop_X = new QCheckBox(page_10_Dimension_Crop);
        checkBox_10_Crop_X->setObjectName(QString::fromUtf8("checkBox_10_Crop_X"));

        gridLayout_10_Crop->addWidget(checkBox_10_Crop_X, 0, 1, 1, 1);

        label_10_Crop_Min = new QLabel(page_10_Dimension_Crop);
        label_10_Crop_Min->setObjectName(QString::fromUtf8("label_10_Crop_Min"));
        label_10_Crop_Min->setMinimumSize(QSize(75, 0));

        gridLayout_10_Crop->addWidget(label_10_Crop_Min, 1, 0, 1, 1);

        checkBox_10_Crop_T = new QCheckBox(page_10_Dimension_Crop);
        checkBox_10_Crop_T->setObjectName(QString::fromUtf8("checkBox_10_Crop_T"));

        gridLayout_10_Crop->addWidget(checkBox_10_Crop_T, 0, 4, 1, 1);

        spinBox_10_Crop_Min_Y = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Min_Y->setObjectName(QString::fromUtf8("spinBox_10_Crop_Min_Y"));
        spinBox_10_Crop_Min_Y->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Min_Y->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Min_Y->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Min_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Min_Y->setMaximum(999999999);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Min_Y, 1, 2, 1, 1);

        spinBox_10_Crop_Min_X = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Min_X->setObjectName(QString::fromUtf8("spinBox_10_Crop_Min_X"));
        spinBox_10_Crop_Min_X->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Min_X->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Min_X->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Min_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Min_X->setMaximum(999999999);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Min_X, 1, 1, 1, 1);

        label_10_Crop_Dim = new QLabel(page_10_Dimension_Crop);
        label_10_Crop_Dim->setObjectName(QString::fromUtf8("label_10_Crop_Dim"));
        label_10_Crop_Dim->setMinimumSize(QSize(75, 0));

        gridLayout_10_Crop->addWidget(label_10_Crop_Dim, 0, 0, 1, 1);

        spinBox_10_Crop_Min_S = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Min_S->setObjectName(QString::fromUtf8("spinBox_10_Crop_Min_S"));
        spinBox_10_Crop_Min_S->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Min_S->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Min_S->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Min_S->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Min_S->setMaximum(999999999);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Min_S, 1, 5, 1, 1);

        checkBox_10_Crop_S = new QCheckBox(page_10_Dimension_Crop);
        checkBox_10_Crop_S->setObjectName(QString::fromUtf8("checkBox_10_Crop_S"));

        gridLayout_10_Crop->addWidget(checkBox_10_Crop_S, 0, 5, 1, 1);

        checkBox_10_Crop_Y = new QCheckBox(page_10_Dimension_Crop);
        checkBox_10_Crop_Y->setObjectName(QString::fromUtf8("checkBox_10_Crop_Y"));

        gridLayout_10_Crop->addWidget(checkBox_10_Crop_Y, 0, 2, 1, 1);

        checkBox_10_Crop_P = new QCheckBox(page_10_Dimension_Crop);
        checkBox_10_Crop_P->setObjectName(QString::fromUtf8("checkBox_10_Crop_P"));

        gridLayout_10_Crop->addWidget(checkBox_10_Crop_P, 0, 6, 1, 1);

        spinBox_10_Crop_Min_Z = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Min_Z->setObjectName(QString::fromUtf8("spinBox_10_Crop_Min_Z"));
        spinBox_10_Crop_Min_Z->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Min_Z->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Min_Z->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Min_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Min_Z->setMaximum(999999999);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Min_Z, 1, 3, 1, 1);

        spinBox_10_Crop_Min_P = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Min_P->setObjectName(QString::fromUtf8("spinBox_10_Crop_Min_P"));
        spinBox_10_Crop_Min_P->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Min_P->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Min_P->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Min_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Min_P->setMaximum(999999999);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Min_P, 1, 6, 1, 1);

        spinBox_10_Crop_Min_T = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Min_T->setObjectName(QString::fromUtf8("spinBox_10_Crop_Min_T"));
        spinBox_10_Crop_Min_T->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Min_T->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Min_T->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Min_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Min_T->setMaximum(999999999);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Min_T, 1, 4, 1, 1);

        spinBox_10_Crop_Max_X = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Max_X->setObjectName(QString::fromUtf8("spinBox_10_Crop_Max_X"));
        spinBox_10_Crop_Max_X->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Max_X->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Max_X->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Max_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Max_X->setMinimum(1);
        spinBox_10_Crop_Max_X->setMaximum(999999999);
        spinBox_10_Crop_Max_X->setValue(1);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Max_X, 2, 1, 1, 1);

        spinBox_10_Crop_Max_Y = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Max_Y->setObjectName(QString::fromUtf8("spinBox_10_Crop_Max_Y"));
        spinBox_10_Crop_Max_Y->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Max_Y->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Max_Y->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Max_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Max_Y->setMinimum(1);
        spinBox_10_Crop_Max_Y->setMaximum(999999999);
        spinBox_10_Crop_Max_Y->setValue(1);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Max_Y, 2, 2, 1, 1);

        spinBox_10_Crop_Max_Z = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Max_Z->setObjectName(QString::fromUtf8("spinBox_10_Crop_Max_Z"));
        spinBox_10_Crop_Max_Z->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Max_Z->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Max_Z->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Max_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Max_Z->setMinimum(1);
        spinBox_10_Crop_Max_Z->setMaximum(999999999);
        spinBox_10_Crop_Max_Z->setValue(1);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Max_Z, 2, 3, 1, 1);

        spinBox_10_Crop_Max_T = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Max_T->setObjectName(QString::fromUtf8("spinBox_10_Crop_Max_T"));
        spinBox_10_Crop_Max_T->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Max_T->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Max_T->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Max_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Max_T->setMinimum(1);
        spinBox_10_Crop_Max_T->setMaximum(999999999);
        spinBox_10_Crop_Max_T->setValue(1);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Max_T, 2, 4, 1, 1);

        spinBox_10_Crop_Max_S = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Max_S->setObjectName(QString::fromUtf8("spinBox_10_Crop_Max_S"));
        spinBox_10_Crop_Max_S->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Max_S->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Max_S->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Max_S->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Max_S->setMinimum(1);
        spinBox_10_Crop_Max_S->setMaximum(999999999);
        spinBox_10_Crop_Max_S->setValue(1);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Max_S, 2, 5, 1, 1);

        spinBox_10_Crop_Max_P = new QSpinBox(page_10_Dimension_Crop);
        spinBox_10_Crop_Max_P->setObjectName(QString::fromUtf8("spinBox_10_Crop_Max_P"));
        spinBox_10_Crop_Max_P->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_10_Crop_Max_P->sizePolicy().hasHeightForWidth());
        spinBox_10_Crop_Max_P->setSizePolicy(sizePolicy1);
        spinBox_10_Crop_Max_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Crop_Max_P->setMinimum(1);
        spinBox_10_Crop_Max_P->setMaximum(999999999);
        spinBox_10_Crop_Max_P->setValue(1);

        gridLayout_10_Crop->addWidget(spinBox_10_Crop_Max_P, 2, 6, 1, 1);

        label_10_Crop_Max = new QLabel(page_10_Dimension_Crop);
        label_10_Crop_Max->setObjectName(QString::fromUtf8("label_10_Crop_Max"));

        gridLayout_10_Crop->addWidget(label_10_Crop_Max, 2, 0, 1, 1);


        gridLayout_51->addLayout(gridLayout_10_Crop, 0, 1, 1, 1);

        verticalSpacer_10_Crop = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_51->addItem(verticalSpacer_10_Crop, 1, 1, 1, 1);

        line_10_Crop = new QFrame(page_10_Dimension_Crop);
        line_10_Crop->setObjectName(QString::fromUtf8("line_10_Crop"));
        line_10_Crop->setFrameShape(QFrame::VLine);
        line_10_Crop->setFrameShadow(QFrame::Sunken);

        gridLayout_51->addWidget(line_10_Crop, 0, 0, 2, 1);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Crop);
        page_10_Dimension_Project = new QWidget();
        page_10_Dimension_Project->setObjectName(QString::fromUtf8("page_10_Dimension_Project"));
        gridLayout_90 = new QGridLayout(page_10_Dimension_Project);
        gridLayout_90->setObjectName(QString::fromUtf8("gridLayout_90"));
        line_10_Project = new QFrame(page_10_Dimension_Project);
        line_10_Project->setObjectName(QString::fromUtf8("line_10_Project"));
        line_10_Project->setFrameShape(QFrame::VLine);
        line_10_Project->setFrameShadow(QFrame::Sunken);

        gridLayout_90->addWidget(line_10_Project, 0, 0, 4, 1);

        label_10_Project_Dimension = new QLabel(page_10_Dimension_Project);
        label_10_Project_Dimension->setObjectName(QString::fromUtf8("label_10_Project_Dimension"));
        label_10_Project_Dimension->setMinimumSize(QSize(75, 0));
        label_10_Project_Dimension->setMaximumSize(QSize(75, 16777215));

        gridLayout_90->addWidget(label_10_Project_Dimension, 0, 1, 1, 1);

        comboBox_10_Project_Dimension = new QComboBox(page_10_Dimension_Project);
        comboBox_10_Project_Dimension->setObjectName(QString::fromUtf8("comboBox_10_Project_Dimension"));
        comboBox_10_Project_Dimension->setMinimumSize(QSize(100, 0));
        comboBox_10_Project_Dimension->setMaximumSize(QSize(100, 16777215));

        gridLayout_90->addWidget(comboBox_10_Project_Dimension, 0, 2, 1, 1);

        horizontalSpacer_10_Project = new QSpacerItem(206, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_90->addItem(horizontalSpacer_10_Project, 0, 3, 1, 1);

        label_10_Project_Stat = new QLabel(page_10_Dimension_Project);
        label_10_Project_Stat->setObjectName(QString::fromUtf8("label_10_Project_Stat"));
        label_10_Project_Stat->setMinimumSize(QSize(75, 0));
        label_10_Project_Stat->setMaximumSize(QSize(75, 16777215));

        gridLayout_90->addWidget(label_10_Project_Stat, 1, 1, 1, 1);

        comboBox_10_Project_Stat = new QComboBox(page_10_Dimension_Project);
        comboBox_10_Project_Stat->setObjectName(QString::fromUtf8("comboBox_10_Project_Stat"));
        comboBox_10_Project_Stat->setMinimumSize(QSize(100, 0));
        comboBox_10_Project_Stat->setMaximumSize(QSize(100, 16777215));

        gridLayout_90->addWidget(comboBox_10_Project_Stat, 1, 2, 1, 1);

        verticalSpacer_10_Project = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_90->addItem(verticalSpacer_10_Project, 3, 2, 1, 1);

        label_10_Project_8bit = new QLabel(page_10_Dimension_Project);
        label_10_Project_8bit->setObjectName(QString::fromUtf8("label_10_Project_8bit"));

        gridLayout_90->addWidget(label_10_Project_8bit, 2, 1, 1, 1);

        checkBox_10_Project_8bit = new QCheckBox(page_10_Dimension_Project);
        checkBox_10_Project_8bit->setObjectName(QString::fromUtf8("checkBox_10_Project_8bit"));

        gridLayout_90->addWidget(checkBox_10_Project_8bit, 2, 2, 1, 1);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Project);
        page_10_Dimension_Deserialise = new QWidget();
        page_10_Dimension_Deserialise->setObjectName(QString::fromUtf8("page_10_Dimension_Deserialise"));
        gridLayout_107 = new QGridLayout(page_10_Dimension_Deserialise);
        gridLayout_107->setSpacing(6);
        gridLayout_107->setObjectName(QString::fromUtf8("gridLayout_107"));
        gridLayout_107->setContentsMargins(9, 9, 9, 9);
        comboBox_10_Deserialise_Dimension_In = new QComboBox(page_10_Dimension_Deserialise);
        comboBox_10_Deserialise_Dimension_In->setObjectName(QString::fromUtf8("comboBox_10_Deserialise_Dimension_In"));
        comboBox_10_Deserialise_Dimension_In->setMinimumSize(QSize(100, 0));
        comboBox_10_Deserialise_Dimension_In->setMaximumSize(QSize(100, 16777215));

        gridLayout_107->addWidget(comboBox_10_Deserialise_Dimension_In, 0, 1, 1, 1);

        verticalSpacer_10_Deserialise = new QSpacerItem(415, 130, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_107->addItem(verticalSpacer_10_Deserialise, 3, 0, 1, 3);

        label_10_Deserialise_Spacing = new QLabel(page_10_Dimension_Deserialise);
        label_10_Deserialise_Spacing->setObjectName(QString::fromUtf8("label_10_Deserialise_Spacing"));
        label_10_Deserialise_Spacing->setMinimumSize(QSize(75, 0));
        label_10_Deserialise_Spacing->setMaximumSize(QSize(75, 16777215));

        gridLayout_107->addWidget(label_10_Deserialise_Spacing, 1, 0, 1, 1);

        label_10_Deserialise_Dimension_In = new QLabel(page_10_Dimension_Deserialise);
        label_10_Deserialise_Dimension_In->setObjectName(QString::fromUtf8("label_10_Deserialise_Dimension_In"));
        label_10_Deserialise_Dimension_In->setMinimumSize(QSize(75, 0));
        label_10_Deserialise_Dimension_In->setMaximumSize(QSize(75, 16777215));

        gridLayout_107->addWidget(label_10_Deserialise_Dimension_In, 0, 0, 1, 1);

        horizontalSpacer_10_Deserialise = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_107->addItem(horizontalSpacer_10_Deserialise, 0, 2, 1, 1);

        label_10_Deserialise_Dimension_Out = new QLabel(page_10_Dimension_Deserialise);
        label_10_Deserialise_Dimension_Out->setObjectName(QString::fromUtf8("label_10_Deserialise_Dimension_Out"));
        label_10_Deserialise_Dimension_Out->setMinimumSize(QSize(75, 0));
        label_10_Deserialise_Dimension_Out->setMaximumSize(QSize(75, 16777215));

        gridLayout_107->addWidget(label_10_Deserialise_Dimension_Out, 2, 0, 1, 1);

        comboBox_10_Deserialise_Dimension_Out = new QComboBox(page_10_Dimension_Deserialise);
        comboBox_10_Deserialise_Dimension_Out->setObjectName(QString::fromUtf8("comboBox_10_Deserialise_Dimension_Out"));
        comboBox_10_Deserialise_Dimension_Out->setMinimumSize(QSize(100, 0));
        comboBox_10_Deserialise_Dimension_Out->setMaximumSize(QSize(100, 16777215));

        gridLayout_107->addWidget(comboBox_10_Deserialise_Dimension_Out, 2, 1, 1, 1);

        spinBox_10_Deserialise_Spacing = new QSpinBox(page_10_Dimension_Deserialise);
        spinBox_10_Deserialise_Spacing->setObjectName(QString::fromUtf8("spinBox_10_Deserialise_Spacing"));
        spinBox_10_Deserialise_Spacing->setMinimumSize(QSize(100, 0));
        spinBox_10_Deserialise_Spacing->setMaximumSize(QSize(100, 16777215));
        spinBox_10_Deserialise_Spacing->setMinimum(1);
        spinBox_10_Deserialise_Spacing->setMaximum(9999);

        gridLayout_107->addWidget(spinBox_10_Deserialise_Spacing, 1, 1, 1, 1);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Deserialise);
        page_10_Dimension_Pages2Color = new QWidget();
        page_10_Dimension_Pages2Color->setObjectName(QString::fromUtf8("page_10_Dimension_Pages2Color"));
        gridLayout_108 = new QGridLayout(page_10_Dimension_Pages2Color);
        gridLayout_108->setObjectName(QString::fromUtf8("gridLayout_108"));
        label_10_Page2Color_R = new QLabel(page_10_Dimension_Pages2Color);
        label_10_Page2Color_R->setObjectName(QString::fromUtf8("label_10_Page2Color_R"));
        label_10_Page2Color_R->setMinimumSize(QSize(75, 0));
        label_10_Page2Color_R->setMaximumSize(QSize(75, 16777215));

        gridLayout_108->addWidget(label_10_Page2Color_R, 0, 0, 1, 1);

        spinBox_10_Page2Color_R = new QSpinBox(page_10_Dimension_Pages2Color);
        spinBox_10_Page2Color_R->setObjectName(QString::fromUtf8("spinBox_10_Page2Color_R"));
        spinBox_10_Page2Color_R->setMinimumSize(QSize(100, 0));
        spinBox_10_Page2Color_R->setMaximumSize(QSize(100, 16777215));
        spinBox_10_Page2Color_R->setMaximum(9999);

        gridLayout_108->addWidget(spinBox_10_Page2Color_R, 0, 1, 1, 1);

        label_10_Page2Color_G = new QLabel(page_10_Dimension_Pages2Color);
        label_10_Page2Color_G->setObjectName(QString::fromUtf8("label_10_Page2Color_G"));
        label_10_Page2Color_G->setMinimumSize(QSize(75, 0));
        label_10_Page2Color_G->setMaximumSize(QSize(75, 16777215));

        gridLayout_108->addWidget(label_10_Page2Color_G, 1, 0, 1, 1);

        spinBox_10_Page2Color_G = new QSpinBox(page_10_Dimension_Pages2Color);
        spinBox_10_Page2Color_G->setObjectName(QString::fromUtf8("spinBox_10_Page2Color_G"));
        spinBox_10_Page2Color_G->setMinimumSize(QSize(100, 0));
        spinBox_10_Page2Color_G->setMaximumSize(QSize(100, 16777215));
        spinBox_10_Page2Color_G->setMaximum(9999);

        gridLayout_108->addWidget(spinBox_10_Page2Color_G, 1, 1, 1, 1);

        label_10_Page2Color_B = new QLabel(page_10_Dimension_Pages2Color);
        label_10_Page2Color_B->setObjectName(QString::fromUtf8("label_10_Page2Color_B"));
        label_10_Page2Color_B->setMinimumSize(QSize(75, 0));
        label_10_Page2Color_B->setMaximumSize(QSize(75, 16777215));

        gridLayout_108->addWidget(label_10_Page2Color_B, 2, 0, 1, 1);

        spinBox_10_Page2Color_B = new QSpinBox(page_10_Dimension_Pages2Color);
        spinBox_10_Page2Color_B->setObjectName(QString::fromUtf8("spinBox_10_Page2Color_B"));
        spinBox_10_Page2Color_B->setMinimumSize(QSize(100, 0));
        spinBox_10_Page2Color_B->setMaximumSize(QSize(100, 16777215));
        spinBox_10_Page2Color_B->setMaximum(9999);

        gridLayout_108->addWidget(spinBox_10_Page2Color_B, 2, 1, 1, 1);

        horizontalSpacer_10_Page2Color = new QSpacerItem(228, 69, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_108->addItem(horizontalSpacer_10_Page2Color, 0, 2, 3, 2);

        verticalSpacer_10_Page2Color = new QSpacerItem(415, 133, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_108->addItem(verticalSpacer_10_Page2Color, 3, 0, 1, 4);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Pages2Color);
        page_10_Dimension_Stitching = new QWidget();
        page_10_Dimension_Stitching->setObjectName(QString::fromUtf8("page_10_Dimension_Stitching"));
        gridLayout_113 = new QGridLayout(page_10_Dimension_Stitching);
        gridLayout_113->setObjectName(QString::fromUtf8("gridLayout_113"));
        horizontalSpacer_10_Stitching = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_113->addItem(horizontalSpacer_10_Stitching, 0, 3, 1, 1);

        label_10_Stitching_Border_R = new QLabel(page_10_Dimension_Stitching);
        label_10_Stitching_Border_R->setObjectName(QString::fromUtf8("label_10_Stitching_Border_R"));
        label_10_Stitching_Border_R->setMinimumSize(QSize(100, 0));
        label_10_Stitching_Border_R->setMaximumSize(QSize(100, 16777215));

        gridLayout_113->addWidget(label_10_Stitching_Border_R, 0, 0, 1, 1);

        verticalSpacer_10_Stitching = new QSpacerItem(20, 137, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_113->addItem(verticalSpacer_10_Stitching, 3, 1, 1, 1);

        doubleSpinBox_10_Stitching_Border_R = new QDoubleSpinBox(page_10_Dimension_Stitching);
        doubleSpinBox_10_Stitching_Border_R->setObjectName(QString::fromUtf8("doubleSpinBox_10_Stitching_Border_R"));
        doubleSpinBox_10_Stitching_Border_R->setMinimumSize(QSize(100, 0));
        doubleSpinBox_10_Stitching_Border_R->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_10_Stitching_Border_R->setMaximum(100.000000000000000);
        doubleSpinBox_10_Stitching_Border_R->setValue(25.000000000000000);

        gridLayout_113->addWidget(doubleSpinBox_10_Stitching_Border_R, 0, 1, 1, 1);

        label_10_Stitching_Mode = new QLabel(page_10_Dimension_Stitching);
        label_10_Stitching_Mode->setObjectName(QString::fromUtf8("label_10_Stitching_Mode"));
        label_10_Stitching_Mode->setMinimumSize(QSize(100, 0));
        label_10_Stitching_Mode->setMaximumSize(QSize(100, 16777215));

        gridLayout_113->addWidget(label_10_Stitching_Mode, 2, 0, 1, 1);

        label_10_Stitching_Border_B = new QLabel(page_10_Dimension_Stitching);
        label_10_Stitching_Border_B->setObjectName(QString::fromUtf8("label_10_Stitching_Border_B"));
        label_10_Stitching_Border_B->setMinimumSize(QSize(100, 0));
        label_10_Stitching_Border_B->setMaximumSize(QSize(100, 16777215));

        gridLayout_113->addWidget(label_10_Stitching_Border_B, 1, 0, 1, 1);

        doubleSpinBox_10_Stitching_Border_B = new QDoubleSpinBox(page_10_Dimension_Stitching);
        doubleSpinBox_10_Stitching_Border_B->setObjectName(QString::fromUtf8("doubleSpinBox_10_Stitching_Border_B"));
        doubleSpinBox_10_Stitching_Border_B->setMinimumSize(QSize(100, 0));
        doubleSpinBox_10_Stitching_Border_B->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_10_Stitching_Border_B->setMaximum(100.000000000000000);
        doubleSpinBox_10_Stitching_Border_B->setValue(25.000000000000000);

        gridLayout_113->addWidget(doubleSpinBox_10_Stitching_Border_B, 0, 2, 1, 1);

        doubleSpinBox_10_Stitching_Overlap_R = new QDoubleSpinBox(page_10_Dimension_Stitching);
        doubleSpinBox_10_Stitching_Overlap_R->setObjectName(QString::fromUtf8("doubleSpinBox_10_Stitching_Overlap_R"));
        doubleSpinBox_10_Stitching_Overlap_R->setMinimumSize(QSize(100, 0));
        doubleSpinBox_10_Stitching_Overlap_R->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_10_Stitching_Overlap_R->setMaximum(100.000000000000000);
        doubleSpinBox_10_Stitching_Overlap_R->setValue(5.000000000000000);

        gridLayout_113->addWidget(doubleSpinBox_10_Stitching_Overlap_R, 1, 1, 1, 1);

        doubleSpinBox_10_Stitching_Overlap_B = new QDoubleSpinBox(page_10_Dimension_Stitching);
        doubleSpinBox_10_Stitching_Overlap_B->setObjectName(QString::fromUtf8("doubleSpinBox_10_Stitching_Overlap_B"));
        doubleSpinBox_10_Stitching_Overlap_B->setMinimumSize(QSize(100, 0));
        doubleSpinBox_10_Stitching_Overlap_B->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_10_Stitching_Overlap_B->setMaximum(100.000000000000000);
        doubleSpinBox_10_Stitching_Overlap_B->setValue(5.000000000000000);

        gridLayout_113->addWidget(doubleSpinBox_10_Stitching_Overlap_B, 1, 2, 1, 1);

        comboBox_10_Stitching_Mode = new QComboBox(page_10_Dimension_Stitching);
        comboBox_10_Stitching_Mode->addItem(QString());
        comboBox_10_Stitching_Mode->addItem(QString());
        comboBox_10_Stitching_Mode->setObjectName(QString::fromUtf8("comboBox_10_Stitching_Mode"));
        comboBox_10_Stitching_Mode->setMinimumSize(QSize(100, 0));
        comboBox_10_Stitching_Mode->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_113->addWidget(comboBox_10_Stitching_Mode, 2, 1, 1, 2);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Stitching);
        page_10_Dimension_Extend = new QWidget();
        page_10_Dimension_Extend->setObjectName(QString::fromUtf8("page_10_Dimension_Extend"));
        gridLayout_63 = new QGridLayout(page_10_Dimension_Extend);
        gridLayout_63->setObjectName(QString::fromUtf8("gridLayout_63"));
        line_2 = new QFrame(page_10_Dimension_Extend);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_63->addWidget(line_2, 0, 0, 2, 1);

        gridLayout_10_Pick_3 = new QGridLayout();
        gridLayout_10_Pick_3->setSpacing(3);
        gridLayout_10_Pick_3->setObjectName(QString::fromUtf8("gridLayout_10_Pick_3"));
        spinBox_10_Pick_Z_3 = new QSpinBox(page_10_Dimension_Extend);
        spinBox_10_Pick_Z_3->setObjectName(QString::fromUtf8("spinBox_10_Pick_Z_3"));
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_Z_3->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_Z_3->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_Z_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_Z_3->setMaximum(999999999);

        gridLayout_10_Pick_3->addWidget(spinBox_10_Pick_Z_3, 1, 3, 1, 1);

        checkBox_10_Pick_Z_3 = new QCheckBox(page_10_Dimension_Extend);
        checkBox_10_Pick_Z_3->setObjectName(QString::fromUtf8("checkBox_10_Pick_Z_3"));

        gridLayout_10_Pick_3->addWidget(checkBox_10_Pick_Z_3, 0, 3, 1, 1);

        checkBox_10_Pick_P_3 = new QCheckBox(page_10_Dimension_Extend);
        checkBox_10_Pick_P_3->setObjectName(QString::fromUtf8("checkBox_10_Pick_P_3"));

        gridLayout_10_Pick_3->addWidget(checkBox_10_Pick_P_3, 0, 6, 1, 1);

        spinBox_10_Pick_T_3 = new QSpinBox(page_10_Dimension_Extend);
        spinBox_10_Pick_T_3->setObjectName(QString::fromUtf8("spinBox_10_Pick_T_3"));
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_T_3->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_T_3->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_T_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_T_3->setMaximum(999999999);

        gridLayout_10_Pick_3->addWidget(spinBox_10_Pick_T_3, 1, 4, 1, 1);

        checkBox_10_Pick_X_3 = new QCheckBox(page_10_Dimension_Extend);
        checkBox_10_Pick_X_3->setObjectName(QString::fromUtf8("checkBox_10_Pick_X_3"));

        gridLayout_10_Pick_3->addWidget(checkBox_10_Pick_X_3, 0, 1, 1, 1);

        spinBox_10_Pick_P_3 = new QSpinBox(page_10_Dimension_Extend);
        spinBox_10_Pick_P_3->setObjectName(QString::fromUtf8("spinBox_10_Pick_P_3"));
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_P_3->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_P_3->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_P_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_P_3->setMaximum(999999999);

        gridLayout_10_Pick_3->addWidget(spinBox_10_Pick_P_3, 1, 6, 1, 1);

        checkBox_10_Pick_Y_3 = new QCheckBox(page_10_Dimension_Extend);
        checkBox_10_Pick_Y_3->setObjectName(QString::fromUtf8("checkBox_10_Pick_Y_3"));

        gridLayout_10_Pick_3->addWidget(checkBox_10_Pick_Y_3, 0, 2, 1, 1);

        label_10_Pick_Pos_3 = new QLabel(page_10_Dimension_Extend);
        label_10_Pick_Pos_3->setObjectName(QString::fromUtf8("label_10_Pick_Pos_3"));
        label_10_Pick_Pos_3->setMinimumSize(QSize(75, 0));

        gridLayout_10_Pick_3->addWidget(label_10_Pick_Pos_3, 1, 0, 1, 1);

        spinBox_10_Pick_Y_3 = new QSpinBox(page_10_Dimension_Extend);
        spinBox_10_Pick_Y_3->setObjectName(QString::fromUtf8("spinBox_10_Pick_Y_3"));
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_Y_3->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_Y_3->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_Y_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_Y_3->setMaximum(999999999);

        gridLayout_10_Pick_3->addWidget(spinBox_10_Pick_Y_3, 1, 2, 1, 1);

        spinBox_10_Pick_X_3 = new QSpinBox(page_10_Dimension_Extend);
        spinBox_10_Pick_X_3->setObjectName(QString::fromUtf8("spinBox_10_Pick_X_3"));
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_X_3->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_X_3->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_X_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_X_3->setMaximum(999999999);

        gridLayout_10_Pick_3->addWidget(spinBox_10_Pick_X_3, 1, 1, 1, 1);

        checkBox_10_Pick_T_3 = new QCheckBox(page_10_Dimension_Extend);
        checkBox_10_Pick_T_3->setObjectName(QString::fromUtf8("checkBox_10_Pick_T_3"));

        gridLayout_10_Pick_3->addWidget(checkBox_10_Pick_T_3, 0, 4, 1, 1);

        spinBox_10_Pick_S_3 = new QSpinBox(page_10_Dimension_Extend);
        spinBox_10_Pick_S_3->setObjectName(QString::fromUtf8("spinBox_10_Pick_S_3"));
        sizePolicy1.setHeightForWidth(spinBox_10_Pick_S_3->sizePolicy().hasHeightForWidth());
        spinBox_10_Pick_S_3->setSizePolicy(sizePolicy1);
        spinBox_10_Pick_S_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10_Pick_S_3->setMaximum(999999999);

        gridLayout_10_Pick_3->addWidget(spinBox_10_Pick_S_3, 1, 5, 1, 1);

        checkBox_10_Pick_S_3 = new QCheckBox(page_10_Dimension_Extend);
        checkBox_10_Pick_S_3->setObjectName(QString::fromUtf8("checkBox_10_Pick_S_3"));

        gridLayout_10_Pick_3->addWidget(checkBox_10_Pick_S_3, 0, 5, 1, 1);

        label_10_Pick_Dim_3 = new QLabel(page_10_Dimension_Extend);
        label_10_Pick_Dim_3->setObjectName(QString::fromUtf8("label_10_Pick_Dim_3"));
        label_10_Pick_Dim_3->setMinimumSize(QSize(75, 0));

        gridLayout_10_Pick_3->addWidget(label_10_Pick_Dim_3, 0, 0, 1, 1);


        gridLayout_63->addLayout(gridLayout_10_Pick_3, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 151, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_63->addItem(verticalSpacer_3, 1, 1, 1, 1);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Extend);
        page_10_Dimension_Flip = new QWidget();
        page_10_Dimension_Flip->setObjectName(QString::fromUtf8("page_10_Dimension_Flip"));
        gridLayout_89 = new QGridLayout(page_10_Dimension_Flip);
        gridLayout_89->setObjectName(QString::fromUtf8("gridLayout_89"));
        line_3 = new QFrame(page_10_Dimension_Flip);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_89->addWidget(line_3, 0, 0, 2, 1);

        label = new QLabel(page_10_Dimension_Flip);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_89->addWidget(label, 0, 1, 1, 1);

        comboBox = new QComboBox(page_10_Dimension_Flip);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_89->addWidget(comboBox, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(page_10_Dimension_Flip);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_89->addWidget(comboBox_2, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(363, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_89->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 170, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_89->addItem(verticalSpacer_4, 1, 2, 1, 1);

        stackedWidget_Settings_10_Dimension->addWidget(page_10_Dimension_Flip);

        gridLayout_50->addWidget(stackedWidget_Settings_10_Dimension, 0, 0, 1, 1);

        stackedWidget_Main_Settings->addWidget(page_Settings_10_Dimension);

        gridLayout_7->addWidget(stackedWidget_Main_Settings, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Settings, 3, 1, 3, 2);

        groupBox_ProcDims = new QGroupBox(centralwidget);
        groupBox_ProcDims->setObjectName(QString::fromUtf8("groupBox_ProcDims"));
        groupBox_ProcDims->setEnabled(false);
        QSizePolicy sizePolicy15(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(groupBox_ProcDims->sizePolicy().hasHeightForWidth());
        groupBox_ProcDims->setSizePolicy(sizePolicy15);
        groupBox_ProcDims->setMinimumSize(QSize(140, 48));
        groupBox_ProcDims->setMaximumSize(QSize(140, 48));
        gridLayout_87 = new QGridLayout(groupBox_ProcDims);
        gridLayout_87->setSpacing(1);
        gridLayout_87->setObjectName(QString::fromUtf8("gridLayout_87"));
        gridLayout_87->setContentsMargins(3, 3, 3, 3);
        checkBox_ProcDims_Z_Proc = new QCheckBox(groupBox_ProcDims);
        checkBox_ProcDims_Z_Proc->setObjectName(QString::fromUtf8("checkBox_ProcDims_Z_Proc"));

        gridLayout_87->addWidget(checkBox_ProcDims_Z_Proc, 1, 2, 1, 1);

        checkBox_ProcDims_T_Proc = new QCheckBox(groupBox_ProcDims);
        checkBox_ProcDims_T_Proc->setObjectName(QString::fromUtf8("checkBox_ProcDims_T_Proc"));

        gridLayout_87->addWidget(checkBox_ProcDims_T_Proc, 1, 3, 1, 1);

        checkBox_ProcDims_Y_Proc = new QCheckBox(groupBox_ProcDims);
        checkBox_ProcDims_Y_Proc->setObjectName(QString::fromUtf8("checkBox_ProcDims_Y_Proc"));
        checkBox_ProcDims_Y_Proc->setChecked(true);

        gridLayout_87->addWidget(checkBox_ProcDims_Y_Proc, 1, 1, 1, 1);

        checkBox_ProcDims_P_Proc = new QCheckBox(groupBox_ProcDims);
        checkBox_ProcDims_P_Proc->setObjectName(QString::fromUtf8("checkBox_ProcDims_P_Proc"));

        gridLayout_87->addWidget(checkBox_ProcDims_P_Proc, 1, 5, 1, 1);

        checkBox_ProcDims_X_Proc = new QCheckBox(groupBox_ProcDims);
        checkBox_ProcDims_X_Proc->setObjectName(QString::fromUtf8("checkBox_ProcDims_X_Proc"));
        checkBox_ProcDims_X_Proc->setChecked(true);

        gridLayout_87->addWidget(checkBox_ProcDims_X_Proc, 1, 0, 1, 1);

        checkBox_ProcDims_S_Proc = new QCheckBox(groupBox_ProcDims);
        checkBox_ProcDims_S_Proc->setObjectName(QString::fromUtf8("checkBox_ProcDims_S_Proc"));

        gridLayout_87->addWidget(checkBox_ProcDims_S_Proc, 1, 4, 1, 1);

        label_ProcDims_X = new QLabel(groupBox_ProcDims);
        label_ProcDims_X->setObjectName(QString::fromUtf8("label_ProcDims_X"));

        gridLayout_87->addWidget(label_ProcDims_X, 0, 0, 1, 1);

        label_ProcDims_Y = new QLabel(groupBox_ProcDims);
        label_ProcDims_Y->setObjectName(QString::fromUtf8("label_ProcDims_Y"));

        gridLayout_87->addWidget(label_ProcDims_Y, 0, 1, 1, 1);

        label_ProcDims_Z = new QLabel(groupBox_ProcDims);
        label_ProcDims_Z->setObjectName(QString::fromUtf8("label_ProcDims_Z"));

        gridLayout_87->addWidget(label_ProcDims_Z, 0, 2, 1, 1);

        label_ProcDims_T = new QLabel(groupBox_ProcDims);
        label_ProcDims_T->setObjectName(QString::fromUtf8("label_ProcDims_T"));

        gridLayout_87->addWidget(label_ProcDims_T, 0, 3, 1, 1);

        label_ProcDims_S = new QLabel(groupBox_ProcDims);
        label_ProcDims_S->setObjectName(QString::fromUtf8("label_ProcDims_S"));

        gridLayout_87->addWidget(label_ProcDims_S, 0, 4, 1, 1);

        label_ProcDims_P = new QLabel(groupBox_ProcDims);
        label_ProcDims_P->setObjectName(QString::fromUtf8("label_ProcDims_P"));

        gridLayout_87->addWidget(label_ProcDims_P, 0, 5, 1, 1);


        gridLayout->addWidget(groupBox_ProcDims, 5, 0, 1, 1);

        groupBox_Source = new QGroupBox(centralwidget);
        groupBox_Source->setObjectName(QString::fromUtf8("groupBox_Source"));
        sizePolicy15.setHeightForWidth(groupBox_Source->sizePolicy().hasHeightForWidth());
        groupBox_Source->setSizePolicy(sizePolicy15);
        groupBox_Source->setMinimumSize(QSize(140, 110));
        groupBox_Source->setMaximumSize(QSize(140, 110));
        gridLayout_2 = new QGridLayout(groupBox_Source);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        label_Source_1 = new QLabel(groupBox_Source);
        label_Source_1->setObjectName(QString::fromUtf8("label_Source_1"));
        label_Source_1->setEnabled(false);

        gridLayout_2->addWidget(label_Source_1, 1, 0, 1, 1);

        label_Source_3 = new QLabel(groupBox_Source);
        label_Source_3->setObjectName(QString::fromUtf8("label_Source_3"));
        label_Source_3->setEnabled(false);

        gridLayout_2->addWidget(label_Source_3, 3, 0, 1, 1);

        spinBox_Source_Pos_3 = new QSpinBox(groupBox_Source);
        spinBox_Source_Pos_3->setObjectName(QString::fromUtf8("spinBox_Source_Pos_3"));
        spinBox_Source_Pos_3->setEnabled(false);
        spinBox_Source_Pos_3->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(spinBox_Source_Pos_3, 3, 1, 1, 1);

        label_Source_2 = new QLabel(groupBox_Source);
        label_Source_2->setObjectName(QString::fromUtf8("label_Source_2"));
        label_Source_2->setEnabled(false);

        gridLayout_2->addWidget(label_Source_2, 2, 0, 1, 1);

        label_Source_Type_2 = new QLabel(groupBox_Source);
        label_Source_Type_2->setObjectName(QString::fromUtf8("label_Source_Type_2"));
        label_Source_Type_2->setEnabled(false);
        QSizePolicy sizePolicy16(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy16.setHorizontalStretch(0);
        sizePolicy16.setVerticalStretch(0);
        sizePolicy16.setHeightForWidth(label_Source_Type_2->sizePolicy().hasHeightForWidth());
        label_Source_Type_2->setSizePolicy(sizePolicy16);

        gridLayout_2->addWidget(label_Source_Type_2, 2, 2, 1, 1);

        spinBox_Source_Pos_2 = new QSpinBox(groupBox_Source);
        spinBox_Source_Pos_2->setObjectName(QString::fromUtf8("spinBox_Source_Pos_2"));
        spinBox_Source_Pos_2->setEnabled(false);
        spinBox_Source_Pos_2->setMaximumSize(QSize(40, 16777215));
        spinBox_Source_Pos_2->setMaximum(10000);

        gridLayout_2->addWidget(spinBox_Source_Pos_2, 2, 1, 1, 1);

        label_Source_Type_1 = new QLabel(groupBox_Source);
        label_Source_Type_1->setObjectName(QString::fromUtf8("label_Source_Type_1"));
        label_Source_Type_1->setEnabled(false);
        sizePolicy16.setHeightForWidth(label_Source_Type_1->sizePolicy().hasHeightForWidth());
        label_Source_Type_1->setSizePolicy(sizePolicy16);

        gridLayout_2->addWidget(label_Source_Type_1, 1, 2, 1, 1);

        spinBox_Source_Pos_1 = new QSpinBox(groupBox_Source);
        spinBox_Source_Pos_1->setObjectName(QString::fromUtf8("spinBox_Source_Pos_1"));
        spinBox_Source_Pos_1->setEnabled(false);
        spinBox_Source_Pos_1->setMaximumSize(QSize(40, 16777215));
        spinBox_Source_Pos_1->setMaximum(10000);
        spinBox_Source_Pos_1->setValue(0);

        gridLayout_2->addWidget(spinBox_Source_Pos_1, 1, 1, 1, 1);

        label_Source_Type_3 = new QLabel(groupBox_Source);
        label_Source_Type_3->setObjectName(QString::fromUtf8("label_Source_Type_3"));
        label_Source_Type_3->setEnabled(false);
        sizePolicy16.setHeightForWidth(label_Source_Type_3->sizePolicy().hasHeightForWidth());
        label_Source_Type_3->setSizePolicy(sizePolicy16);

        gridLayout_2->addWidget(label_Source_Type_3, 3, 2, 1, 1);

        label_Source_4 = new QLabel(groupBox_Source);
        label_Source_4->setObjectName(QString::fromUtf8("label_Source_4"));
        label_Source_4->setEnabled(false);

        gridLayout_2->addWidget(label_Source_4, 4, 0, 1, 1);

        spinBox_Source_Pos_4 = new QSpinBox(groupBox_Source);
        spinBox_Source_Pos_4->setObjectName(QString::fromUtf8("spinBox_Source_Pos_4"));
        spinBox_Source_Pos_4->setEnabled(false);
        spinBox_Source_Pos_4->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(spinBox_Source_Pos_4, 4, 1, 1, 1);

        label_Source_Type_4 = new QLabel(groupBox_Source);
        label_Source_Type_4->setObjectName(QString::fromUtf8("label_Source_Type_4"));
        label_Source_Type_4->setEnabled(false);
        sizePolicy16.setHeightForWidth(label_Source_Type_4->sizePolicy().hasHeightForWidth());
        label_Source_Type_4->setSizePolicy(sizePolicy16);

        gridLayout_2->addWidget(label_Source_Type_4, 4, 2, 1, 1);


        gridLayout->addWidget(groupBox_Source, 4, 0, 1, 1);

        groupBox_Type_Update = new QGroupBox(centralwidget);
        groupBox_Type_Update->setObjectName(QString::fromUtf8("groupBox_Type_Update"));
        sizePolicy15.setHeightForWidth(groupBox_Type_Update->sizePolicy().hasHeightForWidth());
        groupBox_Type_Update->setSizePolicy(sizePolicy15);
        groupBox_Type_Update->setMinimumSize(QSize(140, 90));
        groupBox_Type_Update->setMaximumSize(QSize(140, 90));
        gridLayout_3 = new QGridLayout(groupBox_Type_Update);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        stackedWidget_Type_Main = new QStackedWidget(groupBox_Type_Update);
        stackedWidget_Type_Main->setObjectName(QString::fromUtf8("stackedWidget_Type_Main"));
        stackedWidget_Type_Main->setLineWidth(1);
        page_Type_00_Source = new QWidget();
        page_Type_00_Source->setObjectName(QString::fromUtf8("page_Type_00_Source"));
        gridLayout_4 = new QGridLayout(page_Type_00_Source);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_00_Source = new QComboBox(page_Type_00_Source);
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->addItem(QString());
        comboBox_Type_00_Source->setObjectName(QString::fromUtf8("comboBox_Type_00_Source"));

        gridLayout_4->addWidget(comboBox_Type_00_Source, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_00_Source);
        page_Type_01_Edit = new QWidget();
        page_Type_01_Edit->setObjectName(QString::fromUtf8("page_Type_01_Edit"));
        gridLayout_8 = new QGridLayout(page_Type_01_Edit);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_01_Edit = new QComboBox(page_Type_01_Edit);
        comboBox_Type_01_Edit->addItem(QString());
        comboBox_Type_01_Edit->addItem(QString());
        comboBox_Type_01_Edit->addItem(QString());
        comboBox_Type_01_Edit->addItem(QString());
        comboBox_Type_01_Edit->setObjectName(QString::fromUtf8("comboBox_Type_01_Edit"));
        comboBox_Type_01_Edit->setEnabled(true);

        gridLayout_8->addWidget(comboBox_Type_01_Edit, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_01_Edit);
        page_Type_02_Convert = new QWidget();
        page_Type_02_Convert->setObjectName(QString::fromUtf8("page_Type_02_Convert"));
        gridLayout_9 = new QGridLayout(page_Type_02_Convert);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_02_Convert = new QComboBox(page_Type_02_Convert);
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->addItem(QString());
        comboBox_Type_02_Convert->setObjectName(QString::fromUtf8("comboBox_Type_02_Convert"));

        gridLayout_9->addWidget(comboBox_Type_02_Convert, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_02_Convert);
        page_Type_03_Elemental = new QWidget();
        page_Type_03_Elemental->setObjectName(QString::fromUtf8("page_Type_03_Elemental"));
        gridLayout_10 = new QGridLayout(page_Type_03_Elemental);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_03_Elemental = new QComboBox(page_Type_03_Elemental);
        comboBox_Type_03_Elemental->addItem(QString());
        comboBox_Type_03_Elemental->addItem(QString());
        comboBox_Type_03_Elemental->addItem(QString());
        comboBox_Type_03_Elemental->addItem(QString());
        comboBox_Type_03_Elemental->addItem(QString());
        comboBox_Type_03_Elemental->setObjectName(QString::fromUtf8("comboBox_Type_03_Elemental"));

        gridLayout_10->addWidget(comboBox_Type_03_Elemental, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_03_Elemental);
        page_Type_04_Filter = new QWidget();
        page_Type_04_Filter->setObjectName(QString::fromUtf8("page_Type_04_Filter"));
        gridLayout_11 = new QGridLayout(page_Type_04_Filter);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_04_Filter = new QComboBox(page_Type_04_Filter);
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->addItem(QString());
        comboBox_Type_04_Filter->setObjectName(QString::fromUtf8("comboBox_Type_04_Filter"));

        gridLayout_11->addWidget(comboBox_Type_04_Filter, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_04_Filter);
        page_Type_05_Morphology = new QWidget();
        page_Type_05_Morphology->setObjectName(QString::fromUtf8("page_Type_05_Morphology"));
        gridLayout_12 = new QGridLayout(page_Type_05_Morphology);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_05_Morphology = new QComboBox(page_Type_05_Morphology);
        comboBox_Type_05_Morphology->addItem(QString());
        comboBox_Type_05_Morphology->addItem(QString());
        comboBox_Type_05_Morphology->addItem(QString());
        comboBox_Type_05_Morphology->addItem(QString());
        comboBox_Type_05_Morphology->setObjectName(QString::fromUtf8("comboBox_Type_05_Morphology"));

        gridLayout_12->addWidget(comboBox_Type_05_Morphology, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_05_Morphology);
        page_Type_06_Math = new QWidget();
        page_Type_06_Math->setObjectName(QString::fromUtf8("page_Type_06_Math"));
        gridLayout_13 = new QGridLayout(page_Type_06_Math);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_06_Math = new QComboBox(page_Type_06_Math);
        comboBox_Type_06_Math->addItem(QString());
        comboBox_Type_06_Math->addItem(QString());
        comboBox_Type_06_Math->addItem(QString());
        comboBox_Type_06_Math->addItem(QString());
        comboBox_Type_06_Math->addItem(QString());
        comboBox_Type_06_Math->addItem(QString());
        comboBox_Type_06_Math->setObjectName(QString::fromUtf8("comboBox_Type_06_Math"));

        gridLayout_13->addWidget(comboBox_Type_06_Math, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_06_Math);
        page_Type_07_Transform = new QWidget();
        page_Type_07_Transform->setObjectName(QString::fromUtf8("page_Type_07_Transform"));
        gridLayout_14 = new QGridLayout(page_Type_07_Transform);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_07_Transform = new QComboBox(page_Type_07_Transform);
        comboBox_Type_07_Transform->addItem(QString());
        comboBox_Type_07_Transform->addItem(QString());
        comboBox_Type_07_Transform->addItem(QString());
        comboBox_Type_07_Transform->addItem(QString());
        comboBox_Type_07_Transform->setObjectName(QString::fromUtf8("comboBox_Type_07_Transform"));

        gridLayout_14->addWidget(comboBox_Type_07_Transform, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_07_Transform);
        page_Type_08_Feature = new QWidget();
        page_Type_08_Feature->setObjectName(QString::fromUtf8("page_Type_08_Feature"));
        gridLayout_15 = new QGridLayout(page_Type_08_Feature);
        gridLayout_15->setSpacing(0);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_08_Feature = new QComboBox(page_Type_08_Feature);
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->addItem(QString());
        comboBox_Type_08_Feature->setObjectName(QString::fromUtf8("comboBox_Type_08_Feature"));

        gridLayout_15->addWidget(comboBox_Type_08_Feature, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_08_Feature);
        page_Type_09_Other = new QWidget();
        page_Type_09_Other->setObjectName(QString::fromUtf8("page_Type_09_Other"));
        gridLayout_16 = new QGridLayout(page_Type_09_Other);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_09_Other = new QComboBox(page_Type_09_Other);
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->addItem(QString());
        comboBox_Type_09_Other->setObjectName(QString::fromUtf8("comboBox_Type_09_Other"));

        gridLayout_16->addWidget(comboBox_Type_09_Other, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_09_Other);
        page_Type_10_Dimension = new QWidget();
        page_Type_10_Dimension->setObjectName(QString::fromUtf8("page_Type_10_Dimension"));
        gridLayout_49 = new QGridLayout(page_Type_10_Dimension);
        gridLayout_49->setSpacing(0);
        gridLayout_49->setObjectName(QString::fromUtf8("gridLayout_49"));
        gridLayout_49->setContentsMargins(0, 0, 0, 0);
        comboBox_Type_10_Dimension = new QComboBox(page_Type_10_Dimension);
        comboBox_Type_10_Dimension->addItem(QString());
        comboBox_Type_10_Dimension->addItem(QString());
        comboBox_Type_10_Dimension->addItem(QString());
        comboBox_Type_10_Dimension->addItem(QString());
        comboBox_Type_10_Dimension->addItem(QString());
        comboBox_Type_10_Dimension->addItem(QString());
        comboBox_Type_10_Dimension->setObjectName(QString::fromUtf8("comboBox_Type_10_Dimension"));

        gridLayout_49->addWidget(comboBox_Type_10_Dimension, 0, 0, 1, 1);

        stackedWidget_Type_Main->addWidget(page_Type_10_Dimension);

        gridLayout_3->addWidget(stackedWidget_Type_Main, 1, 0, 1, 1);

        comboBox_Type_Main = new QComboBox(groupBox_Type_Update);
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->addItem(QString());
        comboBox_Type_Main->setObjectName(QString::fromUtf8("comboBox_Type_Main"));

        gridLayout_3->addWidget(comboBox_Type_Main, 0, 0, 1, 1);

        pushButton_Update_Step = new QPushButton(groupBox_Type_Update);
        pushButton_Update_Step->setObjectName(QString::fromUtf8("pushButton_Update_Step"));
        QSizePolicy sizePolicy17(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy17.setHorizontalStretch(0);
        sizePolicy17.setVerticalStretch(0);
        sizePolicy17.setHeightForWidth(pushButton_Update_Step->sizePolicy().hasHeightForWidth());
        pushButton_Update_Step->setSizePolicy(sizePolicy17);
        pushButton_Update_Step->setMinimumSize(QSize(0, 23));

        gridLayout_3->addWidget(pushButton_Update_Step, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_Type_Update, 3, 0, 1, 1);

        groupBox_View_Plane = new QGroupBox(centralwidget);
        groupBox_View_Plane->setObjectName(QString::fromUtf8("groupBox_View_Plane"));
        QSizePolicy sizePolicy18(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy18.setHorizontalStretch(0);
        sizePolicy18.setVerticalStretch(0);
        sizePolicy18.setHeightForWidth(groupBox_View_Plane->sizePolicy().hasHeightForWidth());
        groupBox_View_Plane->setSizePolicy(sizePolicy18);
        groupBox_View_Plane->setMaximumSize(QSize(100, 16777215));
        gridLayout_85 = new QGridLayout(groupBox_View_Plane);
        gridLayout_85->setSpacing(1);
        gridLayout_85->setObjectName(QString::fromUtf8("gridLayout_85"));
        gridLayout_85->setContentsMargins(3, 3, 3, 3);
        comboBox_View_Plane = new QComboBox(groupBox_View_Plane);
        comboBox_View_Plane->setObjectName(QString::fromUtf8("comboBox_View_Plane"));

        gridLayout_85->addWidget(comboBox_View_Plane, 0, 0, 1, 1);

        doubleSpinBox_View_Plane_X = new QDoubleSpinBox(groupBox_View_Plane);
        doubleSpinBox_View_Plane_X->setObjectName(QString::fromUtf8("doubleSpinBox_View_Plane_X"));
        doubleSpinBox_View_Plane_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Plane_X->setAccelerated(false);
        doubleSpinBox_View_Plane_X->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Plane_X->setDecimals(0);
        doubleSpinBox_View_Plane_X->setMaximum(9999999999999999931398190359470212947659194368.000000000000000);

        gridLayout_85->addWidget(doubleSpinBox_View_Plane_X, 1, 0, 1, 1);

        doubleSpinBox_View_Plane_Y = new QDoubleSpinBox(groupBox_View_Plane);
        doubleSpinBox_View_Plane_Y->setObjectName(QString::fromUtf8("doubleSpinBox_View_Plane_Y"));
        doubleSpinBox_View_Plane_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Plane_Y->setAccelerated(false);
        doubleSpinBox_View_Plane_Y->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Plane_Y->setDecimals(0);
        doubleSpinBox_View_Plane_Y->setMaximum(9999999999999999931398190359470212947659194368.000000000000000);

        gridLayout_85->addWidget(doubleSpinBox_View_Plane_Y, 2, 0, 1, 1);

        doubleSpinBox_View_Plane_Z = new QDoubleSpinBox(groupBox_View_Plane);
        doubleSpinBox_View_Plane_Z->setObjectName(QString::fromUtf8("doubleSpinBox_View_Plane_Z"));
        doubleSpinBox_View_Plane_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Plane_Z->setAccelerated(false);
        doubleSpinBox_View_Plane_Z->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Plane_Z->setDecimals(0);
        doubleSpinBox_View_Plane_Z->setMaximum(9999999999999999931398190359470212947659194368.000000000000000);

        gridLayout_85->addWidget(doubleSpinBox_View_Plane_Z, 3, 0, 1, 1);

        doubleSpinBox_View_Plane_T = new QDoubleSpinBox(groupBox_View_Plane);
        doubleSpinBox_View_Plane_T->setObjectName(QString::fromUtf8("doubleSpinBox_View_Plane_T"));
        doubleSpinBox_View_Plane_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Plane_T->setAccelerated(false);
        doubleSpinBox_View_Plane_T->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Plane_T->setDecimals(0);
        doubleSpinBox_View_Plane_T->setMaximum(9999999999999999931398190359470212947659194368.000000000000000);

        gridLayout_85->addWidget(doubleSpinBox_View_Plane_T, 4, 0, 1, 1);

        doubleSpinBox_View_Plane_S = new QDoubleSpinBox(groupBox_View_Plane);
        doubleSpinBox_View_Plane_S->setObjectName(QString::fromUtf8("doubleSpinBox_View_Plane_S"));
        doubleSpinBox_View_Plane_S->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Plane_S->setAccelerated(false);
        doubleSpinBox_View_Plane_S->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Plane_S->setDecimals(0);
        doubleSpinBox_View_Plane_S->setMaximum(9999999999999999931398190359470212947659194368.000000000000000);

        gridLayout_85->addWidget(doubleSpinBox_View_Plane_S, 5, 0, 1, 1);

        doubleSpinBox_View_Plane_P = new QDoubleSpinBox(groupBox_View_Plane);
        doubleSpinBox_View_Plane_P->setObjectName(QString::fromUtf8("doubleSpinBox_View_Plane_P"));
        doubleSpinBox_View_Plane_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Plane_P->setAccelerated(false);
        doubleSpinBox_View_Plane_P->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Plane_P->setDecimals(0);
        doubleSpinBox_View_Plane_P->setMaximum(9999999999999999931398190359470212947659194368.000000000000000);

        gridLayout_85->addWidget(doubleSpinBox_View_Plane_P, 6, 0, 1, 1);


        gridLayout->addWidget(groupBox_View_Plane, 0, 2, 1, 1);

        verticalSpacer_View = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_View, 2, 2, 1, 1);

        groupBox_View_Contrast = new QGroupBox(centralwidget);
        groupBox_View_Contrast->setObjectName(QString::fromUtf8("groupBox_View_Contrast"));
        groupBox_View_Contrast->setEnabled(true);
        sizePolicy18.setHeightForWidth(groupBox_View_Contrast->sizePolicy().hasHeightForWidth());
        groupBox_View_Contrast->setSizePolicy(sizePolicy18);
        groupBox_View_Contrast->setMinimumSize(QSize(100, 0));
        groupBox_View_Contrast->setMaximumSize(QSize(100, 16777215));
        gridLayout_84 = new QGridLayout(groupBox_View_Contrast);
        gridLayout_84->setSpacing(1);
        gridLayout_84->setObjectName(QString::fromUtf8("gridLayout_84"));
        gridLayout_84->setContentsMargins(3, 3, 3, 3);
        comboBox_View_Crop = new QComboBox(groupBox_View_Contrast);
        comboBox_View_Crop->setObjectName(QString::fromUtf8("comboBox_View_Crop"));
        comboBox_View_Crop->setMinimumSize(QSize(92, 0));
        comboBox_View_Crop->setMaximumSize(QSize(92, 16777215));

        gridLayout_84->addWidget(comboBox_View_Crop, 2, 0, 1, 1);

        comboBox_View_Transform = new QComboBox(groupBox_View_Contrast);
        comboBox_View_Transform->setObjectName(QString::fromUtf8("comboBox_View_Transform"));
        comboBox_View_Transform->setMinimumSize(QSize(92, 0));
        comboBox_View_Transform->setMaximumSize(QSize(92, 16777215));

        gridLayout_84->addWidget(comboBox_View_Transform, 6, 0, 1, 1);

        doubleSpinBox_View_Divisor = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Divisor->setObjectName(QString::fromUtf8("doubleSpinBox_View_Divisor"));
        doubleSpinBox_View_Divisor->setEnabled(false);
        doubleSpinBox_View_Divisor->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Divisor->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Divisor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Divisor->setDecimals(3);
        doubleSpinBox_View_Divisor->setMinimum(0.001000000000000);
        doubleSpinBox_View_Divisor->setMaximum(100000000000000002356936751417025583324953279505688186312991253926828166846616173259830936159244951026231410688.000000000000000);
        doubleSpinBox_View_Divisor->setValue(1.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Divisor, 9, 0, 1, 1);

        checkBox_View_VisTrafo = new QCheckBox(groupBox_View_Contrast);
        checkBox_View_VisTrafo->setObjectName(QString::fromUtf8("checkBox_View_VisTrafo"));

        gridLayout_84->addWidget(checkBox_View_VisTrafo, 0, 0, 1, 1);

        doubleSpinBox_View_Range = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Range->setObjectName(QString::fromUtf8("doubleSpinBox_View_Range"));
        doubleSpinBox_View_Range->setEnabled(false);
        doubleSpinBox_View_Range->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Range->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Range->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Range->setDecimals(3);
        doubleSpinBox_View_Range->setMinimum(0.010000000000000);
        doubleSpinBox_View_Range->setMaximum(999999999999999943801810948794571024057224129020550531544123892056457216.000000000000000);
        doubleSpinBox_View_Range->setValue(1.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Range, 13, 0, 1, 1);

        doubleSpinBox_View_Max = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Max->setObjectName(QString::fromUtf8("doubleSpinBox_View_Max"));
        doubleSpinBox_View_Max->setEnabled(false);
        doubleSpinBox_View_Max->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Max->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Max->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Max->setDecimals(3);
        doubleSpinBox_View_Max->setMinimum(-99999999999999999322094867436162797646170844194406400.000000000000000);
        doubleSpinBox_View_Max->setMaximum(9999999999999999830336967949613257980309080240684656321838454199566729216.000000000000000);
        doubleSpinBox_View_Max->setValue(255.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Max, 5, 0, 1, 1);

        doubleSpinBox_View_Anchor = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Anchor->setObjectName(QString::fromUtf8("doubleSpinBox_View_Anchor"));
        doubleSpinBox_View_Anchor->setEnabled(false);
        doubleSpinBox_View_Anchor->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Anchor->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Anchor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Anchor->setDecimals(3);
        doubleSpinBox_View_Anchor->setMinimum(-100000000000000009190283508143378238084034459715684532224.000000000000000);
        doubleSpinBox_View_Anchor->setMaximum(99999999999999995280522225138166806691251291352861698530421623488512.000000000000000);
        doubleSpinBox_View_Anchor->setValue(0.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Anchor, 11, 0, 1, 1);

        comboBox_View_Anchor = new QComboBox(groupBox_View_Contrast);
        comboBox_View_Anchor->setObjectName(QString::fromUtf8("comboBox_View_Anchor"));
        comboBox_View_Anchor->setMinimumSize(QSize(92, 0));
        comboBox_View_Anchor->setMaximumSize(QSize(92, 16777215));

        gridLayout_84->addWidget(comboBox_View_Anchor, 10, 0, 1, 1);

        doubleSpinBox_View_Gamma = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_View_Gamma"));
        doubleSpinBox_View_Gamma->setEnabled(false);
        doubleSpinBox_View_Gamma->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Gamma->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Gamma->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Gamma->setDecimals(3);
        doubleSpinBox_View_Gamma->setMinimum(0.001000000000000);
        doubleSpinBox_View_Gamma->setMaximum(100.000000000000000);
        doubleSpinBox_View_Gamma->setSingleStep(0.010000000000000);
        doubleSpinBox_View_Gamma->setValue(1.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Gamma, 7, 0, 1, 1);

        doubleSpinBox_View_Min = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Min->setObjectName(QString::fromUtf8("doubleSpinBox_View_Min"));
        doubleSpinBox_View_Min->setEnabled(false);
        doubleSpinBox_View_Min->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Min->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Min->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        doubleSpinBox_View_Min->setDecimals(3);
        doubleSpinBox_View_Min->setMinimum(-99999999999999999322094867436162797646170844194406400.000000000000000);
        doubleSpinBox_View_Min->setMaximum(9999999999999999830336967949613257980309080240684656321838454199566729216.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Min, 4, 0, 1, 1);

        comboBox_View_Range = new QComboBox(groupBox_View_Contrast);
        comboBox_View_Range->setObjectName(QString::fromUtf8("comboBox_View_Range"));
        comboBox_View_Range->setMinimumSize(QSize(92, 0));
        comboBox_View_Range->setMaximumSize(QSize(92, 16777215));

        gridLayout_84->addWidget(comboBox_View_Range, 12, 0, 1, 1);

        doubleSpinBox_View_Center = new QDoubleSpinBox(groupBox_View_Contrast);
        doubleSpinBox_View_Center->setObjectName(QString::fromUtf8("doubleSpinBox_View_Center"));
        doubleSpinBox_View_Center->setEnabled(false);
        doubleSpinBox_View_Center->setMinimumSize(QSize(92, 0));
        doubleSpinBox_View_Center->setMaximumSize(QSize(92, 18));
        doubleSpinBox_View_Center->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_View_Center->setDecimals(3);
        doubleSpinBox_View_Center->setMinimum(-99999999999999995280522225138166806691251291352861698530421623488512.000000000000000);
        doubleSpinBox_View_Center->setMaximum(999999999999999949387135297074018866963645011013410073083904.000000000000000);

        gridLayout_84->addWidget(doubleSpinBox_View_Center, 8, 0, 1, 1);

        comboBox_View_Complex = new QComboBox(groupBox_View_Contrast);
        comboBox_View_Complex->setObjectName(QString::fromUtf8("comboBox_View_Complex"));
        comboBox_View_Complex->setMinimumSize(QSize(92, 0));
        comboBox_View_Complex->setMaximumSize(QSize(92, 16777215));

        gridLayout_84->addWidget(comboBox_View_Complex, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_View_Contrast, 1, 2, 1, 1);

        tabWidget_Output = new QTabWidget(centralwidget);
        tabWidget_Output->setObjectName(QString::fromUtf8("tabWidget_Output"));
        tabWidget_Output->setMinimumSize(QSize(0, 0));
        tabWidget_Output->setTabPosition(QTabWidget::West);
        tabWidget_Output->setTabShape(QTabWidget::Rounded);
        tabWidget_Output->setElideMode(Qt::ElideNone);
        tabWidget_Output->setDocumentMode(false);
        tabWidget_Output->setTabsClosable(false);
        tabWidget_Output->setMovable(false);
        tabWidget_Output->setTabBarAutoHide(false);
        tab_Output_Image = new QWidget();
        tab_Output_Image->setObjectName(QString::fromUtf8("tab_Output_Image"));
        gridLayout_27 = new QGridLayout(tab_Output_Image);
        gridLayout_27->setSpacing(3);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setContentsMargins(3, 3, 3, 3);
        graphicsView_Viewer = new QGraphicsView(tab_Output_Image);
        graphicsView_Viewer->setObjectName(QString::fromUtf8("graphicsView_Viewer"));
        graphicsView_Viewer->setMouseTracking(true);
        graphicsView_Viewer->setTabletTracking(true);

        gridLayout_27->addWidget(graphicsView_Viewer, 0, 0, 4, 2);

        tabWidget_Output->addTab(tab_Output_Image, QString());
        tab_Output_Hist = new QWidget();
        tab_Output_Hist->setObjectName(QString::fromUtf8("tab_Output_Hist"));
        gridLayout_48 = new QGridLayout(tab_Output_Hist);
        gridLayout_48->setSpacing(3);
        gridLayout_48->setObjectName(QString::fromUtf8("gridLayout_48"));
        gridLayout_48->setContentsMargins(6, 6, 6, 6);
        gridLayout_Output_Hist = new QGridLayout();
        gridLayout_Output_Hist->setSpacing(3);
        gridLayout_Output_Hist->setObjectName(QString::fromUtf8("gridLayout_Output_Hist"));

        gridLayout_48->addLayout(gridLayout_Output_Hist, 2, 0, 1, 11);

        line_Output_Hist_3 = new QFrame(tab_Output_Hist);
        line_Output_Hist_3->setObjectName(QString::fromUtf8("line_Output_Hist_3"));
        line_Output_Hist_3->setFrameShape(QFrame::VLine);
        line_Output_Hist_3->setFrameShadow(QFrame::Sunken);

        gridLayout_48->addWidget(line_Output_Hist_3, 1, 2, 1, 1);

        checkBox_Output_Hist_Accumulate = new QCheckBox(tab_Output_Hist);
        checkBox_Output_Hist_Accumulate->setObjectName(QString::fromUtf8("checkBox_Output_Hist_Accumulate"));
        checkBox_Output_Hist_Accumulate->setMinimumSize(QSize(0, 0));
        checkBox_Output_Hist_Accumulate->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_48->addWidget(checkBox_Output_Hist_Accumulate, 1, 4, 1, 1);

        horizontalSpacer_Output_Hist = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_48->addItem(horizontalSpacer_Output_Hist, 1, 10, 1, 1);

        checkBox_Output_Hist_Uniform = new QCheckBox(tab_Output_Hist);
        checkBox_Output_Hist_Uniform->setObjectName(QString::fromUtf8("checkBox_Output_Hist_Uniform"));
        checkBox_Output_Hist_Uniform->setMinimumSize(QSize(0, 0));
        checkBox_Output_Hist_Uniform->setMaximumSize(QSize(16777215, 16777215));
        checkBox_Output_Hist_Uniform->setChecked(true);

        gridLayout_48->addWidget(checkBox_Output_Hist_Uniform, 1, 3, 1, 1);

        pushButton_Update_Hist = new QPushButton(tab_Output_Hist);
        pushButton_Update_Hist->setObjectName(QString::fromUtf8("pushButton_Update_Hist"));
        pushButton_Update_Hist->setMinimumSize(QSize(130, 0));
        pushButton_Update_Hist->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_48->addWidget(pushButton_Update_Hist, 1, 0, 1, 1);

        label_HistClasses = new QLabel(tab_Output_Hist);
        label_HistClasses->setObjectName(QString::fromUtf8("label_HistClasses"));

        gridLayout_48->addWidget(label_HistClasses, 1, 6, 1, 1);

        line_Hist = new QFrame(tab_Output_Hist);
        line_Hist->setObjectName(QString::fromUtf8("line_Hist"));
        line_Hist->setFrameShape(QFrame::VLine);
        line_Hist->setFrameShadow(QFrame::Sunken);

        gridLayout_48->addWidget(line_Hist, 1, 5, 1, 1);

        spinBox_HistClasses = new QSpinBox(tab_Output_Hist);
        spinBox_HistClasses->setObjectName(QString::fromUtf8("spinBox_HistClasses"));
        sizePolicy9.setHeightForWidth(spinBox_HistClasses->sizePolicy().hasHeightForWidth());
        spinBox_HistClasses->setSizePolicy(sizePolicy9);
        spinBox_HistClasses->setMinimum(2);
        spinBox_HistClasses->setMaximum(10000);
        spinBox_HistClasses->setSingleStep(10);
        spinBox_HistClasses->setValue(255);

        gridLayout_48->addWidget(spinBox_HistClasses, 1, 7, 1, 1);

        checkBox_Output_Hist_Full6D = new QCheckBox(tab_Output_Hist);
        checkBox_Output_Hist_Full6D->setObjectName(QString::fromUtf8("checkBox_Output_Hist_Full6D"));

        gridLayout_48->addWidget(checkBox_Output_Hist_Full6D, 1, 1, 1, 1);

        tabWidget_Output->addTab(tab_Output_Hist, QString());
        tab_Output_Times = new QWidget();
        tab_Output_Times->setObjectName(QString::fromUtf8("tab_Output_Times"));
        gridLayout_46 = new QGridLayout(tab_Output_Times);
        gridLayout_46->setObjectName(QString::fromUtf8("gridLayout_46"));
        line_Output_Times = new QFrame(tab_Output_Times);
        line_Output_Times->setObjectName(QString::fromUtf8("line_Output_Times"));
        line_Output_Times->setFrameShape(QFrame::VLine);
        line_Output_Times->setFrameShadow(QFrame::Sunken);

        gridLayout_46->addWidget(line_Output_Times, 0, 1, 1, 1);

        horizontalSpacer_Output_Times = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_46->addItem(horizontalSpacer_Output_Times, 0, 6, 1, 1);

        pushButton_Update_Times = new QPushButton(tab_Output_Times);
        pushButton_Update_Times->setObjectName(QString::fromUtf8("pushButton_Update_Times"));
        pushButton_Update_Times->setMinimumSize(QSize(130, 0));

        gridLayout_46->addWidget(pushButton_Update_Times, 0, 0, 1, 1);

        gridLayout_Output_Times = new QGridLayout();
        gridLayout_Output_Times->setObjectName(QString::fromUtf8("gridLayout_Output_Times"));

        gridLayout_46->addLayout(gridLayout_Output_Times, 1, 0, 1, 7);

        checkBox_Output_Times_Processing = new QCheckBox(tab_Output_Times);
        checkBox_Output_Times_Processing->setObjectName(QString::fromUtf8("checkBox_Output_Times_Processing"));
        checkBox_Output_Times_Processing->setChecked(true);

        gridLayout_46->addWidget(checkBox_Output_Times_Processing, 0, 2, 1, 1);

        checkBox_Output_Times_Hist = new QCheckBox(tab_Output_Times);
        checkBox_Output_Times_Hist->setObjectName(QString::fromUtf8("checkBox_Output_Times_Hist"));
        checkBox_Output_Times_Hist->setChecked(false);

        gridLayout_46->addWidget(checkBox_Output_Times_Hist, 0, 5, 1, 1);

        checkBox_Output_Times_Show = new QCheckBox(tab_Output_Times);
        checkBox_Output_Times_Show->setObjectName(QString::fromUtf8("checkBox_Output_Times_Show"));
        checkBox_Output_Times_Show->setChecked(true);

        gridLayout_46->addWidget(checkBox_Output_Times_Show, 0, 4, 1, 1);

        checkBox_Output_Times_Conversion = new QCheckBox(tab_Output_Times);
        checkBox_Output_Times_Conversion->setObjectName(QString::fromUtf8("checkBox_Output_Times_Conversion"));
        checkBox_Output_Times_Conversion->setChecked(true);

        gridLayout_46->addWidget(checkBox_Output_Times_Conversion, 0, 3, 1, 1);

        tabWidget_Output->addTab(tab_Output_Times, QString());
        tab_Output_Chain_Info = new QWidget();
        tab_Output_Chain_Info->setObjectName(QString::fromUtf8("tab_Output_Chain_Info"));
        gridLayout_44 = new QGridLayout(tab_Output_Chain_Info);
        gridLayout_44->setObjectName(QString::fromUtf8("gridLayout_44"));
        label_Cahin_Pos = new QLabel(tab_Output_Chain_Info);
        label_Cahin_Pos->setObjectName(QString::fromUtf8("label_Cahin_Pos"));

        gridLayout_44->addWidget(label_Cahin_Pos, 2, 0, 1, 1);

        label_Chain_Source_of = new QLabel(tab_Output_Chain_Info);
        label_Chain_Source_of->setObjectName(QString::fromUtf8("label_Chain_Source_of"));
        label_Chain_Source_of->setMinimumSize(QSize(75, 0));
        label_Chain_Source_of->setMaximumSize(QSize(75, 16777215));

        gridLayout_44->addWidget(label_Chain_Source_of, 1, 0, 1, 1);

        label_Chain_Sources_Used = new QLabel(tab_Output_Chain_Info);
        label_Chain_Sources_Used->setObjectName(QString::fromUtf8("label_Chain_Sources_Used"));
        label_Chain_Sources_Used->setMinimumSize(QSize(75, 0));
        label_Chain_Sources_Used->setMaximumSize(QSize(75, 16777215));

        gridLayout_44->addWidget(label_Chain_Sources_Used, 0, 0, 1, 1);

        label_Chain_Sources_Used_List = new QLabel(tab_Output_Chain_Info);
        label_Chain_Sources_Used_List->setObjectName(QString::fromUtf8("label_Chain_Sources_Used_List"));
        label_Chain_Sources_Used_List->setMinimumSize(QSize(150, 0));

        gridLayout_44->addWidget(label_Chain_Sources_Used_List, 0, 1, 1, 1);

        label_Chain_Source_of_List = new QLabel(tab_Output_Chain_Info);
        label_Chain_Source_of_List->setObjectName(QString::fromUtf8("label_Chain_Source_of_List"));
        label_Chain_Source_of_List->setMinimumSize(QSize(150, 0));

        gridLayout_44->addWidget(label_Chain_Source_of_List, 1, 1, 1, 1);

        verticalSpacer_Chain = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_44->addItem(verticalSpacer_Chain, 4, 0, 1, 2);

        horizontalSpacer_Chain = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_44->addItem(horizontalSpacer_Chain, 4, 2, 1, 1);

        label_Chain_Pos_Val = new QLabel(tab_Output_Chain_Info);
        label_Chain_Pos_Val->setObjectName(QString::fromUtf8("label_Chain_Pos_Val"));

        gridLayout_44->addWidget(label_Chain_Pos_Val, 2, 1, 1, 1);

        label_Chain_Updated = new QLabel(tab_Output_Chain_Info);
        label_Chain_Updated->setObjectName(QString::fromUtf8("label_Chain_Updated"));

        gridLayout_44->addWidget(label_Chain_Updated, 3, 0, 1, 1);

        label_Chain_Updated_Val = new QLabel(tab_Output_Chain_Info);
        label_Chain_Updated_Val->setObjectName(QString::fromUtf8("label_Chain_Updated_Val"));

        gridLayout_44->addWidget(label_Chain_Updated_Val, 3, 1, 1, 1);

        tabWidget_Output->addTab(tab_Output_Chain_Info, QString());
        tab_Output_FunctionView = new QWidget();
        tab_Output_FunctionView->setObjectName(QString::fromUtf8("tab_Output_FunctionView"));
        gridLayout_110 = new QGridLayout(tab_Output_FunctionView);
        gridLayout_110->setObjectName(QString::fromUtf8("gridLayout_110"));
        comboBox_FunctionView_Mode = new QComboBox(tab_Output_FunctionView);
        comboBox_FunctionView_Mode->addItem(QString());
        comboBox_FunctionView_Mode->setObjectName(QString::fromUtf8("comboBox_FunctionView_Mode"));

        gridLayout_110->addWidget(comboBox_FunctionView_Mode, 0, 0, 1, 1);

        gridLayout_FunctionView = new QGridLayout();
        gridLayout_FunctionView->setObjectName(QString::fromUtf8("gridLayout_FunctionView"));

        gridLayout_110->addLayout(gridLayout_FunctionView, 1, 0, 1, 2);

        checkBox = new QCheckBox(tab_Output_FunctionView);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        sizePolicy9.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy9);

        gridLayout_110->addWidget(checkBox, 0, 1, 1, 1);

        tabWidget_Output->addTab(tab_Output_FunctionView, QString());

        gridLayout->addWidget(tabWidget_Output, 0, 0, 3, 2);

        D_StepWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_StepWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 594, 21));
        menuViewer = new QMenu(menubar);
        menuViewer->setObjectName(QString::fromUtf8("menuViewer"));
        menuViewer->setAutoFillBackground(false);
        menuLayout = new QMenu(menubar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuHistogram = new QMenu(menubar);
        menuHistogram->setObjectName(QString::fromUtf8("menuHistogram"));
        menuTimes = new QMenu(menubar);
        menuTimes->setObjectName(QString::fromUtf8("menuTimes"));
        menuTest = new QMenu(menubar);
        menuTest->setObjectName(QString::fromUtf8("menuTest"));
        menuMeasure = new QMenu(menubar);
        menuMeasure->setObjectName(QString::fromUtf8("menuMeasure"));
        D_StepWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(D_StepWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_StepWindow->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuMeasure->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuHistogram->menuAction());
        menubar->addAction(menuTimes->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuTest->menuAction());
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuViewer->addSeparator();
        menuViewer->addAction(action_connect_plane_position_to_other_steps);
        menuViewer->addSeparator();
        menuViewer->addAction(action_Connect_Steps_Zoom);
        menuViewer->addAction(action_Zoom_In);
        menuViewer->addAction(action_Zoom_Out);
        menuViewer->addAction(action_Zoom_Reset);
        menuLayout->addAction(action_Show_Output);
        menuLayout->addAction(action_Show_STUD);
        menuLayout->addAction(action_Show_Settings);
        menuLayout->addAction(action_Show_ViewOptions);
        menuLayout->addSeparator();
        menuUpdate->addAction(action_Update_Step);
        menuUpdate->addAction(action_Update_Hist);
        menuUpdate->addAction(action_Update_Times);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Autoupdate_ImgProc_on_Settings);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Skip_Chain_Update);
        menuUpdate->addAction(action_Autoupdate_Next_Step);
        menuData->addAction(action_Save_Image);
        menuData->addAction(action_Save_Image_List);
        menuData->addAction(action_SaveScreenshot);
        menuData->addAction(action_Save_asBinary);
        menuWindow->addAction(action_Show_Minimized);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximize);
        menuWindow->addAction(action_Show_Fullscreen);
        menuWindow->addSeparator();
        menuWindow->addAction(action_Change_Title);
        menuHistogram->addAction(action_Autoupdate_Hist_on_Step);
        menuHistogram->addAction(action_Autoupdate_Hist_on_HistSettings);
        menuTimes->addAction(action_Autoupdate_Times_on_Step);
        menuTimes->addAction(action_Autoupdate_Times_on_TimesSettings);
        menuTest->addAction(action_Features_Visualisation);
        menuMeasure->addAction(action_Save_Feature_List);
        menuMeasure->addAction(action_Save_Analysis);
        menuMeasure->addAction(action_Measure_Line_Distance);

        retranslateUi(D_StepWindow);
        QObject::connect(comboBox_Type_Main, SIGNAL(currentIndexChanged(int)), stackedWidget_Main_Settings, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_Main, SIGNAL(currentIndexChanged(int)), stackedWidget_Type_Main, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_01_Edit, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_01_Edit, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_02_Convert, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_02_Convert, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_03_Elemental, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_03_Elemental, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_04_Filter, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_04_Filter, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_05_Morphology, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_05_Morphology, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_07_Transform, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_07_Transform, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_09_Other, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_09_Other, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_02_Color_Direction_Left, SIGNAL(currentIndexChanged(int)), comboBox_02_Color_Direction_Top, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_02_Color_Direction_Top, SIGNAL(currentIndexChanged(int)), comboBox_02_Color_Direction_Left, SLOT(setCurrentIndex(int)));
        QObject::connect(action_Show_Output, SIGNAL(triggered(bool)), tabWidget_Output, SLOT(setVisible(bool)));
        QObject::connect(action_Show_STUD, SIGNAL(triggered(bool)), groupBox_Source, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Settings, SIGNAL(triggered(bool)), groupBox_Settings, SLOT(setVisible(bool)));
        QObject::connect(comboBox_04_Special_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_04_Special, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Type_06_Math, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_06_Math, SLOT(setCurrentIndex(int)));
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_StepWindow, SLOT(showFullScreen()));
        QObject::connect(action_Show_Maximize, SIGNAL(triggered()), D_StepWindow, SLOT(showMaximized()));
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_StepWindow, SLOT(showNormal()));
        QObject::connect(action_Show_Minimized, SIGNAL(triggered()), D_StepWindow, SLOT(showMinimized()));
        QObject::connect(comboBox_Type_00_Source, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_00_Source, SLOT(setCurrentIndex(int)));
        QObject::connect(spinBox_03_GrabColor_Ch1_Max, SIGNAL(valueChanged(int)), horizontalSlider_03_GrabColor_Ch1_Max, SLOT(setValue(int)));
        QObject::connect(spinBox_03_GrabColor_Ch1_Min, SIGNAL(valueChanged(int)), horizontalSlider_03_GrabColor_Ch1_Min, SLOT(setValue(int)));
        QObject::connect(spinBox_03_GrabColor_Ch2_Max, SIGNAL(valueChanged(int)), horizontalSlider_03_GrabColor_Ch2_Max, SLOT(setValue(int)));
        QObject::connect(spinBox_03_GrabColor_Ch2_Min, SIGNAL(valueChanged(int)), horizontalSlider_03_GrabColor_Ch2_Min, SLOT(setValue(int)));
        QObject::connect(spinBox_03_GrabColor_Ch3_Max, SIGNAL(valueChanged(int)), horizontalSlider_03_GrabColor_Ch3_Max, SLOT(setValue(int)));
        QObject::connect(spinBox_03_GrabColor_Ch3_Min, SIGNAL(valueChanged(int)), horizontalSlider_03_GrabColor_Ch3_Min, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_GrabColor_Ch1_Max, SIGNAL(valueChanged(int)), spinBox_03_GrabColor_Ch1_Max, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_GrabColor_Ch1_Min, SIGNAL(valueChanged(int)), spinBox_03_GrabColor_Ch1_Min, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_GrabColor_Ch2_Max, SIGNAL(valueChanged(int)), spinBox_03_GrabColor_Ch2_Max, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_GrabColor_Ch2_Min, SIGNAL(valueChanged(int)), spinBox_03_GrabColor_Ch2_Min, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_GrabColor_Ch3_Max, SIGNAL(valueChanged(int)), spinBox_03_GrabColor_Ch3_Max, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_GrabColor_Ch3_Min, SIGNAL(valueChanged(int)), spinBox_03_GrabColor_Ch3_Min, SLOT(setValue(int)));
        QObject::connect(comboBox_01_Crop_Shape, SIGNAL(currentIndexChanged(int)), stackedWidget_01_Crop_Shape, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_03_Thres_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_03_Thres, SLOT(setCurrentIndex(int)));
        QObject::connect(spinBox_03_Thres_Thres_Value_Abs, SIGNAL(valueChanged(int)), horizontalSlider_03_Thres_Abs_Thres_Value, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_03_Thres_Abs_Thres_Value, SIGNAL(valueChanged(int)), spinBox_03_Thres_Thres_Value_Abs, SLOT(setValue(int)));
        QObject::connect(comboBox_01_Floodfill_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_01_Floodfill_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_04_Eilenstein_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_04_Eilenstein_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(action_Show_STUD, SIGNAL(triggered(bool)), groupBox_Type_Update, SLOT(setVisible(bool)));
        QObject::connect(action_Show_ViewOptions, SIGNAL(triggered(bool)), groupBox_View_Plane, SLOT(setVisible(bool)));
        QObject::connect(action_Show_ViewOptions, SIGNAL(triggered(bool)), groupBox_View_Contrast, SLOT(setVisible(bool)));
        QObject::connect(action_Show_STUD, SIGNAL(triggered(bool)), groupBox_ProcDims, SLOT(setVisible(bool)));
        QObject::connect(comboBox_Type_10_Dimension, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_10_Dimension, SLOT(setCurrentIndex(int)));
        QObject::connect(checkBox_10_Pick_S, SIGNAL(clicked(bool)), spinBox_10_Pick_S, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Pick_P, SIGNAL(clicked(bool)), spinBox_10_Pick_P, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_T, SIGNAL(clicked(bool)), spinBox_10_Crop_Min_T, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_X, SIGNAL(clicked(bool)), spinBox_10_Crop_Min_X, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_Z, SIGNAL(clicked(bool)), spinBox_10_Crop_Min_Z, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_Y, SIGNAL(clicked(bool)), spinBox_10_Crop_Min_Y, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_P, SIGNAL(clicked(bool)), spinBox_10_Crop_Min_P, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_S, SIGNAL(clicked(bool)), spinBox_10_Crop_Min_S, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Pick_T, SIGNAL(clicked(bool)), spinBox_10_Pick_T, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Pick_X, SIGNAL(clicked(bool)), spinBox_10_Pick_X, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_Y, SIGNAL(clicked(bool)), spinBox_10_Crop_Max_Y, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Pick_Z, SIGNAL(clicked(bool)), spinBox_10_Pick_Z, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_P, SIGNAL(clicked(bool)), spinBox_10_Crop_Max_P, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_S, SIGNAL(clicked(bool)), spinBox_10_Crop_Max_S, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_T, SIGNAL(clicked(bool)), spinBox_10_Crop_Max_T, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_X, SIGNAL(clicked(bool)), spinBox_10_Crop_Max_X, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Pick_Y, SIGNAL(clicked(bool)), spinBox_10_Pick_Y, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_10_Crop_Z, SIGNAL(clicked(bool)), spinBox_10_Crop_Max_Z, SLOT(setEnabled(bool)));
        QObject::connect(comboBox_Type_08_Feature, SIGNAL(currentIndexChanged(int)), stackedWidget_Settings_08_Features, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_00_Generate_DimVar, SIGNAL(currentIndexChanged(int)), stackedWidget_00_Generate_DimVar, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_07_Watershed_Implementation, SIGNAL(currentIndexChanged(int)), stackedWidget_07_Watershed, SLOT(setCurrentIndex(int)));

        stackedWidget_Main_Settings->setCurrentIndex(0);
        stackedWidget_Settings_00_Source->setCurrentIndex(0);
        stackedWidget_00_Generate_DimVar->setCurrentIndex(0);
        stackedWidget_01_Crop_Shape->setCurrentIndex(0);
        stackedWidget_01_Floodfill_Type->setCurrentIndex(0);
        stackedWidget_Settings_02_Convert->setCurrentIndex(0);
        stackedWidget_Settings_03_Elemental->setCurrentIndex(0);
        stackedWidget_03_Thres->setCurrentIndex(0);
        stackedWidget_Settings_04_Filter->setCurrentIndex(0);
        stackedWidget_04_Special->setCurrentIndex(0);
        stackedWidget_04_Eilenstein_Type->setCurrentIndex(0);
        stackedWidget_Settings_05_Morphology->setCurrentIndex(0);
        stackedWidget_Settings_06_Math->setCurrentIndex(0);
        stackedWidget_Settings_07_Transform->setCurrentIndex(0);
        stackedWidget_Settings_08_Features->setCurrentIndex(0);
        tabWidget_Output->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_StepWindow);
    } // setupUi

    void retranslateUi(QMainWindow *D_StepWindow)
    {
        D_StepWindow->setWindowTitle(QApplication::translate("D_StepWindow", "MainWindow", nullptr));
        action_Smooth_Transformation->setText(QApplication::translate("D_StepWindow", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QApplication::translate("D_StepWindow", "Keep Aspect Ratio", nullptr));
        action_Show_STUD->setText(QApplication::translate("D_StepWindow", "Show Source, Type, Update", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_STUD->setShortcut(QApplication::translate("D_StepWindow", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Settings->setText(QApplication::translate("D_StepWindow", "Show Settings", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Settings->setShortcut(QApplication::translate("D_StepWindow", "F3", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_ViewOptions->setText(QApplication::translate("D_StepWindow", "Show Processing Dimensions", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_ViewOptions->setShortcut(QApplication::translate("D_StepWindow", "F4", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Output->setText(QApplication::translate("D_StepWindow", "Show Output", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Output->setShortcut(QApplication::translate("D_StepWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_Step->setText(QApplication::translate("D_StepWindow", "Update Step", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_Step->setShortcut(QApplication::translate("D_StepWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Skip_Chain_Update->setText(QApplication::translate("D_StepWindow", "Skip when all steps are updated", nullptr));
        action_Save_Image->setText(QApplication::translate("D_StepWindow", "Save Current 2D Plane as Image", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Image->setShortcut(QApplication::translate("D_StepWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Minimized->setText(QApplication::translate("D_StepWindow", "Minimize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Minimized->setShortcut(QApplication::translate("D_StepWindow", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Maximize->setText(QApplication::translate("D_StepWindow", "Maximize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Maximize->setShortcut(QApplication::translate("D_StepWindow", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Normal->setText(QApplication::translate("D_StepWindow", "Normal", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Normal->setShortcut(QApplication::translate("D_StepWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Fullscreen->setText(QApplication::translate("D_StepWindow", "Fullscreen", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Fullscreen->setShortcut(QApplication::translate("D_StepWindow", "F12", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_Hist->setText(QApplication::translate("D_StepWindow", "Update Histogram", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_Hist->setShortcut(QApplication::translate("D_StepWindow", "F6", nullptr));
#endif // QT_NO_SHORTCUT
        action_Autoupdate_Hist_on_Step->setText(QApplication::translate("D_StepWindow", "Autoupdate Histogram on step update", nullptr));
        action_Autoupdate_Hist_on_HistSettings->setText(QApplication::translate("D_StepWindow", "Autoupdate Histogram on change of histogram settings", nullptr));
        action_Autoupdate_Times_on_Step->setText(QApplication::translate("D_StepWindow", "Autoupdate Times on step update", nullptr));
        action_Update_Times->setText(QApplication::translate("D_StepWindow", "Update Times", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_Times->setShortcut(QApplication::translate("D_StepWindow", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        action_Autoupdate_Times_on_TimesSettings->setText(QApplication::translate("D_StepWindow", "Autoupdate Times on change of times settings", nullptr));
        action_Autoupdate_Next_Step->setText(QApplication::translate("D_StepWindow", "Autoupdate following Steps", nullptr));
        action_Autoupdate_ImgProc_on_Settings->setText(QApplication::translate("D_StepWindow", "Autoupdate on Settings changed", nullptr));
        action_Change_Title->setText(QApplication::translate("D_StepWindow", "Change Title", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Change_Title->setShortcut(QApplication::translate("D_StepWindow", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        action_Features_Visualisation->setText(QApplication::translate("D_StepWindow", "Features Visualisation", nullptr));
        action_SaveScreenshot->setText(QApplication::translate("D_StepWindow", "Save Screenshot", nullptr));
#ifndef QT_NO_SHORTCUT
        action_SaveScreenshot->setShortcut(QApplication::translate("D_StepWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Measure_Line_Distance->setText(QApplication::translate("D_StepWindow", "Line Distance", nullptr));
        action_Save_Feature_List->setText(QApplication::translate("D_StepWindow", "Feature Matrix", nullptr));
        action_connect_plane_position_to_other_steps->setText(QApplication::translate("D_StepWindow", "Connect Steps Plane Position", nullptr));
        action_Connect_Steps_Zoom->setText(QApplication::translate("D_StepWindow", "Connect Steps Zoom", nullptr));
        action_Zoom_In->setText(QApplication::translate("D_StepWindow", "Zoom In (Crtl+Left)", nullptr));
        action_Zoom_Out->setText(QApplication::translate("D_StepWindow", "Zoom Out (Crtl+Right)", nullptr));
        action_Zoom_Reset->setText(QApplication::translate("D_StepWindow", "Zoom Reset (Ctrl+Mid)", nullptr));
        action_Save_Analysis->setText(QApplication::translate("D_StepWindow", "Feature Analysis", nullptr));
        action_Save_Image_List->setText(QApplication::translate("D_StepWindow", "Save Image List", nullptr));
        action_Save_asBinary->setText(QApplication::translate("D_StepWindow", "Save Full 6D Image as Binary File", nullptr));
        groupBox_Settings->setTitle(QApplication::translate("D_StepWindow", "Settings", nullptr));
        label_00_Load__Dim_Target->setText(QApplication::translate("D_StepWindow", "Target Dim.", nullptr));
        label_00_Load_Pages->setText(QApplication::translate("D_StepWindow", "Pages", nullptr));
        label_00_Load_Dim_Source->setText(QApplication::translate("D_StepWindow", "Source Dim.", nullptr));
        label_00_Load_X_Img->setText(QApplication::translate("D_StepWindow", "X Image", nullptr));
        pushButton_00_Load_Image->setText(QApplication::translate("D_StepWindow", "Select Path", nullptr));
        label_00_Load_List->setText(QApplication::translate("D_StepWindow", "List", nullptr));
        label_00_Load_Browse->setText(QApplication::translate("D_StepWindow", "Browse", nullptr));
        label_00_Load_Mode->setText(QApplication::translate("D_StepWindow", "Mode", nullptr));
        label_00_Load_Y_Img->setText(QApplication::translate("D_StepWindow", "Y Image", nullptr));
        label_2->setText(QApplication::translate("D_StepWindow", "Time", nullptr));
        checkBox_00_Load_Force8UC1->setText(QApplication::translate("D_StepWindow", "Force 8 bit 1 channel", nullptr));
        pushButton_00_Sample_Select_Directory->setText(QApplication::translate("D_StepWindow", "Select Directory", nullptr));
        label_00_Sample_Directory->setText(QApplication::translate("D_StepWindow", "Example Directory", nullptr));
        label_00_Generate_DimVar->setText(QApplication::translate("D_StepWindow", "Parametric Dims", nullptr));
        label_00_Generate_Size->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        comboBox_00_Generate_DimVar->setItemText(0, QApplication::translate("D_StepWindow", "2 as Variables (Real)", nullptr));
        comboBox_00_Generate_DimVar->setItemText(1, QApplication::translate("D_StepWindow", "2 as Variables (Complex)", nullptr));
        comboBox_00_Generate_DimVar->setItemText(2, QApplication::translate("D_StepWindow", "6 as Variables (Real)", nullptr));

        spinBox_00_Generate_Size_Z->setSuffix(QString());
        spinBox_00_Generate_Size_Z->setPrefix(QApplication::translate("D_StepWindow", "Z=", nullptr));
        spinBox_00_Generate_Size_Y->setSuffix(QString());
        spinBox_00_Generate_Size_Y->setPrefix(QApplication::translate("D_StepWindow", "Y=", nullptr));
        spinBox_00_Generate_Size_X->setPrefix(QApplication::translate("D_StepWindow", "X=", nullptr));
        spinBox_00_Generate_Size_T->setPrefix(QApplication::translate("D_StepWindow", "T=", nullptr));
        spinBox_00_Generate_Size_S->setPrefix(QApplication::translate("D_StepWindow", "S=", nullptr));
        spinBox_00_Generate_Size_P->setPrefix(QApplication::translate("D_StepWindow", "P=", nullptr));
        doubleSpinBox_00_Generate_2D_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_00_Generate_2D_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_00_Generate_2D_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        doubleSpinBox_00_Generate_2D_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_00_Generate_2D_c->setSuffix(QString());
        doubleSpinBox_00_Generate_2D_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_00_Generate_2D_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_00_Generate_2D_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_00_Generate_2D_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        label_00_Generate_Parameters->setText(QApplication::translate("D_StepWindow", "Parameters", nullptr));
        label_00_Generate_ValuesFunction->setText(QApplication::translate("D_StepWindow", "Value Function", nullptr));
        label_00_Generate_Parameters_Complex->setText(QApplication::translate("D_StepWindow", "Parameters", nullptr));
        label_00_Generate_ValuesFunction_Complex->setText(QApplication::translate("D_StepWindow", "Value Function", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_sy->setPrefix(QApplication::translate("D_StepWindow", "sy=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_ox->setPrefix(QApplication::translate("D_StepWindow", "ox=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_oy->setPrefix(QApplication::translate("D_StepWindow", "oy=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_00_Generate_2D_Complex_c->setSuffix(QString());
        doubleSpinBox_00_Generate_2D_Complex_sx->setPrefix(QApplication::translate("D_StepWindow", "sx=", nullptr));
        label_00_Generate_ValueFunction_6D->setText(QApplication::translate("D_StepWindow", "Value Function", nullptr));
        label_00_Generate_Parameters_6D->setText(QApplication::translate("D_StepWindow", "Parameters", nullptr));
        doubleSpinBox_00_Generate_6D_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_00_Generate_6D_ox->setPrefix(QApplication::translate("D_StepWindow", "ox=", nullptr));
        doubleSpinBox_00_Generate_6D_oy->setPrefix(QApplication::translate("D_StepWindow", "oy=", nullptr));
        doubleSpinBox_00_Generate_6D_st->setPrefix(QApplication::translate("D_StepWindow", "st=", nullptr));
        doubleSpinBox_00_Generate_6D_sy->setPrefix(QApplication::translate("D_StepWindow", "sy=", nullptr));
        doubleSpinBox_00_Generate_6D_ot->setPrefix(QApplication::translate("D_StepWindow", "ot=", nullptr));
        doubleSpinBox_00_Generate_6D_sz->setPrefix(QApplication::translate("D_StepWindow", "sz=", nullptr));
        doubleSpinBox_00_Generate_6D_sx->setPrefix(QApplication::translate("D_StepWindow", "sx=", nullptr));
        doubleSpinBox_00_Generate_6D_nan->setPrefix(QApplication::translate("D_StepWindow", "nan=", nullptr));
        doubleSpinBox_00_Generate_6D_oz->setPrefix(QApplication::translate("D_StepWindow", "oz=", nullptr));
        doubleSpinBox_00_Generate_6D_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_00_Generate_6D_inf->setPrefix(QApplication::translate("D_StepWindow", "inf=", nullptr));
        doubleSpinBox_00_Generate_6D_sp->setPrefix(QApplication::translate("D_StepWindow", "sp=", nullptr));
        doubleSpinBox_00_Generate_6D_op->setPrefix(QApplication::translate("D_StepWindow", "op=", nullptr));
        doubleSpinBox_00_Generate_6D_ss->setPrefix(QApplication::translate("D_StepWindow", "ss=", nullptr));
        doubleSpinBox_00_Generate_6D_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_00_Generate_6D_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_00_Generate_6D_os->setPrefix(QApplication::translate("D_StepWindow", "os=", nullptr));
        doubleSpinBox_00_Generate_6D_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_00_Generate_6D_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        label_00_Generate_ScaleOffset->setText(QApplication::translate("D_StepWindow", "Scaling/Offset", nullptr));
        label_00_Generate_ScaleOffset_Description->setText(QApplication::translate("D_StepWindow", "(sx * x + ox)   ,   (sy * y + oy)   ,   ...", nullptr));
        label_00_Random_Parameters->setText(QApplication::translate("D_StepWindow", "Parameters", nullptr));
        label_00_Random_Distribution->setText(QApplication::translate("D_StepWindow", "Distribution", nullptr));
        doubleSpinBox_00_Random_Min->setPrefix(QApplication::translate("D_StepWindow", "min=", nullptr));
        doubleSpinBox_00_Random_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_00_Random_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_00_Random_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_00_Random_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_00_Random_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_00_Random_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_00_Random_Max->setPrefix(QApplication::translate("D_StepWindow", "max=", nullptr));
        label_00_Random_Range->setText(QApplication::translate("D_StepWindow", "Range", nullptr));
        label_8->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        spinBox_00_Random_Size_Z->setPrefix(QApplication::translate("D_StepWindow", "Z=", nullptr));
        spinBox_00_Random_Size_X->setSuffix(QString());
        spinBox_00_Random_Size_X->setPrefix(QApplication::translate("D_StepWindow", "X=", nullptr));
        spinBox_00_Random_Size_Y->setPrefix(QApplication::translate("D_StepWindow", "Y=", nullptr));
        spinBox_00_Random_Size_T->setPrefix(QApplication::translate("D_StepWindow", "T=", nullptr));
        spinBox_00_Random_Size_S->setPrefix(QApplication::translate("D_StepWindow", "S=", nullptr));
        spinBox_00_Random_Size_P->setPrefix(QApplication::translate("D_StepWindow", "P=", nullptr));
        label_00_CastRaw_Width->setText(QApplication::translate("D_StepWindow", "Width", nullptr));
        label_00_CastRaw_Path->setText(QApplication::translate("D_StepWindow", "Browse", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(0, QApplication::translate("D_StepWindow", "CV_8UC1", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(1, QApplication::translate("D_StepWindow", "CV_8SC1", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(2, QApplication::translate("D_StepWindow", "CV_16UC1", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(3, QApplication::translate("D_StepWindow", "CV_16SC1", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(4, QApplication::translate("D_StepWindow", "CV_32SC1", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(5, QApplication::translate("D_StepWindow", "CV_32FC1", nullptr));
        comboBox_00_CastRaw_BitPerPixel->setItemText(6, QApplication::translate("D_StepWindow", "CV_64FC1", nullptr));

        label_00_CastRaw_Height->setText(QApplication::translate("D_StepWindow", "Height", nullptr));
        label_00_CastRaw_Type->setText(QApplication::translate("D_StepWindow", "Bit per Pixel", nullptr));
        pushButton_00_CastRaw_Path->setText(QApplication::translate("D_StepWindow", "Select Path", nullptr));
        label_00_CastRaw_Channel->setText(QApplication::translate("D_StepWindow", "(1 Channel, Unsigned)", nullptr));
        label_00_VideoStream_File->setText(QApplication::translate("D_StepWindow", "File", nullptr));
        label_00_VideoStream_Combi_X->setText(QApplication::translate("D_StepWindow", "X: T-Frame 1", nullptr));
        label_00_VideoStream_T2->setText(QApplication::translate("D_StepWindow", "Time-Frame 2", nullptr));
        label_00_VideoStream_T1->setText(QApplication::translate("D_StepWindow", "Time-Frame 1", nullptr));
        label_00_VideoStream_Blur->setText(QApplication::translate("D_StepWindow", "Input Blur", nullptr));
        spinBox_00_VideoStream_T1_Frames->setSuffix(QApplication::translate("D_StepWindow", " frame", nullptr));
        spinBox_00_VideoStream_T2_Frames->setSuffix(QApplication::translate("D_StepWindow", " frames", nullptr));
        spinBox_00_VideoStream_T_Offset->setSuffix(QApplication::translate("D_StepWindow", " frames (center to center)", nullptr));
        doubleSpinBox_00_VideoStream_Blur_Sigma->setPrefix(QApplication::translate("D_StepWindow", "sigma = ", nullptr));
        spinBox_00_VideoStream_Blur_Size->setPrefix(QApplication::translate("D_StepWindow", "size = ", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_00_VideoStream_CombiFunction_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        checkBox_00_VideoStream_Force_8bit->setText(QApplication::translate("D_StepWindow", "Force 8bit Output", nullptr));
        label_00_VideoStream_Combi_Y->setText(QApplication::translate("D_StepWindow", "Y: T-Frame 2", nullptr));
        label_00_VideoStream_Offset->setText(QApplication::translate("D_StepWindow", "Offset", nullptr));
        label_00_VideoStream_Combi->setText(QApplication::translate("D_StepWindow", "Combination", nullptr));
        pushButton_00_VideoStream_Browse->setText(QApplication::translate("D_StepWindow", "Browse Video", nullptr));
        label_00_VideoStream_Path->setText(QString());
        label_01_Crop_Shape->setText(QApplication::translate("D_StepWindow", "Shape", nullptr));
        comboBox_01_Crop_Shape->setItemText(0, QApplication::translate("D_StepWindow", "Rect Relative", nullptr));
        comboBox_01_Crop_Shape->setItemText(1, QApplication::translate("D_StepWindow", "Rect Absolute", nullptr));
        comboBox_01_Crop_Shape->setItemText(2, QApplication::translate("D_StepWindow", "Rect Rotate", nullptr));
        comboBox_01_Crop_Shape->setItemText(3, QApplication::translate("D_StepWindow", "Circle", nullptr));

        label_01_Crop_Rect_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_01_Crop_Rect_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        label_01_Crop_Rect_1->setText(QApplication::translate("D_StepWindow", "Top Left", nullptr));
        label_01_Crop_Rect_2->setText(QApplication::translate("D_StepWindow", "Bottom Right", nullptr));
        label_01_Crop_Rect_Prz1->setText(QApplication::translate("D_StepWindow", "%", nullptr));
        label_01_Crop_Rect_Prz2->setText(QApplication::translate("D_StepWindow", "%", nullptr));
        label_01_Crop_RectAbs_Offset->setText(QApplication::translate("D_StepWindow", "Offset", nullptr));
        label_01_Crop_RectAbs_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        label_01_Crop_RectAbs_Size->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        label_01_Crop_RectAbs_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_01_Crop_RectAbs_Offset_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_RectAbs_Size_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_RectRot_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        label_01_Crop_RectRot_Size_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_RectRot_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_01_Crop_RectRot_Center->setText(QApplication::translate("D_StepWindow", "Center", nullptr));
        label_01_Crop_RectRot_Center_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_RectRot_Size->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        label_01_Crop_RectRot_Rotation_Unit->setText(QApplication::translate("D_StepWindow", "\302\260", nullptr));
        label_01_Crop_RectRot_Rotation->setText(QApplication::translate("D_StepWindow", "Rotation", nullptr));
        label_01_Crop_Circle_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        label_01_Crop_Circle_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_01_Crop_Circle_Center->setText(QApplication::translate("D_StepWindow", "Center", nullptr));
        label_01_Crop_Circle_Center_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_Circle_Radius->setText(QApplication::translate("D_StepWindow", "Radius", nullptr));
        label_01_Crop_Circle_Radius_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_Ellipse_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        label_01_Crop_Ellipse_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_01_Crop_Ellipse_Center->setText(QApplication::translate("D_StepWindow", "Center", nullptr));
        label_01_Crop_Ellipse_Center_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_Ellipse_Size->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        label_01_Crop_Ellipse_Size_Unit->setText(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_Crop_Ellipse_Rotation->setText(QApplication::translate("D_StepWindow", "Rotation", nullptr));
        label_01_Crop_Ellipse_Rotation_Unit->setText(QApplication::translate("D_StepWindow", "\302\260", nullptr));
        label_01_Floodfill_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        label_01_Floodfill_Delta_Seed->setText(QApplication::translate("D_StepWindow", "Seed x/y", nullptr));
        label_01_Floodfill_Delta_Delta->setText(QApplication::translate("D_StepWindow", "Delta", nullptr));
        label_13->setText(QApplication::translate("D_StepWindow", "Only call this on very small images or recursion", nullptr));
        label_14->setText(QApplication::translate("D_StepWindow", " limit will be reached and programm will crash!", nullptr));
        comboBox_01_Floodfill_Type->setItemText(0, QApplication::translate("D_StepWindow", "Border", nullptr));
        comboBox_01_Floodfill_Type->setItemText(1, QApplication::translate("D_StepWindow", "Delta on Grayvalues", nullptr));

        label_01_Floodfill_Fill->setText(QApplication::translate("D_StepWindow", "Value Fill", nullptr));
        label_01_Padding_Width_X->setText(QApplication::translate("D_StepWindow", "Border X", nullptr));
        label_01_Padding_Type->setText(QApplication::translate("D_StepWindow", "Border Type", nullptr));
        comboBox_01_Padding_Type->setItemText(0, QApplication::translate("D_StepWindow", "Default", nullptr));
        comboBox_01_Padding_Type->setItemText(1, QApplication::translate("D_StepWindow", "Constant", nullptr));
        comboBox_01_Padding_Type->setItemText(2, QApplication::translate("D_StepWindow", "Replicate", nullptr));
        comboBox_01_Padding_Type->setItemText(3, QApplication::translate("D_StepWindow", "Reflect", nullptr));
        comboBox_01_Padding_Type->setItemText(4, QApplication::translate("D_StepWindow", "Reflect 101", nullptr));

        label_01_Padding_Width_Z->setText(QApplication::translate("D_StepWindow", "Border Z", nullptr));
        label_01_Padding_Value->setText(QApplication::translate("D_StepWindow", "Border Value", nullptr));
        label_01_Padding_Width_Y->setText(QApplication::translate("D_StepWindow", "Border Y", nullptr));
        spinBox_01_ForceSize_Height->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        spinBox_01_ForceSize_Width->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        label_01_ForceSize_Width->setText(QApplication::translate("D_StepWindow", "Width", nullptr));
        label_01_ForceSize_Height->setText(QApplication::translate("D_StepWindow", "Height", nullptr));
        label_01_ForceSize_Border->setText(QApplication::translate("D_StepWindow", "Border", nullptr));
        comboBox_01_ForceSize_Border->setItemText(0, QApplication::translate("D_StepWindow", "Default", nullptr));
        comboBox_01_ForceSize_Border->setItemText(1, QApplication::translate("D_StepWindow", "Constant", nullptr));
        comboBox_01_ForceSize_Border->setItemText(2, QApplication::translate("D_StepWindow", "Replicate", nullptr));
        comboBox_01_ForceSize_Border->setItemText(3, QApplication::translate("D_StepWindow", "Reflect", nullptr));
        comboBox_01_ForceSize_Border->setItemText(4, QApplication::translate("D_StepWindow", "Reflect 101", nullptr));

        label_02_Color2Mono_Reduction->setText(QApplication::translate("D_StepWindow", "Reduction to:", nullptr));
        label_02_Color_HSL->setText(QApplication::translate("D_StepWindow", "HSV", nullptr));
        label_02_Color_BGR_1->setText(QApplication::translate("D_StepWindow", "BGR", nullptr));
        label_02_Color_Luv->setText(QApplication::translate("D_StepWindow", "Luv", nullptr));
        label_02_Color_RGB_1->setText(QApplication::translate("D_StepWindow", "RGB", nullptr));
        label_02_Color_Lab->setText(QApplication::translate("D_StepWindow", "Lab", nullptr));
        label_02_Color_Grey->setText(QApplication::translate("D_StepWindow", "Grey", nullptr));
        radioButton_02_Color_YCrCb_BGR->setText(QString());
        radioButton_02_Color_XYZ_BGR->setText(QString());
        radioButton_02_Color_RGB_BGR->setText(QString());
        radioButton_02_Color_HSL_BGR->setText(QString());
        label_02_Color_RGB_2->setText(QApplication::translate("D_StepWindow", "RGB", nullptr));
        radioButton_02_Color_Lab_BGR->setText(QString());
        radioButton_02_Color_HSV_BGR->setText(QString());
        radioButton_02_Color_Grey_BGR->setText(QString());
        label_02_Color_BGR_2->setText(QApplication::translate("D_StepWindow", "BGR", nullptr));
        radioButton_02_Color_Lab_RGB->setText(QString());
        radioButton_02_Color_BGR_RGB->setText(QString());
        radioButton_02_Color_HSV_RGB->setText(QString());
        radioButton_02_Color_Luv_BGR->setText(QString());
        radioButton_02_Color_HSL_RGB->setText(QString());
        radioButton_02_Color_Luv_RGB->setText(QString());
        radioButton_02_Color_Grey_RGB->setText(QString());
        radioButton_02_Color_XYZ_RGB->setText(QString());
        radioButton_02_Color_YCrCb_RGB->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_02_Color_HSV->setToolTip(QApplication::translate("D_StepWindow", "<html><head/><body><p>Full</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_02_Color_HSV->setText(QApplication::translate("D_StepWindow", "HSV", nullptr));
        label_02_Color_XYZ->setText(QApplication::translate("D_StepWindow", "XYZ", nullptr));
        label_02_Color_YCrCb->setText(QApplication::translate("D_StepWindow", "YCrCb", nullptr));
        comboBox_02_Color_Direction_Top->setItemText(0, QApplication::translate("D_StepWindow", "to", nullptr));
        comboBox_02_Color_Direction_Top->setItemText(1, QApplication::translate("D_StepWindow", "from", nullptr));

        radioButton_02_Color_RGB_RGB->setText(QString());
        _Color_BGR_BGR->setText(QString());
        comboBox_02_Color_Direction_Left->setItemText(0, QApplication::translate("D_StepWindow", "from", nullptr));
        comboBox_02_Color_Direction_Left->setItemText(1, QApplication::translate("D_StepWindow", "to", nullptr));

        label_02_Double_Description->setText(QApplication::translate("D_StepWindow", "Converts the format to double (No scaling).", nullptr));
        label_02_Depth_Maximum->setText(QApplication::translate("D_StepWindow", "Maximum", nullptr));
        label_02_Depth_Norm->setText(QApplication::translate("D_StepWindow", "Norm", nullptr));
        label_02_Depth_Minimum->setText(QApplication::translate("D_StepWindow", "Minimum", nullptr));
        comboBox_02_Depth_Type->setItemText(0, QApplication::translate("D_StepWindow", "CV_8U", nullptr));
        comboBox_02_Depth_Type->setItemText(1, QApplication::translate("D_StepWindow", "CV_16U", nullptr));
        comboBox_02_Depth_Type->setItemText(2, QApplication::translate("D_StepWindow", "CV_32S", nullptr));
        comboBox_02_Depth_Type->setItemText(3, QApplication::translate("D_StepWindow", "CV_32F", nullptr));

        label_02_Depth_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_02_Depth_Norm->setItemText(0, QApplication::translate("D_StepWindow", "Min Max", nullptr));

        label_02_Merge_Ch1->setText(QApplication::translate("D_StepWindow", "Channel 1", nullptr));
        label_02_Merge_Channels->setText(QApplication::translate("D_StepWindow", "Channels", nullptr));
        label_02_Merge_Ch0->setText(QApplication::translate("D_StepWindow", "Channel 0", nullptr));
        checkBox_02_Merge_Ch0->setText(QApplication::translate("D_StepWindow", "Source 1   -   Blue", nullptr));
        label_02_Merge_Ch2->setText(QApplication::translate("D_StepWindow", "Channel 2", nullptr));
        checkBox_02_Merge_Ch1->setText(QApplication::translate("D_StepWindow", "Source 2   -   Green", nullptr));
        checkBox_02_Merge_Ch3->setText(QApplication::translate("D_StepWindow", "Source 4   -   Alpha", nullptr));
        checkBox_02_Merge_Ch2->setText(QApplication::translate("D_StepWindow", "Source 3   -   Red", nullptr));
        label_02_Merge_Ch3->setText(QApplication::translate("D_StepWindow", "Channel 3", nullptr));
        label_02_Split_Channel->setText(QApplication::translate("D_StepWindow", "Grab Channel", nullptr));
        label_02_Combi_Format->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_02_Combi_Type->setItemText(0, QApplication::translate("D_StepWindow", "8UC1 binary", nullptr));

        label_02_Angle2Color_V->setText(QApplication::translate("D_StepWindow", "Value", nullptr));
        label_02_Angle2Color_H->setText(QApplication::translate("D_StepWindow", "Hue", nullptr));
        label_02_Angle2Color_S->setText(QApplication::translate("D_StepWindow", "Saturation", nullptr));
        comboBox_02_Angle2Color_Mode->setItemText(0, QApplication::translate("D_StepWindow", "Angle (Rad)", nullptr));

        label_03_Thres_Otsu->setText(QApplication::translate("D_StepWindow", "Threshold at minimum between fore- and backgroundpeak in hist.", nullptr));
        label_03_Thres_Thres_Value->setText(QApplication::translate("D_StepWindow", "Thres Value", nullptr));
        label_03_Thres_Real_Thres->setText(QApplication::translate("D_StepWindow", "Thres Value", nullptr));
        doubleSpinBox_03_Thres_Rel_Thres_Rel->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        label_03_Thres_Rel_Base->setText(QApplication::translate("D_StepWindow", "Base Value", nullptr));
        label_03_Thres_Adapt_Offset->setText(QApplication::translate("D_StepWindow", "Const. Offset", nullptr));
        comboBox_03_Thres_Adapt_Type->setItemText(0, QApplication::translate("D_StepWindow", "Mean", nullptr));
        comboBox_03_Thres_Adapt_Type->setItemText(1, QApplication::translate("D_StepWindow", "Gaussian", nullptr));

        label_03_Thres_Adapt_Type->setText(QApplication::translate("D_StepWindow", "Adapt Type", nullptr));
        label_03_Thres_Mask_Size->setText(QApplication::translate("D_StepWindow", "Mask Size", nullptr));
        comboBox_03_Thres_Type->setItemText(0, QApplication::translate("D_StepWindow", "Automatic Otsu", nullptr));
        comboBox_03_Thres_Type->setItemText(1, QApplication::translate("D_StepWindow", "Manual Absolute", nullptr));
        comboBox_03_Thres_Type->setItemText(2, QApplication::translate("D_StepWindow", "Manual Relative", nullptr));
        comboBox_03_Thres_Type->setItemText(3, QApplication::translate("D_StepWindow", "Local Adaptive", nullptr));

        comboBox_03_Thres_Output_Mode->setItemText(0, QApplication::translate("D_StepWindow", "Thres. Bin.", nullptr));
        comboBox_03_Thres_Output_Mode->setItemText(1, QApplication::translate("D_StepWindow", "Thres. Bin. Inv.", nullptr));
        comboBox_03_Thres_Output_Mode->setItemText(2, QApplication::translate("D_StepWindow", "Trunc.", nullptr));
        comboBox_03_Thres_Output_Mode->setItemText(3, QApplication::translate("D_StepWindow", "Trunc. to 0", nullptr));
        comboBox_03_Thres_Output_Mode->setItemText(4, QApplication::translate("D_StepWindow", "Trunc. to 0 Inv.", nullptr));

        label_03_Thres_Max_Value->setText(QApplication::translate("D_StepWindow", "Maximum Value", nullptr));
        label_03_Thres_Output_Type->setText(QApplication::translate("D_StepWindow", "Output", nullptr));
        label_03_Thres_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        label_03_Labeling_Depth->setText(QApplication::translate("D_StepWindow", "Depth", nullptr));
        label_03_Labeling_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_03_Labeling_Type->setItemText(0, QApplication::translate("D_StepWindow", "Connected Components", nullptr));

        comboBox_03_Labeling_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_03_Labeling_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_03_Labeling_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        comboBox_03_Labeling_Depth->setItemText(0, QApplication::translate("D_StepWindow", "CV_32S", nullptr));
        comboBox_03_Labeling_Depth->setItemText(1, QApplication::translate("D_StepWindow", "CV_16U", nullptr));

        label_03_ShadeCorr_Dst_Titel->setText(QApplication::translate("D_StepWindow", "Destination:", nullptr));
        label_03_ShadeCorr_Src2_Titel->setText(QApplication::translate("D_StepWindow", "Source 2:", nullptr));
        label_03_ShadeCorr_Src1_Titel->setText(QApplication::translate("D_StepWindow", "Source 1:", nullptr));
        label_03_ShadeCorr_Src1_Descr->setText(QApplication::translate("D_StepWindow", "Shaded image.", nullptr));
        label_03_ShadeCorr_Src2_Descr->setText(QApplication::translate("D_StepWindow", "Reference image.", nullptr));
        label_03_ShadeCorr_Dst_Descr->setText(QApplication::translate("D_StepWindow", "(Shaded * Reference_Mean) / Reference", nullptr));
        label_03_GrabColor_Ch2_Max->setText(QApplication::translate("D_StepWindow", "Max", nullptr));
        comboBox_03_GrabColor_ColorSpace->setItemText(0, QApplication::translate("D_StepWindow", "BGR", nullptr));
        comboBox_03_GrabColor_ColorSpace->setItemText(1, QApplication::translate("D_StepWindow", "XYZ", nullptr));
        comboBox_03_GrabColor_ColorSpace->setItemText(2, QApplication::translate("D_StepWindow", "YCrCb", nullptr));
        comboBox_03_GrabColor_ColorSpace->setItemText(3, QApplication::translate("D_StepWindow", "HSV", nullptr));
        comboBox_03_GrabColor_ColorSpace->setItemText(4, QApplication::translate("D_StepWindow", "Lab", nullptr));
        comboBox_03_GrabColor_ColorSpace->setItemText(5, QApplication::translate("D_StepWindow", "Luv", nullptr));

        label_03_GrabColor_Ch2_Min->setText(QApplication::translate("D_StepWindow", "Min", nullptr));
        label_03_GrabColor_Ch3_Min->setText(QApplication::translate("D_StepWindow", "Min", nullptr));
        label_03_GrabColor_Ch3_Max->setText(QApplication::translate("D_StepWindow", "Max", nullptr));
        comboBox_03_GrabColor_Output->setItemText(0, QApplication::translate("D_StepWindow", "Binary", nullptr));
        comboBox_03_GrabColor_Output->setItemText(1, QApplication::translate("D_StepWindow", "Mask", nullptr));

        label_03_GrabColor_Output->setText(QApplication::translate("D_StepWindow", "Output Selcted", nullptr));
        label_03_GrabColor_Ch1_Min->setText(QApplication::translate("D_StepWindow", "Min", nullptr));
        label_03_GrabColor_Ch1_Max->setText(QApplication::translate("D_StepWindow", "Max", nullptr));
        label_03_GrabColor_Ch1->setText(QApplication::translate("D_StepWindow", "Blue", nullptr));
        label_03_GrabColor_Ch2->setText(QApplication::translate("D_StepWindow", "Green", nullptr));
        label_03_GrabColor_Ch3->setText(QApplication::translate("D_StepWindow", "Red", nullptr));
#ifndef QT_NO_TOOLTIP
        label_03_GrabColor_ColorSpace->setToolTip(QApplication::translate("D_StepWindow", "<html><head/><body><p>BGR (openCV standard) expected as input</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_03_GrabColor_ColorSpace->setText(QApplication::translate("D_StepWindow", "Color Space", nullptr));
        label_03_FillHoles_Description->setText(QApplication::translate("D_StepWindow", "Fills all holes not connected to the border", nullptr));
        label_04_Blur_Size_XY->setText(QApplication::translate("D_StepWindow", "Size X/Y", nullptr));
        label_04_Blur_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_04_Blur_Type->setItemText(0, QApplication::translate("D_StepWindow", "Mean", nullptr));
        comboBox_04_Blur_Type->setItemText(1, QApplication::translate("D_StepWindow", "Root Mean Square", nullptr));
        comboBox_04_Blur_Type->setItemText(2, QApplication::translate("D_StepWindow", "Gaussian", nullptr));
        comboBox_04_Blur_Type->setItemText(3, QApplication::translate("D_StepWindow", "Median OpenCV", nullptr));
        comboBox_04_Blur_Type->setItemText(4, QApplication::translate("D_StepWindow", "Median Custom", nullptr));

        label_04_Blur_Size->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        label_04_Blur_Sigma_XY->setText(QApplication::translate("D_StepWindow", "Sigma X/Y", nullptr));
        label_04_Blur_Depth->setText(QApplication::translate("D_StepWindow", "Depth", nullptr));
        comboBox_04_Blur_Depth->setItemText(0, QApplication::translate("D_StepWindow", "from Source", nullptr));

        label_04_Blur_Normalized->setText(QApplication::translate("D_StepWindow", "Normalized", nullptr));
        checkBox_04_Blur_Normalized->setText(QString());
        label_04_Edge_Thesh->setText(QApplication::translate("D_StepWindow", "Thresh low/high", nullptr));
        label_04_Edge_Size->setText(QApplication::translate("D_StepWindow", "Size", nullptr));
        label_04_Edge_Scale->setText(QApplication::translate("D_StepWindow", "scale", nullptr));
        comboBox_04_Edge_Type->setItemText(0, QApplication::translate("D_StepWindow", "Laplace", nullptr));
        comboBox_04_Edge_Type->setItemText(1, QApplication::translate("D_StepWindow", "Sobel", nullptr));
        comboBox_04_Edge_Type->setItemText(2, QApplication::translate("D_StepWindow", "Scharr", nullptr));
        comboBox_04_Edge_Type->setItemText(3, QApplication::translate("D_StepWindow", "Canny", nullptr));

        label_04_Edge_Delta->setText(QApplication::translate("D_StepWindow", "delta", nullptr));
        label_04_Edge_dXdY->setText(QApplication::translate("D_StepWindow", "dx / dy", nullptr));
        label_04_Edge_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        label_04_Edge_Depth->setText(QApplication::translate("D_StepWindow", "Depth", nullptr));
        comboBox_04_Edge_Depth->setItemText(0, QApplication::translate("D_StepWindow", "from Source", nullptr));

        label_04_Edge_Options->setText(QApplication::translate("D_StepWindow", "Options", nullptr));
        checkBox_04_Edge_L2_Gradient->setText(QApplication::translate("D_StepWindow", "L2 Gradient", nullptr));
        label_04_Special_Depth->setText(QApplication::translate("D_StepWindow", "Depth", nullptr));
        comboBox_04_Special_Type->setItemText(0, QApplication::translate("D_StepWindow", "Bilateral", nullptr));
        comboBox_04_Special_Type->setItemText(1, QApplication::translate("D_StepWindow", "Gabor", nullptr));

        label_04_Special_Diameter->setText(QApplication::translate("D_StepWindow", "Diameter", nullptr));
        label_04_Special_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        label_04_Special_Sigma_Color->setText(QApplication::translate("D_StepWindow", "Sigma Color", nullptr));
        label_04_Special_Sigma_Space->setText(QApplication::translate("D_StepWindow", "Sigma Space", nullptr));
        label_04_Special_Lambda->setText(QApplication::translate("D_StepWindow", "Lambda", nullptr));
        label_04_Special_Sigma->setText(QApplication::translate("D_StepWindow", "Sigma", nullptr));
        label_04_Special_Psi->setText(QApplication::translate("D_StepWindow", "Psi", nullptr));
        label_04_Special_Theta->setText(QApplication::translate("D_StepWindow", "Theta", nullptr));
        label_04_Special_Delta->setText(QApplication::translate("D_StepWindow", "Delta", nullptr));
        label_04_Special_Gamma->setText(QApplication::translate("D_StepWindow", "Gamma", nullptr));
        label_04_Special_Size_XY->setText(QApplication::translate("D_StepWindow", "Size X/Y", nullptr));
        comboBox_04_Special_Depth->setItemText(0, QApplication::translate("D_StepWindow", "CV_32F", nullptr));
        comboBox_04_Special_Depth->setItemText(1, QApplication::translate("D_StepWindow", "CV_64F", nullptr));

        label_04_Eilenstein_Size->setText(QApplication::translate("D_StepWindow", "Size X/Y", nullptr));
        label_04_Eilenstein_Comparator->setText(QApplication::translate("D_StepWindow", "Comparator", nullptr));
        checkBox_04_Eilenstein_Normalized->setText(QString());
        label_04_Eilenstein_Normalized->setText(QApplication::translate("D_StepWindow", "Normalized", nullptr));
        label_04_Eilenstein_Delta->setText(QApplication::translate("D_StepWindow", "Delta", nullptr));
        comboBox_04_Eilenstein_Comparator->setItemText(0, QApplication::translate("D_StepWindow", "==", nullptr));
        comboBox_04_Eilenstein_Comparator->setItemText(1, QApplication::translate("D_StepWindow", ">", nullptr));
        comboBox_04_Eilenstein_Comparator->setItemText(2, QApplication::translate("D_StepWindow", ">=", nullptr));
        comboBox_04_Eilenstein_Comparator->setItemText(3, QApplication::translate("D_StepWindow", "<", nullptr));
        comboBox_04_Eilenstein_Comparator->setItemText(4, QApplication::translate("D_StepWindow", "<=", nullptr));
        comboBox_04_Eilenstein_Comparator->setItemText(5, QApplication::translate("D_StepWindow", "!=", nullptr));

        label_04_Eilenstein_Response_Title->setText(QApplication::translate("D_StepWindow", "Stat Responses", nullptr));
        label_04_Eilenstein_PixelCenter_Y->setText(QApplication::translate("D_StepWindow", "Y: Center-Value", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_04_Eilenstein_PixelCenter_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        label_04_Eilenstein_PixelCenter_X->setText(QApplication::translate("D_StepWindow", "X: Pixel-Value", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_04_Eilenstein_PixelMask_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        label_04_Eilenstein_PixelMask_Y->setText(QApplication::translate("D_StepWindow", "Y:Mask-Value", nullptr));
        label_04_Eilenstein_PixelMask_X->setText(QApplication::translate("D_StepWindow", "X:Pixel-Result", nullptr));
        label_04_Eilenstein_PixelCenter_Titel->setText(QApplication::translate("D_StepWindow", "Respones", nullptr));
        label_04_Eilenstein_PixelMask_Title->setText(QApplication::translate("D_StepWindow", "Weights", nullptr));
        label_04_Eilenstein_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_04_Eilenstein_Type->setItemText(0, QApplication::translate("D_StepWindow", "Comparators", nullptr));
        comboBox_04_Eilenstein_Type->setItemText(1, QApplication::translate("D_StepWindow", "Generalized", nullptr));

        label_04_Function_f_f2_y->setText(QApplication::translate("D_StepWindow", "mask", nullptr));
        label_04_Function_f_f4_x->setText(QApplication::translate("D_StepWindow", "f3", nullptr));
        label_04_Function_f_f2_x->setText(QApplication::translate("D_StepWindow", "f1", nullptr));
        label_04_Function_f_f1_y->setText(QApplication::translate("D_StepWindow", "image", nullptr));
        label_04_Function_f_f4_y->setText(QApplication::translate("D_StepWindow", "center", nullptr));
        label_04_Function_f_f3->setText(QApplication::translate("D_StepWindow", "f3: ", nullptr));
        label_04_Function_f_y->setText(QApplication::translate("D_StepWindow", "y", nullptr));
        label_04_Function_f_f1->setText(QApplication::translate("D_StepWindow", "f1: ", nullptr));
        label_04_Function_f_f4->setText(QApplication::translate("D_StepWindow", "f4: ", nullptr));
        label_04_Function_f_f2->setText(QApplication::translate("D_StepWindow", "f2: ", nullptr));
        label_04_Function_f_f1_x->setText(QApplication::translate("D_StepWindow", "center", nullptr));
        label_04_Function_f_x->setText(QApplication::translate("D_StepWindow", "x", nullptr));
        label_04_Function_f_f3_data->setText(QApplication::translate("D_StepWindow", "results of f2 loop", nullptr));
        label_04_Function_f_prototype->setText(QApplication::translate("D_StepWindow", "function prototype", nullptr));
        checkBox_04_Function_OnlyNonZero->setText(QApplication::translate("D_StepWindow", "Only consider areas where mask is not 0", nullptr));
        label_04_Function_inf->setText(QApplication::translate("D_StepWindow", "+/- inf", nullptr));
        label_04_Function_nan->setText(QApplication::translate("D_StepWindow", "nan", nullptr));
        label_04_Function_f->setText(QApplication::translate("D_StepWindow", "f", nullptr));
        label_04_Function_e->setText(QApplication::translate("D_StepWindow", "e", nullptr));
        label_04_Function_d->setText(QApplication::translate("D_StepWindow", "d", nullptr));
        label_04_Function_c->setText(QApplication::translate("D_StepWindow", "c", nullptr));
        label_04_Function_b->setText(QApplication::translate("D_StepWindow", "b", nullptr));
        label_04_Function_f4->setText(QApplication::translate("D_StepWindow", "f4: ", nullptr));
        label_04_Function_f2->setText(QApplication::translate("D_StepWindow", "f2: ", nullptr));
        label_04_Function_f1->setText(QApplication::translate("D_StepWindow", "f1: ", nullptr));
        label_04_Function_a->setText(QApplication::translate("D_StepWindow", "a", nullptr));
        label_04_RankOrder_MaskType->setText(QApplication::translate("D_StepWindow", "Mask Type", nullptr));
        label_04_RankOrder_Stat->setText(QApplication::translate("D_StepWindow", "Quantil", nullptr));
        doubleSpinBox_04_RankOrder_Quantil->setPrefix(QString());
        doubleSpinBox_04_RankOrder_Quantil->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        label_04_RankOrder_Radius->setText(QApplication::translate("D_StepWindow", "Radius", nullptr));
        label_04_RankOrder_Size->setText(QApplication::translate("D_StepWindow", "Size x/y", nullptr));
        label_04_Statistic_Stat->setText(QApplication::translate("D_StepWindow", "Statistic", nullptr));
        label_04_Statistic_MaskType->setText(QApplication::translate("D_StepWindow", "Mask Type", nullptr));
        label_04_Statistic_Radius->setText(QApplication::translate("D_StepWindow", "Radius", nullptr));
        label_04_Statistic_Size->setText(QApplication::translate("D_StepWindow", "Size x/y", nullptr));
        label_04_Border_Type->setText(QApplication::translate("D_StepWindow", "      Border Type", nullptr));
        comboBox_04_Border_Type->setItemText(0, QApplication::translate("D_StepWindow", "Default", nullptr));
        comboBox_04_Border_Type->setItemText(1, QApplication::translate("D_StepWindow", "Constant", nullptr));
        comboBox_04_Border_Type->setItemText(2, QApplication::translate("D_StepWindow", "Replicate", nullptr));
        comboBox_04_Border_Type->setItemText(3, QApplication::translate("D_StepWindow", "Reflect", nullptr));
        comboBox_04_Border_Type->setItemText(4, QApplication::translate("D_StepWindow", "Reflect 101", nullptr));

        checkBox_04_Force_8bit->setText(QApplication::translate("D_StepWindow", "Force 8bit", nullptr));
        label_05_Elem_Border_Type->setText(QApplication::translate("D_StepWindow", "Border", nullptr));
        label_05_Elem_Morph_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_05_Elem_Elem_Type->setItemText(0, QApplication::translate("D_StepWindow", "Rectangle", nullptr));
        comboBox_05_Elem_Elem_Type->setItemText(1, QApplication::translate("D_StepWindow", "Cross", nullptr));
        comboBox_05_Elem_Elem_Type->setItemText(2, QApplication::translate("D_StepWindow", "Ellipse", nullptr));

        label_05_Elem_Elem_Type->setText(QApplication::translate("D_StepWindow", "Shape", nullptr));
        label_05_Elem_Elem_Size->setText(QApplication::translate("D_StepWindow", "Size X/Y", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(0, QApplication::translate("D_StepWindow", "Erosion", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(1, QApplication::translate("D_StepWindow", "Dilation", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(2, QApplication::translate("D_StepWindow", "Opening", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(3, QApplication::translate("D_StepWindow", "Closing", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(4, QApplication::translate("D_StepWindow", "Gradient", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(5, QApplication::translate("D_StepWindow", "Top Hat", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(6, QApplication::translate("D_StepWindow", "Black Hat", nullptr));
        comboBox_05_Elem_Morph_Type->setItemText(7, QApplication::translate("D_StepWindow", "Skeleton", nullptr));

        comboBox_05_Elem_Border_Type->setItemText(0, QApplication::translate("D_StepWindow", "Default", nullptr));
        comboBox_05_Elem_Border_Type->setItemText(1, QApplication::translate("D_StepWindow", "Constant", nullptr));
        comboBox_05_Elem_Border_Type->setItemText(2, QApplication::translate("D_StepWindow", "Replicate", nullptr));
        comboBox_05_Elem_Border_Type->setItemText(3, QApplication::translate("D_StepWindow", "Reflect", nullptr));
        comboBox_05_Elem_Border_Type->setItemText(4, QApplication::translate("D_StepWindow", "Reflect 101", nullptr));

        label_05_Elem_Iterations->setText(QApplication::translate("D_StepWindow", "Iterations", nullptr));
        comboBox_05_MinMaxGil_MinMax->setItemText(0, QApplication::translate("D_StepWindow", "Maximum", nullptr));
        comboBox_05_MinMaxGil_MinMax->setItemText(1, QApplication::translate("D_StepWindow", "Minimum", nullptr));

        label_05_MinMaxGil_MinMax->setText(QApplication::translate("D_StepWindow", "Min/Max", nullptr));
        label_05_MinMaxGil_Size->setText(QApplication::translate("D_StepWindow", "Size x/y", nullptr));
        label_05_Reconstruction_Limit_Header->setText(QApplication::translate("D_StepWindow", "Recon. Limit", nullptr));
        label_05_Reconstruction_Elem_Header->setText(QApplication::translate("D_StepWindow", "Structing Elem.", nullptr));
        label_05_Reconstruction_Limit_Source->setText(QApplication::translate("D_StepWindow", "Source 2", nullptr));
        label_05_Reconstruction_Elem_Source->setText(QApplication::translate("D_StepWindow", "Source 3", nullptr));
        label_05_Reconstruction_Seed_Source->setText(QApplication::translate("D_StepWindow", "Source 1", nullptr));
        label_05_Reconstruction_Seed_Header->setText(QApplication::translate("D_StepWindow", "Seed", nullptr));
        label_05_Reconstruction_Quantil->setText(QApplication::translate("D_StepWindow", "Quantil", nullptr));
        doubleSpinBox_05_Reconstruction_Quantil->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        label_05_LocalMaxima_Size->setText(QApplication::translate("D_StepWindow", "Size X/Y", nullptr));
        label_06_1Img_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_06_1Img_Type->setItemText(0, QApplication::translate("D_StepWindow", "! Not", nullptr));
        comboBox_06_1Img_Type->setItemText(1, QApplication::translate("D_StepWindow", "+ Addition", nullptr));
        comboBox_06_1Img_Type->setItemText(2, QApplication::translate("D_StepWindow", "- Subtraction", nullptr));
        comboBox_06_1Img_Type->setItemText(3, QApplication::translate("D_StepWindow", "* Multiplication", nullptr));
        comboBox_06_1Img_Type->setItemText(4, QApplication::translate("D_StepWindow", "/ Division", nullptr));
        comboBox_06_1Img_Type->setItemText(5, QApplication::translate("D_StepWindow", "^ Power", nullptr));
        comboBox_06_1Img_Type->setItemText(6, QApplication::translate("D_StepWindow", "\342\210\232 Root (2)", nullptr));
        comboBox_06_1Img_Type->setItemText(7, QApplication::translate("D_StepWindow", "log Logarithm (e)", nullptr));

        label_06_1Img_Arg->setText(QApplication::translate("D_StepWindow", "Argument", nullptr));
        comboBox_06_2Img_Comparator->setItemText(0, QApplication::translate("D_StepWindow", "S1 == S2", nullptr));
        comboBox_06_2Img_Comparator->setItemText(1, QApplication::translate("D_StepWindow", "S1  >  S2", nullptr));
        comboBox_06_2Img_Comparator->setItemText(2, QApplication::translate("D_StepWindow", "S1 >= S2", nullptr));
        comboBox_06_2Img_Comparator->setItemText(3, QApplication::translate("D_StepWindow", "S1  <  S2", nullptr));
        comboBox_06_2Img_Comparator->setItemText(4, QApplication::translate("D_StepWindow", "S1 <= S2", nullptr));
        comboBox_06_2Img_Comparator->setItemText(5, QApplication::translate("D_StepWindow", "S1 != S2", nullptr));

        label_06_2Img_Weight_Sum->setText(QApplication::translate("D_StepWindow", "Weight Sum", nullptr));
        label_06_2Img_Weight_Source->setText(QApplication::translate("D_StepWindow", "Weight S1/S2", nullptr));
        label_06_2Img_Scale->setText(QApplication::translate("D_StepWindow", "Scale", nullptr));
        label_06_2Img_Comparator->setText(QApplication::translate("D_StepWindow", "Comparator", nullptr));
        label_06_2Img_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_06_2Img_Type->setItemText(0, QApplication::translate("D_StepWindow", "Addition", nullptr));
        comboBox_06_2Img_Type->setItemText(1, QApplication::translate("D_StepWindow", "Addition weighted", nullptr));
        comboBox_06_2Img_Type->setItemText(2, QApplication::translate("D_StepWindow", "Difference", nullptr));
        comboBox_06_2Img_Type->setItemText(3, QApplication::translate("D_StepWindow", "Difference absolute", nullptr));
        comboBox_06_2Img_Type->setItemText(4, QApplication::translate("D_StepWindow", "Multiplikation", nullptr));
        comboBox_06_2Img_Type->setItemText(5, QApplication::translate("D_StepWindow", "Division", nullptr));
        comboBox_06_2Img_Type->setItemText(6, QApplication::translate("D_StepWindow", "Bitwise and", nullptr));
        comboBox_06_2Img_Type->setItemText(7, QApplication::translate("D_StepWindow", "Bitwise or", nullptr));
        comboBox_06_2Img_Type->setItemText(8, QApplication::translate("D_StepWindow", "Bitwise xor", nullptr));
        comboBox_06_2Img_Type->setItemText(9, QApplication::translate("D_StepWindow", "Minimum", nullptr));
        comboBox_06_2Img_Type->setItemText(10, QApplication::translate("D_StepWindow", "Maximum", nullptr));
        comboBox_06_2Img_Type->setItemText(11, QApplication::translate("D_StepWindow", "Compare", nullptr));

        label_06_2ImgFunction_Function->setText(QApplication::translate("D_StepWindow", "Function", nullptr));
        label_06_2ImgFunction_Parameters->setText(QApplication::translate("D_StepWindow", "Parameters", nullptr));
        doubleSpinBox_06_2ImgFunction_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_06_2ImgFunction_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_06_2ImgFunction_c->setSuffix(QString());
        doubleSpinBox_06_2ImgFunction_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_06_2ImgFunction_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_06_2ImgFunction_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_06_2ImgFunction_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_06_2ImgFunction_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_06_2ImgFunction_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        checkBox_06_2ImgFunction_Force_8bit->setText(QString());
        label_06_2ImgFunction_Force_8bit->setText(QApplication::translate("D_StepWindow", "Force 8bit", nullptr));
        label_06_2ImgFunction_Complex_Function->setText(QApplication::translate("D_StepWindow", "Function", nullptr));
        label_06_2ImgFunction_Complex_Parameters->setText(QApplication::translate("D_StepWindow", "Parameters", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_c->setSuffix(QString());
        doubleSpinBox_06_2ImgFunction_Complex_oy->setPrefix(QApplication::translate("D_StepWindow", "oy=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_sx->setPrefix(QApplication::translate("D_StepWindow", "sx=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_nan->setPrefix(QApplication::translate("D_StepWindow", "nan: ", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_ox->setPrefix(QApplication::translate("D_StepWindow", "ox=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_inf->setPrefix(QApplication::translate("D_StepWindow", "inf: ", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_06_2ImgFunction_Complex_sy->setPrefix(QApplication::translate("D_StepWindow", "sy=", nullptr));
        label_06_3Img_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_06_3Img_Type->setItemText(0, QApplication::translate("D_StepWindow", "Addition", nullptr));
        comboBox_06_3Img_Type->setItemText(1, QApplication::translate("D_StepWindow", "Multiplication", nullptr));
        comboBox_06_3Img_Type->setItemText(2, QApplication::translate("D_StepWindow", "Bitwise And", nullptr));
        comboBox_06_3Img_Type->setItemText(3, QApplication::translate("D_StepWindow", "Bitwise Or", nullptr));

        label_06_3Img_Value->setText(QApplication::translate("D_StepWindow", "Value", nullptr));
        checkBox_06_3Img_Value->setText(QString());
        label_06_4Img_Type->setText(QApplication::translate("D_StepWindow", "Type", nullptr));
        comboBox_06_4Img_Type->setItemText(0, QApplication::translate("D_StepWindow", "Addition", nullptr));
        comboBox_06_4Img_Type->setItemText(1, QApplication::translate("D_StepWindow", "Multiplication", nullptr));
        comboBox_06_4Img_Type->setItemText(2, QApplication::translate("D_StepWindow", "Bitwise And", nullptr));
        comboBox_06_4Img_Type->setItemText(3, QApplication::translate("D_StepWindow", "Bitwise Or", nullptr));

        label_06_4Img_Value->setText(QApplication::translate("D_StepWindow", "Value", nullptr));
        checkBox_06_4Img_Value->setText(QString());
        label_07_Dist_Norm->setText(QApplication::translate("D_StepWindow", "Norm", nullptr));
        label_07_Dist_Precision->setText(QApplication::translate("D_StepWindow", "Precision", nullptr));
        comboBox_07_Dist_Precision->setItemText(0, QApplication::translate("D_StepWindow", "Precise", nullptr));
        comboBox_07_Dist_Precision->setItemText(1, QApplication::translate("D_StepWindow", "3x3", nullptr));
        comboBox_07_Dist_Precision->setItemText(2, QApplication::translate("D_StepWindow", "5x5", nullptr));

        comboBox_07_Dist_Metric->setItemText(0, QApplication::translate("D_StepWindow", "Euclidean", nullptr));
        comboBox_07_Dist_Metric->setItemText(1, QApplication::translate("D_StepWindow", "Taxi", nullptr));
        comboBox_07_Dist_Metric->setItemText(2, QApplication::translate("D_StepWindow", "Max of X and Y", nullptr));
        comboBox_07_Dist_Metric->setItemText(3, QApplication::translate("D_StepWindow", "L1-L2", nullptr));
        comboBox_07_Dist_Metric->setItemText(4, QApplication::translate("D_StepWindow", "Fair", nullptr));
        comboBox_07_Dist_Metric->setItemText(5, QApplication::translate("D_StepWindow", "Welsch", nullptr));
        comboBox_07_Dist_Metric->setItemText(6, QApplication::translate("D_StepWindow", "Huber", nullptr));

        comboBox_07_Watershed_Implementation->setItemText(0, QApplication::translate("D_StepWindow", "ImageD", nullptr));
        comboBox_07_Watershed_Implementation->setItemText(1, QApplication::translate("D_StepWindow", "OpenCV", nullptr));

        label_07_Watershed_Implementation->setText(QApplication::translate("D_StepWindow", "Implementation", nullptr));
        comboBox_07_WatershedCustom_Mask->setItemText(0, QApplication::translate("D_StepWindow", "Source 3 (8UC1)", nullptr));

        label_07_WatershedCustom_Connectivity_3->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        label_07_WatershedCustom_Border->setText(QApplication::translate("D_StepWindow", "Excl. Border", nullptr));
        comboBox_07_WatershedCustom_Flood->setItemText(0, QApplication::translate("D_StepWindow", "Source 1 (C1, no 32F, no 64F)", nullptr));

        label_07_WatershedCustom_NonSeed->setText(QApplication::translate("D_StepWindow", "Incl. no seed", nullptr));
        label_07_WatershedCustom_Mask_3->setText(QApplication::translate("D_StepWindow", "Image Mask", nullptr));
        spinBox_07_WatershedCustom_Flood_GaussSize->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        spinBox_07_WatershedCustom_Flood_GaussSize->setPrefix(QApplication::translate("D_StepWindow", "size ", nullptr));
        doubleSpinBox_07_WatershedCustom_Flood_GaussSigma->setPrefix(QApplication::translate("D_StepWindow", "sigma ", nullptr));
        comboBox_07_WatershedCustom_Flood_Morph_Elem->setItemText(0, QApplication::translate("D_StepWindow", "Circle", nullptr));
        comboBox_07_WatershedCustom_Flood_Morph_Elem->setItemText(1, QApplication::translate("D_StepWindow", "Square", nullptr));

        spinBox_07_WatershedCustom_Flood_Morph_Size->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        spinBox_07_WatershedCustom_Flood_Morph_Size->setPrefix(QApplication::translate("D_StepWindow", "size ", nullptr));
        comboBox_07_WatershedCustom_Marker->setItemText(0, QApplication::translate("D_StepWindow", "Source 2 (32SC1 Labels)", nullptr));

        label_07_WatershedCustom_Marker_3->setText(QApplication::translate("D_StepWindow", "Image Marker", nullptr));
        label_07_WatershedCustom_Flood_3->setText(QApplication::translate("D_StepWindow", "Image Flood", nullptr));
        checkBox_07_WatershedCustom_IncludeNonSeed->setText(QString());
        comboBox_07_WatershedCustom_Marker_LabelNeighborhood->setItemText(0, QApplication::translate("D_StepWindow", "8 neighborhood", nullptr));
        comboBox_07_WatershedCustom_Marker_LabelNeighborhood->setItemText(1, QApplication::translate("D_StepWindow", "4 neighborhood", nullptr));

        comboBox_07_WatershedCustom_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "4 neighborhood", nullptr));
        comboBox_07_WatershedCustom_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "8 neighborhood", nullptr));

        checkBox_07_WatershedCustom_ExcludeBorder->setText(QString());
        doubleSpinBox_07_WatershedCustom_Mask_Thres->setPrefix(QApplication::translate("D_StepWindow", "thres ", nullptr));
        label_15->setText(QApplication::translate("D_StepWindow", "Draw watersh.", nullptr));
        checkBox_07_WatershedCustom_DrawWatershed->setText(QString());
        comboBox_07_WatershedCustom_DrawWatershed_Neighborhood->setItemText(0, QApplication::translate("D_StepWindow", "8 neighborhood", nullptr));
        comboBox_07_WatershedCustom_DrawWatershed_Neighborhood->setItemText(1, QApplication::translate("D_StepWindow", "4 neighborhood", nullptr));

        label_07_Watershed_8bit_Description->setText(QApplication::translate("D_StepWindow", "Convert Output to 8bit", nullptr));
        label_07_Watershed_8bit->setText(QApplication::translate("D_StepWindow", "8bit Output", nullptr));
        comboBox_07_Watershed_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_07_Watershed_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_07_Watershed_InclNonSeed_Description->setText(QApplication::translate("D_StepWindow", "Include non seeded labels too", nullptr));
        label_07_Watershed_Markers_Desription->setText(QApplication::translate("D_StepWindow", "CV_8UC1, binary marker", nullptr));
        label_07_Watershed_InclNonSeed->setText(QApplication::translate("D_StepWindow", "Incl. n. Seeded", nullptr));
        checkBox_07_Watershed_InclNonSeed->setText(QString());
        label_07_Watersehd_Input->setText(QApplication::translate("D_StepWindow", "Input", nullptr));
        label_07_Watershed_Markers_Source->setText(QApplication::translate("D_StepWindow", "Source 2", nullptr));
        label_07_Watershed_Auto_Description->setText(QApplication::translate("D_StepWindow", "Pure Watershed / aditional processing", nullptr));
        checkBox_07_Watershed_ExclBorder->setText(QString());
        label_07_Watershed_Input_Source->setText(QApplication::translate("D_StepWindow", "Source 1", nullptr));
        label_07_Watershed_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        label_07_Watershed_Markers->setText(QApplication::translate("D_StepWindow", "Markers", nullptr));
        label_07_Watershed_ExclBor->setText(QApplication::translate("D_StepWindow", "Excl. Border.", nullptr));
        checkBox_07_Watershed_8bit->setText(QString());
        label_07_Watershed_Input_Desciption->setText(QApplication::translate("D_StepWindow", "CV_8UC1, binary input", nullptr));
        label_07_Watershed_Auto->setText(QApplication::translate("D_StepWindow", "Automatic", nullptr));
        label_07_Watershed_Connectivity_2->setText(QApplication::translate("D_StepWindow", "Connectivity Output-Objects", nullptr));
        checkBox_07_Watershed_Auto->setText(QString());
        label_07_Watershed_ExclBorder_Description->setText(QApplication::translate("D_StepWindow", "Exclude Labels connected to border", nullptr));
        label_07_Fourier_Input_Complex->setText(QApplication::translate("D_StepWindow", "Complex input", nullptr));
        checkBox_07_Fourier_Output_Scale->setText(QString());
        checkBox_07_Fourier_Input_Complex->setText(QString());
        comboBox_07_Fourier_Output_ComplexMode->setItemText(0, QApplication::translate("D_StepWindow", "Absolute squared", nullptr));

        label_07_Fourier_Output_Centered->setText(QApplication::translate("D_StepWindow", "Out centered", nullptr));
        checkBox_07_Fourier_ForceFFT->setText(QString());
        label_07_Fourier_OptimalSize->setText(QApplication::translate("D_StepWindow", "Force FFT size", nullptr));
        checkBox_07_Fourier_Invers->setText(QString());
        checkBox_07_Fourier_Output_RealOnly->setText(QString());
        label_07_Fourier_Output_no_f0->setText(QApplication::translate("D_StepWindow", "Out no f=0", nullptr));
        label_07_Fourier_Output_ComplexMode->setText(QApplication::translate("D_StepWindow", "Out mode", nullptr));
        label_07_Fourier_Output_RealOnly->setText(QApplication::translate("D_StepWindow", "Out real only", nullptr));
        label_07_Fourier_Invers->setText(QApplication::translate("D_StepWindow", "Invers", nullptr));
        checkBox_07_Fourier_Output_Centered->setText(QString());
        checkBox_07_Fourier_Output_no_f0->setText(QString());
        label_07_Fourier_Output_Scale->setText(QApplication::translate("D_StepWindow", "Out scale", nullptr));
        label_08_FeatVal_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        comboBox_08_FeatVal_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_FeatVal_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_08_FeatVal_Feature->setText(QApplication::translate("D_StepWindow", "Feature", nullptr));
        label_08_FeatContextVal_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        comboBox_08_FeatContextVal_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_FeatContextVal_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_08_FeatContextVal_DistanceFrom->setText(QApplication::translate("D_StepWindow", "Distance From", nullptr));
        label_08_FeatContextVal_Feat->setText(QApplication::translate("D_StepWindow", "Feature", nullptr));
        label_08_FeatContextVal_Stat->setText(QApplication::translate("D_StepWindow", "Statistic", nullptr));
        label_08_FeatContextVal_DistanceRange->setText(QApplication::translate("D_StepWindow", "Distance Range", nullptr));
        label_08_FeatContextVal_DistanceTo->setText(QApplication::translate("D_StepWindow", "Distance To", nullptr));
        label_08_Select_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        label_08_Select_Range->setText(QApplication::translate("D_StepWindow", "Range", nullptr));
        comboBox_08_Select_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_Select_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_08_Select_Decimals->setText(QApplication::translate("D_StepWindow", "Dec. of Range", nullptr));
        label_08_Select_Step->setText(QApplication::translate("D_StepWindow", "Step of Range", nullptr));
        label_08_Select_Type->setText(QApplication::translate("D_StepWindow", "Feature", nullptr));
        comboBox_08_FeatContextSelect_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_FeatContextSelect_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_08_FeatContextSelect_Stat->setText(QApplication::translate("D_StepWindow", "Statistic", nullptr));
        label_08_FeatContextSelect_Range->setText(QApplication::translate("D_StepWindow", "Range", nullptr));
        label_08_FeatContextSelect_DistanceRange->setText(QApplication::translate("D_StepWindow", "Distance Range", nullptr));
        label_08_FeatContextSelect_Feat->setText(QApplication::translate("D_StepWindow", "Feature", nullptr));
        label_08_FeatContextSelect_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        label_08_FeatContextSelect_DistanceFrom->setText(QApplication::translate("D_StepWindow", "Distance From", nullptr));
        label_08_FeatContextSelectDistanceTo->setText(QApplication::translate("D_StepWindow", "Distance To", nullptr));
        label_08_Connect_Cond->setText(QApplication::translate("D_StepWindow", "Condition", nullptr));
        doubleSpinBox_08_Connect_Cond_h->setPrefix(QApplication::translate("D_StepWindow", "h=", nullptr));
        doubleSpinBox_08_Connect_Cond_e->setPrefix(QApplication::translate("D_StepWindow", "e=", nullptr));
        doubleSpinBox_08_Connect_Cond_c->setPrefix(QApplication::translate("D_StepWindow", "c=", nullptr));
        doubleSpinBox_08_Connect_Cond_a->setPrefix(QApplication::translate("D_StepWindow", "a=", nullptr));
        doubleSpinBox_08_Connect_Cond_d->setPrefix(QApplication::translate("D_StepWindow", "d=", nullptr));
        doubleSpinBox_08_Connect_Cond_d->setSuffix(QString());
        doubleSpinBox_08_Connect_Cond_g->setPrefix(QApplication::translate("D_StepWindow", "g=", nullptr));
        doubleSpinBox_08_Connect_Cond_f->setPrefix(QApplication::translate("D_StepWindow", "f=", nullptr));
        doubleSpinBox_08_Connect_Cond_b->setPrefix(QApplication::translate("D_StepWindow", "b=", nullptr));
        label_08_Connect_Object2_Feat->setText(QApplication::translate("D_StepWindow", "Feature Y", nullptr));
        label_08_Connect_Object1_Feat->setText(QApplication::translate("D_StepWindow", "Feature X", nullptr));
        label_08_Connect_DistanceFrom->setText(QApplication::translate("D_StepWindow", "Distance From", nullptr));
        label_08_Connect_Connectivity->setText(QApplication::translate("D_StepWindow", "Connect(ivity)", nullptr));
        label_08_Connect_DistanceTo->setText(QApplication::translate("D_StepWindow", "Distance To", nullptr));
        label_08_Connect_DistanceRange->setText(QApplication::translate("D_StepWindow", "Distance Range", nullptr));
        comboBox_08_Connect_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_Connect_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        spinBox_08_Connect_Thickness->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        label_08_Reduce_Type->setText(QApplication::translate("D_StepWindow", "Reduce to", nullptr));
        label_08_Reduce_Thickness->setText(QApplication::translate("D_StepWindow", "Thickness", nullptr));
        comboBox_08_Reduce_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_Reduce_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_08_Reduce_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        label_08_Reduce_Value->setText(QApplication::translate("D_StepWindow", "Value", nullptr));
        comboBox_08_Visualize_Connectivity->setItemText(0, QApplication::translate("D_StepWindow", "8", nullptr));
        comboBox_08_Visualize_Connectivity->setItemText(1, QApplication::translate("D_StepWindow", "4", nullptr));

        label_08_Visualize_Scale->setText(QApplication::translate("D_StepWindow", "Scale", nullptr));
        label_08_Visualize_Thickness->setText(QApplication::translate("D_StepWindow", "Thickness", nullptr));
        label_08_Visualize_Connectivity->setText(QApplication::translate("D_StepWindow", "Connectivity", nullptr));
        label_08_Visualize_Feature->setText(QApplication::translate("D_StepWindow", "Feature", nullptr));
        label_10->setText(QApplication::translate("D_StepWindow", "Quantile", nullptr));
        label_11->setText(QApplication::translate("D_StepWindow", "Feature Extract", nullptr));
        label_9->setText(QApplication::translate("D_StepWindow", "Feature Select", nullptr));
        label_12->setText(QApplication::translate("D_StepWindow", "Default Value", nullptr));
        doubleSpinBox_2->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        label_09_Equal_Hist_1->setText(QApplication::translate("D_StepWindow", "Equalize the histogram of 8bit single channel (CV_8UC1) image.", nullptr));
        label_09_Equal_Hist_2->setText(QApplication::translate("D_StepWindow", "Loss of information, but usefull to see detail in low contrast.", nullptr));
        label_09_GammaSpread_OutMax->setText(QApplication::translate("D_StepWindow", "Out Max", nullptr));
        label_09_GammaSpread_InMax->setText(QApplication::translate("D_StepWindow", "In Max", nullptr));
        label_09_GammaSpread_OutMin->setText(QApplication::translate("D_StepWindow", "Out Min", nullptr));
        label_09_GammaSpread_InMin->setText(QApplication::translate("D_StepWindow", "In Min", nullptr));
        label_09_GammaSpread_Gamma->setText(QApplication::translate("D_StepWindow", "Gamma", nullptr));
        label_09_GammaSpread_Force8bit->setText(QApplication::translate("D_StepWindow", "Force 8bit", nullptr));
        checkBox_09_GammaSpread_Force8bit->setText(QString());
        label_09_LabelNo_Src1_Title->setText(QApplication::translate("D_StepWindow", "Source 1:", nullptr));
        label_09_LabelNo_Src1_Desc->setText(QApplication::translate("D_StepWindow", "Original", nullptr));
        label_09_LabelNo_Src2_Title->setText(QApplication::translate("D_StepWindow", "Source 2:", nullptr));
        label_09_LabelNo_Src2_Desc->setText(QApplication::translate("D_StepWindow", "Label", nullptr));
        label_09_LabelNo_Scale->setText(QApplication::translate("D_StepWindow", "Scale", nullptr));
        label_09_LabelNo_Thickness->setText(QApplication::translate("D_StepWindow", "Thickness", nullptr));
        label_09_LabelNo_Position->setText(QApplication::translate("D_StepWindow", "Position", nullptr));
        checkBox_09_LabelNo_Position->setText(QApplication::translate("D_StepWindow", "Center", nullptr));
        label_09_LabelNo_Ch1_Title->setText(QApplication::translate("D_StepWindow", "1 / Blue:", nullptr));
        label_09_LabelNo_Ch1_Desc->setText(QApplication::translate("D_StepWindow", "Label-Numbers", nullptr));
        label_09_LabelNo_Ch2_Title->setText(QApplication::translate("D_StepWindow", "2 / Green:", nullptr));
        label_09_LabelNo_Ch2_Desc->setText(QApplication::translate("D_StepWindow", "Label-Edges", nullptr));
        label_09_LabelNo_Ch3_Title->setText(QApplication::translate("D_StepWindow", "3 / Red:", nullptr));
        label_09_LabelNo_Ch3_Desc->setText(QApplication::translate("D_StepWindow", "Original", nullptr));
        label_09_NeighborhoodConfig_Euler_Description->setText(QApplication::translate("D_StepWindow", "Euler-Number:", nullptr));
        label_09_NeighborhoodConfig_Euler_Number->setText(QApplication::translate("D_StepWindow", "-", nullptr));
        label_09_NeighborhoodConfig->setText(QApplication::translate("D_StepWindow", "3D Pixelneighborhood Configurations", nullptr));
        label_09_MotionField_SizeSpace->setText(QApplication::translate("D_StepWindow", "Size Space", nullptr));
        label_09_MotionField_SizeTime->setText(QApplication::translate("D_StepWindow", "Size Time", nullptr));
        label_3->setText(QApplication::translate("D_StepWindow", "n", nullptr));
        label_4->setText(QApplication::translate("D_StepWindow", "Classes 0", nullptr));
        label_5->setText(QApplication::translate("D_StepWindow", "Classes 1", nullptr));
        label_6->setText(QApplication::translate("D_StepWindow", "Source 2 (red)", nullptr));
        label_7->setText(QApplication::translate("D_StepWindow", "Source 1 (blue)", nullptr));
        label_09_HDR_Dimension->setText(QApplication::translate("D_StepWindow", "Dimension", nullptr));
        doubleSpinBox_09_HDR_Exposure_Min->setSuffix(QApplication::translate("D_StepWindow", "us", nullptr));
        label_09_HDR_ExpFirst_Description->setText(QApplication::translate("D_StepWindow", "Exposure of first image", nullptr));
        comboBox_09_HDR_ProjectStat->setItemText(0, QApplication::translate("D_StepWindow", "Mean", nullptr));

        label_09_HDR_Project_Description->setText(QApplication::translate("D_StepWindow", "Project normed values", nullptr));
        label_09_HDR_Range_Description->setText(QApplication::translate("D_StepWindow", "Range of values to be valid", nullptr));
        label_09_HDR_Dim_Description->setText(QApplication::translate("D_StepWindow", "Dimension containing exposures", nullptr));
        label_09_HDR_Projection->setText(QApplication::translate("D_StepWindow", "Projection", nullptr));
        doubleSpinBox_09_HDR_Exposure_Factor->setPrefix(QApplication::translate("D_StepWindow", "x", nullptr));
        label_09_HDR_ExpFactor_Description->setText(QApplication::translate("D_StepWindow", "Exposure increase per layer", nullptr));
        label_09_HDR_Thres->setText(QApplication::translate("D_StepWindow", "Thresh", nullptr));
        comboBox_09_HDR_Dim->setItemText(0, QApplication::translate("D_StepWindow", "S", nullptr));

        label_09_HDR_Stat_Description->setText(QApplication::translate("D_StepWindow", "Statistical projection", nullptr));
        label_09_HDR_Thres_Description->setText(QApplication::translate("D_StepWindow", "Only consider valid values", nullptr));
        checkBox_09_HDR_Thresh->setText(QApplication::translate("D_StepWindow", "only consider values:", nullptr));
        checkBox_09_HDR_Project->setText(QApplication::translate("D_StepWindow", "Project", nullptr));
        label_09_HDR_Exp->setText(QApplication::translate("D_StepWindow", "Exposure", nullptr));
        radioButton_09_RelationStat_Angle->setText(QString());
        radioButton_09_RelationStat_Distance->setText(QString());
        label_09_RelationStat_Distance->setText(QApplication::translate("D_StepWindow", "Distance", nullptr));
        label_09_RelationStat_Angle->setText(QApplication::translate("D_StepWindow", "Angle", nullptr));
        label_09_ZernikeStack_Radius->setText(QApplication::translate("D_StepWindow", "Radius", nullptr));
        label_09_ZernikeStack_J->setText(QApplication::translate("D_StepWindow", "max j", nullptr));
        groupBox_09_Michelson_Scene_px->setTitle(QApplication::translate("D_StepWindow", "Scene (px)", nullptr));
        spinBox_09_Michelson_Scene_Size_X->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        spinBox_09_Michelson_Scene_Size_X->setPrefix(QApplication::translate("D_StepWindow", "sx=", nullptr));
        spinBox_09_Michelson_Scene_Size_Y->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        spinBox_09_Michelson_Scene_Size_Y->setPrefix(QApplication::translate("D_StepWindow", "sy=", nullptr));
        spinBox_09_Michelson_Scene_Size_Z->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        spinBox_09_Michelson_Scene_Size_Z->setPrefix(QApplication::translate("D_StepWindow", "sz=", nullptr));
        groupBox_09_Michelson_SP->setTitle(QApplication::translate("D_StepWindow", "Beamsplitter", nullptr));
        label_09_Michelson_Splitter->setText(QApplication::translate("D_StepWindow", "(0|0|0)", nullptr));
        groupBox_09_Michelson_Axis->setTitle(QApplication::translate("D_StepWindow", "Axis", nullptr));
        label_18->setText(QApplication::translate("D_StepWindow", "\342\206\223", nullptr));
        label_16->setText(QApplication::translate("D_StepWindow", "\342\206\222", nullptr));
        label_19->setText(QApplication::translate("D_StepWindow", "\342\212\231", nullptr));
        label_21->setText(QApplication::translate("D_StepWindow", "x", nullptr));
        label_20->setText(QApplication::translate("D_StepWindow", "y", nullptr));
        label_22->setText(QApplication::translate("D_StepWindow", "z", nullptr));
        groupBox_09_Michelson_M1->setTitle(QApplication::translate("D_StepWindow", "Mirror 1", nullptr));
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setPrefix(QApplication::translate("D_StepWindow", "\316\261y=", nullptr));
        doubleSpinBox_09_Michelson_Mirror1_angle_y->setSuffix(QApplication::translate("D_StepWindow", "\302\260", nullptr));
        checkBox_09_Michelson_Beam_atM1_SO->setText(QApplication::translate("D_StepWindow", "direct", nullptr));
        checkBox_09_Michelson_Beam_atM1_M1_SO->setText(QApplication::translate("D_StepWindow", "M1", nullptr));
        doubleSpinBox_09_Michelson_Mirror1_distance->setPrefix(QApplication::translate("D_StepWindow", "\316\224s=", nullptr));
        doubleSpinBox_09_Michelson_Mirror1_distance->setSuffix(QApplication::translate("D_StepWindow", "\316\274m", nullptr));
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setPrefix(QApplication::translate("D_StepWindow", "\316\261x=", nullptr));
        doubleSpinBox_09_Michelson_Mirror1_angle_x->setSuffix(QApplication::translate("D_StepWindow", "\302\260", nullptr));
        groupBox_09_Michelson_DE->setTitle(QApplication::translate("D_StepWindow", "Detector", nullptr));
        doubleSpinBox_09_Michelson_Detector_distance->setPrefix(QApplication::translate("D_StepWindow", "\316\224s=", nullptr));
        doubleSpinBox_09_Michelson_Detector_distance->setSuffix(QApplication::translate("D_StepWindow", "\316\274m", nullptr));
        checkBox_09_Michelson_Beam_atDE_SP_M1_SO->setText(QApplication::translate("D_StepWindow", "SP M1", nullptr));
        checkBox_09_Michelson_Beam_atDE_M2_SP_SO->setText(QApplication::translate("D_StepWindow", "M2 SP", nullptr));
        groupBox_09_MichelsonScene_um->setTitle(QApplication::translate("D_StepWindow", "Scene (\316\274m)", nullptr));
        label_09_Michelson_SceneSize_Y->setText(QApplication::translate("D_StepWindow", "10\316\274m", nullptr));
        label_09_Michelson_SceneSize_X->setText(QApplication::translate("D_StepWindow", "10\316\274m", nullptr));
        label_09_Michelson_SceneSize_Z->setText(QApplication::translate("D_StepWindow", "0.02\316\274m", nullptr));
        groupBox_09_Michelson_M2->setTitle(QApplication::translate("D_StepWindow", "Mirror 2", nullptr));
        checkBox_09_Michelson_Beam_atM2_SP_SO->setText(QApplication::translate("D_StepWindow", "SP", nullptr));
        checkBox_09_Michelson_Beam_atM2_M2_SP_SO->setText(QApplication::translate("D_StepWindow", "M2 SP", nullptr));
        doubleSpinBox_09_Michelson_Mirror2_distance->setPrefix(QApplication::translate("D_StepWindow", "\316\224s=", nullptr));
        doubleSpinBox_09_Michelson_Mirror2_distance->setSuffix(QApplication::translate("D_StepWindow", "\316\274m", nullptr));
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setPrefix(QApplication::translate("D_StepWindow", "\316\261y=", nullptr));
        doubleSpinBox_09_Michelson_Mirror2_angle_y->setSuffix(QApplication::translate("D_StepWindow", "\302\260", nullptr));
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setPrefix(QApplication::translate("D_StepWindow", "\316\261x=", nullptr));
        doubleSpinBox_09_Michelson_Mirror2_angle_x->setSuffix(QApplication::translate("D_StepWindow", "\302\260", nullptr));
        groupBox_09_Michelson_SO->setTitle(QApplication::translate("D_StepWindow", "Source", nullptr));
        checkBox_09_Michelson_Beam_atSO_SO->setText(QApplication::translate("D_StepWindow", "direct", nullptr));
        checkBox_09_Michelson_Beam_atSO_M1_SO->setText(QApplication::translate("D_StepWindow", "M1 ", nullptr));
        checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->setText(QApplication::translate("D_StepWindow", "SP M2 SP", nullptr));
        doubleSpinBox_09_Michelson_Wavelength->setSuffix(QApplication::translate("D_StepWindow", "\316\274m", nullptr));
        doubleSpinBox_09_Michelson_Source_distance->setPrefix(QApplication::translate("D_StepWindow", "\316\224s=", nullptr));
        doubleSpinBox_09_Michelson_Source_distance->setSuffix(QApplication::translate("D_StepWindow", "\316\274m", nullptr));
        groupBox_09_MichelsonScale->setTitle(QApplication::translate("D_StepWindow", "Scale", nullptr));
        doubleSpinBox_09_Michelson_Scale_um->setSuffix(QApplication::translate("D_StepWindow", "\316\274m", nullptr));
        spinBox_09_Michelson_Scale_px->setSuffix(QApplication::translate("D_StepWindow", "px", nullptr));
        comboBox_09_Michelson_Show_IorE->setItemText(0, QApplication::translate("D_StepWindow", "Show Fieldstrength", nullptr));
        comboBox_09_Michelson_Show_IorE->setItemText(1, QApplication::translate("D_StepWindow", "Show Intensity", nullptr));

        label_09_RadiometricStereo_S4->setText(QApplication::translate("D_StepWindow", "Image 4", nullptr));
        label_09_RadiometricStereo_X->setText(QApplication::translate("D_StepWindow", "x", nullptr));
        label_09_RadiometricStereo_Y->setText(QApplication::translate("D_StepWindow", "y", nullptr));
        label_09_RadiometricStereo_S3->setText(QApplication::translate("D_StepWindow", "Image 3", nullptr));
        label_09_RadiometricStereo_S->setText(QApplication::translate("D_StepWindow", "S", nullptr));
        label_09_RadiometricStereo_S1->setText(QApplication::translate("D_StepWindow", "Image 1", nullptr));
        label_09_RadiometricStereo_S2->setText(QApplication::translate("D_StepWindow", "Image 2", nullptr));
        label_09_RadiometricStereo_Z->setText(QApplication::translate("D_StepWindow", "z", nullptr));
        label_09_RadiometricStereo_OutMode->setText(QApplication::translate("D_StepWindow", "Output", nullptr));
        checkBox_10_Pick_Z->setText(QApplication::translate("D_StepWindow", "Z", nullptr));
        checkBox_10_Pick_P->setText(QApplication::translate("D_StepWindow", "P", nullptr));
        checkBox_10_Pick_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        checkBox_10_Pick_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_10_Pick_Pos->setText(QApplication::translate("D_StepWindow", "Position", nullptr));
        checkBox_10_Pick_T->setText(QApplication::translate("D_StepWindow", "T", nullptr));
        checkBox_10_Pick_S->setText(QApplication::translate("D_StepWindow", "S", nullptr));
        label_10_Pick_Dim->setText(QApplication::translate("D_StepWindow", "Pick Dim", nullptr));
        checkBox_10_Crop_Z->setText(QApplication::translate("D_StepWindow", "Z", nullptr));
        checkBox_10_Crop_X->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        label_10_Crop_Min->setText(QApplication::translate("D_StepWindow", "Min", nullptr));
        checkBox_10_Crop_T->setText(QApplication::translate("D_StepWindow", "T", nullptr));
        label_10_Crop_Dim->setText(QApplication::translate("D_StepWindow", "Crop Dim", nullptr));
        checkBox_10_Crop_S->setText(QApplication::translate("D_StepWindow", "S", nullptr));
        checkBox_10_Crop_Y->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        checkBox_10_Crop_P->setText(QApplication::translate("D_StepWindow", "P", nullptr));
        label_10_Crop_Max->setText(QApplication::translate("D_StepWindow", "Max", nullptr));
        label_10_Project_Dimension->setText(QApplication::translate("D_StepWindow", "Project Dim", nullptr));
        label_10_Project_Stat->setText(QApplication::translate("D_StepWindow", "Stat", nullptr));
        label_10_Project_8bit->setText(QApplication::translate("D_StepWindow", "Force 8bit", nullptr));
        checkBox_10_Project_8bit->setText(QString());
        label_10_Deserialise_Spacing->setText(QApplication::translate("D_StepWindow", "with spaces of", nullptr));
        label_10_Deserialise_Dimension_In->setText(QApplication::translate("D_StepWindow", "Split dimension", nullptr));
        label_10_Deserialise_Dimension_Out->setText(QApplication::translate("D_StepWindow", "into dimension", nullptr));
        label_10_Page2Color_R->setText(QApplication::translate("D_StepWindow", "Red Page", nullptr));
        label_10_Page2Color_G->setText(QApplication::translate("D_StepWindow", "Green Page", nullptr));
        label_10_Page2Color_B->setText(QApplication::translate("D_StepWindow", "Blue Page", nullptr));
        label_10_Stitching_Border_R->setText(QApplication::translate("D_StepWindow", "Border Right/Bottom", nullptr));
        doubleSpinBox_10_Stitching_Border_R->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        label_10_Stitching_Mode->setText(QApplication::translate("D_StepWindow", "Mode", nullptr));
        label_10_Stitching_Border_B->setText(QApplication::translate("D_StepWindow", "Overlap Right/Bottom", nullptr));
        doubleSpinBox_10_Stitching_Border_B->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        doubleSpinBox_10_Stitching_Overlap_R->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        doubleSpinBox_10_Stitching_Overlap_B->setSuffix(QApplication::translate("D_StepWindow", "%", nullptr));
        comboBox_10_Stitching_Mode->setItemText(0, QApplication::translate("D_StepWindow", "Scans", nullptr));
        comboBox_10_Stitching_Mode->setItemText(1, QApplication::translate("D_StepWindow", "Panorama", nullptr));

        checkBox_10_Pick_Z_3->setText(QApplication::translate("D_StepWindow", "Z", nullptr));
        checkBox_10_Pick_P_3->setText(QApplication::translate("D_StepWindow", "P", nullptr));
        checkBox_10_Pick_X_3->setText(QApplication::translate("D_StepWindow", "X", nullptr));
        checkBox_10_Pick_Y_3->setText(QApplication::translate("D_StepWindow", "Y", nullptr));
        label_10_Pick_Pos_3->setText(QApplication::translate("D_StepWindow", "Extension", nullptr));
        checkBox_10_Pick_T_3->setText(QApplication::translate("D_StepWindow", "T", nullptr));
        checkBox_10_Pick_S_3->setText(QApplication::translate("D_StepWindow", "S", nullptr));
        label_10_Pick_Dim_3->setText(QApplication::translate("D_StepWindow", "Pick Dim", nullptr));
        label->setText(QApplication::translate("D_StepWindow", "TextLabel", nullptr));
        groupBox_ProcDims->setTitle(QApplication::translate("D_StepWindow", "Processing Dimensions", nullptr));
        checkBox_ProcDims_Z_Proc->setText(QString());
        checkBox_ProcDims_T_Proc->setText(QString());
        checkBox_ProcDims_Y_Proc->setText(QString());
        checkBox_ProcDims_P_Proc->setText(QString());
        checkBox_ProcDims_X_Proc->setText(QString());
        checkBox_ProcDims_S_Proc->setText(QString());
        label_ProcDims_X->setText(QApplication::translate("D_StepWindow", " X", nullptr));
        label_ProcDims_Y->setText(QApplication::translate("D_StepWindow", " Y", nullptr));
        label_ProcDims_Z->setText(QApplication::translate("D_StepWindow", " Z", nullptr));
        label_ProcDims_T->setText(QApplication::translate("D_StepWindow", " T", nullptr));
        label_ProcDims_S->setText(QApplication::translate("D_StepWindow", " S", nullptr));
        label_ProcDims_P->setText(QApplication::translate("D_StepWindow", " P", nullptr));
        groupBox_Source->setTitle(QApplication::translate("D_StepWindow", "Source", nullptr));
        label_Source_1->setText(QApplication::translate("D_StepWindow", "1:", nullptr));
        label_Source_3->setText(QApplication::translate("D_StepWindow", "3:", nullptr));
        label_Source_2->setText(QApplication::translate("D_StepWindow", "2:", nullptr));
        label_Source_Type_2->setText(QApplication::translate("D_StepWindow", "Type S2 MA", nullptr));
        label_Source_Type_1->setText(QApplication::translate("D_StepWindow", "Type S1 MA", nullptr));
        label_Source_Type_3->setText(QApplication::translate("D_StepWindow", "Type S3 MA", nullptr));
        label_Source_4->setText(QApplication::translate("D_StepWindow", "4:", nullptr));
        label_Source_Type_4->setText(QApplication::translate("D_StepWindow", "Type S4 MA", nullptr));
        groupBox_Type_Update->setTitle(QApplication::translate("D_StepWindow", "Type and Update", nullptr));
        comboBox_Type_00_Source->setItemText(0, QApplication::translate("D_StepWindow", "Load", nullptr));
        comboBox_Type_00_Source->setItemText(1, QApplication::translate("D_StepWindow", "Duplicate", nullptr));
        comboBox_Type_00_Source->setItemText(2, QApplication::translate("D_StepWindow", "Sample Images", nullptr));
        comboBox_Type_00_Source->setItemText(3, QApplication::translate("D_StepWindow", "Generate", nullptr));
        comboBox_Type_00_Source->setItemText(4, QApplication::translate("D_StepWindow", "Random", nullptr));
        comboBox_Type_00_Source->setItemText(5, QApplication::translate("D_StepWindow", "Cast Raw Data", nullptr));
        comboBox_Type_00_Source->setItemText(6, QApplication::translate("D_StepWindow", "Video Proc", nullptr));

        comboBox_Type_01_Edit->setItemText(0, QApplication::translate("D_StepWindow", "Crop", nullptr));
        comboBox_Type_01_Edit->setItemText(1, QApplication::translate("D_StepWindow", "Floodfill", nullptr));
        comboBox_Type_01_Edit->setItemText(2, QApplication::translate("D_StepWindow", "Padding", nullptr));
        comboBox_Type_01_Edit->setItemText(3, QApplication::translate("D_StepWindow", "Force Size", nullptr));

        comboBox_Type_02_Convert->setItemText(0, QApplication::translate("D_StepWindow", "Color to Mono", nullptr));
        comboBox_Type_02_Convert->setItemText(1, QApplication::translate("D_StepWindow", "Color to Color", nullptr));
        comboBox_Type_02_Convert->setItemText(2, QApplication::translate("D_StepWindow", "Double", nullptr));
        comboBox_Type_02_Convert->setItemText(3, QApplication::translate("D_StepWindow", "Depth", nullptr));
        comboBox_Type_02_Convert->setItemText(4, QApplication::translate("D_StepWindow", "Channel Merge", nullptr));
        comboBox_Type_02_Convert->setItemText(5, QApplication::translate("D_StepWindow", "Channel Split", nullptr));
        comboBox_Type_02_Convert->setItemText(6, QApplication::translate("D_StepWindow", "Combination", nullptr));
        comboBox_Type_02_Convert->setItemText(7, QApplication::translate("D_StepWindow", "Angle to Color", nullptr));

        comboBox_Type_03_Elemental->setItemText(0, QApplication::translate("D_StepWindow", "Threshold", nullptr));
        comboBox_Type_03_Elemental->setItemText(1, QApplication::translate("D_StepWindow", "Labeling", nullptr));
        comboBox_Type_03_Elemental->setItemText(2, QApplication::translate("D_StepWindow", "Shading Correct", nullptr));
        comboBox_Type_03_Elemental->setItemText(3, QApplication::translate("D_StepWindow", "Grab Color", nullptr));
        comboBox_Type_03_Elemental->setItemText(4, QApplication::translate("D_StepWindow", "Fill Holes", nullptr));

        comboBox_Type_04_Filter->setItemText(0, QApplication::translate("D_StepWindow", "Blur", nullptr));
        comboBox_Type_04_Filter->setItemText(1, QApplication::translate("D_StepWindow", "Edge", nullptr));
        comboBox_Type_04_Filter->setItemText(2, QApplication::translate("D_StepWindow", "Special", nullptr));
        comboBox_Type_04_Filter->setItemText(3, QApplication::translate("D_StepWindow", "Eilenstein", nullptr));
        comboBox_Type_04_Filter->setItemText(4, QApplication::translate("D_StepWindow", "Function", nullptr));
        comboBox_Type_04_Filter->setItemText(5, QApplication::translate("D_StepWindow", "Rank Order", nullptr));
        comboBox_Type_04_Filter->setItemText(6, QApplication::translate("D_StepWindow", "Statistic", nullptr));

        comboBox_Type_05_Morphology->setItemText(0, QApplication::translate("D_StepWindow", "Elemental", nullptr));
        comboBox_Type_05_Morphology->setItemText(1, QApplication::translate("D_StepWindow", "Min/Max Gil", nullptr));
        comboBox_Type_05_Morphology->setItemText(2, QApplication::translate("D_StepWindow", "Reconstruction", nullptr));
        comboBox_Type_05_Morphology->setItemText(3, QApplication::translate("D_StepWindow", "Local Maxima", nullptr));

        comboBox_Type_06_Math->setItemText(0, QApplication::translate("D_StepWindow", "1 Image Simple", nullptr));
        comboBox_Type_06_Math->setItemText(1, QApplication::translate("D_StepWindow", "2 Image Simple", nullptr));
        comboBox_Type_06_Math->setItemText(2, QApplication::translate("D_StepWindow", "2 Image Function", nullptr));
        comboBox_Type_06_Math->setItemText(3, QApplication::translate("D_StepWindow", "2 Image Func. Compl.", nullptr));
        comboBox_Type_06_Math->setItemText(4, QApplication::translate("D_StepWindow", "3 Image Simple", nullptr));
        comboBox_Type_06_Math->setItemText(5, QApplication::translate("D_StepWindow", "4 Image Simple", nullptr));

        comboBox_Type_07_Transform->setItemText(0, QApplication::translate("D_StepWindow", "Distance", nullptr));
        comboBox_Type_07_Transform->setItemText(1, QApplication::translate("D_StepWindow", "Watershed", nullptr));
        comboBox_Type_07_Transform->setItemText(2, QApplication::translate("D_StepWindow", "Fourier", nullptr));
        comboBox_Type_07_Transform->setItemText(3, QApplication::translate("D_StepWindow", "Radon", nullptr));

        comboBox_Type_08_Feature->setItemText(0, QApplication::translate("D_StepWindow", "Value", nullptr));
        comboBox_Type_08_Feature->setItemText(1, QApplication::translate("D_StepWindow", "Value Context", nullptr));
        comboBox_Type_08_Feature->setItemText(2, QApplication::translate("D_StepWindow", "Select", nullptr));
        comboBox_Type_08_Feature->setItemText(3, QApplication::translate("D_StepWindow", "Select Context", nullptr));
        comboBox_Type_08_Feature->setItemText(4, QApplication::translate("D_StepWindow", "Connect", nullptr));
        comboBox_Type_08_Feature->setItemText(5, QApplication::translate("D_StepWindow", "Reduce", nullptr));
        comboBox_Type_08_Feature->setItemText(6, QApplication::translate("D_StepWindow", "Visualize", nullptr));
        comboBox_Type_08_Feature->setItemText(7, QString());

        comboBox_Type_09_Other->setItemText(0, QApplication::translate("D_StepWindow", "Equalize Histo.", nullptr));
        comboBox_Type_09_Other->setItemText(1, QApplication::translate("D_StepWindow", "Gamma Spread", nullptr));
        comboBox_Type_09_Other->setItemText(2, QApplication::translate("D_StepWindow", "Label Numbers", nullptr));
        comboBox_Type_09_Other->setItemText(3, QApplication::translate("D_StepWindow", "Euler Number", nullptr));
        comboBox_Type_09_Other->setItemText(4, QApplication::translate("D_StepWindow", "Motion Field (buggy)", nullptr));
        comboBox_Type_09_Other->setItemText(5, QApplication::translate("D_StepWindow", "Class Border kNN", nullptr));
        comboBox_Type_09_Other->setItemText(6, QApplication::translate("D_StepWindow", "HDR", nullptr));
        comboBox_Type_09_Other->setItemText(7, QApplication::translate("D_StepWindow", "Relation Stat", nullptr));
        comboBox_Type_09_Other->setItemText(8, QApplication::translate("D_StepWindow", "Zernike Stack", nullptr));
        comboBox_Type_09_Other->setItemText(9, QApplication::translate("D_StepWindow", "Michelson Interferometer", nullptr));

        comboBox_Type_10_Dimension->setItemText(0, QApplication::translate("D_StepWindow", "Pick", nullptr));
        comboBox_Type_10_Dimension->setItemText(1, QApplication::translate("D_StepWindow", "Crop", nullptr));
        comboBox_Type_10_Dimension->setItemText(2, QApplication::translate("D_StepWindow", "Project", nullptr));
        comboBox_Type_10_Dimension->setItemText(3, QApplication::translate("D_StepWindow", "Deserialise", nullptr));
        comboBox_Type_10_Dimension->setItemText(4, QApplication::translate("D_StepWindow", "Pages 2 Color", nullptr));
        comboBox_Type_10_Dimension->setItemText(5, QApplication::translate("D_StepWindow", "Stitch Border", nullptr));

        comboBox_Type_Main->setItemText(0, QApplication::translate("D_StepWindow", "Source", nullptr));
        comboBox_Type_Main->setItemText(1, QApplication::translate("D_StepWindow", "Edit", nullptr));
        comboBox_Type_Main->setItemText(2, QApplication::translate("D_StepWindow", "Convert", nullptr));
        comboBox_Type_Main->setItemText(3, QApplication::translate("D_StepWindow", "Elemental", nullptr));
        comboBox_Type_Main->setItemText(4, QApplication::translate("D_StepWindow", "Filter", nullptr));
        comboBox_Type_Main->setItemText(5, QApplication::translate("D_StepWindow", "Morphology", nullptr));
        comboBox_Type_Main->setItemText(6, QApplication::translate("D_StepWindow", "Math", nullptr));
        comboBox_Type_Main->setItemText(7, QApplication::translate("D_StepWindow", "Transform", nullptr));
        comboBox_Type_Main->setItemText(8, QApplication::translate("D_StepWindow", "Feature", nullptr));
        comboBox_Type_Main->setItemText(9, QApplication::translate("D_StepWindow", "Other", nullptr));
        comboBox_Type_Main->setItemText(10, QApplication::translate("D_StepWindow", "Dimension", nullptr));

        pushButton_Update_Step->setText(QApplication::translate("D_StepWindow", "Update Step (F5)", nullptr));
        groupBox_View_Plane->setTitle(QApplication::translate("D_StepWindow", "Plane", nullptr));
        doubleSpinBox_View_Plane_X->setPrefix(QApplication::translate("D_StepWindow", "X=", nullptr));
        doubleSpinBox_View_Plane_X->setSuffix(QApplication::translate("D_StepWindow", " px", nullptr));
        doubleSpinBox_View_Plane_Y->setPrefix(QApplication::translate("D_StepWindow", "Y=", nullptr));
        doubleSpinBox_View_Plane_Y->setSuffix(QApplication::translate("D_StepWindow", " px", nullptr));
        doubleSpinBox_View_Plane_Z->setPrefix(QApplication::translate("D_StepWindow", "Z=", nullptr));
        doubleSpinBox_View_Plane_Z->setSuffix(QApplication::translate("D_StepWindow", " px", nullptr));
        doubleSpinBox_View_Plane_T->setPrefix(QApplication::translate("D_StepWindow", "T=", nullptr));
        doubleSpinBox_View_Plane_T->setSuffix(QApplication::translate("D_StepWindow", " f", nullptr));
        doubleSpinBox_View_Plane_S->setPrefix(QApplication::translate("D_StepWindow", "S=", nullptr));
        doubleSpinBox_View_Plane_P->setPrefix(QApplication::translate("D_StepWindow", "P=", nullptr));
        groupBox_View_Contrast->setTitle(QApplication::translate("D_StepWindow", "Display", nullptr));
        doubleSpinBox_View_Divisor->setPrefix(QApplication::translate("D_StepWindow", "divisor=", nullptr));
        checkBox_View_VisTrafo->setText(QApplication::translate("D_StepWindow", "Transformed", nullptr));
        doubleSpinBox_View_Range->setPrefix(QApplication::translate("D_StepWindow", "range=", nullptr));
        doubleSpinBox_View_Max->setPrefix(QApplication::translate("D_StepWindow", "max=", nullptr));
        doubleSpinBox_View_Anchor->setPrefix(QApplication::translate("D_StepWindow", "anchor=", nullptr));
        doubleSpinBox_View_Gamma->setPrefix(QApplication::translate("D_StepWindow", "gamma=", nullptr));
        doubleSpinBox_View_Min->setPrefix(QApplication::translate("D_StepWindow", "min=", nullptr));
        doubleSpinBox_View_Center->setPrefix(QApplication::translate("D_StepWindow", "center=", nullptr));
#ifndef QT_NO_TOOLTIP
        comboBox_View_Complex->setToolTip(QApplication::translate("D_StepWindow", "<html><head/><body><p>Transforms complex values into something that can be displayed in real values.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget_Output->setTabText(tabWidget_Output->indexOf(tab_Output_Image), QApplication::translate("D_StepWindow", "Image", nullptr));
        checkBox_Output_Hist_Accumulate->setText(QApplication::translate("D_StepWindow", "Acc", nullptr));
        checkBox_Output_Hist_Uniform->setText(QApplication::translate("D_StepWindow", "Uni", nullptr));
        pushButton_Update_Hist->setText(QApplication::translate("D_StepWindow", "Update Hist (F6)", nullptr));
        label_HistClasses->setText(QApplication::translate("D_StepWindow", "Classes:", nullptr));
        checkBox_Output_Hist_Full6D->setText(QApplication::translate("D_StepWindow", "Full 6D", nullptr));
        tabWidget_Output->setTabText(tabWidget_Output->indexOf(tab_Output_Hist), QApplication::translate("D_StepWindow", "Histogram", nullptr));
        pushButton_Update_Times->setText(QApplication::translate("D_StepWindow", "Update Times (F7)", nullptr));
        checkBox_Output_Times_Processing->setText(QApplication::translate("D_StepWindow", "Processing", nullptr));
        checkBox_Output_Times_Hist->setText(QApplication::translate("D_StepWindow", "Histogram", nullptr));
        checkBox_Output_Times_Show->setText(QApplication::translate("D_StepWindow", "Show", nullptr));
        checkBox_Output_Times_Conversion->setText(QApplication::translate("D_StepWindow", "Conversion", nullptr));
        tabWidget_Output->setTabText(tabWidget_Output->indexOf(tab_Output_Times), QApplication::translate("D_StepWindow", "Time", nullptr));
        label_Cahin_Pos->setText(QApplication::translate("D_StepWindow", "Position:", nullptr));
        label_Chain_Source_of->setText(QApplication::translate("D_StepWindow", "Is source of:", nullptr));
        label_Chain_Sources_Used->setText(QApplication::translate("D_StepWindow", "Used sources:", nullptr));
        label_Chain_Sources_Used_List->setText(QApplication::translate("D_StepWindow", "-", nullptr));
        label_Chain_Source_of_List->setText(QApplication::translate("D_StepWindow", "-", nullptr));
        label_Chain_Pos_Val->setText(QApplication::translate("D_StepWindow", "-", nullptr));
        label_Chain_Updated->setText(QApplication::translate("D_StepWindow", "Last updated:", nullptr));
        label_Chain_Updated_Val->setText(QApplication::translate("D_StepWindow", "-", nullptr));
        tabWidget_Output->setTabText(tabWidget_Output->indexOf(tab_Output_Chain_Info), QApplication::translate("D_StepWindow", "Chain", nullptr));
        comboBox_FunctionView_Mode->setItemText(0, QApplication::translate("D_StepWindow", "Line", nullptr));

        checkBox->setText(QApplication::translate("D_StepWindow", "Anitaliasing", nullptr));
        tabWidget_Output->setTabText(tabWidget_Output->indexOf(tab_Output_FunctionView), QApplication::translate("D_StepWindow", "Function", nullptr));
        menuViewer->setTitle(QApplication::translate("D_StepWindow", "Viewer", nullptr));
        menuLayout->setTitle(QApplication::translate("D_StepWindow", "Layout", nullptr));
        menuUpdate->setTitle(QApplication::translate("D_StepWindow", "Update", nullptr));
        menuData->setTitle(QApplication::translate("D_StepWindow", "Save", nullptr));
        menuWindow->setTitle(QApplication::translate("D_StepWindow", "Window", nullptr));
        menuHistogram->setTitle(QApplication::translate("D_StepWindow", "Histogram", nullptr));
        menuTimes->setTitle(QApplication::translate("D_StepWindow", "Time", nullptr));
        menuTest->setTitle(QApplication::translate("D_StepWindow", "Test", nullptr));
        menuMeasure->setTitle(QApplication::translate("D_StepWindow", "Measure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_StepWindow: public Ui_D_StepWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_STEPWINDOW_H
