//
// Created by tang on 23-1-4.
//


#include "HackRF.h"
#include "../myQString/myQString.h"

HackRF::HackRF(int sampling_frequency_, int centerFrequency, int gain, int rfGain, int ifGain, bool agcEnabled,
               QString &osmosdrArg) {
}

void HackRF::ConfigGetHackrf(QStringList datalist) {
    for (int i = 0; i < datalist.size(); ++i) {
        myQString myStr(datalist.at(i));
        QString keyWord=myStr.readKeyWordAll();
        if(keyWord.contains("SignalSource.sampling_frequency", Qt::CaseSensitive)){
            sampling_frequency_=myStr.readData().toInt();
        }
        if(keyWord.contains("SignalSource.gain", Qt::CaseSensitive)){
            gain_=myStr.readData().toInt();
        }
        if(keyWord.contains("SignalSource.rf_gain", Qt::CaseSensitive)){
            rf_gain_=myStr.readData().toInt();
        }
        if(keyWord.contains("SignalSource.if_gain", Qt::CaseSensitive)){
            if_gain_=myStr.readData().toInt();
        }
        if(keyWord.contains("SignalSource.AGC_enabled", Qt::CaseSensitive)){
            if (myStr.readData()=="true")
                AGC_enabled_= true;
            else
                AGC_enabled_= false;
        }
    }
}

void HackRF::HackrfGetConfig(QStringList &datalist) {
    for (int i = 0; i < datalist.size(); ++i) {
        myQString myStr(datalist.at(i));
        QString keyWord=myStr.readKeyWordAll();
        if(keyWord.contains("SignalSource.sampling_frequency", Qt::CaseSensitive)){
            QString str = QString("%1=%2\n").arg(keyWord).arg(sampling_frequency_);
            datalist.replace(i, str);
        }
        if(keyWord.contains("SignalSource.gain", Qt::CaseSensitive)){
            QString str = QString("%1=%2\n").arg(keyWord).arg(gain_);
            datalist.replace(i, str);
        }
        if(keyWord.contains("SignalSource.rf_gain", Qt::CaseSensitive)){
            QString str = QString("%1=%2\n").arg(keyWord).arg(rf_gain_);
            datalist.replace(i, str);
        }
        if(keyWord.contains("SignalSource.if_gain", Qt::CaseSensitive)){
            QString str = QString("%1=%2\n").arg(keyWord).arg(if_gain_);
            datalist.replace(i, str);
        }
        if(keyWord.contains("SignalSource.AGC_enabled", Qt::CaseSensitive)){
            QString str;
            if (AGC_enabled_)
                str = QString("%1=%2\n").arg(keyWord).arg("true");
            else
                str = QString("%1=%2\n").arg(keyWord).arg("false");
            datalist.replace(i,str);
        }
    }
}

int HackRF::getSamplingFrequency() const {
    return sampling_frequency_;
}

int HackRF::getGain() const {
    return gain_;
}

int HackRF::getRfGain() const {
    return rf_gain_;
}

int HackRF::getIfGain() const {
    return if_gain_;
}

bool HackRF::isAgcEnabled() const {
    return AGC_enabled_;
}


void HackRF::setGain(int gain) {
    gain_ = gain;
}

void HackRF::setRfGain(int rfGain) {
    rf_gain_ = rfGain;
}

void HackRF::setIfGain(int ifGain) {
    if_gain_ = ifGain;
}

void HackRF::setAgcEnabled(bool agcEnabled) {
    AGC_enabled_ = agcEnabled;
}

void HackRF::setSamplingFrequency(int samplingFrequency) {
    sampling_frequency_ = samplingFrequency;
}

HackRF::HackRF() = default;
