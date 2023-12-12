#include <QApplication>
#include <QPushButton>
#include "UI/SdrWindows.h"
#include <QFile>
#include <iostream>
#include "monitor_Qthread.h"

int main(int argc, char *argv[]) {
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QFile file("../index.css");

    QApplication a(argc, argv);
    auto *b=new QWidget;
    SdrWindows uiw(b);
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
        std::cout<<"qss reading success!"<<std::endl;
    } else
    {std::cerr<<"qss reading failed, use the default style sheet"<<std::endl;}
    uiw.show();
    return QApplication::exec();
}
