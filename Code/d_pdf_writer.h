/************************************
 *   added:     31.08.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_PDF_WRITER_H
#define D_PDF_WRITER_H

//own
#include <d_enum.h>
#include <d_img_proc.h>
#include <d_error_handler.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QElapsedTimer>
#include <QScrollBar>
#include <QPdfWriter>
#include <QPainter>
#include <QRect>
#include <QDateTime>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

/*!
 * \brief The D_PDF_Writer class Create PDFs by calling simple to use methods.
 * \details Initialize with output path of your choice. Add elements using methods from this class. Call save_PDF"()" to close created PDF.
 */
class D_PDF_Writer : public QPdfWriter
{
public:
    D_PDF_Writer(QString QS_Dest);
    D_PDF_Writer(QFileInfo FI_Dest);

private:
    void init();

public slots:
    int add_Text                    (QString QS_text, int size = -1, int align = Qt::AlignLeft);
    int add_Text                    (QString QS_text, double x1_rel,  double x2_rel,  double y1_rel, double y2_rel, int size = -1, int align = Qt::AlignLeft);

    int add_Headline                (QString QS_text, int size = -1, int align = Qt::AlignCenter);
    int add_Header                  (QString QS_text, int size = -1, int align = Qt::AlignLeft);
    int add_Header_FileDescription  (                 int size = -1, int align = Qt::AlignLeft);
    int add_DateTimeCurrent         (                 int size = -1, int align = Qt::AlignRight);
    int add_DateTime                (QString QS_text, int size = -1, int align = Qt::AlignRight);

    int add_Image(QImage *pQI_img,  QString QS_text = "", int size = -1, int align = Qt::AlignLeft);
    int add_Image(QImage *pQI_img,  double x1_rel,  double x2_rel,  double y1_rel, double y2_rel);
    int add_Image(Mat *pMA_img,     double x1_rel,  double x2_rel,  double y1_rel, double y2_rel);

    int add_NewLine(int count = 1);
    int add_NewPage();

    int save_PDF();

    void set_Margins(int t, int l, int b, int r);
private:

    QRectF                      Rect_FromRelCorrd   (double x1_rel, double x2_rel, double y1_rel,    double y2_rel);
    QRectF                      Rect_FromRelCorrd   (double x1_rel, double x2_rel, double y1_rel,    double y2_rel,     QRect R_Source);
    QRectF                      Rect_FromRelRect    (double x_rel,  double y_rel,  double width_rel, double height_rel);
    QRectF                      Rect_FromRelRect    (double x_rel,  double y_rel,  double width_rel, double height_rel, QRect R_Source);
    QRectF                      Rect_FitToAspectRatio(QRectF R_Target, QRectF R_Source);
    QFileInfo                   FI_Destination;

    QPainter                    PDF_Painter;
    bool                        PDF_Painter_is_active   = false;

    QPagedPaintDevice::PageSize PDF_PageSize            = QPagedPaintDevice::A4;
    int                         PDF_Margin_Top          = 15;
    int                         PDF_Margin_Left         = 15;
    int                         PDF_Margin_Bottom       = 15;
    int                         PDF_Margin_Right        = 15;

    QColor                      PDF_Color               = Qt::black;
    QString                     PDF_Font                = "Times";
    int                         PDF_FontSize_Default    = 10;
    int                         PDF_FontSize_Text       = 10;
    int                         PDF_FontSize_Date       = 10;
    int                         PDF_FontSize_Header     = 12;
    int                         PDF_FontSize_Headline   = 20;
};

#endif // D_PDF_WRITER_H
