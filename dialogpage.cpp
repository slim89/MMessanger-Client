#include "dialogpage.h"
#include <QDebug>

DialogPage::DialogPage(MApplicationWindow* w)
{
    this->setTitle("UserName");

    v=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());
    h2=new QGraphicsLinearLayout(Qt::Horizontal);
    send=new MButton("Send");
    chat=new MTextEdit(MTextEditModel::MultiLine);
    message=new MTextEdit(MTextEditModel::MultiLine);

    //chat->setReadOnly(true);
    chat->setMaximumHeight(290);
    h2->addItem(message);
    h2->addItem(send);
    h2->setMaximumHeight(80);
    send->setMinimumWidth(160);

    v->addItem(chat);
    v->addItem(h2);

    connect(send,SIGNAL(clicked()),this,SLOT(sendClick()));
}

void DialogPage::appearPage(QString username)
{
    this->setTitle(username);
    this->appear();
}

void DialogPage::sendClick()
{
    QString str;
    chat->setText(chat->text()+"I`m:\n  "+message->text()+"\n");
    str="#type/send#r/"+this->title()+"#m/"+Screen(message->text())+"#/";
    qCritical()<<str;
    emit readySend(str);
    message->clear();
}

QString DialogPage::Screen(QString str)
{
    QString s;
    s="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='#')
        {
            s=s+str[i]+'\'';
        }
        else
        {
            s=s+str[i];
        }
    }
    return s;
}

QString DialogPage::unScreen(QString str)
{
    QString s;
    s="";
    int i=0;
    while(i<str.size())
    {
        s=s+str[i];
        if(str[i]=='#')
        {
            i+=2;
        }
        else
        {
            i++;
        }
    }
    return s;
}

void DialogPage::Display(QString s,QString m)
{
    qCritical()<<">>>>UnScreen"<<m<<"  "<<unScreen(m);
    chat->setText(chat->text()+s+":\n  "+unScreen(m)+"\n");
}

