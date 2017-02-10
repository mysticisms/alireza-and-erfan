#include "fueldepot.h"
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
#include "fuel.h"


extern Game * RiverRaid;

FuelDepot::FuelDepot(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    QPixmap oilIcon(":/img/oil.png");
    QPixmap oilresize = oilIcon.scaled(QSize(30,30) ,Qt::KeepAspectRatio);
    setPixmap(oilresize);
    setTransformOriginPoint(50,50);


    QTimer * Otimer = new QTimer(this);

    connect(Otimer,SIGNAL(timeout()),this,SLOT(move()));

    Otimer->start(100);

}

FuelDepot::~FuelDepot(){

    scene()->removeItem(this);


}

void FuelDepot::move(){

    QList<QGraphicsItem *> colliding_items = scene()->collidingItems(this);
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){

            RiverRaid->fuel->getFuel();
            delete this;
            return;
        }

    }

    setPos(x(),y()+5);

    if (pos().y() > 700){
        delete this;
    }

}
