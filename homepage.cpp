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

    VLay->addItem(login);
    VLay->addItem(con_list);
    VLay->addItem(registration);
    VLay->addItem(settings);
    VLay->addItem(exit);

    int size =70;

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

    connect(login,SIGNAL(clicked()),SIGNAL(goLoginPage()));
    connect(con_list,SIGNAL(clicked()),SIGNAL(goContactListPage()));
    connect(registration,SIGNAL(clicked()),SIGNAL(goRegistrationPage()));
    //connect(settings,SIGNAL(clicked()),SLOT());
    connect(exit,SIGNAL(clicked()),SIGNAL(exiting()));
}

