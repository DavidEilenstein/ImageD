/************************************
 *   added:     12.01.2022          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_ATTRIBUTE_FILTER_H
#define D_BIO_ATTRIBUTE_FILTER_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_bio_enum.h>
#include <d_bio_focus.h>
#include <d_bio_nucleusblob.h>
#include <d_bio_nucleuslife.h>
#include <d_math.h>

//Qt
#include <QObject>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QInputDialog>
#include <QTextStream>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QMessageBox>
#include <QFileDialog>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Bio_Attribute_Filter : public QWidget
{
    Q_OBJECT
public:
    explicit D_Bio_Attribute_Filter();
    explicit D_Bio_Attribute_Filter(QGroupBox *ui_box);

    bool set_ui_groupbox(QGroupBox *ui_box);
    bool set_filter_mode(size_t mode);
    bool set_channels(QStringList channels_foc, QStringList channels_val);
    bool set_ScalePx2Um(double scale);
    bool set_SaveDir(QDir* pDirSave);

    bool set_filter(size_t i_filt, bool is_active, size_t i_att, size_t i_comp, size_t i_ch, double thres_val);

    bool filter_is_active(size_t i_filter);
    size_t filter_inactive_1st();

    bool accept_Foc(D_Bio_Focus * pFoc);
    bool accept_NucBlob(D_Bio_NucleusBlob * pNucBlob);
    bool accept_NucLife(D_Bio_NucleusLife * pNucLife);

public slots:

    void            Filters_Info();
    void            Filters_Clear();
    bool            Filters_Save();
    bool            Filters_Load();

private slots:

    void            Filter_CurrentToUi();
    void            Filter_CurrentFromUi();
    void            Filter_UpdateUi_CurrentChannelDependency();
    void            Check_ClearButtonPossible();

signals:
    void            FilterParamsChanged();

private:
    bool Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init = 0);

    bool            Ui_Init();
    bool            Ui_Init_FilterMode();

    void            Filter_Init();

    //ui elements
    QGroupBox*      ui_grpbox_master;
    QGridLayout*    ui_layout_master;
    QFrame*         ui_line_v;
    QSpinBox*       ui_spinbox_selctedFilter;
    QSpinBox*       ui_spinbox_activeFilters;
    QPushButton*    ui_button_Save;
    QPushButton*    ui_button_Load;
    QPushButton*    ui_button_Clear;
    QPushButton*    ui_button_Info;
    QComboBox*      ui_combobox_Attribute;
    QCheckBox*      ui_checkbox_Active;
    QComboBox*      ui_combobox_Channels;
    QComboBox*      ui_combobox_Comparison;
    QDoubleSpinBox* ui_doublespinbox_Thres;

    //sizes
    const size_t    filter_count    = 100;
    double          thres_min       = -INFINITY;
    double          thres_max       = INFINITY;
    int             thres_decimals  = 6;

    //filter struct
    struct Filter {
        bool    active      = false;
        size_t  i_attrib    = 0;
        size_t  i_compare   = c_COMPARE_EQUAL;
        size_t  i_channel   = 0;
        double  thres       = 0;
    };

    //filters
    vector<Filter>  vFilters;
    vector<size_t>  vFilterIndicesActive;

    //states
    bool            state_grpbox_set = false;
    bool            state_ui_init = false;
    bool            state_filter_mode_set = false;
    bool            state_filter_mode_2ui = false;
    bool            state_channels_set = false;
    bool            state_save_dir_set = false;

    //filter mode
    size_t filter_mode = ATTRIB_FILTER_MODE_FOCI;

    //channels
    QStringList QSL_Channels_Val;
    QStringList QSL_Channels_Foc;

    //Attribs
    QStringList QSL_Attributes;

    //scaling
    double scale_px2um = 1;
    double scale_um2px = 1;

    //save dir
    QDir* pDIR_Save;
};

#endif // D_BIO_ATTRIBUTE_FILTER_H
