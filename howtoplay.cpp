#include"bodygame.h"
#include"howtoplay.h"

extern BodyGame * game;

howtoplay::howtoplay()
{
    setPixmap(QPixmap(":/images/how to play.jpg"));

}


void howtoplay::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
    {
        delete this;
         game->startmenu->setFlag(QGraphicsRectItem::ItemIsFocusable);
         game->startmenu-> setFocus();
    }
}
