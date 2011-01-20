#include "sendthread.h"
#include <QDebug>
SendThread::SendThread(QSharedPointer<QTcpSocket> sock):QThread()
{
    mysock = sock;
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
}

void SendThread::run()
{
    qCritical()<<"RUN SEND THREAD";
    exec();
}

void  SendThread::writeToServer(QString str)
{
    qCritical()<<str;
    mysock->write(qPrintable(str));
}
