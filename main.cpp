#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <vector>
using namespace std ;

void creatingDiamonds(QGraphicsScene *sc){
    vector <MyRect *>demond(10);
    //MyRect *= new MyRect();
    for (int i = 0 , j= 100 ; i < 9; j+= 100,++i) {
        demond[i]=new MyRect();
        demond[i] ->setRect(55+j,-300,100,50);
        sc ->addItem(demond[i]);
    }




//    MyRect *demond2 =new MyRect();
//    demond2 ->setRect(-55,-300,100,50);

//    sc ->addItem(demond2);

//    MyRect *demond3 =new MyRect();
//    demond3 ->setRect(165,-300,100,50);

//    sc ->addItem(demond3);

//    MyRect *demond4 =new MyRect();
//    demond4 ->setRect(-165,-300,100,50);

//    sc ->addItem(demond4);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    MyRect *rec =new MyRect();
    rec ->setRect(0,300,100,10);

    scene ->addItem(rec);

    creatingDiamonds(scene);

    rec -> setFlag(QGraphicsRectItem::ItemIsFocusable);
    rec -> setFocus();

    QGraphicsView * vi = new QGraphicsView(scene);
    vi -> show();

    return a.exec();
}

