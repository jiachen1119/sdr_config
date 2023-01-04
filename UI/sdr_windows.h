//
// Created by tang on 22-12-24.
//

#ifndef SDR_CONFIG_SDR_WINDOWS_H
#define SDR_CONFIG_SDR_WINDOWS_H

#include <QMainWindow>
#include <qdebug.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qbuttongroup.h>
#include "../HackRF/HackRF.h"

QT_BEGIN_NAMESPACE
namespace Ui { class sdr_windows; }
QT_END_NAMESPACE

#define combobox_true QVariant(-1)
#define combobox_false QVariant(0)

class sdr_windows : public QMainWindow {
Q_OBJECT

public:
    explicit sdr_windows(QWidget *parent = nullptr);
    void init();
    QStringList readConfigInLine(const QString& file_path);
    void fileConfig(QStringList data_list,bool read_or_write);
    void hackrfConfig(QStringList data_list,bool read_or_write);
    ~sdr_windows() override;

public slots:
    void btnToggled(int btn, bool checked);

private:
    Ui::sdr_windows *ui;

    QString config_filepath_;
    QString config_file_lastpath_;
    QString data_type_;
    QString sampling_freq_;
    QButtonGroup* function_btnGroup_{};
    int btnGroup_flag_=0;
    QString model_config_file_="../file.conf";
    HackRF hackRf_;

};


#endif //SDR_CONFIG_SDR_WINDOWS_H
