#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <MApplicationWindow>
#include "sendthread.h"
#include "clientsocket.h"
#include "homepage.h"
#include "loginpage.h"
#include "registrationpage.h"
#include "settingpage.h"
#include "infopage.h"
#include "contactlistpage.h"
#include "message.h"
#include "recvclass.h"
#include "dialogpage.h"

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
    SettingPage *page4;
    InfoPage *page5;
    ContactlistPage* page6;
    DialogPage* page7;
    SendThread* thread1;
    RecvThread* thread2;

public slots:
    void StartSendThread(QString);
    void ApplyNewSettings();
    void GoLoginPage();
    void GoHomePage();
    void GoContactListPage();
    void ListenServer(Message* mes);
    void GoDialogPage(QString);

signals:
    void incomingMessage(QString, QString);

};

#endif // MAINWINDOW_H
