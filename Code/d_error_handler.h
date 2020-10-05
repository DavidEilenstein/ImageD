/************************************
 *   added:     12.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_ERROR_HANDLER_H
#define D_ERROR_HANDLER_H

//own
#include <d_enum.h>

//general
#include <iostream>
#include <vector>
#include <fstream>

//Qt
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSizePolicy>

//namespaces
using namespace std;

class D_Error_Handler
{
public:
    D_Error_Handler();

    void ERR(unsigned int err, QString sender, QString func, QString detail);

};

#endif // D_ERROR_HANDLER_H
