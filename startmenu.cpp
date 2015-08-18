#include <QFont>
#include <QKeyEvent>
//#include <QObject>
#include <QDebug>
#include "startmenu.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include "bodygame.h"
extern BodyGame * game;
extern QGraphicsView * view ;
StartMenu::StartMenu()
{
    setRect(view->width()/2-150,view->height()/4+150,10,10);
}

void StartMenu::viewit()
{
    QGraphicsTextItem *text=new QGraphicsTextItem();
    text->setPlainText("BREAKOUT");
    text->setDefaultTextColor(Qt:: blue);
    text->setFont(QFont("time", 80));
    text->setPos(view->width()/5,view->height()/5);
    game->scene->addItem(text);
    view->setScene(game->scene);
    view->show();
    text=new QGraphicsTextItem();
    text->setPlainText("start game\nhow to play\nabout");
    text->setDefaultTextColor(Qt:: blue);
    text->setFont(QFont("time", 25));
    text->setPos(view->width()/4+150,view->height()/4+130);
    game->scene->addItem(text);
    view->setScene(game->scene);
    view->show();
}

void StartMenu::keyPressEvent(QKeyEvent *event)
{
//    qDebug() <<"pressed";
    if(event->key() == Qt :: Key_Up&&y()>0){
        setPos(x(), y()-38);
    }
    if(event->key() == Qt :: Key_Down&&y()<76){
        setPos(x(), y()+38);
    }
    if(event->key() == Qt :: Key_Enter){
        if(y()==0)//new game
        {
            game->startgame=1;
            game->show();
        }

        else if(y()==38)//how to play
        {
            game->startgame=2;
            game->show();
        }
        //else if(y()==76)//about

    }
}
