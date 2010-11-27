#include "loginpage.h"

//extern SendThread* thread1;

 LoginPage::LoginPage()

{
     this->setTitle("Autorization");

             QGraphicsLinearLayout *lay;
             QGraphicsLinearLayout *hEnter,*home,*Hlogin,*VEdit,*VLabel,*last;
             log_lab=new MLabel ("    Enter your login");
             pass_lab=new MLabel("Enter your password");

             log_lab->setAlignment(Qt::AlignCenter);
             pass_lab->setAlignment(Qt::AlignCenter );

             lay=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());
             home=new QGraphicsLinearLayout(Qt::Horizontal);
             hEnter=new QGraphicsLinearLayout(Qt::Horizontal);
             Hlogin=new QGraphicsLinearLayout(Qt::Horizontal);
             VEdit=new QGraphicsLinearLayout(Qt::Vertical);
             VLabel=new QGraphicsLinearLayout(Qt::Vertical);
             last=new QGraphicsLinearLayout(Qt::Horizontal);

              mylogin=new MTextEdit();
              password=new MTextEdit();

             password->setEchoMode(MTextEditModel::Password);
             mylogin->setReadOnly(false);
             password->setReadOnly(false);

             VEdit->addItem(mylogin);
             VEdit->addItem(password);

             VLabel->addItem(log_lab);
             VLabel->addItem(pass_lab);

             Hlogin->addItem(VLabel);
             Hlogin->addItem(VEdit);

             but=new MButton("Home");
             lab=new MLabel("");
             line=new MLabel("<hr>");
             home->addItem(lab);
             home->addItem(but);
             home->setStretchFactor(but,Qt::StretchTile);
             home->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
             VLabel->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

             //Button creating-------------------------------------------------
             enter=new MButton("                    Login                   ");
             hEnter->addItem(new MLabel(""));
             hEnter->addItem(enter);
             hEnter->setStretchFactor(enter,Qt::StretchTile);
             but->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
             lay->setStretchFactor(home,Qt::StretchTile);
             lay->addItem(home);
             lay->addItem(line);
             lay->addItem(Hlogin);
             lay->addItem(hEnter);

             connect(enter,SIGNAL(clicked()),this,SLOT(login()));
             connect(but,SIGNAL(clicked()),SIGNAL(goHomePage()));
}



void LoginPage::login(){

        QString badnick = "ser*ver";
        QString str ="";

        if(mylogin->text()!="" && password->text()!="" )//если не пустые
        {

             if(mylogin->text()!=badnick && mylogin->text().length()<15 && mylogin->text()[0] != '#' && mylogin->text().contains('*',Qt::CaseInsensitive) == false)
                //имя не=ser*ver, не больше 15 символов и первый симовл не # ,не содержит * а пароль меньше 10 симолов
            {
                    if(password->text().length()<10){
                            str ="#type/log#o/login#l/" + mylogin->text() + "#p/" + password->text(); //отправляем сформированную строку-сообщение
                            emit readySend(str);
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





