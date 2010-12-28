#include <MList>
#include <MContentItemCreator.h>
#include <QGraphicsLinearLayout>
#include <MLayout>
#include <QDebug>
#include <QMapIterator>
#include <QTimer>

#include "contactlistpage.h"
#include "list_model.h"

ContactlistPage::ContactlistPage(QGraphicsItem *parent)
    : MApplicationPage(parent)
{
    clist = NULL;
    setTitle("Contacts");
}

ContactlistPage::~ContactlistPage()
{
    delete messageAnimation;
}

void ContactlistPage::createContent()
{
    qDebug()<<">>>ContactlistPage::createContent() ";

    messageAnimation = new MessageAnimation();

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical);

    centralWidget()->setLayout(layout);

    contactsList["System Administraition"] = "connect";

    activeContacts << contactsList.keys("connect");
    activeContacts << contactsList.value("System Administraition");
    activeContacts << messageAnimation->Thumbnail("System Administraition", "connect");

    qDebug()<<">>>ContactlistPage::createContent() : activeContacts" << activeContacts;

    clist = new MList;
    MContentItemCreator * cellCreator = new MContentItemCreator;

    clist->setCellCreator(cellCreator);

    cmodel = new ContactsListModel(activeContacts);
    cmodel->setActiveContcts(activeContacts);

    clist->setItemModel(cmodel);
    clist->setSelectionMode(MList::SingleSelection);

    layout->addItem(clist);

    connect(clist, SIGNAL(itemClicked(QModelIndex)),
            this, SLOT(displayContact(QModelIndex)));

    connect(clist, SIGNAL(panningStarted()), this, SLOT(startPannigList()));

    connect(clist, SIGNAL(panningStopped()), this, SLOT(stopPannigList()));

    messageAnimation->connect(messageAnimation, SIGNAL(update()), this, SLOT(updateContatsListView()));

    QObject::connect( this, SIGNAL(appeared()), this, SLOT(onAppeared()));

    scrolling = 0;
}

void ContactlistPage::displayContact(const QModelIndex &index)
{
    qDebug() << ">>>ContactlistPage::displayContact : index row" << index.row() <<", contact num="<<index.row()*3;

    QString cname = activeContacts[index.row()*3];

    qDebug() << ">>>ContactlistPage::displayContact" << cname;
    qCritical()<<">>>ContactlistPage::displayContact" << cname;

    emit goDialogPage(cname);

    messageAnimation->Stop(cname);

    //ContactsPage  * contactsPage = new ContactsPage(cname);

    //contactsPage->appear(/*(MWindow*)scene(), MSceneWindow::DestroyWhenDismissed*/);


}

void ContactlistPage::updateContatsListView()
{
    qDebug() << ">>>ContactlistPage::updateContatsListView() : List = " << activeContacts;

    UpdateContacts(contactsList);
}

void ContactlistPage::startPannigList()
{
    scrolling = 1;
    messageAnimation->StopAnimation();
}

void ContactlistPage::stopPannigList()
{
    messageAnimation->StartAll();
    scrolling = 0;
}

void ContactlistPage::displayMeesage(QString username)
{
    qDebug()<<">>>MainPage::displayMeesage(QString username)";
    if (scrolling)
        messageAnimation->AddUser(username);
    else
        messageAnimation->Start(username);
}

void ContactlistPage::onAppeared()
{
    if ( !scrolling ) messageAnimation->StartAll();
}

void ContactlistPage::Add(QString username, QString status)
{
    qDebug()<<">>>ContactlistPage::Add(QString username, QString status) : Nick = " << username << ", Status" << status;
    contactsList[username] = status;
    UpdateContacts(contactsList);
}

void ContactlistPage::Remove(QString username)
{
    qDebug()<<">>>ContactlistPage::Remove(QString username) : Nick = " << username;
    contactsList.remove(username);

    messageAnimation->RemoveUser(username);

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

MList* ContactlistPage::getList()
{
    return clist;
}

void ContactlistPage::UpdateContacts(QMap<QString, QString> contactsList)
{
    qDebug()<<">>>ContactlistPage::UpdateContacts(QString nick, QString status)";
    activeContacts.clear();
    QMap<QString, QString>::const_iterator i = contactsList.constBegin();
    while (i != contactsList.constEnd()) {
        activeContacts << i.key() << i.value();
        activeContacts << messageAnimation->Thumbnail( i.key(), i.value() );
        ++i;
    }
    cmodel->setActiveContcts(activeContacts);
}
