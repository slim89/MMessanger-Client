#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include <MApplicationPage>
#include <MApplicationWindow>
#include <QGraphicsGridLayout>
#include <MButton>
#include <MLabel>
#include <QObject>
#include <MImageWidget>
class HomePage : public MApplicationPage
{
    Q_OBJECT
    MButton *con_list;
    MButton *settings;
    MButton *registration;
    MButton *login;
    MButton *exit;
    MButton *about;
    MLabel *empty_label;
    QGraphicsGridLayout *VLay;
    MImageWidget* im;
    qreal size_but, size;
public:
    HomePage(MApplicationWindow*);
signals:
    void goRegistrationPage();
    void goLoginPage();
    void goContactListPage();
    void goSettingPage();
    void goInfoPage();
    void exiting();
};

#endif // HOMEPAGE_H
