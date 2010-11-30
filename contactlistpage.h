#ifndef CONTACTLISTPAGE_H
#define CONTACTLISTPAGE_H
#include <MApplicationPage>
#include <QModelIndex>
#include <MList>
#include <QHash>

#include "contact_data.h"
#include <contactspage.h>
#include "list_model.h"

class ContactlistPage: public MApplicationPage
{
    Q_OBJECT
public:
    ContactlistPage(QGraphicsItem *parent = 0);
    virtual ~ ContactlistPage();

    void Add(QString username, QString status);
    void Remove(QString nick);

signals:
    void goDialogPage(QString username);

protected:
    // From MApplicationPage
    virtual void createContent();

private slots:
    void displayContact(const QModelIndex &index);
    //void updateContact(const int &action);

private:
    QMap<QString, QString> contactsList; // Contacts list with status strings
    QList<QString> activeContacts; //Current contacts list
    ContactsListModel* cmodel;

    void UpdateContacts(QMap<QString, QString> contactsList);

};


#endif // CONTACTLISTPAGE_H
