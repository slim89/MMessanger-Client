#ifndef MESSAGEANIMATION_H
#define MESSAGEANIMATION_H

#include <QTimer>
#include <QList>
#include <QObject>
#include <QString>

class MessageAnimation : public QObject
{
   Q_OBJECT

 public:
   MessageAnimation();
   virtual ~ MessageAnimation();
   void Start(QString username);
   void Stop(QString username);
   bool hasMessage(QString username);
   void RemoveUser(QString username);
   QString Thumbnail( QString username, QString status );

signals:
//    void animate();
    void update();

public slots:
    void reStart();

private slots:
    void moveFrame();
    void startUnread();

private:
    QList<QString> users;
    int frame;
    QTimer* timer;

    QString Frame();

};

#endif // MESSAGEANIMATION_H