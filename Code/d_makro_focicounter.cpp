#include "d_makro_focicounter.h"
#include "ui_d_makro_focicounter.h"

D_MAKRO_FociCounter::D_MAKRO_FociCounter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_FociCounter)
{
    ui->setupUi(this);
}

D_MAKRO_FociCounter::~D_MAKRO_FociCounter()
{
    delete ui;
}
