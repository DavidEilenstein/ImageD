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

void D_Error_Handler::ERR(unsigned int err, QString sender, QString func, QString detail)
{
    if(err == ER_okay)
        return;

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
