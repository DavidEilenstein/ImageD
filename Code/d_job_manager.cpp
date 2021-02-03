/************************************
 *   added:     02.02.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_job_manager.h"

D_Job_Manager::D_Job_Manager(QDir jobs_dir, QString worker_id)
{
    ///save worker id and master dir
    DIR_Master = jobs_dir;
    Worker_ID = worker_id;

    ///create job dir, if not existent yet
    create_JobDir();
}

bool D_Job_Manager::add_job_range(QString QS_VarName, size_t loop_start, size_t loop_end)
{
    ///remove _ characters from name
    QString name_no_underbar;
    while (QS_VarName.contains("_"))
        name_no_underbar = QS_VarName.remove(QS_VarName.lastIndexOf("_"), 1);

    ///check if string is not empty
    if(name_no_underbar.isEmpty())
        return false;

    ///check if name is duplicate
    bool duplicate = false;
    for(int i = 0; i < QSL_JobVar.size() && !duplicate; i++)
        duplicate = name_no_underbar == QSL_JobVar[i];
    if(duplicate)
        return false;

    ///append name, start and end to job var list
    QSL_JobVar.append(QS_VarName);
    vJobVar_Start.push_back(loop_start);
    vJobVar_End.push_back(loop_end);

    return true;
}

bool D_Job_Manager::add_bundle_range(QString QS_VarName, size_t loop_start, size_t loop_end)
{
    ///remove _ characters from name
    QString name_no_underbar;
    while (QS_VarName.contains("_"))
        name_no_underbar = QS_VarName.remove(QS_VarName.lastIndexOf("_"), 1);

    ///check if string is not empty
    if(name_no_underbar.isEmpty())
        return false;

    ///check if name is duplicate
    bool duplicate = false;
    for(int i = 0; i < QSL_BundleVar.size() && !duplicate; i++)
        duplicate = name_no_underbar == QSL_BundleVar[i];
    if(duplicate)
        return false;

    ///append name, start and end to bundle var list
    QSL_BundleVar.append(QS_VarName);
    vBundleVar_Start.push_back(loop_start);
    vBundleVar_End.push_back(loop_end);

    return true;
}

bool D_Job_Manager::start_working()
{
    ///do nothing if master dir not exists
    if(!DIR_Master.exists())
        return false;

    ///create job lists
    return create_JobLists();
}

bool D_Job_Manager::next_Job()
{
    return true;
}



bool D_Job_Manager::create_JobDir()
{
    ///do nothing if dir exists allready
    if(DIR_Master.exists())
        return false;

    ///set names of subdirs
    DIR_Jobs        = QDir(DIR_Master.path() + "/Jobs");
    DIR_Started     = QDir(DIR_Master.path() + "/Started");
    DIR_Finished    = QDir(DIR_Master.path() + "/Finished");

    ///create dir and subdirs
    QDir().mkdir(DIR_Master.path());
    QDir().mkdir(DIR_Jobs.path());
    QDir().mkdir(DIR_Started.path());
    QDir().mkdir(DIR_Finished.path());

    this_is_creator = true;

    return true;
}

bool D_Job_Manager::create_JobLists()
{
    ///do nothing if jobs dir not exists
    if(!DIR_Jobs.exists())
        return false;

    ///loop bundles
    vector<size_t> vBundleVar_Pos = vBundleVar_Start;
    for(size_t i_bundle = 0; i_bundle < vBundleVar_Pos.size(); i_bundle++)
        if(vBundleVar_Pos[i_bundle] < vBundleVar_End[i_bundle])
        {
            ///create a file per bundle
            //find name
            QString QS_Bundle_Path = DIR_Jobs.path() + "/Bundle";
            for(size_t k_bundle = 0; k_bundle < vBundleVar_Pos.size(); k_bundle++)
                QS_Bundle_Path.append("_" + QSL_BundleVar[k_bundle] + QString::number(vBundleVar_Pos[k_bundle]));
            QS_Bundle_Path.append(".txt");
            //open stream
            ofstream OS(QS_Bundle_Path.toStdString());

            ///loop jobs
            vector<size_t> vJobVar_Pos = vJobVar_Start;
            for(size_t i_job = 0; i_job < vJobVar_Pos.size(); i_job++)
                if(vJobVar_Pos[i_job] < vJobVar_End[i_job])
                {
                    for(size_t j_job = 0; j_job < i_job; j_job++)
                        vJobVar_Pos[j_job] = vJobVar_Start[j_job];
                    vJobVar_Pos[i_job]++;
                    i_job = 0;


                }

            //next bundle pos
            for(size_t j_bundle = 0; j_bundle < i_bundle; j_bundle++)
                vBundleVar_Pos[j_bundle] = vBundleVar_Start[j_bundle];
            vBundleVar_Pos[i_bundle]++;
            i_bundle = 0;
        }


    return true;
}
