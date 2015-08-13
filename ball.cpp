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
#include <QFont>
#include <QGraphicsTextItem>
#include<QMediaPlayer>

float ball::speed =1;
ball::ball()
{
    setPixmap(QPixmap(":/images/gray-2.png"));

}
extern BodyGame * game ;
QTimer * timer=new QTimer();

void ball::moveball()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    if(speed==1)
    timer->start(7);

}

int dx=-1,dy=-1;
bool firsmv = 0 ;

void ball:: move(){
    QList <QGraphicsItem*> colliding_Items=collidingItems();
    for (int i=0;i<colliding_Items.size();i++)
    {
        if(typeid(*(colliding_Items[i]))==typeid(Demond))

        {

            if(y()==(colliding_Items[i]->y()+41)||y()+17==(colliding_Items[i]->y())){//hit from down and up
                            dy = -1*dy;
                            setPos(x()+dx, y()+dy);
                            scene()->removeItem((colliding_Items[i]));
                            delete colliding_Items[i];
                        }
                        else if(x()+18==(colliding_Items[i]->x())||x()==(colliding_Items[i]->x())+100){//hit from right and left
                            dx= -1*dx;
                            setPos(x()+dx, y()+dy);
                            scene()->removeItem((colliding_Items[i]));
                            delete colliding_Items[i];
                        }
                        else {//hit from corners
                            dy = -1*dy;dx= -1*dx;
                            setPos(x()+dx, y()+dy);
                            scene()->removeItem((colliding_Items[i]));
                            delete colliding_Items[i];
                        }
           if(game->score->getScore()%20==0&&timer->interval()-speed>0)

            {
                timer->setInterval(timer->interval()-speed);
                speed+=0.5;
            }
            game ->score->increase();
            if(game->score->getScore() == 56){//the total number of dimonds
                disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
                game->finishView();
            }
        }
        else if (typeid(*(colliding_Items[i]))==typeid(Player)){
            if(firsmv)dy = -1*dy;
            setPos(x()+dx, y()+dy);
        }
    }
    if(x()==0&&y()==0)
    {
        dx=-1*dx;dy=-1*dy;
        setPos(x()+dx,y()+dy);
    }
     else if(x()==0)//left edge
    {
        dx=-1*dx;
        setPos(x()+dx,y()+dy);
    }
   else if(y()==0)//up
    {
        dy=-1*dy;
        setPos(x()+dx,y()+dy);
    }

  else if(y()==700){//falling
        game->player->setPos(500 - game->player->boundingRect().width()/2, 700-game ->player->boundingRect().height()-5);
        setPos(490 , 640);//position of the ball after falling down
    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    firsmv=0;
    dx = -1 , dy= -1 ;
    game ->health->decrease();

    QMediaPlayer *fallBall = new QMediaPlayer();
    if(game->health->getHealth() > 0){

         fallBall->setMedia(QUrl("qrc:/sounds/playerDie.wav"));
         fallBall->play();
    }
   else if(game->health->getHealth() == 0){
    fallBall->setMedia(QUrl("qrc:/sounds/GameOver.wav"));
    fallBall->play();

        game->scene->clear();
    }
    }

   else if(x()==970)//right edge
    {

        dx=-1*dx;
        setPos(x()+dx,y()+dy);
    }

    else//moving
    {
        setPos(x()+dx,y()+dy);firsmv=1;
    }
    return;
}
