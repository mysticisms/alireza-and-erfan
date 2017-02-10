#ifndef SHIP_H
#define SHIP_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "gameover.h"


class Ship: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ship(QGraphicsItem * parent=0);
    ~Ship();
    int direction;
    GameOver * gameover;
public slots:
    void move();
};

#endif // SHIP_H
