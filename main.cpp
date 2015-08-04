#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

void creatingDiamonds(QGraphicsScene *sc){
    MyRect *demond1 =new MyRect();
    demond1 ->setRect(55,-300,100,50);

    sc ->addItem(demond1);

    MyRect *demond2 =new MyRect();
    demond2 ->setRect(-55,-300,100,50);

    sc ->addItem(demond2);

    MyRect *demond3 =new MyRect();
    demond3 ->setRect(165,-300,100,50);

    sc ->addItem(demond3);

    MyRect *demond4 =new MyRect();
    demond4 ->setRect(-165,-300,100,50);

    sc ->addItem(demond4);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *sc = new QGraphicsScene();

    MyRect *rec =new MyRect();
    rec ->setRect(0,300,100,10);

    sc ->addItem(rec);

    creatingDiamonds(sc);

    rec -> setFlag(QGraphicsRectItem::ItemIsFocusable);
    rec -> setFocus();

    QGraphicsView * vi = new QGraphicsView(sc);
    vi -> show();

    return a.exec();
}
