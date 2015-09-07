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
    Score *score;
    QGraphicsTextItem * pusetext;
    int startgame;
    ball * B;
    StartMenu * startmenu;
    Health *health;

    //constructor to intialize new game view
    BodyGame();

    //destructor
    ~BodyGame();

    //creats the diamonds in the new game
    void creatingDiamonds() ;

    //moving between main menu and new game screen and how to play screen
    void show();

    //show to screen of the ending
    void finishView();

};

#endif // BODYGAME_H
