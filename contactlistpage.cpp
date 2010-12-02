#include <MList>
#include <MContentItemCreator.h>
#include <QGraphicsLinearLayout>
#include <MLayout>
#include <QDebug>
#include <QMapIterator>

#include "contactlistpage.h"
#include "list_model.h"
#include <contactspage.h>

ContactlistPage::ContactlistPage(QGraphicsItem *parent)
    : MApplicationPage(parent)
{
    setTitle("Contacts");
}

ContactlistPage::~ContactlistPage()
{
}

void ContactlistPage::createContent()
{
    qDebug()<<">>>MainPage::createContent() ";

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical);

    centralWidget()->setLayout(layout);

    contactsList["System Administraition"] = "Online";

    activeContacts << contactsList.keys("Online");
    activeContacts << contactsList.value("System Administraition");


    qDebug()<<">>>MainPage::createContent() : activeContacts" << activeContacts;

    MList *clist = new MList;
    MContentItemCreator * cellCreator = new MContentItemCreator;
    clist->setCellCreator(cellCreator);

    cmodel = new ContactsListModel(activeContacts);
    cmodel->setActiveContcts(activeContacts);

    clist->setItemModel(cmodel);
    clist->setSelectionMode(MList::SingleSelection);
    layout->addItem(clist);

    connect(clist, SIGNAL(itemClicked(QModelIndex)),
            this, SLOT(displayContact(QModelIndex)));

}

void ContactlistPage::displayContact(const QModelIndex &index)
{
    qDebug() << ">>>MainPage::displayContact : index row" << index.row() <<", contact num="<<index.row()*2;
    QString cname = activeContacts[index.row()*2];
    qDebug() << ">>>MainPage::displayContact" << cname;

    emit goDialogPage(cname);

    //ContactsPage  * contactsPage = new ContactsPage(cname);

    //contactsPage->appear(/*(MWindow*)scene(), MSceneWindow::DestroyWhenDismissed*/);

}

void ContactlistPage::Add(QString username, QString status)
{
    qDebug()<<">>>MainPage::Add(QString username, QString status) : Nick = " << username << ", Status" << status;

    contactsList[username] = status;

    UpdateContacts(contactsList);
}

void ContactlistPage::Remove(QString username)
{
    qDebug()<<">>>MainPage::Remove(QString username) : Nick = " << username;

    contactsList.remove(username);

    UpdateContacts(contactsList);

}

QList<QString> ContactlistPage::getUsernameList()
{
    return activeContacts;
}

QString ContactlistPage::getStatusByName(QString username)
{
    QMap<QString, QString>::const_iterator i = contactsList.find(username);

    return i.value();
}

void ContactlistPage::UpdateContacts(QMap<QString, QString> contactsList)
{
    qDebug()<<">>>MainPage::UpdateContacts(QString nick, QString status)";

    activeContacts.clear();

    QMap<QString, QString>::const_iterator i = contactsList.constBegin();
    while (i != contactsList.constEnd()) {
        activeContacts << i.key() << i.value();
        ++i;
    }

    qDebug() << ">>>MainPage::UpdateContacts : List = " << activeContacts;

    cmodel->setActiveContcts(activeContacts);

}
