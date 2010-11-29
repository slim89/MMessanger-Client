#include <MApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    MApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
