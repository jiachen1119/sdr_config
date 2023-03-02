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
    m_dock->SetXLength(40);
    m_dock->SetYrange(1,-5,5);
    //m_dock->ShowTagLabels(false);
}

Qchart_window::~Qchart_window() {
    delete qchart_ui;
}

void Qchart_window::receive_data(QMap<int,double> data_map) {
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.002) // at most add point every 2 ms
    {
        // add data to lines
        double vv1 = qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843);
        double vv2 = qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364);
        QMap<int,double> mapData;
        mapData.insert(1,vv1);
        mapData.insert(2,vv2);
        m_dock->AddData(key,mapData);
        lastPointKey = key;
    }
}
