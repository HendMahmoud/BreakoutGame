#include <QApplication>
#include <QGraphicsScene>
#include "demond.h"
#include <QGraphicsView>
#include "bodygame.h"
#include<QDebug>
#include "startmenu.h"

BodyGame * game ;
bool ballmove=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Breakout Game");
    srand((unsigned)time(0));

    game = new BodyGame();
    game->show();

    return a.exec();
}

