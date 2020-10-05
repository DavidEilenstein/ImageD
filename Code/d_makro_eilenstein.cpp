/************************************
 *   added:     08.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_eilenstein.h"
#include "ui_d_makro_eilenstein.h"

D_MAKRO_Eilenstein::D_MAKRO_Eilenstein(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_Eilenstein)
{
    ui->setupUi(this);

    pStore = pStorage;

    Viewer.set_GV(ui->graphicsView_Img);
    Viewer.set_Name("Eilenstein Filter");

    Update_Stack_Count();
}

D_MAKRO_Eilenstein::~D_MAKRO_Eilenstein()
{
    delete ui;
}

void D_MAKRO_Eilenstein::closeEvent(QCloseEvent *event)
{
    if(ClosingPossible)
    {
        event->accept();
    }
    else
    {
        event->ignore();
        this->showMinimized();
    }
}

void D_MAKRO_Eilenstein::Update_Stack_Count()
{
    int count_img       = (int)v_MA_Img.size();
    int count_sizes     = (size_max - size_min) / size_step;
    int count_offset    = (int)((off_max - off_min) / off_step);

    ui->label_Run_Stack->setText(
                "Process " +
                QString::number(count_img * count_sizes * count_offset * 3) +
                " Images");
}

void D_MAKRO_Eilenstein::Update_Image()
{
    Viewer.Update_Image(&(v_MA_Img[ui->comboBox_Img->currentIndex()]));
}

void D_MAKRO_Eilenstein::Update_Ui()
{
    if(this->isEnabled())
        return;

    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_Eilenstein::on_pushButton_Img_Add_clicked()
{
    QStringList QSL_load_path = QFileDialog::getOpenFileNames(
                this,
                "Select Images to be filtered.",
                pStore->dir_M_Eilenstein()->path(),
                tr("Image Files - *.tif *.png *.jpg *.bmp"));

    if(QSL_load_path.isEmpty())
        return;

    pStore->set_dir_M_Eilenstein(QSL_load_path.first());

    for(int i = 0; i < QSL_load_path.size(); i++)
        if(QSL_load_path[i] != 0)
        {
            QString path = QSL_load_path[i];
            qDebug() << path;

            v_MA_Img.push_back(Mat());
            QSL_Img.push_back(path);
            int index = (int)v_MA_Img.size() - 1;

            D_Img_Proc::Load_From_Path(
                        &(v_MA_Img[index]),
                        path.toStdString());

            ui->comboBox_Img->addItem(path);
        }

    Update_Image();
    Update_Stack_Count();
}

void D_MAKRO_Eilenstein::on_pushButton_img_Clear_clicked()
{
    v_MA_Img.clear();
    QSL_Img.clear();
}

void D_MAKRO_Eilenstein::on_comboBox_Img_currentIndexChanged(int index)
{
    index;
    Update_Image();
}

void D_MAKRO_Eilenstein::on_pushButton_Out_Select_clicked()
{
    QString path = QFileDialog::getExistingDirectory(
                this,
                "Select output Directory.",
                pStore->dir_M_Eilenstein()->path());

    if(path == 0)
        return;
    pStore->set_dir_M_Eilenstein(path);

    QS_Out_Path = path;
    ui->label_Out_Path->setText(path);
    ui->groupBox_Run->setEnabled(true);
    ui->pushButton_Out_Open->setEnabled(true);
}

void D_MAKRO_Eilenstein::on_pushButton_Out_Open_clicked()
{
    QDesktopServices::openUrl(QS_Out_Path);
}

void D_MAKRO_Eilenstein::on_pushButton_Run_clicked()
{
    //create subfolder for output
    unsigned int count = 0;
    QString QS_OutSubdir = QS_Out_Path + "/Results_0";
    while(QDir(QS_OutSubdir).exists())
    {
        count++;
        QS_OutSubdir = QS_Out_Path + "/Results_" + QString::number(count);
    }
    QDir().mkdir(QS_OutSubdir);
    qDebug() << "Results-Subdir:" << QS_OutSubdir;

    this->setEnabled(false);

    //loop images and parameters
    for(int i = 0; i < v_MA_Img.size(); i++)
    {
        qDebug() << ":::::::::::::::::::::::::::::::: Image:    " << QSL_Img[i];

        QFileInfo FI_Img = QFileInfo(QSL_Img[i]);
        QString QS_ImgDir = QS_OutSubdir + "/" + FI_Img.baseName();
        QDir().mkdir(QS_ImgDir);

        qDebug() << ":::::::::::::::::::::::::::::::: Output:   " << QS_ImgDir;

        for(int c = 0; c < 4; c++)
        {
            QString QS_cmp;

            switch (c) {
            case 0: QS_cmp = "Equal";           break;
            case 1: QS_cmp = "Greater";         break;
            case 2: QS_cmp = "GreaterEqual";    break;
            case 3: QS_cmp = "Less";            break;
            case 4: QS_cmp = "LessEqual";       break;
            case 5: QS_cmp = "NotEqual";        break;
            default:                            break;}

            qDebug() << "================ Comparator:" << QS_cmp;

            QString QS_ImgCmpDir = QS_ImgDir + "/" + QS_cmp;
            QDir().mkdir(QS_ImgCmpDir);

            for(int o = off_min; o <= off_max; o += off_step)
            {
                QString QS_Off;
                if(o < 0)
                    QS_Off.append("m");
                else if(o == 0)
                    QS_Off.append("n");
                else
                    QS_Off.append("p");

                if(abs(o) < 100)
                    QS_Off.append("0");
                if(abs(o) < 10)
                    QS_Off.append("0");

                QS_Off.append(QString::number(abs(o)));

                qDebug() << "-------- Offset:" << QS_Off;

                for(int s = size_min; s <= size_max; s += size_step)
                {
                    QString QS_Size;
                    if(s < 10)
                        QS_Size.append("0");
                    QS_Size.append(QString::number(s));

                    qDebug() << ".... Size:  " << QS_Size;

                    Mat MA_tmp;
                    QImage QI_tmp;

                    QString QS_SavePath =
                            QS_ImgCmpDir + "/" +
                            FI_Img.baseName() + " - " +
                            QS_cmp + " - " +
                            "Offset_" + QS_Off + " - " +
                            "Size_" + QS_Size + ".png";

                    D_Img_Proc::Filter_Eilenstein(
                                &MA_tmp,
                                &(v_MA_Img[i]),
                                c,
                                s / 2,
                                s / 2,
                                true,
                                o);

                    D_Img_Proc::Convert_Mat_to_QImage(
                                &QI_tmp,
                                &MA_tmp);

                    QI_tmp.save(QS_SavePath, 0, -1);

                    Viewer.Update_Image(&MA_tmp);
                    Update_Ui();

                    MA_tmp.release();
                }
            }

            if(c == 1)
                c++;
        }
    }

    this->setEnabled(true);
}

void D_MAKRO_Eilenstein::on_spinBox_Min_valueChanged(int arg1)
{
    if(arg1 > ui->spinBox_Max->value())
        ui->spinBox_Max->setValue(arg1);

    size_min = arg1;
    Update_Stack_Count();
}

void D_MAKRO_Eilenstein::on_spinBox_Max_valueChanged(int arg1)
{
    if(arg1 < ui->spinBox_Min->value())
        ui->spinBox_Min->setValue(arg1);

    size_max = arg1;
    Update_Stack_Count();
}

void D_MAKRO_Eilenstein::on_spinBox_Step_valueChanged(int arg1)
{
    size_step = arg1;
    Update_Stack_Count();
}

void D_MAKRO_Eilenstein::on_doubleSpinBox_Off_Min_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_Off_Max->value())
        ui->doubleSpinBox_Off_Max->setValue(arg1);

    off_min = arg1;
    Update_Stack_Count();
}

void D_MAKRO_Eilenstein::on_doubleSpinBox_Off_Max_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_Off_Min->value())
        ui->doubleSpinBox_Off_Min->setValue(arg1);

    off_max = arg1;
    Update_Stack_Count();
}

void D_MAKRO_Eilenstein::on_doubleSpinBox_Off_Step_valueChanged(double arg1)
{
    off_step = arg1;
    Update_Stack_Count();
}
