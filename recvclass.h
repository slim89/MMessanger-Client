#ifndef RECVCLASS_H
#define RECVCLASS_H

#include <QObject>
#include <QThread>

#ifndef MESSAGE_H
#define MESSAGE_H
#include "message.h"
#endif

#include "clientsocket.h"
class RecvThread : public QThread
{
    Q_OBJECT
private:
    ClientSocket* socket;
    void readFromServer();
public:
    explicit RecvThread(ClientSocket* sock,QObject *parent);
    void run();
signals:
    void readyMessage(Message* mes);
private slots:
};

#endif // RECVCLASS_H
