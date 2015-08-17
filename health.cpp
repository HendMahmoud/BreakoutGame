#include "health.h"
#include<QFont>
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){
    health = 3;
    setPos(x(), y()+35);
    setPlainText("Health : "+QString:: number(health));
   setFont(QFont("time",15));// For type of font and the size
   setDefaultTextColor(Qt::black);
}

void Health::decrease(){
    health--;
     setPlainText("Health : "+QString:: number(health)); // to overwriting the new health

}
int Health ::getHealth(){
    return health;
}
