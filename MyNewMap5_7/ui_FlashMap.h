/********************************************************************************
** Form generated from reading UI file 'FlashMap.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHMAP_H
#define UI_FLASHMAP_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qfi_hsi.h>

QT_BEGIN_NAMESPACE

class Ui_FlashMap
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_6;
    QProgressBar *progressBar;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QLabel *altitude_label;
    QLabel *deep_label;
    QLabel *deepAngle_label;
    QLabel *altitudeAngle_label;
    QAxWidget *axWidget;
    QGroupBox *groupBox;
    QPushButton *planTrack_Btn;
    QLabel *rF_label;
    QLabel *sound_label;
    QLabel *sate_label;
    QPushButton *reSendTrack_Btn;
    QPushButton *clearTrack_Btn;
    QPushButton *displayTrack_Btn;
    QPushButton *setDevice_Btn;
    QPushButton *deletePath_Btn;
    QPushButton *init_Btn;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    qfi_HSI *VgraphicsView;
    QGroupBox *groupBox_7;
    QLCDNumber *time_lcdNumber;
    QLabel *roll_label;
    QLabel *pitch_label;
    QLabel *yaw_label;
    QLabel *lat_label;
    QLabel *lon_label;
    QLabel *pitchAngle_label;
    qfi_HSI *yaw_GraphicsView;
    qfi_HSI *roll_GraphicsView;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_4;
    QLabel *bizhang_label;
    QGroupBox *groupBox_5;
    QLabel *salt_label;
    QLabel *hum_label;
    QLabel *inTem_label;
    QLabel *outTem_label;
    QLabel *humAngle_label;
    QLabel *saltAngle_label;

    void setupUi(QWidget *FlashMap)
    {
        if (FlashMap->objectName().isEmpty())
            FlashMap->setObjectName(QStringLiteral("FlashMap"));
        FlashMap->resize(1920, 1080);
        QFont font;
        font.setPointSize(10);
        FlashMap->setFont(font);
        gridLayout = new QGridLayout(FlashMap);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_6 = new QGroupBox(FlashMap);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setLayoutDirection(Qt::RightToLeft);
        groupBox_6->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\345\244\247\350\235\240\351\262\274\347\225\214\351\235\242\350\203\214\346\231\257_01.png);"));
        progressBar = new QProgressBar(groupBox_6);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(837, 51, 495, 24));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {   border: 2px solid grey;   border-radius: 5px;   background-color: #FFFFFF;}\n"
"QProgressBar::chunk {   background-color: #05B8CC;   width: 20px;}\n"
"QProgressBar {   border: 2px solid grey;   border-radius: 5px;   text-align: center;}\n"
"border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        progressBar->setValue(80);

        verticalLayout_2->addWidget(groupBox_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_3 = new QGroupBox(FlashMap);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\347\225\214\351\235\242UI\345\210\207\345\233\276_03.png);"));
        altitude_label = new QLabel(groupBox_3);
        altitude_label->setObjectName(QStringLiteral("altitude_label"));
        altitude_label->setGeometry(QRect(43, 613, 71, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        altitude_label->setFont(font1);
        altitude_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        altitude_label->setAlignment(Qt::AlignCenter);
        deep_label = new QLabel(groupBox_3);
        deep_label->setObjectName(QStringLiteral("deep_label"));
        deep_label->setGeometry(QRect(42, 518, 75, 28));
        deep_label->setFont(font1);
        deep_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        deep_label->setAlignment(Qt::AlignCenter);
        deepAngle_label = new QLabel(groupBox_3);
        deepAngle_label->setObjectName(QStringLiteral("deepAngle_label"));
        deepAngle_label->setGeometry(QRect(97, 20, 11, 10));
        deepAngle_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\260\264\346\267\261\343\200\201\351\253\230\345\272\246.png);"));
        altitudeAngle_label = new QLabel(groupBox_3);
        altitudeAngle_label->setObjectName(QStringLiteral("altitudeAngle_label"));
        altitudeAngle_label->setGeometry(QRect(150, 747, 11, 10));
        altitudeAngle_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\344\277\257\344\273\260\357\274\214\346\260\264\346\267\261.png);"));

        horizontalLayout->addWidget(groupBox_3);

        axWidget = new QAxWidget(FlashMap);
        axWidget->setObjectName(QStringLiteral("axWidget"));
        axWidget->setProperty("styleSheet", QVariant(QStringLiteral("")));

        horizontalLayout->addWidget(axWidget);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 34);

        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(FlashMap);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\347\225\214\351\235\242UI\345\210\207\345\233\276_08.png);"));
        planTrack_Btn = new QPushButton(groupBox);
        planTrack_Btn->setObjectName(QStringLiteral("planTrack_Btn"));
        planTrack_Btn->setGeometry(QRect(140, 20, 158, 49));
        sizePolicy.setHeightForWidth(planTrack_Btn->sizePolicy().hasHeightForWidth());
        planTrack_Btn->setSizePolicy(sizePolicy);
        planTrack_Btn->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/image/\350\247\204\345\210\222\350\267\257\345\276\204-\346\255\243\345\270\270.png);}\n"
"QPushButton:hover{border-image: url(:/new/prefix1/image/\350\247\204\345\210\222\350\267\257\345\276\204-\346\202\254\346\265\256.png);}\n"
"QPushButton:pressed{border-image: url(:/new/prefix1/image/\350\247\204\345\210\222\350\267\257\345\276\204\346\214\211\344\270\213.png);}\n"
""));
        rF_label = new QLabel(groupBox);
        rF_label->setObjectName(QStringLiteral("rF_label"));
        rF_label->setGeometry(QRect(766, 20, 108, 107));
        sizePolicy.setHeightForWidth(rF_label->sizePolicy().hasHeightForWidth());
        rF_label->setSizePolicy(sizePolicy);
        rF_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        sound_label = new QLabel(groupBox);
        sound_label->setObjectName(QStringLiteral("sound_label"));
        sound_label->setGeometry(QRect(950, 20, 108, 107));
        sizePolicy.setHeightForWidth(sound_label->sizePolicy().hasHeightForWidth());
        sound_label->setSizePolicy(sizePolicy);
        sound_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        sate_label = new QLabel(groupBox);
        sate_label->setObjectName(QStringLiteral("sate_label"));
        sate_label->setGeometry(QRect(1134, 20, 108, 107));
        sizePolicy.setHeightForWidth(sate_label->sizePolicy().hasHeightForWidth());
        sate_label->setSizePolicy(sizePolicy);
        sate_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        reSendTrack_Btn = new QPushButton(groupBox);
        reSendTrack_Btn->setObjectName(QStringLiteral("reSendTrack_Btn"));
        reSendTrack_Btn->setGeometry(QRect(330, 20, 158, 49));
        sizePolicy.setHeightForWidth(reSendTrack_Btn->sizePolicy().hasHeightForWidth());
        reSendTrack_Btn->setSizePolicy(sizePolicy);
        reSendTrack_Btn->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/image/\351\207\215\346\226\260\345\217\221\351\200\201\350\275\250\350\277\271-\346\255\243\345\270\270.png);}\n"
"QPushButton:hover{border-image: url(:/new/prefix1/image/\351\207\215\346\226\260\345\217\221\351\200\201\350\275\250\350\277\271-\346\202\254\346\265\256.png);}\n"
"QPushButton:pressed{border-image: url(:/new/prefix1/image/\351\207\215\346\226\260\345\217\221\351\200\201\350\275\250\350\277\271-\346\214\211\344\270\213.png);}\n"
""));
        clearTrack_Btn = new QPushButton(groupBox);
        clearTrack_Btn->setObjectName(QStringLiteral("clearTrack_Btn"));
        clearTrack_Btn->setGeometry(QRect(330, 80, 158, 49));
        sizePolicy.setHeightForWidth(clearTrack_Btn->sizePolicy().hasHeightForWidth());
        clearTrack_Btn->setSizePolicy(sizePolicy);
        clearTrack_Btn->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/image/\346\270\205\346\245\232\350\275\250\350\277\271-\346\255\243\345\270\270.png);}\n"
"QPushButton:hover{border-image: url(:/new/prefix1/image/\346\270\205\346\245\232\350\275\250\350\277\271-\346\202\254\346\265\256.png);}\n"
"QPushButton:pressed{border-image: url(:/new/prefix1/image/\346\270\205\346\245\232\350\275\250\350\277\271-\346\214\211\344\270\213.png);}\n"
""));
        displayTrack_Btn = new QPushButton(groupBox);
        displayTrack_Btn->setObjectName(QStringLiteral("displayTrack_Btn"));
        displayTrack_Btn->setGeometry(QRect(140, 80, 158, 49));
        sizePolicy.setHeightForWidth(displayTrack_Btn->sizePolicy().hasHeightForWidth());
        displayTrack_Btn->setSizePolicy(sizePolicy);
        displayTrack_Btn->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/image/\346\230\276\347\244\272\350\275\250\350\277\271-\346\255\243\345\270\270.png);}\n"
"QPushButton:hover{border-image: url(:/new/prefix1/image/\346\230\276\347\244\272\350\275\250\350\277\271-\346\202\254\346\265\256.png);}\n"
"QPushButton:pressed{border-image: url(:/new/prefix1/image/\346\230\276\347\244\272\350\275\250\350\277\271-\346\214\211\344\270\213.png);}\n"
""));
        setDevice_Btn = new QPushButton(groupBox);
        setDevice_Btn->setObjectName(QStringLiteral("setDevice_Btn"));
        setDevice_Btn->setGeometry(QRect(520, 78, 158, 49));
        sizePolicy.setHeightForWidth(setDevice_Btn->sizePolicy().hasHeightForWidth());
        setDevice_Btn->setSizePolicy(sizePolicy);
        setDevice_Btn->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/image/\350\256\276\345\244\207\351\205\215\347\275\256-\346\255\243\345\270\270.png);}\n"
"QPushButton:hover{border-image: url(:/new/prefix1/image/\350\256\276\345\244\207\351\205\215\347\275\256-\346\202\254\346\265\256.png);}\n"
"QPushButton:pressed{border-image: url(:/new/prefix1/image/\350\256\276\345\244\207\351\205\215\347\275\256-\346\214\211\344\270\213.png);}"));
        deletePath_Btn = new QPushButton(groupBox);
        deletePath_Btn->setObjectName(QStringLiteral("deletePath_Btn"));
        deletePath_Btn->setGeometry(QRect(520, 20, 158, 49));
        sizePolicy.setHeightForWidth(deletePath_Btn->sizePolicy().hasHeightForWidth());
        deletePath_Btn->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        deletePath_Btn->setFont(font2);
        deletePath_Btn->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/new/prefix1/image/\345\210\240\351\231\244\350\267\257\345\276\204--\346\255\243\345\270\270.png);}\n"
"QPushButton:hover{border-image: url(:/new/prefix1/image/\345\210\240\351\231\244\350\267\257\345\276\204-\346\202\254\346\265\256.png);}\n"
"QPushButton:pressed{border-image: url(:/new/prefix1/image/\345\210\240\351\231\244\350\267\257\345\276\204-\346\214\211\344\270\213.png);}"));
        init_Btn = new QPushButton(groupBox);
        init_Btn->setObjectName(QStringLiteral("init_Btn"));
        init_Btn->setGeometry(QRect(850, 110, 93, 28));
        init_Btn->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(groupBox);

        verticalLayout->setStretch(0, 36);
        verticalLayout->setStretch(1, 7);

        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 18);

        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(FlashMap);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\345\244\247\350\235\240\351\262\274\347\225\214\351\235\242\350\203\214\346\231\257_02.png);"));
        VgraphicsView = new qfi_HSI(groupBox_2);
        VgraphicsView->setObjectName(QStringLiteral("VgraphicsView"));
        VgraphicsView->setGeometry(QRect(190, 40, 180, 180));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(VgraphicsView->sizePolicy().hasHeightForWidth());
        VgraphicsView->setSizePolicy(sizePolicy1);
        VgraphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        VgraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        VgraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_3->addWidget(groupBox_2);

        groupBox_7 = new QGroupBox(FlashMap);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\345\244\247\350\235\240\351\262\274\347\225\214\351\235\242\350\203\214\346\231\257_05.png);"));
        time_lcdNumber = new QLCDNumber(groupBox_7);
        time_lcdNumber->setObjectName(QStringLiteral("time_lcdNumber"));
        time_lcdNumber->setGeometry(QRect(278, 29, 200, 65));
        time_lcdNumber->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (2).png);\n"
"color: rgb(135, 203, 255);"));
        roll_label = new QLabel(groupBox_7);
        roll_label->setObjectName(QStringLiteral("roll_label"));
        roll_label->setGeometry(QRect(130, 120, 110, 26));
        roll_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        pitch_label = new QLabel(groupBox_7);
        pitch_label->setObjectName(QStringLiteral("pitch_label"));
        pitch_label->setGeometry(QRect(130, 150, 110, 26));
        pitch_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        yaw_label = new QLabel(groupBox_7);
        yaw_label->setObjectName(QStringLiteral("yaw_label"));
        yaw_label->setGeometry(QRect(130, 180, 110, 26));
        yaw_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        lat_label = new QLabel(groupBox_7);
        lat_label->setObjectName(QStringLiteral("lat_label"));
        lat_label->setGeometry(QRect(109, 29, 130, 28));
        lat_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (3).png);\n"
"color: rgb(85, 255, 255);"));
        lon_label = new QLabel(groupBox_7);
        lon_label->setObjectName(QStringLiteral("lon_label"));
        lon_label->setGeometry(QRect(109, 60, 130, 28));
        lon_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (3).png);\n"
"color: rgb(85, 255, 255);"));
        pitchAngle_label = new QLabel(groupBox_7);
        pitchAngle_label->setObjectName(QStringLiteral("pitchAngle_label"));
        pitchAngle_label->setGeometry(QRect(370, 300, 11, 10));
        pitchAngle_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\344\277\257\344\273\260\357\274\214\346\260\264\346\267\261.png);"));
        yaw_GraphicsView = new qfi_HSI(groupBox_7);
        yaw_GraphicsView->setObjectName(QStringLiteral("yaw_GraphicsView"));
        yaw_GraphicsView->setGeometry(QRect(30, 240, 200, 200));
        yaw_GraphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        yaw_GraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        yaw_GraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        roll_GraphicsView = new qfi_HSI(groupBox_7);
        roll_GraphicsView->setObjectName(QStringLiteral("roll_GraphicsView"));
        roll_GraphicsView->setGeometry(QRect(230, 180, 250, 250));
        roll_GraphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\200\217\346\230\216.png);"));
        roll_GraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        roll_GraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_3->addWidget(groupBox_7);

        verticalLayout_3->setStretch(0, 14);
        verticalLayout_3->setStretch(1, 29);

        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_4 = new QGroupBox(FlashMap);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\345\244\247\350\235\240\351\262\274\347\225\214\351\235\242\350\203\214\346\231\257_06.png);"));
        bizhang_label = new QLabel(groupBox_4);
        bizhang_label->setObjectName(QStringLiteral("bizhang_label"));
        bizhang_label->setGeometry(QRect(121, 37, 360, 84));
        bizhang_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (4).png);"));

        verticalLayout_4->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(FlashMap);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\345\244\247\350\235\240\351\262\274\347\225\214\351\235\242\350\203\214\346\231\257_07.png);"));
        salt_label = new QLabel(groupBox_5);
        salt_label->setObjectName(QStringLiteral("salt_label"));
        salt_label->setGeometry(QRect(89, 7, 55, 28));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        salt_label->setFont(font3);
        salt_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        salt_label->setAlignment(Qt::AlignCenter);
        hum_label = new QLabel(groupBox_5);
        hum_label->setObjectName(QStringLiteral("hum_label"));
        hum_label->setGeometry(QRect(90, 60, 55, 28));
        hum_label->setFont(font3);
        hum_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\226\207\345\255\227\346\241\206\350\203\214\346\231\257 (1).png);\n"
"color: rgb(85, 255, 255);"));
        hum_label->setAlignment(Qt::AlignCenter);
        inTem_label = new QLabel(groupBox_5);
        inTem_label->setObjectName(QStringLiteral("inTem_label"));
        inTem_label->setGeometry(QRect(250, 110, 99, 20));
        inTem_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\270\251\345\272\246\346\225\260\346\215\256\346\241\206.png);\n"
"color: rgb(85, 255, 255);"));
        inTem_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        outTem_label = new QLabel(groupBox_5);
        outTem_label->setObjectName(QStringLiteral("outTem_label"));
        outTem_label->setGeometry(QRect(249, 174, 99, 20));
        outTem_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\270\251\345\272\246\346\225\260\346\215\256\346\241\206.png);\n"
"color: rgb(85, 255, 255);"));
        outTem_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        humAngle_label = new QLabel(groupBox_5);
        humAngle_label->setObjectName(QStringLiteral("humAngle_label"));
        humAngle_label->setGeometry(QRect(160, 51, 8, 7));
        humAngle_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\347\233\220\345\272\246\346\271\277\345\272\246.png);"));
        saltAngle_label = new QLabel(groupBox_5);
        saltAngle_label->setObjectName(QStringLiteral("saltAngle_label"));
        saltAngle_label->setGeometry(QRect(160, 2, 8, 7));
        saltAngle_label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\347\233\220\345\272\246\346\271\277\345\272\246.png);"));

        verticalLayout_4->addWidget(groupBox_5);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 8);

        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5->setStretch(0, 49);
        verticalLayout_5->setStretch(1, 30);

        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2->setStretch(0, 55);
        horizontalLayout_2->setStretch(1, 20);

        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(FlashMap);

        QMetaObject::connectSlotsByName(FlashMap);
    } // setupUi

    void retranslateUi(QWidget *FlashMap)
    {
        FlashMap->setWindowTitle(QApplication::translate("FlashMap", "FlashMap", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        groupBox_3->setTitle(QString());
        altitude_label->setText(QString());
        deep_label->setText(QString());
        deepAngle_label->setText(QString());
        altitudeAngle_label->setText(QString());
        groupBox->setTitle(QString());
        planTrack_Btn->setText(QString());
        rF_label->setText(QString());
        sound_label->setText(QString());
        sate_label->setText(QString());
        reSendTrack_Btn->setText(QString());
        clearTrack_Btn->setText(QString());
        displayTrack_Btn->setText(QString());
        setDevice_Btn->setText(QString());
        deletePath_Btn->setText(QString());
        init_Btn->setText(QApplication::translate("FlashMap", "\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        groupBox_7->setTitle(QString());
        roll_label->setText(QString());
        pitch_label->setText(QString());
        yaw_label->setText(QString());
        lat_label->setText(QString());
        lon_label->setText(QString());
        pitchAngle_label->setText(QString());
        groupBox_4->setTitle(QString());
        bizhang_label->setText(QString());
        groupBox_5->setTitle(QString());
        salt_label->setText(QString());
        hum_label->setText(QString());
        inTem_label->setText(QApplication::translate("FlashMap", "      10", Q_NULLPTR));
        outTem_label->setText(QApplication::translate("FlashMap", "      10", Q_NULLPTR));
        humAngle_label->setText(QString());
        saltAngle_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FlashMap: public Ui_FlashMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHMAP_H
