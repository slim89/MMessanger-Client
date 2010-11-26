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

public:
    LoginPage();
    Q_OBJECT

private:
    MLabel *lab,*line,*log_lab,*pass_lab;
    MButton *enter,*but;
    MTextEdit* mylogin;
    MTextEdit* password;
signals:
    void goHomePage();
    void readySend(QString);
    void loadInfoPage(int);
    void exiting();
private slots:
    void login();
};
#endif // LOGIN_PAGE_H
