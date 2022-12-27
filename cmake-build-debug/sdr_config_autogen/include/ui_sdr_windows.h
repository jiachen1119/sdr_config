/********************************************************************************
** Form generated from reading UI file 'sdr_windows.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDR_WINDOWS_H
#define UI_SDR_WINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sdr_windows
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sdr_windows)
    {
        if (sdr_windows->objectName().isEmpty())
            sdr_windows->setObjectName(QString::fromUtf8("sdr_windows"));
        sdr_windows->resize(563, 416);
        actionOpen = new QAction(sdr_windows);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(sdr_windows);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionExit = new QAction(sdr_windows);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(sdr_windows);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(sdr_windows);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 306, 136));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addWidget(widget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 290, 89, 25));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sdr_windows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sdr_windows);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 563, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        sdr_windows->setMenuBar(menubar);
        statusbar = new QStatusBar(sdr_windows);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sdr_windows->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionNew);
        menu->addAction(actionExit);
        menu_2->addAction(actionAbout);

        retranslateUi(sdr_windows);

        comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(sdr_windows);
    } // setupUi

    void retranslateUi(QMainWindow *sdr_windows)
    {
        sdr_windows->setWindowTitle(QCoreApplication::translate("sdr_windows", "sdr_windows", nullptr));
        actionOpen->setText(QCoreApplication::translate("sdr_windows", "Open", nullptr));
        actionNew->setText(QCoreApplication::translate("sdr_windows", "New", nullptr));
        actionExit->setText(QCoreApplication::translate("sdr_windows", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("sdr_windows", "About", nullptr));
        groupBox->setTitle(QCoreApplication::translate("sdr_windows", "Basic Settings", nullptr));
        label->setText(QCoreApplication::translate("sdr_windows", "Data Type", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("sdr_windows", "byte", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("sdr_windows", "short", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("sdr_windows", "float", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("sdr_windows", "ibyte", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("sdr_windows", "ishort", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("sdr_windows", "cbyte", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("sdr_windows", "cshort", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("sdr_windows", "gr_complex", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("sdr_windows", "ibyte", nullptr));
        label_2->setText(QCoreApplication::translate("sdr_windows", "Sample Rate (Hz)", nullptr));
        pushButton->setText(QCoreApplication::translate("sdr_windows", "OK", nullptr));
        menu->setTitle(QCoreApplication::translate("sdr_windows", "File", nullptr));
        menu_2->setTitle(QCoreApplication::translate("sdr_windows", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sdr_windows: public Ui_sdr_windows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDR_WINDOWS_H
