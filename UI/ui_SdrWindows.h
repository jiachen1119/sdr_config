/********************************************************************************
** Form generated from reading UI file 'SdrWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDRWINDOWS_H
#define UI_SDRWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SdrWindows
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
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_configPath;
    QToolButton *toolButton_conf;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLineEdit *lineEdit_workPath;
    QToolButton *toolButton_workPath;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButtonFile;
    QRadioButton *radioButtonHackrf;
    QRadioButton *radioButtonUSRP;
    QGroupBox *groupBox_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *lineEdit_rawData;
    QToolButton *toolButton_rawData;
    QWidget *page_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *lineEdit_gain;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLineEdit *lineEdit_rf;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QLineEdit *lineEdit_if;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QCheckBox *checkBox_agc;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QCheckBox *checkBox_bias;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SdrWindows)
    {
        if (SdrWindows->objectName().isEmpty())
            SdrWindows->setObjectName(QString::fromUtf8("SdrWindows"));
        SdrWindows->resize(811, 648);
        actionOpen = new QAction(SdrWindows);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(SdrWindows);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionExit = new QAction(SdrWindows);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(SdrWindows);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(SdrWindows);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 130, 311, 321));
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

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

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
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineEdit);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_configPath = new QLineEdit(widget_3);
        lineEdit_configPath->setObjectName(QString::fromUtf8("lineEdit_configPath"));

        horizontalLayout_5->addWidget(lineEdit_configPath);

        toolButton_conf = new QToolButton(widget_3);
        toolButton_conf->setObjectName(QString::fromUtf8("toolButton_conf"));

        horizontalLayout_5->addWidget(toolButton_conf);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 3);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout->addWidget(widget_3);

        widget_12 = new QWidget(groupBox);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_14 = new QHBoxLayout(widget_12);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_10 = new QLabel(widget_12);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_14->addWidget(label_10);

        lineEdit_workPath = new QLineEdit(widget_12);
        lineEdit_workPath->setObjectName(QString::fromUtf8("lineEdit_workPath"));

        horizontalLayout_14->addWidget(lineEdit_workPath);

        toolButton_workPath = new QToolButton(widget_12);
        toolButton_workPath->setObjectName(QString::fromUtf8("toolButton_workPath"));

        horizontalLayout_14->addWidget(toolButton_workPath);


        verticalLayout->addWidget(widget_12);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(400, 490, 371, 61));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 20, 311, 80));
        widget_5 = new QWidget(groupBox_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 30, 311, 41));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioButtonFile = new QRadioButton(widget_5);
        radioButtonFile->setObjectName(QString::fromUtf8("radioButtonFile"));

        horizontalLayout_7->addWidget(radioButtonFile);

        radioButtonHackrf = new QRadioButton(widget_5);
        radioButtonHackrf->setObjectName(QString::fromUtf8("radioButtonHackrf"));

        horizontalLayout_7->addWidget(radioButtonHackrf);

        radioButtonUSRP = new QRadioButton(widget_5);
        radioButtonUSRP->setObjectName(QString::fromUtf8("radioButtonUSRP"));

        horizontalLayout_7->addWidget(radioButtonUSRP);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(370, 130, 391, 321));
        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 30, 371, 281));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_6 = new QWidget(page);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(10, 10, 351, 43));
        horizontalLayout_8 = new QHBoxLayout(widget_6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_8->addWidget(label_4);

        lineEdit_rawData = new QLineEdit(widget_6);
        lineEdit_rawData->setObjectName(QString::fromUtf8("lineEdit_rawData"));

        horizontalLayout_8->addWidget(lineEdit_rawData);

        toolButton_rawData = new QToolButton(widget_6);
        toolButton_rawData->setObjectName(QString::fromUtf8("toolButton_rawData"));

        horizontalLayout_8->addWidget(toolButton_rawData);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        layoutWidget2 = new QWidget(page_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 361, 271));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(layoutWidget2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_9 = new QHBoxLayout(widget_7);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        lineEdit_gain = new QLineEdit(widget_7);
        lineEdit_gain->setObjectName(QString::fromUtf8("lineEdit_gain"));
        lineEdit_gain->setMaximumSize(QSize(296, 16777215));
        lineEdit_gain->setClearButtonEnabled(false);

        horizontalLayout_9->addWidget(lineEdit_gain);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_7);

        widget_8 = new QWidget(layoutWidget2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_10 = new QHBoxLayout(widget_8);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineEdit_rf = new QLineEdit(widget_8);
        lineEdit_rf->setObjectName(QString::fromUtf8("lineEdit_rf"));
        lineEdit_rf->setMaximumSize(QSize(296, 16777215));
        lineEdit_rf->setClearButtonEnabled(false);

        horizontalLayout_10->addWidget(lineEdit_rf);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_8);

        widget_9 = new QWidget(layoutWidget2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_11 = new QHBoxLayout(widget_9);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(widget_9);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        lineEdit_if = new QLineEdit(widget_9);
        lineEdit_if->setObjectName(QString::fromUtf8("lineEdit_if"));
        lineEdit_if->setMaximumSize(QSize(296, 16777215));
        lineEdit_if->setClearButtonEnabled(false);

        horizontalLayout_11->addWidget(lineEdit_if);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_9);

        widget_10 = new QWidget(layoutWidget2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_12 = new QHBoxLayout(widget_10);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_8 = new QLabel(widget_10);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_12->addWidget(label_8);

        checkBox_agc = new QCheckBox(widget_10);
        checkBox_agc->setObjectName(QString::fromUtf8("checkBox_agc"));

        horizontalLayout_12->addWidget(checkBox_agc);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_10);

        widget_11 = new QWidget(layoutWidget2);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_13 = new QHBoxLayout(widget_11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_9 = new QLabel(widget_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_13->addWidget(label_9);

        checkBox_bias = new QCheckBox(widget_11);
        checkBox_bias->setObjectName(QString::fromUtf8("checkBox_bias"));
        checkBox_bias->setTristate(false);

        horizontalLayout_13->addWidget(checkBox_bias);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_11);

        stackedWidget->addWidget(page_2);
        SdrWindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SdrWindows);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 811, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        SdrWindows->setMenuBar(menubar);
        statusbar = new QStatusBar(SdrWindows);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SdrWindows->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionNew);
        menu->addAction(actionExit);
        menu_2->addAction(actionAbout);

        retranslateUi(SdrWindows);

        comboBox->setCurrentIndex(3);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SdrWindows);
    } // setupUi

    void retranslateUi(QMainWindow *SdrWindows)
    {
        SdrWindows->setWindowTitle(QCoreApplication::translate("SdrWindows", "SdrWindows", nullptr));
        actionOpen->setText(QCoreApplication::translate("SdrWindows", "Open", nullptr));
        actionNew->setText(QCoreApplication::translate("SdrWindows", "New", nullptr));
        actionExit->setText(QCoreApplication::translate("SdrWindows", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("SdrWindows", "About", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SdrWindows", "Settings", nullptr));
        label->setText(QCoreApplication::translate("SdrWindows", "Data Type", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SdrWindows", "byte", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SdrWindows", "short", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SdrWindows", "float", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SdrWindows", "ibyte", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("SdrWindows", "ishort", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("SdrWindows", "cbyte", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("SdrWindows", "cshort", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("SdrWindows", "gr_complex", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("SdrWindows", "ibyte", nullptr));
        label_2->setText(QCoreApplication::translate("SdrWindows", "Sample Rate (Hz)", nullptr));
        lineEdit->setText(QCoreApplication::translate("SdrWindows", "4e6", nullptr));
        label_3->setText(QCoreApplication::translate("SdrWindows", "Read Config Path ", nullptr));
        lineEdit_configPath->setText(QCoreApplication::translate("SdrWindows", "../file.conf", nullptr));
        toolButton_conf->setText(QCoreApplication::translate("SdrWindows", "...", nullptr));
        label_10->setText(QCoreApplication::translate("SdrWindows", "Working Place", nullptr));
        lineEdit_workPath->setText(QString());
        toolButton_workPath->setText(QCoreApplication::translate("SdrWindows", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("SdrWindows", "Read", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SdrWindows", "Start", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SdrWindows", "Default", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SdrWindows", "Signal Source Implementation", nullptr));
        radioButtonFile->setText(QCoreApplication::translate("SdrWindows", "File", nullptr));
        radioButtonHackrf->setText(QCoreApplication::translate("SdrWindows", "HackRF", nullptr));
        radioButtonUSRP->setText(QCoreApplication::translate("SdrWindows", "USRP", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SdrWindows", "Settings-2", nullptr));
        label_4->setText(QCoreApplication::translate("SdrWindows", "Raw Signal File Path", nullptr));
        toolButton_rawData->setText(QCoreApplication::translate("SdrWindows", "...", nullptr));
        label_5->setText(QCoreApplication::translate("SdrWindows", "Gain", nullptr));
        lineEdit_gain->setText(QCoreApplication::translate("SdrWindows", "0", nullptr));
        label_6->setText(QCoreApplication::translate("SdrWindows", "RF Gain", nullptr));
        lineEdit_rf->setText(QCoreApplication::translate("SdrWindows", "0", nullptr));
        label_7->setText(QCoreApplication::translate("SdrWindows", "IF Gain", nullptr));
        lineEdit_if->setText(QCoreApplication::translate("SdrWindows", "0", nullptr));
        label_8->setText(QCoreApplication::translate("SdrWindows", "AGC", nullptr));
        checkBox_agc->setText(QCoreApplication::translate("SdrWindows", "Enable", nullptr));
        label_9->setText(QCoreApplication::translate("SdrWindows", "Bias Voltage", nullptr));
        checkBox_bias->setText(QCoreApplication::translate("SdrWindows", "Enable", nullptr));
        menu->setTitle(QCoreApplication::translate("SdrWindows", "File", nullptr));
        menu_2->setTitle(QCoreApplication::translate("SdrWindows", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SdrWindows: public Ui_SdrWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDRWINDOWS_H
