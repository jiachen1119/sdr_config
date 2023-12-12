/********************************************************************************
** Form generated from reading UI file 'ChartWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "PlotBaseWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ChartWindow
{
public:
    QWidget *centralwidget;
    PlotBaseWidget *widget;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChartWindow)
    {
        if (ChartWindow->objectName().isEmpty())
            ChartWindow->setObjectName(QString::fromUtf8("ChartWindow"));
        ChartWindow->resize(827, 568);
        centralwidget = new QWidget(ChartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new PlotBaseWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 781, 481));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 510, 89, 25));
        ChartWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ChartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChartWindow->setStatusBar(statusbar);

        retranslateUi(ChartWindow);

        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChartWindow)
    {
        ChartWindow->setWindowTitle(QCoreApplication::translate("ChartWindow", "ChartWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("ChartWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartWindow: public Ui_ChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H
