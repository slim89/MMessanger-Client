#ifndef INFOPAGE_H
#define INFOPAGE_H
#include <MLabel>
#include <QObject>
#include <MApplicationPage>
#include <QGraphicsGridLayout>
#include <QGraphicsGridLayout>
#include <MImageWidget>
#include <mlabelmodel.h>
#include <MApplicationWindow>
class InfoPage: public MApplicationPage
{
     Q_OBJECT
     MImageWidget* im;
     MLabel *developers_name,   *project_name, *dev,*description1, *description2;
     QGraphicsGridLayout *VLay;
     qreal maxHeigh;
public:
     InfoPage(MApplicationWindow*);
};

#endif // INFOPAGE_H
