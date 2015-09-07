#ifndef HOWTOPLAY
#define HOWTOPLAY
#include<QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsTextItem>

class howtoplay:public QGraphicsPixmapItem
{

public:
    //constructor to set the screen of how to play
    howtoplay();

    //when pressing space to return to main menu
    void keyPressEvent(QKeyEvent *event);

};




#endif // HOWTOPLAY

