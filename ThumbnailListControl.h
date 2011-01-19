#ifndef THUMBNAILLISTCONTROL_H
#define THUMBNAILLISTCONTROL_H
#include <QTimer>
#include <QList>
#include <QObject>
#include <QString>

class ThumbnailListControl : public QObject
{
   Q_OBJECT

 public:
   ThumbnailListControl();
   virtual ~ ThumbnailListControl();
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
    void StartOnTimer();

private:
    QList<QString> users;
    int frame;
    QTimer* timer;

    QString Frame();

};

#endif // THUMBNAILLISTCONTROL_H
