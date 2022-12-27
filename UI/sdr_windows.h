//
// Created by tang on 22-12-24.
//

#ifndef SDR_CONFIG_SDR_WINDOWS_H
#define SDR_CONFIG_SDR_WINDOWS_H

#include <QMainWindow>
#include <qdebug.h>
#include <qfile.h>
#include <qfiledialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class sdr_windows; }
QT_END_NAMESPACE

class sdr_windows : public QMainWindow {
Q_OBJECT

public:
    explicit sdr_windows(QWidget *parent = nullptr);

    ~sdr_windows() override;

private:
    Ui::sdr_windows *ui;
};


#endif //SDR_CONFIG_SDR_WINDOWS_H
