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
    ui->pushButton_Proc_Step->setEnabled(false);
    ui->pushButton_Proc_Iteration->setEnabled(false);
    ui->pushButton_Proc_Endless->setEnabled(false);
    ui->pushButton_ResetAndInit->setEnabled(false);
    ui->pushButton_Proc_Stop->setEnabled(false);

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

    ui->pushButton_ResetAndInit->setEnabled(true);
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
        Proc_Step();
        //Proc_StepIteration();
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

void D_MAKRO_SoftmaxVisualization::Proc_s()
{
    iteration++;
    ui->label_Iteration->setText("Iteration: " + QString::number(iteration));

    MA_s = MA_W * MA_x;

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_s,
                &MA_s),
        "Proc_s",
        "");
    Viewer_s.Update_Image(&MA_color_s);

    step_next = STEP_s_norm;
}

void D_MAKRO_SoftmaxVisualization::Proc_s_normed()
{
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        double max = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            if(MA_s.at<double>(y_class, x_dataset) > max)
                max = MA_s.at<double>(y_class, x_dataset);

        double sum = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            sum += pow(c_E, MA_s.at<double>(y_class, x_dataset) - max);

        for(size_t y_class = 0; y_class < K; y_class++)
            MA_s_normed.at<double>(y_class, x_dataset) = pow(c_E, MA_s.at<double>(y_class, x_dataset) - max) / sum;
    }

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_s_normed,
                &MA_s_normed),
        "Proc_s_normed",
        "");
    Viewer_s_normed.Update_Image(&MA_color_s_normed);

    step_next = STEP_classify;
}

void D_MAKRO_SoftmaxVisualization::Proc_classify()
{
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        double top_score = 0;
        int top_class = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
        {
            double score = MA_s_normed.at<double>(y_class, x_dataset);
            if(score > top_score)
            {
                top_score = score;
                top_class = y_class;
            }
        }

        MA_classification.at<double>(0, x_dataset) = top_class;
    }

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_classification,
                &MA_classification),
        "Proc_classify",
        "");
    Viewer_classification.Update_Image(&MA_color_classification);

    step_next = STEP_accuracy;
}

void D_MAKRO_SoftmaxVisualization::Proc_accuracy()
{
    size_t correct_count = 0;
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
        if(MA_y.at<double>(0, x_dataset) == MA_classification.at<double>(0, x_dataset))
            correct_count++;

    accuracy = static_cast<double>(correct_count) / N;

    ui->groupBox_accuracy->setTitle("accuracy: " + QString::number(accuracy));

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
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        /*
        double max = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            if(MA_s.at<double>(y_class, x_dataset) > max)
                max = MA_s.at<double>(y_class, x_dataset);
                */

        double sum = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            sum += pow(c_E, MA_s.at<double>(y_class, x_dataset));

        double log_sum = log(sum) / log(c_E);

        MA_L.at<double>(0, x_dataset) =  - MA_y.at<double>(0, x_dataset) + log_sum;
    }

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_L,
                &MA_L),
        "Proc_L",
        "");
    Viewer_L.Update_Image(&MA_color_L);

    step_next = STEP_loss;
}

void D_MAKRO_SoftmaxVisualization::Proc_loss()
{
    double lambda = ui->doubleSpinBox_lambda->value();

    double w2_norm_sqaure = 0;
    for(size_t x_features = 0; x_features < M - 1; x_features++)
        for(size_t y_class = 0; y_class < K; y_class++)
            w2_norm_sqaure += MA_W.at<double>(y_class, x_features) * MA_W.at<double>(y_class, x_features);

    double sum_L = 0;
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
        sum_L += MA_L.at<double>(0, x_dataset);

    double mean_L = sum_L /static_cast<double>(N);
    loss = mean_L + lambda * w2_norm_sqaure;

    ui->groupBox_loss->setTitle("loss: " + QString::number(loss));

    vLoss.push_back(loss);

    D_Plot::Plot_Line_XY_Single(
                pChartView_Loss,
                vLoss,
                "",
                "",
                "",
                "loss");
    //pChartView_Loss->chart()->legend()->setVisible(false);

    //show iteration summary
    //qDebug() << "iteration:" << iteration << "accuracy:" << accuracy << "loss:" << loss;

    step_next = STEP_L_partial;
}

void D_MAKRO_SoftmaxVisualization::Proc_L_partial()
{
    for(size_t x_dataset = 0; x_dataset < N; x_dataset++)
    {
        double max = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            if(MA_s.at<double>(y_class, x_dataset) > max)
                max = MA_s.at<double>(y_class, x_dataset);

        double sum = 0;
        for(size_t y_class = 0; y_class < K; y_class++)
            sum += pow(c_E, MA_s.at<double>(y_class, x_dataset) - max);

        for(size_t y_class = 0; y_class < K; y_class++)
        {
            MA_L_partial_s.at<double>(y_class, x_dataset) = pow(c_E, MA_s.at<double>(y_class, x_dataset) - max) / sum;

            if(MA_classification.at<double>(0, x_dataset) == MA_y.at<double>(0, x_dataset))
                MA_L_partial_s.at<double>(y_class, x_dataset) -= 1;
        }
    }

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_L_partial_s,
                &MA_L_partial_s),
        "Proc_L_partial",
        "");
    Viewer_L_partial_s.Update_Image(&MA_color_L_partial_s);

    step_next = STEP_grad;
}

void D_MAKRO_SoftmaxVisualization::Proc_grad()
{
    for(size_t y_class = 0; y_class < K; y_class++)
        for(size_t x_features = 0; x_features < M; x_features++)
            MA_gradient.at<double>(y_class, x_features) = 0;

    for(size_t i_dataset = 0; i_dataset < N; i_dataset++)
        for(size_t y_class = 0; y_class < K; y_class++)
            for(size_t x_features = 0; x_features < M; x_features++)
                MA_gradient.at<double>(y_class, x_features) += MA_x.at<double>(x_features, i_dataset) * MA_L_partial_s.at<double>(i_dataset, y_class);

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_gradient,
                &MA_gradient),
        "Proc_grad",
        "");
    Viewer_gradient.Update_Image(&MA_color_gradient);

    step_next = STEP_W;
}

void D_MAKRO_SoftmaxVisualization::Proc_W()
{
    double learning_rate = pow(10, ui->doubleSpinBox_delta->value());

    for(size_t y_class = 0; y_class < K; y_class++)
        for(size_t x_features = 0; x_features < M; x_features++)
            MA_W.at<double>(y_class, x_features) -= learning_rate * loss * MA_gradient.at<double>(y_class, x_features);

    ERR(D_Img_Proc::Highlight_NumericalProblems(
                &MA_color_W,
                &MA_W),
        "Proc_W",
        "");
    Viewer_W.Update_Image(&MA_color_W);

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

void D_MAKRO_SoftmaxVisualization::ERR(int err, QString func, QString detail)
{
    ER.ERR(
                err,
                "D_MAKRO_SoftmaxVisualization",
                func,
                detail);
}
