#include "loginpage.h"
#include "sendthread.h"


extern SendThread* thread1;

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

}

void  LoginPage::show_login(){



}
void LoginPage::login(){
        QString str ="";
        //отправляем сформированную строку-сообщение
        str ="#type/log#o/login#l/" + mylogin->text()+ "#p/" + password->text();
        thread1->set(str);
        thread1->start();
}
