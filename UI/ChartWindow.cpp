//
// Created by tang on 23-3-2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Qchart_window.h" resolved

#include "ChartWindow.h"
#include <QTime>
#include <utility>
#include <iostream>


ChartWindow::ChartWindow(QWidget *parent) :
        QMainWindow(parent), chart_window_(new Ui::ChartWindow) {
    chart_window_->setupUi(this);

//    chart_window_->widget = new PlotBaseWidget(this,screenWidth/3,screenHeight/3);
    chart_window_->widget->move(0, 10);

    std::vector<StLineInfo> LineInfo;
    StLineInfo st1,st2,st3,st4;
    st1.lineName = "CNo of channel 1";
    st2.lineName = "CNo of channel 2";
    LineInfo.push_back(st1);
    LineInfo.push_back(st2);
    LineInfo.push_back(st3);
    LineInfo.push_back(st4);

    chart_window_->widget->CreateGraph(LineInfo);
}

ChartWindow::~ChartWindow() {
    delete chart_window_;
}

void ChartWindow::receive_data(QMap<int,double> data_map) {
        // add data to lines
     static int key =0;
     key++;
     chart_window_->widget->AddData(key, data_map);
}
