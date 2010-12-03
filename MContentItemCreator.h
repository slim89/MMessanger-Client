#ifndef MCONTENTITEMCREATOR_H
#define MCONTENTITEMCREATOR_H
#include <MApplication>
#include <MApplicationWindow>
#include <mcontentitem.h>
#include <MApplicationPage>
#include <mlist.h>
#include <mabstractcellcreator.h>
//#include <mwidgetcontroller.h>
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
