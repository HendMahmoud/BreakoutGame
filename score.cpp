#include"score.h"
#include<QFont>
#include<QMediaPlayer>

//constructor to intialize score and put it on screen
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    score = 0 ;
    setPos(x(), y());
    setPlainText("Score : "+QString :: number (score));
    setDefaultTextColor(Qt:: black);
    setFont(QFont("time", 15));
}

//increase score when ball hits diamond
void Score::increase(){
    score++ ;
    QMediaPlayer * ball= new QMediaPlayer();
        ball->setMedia(QUrl("qrc:/sounds/mouseDown.mp3"));
        ball->play();
    setPlainText("Score :"+QString :: number(score));
}

//return the score value
int Score:: getScore(){
    return score;
}
