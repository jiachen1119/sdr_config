//
// Created by tang on 23-3-1.
//

#include "monitor_Qthread.h"

void monitor_Qthread::run() {
    std::cout<<"monitor thread is running"<<std::endl;
    Gnss_Synchro_Udp_Source udpSource(4040);
    QElapsedTimer timer;
    timer.start();
    while(!end_sign){
        if(timer.hasExpired(1000)){
            timer.start();
            receive_map=udpSource.get_data();
            for (auto it =receive_map.begin();it!=receive_map.end();it++) {
                std::cout<<it.value()<<std::endl;
            }
            emit send_map(receive_map);
        }
    }
    std::cout<<"monitor end"<<std::endl;
}

void monitor_Qthread::change_endSign_status() {
    end_sign=!end_sign;
}

monitor_Qthread::~monitor_Qthread() = default;
