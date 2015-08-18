#ifndef RECT_H
#define RECT_H
#include<QGraphicsPixmapItem>
class Player : public QGraphicsPixmapItem{
    public:
        Player();
        void keyPressEvent(QKeyEvent *event);
private:
        int spaces;
};

#endif // RECT_H
