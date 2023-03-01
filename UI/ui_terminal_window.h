/********************************************************************************
** Form generated from reading UI file 'terminal_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINAL_WINDOW_H
#define UI_TERMINAL_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_terminal_window
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *terminal_window)
    {
        if (terminal_window->objectName().isEmpty())
            terminal_window->setObjectName(QString::fromUtf8("terminal_window"));
        terminal_window->resize(568, 393);
        centralwidget = new QWidget(terminal_window);
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
        terminal_window->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(terminal_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        terminal_window->setStatusBar(statusbar);

        retranslateUi(terminal_window);

        QMetaObject::connectSlotsByName(terminal_window);
    } // setupUi

    void retranslateUi(QMainWindow *terminal_window)
    {
        terminal_window->setWindowTitle(QCoreApplication::translate("terminal_window", "terminal_window", nullptr));
        pushButton->setText(QCoreApplication::translate("terminal_window", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("terminal_window", "Monitor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class terminal_window: public Ui_terminal_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINAL_WINDOW_H
