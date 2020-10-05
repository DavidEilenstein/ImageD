/************************************
 *   added:     08.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_EILENSTEIN_H
#define D_MAKRO_EILENSTEIN_H

//Qt
#include <QMainWindow>

//own
#include <d_enum.h>
#include <d_viewer.h>
#include <d_img_proc.h>
#include <d_storage.h>
#include <d_error_handler.h>

//basic
#include <vector>
#include <QStringList>
#include <QString>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDir>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

namespace Ui {
class D_MAKRO_Eilenstein;
}

class D_MAKRO_Eilenstein : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_Eilenstein(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_Eilenstein();

    void closeEvent(QCloseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Update_Stack_Count();
    void Update_Image();
    void Update_Ui();

    void on_pushButton_Img_Add_clicked();

    void on_pushButton_img_Clear_clicked();

    void on_comboBox_Img_currentIndexChanged(int index);

    void on_pushButton_Out_Select_clicked();

    void on_pushButton_Out_Open_clicked();

    void on_pushButton_Run_clicked();

    void on_spinBox_Min_valueChanged(int arg1);

    void on_spinBox_Max_valueChanged(int arg1);

    void on_spinBox_Step_valueChanged(int arg1);

    void on_doubleSpinBox_Off_Min_valueChanged(double arg1);

    void on_doubleSpinBox_Off_Max_valueChanged(double arg1);

    void on_doubleSpinBox_Off_Step_valueChanged(double arg1);

private:
    Ui::D_MAKRO_Eilenstein *ui;

    bool                    ClosingPossible = false;

    D_Storage   *pStore;

    D_Viewer    Viewer;
    vector<Mat> v_MA_Img;
    QStringList QSL_Img;

    QString     QS_Out_Path = 0;

    int         size_min    = 3;
    int         size_max    = 15;
    int         size_step   = 2;
    double      off_min     = -16;
    double      off_max     = 16;
    double      off_step    = 4;

};

#endif // D_MAKRO_EILENSTEIN_H
