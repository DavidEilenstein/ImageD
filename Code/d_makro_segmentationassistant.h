/************************************
 *   added:     24.09.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_SEGMENTATIONASSISTANT_H
#define D_MAKRO_SEGMENTATIONASSISTANT_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>

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
class D_MAKRO_SegmentationAssistant;
}

class D_MAKRO_SegmentationAssistant : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_SegmentationAssistant(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_SegmentationAssistant();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

    void Init();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB();

private slots:
    void Update_Views();
    void Update_Images();
    void Update_ProcSetps(int step_start);
    void Update_ProcStep(int step);
    void Images_Add();
    void Images_Clear();
    void Images_Next();
    void Images_Previous();

    void on_comboBox_In_Images_currentIndexChanged(int index);

    void on_spinBox_In_PageDisplay_valueChanged(int arg1);

    void on_spinBox_Select_Page_valueChanged(int arg1);

    void on_comboBox_Select_Mono_currentIndexChanged(int index);

    void on_doubleSpinBox_Blur_Sigma_valueChanged(double arg1);

    void on_spinBox_Blur_Size_valueChanged(int arg1);

    void on_doubleSpinBox_Seg_Sigma_valueChanged(double arg1);

    void on_spinBox_Seg_Size_valueChanged(int arg1);

    void on_comboBox_Step_currentIndexChanged(int index);

    void on_checkBox_Seg_InclNonSeed_stateChanged(int arg1);

    void on_checkBox_Seg_ExclBorder_stateChanged(int arg1);

    void on_doubleSpinBox_Binary_Thres_valueChanged(double arg1);

private:
    Ui::D_MAKRO_SegmentationAssistant *ui;
    bool                            ClosingPossible = false;

    //Data-Info
    QFileInfoList                   FIL_Images;
    QStringList                     QSL_Images_Paths;
    QStringList                     QSL_Images_Names;

    //Data
    D_VisDat_Slicing                ProcSlicing = D_VisDat_Slicing(c_SLICE_2D_XY);
    vector<D_VisDat_Obj>            vVD_Steps;
    Mat                             MA_ShowProc;

    //Storage
    D_Storage                       *pStore;

    //Viewer
    D_Viewer                        Viewer_Proc;

    //states
    bool                            state_no_img            = true;
    bool                            state_cur_img_loaded    = false;
    bool                            state_img_proc_done     = false;

    //Error handler
    D_Error_Handler                 ER;
    void                            ERR(int err, QString func = "not specified", QString detail = "not specified");

    enum c_PROC_STEPS {
        c_ST_IN,
        c_ST_SEL_PAGE,
        c_ST_SEL_CHANNEL,
        c_ST_BLUR,
        c_ST_THRES,
        c_ST_WATERSHED,
        //c_ST_INF_MERGE,
        //c_ST_INF_SEPARATE,
        //c_ST_INF_KICK,
        c_ST_TRAIN_RECOVER,
        c_ST_TRAIN_MERGE,
        c_ST_TRAIN_SEPARATE,
        c_ST_TRAIN_KICK,
        c_ST_OUT,
        c_ST_NUMBER_OF
    };
    const QStringList QSL_Steps = {
        "Input",
        "Select Page",
        "Select Mono Mode",
        "Blur",
        "Binary",
        "Watershed",
        //"Inference Merge",
        //"Inference Separate",
        //"Inference Kick",
        "Recover",
        "Merge",
        "Separate",
        "Kick",
        "Output"
    };
};

#endif // D_MAKRO_SEGMENTATIONASSISTANT_H
