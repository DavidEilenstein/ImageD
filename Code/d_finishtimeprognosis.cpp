/************************************
 *   added:     17.11.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_finishtimeprognosis.h"

D_FinishTimePrognosis::D_FinishTimePrognosis()
{

}

D_FinishTimePrognosis::D_FinishTimePrognosis(QProgressBar *bar)
{
    set_ProgressBar(bar);
}

D_FinishTimePrognosis::D_FinishTimePrognosis(QProgressBar *bar, size_t step_count)
{
    set_ProgressBar(bar);
    set_StepCount(step_count);
}

D_FinishTimePrognosis::D_FinishTimePrognosis(QProgressBar *bar, size_t step_count, qint64 typical_step_duration_ms)
{
    set_ProgressBar(bar);
    set_StepCount(step_count);
    DefaultStepLength = typical_step_duration_ms;
}

D_FinishTimePrognosis::D_FinishTimePrognosis(size_t step_count)
{
    set_StepCount(step_count);
}

void D_FinishTimePrognosis::set_ProgressBar(QProgressBar *bar)
{
    if(state_bar_set)
        return;

    pProgressBar = bar;
    state_bar_set = true;

    /*
    pProgressBar->setAlignment(Qt::AlignCenter);
    pProgressBar->setStyleSheet(
                "QProgressBar::chunk {"
                "background-color: green;"
                "width: 1px;"
                "margin: 0px;"
                "}");
                */
}

void D_FinishTimePrognosis::set_StepCount(size_t step_count)
{
    StepsMax = step_count;
    state_step_max_set = true;
}

void D_FinishTimePrognosis::start(size_t step_count)
{
    set_StepCount(step_count);
    start();
}

void D_FinishTimePrognosis::start(size_t step_count, qint64 typical_step_duration_ms)
{
    set_StepCount(step_count);
    DefaultStepLength = typical_step_duration_ms;
    start();
}

/*!
 * \brief D_FinishTimePrognosis::start start time measurement
 */
void D_FinishTimePrognosis::start()
{
    if(!state_bar_set || !state_step_max_set || state_running)
        return;

    //save times
    Time_Start = QDateTime::currentDateTime();

    //start timer
    if(state_run_1st_time)
        Timer_Measurement.start();
    else
        Timer_Measurement.restart();
    state_run_1st_time = false;

    //set steps to 0
    StepsExecuted = 0;

    //state
    state_running = true;

    //show in ui
    pProgressBar->setMaximum(static_cast<int>(StepsMax));
    pProgressBar->setValue(0);
    if(DefaultStepLength != 0)
    {
        Time_FinishPrognosis = Time_Start;
        Time_FinishPrognosis.addMSecs(DefaultStepLength * StepsMax);
        pProgressBar->setFormat("Inital end prognosis: " + Time_FinishPrognosis.toString());
        //qDebug() << "D_FinishTimePrognosis::start" << "init time" << DefaultStepLength << "ms" << "step count expected:" << StepsMax;
        //qDebug() << "D_FinishTimePrognosis::start" << "Updated End prognosis at:" << QDateTime::currentDateTime().toString() << "to" << Time_FinishPrognosis.toString();
    }
    else
    {
        pProgressBar->setFormat("Wait 1st iteration for prognosis");
        //qDebug() << "D_FinishTimePrognosis::start" << "no init time for 1st prognosis at:" << QDateTime::currentDateTime().toString();
    }
}

/*!
 * \brief D_FinishTimePrognosis::step call this when one of X steps is done
 */
void D_FinishTimePrognosis::step()
{
    if(!state_running)
        return;

    //count step
    StepsExecuted++;
    pProgressBar->setValue(StepsExecuted);

    if(StepsExecuted == StepsMax)
        return end();
    if(StepsExecuted > StepsMax)
        return quit("Max steps exeeded");

    //mean duration of steps done
    double mean_step_duration = Timer_Measurement.elapsed() / static_cast<double>(StepsExecuted);

    //update prognosis
    Time_FinishPrognosis = Time_Start.addMSecs(static_cast<qint64>(mean_step_duration * StepsMax));

    //set in ui
    pProgressBar->setFormat("End prognosis: " + Time_FinishPrognosis.toString());
    //qDebug() << "D_FinishTimePrognosis::step" << "Step" << StepsExecuted << "of" << StepsMax << "mean step time" << mean_step_duration << "ms" << "total time expected" << static_cast<qint64>(mean_step_duration * StepsMax) << "ms" << "Updated End prognosis at:" << QDateTime::currentDateTime().toString() << "to" << Time_FinishPrognosis.toString();
}

/*!
 * \brief D_FinishTimePrognosis::quit call(ed) when something causes the processing to stop running
 * \param QS_reason_for_qutiing descrition of error
 */
void D_FinishTimePrognosis::quit(QString QS_reason_for_qutiing)
{
    Time_FinishPrognosis = QDateTime::currentDateTime();
    pProgressBar->setFormat(QS_reason_for_qutiing + Time_FinishPrognosis.toString());

    DefaultStepLength = 0;
}

/*!
 * \brief D_FinishTimePrognosis::end successfully end the measurment
 */
void D_FinishTimePrognosis::end()
{
    Time_FinishPrognosis = QDateTime::currentDateTime();
    pProgressBar->setFormat("Finished" + Time_FinishPrognosis.toString());

    DefaultStepLength = 0;
}
