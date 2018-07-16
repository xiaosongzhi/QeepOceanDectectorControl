#include "FlashMap.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QProcess p;
//    p.start("cmd.exe",QStringList()<<"/c"<<"F://map//mbtiles-server//startmap.bat");
    FlashMap w;
    w.show();
    return a.exec();
}
