#include "registrationpage.h"
#include "QDebug"
#include <MMessageBox>
RegistrationPage::RegistrationPage(MApplicationWindow* wind)
{
    this->setTitle("Registration");
    log="";
    pass="";
    VLay=new QGraphicsGridLayout(this->centralWidget());

    l_line=new MLabel("<hr>");
    l_login=new MLabel("Enter login:");
    l_pass=new MLabel("Enter password:");
    l_repeat=new MLabel("Repeat password:");
    ok=new MButton("OK");

    t_login=new MTextEdit();
    t_pass=new MTextEdit();
    t_repeat=new MTextEdit();

    t_pass->setEchoMode(MTextEditModel::Password);
    t_repeat->setEchoMode(MTextEditModel::Password);

    maxWidth_label = wind->size().width()/4;
    maxHeigh = wind->size().height()/5.7;
    maxWidth_edit =  maxWidth_edit - maxWidth_label;


    l_login->setMaximumWidth(maxWidth_label);
    l_login->setMinimumWidth(maxWidth_label);
    l_pass->setMaximumWidth(maxWidth_label);
    l_pass->setMinimumWidth(maxWidth_label);
    l_repeat->setMaximumWidth(maxWidth_label);
    l_repeat->setMinimumWidth(maxWidth_label);

    ok->setMaximumWidth(maxWidth_label);
    ok->setMinimumWidth(maxWidth_label);

    l_login->setMaximumHeight(maxHeigh);
    l_login->setMinimumHeight(maxHeigh);
    l_pass->setMaximumHeight(maxHeigh);
    l_pass->setMinimumHeight(maxHeigh);
    l_repeat->setMaximumHeight(maxHeigh);
    l_repeat->setMinimumHeight(maxHeigh);

    t_login->setMaximumHeight(maxHeigh);
    t_login->setMinimumHeight(maxHeigh);
    t_pass->setMinimumHeight(maxHeigh);
    t_pass->setMaximumHeight(maxHeigh);
    t_repeat->setMinimumHeight(maxHeigh);
    t_repeat->setMaximumHeight(maxHeigh);

    ok->setMaximumHeight(maxHeigh);
    ok->setMinimumHeight(maxHeigh);

    l_line->setMinimumHeight(maxHeigh/2);
    l_line->setMaximumHeight(maxHeigh/2);


    VLay->addItem(l_login,1,1);
    VLay->addItem(t_login,1,2);

    VLay->addItem(l_pass,2,1);
    VLay->addItem(t_pass,2,2);

    VLay->addItem(l_repeat,3,1);
    VLay->addItem(t_repeat,3,2);

    VLay->addItem(l_line,4,1,1,2);

    VLay->addItem(ok,5,2);

    VLay->setAlignment(ok,Qt::AlignRight);
    VLay->setSpacing(-3);
    connect(ok,SIGNAL(clicked()),this,SLOT(tryToReg()));
}

void RegistrationPage::tryToReg()
{
    QString str1,str2;
    QString badnick = "ser*ver";

    str1=t_repeat->text();
    str2=t_pass->text();

    if(str1==str2)
    {
        log=t_login->text();
        pass=t_pass->text();
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
                            MMessageBox* r=new MMessageBox("Error!","Incorrect password",M::OkButton);//сообщение некорректный пароль

                            r->appear();
                    }
            }
            else
            {
                 MMessageBox* r=new MMessageBox("Error!","Incorrect login",M::OkButton);//сообщение некорректный логин
                 r->appear();
            }


        }
        else
        {

             MMessageBox* r=new MMessageBox("Error!","Please fill in all fields",M::OkButton); //сообшение не заполнили все поля
            r->appear();
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
    t_login->clear();
    t_pass->clear();
    t_repeat->clear();

}
