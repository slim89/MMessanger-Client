#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork/QtNetwork>

class ClientSocket :  public QObject
{
    Q_OBJECT

    QTcpSocket sock;
    QString IPaddr;
    int port;

public:
    ClientSocket(QObject *parent = 0);
    ~ClientSocket();
    void ConnectToHost();
    bool IsSocketCorrect();
    QByteArray Read();
    int Write(QByteArray str);
    void SetSettings(QString ip,int port);
    int bytesAvailable();

public slots:

signals:
    void socketReadyRead();
};

#endif // CLIENTSOCKET_H
