//
// Created by tang on 23-2-28.
//

#ifndef SDR_CONFIG_GNSS_SYNCHRO_UDP_SOURCE_H
#define SDR_CONFIG_GNSS_SYNCHRO_UDP_SOURCE_H


#include <boost/asio.hpp>
#include "gnss_synchro.pb.h"  // This file is created automatically
// by the Protocol Buffers compiler
#include <qstring.h>

class Gnss_Synchro_Udp_Source
{
public:
    Gnss_Synchro_Udp_Source(const unsigned short port);
    bool read_gnss_synchro(gnss_sdr::Observables& stocks);
    void populate_channels(gnss_sdr::Observables& stocks);
    bool print_table();
    QMap<int,double> get_data();

private:
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket socket;
    boost::system::error_code error;
    boost::asio::ip::udp::endpoint endpoint;
    gnss_sdr::Observables stocks;
    std::map<int, gnss_sdr::GnssSynchro> channels;
};

#endif  // GNSS_SYNCHRO_UDP_SOURCE_H
