/****************************************************
 *   added:     10.12.2020                          *
 *   author:    David Eilenstein                    *
 *   contact:   David.Eilenstein@stud.h-da.de.de    *
 *   project:   ImageD                              *
 *   facility:  Hochschule Darmstadt, Ger           *
 ****************************************************/


#include "d_makro_huangvisualization.h"
#include "ui_d_makro_huangvisualization.h"

D_MAKRO_HuangVisualization::D_MAKRO_HuangVisualization(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_HuangVisualization)
{
    ui->setupUi(this);
}

D_MAKRO_HuangVisualization::~D_MAKRO_HuangVisualization()
{
    delete ui;
}

void D_MAKRO_HuangVisualization::closeEvent(QCloseEvent *event)
{
    if(ClosingPossible)
    {
        delete ui;
        event->accept();
    }
    else
    {
        event->ignore();
        this->showMinimized();
        //StatusSet("I'll minimze instead to save your data");
    }
}

void D_MAKRO_HuangVisualization::resizeEvent(QResizeEvent *event)
{
    event->accept();
    //Update_Views();
}
