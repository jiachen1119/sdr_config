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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
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
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_2;
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
    QWidget *page_2;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sdr_windows)
    {
        if (sdr_windows->objectName().isEmpty())
            sdr_windows->setObjectName(QString::fromUtf8("sdr_windows"));
        sdr_windows->resize(811, 648);
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
        groupBox->setGeometry(QRect(30, 130, 311, 221));
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
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_5->addWidget(lineEdit_2);

        toolButton_2 = new QToolButton(widget_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout_5->addWidget(toolButton_2);


        verticalLayout->addWidget(widget_3);

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
        widget_4->setGeometry(QRect(500, 540, 270, 43));
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
        widget_5->setGeometry(QRect(20, 30, 311, 41));
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

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(370, 130, 391, 321));
        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 30, 371, 281));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        sdr_windows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sdr_windows);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 811, 28));
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
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sdr_windows);
    } // setupUi

    void retranslateUi(QMainWindow *sdr_windows)
    {
        sdr_windows->setWindowTitle(QCoreApplication::translate("sdr_windows", "sdr_windows", nullptr));
        actionOpen->setText(QCoreApplication::translate("sdr_windows", "Open", nullptr));
        actionNew->setText(QCoreApplication::translate("sdr_windows", "New", nullptr));
        actionExit->setText(QCoreApplication::translate("sdr_windows", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("sdr_windows", "About", nullptr));
        groupBox->setTitle(QCoreApplication::translate("sdr_windows", "Settings", nullptr));
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
        lineEdit->setText(QCoreApplication::translate("sdr_windows", "4e6", nullptr));
        label_3->setText(QCoreApplication::translate("sdr_windows", "Read Config Path ", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("sdr_windows", "../1.conf", nullptr));
        toolButton_2->setText(QCoreApplication::translate("sdr_windows", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("sdr_windows", "Read", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sdr_windows", "Write", nullptr));
        pushButton_3->setText(QCoreApplication::translate("sdr_windows", "Default", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("sdr_windows", "GroupBox", nullptr));
        radioButtonFile->setText(QCoreApplication::translate("sdr_windows", "File", nullptr));
        radioButtonHackrf->setText(QCoreApplication::translate("sdr_windows", "HackRF", nullptr));
        radioButtonUSRP->setText(QCoreApplication::translate("sdr_windows", "USRP", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("sdr_windows", "GroupBox", nullptr));
        menu->setTitle(QCoreApplication::translate("sdr_windows", "File", nullptr));
        menu_2->setTitle(QCoreApplication::translate("sdr_windows", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sdr_windows: public Ui_sdr_windows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDR_WINDOWS_H
