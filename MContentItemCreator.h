#ifndef MCONTENTITEMCREATOR_H
#define MCONTENTITEMCREATOR_H
#include <mcontentitem.h>
#include <mabstractcellcreator.h>

class MContentItemCreator : public MAbstractCellCreator<MContentItem>
 {
  public:
      void updateCell(const QModelIndex& index, MWidget * cell) const
      {
          MContentItem* contentItem = qobject_cast<MContentItem *>(cell);
          QVariant data = index.data(Qt::DisplayRole);
          QStringList rowData = data.value<QStringList>();
          contentItem->setTitle(rowData[0]);
          contentItem->setSubtitle(rowData[1]);

      }

  };

#endif // MCONTENTITEMCREATOR_H
