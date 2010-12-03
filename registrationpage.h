#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H
#include <MApplicationPage>
#include <MApplicationWindow>
#include <QGraphicsGridLayout>
#include <MButton>
#include <QObject>
#include <MLabel>
#include <MTextEdit>
#include <QString>
class RegistrationPage : public MApplicationPage
{
    Q_OBJECT
    MLabel *l_line,*l_login,*l_pass,*l_repeat;
    MTextEdit *t_login, *t_pass,*t_repeat;
    MButton *ok;
    QString pass, log;
    QGraphicsGridLayout* VLay;
    qreal maxWidth_label,maxWidth_edit,maxHeigh;
public:
    RegistrationPage(MApplicationWindow*);
signals:
    void readySend(QString);
    void loadInfoPage(int);
public slots:
    void tryToReg();
};

#endif // REGISTRATIONPAGE_H
