#include <QDebug>
#include "contactspage.h"

ContactsPage::ContactsPage(QString cname, QGraphicsItem *parent)
    : MApplicationPage(parent)
{
    qCritical() << "ContactsPage::ContactsPage";
    setTitle(cname);
}

void ContactsPage::createContent()
{
    qCritical() << "ContactsPage::createContent" ;
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical);
    centralWidget()->setLayout(layout);
    layout->addItem(new MLabel("Read"));
}

