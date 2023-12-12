//
// Created by tang on 22-12-24.
//

#ifndef SDR_CONFIG_SDRWINDOWS_H
#define SDR_CONFIG_SDRWINDOWS_H

#include <memory>

#include <QMainWindow>
#include <QSettings>
#include <QMessageBox>
#include <qdebug.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qbuttongroup.h>
#include <qprocess.h>
#include <QDir>

#include "../HackRF/HackRF.h"
#include "TerminalWindow.h"
#include "monitor_Qthread.h"
#include "ChartWindow.h"
#include "ui_SdrWindows.h"
#include "../myQString/myQString.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SdrWindows; }
QT_END_NAMESPACE

#define combobox_true QVariant(-1)
#define combobox_false QVariant(0)

class SdrWindows : public QMainWindow {
Q_OBJECT

public:
    explicit SdrWindows(QWidget *parent = nullptr);
    void init();

    QStringList readConfigInLine(const QString& file_path);
    void fileConfig(QStringList data_list);
    void hackrfConfig(QStringList data_list);
    ~SdrWindows() override;
    enum class frontEnd{
        file=0,
        hackrf=1,
        usrp=2
    };


public slots:
    void buttonToggled(int button, bool checked);

private:
    Ui::SdrWindows *ui;
    QDir work_path_;

    // "Setting"
    std::unique_ptr<QSettings> setting_;
    QDir config_path_;
    QDir rawData_path_;

    QString data_type_;
    QString sampling_freq_;
    std::unique_ptr<QButtonGroup> button_group_;
    int buttonGroup_id_=0;
    HackRF hackRf_;
    monitor_Qthread monitor_Qthread_;

    // window widget
    std::unique_ptr<TerminalWindow> term_window_;
    std::unique_ptr<ChartWindow> chart_window_;

    //status label
    std::unique_ptr<QLabel> status_label_;

    void settingInit();
    void toolButtonConnect();

};


#endif //SDR_CONFIG_SDRWINDOWS_H
