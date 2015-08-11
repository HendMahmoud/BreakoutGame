#include <bits/stdc++.h>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QFont>
#include "bodygame.h"

#include "ball.h"
#include "startmenu.h"

using namespace std ;

BodyGame::BodyGame(){
    startgame=0;
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0 , 1000, 700);//screen size
    QPixmap pim(":/images/bg_image.jpg");
    scene->setBackgroundBrush(pim);
    view = new QGraphicsView();
    player = new Player();
    score = new Score();
    health = new Health();
    view->setFixedSize(1000, 700);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

ball * B;
extern bool ballmove;
void BodyGame::show()
{

    if(startgame==0){
        StartMenu *startmenu =new StartMenu();
        scene->addItem(startmenu);
        startmenu->viewit();
        startmenu->setFlag(QGraphicsRectItem::ItemIsFocusable);
        startmenu-> setFocus();
        view->setScene(scene);
        view -> show();
    }
    else if(startgame==1){
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
        //B->setPos(view->width()/2, view->height()- B->boundingRect().height()-15);

        B->setPos(view->width()/2-10, view->height()-67);
        //B->setPos(view->width()/2-22, view->height()-63);
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
    text->setPos(0,this->view->height()/4);
    text->setPlainText("\t\t\t\tYOU WIN");
    text->setDefaultTextColor(Qt:: blue);
    text->setFont(QFont("time", 40));
    scene->addItem(text);
    QGraphicsTextItem * text2 =new QGraphicsTextItem();
    text2->setPos(0,this->view->height()/3);
    QString s;
    view->alignment();
    text2->setPlainText("\n\t\t\t\ttype your user name: "+(QString)s);
    text2->setDefaultTextColor(Qt:: black);
    text2->setFont(QFont("time", 20));
    scene->addItem(text2);
    //scene->addItem(s);
    view->setScene(scene);
    view -> show();
}
void BodyGame::userinput(QString s){
    QGraphicsTextItem * text =new QGraphicsTextItem();
    text->setPos(this->view->width()-this->view->width()/3-50,this->view->height()/3);
    text->setPlainText("\n"+(QString)s);
    text->setDefaultTextColor(Qt:: black);
    text->setFont(QFont("time", 20));
    scene->addItem(text);
    view->setScene(scene);
    view -> show();
}
