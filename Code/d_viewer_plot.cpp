/************************************
 *   added:     11.03.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_viewer_plot.h"

D_Viewer_Plot::D_Viewer_Plot()
{

}

D_Viewer_Plot::D_Viewer_Plot(QGridLayout *pGL)
{
    set_Layout(pGL);
}

void D_Viewer_Plot::set_Layout(QGridLayout *pGL)
{
    Layout = pGL;
    state_GL_set = true;
}

/*
int D_Viewer_Plot::Plot_X1D_Y1D(vector<double> vX, vector<double> vY, int mode, QString QS_Title, QString QS_X, QString QS_Y, QString QS_Series)
{
    return ER_okay;
}
*/
