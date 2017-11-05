#include <iostream>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::cout << "Dave scks" << std::endl;
    QApplication a(argc, argv);
    std::cout << "Dave scks" << std::endl;
    MainWindow w;
    std::cout << "Dave scks" << std::endl;
    w.show();
    std::cout << "Dave scks post show" << std::endl;

    return a.exec();
}
