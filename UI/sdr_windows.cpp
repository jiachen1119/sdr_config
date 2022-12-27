//
// Created by tang on 22-12-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdr_windows.h" resolved
//You can try to execute "uic sdr_windows.ui -o ui_sdr_windows.h"
#include "sdr_windows.h"
#include "ui_sdr_windows.h"


sdr_windows::sdr_windows(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::sdr_windows) {
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this,[=](){
                QString dataType=ui->comboBox->currentText();
                qDebug()<<dataType;
                QString samplingRate=ui->lineEdit->text();
                qDebug()<<samplingRate;
    });

}

sdr_windows::~sdr_windows() {
    delete ui;
}
