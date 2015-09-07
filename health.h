#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    //constructor to set health word on screen and intialize the healths of the player
    Health(QGraphicsItem * parent=0);

    //decrease the health of the player when the ball fall
    void decrease();

    //return the current health
    int getHealth();

private :
    int health ;
};

#endif // HEALTH_H
