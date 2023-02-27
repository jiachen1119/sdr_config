
// Created by tang on 23-2-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_terminal_window.h" resolved

#include "terminal_window.h"
#include "ui_terminal_window.h"
#include <QDebug>
#include <iostream>


terminal_window::terminal_window(QWidget *parent) :
        QMainWindow(parent), terminal_ui(new Ui::terminal_window) {
    terminal_ui->setupUi(this);
}

terminal_window::~terminal_window() {
    delete terminal_ui;
}

void terminal_window::cmd_start(QString workPlace_path) {
    cmd=new QProcess(this);
    cmd->setWorkingDirectory(workPlace_path);
    connect(cmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(on_readoutput()));

    QString program=QString("gnss-sdr");
    QStringList arguments=QStringList(" --config_file=sdr_config.conf");
    cmd->start("bash");
    cmd->write("gnss-sdr --config_file=sdr_config.conf\n");
    if(cmd->waitForReadyRead()) qDebug()<<"cmd success";
    else
    {
        qDebug()<<"cmd failed";
        cmd->close();
        return;
    }
//    QString strTemp =cmd->readAllStandardOutput();
//    terminal_ui->textEdit->setText(strTemp);
//    std::cout<<strTemp.toStdString();
    //cmd->waitForFinished();
    cmd->close();
}

void terminal_window::on_readoutput() {
    terminal_ui->textEdit->append(cmd->readAllStandardOutput().data());
}

