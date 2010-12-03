#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H
#include <QGraphicsGridLayout>
#include <MApplicationPage>
#include <MApplicationWindow>
#include <QObject>
#include <MTextEdit>
#include <MLabel>
#include <MButton>
class SettingPage : public MApplicationPage
{
    Q_OBJECT
    MLabel *ip_label, *empt_label;
    MLabel *port_label;
    MButton *ok;
    MLabel *h_line;
    MTextEdit *ipAddr_text;
    MTextEdit *port_text;
    QGraphicsGridLayout* VLay;
    QString ipAddr;
    int port;
    qreal maxWidth_label,maxWidth_edit,maxHeigh;
public:
    SettingPage(MApplicationWindow*);
    QString GetIPAdrr();
    int GetPort();
signals:
    void changeSettings();
private slots:
    void CheckNewSetting();
};

#endif // SETTINGPAGE_H
