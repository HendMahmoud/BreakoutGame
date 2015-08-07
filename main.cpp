#include <QApplication>
#include <QGraphicsScene>
#include "demond.h"
#include <QGraphicsView>
#include "bodygame.h"
#include<QDebug>

BodyGame * game ;
bool ballmove=0;

int main(int argc, char *argv[])
{
    srand((unsigned)time(0));
    game = new BodyGame();
    QApplication a(argc, argv);

    game->show();

    return a.exec();
}

