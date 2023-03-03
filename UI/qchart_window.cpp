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
    QScreen *screen = qApp->primaryScreen();
    int screenWidth = screen->size().width();            //屏幕宽
    int screenHeight = screen->size().height();
    m_dock = new PlotBaseWidget(this,screenWidth/2,screenHeight/2);
    m_dock->move(0,10);

    QMap<int,StLineInfo> LineInfo;
    StLineInfo st1;
    st1.name = "test"+QString::number(1);
    LineInfo.insert(1,st1);
    st1.name = "test"+QString::number(2);
    LineInfo.insert(2,st1);

    m_dock->CreateGraph(LineInfo);
    m_dock->SetXrange(0,0,1000);
    m_dock->SetXLength(1000);
    m_dock->SetYrange(1,40,50);
    m_dock->ShowTagLabels(true);
}

Qchart_window::~Qchart_window() {
    delete qchart_ui;
}

void Qchart_window::receive_data(QMap<int,double> data_map) {
        // add data to lines
        static int key =0;
        key++;
        std::cout<<"draw once"<<std::endl;
        QMap<int,double> mapData;
        mapData.insert(1,data_map.begin().value());
        mapData.insert(2,42.8387);
        m_dock->AddData(key,mapData);
}
