#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <MApplicationWindow>
#include "sendthread.h"
#include "clientsocket.h"
#include "homepage.h"
#include "loginpage.h"
#include "registrationpage.h"
#include "recvclass.h"
#include "message.h"

class MainWindow : public MApplicationWindow
{
    Q_OBJECT
public:
    MainWindow();

private:
    ClientSocket* sock;
    HomePage *page1;
    LoginPage *page2;
    RegistrationPage *page3;
    SendThread* thread1;
    RecvThread* thread2;


public slots:
    void StartSendThread(QString);
    void SelectOperation(Message*);
};

#endif // MAINWINDOW_H
