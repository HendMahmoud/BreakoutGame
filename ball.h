#ifndef BALL_H
#define BALL_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include<QMediaPlayer>

class ball :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QMediaPlayer *fallBall;

    ball();
    void moveball();
    static float speed ;
public slots:
    void move();
};

#endif // BALL_H
