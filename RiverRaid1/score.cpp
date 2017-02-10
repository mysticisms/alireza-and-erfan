#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    score = 0;


    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int s){
    score += s;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
