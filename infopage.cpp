#include "infopage.h"

InfoPage::InfoPage()
{
   this->setTitle("About");
   im=new MImageWidget(this->centralWidget());
   QPixmap pp("./logo.png");
   im->setPixmap(pp);
   VLay=new QGraphicsGridLayout(this->centralWidget());
   project_name = new MLabel("Meego-KVP-Client 1.0.0");
   dev = new MLabel("Developers:");
   developers_name = new MLabel("Dmitry Nikolaev, Anton Magaev, Andrey Gavrilin, Fomicheva Natalya");
   description1 = new MLabel("The program is provided AS IS with NO WARRANTY OF ANY KIND");
   description2 = new MLabel("");
   int size =45;

   project_name->setMaximumHeight(55);
   project_name->setMinimumHeight(55);
   dev->setMaximumHeight(size);
   dev->setMinimumHeight(size);
   developers_name->setMaximumHeight(size);
   developers_name->setMinimumHeight(size);
   description1->setMaximumHeight(size);
   description1->setMinimumHeight(size);

   //project_name->setObjectName("calculationLine");
     // project_name->setAlignment(Qt::AlignRight);
   // description1->setObjectName("calculationLine1");
 //developers_name->setObjectName("calculationLine1");

   MLabelModel *model1 = new MLabelModel();
   model1->setText("Meego-KVP-Client 1.0.0");
   QFont f("Nokia Sans Wide",45,80);
   f.setPixelSize(80);
   f.setBold(true);
    model1->setFont(f);
    model1->setColor(Qt::red);
   project_name->setModel(model1);

   description2->setMinimumHeight(90);
   description2->setMaximumHeight(90);
   im->setMaximumSize(125,130);
   im->setMinimumSize(125,130);

    //VLay->addItem(im,1,1);
    VLay->addItem(project_name,1,2);
    VLay->addItem(description2,2,1);
    VLay->addItem(description1,3,1,1,2);
    VLay->addItem(dev,4,1);
    VLay->addItem(developers_name,5,1,1,2);
    VLay->setSpacing(-10);
}

