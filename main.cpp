#include "sikplayer.h"
//#include "mystatuswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SikPlayer w;
    w.show();
    return a.exec();
}
