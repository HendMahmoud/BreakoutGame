#include <QGraphicsRectItem>


#ifndef MYRECT_H
#define MYRECT_H

class MyRect:public QGraphicsRectItem
{
public:
    MyRect() {}
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYRECT_H
