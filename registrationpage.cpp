#include "registrationpage.h"

RegistrationPage::RegistrationPage()
{
    this->setTitle("Registration");

    log="";
    pass="";

    QGraphicsLinearLayout *v=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());
    QGraphicsLinearLayout *h1=new QGraphicsLinearLayout(Qt::Horizontal);
    QGraphicsLinearLayout *h2=new QGraphicsLinearLayout(Qt::Horizontal);
    QGraphicsLinearLayout *h3=new QGraphicsLinearLayout(Qt::Horizontal);

    h_line=new MLabel("<hr>");
    en_log=new MLabel("Enter login:");
    en_pass=new MLabel("Enter password:");
    rep_pass=new MLabel("Repeat password:");

    reg=new MButton("Registration");

    login=new MTextEdit();
    password=new MTextEdit();
    repeat=new MTextEdit();

    password->setEchoMode(MTextEditModel::Password);
    repeat->setEchoMode(MTextEditModel::Password);

    h1->addItem(en_log);
    h1->addItem(login);
    h2->addItem(en_pass);
    h2->addItem(password);
    h3->addItem(rep_pass);
    h3->addItem(repeat);

    int maxWidth=230;

    en_log->setMaximumWidth(maxWidth);
    en_pass->setMaximumWidth(maxWidth);
    rep_pass->setMaximumWidth(maxWidth);
    en_log->setMinimumWidth(maxWidth);
    en_pass->setMinimumWidth(maxWidth);
    rep_pass->setMinimumWidth(maxWidth);

    v->addItem(h1);
    v->addItem(h2);
    v->addItem(h3);
    v->addItem(h_line);
    v->addItem(reg);
    v->addStretch();

    connect(reg,SIGNAL(clicked()),this,SLOT(tryToReg()));
}

void RegistrationPage::tryToReg()
{
    QString str1,str2;
    str1=repeat->text();
    str2=password->text();
    if(str1==str2)
    {
        log=login->text();
        pass=password->text();
    }
    else
    {
        log="";
        pass="";
        //say that error in password
    }
    str1="";
    str1="#type/log#o/registration#l/"+log+"#p/"+pass;
    login->clear();
    password->clear();
    repeat->clear();
    emit readySend(str1);
}
