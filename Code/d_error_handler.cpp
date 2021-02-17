/************************************
 *   added:     12.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_error_handler.h"

D_Error_Handler::D_Error_Handler()
{

}

/*!
 * \brief D_Error_Handler::ERR pops an error message if an error occured and/or streams it to a csv file
 * \param err error code
 * \param sender name of sending classs
 * \param func name of sending function
 * \param detail some detailed infomation you want to show up / be saved
 */
void D_Error_Handler::ERR(int err, QString sender, QString func, QString detail)
{
    ///do nothing if no error occured
    if(err == ER_okay)
        return;

    ///make sure error code is valid
    if(err < 0 || err >= ER_number_of)
        err = ER_other;

    ///popup
    if(err_popup)
    {
        QMessageBox MSG;

        QString er_type = QSL_Errors[err];
        QString er_info = "";

        er_info.append(
                    "<b>Class</b>:\t"   + sender    + "<br>" +
                    "<b>Function</b>:\t"+ func      + "<br>" +
                    "<b>Type</b>:\t"    + er_type   + "<br><br>");

        er_info.append("<b>Detail</b>:\n" + detail  + "<br><br>");

        er_info.append("<i>If this causes serious problems, please tell me and i will try to find a solution.</i>");

        MSG.setBaseSize(400, 200);
        MSG.setStyleSheet("QLabel{min-width: 400px;}");
        MSG.setText("An error occured... Q.Q");
        MSG.setInformativeText(er_info);

        MSG.exec();
    }

    ///stream
    if(err_stream && file_set)
    {
        ///create error string to stream
        QString QS_Error =
                "\n" +
                QDateTime::currentDateTime().toString() + ";" +
                QSL_Errors[err] + ";" +
                sender + ";" +
                func + ";" +
                detail;

        ///open stream to file (appending)
        ofstream OS_ErrorProtocol;
        OS_ErrorProtocol.open(FI_ErrorProtocol.absoluteFilePath().toStdString(), fstream::app);

        ///check, if file is opened
        if(OS_ErrorProtocol.is_open())
        {
            ///stream error
            OS_ErrorProtocol << QS_Error.toStdString();

            ///stream stashed errors
            if(!QSL_StashedErrors.isEmpty())
            {
                for(int i = 0; i < QSL_StashedErrors.size(); i++)
                    OS_ErrorProtocol << QSL_StashedErrors[i].toStdString();
                QSL_StashedErrors.clear();
            }

            ///close stream
            OS_ErrorProtocol.close();
        }
        else
        {
            ///if file not open, append error to stashed error list
            QSL_StashedErrors.append(QS_Error);
        }
    }
}

/*!
 * \brief D_Error_Handler::set_FileStream_path_csv set the file for error streaming and activates error streaming. File is init with a header.
 * \param path path to stream to. Must end with ".csv"
 */
void D_Error_Handler::set_FileStream_path_csv(QString path)
{
    FI_ErrorProtocol = QFileInfo(path);
    if(FI_ErrorProtocol.suffix() != "csv")
        return;

    err_stream = true;

    ofstream OS_ErrorProtocol;
    OS_ErrorProtocol.open(FI_ErrorProtocol.absoluteFilePath().toStdString(), fstream::app);

    ///check, if file is opened
    if(OS_ErrorProtocol.is_open())
    {
        OS_ErrorProtocol << QDateTime::currentDateTime().toString().toStdString() << ";ERROR PROTOCOL INITIALIZED;" << path.toStdString();
        file_set = true;
    }
    else
    {
        file_set = false;
        ERR(
                    ER_file_not_exist,
                    "D_Error_Handler",
                    "set_FileStream_path_csv",
                    "Unable to create or stream to: " + path);
    }
}
