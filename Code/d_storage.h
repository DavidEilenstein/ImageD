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
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

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
    QDir            *dir_byIndex(int dir_index)                     {return &(vDIR_DefaultPaths[dir_index > 0 && dir_index < dir_NUMBER_OF ? dir_index : 0]);}
    QDir            *dir_Config()                                   {return &DIR_Config;}
    QDir            *dir_Default()                                  {return dir_byIndex(dir_DEFAULT);}
    QDir            *dir_Load()                                     {return dir_byIndex(dir_LOAD);}
    QDir            *dir_Save()                                     {return dir_byIndex(dir_SAVE);}
    QDir            *dir_M_dsDNA()                                  {return dir_byIndex(dir_M_DSDNA);}
    QDir            *dir_M_Mitochondria()                           {return dir_byIndex(dir_M_MITO);}
    QDir            *dir_M_Eilenstein()                             {return dir_byIndex(dir_M_EILEN);}
    QDir            *dir_Examples()                                 {return dir_byIndex(dir_EXAMPLE);}
    QDir            *dir_Steps()                                    {return dir_byIndex(dir_STEPS);}
    QDir            *dir_M_CellColonies()                           {return dir_byIndex(dir_M_CELLCOL);}
    QDir            *dir_M_FociTimeNuclei()                         {return dir_byIndex(dir_M_FOCITIME);}
    QDir            *dir_Analyzer()                                 {return dir_byIndex(dir_ANALYZER);}
    QDir            *dir_Test()                                     {return dir_byIndex(dir_TEST);}
    QDir            *dir_M_IonTracks()                              {return dir_byIndex(dir_M_TRACKS);}
    QDir            *dir_M_Visualization()                          {return dir_byIndex(dir_M_VIS);}
    QDir            *dir_M_Osteoclasts()                            {return dir_byIndex(dir_M_OSTEO);}
    QDir            *dir_M_DnaFibre()                               {return dir_byIndex(dir_M_DNAFIBER);}
    QDir            *dir_M_RadonCurveFit()                          {return dir_byIndex(dir_M_RADONFIT);}
    QDir            *dir_M_SegmentationAssistant()                  {return dir_byIndex(dir_M_SEGASSI);}
    QDir            *dir_M_CerebralOrganoids()                      {return dir_byIndex(dir_M_CEREB);}
    QDir            *dir_M_ManualSegmentation()                     {return dir_byIndex(dir_M_MANSEG);}
    QDir            *dir_M_CiliaSphereTracker()                     {return dir_byIndex(dir_M_CILTRACK);}
    QDir            *dir_M_FourierTransformator()                   {return dir_byIndex(dir_M_FOURIER);}
    QDir            *dir_M_AirDrag()                                {return dir_byIndex(dir_M_AIRDRAG);}
    QDir            *dir_M_MegaFoci_Images()                        {return dir_byIndex(dir_M_MEGAFOCI_IMG);}
    QDir            *dir_M_MegaFoci_Results()                       {return dir_byIndex(dir_M_MEGAFOCI_RES);}
    QDir            *dir_M_Huang()                                  {return dir_byIndex(dir_M_HUANG);}
    QDir            *dir_M_Softmax()                                {return dir_byIndex(dir_M_SOFTMAX);}

    void            set_dir_byIndex(QString path, int dir_index)    {Path_Set(path, dir_index > 0 && dir_index < dir_NUMBER_OF ? dir_index : 0);}
    void            set_dir_Load(QString path)                      {set_dir_byIndex(path, dir_LOAD);}
    void            set_dir_Save(QString path)                      {set_dir_byIndex(path, dir_SAVE);}
    void            set_dir_M_dsDNA(QString path)                   {set_dir_byIndex(path, dir_M_DSDNA);}
    void            set_dir_M_Mitochondria(QString path)            {set_dir_byIndex(path, dir_M_MITO);}
    void            set_dir_M_Eilenstein(QString path)              {set_dir_byIndex(path, dir_M_EILEN);}
    void            set_dir_Examples(QString path)                  {set_dir_byIndex(path, dir_EXAMPLE);}
    void            set_dir_Steps(QString path)                     {set_dir_byIndex(path, dir_STEPS);}
    void            set_dir_M_CellColonies(QString path)            {set_dir_byIndex(path, dir_M_CELLCOL);}
    void            set_dir_M_FociTimeNuclei(QString path)          {set_dir_byIndex(path, dir_M_FOCITIME);}
    void            set_dir_Analyzer(QString path)                  {set_dir_byIndex(path, dir_ANALYZER);}
    void            set_dir_Test(QString path)                      {set_dir_byIndex(path, dir_TEST);}
    void            set_dir_M_IonTracks(QString path)               {set_dir_byIndex(path, dir_M_TRACKS);}
    void            set_dir_M_Visualization(QString path)           {set_dir_byIndex(path, dir_M_VIS);}
    void            set_dir_M_Osteoclasts(QString path)             {set_dir_byIndex(path, dir_M_OSTEO);}
    void            set_dir_M_DnaFibre(QString path)                {set_dir_byIndex(path, dir_M_DNAFIBER);}
    void            set_dir_M_RadonCurveFit(QString path)           {set_dir_byIndex(path, dir_M_RADONFIT);}
    void            set_dir_M_SegmentationAssistant(QString path)   {set_dir_byIndex(path, dir_M_SEGASSI);}
    void            set_dir_M_CerebralOrganoids(QString path)       {set_dir_byIndex(path, dir_M_CEREB);}
    void            set_dir_M_ManualSegmentation(QString path)      {set_dir_byIndex(path, dir_M_MANSEG);}
    void            set_dir_M_CiliaSphereTracker(QString path)      {set_dir_byIndex(path, dir_M_CILTRACK);}
    void            set_dir_M_FourierTransformator(QString path)    {set_dir_byIndex(path, dir_M_FOURIER);}
    void            set_dir_M_AirDrag(QString path)                 {set_dir_byIndex(path, dir_M_AIRDRAG);}
    void            set_dir_M_MegaFoci_Images(QString path)         {set_dir_byIndex(path, dir_M_MEGAFOCI_IMG);}
    void            set_dir_M_MegaFoci_Results(QString path)        {set_dir_byIndex(path, dir_M_MEGAFOCI_RES);}
    void            set_dir_M_Huang(QString path)                   {set_dir_byIndex(path, dir_M_HUANG);}
    void            set_dir_M_Softmax(QString path)                 {set_dir_byIndex(path, dir_M_SOFTMAX);}

    //SettingsStats
    int             get_UseCounter();
    int             get_ReminderCountdown();
    bool            get_FeedbackIsSent();
    void            set_ReminderCounter(int countdown);
    void            set_ReminderNextAt(int reminderAt);
    void            set_FeedbackIsSent(bool sent);
    size_t          PluginLastUsed_Get();
    void            PluginLastUsed_Set(size_t index);

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
        SS_PLUGIN_LAST_USED,
        SS_NUMBER_OF
    };
};

#endif // D_STORAGE_H
