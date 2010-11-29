#include "mainwindow.h"
#include "homepage.h"
#include "loginpage.h"
#include "settingpage.h"
#include <MMessageBox>
#include "contactlistpage.h"

MainWindow::MainWindow():MApplicationWindow()
{

    page1=new HomePage();
    page2 =new LoginPage();
    page3=new RegistrationPage();
    page4=new SettingPage();
    page5 = new InfoPage();
    page6 = new ContactListPage();
    sock= new ClientSocket();
    sock->ConnectToHost();

    thread1=new SendThread(sock);
    thread2=new RecvThread(sock);

    page1->appear();


    //переходы со страницы home на все остальные
    QObject::connect(page1,SIGNAL(goLoginPage()),this,SLOT(GoLoginPage()));
    QObject::connect(page1,SIGNAL(exiting()),this,SLOT(close()));
    QObject::connect(page1,SIGNAL(goRegistrationPage()),this,SLOT(GoRegistrationPage()));
    QObject::connect(page1,SIGNAL(goSettingPage()),this,SLOT(GoSettingPage()));
    QObject::connect(page1,SIGNAL(goContactListPage()),this,SLOT(GoContactListPage()));

    QObject::connect(page3,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));
    QObject::connect(page2,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));

    QObject::connect(page2,SIGNAL(goHomePage()),this,SLOT(GoHomePage()));
    QObject::connect(page4,SIGNAL(changeSettings()),this,SLOT(ApplyNewSettings()));
    QObject::connect(page2,SIGNAL(loadInfoPage(int)),this,SLOT(GoInfoPage(int)));
    QObject::connect(page3,SIGNAL(loadInfoPage(int)),this,SLOT(GoInfoPage(int)));

    QObject::connect(thread2,SIGNAL(readyMessage(Message*)),this,SLOT(ListenServer(Message*)));
}

void MainWindow::ListenServer(Message * mes)
{
    mes->Parse();
    if ("ser*ver"==mes->GetPart("s"))
    {
        if ("good login-password"==mes->GetPart("m"))
        {
            MMessageBox* r=new MMessageBox("Title","Hi",M::OkButton);

            r->appear(this);
            page6->appear();
        }
        if ("good registration"==mes->GetPart("m"))
            page2->appear();
    }
   /* if ("connect"==mes->GetPart("o"))
    {
        page6->Add();
    }*/
    delete mes;
}
void MainWindow::GoContactListPage()
{
    page6->appear();
}
void MainWindow::GoHomePage()
{
    page2->disappear();
    page3->disappear();
    page4->disappear();
    page5->disappear();
    page6->disappear();
    page1->appear();

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
void  MainWindow::GoInfoPage(int number)
{

    page5->setInfoMessage(number);
   page5->appear();

}
void MainWindow::GoRegistrationPage(){
    page3->appear();
}

void MainWindow::GoSettingPage(){
    page4->appear();
}
void MainWindow::GoLoginPage(){
    page2->appear();
}
