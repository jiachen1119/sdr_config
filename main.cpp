#include <QApplication>
#include <QPushButton>
#include "UI/sdr_windows.h"

int main(int argc, char *argv[]) {
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication a(argc, argv);
    QWidget *b=new QWidget;
    sdr_windows uiw(b);
    uiw.show();
    return QApplication::exec();
}
