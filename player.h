#ifndef RECT_H
#define RECT_H
#include<QGraphicsPixmapItem>
#include<QObject>
class Player :public QObject,  public QGraphicsPixmapItem{
    Q_OBJECT
    public:
        Player();
        void keyPressEvent(QKeyEvent *event);
//    public slots :
//        void spawn();
};

#endif // RECT_H
