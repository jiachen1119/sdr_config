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

QT_BEGIN_NAMESPACE
namespace Ui { class sdr_windows; }
QT_END_NAMESPACE

class sdr_windows : public QMainWindow {
Q_OBJECT

public:
    explicit sdr_windows(QWidget *parent = nullptr);
    void init();
    QStringList readConfigInLine(QString file_path);
    ~sdr_windows() override;

public slots:
    void btnToggled(int btn, bool checked);

private:
    Ui::sdr_windows *ui;
    QString config_filepath_;
    QString config_file_lastpath_;
    QString data_type_;
    QString sampling_freq_;

};


#endif //SDR_CONFIG_SDR_WINDOWS_H
