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

Helicopter::Helicopter(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    qDebug("helec");
    QPixmap HelecIcon(":/img/helec.png");
    QPixmap Helecresize = HelecIcon.scaled(QSize(100,100) ,Qt::KeepAspectRatio);
    setPixmap(Helecresize);
    setTransformOriginPoint(50,50);
    QTimer * Htimer = new QTimer(this);
    qDebug("kone time");
    connect(Htimer,SIGNAL(timeout()),this,SLOT(move()));
    Htimer->start(100);
     qDebug("kone bade time");
    long randtime = time(NULL);
    int stime = (unsigned) randtime/2;
    srand(stime);

    direction=rand()%2;
     qDebug("koneaaaaaaaaaaaaa time");
}

Helicopter::~Helicopter(){

    scene()->removeItem(this);
    qDebug("delete");

}

void Helicopter::move(){


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
        setPos(x()+RiverRaid->Level*3,y()+RiverRaid->Level*5);
    }
    else{
        setPos(x()-RiverRaid->Level*3,y()+RiverRaid->Level*5);
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


