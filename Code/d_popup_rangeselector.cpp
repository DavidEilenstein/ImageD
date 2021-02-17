/************************************
 *   added:     17.02.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_rangeselector.h"
#include "ui_d_popup_rangeselector.h"

D_PopUp_RangeSelector::D_PopUp_RangeSelector(Vec<int, c_DIM_NUMBER_OF> *selected_start, Vec<int, c_DIM_NUMBER_OF> *selected_end, Vec<int, c_DIM_NUMBER_OF> limit_min, Vec<int, c_DIM_NUMBER_OF> limit_max, QString title, bool select_x, bool select_y, bool select_z, bool select_t, bool select_s, bool select_p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_PopUp_RangeSelector)
{
    ///setup and show ui
    ui->setupUi(this);
    setWindowTitle(title);
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));

    ///container with spinboxes
    //from
    v_SpinFrom.resize(c_DIM_NUMBER_OF);
    v_SpinFrom[c_DIM_X] = ui->spinBox_X_from;
    v_SpinFrom[c_DIM_Y] = ui->spinBox_Y_from;
    v_SpinFrom[c_DIM_Z] = ui->spinBox_Z_from;
    v_SpinFrom[c_DIM_T] = ui->spinBox_T_from;
    v_SpinFrom[c_DIM_S] = ui->spinBox_S_from;
    v_SpinFrom[c_DIM_P] = ui->spinBox_P_from;
    //to
    v_SpinTo.resize(c_DIM_NUMBER_OF);
    v_SpinTo[c_DIM_X] = ui->spinBox_X_to;
    v_SpinTo[c_DIM_Y] = ui->spinBox_Y_to;
    v_SpinTo[c_DIM_Z] = ui->spinBox_Z_to;
    v_SpinTo[c_DIM_T] = ui->spinBox_T_to;
    v_SpinTo[c_DIM_S] = ui->spinBox_S_to;
    v_SpinTo[c_DIM_P] = ui->spinBox_P_to;

    ///container with sliders
    //from
    vector<QSlider*> v_SliderFrom(c_DIM_NUMBER_OF);
    v_SliderFrom[c_DIM_X] = ui->horizontalSlider_X_from;
    v_SliderFrom[c_DIM_Y] = ui->horizontalSlider_Y_from;
    v_SliderFrom[c_DIM_Z] = ui->horizontalSlider_Z_from;
    v_SliderFrom[c_DIM_T] = ui->horizontalSlider_T_from;
    v_SliderFrom[c_DIM_S] = ui->horizontalSlider_S_from;
    v_SliderFrom[c_DIM_P] = ui->horizontalSlider_P_from;
    //to
    vector<QSlider*> v_SliderTo(c_DIM_NUMBER_OF);
    v_SliderTo[c_DIM_X] = ui->horizontalSlider_X_to;
    v_SliderTo[c_DIM_Y] = ui->horizontalSlider_Y_to;
    v_SliderTo[c_DIM_Z] = ui->horizontalSlider_Z_to;
    v_SliderTo[c_DIM_T] = ui->horizontalSlider_T_to;
    v_SliderTo[c_DIM_S] = ui->horizontalSlider_S_to;
    v_SliderTo[c_DIM_P] = ui->horizontalSlider_P_to;

    ///containers with labels
    //extends
    v_LabelExtend.resize(c_DIM_NUMBER_OF);
    v_LabelExtend[c_DIM_X] = ui->label_X_ext;
    v_LabelExtend[c_DIM_Y] = ui->label_Y_ext;
    v_LabelExtend[c_DIM_Z] = ui->label_Z_ext;
    v_LabelExtend[c_DIM_T] = ui->label_T_ext;
    v_LabelExtend[c_DIM_S] = ui->label_S_ext;
    v_LabelExtend[c_DIM_P] = ui->label_P_ext;
    //impacts
    v_LabelImpact.resize(c_DIM_NUMBER_OF);
    v_LabelImpact[c_DIM_X] = ui->label_X_imp;
    v_LabelImpact[c_DIM_Y] = ui->label_Y_imp;
    v_LabelImpact[c_DIM_Z] = ui->label_Z_imp;
    v_LabelImpact[c_DIM_T] = ui->label_T_imp;
    v_LabelImpact[c_DIM_S] = ui->label_S_imp;
    v_LabelImpact[c_DIM_P] = ui->label_P_imp;

    ///enable/disable dim selection
    ui->groupBox_X->setEnabled(select_x && (limit_min[c_DIM_X] < limit_max[c_DIM_X]));
    ui->groupBox_Y->setEnabled(select_y && (limit_min[c_DIM_Y] < limit_max[c_DIM_Y]));
    ui->groupBox_Z->setEnabled(select_z && (limit_min[c_DIM_Z] < limit_max[c_DIM_Z]));
    ui->groupBox_T->setEnabled(select_t && (limit_min[c_DIM_T] < limit_max[c_DIM_T]));
    ui->groupBox_S->setEnabled(select_s && (limit_min[c_DIM_S] < limit_max[c_DIM_S]));
    ui->groupBox_P->setEnabled(select_p && (limit_min[c_DIM_P] < limit_max[c_DIM_P]));

    ///save pointer to extern range
    v_from_ext = selected_start;
    v_to_ext = selected_end;

    ///limit extern range to selectable
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if((*v_from_ext)[d] < limit_min[d]) (*v_from_ext)[d] = limit_min[d];
        if((*v_to_ext)[d]   > limit_max[d]) (*v_to_ext)[d]   = limit_max[d];
    }

    ///set ranges and starting values of spinboxes/sliders
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        v_SpinFrom[d]->setMinimum(limit_min[d]);
        v_SpinFrom[d]->setMaximum(limit_max[d]);
        v_SliderFrom[d]->setMinimum(limit_min[d]);
        v_SliderFrom[d]->setMaximum(limit_max[d]);

        v_SpinTo[d]->setMinimum(limit_min[d]);
        v_SpinTo[d]->setMaximum(limit_max[d]);
        v_SliderTo[d]->setMinimum(limit_min[d]);
        v_SliderTo[d]->setMaximum(limit_max[d]);

        v_SpinFrom[d]->setValue((*v_from_ext)[d]);
        v_SpinTo[d]->setValue((*v_to_ext)[d]);
    }
}

D_PopUp_RangeSelector::~D_PopUp_RangeSelector()
{
    delete ui;
}

int D_PopUp_RangeSelector::extent(size_t d)
{
    return v_SpinTo[d]->value() - v_SpinFrom[d]->value() + 1;
}

double D_PopUp_RangeSelector::impact(size_t d)
{
    return extent(d) > 0 ? 1.0/extent(d) : 0.0;
}

int D_PopUp_RangeSelector::volume()
{
    int vol = 1;
    for(size_t d = 0; d < c_DIM_NUMBER_OF; d++)
        vol *= extent(d);
    return vol;
}

int D_PopUp_RangeSelector::dimensionality()
{
    int dims = 0;
    for(size_t d = 0; d < c_DIM_NUMBER_OF; d++)
        if(extent(d) > 1)
            dims++;
    return dims;
}

void D_PopUp_RangeSelector::extend2ui(int d)
{
    v_LabelExtend[d]->setText("Extend: " + QString::number(extent(d)));
}

void D_PopUp_RangeSelector::impact2ui(int d)
{
    v_LabelImpact[d]->setText("Change impact: " + QString::number(static_cast<int>(impact(d) * 1000.0)/10.0) + "%");
}

void D_PopUp_RangeSelector::volume2ui()
{
    ui->label_Volume->setText("Volume: " + QString::number(volume()));
}

void D_PopUp_RangeSelector::dimensionality2ui()
{
    ui->label_Dims->setText(QString::number(dimensionality()) + "D");
}

void D_PopUp_RangeSelector::change_from(int d, int val)
{
    if(val > v_SpinTo[d]->value())
        v_SpinTo[d]->setValue(val);

    (*v_from_ext)[d] = val;

    extend2ui(d);
    impact2ui(d);
    volume2ui();
    dimensionality2ui();
}

void D_PopUp_RangeSelector::change_to(int d, int val)
{
    if(val < v_SpinFrom[d]->value())
        v_SpinFrom[d]->setValue(val);

    (*v_to_ext)[d] = val;

    extend2ui(d);
    impact2ui(d);
    volume2ui();
    dimensionality2ui();
}

void D_PopUp_RangeSelector::on_spinBox_X_from_valueChanged(int arg1)
{
    change_from(c_DIM_X, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_X_to_valueChanged(int arg1)
{
    change_to(c_DIM_X, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_Y_from_valueChanged(int arg1)
{
    change_from(c_DIM_Y, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_Y_to_valueChanged(int arg1)
{
    change_to(c_DIM_Y, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_Z_from_valueChanged(int arg1)
{
    change_from(c_DIM_Z, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_Z_to_valueChanged(int arg1)
{
    change_to(c_DIM_Z, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_T_from_valueChanged(int arg1)
{
    change_from(c_DIM_T, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_T_to_valueChanged(int arg1)
{
    change_to(c_DIM_T, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_S_from_valueChanged(int arg1)
{
    change_from(c_DIM_S, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_S_to_valueChanged(int arg1)
{
    change_to(c_DIM_S, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_P_from_valueChanged(int arg1)
{
    change_from(c_DIM_P, arg1);
}

void D_PopUp_RangeSelector::on_spinBox_P_to_valueChanged(int arg1)
{
    change_to(c_DIM_P, arg1);
}

void D_PopUp_RangeSelector::on_pushButton_Done_clicked()
{
    close();
}
