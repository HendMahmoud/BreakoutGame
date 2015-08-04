#include <QApplication>
#include <QGraphicsScene>
#include "demond.h"
#include <QGraphicsView>
#include "bodygame.h"
#include<QDebug>

BodyGame * game ;
int main(int argc, char *argv[])
{
    game = new BodyGame();
    QApplication a(argc, argv);
    game->show();
    return a.exec();
}

