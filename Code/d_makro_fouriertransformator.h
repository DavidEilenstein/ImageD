/************************************************
 *   added:     05.06.2020                      *
 *   author:    David Eilenstein                *
 *   contact:   David.Eilenstein@stud.h-da.de   *
 *   project:   ImageD                          *
 *   facility:  Hochschule Darmstadt, Ger       *
 ************************************************/

#ifndef D_MAKRO_FOURIERTRANSFORMATOR_H
#define D_MAKRO_FOURIERTRANSFORMATOR_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>
#include <d_popup_listedit.h>
#include <d_videoslicer.h>
#include <d_videowriter.h>

//Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QComboBox>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QInputDialog>
#include <qplaintextedit.h>
#include <QColorDialog>

//Qt::Charts
#include <QChartView>
#include <QChart>

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

namespace Ui {
class D_MAKRO_FourierTransformator;
}

class D_MAKRO_FourierTransformator : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_FourierTransformator(QWidget *parent = nullptr);
    ~D_MAKRO_FourierTransformator();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Update_Ui();
    
private:
    Ui::D_MAKRO_FourierTransformator *ui;
    bool ClosingPossible = false;
};

#endif // D_MAKRO_FOURIERTRANSFORMATOR_H
