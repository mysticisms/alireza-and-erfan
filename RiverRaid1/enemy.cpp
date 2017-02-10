#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QBrush>
#include <QImage>
#include <time.h>
#include <typeinfo>
#include "Game.h"
#include "fueldepot.h"



extern Game * RiverRaid;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    long randtime = time(NULL);
    int stime = (unsigned) randtime/2;
    srand(stime);

    int randX;
    randX= rand() % 400;
    setPos(randX,20);

    int randEnemy;
    randEnemy = rand() % 3 ;
    //randEnemy=2;

    switch (randEnemy) {

    case 0:{
        helicopter = new Helicopter();
        helicopter->setPos(randX,20);
        RiverRaid->scene->addItem(helicopter);
        qDebug("koooose hel");
        break;
    }


    case 1:{
        jet = new Jet();
        jet->setPos(randX,20);
        RiverRaid->scene->addItem(jet);
        qDebug(" hel");
        break;
    }


    case 2:{

        ship = new Ship();
        ship->setPos(randX,20);
        RiverRaid->scene->addItem(ship);
        qDebug(" hel");

        FuelDepot * oil ;
        oil = new FuelDepot();
        int oilpos;
        oilpos= (randX +100) % 400;
        oil->setPos(oilpos,25);
        RiverRaid->scene->addItem(oil);

        break;
    }

    }

}





