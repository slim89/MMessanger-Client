#ifndef CONTACTSPAGE_H
#define CONTACTSPAGE_H

#include <MApplicationPage>

#include "contact_data.h"

class ContactsPage : public MApplicationPage {
    Q_OBJECT
public:
    ContactsPage(QString cname, QGraphicsItem *parent = 0);

protected:
    // From MApplicationPage
    virtual void createContent();

};

#endif // CONTACTSPAGE_H
