#ifndef CONTACTLISTPAGE_H
#define CONTACTLISTPAGE_H
#include <MApplicationPage>
#include <QModelIndex>
#include <MList>
#include <QHash>
#include "list_model.h"
#include "ThumbnailListControl.h"

class ContactlistPage: public MApplicationPage
{
    Q_OBJECT

public:
    ContactlistPage(QGraphicsItem *parent = 0);
    virtual ~ ContactlistPage();

    void Add(QString user_id, QString username, QString status);
    void Remove(QString user_id);

    QString getUserDisplayNameByID(QString userID);

    //QList<QString> getUsernameList();
    //QString getStatusByName(QString username);

    QList<QString> getActiveContactList();
    QString getStatusByDisplayName(QString userID, QString username);

    MList* getList();

    //QMap<QString, QString> findContactByStatus(QString username);
public slots:
    void displayMessage(QString);

signals:
    void goDialogPage(QString username);

protected:
    virtual void createContent();

private slots:
    void onAppeared();
    void displayContact(const QModelIndex &index);
    void updateContatsListView();
    void startPannigList();
    void stopPannigList();

private:
    QMap<QString, QString> contactsList; // Contacts list with status strings
    QList<QString> activeContacts; //Current contacts list
    ContactsListModel* cmodel;
    MList *clist;
    ThumbnailListControl* thumbnailListControl;
    int scrolling;
    QString readFrom;

    void UpdateContacts();
    QString displayName(QString userID, QString username);
};


#endif // CONTACTLISTPAGE_H
