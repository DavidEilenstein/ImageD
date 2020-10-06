/************************************
 *   added:     09.01.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_TABLE_H
#define D_TABLE_H

//own
#include <d_enum.h>
#include <d_error_handler.h>

//general
#include <iostream>
#include <vector>
#include <fstream>

//Qt
#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileInfo>
#include <QFileDialog>

//namespaces
using namespace std;

/*!
 * \brief The D_Table class Display tables in <a href="https://doc.qt.io/archives/qt-4.8/qtablewidget.html">QTableWidget</a> in the user interface.
 * \details Put a <a href="https://doc.qt.io/archives/qt-4.8/qtablewidget.html">QTableWidget</a> somewhere in the user interface and pass a pointer to it to (<D_Table>"::")n<set_TW>"("<(QTableWidget *TW)")" and changes made to the D_Table will be displayed in the UI
 */
class D_Table : public QWidget
{
    Q_OBJECT
public:

    //constructor
    D_Table();

    //setter
    void            set_TW(QTableWidget *TW);

    void            set_data_d_1D_qs_qsl    (vector<double> v_data,             QString qs_col_name,          QStringList qsl_row_names);
    void            set_data_d_1D_qs_vd     (vector<double> v_data,             QString qs_col_name,          vector<double> v_row_names);
    void            set_data_d_1D_qs_count  (vector<double> v_data,             QString qs_col_name);
    void            set_data_d_1D_qs_step   (vector<double> v_data,             QString qs_col_name,          double row_names_start,        double row_names_step);
    void            set_data_d_2D_qsl_qsl   (vector<vector<double>> vv_data,    QStringList qsl_col_names,    QStringList qsl_row_names);
    void            set_data_d_2D_qsl_vd    (vector<vector<double>> vv_data,    QStringList qsl_col_names,    vector<double> v_row_names);
    void            set_data_d_2D_qsl_count (vector<vector<double>> vv_data,    QStringList qsl_col_names);
    void            set_data_d_2D_vd_vd     (vector<vector<double>> vv_data,    vector<double> v_col_names,   vector<double> v_row_names);
    void            set_data_d_2D_vd_qsl    (vector<vector<double>> vv_data,    vector<double> v_col_names,   QStringList qsl_row_names);
    void            set_data_d_2D_qsl_step  (vector<vector<double>> vv_data,    QStringList qsl_col_names,    double row_names_start,        double row_names_step);

    void            clear_data();

    //getter
    QTableWidget    *get_pTableWidget       ()     {return TW_table;}

    //Save
    QString     Save_Table_Dialog           ();
    QString     Save_Table_Dialog           (QString path_default);
    QString     Save_Table                  ();
    QString     Save_Table                  (QString path);

private:
    bool            TW_is_set = false;
    QTableWidget    *TW_table;

    void Data_2_TableWidget();

    QFileInfo               FI_LastSaved;

    QString                 QS_Name;
    QStringList             QSL_Col_Names;
    QStringList             QSL_Row_Names;
    vector<vector<double>>  vv_Data;

    //Error handler
    D_Error_Handler ER;
    void            ERR(int err, QString func = "not specified", QString detail = "not specified");

};

#endif // D_TABLE_H
