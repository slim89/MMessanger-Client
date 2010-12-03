#ifndef CONTACTSPAGE_H
#define CONTACTSPAGE_H
#include <MApplicationPage>
#include <MButton>
#include <MButtonGroup>
#include <MLabel>
#include <MSceneManager>
#include <QGraphicsLinearLayout>
#include "contact_data.h"
class ContactsPage : public MApplicationPage {
    Q_OBJECT
public:
    ContactsPage(QString cname, QGraphicsItem *parent = 0);

protected:
    virtual void createContent();
private:
};
#endif // CONTACTSPAGE_H
