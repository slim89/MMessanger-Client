#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <MApplicationWindow>
#include "sendthread.h"
#include "clientsocket.h"
#include "homepage.h"
#include "loginpage.h"
#include "registrationpage.h"

class MyMainWindow : public MApplicationWindow
{
    Q_OBJECT
public:
    MyMainWindow();

private:
    ClientSocket* sock;
    HomePage *page1;
    LoginPage *page2;
    RegistrationPage *page3;
    SendThread* thread1;

public slots:
    void StartSendThread(QString);
};

#endif // MAINWINDOW_H
