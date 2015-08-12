#include <QFont>
#include <QKeyEvent>
//#include <QObject>
#include <QDebug>
#include "startmenu.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include "bodygame.h"
extern BodyGame * game;
StartMenu::StartMenu()
{
    setRect(game->view->width()/2-150,game->view->height()/4+150,10,10);
}

void StartMenu::viewit()
{
    QGraphicsTextItem *text=new QGraphicsTextItem();
    text->setPlainText("BREAKOUT");
    text->setDefaultTextColor(Qt:: blue);
    text->setFont(QFont("time", 80));
    text->setPos(game->view->width()/5,game->view->height()/5);
    game->scene->addItem(text);
    game->view->setScene(game->scene);
    game->view->show();
    text=new QGraphicsTextItem();
    text->setPlainText("start game\nhow to play\nabout");
    text->setDefaultTextColor(Qt:: blue);
    text->setFont(QFont("time", 25));
    text->setPos(game->view->width()/4+150,game->view->height()/4+130);
    game->scene->addItem(text);
    game->view->setScene(game->scene);
    game->view->show();
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
        game->startgame=1;
        if(y()==0)//new game
            game->show();
        //else if(y()==38)//how to play
        //else if(y()==76)//about

    }
}
