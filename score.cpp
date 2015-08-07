#include"score.h"
#include<QFont>

 Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    score = 0 ;
    setPos(x(), y());
    setPlainText("Score :"+QString :: number (score));
    setDefaultTextColor(Qt:: blue);
    setFont(QFont("time", 18));
}

void Score::increase(){
    score++ ;
    setPlainText("Score :"+QString :: number(score));
}
int Score:: getScore(){
    return score;
}
