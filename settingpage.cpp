#include "settingpage.h"

SettingPage::SettingPage()
{
    this->setTitle("Settings");

    ipAddr="127.0.0.1";
    port=3425;

    QGraphicsLinearLayout *v=new QGraphicsLinearLayout(Qt::Vertical,this->centralWidget());
    QGraphicsLinearLayout *h1=new QGraphicsLinearLayout(Qt::Horizontal);
    QGraphicsLinearLayout *h2=new QGraphicsLinearLayout(Qt::Horizontal);

    h_line=new MLabel("<hr>");
    ip_label=new MLabel("Enter Server IP:");
    port_label=new MLabel("Enter Server Port:");

    ok=new MButton("Apply");

    ipAddr_text=new MTextEdit();
    port_text=new MTextEdit();

    h1->addItem(ip_label);
    h1->addItem(ipAddr_text);
    h2->addItem(port_label);
    h2->addItem(port_text);

    int maxWidth=230;

    ip_label->setMaximumWidth(maxWidth);
    ipAddr_text->setMaximumWidth(maxWidth);
    ip_label->setMaximumWidth(maxWidth);
    port_text->setMinimumWidth(maxWidth);

    v->addItem(h1);
    v->addItem(h2);
    v->addItem(h_line);
    v->addItem(ok);
    v->addStretch();

    connect(ok,SIGNAL(clicked()),this,SLOT(CheckNewSetting()));
}

QString SettingPage::GetIPAdrr()
{
      return ipAddr;
}

int SettingPage::GetPort()
{
      return port;
}
void SettingPage::CheckNewSetting()
{
    ipAddr=ipAddr_text->text();
    port=(port_text->text()).toInt();
    emit changeSettings();
}
