#include "sendthread.h"
#include "clientsocket.h"
#include <iostream>

using namespace std;

SendThread::SendThread(ClientSocket* sock):QThread()
{
    //QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
    mysock = sock;
    mystr ="";
}

void SendThread::run()
{
       QByteArray* buf = new QByteArray(mystr.toStdString().c_str());
       mysock->Write(*buf);
       cout<<mystr.toStdString()<<endl;
       mystr ="";
       cout<<mystr.toStdString()<<endl;
       //this->exit();
}

void  SendThread::set(QString str)
{
    mystr = str;
}
