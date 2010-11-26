#ifndef SENDTREAD_H
#define SENDTREAD_H
#include <QThread>
#include <strings.h>


class ClientSocket;

class SendThread : public QThread
{
    Q_OBJECT
public:
     ClientSocket*  mysock;
     QString mystr;
     explicit SendThread(ClientSocket* sock);
     void set(QString str);
     void run();

signals:
     void success();
     void fail();
};
#endif // SENDTREAD_H
