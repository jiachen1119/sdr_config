//
// Created by tang on 23-2-27.
//

#ifndef SDR_CONFIG_TERMINAL_WINDOW_H
#define SDR_CONFIG_TERMINAL_WINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class terminal_window; }
QT_END_NAMESPACE

class terminal_window : public QMainWindow {
Q_OBJECT

public:
    explicit terminal_window(QWidget *parent = nullptr);
    void cmd_start(QString workPlace_path);

    ~terminal_window() override;

public slots:
    void on_readoutput();
private:
    Ui::terminal_window *terminal_ui;
    QProcess *cmd;
};


#endif //SDR_CONFIG_TERMINAL_WINDOW_H
