//
// Created by tang on 23-3-1.
//

#ifndef SDR_CONFIG_MONITOR_QTHREAD_H
#define SDR_CONFIG_MONITOR_QTHREAD_H
#include <QThread>
#include "gnss_synchro_udp_source.h"
#include <iostream>

class monitor_Qthread :public QThread{
Q_OBJECT
public:
    ~monitor_Qthread() override;
    void run() override;
private:
    bool end_sign= false;
public slots:
    void change_endSign_status();
};


#endif //SDR_CONFIG_MONITOR_QTHREAD_H
