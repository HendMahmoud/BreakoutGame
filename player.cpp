#include<QKeyEvent>

#include"player.h"
#include"ball.h"
#include <QDebug>
#include "bodygame.h"

Player::Player()
{
    spaces=0;
    setPixmap(QPixmap(":/images/rounded_rectangle_0525.jpg"));
}
extern BodyGame *game;
extern ball *B;
extern bool firsmv;
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt :: Key_Left&& pos().x()-10 >= 0){
        setPos(x()-15 , y());
        if(firsmv==0)B->setPos(B->x()-15, B->y());
    }else if(event->key() == Qt::Key_Right && pos().x()+60 < 860){
        setPos(x()+15, y());
        if(firsmv==0)B->setPos(B->x()+15, B->y());
    }
    else if(event->key() == Qt:: Key_Space){
        if(firsmv==0)B->moveball();
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
