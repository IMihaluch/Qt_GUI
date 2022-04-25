#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumHeight(100);
    w.setMinimumWidth(200);
    w.setMaximumHeight(200);
    w.setMaximumWidth(400);
    w.show();

    return a.exec();
}
