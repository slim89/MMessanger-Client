#ifndef SENDTREAD_H
#define SENDTREAD_H
#include <QThread>
#include <QtNetwork>
class SendThread : public QThread
{
    Q_OBJECT
public:
     QSharedPointer<QTcpSocket>  mysock;
     QString mystr;
     explicit SendThread(QSharedPointer<QTcpSocket> sock);
 public slots:
     void writeToServer(QString str);
     void run();
signals:
     void success();
     void fail();
};
#endif // SENDTREAD_H
