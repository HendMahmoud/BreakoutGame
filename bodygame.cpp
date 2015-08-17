#include <bits/stdc++.h>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QFont>
#include "bodygame.h"

#include "ball.h"
#include "startmenu.h"

using namespace std ;

extern QGraphicsView * view ;

BodyGame::BodyGame(){
    startgame=0;
//    scene->clear();
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0 , 1000, 700);//screen size
    QPixmap pim(":/images/bg_image.jpg");
    scene->setBackgroundBrush(pim);

    player = new Player();
    score = new Score();
    health = new Health();
    view->setFixedSize(1000, 700);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
extern bool ballmove;

BodyGame::~BodyGame()
{
    //scene->clear();
    delete player;
    delete score;
    delete health;
    delete B;
}

void BodyGame :: creatingDiamonds(){

    Demond *demond;
    //MyRect *= new MyRect();
    for (int x=0,l=0;x<7;x++,l+=40){// 7 rows of dimonds the distance between them is 40
        for (int i = 0 , j= 0 ; i < 8; j+= 98,++i) {// 8 columns of dimonds the distance between them is 98
            demond=new Demond();
            demond->setPos(110+j,l+30);//100 50
            scene ->addItem(demond);

        }
    }
 }


void BodyGame::show()
{

    if(startgame==0)//start menu
    {
        StartMenu *startmenu =new StartMenu();
        scene->addItem(startmenu);
        startmenu->viewit();
        startmenu->setFlag(QGraphicsRectItem::ItemIsFocusable);
        startmenu-> setFocus();
        view->setScene(scene);
        view -> show();
    }
    else if(startgame==1)// game start
    {
        scene->clear();
        creatingDiamonds();
        B = new ball();

        scene -> addItem(player);
        scene -> addItem(B);
        scene -> addItem(score);
        scene -> addItem(health);
        player -> setFlag(QGraphicsRectItem::ItemIsFocusable);
        player -> setFocus();

        player->setPos(view->width()/2 - player->boundingRect().width()/2, view->height()-player->boundingRect().height()-5);

        B->setPos(view->width()/2-10, view->height()-60);
        view->setScene(scene);
        view -> show();
    }
}

void BodyGame::finishView()
{
    //player->flags();//QGraphicsRectItem::ItemIsFocusable);
    //this -> setFlag(QGraphicsRectItem::ItemFocusable);
    //player -> setFocus();
//    scene->clear();
    QGraphicsTextItem * text =new QGraphicsTextItem();
    text->setPos(0,view->height()/4);
    if(health->getHealth()==0)
        text->setPlainText("\t\t\t\tGAME OVER");
    else text->setPlainText("\t\t\t\tYOU WIN");
    text->setDefaultTextColor(Qt:: blue);
    text->setFont(QFont("time", 40));
    scene->addItem(text);
    QGraphicsTextItem * text2 =new QGraphicsTextItem();
    text2->setPos(0,view->height()/3);
    text2->setPlainText("\n\t\t\t\tPress enter to Back");
    text2->setDefaultTextColor(Qt:: black);
    text2->setFont(QFont("time", 20));
    scene->addItem(text2);
    view->setScene(scene);
    view -> show();
}
//void BodyGame::userinput(QString s){
//    QGraphicsTextItem * text =new QGraphicsTextItem();
//    text->setPos(view->width()-view->width()/3-50,view->height()/3);
//    text->setPlainText("\n"+(QString)s);
//    text->setDefaultTextColor(Qt:: black);
//    text->setFont(QFont("time", 20));
//    scene->addItem(text);
//    view->setScene(scene);
//    view -> show();

//}
