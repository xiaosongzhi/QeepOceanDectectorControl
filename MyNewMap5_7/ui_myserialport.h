/********************************************************************************
** Form generated from reading UI file 'myserialport.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSERIALPORT_H
#define UI_MYSERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySerialPort
{
public:
    QGroupBox *groupBox;
    QComboBox *rfSerialPort_ComboBox;
    QComboBox *rfBaud_ComboBox;
    QLabel *label;
    QPushButton *rfOpen_Btn;
    QPushButton *rfFlush_Btn;
    QGroupBox *groupBox_2;
    QPushButton *soundOpen_Btn;
    QPushButton *soundFlush_Btn;
    QLabel *label_3;
    QComboBox *soundBaud_Combox;
    QComboBox *soundSerialPort_Combox;
    QGroupBox *groupBox_3;
    QPushButton *sateOpen_Btn;
    QPushButton *sateFlush_Btn;
    QLabel *label_4;
    QComboBox *sateBaud_Combox;
    QComboBox *sateSerialPort_Combox;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *hostIP_Combox;
    QComboBox *hostPort_Combox;
    QPushButton *udpConnect_Btn;
    QPushButton *disConnect_Btn;
    QGroupBox *groupBox_5;
    QComboBox *slaveIP_Combox;
    QComboBox *slavePort_Combox;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *confirm_Btn;
    QGroupBox *groupBox_6;
    QCheckBox *rf_CheckBox;
    QCheckBox *sound_CheckBox;
    QCheckBox *sate_CheckBox;
    QCheckBox *net_CheckBox;
    QGroupBox *groupBox_7;
    QCheckBox *flushSpeed_CheckBox;
    QCheckBox *flushSenser_CheckBox;
    QGroupBox *groupBox_8;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *debug_Btn;
    QPushButton *pushButton;

    void setupUi(QWidget *MySerialPort)
    {
        if (MySerialPort->objectName().isEmpty())
            MySerialPort->setObjectName(QStringLiteral("MySerialPort"));
        MySerialPort->resize(801, 754);
        MySerialPort->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        groupBox = new QGroupBox(MySerialPort);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 231, 171));
        rfSerialPort_ComboBox = new QComboBox(groupBox);
        rfSerialPort_ComboBox->setObjectName(QStringLiteral("rfSerialPort_ComboBox"));
        rfSerialPort_ComboBox->setGeometry(QRect(20, 20, 181, 22));
        rfBaud_ComboBox = new QComboBox(groupBox);
        rfBaud_ComboBox->setObjectName(QStringLiteral("rfBaud_ComboBox"));
        rfBaud_ComboBox->setGeometry(QRect(80, 60, 121, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 56, 51, 31));
        rfOpen_Btn = new QPushButton(groupBox);
        rfOpen_Btn->setObjectName(QStringLiteral("rfOpen_Btn"));
        rfOpen_Btn->setGeometry(QRect(20, 110, 81, 28));
        rfFlush_Btn = new QPushButton(groupBox);
        rfFlush_Btn->setObjectName(QStringLiteral("rfFlush_Btn"));
        rfFlush_Btn->setGeometry(QRect(122, 110, 81, 28));
        groupBox_2 = new QGroupBox(MySerialPort);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 20, 230, 171));
        soundOpen_Btn = new QPushButton(groupBox_2);
        soundOpen_Btn->setObjectName(QStringLiteral("soundOpen_Btn"));
        soundOpen_Btn->setGeometry(QRect(0, 110, 93, 28));
        soundFlush_Btn = new QPushButton(groupBox_2);
        soundFlush_Btn->setObjectName(QStringLiteral("soundFlush_Btn"));
        soundFlush_Btn->setGeometry(QRect(120, 110, 93, 28));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 72, 15));
        soundBaud_Combox = new QComboBox(groupBox_2);
        soundBaud_Combox->setObjectName(QStringLiteral("soundBaud_Combox"));
        soundBaud_Combox->setGeometry(QRect(120, 50, 87, 22));
        soundSerialPort_Combox = new QComboBox(groupBox_2);
        soundSerialPort_Combox->setObjectName(QStringLiteral("soundSerialPort_Combox"));
        soundSerialPort_Combox->setGeometry(QRect(10, 20, 201, 22));
        groupBox_3 = new QGroupBox(MySerialPort);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(550, 20, 230, 171));
        sateOpen_Btn = new QPushButton(groupBox_3);
        sateOpen_Btn->setObjectName(QStringLiteral("sateOpen_Btn"));
        sateOpen_Btn->setGeometry(QRect(10, 110, 93, 28));
        sateFlush_Btn = new QPushButton(groupBox_3);
        sateFlush_Btn->setObjectName(QStringLiteral("sateFlush_Btn"));
        sateFlush_Btn->setGeometry(QRect(120, 110, 93, 28));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 72, 15));
        sateBaud_Combox = new QComboBox(groupBox_3);
        sateBaud_Combox->setObjectName(QStringLiteral("sateBaud_Combox"));
        sateBaud_Combox->setGeometry(QRect(110, 70, 87, 22));
        sateSerialPort_Combox = new QComboBox(groupBox_3);
        sateSerialPort_Combox->setObjectName(QStringLiteral("sateSerialPort_Combox"));
        sateSerialPort_Combox->setGeometry(QRect(20, 30, 201, 22));
        groupBox_4 = new QGroupBox(MySerialPort);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(true);
        groupBox_4->setGeometry(QRect(20, 200, 331, 191));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 40, 41, 16));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 90, 41, 16));
        hostIP_Combox = new QComboBox(groupBox_4);
        hostIP_Combox->setObjectName(QStringLiteral("hostIP_Combox"));
        hostIP_Combox->setGeometry(QRect(90, 40, 201, 22));
        hostPort_Combox = new QComboBox(groupBox_4);
        hostPort_Combox->setObjectName(QStringLiteral("hostPort_Combox"));
        hostPort_Combox->setGeometry(QRect(90, 90, 201, 22));
        hostPort_Combox->setEditable(false);
        udpConnect_Btn = new QPushButton(groupBox_4);
        udpConnect_Btn->setObjectName(QStringLiteral("udpConnect_Btn"));
        udpConnect_Btn->setGeometry(QRect(20, 130, 93, 28));
        disConnect_Btn = new QPushButton(groupBox_4);
        disConnect_Btn->setObjectName(QStringLiteral("disConnect_Btn"));
        disConnect_Btn->setGeometry(QRect(170, 130, 93, 28));
        groupBox_5 = new QGroupBox(MySerialPort);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(400, 200, 361, 191));
        slaveIP_Combox = new QComboBox(groupBox_5);
        slaveIP_Combox->setObjectName(QStringLiteral("slaveIP_Combox"));
        slaveIP_Combox->setGeometry(QRect(100, 50, 221, 22));
        slavePort_Combox = new QComboBox(groupBox_5);
        slavePort_Combox->setObjectName(QStringLiteral("slavePort_Combox"));
        slavePort_Combox->setGeometry(QRect(96, 90, 221, 22));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 72, 15));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 90, 72, 15));
        confirm_Btn = new QPushButton(groupBox_5);
        confirm_Btn->setObjectName(QStringLiteral("confirm_Btn"));
        confirm_Btn->setGeometry(QRect(220, 140, 93, 28));
        groupBox_6 = new QGroupBox(MySerialPort);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 400, 331, 61));
        rf_CheckBox = new QCheckBox(groupBox_6);
        rf_CheckBox->setObjectName(QStringLiteral("rf_CheckBox"));
        rf_CheckBox->setGeometry(QRect(20, 27, 71, 19));
        sound_CheckBox = new QCheckBox(groupBox_6);
        sound_CheckBox->setObjectName(QStringLiteral("sound_CheckBox"));
        sound_CheckBox->setGeometry(QRect(98, 27, 71, 19));
        sate_CheckBox = new QCheckBox(groupBox_6);
        sate_CheckBox->setObjectName(QStringLiteral("sate_CheckBox"));
        sate_CheckBox->setGeometry(QRect(190, 26, 71, 19));
        net_CheckBox = new QCheckBox(groupBox_6);
        net_CheckBox->setObjectName(QStringLiteral("net_CheckBox"));
        net_CheckBox->setGeometry(QRect(270, 26, 71, 19));
        groupBox_7 = new QGroupBox(MySerialPort);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(400, 400, 251, 61));
        flushSpeed_CheckBox = new QCheckBox(groupBox_7);
        flushSpeed_CheckBox->setObjectName(QStringLiteral("flushSpeed_CheckBox"));
        flushSpeed_CheckBox->setGeometry(QRect(44, 27, 71, 16));
        flushSenser_CheckBox = new QCheckBox(groupBox_7);
        flushSenser_CheckBox->setObjectName(QStringLiteral("flushSenser_CheckBox"));
        flushSenser_CheckBox->setGeometry(QRect(150, 26, 91, 16));
        groupBox_8 = new QGroupBox(MySerialPort);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 470, 331, 171));
        lineEdit_1 = new QLineEdit(groupBox_8);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(60, 20, 111, 20));
        lineEdit_2 = new QLineEdit(groupBox_8);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 50, 113, 20));
        lineEdit_3 = new QLineEdit(groupBox_8);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 80, 113, 20));
        lineEdit_4 = new QLineEdit(groupBox_8);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 110, 113, 20));
        lineEdit_5 = new QLineEdit(groupBox_8);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(60, 140, 113, 20));
        debug_Btn = new QPushButton(groupBox_8);
        debug_Btn->setObjectName(QStringLiteral("debug_Btn"));
        debug_Btn->setGeometry(QRect(230, 80, 75, 23));
        pushButton = new QPushButton(MySerialPort);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 520, 93, 28));

        retranslateUi(MySerialPort);

        QMetaObject::connectSlotsByName(MySerialPort);
    } // setupUi

    void retranslateUi(QWidget *MySerialPort)
    {
        MySerialPort->setWindowTitle(QApplication::translate("MySerialPort", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MySerialPort", "\345\260\204\351\242\221\351\200\232\344\277\241", Q_NULLPTR));
        rfBaud_ComboBox->clear();
        rfBaud_ComboBox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "9600", Q_NULLPTR)
         << QApplication::translate("MySerialPort", "115200", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MySerialPort", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        rfOpen_Btn->setText(QApplication::translate("MySerialPort", "\346\211\223\345\274\200", Q_NULLPTR));
        rfFlush_Btn->setText(QApplication::translate("MySerialPort", "\345\210\267\346\226\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MySerialPort", "\346\260\264\345\243\260\351\200\232\344\277\241", Q_NULLPTR));
        soundOpen_Btn->setText(QApplication::translate("MySerialPort", "\346\211\223\345\274\200", Q_NULLPTR));
        soundFlush_Btn->setText(QApplication::translate("MySerialPort", "\345\210\267\346\226\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("MySerialPort", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        soundBaud_Combox->clear();
        soundBaud_Combox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "9600", Q_NULLPTR)
         << QApplication::translate("MySerialPort", "115200", Q_NULLPTR)
        );
        groupBox_3->setTitle(QApplication::translate("MySerialPort", "\345\215\253\346\230\237\351\200\232\344\277\241", Q_NULLPTR));
        sateOpen_Btn->setText(QApplication::translate("MySerialPort", "\346\211\223\345\274\200", Q_NULLPTR));
        sateFlush_Btn->setText(QApplication::translate("MySerialPort", "\345\210\267\346\226\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("MySerialPort", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        sateBaud_Combox->clear();
        sateBaud_Combox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "9600", Q_NULLPTR)
         << QApplication::translate("MySerialPort", "115200", Q_NULLPTR)
        );
        groupBox_4->setTitle(QApplication::translate("MySerialPort", "UDPHost", Q_NULLPTR));
        label_5->setText(QApplication::translate("MySerialPort", "IP ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MySerialPort", "Port", Q_NULLPTR));
        hostIP_Combox->clear();
        hostIP_Combox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "192.168.1.141", Q_NULLPTR)
         << QApplication::translate("MySerialPort", "192.168.1.10", Q_NULLPTR)
        );
        hostPort_Combox->clear();
        hostPort_Combox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "8080", Q_NULLPTR)
        );
        udpConnect_Btn->setText(QApplication::translate("MySerialPort", "\350\277\236\346\216\245", Q_NULLPTR));
        disConnect_Btn->setText(QApplication::translate("MySerialPort", "\346\226\255\345\274\200", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MySerialPort", "UDPSlave", Q_NULLPTR));
        slaveIP_Combox->clear();
        slaveIP_Combox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "192.168.1.117", Q_NULLPTR)
         << QApplication::translate("MySerialPort", "192.168.1.12", Q_NULLPTR)
        );
        slavePort_Combox->clear();
        slavePort_Combox->insertItems(0, QStringList()
         << QApplication::translate("MySerialPort", "8080", Q_NULLPTR)
         << QApplication::translate("MySerialPort", "8000", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("MySerialPort", "IP ", Q_NULLPTR));
        label_8->setText(QApplication::translate("MySerialPort", "Port", Q_NULLPTR));
        confirm_Btn->setText(QApplication::translate("MySerialPort", "\347\241\256\350\256\244", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MySerialPort", "\351\200\232\344\277\241\346\226\271\345\274\217", Q_NULLPTR));
        rf_CheckBox->setText(QApplication::translate("MySerialPort", "\345\260\204\351\242\221", Q_NULLPTR));
        sound_CheckBox->setText(QApplication::translate("MySerialPort", "\346\260\264\345\243\260", Q_NULLPTR));
        sate_CheckBox->setText(QApplication::translate("MySerialPort", "\345\215\253\346\230\237", Q_NULLPTR));
        net_CheckBox->setText(QApplication::translate("MySerialPort", "\347\275\221\347\273\234", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MySerialPort", "\350\207\252\345\212\250\345\210\267\346\226\260", Q_NULLPTR));
        flushSpeed_CheckBox->setText(QApplication::translate("MySerialPort", "\351\200\237\345\272\246", Q_NULLPTR));
        flushSenser_CheckBox->setText(QApplication::translate("MySerialPort", "\344\274\240\346\204\237\345\231\250\347\212\266\346\200\201", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MySerialPort", " \350\260\203\350\257\225", Q_NULLPTR));
        debug_Btn->setText(QApplication::translate("MySerialPort", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MySerialPort", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MySerialPort: public Ui_MySerialPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSERIALPORT_H
