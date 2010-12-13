#include "list_model.h"
#include <QDebug>
//#include <QApplication>


int ContactsListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    qDebug()<<">>ContactsListModel::rowCount : contactsCount="<< contactsCount;
    return contactsCount;

    //return activeContacts.count();
}

QVariant ContactsListModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<">>ContactsListModel::data : index.row() =" << index.row() << " index.row()/2 =" << index.row()/2 ;
    qDebug()<<">>ContactsListModel::data : activeContacts.size() =" << activeContacts.size() << " activeContacts.size()/2 =" << activeContacts.size()/2 ;

    if (index.row() >= activeContacts.size()/3 || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        qDebug()<<">>ContactsListModel::data : HERE ODD ROWS";
        QStringList rowData;
        qDebug()<<">>ContactsListModel::data : activeContacts="<< activeContacts.at(index.row()*3)<<" Index At ="<<index.row()*3;
        rowData << activeContacts.at(index.row()*3);

        qDebug()<<">>ContactsListModel::data : activeContacts="<< activeContacts.at(index.row()*3 + 1)<<" Index At="<< index.row()*3 + 1;
        rowData << activeContacts.at(index.row()*3 + 1);

        qDebug()<<">>ContactsListModel::data : activeContacts="<< activeContacts.at(index.row()*3 + 2)<<" Index At="<< index.row()*3 + 2;
        rowData << activeContacts.at(index.row()*3 + 2);

        qDebug()<<">>ContactsListModel::data : rowData="<< rowData;
        //return QVariant(activeContacts.at(index.row()));
        return QVariant(rowData);
    }
    else
        return QVariant();

}
/*
bool ContactsListModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        contactsList.insert(position, "");
    }

    endInsertRows();
    return true;
}

bool ContactsListModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        contactsList.removeAt(position);
    }

    endRemoveRows();
    return true;
}
*/

bool ContactsListModel::canFetchMore(const QModelIndex & ) const
{
    qDebug()<<">>ContactsListModel::canFetchMore : activeContacts="<< activeContacts;
    qDebug()<<">>ContactsListModel::canFetchMore : contactsCount="<< contactsCount;
    if (contactsCount < activeContacts.size()/3)
    {
        qDebug()<<">>ContactsListModel::canFetchMore : activeContacts=true";
        return true;
    }
    else
        return false;
}

void ContactsListModel::fetchMore(const QModelIndex &)
{
    int remainder = activeContacts.size()/3 - contactsCount;
    qDebug()<<">>ContactsListModel::fetchMore : remainder="<< remainder;
    int itemsToFetch = qMin(100, remainder);
    qDebug()<<">>ContactsListModel::fetchMore : itemsToFetch="<< itemsToFetch;
    qDebug()<<">>ContactsListModel::fetchMore : contactsCount="<< contactsCount;

    beginInsertRows(QModelIndex(), contactsCount, contactsCount + itemsToFetch);

    contactsCount += itemsToFetch;
    qDebug()<<">>ContactsListModel::fetchMore : contactsCount="<< contactsCount;

    endInsertRows();

    emit numberPopulated(itemsToFetch);
}


void ContactsListModel::setActiveContcts(QList<QString> &contacts)
{
    activeContacts = contacts;
    qDebug()<<">>ContactsListModel::setActiveContcts : activeContacts="<< contacts;

    contactsCount = activeContacts.count()/3;

    qDebug()<<">>ContactsListModel::setActiveContcts : contactsCount="<< contactsCount;
    reset();
}

/*
QVariant ContactsListModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}
*/
