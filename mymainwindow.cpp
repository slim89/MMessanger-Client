#include "mymainwindow.h"
#include "homepage.h"
#include "loginpage.h"

MyMainWindow::MyMainWindow():MApplicationWindow()
{

    page1=new HomePage();
    page2 =new LoginPage();
    page3=new RegistrationPage();
    sock= new ClientSocket();
    sock->ConnectToHost();
    thread1=new SendThread(sock);

    page1->appear();


    //переходы со страницы home на все остальные
    QObject::connect(page1,SIGNAL(goLoginPage()),page2,SLOT(appear()));
    QObject::connect(page1,SIGNAL(exiting()),this,SLOT(close()));
    QObject::connect(page1,SIGNAL(goRegistrationPage()),page3,SLOT(appear()));

    QObject::connect(page3,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));

    QObject::connect(page2,SIGNAL(goHomePage()),page1,SLOT(appear()));
    QObject::connect(page2,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));
}

void MyMainWindow::StartSendThread(QString buf)
{
    thread1->set(buf);
    thread1->start();
}
