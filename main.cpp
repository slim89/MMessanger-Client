#include <MApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    MApplication a(argc, argv);
    MainWindow w;
    MTheme::loadCSS("usr/share/Meego-KVP-Client/style/Meego-KVP-Client.css");
    MTheme::addPixmapDirectory("usr/share/Meego-KVP-Client/style/");
    w.show();
    return a.exec();
}
