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

    QString er_type = "";
    QString er_info = "";

    switch (err) {
    case ER_other:                  er_type = "other";                              break;
    case ER_empty:                  er_type = "data empty";                         break;
    case ER_type_bad:               er_type = "type not suported";                  break;
    case ER_type_missmatch:         er_type = "types missmatch";                    break;
    case ER_bitdepth_bad:           er_type = "bitdepth not supported";             break;
    case ER_bitdepth_missmatch:     er_type = "bitdepth missmatch";                 break;
    case ER_size_bad:               er_type = "size not supported";                 break;
    case ER_size_missmatch:         er_type = "sizes missmatch";                    break;
    case ER_parameter_bad:          er_type = "parameter not supported";            break;
    case ER_parameter_missmatch:    er_type = "parameter missmatch";                break;
    case ER_channel_bad:            er_type = "channels not supported";             break;
    case ER_channel_missmatch:      er_type = "channels missmatch";                 break;
    case ER_index_out_of_range:     er_type = "index out of range";                 break;
    case ER_dim_out_of_range:       er_type = "dimension index out of range";       break;
    case ER_dim_missmatch:          er_type = "dimension missmatch";                break;
    case ER_dim_X_out_of_range:     er_type = "X index out of range";               break;
    case ER_dim_X_missmatch:        er_type = "X dimensions missmatch";             break;
    case ER_dim_Y_out_of_range:     er_type = "Y index out of range";               break;
    case ER_dim_Y_missmatch:        er_type = "Y dimensions missmatch";             break;
    case ER_dim_Z_out_of_range:     er_type = "Z index out of range";               break;
    case ER_dim_Z_missmatch:        er_type = "Z dimensions missmatch";             break;
    case ER_dim_T_out_of_range:     er_type = "T index out of range";               break;
    case ER_dim_T_missmatch:        er_type = "T dimensions missmatch";             break;
    case ER_dim_S_out_of_range:     er_type = "S index out of range";               break;
    case ER_dim_S_missmatch:        er_type = "S dimensions missmatch";             break;
    case ER_dim_P_out_of_range:     er_type = "P index out of range";               break;
    case ER_dim_P_missmatch:        er_type = "P dimensions missmatch";             break;
    case ER_file_not_exist:         er_type = "file does not exist";                break;
    case ER_dim_1D_only:            er_type = "only supported for 1D processing";   break;
    case ER_dim_2D_only:            er_type = "only supported for 2D processing";   break;
    case ER_dim_3D_only:            er_type = "only supported for 3D processing";   break;
    case ER_list_empty:             er_type = "list empty";                         break;
    case ER_VideoCaptureClosed:     er_type = "video capture not open";             break;
    default:                                                                        break;}

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
