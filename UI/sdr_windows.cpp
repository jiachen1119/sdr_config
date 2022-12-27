//
// Created by tang on 22-12-24.

// You may need to build the project (run Qt uic code generator) to get "ui_sdr_windows.h" resolved
// You can try to execute "uic sdr_windows.ui -o ui_sdr_windows.h"
#include <QSettings>
#include "sdr_windows.h"
#include "ui_sdr_windows.h"


sdr_windows::sdr_windows(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::sdr_windows) {
    ui->setupUi(this);
    QString filePath=ui->lineEdit_2->text();

    //file read setting
    QSettings setting("./Setting.ini", QSettings::IniFormat); // to remember the path
    QString lastPath = setting.value("LastFilePath").toString();
    //...tool button connect
    connect(ui->toolButton_2,&QToolButton::clicked, this,[=]() mutable {
        filePath=QFileDialog::getOpenFileName(this,"Open configuration file",
                                                  lastPath,"configuration(*.conf)");
        ui->lineEdit_2->setText(filePath);
    });

    connect(ui->pushButton,&QPushButton::clicked, this,[=](){
        QString dataType=ui->comboBox->currentText();
        qDebug()<<dataType;
        QString samplingRate=ui->lineEdit->text();
        qDebug()<<samplingRate;
        //read the configuration file
        QFile file(filePath);
        if(!file.open(QIODevice::ReadOnly|QIODevice::ExistingOnly|QIODevice::Text)){
            qDebug()<<"Opening the configuration file failed!";
        }
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
            }
            readNum=file.readLine(data,100);
        }
    });

}

sdr_windows::~sdr_windows() {
    delete ui;
}
