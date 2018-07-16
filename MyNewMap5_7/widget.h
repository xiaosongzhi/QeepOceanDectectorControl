#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qjoystick.h"
#include <QProgressBar>
#include <QLabel>
#include <QMap>
#include "dataform.h"
#include <QTimer>
#include <QTime>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    QMap<uint, QList<QProgressBar*> > barsMap;
    QMap<uint, QList<QLabel*> > buttonLabelsMap;
    QTimer *moveDataTimer;
    //展示模块********/
    QTimer *displayTimer;
    bool isSendDisplay = false;
    //**********/
    bool keepYaw = false;
    bool keepNoraml = true;
    short roll = 0,depth_1 = 0,direction = 0,nowDirection = 0,speed = 0,light;
    quint8 temMode = 0,mode = 0;
private slots:
    void handleQJoystickAxisEvent(QJoystickAxisEvent *event);
    void handleQJoystickButtonEvent(QJoystickButtonEvent *event);
    void sendMoveData();
    void getBtnState(quint8);
    void getDisplayData();
signals:
    void sendBtnState(quint8);

    void sendMoveDataSlot(DATA_FREE_MOVE_TypeDef);
    void sendDisplayMoveData(Data_SHOW_TypeDef);
};

#endif // WIDGET_H
