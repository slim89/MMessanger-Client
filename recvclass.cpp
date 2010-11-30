#include "recvclass.h"
#include <QString>
#include <QByteArray>
#include <string>
#include <QTextCodec>
using namespace std;

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
    cout<<"READ FROM"<<endl;   
    QByteArray str;
    str=socket->Read();
    QString tmp=str;
    string buf=tmp.toStdString();
    cout<<"STR"<<buf<<endl;
    Message* mes=new Message(buf);
    emit readyMessage(mes);
}
