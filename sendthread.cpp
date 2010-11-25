#include "sendthread.h"
#include "clientsocket.h"
#include <iostream>

using namespace std;
SendThread::SendThread(QObject *parent,ClientSocket* sock):QThread()
{
    //QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
    mysock = sock;
    mystr ="";
}

void SendThread::run()
{
   bool res = 0;
   res = sendFromServer();
}
bool SendThread::sendFromServer()
{
    if(mystr!=""){
        QByteArray* buf = new QByteArray(mystr.toStdString().c_str());
        mysock->Write(*buf);
        cout<<mystr.toStdString()<<endl;
        mystr ="";
        return 1;
    }
    else
    return 0;

}
void  SendThread::set(QString str){
    mystr = str;
}
