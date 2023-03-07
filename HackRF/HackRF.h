//
// Created by tang on 23-1-4.
//

#ifndef SDR_CONFIG_HACKRF_H
#define SDR_CONFIG_HACKRF_H

#include <QString>
#include <QStringList>
#include <iostream>

class HackRF {
public:
    HackRF();
    HackRF(int sampling_frequency_, int centerFrequency, int gain, int rfGain, int ifGain,
           bool agcEnabled, QString &osmosdrArg);
    void ConfigGetHackrf(QStringList datalist);
    void HackrfGetConfig(QStringList &datalist);

    void setSamplingFrequency(int samplingFrequency);
    void setGain(int gain);
    void setRfGain(int rfGain);
    void setIfGain(int ifGain);
    void setAgcEnabled(bool agcEnabled);

    int getSamplingFrequency() const;
    int getGain() const;
    int getRfGain() const;
    int getIfGain() const;
    bool isAgcEnabled() const;

private:
    int sampling_frequency_=4e6;
    int center_frequency_=1575420000;
    int gain_=0;
    int rf_gain_=0;
    int if_gain_=0;
    bool AGC_enabled_= false;
    QString osmosdr_arg="hackrf,bias=1";

};


#endif //SDR_CONFIG_HACKRF_H
