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
   void AddUser(QString username);
   QString Thumbnail( QString username, QString status );
   void StartAll();
   int getTimerID();
   QList<QString> getUsers();
   void StopAnimation();

signals:
//    void animate();
    void update();

private slots:
    void moveFrame();

private:
    QList<QString> users;
    int frame;
    QTimer* timer;

    QString Frame();

};

#endif // MESSAGEANIMATION_H
