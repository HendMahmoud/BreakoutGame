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
    QTimer * timer;
    int dx,dy;
    bool firsmv;
    static float speed ;

    //constructor
    ball();

    //destructor
    ~ball();

    //start the move of the ball and intilize it's speed
    void moveball();

public slots:
    //moving the ball when it touchs object or fail
    void move();
};

#endif // BALL_H
