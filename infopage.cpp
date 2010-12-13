#include "infopage.h"

InfoPage::InfoPage(MApplicationWindow* wind)
{
   this->setTitle("About");
   im=new MImageWidget(this->centralWidget());
   QPixmap pp("usr/share/Meego-KVP-Client/style/logo.gif");
   im->setPixmap(pp);
   VLay=new QGraphicsGridLayout(this->centralWidget());

   maxHeigh = wind->size().height()/6;

   project_name = new MLabel("Meego-KVP-Client 1.0.0");
   dev = new MLabel("Developers:");
   developers_name = new MLabel("Dmitry Nikolaev, Anton Magaev, Andrey Gavrilin, Fomicheva Natalya");
   description1 = new MLabel("The program is provided AS IS with NO WARRANTY OF ANY KIND");
   description2 = new MLabel("");

   project_name->setMaximumHeight(maxHeigh);
   project_name->setMinimumHeight(maxHeigh);
   dev->setMaximumHeight(maxHeigh * 0.6);
   dev->setMinimumHeight(maxHeigh *0.6);
   developers_name->setMaximumHeight(maxHeigh *0.6);
   developers_name->setMinimumHeight(maxHeigh *0.6);
   description1->setMaximumHeight(maxHeigh);
   description1->setMinimumHeight(maxHeigh);
   description2->setMinimumHeight(maxHeigh);
   description2->setMaximumHeight(maxHeigh);

   MLabelModel *model1 = new MLabelModel();
   model1->setText("Meego-KVP-Client 1.0.0");
   QFont f("Nokia Sans Wide",45,80);
   model1->setFont(f);
   model1->setColor(Qt::white);
   project_name->setModel(model1);

   im->setMaximumSize(maxHeigh*2,maxHeigh*2);
   im->setMinimumSize(maxHeigh*2,maxHeigh*2);

   VLay->addItem(im,1,1);
   VLay->addItem(project_name,1,2,1,2);
   VLay->addItem(description1,3,1,1,2);
   VLay->addItem(dev,4,1);
   VLay->addItem(developers_name,5,1,1,2);
   VLay->setSpacing(-10);
   VLay->setAlignment(project_name,Qt::AlignLeft);
}

