#include "infopage.h"

InfoPage::InfoPage()
{
    this->setTitle("Attention!");
    VLay=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());

    okbut=new MButton("OK");
    info_label = new MLabel("");

    VLay->addItem(info_label);
    VLay->addItem(okbut);

    okbut->setMaximumSize(200,70);


    //виды ошибок  и предупреждений
    list << "You do not enter your username or password "
    << "Incorrect login. Username can not contain the symbol \n '*' and start with '#', and be longer than 15 characters"
    << "Incorrect password. The password can not be longer than \n 10 characters"
   ;
    connect(okbut,SIGNAL(clicked()),this,SLOT(GoNext()));//не работает!!!!

}
void InfoPage::setInfoMessage(int number){
    info_label->setText(list[number]);

}
void InfoPage::GoNext(){
    emit this->backButtonClicked();
}
