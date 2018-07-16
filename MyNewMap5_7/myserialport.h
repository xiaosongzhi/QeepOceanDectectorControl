#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QUdpSocket>
#include <QTimer>
#include <QTime>
#include "dataform.h"
#include "widget.h"

namespace Ui {
class MySerialPort;
}

class MySerialPort : public QWidget
{
    Q_OBJECT

public:
    explicit MySerialPort(QWidget *parent = 0);
    ~MySerialPort();

    void sendMoveControlCmd(qint8);

    void sendComeBackCmd(qint8);
    void sendPathStartCmd();
    void sendPointsDataToSlave();
    void sendPathEndCmd();
    void sendPathCmd();
    void sendMessageToSlave(qint8 *,int);
    void deciveInit();

    void sendDataThroughRF(qint8 *message,int num,qint8 cmd);
    void sendDataThroughSound(qint8 *message,int num,qint8 cmd);
    void sendDataThroughSate(qint8 *message,int num,qint8 cmd);

signals:
    void sendStateToUI(Data_STATE_TypeDef);
    void sendArrayToBrower(QByteArray);
private slots:
    void on_rfOpen_Btn_clicked();

    void on_rfFlush_Btn_clicked();

    void on_soundOpen_Btn_clicked();

    void on_soundFlush_Btn_clicked();

    void on_sateOpen_Btn_clicked();

    void on_sateFlush_Btn_clicked();

    void on_udpConnect_Btn_clicked();

    void on_disConnect_Btn_clicked();

    void on_confirm_Btn_clicked();

    void receiveMessageFromSlave();

    void readRFDataFromSerialPort();

    void readSoundDataFromSerialPort();

    void readSateDataFromSerialPort();

    void getRfStateData();

    void getSoundStateData();

    void rfCmdPool();

    void soundCmdPool();

    void on_flushSpeed_CheckBox_clicked();

    void on_flushSenser_CheckBox_clicked();

    void on_debug_Btn_clicked();

    void on_pushButton_clicked();

public slots:

    void receivePointsData(QList <QPointF>,float,int,quint8,int);
    void receiveControlData(DATA_FREE_MOVE_TypeDef);
    void receiveComebackCmd();

    void receiveDisplayData(Data_SHOW_TypeDef);

private:
    Ui::MySerialPort *ui;

    QSerialPort *rfSerialPort;
    QSerialPort *soundSerialPort;
    QSerialPort *sateSerialPort;
    QUdpSocket *myUdpSocket;
    Widget *myJoyStick;
    QString slaveIp;

    DATA_FREE_MOVE_TypeDef MOVEDATA;
    Data_SHOW_TypeDef DATASHOW;

    int slavePort;

    bool isRFOk = false;
    bool isSoundOk = false;
    bool isSateOk = false;
    bool isNetOk = false;

    QTimer *rfTimer;
    QTimer *soundTimer;
    QTimer *sateTimer;
    QTimer *netTimer;

    QTimer *rfCylceTimer;
    QTimer *soundCycleTimer;

    short speed;
    short heading;
    short pitch;
    short roll;
    quint8 lightStep;

    bool isSHowDataTriggle = false;

    //判断是否触发
    bool isRfCombackTriggle = false;
    bool isRfPathCmdTirggle = false;
    bool isRfStateTriggle = false;

    bool isSpeedTriggle = false;
    bool isSenserTriggle = false;

    bool isSoundLightTriggle = false;
    bool isSoundCombackTriggle = false;
    bool isSoundStateTriggle = false;

    //路径规划数据
    bool isPathTriggle = false;//上浮下潜数据
    bool isSendingpath = false;

    QList<QPointF> pathPoints;
    float   pathDeep;
    int     pathPointsNum;
    quint8  pathDownOrUpFlag;
    int     pathTime;

};

#endif // MYSERIALPORT_H
