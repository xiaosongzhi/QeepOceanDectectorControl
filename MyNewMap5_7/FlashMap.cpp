#include "FlashMap.h"
#include "ui_FlashMap.h"
#include <QAxWidget>
#include <QDebug>
#include <QDir>
#include <QRegExp>
#include "data.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPixmap>
#include <QMovie>
#include <QTime>

FlashMap::FlashMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlashMap)
{
    ui->setupUi(this);
    communication = new MySerialPort;
    QString path = QDir::currentPath();

    ui->axWidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
    ui->axWidget->dynamicCall("LoadMovie(int,QString)",0,path+"/API/FlashGIS.swf");
    ui->axWidget->dynamicCall("");
    connect(ui->axWidget,SIGNAL(FlashCall(QString)),this,SLOT(acceptFlashData(QString)));
    connect(this,SIGNAL(sendPointsData(QList<QPointF>,float,int,quint8,int)),communication,
            SLOT(receivePointsData(QList <QPointF>,float,int,quint8,int)));
    connect(communication,SIGNAL(sendStateToUI(Data_STATE_TypeDef)),this,SLOT(receiveStateData(Data_STATE_TypeDef)));
    connect(communication,SIGNAL(sendArrayToBrower(QByteArray)),this,SLOT(displayText(QByteArray)));
    //    initBtn();
    initPixmap();
    mySleep(2000);
    initMap();

}

FlashMap::~FlashMap()
{
    delete ui;
}
//地图使用前的初始化
void FlashMap::initMap()
{
    //1.添加图层
    addLayer("fishMap");
    addLayer("fishPoint");
    //2.添加图例
    int width = 80,height = 42;
    QString path = "C:/Users/muhai/Desktop/6.5/MyNewMap5_7/image/fufen.png";
    QString type("img");
    QString layer("fishMap");
    addImage(layer,4,type,path,width,height,100,30,0);
    tempLatitude = 31.22845,tempLongitude = 121.49491;
    dataTimer = new QTimer(this);
    connect(dataTimer,SIGNAL(timeout()),this,SLOT(onDisplayDynamicDatas()));
    dataTimer->start(100);
}
//初始化动图
void FlashMap::initPixmap()
{
    QMovie* movie = new QMovie("./image/信号-gif--蓝.gif");
    ui->bizhang_label->setMovie(movie);
    movie->start();
    QMovie *soundMovie = new QMovie("./image/水声开.gif");
    ui->sound_label->setMovie(soundMovie);
    soundMovie->start();
    QMovie *sateMovie = new QMovie("./image/卫星开.gif");
    ui->sate_label->setMovie(sateMovie);
    sateMovie->start();
    QMovie *rfMovie = new QMovie("./image/射频开.gif");
    ui->rF_label->setMovie(rfMovie);
    rfMovie->start();

    ui->VgraphicsView->addItem("./hsi/电压指示.svg");
    //设置场景大小以及旋转中心
    ui->VgraphicsView->setOrignalSizeAndCoordinate(180,180,11.5,80);

    ui->yaw_GraphicsView->addItem("./hsi/蝠鲼-偏航角.svg");
    ui->yaw_GraphicsView->setOrignalSizeAndCoordinate(200,200,68,93);

    ui->roll_GraphicsView->addItem("./hsi/翻滚角.svg");
    ui->roll_GraphicsView->setOrignalSizeAndCoordinate(250,250,127,123);

}
void FlashMap::initBtn()
{
    ui->planTrack_Btn->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/image/规划路径-正常.png);}"
                                     "QPushButton:hover{border-image: url(:/new/prefix1/image/规划路径-悬浮.png);}"
                                     "QPushButton:pressed{border-image: url(:/new/prefix1/image/规划路径按下.png);}");
}
/************
void FlashMap::on_pushButton_2_clicked()
{
    qDebug()<<"收到";
}

void FlashMap::on_reSendPath_Btn_clicked()
{   //发送完路径后，需要告诉之后的行为，比如上浮下潜

}
void FlashMap::on_textClear_Btn_clicked()
{

}
void FlashMap::on_draw_line_clicked()
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>testlayer</layer_name>");
    argu.append("<bus_id>12</bus_id>");         //业务ID
    argu.append("<bus_type>line</bus_type>");   //业务类型
    argu.append("<width>1</width>");
    argu.append("<color>16711680</color>");
    argu.append("<type>solid</type>");
    argu.append("<points>");
    argu.append("<point><lonlat>85,36</lonlat></point>");
    argu.append("<point><lonlat>127,45</lonlat></point>");
    argu.append("</points>");
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"add_line\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

void FlashMap::on_setLayerVisible_Btn_clicked()
{
//    QString argu;
//    argu.append("<param>");
//    argu.append("<layer_name>testlayer</layer_name>");
//    if(ui->setLayerVisible_Btn->text() == "显示")
//    {
//        argu.append("<layer_visible>1</layer_visible>");
//        ui->setLayerVisible_Btn->setText("隐藏");
//    }
//    else if(ui->setLayerVisible_Btn->text() == "隐藏")
//    {
//        argu.append("<layer_visible>0</layer_visible>");
//        ui->setLayerVisible_Btn->setText("显示");
//    }
//    argu.append("</param>");
//    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"set_layer_visible\" returntype=\"xml\">"
//                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

//可以执行但是角度无法旋转
void FlashMap::on_addImage_Btn_clicked()
{
    int width = 40,height = 28;
    QString path = "C:/Users/muhai/Desktop/Army/fufen.png";
    QString type("img");
    QString layer("testlayer");
    addImage(layer,4,type,path,width,height,100,30,0);
}

void FlashMap::on_setImagePosition_Btn_clicked()
{
    setImagePosition(100,30);
}
int angle = 0;
void FlashMap::on_setImageRotation_Btn_clicked()
{
    angle += 5;
    setImageRotation(angle);
}

void FlashMap::on_clearLayer_Btn_clicked()
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>testlayer</layer_name>");
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"clear_layer\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

void FlashMap::on_delObject_Btn_clicked()
{
    delObject(4,"img");
}

void FlashMap::on_addLabel_Btn_clicked()
{
    QString text = "hello world";
    addLabel(text);
}

void FlashMap::on_setPointColor_Btn_clicked()
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>testlayer</layer_name>");
    argu.append("<bus_id>2</bus_id>");         //业务ID
    argu.append("<bus_type>point</bus_type>");   //业务类型
    argu.append("<color>0x00FF00</color>");
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"set_point_color\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

void FlashMap::on_setPointSize_Btn_clicked()
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>testlayer</layer_name>");
    argu.append("<bus_id>2</bus_id>");         //业务ID
    argu.append("<bus_type>point</bus_type>");   //业务类型
    argu.append("<size>10</size>");
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"set_point_size\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

//清除规划的路径
void FlashMap::on_clearRuler_Btn_clicked()
{
    clearRuler("testlayer",0);
}
******************/
void FlashMap::acceptFlashData(QString str)
{
    QPointF tempPoint;
    QString latitude;
    QString longitude;
    QString tempData;
    int ret = 0;
    QString fileName = QDateTime::
            currentDateTime().toString("yyyyMMddhhmmss") + ".txt";
    QDir myDir;
    myDir.mkdir("logDir");
    QString filePath = QDir::currentPath() + "/logDir/";
    QFile logFile(filePath + fileName);
    if(isPlanning)
    {
        if(!logFile.open(QIODevice::Append | QIODevice::Text))
        {
            QMessageBox::warning(NULL,"WARNING","文件打开失败",QMessageBox::Retry);
            return;
        }
        QTextStream out(&logFile);

        while(-1 != ret)
        {
            ret = str.indexOf(separate);
            tempData = str.mid(ret+11,24);
            QStringList list =tempData.split(",");
            longitude = list[0];
            latitude = list[1];

            tempPoint.setX(longitude.remove(longitude.length()-3,3).toDouble());
            tempPoint.setY(latitude.remove(latitude.length()-3,3).toDouble());
            //保存日志文件
            out << longitude <<","<<latitude<<","<<tempPoint.x()<<","<<tempPoint.y()<<"\n";

            if(tempPoint.x() == 0 || tempPoint.y() == 0)
            {
                QMessageBox::warning(NULL,"WARNING" ,"路径规划失败请重试",QMessageBox::Retry);
                clearRuler("testlayer",0);
                //                ui->openRuler_Btn->setText("开始规划");
                //                on_openRuler_Btn_clicked();
                logPoints.clear();
                return;
            }
            logPoints.append(tempPoint);
            str = str.mid(ret+1);
        }
        logFile.close();
        isPlanning = false;
        //        ui->openRuler_Btn->setText("开始规划");
        logPoints.removeLast();
        //发送点数据并保存
        emit sendPointsData(logPoints,1,1,1,1);
        //        logPoints.clear();
    }
}

//与本地类 进行通信
void FlashMap::receiveStateData(Data_STATE_TypeDef State)
{
    STATEDATA = State;
    if(1)
    {
        qint16 speed = State.speed;
        short power = State.Power;
        float depth = State.NowDeepth;
        qint16 tempIn = State.TempIn;
        qint16 humIn = State.HumIn;
        float tempOut = State.TempOut;
        float salt = State.salt;
        float hight = State.seahigh;
        short roll = State.Roll;
        short pitch = State.pitch;
        short heading = State.Yaw;
        int longitude = State.gps[0];
        int latitude = State.gps[1];
        qint8 sateComState = State.satcom_state;
        qint8 soundComState = State.sonar_state;
        qint8 rfComState = State.rf_state;
        int leftAvoid = State.left_avoid;
        int rightAvoid = State.right_avoid;

        qDebug()<<speed<<(int)power<<depth<<tempIn<<humIn<<tempOut<<salt<<hight<<(int)roll<<(int)pitch<<heading<<longitude<<latitude
               <<sateComState<<soundComState<<rfComState<<leftAvoid<<rightAvoid;
    }

    ui->deep_label->setText(QString::number(State.NowDeepth));
    ui->altitude_label->setText(QString::number(State.seahigh));
    ui->salt_label->setText(QString::number(State.salt));
    ui->hum_label->setText(QString::number(State.HumIn));
    ui->lon_label->setText(QString::number(State.gps[0]));
    ui->lat_label->setText(QString::number(State.gps[1]));
    ui->yaw_label->setText(QString::number(State.Yaw));
    ui->pitch_label->setText(QString::number(State.pitch));
    ui->roll_label->setText(QString::number(State.Roll));

    QTime time;
    ui->time_lcdNumber->display(time.currentTime().toString("hh:mm"));
}


void FlashMap::displayText(QByteArray array)
{

}


//****************地图设置函数****************/
void FlashMap::setCenter(float lon,float lat)
{
    QString argu;
    argu.append("<param>");
    argu.append(QString("<lon>%1</lon>").arg(lon));
    argu.append(QString("<lat>%1</lat>").arg(lat));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"set_map_center\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
//开始路径规划
void FlashMap::startRuler(quint8 flag,QString layer)
{
    QString argu;
    argu.append("<param>");
    argu.append(QString("<layer_name>%1</layer_name>").arg(layer));
    argu.append(QString("<open>%1</open>").arg(flag));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"open_ruler\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
//停止路径规划
void FlashMap::clearRuler(QString layer,quint8 flag)
{
    QString argu;
    argu.append("<param>");
    argu.append(QString("<layer_name>%1</layer_name>").arg(layer));
    argu.append(QString("<open>%1</open>").arg(flag));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"open_ruler\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

void FlashMap::addLabel(QString text)
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>fishMap</layer_name>");
    argu.append("<bus_id>5</bus_id>");         //业务ID
    argu.append("<bus_type>label</bus_type>");   //业务类型
    argu.append(QString("<text>%1</text>").arg(text));
    argu.append(QString("<lonlat>%1,%2</lonlat>").arg(100).arg(30));
    argu.append("<placement>square</placement>");
    argu.append("<color>16711680</color>");
    argu.append("<size>12</size>");
    argu.append("<xoff>0</xoff>");
    argu.append("<yoff>0</yoff>");
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"add_lable\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
void FlashMap::addPoint(quint8 id,QString type,float lon,float lat,QString pointType,int size,int color)
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>fishPoint</layer_name>");
    argu.append(QString("<bus_id>%1</bus_id>").arg(id));         //业务ID
    argu.append(QString("<bus_type>%1</bus_type>").arg(type));   //业务类型
    argu.append(QString("<lonlat>%1,%2</lonlat>").arg(lon).arg(lat));
    argu.append(QString("<type>%1</type>").arg(pointType));
    argu.append(QString("<size>%1</size>").arg(size));
    argu.append(QString("<color>%1</color>").arg(color));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"add_point\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
void FlashMap::delObject(quint8 id,QString type)
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>fishMap</layer_name>");
    argu.append(QString("<bus_id>%1</bus_id>").arg(id)) ;
    argu.append(QString("<bus_type>%1</bus_type>").arg(type));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"del_objects\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}

//添加图层
void FlashMap::addLayer(QString layer)
{
    QString argu;
    argu.append("<param>");
    argu.append(QString("<layer_name>%1</layer_name>").arg(layer));
    argu.append("<layer_visible>1</layer_visible>");
    argu.append("<min_level>0</min_level>") ;
    argu.append("<max_level>18</max_level>");
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"add_layer\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
//删除图层
void FlashMap::deleteLayer(QString layer)
{
    QString argu;
    argu.append("<param>");
    argu.append(QString("<layer_name>%1</layer_name>").arg(layer));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"clear_layer\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
void FlashMap::addImage(QString layer,quint8 Id,QString type,QString path,quint8 width,quint8 height,float lon,float lat,int angle)
{
    QString argu;
    argu.append("<param>");
    argu.append(QString("<layer_name>%1</layer_name>").arg(layer));
    argu.append(QString("<bus_id>%1</bus_id>").arg(Id)) ;
    argu.append(QString("<bus_type>%1</bus_type>").arg(type));
    argu.append(QString("<url>%1</url>").arg(path));
    argu.append(QString("<width>%1</width>").arg(width));
    argu.append(QString("<height>%1</height>").arg(height));
    argu.append(QString("<lonlat>%1,%2</lonlat>").arg(lon).arg(lat));
    argu.append(QString("<rotation>%1</rotation>").arg(angle));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"add_image\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
void FlashMap::setImageRotation(int angle)
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>fishMap</layer_name>");
    argu.append("<bus_id>4</bus_id>") ;
    argu.append("<bus_type>img</bus_type>");
    argu.append(QString("<rotation>%1</rotation>").arg(angle));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"set_image_rotation\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
void FlashMap::setImagePosition(float lon,float lat)
{
    QString argu;
    argu.append("<param>");
    argu.append("<layer_name>fishMap</layer_name>");
    argu.append("<bus_id>4</bus_id>") ;
    argu.append("<bus_type>img</bus_type>");
    argu.append(QString("<lonlat>%1,%2</lonlat>").arg(lon).arg(lat));
    argu.append("</param>");
    ui->axWidget->dynamicCall("CallFunction(string)","<invoke name=\"set_image_position\" returntype=\"xml\">"
                                                     "<arguments><string>" + argu + "</string></arguments></invoke>");
}
//**************界面命令**************//
void FlashMap::on_reSendTrack_Btn_clicked()
{
    emit sendPointsData(logPoints,1,1,1,1);
}

void FlashMap::on_planTrack_Btn_clicked()
{
    startRuler(1,"fishMap");
}
//清除规划的路径
void FlashMap::on_deletePath_Btn_clicked()
{
    clearRuler("fishMap",0);
}
//添加显示GPS点
float point = 0;

void FlashMap::on_displayTrack_Btn_clicked()
{
    point += 0.1;
    addPoint(2,"point",tempLongitude+point,tempLatitude+point,"square",5,16711680);
}

void FlashMap::on_clearTrack_Btn_clicked()
{
    deleteLayer("fishPoint");
}

void FlashMap::on_setDevice_Btn_clicked()
{
    communication->show();
}

void FlashMap::on_init_Btn_clicked()
{
    initMap();
    setCenter(121.49491,31.22845);
}

//UI界面设计
void FlashMap::resizeEvent(QResizeEvent* size)
{
    resizeGroup();
    resizeGroup2();
    resizeGroup3();
    resizeGroup4();
    resizeGroup5();
    resizeGroup6();
    resizeGroup7();

}
void FlashMap::resizeGroup()
{
    //groupbox  重绘
    xscale = (float)(ui->groupBox->width())/1403.f;
    yscale = (float)(ui->groupBox->height())/157.f;

    ui->planTrack_Btn->resize(158*xscale,49*yscale);
    ui->planTrack_Btn->move(140*xscale,17*yscale);

    ui->reSendTrack_Btn->resize(158*xscale,49*yscale);
    ui->reSendTrack_Btn->move(330*xscale,17*yscale);

    ui->deletePath_Btn->resize(158*xscale,49*yscale);
    ui->deletePath_Btn->move(520*xscale,17*yscale);

    ui->displayTrack_Btn->resize(158*xscale,49*yscale);
    ui->displayTrack_Btn->move(140*xscale,80*yscale);

    ui->clearTrack_Btn->resize(158*xscale,49*yscale);
    ui->clearTrack_Btn->move(330*xscale,80*yscale);

    ui->setDevice_Btn->resize(158*xscale,49*yscale);
    ui->setDevice_Btn->move(520*xscale,80*yscale);

    ui->rF_label->resize(110*xscale,109*yscale);
    ui->rF_label->move(766*xscale,20*yscale);

    ui->sound_label->resize(110*xscale,109*yscale);
    ui->sound_label->move(950*xscale,20*yscale);

    ui->sate_label->resize(110*xscale,109*yscale);
    ui->sate_label->move(1134*xscale,20*yscale);
}
void FlashMap::resizeGroup2()
{
    xscale2 = ui->groupBox_2->width()/507.f;
    yscale2 = ui->groupBox_2->height()/217.f;

    ui->VgraphicsView->resize(180*xscale2,180*yscale2);
    ui->VgraphicsView->move(190*xscale2,40*yscale2);


}
void FlashMap::resizeGroup3()
{
    xscale3 = ui->groupBox_3->width()/180.f;
    yscale3 = ui->groupBox_3->height()/807.f;

    ui->deep_label->resize(75*xscale3,25*yscale3);
    ui->deep_label->move(42*xscale3,518*yscale3);

    ui->altitude_label->resize(71*xscale3,31*yscale3);
    ui->altitude_label->move(43*xscale3,613*yscale3);

    ui->deepAngle_label->resize(11*xscale3,10*yscale3);
    ui->deepAngle_label->move(97*xscale3,20*yscale3);

    ui->altitudeAngle_label->resize(11*xscale3,10*yscale3);
    ui->altitudeAngle_label->move(150*xscale3,747*yscale3);
}
void FlashMap::resizeGroup4()
{
    xscale4 = ui->groupBox_4->width()/507.f;
    yscale4 = ui->groupBox_4->height()/157.f;

    ui->bizhang_label->resize(360*xscale4,84*yscale4);
    ui->bizhang_label->move(123*xscale4,37*yscale4);
}
void FlashMap::resizeGroup5()
{
    xscale5 = ui->groupBox_5->width()/507.f;
    yscale5 = ui->groupBox_5->height()/250.f;

    ui->salt_label->resize(55*xscale5,28*yscale5);
    ui->salt_label->move(89*xscale5,8*yscale5);

    ui->hum_label->resize(55*xscale5,28*yscale5);
    ui->hum_label->move(89*xscale5,60*yscale5);

    ui->inTem_label->move(250*xscale5,110*yscale5);
    ui->outTem_label->move(250*xscale5,174*yscale5);

    ui->saltAngle_label->resize(8*xscale5,7*yscale5);
    ui->saltAngle_label->move(190*xscale5,2*yscale5);

    ui->humAngle_label->resize(8*xscale5,7*yscale5);
    ui->humAngle_label->move(210*xscale5,51*yscale5);

    //此处温度的x坐标是变值
}
void FlashMap::resizeGroup6()
{
    xscale6 = ui->groupBox_6->width()/1407.f;
    yscale6 = ui->groupBox_6->height()/108.f;

    ui->progressBar->resize(495*xscale6,24*yscale6);
    ui->progressBar->move(851*xscale6,54*yscale6);
}
void FlashMap::resizeGroup7()
{
    xscale7 = ui->groupBox_7->width()/507.f;
    yscale7 = ui->groupBox_7->height()/448.f;

    ui->lat_label->resize(130*xscale7,28*yscale7);
    ui->lat_label->move(109*xscale7,29*yscale7);

    ui->lon_label->resize(130*xscale7,28*yscale7);
    ui->lon_label->move(109*xscale7,60*yscale7);

    ui->time_lcdNumber->resize(200*xscale7,65*yscale7);
    ui->time_lcdNumber->move(278*xscale7,29*yscale7);

    ui->roll_label->resize(110*xscale7,26*yscale7);
    ui->roll_label->move(130*xscale7,120*yscale7);

    ui->pitch_label->resize(110*xscale7,26*yscale7);
    ui->pitch_label->move(130*xscale7,150*yscale7);

    ui->yaw_label->resize(110*xscale7,26*yscale7);
    ui->yaw_label->move(130*xscale7,180*yscale7);

    ui->pitchAngle_label->resize(11*xscale7,10*yscale7);
    ui->pitchAngle_label->move(370*xscale7,300*yscale7);

    ui->yaw_GraphicsView->resize(200*xscale7,200*yscale7);
    ui->yaw_GraphicsView->move(29*xscale7,239*yscale7);

    ui->roll_GraphicsView->resize(250*xscale7,250*yscale7);
    ui->roll_GraphicsView->move(230*xscale7,179*yscale7);

}
//图形可视化显示数据
float depth_1 = 0;
bool add = true;
bool lose = false;
void FlashMap::onDisplayDynamicDatas()
{
    if(isDisplay)
    {
        if(depth_1 == 60)
        {
            add = false;
            lose = true;
        }
        else if(depth_1 == -60)
        {
            add = true;
            lose = false;
        }

        if(add)
        {
            depth_1 += 2;
        }
        if(lose)
        {
            depth_1 -= 2;
        }

        ui->deepAngle_label->move(97*xscale3,(depth_1*1.5 + 20)*yscale3);
        ui->deep_label->setText(QString::number(depth_1));

        ui->altitudeAngle_label->move(150*xscale3,(747-depth_1*1.7)*yscale3);
        ui->altitude_label->setText(QString::number(depth_1));

        ui->salt_label->setText(QString::number(depth_1));
        ui->saltAngle_label->move((160+depth_1*3)*xscale5,2*yscale5);

        ui->hum_label->setText(QString::number(depth_1));
        ui->humAngle_label->move((160+depth_1*3)*xscale5,51*yscale5);

        ui->inTem_label->move((250+depth_1*3)*xscale5,110*yscale5);
        ui->inTem_label->setText("      "+QString::number(depth_1));

        ui->outTem_label->move((250+depth_1*3)*xscale5,174*yscale5);
        ui->outTem_label->setText("      "+QString::number(depth_1));

        ui->pitchAngle_label->move(370*xscale7,(300+depth_1)*yscale7);

        //set heading  and  pos
        ui->VgraphicsView->setHeading(depth_1-60,75,60);

        ui->yaw_GraphicsView->setHeading(depth_1,32,6);

        ui->roll_GraphicsView->setHeading(depth_1,0,0);
    }
    else
    {

        ui->deepAngle_label->move(97*xscale3,(STATEDATA.NowDeepth*1.5 + 20)*yscale3);
        ui->deep_label->setText(QString::number(STATEDATA.NowDeepth));

        ui->altitudeAngle_label->move(150*xscale3,(747-STATEDATA.seahigh*1.7)*yscale3);
        ui->altitude_label->setText(QString::number(STATEDATA.seahigh));

        ui->salt_label->setText(QString::number(STATEDATA.salt));
        ui->saltAngle_label->move((160+STATEDATA.salt*3)*xscale5,2*yscale5);

        ui->hum_label->setText(QString::number(STATEDATA.HumIn));
        ui->humAngle_label->move((160+STATEDATA.HumIn*3)*xscale5,51*yscale5);

        ui->inTem_label->move((250+STATEDATA.TempIn*3)*xscale5,110*yscale5);
        ui->inTem_label->setText("      "+QString::number(STATEDATA.TempIn));

        ui->outTem_label->move((250+STATEDATA.TempOut*3)*xscale5,174*yscale5);
        ui->outTem_label->setText("      "+QString::number(STATEDATA.TempOut));

        ui->pitchAngle_label->move(370*xscale7,(300+STATEDATA.pitch)*yscale7);

        //set heading  and  pos
        ui->VgraphicsView->setHeading(STATEDATA.speed-60,75,60);

        ui->yaw_GraphicsView->setHeading(STATEDATA.Yaw,32,6);

        ui->roll_GraphicsView->setHeading(STATEDATA.Roll,0,0);
    }
}

