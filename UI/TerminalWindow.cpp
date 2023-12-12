
// Created by tang on 23-2-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_terminal_window.h" resolved

#include "TerminalWindow.h"

#include <QDebug>
#include <iostream>
#include "gnss_synchro_udp_source.h"
#include <thread>


TerminalWindow::TerminalWindow(QWidget *parent) :
        QMainWindow(parent), terminal_ui(new Ui::TerminalWindow) {
    terminal_ui->setupUi(this);
}

TerminalWindow::~TerminalWindow() {
    delete terminal_ui;
}

void TerminalWindow::cmd_start(QString workPlace_path) {
    cmd=new QProcess(this);
    cmd->setWorkingDirectory(workPlace_path);
    connect(cmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(on_readoutput()));
    connect(terminal_ui->pushButton,&QPushButton::clicked, this, [&](){
        cmd->write("q");
        cmd->close();
        cmd->waitForFinished();
    });
    connect(terminal_ui->pushButton_2,&QPushButton::clicked, this, [&](){
        emit end_monitor();
        std::cout<<"clicked monitor button"<<std::endl;
    });
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
    if (cmd->waitForFinished(10))
        cmd->close();
}

void TerminalWindow::on_readoutput() {
    QString temp_output=cmd->readAllStandardOutput().data();
    terminal_ui->textEdit->append(temp_output);
}


