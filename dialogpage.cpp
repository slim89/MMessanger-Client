#include "dialogpage.h"

DialogPage::DialogPage(MApplicationWindow* w)
{
    this->setTitle("UserName");

    v=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());
    h2=new QGraphicsLinearLayout(Qt::Horizontal);
    send=new MButton("Send");
    chat=new MTextEdit(MTextEditModel::MultiLine);
    message=new MTextEdit(MTextEditModel::MultiLine);

    chat->setReadOnly(true);

    h2->addItem(message);
    h2->addItem(send);
    h2->setMaximumHeight(80);
    send->setMinimumWidth(160);

    v->addItem(chat);
    v->addItem(h2);

    connect(send,SIGNAL(clicked()),message,SLOT(clear()));
}

void DialogPage::appearPage(QString username)
{
    this->setTitle(username);
    this->appear();
}
