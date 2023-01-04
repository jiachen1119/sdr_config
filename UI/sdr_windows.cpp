//
// Created by Kepeng Luan on 22-12-24.

// You may need to build the project (run Qt uic code generator) to get "ui_sdr_windows.h" resolved
// You can try to execute "uic sdr_windows.ui -o ui_sdr_windows.h"
#include <QSettings>
#include <QMessageBox>
#include "sdr_windows.h"
#include "ui_sdr_windows.h"
#include "../myQString/myQString.h"


sdr_windows::sdr_windows(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::sdr_windows) {
    init();
    // to remember the path
    QSettings setting("./Setting.ini", QSettings::IniFormat);
    config_file_lastpath_= setting.value("LastFilePath").toString();

    //...tool button connect
    connect(ui->toolButton_conf,&QToolButton::clicked, this,[=]() mutable {
        config_filepath_=QFileDialog::getOpenFileName(this, "Open configuration file",
                                                      config_file_lastpath_, "configuration(*.conf)");
        ui->lineEdit_2->setText(config_filepath_);
    });

    //set the Read button
    connect(ui->pushButton,&QPushButton::clicked, this,[&](){
        config_filepath_=ui->lineEdit_2->text();
        QStringList readBtn_list= readConfigInLine(config_filepath_);
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

    //set the Write button
    connect(ui->pushButton_2,&QPushButton::clicked, this,[&](){
        data_type_=ui->comboBox->currentText();
        sampling_freq_=ui->lineEdit->text();
        //todo: model config file need to be debug
        QStringList writeBtn_list=readConfigInLine(model_config_file_);
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

    connect(function_btnGroup_, SIGNAL(idToggled(int, bool)),
            this, SLOT(btnToggled(int,bool)));

    //set the Default button
    connect(ui->pushButton_3,&QPushButton::clicked, this,[&](){
            ui->setupUi(this);
    });
}

sdr_windows::~sdr_windows() {
    delete ui;
}

void sdr_windows::init() {
    //todo: make the special edit line only written numbers
    ui->setupUi(this);
    //default select the first radioButton
    ui->radioButtonFile->setChecked(true);
    ui->stackedWidget->setCurrentWidget(ui->page);
    //button group setting
    function_btnGroup_=new QButtonGroup(this);
    function_btnGroup_->addButton(ui->radioButtonFile,0);
    function_btnGroup_->addButton(ui->radioButtonHackrf,1);
    function_btnGroup_->addButton(ui->radioButtonUSRP,2);
    //basic widget setting
    data_type_=ui->comboBox->currentText();
    config_filepath_=ui->lineEdit_2->text();
    ui->checkBox_bias->setCheckState(Qt::Checked);
}

void sdr_windows::btnToggled(int btn, bool checked) {
    if (!checked)
        return;
    btnGroup_flag_=btn;
    switch (btn)
    {
        case 0:
            //todo: need to remember the choice of combobox in the different stackedWidget
            ui->stackedWidget->setCurrentWidget(ui->page);
            model_config_file_="../file.conf";
            ui->lineEdit_2->setText(model_config_file_);
            ui->comboBox->setItemData(0,combobox_true,Qt::UserRole-1);
            ui->comboBox->setItemData(1,combobox_true,Qt::UserRole-1);
            ui->comboBox->setItemData(2,combobox_true,Qt::UserRole-1);
            ui->comboBox->setItemData(3,combobox_true,Qt::UserRole-1);
            ui->comboBox->setItemData(4,combobox_true,Qt::UserRole-1);
            ui->comboBox->setItemData(5,combobox_true,Qt::UserRole-1);
            ui->comboBox->setItemData(6,combobox_true,Qt::UserRole-1);
            break;
        case 1:
            ui->stackedWidget->setCurrentWidget(ui->page_2);
            model_config_file_="../hackrf_GPS_L1.conf";
            ui->lineEdit_2->setText(model_config_file_);
            ui->comboBox->setCurrentIndex(7);
            ui->comboBox->setItemData(0,combobox_false,Qt::UserRole-1);
            ui->comboBox->setItemData(1,combobox_false,Qt::UserRole-1);
            ui->comboBox->setItemData(2,combobox_false,Qt::UserRole-1);
            ui->comboBox->setItemData(3,combobox_false,Qt::UserRole-1);
            ui->comboBox->setItemData(4,combobox_false,Qt::UserRole-1);
            ui->comboBox->setItemData(5,combobox_false,Qt::UserRole-1);
            ui->comboBox->setItemData(6,combobox_false,Qt::UserRole-1);
            break;
        case 2:
            qDebug("This is button two");
            break;
        default:
            break;
    }
}

QStringList sdr_windows::readConfigInLine(const QString& file_path) {
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

void sdr_windows::fileConfig(QStringList data_list, bool read_or_write) {
    //true is reading function, and false is writing function
    if(read_or_write){
        for (int i = 0; i < data_list.size(); ++i) {
            myQString myStr(data_list.at(i));
            QString keyWord=myStr.readKeyWordAll();
            if(keyWord.contains("SignalSource.sampling_frequency", Qt::CaseSensitive)){
                sampling_freq_=myStr.readData();
                ui->lineEdit->setText(sampling_freq_);
            }
            if(keyWord.contains("SignalSource.item_type", Qt::CaseSensitive)){
                data_type_=myStr.readData();
                ui->comboBox->setCurrentText(data_type_);
            }
        }
    }
    else{
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
        }
        QFile writeFile("../sdr_config.conf");
        if(!writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
            qDebug()<<"sdr_config.conf don't exist";
        else{
            for (int index = 0; index < data_list.size(); ++index) {
                writeFile.write(data_list.at(index).toStdString().c_str());
            }
            writeFile.close();
        }
        //system("gnss-sdr --config_file=../sdr_config.conf");
    }
}

void sdr_windows::hackrfConfig(QStringList data_list, bool read_or_write) {
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
    }
    else {
        hackRf_.setSamplingFrequency(ui->lineEdit_2->text().toInt());
        hackRf_.setGain(ui->lineEdit_gain->text().toInt());
        hackRf_.setIfGain(ui->lineEdit_if->text().toInt());
        hackRf_.setRfGain(ui->lineEdit_rf->text().toInt());
        if (ui->checkBox_agc->isChecked())
            hackRf_.setAgcEnabled(true);
        else
            hackRf_.setAgcEnabled(false);
        hackRf_.HackrfGetConfig(data_list);
        QFile writeFile("../sdr_config.conf");
        if (!writeFile.open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "sdr_config.conf don't exist";
        else {
            for (int index = 0; index < data_list.size(); ++index) {
                writeFile.write(data_list.at(index).toStdString().c_str());
            }
            writeFile.close();
        }
    }
}

