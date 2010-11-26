#include "mainwindow.h"
#include "homepage.h"
#include "loginpage.h"
#include "settingpage.h"

MainWindow::MainWindow():MApplicationWindow()
{

    page1=new HomePage();
    page2 =new LoginPage();
    page3=new RegistrationPage();
    page4=new SettingPage();
    sock= new ClientSocket();
    sock->ConnectToHost();
    thread1=new SendThread(sock);

    page1->appear();


    //переходы со страницы home на все остальные
    QObject::connect(page1,SIGNAL(goLoginPage()),page2,SLOT(appear()));
    QObject::connect(page1,SIGNAL(exiting()),this,SLOT(close()));
    QObject::connect(page1,SIGNAL(goRegistrationPage()),page3,SLOT(appear()));
    QObject::connect(page1,SIGNAL(goSettingPage()),page4,SLOT(appear()));

    QObject::connect(page3,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));

    QObject::connect(page2,SIGNAL(goHomePage()),page1,SLOT(appear()));
    QObject::connect(page2,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));

    QObject::connect(page4,SIGNAL(changeSettings()),this,SLOT(ApplyNewSettings()));
}

void MainWindow::ApplyNewSettings()
{
    sock->SetSettings(page4->GetIPAdrr(),page4->GetPort());

}
void MainWindow::StartSendThread(QString buf)
{
    thread1->set(buf);
    thread1->start();
}
