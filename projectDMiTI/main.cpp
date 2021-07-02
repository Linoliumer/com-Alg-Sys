#include "MainBack/mainwindow.h"
#include <iostream>
#include <QApplication>


int main(int argc, char *argv[])
{
    QIcon winIcon("one.png");
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(813,401);
    w.setWindowIcon(winIcon);
    w.setWindowTitle("Главная");
    w.show();
    return a.exec();
}
