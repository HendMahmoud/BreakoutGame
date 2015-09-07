#ifndef SCORE
#define SCORE
#include<QGraphicsTextItem>
#endif // SCORE

class Score : public QGraphicsTextItem{
public:
    //constructor to intialize score and put it on screen
    Score(QGraphicsItem * parent = 0 );

    //increase score when ball hits diamond
    void increase ();

    //return the score value
    int getScore();
private :
    int score ;
};
