#include "gameover.h"
#include "score.h"
#include <QFont>

GameOver::GameOver(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("Game over"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",56));

}
