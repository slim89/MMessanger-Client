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
public:
    DialogPage(MApplicationWindow*);
public slots:
    void appearPage(QString username);

};

#endif // DIALOGPAGE_H
