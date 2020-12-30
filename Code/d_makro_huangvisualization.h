/****************************************************
 *   added:     10.12.2020                          *
 *   author:    David Eilenstein                    *
 *   contact:   David.Eilenstein@stud.h-da.de.de    *
 *   project:   ImageD                              *
 *   facility:  Hochschule Darmstadt, Ger           *
 ****************************************************/

#ifndef D_MAKRO_HUANGVISUALIZATION_H
#define D_MAKRO_HUANGVISUALIZATION_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>
#include <d_img_proc.h>

//Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QComboBox>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QInputDialog>

//Qt::Charts
#include <QChartView>
#include <QChart>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

namespace Ui {
class D_MAKRO_HuangVisualization;
}

/*!
 * \brief The D_MAKRO_HuangVisualization class visualization of huangs rank order filtering.
 * \details See explanation video <a href="https://www.youtube.com/watch?v=j_3wfKGABgQ">here</a>.
 */
class D_MAKRO_HuangVisualization : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_HuangVisualization(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_MAKRO_HuangVisualization();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    void Update_Ui();
    void Update_Image_Out();
    void Update_Image_In();
    void Update_Image_Mask();

    void Update_Plot_Hist();
    void Update_Plot_Mass();

    void Load_Image();
    void Get_Mask();
    void Load_Mask();
    void Generate_Mask();
    void Get_Quantil();

    void Pad_Image();
    void Init_ImgOut();

    void Proc_StepDetail();
    void Proc_StepValue();
    void Proc_StepPixel();
    void Proc_StepLine();
    void Proc_Full();

    void Init_Position();
    void Init_Hist();
    void Init_Quantile();
    void Init_Masses();
    void Init_PointLists();

    void Step_SaveLineBegin();
    void Step_LoadLineBegin();

    void Step_Pixel_ChangePos();
    void Step_Pixel_ChangePointLists();

    void Step_Point_ChangeAddRem();
    void Step_Point_Change_Hist();
    void Step_Point_Change_Masses_Add();
    void Step_Point_Change_Masses_Rem();
    void Step_Point_Check_Masses();

    void Step_Point_Quantil_Decrease_Change_Mass_Greater();
    void Step_Point_Quantil_Decrease_Change_Quantil();
    void Step_Point_Quantil_Decrease_Change_Mass_Quantil();
    void Step_Point_Quantil_Decrease_Change_Mass_Smaller();

    void Step_Point_Quantil_Increase_Change_Mass_Smaller();
    void Step_Point_Quantil_Increase_Change_Quantil();
    void Step_Point_Quantil_Increase_Change_Mass_Quantil();
    void Step_Point_Quantil_Increase_Change_Mass_Greater();

    void Step_Point_End();

    void Step_Pixel_WriteOut();
    void Step_Pixel_Change_Direction();

private:
    Ui::D_MAKRO_HuangVisualization *ui;
    bool ClosingPossible = false;

    //states ------------------------------------------

    bool state_img_loaded = false;
    bool state_mask_loaded = false;
    bool state_quantil_rel_set = false;
    bool state_img_padded = false;
    bool state_img_out_init = false;

    //Storage ----------------------------------------------

    D_Storage *pStore;

    //Stuff to show things -----------------------------------

    D_Viewer Viewer_In;
    D_Viewer Viewer_Mask;
    D_Viewer Viewer_Out;
    D_Viewer Viewer_Hist;
    D_Viewer Viewer_Mass;

    QLabel *pLabelStatus;


    //Images ------------------------------------------

    //in
    Mat MA_ImgIn_Load;
    Mat MA_ImgIn_Gray;
    Mat MA_ImgIn_GrayPadded;
    Mat MA_ImgIn_GrayPadded3Ch;
    Mat MA_ImgIn_Show;
    //out
    Mat MA_ImgOut_Gray;
    //Mat MA_ImgOut_Show;
    //Hist
    Mat MA_Hist;
    Mat MA_Mass;


    //mask
    Mat MA_MaskLoad;
    Mat MA_MaskBinary;
    Mat MA_MaskBinary_3C;
    Mat MA_MaskShow;
    //image sizes
    size_t img_in_sy;
    size_t img_in_sx;


    //parameters and variables for algorithm -------------------------

    //mask parameters
    //sizes
    int mask_sx;
    int mask_sy;
    //centers
    int mask_cx;
    int mask_cy;
    //center to border
    int mask_c2l;
    int mask_c2r;
    int mask_c2t;
    int mask_c2b;

    //mask to point lists parameters
    vector<Point> vBorderL;
    vector<Point> vBorderR;
    vector<Point> vBorderT;
    vector<Point> vBorderB;
    size_t mask_relevant_px_count;

    //hist
    vector<size_t> hist;
    vector<size_t> hist_line_begin;

    //looping parameters
    bool at_end = false;
    size_t pos_x;
    size_t pos_y;
    int direction = c_DIR2D_R;

    //masses
    size_t mass_smaller;
    size_t mass_smaller_line_begin;
    size_t mass_smaller_or_median;
    size_t mass_smaller_or_median_line_begin;
    size_t mass_quantil;
    size_t mass_quantil_line_begin;
    size_t mass_greater;
    size_t mass_greater_line_begin;
    size_t mass_greater_or_median;
    size_t mass_greater_or_median_line_begin;

    //quantil
    double quantil_relPos;
    double quantil_val;
    double quantil_val_line_begin;

    //mass check values
    double mass_smaller_or_equal_needed;
    double mass_greater_or_equal_needed;

    //add remove list and step length
    vector<Point> *vBorderAdd;
    vector<Point> *vBorderRem;
    int dx_to_prev_pos;
    int dy_to_prev_pos;

    //looping add/remove values
    size_t i_add_rem = 0;

    //values to add/remove
    uchar val_add;
    uchar val_rem;

    //mass checks
    bool check_smaller;
    bool check_greater;

    enum PROC_STEP {
        STEP_INIT_POSITION,
        STEP_INIT_QUANTILE,
        STEP_INIT_HIST,
        STEP_INIT_MASSES,
        STEP_INIT_POINT_LISTS,

        STEP_SAVE_LINE_BEGIN,
        STEP_LOAD_LINE_BEGIN,

        STEP_PIXEL_CHANGE_POS,
        STEP_PIXEL_CHANGE_POINT_LISTS,

        STEP_POINT_CHANGE_ADD_REM,
        STEP_POINT_CHANGE_HIST,
        STEP_POINT_CHANGE_MASSES_ADD,
        STEP_POINT_CHANGE_MASSES_REM,
        STEP_POINT_CHECK_MASSES,
        STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_GREATER,
        STEP_POINT_QUANTIL_DECREASE_CHANGE_QUANTIL,
        STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_QUANTIL,
        STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_SMALLER,

        STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_SMALLER,
        STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_QUANTILE,
        STEP_POINT_QUANTIL_INCREASE_CHANGE_QUANTIL,
        STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_GREATER,

        STEP_POINT_END,

        STEP_PIXEL_WRITE_OUT,
        STEP_PIXEL_CHANGE_DIRECTION,

        STEP_END,

        STEP_NUMBER_OF
    };
    size_t step_next = STEP_INIT_POSITION;
};

#endif // D_MAKRO_HUANGVISUALIZATION_H
