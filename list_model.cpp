#include "list_model.h"

int ContactsListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    qDebug()<<">>ContactsListModel::rowCount : contactsCount="<< contactsCount;
    return contactsCount;
}

QVariant ContactsListModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<">>ContactsListModel::data : index.row() =" << index.row() << " index.row()/2 =" << index.row()/2 ;
    qDebug()<<">>ContactsListModel::data : activeContacts.size() =" << activeContacts.size() << " activeContacts.size()/2 =" << activeContacts.size()/2 ;

    if (index.row() >= activeContacts.size()/2 || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        qDebug()<<">>ContactsListModel::data : HERE ODD ROWS";
        QStringList rowData;
        qDebug()<<">>ContactsListModel::data : activeContacts="<< activeContacts.at(index.row()*2)<<" Index At ="<<index.row()*2;
        rowData << activeContacts.at(index.row()*2);
        qDebug()<<">>ContactsListModel::data : activeContacts="<< activeContacts.at(index.row()*2 + 1)<<" Index At="<< index.row()*2 + 1;
        rowData << activeContacts.at(index.row()*2 + 1);
        qDebug()<<">>ContactsListModel::data : rowData="<< rowData;

        return QVariant(rowData);
    }
    else
        return QVariant();

}

bool ContactsListModel::canFetchMore(const QModelIndex & ) const
{
    qDebug()<<">>ContactsListModel::canFetchMore : activeContacts="<< activeContacts;
    qDebug()<<">>ContactsListModel::canFetchMore : contactsCount="<< contactsCount;
    if (contactsCount < activeContacts.size()/2)
    {
        qDebug()<<">>ContactsListModel::canFetchMore : activeContacts=true";
        return true;
    }
    else
        return false;
}

void ContactsListModel::fetchMore(const QModelIndex &)
{
    int remainder = activeContacts.size()/2 - contactsCount;
    qDebug()<<">>ContactsListModel::fetchMore : remainder="<< remainder;
    int itemsToFetch = qMin(100, remainder);
    qDebug()<<">>ContactsListModel::fetchMore : itemsToFetch="<< itemsToFetch;
    qDebug()<<">>ContactsListModel::fetchMore : contactsCount="<< contactsCount;
    beginInsertRows(QModelIndex(), contactsCount, contactsCount + itemsToFetch);
    contactsCount += itemsToFetch;
    qDebug()<<">>ContactsListModel::fetchMore : contactsCount="<< contactsCount;
    endInsertRows();
}


void ContactsListModel::setActiveContcts(QList<QString> &contacts)
{
    activeContacts = contacts;
    qDebug()<<">>ContactsListModel::setActiveContcts : activeContacts="<< contacts;
    contactsCount = activeContacts.count()/2;
    qDebug()<<">>ContactsListModel::setActiveContcts : contactsCount="<< contactsCount;
    reset();
}
