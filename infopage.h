#ifndef INFOPAGE_H
#define INFOPAGE_H
#include <MButton>
#include <MLabel>
#include <QObject>
#include <MApplicationPage>
#include <QGraphicsLinearLayout>

class InfoPage: public MApplicationPage
{
    Q_OBJECT
    QStringList list;
    MButton *okbut;
    MLabel *info_label;
    QGraphicsLinearLayout *VLay;
public:
    InfoPage();
    void setInfoMessage(int);

signals:

public slots:
    void GoNext();

};

#endif // INFOPAGE_H
