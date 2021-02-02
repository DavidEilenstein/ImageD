/****************************************************
 *   added:     24.01.2021                          *
 *   author:    David Eilenstein                    *
 *   contact:   David.Eilenstein@stud.h-da.de.de    *
 *   project:   ImageD                              *
 *   facility:  Hochschule Darmstadt, Ger           *
 ****************************************************/

#include "d_makro_softmaxvisualization.h"
#include "ui_d_makro_softmaxvisualization.h"

D_MAKRO_SoftmaxVisualization::D_MAKRO_SoftmaxVisualization(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_SoftmaxVisualization)
{
    ui->setupUi(this);

    //storage
    pStore = pStorage;

    //init mats
    Data_InitMats_CorrectSize();

    //Viewers
    Viewer_x.set_GV(ui->graphicsView_x);
    Viewer_y.set_GV(ui->graphicsView_y);
    Viewer_W.set_GV(ui->graphicsView_W);
    Viewer_s.set_GV(ui->graphicsView_s);
    Viewer_s_normed.set_GV(ui->graphicsView_s_normed);
    Viewer_classification.set_GV(ui->graphicsView_classes);
    Viewer_L.set_GV(ui->graphicsView_L);
    Viewer_L_partial_s.set_GV(ui->graphicsView_L_partial_s);
    Viewer_gradient.set_GV(ui->graphicsView_grad);
    Viewer_x.Set_Aspect_Mode(false);
    Viewer_y.Set_Aspect_Mode(false);
    Viewer_W.Set_Aspect_Mode(false);
    Viewer_s.Set_Aspect_Mode(false);
    Viewer_s_normed.Set_Aspect_Mode(false);
    Viewer_classification.Set_Aspect_Mode(false);
    Viewer_L.Set_Aspect_Mode(false);
    Viewer_L_partial_s.Set_Aspect_Mode(false);
    Viewer_gradient.Set_Aspect_Mode(false);
    Viewer_x.Set_Transformation_Mode(false);
    Viewer_y.Set_Transformation_Mode(false);
    Viewer_W.Set_Transformation_Mode(false);
    Viewer_s.Set_Transformation_Mode(false);
    Viewer_s_normed.Set_Transformation_Mode(false);
    Viewer_classification.Set_Transformation_Mode(false);
    Viewer_L.Set_Transformation_Mode(false);
    Viewer_L_partial_s.Set_Transformation_Mode(false);
    Viewer_gradient.Set_Transformation_Mode(false);

    //Init chartview
    pChartView_Loss = new QChartView(this);
    ui->gridLayout_Loss->addWidget(pChartView_Loss);
    pChartView_Loss->setRenderHint(QPainter::Antialiasing);

    pChartView_Accuracy = new QChartView(this);
    ui->gridLayout_Accuracy->addWidget(pChartView_Accuracy);
    pChartView_Accuracy->setRenderHint(QPainter::Antialiasing);

    //show
    showMaximized();
    Set_MatrixViewDiemsnions();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Softmax classifiaction visualization");

    //status bar
    pQL_ValueUnderCursor = new QLabel(this);
    pQL_ValueUnderCursor->setToolTip("Value under mouse");
    ui->statusbar->addPermanentWidget(pQL_ValueUnderCursor);

    pQL_CursorPosition = new QLabel(this);
    pQL_CursorPosition->setToolTip("Mouse Position");
    ui->statusbar->addPermanentWidget(pQL_CursorPosition);

    //connect
    connect(&Viewer_x,              SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_y,              SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_W,              SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_s,              SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_s_normed,       SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_classification, SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_L,              SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_L_partial_s,    SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));
    connect(&Viewer_gradient,       SIGNAL(MouseMoved_Value(QString)),      pQL_ValueUnderCursor,   SLOT(setText(QString)));

    connect(&Viewer_x,              SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_y,              SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_W,              SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_s,              SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_s_normed,       SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_classification, SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_L,              SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_L_partial_s,    SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));
    connect(&Viewer_gradient,       SIGNAL(MouseMoved_Pos(QString)),        pQL_CursorPosition,     SLOT(setText(QString)));

    //set default data
    vvData_X = vvData_X_default;
    vData_Y = vData_Y_default;
    Data_Vec2Mat();
}

D_MAKRO_SoftmaxVisualization::~D_MAKRO_SoftmaxVisualization()
{
    delete ui;
}

void D_MAKRO_SoftmaxVisualization::closeEvent(QCloseEvent *event)
{
    if(ClosingPossible)
    {
        delete ui;
        event->accept();
    }
    else
    {
        event->ignore();
        this->showMinimized();
    }
}

void D_MAKRO_SoftmaxVisualization::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_SoftmaxVisualization::Update_Ui()
{
    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_SoftmaxVisualization::Update_Views()
{
    Viewer_x.Update_View();
    Viewer_y.Update_View();
    Viewer_W.Update_View();
    Viewer_s.Update_View();
    Viewer_s_normed.Update_View();
    Viewer_classification.Update_View();
    Viewer_L.Update_View();
    Viewer_L_partial_s.Update_View();
    Viewer_gradient.Update_View();
}

void D_MAKRO_SoftmaxVisualization::Update_Images()
{
    Viewer_x.Update_Image(&MA_x);
    Viewer_y.Update_Image(&MA_y);
    Viewer_W.Update_Image(&MA_W);
    Viewer_s.Update_Image(&MA_s);
    Viewer_s_normed.Update_Image(&MA_s_normed);
    Viewer_classification.Update_Image(&MA_classification);
    Viewer_L.Update_Image(&MA_L);
    Viewer_L_partial_s.Update_Image(&MA_L_partial_s);
    Viewer_gradient.Update_Image(&MA_gradient);

    Update_Views();
    Update_Ui();
    Update_Views();
}

void D_MAKRO_SoftmaxVisualization::Load_File_CSV()
{
    //get filepath
    QString QS_Path = QFileDialog::getOpenFileName(
                this,
                "Load CSV/TXT Training Data",
                pStore->dir_M_Softmax()->path(),
                "CSV/TXT Files (*.csv *.txt)");
    if(QS_Path.isEmpty())
        return;

    //set default dir
    pStore->set_dir_M_Softmax(QS_Path);

    //file info
    QFileInfo FI(QS_Path);
    if(!FI.exists())
        return;

    //file
    QFile F(FI.absoluteFilePath());
    if (!F.open(QIODevice::ReadOnly))
        return;

    //text stream
    QTextStream TS(&F);

    //clear old
    vvData_X.clear();
    vData_Y.clear();

    //read line by line
    for(size_t l = 0; !TS.atEnd(); l++)
    {
        QStringList QSL_line = TS.readLine().split(",");

        if(QSL_line.size() >= 2)
        {
            //feature data
            vector<double> vFeats;

            //loop features in line
            for(int f = 0; f < QSL_line.size() - 1; f++)
            {
                bool ok;
                double feature = QSL_line[f].toDouble(&ok);
                if(ok)
                    vFeats.push_back(feature);
            }

            //push back a 1 to integrate b (linear offset) into W
            //see: homgenious coordinates
            vFeats.push_back(1);

            //get class
            bool ok;
            int class_id = QSL_line.last().toInt(&ok);
            if(ok)
                vData_Y.push_back(class_id);

            //save data
            vvData_X.push_back(vFeats);
        }
    }

    //close
    F.close();

    Data_Vec2Mat();
}

void D_MAKRO_SoftmaxVisualization::Data_Vec2Mat()
{
    //Dataset size/errors
    if(vvData_X.empty())                                return;
    if(vData_Y.empty())                                 return;
    if(vvData_X.size() != vData_Y.size())               return;
    N = vData_Y.size();

    //feature size/errors
    if(vvData_X[0].empty())                             return;
    M = vvData_X[0].size();
    for(size_t i = 1; i < vvData_X.size(); i++)
        if(vvData_X[i].size() != M)                     return;

    //class size/errors
    K = 0;
    for(size_t i = 0; i < vData_Y.size(); i++)
        if(vData_Y[i] >= static_cast<int>(K))
            K++;
    for(size_t i = 0; i < vData_Y.size(); i++)
        if(vData_Y[i] >= static_cast<int>(K))
            return;

    //init mats
    Data_InitMats_CorrectSize();

    //adapt ui
    Set_MatrixViewDiemsnions();

    //init x
    for(size_t x = 0; x < N; x++)
        for(size_t y = 0; y < M; y++)
            MA_x.at<double>(y, x) = vvData_X[x][y];

    //init y
    for(size_t x = 0; x < N; x++)
        MA_y.at<double>(0, x) = vData_Y[x];

    //clear loss/accuracy
    vLoss.clear();
    vAccuracy.clear();
    iteration = 0;

    //show images
    Update_Images();
}

void D_MAKRO_SoftmaxVisualization::Data_InitMats_CorrectSize(bool init_x_and_y)
{
    //init Mats
    if(init_x_and_y)
    {
        MA_x                = Mat::zeros(M, N, CV_64FC1);
        MA_y                = Mat::zeros(1, N, CV_64FC1);
    }

    MA_W                = Mat::zeros(K, M, CV_64FC1);
    MA_s                = Mat::zeros(K, N, CV_64FC1);
    MA_s_normed         = Mat::zeros(K, N, CV_64FC1);
    MA_classification   = Mat::zeros(1, N, CV_64FC1);
    MA_L                = Mat::zeros(1, N, CV_64FC1);
    MA_L_partial_s      = Mat::zeros(K, N, CV_64FC1);
    MA_gradient         = Mat::zeros(K, M, CV_64FC1);
}

void D_MAKRO_SoftmaxVisualization::Init_W()
{
    Data_InitMats_CorrectSize(false);

    MA_W = Mat::zeros(K, M, CV_64FC1);
    randn(MA_W, ui->doubleSpinBox_W_mu->value(), ui->doubleSpinBox_W_sigma->value());

    step_next = STEP_s;

    Update_Images();

    ui->pushButton_Proc_Step->setEnabled(true);
    ui->pushButton_Proc_Iteration->setEnabled(true);
    ui->pushButton_Proc_Endless->setEnabled(true);
    ui->pushButton_ResetAndInit->setText("Reset and init W");
}

void D_MAKRO_SoftmaxVisualization::Set_MatrixViewDiemsnions()
{
    ui->spinBox_N_datasets->setValue(N);
    ui->spinBox_M_features->setValue(M);
    ui->spinBox_K_classes->setValue(K);

    /*
    QSizePolicy QSP_MN;     QSP_MN.setVerticalStretch(M);       QSP_MN.setHorizontalStretch(N);     QSP_MN.setVerticalPolicy(QSizePolicy::Preferred);   QSP_MN.setHorizontalPolicy(QSizePolicy::Preferred);
    QSizePolicy QSP_KM;     QSP_KM.setVerticalStretch(K);       QSP_KM.setHorizontalStretch(M);     QSP_KM.setVerticalPolicy(QSizePolicy::Preferred);   QSP_KM.setHorizontalPolicy(QSizePolicy::Preferred);
    QSizePolicy QSP_KN;     QSP_KN.setVerticalStretch(K);       QSP_KN.setHorizontalStretch(N);     QSP_KN.setVerticalPolicy(QSizePolicy::Preferred);   QSP_KN.setHorizontalPolicy(QSizePolicy::Preferred);
    QSizePolicy QSP_1N;     QSP_1N.setVerticalStretch(1);       QSP_1N.setHorizontalStretch(N);     QSP_1N.setVerticalPolicy(QSizePolicy::Preferred);   QSP_1N.setHorizontalPolicy(QSizePolicy::Preferred);
    QSizePolicy QSP_MM;     QSP_MM.setVerticalStretch(M);       QSP_MM.setHorizontalStretch(M);     QSP_MM.setVerticalPolicy(QSizePolicy::Preferred);   QSP_MM.setHorizontalPolicy(QSizePolicy::Preferred);

    ui->groupBox_Other->setSizePolicy(QSP_KM);  //QSP_MM
    ui->groupBox_W->setSizePolicy(QSP_KM);
    ui->groupBox_grad->setSizePolicy(QSP_KM);

    ui->groupBox_y->setSizePolicy(QSP_1N);
    ui->groupBox_x->setSizePolicy(QSP_KN);  //QSP_MN
    ui->groupBox_s->setSizePolicy(QSP_KN);
    ui->groupBox_L->setSizePolicy(QSP_1N);
    ui->groupBox_L_partial_s->setSizePolicy(QSP_KN);

    ui->groupBox_accuracy->setSizePolicy(QSP_KN); //QSP_MN
    ui->groupBox_s_normed->setSizePolicy(QSP_KN);
    ui->groupBox_classification->setSizePolicy(QSP_1N);
    ui->groupBox_loss->setSizePolicy(QSP_KN);
    */
}

void D_MAKRO_SoftmaxVisualization::Proc_Step()
{
    switch (step_next)
    {
    case STEP_s:            Proc_s();                   break;
    case STEP_s_norm:       Proc_s_normed();            break;
    case STEP_classify:     Proc_classify();            break;
    case STEP_accuracy:     Proc_accuracy();            break;
    case STEP_L:            Proc_L();                   break;
    case STEP_loss:         Proc_loss();                break;
    case STEP_L_partial:    Proc_L_partial();           break;
    case STEP_grad:         Proc_grad();                break;
    case STEP_W:            Proc_W();                   break;
    default:                step_next = STEP_NUMBER_OF; return;
    }
}

void D_MAKRO_SoftmaxVisualization::Proc_StepDetail()
{
    Proc_Step();
}

void D_MAKRO_SoftmaxVisualization::Proc_StepIteration()
{
    do Proc_Step();
    while (step_next != STEP_s);
}

void D_MAKRO_SoftmaxVisualization::Proc_StepEndless()
{
    ui->pushButton_LoadData->setEnabled(false);
    ui->pushButton_Proc_Step->setEnabled(false);
    ui->pushButton_Proc_Iteration->setEnabled(false);
    ui->pushButton_Proc_Endless->setEnabled(false);
    ui->pushButton_ResetAndInit->setEnabled(false);
    ui->pushButton_Proc_Stop->setEnabled(true);
    ui->doubleSpinBox_delta->setEnabled(false);
    ui->doubleSpinBox_lambda->setEnabled(false);

    Update_Ui();
    while (!endless_proc_stop)
    {
        Proc_StepIteration();
        Update_Ui();
    }

    ui->pushButton_LoadData->setEnabled(true);
    ui->pushButton_Proc_Step->setEnabled(true);
    ui->pushButton_Proc_Iteration->setEnabled(true);
    ui->pushButton_Proc_Endless->setEnabled(true);
    ui->pushButton_ResetAndInit->setEnabled(true);
    ui->pushButton_Proc_Stop->setEnabled(false);
    ui->doubleSpinBox_delta->setEnabled(true);
    ui->doubleSpinBox_lambda->setEnabled(true);
    endless_proc_stop = false;
}

void D_MAKRO_SoftmaxVisualization::Proc_SaveVideos()
{
    bool ok;

    double lambda_min = QInputDialog::getDouble(
                this,
                "Regularization",
                "lambda min =",
                0,
                0,
                50000,
                3,
                &ok);
    if(!ok)
        return;

    double lambda_max = QInputDialog::getDouble(
                this,
                "Regularization",
                "lambda max =",
                10,
                0,
                50000,
                3,
                &ok);
    if(!ok)
        return;

    double lambda_step = QInputDialog::getDouble(
                this,
                "Regularization",
                "lambda step =",
                1,
                0,
                50000,
                3,
                &ok);
    if(!ok)
        return;

    double delta_min_exp = QInputDialog::getDouble(
                this,
                "Learning rate",
                "delta min = 10^",
                0,
                0,
                -10,
                3,
                &ok);
    if(!ok)
        return;

    double delta_max_exp = QInputDialog::getDouble(
                this,
                "Learning rate",
                "delta max = 10^",
                10,
                0,
                50000,
                3,
                &ok);
    if(!ok)
        return;

    double delta_step_exp = QInputDialog::getDouble(
                this,
                "Learning rate",
                "delta step = 10^",
                1,
                0,
                50000,
                3,
                &ok);
    if(!ok)
        return;

}

void D_MAKRO_SoftmaxVisualization::Proc_SaveVideo()
{
    QString path_save = QFileDialog::getExistingDirectory(
                this,
                "Save Video",
                pStore->dir_M_Softmax()->path());

    if(path_save.isEmpty())
        return;

    QDir DIR_Save(path_save);
    if(!DIR_Save.exists())
        return;

    bool ok;
    int max_iterations = QInputDialog::getInt(
                this,
                "Max Iterations",
                "Max iterations:",
                10000,
                0,
                1000000,
                100,
                &ok);
    if(!ok)
        return;

    Proc_SaveVideo(
                DIR_Save,
                ui->doubleSpinBox_lambda->value(),
                ui->doubleSpinBox_delta->value(),
                25,
                max_iterations);
}

void D_MAKRO_SoftmaxVisualization::Proc_SaveVideo(QDir DIR_Save, double lambda, double delta, double fps, size_t max_iterations)
{
    ui->pushButton_Proc_Stop->setEnabled(true);

    ui->doubleSpinBox_delta->setValue(delta);
    ui->doubleSpinBox_lambda->setValue(lambda);

    //size
    int w = this->width();
    int h = this->height();

    //Init Video Writer
    D_VideoWriter VW_Out;
    VW_Out.set_isColor(true);
    VW_Out.set_Size(w, h);
    VW_Out.set_FPS(fps);
    VW_Out.set_PathOut(DIR_Save.path() + "/SoftmaxClassification_learn_" + QString::number(delta) + "_regul_" + QString::number(lambda) + ".avi");
    VW_Out.init_VideoWriter();
    if(!VW_Out.is_Init())
    {
        return;
    }

    //loop video
    while (!endless_proc_stop && iteration < max_iterations)
    {
        Proc_StepIteration();
        Update_Ui();

        //convert to MA
        QPixmap PX = this->grab();
        PX = PX.scaled(w, h);
        QImage QI = PX.toImage();
        Mat MA;
        D_Img_Proc::Convert_QImage_to_Mat(&MA, &QI);

        //write
        VW_Out.AddFrame(MA);
    }
    endless_proc_stop = true;

    //close writer
    VW_Out.EndVideoWriting();


    ui->pushButton_Proc_Stop->setEnabled(false);
}

void D_MAKRO_SoftmaxVisualization::Proc_SaveVideos(QDir Path, double fps, size_t max_iterations, double lambda_min, double lambda_max, double lambda_step, double delta_min_exp, double delta_max_exp, double delta_step_exp)
{
    for(double lambda = lambda_min; lambda < lambda_max; lambda += lambda_step)
        for(double delta_exp = delta_min_exp; delta_exp < delta_max_exp; delta_exp += delta_step_exp)
            Proc_SaveVideo(Path, lambda, delta_exp, fps, max_iterations);
}

void D_MAKRO_SoftmaxVisualization::Proc_s()
{
    iteration++;
    ui->label_Iteration->setText("Iteration: " + QString::number(iteration));

    //s = W * x
    MA_s = MA_W * MA_x;

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_s, &MA_s) != ER_okay)
        endless_proc_stop = true;
    Viewer_s.Update_Image(&MA_color_s);

    ui->groupBox_s->setTitle("s (norm: " + QString::number(norm(MA_s)) + ")");

    step_next = STEP_s_norm;
}

void D_MAKRO_SoftmaxVisualization::Proc_s_normed()
{
    //datasets are calced independently
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        //find max s (logC)
        double max = - INFINITY;
        for(size_t y_class = 0; y_class < K; y_class++)
            if(MA_s.at<double>(y_class, x_dataset) > max)
                max = MA_s.at<double>(y_class, x_dataset);

        //sum e^s
        double sum = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            sum += pow(c_E, MA_s.at<double>(y_class, x_dataset) - max);

        //s_normed = e^s_j / sum(e^s)
        for(size_t y_class = 0; y_class < K; y_class++)
            MA_s_normed.at<double>(y_class, x_dataset) = pow(c_E, MA_s.at<double>(y_class, x_dataset) - max) / sum;
    }

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_s_normed, &MA_s_normed) != ER_okay)
        endless_proc_stop = true;
    Viewer_s_normed.Update_Image(&MA_color_s_normed);

    ui->groupBox_s_normed->setTitle("softmax(s) (norm: " + QString::number(norm(MA_s_normed)) + ")");

    step_next = STEP_classify;
}

void D_MAKRO_SoftmaxVisualization::Proc_classify()
{
    //datasets are calced independently
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        //find top normed score
        double top_score = -INFINITY;
        size_t top_class = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
        {
            double score = MA_s_normed.at<double>(y_class, x_dataset);
            if(score > top_score)
            {
                top_score = score;
                top_class = y_class;
            }
        }

        //class = top score index
        MA_classification.at<double>(0, x_dataset) = top_class;
    }

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_classification, &MA_classification) != ER_okay)
        endless_proc_stop = true;
    Viewer_classification.Update_Image(&MA_color_classification);

    step_next = STEP_accuracy;
}

void D_MAKRO_SoftmaxVisualization::Proc_accuracy()
{
    //count correctly classified datasets
    size_t correct_count = 0;
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
        if(MA_y.at<double>(0, x_dataset) == MA_classification.at<double>(0, x_dataset))
            correct_count++;

    //accuracy = correct / all
    accuracy = static_cast<double>(correct_count) / N;

    ui->groupBox_accuracy->setTitle("accuracy: " + QString::number(accuracy, 'g', 15));

    vAccuracy.push_back(accuracy);

    D_Plot::Plot_Line_XY_Single(
                pChartView_Accuracy,
                vAccuracy,
                "",
                "",
                "",
                "accuracy");
    pChartView_Accuracy->chart()->legend()->setVisible(false);
    pChartView_Accuracy->chart()->axisY()->setMin(0);
    pChartView_Accuracy->chart()->axisY()->setMax(1);

    step_next = STEP_L;
}

void D_MAKRO_SoftmaxVisualization::Proc_L()
{
    //datasets are calced independently
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        //sum e^s
        double sum = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            sum += pow(c_E, MA_s_normed.at<double>(y_class, x_dataset));

        //log_e(sum(e^s))
        double log_sum = log(sum) / log(c_E);

        //correct class index
        size_t index_correct_class = MA_y.at<double>(0, x_dataset);

        //score of correct class
        double score_correct_class = MA_s_normed.at<double>(index_correct_class, x_dataset);

        //L = - class_correct_label + log_e(sum(e^s))
        MA_L.at<double>(0, x_dataset) = - score_correct_class + log_sum;
    }

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_L, &MA_L) != ER_okay)
        endless_proc_stop = true;
    Viewer_L.Update_Image(&MA_color_L);

    ui->groupBox_L->setTitle("L (norm: " + QString::number(norm(MA_L)) + ")");
    step_next = STEP_loss;
}

void D_MAKRO_SoftmaxVisualization::Proc_loss()
{
    double lambda = ui->doubleSpinBox_lambda->value();

    //square of 2-norm of W (aka sum of squares)
    double w2_norm_sqaure = 0;
    for(size_t x_features = 0; x_features < M; x_features++)
        for(size_t y_class = 0; y_class < K; y_class++)
        {
            double w_value = MA_W.at<double>(y_class, x_features);
            w2_norm_sqaure += (w_value * w_value);
        }

    //sum L
    double sum_L = 0;
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
        sum_L += MA_L.at<double>(0, x_dataset);

    //mean L
    double mean_L = sum_L / static_cast<double>(N);

    //loss = mean(L) + regularisation * 2-norm(W)^2
    loss = mean_L + lambda * w2_norm_sqaure;

    ui->groupBox_loss->setTitle("loss: " + QString::number(loss, 'g', 15));

    vLoss.push_back(loss);

    D_Plot::Plot_Line_XY_Single(
                pChartView_Loss,
                vLoss,
                "",
                "",
                "",
                "loss",
                c_AXE_TRANS_LIN,
                c_AXE_TRANS_LOG_10);
    //pChartView_Loss->chart()->legend()->setVisible(false);

    step_next = STEP_L_partial;
}

void D_MAKRO_SoftmaxVisualization::Proc_L_partial()
{
    MA_L_partial_s = MA_s_normed.clone();

    //datasets are calced independently
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        //index of classifications (result and ground truth)
        size_t index_correct_class = MA_y.at<double>(0, x_dataset);
        size_t index_classified_as = MA_classification.at<double>(0, x_dataset);

        //-1 if corrctly classified
        if(index_classified_as == index_correct_class)
            MA_L_partial_s.at<double>(index_correct_class, x_dataset) -= 1;
    }

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_L_partial_s, &MA_L_partial_s) != ER_okay)
        endless_proc_stop = true;
    Viewer_L_partial_s.Update_Image(&MA_color_L_partial_s);

    ui->groupBox_L_partial_s->setTitle("L partial s (norm: " + QString::number(norm(MA_s)) + ")");
    step_next = STEP_grad;
}

void D_MAKRO_SoftmaxVisualization::Proc_grad()
{
    double lambda = ui->doubleSpinBox_lambda->value();

    MA_gradient = Mat::zeros(K, M, CV_64FC1);

    //sum (datasets) of dyadic pruduct of s_partial_s and x
    for(size_t i_dataset = 0; i_dataset < N; i_dataset++)
        for(size_t y_class = 0; y_class < K; y_class++)
            for(size_t x_features = 0; x_features < M; x_features++)
                MA_gradient.at<double>(y_class, x_features) += MA_x.at<double>(x_features, i_dataset) * MA_L_partial_s.at<double>(y_class, i_dataset);

    //regularistaion
    for(size_t y_class = 0; y_class < K; y_class++)
        for(size_t x_features = 0; x_features < M; x_features++)
            MA_gradient.at<double>(y_class, x_features) += 2 * lambda * MA_W.at<double>(y_class, x_features);

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_gradient, &MA_gradient) != ER_okay)
        endless_proc_stop = true;
    Viewer_gradient.Update_Image(&MA_color_gradient);

    ui->groupBox_grad->setTitle("gradient (norm: " + QString::number(norm(MA_gradient)) + ")");

    step_next = STEP_W;
}

void D_MAKRO_SoftmaxVisualization::Proc_W()
{
    double learning_rate = pow(10, ui->doubleSpinBox_delta->value());

    //new W = old W - (learning rate * loss * grad)
    for(size_t y_class = 0; y_class < K; y_class++)
        for(size_t x_features = 0; x_features < M; x_features++)
            MA_W.at<double>(y_class, x_features) -= learning_rate * MA_gradient.at<double>(y_class, x_features);

    if(D_Img_Proc::Highlight_NumericalProblems(&MA_color_W, &MA_W) != ER_okay)
        endless_proc_stop = true;
    Viewer_W.Update_Image(&MA_color_W);

    ui->groupBox_W->setTitle("W (norm: " + QString::number(norm(MA_W)) + ")");

    step_next = STEP_s;
}

void D_MAKRO_SoftmaxVisualization::on_pushButton_LoadData_clicked()
{
    Load_File_CSV();
}

void D_MAKRO_SoftmaxVisualization::on_pushButton_Proc_Step_clicked()
{
    Proc_StepDetail();
}

void D_MAKRO_SoftmaxVisualization::on_pushButton_Proc_Iteration_clicked()
{
    Proc_StepIteration();
}

void D_MAKRO_SoftmaxVisualization::on_pushButton_Proc_Endless_clicked()
{
    Proc_StepEndless();
}

void D_MAKRO_SoftmaxVisualization::on_pushButton_Proc_Stop_clicked()
{
    endless_proc_stop = true;
}

void D_MAKRO_SoftmaxVisualization::on_pushButton_ResetAndInit_clicked()
{
    //clear loss/accuracy
    vLoss.clear();
    vAccuracy.clear();
    iteration = 0;
    ui->label_Iteration->setText("iteration 0");

    Init_W();
}

