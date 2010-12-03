#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H
#include <QObject>
#include <MButton>
#include <MTextEdit>
#include <MLayout>
#include <MLabel>
#include <MApplicationPage>
#include <MApplicationWindow>
#include <MButtonView>
#include <QGraphicsGridLayout>

class  LoginPage : public MApplicationPage
{

public:
    LoginPage(MApplicationWindow*);
    Q_OBJECT

private:
    MLabel *l_line,*l_login,*l_pass, *l_lab;
    MTextEdit *t_login, *t_pass;
    MButton *ok,*home;
    QGraphicsGridLayout* VLay;
    qreal maxWidth_label,maxWidth_edit,maxHeigh;
signals:
    void goHomePage();
    void readySend(QString);
    void loadInfoPage(int);
    void exiting();
private slots:
    void login();
};
#endif // LOGIN_PAGE_H
