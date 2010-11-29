#ifndef CONTACTLISTPAGE_H
#define CONTACTLISTPAGE_H
#include <MApplicationPage>
class ContactListPage : public MApplicationPage
{
public:
    ContactListPage();
    void Add(QString nick,QString status);
    void Remove(QString nick);
};

#endif // CONTACTLISTPAGE_H
