#include <QDebug>
#include "MessageAnimation.h"
#include "config.h"

MessageAnimation::MessageAnimation()
{
    frame = 0;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(moveFrame()));
}

MessageAnimation::~ MessageAnimation()
{
    if ( timer->isActive() )
        timer->stop();
    delete timer;
}

void MessageAnimation::Start(QString username)
{
    if(!hasMessage(username))
    {
        users << username;
        //UpdateContacts(contactsList);
    }

    if (!timer->isActive())
        timer->start(200);
}

void MessageAnimation::Stop(QString username)
{
    if ( timer->isActive() )
        timer->stop();

    if(hasMessage(username))
        users.removeAll(username);

    //QTimer::singleShot(4000, this, SLOT(startUnread()));

}

bool MessageAnimation::hasMessage(QString username)
{
    if (!users.empty())
        return users.contains(username);
    else
        return false;
}

void MessageAnimation::moveFrame()
{
    emit update();
    frame = !frame;
}

void MessageAnimation::RemoveUser(QString username)
{
    users.removeAll(username);
}

QString MessageAnimation::Frame()
{
    QString message_frame( KVP_THEMES_SVG_DIR );

    message_frame += KVP_THEMES_MESS_ICON;

    if(frame == 0)
        return message_frame;
    else
        return "";
}

QString MessageAnimation::Thumbnail( QString username, QString status )
{
    qDebug()<<">>>MessageAnimation::Thumbnail(QString username, QString status)";

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

void MessageAnimation::StartAll()
{
    if(!users.empty())
    {
        qDebug()<<">>>MessageAnimation::StartAll() : users: "<<users;
        if(!(timer->isActive()))
            timer->start(200);
    }
    else
        emit update();

}
