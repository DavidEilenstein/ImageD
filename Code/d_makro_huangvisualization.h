/****************************************************
 *   added:     10.12.2020                          *
 *   author:    David Eilenstein                    *
 *   contact:   David.Eilenstein@stud.h-da.de.de    *
 *   project:   ImageD                              *
 *   facility:  Hochschule Darmstadt, Ger           *
 ****************************************************/

#ifndef D_MAKRO_HUANGVISUALIZATION_H
#define D_MAKRO_HUANGVISUALIZATION_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>
#include <d_img_proc.h>

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
using namespace cv;

namespace Ui {
class D_MAKRO_HuangVisualization;
}

class D_MAKRO_HuangVisualization : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_HuangVisualization(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_MAKRO_HuangVisualization();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private:
    Ui::D_MAKRO_HuangVisualization *ui;
    bool ClosingPossible = false;
};

#endif // D_MAKRO_HUANGVISUALIZATION_H
