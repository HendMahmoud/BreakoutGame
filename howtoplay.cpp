#include"bodygame.h"
#include"howtoplay.h"

extern BodyGame * game;

//constructor to set the screen of how to play
howtoplay::howtoplay()
{
    setPixmap(QPixmap(":/images/how to play.jpg"));

}

//when pressing space to return to main menu
void howtoplay::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
    {
        delete this;
         game->startmenu->setFlag(QGraphicsRectItem::ItemIsFocusable);
         game->startmenu-> setFocus();
    }
}
