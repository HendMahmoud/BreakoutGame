#ifndef RECT_H
#define RECT_H
#include<QGraphicsRectItem>
#include<QObject>
class Player :public QObject,  public QGraphicsRectItem{
    Q_OBJECT
    public:
        Player();
        void keyPressEvent(QKeyEvent *event);
//    public slots :
//        void spawn();
};

#endif // RECT_H
