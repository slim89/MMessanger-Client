#include "homepage.h"
#include <QDebug>
HomePage::HomePage(MApplicationWindow* wind):MApplicationPage()
{

    this->setTitle("Home Page");
    VLay=new QGraphicsGridLayout(this->centralWidget());
    im=new MImageWidget(this->centralWidget());
    QPixmap pp("usr/share/Meego-KVP-Client/style/logo.gif");
    im->setPixmap(pp);

    VLay=new QGraphicsGridLayout(this->centralWidget());

    con_list=new MButton("Contact list");
    settings=new MButton("Settings");
    registration=new MButton("Registration");
    login=new MButton("Login / Relogin");
    exit = new MButton("Exit");
    about =new MButton("About");

    //settings->setEnabled(false);

    empty_label=new MLabel("");

    size_but = wind->size().width()/2;
    size = wind->size().height()/5.7;

    empty_label->setMinimumWidth(size_but);
    empty_label->setMaximumWidth(size_but);
    exit->setMinimumWidth(size_but);
    exit->setMaximumWidth(size_but);

    login->setMaximumHeight(size);
    login->setMinimumHeight(size);
    con_list->setMaximumHeight(size);
    con_list->setMinimumHeight(size);
    registration->setMaximumHeight(size);
    registration->setMinimumHeight(size);
    settings->setMaximumHeight(size);
    settings->setMinimumHeight(size);
    exit->setMaximumHeight(size);
    exit->setMinimumHeight(size);
    about->setMaximumHeight(size);
    about->setMinimumHeight(size);

    login->setMaximumWidth(size_but);
    login->setMinimumWidth(size_but);
    con_list->setMaximumWidth(size_but);
    con_list->setMinimumWidth(size_but);
    registration->setMaximumWidth(size_but);
    registration->setMinimumWidth(size_but);
    settings->setMaximumWidth(size_but);
    settings->setMinimumWidth(size_but);
    exit->setMaximumWidth(size_but);
    exit->setMinimumWidth(size_but);
    about->setMaximumWidth(size_but);
    about->setMinimumWidth(size_but);

    VLay->addItem(im,1,1,4,1);

   // VLay->addItem(empty_label,1,1,4,1);
    VLay->addItem(con_list,1,2);
    VLay->addItem(login,2,2);
    VLay->addItem(settings,3,2);
    VLay->addItem(registration,4,2);
    VLay->addItem(about,5,2);
    VLay->addItem(exit,5,1);
    VLay->setSpacing(-11);

    connect(login,SIGNAL(clicked()),SIGNAL(goLoginPage()));
    connect(con_list,SIGNAL(clicked()),SIGNAL(goContactListPage()));
    connect(registration,SIGNAL(clicked()),SIGNAL(goRegistrationPage()));
    connect(settings,SIGNAL(clicked()),SIGNAL(goSettingPage()));
    connect(about,SIGNAL(clicked()),SIGNAL(goInfoPage()));
    connect(exit,SIGNAL(clicked()),SIGNAL(exiting()));

}

