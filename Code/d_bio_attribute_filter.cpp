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

bool D_Bio_Attribute_Filter::set_channels(QStringList channels_foc, QStringList channels_val)
{
    if(state_channels_set)
        return false;

    QSL_Channels_Foc = channels_foc;
    QSL_Channels_Val = channels_val;

    Populate_CB_Single(ui_combobox_Channels, channels_val, 0);
    if(state_ui_init)
        Filter_UpdateUi_CurrentChannelDependency();

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

bool D_Bio_Attribute_Filter::set_SaveDir(QDir *pDirSave)
{
    if(!pDirSave->exists())
        QDir().mkdir(pDirSave->path());
    if(!pDirSave->exists())
        return false;

    pDIR_Save = pDirSave;
    state_save_dir_set = true;
    return true;
}

bool D_Bio_Attribute_Filter::set_filter(size_t i_filt, bool is_active, size_t i_att, size_t i_comp, size_t i_ch, double thres_val)
{
    //check indices
    if(i_filt >= vFilters.size())                           return false;
    if(i_att >= size_t(ui_combobox_Attribute->count()))     return false;
    if(i_comp >= size_t(ui_combobox_Comparison->count()))   return false;
    if(i_ch >= size_t(ui_combobox_Channels->count()))       return false;

    //set filter
    vFilters[i_filt].active     = is_active;
    vFilters[i_filt].i_attrib   = i_att;
    vFilters[i_filt].i_compare  = i_comp;
    vFilters[i_filt].i_channel  = i_ch;
    vFilters[i_filt].thres      = thres_val;

    //show filter
    Filter_CurrentToUi();
    Filter_CurrentFromUi();

    //end
    return true;
}

bool D_Bio_Attribute_Filter::filter_is_active(size_t i_filter)
{
    return i_filter >= vFilters.size() ? false : vFilters[i_filter].active;
}

size_t D_Bio_Attribute_Filter::filter_inactive_1st()
{
    for(size_t f = 0; f < vFilters.size(); f++)
        if(!filter_is_active(f))
            return f;

    return vFilters.size() - 1;
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

void D_Bio_Attribute_Filter::Filters_Info()
{
    QString QS_Info;

    size_t n = vFilterIndicesActive.size();
    for(size_t i = 0; i < n; i++)
    {
        size_t i_f = vFilterIndicesActive[i];
        Filter F = vFilters[i_f];

        QS_Info.append("<br>");
        QS_Info.append("Filter " + QString::number(i_f) + ": ");

        size_t attrib = F.i_attrib;
        QS_Info.append(QSL_Attributes[attrib]);

        bool channel_foc_dependent = false;
        switch (filter_mode) {
        case ATTRIB_FILTER_MODE_FOCI:       channel_foc_dependent = D_Bio_Focus::attribute_is_focus_channel_dependent(attrib);          break;
        case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_foc_dependent = D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(attrib);    break;
        case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_foc_dependent = D_Bio_NucleusLife::attribute_is_focus_channel_dependent(attrib);    break;
        default:                                                                                                                        return;}

        bool channel_val_dependent = false;
        switch (filter_mode) {
        case ATTRIB_FILTER_MODE_FOCI:       channel_val_dependent = D_Bio_Focus::attribute_is_value_channel_dependent(attrib);          break;
        case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_val_dependent = D_Bio_NucleusBlob::attribute_is_value_channel_dependent(attrib);    break;
        case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_val_dependent = D_Bio_NucleusLife::attribute_is_value_channel_dependent(attrib);    break;
        default:                                                                                                                        return;}

        size_t ch = F.i_channel;
        if(channel_foc_dependent)
            QS_Info.append("(" + QSL_Channels_Foc[ch] + ")");
        else if(channel_val_dependent)
            QS_Info.append("(" + QSL_Channels_Val[ch] + ")");

        QS_Info.append("  " + QSL_CompareSimple[F.i_compare]);
        QS_Info.append("  " + QString::number(F.thres));
    }

    if(n == 0)
        QS_Info.append("No active filters");

    QMessageBox::information(
                this,
                "Attribute Filters (" + QSL_FilterMode[filter_mode] + ")",
                QS_Info);
}

void D_Bio_Attribute_Filter::Filters_Clear()
{
    if(QMessageBox::question(
                this,
                "Clear all filters?",
                "Do you want to clear all " + QSL_FilterMode[filter_mode] + " filters?")
            != QMessageBox::Yes)
        return;

    Filter_Init();
    Filter_CurrentToUi();
}

bool D_Bio_Attribute_Filter::Filters_Save()
{
    if(!state_save_dir_set)
        *pDIR_Save = QDir::home();

    QString QS_Save = QFileDialog::getSaveFileName(
                this,
                "Save " + QSL_FilterMode[filter_mode] + " filters",
                QString(pDIR_Save->path() + "/") +
                QString("Filters_" + QSL_FilterMode[filter_mode] + "_" + QDateTime::currentDateTime().toString() + ".txt").replace(":", "_").replace(" ", "_"),
                tr("Text files (*.txt *.TXT)"));
    if(QS_Save.isEmpty())
        return false;

    ofstream OS;
    OS.open(QS_Save.toStdString());
    if(!OS.is_open())
        return false;

    OS << QS_Save.toStdString();
    OS << "\n" << QDateTime::currentDateTime().toString().toStdString();

    size_t n = vFilters.size();
    for(size_t i = 0; i < n; i++)
    {
        Filter F = vFilters[i];

        //index
        OS << "\n" << i;

        //activ?
        if(F.active)
            OS << ";" << "active";
        else
            OS << ";" << "inactive";

        //attrib
        size_t attrib = F.i_attrib;
        OS << ";" << QSL_Attributes[attrib].toStdString();

        //channel

        bool channel_foc_dependent = false;
        switch (filter_mode) {
        case ATTRIB_FILTER_MODE_FOCI:       channel_foc_dependent = D_Bio_Focus::attribute_is_focus_channel_dependent(attrib);          break;
        case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_foc_dependent = D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(attrib);    break;
        case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_foc_dependent = D_Bio_NucleusLife::attribute_is_focus_channel_dependent(attrib);    break;
        default:                            OS.close();                                                                                 return false;}

        bool channel_val_dependent = false;
        switch (filter_mode) {
        case ATTRIB_FILTER_MODE_FOCI:       channel_val_dependent = D_Bio_Focus::attribute_is_value_channel_dependent(attrib);          break;
        case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_val_dependent = D_Bio_NucleusBlob::attribute_is_value_channel_dependent(attrib);    break;
        case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_val_dependent = D_Bio_NucleusLife::attribute_is_value_channel_dependent(attrib);    break;
        default:                            OS.close();                                                                                 return false;}

        size_t ch = F.i_channel;
        if(channel_foc_dependent)
            OS << ";" << QSL_Channels_Foc[int(ch)].toStdString();
        else if(channel_val_dependent)
            OS << ";" << QSL_Channels_Val[int(ch)].toStdString();
        else
            OS << ";---";

        //compare
        OS << ";" << QSL_CompareSimple[int(F.i_compare)].toStdString();

        //thres
        OS << ";" << F.thres;
    }

    OS.close();
    return true;
}

bool D_Bio_Attribute_Filter::Filters_Load()
{
    if(!state_save_dir_set)
        *pDIR_Save = QDir::home();

    QString QS_Load = QFileDialog::getOpenFileName(
                this,
                "Load " + QSL_FilterMode[filter_mode] + " filters",
                pDIR_Save->path(),
                tr("Text files (*.txt *.TXT)"));
    if(QS_Load.isEmpty())
        return false;

    QFileInfo FI_Load(QS_Load);
    if(!FI_Load.exists())
        return false;

    QFile F_Load(FI_Load.absoluteFilePath());
    if(!F_Load.open(QIODevice::ReadOnly))
        return false;

    QTextStream TS_Load(&F_Load);

    ifstream IS;
    IS.open(QS_Load.toStdString());
    if(!IS.is_open())
        return false;

    Filter_Init();

    bool ok;
    size_t line = 0;
    size_t filter_loads_failed = 0;
    size_t filter_loads_ok = 0;
    while(!TS_Load.atEnd())
    {
        QString QS_Line = TS_Load.readLine();
        qDebug() << QS_Line;

        if(line >= 2)//line 0 and 1 are meta infos
        {
            bool filter_load_failed = false;
            int i_filter = 0;
            Filter Fil;

            //blocks
            QStringList QSL_Blocks = QS_Line.split(";");
            if(QSL_Blocks.size() != 6)
                filter_load_failed = true;

            //index
            if(!filter_load_failed)
            {
                i_filter = QSL_Blocks[0].toUInt(&ok);
                if(!ok)
                {
                    filter_load_failed = true;
                }
                else
                {
                    if(i_filter >= int(vFilters.size()))
                        filter_load_failed = true;
                }
            }

            //active
            if(!filter_load_failed)
            {
                if(QSL_Blocks[1] == "active")
                    Fil.active = true;
                else if(QSL_Blocks[1] == "inactive")
                    Fil.active = false;
                else
                    filter_load_failed = true;
            }

            //attrib
            if(!filter_load_failed)
            {
                QString QS_Attrib = QSL_Blocks[2];
                bool attrib_found = false;
                for(int a = 0; a < QSL_Attributes.size() && !attrib_found; a++)
                    if(QS_Attrib == QSL_Attributes[a])
                    {
                        Fil.i_attrib = a;
                        attrib_found = true;
                    }

                if(!attrib_found)
                    filter_load_failed = true;
            }

            //channel
            if(!filter_load_failed)
            {
                size_t attrib = Fil.i_attrib;

                bool channel_foc_dependent = false;
                switch (filter_mode) {
                case ATTRIB_FILTER_MODE_FOCI:       channel_foc_dependent = D_Bio_Focus::attribute_is_focus_channel_dependent(attrib);          break;
                case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_foc_dependent = D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(attrib);    break;
                case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_foc_dependent = D_Bio_NucleusLife::attribute_is_focus_channel_dependent(attrib);    break;
                default:                                                                                                                        return false;}

                bool channel_val_dependent = false;
                switch (filter_mode) {
                case ATTRIB_FILTER_MODE_FOCI:       channel_val_dependent = D_Bio_Focus::attribute_is_value_channel_dependent(attrib);          break;
                case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_val_dependent = D_Bio_NucleusBlob::attribute_is_value_channel_dependent(attrib);    break;
                case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_val_dependent = D_Bio_NucleusLife::attribute_is_value_channel_dependent(attrib);    break;
                default:                                                                                                                        return false;}

                if(channel_foc_dependent || channel_val_dependent)
                {
                    QStringList QSL_Channels = channel_foc_dependent ? QSL_Channels_Foc : QSL_Channels_Val;

                    QString QS_Channel = QSL_Blocks[3];
                    bool channel_found = false;
                    for(int ch = 0; ch < QSL_Channels.size() && !channel_found; ch++)
                        if(QS_Channel == QSL_Channels[ch])
                        {
                            Fil.i_channel = ch;
                            channel_found = true;
                        }

                    if(!channel_found)
                        filter_load_failed = true;
                }
            }

            //comparator
            if(!filter_load_failed)
            {
                QString QS_Compare = QSL_Blocks[4];
                bool comparator_found = false;
                for(int c = 0; c < QSL_CompareSimple.size() && !comparator_found; c++)
                    if(QS_Compare == QSL_CompareSimple[c])
                    {
                        Fil.i_compare = c;
                        comparator_found = true;
                    }

                if(!comparator_found)
                    filter_load_failed = true;
            }

            //thres
            if(!filter_load_failed)
            {
                Fil.thres = QSL_Blocks[5].toUInt(&ok);
                if(!ok)
                    filter_load_failed = true;
            }

            //save filter
            if(!filter_load_failed)
                filter_load_failed = !set_filter(
                            i_filter,
                            Fil.active,
                            Fil.i_attrib,
                            Fil.i_compare,
                            Fil.i_channel,
                            Fil.thres);

            //count ok filters
            if(!filter_load_failed)
                filter_loads_ok++;
            else
                filter_loads_failed++;
        }

        line++;
    }

    Filter_CurrentToUi();

    qDebug() << "ok" << filter_loads_ok << "nok" << filter_loads_failed;
    if(filter_loads_failed > 0)
        QMessageBox::warning(
                    this,
                    "Load fail",
                    "Failed loading " + QString::number(filter_loads_failed) + " filters."
                     "<br>Succsessful filter loads: " + QString::number(filter_loads_ok));

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
    ui_spinbox_activeFilters->setSuffix("/" + QString::number(ui_spinbox_activeFilters->maximum() + 1) + " active");
    ui_spinbox_activeFilters->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    ui_spinbox_activeFilters->setFixedWidth(spinbox_width);
    ui_spinbox_activeFilters->setReadOnly(true);
    ui_layout_master->addWidget(ui_spinbox_activeFilters, 1, 0);

    //save button
    ui_button_Save = new QPushButton("Save", this);
    ui_button_Save->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Save, 0, 1);
    connect(ui_button_Save, SIGNAL(clicked()), this, SLOT(Filters_Save()));

    //load button
    ui_button_Load = new QPushButton("Load", this);
    ui_button_Load->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Load, 0, 2);
    connect(ui_button_Load, SIGNAL(clicked()), this, SLOT(Filters_Load()));

    //info button
    ui_button_Info = new QPushButton("Info", this);
    ui_button_Info->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Info, 1, 1);
    connect(ui_button_Info, SIGNAL(clicked()), this, SLOT(Filters_Info()));

    //clear button
    ui_button_Clear = new QPushButton("Clear", this);
    ui_button_Clear->setFixedWidth(button_width);
    ui_layout_master->addWidget(ui_button_Clear, 1, 2);
    ui_button_Clear->setEnabled(false);
    connect(ui_button_Clear, SIGNAL(clicked()), this, SLOT(Filters_Clear()));

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

    Filter_UpdateUi_CurrentChannelDependency();

    return true;
}

bool D_Bio_Attribute_Filter::Ui_Init_FilterMode()
{
    if(!state_ui_init)
        return false;

    Populate_CB_Single(ui_combobox_Comparison, QSL_CompareSimple, c_COMPARE_EQUAL);

    switch (filter_mode) {
    case ATTRIB_FILTER_MODE_FOCI:       QSL_Attributes = QSL_Attrib_Foc;        break;
    case ATTRIB_FILTER_MODE_NUC_BLOB:   QSL_Attributes = QSL_Attrib_Nuc;        break;
    case ATTRIB_FILTER_MODE_NUC_LIFE:   QSL_Attributes = QSL_Attrib_NucLife;    break;
    default:                                                                    return false;}

    Populate_CB_Single(ui_combobox_Attribute, QSL_Attributes);

    return true;
}

void D_Bio_Attribute_Filter::Filter_Init()
{
    vFilters.clear();
    vFilters.resize(filter_count);

    vFilterIndicesActive.clear();
    Check_ClearButtonPossible();
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

    Filter_UpdateUi_CurrentChannelDependency();
    Check_ClearButtonPossible();
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

    Filter_UpdateUi_CurrentChannelDependency();
    Check_ClearButtonPossible();
}

void D_Bio_Attribute_Filter::Filter_UpdateUi_CurrentChannelDependency()
{
    size_t i_filter = size_t(ui_spinbox_selctedFilter->value());
    if(i_filter >= vFilters.size())
        return;

    size_t attrib = vFilters[i_filter].i_attrib;

    bool channel_foc_dependent = false;
    switch (filter_mode) {
    case ATTRIB_FILTER_MODE_FOCI:       channel_foc_dependent = D_Bio_Focus::attribute_is_focus_channel_dependent(attrib);          break;
    case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_foc_dependent = D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(attrib);    break;
    case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_foc_dependent = D_Bio_NucleusLife::attribute_is_focus_channel_dependent(attrib);    break;
    default:                                                                                                                        return;}

    bool channel_val_dependent = false;
    switch (filter_mode) {
    case ATTRIB_FILTER_MODE_FOCI:       channel_val_dependent = D_Bio_Focus::attribute_is_value_channel_dependent(attrib);          break;
    case ATTRIB_FILTER_MODE_NUC_BLOB:   channel_val_dependent = D_Bio_NucleusBlob::attribute_is_value_channel_dependent(attrib);    break;
    case ATTRIB_FILTER_MODE_NUC_LIFE:   channel_val_dependent = D_Bio_NucleusLife::attribute_is_value_channel_dependent(attrib);    break;
    default:                                                                                                                        return;}

    int i_old = ui_combobox_Channels->currentIndex();
    QStringList QSL_new = channel_foc_dependent ? QSL_Channels_Foc : QSL_Channels_Val;
    Populate_CB_Single(ui_combobox_Channels, QSL_new, min(QSL_new.size() - 1, i_old));

    ui_combobox_Channels->setEnabled(channel_foc_dependent || channel_val_dependent);
}

void D_Bio_Attribute_Filter::Check_ClearButtonPossible()
{
    if(state_ui_init)
        ui_button_Clear->setEnabled(!vFilterIndicesActive.empty());
}


