#include "loginpage.h"
#include <MMessageBox>
 LoginPage::LoginPage(MApplicationWindow* wind)

{
            this->setTitle("Autorization");
             VLay=new QGraphicsGridLayout(this->centralWidget());

             l_line=new MLabel("<hr>");
             l_login=new MLabel("Enter login:");
             l_pass=new MLabel("Enter password:");
             ok=new MButton("OK");
             home=new MButton("Home");
             l_lab=new MLabel("");

             t_login=new MTextEdit();
             t_pass=new MTextEdit();
             t_login->setEnabled(true);
             t_pass->setEnabled(true);

             t_pass->setEchoMode(MTextEditModel::Password);


             maxWidth_label = wind->size().width()/4;
             maxHeigh = wind->size().height()/5.7;
             maxWidth_edit =  maxWidth_edit - maxWidth_label;


             l_login->setMaximumWidth(maxWidth_label);
             l_login->setMinimumWidth(maxWidth_label);
             l_pass->setMaximumWidth(maxWidth_label);
             l_pass->setMinimumWidth(maxWidth_label);


             ok->setMaximumWidth(maxWidth_label);
             ok->setMinimumWidth(maxWidth_label);

             home->setMaximumWidth(maxWidth_label);
             home->setMinimumWidth(maxWidth_label);

             l_login->setMaximumHeight(maxHeigh);
             l_login->setMinimumHeight(maxHeigh);
             l_pass->setMaximumHeight(maxHeigh);
             l_pass->setMinimumHeight(maxHeigh);


             t_login->setMaximumHeight(maxHeigh);
             t_login->setMinimumHeight(maxHeigh);
             t_pass->setMinimumHeight(maxHeigh);
             t_pass->setMaximumHeight(maxHeigh);


             ok->setMaximumHeight(maxHeigh);
             ok->setMinimumHeight(maxHeigh);
             home->setMaximumHeight(maxHeigh);
             home->setMinimumHeight(maxHeigh);

             l_line->setMinimumHeight(maxHeigh/2);
             l_line->setMaximumHeight(maxHeigh/2);

             VLay->addItem(home,1,2);
             VLay->addItem(l_line,2,1,1,2);

             VLay->addItem(l_login,3,1);
             VLay->addItem(t_login,3,2);

             VLay->addItem(l_pass,4,1);
             VLay->addItem(t_pass,4,2);

             VLay->addItem(ok,5,2);

             VLay->setAlignment(ok,Qt::AlignRight);
             VLay->setAlignment(home,Qt::AlignRight);
             VLay->setSpacing(-3);
             connect(ok,SIGNAL(clicked()),this,SLOT(login()));
             connect(home,SIGNAL(clicked()),SIGNAL(goHomePage()));
}
void LoginPage::login(){
        QString badnick = "ser*ver";
        QString str ="";
        QString log ="";
        QString pass ="";
        if(t_login->text()!="" && t_pass->text()!="" )//если не пустые
        {
            log = t_login->text();
            pass = t_pass->text();
             if(log!=badnick && log.length()<15 && log[0] != '#' && log.contains('*',Qt::CaseInsensitive) == false)
                //имя не=ser*ver, не больше 15 символов и первый симовл не # ,не содержит * а пароль меньше 10 симолов
            {
                    if(pass.length()<10){
                        str ="#type/log#o/login#id/" + log + "#p/" + pass+"#/"; //отправляем сформированную строку-сообщение
                            emit readySend(str);
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
            MMessageBox* r=new MMessageBox("Error!","Please fill in all fields",M::OkButton);//сообшение не заполнили все поля
            r->appear();
        }

    }
