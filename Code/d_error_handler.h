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
#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QSizePolicy>
#include <QFileInfo>
#include <QDateTime>

//namespaces
using namespace std;

/*!
 * \brief The D_Error_Handler class takes error codes from D_ERROR_ENUM and shows a popup if an error occures.
 * \details Create an instance of this in your class and call you possibly error code returning functionsin its ::ERR method.
 */
class D_Error_Handler
{

public:
    D_Error_Handler();

    void ERR(int err, QString sender, QString func, QString detail);
    void set_Popup_active(bool show_pop)            {err_popup  = show_pop;}
    void set_FileStream_active(bool stream_to_file) {err_stream = stream_to_file;}
    void set_FileStream_path_csv(QString path);

private:
    bool err_popup = true;
    bool err_stream = false;
    bool file_set = false;
    QFileInfo FI_ErrorProtocol;

    QStringList QSL_StashedErrors;
};

#endif // D_ERROR_HANDLER_H
