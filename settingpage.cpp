#include "settingpage.h"

SettingPage::SettingPage(MApplicationWindow* wind):MApplicationPage()
{
    this->setTitle("Settings");
    VLay=new QGraphicsGridLayout(this->centralWidget());

    h_line=new MLabel("<hr>");
    ip_label=new MLabel("Enter Server IP:");
    port_label=new MLabel("Enter Server Port:");
    empt_label=new MLabel("");
    ok=new MButton("Apply");

    ipAddr_text=new MTextEdit();
    port_text=new MTextEdit();

    ipAddr="127.0.0.1";//default
    port=3425;

    maxWidth_label = wind->size().width()/4;
    maxHeigh = wind->size().height()/5.7;
    maxWidth_edit =  maxWidth_edit - maxWidth_label;

    ip_label->setMaximumWidth(maxWidth_label);
    ip_label->setMinimumWidth(maxWidth_label);
    port_label->setMaximumWidth(maxWidth_label);
    port_label->setMinimumWidth(maxWidth_label);

    ok->setMaximumWidth(maxWidth_label);
    ok->setMinimumWidth(maxWidth_label);

    ip_label->setMaximumHeight(maxHeigh);
    ip_label->setMinimumHeight(maxHeigh);
    port_label->setMaximumHeight(maxHeigh);
    port_label->setMinimumHeight(maxHeigh);
    ipAddr_text->setMaximumHeight(maxHeigh);
    ipAddr_text->setMinimumHeight(maxHeigh);
    port_text->setMinimumHeight(maxHeigh);
    port_text->setMaximumHeight(maxHeigh);
    ok->setMaximumHeight(maxHeigh);
    ok->setMinimumHeight(maxHeigh);
    h_line->setMinimumHeight(maxHeigh/2);
    h_line->setMaximumHeight(maxHeigh/2);

    VLay->addItem(empt_label,1,1,1,2);
    VLay->addItem(ip_label,2,1);
    VLay->addItem(ipAddr_text,2,2);
    VLay->addItem(port_label,3,1);
    VLay->addItem(port_text,3,2);
    VLay->addItem(h_line,4,1,1,2);
    VLay->addItem(ok,5,2);
    VLay->setAlignment(ok,Qt::AlignRight);
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
