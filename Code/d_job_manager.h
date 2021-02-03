/************************************
 *   added:     02.02.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_JOB_MANAGER_H
#define D_JOB_MANAGER_H

//own
#include <d_enum.h>
#include <d_stat.h>

//Qt
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QInputDialog>
#include <QTextStream>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//namespaces
using namespace std;

/*!
 * \brief The D_Job_Manager class Manger for working jobs with multiple workers (i.e. PCs). WIP
 */
class D_Job_Manager
{
public:

    D_Job_Manager(QDir jobs_dir, QString worker_id);

    bool            add_job_range       (QString QS_VarName, size_t loop_start, size_t loop_end);
    bool            add_bundle_range    (QString QS_VarName, size_t loop_start, size_t loop_end);
    bool            start_working();
    bool            next_Job            ();
    QString         get_JobString       ();
    vector<size_t>  get_JobVector       ();
    bool            finish_Job          (QString job);

private:

    bool            create_JobDir       ();
    bool            create_JobLists     ();

    bool            this_is_creator = false;

    QString Worker_ID = "";

    QDir DIR_Master;
    QDir DIR_Jobs;
    QDir DIR_Started;
    QDir DIR_Finished;

    QStringList QSL_BundleVar;
    vector<size_t> vBundleVar_Start;
    vector<size_t> vBundleVar_End;

    QStringList QSL_JobVar;
    vector<size_t> vJobVar_Start;
    vector<size_t> vJobVar_End;

};

#endif // D_JOB_MANAGER_H
