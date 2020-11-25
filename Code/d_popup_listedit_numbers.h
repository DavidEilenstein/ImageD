/************************************
 *   added:     25.11.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_POPUP_LISTEDIT_NUMBERS_H
#define D_POPUP_LISTEDIT_NUMBERS_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_plot.h>
#include <d_stat.h>

//Qt
#include <QDialog>
#include <QComboBox>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QPlainTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QStringList>
#include <QString>

//Qt::Charts
#include <QChartView>
#include <QChart>

//general
#include <vector>

//namespaces
using namespace std;

namespace Ui {
class D_Popup_ListEdit_Numbers;
}

class D_Popup_ListEdit_Numbers : public QDialog
{
    Q_OBJECT

public:
    explicit D_Popup_ListEdit_Numbers(vector<double> *vDataToEdit, QString QS_Title = "Edit list of numbers", QWidget *parent = nullptr);
    ~D_Popup_ListEdit_Numbers();

    vector<uchar>   vData_UChar()   {vector<uchar>  v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<uchar>(    (*vData)[i]); return v;}
    vector<char>    vData_Char()    {vector<char>   v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<char>(     (*vData)[i]); return v;}
    vector<ushort>  vData_UShort()  {vector<ushort> v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<ushort>(   (*vData)[i]); return v;}
    vector<short>   vData_Short()   {vector<short>  v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<short>(    (*vData)[i]); return v;}
    vector<uint>    vData_UInt()    {vector<uint>   v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<uint>(     (*vData)[i]); return v;}
    vector<int>     vData_Int()     {vector<int>    v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<int>(      (*vData)[i]); return v;}
    vector<float>   vData_Float()   {vector<float>  v(vData->size());   for(size_t i = 0; i < vData->size(); i++) v[i] = static_cast<float>(    (*vData)[i]); return v;}
    vector<double>  vData_Double()  {return *vData;}

private slots:
    void Data_2_Ui();
    void Ui_2_Data();


    void on_pushButton_Ok_clicked();

private:
    Ui::D_Popup_ListEdit_Numbers *ui;

    vector<double>  *vData;

    QChartView      *pChartView;

};

#endif // D_POPUP_LISTEDIT_NUMBERS_H
