#include "mainwindow.h"
#include "homepage.h"
#include "loginpage.h"
#include "settingpage.h"
#include <MMessageBox>
#include "contactlistpage.h"
#include <QDebug>

MainWindow::MainWindow():MApplicationWindow()
{
    page1=new HomePage(this);
    page2 =new LoginPage(this);
    page3=new RegistrationPage(this);
    page4=new SettingPage(this);
    page5 =new InfoPage(this);
    page6 = new ContactlistPage();
    sock= new ClientSocket();
    //sock->ConnectToHost();
    thread1=new SendThread(sock);
    thread2=new RecvThread(sock);
    page1->appear();
    //переходы со страницы home на все остальные
    QObject::connect(page1,SIGNAL(goLoginPage()),this,SLOT(GoLoginPage()));
    QObject::connect(page1,SIGNAL(exiting()),this,SLOT(close()));
    QObject::connect(page1,SIGNAL(goRegistrationPage()),page3,SLOT(appear()));
    QObject::connect(page1,SIGNAL(goSettingPage()),page4,SLOT(appear()));
    QObject::connect(page1,SIGNAL(goContactListPage()),this,SLOT(GoContactListPage()));
    QObject::connect(page2,SIGNAL(goHomePage()),this,SLOT(GoHomePage()));
    QObject::connect(page1,SIGNAL(goInfoPage()),page5,SLOT(appear()));
    QObject::connect(page2,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));
    QObject::connect(page3,SIGNAL(readySend(QString)),this,SLOT(StartSendThread(QString)));
    QObject::connect(page4,SIGNAL(changeSettings()),this,SLOT(ApplyNewSettings()));
    QObject::connect(thread2,SIGNAL(readyMessage(Message*)),this,SLOT(ListenServer(Message*)));
}
void MainWindow::ListenServer(Message * mes)
{
    mes->Parse();
    if ("ser*ver"==mes->GetPart("s"))
   {
        if ("good login-password"==mes->GetPart("m"))
        {
            MMessageBox* r=new MMessageBox("Title","Welcom",M::OkButton);
            r->appear(this);
            page6->appear();
        }

        if ("good registration"==mes->GetPart("m"))
            page2->appear();

        if(mes->GetPart("m")=="login is already used")
        {
            MMessageBox* r=new MMessageBox("Error!","This user online already",M::OkButton);
            r->appear(this);
        }

        if(mes->GetPart("m")=="Error of password")
        {
            MMessageBox* r=new MMessageBox("Error!","Error of password",M::OkButton);
            r->appear(this);
        }

        if(mes->GetPart("m")=="Error of login")
        {
            MMessageBox* r=new MMessageBox("Error!","This login doesn`t find in contacts base",M::OkButton);
            r->appear(this);
        }

        if(mes->GetPart("m")=="Login already exist")
        {
            MMessageBox* r=new MMessageBox("Error!","Login already exist",M::OkButton);
            r->appear(this);
        }
    }

    else
    {

         if ("connect"==mes->GetPart("o"))
        {
            page6->Add(QString::fromStdString(mes->GetPart("s")),QString::fromStdString(mes->GetPart("o")));
        }
        if ("disconnect"==mes->GetPart("o"))
        {
            page6->Remove(QString::fromStdString(mes->GetPart("s")));
        }
    }

    delete mes;
}
void MainWindow::GoContactListPage()
{
    page6->appear();
}
void MainWindow::GoHomePage()
{
    page1->disappear();
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
void MainWindow::GoLoginPage(){

    page2->appear();
}
