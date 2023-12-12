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

    //set the Read button
    connect(ui->pushButton,&QPushButton::clicked, this,[&](){
        QStringList readBtn_list= readConfigInLine(config_path_.path());
        switch (btnGroup_flag_) {
            case 0:
                //read the configuration readFile
                fileConfig(readBtn_list,true);
                break;
            case 1:
                hackrfConfig(readBtn_list, true);
                break;
            case 2:
                break;
            default:
                break;
        }

    });

    //set the Start button
    connect(ui->pushButton_2,&QPushButton::clicked, this,[&](){
        data_type_=ui->comboBox->currentText();
        sampling_freq_=ui->lineEdit->text();
        //todo: model config file need to be debug
        QStringList writeBtn_list=readConfigInLine(config_path_.path());
        switch (btnGroup_flag_) {
            case 0:
                fileConfig(writeBtn_list, false);
                break;
            case 1:
                hackrfConfig(writeBtn_list, false);
                break;
            case 2:
                break;
            default:
                break;
        }
    });

    connect(button_group_.get(), &QButtonGroup::idToggled,
            this, &SdrWindows::buttonToggled);

    //set the Default button
    connect(ui->pushButton_3,&QPushButton::clicked, this,[&](){
            ui->setupUi(this);
    });
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
    btnGroup_flag_=button;
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
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text|QIODevice::ExistingOnly)){
        QMessageBox::critical(this,"File Read Error",
                              QString("cannot find: ")+file_path+QString(" , please retry!"));
        qDebug()<<QString("cannot find ")+file_path;
    }
    else{
        char* read_data=new char[100];
        qint64 readNum=file.readLine(read_data,100);
        while ((readNum !=0) && (readNum != -1)){
            QString read_data_QString(read_data);
            read_QString_list<<read_data_QString;
            readNum=file.readLine(read_data, 100);
        }
        file.close();
    }
    return read_QString_list;
}

void SdrWindows::fileConfig(QStringList data_list, bool read_or_write) {
    //true is reading function, and false is writing function
    if(read_or_write){
        for (int i = 0; i < data_list.size(); ++i) {
            myQString myStr(data_list.at(i));
            QString keyWord=myStr.readKeyWordAll();
            if(keyWord.contains("SignalSource.sampling_frequency", Qt::CaseSensitive)){
                //because some read datalist is null, readData sometimes can be out of range
                sampling_freq_=myStr.readData();
                ui->lineEdit->setText(sampling_freq_);
            }
            if(keyWord.contains("SignalSource.item_type", Qt::CaseSensitive)){
                data_type_=myStr.readData();
                ui->comboBox->setCurrentText(data_type_);
            }
            if(keyWord.contains("SignalSource.filename", Qt::CaseSensitive)){
                rawData_path_=myStr.readData();
                ui->lineEdit_rawData->setText(rawData_path_.path());
            }
        }
        ui->statusbar->showMessage("File part reading completed",2000);
    }
    else{
        rawData_path_=ui->lineEdit_rawData->text();
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
        QFile writeFile(work_path_.path() + "/sdr_config.conf");
        if(!writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
            ui->statusbar->showMessage("sdr_config.conf not found, already created",2000);
        else{
            for (int index = 0; index < data_list.size(); ++index) {
                writeFile.write(data_list.at(index).toStdString().c_str());
            }
            writeFile.close();
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
}

void SdrWindows::hackrfConfig(QStringList data_list, bool read_or_write) {
    if(read_or_write){
        hackRf_.ConfigGetHackrf(data_list);
        ui->lineEdit->setText(QString::number(hackRf_.getSamplingFrequency(),10));
        ui->lineEdit_gain->setText(QString::number(hackRf_.getGain()));
        ui->lineEdit_rf->setText(QString::number(hackRf_.getRfGain()));
        ui->lineEdit_if->setText(QString::number(hackRf_.getIfGain()));
        if (hackRf_.isAgcEnabled())
            ui->checkBox_agc->setCheckState(Qt::Checked);
        else
            ui->checkBox_agc->setCheckState(Qt::Unchecked);
        ui->statusbar->showMessage("Hackrf part reading completed",2000);
    }
    else {
        hackRf_.setSamplingFrequency(ui->lineEdit->text().toInt());
        hackRf_.setGain(ui->lineEdit_gain->text().toInt());
        hackRf_.setIfGain(ui->lineEdit_if->text().toInt());
        hackRf_.setRfGain(ui->lineEdit_rf->text().toInt());
        if (ui->checkBox_agc->isChecked())
            hackRf_.setAgcEnabled(true);
        else
            hackRf_.setAgcEnabled(false);
        hackRf_.HackrfGetConfig(data_list);
        QFile writeFile(work_path_.path() + "/sdr_config.conf");
        if (!writeFile.open(QIODevice::WriteOnly | QIODevice::Text))
            ui->statusbar->showMessage("sdr_config.conf not found, already created",2000);
        else {
            for (int index = 0; index < data_list.size(); ++index) {
                writeFile.write(data_list.at(index).toStdString().c_str());
            }
            writeFile.close();
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

