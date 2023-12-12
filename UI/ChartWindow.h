//
// Created by tang on 23-3-2.
//

#ifndef SDR_CONFIG_CHARTWINDOW_H
#define SDR_CONFIG_CHARTWINDOW_H

#include <QMainWindow>
#include <map>

#include "PlotBaseWidget.h"
#include "ui_ChartWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChartWindow; }
QT_END_NAMESPACE

class ChartWindow : public QMainWindow {
Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr);

    ~ChartWindow() override;

private:
    Ui::ChartWindow *chart_window_;

public slots:
    void receive_data(QMap<int,double> data_map);
};


#endif //SDR_CONFIG_CHARTWINDOW_H
