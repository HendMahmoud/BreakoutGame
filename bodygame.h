#ifndef BODYGAME_H
#define BODYGAME_H
#include <QApplication>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsTextItem>
#include"demond.h"
#include "player.h"
#include"health.h"
#include "ball.h"
#include "score.h"
#include "startmenu.h"
class BodyGame{
public:
    QGraphicsScene *scene ;
    Player * player  ;
    StartMenu *startmenu ;
    Score *score;

    bool startgame;
    ball * B;

    BodyGame();
    ~BodyGame();
    void creatingDiamonds() ;

    Health *health;

    void show();
    void finishView();
    void keyPressEvent(QKeyEvent *event);
    void userinput(QString);
};

#endif // BODYGAME_H
