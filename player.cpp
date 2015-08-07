#include<QKeyEvent>
#include<QGraphicsScene>
#include"player.h"
Player::Player(){
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt :: Key_Left&& pos().x()-10 >= 0){
        setPos(x()-10 , y());
    }else if(event->key() == Qt::Key_Right && pos().x()+60 < 800){
        setPos(x()+10, y());
    }/*else if(event->key() == Qt:: Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }*/
}

//void Player::spawn(){
//    Enemy *enemy = new Enemy();
//    Enemy * enemy2 = new Enemy();
//    scene()->addItem(enemy);
//    scene()->addItem(enemy2);
//}
