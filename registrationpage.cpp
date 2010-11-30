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
    QString badnick = "ser*ver";

    str1=repeat->text();
    str2=password->text();

    if(str1==str2)
    {
        log=login->text();
        pass=password->text();
        if(log!="" && pass!="" )//если не пустые
        {

             if(log!=badnick &&log.length()<15 && log[0] != '#' && log.contains('*',Qt::CaseInsensitive) == false)
                //имя не=ser*ver, не больше 15 символов и первый симовл не # ,не содержит * а пароль меньше 10 симолов
            {
                    if(pass.length()<10){
                           str1="#type/log#o/registration#l/"+log+"#p/"+pass; //отправляем сформированную строку-сообщение
                           emit readySend(str1);
                    }
                    else{
                            emit loadInfoPage(2);//сообщение некорректный пароль
                    }
            }
            else
            {
                 emit loadInfoPage(1);//сообщение некорректный логин
            }


        }
        else
        {

            emit loadInfoPage(0);//сообшение не заполнили все поля
        }
    }
    else
    {
        log="";
        pass="";
        emit loadInfoPage(3);
    }

    badnick.clear();
    str1.clear();
    login->clear();
    password->clear();
    repeat->clear();

}
