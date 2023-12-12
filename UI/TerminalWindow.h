//
// Created by tang on 23-2-27.
//

#ifndef SDR_CONFIG_TERMINALWINDOW_H
#define SDR_CONFIG_TERMINALWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QString>

#include "ui_TerminalWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class TerminalWindow; }
QT_END_NAMESPACE

class TerminalWindow : public QMainWindow {
Q_OBJECT

public:
    explicit TerminalWindow(QWidget *parent = nullptr);
    void cmd_start(QString workPlace_path);

    ~TerminalWindow() override;

private:
    Ui::TerminalWindow *terminal_ui;
    QProcess *cmd;
public slots:
    void on_readoutput();
signals:
    void end_monitor();
};


#endif //SDR_CONFIG_TERMINALWINDOW_H
