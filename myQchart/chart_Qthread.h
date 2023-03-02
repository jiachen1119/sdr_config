//
// Created by tang on 23-3-2.
//

#ifndef SDR_CONFIG_CHART_QTHREAD_H
#define SDR_CONFIG_CHART_QTHREAD_H
#include <QThread>

class chart_Qthread :public QThread{
Q_OBJECT
public:
    void run() override;
};


#endif //SDR_CONFIG_CHART_QTHREAD_H
