#include "recvclass.h"
#include <QString>
#include <QByteArray>
#include <QTextCodec>

RecvThread::RecvThread(QSharedPointer<QTcpSocket> sock):
    QThread()
{
    socket=sock;
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
    connect(socket.data(),SIGNAL(readyRead()),SLOT(readFromServer()),Qt::QueuedConnection);
}
void RecvThread::run()
{
    exec();
}
void RecvThread::readFromServer()
{
    qCritical()<<"READ ";
    QByteArray array=socket->readAll();
    QString buffer = array;
    qCritical()<<buffer;
    if (!buffer.contains("#/"))
    {
        return;
    }
    QStringList strList=buffer.split("#/");
    if (strList.isEmpty())
        return;
    QStringListIterator iter(strList);
    while(iter.hasNext())
    {
        QString tmp=iter.next();
        QSharedPointer<IMessage> mes(new Message(tmp));
        emit readyMessage(mes);
    }
}
