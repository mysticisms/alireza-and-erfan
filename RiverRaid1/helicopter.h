#ifndef HELICOPTER_H
#define HELICOPTER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "gameover.h"

class Helicopter: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Helicopter(QGraphicsItem * parent=0);
    GameOver * gameover;
    ~Helicopter();
    int direction;
public slots:
    void move();
};

#endif // HELICOPTER_H
