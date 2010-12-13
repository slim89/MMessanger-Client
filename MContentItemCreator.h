#ifndef MCONTENTITEMCREATOR_H
#define MCONTENTITEMCREATOR_H
#include <mcontentitem.h>
#include <mabstractcellcreator.h>

class MContentItemCreator : public MAbstractCellCreator<MContentItem>
 {
  public:
     MContentItemCreator()
     {
        // in css corresponding selector would be:
        // MContentItem[myCustomViewType]#myObjectName { ....
        setCellViewType("myCustomViewType");
        setCellObjectName("myObjectName");
     }
      void updateCell(const QModelIndex& index, MWidget * cell) const
      {
          MContentItem* contentItem = qobject_cast<MContentItem *>(cell);
          QVariant data = index.data(Qt::DisplayRole);
          QStringList rowData = data.value<QStringList>();
          contentItem->setTitle(rowData[0]);
          contentItem->setSubtitle(rowData[1]);
          contentItem->setPixmap(QPixmap(rowData[2]));

      }

  };

#endif // MCONTENTITEMCREATOR_H
