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
class BodyGame{
public:
    BodyGame();
    void creatingDiamonds() ;
    QGraphicsScene *scene ;
    Player * player  ;
    QGraphicsView * view ;
    Score *score;
    void show();
};

#endif // BODYGAME_H
