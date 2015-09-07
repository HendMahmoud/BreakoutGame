#ifndef STARTMENU_H
#define STARTMENU_H
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
//#include <QObject>

class StartMenu :public QGraphicsRectItem
{
    //Q_OBJECT
public:
    //constructor to intialize the winfow size
    StartMenu();

    //show and set the main menu screen
    void viewit();

    //manage what will happen when moving the square and making choise in the main menu
    void keyPressEvent(QKeyEvent *event);

};

#endif // STARTMENU_H
