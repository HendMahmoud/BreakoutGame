#include "ball.h"
#include <QGraphicsEllipseItem>
#include <bits/stdc++.h>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QTimer>
#include <typeinfo>
#include <demond.h>
#include <QGraphicsScene>
#include "bodygame.h"

ball::ball()
{
    setPixmap(QPixmap(":/images/Soccer-Ball-icon.png"));
}
extern BodyGame * game ;
QTimer * timer=new QTimer();

void ball::moveball()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(5);
}

int dx=-1,dy=-1;
bool firsmv = 0 ;

void ball:: move(){
    QList <QGraphicsItem*> colliding_Items=collidingItems();
    for (int i=0;i<colliding_Items.size();i++){
        if(typeid(*(colliding_Items[i]))==typeid(Demond)){
            scene()->removeItem((colliding_Items[i]));
            //setPos((dx==1));
            game ->score->increase();
            if(game->score->getScore() == 56){
                game->scene->clear();
            }
        }
        else if (typeid(*(colliding_Items[i]))==typeid(Player)){
            if(firsmv)dy = -1*dy;
            setPos(x()+dx, y()+dy);
        }
    }
    if(x()==0&&y()==0){dx=-1*dx;dy=-1*dy;
        setPos(x()+dx,y()+dy);
    }
     else if(x()==0){dx=-1*dx;
        setPos(x()+dx,y()+dy);
    }
   else if(y()==0){dy=-1*dy;
        setPos(x()+dx,y()+dy);
    }

  else if(y()==700){
        game->player->setPos(500 - game->player->boundingRect().width()/2, 700-game ->player->boundingRect().height()-5);
        setPos(500, 700- boundingRect().height()-15);
    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    firsmv=0;
    dx = -1 , dy= -1 ;
    }

   else if(x()==970){dx=-1*dx;
        setPos(x()+dx,y()+dy);
    }
    else {setPos(x()+dx,y()+dy);firsmv=1;}
    return;
}
