/********************************************************************************
** Form generated from reading UI file 'TerminalWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINALWINDOW_H
#define UI_TERMINALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TerminalWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TerminalWindow)
    {
        if (TerminalWindow->objectName().isEmpty())
            TerminalWindow->setObjectName(QString::fromUtf8("TerminalWindow"));
        TerminalWindow->resize(568, 393);
        centralwidget = new QWidget(TerminalWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 511, 351));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(23, 9, 481, 271));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 300, 89, 25));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 300, 89, 25));
        TerminalWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TerminalWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TerminalWindow->setStatusBar(statusbar);

        retranslateUi(TerminalWindow);

        QMetaObject::connectSlotsByName(TerminalWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TerminalWindow)
    {
        TerminalWindow->setWindowTitle(QCoreApplication::translate("TerminalWindow", "TerminalWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("TerminalWindow", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TerminalWindow", "Monitor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TerminalWindow: public Ui_TerminalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINALWINDOW_H
