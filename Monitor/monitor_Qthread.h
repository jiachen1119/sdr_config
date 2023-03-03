//
// Created by tang on 23-3-1.
//

#ifndef SDR_CONFIG_MONITOR_QTHREAD_H
#define SDR_CONFIG_MONITOR_QTHREAD_H
#include <QThread>
#include "gnss_synchro_udp_source.h"
#include <iostream>
#include <qmap.h>
#include <QElapsedTimer>

class monitor_Qthread :public QThread{
Q_OBJECT
public:
    ~monitor_Qthread() override;
    void run() override;
private:
    bool end_sign= false;
    QMap<int,double> receive_map;
public slots:
    void change_endSign_status();
signals:
    void send_map(QMap<int,double> sendMap);
};


#endif //SDR_CONFIG_MONITOR_QTHREAD_H
