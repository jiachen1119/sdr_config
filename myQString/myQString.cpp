//
// Created by tang on 23-1-4.
//

#include "myQString.h"

myQString::myQString(QString qStr):QString(qStr) {
}

QString myQString::readKeyWordAll() {
    QString str = this->trimmed().split(";").at(0);
    str=str.split("=").at(0);
    return str;
}

QString myQString::readData() {
    QString str = this->trimmed().split(";").at(0);
    str=str.split("=").at(1);
    return str;
}

QString myQString::readKeyWord1() {
    QString str=this->readKeyWordAll();
    str=str.split(".").at(0);
    return str;
}

QString myQString::readKeyWord2() {
    QString str=this->readKeyWordAll();
    str=str.split(".").at(1);
    return str;
}

