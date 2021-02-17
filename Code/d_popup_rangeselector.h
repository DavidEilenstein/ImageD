/************************************
 *   added:     17.02.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_POPUP_RANGESELECTOR_H
#define D_POPUP_RANGESELECTOR_H


//own
#include <d_enum.h>
#include <d_visdat_dim.h>
#include <d_visdat_range.h>

//general
#include <vector>

//Qt
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QGroupBox>
#include <QPushButton>

//namespaces
using namespace std;

namespace Ui {
class D_PopUp_RangeSelector;
}

/*!
 * \brief The D_PopUp_RangeSelector class popup to slect an abstract subvolume in a volume
 */
class D_PopUp_RangeSelector : public QDialog
{
    Q_OBJECT

public:
    explicit D_PopUp_RangeSelector(
            Vec<int, c_DIM_NUMBER_OF> *selected_start,
            Vec<int, c_DIM_NUMBER_OF> *selected_end,
            Vec<int, c_DIM_NUMBER_OF> limit_min,
            Vec<int, c_DIM_NUMBER_OF> limit_max,
            QString title,
            bool select_x = false, bool select_y = false, bool select_z = false, bool select_t = false, bool select_s = false, bool select_p = false,
            QWidget *parent = nullptr);
    ~D_PopUp_RangeSelector();

private slots:
    void on_spinBox_X_from_valueChanged(int arg1);
    void on_spinBox_X_to_valueChanged(int arg1);
    void on_spinBox_Y_from_valueChanged(int arg1);
    void on_spinBox_Y_to_valueChanged(int arg1);
    void on_spinBox_Z_from_valueChanged(int arg1);
    void on_spinBox_Z_to_valueChanged(int arg1);
    void on_spinBox_T_from_valueChanged(int arg1);
    void on_spinBox_T_to_valueChanged(int arg1);
    void on_spinBox_S_from_valueChanged(int arg1);
    void on_spinBox_S_to_valueChanged(int arg1);
    void on_spinBox_P_from_valueChanged(int arg1);
    void on_spinBox_P_to_valueChanged(int arg1);

    void on_pushButton_Done_clicked();

private:
    Ui::D_PopUp_RangeSelector *ui;

    Vec<int, c_DIM_NUMBER_OF>* v_from_ext;
    Vec<int, c_DIM_NUMBER_OF>* v_to_ext;

    vector<QSpinBox*>   v_SpinFrom;
    vector<QSpinBox*>   v_SpinTo;
    vector<QLabel*>     v_LabelExtend;
    vector<QLabel*>     v_LabelImpact;

    int extent(size_t d);
    double impact(size_t d);
    int volume();
    int dimensionality();

    void extend2ui(int d);
    void impact2ui(int d);
    void volume2ui();
    void dimensionality2ui();

    void change_from(int d, int val);
    void change_to(int d, int val);
};

#endif // D_POPUP_RANGESELECTOR_H
