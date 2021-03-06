#include "clientsocket.h"
#include <iostream>
using namespace std;
ClientSocket::ClientSocket(QObject *parent) :
        QObject(parent)
{
    IPaddr="127.0.0.1";
    //IPaddr="10.13.0.110";
    port=3425;
    status=0;
    connect(&sock,SIGNAL(readyRead()),this,SIGNAL(socketReadyRead()),Qt::QueuedConnection);
}

ClientSocket::~ClientSocket()
{
}

void ClientSocket::ConnectToHost()
{
    sock.connectToHost(IPaddr,port);
}

bool ClientSocket::IsSocketCorrect()
{
    return sock.isValid();
}

void ClientSocket::SetSettings(QString ip, int p)
{
    IPaddr=ip;
    port=p;
    sock.disconnectFromHost();
    ConnectToHost();
    cout<<"Change Setting"<<IPaddr.toStdString()<<port<<endl;
}

QByteArray ClientSocket::Read()
{
    QByteArray array;
    array.clear();
    QByteArray tmp=sock.peek(1024);
    int i1=0;
    while((tmp[i1]!='#')||(tmp[i1+1]!='/'))
    {
        i1++;
    }
    array=sock.read(i1+2);
    array=array.left(i1);
    return array;
}

int ClientSocket::Write(QByteArray str)
{
    sock.write(str+"#/");
    return 0;
   /* if(IsSocketCorrect())
    {
        sock.write(str);
        return 0;
    }
    else
    {
        ConnectToHost();
        sock.write(str);
        return 1;
    }*/
}

int ClientSocket::bytesAvailable()
{
    return sock.bytesAvailable();
}

int ClientSocket::Status()
{
    return status;
}

void ClientSocket::SetStatus(int i)
{
    status=i;
}
