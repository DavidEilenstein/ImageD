/************************************
 *   added:     09.12.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_POPUP_LISTSELECT_H
#define D_POPUP_LISTSELECT_H

//own
#include <d_enum.h>

//general
#include <vector>

//Qt
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

//namespaces
using namespace std;

namespace Ui {
class D_Popup_ListSelect;
}

/*!
 * \brief The D_Popup_ListSelect class Lets the user choose an entry from a <a href="https://doc.qt.io/qt-5/qstringlist.html">QStringList</a>
 * \details Pass a <a href="https://doc.qt.io/qt-5/qstringlist.html">QStringList</a> and a pointer to an index corresponding to that list. The user may choose an entry from the list by using a user interface popup.
 */
class D_Popup_ListSelect : public QDialog
{
    Q_OBJECT

public:
    explicit D_Popup_ListSelect(QString Title, int *index, QStringList Names, int init_index, QWidget *parent = nullptr);
    ~D_Popup_ListSelect();

private slots:
    void on_pushButton_Done_clicked();

    void on_comboBox_List_currentIndexChanged(int index);

private:
    Ui::D_Popup_ListSelect *ui;
    int *index_selected;
    QStringList QSL_Names;};

#endif // D_POPUP_LISTSELECT_H
