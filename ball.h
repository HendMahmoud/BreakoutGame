#ifndef BALL_H
#define BALL_H
#include <QGraphicsPixmapItem>
#include <QObject>

class ball :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ball();
    void moveball();
public slots:
    void move();
};

#endif // BALL_H
