#ifndef BALL_H
#define BALL_H
#include <QGraphicsEllipseItem>
#include <QObject>

class ball :public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    ball();
    void moveball();
public slots:
    void move();
};

#endif // BALL_H
