#include "myserialport.h"
#include "ui_myserialport.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include "dataform.h"
#include "data.h"
#define DATAHEAD 0xAA
#define DATATAIL 0xBB
#define DISCONNECTTIME 200  //判断是否失联
#define RFCYCLE 500           //任务池刷新时间
#define SOUNDCYCLE 500


MySerialPort::MySerialPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySerialPort)
{
    ui->setupUi(this);
    rfSerialPort = new QSerialPort;
    soundSerialPort = new QSerialPort;
    sateSerialPort = new QSerialPort;
    myUdpSocket = new QUdpSocket;
    myJoyStick = new Widget(this);

    rfTimer = new QTimer;
    soundTimer = new QTimer;
    sateTimer = new QTimer;

    rfCylceTimer = new QTimer;
    soundCycleTimer = new QTimer;
    //读取串口数据
    connect(rfSerialPort,SIGNAL(readyRead()),this,SLOT(readRFDataFromSerialPort()));
    connect(soundSerialPort,SIGNAL(readyRead()),this,SLOT(readSoundDataFromSerialPort()));
    connect(sateSerialPort,SIGNAL(readyRead()),this,SLOT(readSateDataFromSerialPort()));
    //获取状态信息
    connect(rfTimer,SIGNAL(timeout()),this,SLOT(getRfStateData()));
    connect(soundTimer,SIGNAL(timeout()),this,SLOT(getSoundStateData()));
    //任务池触发周期
    connect(rfCylceTimer,SIGNAL(timeout()),this,SLOT(rfCmdPool()));
    connect(soundCycleTimer,SIGNAL(timeout()),this,SLOT(soundCmdPool()));

    //外部信号
    connect(myJoyStick,SIGNAL(sendMoveDataSlot(DATA_FREE_MOVE_TypeDef)),this,SLOT(receiveControlData(DATA_FREE_MOVE_TypeDef)));
    connect(myJoyStick,SIGNAL(sendDisplayMoveData(Data_SHOW_TypeDef)),this,SLOT(receiveDisplayData(Data_SHOW_TypeDef)));
    deciveInit();
}

MySerialPort::~MySerialPort()
{
    delete ui;
    delete rfSerialPort;
    delete soundSerialPort;
    delete sateSerialPort;
    delete myUdpSocket;

    delete rfTimer;
    delete soundTimer;
    delete sateTimer;
}

void MySerialPort::deciveInit()
{
    on_rfFlush_Btn_clicked();
    on_soundFlush_Btn_clicked();
    on_sateFlush_Btn_clicked();
}
void MySerialPort::on_rfOpen_Btn_clicked()
{
    rfSerialPort->setPortName(ui->rfSerialPort_ComboBox->currentText());
    if(ui->rfOpen_Btn->text() == "打开")
    {
        if(rfSerialPort->open(QIODevice::ReadWrite))
        {
            rfSerialPort->setBaudRate(ui->rfBaud_ComboBox->currentText().toInt());
            rfSerialPort->setDataBits(QSerialPort::Data8);
            rfSerialPort->setParity(QSerialPort::NoParity);
            rfSerialPort->setStopBits(QSerialPort::OneStop);
            rfSerialPort->setFlowControl(QSerialPort::NoFlowControl);
            ui->rfOpen_Btn->setText("关闭");
            rfTimer->start(DISCONNECTTIME);
            rfCylceTimer->start(RFCYCLE);
        }
        else
        {
            QMessageBox::warning(NULL,"WARNING","串口打开失败",QMessageBox::Retry);
            return;
        }
    }
    else if(ui->rfOpen_Btn->text() == "关闭")
    {
        rfSerialPort->close();
        ui->rfOpen_Btn->setText("打开");
        rfCylceTimer->stop();
        rfTimer->stop();
    }
}

void MySerialPort::on_rfFlush_Btn_clicked()
{
    QSerialPortInfo m_SerialPortInfo;
    QStringList serialPortNames;
    foreach(m_SerialPortInfo,QSerialPortInfo::availablePorts())
    {
        QSerialPort serialport;
        serialport.setPort(m_SerialPortInfo);

        if(serialport.open(QIODevice::ReadWrite))
        {
            serialPortNames.append(m_SerialPortInfo.portName());
            serialport.close();
        }
        ui->rfOpen_Btn->setText("打开");
    }
    if(serialPortNames.isEmpty())
    {
        QMessageBox::warning(NULL,"WARNING","无可用串口",QMessageBox::Retry);
        return;
    }
    ui->rfSerialPort_ComboBox->clear();
    ui->rfSerialPort_ComboBox->addItems(serialPortNames);
}

void MySerialPort::on_soundOpen_Btn_clicked()
{
    soundSerialPort->setPortName(ui->soundSerialPort_Combox->currentText());
    if(ui->soundOpen_Btn->text() == "打开")
    {
        if(soundSerialPort->open(QIODevice::ReadWrite))
        {
            soundSerialPort->setBaudRate(ui->soundBaud_Combox->currentText().toInt());
            soundSerialPort->setDataBits(QSerialPort::Data8);
            soundSerialPort->setParity(QSerialPort::NoParity);
            soundSerialPort->setStopBits(QSerialPort::OneStop);
            soundSerialPort->setFlowControl(QSerialPort::NoFlowControl);
            ui->soundOpen_Btn->setText("关闭");
            soundTimer->start(DISCONNECTTIME);
            soundCycleTimer->start(SOUNDCYCLE);
        }
        else
        {
            QMessageBox::warning(NULL,"WARNING","串口打开失败",QMessageBox::Retry);
            return;
        }
    }
    else if(ui->soundOpen_Btn->text() == "关闭")
    {
        soundSerialPort->close();
        ui->soundOpen_Btn->setText("打开");
        soundCycleTimer->stop();
        soundTimer->stop();
    }
}

void MySerialPort::on_soundFlush_Btn_clicked()
{
    QSerialPortInfo m_SerialPortInfo;
    QStringList serialPortNames;
    foreach(m_SerialPortInfo,QSerialPortInfo::availablePorts())
    {
        QSerialPort serialport;
        serialport.setPort(m_SerialPortInfo);

        if(serialport.open(QIODevice::ReadWrite))
        {
            serialPortNames.append(m_SerialPortInfo.portName());
            serialport.close();
            ui->soundOpen_Btn->setText("打开");
        }
    }
    if(serialPortNames.isEmpty())
    {
        QMessageBox::warning(NULL,"WARNING","无可用串口",QMessageBox::Retry);
        return;
    }
    ui->soundSerialPort_Combox->clear();
    ui->soundSerialPort_Combox->addItems(serialPortNames);
}

void MySerialPort::on_sateOpen_Btn_clicked()
{
    sateSerialPort->setPortName(ui->sateSerialPort_Combox->currentText());
    if(ui->sateOpen_Btn->text() == "打开")
    {
        if(sateSerialPort->open(QIODevice::ReadWrite))
        {
            sateSerialPort->setBaudRate(ui->sateBaud_Combox->currentText().toInt());
            sateSerialPort->setDataBits(QSerialPort::Data8);
            sateSerialPort->setParity(QSerialPort::NoParity);
            sateSerialPort->setStopBits(QSerialPort::OneStop);
            sateSerialPort->setFlowControl(QSerialPort::NoFlowControl);
            ui->sateOpen_Btn->setText("关闭");
            sateTimer->start(DISCONNECTTIME);
        }
        else
        {
            QMessageBox::warning(NULL,"WARNING","串口打开失败",QMessageBox::Retry);
            return;
        }
    }
    else if(ui->sateOpen_Btn->text() == "关闭")
    {
        sateSerialPort->close();
        ui->sateOpen_Btn->setText("打开");
        sateTimer->stop();
    }
}

void MySerialPort::on_sateFlush_Btn_clicked()
{
    QSerialPortInfo m_SerialPortInfo;
    QStringList serialPortNames;
    foreach(m_SerialPortInfo,QSerialPortInfo::availablePorts())
    {
        QSerialPort serialport;
        serialport.setPort(m_SerialPortInfo);

        if(serialport.open(QIODevice::ReadWrite))
        {
            serialPortNames.append(m_SerialPortInfo.portName());
            serialport.close();
            ui->sateOpen_Btn->setText("打开");
        }
    }
    if(serialPortNames.isEmpty())
    {
        QMessageBox::warning(NULL,"WARNING","无可用串口",QMessageBox::Retry);
        return;
    }
    ui->sateSerialPort_Combox->clear();
    ui->sateSerialPort_Combox->addItems(serialPortNames);
}
//串口通信
static QByteArray rfBuffer;
void MySerialPort::readRFDataFromSerialPort()
{
    QByteArray receiveData;
    receiveData = rfSerialPort->readAll();
    rfBuffer.append(receiveData);

    if(rfBuffer[0] != (char)0xaa)
    {
        rfBuffer.remove(0,1);
        if(rfBuffer.isEmpty())
            return;
    }
    else
    {
        if(rfBuffer.length() >= rfBuffer[1])
        {
            if(rfBuffer[rfBuffer[1] -1] == (char)0xbb  && rfBuffer[3] == (char)RFID)
            {
                DATA_POINTMOVE_START PointNum;
                Data_STATE_TypeDef State;
                char *ch;
                ch = rfBuffer.data();
                qint8 cmd = (qint8)rfBuffer[4];
                memcpy(&PointNum,ch+5,sizeof(PointNum));
                memcpy(&State,ch+5,sizeof(State));
                emit sendArrayToBrower(rfBuffer.toHex());
                switch(cmd)
                {
                //点对点控制反馈
                //(1)透传前的准备
                case CMD_POINTMOVE_START:
                    //下位机做好准备
                    if(0 == PointNum.GPS_Point_num)
                    {
                        sendPointsDataToSlave();    //发送GPS数据包
                        sendPathEndCmd();           //告知下位机总点数进行校验
                    }
                    else if(pathPoints.length() == PointNum.GPS_Point_num)
                    {
                        //点数校验成功，发送上浮下潜数据
                        isSendingpath = true;//打开串口管制
                        isPathTriggle = true;
                        QMessageBox::warning(NULL,"WARNING","路径发送成功",QMessageBox::Ok);
                    }
                    else if(pathPoints.length() != PointNum.GPS_Point_num)
                    {
                        //校验未成功,重新来过
//                        receivePointsData(pathPoints,pathDeep,pathPointsNum,pathDownOrUpFlag,pathTime);
                    }
                    break;
                case CMD_POINTMOVE:
                    //开始执行路径规划
                    isPathTriggle = false;
                    break;
                    //状态恢复
                case CMD_STATE:
                    isRfStateTriggle = false;
                    emit sendStateToUI(State);
                    break;
                    //调试状态回馈
                case CMD_DEBUG:
                    break;
                default:
                    break;
                }
                rfBuffer.remove(0,rfBuffer[1]);
            }
            else
            {
                rfBuffer.remove(0,1);
            }
        }
        else
        {
            return;
        }

    }
}
void MySerialPort::sendDataThroughRF(qint8 *message,int num,qint8 cmd)
{

    quint8 send[num + 6] = {0};
    send[0] = DATAHEAD;
    send[1] = sizeof(send);
    send[2] = RFID;
    send[3] = RFID;
    send[4] = cmd;
    memcpy(send+5,message,num);
    send[num+5] = DATATAIL;

    if(rfSerialPort->isOpen())
        rfSerialPort->write((const char*)send,sizeof(send));
    else
    {
        QMessageBox::warning(NULL,"WARNING","串口未打开",QMessageBox::Retry);
        return;
    }
}
//水声
static QByteArray soundBuffer;
void MySerialPort::readSoundDataFromSerialPort()
{
    QByteArray receiveData;
    receiveData = rfSerialPort->readAll();
    soundBuffer.append(receiveData);
    if(soundBuffer[0] != (char)0xAA)
    {
        soundBuffer.remove(0,1);
        if(soundBuffer.isEmpty())
            return;
    }
    else
    {
        if(rfBuffer.length() >= soundBuffer[1])
        {
            if(soundBuffer[soundBuffer[1] -1] == (char)0xBB  && soundBuffer[3] == (char)RFID)
            {

                Data_STATE_TypeDef State;
                char *ch;
                ch = soundBuffer.data();
                qint8 cmd = soundBuffer[4];
                memcpy(&State,ch + 5,sizeof(State));
                switch(cmd)
                {
                    //状态恢复
                case CMD_STATE:
                    sendStateToUI(State);
                    isRFOk = true;
                    break;
                    //调试状态回馈
                case CMD_DEBUG:
                    break;
                default:
                    break;
                }
                soundBuffer.remove(0,soundBuffer[1]);
            }
            else
            {
                soundBuffer.remove(0,1);
            }
        }
        else
        {
            return;
        }

    }
}
void MySerialPort::sendDataThroughSound(qint8 *message,int num,qint8 cmd)
{
    qint8 send[num + 6] = {0};
    send[0] = DATAHEAD;
    send[1] = sizeof(send);
    send[2] = SONARID;
    send[3] = SONARID;
    send[4] = cmd;
    memcpy(send+5,message,num);
    send[num+5] = DATATAIL;
    if(soundSerialPort->isOpen())
        soundSerialPort->write((const char*)send,sizeof(send));
    else
    {
        QMessageBox::warning(NULL,"WARNING","串口未打开",QMessageBox::Retry);
        return;
    }
}
//卫星
static QByteArray sateBuffer;
void MySerialPort::readSateDataFromSerialPort()
{
    QByteArray receiveData;
    receiveData = rfSerialPort->readAll();
    sateBuffer.append(receiveData);
    if(sateBuffer[0] != (char)0xAA)
    {
        sateBuffer.remove(0,1);
        if(sateBuffer.isEmpty())
            return;
    }
    else
    {
        if(rfBuffer.length() >= sateBuffer[1])
        {
            if(sateBuffer[sateBuffer[1] -1] == (char)0xBB  && sateBuffer[3] == (char)RFID)
            {

                Data_STATE_TypeDef State;
                char *ch;
                ch = sateBuffer.data();
                qint8 cmd = sateBuffer[4];
                memcpy(&State,ch + 5,sizeof(State));
                switch(cmd)
                {
                case CMD_STATE:
                    sendStateToUI(State);
                    isRFOk = true;
                    break;
                    //调试状态回馈
                case CMD_DEBUG:
                    break;
                default:
                    break;
                }
                sateBuffer.remove(0,sateBuffer[1]);
            }
            else
            {
                sateBuffer.remove(0,1);
            }
        }
        else
        {
            return;
        }

    }
}
void MySerialPort::sendDataThroughSate(qint8 *message,int num,qint8 cmd)
{
    qint8 send[num + 6] = {0};
    send[0] = DATAHEAD;
    send[1] = sizeof(send);
    send[2] = SATCOMID;
    send[3] = SATCOMID;
    send[4] = cmd;
    memcpy(send+5,message,num);
    send[num+5] = DATATAIL;
    if(sateSerialPort->isOpen())
        sateSerialPort->write((const char*)send,sizeof(send));
    else
    {
        QMessageBox::warning(NULL,"WARNING","串口未打开",QMessageBox::Retry);
        return;
    }
}
//udp通讯
void MySerialPort::on_udpConnect_Btn_clicked()
{
    myUdpSocket->abort();
    myUdpSocket->bind(QHostAddress(ui->hostIP_Combox->currentText()),ui->hostPort_Combox->currentText().toInt());
    connect(myUdpSocket,SIGNAL(readyRead()),this,SLOT(receiveMessageFromSlave()));
}

void MySerialPort::on_disConnect_Btn_clicked()
{
    myUdpSocket->abort();
    myUdpSocket->close();
    myUdpSocket->disconnect();
}
//confirm slave  udp IP and Port
void MySerialPort::on_confirm_Btn_clicked()
{
    slaveIp = ui->slaveIP_Combox->currentText();
    slavePort = ui->slavePort_Combox->currentText().toInt();
}
void MySerialPort::sendMessageToSlave(qint8 *message,int num)
{
    myUdpSocket->writeDatagram((char*)message,num,QHostAddress(slaveIp),slavePort);
}

void MySerialPort::receiveMessageFromSlave()
{
    QByteArray myBuff;

    while(myUdpSocket->hasPendingDatagrams())
    {
        QByteArray receiveData;
        receiveData.resize(myUdpSocket->pendingDatagramSize());
        myUdpSocket->readDatagram(receiveData.data(),receiveData.size());

        myBuff.append(receiveData);

        if(myBuff[0] != (char)DATAHEAD)
        {
            myBuff.remove(0,1);
            if(myBuff.isEmpty())
                return;
        }
        else
        {
            if(myBuff.length() >= myBuff[1])
            {
                Data_STATE_TypeDef State;
                char *ch;
                ch = myBuff.data();
                memcpy(&State,ch + 5,sizeof(State));
                //开始解析 start analyze
                if(myBuff[myBuff[1]-1] ==(char)DATATAIL  && myBuff[3] == (char)UDPID)
                {
                    char cmd = myBuff[4];

                    switch(cmd)
                    {
                    case CMD_STATE:
                        sendStateToUI(State);
                        isSateOk = true;
                        break;
                    case CMD_DEBUG:
                        break;
                    default:
                        break;
                    }
                    myBuff.remove(0,myBuff[1]);
                }
                else
                {
                    myBuff.remove(0,1);
                }
            }
            else
            {
                return;
            }

        }
    }
}
//调试接口
void MySerialPort::on_debug_Btn_clicked()
{
    Data_DEBUG_TypeDef DebugData;
    DebugData.PID[0] = ui->lineEdit_1->text().toFloat();
    DebugData.PID[1] = ui->lineEdit_2->text().toFloat();
    DebugData.PID[2] = ui->lineEdit_3->text().toFloat();
}
/***********UDP   END************/

/********路径规划模块***********/
void MySerialPort::sendPathStartCmd()
{
    DATA_POINTMOVE_START StartPathCmd;
    StartPathCmd.GPS_Point_num = 0;

    qint8 send[sizeof(StartPathCmd)] = {0};
    memcpy(send,&StartPathCmd,sizeof(StartPathCmd));
    sendDataThroughRF(send,sizeof(send),CMD_POINTMOVE_START);

}
void MySerialPort::sendPathEndCmd()
{
    DATA_POINTMOVE_START StartPathCmd;
    StartPathCmd.GPS_Point_num = pathPoints.length();

    qint8 send[sizeof(StartPathCmd)] = {0};
    memcpy(send,&StartPathCmd,sizeof(StartPathCmd));
    sendDataThroughRF(send,sizeof(send),CMD_POINTMOVE_START);

    //发完此项数据后开始计时，如果5s后还没收到回复则继续发送start

}
void MySerialPort::sendPathCmd()
{
    Data_POINT_MOVE_TypeDef Para;
    Para.deep = pathDeep;
    Para.DownTime = pathTime;
    Para.UporDown = pathDownOrUpFlag;

    qint8 send[sizeof(Para)] = {0};
    memcpy(send,&Para,sizeof(Para));
    sendDataThroughRF(send,sizeof(send),CMD_POINTMOVE);

}
//发送路径的大量数据
void MySerialPort::sendPointsDataToSlave()
{
    isSendingpath = true;
    qint8 send[pathPoints.size()*8] = {0};
    struct Point
    {
        int longitude;
        int latitude;
    }PathPoint;

    for(int i = 0;i < pathPoints.size();i++)
    {
        PathPoint.longitude = (pathPoints.at(i).x())*100000;
        PathPoint.latitude = (pathPoints.at(i).y())*100000;

        memcpy(send+i*(sizeof(PathPoint)),&PathPoint,sizeof(PathPoint));
    }

    rfSerialPort->write((const char*)send,sizeof(send));
    //开启定时器计时，判断5秒内是否收到回复----待定
}

/*************外界触发的控制指令****************/
//1 路径规划函数   [1]
void MySerialPort::receivePointsData(QList <QPointF> PathPoints,float deep,int num,quint8 flag,int time)
{
    isSendingpath = true;//实时串口管制
    pathPoints = PathPoints;
    pathDeep = deep;
    pathPointsNum = num;
    pathDownOrUpFlag = flag;
    pathTime = time;
    sendPathStartCmd();//让下位机做好接受准备
}

//2 获取运动数据    一直发送
void MySerialPort::receiveControlData(DATA_FREE_MOVE_TypeDef Data)
{
    MOVEDATA = Data;
}
//3获取演示数据
void receiveDisplayData(Data_SHOW_TypeDef Display_Data)
{

}
//4 触发返航指令
void MySerialPort::receiveComebackCmd()
{
    isRfCombackTriggle = true;
}
// 5、判断是否失联以及获取状态数据  该两个函数有定时器触发
void MySerialPort::getRfStateData()
{
    isRfStateTriggle = true;//接收到数据后置0
}
void MySerialPort::getSoundStateData()
{
    isSoundStateTriggle = true;
}
//获取演示指令
void MySerialPort::receiveDisplayData(Data_SHOW_TypeDef DataShow)
{
    isSHowDataTriggle = true;
    DATASHOW = DataShow;
}
/***************end*****************/



/*******向下位机发送控制指令***********/
// 1、实时运动控制数据
void MySerialPort::sendMoveControlCmd(qint8 mode)
{
    qint8 send[sizeof(MOVEDATA)] = {0};
    memcpy(send,&MOVEDATA,sizeof(MOVEDATA));
    switch(mode){
    case 0:
        sendDataThroughRF(send,sizeof(send),CMD_FREEMOVE);
        break;
    case 1:
        sendDataThroughSound(send,sizeof(send),CMD_FREEMOVE);
        break;
    default:
        break;
    }
}

// 3、返航指令
void MySerialPort::sendComeBackCmd(qint8 mode)
{
    qint8 send[1] = {0x01};

    switch(mode){
    case 0:
        sendDataThroughRF(send,sizeof(send),CMD_COMEBACK);
        break;
    case 1:
        sendDataThroughSound(send,sizeof(send),CMD_COMEBACK);
        break;
    case 2:
        sendDataThroughSate(send,sizeof(send),CMD_COMEBACK);
        break;
    default:
        break;
    }
}
// 4、发送路径----发送路径并不放在任务池中，在发送路径时其他命令暂时发送，直到路径规划成功
/***********end*****************/


/**********任务池周期发送数据************/
void MySerialPort::rfCmdPool()
{
    if(!isSendingpath)//没有传送规路径
    {

        if(isRfCombackTriggle)
        {
            sendComeBackCmd(0);
        }

        //发送演示控制数据
        else if(isSHowDataTriggle)
        {
            isSHowDataTriggle = false;
            qint8 ch[sizeof(Data_SHOW_TypeDef)] = {0};
            memcpy(ch,&DATASHOW,sizeof(Data_SHOW_TypeDef));
            sendDataThroughRF(ch,sizeof(ch),CMD_SHOW);
        }
        //获取传感器数据
        else if(isRfStateTriggle && isSenserTriggle)
        {
            qDebug()<<"get State";
            qint8 ch[1] = {0x01};
            sendDataThroughRF(ch,1,CMD_STATE);//其他都是调用函数，此处直接使用
        }
        //控制指令
        else if(isSpeedTriggle )
        {
//            sendMoveControlCmd(0);
        }
    }
}
//通过水声发送数据
void MySerialPort::soundCmdPool()
{
    if(isSoundCombackTriggle)
    {
        sendComeBackCmd(1);
    }
    //获取传感器数据
    else if(isSoundStateTriggle && isSenserTriggle)
    {
        qint8 ch[1] = {0x01};
        sendDataThroughSound(ch,1,CMD_STATE);
    }
    //控制指令
    else if(isSpeedTriggle)
    {
        sendMoveControlCmd(1);
    }
}

void MySerialPort::on_flushSpeed_CheckBox_clicked()
{
    if(ui->flushSpeed_CheckBox->isChecked())
        isSpeedTriggle = true;
    else
        isSpeedTriggle = false;

}

void MySerialPort::on_flushSenser_CheckBox_clicked()
{
   if(ui->flushSenser_CheckBox->isChecked())
       isSenserTriggle = true;
   else
       isSenserTriggle = false;
}


void MySerialPort::on_pushButton_clicked()
{
    if(rfSerialPort->isOpen())
    sendPointsDataToSlave();
}
