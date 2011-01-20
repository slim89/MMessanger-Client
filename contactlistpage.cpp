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
    delete thumbnailListControl;
}

void ContactlistPage::createContent()
{
    qDebug()<<">>>ContactlistPage::createContent() ";

    thumbnailListControl = new ThumbnailListControl();

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical);

    centralWidget()->setLayout(layout);

    //contactsList["System Administraition"] = "connect";

    //activeContacts << contactsList.keys("connect");
    //activeContacts << contactsList.value("System Administraition");
    //activeContacts << thumbnailListControl->Thumbnail("System Administraition", "connect");

    contactsList[displayName("777","System Administraition")] = "connect";

    activeContacts << displayName("777","System Administraition") << "connect";
    activeContacts << thumbnailListControl->Thumbnail(displayName("777","System Administraition"), "connect");

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

    thumbnailListControl->connect(thumbnailListControl, SIGNAL(update()), this, SLOT(updateContatsListView()));

    QObject::connect( this, SIGNAL(appeared()), this, SLOT(onAppeared()));

    scrolling = 0;
    readFrom = "";
}

void ContactlistPage::displayContact(const QModelIndex &index)
{
    qDebug() << ">>>ContactlistPage::displayContact : index row" << index.row() <<", contact num="<<index.row()*3;

    readFrom = activeContacts[index.row()*3];

    emit goDialogPage(readFrom);

    thumbnailListControl->Stop(readFrom);

    //ContactsPage  * contactsPage = new ContactsPage(cname);

    //contactsPage->appear(/*(MWindow*)scene(), MSceneWindow::DestroyWhenDismissed*/);


}

void ContactlistPage::updateContatsListView()
{
    qDebug() << ">>>ContactlistPage::updateContatsListView() : List = " << activeContacts;

    UpdateContacts();
}

void ContactlistPage::startPannigList()
{
    scrolling = 1;
    thumbnailListControl->StopAnimation();
}

void ContactlistPage::stopPannigList()
{
    thumbnailListControl->StartAll();
    scrolling = 0;
}

void ContactlistPage::displayMessage(QString userID, QString username)
{
    qCritical()<<">>>MainPage::displayMeesage(QString username)";

    QString dName = displayName(userID, username);

    qCritical()<<"dName "<<dName<<"  ID  "<<userID<<"  username  "<<username;
    if (dName == readFrom)
    {
        qCritical()<<"VSE PLOHO";
        thumbnailListControl->RemoveUser(dName);
    }
    else
    {
        if (scrolling)
            thumbnailListControl->AddUser(dName);
        else
            thumbnailListControl->Start(dName);
    }
}

void ContactlistPage::onAppeared()
{
    if ( !scrolling ) thumbnailListControl->StartAll();
    readFrom = "";
}

void ContactlistPage::Add(QString userID, QString username, QString status)
{
    qDebug()<<">>>ContactlistPage::Add(QString username, QString status) : Nick = " << username << ", Status" << status;

    contactsList[displayName(userID, username)] = status;
    UpdateContacts();
}

void ContactlistPage::Remove(QString userID)
{
    qDebug()<<">>>ContactlistPage::Remove(QString userID) : userID = " << userID;

    QString dName = "";
    QString currID = "";

    QMap<QString, QString>::const_iterator i = contactsList.constBegin();

    while ((i != contactsList.constEnd()) && (currID != userID)) {
        dName = i.key();
        QStringList list1 = dName.split("( ");
        QString id_part = list1[1];
        QStringList list2 = id_part.split(" )");
        currID = list2[0];
        ++i;
    }

    contactsList.remove(dName);

    thumbnailListControl->RemoveUser(dName);

    UpdateContacts();
}

QList<QString> ContactlistPage::getActiveContactList()
{
    return activeContacts;
}

QString ContactlistPage::getStatusByDisplayName(QString userID, QString username)
{
    QString dName = displayName(userID, username);

    QMap<QString, QString>::const_iterator i = contactsList.find(dName);

    return i.value();
}

MList* ContactlistPage::getList()
{
    return clist;
}

void ContactlistPage::UpdateContacts()
{
    qDebug()<<">>>ContactlistPage::UpdateContacts(QString nick, QString status)";
    activeContacts.clear();
    QMap<QString, QString>::const_iterator i = contactsList.constBegin();
    while (i != contactsList.constEnd()) {
        activeContacts << i.key() << i.value();
        activeContacts << thumbnailListControl->Thumbnail( i.key(), i.value() );
        ++i;
    }
    cmodel->setActiveContcts(activeContacts);
}

QString ContactlistPage::displayName(QString userID, QString username)
{

    return username + " ( " + userID + " )";
}
