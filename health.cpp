#include "health.h"
#include<QFont>
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){
    health = 3;
    setPos(x(), y()+35);
    setPlainText("Health : "+QString:: number(health));
   setFont(QFont("time",18));// For type of font and the size
   setDefaultTextColor(Qt::red);
}

void Health::decrease(){
    health--;
     setPlainText("time"+QString:: number(health)); // to overwriting the new health

}
int Health ::getHealth(){
    return health;
}
