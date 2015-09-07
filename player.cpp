#include<QKeyEvent>
#include"player.h"
#include"ball.h"
#include <QDebug>
#include "bodygame.h"
#include<QMediaPlayer>

//constructor to set the player shape
Player::Player()
{
    spaces=0;
    setPixmap(QPixmap(":/images/rounded_rectangle_0525.jpg"));
}

extern BodyGame *game;
extern bool firsmv;//to let the ball change it is position when the player change

//organize the movement of the player and setting position when it fails
void Player::keyPressEvent(QKeyEvent *event)
{
    if(game->health->getHealth()!=0&&game->score->getScore()!=56){
        if(event->key() == Qt :: Key_Left&& pos().x()-10 >= 0){
            setPos(x()-45 , y());
            if(game->B->firsmv==0)game->B->setPos(game->B->x()-45, game->B->y());
        }else if(event->key() == Qt::Key_Right && pos().x()+60 < 860){
            setPos(x()+45, y());
            if(game->B->firsmv==0)game->B->setPos(game->B->x()+45, game->B->y());
        }
        else if(event->key() == Qt:: Key_Space){
            QMediaPlayer * hitBall = new QMediaPlayer();
            hitBall->setMedia(QUrl("qrc:/sounds/hitBall.wav"));
            hitBall->play();
            if(game->B->firsmv==0)game->B->moveball();
        }
    }
    if(event->key() == Qt:: Key_Return||event->key() == Qt:: Key_Enter){
        if(game->health->getHealth()==0||game->score->getScore()==56){
            game->startgame=0;
            delete game;
            BodyGame*game=new BodyGame();
            game->show();
            }
        }
}
