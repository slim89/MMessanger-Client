#include <MApplication>
#include <MApplicationWindow>
#include <MApplicationPage>
#include <QObject>
#include <QGraphicsLinearLayout>

#include "homepage.h"
#include "registrationpage.h"


#include "loginpage.h"
#include "clientsocket.h"
#include "sendthread.h"

ClientSocket* sock= new ClientSocket();
SendThread* thread1 = new SendThread(0,sock);

int main(int argc, char *argv[])
{
    MApplication a(argc, argv);
    MApplicationWindow w;
    MApplicationPage p;
    HomePage *page1=new HomePage();
    LoginPage *page2 =new LoginPage();
    RegistrationPage *page3=new RegistrationPage();

    QGraphicsLinearLayout *lay=new QGraphicsLinearLayout(Qt::Vertical,p.centralWidget());

    MButton *button1=new MButton("HomePage");
    MButton *button2=new MButton("LoginPage");
    MButton *button3=new MButton("RegistrationPage");

    lay->addItem(button1);
    lay->addItem(button2);
    lay->addItem(button3);

    w.show();
    p.appear();

    QObject::connect(button1,SIGNAL(clicked()),page1,SLOT(appear()));
    QObject::connect(button2,SIGNAL(clicked()),page2,SLOT(appear()));
    QObject::connect(button3,SIGNAL(clicked()),page3,SLOT(appear()));

    QObject::connect(page1,SIGNAL(exiting()),&w,SLOT(close()));
    QObject::connect(page1,SIGNAL(goRegistrationPage()),page2,SLOT(appear()));

    return a.exec();
}
