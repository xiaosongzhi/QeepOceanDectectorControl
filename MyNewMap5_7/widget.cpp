#include "widget.h"
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include "data.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //    this->setWindowTitle("QJoystick Test");
    this->hide();
    moveDataTimer = new QTimer;
    displayTimer = new QTimer;
    QVBoxLayout *layout = new QVBoxLayout(this);
    QJoystick *joystick;
    connect(this,SIGNAL(sendBtnState(quint8)),this,SLOT(getBtnState(quint8)));
    connect(displayTimer,SIGNAL(timeout()),this,SLOT(getDisplayData()));
    for (int i = 0; i < 10; i++)
    {
        joystick = new QJoystick(i, this);
        if (joystick->isValid())
        {
            connect(joystick, SIGNAL(JoystickAxisEvent(QJoystickAxisEvent*)), this, SLOT(handleQJoystickAxisEvent(QJoystickAxisEvent*)));
            connect(joystick, SIGNAL(JoystickButtonEvent(QJoystickButtonEvent*)), this, SLOT(handleQJoystickButtonEvent(QJoystickButtonEvent*)));
            connect(moveDataTimer,SIGNAL(timeout()),this,SLOT(sendMoveData()));
            QList<QProgressBar*> bars;
            QList<QLabel*> buttonLabels;
            moveDataTimer->start(50);
            displayTimer->start(100);

            QLabel *label = new QLabel(joystick->name(), this);
            layout->addWidget(label);
            QHBoxLayout *buttonLayout = new QHBoxLayout();
            for (int i = 0; i < joystick->buttonCount(); i++)
            {
                QLabel *label = new QLabel(QString ("%1: <b><font color=grey>U</font></b>").arg(i), this);
                label->setMargin(2);
                buttonLabels.append(label);
                buttonLayout->addWidget(label);
            }
            layout->addItem(buttonLayout);
            for (int i = 0; i < joystick->axisCount(); i++)
            {
                QLabel *label = new QLabel(QString ("Axis %1: ").arg(i), this);
                QProgressBar *bar = new QProgressBar(this);
                bar->setMinimum(-1000);
                bar->setMaximum(1000);
                bar->setValue(0);
                bars.append(bar);
                QHBoxLayout *hlayout = new QHBoxLayout();
                hlayout->addWidget(label);
                hlayout->addWidget(bar);
                layout->addItem(hlayout);
            }

            buttonLabelsMap.insert(i, buttonLabels);
            barsMap.insert(i, bars);

            QTimer *timer = new QTimer(this);
            timer->setInterval(50);
            connect(timer, SIGNAL(timeout()), joystick, SLOT(readJoystick()));
            timer->start();
        }
        else
            delete joystick;
    }
}

void Widget::handleQJoystickAxisEvent(QJoystickAxisEvent* event)
{
    //    int speed = 0,direction = 0,depth = 0,roll = 0;
    uint axis = event->axis();
    QList<QProgressBar*> bars = barsMap.value(event->joystickId());
    Q_ASSERT(axis < bars.count());
    QProgressBar *bar = bars.at(axis);
    bar->setValue(event->value()*1000);

    if(0 == axis)
    {
        direction = (event->value())*100;
    }

    if(2 == axis )
    {
        depth_1 = (event->value())*100;
    }
    if(3 == axis )
    {
        roll = (event->value())*100;
    }
    if(5 == axis)
    {   //速度

        speed = ((event->value())*100 + 100)/(-2);
    }
    if(6 == axis)
    {   //速度
        light =100 - ((event->value())*100 + 100)/2;
    }

}

void Widget::handleQJoystickButtonEvent(QJoystickButtonEvent* event)
{
    //    qDebug("handleQJoystickButtonEvent");
    uint button = event->button();
    QList<QLabel*> buttonLabels = buttonLabelsMap.value(event->joystickId());
    Q_ASSERT(button < buttonLabels.count());
    QLabel *label = buttonLabels.at(button);
    if (event->pressed())
    {
        label->setText(QString ("%1: <b><font color=green>D</font></b>").arg(button));
        getBtnState(button);
        if(button == 23)
            isSendDisplay = true;
    }
    else
    {
        if(button == 23)
            isSendDisplay = false;
        label->setText(QString ("%1: <b><font color=grey>U</font></b>").arg(button));
    }


}
void Widget::sendMoveData()
{

    if(100 == direction)
    {
        nowDirection += 5;

    }
    else if(-100 == direction)
    {
        nowDirection -= 5;
    }
    else if( 0 == direction)
    {
        if(nowDirection > 0)
            nowDirection -= 5;
        else if(nowDirection < 0)
            nowDirection += 5;
    }

    if(nowDirection > 100)
        nowDirection = 100;
    if(nowDirection < -100)
        nowDirection = -100;

    DATA_FREE_MOVE_TypeDef MoveData;
    MoveData.Speed = speed;
    MoveData.heading = nowDirection;
    MoveData.light = 0;
    MoveData.pitch = depth_1;
    MoveData.roll = roll;
    if(keepYaw)
        MoveData.yaw = 1;
    else
        MoveData.yaw = 0;
    quint8 send[sizeof(MoveData)] = {0};
    memcpy(send,&MoveData,sizeof(MoveData));
    //    qDebug()<<(int)MoveData.Speed<<(int)MoveData.heading<<(int)MoveData.light
    //    <<(int)MoveData.pitch<<(int)MoveData.roll<<(int)MoveData.yaw;
    sendMoveDataSlot(MoveData);
}
void Widget::getBtnState(quint8 button)
{
    switch(button)
    {
    case 0:
        if(keepNoraml)
            keepNoraml = false;
        else
            keepNoraml = true;
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        //定航开关
        if(keepYaw)
            keepYaw = false;
        else
            keepYaw = true;
        break;
    default:
        break;
    }
}
//获取演示数据并发送
void Widget::getDisplayData()
{
    Data_SHOW_TypeDef SHOW_Data;

    SHOW_Data.lightStep = light;

    if(isSendDisplay)
        SHOW_Data.start_flag = 1;
    else
        SHOW_Data.start_flag = 0;

    if(speed > 50)
        SHOW_Data.frequence = 1;
    else
        SHOW_Data.frequence = 0;

    if(roll < -10)
        temMode = 1;
    else if(roll > 10)
        temMode = 2;
    else if(roll > -10  && roll < 10 && (!keepNoraml))
        temMode = 3;
    else
    {
        temMode = 0;
    }

    qDebug()<<"mode"<<mode<<"temMode"<<temMode;
    if(temMode != mode)
    {
        mySleep(8000);
        mode = temMode;
    }
    else
    {
        mode = temMode;
    }
    SHOW_Data.mode = mode;
    sendDisplayMoveData(SHOW_Data);

}
Widget::~Widget()
{

}
