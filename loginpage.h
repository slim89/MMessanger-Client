#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H
#include <QObject>
#include <MButton>
#include <MTextEdit>
#include <MLayout>
#include <QGraphicsLinearLayout>
#include <MLabel>
#include <MApplicationPage>
#include <MButtonView>
#include <QSizePolicy>


class  LoginPage : public MApplicationPage
{
    Q_OBJECT
public:
    LoginPage();
    void show_login();

private:
    MLabel *lab,*line,*log_lab,*pass_lab;
    MButton *enter,*but;
    MTextEdit* mylogin;
    MTextEdit* password;
signals:
    void goHomePage();
    void readySend(QString);
public slots:
    void login();
};
#endif // LOGIN_PAGE_H
