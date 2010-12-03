#ifndef LIST_MODEL_H
#define LIST_MODEL_H
#include <QAbstractListModel>
#include <MAbstractCellCreator>
#include <QDebug>
#include <QApplication>
class ContactsListModel : public QAbstractListModel
{
   Q_OBJECT
 public:
   ContactsListModel(QStringList activeContacts, QObject *parent = 0)
       : QAbstractListModel(parent), activeContacts(activeContacts) {}
   int rowCount(const QModelIndex &parent = QModelIndex()) const;
   QVariant data(const QModelIndex &index, int role) const;
public slots:
    void setActiveContcts(QList<QString> &contacts);
protected:
   bool canFetchMore(const QModelIndex &parent) const;
   void fetchMore(const QModelIndex &parent);
private:
    QList<QString> activeContacts;
    int contactsCount;
};
#endif // LIST_MODEL_H
