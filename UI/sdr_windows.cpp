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
    ui->setupUi(this);

    //1. lineEdit file path init
    QString filePath=ui->lineEdit_2->text();
    //2. file read setting
    QSettings setting("./Setting.ini", QSettings::IniFormat); // to remember the path
    QString lastPath = setting.value("LastFilePath").toString();

    ui->lineEdit->textEdited();
    //...tool button connect
    connect(ui->toolButton_2,&QToolButton::clicked, this,[=]() mutable {
        filePath=QFileDialog::getOpenFileName(this,"Open configuration file",
                                                  lastPath,"configuration(*.conf)");
        ui->lineEdit_2->setText(filePath);
    });

    //set the Read button
    connect(ui->pushButton,&QPushButton::clicked, this,[&](){
        //read the configuration file
        filePath=ui->lineEdit_2->text();
        QFile file(filePath);
        if(!file.open(QIODevice::ReadOnly|QIODevice::ExistingOnly|QIODevice::Text)){
            QMessageBox::critical(this,"File Read Error","The file path is error, please retry!");
            qDebug()<<"Opening the configuration file failed!";
        }
        else{
            char *data=new char [100];
            qint64 readNum=file.readLine(data,100);
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
                readNum=file.readLine(data,100);
            }
            file.close();
        }
    });

    //set the Write button
    connect(ui->pushButton_2,&QPushButton::clicked, this,[&](){
        QString dataType=ui->comboBox->currentText();
        QString samplingFreq=ui->lineEdit->text();
    });

    //set the Default button
    connect(ui->pushButton_3,&QPushButton::clicked, this,[&](){
        ui->setupUi(this);
    });
}

sdr_windows::~sdr_windows() {
    delete ui;
}
