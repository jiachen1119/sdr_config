/********************************************************************************
** Form generated from reading UI file 'Qchart_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCHART_WINDOW_H
#define UI_QCHART_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "PlotBaseWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Qchart_window
{
public:
    QWidget *centralwidget;
    PlotBaseWidget *widget;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qchart_window)
    {
        if (Qchart_window->objectName().isEmpty())
            Qchart_window->setObjectName(QString::fromUtf8("Qchart_window"));
        Qchart_window->resize(827, 568);
        centralwidget = new QWidget(Qchart_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new PlotBaseWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 781, 481));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 510, 89, 25));
        Qchart_window->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Qchart_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Qchart_window->setStatusBar(statusbar);

        retranslateUi(Qchart_window);

        QMetaObject::connectSlotsByName(Qchart_window);
    } // setupUi

    void retranslateUi(QMainWindow *Qchart_window)
    {
        Qchart_window->setWindowTitle(QCoreApplication::translate("Qchart_window", "Qchart_window", nullptr));
        pushButton->setText(QCoreApplication::translate("Qchart_window", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qchart_window: public Ui_Qchart_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCHART_WINDOW_H
