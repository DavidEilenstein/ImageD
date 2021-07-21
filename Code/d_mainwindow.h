/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAINWINDOW_H
#define D_MAINWINDOW_H

//own
#include <d_enum.h>
#include <d_stepwindow.h>
#include <scenemousetrack.h>
#include <d_storage.h>
#include <d_img_proc.h>
#include <d_img_proc_3d.h>
#include <d_stat.h>
#include <d_stat_tester.h>
#include <d_viewer.h>
#include <d_error_handler.h>
#include <d_analysiswindow.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>
#include <d_math.h>
#include <d_popup_listselect.h>
#include <d_pdf_writer.h>
#include <d_popup_feedbackrequest.h>
#include <d_popup_listedit_numbers.h>
#include <d_popup_plot.h>
#include <d_multidimloop.h>
#include <d_contour.h>

//makros
#include <d_makro_corefoci.h>
#include <d_makro_mitochondrien.h>
#include <d_makro_eilenstein.h>
#include <d_makro_cellcolonies.h>
#include <d_makro_iontracks.h>
#include <d_makro_visualization.h>
#include <m_makro_foci.h>
#include <d_makro_osteoclasts.h>
#include <d_makro_dnafiber.h>
#include <d_makro_curvefitting.h>
#include <d_makro_segmentationassistant.h>
#include <d_makro_cerebralorganoids.h>
#include <d_makro_manuelsegmentation.h>
#include <d_makro_ciliaspheretracker.h>
#include <d_makro_fouriertransformator.h>
#include <d_makro_airdragtrack.h>
#include <d_makro_megafoci.h>
#include <d_makro_huangvisualization.h>
#include <d_makro_softmaxvisualization.h>

//general
#include <iostream>
#include <vector>
#include <fstream>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSysInfo>
#include <QLabel>

//Qt-Charts
#include <QChartView>
#include <QChart>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

namespace Ui {
class D_MainWindow;
}

/*!
 * \brief The D_MainWindow class The main window you see when ImageD starts.
 * \details Hosts the only D_Storage object. Functions as a master window from where other windows and moduls can be opened. Has access to all D_StepWindow s.
 */
class D_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MainWindow(QWidget *parent = 0);
    ~D_MainWindow();

    void            Add_Step();
    void            Add_Analysis();

    void            resizeEvent(QResizeEvent *event);
    void            closeEvent(QCloseEvent *event);
    void            set_Position();

private slots:

    void            Update_All_Steps();
    void            Update_Image();
    void            Update_View();
    void            Update_Times();

    void            Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init = 0);
    void            Populate_CB_Plugins();

    void Connect_TimesSettings_2_UpdateTimes(bool con);

    void on_spinBox_Viewer_Image_Number_valueChanged(int arg1);

    void on_pushButton_Step_Add_clicked();

    void on_tabWidget_Overview_currentChanged(int index);

    void on_action_Set_Step_Pos_triggered();

    void on_action_Test_Statistic_Function_triggered();

    void on_action_Test_Quatile_Access_triggered();

    void on_action_Stat_Tester_triggered();

    void on_action_Steps_Normal_Size_triggered();

    void on_pushButton_Steps_Save_clicked();
    void stream_init();

    void on_pushButton_Analysis_Add_clicked();

    void on_action_Test_D_VisDat_triggered();

    void on_actionTest_ND_Mat_load_and_display_triggered();

    void on_action_Test_1D_EDT_triggered();

    void on_comboBox_PluginList_currentIndexChanged(int index);

    void on_pushButton_PluginLaunch_clicked();

    void on_pushButton_Ref_Licence_clicked();

    void on_pushButton_Ref_Citation_clicked();

    void on_pushButton_Ref_Contact_clicked();

    void on_pushButton_Ref_GSI_clicked();

    void on_pushButton_Ref_Biophysics_clicked();

    void on_pushButton_Ref_hda_clicked();

    void on_pushButton_Ref_OBV_clicked();

    void on_pushButton_Ref_OpenCV_clicked();

    void on_pushButton_Ref_Qt_clicked();

    void on_actionTest_DPF_Writer_triggered();

    void on_pushButton_Ref_Docs_clicked();

    void on_pushButton_Ref_Github_clicked();

    void on_actionTest_Running_Median_triggered();

    void on_actionTest_Maximum_Gil_triggered();

    void on_actionTest_nD_for_loop_triggered();

    void on_actionTest_range_selector_triggered();

    void on_actionTest_contour_intersection_triggered();

private:
    Ui::D_MainWindow        *ui;

    //D_VisDat Test
    Mat MA_vdTest, MA_vdTest2;

    //Error Handling
    D_Error_Handler         ER;
    void                    ERR(unsigned int er, QString func = "no specified", QString detail = "no specified");

    //Data Storage
    D_Storage               Store;

    //Img Proc Window Adresses
    vector<D_StepWindow*>           vSW_Steps;

    //Anaysis Adresses
    vector<D_AnalysisWindow*>        vAW_Analysis;

    //Plugins
    vector<int>                     vPluginActive;
    D_MAKRO_CoreFoci                *pCoreFoci;
    D_MAKRO_Mitochondrien           *pMitochondrien;
    D_MAKRO_Eilenstein              *pEilenstein;
    D_MAKRO_CellColonies            *pCellColonies;
    m_makro_foci                    *pFociNucleiTime;
    D_MAKRO_IonTracks               *pIonTracks;
    D_MAKRO_Visualization           *pVisualization;
    D_MAKRO_Osteoclasts             *pOsteoclasts;
    D_MAKRO_DnaFiber                *pDnaFibers;
    D_MAKRO_CurveFitting            *pCurveFitting;
    D_MAKRO_SegmentationAssistant   *pSegAssi;
    D_MAKRO_CerebralOrganoids       *pCerebOrga;
    D_MAKRO_ManuelSegmentation      *pManSeg;
    D_MAKRO_CiliaSphereTracker      *pCilTrack;
    D_MAKRO_FourierTransformator    *pFourierTrans;
    D_MAKRO_AirDragTrack            *pAirDrag;
    D_MAKRO_MegaFoci                *pMegaFoci;
    D_MAKRO_HuangVisualization      *pHuang;
    D_MAKRO_SoftmaxVisualization    *pSoftmax;

    //Stuff to show images
    QImage                  QI_Step_Image;
    QPixmap                 PX_Step_Image;
    SceneMouseTrack         SC_Step_Image;

    //Times
    QChartView              *ChartView_Times;
    QChart                  *Chart_Times;

    //Stream
    ofstream                OS_Steps_Stream;
    QDir                    DIR_Steps_Stream;

    //StatusBar
    QLabel                  *SB_L_Version;
    QLabel                  *SB_L_Date;
    QLabel                  *SB_L_Status;
    QLabel                  *SB_L_Author;
    QLabel                  *SB_L_Facility;
  //QLabel                  *SB_L_UseCounter;

    //Useful variables to avoid checking ui often
    unsigned int            current_step = 0;
};

#endif // D_MAINWINDOW_H
