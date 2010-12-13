#include <QDebug>
#include "MessageAnimation.h"

#define MESS_FRAME_0 "usr/share/Meego-KVP-Client/style/message64x64.svg"
#define MESS_FRAME_1 "usr/share/Meego-KVP-Client/style/empty.svg"

#define GREEN "usr/share/Meego-KVP-Client/style/green64x64.svg"
#define RED "usr/share/Meego-KVP-Client/style/red64x64.svg"

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
    {
        users.removeAll(username);
        QTimer::singleShot(4000, this, SLOT(startUnread()));
    }

}

bool MessageAnimation::hasMessage(QString username)
{
    if (!users.empty())
        return users.contains(username);
    else
        return false;
}

void MessageAnimation::reStart()
{
    if(!(timer->isActive()))
        timer->start(200);
}

void MessageAnimation::moveFrame()
{
    emit update();
    frame = !frame;
}

void MessageAnimation::startUnread()
{
    if(!users.empty())
    {
        if(!(timer->isActive()))
            timer->start(200);
    }
    else
        emit update();
}

void MessageAnimation::RemoveUser(QString username)
{
    users.removeAll(username);
}

QString MessageAnimation::Frame()
{
    if(frame == 0)
        return MESS_FRAME_0;
    else
        return MESS_FRAME_1;
}

QString MessageAnimation::Thumbnail( QString username, QString status )
{
    qDebug()<<">>>MainPage::GetTumbnailPath(QString username, QString status)";

    if (hasMessage(username))
    {
        return Frame();
    }

    if (status == "connect")
    {
        return GREEN;
    }
    else
    {
        return RED;
    }
}

