#ifndef RECVCLASS_H
#define RECVCLASS_H
#include <QObject>
#include <QThread>
#include "message.h"
#include <QtNetwork>
class RecvThread : public QThread
{
    Q_OBJECT
private:
    QSharedPointer<QTcpSocket>  socket;

public:
    explicit RecvThread(QSharedPointer<QTcpSocket> sock);
    void run();
signals:
    void readyMessage(QSharedPointer<IMessage> mes);
private slots:
     void readFromServer();
};
#endif // RECVCLASS_H
