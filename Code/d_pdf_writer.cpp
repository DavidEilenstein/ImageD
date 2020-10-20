/************************************
 *   added:     31.08.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_pdf_writer.h"

D_PDF_Writer::D_PDF_Writer(QString QS_Dest) :
    QPdfWriter(QS_Dest),
    PDF_Painter(this)
{
    FI_Destination = QFileInfo(QS_Dest);
    init();
}

D_PDF_Writer::D_PDF_Writer(QFileInfo FI_Dest) :
    QPdfWriter(FI_Dest.absoluteFilePath()),
    PDF_Painter(this)
{
    FI_Destination = FI_Dest;
    init();
}

void D_PDF_Writer::init()
{
    this->setPageSize(PDF_PageSize);

    QPagedPaintDevice::Margins PDF_Margins;
    PDF_Margins.left    = PDF_Margin_Left;
    PDF_Margins.top     = PDF_Margin_Top;
    PDF_Margins.bottom  = PDF_Margin_Bottom;
    PDF_Margins.right   = PDF_Margin_Right;
    this->setMargins(PDF_Margins);

    PDF_Painter.setPen(PDF_Color);
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));

    PDF_Painter_is_active = true;
}

int D_PDF_Writer::add_Text(QString QS_text, int size, int align)
{
    if(!PDF_Painter_is_active)
        return ER_other;

    //size
    if(size <= 0)   size = PDF_FontSize_Text;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(PDF_Painter.viewport(), align, QS_text + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_Text(QString QS_text, double x1_rel, double x2_rel, double y1_rel, double y2_rel, int size, int align)
{
    if(!PDF_Painter_is_active)
        return ER_other;

    //size
    if(size <= 0)   size = PDF_FontSize_Text;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(
                Rect_FromRelCorrd(x1_rel, x2_rel, y1_rel, y2_rel),
                align,
                QS_text + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_Headline(QString QS_text, int size, int align)
{
    //size
    if(size <= 0)   size = PDF_FontSize_Headline;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(PDF_Painter.viewport(), align, QS_text + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_Header(QString QS_text, int size, int align)
{
    //size
    if(size <= 0)   size = PDF_FontSize_Header;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(PDF_Painter.viewport(), align, "* * * * * * * * * * * *\n" + QS_text + "\n* * * * * * * * * * * *" + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_Header_FileDescription(int size, int align)
{
    //size
    if(size <= 0)   size = PDF_FontSize_Header;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(PDF_Painter.viewport(), align,
                         FI_Destination.fileName() + "\n" +
                         FI_Destination.absolutePath() + "\n" +
                         QDateTime::currentDateTime().toString() + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_DateTimeCurrent(int size, int align)
{
    return add_DateTime(QDateTime::currentDateTime().toString(), size, align);
}

int D_PDF_Writer::add_DateTime(QString QS_DateTime, int size, int align)
{
    //size
    if(size <= 0)   size = PDF_FontSize_Date;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(PDF_Painter.viewport(), align, QS_DateTime + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_Image(QImage *pQI_img, QString QS_text, int size, int align)
{
    if(!PDF_Painter_is_active)
        return ER_other;

    if(pQI_img->isNull())
        return ER_empty;

    //Source
    QRect R_Source = pQI_img->rect();
    //qDebug() << "Rect Source" << R_Source;

    //Viewport
    QRect R_Viewport(
                PDF_Painter.viewport().x(),
                PDF_Painter.viewport().y(),
                this->width() - PDF_Margin_Left -  PDF_Margin_Right,
                this->height() - PDF_Margin_Top - PDF_Margin_Bottom);
    //qDebug() << "Rect VP" << R_Viewport;

    //
    if(R_Source.width() == 0) R_Source.setWidth(1);
    if(R_Source.height() == 0) R_Source.setHeight(1);

    //Scale
    int w_in = R_Source.width();
    int h_in = R_Source.height();
    int w_out = R_Viewport.width();
    int h_out = R_Viewport.height();
    double w_scale = static_cast<double>(w_out) / w_in;
    double h_scale = static_cast<double>(h_out) / h_in;
    //qDebug() << "scale w/h" << w_scale << h_scale;

    //Target
    QRect R_Target_Img;
    R_Target_Img.setX(PDF_Margin_Left);
    R_Target_Img.setY(PDF_Margin_Top);
    if(w_scale < 1 && h_scale < 1)
    {
        R_Target_Img.setWidth(w_in);
        R_Target_Img.setHeight(h_in);
    }
    else if(w_scale < h_scale)
    {
        R_Target_Img.setWidth(w_out);
        R_Target_Img.setHeight(h_in * w_scale);
    }
    else
    {
        R_Target_Img.setWidth(w_in * h_scale);
        R_Target_Img.setHeight(h_out);
    }
    //qDebug() << "Rect Target" << R_Target;

    //Draw
    PDF_Painter.drawImage(
                R_Target_Img,
                *pQI_img,
                R_Source);

    //check space for text
    if(this->height() - R_Target_Img.height() - PDF_Margin_Top - PDF_Margin_Bottom < size)
        return ER_size_missmatch;

    //Text Target
    QRect R_Target_Txt(
                PDF_Margin_Left,
                PDF_Margin_Top + R_Target_Img.height(),
                this->width() - PDF_Margin_Left - PDF_Margin_Right,
                this->height() - R_Target_Img.height() - PDF_Margin_Top - PDF_Margin_Bottom);

    //Font
    if(size <= 0)   size = PDF_FontSize_Text;
    PDF_Painter.setFont(QFont(PDF_Font, size));

    //write
    PDF_Painter.drawText(R_Target_Txt, align, QS_text + "\n");

    //end
    PDF_Painter.setFont(QFont(PDF_Font, PDF_FontSize_Default));
    return ER_okay;
}

int D_PDF_Writer::add_Image(QImage *pQI_img, double x1_rel, double x2_rel, double y1_rel, double y2_rel)
{
    if(!PDF_Painter_is_active)
        return ER_other;

    if(pQI_img->isNull())
        return ER_empty;

    //Draw
    PDF_Painter.drawImage(
                Rect_FromRelCorrd(x1_rel, x2_rel, y1_rel, y2_rel, pQI_img->rect()),
                *pQI_img,
                pQI_img->rect());

    return ER_okay;
}

int D_PDF_Writer::add_Image(Mat *pMA_img, double x1_rel, double x2_rel, double y1_rel, double y2_rel)
{
    if(pMA_img->empty())    return ER_empty;

    QImage QI_tmp;
    int ER = D_Img_Proc::Convert_Mat_to_QImage(
                &QI_tmp,
                pMA_img);

    if(ER == ER_okay)
        return add_Image(
                    &QI_tmp,
                    x1_rel,
                    x2_rel,
                    y1_rel,
                    y2_rel);
    else
        return ER_other;
}

int D_PDF_Writer::add_NewLine(int count)
{
    if(count < 1)
        count = 1;
    for(int l = 0; l < count; l++)
        add_Text("\n", PDF_FontSize_Default, Qt::AlignLeft);
    return ER_okay;
}

int D_PDF_Writer::add_NewPage()
{
    this->newPage();
    return ER_okay;
}

int D_PDF_Writer::save_PDF()
{
    PDF_Painter.end();
    return ER_okay;
}

void D_PDF_Writer::set_Margins(int t, int l, int b, int r)
{
    PDF_Margin_Top = t;
    PDF_Margin_Left = l;
    PDF_Margin_Bottom = b;
    PDF_Margin_Right = r;

    QPagedPaintDevice::Margins PDF_Margins;
    PDF_Margins.left    = PDF_Margin_Left;
    PDF_Margins.top     = PDF_Margin_Top;
    PDF_Margins.bottom  = PDF_Margin_Bottom;
    PDF_Margins.right   = PDF_Margin_Right;
    this->setMargins(PDF_Margins);
}

QRectF D_PDF_Writer::Rect_FromRelCorrd(double x1_rel, double x2_rel, double y1_rel, double y2_rel)
{
    return Rect_FromRelRect(
                x1_rel,
                y1_rel,
                x2_rel - x1_rel,
                y2_rel - y1_rel);
}

QRectF D_PDF_Writer::Rect_FromRelCorrd(double x1_rel, double x2_rel, double y1_rel, double y2_rel, QRect R_Source)
{
    return Rect_FromRelRect(
                x1_rel,
                y1_rel,
                x2_rel - x1_rel,
                y2_rel - y1_rel,
                R_Source);
}

QRectF D_PDF_Writer::Rect_FromRelRect(double x_rel, double y_rel, double width_rel, double height_rel)
{
    //make sure offset fits
    if(x_rel < 0)       x_rel = 0;
    if(y_rel < 0)       y_rel = 0;
    if(x_rel > 1)       x_rel = 1;
    if(y_rel > 1)       y_rel = 1;

    //make sure size fits
    if(width_rel < 0)           width_rel   = 0;
    if(height_rel < 0)          height_rel  = 0;
    if(x_rel + width_rel > 1)   width_rel   = 1 - x_rel;
    if(y_rel + height_rel > 1)  height_rel  = 1 - y_rel;

    return QRectF(
                this->width()   * x_rel,
                this->height()  * y_rel,
                this->width()   * width_rel,
                this->height()  * height_rel);
}

QRectF D_PDF_Writer::Rect_FromRelRect(double x_rel, double y_rel, double width_rel, double height_rel, QRect R_Source)
{
    return Rect_FitToAspectRatio(
                Rect_FromRelRect(
                    x_rel,
                    y_rel,
                    width_rel,
                    height_rel),
                R_Source);
}

QRectF D_PDF_Writer::Rect_FitToAspectRatio(QRectF R_Target, QRectF R_Source)
{
    //avoid 0-division
    if(R_Source.width() == 0) R_Source.setWidth(1);
    if(R_Source.height() == 0) R_Source.setHeight(1);
    if(R_Target.width() == 0) R_Target.setWidth(1);
    if(R_Target.height() == 0) R_Target.setHeight(1);

    //Scale
    int w_in = R_Source.width();
    int h_in = R_Source.height();
    int w_out = R_Target.width();
    int h_out = R_Target.height();
    double w_scale = static_cast<double>(w_out) / w_in;
    double h_scale = static_cast<double>(h_out) / h_in;

    //Result
    QRect R_Result;
    R_Result.setX(R_Target.x());
    R_Result.setY(R_Target.y());
    if(w_scale < 1 && h_scale < 1)
    {
        R_Result.setWidth(w_in);
        R_Result.setHeight(h_in);
    }
    else if(w_scale < h_scale)
    {
        R_Result.setWidth(w_out);
        R_Result.setHeight(h_in * w_scale);
    }
    else
    {
        R_Result.setWidth(w_in * h_scale);
        R_Result.setHeight(h_out);
    }

    return R_Result;
}

