#include <MApplication>
#include "mymainwindow.h"

int main(int argc, char *argv[])
{
    MApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
