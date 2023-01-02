//
// Created by tang on 22-12-24.

// You may need to build the project (run Qt uic code generator) to get "ui_sdr_windows.h" resolved
// You can try to execute "uic sdr_windows.ui -o ui_sdr_windows.h"
#include <QSettings>
#include <QMessageBox>
#include "sdr_windows.h"
#include "ui_sdr_windows.h"


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
        //read the configuration readFile
        config_filepath_=ui->lineEdit_2->text();
        QFile readFile(config_filepath_);
        if(!readFile.open(QIODevice::ReadOnly | QIODevice::ExistingOnly | QIODevice::Text)){
            QMessageBox::critical(this,"File Read Error","The readFile path is error, please retry!");
            qDebug()<<"Opening the configuration readFile failed!";
        }
        else{
            char *data=new char [100];
            qint64 readNum=readFile.readLine(data, 100);
            while ((readNum !=0) && (readNum != -1)){
                QString dataQString(data);
                dataQString=dataQString.trimmed();
                dataQString=dataQString.split(";").at(0);
                if(dataQString.contains("sampling_frequency", Qt::CaseSensitive)){
                    QStringList dataList=dataQString.split("=");
                    qDebug()<<dataList.at(0);
                    qDebug()<<dataList.at(1);
                    ui->lineEdit->setText(dataList.at(1));
                }
                if(dataQString.contains("item_type", Qt::CaseInsensitive)){
                    QStringList dataList=dataQString.split("=");
                    qDebug()<<dataList.at(0);
                    qDebug()<<dataList.at(1);
                    ui->comboBox->setCurrentText(dataList.at(1));
                }
                readNum=readFile.readLine(data, 100);
            }
            readFile.close();
        }
    });

    //set the Write button
    connect(ui->pushButton_2,&QPushButton::clicked, this,[&](){
        data_type_=ui->comboBox->currentText();
        sampling_freq_=ui->lineEdit->text().toInt();
        QFile openFile("../file.conf");
        QStringList readQStringList;
        if(!openFile.open(QIODevice::ReadOnly|QIODevice::Text|QIODevice::ExistingOnly))
            qDebug()<<"cannot find the model configuration file";
        else{
            char* readLineData=new char[100];
            qint64 readNum=openFile.readLine(readLineData,100);
            while ((readNum !=0) && (readNum != -1)){
                QString dataQString(readLineData);
                QString confKeyWord=dataQString.split("=").at(0);
                if(confKeyWord.contains("sampling_frequency", Qt::CaseInsensitive)){
                    QStringList dataList=dataQString.split("=");
                    QString str=QString("%1=%2\n").arg(confKeyWord).arg(sampling_freq_);
                    dataQString=str;
                }
                if(dataQString.contains("item_type", Qt::CaseInsensitive)){
                    QStringList dataList=dataQString.split("=");
                    QString str=QString("%1=%2\n").arg(confKeyWord).arg(data_type_);
                    dataQString=str;
                }
                readQStringList<<dataQString;
                readNum=openFile.readLine(readLineData, 100);
            }
            openFile.close();
        }
        QFile writeFile("../sdr_config.conf");
        if(!writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
            qDebug()<<"sdr_config.conf don't exist";
        else{
            for (int index = 0; index < readQStringList.size(); ++index) {
                writeFile.write(readQStringList.at(index).toStdString().c_str());
            }
            writeFile.close();
        }
        //system("gnss-sdr --config_file=../sdr_config.conf");
    });

    QButtonGroup* function_btnGroup=new QButtonGroup(this);
    function_btnGroup->addButton(ui->radioButtonFile,0);
    function_btnGroup->addButton(ui->radioButtonHackrf,1);
    function_btnGroup->addButton(ui->radioButtonUSRP,2);
    connect(function_btnGroup, SIGNAL(idToggled(int, bool)), this, SLOT(btnToggled(int,bool)));

    //set the Default button
    connect(ui->pushButton_3,&QPushButton::clicked, this,[&](){
        ui->setupUi(this);
    });
}

sdr_windows::~sdr_windows() {
    delete ui;
}

void sdr_windows::init() {
    ui->setupUi(this);
    //default select the first radioButtion
    ui->radioButtonFile->setChecked(true);
    ui->stackedWidget->setCurrentWidget(ui->page);
    //setting
    data_type_=ui->comboBox->currentText();
    config_filepath_=ui->lineEdit_2->text();
    ui->checkBox_bias->setCheckState(Qt::Checked);
}

void sdr_windows::btnToggled(int btn, bool checked) {
    if (!checked)
        return;
    switch (btn)
    {
        case 0:
            ui->stackedWidget->setCurrentWidget(ui->page);
            qDebug("This is button zero");
            break;
        case 1:
            ui->stackedWidget->setCurrentWidget(ui->page_2);
            qDebug("This is button one");
            break;
        case 2:
            qDebug("This is button two");
            break;
        default:
            break;
    }
}
