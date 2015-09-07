#include "health.h"
#include<QFont>

//constructor to set health word on screen and intialize the healths of the player
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){
    health = 3;
    setPos(x(), y()+35);
    setPlainText("Health : "+QString:: number(health));
   setFont(QFont("time",15));// For type of font and the size
   setDefaultTextColor(Qt::black);
}

//decrease the health of the player when the ball fall
void Health::decrease(){
    health--;
     setPlainText("Health : "+QString:: number(health)); // to overwriting the new health
}

//return the current health
int Health ::getHealth(){
    return health;
}
