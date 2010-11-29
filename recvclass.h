#ifndef RECVCLASS_H
#define RECVCLASS_H

#include <QObject>
#include <QThread>

#include "message.h"

#include "clientsocket.h"
class RecvThread : public QThread
{
    Q_OBJECT
private:
    ClientSocket* socket;
    void readFromServer();
public:
    explicit RecvThread(ClientSocket* sock);
    void run();
signals:
    void readyMessage(Message* mes);
private slots:
};

#endif // RECVCLASS_H
