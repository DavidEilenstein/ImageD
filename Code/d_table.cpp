/************************************
 *   added:     09.01.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_table.h"

D_Table::D_Table()
{

}

void D_Table::set_TW(QTableWidget *TW)
{
    TW_table = TW;
    TW_is_set = true;
    clear_data();
}

void D_Table::set_data_d_1D_qs_qsl(vector<double> v_data, QString qs_col_name, QStringList qsl_row_names)
{
    QStringList qsl_col_names;
    qsl_col_names.append(qs_col_name);

    vector<vector<double>> vv_data;
    vv_data.resize(1);
    vv_data[0] = v_data;

    set_data_d_2D_qsl_qsl(
                vv_data,
                qsl_col_names,
                qsl_row_names);
}

void D_Table::set_data_d_1D_qs_vd(vector<double> v_data, QString qs_col_name, vector<double> v_row_names)
{
    QStringList qsl_row_names;
    for(int row = 0; row < v_row_names.size(); row++)
        qsl_row_names.append(QString::number(v_row_names[row]));

    set_data_d_1D_qs_qsl(
                v_data,
                qs_col_name,
                qsl_row_names);
}

void D_Table::set_data_d_1D_qs_count(vector<double> v_data, QString qs_col_name)
{
    QStringList qsl_row_names;
    for(int row = 0; row < v_data.size(); row++)
        qsl_row_names.append(QString::number(row));

    set_data_d_1D_qs_qsl(
                v_data,
                qs_col_name,
                qsl_row_names);
}

void D_Table::set_data_d_1D_qs_step(vector<double> v_data, QString qs_col_name, double row_names_start, double row_names_step)
{
    QStringList qsl_row_names;
    for(int row = 0; row < v_data.size(); row++)
        qsl_row_names.append(QString::number(row_names_start + row * row_names_step));

    set_data_d_1D_qs_qsl(
                v_data,
                qs_col_name,
                qsl_row_names);
}

void D_Table::set_data_d_2D_qsl_qsl(vector<vector<double> > vv_data, QStringList qsl_col_names, QStringList qsl_row_names)
{
    //every other set_data_d method is leading to this one

    vv_Data = vv_data;
    QSL_Col_Names = qsl_col_names;
    QSL_Row_Names = qsl_row_names;

    Data_2_TableWidget();
}

void D_Table::set_data_d_2D_qsl_vd(vector<vector<double> > vv_data, QStringList qsl_col_names, vector<double> v_row_names)
{
    //row names
    QStringList qsl_row_names;
    for(int row = 0; row < v_row_names.size(); row++)
        qsl_row_names.append(QString::number(v_row_names[row]));

    set_data_d_2D_qsl_qsl(
                vv_data,
                qsl_col_names,
                qsl_row_names);
}

void D_Table::set_data_d_2D_qsl_count(vector<vector<double> > vv_data, QStringList qsl_col_names)
{
    //max rows in columns
    int max_rows = static_cast<int>(vv_data[0].size());
    for(int col = 0; col < vv_data.size(); col++)
        if(vv_data[col].size() > max_rows)
            max_rows = static_cast<int>(vv_data[col].size());

    //row names
    QStringList qsl_row_names;
    for(int row = 0; row < max_rows; row++)
        qsl_row_names.append(QString::number(row));

    set_data_d_2D_qsl_qsl(
                vv_data,
                qsl_col_names,
                qsl_row_names);
}

void D_Table::set_data_d_2D_vd_vd(vector<vector<double> > vv_data, vector<double> v_col_names, vector<double> v_row_names)
{

}

void D_Table::set_data_d_2D_vd_qsl(vector<vector<double> > vv_data, vector<double> v_col_names, QStringList qsl_row_names)
{

}

void D_Table::set_data_d_2D_qsl_step(vector<vector<double> > vv_data, QStringList qsl_col_names, double row_names_start, double row_names_step)
{
    if(vv_data.empty())     {clear_data();      return;}

    //max rows in columns
    int max_rows = static_cast<int>(vv_data[0].size());
    for(int col = 0; col < vv_data.size(); col++)
        if(vv_data[col].size() > max_rows)
            max_rows = static_cast<int>(vv_data[col].size());

    //row names
    QStringList qsl_row_names;
    for(int row = 0; row < max_rows; row++)
        qsl_row_names.append(QString::number(row_names_start + row * row_names_step));

    set_data_d_2D_qsl_qsl(
                vv_data,
                qsl_col_names,
                qsl_row_names);
}

void D_Table::clear_data()
{
    vv_Data.clear();
    TW_table->setColumnCount(1);
    TW_table->setRowCount(1);
    TW_table->setItem(0, 0, new QTableWidgetItem("clear"));
    TW_table->setHorizontalHeaderItem(0, new QTableWidgetItem("-"));
    TW_table->setVerticalHeaderItem(0, new QTableWidgetItem("-"));
}

QString D_Table::Save_Table_Dialog()
{
    QString path = QFileDialog::getSaveFileName(
                this,
                "Save Table: " + QS_Name,
                FI_LastSaved.path(),
                tr("Table (*.csv)"));

    if(path == 0)
        return path;

    return Save_Table(path);
}

QString D_Table::Save_Table_Dialog(QString path_default)
{
    QString path = QFileDialog::getSaveFileName(
                this,
                "Save Table: " + QS_Name,
                path_default,
                tr("Table (*.csv)"));

    if(path == 0)
        return path;

    return Save_Table(path);
}

QString D_Table::Save_Table()
{
    return Save_Table(FI_LastSaved.absoluteFilePath());
}

QString D_Table::Save_Table(QString path)
{
    //Errors

    if(path == 0)
    {
        ERR(ER_other, "Save_Table");
        return path;
    }

    if(!path.endsWith(".csv"))
    {
        ERR(ER_type_bad, "Save_Table", "Path must end with '.csv' to save the table.");
        return path;
    }

    //open
    ofstream OS_Save;
    OS_Save.open(path.toStdString());

    //header
    OS_Save << QS_Name.toStdString();

    //colum-names
    OS_Save << ";;";
    for(int col = 0; col < QSL_Col_Names.size(); col++)
        OS_Save << QSL_Col_Names[col].toStdString() << ";";
    OS_Save << "\n";

    //rows
    OS_Save << "\n";
    for(int row = 0; row < QSL_Row_Names.size(); row++)
    {
        //row name
        OS_Save << QSL_Row_Names[row].toStdString() << ";;";

        //column-data, if exists
        for(int col = 0; col < QSL_Col_Names.size(); col++)
            if(row < vv_Data[col].size())
                OS_Save << vv_Data[col][row] << ";";
            else
                OS_Save << ";";

        //new row
        OS_Save << "\n";
    }

    //close
    OS_Save.close();
    return path;
}

void D_Table::Data_2_TableWidget()
{
    //errors
    if(!TW_is_set)                                      {ERR(ER_other,          "Data_2_TableWidget", "TableWidget is not initalized.");          return;}
    if(vv_Data.empty())                                 {clear_data();                                                                            return;}
    if(vv_Data[0].empty())                              {clear_data();                                                                            return;}
    if(QSL_Col_Names.empty())                           {clear_data();                                                                            return;}
    if(vv_Data.size() != QSL_Col_Names.size())          {ERR(ER_size_missmatch, "Data_2_TableWidget", "vv_Data.size() != QSL_Col_Names.size()");  return;}
    for(int col = 0; col < vv_Data.size(); col++)
        if(vv_Data[col].size() != QSL_Row_Names.size()) {ERR(ER_size_missmatch, "Data_2_TableWidget", "vv_Data[" + QString::number(col) + "].size() != QSL_Row_Names.size()"); return;}

    //Columns (1st index)
    TW_table->setColumnCount(QSL_Col_Names.size());
    TW_table->setHorizontalHeaderLabels(QSL_Col_Names);

    //Rows (2nd index)
    TW_table->setRowCount(QSL_Row_Names.size());
    TW_table->setVerticalHeaderLabels(QSL_Row_Names);

    //Data
    for(int col = 0; col < vv_Data.size(); col++)
        for(int row = 0; row < vv_Data[col].size(); row++)
            TW_table->setItem(row, col, new QTableWidgetItem(QString::number(vv_Data[col][row])));
}

void D_Table::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Table", func, detail);
}
