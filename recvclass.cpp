#include "recvclass.h"
#include <QString>
#include <string>
#include <QTextCodec>
using namespace std;

RecvThread::RecvThread(ClientSocket* sock,QObject *parent):
    QThread()
{
    socket=sock;
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
    connect(socket,SIGNAL(readyRead()),SLOT(start()),Qt::QueuedConnection);
}
void RecvThread::run()
{
    readFromServer();
}
void RecvThread::readFromServer()
{
    cout<<"READ FROM"<<endl;
    QString str;
    str=socket->Read();

    string buf=str.toStdString();
    cout<<"STR"<<buf<<endl;
    Message* mes=new Message(buf);
    emit readyMessage(mes);
}
