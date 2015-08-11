#ifndef STARTMENU_H
#define STARTMENU_H
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
//#include <QObject>

class StartMenu :public QGraphicsRectItem
{
    //Q_OBJECT
public:

    StartMenu();
    void viewit();
    void keyPressEvent(QKeyEvent *event);

};

#endif // STARTMENU_H
