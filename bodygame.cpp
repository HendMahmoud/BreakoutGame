#include "bodygame.h"
#include<QDebug>
BodyGame::BodyGame(){
 // constructor
}

void BodyGame :: creatingDiamonds(){
    scene = new QGraphicsScene();
   Demond *demond1 =new Demond();
   Demond *demond2 =new Demond();
   Demond *demond3 =new Demond();
   Demond *demond4 =new Demond();

   demond1 ->setRect(0,0,100,50);
   demond2 ->setRect(100,0,100,50);
   demond3 ->setRect(200,0,100,50);
   demond4 ->setRect(300,0,100,50);
       scene ->addItem(demond1);
       scene ->addItem(demond2);
       scene ->addItem(demond3);
       scene ->addItem(demond4);
  }

void BodyGame::show()
{
    creatingDiamonds();
    player = new Player();
    player->setRect(0,0 , 60 , 10);
    scene->setSceneRect(0, 0 , 800, 600);
    scene -> addItem(player);

    player -> setFlag(QGraphicsRectItem::ItemIsFocusable);
    player -> setFocus();
     view = new QGraphicsView(scene);
     view->setFixedSize(800, 600);
     player->setPos(view->width()/2, view->height()-player->rect().height());
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view -> show();
}
