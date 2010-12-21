#ifndef DIALOGPAGE_H
#define DIALOGPAGE_H
#include <MApplicationPage>
#include <MApplicationWindow>
#include <QObject>
#include <MButton>
#include <MTextEdit>
#include <QGraphicsLinearLayout>

class DialogPage : public MApplicationPage
{
    Q_OBJECT

    MButton *send;
    MTextEdit *chat;
    MTextEdit *message;
    QGraphicsLinearLayout *v;
    QGraphicsLinearLayout *h2;

    QString Screen(QString str);
    QString unScreen(QString str);
public:
    DialogPage(MApplicationWindow*);
    void Display(QString s,QString m);

public slots:
    void appearPage(QString username);
    void sendClick();
signals:
    void readySend(QString);

};

#endif // DIALOGPAGE_H
