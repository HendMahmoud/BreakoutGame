#include<QKeyEvent>
#include<QGraphicsScene>
#include"player.h"
#include"ball.h"
#include <QDebug>

Player::Player()
{
    setPixmap(QPixmap(":/images/rounded_rectangle_0525.jpg"));
}

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
}

//void Player::spawn(){
//    Enemy *enemy = new Enemy();
//    Enemy * enemy2 = new Enemy();
//    scene()->addItem(enemy);
//    scene()->addItem(enemy2);
//}
