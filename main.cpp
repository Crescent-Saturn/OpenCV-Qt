#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move(-640/2, -480/2);       // Or change it in mainwindow.cpp by move(x,y)

    return a.exec();
}
