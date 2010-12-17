#include "recvclass.h"
#include <QString>
#include <QByteArray>
#include <string>
#include <QTextCodec>

RecvThread::RecvThread(ClientSocket* sock):
    QThread()
{
    socket=sock;
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
    connect(socket,SIGNAL(socketReadyRead()),SLOT(start()),Qt::QueuedConnection);
}
void RecvThread::run()
{
    while(socket->bytesAvailable()>0)
    {
        readFromServer();
    }
}
void RecvThread::readFromServer()
{
    qCritical()<<"READ FROM";
    QByteArray str;
    str=socket->Read();
    QString tmp=str;
    qCritical()<<"STR"<<tmp;
    Message* mes=new Message(tmp);
    emit readyMessage(mes);
}
