#include"score.h"
#include<QFont>
#include<QMediaPlayer>
 Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    score = 55 ;
    setPos(x(), y());
    setPlainText("Score : "+QString :: number (score));
    setDefaultTextColor(Qt:: black);
    setFont(QFont("time", 15));
}

void Score::increase(){
    score++ ;
    QMediaPlayer * ball= new QMediaPlayer();
        ball->setMedia(QUrl("qrc:/sounds/mouseDown.mp3"));
        ball->play();
    setPlainText("Score :"+QString :: number(score));
}
int Score:: getScore(){
    return score;
}
