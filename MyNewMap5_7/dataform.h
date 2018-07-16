#ifndef __DATAFORM_H
#define __DATAFORM_H
#include "stdio.h"	
#include "string.h"
#include <QWidget>

#define PackageMaxLength 256
#define PackageMinLength 7
#define PackageHead 0xAA
#define PackageTail 0xBB
#define MyID 0x00      //自身ID为0x01
#define SLAVEID 0x01 
#define SATCOMID 0x02
#define SONARID 0x03
#define RFID 0x04
#define UDPID 0x05

typedef enum 
{
    DISABLE = 0,
    ENABLE
}FunctionalState;
typedef struct
{
    quint8 Head;
    quint8 PackageLength;
    quint8 SendID;
    quint8 ReceivedID;
    quint8 Cmd;
    quint8 *Code;
    quint8 Tail;
}DataPackage_TypeDef;

typedef enum 
{
    CMD_FREEMOVE=0,      //自由运动控制
    CMD_POINTMOVE_START, //开始和结束点对点控制命令
    CMD_POINTMOVE,       //点接受完成后发送控制指令
    CMD_STATE,           //设备状态信息
    CMD_SOUNDCONTROL,    //水听器采集数据控制
    CMD_SOUNDFSACK,		 //水听器数据回复
    CMD_DOWNLOADCONTROL, //程序加载控制
    CMD_DEBUG,			 //debug指令
    CMD_SLAVE_DATA,      //从板shuju
    CMD_COMEBACK,         //返航指令
    CMD_STOP,           //emergency  stop
    CMD_CALIBRATION_IMU,    //init  IMU  direction
    CMD_SHOW                //display in shanghai
}TrainCmd;

//////////////////自由控制时 三种方式 定深，定航，定侧倾的开启；翅膀运动的是否开启////////////////////////
typedef struct
{
    quint8 Mode;  //0-only wing   1-only enrage   2-all
    short int  Speed;	   //速度0-100
    short int  heading;    //方向-100 - 100
    short int  pitch;	   //深度0 - 40
    short int  roll;       //侧倾运动控制 默认0度
    short int  yaw;        //ding xiang 0 1
    short int  light;      // control  light 1-100

}DATA_FREE_MOVE_TypeDef;
//**yan   shi*****/
typedef struct
{
    quint8 start_flag;
    quint8 mode;
    quint8 frequence;
    short lightStep;
}Data_SHOW_TypeDef;
//////////////////////////////////////////GPS点对点游动/////////////////////////////////
//GPS点坐标透传命令（当GPS_Point_num为0时 开始透传，不为零时透传结束，数量为GPS的点数）
//当发开始命令后 回复相同的命令后 方可透传 ，透传完成后 发送相同的命令后（如果值为1不需要重复发送，为0需要重复发送）
typedef struct
{
    int GPS_Point_num;
}DATA_POINTMOVE_START;
//接受控制指令
typedef struct
{
    float deep;       //深度值（水面控制，水下控制）
    quint8 UporDown;  //运行完最后一个点后上浮还是下潜 （0 下潜，1上浮）
    int DownTime;     //运行完最后一个点后下潜的话，下潜多长时间（单位S，）
}Data_POINT_MOVE_TypeDef;
///////////////////////////////////状态发送触发////////////////////////////////////
//上位机发送至下位机命令不变
typedef struct
{
    quint8 state;  //为1  发送状态
}DATA_POINT_STATE;
//下位机对上位机的回复
typedef struct
{
    short   speed;
    short    Power;       //电量,0-5
    float   NowDeepth;       //深度
    qint16  TempIn;       //舱内温度
    qint16  HumIn;		  //舱内湿度
    float   TempOut;    //舱外温度
    float   salt;        //盐度
    float   seahigh;      //高度
    short    Roll;         //roll角度
    short    pitch;	      //pitch角度
    short int Yaw;      //偏航角 0-360
    int gps[2];         //GPS坐标 经度 纬度
    quint8 satcom_state;    //卫星通信状态
    quint8 sonar_state;     //水声通信状态
    quint8 rf_state;        //数传通信状态
    int left_avoid;
    int right_avoid;
}Data_STATE_TypeDef;
///////////////////////////////程序下载控制指令/////////////////////////////////

typedef enum //程序加载控制指令
{
    Boot_Reset=0,
    Boot_Download
}BootloaderCmd;
//先发送Boot_Reset命令，让程序复位， 复位成功后发送相同的命令 开始串口透传，透传完成后发送Boot_Download
// 数据为程序字节数 待校验成功后 回复相同指令（）
typedef struct
{
    quint8 Cmd;     //设备程序加载控制
    int Ask;     //对应命令回复
}Data_DOWNLOADCONTROL_TypeDef;
//////////////////////////////灯的控制/////////////////////
typedef struct
{
    quint8 lightpower;    //灯的控制0-100
}Data_LIGHTCONTROL_TypeDef;
//////////////////////////////////////水听器的控制////////////////////////////
typedef struct
{
    unsigned char EnOrDisEN;	//ENABLE	DISABLE  //水听器数据采集控制
    qint8 ReadAll; 				//ENABLE	DISABLE  开启结束读取命令
    qint8 GetFS;	 				//水听器频谱数据控制 开启触发一次
}Data_SOUNDCONTROL_TypeDef;
typedef struct // 水听器的数据回复
{
    unsigned char FScode[256];//
}Data_SOUNDFSACK_TypeDef;
/////////////////////////////////debug指令的命令控制
typedef struct  
{
    float PID[3];
}Data_DEBUG_TypeDef;

//////////////////////////////////小板的通信//////////////////////////////
typedef struct 
{
    float latitude;   // 纬度
    float longitude;  //精度
    float GPS_x;
    float GPS_y;
    qint8 posslnum;      //卫星个数
}Data_SLAVE_GPS_TypeDef;

typedef struct 
{
    float salt;
    float salt_temp;
}Data_SLAVE_SALT_TypeDef;

typedef struct 
{
    float seahigh;
}Data_SLAVE_HIGH_TypeDef;


typedef struct
{
    qint8 uart_event_tc; //发送完成事件
    qint8 uart_event_idle; //接收完成事件
}Uart_Event;

#endif


