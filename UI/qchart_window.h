//
// Created by tang on 23-3-2.
//

#ifndef SDR_CONFIG_QCHART_WINDOW_H
#define SDR_CONFIG_QCHART_WINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Qchart_window; }
QT_END_NAMESPACE

class Qchart_window : public QMainWindow {
Q_OBJECT

public:
    explicit Qchart_window(QWidget *parent = nullptr);

    ~Qchart_window() override;

private:
    Ui::Qchart_window *qchart_ui;
};


#endif //SDR_CONFIG_QCHART_WINDOW_H
