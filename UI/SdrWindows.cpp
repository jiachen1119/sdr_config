//
// Created by Kepeng Luan on 22-12-24.

// You may need to build the project (run Qt uic code generator) to get "ui_sdr_windows.h" resolved
// You can try to execute "uic SdrWindows.ui -o ui_sdr_windows.h"

#include "SdrWindows.h"

SdrWindows::SdrWindows(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::SdrWindows) {
    ui->setupUi(this);

    init();
    toolButtonConnect();

    //set the Start button
    connect(ui->pushButton_start,&QPushButton::clicked, this,[&](){
        //get the user config
        data_type_=ui->comboBox->currentText();
        sampling_freq_=ui->lineEdit->text();
        work_path_.setPath(ui->lineEdit_workPath->text());
        config_path_.setPath(ui->lineEdit_configPath->text());
        rawData_path_.setPath(ui->lineEdit_rawData->text());
        //todo: model config file need to be debug
        QStringList writeBtn_list=readConfigInLine(config_path_.path());
        switch (buttonGroup_id_) {
            case 0:
                fileConfig(writeBtn_list);
                break;
            case 1:
                hackrfConfig(writeBtn_list);
                break;
            default:
                break;
        }
    });

    connect(button_group_.get(), &QButtonGroup::idToggled,
            this, &SdrWindows::buttonToggled);

    //只要按下monitor就停止
    connect(term_window_.get(), &TerminalWindow::end_monitor, &monitor_Qthread_, &monitor_Qthread::change_endSign_status);
    //接收到数据，触发 绘图
    qRegisterMetaType<QMap<int,double>>("myQMap");
    connect(&monitor_Qthread_, &monitor_Qthread::send_map, chart_window_.get(), &ChartWindow::receive_data);
}

SdrWindows::~SdrWindows() {
    monitor_Qthread_.quit();
    if (monitor_Qthread_.isRunning())
        monitor_Qthread_.wait();
    delete ui;
}

void SdrWindows::init() {
    //todo: make the special edit line only written numbers

    // widget initialize
    chart_window_=std::make_unique<ChartWindow>();
    term_window_ =std::make_unique<TerminalWindow>();
    status_label_=std::make_unique<QLabel>
            ("Welcome to Config Creator for GNSS-SDR! (Written by Kepeng Luan from SEU)");
    ui->statusbar->addWidget(status_label_.get());

    // select the "File" model default
    ui->radioButtonFile->setChecked(true);
    ui->stackedWidget->setCurrentWidget(ui->page);

    // button group setting
    button_group_=std::make_unique<QButtonGroup>(this);
    button_group_->addButton(ui->radioButtonFile, 0);
    button_group_->addButton(ui->radioButtonHackrf, 1);
    button_group_->addButton(ui->radioButtonUSRP, 2);

    // mkdir workPath
    QString build_path=QCoreApplication::applicationDirPath();
    QString work_path=build_path+ "/gnss_sdr_workPath";
    work_path_.setPath(work_path);
    if(!work_path_.exists()){
        qDebug()<<"workPath is not exist";
        work_path_.mkpath(".");
    }
    config_path_=work_path_;
    rawData_path_=work_path_;

    settingInit();
    ui->lineEdit_configPath->setText(config_path_.path());
    ui->lineEdit_rawData->setText(rawData_path_.path());
    ui->lineEdit_workPath->setText(work_path_.path());

    // hackrf bias voltage
    ui->checkBox_bias->setCheckState(Qt::Checked);
}

void SdrWindows::buttonToggled(int button, bool checked) {
    if (!checked)
        return;
    buttonGroup_id_=button;
    switch (button)
    {
        case 0:
            //todo: need to remember the choice of combobox in the different stackedWidget
            ui->stackedWidget->setCurrentWidget(ui->page);
            ui->comboBox->setEnabled(true);
            ui->comboBox->setCurrentIndex(0);
            break;
        case 1:
            ui->stackedWidget->setCurrentWidget(ui->page_2);
            ui->comboBox->setCurrentIndex(7);
            ui->comboBox->setEnabled(false);
            break;
        case 2:
            qDebug("This is button two");
            break;
        default:
            break;
    }
}

QStringList SdrWindows::readConfigInLine(const QString& file_path) {
    QFile file(file_path);
    QStringList read_QString_list;

    if(!file.exists()||!file.open(QIODevice::ReadOnly|QIODevice::Text|QIODevice::ExistingOnly)){
        QMessageBox::critical(this,"File Read Error",
                              QString("cannot find: ")+file_path+QString(" , please retry!"));
        qDebug()<<QString("cannot find ")+file_path;
    }
    else{
        QTextStream in(&file);
        while (!in.atEnd()){
            QString line=in.readLine();
            read_QString_list<<line<<QString('\n');
        }
        file.close();
    }
    return read_QString_list;
}

void SdrWindows::fileConfig(QStringList data_list) {
    for (int list_index = 0; list_index < data_list.size(); ++list_index) {
        myQString myStr(data_list.at(list_index));
        QString keyWord=myStr.readKeyWordAll();
        if (keyWord.contains("SignalSource.sampling_frequency",Qt::CaseInsensitive)){
            QString str=QString("%1=%2\n").arg(keyWord).arg(sampling_freq_);
            data_list.replace(list_index, str);
        }
        if (keyWord.contains("SignalSource.item_type",Qt::CaseInsensitive)){
            QString str=QString("%1=%2\n").arg(keyWord).arg(data_type_);
            data_list.replace(list_index, str);
        }
        if (keyWord.contains("SignalSource.filename",Qt::CaseInsensitive)){
            QString str=QString("%1=%2\n").arg(keyWord).arg(rawData_path_.path());
            data_list.replace(list_index, str);
        }
    }
    QFile generate_file(work_path_.path() + "/generate_config.conf");
    if(!generate_file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        ui->statusbar->showMessage("Generating failed!",2000);
    else{
            for (const auto & index : data_list) {
                generate_file.write(index.toStdString().c_str());
            }
            generate_file.close();
            ui->statusbar->showMessage("File config completed!",2000);
        }
    //ask if the user want to run gnss-sdr
    QMessageBox::StandardButton result = QMessageBox::question(this,"GNSS-SDR","Do you want to run GNSS-SDR with sdr_config.conf?",
                              QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if (result==QMessageBox::Yes){
        if(!monitor_Qthread_.isRunning())
            monitor_Qthread_.start();
        term_window_->show();
        term_window_->cmd_start(work_path_.path());
        chart_window_->show();
    }
}

void SdrWindows::hackrfConfig(QStringList data_list) {
    hackRf_.setSamplingFrequency(ui->lineEdit->text().toInt());
    hackRf_.setGain(ui->lineEdit_gain->text().toInt());
    hackRf_.setIfGain(ui->lineEdit_if->text().toInt());
    hackRf_.setRfGain(ui->lineEdit_rf->text().toInt());
    if (ui->checkBox_agc->isChecked())
        hackRf_.setAgcEnabled(true);
    else
        hackRf_.setAgcEnabled(false);
    hackRf_.HackrfGetConfig(data_list);
    QFile generate_file(work_path_.path() + "/generate_config.conf");
    if (!generate_file.open(QIODevice::WriteOnly | QIODevice::Text))
        ui->statusbar->showMessage("Generating failed!",2000);
    else
    {
        for (const auto & index : data_list) {
            generate_file.write(index.toStdString().c_str());
        }
        generate_file.close();
        ui->statusbar->showMessage("hackrf config completed!",2000);
    }
    QMessageBox::StandardButton result = QMessageBox::question(this,"GNSS-SDR","Do you want to run GNSS-SDR with sdr_config.conf?",
                                                               QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if (result==QMessageBox::Yes) {
        if (!monitor_Qthread_.isRunning())
            monitor_Qthread_.start();
        term_window_->show();
        term_window_->cmd_start(work_path_.path());
        chart_window_->show();
    }
}

void SdrWindows::settingInit() {
    // save the setting
    QString setting_path=work_path_.path()+"/Setting.ini";
    QFile setting_file(setting_path);
    setting_=std::make_unique<QSettings>(setting_path,QSettings::IniFormat);
    if (!setting_file.exists()){
        qDebug()<<"Setting configuration file is not exist!";
        setting_->beginGroup("Path");
        setting_->setValue("Configuration_Path", config_path_.path());
        setting_->setValue("Raw_Data_Path", rawData_path_.path());
        setting_->setValue("Working_Path",work_path_.path());
        setting_->endGroup();

        setting_->sync();
    } else{
        work_path_.setPath(setting_->value("Path/Working_Path").toString());
        rawData_path_.setPath(setting_->value("Path/Raw_Data_Path").toString());
        config_path_.setPath(setting_->value("Path/Configuration_Path").toString());
    }
}

void SdrWindows::toolButtonConnect() {
    // tool button connect
    connect(ui->toolButton_rawData,&QToolButton::clicked, this,[&]()  {
        QString temp_path=QFileDialog::getOpenFileName(this, "Open Raw data",
                                                       rawData_path_.path(), "raw data(*.bin *.dat)");
        if(!temp_path.isNull()){
            rawData_path_.setPath(temp_path);
            ui->lineEdit_rawData->setText(rawData_path_.path());
            setting_->beginGroup("Path");
            setting_->setValue("Raw_Data_Path", rawData_path_.path());
            setting_->endGroup();
            setting_->sync();
        }
    });

    connect(ui->toolButton_conf,&QToolButton::clicked, this,[&]()  {
        QString temp_path=QFileDialog::getOpenFileName(this, "Open configuration file",
                                                       config_path_.path(), "configuration(*.conf)");
        if (!temp_path.isNull()){
            config_path_.setPath(temp_path);
            ui->lineEdit_configPath->setText(config_path_.path());
            setting_->beginGroup("Path");
            setting_->setValue("Configuration_Path", config_path_.path());
            setting_->endGroup();
            setting_->sync();
        }
    });

    connect(ui->toolButton_workPath,&QToolButton::clicked, this,[&]()  {
        QString temp_path=QFileDialog::getExistingDirectory(this, "Choose the workPlace",
                                                            work_path_.path());
        if(!temp_path.isNull()){
            work_path_.setPath(temp_path);
            ui->lineEdit_workPath->setText(work_path_.path());
            setting_->beginGroup("Path");
            setting_->setValue("Working_Path",work_path_.path());
            setting_->endGroup();
            setting_->sync();
        }
    });
}

