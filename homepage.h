#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include <MApplicationPage>
#include <QGraphicsLinearLayout>
#include <MButton>
#include <QObject>

class HomePage : public MApplicationPage
{
    Q_OBJECT
    MButton *con_list;
    MButton *settings;
    MButton *registration;
    MButton *login;
    MButton *exit;
    MButton *about;
    QGraphicsLinearLayout *VLay;
public:
    HomePage();
signals:
    void goRegistrationPage();
    void goLoginPage();
    void goContactListPage();
    void goSettingPage();
    void goInfoPage();
    void exiting();
};

#endif // HOMEPAGE_H
