#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H
#include <MApplicationPage>
#include <QGraphicsLinearLayout>
#include <MButton>
#include <QObject>
#include <MLabel>
#include <MTextEdit>
#include <QString>

class RegistrationPage : public MApplicationPage
{
    Q_OBJECT
    MLabel *h_line;
    MLabel *en_log;
    MLabel *en_pass;
    MLabel *rep_pass;
    MButton *reg;
    MTextEdit *login;
    MTextEdit *password;
    MTextEdit *repeat;
    QString pass;
    QString log;
public:
    RegistrationPage();
signals:
    void readySend(QString);
public slots:
    void tryToReg();
};

#endif // REGISTRATIONPAGE_H
