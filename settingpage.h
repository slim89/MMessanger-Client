#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H
#include <QGraphicsLinearLayout>
#include <MApplicationPage>
#include <QObject>
#include <MTextEdit>
#include <MLabel>
#include <MButton>
class SettingPage : public MApplicationPage
{
    Q_OBJECT
    MLabel *ip_label;
    MLabel *port_label;
    MButton *ok;
    MLabel *h_line;
    MTextEdit *ipAddr_text;
    MTextEdit *port_text;
    QString ipAddr;
    int port;
public:
    SettingPage();
    QString GetIPAdrr();
    int GetPort();
signals:
    void changeSettings();
private slots:
    void CheckNewSetting();
};

#endif // SETTINGPAGE_H
