#include "homepage.h"

HomePage::HomePage()
{

    this->setTitle("Home Page");
    VLay=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());

    con_list=new MButton("Contact list");
    settings=new MButton("Settings");
    registration=new MButton("Registration");
    login=new MButton("Login / Relogin");
    exit = new MButton("Exit");
    about =new MButton("About");

    VLay->addItem(login);
    VLay->addItem(con_list);
    VLay->addItem(registration);
    VLay->addItem(settings);
    VLay->addItem(about);
    VLay->addItem(exit);
    VLay->setSpacing(-20);
    int size =65;

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

    connect(login,SIGNAL(clicked()),SIGNAL(goLoginPage()));
    connect(con_list,SIGNAL(clicked()),SIGNAL(goContactListPage()));
    connect(registration,SIGNAL(clicked()),SIGNAL(goRegistrationPage()));
    connect(settings,SIGNAL(clicked()),SIGNAL(goSettingPage()));
    connect(about,SIGNAL(clicked()),SIGNAL(goInfoPage()));
    connect(exit,SIGNAL(clicked()),SIGNAL(exiting()));

}

