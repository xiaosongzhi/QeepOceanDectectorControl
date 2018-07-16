#ifndef __DATAFORM_H
#define __DATAFORM_H
#include "stdio.h"	
#include "string.h"
#include <QWidget>

#define PackageMaxLength 256
#define PackageMinLength 7
#define PackageHead 0xAA
#define PackageTail 0xBB
#define MyID 0x00      //����IDΪ0x01
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
    CMD_FREEMOVE=0,      //�����˶�����
    CMD_POINTMOVE_START, //��ʼ�ͽ�����Ե��������
    CMD_POINTMOVE,       //�������ɺ��Ϳ���ָ��
    CMD_STATE,           //�豸״̬��Ϣ
    CMD_SOUNDCONTROL,    //ˮ�����ɼ����ݿ���
    CMD_SOUNDFSACK,		 //ˮ�������ݻظ�
    CMD_DOWNLOADCONTROL, //������ؿ���
    CMD_DEBUG,			 //debugָ��
    CMD_SLAVE_DATA,      //�Ӱ�shuju
    CMD_COMEBACK,         //����ָ��
    CMD_STOP,           //emergency  stop
    CMD_CALIBRATION_IMU,    //init  IMU  direction
    CMD_SHOW                //display in shanghai
}TrainCmd;

//////////////////���ɿ���ʱ ���ַ�ʽ ���������������Ŀ���������˶����Ƿ���////////////////////////
typedef struct
{
    quint8 Mode;  //0-only wing   1-only enrage   2-all
    short int  Speed;	   //�ٶ�0-100
    short int  heading;    //����-100 - 100
    short int  pitch;	   //���0 - 40
    short int  roll;       //�����˶����� Ĭ��0��
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
//////////////////////////////////////////GPS��Ե��ζ�/////////////////////////////////
//GPS������͸�������GPS_Point_numΪ0ʱ ��ʼ͸������Ϊ��ʱ͸������������ΪGPS�ĵ�����
//������ʼ����� �ظ���ͬ������� ����͸�� ��͸����ɺ� ������ͬ����������ֵΪ1����Ҫ�ظ����ͣ�Ϊ0��Ҫ�ظ����ͣ�
typedef struct
{
    int GPS_Point_num;
}DATA_POINTMOVE_START;
//���ܿ���ָ��
typedef struct
{
    float deep;       //���ֵ��ˮ����ƣ�ˮ�¿��ƣ�
    quint8 UporDown;  //���������һ������ϸ�������Ǳ ��0 ��Ǳ��1�ϸ���
    int DownTime;     //���������һ�������Ǳ�Ļ�����Ǳ�೤ʱ�䣨��λS����
}Data_POINT_MOVE_TypeDef;
///////////////////////////////////״̬���ʹ���////////////////////////////////////
//��λ����������λ�������
typedef struct
{
    quint8 state;  //Ϊ1  ����״̬
}DATA_POINT_STATE;
//��λ������λ���Ļظ�
typedef struct
{
    short   speed;
    short    Power;       //����,0-5
    float   NowDeepth;       //���
    qint16  TempIn;       //�����¶�
    qint16  HumIn;		  //����ʪ��
    float   TempOut;    //�����¶�
    float   salt;        //�ζ�
    float   seahigh;      //�߶�
    short    Roll;         //roll�Ƕ�
    short    pitch;	      //pitch�Ƕ�
    short int Yaw;      //ƫ���� 0-360
    int gps[2];         //GPS���� ���� γ��
    quint8 satcom_state;    //����ͨ��״̬
    quint8 sonar_state;     //ˮ��ͨ��״̬
    quint8 rf_state;        //����ͨ��״̬
    int left_avoid;
    int right_avoid;
}Data_STATE_TypeDef;
///////////////////////////////�������ؿ���ָ��/////////////////////////////////

typedef enum //������ؿ���ָ��
{
    Boot_Reset=0,
    Boot_Download
}BootloaderCmd;
//�ȷ���Boot_Reset����ó���λ�� ��λ�ɹ�������ͬ������ ��ʼ����͸����͸����ɺ���Boot_Download
// ����Ϊ�����ֽ��� ��У��ɹ��� �ظ���ָͬ���
typedef struct
{
    quint8 Cmd;     //�豸������ؿ���
    int Ask;     //��Ӧ����ظ�
}Data_DOWNLOADCONTROL_TypeDef;
//////////////////////////////�ƵĿ���/////////////////////
typedef struct
{
    quint8 lightpower;    //�ƵĿ���0-100
}Data_LIGHTCONTROL_TypeDef;
//////////////////////////////////////ˮ�����Ŀ���////////////////////////////
typedef struct
{
    unsigned char EnOrDisEN;	//ENABLE	DISABLE  //ˮ�������ݲɼ�����
    qint8 ReadAll; 				//ENABLE	DISABLE  ����������ȡ����
    qint8 GetFS;	 				//ˮ����Ƶ�����ݿ��� ��������һ��
}Data_SOUNDCONTROL_TypeDef;
typedef struct // ˮ���������ݻظ�
{
    unsigned char FScode[256];//
}Data_SOUNDFSACK_TypeDef;
/////////////////////////////////debugָ����������
typedef struct  
{
    float PID[3];
}Data_DEBUG_TypeDef;

//////////////////////////////////С���ͨ��//////////////////////////////
typedef struct 
{
    float latitude;   // γ��
    float longitude;  //����
    float GPS_x;
    float GPS_y;
    qint8 posslnum;      //���Ǹ���
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
    qint8 uart_event_tc; //��������¼�
    qint8 uart_event_idle; //��������¼�
}Uart_Event;

#endif


