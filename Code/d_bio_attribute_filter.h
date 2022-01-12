/************************************
 *   added:     12.01.2022          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_ATTRIBUTE_FILTER_H
#define D_BIO_ATTRIBUTE_FILTER_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_bio_enum.h>
#include <d_math.h>

//Qt
#include <QObject>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QInputDialog>
#include <QTextStream>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QComboBox>
#include <QCheckBox>
#include <QGroupBox>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Bio_Attribute_Filter : public QWidget
{
    Q_OBJECT
public:
    explicit D_Bio_Attribute_Filter();
    explicit D_Bio_Attribute_Filter(QGroupBox *ui_box);

    bool set_ui_groupbox(QGroupBox *ui_box);

private slots:


signals:


private:

    bool            Ui_Init();

    //ui elements
    //master
    QGroupBox*      ui_grpbox_master;
    QHBoxLayout*    ui_layoutH_master;
    QVBoxLayout*    ui_layoutV_l;
    QVBoxLayout*    ui_layoutV_r;
    QHBoxLayout*    ui_layoutH_lt;
    QHBoxLayout*    ui_layoutH_lb;
    QHBoxLayout*    ui_layoutH_rt;
    QHBoxLayout*    ui_layoutH_rb;
    QFrame*         ui_line_v;


    //states
    bool            state_grpbox_set = false;
    bool            state_ui_init = false;
};

#endif // D_BIO_ATTRIBUTE_FILTER_H
