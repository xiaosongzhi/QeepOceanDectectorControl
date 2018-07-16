#ifndef FLASHMAP_H
#define FLASHMAP_H

#include <QWidget>
#include <QMouseEvent>
#include "myserialport.h"
#include "dataform.h"
#include <QResizeEvent>
#include <QTimer>

namespace Ui {
class FlashMap;
}

class FlashMap : public QWidget
{
    Q_OBJECT

public:
    explicit FlashMap(QWidget *parent = 0);
    ~FlashMap();
    void clearRuler(QString layer,quint8 flag);//*
    void addLayer(QString);//*
    void deleteLayer(QString layer);//*
    void addPoint(quint8 id,QString type,float lon,float lat,QString pointType,int size,int color);//*
    void delObject(quint8 id,QString type);//*
    void setImageRotation(int angle);
    void setImagePosition(float,float);
    void addImage(QString layer,quint8 Id,QString type,QString path,quint8 width,quint8 height,float lon,float lat,int angle);
    void clearLayer(QString);// *
    void addLabel(QString); // *
    void setPointColor(quint8 id,QString type,int color);
    void startRuler(quint8,QString);//路径规划 *
    void setCenter(float,float);//设置地图中心 *

    //重绘事件
    void resizeGroup();
    void resizeGroup2();
    void resizeGroup3();
    void resizeGroup4();
    void resizeGroup5();
    void resizeGroup6();
    void resizeGroup7();

    void initMap();
    void initPixmap();
    void initBtn();
public slots:
    void acceptFlashData(QString);
    void receiveStateData(Data_STATE_TypeDef);
    void displayText(QByteArray array);
signals:
    void sendPointsData(QList <QPointF>,float,int,quint8,int);
protected:
    void resizeEvent(QResizeEvent* size);
private slots:
    void onDisplayDynamicDatas();

    void on_reSendTrack_Btn_clicked();

    void on_planTrack_Btn_clicked();

    void on_displayTrack_Btn_clicked();

    void on_clearTrack_Btn_clicked();

    void on_setDevice_Btn_clicked();

    void on_init_Btn_clicked();

    void on_deletePath_Btn_clicked();

private:
    Ui::FlashMap *ui;
    QList <QPointF> logPoints;
    QString separate = ";string&gt;";
    bool isPlanning = false;
    float tempLatitude = 0,tempLongitude = 0;
    MySerialPort *communication;
    float xscale = 0,yscale = 0;
    float xscale2 = 0,yscale2 = 0;
    float xscale3 = 0,yscale3 = 0;
    float xscale4 = 0,yscale4 = 0;
    float xscale5 = 0,yscale5 = 0;
    float xscale6 = 0,yscale6 = 0;
    float xscale7 = 0,yscale7 = 0;
    QTimer *dataTimer;
    Data_STATE_TypeDef STATEDATA;

    bool isDisplay = false;


};

#endif // FLASHMAP_H
