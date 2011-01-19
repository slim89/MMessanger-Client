#include <QDebug>
#include "ThumbnailListControl.h"
#include "config.h"

#define START_TIME 0

ThumbnailListControl::ThumbnailListControl()
{
    frame = 0;

#ifdef MESSAGE_ANIMATION
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(moveFrame()));
#endif
}

ThumbnailListControl::~ ThumbnailListControl()
{
#ifdef MESSAGE_ANIMATION
    if ( timer->isActive() )
        timer->stop();
    delete timer;
#endif
}

void ThumbnailListControl::Start(QString username)
{
    if(!hasMessage(username))
    {
        users << username;
        //UpdateContacts(contactsList);
    }
#ifdef MESSAGE_ANIMATION
    if(!(timer->isActive()))
        timer->start(200);
#else
        emit update();
#endif
}

void ThumbnailListControl::Stop(QString username)
{
#ifdef MESSAGE_ANIMATION
    if ( timer->isActive() )
        timer->stop();
#endif

    if(hasMessage(username))
        users.removeAll(username);

    frame = 0;
    //QTimer::singleShot(4000, this, SLOT(StartOnTimer()));

}

bool ThumbnailListControl::hasMessage(QString username)
{
    if (!users.empty())
        return users.contains(username);
    else
        return false;
}

void ThumbnailListControl::moveFrame()
{
    emit update();
    frame = !frame;
}

void ThumbnailListControl::StartOnTimer()
{
    if(!(timer->isActive()))
        timer->start(200);
}

void ThumbnailListControl::RemoveUser(QString username)
{
    users.removeAll(username);
}

void ThumbnailListControl::AddUser(QString username)
{
    users << username;
}

QString ThumbnailListControl::Frame()
{
    QString message_frame( KVP_THEMES_SVG_DIR );

    message_frame += KVP_THEMES_MESS_ICON;

    if(frame == 0)
        return message_frame;
    else
        return "";
}

QString ThumbnailListControl::Thumbnail( QString username, QString status )
{
    qDebug()<<">>>ThumbnailListControl::Thumbnail(QString username, QString status)";

    QString status_icon( KVP_THEMES_SVG_DIR );

    if (hasMessage(username))
    {
        return Frame();
    }

    if (status == "connect")
    {
        status_icon += KVP_THEMES_ON_ICON;
    }
    else
    {
        status_icon +=  KVP_THEMES_OFF_ICON;
    }

    return status_icon;
}

void ThumbnailListControl::StartAll()
{
    if(!users.empty())
    {
        qDebug()<<">>>ThumbnailListControl::StartAll() : users: "<<users;
#ifdef MESSAGE_ANIMATION
        QTimer::singleShot(START_TIME, this, SLOT(StartOnTimer()));
#else
        emit update();
#endif
    }
    else
        emit update();

}

int ThumbnailListControl::getTimerID()
{
    return timer->timerId();
}

QList<QString> ThumbnailListControl::getUsers()
{
    return users;
}

void ThumbnailListControl::StopAnimation()
{
#ifdef MESSAGE_ANIMATION
    if ( timer->isActive() )
        timer->stop();
#endif

    frame = 0;

    emit update();
}

