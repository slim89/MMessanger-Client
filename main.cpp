#include <MApplication>

#include "clientsocket.h"
#include "sendthread.h"
#include "mymainwindow.h"

ClientSocket* sock= new ClientSocket();
SendThread* thread1 = new SendThread(0,sock);


int main(int argc, char *argv[])
{
    sock->ConnectToHost();
    MApplication a(argc, argv);
    MyMainWindow w;
    w.show();
    return a.exec();
}
