/************************************
 *   added:     17.11.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_FINISHTIMEPROGNOSIS_H
#define D_FINISHTIMEPROGNOSIS_H

//own
#include <d_enum.h>

//Qt
#include <QObject>
#include <QElapsedTimer>
#include <QDateTime>
#include <QDebug>
#include <QProgressBar>

//namespaces
using namespace std;

/*!
 * \brief The D_FinishTimePrognosis class measures the time of processing steps and prognoses the finish time
 * \details results are shown in a progressbar
 */
class D_FinishTimePrognosis : public QObject
{
    Q_OBJECT

public:
    D_FinishTimePrognosis();
    D_FinishTimePrognosis(QProgressBar *bar);
    D_FinishTimePrognosis(QProgressBar *bar, size_t step_count);
    D_FinishTimePrognosis(QProgressBar *bar, size_t step_count, qint64 typical_step_duration_ms);
    D_FinishTimePrognosis(size_t step_count);

    void set_ProgressBar(QProgressBar *bar);

public slots:
    void set_StepCount(size_t step_count);
    void start(size_t step_count);
    void start(size_t step_count, qint64 typical_step_duration_ms);
    void start();
    void step();
    void quit(QString QS_reason_for_qutiing);
    void end();

private:
    bool            state_bar_set = false;
    bool            state_step_max_set = false;
    bool            state_running = false;
    bool            state_run_1st_time = true;

    QProgressBar    *pProgressBar;

    size_t          StepsMax = 0;
    size_t          StepsExecuted = 0;

    QDateTime       Time_Start;
    QDateTime       Time_Running;
    QDateTime       Time_FinishPrognosis;
    QElapsedTimer   Timer_Measurement;

    qint64          DefaultStepLength = 0;
};

#endif // D_FINISHTIMEPROGNOSIS_H
