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
    for (int x=0,l=0;x<7;x++,l+=40){// 7 rows of dimonds the distance between them is 40
        for (int i = 0 , j= 0 ; i < 8; j+= 98,++i) {// 8 columns of dimonds the distance between them is 98
            demond[i]=new Demond();
            demond[i] ->setPos(35+j,l-50);//100 50
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
    //B->setRect(0,0,10,10);
    score = new Score();
    player = new Player();
    //player->setRect(0,0 , 100 , 10);
    scene->setSceneRect(0, 0 , 1000, 700);//screen size
    QPixmap pim(":/images/bg_image.jpg");
    scene->setBackgroundBrush(pim);
//>>>>>>> 78edc2b66d9b2687f004fd0047025e8ef1d79379


    scene -> addItem(player);
    scene -> addItem(B);
    scene -> addItem(score);
    player -> setFlag(QGraphicsRectItem::ItemIsFocusable);
    player -> setFocus();

    view = new QGraphicsView(scene);
    view->setFixedSize(1000, 700);
    player->setPos(view->width()/2 - player->boundingRect().width()/2, view->height()-player->boundingRect().height()-5);
    //B->setPos(view->width()/2, view->height()- B->boundingRect().height()-15);
    B->setPos(view->width()/2-10, view->height()-67);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view -> show();

}
