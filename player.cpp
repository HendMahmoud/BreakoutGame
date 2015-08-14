#include<QKeyEvent>

#include"player.h"
#include"ball.h"
#include <QDebug>
#include "bodygame.h"
#include<QMediaPlayer>
Player::Player()
{
    spaces=0;
    setPixmap(QPixmap(":/images/rounded_rectangle_0525.jpg"));
}
extern BodyGame *game;

extern bool firsmv;//to let the ball change it is position when the player change
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt :: Key_Left&& pos().x()-10 >= 0){
        setPos(x()-45 , y());
        if(firsmv==0)game->B->setPos(game->B->x()-45, game->B->y());
    }else if(event->key() == Qt::Key_Right && pos().x()+60 < 860){
        setPos(x()+45, y());
        if(firsmv==0)game->B->setPos(game->B->x()+45, game->B->y());
    }
    else if(event->key() == Qt:: Key_Space){
        QMediaPlayer * hitBall = new QMediaPlayer();
        hitBall->setMedia(QUrl("qrc:/sounds/hitBall.wav"));
        hitBall->play();
        if(firsmv==0)game->B->moveball();
    }
    else if(event->key() == Qt:: Key_Enter){
        if(game->health->getHealth()==0||game->score->getScore()==56){
            game->startgame=0;
            game->scene->clear();
            game->show();
        }
    }
    int arr[27];
    arr[26]=Qt::Key_Space;
    for (int i = 0; i < 26; ++i) {
        arr[i]=Qt::Key_A+i;
    }
    for (int i = 0; i < 27; ++i) {
        if(((int)event->key()) == arr[i]){
            QString s;
            for (int j = 0; j < spaces; ++j) s+="  ";

            s+=arr[i];
            if(game->health->getHealth()==0||game->score->getScore()==56)
                game ->userinput(s);spaces++;
        }
    }


}

//void Player::spawn(){
//    Enemy *enemy = new Enemy();
//    Enemy * enemy2 = new Enemy();
//    scene()->addItem(enemy);
//    scene()->addItem(enemy2);
//}
