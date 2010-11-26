#include "clientsocket.h"
#include <iostream>

using namespace std;

ClientSocket::ClientSocket(QObject *parent) :
        QObject(parent)
{
    IPaddr="127.0.0.1";
    port=3425;
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
    cout<<"Change Setting"<<IPaddr.toStdString()<<port<<endl;
}

QByteArray ClientSocket::Read()
{
    QByteArray array;
    array.clear();
    QByteArray tmp=sock.peek(1024);
    int i1=0;
    while(tmp[i1]!='\0')
    {
        i1++;
    }
    array=sock.read(i1+1);

    if((tmp.count()-array.count())>0)
        {
            emit socketReadyRead();
        }

    return array;
}

int ClientSocket::Write(QByteArray str)
{
    if(IsSocketCorrect())
    {
        sock.write(str);
        return 0;
    }
    else
    {
        return 1;
    }
}
