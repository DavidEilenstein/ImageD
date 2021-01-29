/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_STORAGE_H
#define D_STORAGE_H

//own
#include <d_enum.h>
#include <d_img_proc.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QClipboard>
#include <QApplication>
#include <QMessageBox>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

/*!
 * \brief The D_Storage class Used for storing data. There is only one instance in D_MainWindow .
 * \details There is only one instance of this in D_MainWindow . All others modules with acces to this get a pointer to that object.
 */
class D_Storage
{
public:
    D_Storage();

    //Basic
    Mat             *get_Adress(size_t pos)                         {return vMA_Images.size() <= pos ? &vMA_Images[0] : &vMA_Images[pos];}
    D_VisDat_Obj    *get_pVD(size_t pos)                            {return pos < vVD_Steps.size() ? &(vVD_Steps[pos]) : &(vVD_Steps[0]);}
    D_VisDat_Obj    get_VD(size_t pos)                              {return pos < vVD_Steps.size() ? vVD_Steps[pos] : vVD_Steps[0];}
    size_t          size()                                          {return vMA_Images.size();}
    void            expand();
    void            free()                                          {vMA_Images.clear(); vVD_Steps.clear();}

    //Clipboard
    QClipboard      *clipboard()                                    {return clip;}

    //Standard-Directories
    QDir            *dir_Config()                                   {return &DIR_Config;}
    QDir            *dir_Default()                                  {return &(vDIR_DefaultPaths[i_DEFAULT]);}
    QDir            *dir_Load()                                     {return &(vDIR_DefaultPaths[i_LOAD]);}
    QDir            *dir_Save()                                     {return &(vDIR_DefaultPaths[i_SAVE]);}
    QDir            *dir_M_dsDNA()                                  {return &(vDIR_DefaultPaths[i_M_DSDNA]);}
    QDir            *dir_M_Mitochondria()                           {return &(vDIR_DefaultPaths[i_M_MITO]);}
    QDir            *dir_M_Eilenstein()                             {return &(vDIR_DefaultPaths[i_M_EILEN]);}
    QDir            *dir_Examples()                                 {return &(vDIR_DefaultPaths[i_EXAMPLE]);}
    QDir            *dir_Steps()                                    {return &(vDIR_DefaultPaths[i_STEPS]);}
    QDir            *dir_M_CellColonies()                           {return &(vDIR_DefaultPaths[i_M_CELLCOL]);}
    QDir            *dir_M_FociTimeNuclei()                         {return &(vDIR_DefaultPaths[i_M_FOCITIME]);}
    QDir            *dir_Analyzer()                                 {return &(vDIR_DefaultPaths[i_ANALYZER]);}
    QDir            *dir_Test()                                     {return &(vDIR_DefaultPaths[i_TEST]);}
    QDir            *dir_M_IonTracks()                              {return &(vDIR_DefaultPaths[i_M_TRACKS]);}
    QDir            *dir_M_Visualization()                          {return &(vDIR_DefaultPaths[i_M_VIS]);}
    QDir            *dir_M_Osteoclasts()                            {return &(vDIR_DefaultPaths[i_M_OSTEO]);}
    QDir            *dir_M_DnaFibre()                               {return &(vDIR_DefaultPaths[i_M_DNAFIBER]);}
    QDir            *dir_M_RadonCurveFit()                          {return &(vDIR_DefaultPaths[i_M_RADONFIT]);}
    QDir            *dir_M_SegmentationAssistant()                  {return &(vDIR_DefaultPaths[i_M_SEGASSI]);}
    QDir            *dir_M_CerebralOrganoids()                      {return &(vDIR_DefaultPaths[i_M_CEREB]);}
    QDir            *dir_M_ManualSegmentation()                     {return &(vDIR_DefaultPaths[i_M_MANSEG]);}
    QDir            *dir_M_CiliaSphereTracker()                     {return &(vDIR_DefaultPaths[i_M_CILTRACK]);}
    QDir            *dir_M_FourierTransformator()                   {return &(vDIR_DefaultPaths[i_M_FOURIER]);}
    QDir            *dir_M_AirDrag()                                {return &(vDIR_DefaultPaths[i_M_AIRDRAG]);}
    QDir            *dir_M_MegaFoci()                               {return &(vDIR_DefaultPaths[i_M_MEGAFOCI]);}
    QDir            *dir_M_Huang()                                  {return &(vDIR_DefaultPaths[i_M_HUANG]);}
    QDir            *dir_M_Softmax()                                {return &(vDIR_DefaultPaths[i_M_SOFTMAX]);}
    void            set_dir_Load(QString path)                      {Path_Set(path, i_LOAD);}
    void            set_dir_Save(QString path)                      {Path_Set(path, i_SAVE);}
    void            set_dir_M_dsDNA(QString path)                   {Path_Set(path, i_M_DSDNA);}
    void            set_dir_M_Mitochondria(QString path)            {Path_Set(path, i_M_MITO);}
    void            set_dir_M_Eilenstein(QString path)              {Path_Set(path, i_M_EILEN);}
    void            set_dir_Examples(QString path)                  {Path_Set(path, i_EXAMPLE);}
    void            set_dir_Steps(QString path)                     {Path_Set(path, i_STEPS);}
    void            set_dir_M_CellColonies(QString path)            {Path_Set(path, i_M_CELLCOL);}
    void            set_dir_M_FociTimeNuclei(QString path)          {Path_Set(path, i_M_FOCITIME);}
    void            set_dir_Analyzer(QString path)                  {Path_Set(path, i_ANALYZER);}
    void            set_dir_Test(QString path)                      {Path_Set(path, i_TEST);}
    void            set_dir_M_IonTracks(QString path)               {Path_Set(path, i_M_TRACKS);}
    void            set_dir_M_Visualization(QString path)           {Path_Set(path, i_M_VIS);}
    void            set_dir_M_Osteoclasts(QString path)             {Path_Set(path, i_M_OSTEO);}
    void            set_dir_M_DnaFibre(QString path)                {Path_Set(path, i_M_DNAFIBER);}
    void            set_dir_M_RadonCurveFit(QString path)           {Path_Set(path, i_M_RADONFIT);}
    void            set_dir_M_SegmentationAssistant(QString path)   {Path_Set(path, i_M_SEGASSI);}
    void            set_dir_M_CerebralOrganoids(QString path)       {Path_Set(path, i_M_CEREB);}
    void            set_dir_M_ManualSegmentation(QString path)      {Path_Set(path, i_M_MANSEG);}
    void            set_dir_M_CiliaSphereTracker(QString path)      {Path_Set(path, i_M_CILTRACK);}
    void            set_dir_M_FourierTransformator(QString path)    {Path_Set(path, i_M_FOURIER);}
    void            set_dir_M_AirDrag(QString path)                 {Path_Set(path, i_M_AIRDRAG);}
    void            set_dir_M_MegaFoci(QString path)                {Path_Set(path, i_M_MEGAFOCI);}
    void            set_dir_M_Huang(QString path)                   {Path_Set(path, i_M_HUANG);}
    void            set_dir_M_Softmax(QString path)                 {Path_Set(path, i_M_SOFTMAX);}

    //SettingsStats
    int             get_UseCounter();
    int             get_ReminderCountdown();
    bool            get_FeedbackIsSent();
    void            set_ReminderCounter(int countdown);
    void            set_ReminderNextAt(int reminderAt);
    void            set_FeedbackIsSent(bool sent);

    //init img
    QFileInfo       *default_img()                                  {return &FI_Image_Init;}
    QFileInfoList   *default_img_list()                             {return &FIL_VD_init;}

    //Stored times (for time measurement of stepwindows)
    unsigned int    time(size_t pos, size_t type);
    void            set_times(size_t pos, size_t type, unsigned int val);

private:
    //Images
    void                    Image_Init();
    vector<Mat>             vMA_Images;     //This is where the displayed images of the proccessing chain (stepwindows) are stored
    Mat                     MA_Init;
    QImage                  *pQI_Init;

    //VisDat
    vector<D_VisDat_Obj>    vVD_Steps;
    D_VisDat_Obj            VD_Init;

    //Times
    vector<array<unsigned int, 5>>  v_times;

    //Defaults
    QString QS_Dir_Config = QDir().homePath() + "/ImageD_Config";
    void                    SettingsStats_Init();
    int                     SettingsStats_UseCounterIncreaseAndCheck();
    void                    SettingsStats_Read();
    void                    SettingsStats_Write();
    void                    Paths_Write();
    void                    Paths_Read();
    void                    Paths_Init();
    void                    Path_Set(QString path, unsigned int index_DIR);
    QFileInfo               FI_Paths;
    QFileInfo               FI_Image_Init;
    QFileInfoList           FIL_VD_init;
    QDir                    DIR_Config;
    vector<QDir>            vDIR_DefaultPaths;

    //Clipboard
    QClipboard      *clip;

    //settings and stats
    QFileInfo               FI_SettingsStats;
    QStringList             QSL_SettingsStats;

    //CONSTANTS

    //Settings & Stats
    enum settings_stats_lines
    {
        SS_USE_COUNTER,
        SS_REMINDER_COUNTDOWN,
        SS_FEEDBACK_IS_SENT,
        SS_NUMBER_OF
    };

    //Dir indices
    enum default_dirs
    {
        i_DEFAULT,
        i_LOAD,
        i_SAVE,
        i_M_DSDNA,
        i_M_MITO,
        i_M_EILEN,
        i_EXAMPLE,
        i_STEPS,
        i_M_CELLCOL,
        i_M_FOCITIME,
        i_ANALYZER,
        i_TEST,
        i_M_TRACKS,
        i_M_VIS,
        i_M_OSTEO,
        i_M_DNAFIBER,
        i_M_RADONFIT,
        i_M_SEGASSI,
        i_M_CEREB,
        i_M_MANSEG,
        i_M_CILTRACK,
        i_M_FOURIER,
        i_M_AIRDRAG,
        i_M_MEGAFOCI,
        i_M_HUANG,
        i_M_SOFTMAX,
        c_COUNT_DIR
    };

};

#endif // D_STORAGE_H
