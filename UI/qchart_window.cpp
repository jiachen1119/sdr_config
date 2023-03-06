//
// Created by tang on 23-3-2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Qchart_window.h" resolved

#include "qchart_window.h"
#include "ui_Qchart_window.h"
#include <QTime>
#include <utility>
#include <iostream>


Qchart_window::Qchart_window(QWidget *parent) :
        QMainWindow(parent), qchart_ui(new Ui::Qchart_window) {
    qchart_ui->setupUi(this);

//    qchart_ui->widget = new PlotBaseWidget(this,screenWidth/3,screenHeight/3);
    qchart_ui->widget->move(0,10);

    std::vector<StLineInfo> LineInfo;
    StLineInfo st1,st2,st3,st4;
    st1.lineName = "CNo of channel 1";
    st2.lineName = "CNo of channel 2";
    LineInfo.push_back(st1);
    LineInfo.push_back(st2);
    LineInfo.push_back(st3);
    LineInfo.push_back(st4);

    qchart_ui->widget->CreateGraph(LineInfo);
    qchart_ui->widget->SetXrange(0,0,1000);
    qchart_ui->widget->SetYrange(0,40,55);
}

Qchart_window::~Qchart_window() {
    delete qchart_ui;
}

void Qchart_window::receive_data(QMap<int,double> data_map) {
        // add data to lines
     static int key =0;
     key++;
        qchart_ui->widget->AddData(key,data_map);
}
