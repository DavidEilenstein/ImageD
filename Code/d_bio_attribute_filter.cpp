/************************************
 *   added:     12.01.2022          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_attribute_filter.h"

D_Bio_Attribute_Filter::D_Bio_Attribute_Filter() : QWidget()
{
    Filter_Init();
}

D_Bio_Attribute_Filter::D_Bio_Attribute_Filter(QGroupBox* ui_box) : QWidget()
{
    Filter_Init();
    set_ui_groupbox(ui_box);
}

bool D_Bio_Attribute_Filter::set_ui_groupbox(QGroupBox* ui_box)
{
    //no grp box?
    if(ui_box == nullptr)
        return false;

    //set box
    ui_grpbox_master = ui_box;
    state_grpbox_set = true;

    return Ui_Init();
}

bool D_Bio_Attribute_Filter::set_filter_mode(size_t mode)
{
    if(mode >= ATTRIB_FILTER_MODE_NUMBER_OF)
        return false;

    if(state_filter_mode_set)
        return false;

    filter_mode = mode;

    state_filter_mode_set = true;

    return Ui_Init_FilterMode();
}

bool D_Bio_Attribute_Filter::set_channels(QStringList channels)
{
    if(state_channels_set)
        return false;

    if(!Populate_CB_Single(ui_combobox_Channels, channels, 0))
        return false;

    QSL_Channels = channels;
    state_channels_set = true;
    return true;
}

bool D_Bio_Attribute_Filter::set_ScalePx2Um(double scale)
{
    if(scale <= 0 || isnan(scale) || isinf(scale))
        return false;

    scale_px2um = scale;
    scale_um2px = 1.0 / scale;

    return true;
}

bool D_Bio_Attribute_Filter::accept_Foc(D_Bio_Focus *pFoc)
{
    for(size_t i = 0; i < vFilterIndicesActive.size(); i++)
    {
        Filter Fil = vFilters[vFilterIndicesActive[i]];

        bool pass = D_Math::Compare(
                    Fil.i_compare,
                    pFoc->attribute(
                        Fil.i_attrib,
                        Fil.i_channel,
                        scale_px2um),
                    Fil.thres);

        if(!pass)
            return false;
    }

    return true;
}

bool D_Bio_Attribute_Filter::accept_NucBlob(D_Bio_NucleusBlob *pNucBlob)
{
    for(size_t i = 0; i < vFilterIndicesActive.size(); i++)
    {
        Filter Fil = vFilters[vFilterIndicesActive[i]];

        bool pass = D_Math::Compare(
                    Fil.i_compare,
                    pNucBlob->attribute(
                        Fil.i_attrib,
                        Fil.i_channel,
                        scale_px2um),
                    Fil.thres);

        if(!pass)
            return false;
    }

    return true;
}

bool D_Bio_Attribute_Filter::accept_NucLife(D_Bio_NucleusLife *pNucLife)
{
    for(size_t i = 0; i < vFilterIndicesActive.size(); i++)
    {
        Filter Fil = vFilters[vFilterIndicesActive[i]];

        bool pass = D_Math::Compare(
                    Fil.i_compare,
                    pNucLife->attrib_nuclife(
                        Fil.i_attrib),
                    Fil.thres);

        if(!pass)
            return false;
    }

    return true;
}

bool D_Bio_Attribute_Filter::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    if(!state_ui_init)
        return false;

    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);

    return true;
}

bool D_Bio_Attribute_Filter::Ui_Init()
{
    if(!state_grpbox_set)
        return false;

    //------------------------------------------------------ layouts

    //master
    ui_layout_master = new QGridLayout(this);
    ui_layout_master->setSpacing(1);
    ui_layout_master->setContentsMargins(0, 0, 0, 0);
    ui_grpbox_master->setLayout(ui_layout_master);

    //line
    ui_line_v = new QFrame(this);
    ui_line_v->setFrameShape(QFrame::VLine);
    ui_line_v->setFrameShadow(QFrame::Raised);
    ui_line_v->setLineWidth(3);
    ui_layout_master->addWidget(ui_line_v, 0, 3, 2, 1);

    //------------------------------------------------------ elements

    //sizes
    int spinbox_width = 65;
    int button_width = 33;
    int compare_width = 40;
    int channel_width = 45;

    //selected filter
    ui_spinbox_selctedFilter = new QSpinBox(this);
    ui_spinbox_selctedFilter->setRange(0, int(filter_count - 1));
    ui_spinbox_selctedFilter->setPrefix("Filter ");
    ui_spinbox_selctedFilter->setSuffix("/" + QString::number(ui_spinbox_selctedFilter->maximum()));
    ui_spinbox_selctedFilter->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    ui_spinbox_selctedFilter->setFixedWidth(spinbox_width);
    ui_layout_master->addWidget(ui_spinbox_selctedFilter, 0, 0);
    connect(ui_spinbox_selctedFilter, SIGNAL(valueChanged(int)), this, SLOT(Filter_CurrentToUi()));

    //active filters
    ui_spinbox_activeFilters = new QSpinBox(this);
    ui_spinbox_activeFilters->setRange(0, int(filter_count - 1));
    ui_spinbox_activeFilters->setPrefix("");
    ui_spinbox_activeFilters->setSuffix("/" + QString::number(ui_spinbox_activeFilters->maximum()) + " active");
    ui_spinbox_activeFilters->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    ui_spinbox_activeFilters->setFixedWidth(spinbox_width);
    ui_spinbox_activeFilters->setReadOnly(true);
    ui_layout_master->addWidget(ui_spinbox_activeFilters, 1, 0);

    //save button
    ui_button_Save = new QPushButton("Save", this);
    ui_button_Save->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Save, 0, 1);

    //load button
    ui_button_Load = new QPushButton("Load", this);
    ui_button_Load->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Load, 0, 2);

    //info button
    ui_button_Info = new QPushButton("Info", this);
    ui_button_Info->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Info, 1, 1);

    //clear button
    ui_button_Clear = new QPushButton("Clear", this);
    ui_button_Clear->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Clear, 1, 2);

    //attribs
    ui_combobox_Attribute = new QComboBox(this);
    ui_layout_master->addWidget(ui_combobox_Attribute, 0, 4, 1, 4);
    connect(ui_combobox_Attribute, SIGNAL(currentIndexChanged(int)), this, SLOT(Filter_CurrentFromUi()));

    //active
    ui_checkbox_Active = new QCheckBox("active", this);
    ui_checkbox_Active->setChecked(false);
    ui_checkbox_Active->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    ui_layout_master->addWidget(ui_checkbox_Active, 1, 4);
    connect(ui_checkbox_Active, SIGNAL(toggled(bool)), this, SLOT(Filter_CurrentFromUi()));

    //channel
    ui_combobox_Channels = new QComboBox(this);
    ui_combobox_Channels->setFixedWidth(channel_width);
    ui_layout_master->addWidget(ui_combobox_Channels, 1, 5);
    connect(ui_combobox_Channels, SIGNAL(currentIndexChanged(int)), this, SLOT(Filter_CurrentFromUi()));

    //comparison
    ui_combobox_Comparison = new QComboBox(this);
    ui_combobox_Comparison->setFixedWidth(compare_width);
    ui_layout_master->addWidget(ui_combobox_Comparison, 1, 6);
    connect(ui_combobox_Comparison, SIGNAL(currentIndexChanged(int)), this, SLOT(Filter_CurrentFromUi()));

    //thres
    ui_doublespinbox_Thres = new QDoubleSpinBox(this);
    ui_doublespinbox_Thres->setRange(thres_min, thres_max);
    ui_doublespinbox_Thres->setDecimals(thres_decimals);
    ui_doublespinbox_Thres->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    ui_doublespinbox_Thres->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui_layout_master->addWidget(ui_doublespinbox_Thres, 1, 7);
    connect(ui_doublespinbox_Thres, SIGNAL(valueChanged(double)), this, SLOT(Filter_CurrentFromUi()));


    //------------------------------------------------------ finish

    state_ui_init = true;

    if(!state_filter_mode_2ui && state_filter_mode_set)
        Ui_Init_FilterMode();

    return true;
}

bool D_Bio_Attribute_Filter::Ui_Init_FilterMode()
{
    if(!state_ui_init)
        return false;

    Populate_CB_Single(ui_combobox_Comparison, QSL_CompareSimple, c_COMPARE_EQUAL);

    switch (filter_mode) {
    case ATTRIB_FILTER_MODE_FOCI:       Populate_CB_Single(ui_combobox_Attribute, QSL_Attrib_Foc);          break;
    case ATTRIB_FILTER_MODE_NUC_BLOB:   Populate_CB_Single(ui_combobox_Attribute, QSL_Attrib_Nuc);          break;
    case ATTRIB_FILTER_MODE_NUC_LIFE:   Populate_CB_Single(ui_combobox_Attribute, QSL_Attrib_NucLife);      break;
    default:                                                                                                return false;}

    return true;
}

void D_Bio_Attribute_Filter::Filter_Init()
{
    vFilters.clear();
    vFilters.resize(filter_count);

    vFilterIndicesActive.clear();
}

void D_Bio_Attribute_Filter::Filter_CurrentToUi()
{
    ui_grpbox_master->setEnabled(false);

    size_t i_filter     = ui_spinbox_selctedFilter->value();
    Filter* pFil        = &(vFilters[i_filter]);

    ui_combobox_Attribute->blockSignals(true);
    ui_combobox_Comparison->blockSignals(true);
    ui_combobox_Channels->blockSignals(true);
    ui_checkbox_Active->blockSignals(true);
    ui_doublespinbox_Thres->blockSignals(true);

    ui_combobox_Attribute->setCurrentIndex(int(pFil->i_attrib));
    ui_combobox_Comparison->setCurrentIndex(int(pFil->i_compare));
    ui_combobox_Channels->setCurrentIndex(int(pFil->i_channel));
    ui_checkbox_Active->setChecked(pFil->active);
    ui_doublespinbox_Thres->setValue(pFil->thres);

    ui_combobox_Attribute->blockSignals(false);
    ui_combobox_Comparison->blockSignals(false);
    ui_combobox_Channels->blockSignals(false);
    ui_checkbox_Active->blockSignals(false);
    ui_doublespinbox_Thres->blockSignals(false);

    ui_grpbox_master->setEnabled(true);
}

void D_Bio_Attribute_Filter::Filter_CurrentFromUi()
{
    ui_grpbox_master->setEnabled(false);

    size_t i_filter     = ui_spinbox_selctedFilter->value();
    Filter* pFil        = &(vFilters[i_filter]);

    pFil->i_attrib      = ui_combobox_Attribute->currentIndex();
    pFil->i_compare     = ui_combobox_Comparison->currentIndex();
    pFil->i_channel     = ui_combobox_Channels->currentIndex();
    pFil->active        = ui_checkbox_Active->isChecked();
    pFil->thres         = ui_doublespinbox_Thres->value();

    vFilterIndicesActive.clear();
    size_t active_filters_count = 0;
    for(size_t f = 0; f < filter_count; f++)
        if(vFilters[f].active)
        {
            active_filters_count++;
            vFilterIndicesActive.push_back(f);
        }
    ui_spinbox_activeFilters->setValue(int(active_filters_count));

    //emit signal to trigger apllication of the filter externally
    emit FilterParamsChanged();

    ui_grpbox_master->setEnabled(true);
}


