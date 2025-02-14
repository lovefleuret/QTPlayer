#include "mainwindow.h"
#include <QApplication>
#include "log.h"

int main(int argc, char *argv[])
{   
    LogInit();
    QApplication a(argc, argv);
    MainWindow w;
    LogInfo("test");

    w.show();

    return a.exec();
}
