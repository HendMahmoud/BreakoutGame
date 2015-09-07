#ifndef RECT_H
#define RECT_H
#include<QGraphicsPixmapItem>
class Player : public QGraphicsPixmapItem{
public:
    //constructor to set the player shape
      Player();

      //organize the movement of the player and setting position when it fails
      void keyPressEvent(QKeyEvent *event);

private:
        int spaces;
};

#endif // RECT_H
