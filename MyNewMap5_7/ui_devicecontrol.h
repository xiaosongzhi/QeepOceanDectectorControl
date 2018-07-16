/********************************************************************************
** Form generated from reading UI file 'devicecontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONTROL_H
#define UI_DEVICECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceControl
{
public:

    void setupUi(QWidget *DeviceControl)
    {
        if (DeviceControl->objectName().isEmpty())
            DeviceControl->setObjectName(QStringLiteral("DeviceControl"));
        DeviceControl->resize(400, 300);

        retranslateUi(DeviceControl);

        QMetaObject::connectSlotsByName(DeviceControl);
    } // setupUi

    void retranslateUi(QWidget *DeviceControl)
    {
        DeviceControl->setWindowTitle(QApplication::translate("DeviceControl", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeviceControl: public Ui_DeviceControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONTROL_H
