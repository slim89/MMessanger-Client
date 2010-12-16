#ifndef CONTACTLISTPAGE_H
#define CONTACTLISTPAGE_H
#include <MApplicationPage>
#include <QModelIndex>
#include <MList>
#include <QHash>
#include "list_model.h"
#include "MessageAnimation.h"

class ContactlistPage: public MApplicationPage
{
    Q_OBJECT

public:
    ContactlistPage(QGraphicsItem *parent = 0);
    virtual ~ ContactlistPage();
    void Add(QString username, QString status);
    void Remove(QString username);

    QList<QString> getUsernameList();
    QString getStatusByName(QString username);

    //QMap<QString, QString> findContactByStatus(QString username);
public slots:
    void displayMeesage(QString);

signals:
    void goDialogPage(QString username);
    void incomingMessage(QString);       //test

protected:
    virtual void createContent();

private slots:
    void onAppeared();
    void displayContact(const QModelIndex &index);
    void updateContatsListView();

private:
    QMap<QString, QString> contactsList; // Contacts list with status strings
    QList<QString> activeContacts; //Current contacts list
    ContactsListModel* cmodel;
    MessageAnimation* messageAnimation;

    void UpdateContacts(QMap<QString, QString> contactsList);

};


#endif // CONTACTLISTPAGE_H
