/********************************************************************************
** Form generated from reading UI file 'carcontroler.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARCONTROLER_H
#define UI_CARCONTROLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarControlerClass
{
public:
    QWidget *centralWidget;
    QPushButton *btnOpenCam;
    QPushButton *btnCloseCam;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *labelOri;
    QLabel *labelProcessed;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxBaudRate;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBoxData;
    QLabel *label_5;
    QComboBox *comboBoxCheck;
    QLabel *label_6;
    QComboBox *comboBoxStop;
    QRadioButton *radioButtonTrue;
    QRadioButton *radioButtonFalse;
    QPushButton *btnConnect;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBoxPort;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *comboBoxCam;
    QLabel *label_12;
    QCheckBox *checkBoxCamInfo;
    QCheckBox *checkBoxCarInfo;
    QLabel *label_7;
    QPushButton *btnDisconnect;

    void setupUi(QMainWindow *CarControlerClass)
    {
        if (CarControlerClass->objectName().isEmpty())
            CarControlerClass->setObjectName(QStringLiteral("CarControlerClass"));
        CarControlerClass->setWindowModality(Qt::NonModal);
        CarControlerClass->resize(1242, 524);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CarControlerClass->sizePolicy().hasHeightForWidth());
        CarControlerClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(CarControlerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnOpenCam = new QPushButton(centralWidget);
        btnOpenCam->setObjectName(QStringLiteral("btnOpenCam"));
        btnOpenCam->setGeometry(QRect(1020, 90, 101, 28));
        btnCloseCam = new QPushButton(centralWidget);
        btnCloseCam->setObjectName(QStringLiteral("btnCloseCam"));
        btnCloseCam->setGeometry(QRect(1130, 90, 101, 28));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-110, 0, 1111, 551));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1109, 549));
        labelOri = new QLabel(scrollAreaWidgetContents);
        labelOri->setObjectName(QStringLiteral("labelOri"));
        labelOri->setGeometry(QRect(120, 70, 480, 360));
        labelOri->setAutoFillBackground(false);
        labelProcessed = new QLabel(scrollAreaWidgetContents);
        labelProcessed->setObjectName(QStringLiteral("labelProcessed"));
        labelProcessed->setGeometry(QRect(610, 70, 480, 360));
        labelProcessed->setAutoFillBackground(false);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 30, 151, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(770, 30, 151, 31));
        label_2->setFont(font);
        scrollArea->setWidget(scrollAreaWidgetContents);
        comboBoxBaudRate = new QComboBox(centralWidget);
        comboBoxBaudRate->setObjectName(QStringLiteral("comboBoxBaudRate"));
        comboBoxBaudRate->setGeometry(QRect(1090, 200, 141, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1020, 200, 51, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1020, 230, 51, 21));
        comboBoxData = new QComboBox(centralWidget);
        comboBoxData->setObjectName(QStringLiteral("comboBoxData"));
        comboBoxData->setGeometry(QRect(1090, 230, 141, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1020, 260, 51, 21));
        comboBoxCheck = new QComboBox(centralWidget);
        comboBoxCheck->setObjectName(QStringLiteral("comboBoxCheck"));
        comboBoxCheck->setGeometry(QRect(1090, 260, 141, 22));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1020, 290, 51, 21));
        comboBoxStop = new QComboBox(centralWidget);
        comboBoxStop->setObjectName(QStringLiteral("comboBoxStop"));
        comboBoxStop->setGeometry(QRect(1090, 290, 141, 22));
        radioButtonTrue = new QRadioButton(centralWidget);
        radioButtonTrue->setObjectName(QStringLiteral("radioButtonTrue"));
        radioButtonTrue->setGeometry(QRect(1030, 400, 61, 19));
        radioButtonFalse = new QRadioButton(centralWidget);
        radioButtonFalse->setObjectName(QStringLiteral("radioButtonFalse"));
        radioButtonFalse->setGeometry(QRect(1150, 400, 61, 19));
        radioButtonFalse->setChecked(true);
        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(1020, 320, 91, 28));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1070, 370, 101, 21));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1020, 170, 61, 21));
        comboBoxPort = new QComboBox(centralWidget);
        comboBoxPort->setObjectName(QStringLiteral("comboBoxPort"));
        comboBoxPort->setGeometry(QRect(1090, 170, 141, 22));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1090, 140, 71, 21));
        label_10->setFont(font1);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1090, 20, 61, 21));
        label_11->setFont(font1);
        comboBoxCam = new QComboBox(centralWidget);
        comboBoxCam->setObjectName(QStringLiteral("comboBoxCam"));
        comboBoxCam->setGeometry(QRect(1060, 50, 171, 22));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1020, 50, 31, 21));
        checkBoxCamInfo = new QCheckBox(centralWidget);
        checkBoxCamInfo->setObjectName(QStringLiteral("checkBoxCamInfo"));
        checkBoxCamInfo->setEnabled(false);
        checkBoxCamInfo->setGeometry(QRect(1140, 490, 101, 19));
        checkBoxCamInfo->setMouseTracking(false);
        checkBoxCamInfo->setCheckable(true);
        checkBoxCarInfo = new QCheckBox(centralWidget);
        checkBoxCarInfo->setObjectName(QStringLiteral("checkBoxCarInfo"));
        checkBoxCarInfo->setEnabled(false);
        checkBoxCarInfo->setGeometry(QRect(1030, 490, 101, 19));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        checkBoxCarInfo->setFont(font2);
        checkBoxCarInfo->setMouseTracking(false);
        checkBoxCarInfo->setCheckable(true);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1100, 450, 61, 21));
        label_7->setFont(font1);
        btnDisconnect = new QPushButton(centralWidget);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(1140, 320, 91, 28));
        CarControlerClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(comboBoxCam, btnOpenCam);
        QWidget::setTabOrder(btnOpenCam, btnCloseCam);
        QWidget::setTabOrder(btnCloseCam, comboBoxPort);
        QWidget::setTabOrder(comboBoxPort, comboBoxBaudRate);
        QWidget::setTabOrder(comboBoxBaudRate, comboBoxData);
        QWidget::setTabOrder(comboBoxData, comboBoxCheck);
        QWidget::setTabOrder(comboBoxCheck, comboBoxStop);
        QWidget::setTabOrder(comboBoxStop, btnConnect);
        QWidget::setTabOrder(btnConnect, radioButtonTrue);
        QWidget::setTabOrder(radioButtonTrue, radioButtonFalse);
        QWidget::setTabOrder(radioButtonFalse, checkBoxCarInfo);
        QWidget::setTabOrder(checkBoxCarInfo, checkBoxCamInfo);
        QWidget::setTabOrder(checkBoxCamInfo, scrollArea);

        retranslateUi(CarControlerClass);

        QMetaObject::connectSlotsByName(CarControlerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CarControlerClass)
    {
        CarControlerClass->setWindowTitle(QApplication::translate("CarControlerClass", "CarControler", 0));
        btnOpenCam->setText(QApplication::translate("CarControlerClass", "\346\211\223\345\274\200\347\233\270\346\234\272", 0));
        btnCloseCam->setText(QApplication::translate("CarControlerClass", "\345\205\263\351\227\255\347\233\270\346\234\272", 0));
        labelOri->setText(QString());
        labelProcessed->setText(QString());
        label->setText(QApplication::translate("CarControlerClass", "\351\207\207\351\233\206\345\210\260\347\232\204\345\233\276\345\203\217", 0));
        label_2->setText(QApplication::translate("CarControlerClass", "\345\244\204\347\220\206\345\220\216\347\232\204\345\233\276\345\203\217", 0));
        comboBoxBaudRate->clear();
        comboBoxBaudRate->insertItems(0, QStringList()
         << QApplication::translate("CarControlerClass", "9600", 0)
         << QApplication::translate("CarControlerClass", "1200", 0)
        );
        label_3->setText(QApplication::translate("CarControlerClass", "\346\263\242\347\211\271\347\216\207", 0));
        label_4->setText(QApplication::translate("CarControlerClass", "\346\225\260\346\215\256\344\275\215", 0));
        comboBoxData->clear();
        comboBoxData->insertItems(0, QStringList()
         << QApplication::translate("CarControlerClass", "8", 0)
        );
        label_5->setText(QApplication::translate("CarControlerClass", "\346\240\241\351\252\214\344\275\215", 0));
        comboBoxCheck->clear();
        comboBoxCheck->insertItems(0, QStringList()
         << QApplication::translate("CarControlerClass", "0", 0)
         << QApplication::translate("CarControlerClass", "2", 0)
        );
        label_6->setText(QApplication::translate("CarControlerClass", "\345\201\234\346\255\242\344\275\215", 0));
        comboBoxStop->clear();
        comboBoxStop->insertItems(0, QStringList()
         << QApplication::translate("CarControlerClass", "0", 0)
         << QApplication::translate("CarControlerClass", "1", 0)
         << QApplication::translate("CarControlerClass", "2", 0)
        );
        radioButtonTrue->setText(QApplication::translate("CarControlerClass", "\350\277\220\350\241\214", 0));
        radioButtonFalse->setText(QApplication::translate("CarControlerClass", "\345\201\234\346\255\242", 0));
        btnConnect->setText(QApplication::translate("CarControlerClass", "\350\277\236\346\216\245\345\260\217\350\275\246", 0));
        label_8->setText(QApplication::translate("CarControlerClass", "\345\260\217\350\275\246\350\277\220\350\241\214\345\274\200\345\205\263", 0));
        label_9->setText(QApplication::translate("CarControlerClass", "\347\233\221\345\220\254\347\253\257\345\217\243", 0));
        label_10->setText(QApplication::translate("CarControlerClass", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label_11->setText(QApplication::translate("CarControlerClass", "\347\233\270\346\234\272\345\274\200\345\205\263", 0));
        label_12->setText(QApplication::translate("CarControlerClass", "\347\233\270\346\234\272", 0));
        checkBoxCamInfo->setText(QApplication::translate("CarControlerClass", "\347\233\270\346\234\272\345\267\262\346\211\223\345\274\200", 0));
        checkBoxCarInfo->setText(QApplication::translate("CarControlerClass", "\345\260\217\350\275\246\345\267\262\350\277\236\346\216\245", 0));
        label_7->setText(QApplication::translate("CarControlerClass", "\347\233\221\350\247\206\346\235\277", 0));
        btnDisconnect->setText(QApplication::translate("CarControlerClass", "\346\226\255\345\274\200\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class CarControlerClass: public Ui_CarControlerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARCONTROLER_H
