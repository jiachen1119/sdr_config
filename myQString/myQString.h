//
// Created by tang on 23-1-4.
//

#ifndef SDR_CONFIG_MYQSTRING_H
#define SDR_CONFIG_MYQSTRING_H


#include <QString>
#include <QStringList>

class myQString: public QString{

public:
    myQString(QString qStr);


    QString readKeyWordAll();
    QString readData();
    QString readKeyWord1();
    QString readKeyWord2();
};


#endif //SDR_CONFIG_MYQSTRING_H
