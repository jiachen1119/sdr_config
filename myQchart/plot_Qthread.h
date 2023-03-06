//
// Created by tang on 23-3-6.
//

#ifndef SDR_CONFIG_PLOT_QTHREAD_H
#define SDR_CONFIG_PLOT_QTHREAD_H
#include <QThread>


class plot_Qthread :public QThread{
Q_OBJECT
public:
    void run() override;
private:
};


#endif //SDR_CONFIG_PLOT_QTHREAD_H
