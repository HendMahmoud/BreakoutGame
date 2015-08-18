#ifndef HOWTOPLAY
#define HOWTOPLAY
#include<QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsTextItem>

class howtoplay:public QGraphicsPixmapItem
{

public:
    howtoplay();
    void keyPressEvent(QKeyEvent *event);

};




#endif // HOWTOPLAY

