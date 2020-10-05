/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_storage.h"

D_Storage::D_Storage()
{
    Paths_Init();
    Image_Init();
    SettingsStats_Init();

    clip = QApplication::clipboard();

    //FI_Image_Init.setFile("D:/David_Eilenstein/ImageD/build-ImageD-MSVC17_64bit_custom-Debug/images/ImageD_Init.png");
    D_Img_Proc::Load_From_Path(&MA_Init, FI_Image_Init.absoluteFilePath().toStdString());

    expand();
}

void D_Storage::expand()
{
    vMA_Images.push_back(MA_Init.clone());  //add mat
    vVD_Steps.push_back(VD_Init);           //add VD

    array<unsigned int, 5> time = {0, 0, 0, 0, 0};
    v_times.push_back(time);
}

int D_Storage::get_UseCounter()
{
    bool ok;
    int counter = QSL_SettingsStats[SS_USE_COUNTER].toInt(&ok);
    return ok ? counter : 0;
}

int D_Storage::get_ReminderCountdown()
{
    bool ok;
    int cd = QSL_SettingsStats[SS_REMINDER_COUNTDOWN].toInt(&ok);
    return ok ? cd : 0;
}

bool D_Storage::get_FeedbackIsSent()
{
    bool ok;
    int sent = QSL_SettingsStats[SS_FEEDBACK_IS_SENT].toInt(&ok);
    return ok ? static_cast<bool>(sent) : false;
}

void D_Storage::set_ReminderCounter(int countdown)
{
    QSL_SettingsStats[SS_REMINDER_COUNTDOWN] = QString::number(countdown);
    SettingsStats_Write();
}

void D_Storage::set_ReminderNextAt(int reminderAt)
{
    bool ok;
    int counter = QSL_SettingsStats[SS_USE_COUNTER].toInt(&ok);
    if(!ok)
        counter = 0;

    QSL_SettingsStats[SS_REMINDER_COUNTDOWN] = QString::number(reminderAt - counter);
    SettingsStats_Write();
}

void D_Storage::set_FeedbackIsSent(bool sent)
{
    QSL_SettingsStats[SS_FEEDBACK_IS_SENT] = QString::number(static_cast<int>(sent));
    SettingsStats_Write();
}

unsigned int D_Storage::time(size_t pos, size_t type)
{
    if(v_times.size() <= pos || type > 4)
    {
        qDebug() << "time out of range! (get)";
        return 0;
    }
    else
    {
        return v_times[pos][type];
    }
}

void D_Storage::set_times(size_t pos, size_t type, unsigned int val)
{
    if(v_times.size() <= pos || type > 4)
    {
        qDebug() << "time out of range! (set)";
    }
    else
    {
        v_times[pos][type] = val;
    }
}

void D_Storage::Image_Init()
{
    QImage QI = QImage(":/Init_2D/VD_init_2d_logo.png");
    QString path = DIR_Config.path() + "/VD_init_2d_logo.png";
    QI.save(path, 0, -1);
    FI_Image_Init.setFile(path);

    //VisDat stack to init to config folder
    QStringList QSL_VDinit = {
        ":/Init_3D/VD_init_3d_00.png",
        ":/Init_3D/VD_init_3d_01.png",
        ":/Init_3D/VD_init_3d_02.png",
        ":/Init_3D/VD_init_3d_03.png",
        ":/Init_3D/VD_init_3d_04.png",
        ":/Init_3D/VD_init_3d_05.png",
        ":/Init_3D/VD_init_3d_06.png",
        ":/Init_3D/VD_init_3d_07.png",
        ":/Init_3D/VD_init_3d_08.png",
        ":/Init_3D/VD_init_3d_09.png",
        ":/Init_3D/VD_init_3d_10.png",
        ":/Init_3D/VD_init_3d_11.png",
        ":/Init_3D/VD_init_3d_12.png",
    };
    FIL_VD_init.clear();
    for(int i = 0; i < QSL_VDinit.size(); i++)
    {
        QI = QImage(QSL_VDinit[i]);
        if(i < 10)
            path = DIR_Config.path() + "/VD_0" + QString::number(i) + ".png";
        else
            path = DIR_Config.path() + "/VD_" + QString::number(i) + ".png";
        //qDebug() << "D_Storage" << "Image_Init" << "save VD init img to path:" << path;
        QI.save(path, 0, -1);
        FIL_VD_init.append(QFileInfo(path));
    }

    //VD from images in config folder
    D_VisDat_Proc::Create_VD_List(
                &VD_Init,
                FIL_VD_init,
                c_DIM_Z,
                c_DIM_X,
                c_DIM_Y);
}

void D_Storage::SettingsStats_Init()
{
    //file name
    FI_SettingsStats.setFile(QS_Dir_Config + "/Settings_and_Stats.txt");

    //default content
    for(int i = 0; i < SS_NUMBER_OF; i++)
        QSL_SettingsStats.append("");

    //specilized content (just to init with something that can be interpreted)
    QSL_SettingsStats[SS_USE_COUNTER] = "0";
    QSL_SettingsStats[SS_REMINDER_COUNTDOWN] = "10";
    QSL_SettingsStats[SS_FEEDBACK_IS_SENT] = "0";

    //if some real content exists -> read it
    if(FI_SettingsStats.exists())
        SettingsStats_Read();

    //increase use counter
    SettingsStats_UseCounterIncreaseAndCheck();

    //write best content availiable (creates file, if not existent)
    SettingsStats_Write();
}

int D_Storage::SettingsStats_UseCounterIncreaseAndCheck()
{
    //read
    bool ok;
    int use_counter = QSL_SettingsStats[SS_USE_COUNTER].toInt(&ok);
    if(!ok) use_counter = 0;

    int reminder_countdown = QSL_SettingsStats[SS_REMINDER_COUNTDOWN].toInt(&ok);
    if(!ok) reminder_countdown = 10;

    //change
    use_counter++;
    reminder_countdown--;

    //check
    qDebug() << "You use ImageD for the " << QString::number(use_counter) << ". time.";


    //write
    QSL_SettingsStats[SS_USE_COUNTER] = QString::number(use_counter);
    QSL_SettingsStats[SS_REMINDER_COUNTDOWN] = QString::number(reminder_countdown);

    //return
    return use_counter;
}

void D_Storage::SettingsStats_Read()
{
    if(FI_SettingsStats.exists())
    {
        QFile F_SettingsStats(FI_SettingsStats.absoluteFilePath());
        if (F_SettingsStats.open(QIODevice::ReadOnly))
        {
            QTextStream TS_SettingsStats(&F_SettingsStats);

            for(size_t i = 0; i < SS_NUMBER_OF && !TS_SettingsStats.atEnd(); i++)
                QSL_SettingsStats[i] = TS_SettingsStats.readLine();

           F_SettingsStats.close();
        }
    }
}

void D_Storage::SettingsStats_Write()
{
    QFile F_SettingsStats(FI_SettingsStats.absoluteFilePath());
    if(F_SettingsStats.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        QTextStream TS_SettingsStats(&F_SettingsStats);
        for(size_t i = 0; i < SS_NUMBER_OF && i < static_cast<size_t>(QSL_SettingsStats.size()); i++)
        {
            TS_SettingsStats << QSL_SettingsStats[i];
            TS_SettingsStats << "\r\n";
        }
    }
}

void D_Storage::Paths_Write()
{
    QFile F_Paths(FI_Paths.absoluteFilePath());
    if (F_Paths.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        QTextStream TS_Paths(&F_Paths);
        for(unsigned int ld = 0; ld < c_COUNT_DIR; ld++)
        {
            TS_Paths << vDIR_DefaultPaths[ld].absolutePath();
            TS_Paths << "\r\n";
        }
    }
}

void D_Storage::Paths_Read()
{
    FI_Paths.setFile(QS_Dir_Config + "/Default_Paths.txt");
    if(FI_Paths.exists())
    {
        QFile F_Paths(FI_Paths.absoluteFilePath());
        if (F_Paths.open(QIODevice::ReadOnly))
        {
            QTextStream TS_Paths(&F_Paths);

            for(unsigned int ld = 0; ld < c_COUNT_DIR && !TS_Paths.atEnd(); ld++)
                vDIR_DefaultPaths[ld].setPath(TS_Paths.readLine());

           F_Paths.close();
        }
    }

    Paths_Write();
}


void D_Storage::Paths_Init()
{
    //Get/Create Config Dir
    if(!QDir(QS_Dir_Config).exists())
        QDir().mkdir(QS_Dir_Config);
    DIR_Config.setPath(QS_Dir_Config);

    //Init with default path (same as config)
    vDIR_DefaultPaths.resize(c_COUNT_DIR);
    for(size_t d = 0; d < c_COUNT_DIR; d++)
        vDIR_DefaultPaths[d].setPath(QS_Dir_Config);

    //Read existing path
    Paths_Read();
}

void D_Storage::Path_Set(QString path, unsigned int index_DIR)
{
    if(path.isEmpty())
        return;

    if(index_DIR > c_COUNT_DIR)
        return;

    QFileInfo FI_Path(path);
    if(!FI_Path.isDir())
        path = FI_Path.dir().path();

    vDIR_DefaultPaths[index_DIR].setPath(path);
    Paths_Write();
}
