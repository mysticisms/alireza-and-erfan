#include "ship.h"
#include "helicopter.h"
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
#include "gameover.h"



extern Game * RiverRaid;

Ship::Ship(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    qDebug("ship");
    QPixmap playerIcon(":/img/ship.png");
    QPixmap resize = playerIcon.scaled(QSize(90,90) ,Qt::KeepAspectRatio);
    setPixmap(resize);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);

    long randtime = time(NULL);
    int stime = (unsigned) randtime/2;
    srand(stime);

    direction=rand()%2;

}

Ship::~Ship(){

    scene()->removeItem(this);
    qDebug("delete");

}

void Ship::move(){

    QList<QGraphicsItem *> colliding_items = scene()->collidingItems(this);
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            qDebug("destructor enemy");
            delete colliding_items[i];
            delete this;
            gameover = new GameOver();
            gameover->setPos(150,400);
            RiverRaid->scene->addItem(gameover);
            return;
        }

    }

    if(direction){
        setPos(x()+RiverRaid->Level*1,y()+RiverRaid->Level*5);
    }
    else{
        setPos(x()-RiverRaid->Level*1,y()+RiverRaid->Level*5);
    }


    if(pos().x()>400){
       direction=0;
    }
    else if (pos().x()<0){
        direction=1;
    }


    if (pos().y() > 700){
        delete this;
    }

}


