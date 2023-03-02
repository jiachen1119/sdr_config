//
// Created by tang on 23-3-2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Qchart_window.h" resolved

#include "qchart_window.h"
#include "ui_Qchart_window.h"


Qchart_window::Qchart_window(QWidget *parent) :
        QMainWindow(parent), qchart_ui(new Ui::Qchart_window) {
    qchart_ui->setupUi(this);
}

Qchart_window::~Qchart_window() {
    delete qchart_ui;
}
