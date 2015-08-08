#include "bodygame.h"
#include "ball.h"
#include<QDebug>
#include <vector>
using namespace std ;


BodyGame::BodyGame(){
 // constructor
}

void BodyGame :: creatingDiamonds(){
    scene = new QGraphicsScene();
    vector <Demond *>demond(18);
    //MyRect *= new MyRect();
    for (int x=0,l=0;x<5;x++,l+=50){
        for (int i = 0 , j= 0 ; i < 9; j+= 100,++i) {
            demond[i]=new Demond();
            demond[i] ->setRect(55+j,30+l,100,50);
            scene ->addItem(demond[i]);
        }
    }
 }

ball * B;
extern bool ballmove;
void BodyGame::show()
{
    creatingDiamonds();
    B = new ball();
    B->setRect(0,0,10,10);
    score = new Score();
    player = new Player();
    player->setRect(0,0 , 100 , 10);
    scene->setSceneRect(0, 0 , 1000, 700);
    scene -> addItem(player);
    scene -> addItem(B);
    scene -> addItem(score);
    player -> setFlag(QGraphicsRectItem::ItemIsFocusable);
    player -> setFocus();
    view = new QGraphicsView(scene);
    view->setFixedSize(1000, 700);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height()-player->rect().height()-5);
    B->setPos(view->width()/2, view->height()- B->rect().height()-15);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> show();

}
