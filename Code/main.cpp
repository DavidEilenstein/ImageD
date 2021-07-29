/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "ImageD - Main - Stared ================================================" << endl;

    QApplication a(argc, argv);
    D_MainWindow the_window_to_rule_them_all;
    the_window_to_rule_them_all.show();

    cout << "ImageD - Main - Ended ================================================" << endl;
    return a.exec();
}
