//
// Created by tang on 23-3-1.
//

#include "monitor_Qthread.h"

void monitor_Qthread::run() {
    std::cout<<"monitor thread is running"<<std::endl;
    Gnss_Synchro_Udp_Source udpSource(1234);
    while(!end_sign)
        udpSource.get_data();
    std::cout<<"monitor pause"<<std::endl;
    exec();
}

void monitor_Qthread::change_endSign_status() {
    end_sign=!end_sign;
}

monitor_Qthread::~monitor_Qthread() = default;
