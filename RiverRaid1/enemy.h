#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "fueldepot.h"
#include "ship.h"
#include "helicopter.h"
#include "jet.h"

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FuelDepot *oil;
    Ship * ship;
    Jet * jet;
    Helicopter * helicopter;

    Enemy(QGraphicsItem * parent=0);

};

#endif // ENEMY_H
