#include "jet.h"
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
#include <QFont>
#include "fueldepot.h"



extern Game * RiverRaid;

Jet::Jet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    qDebug("jet");
    QPixmap JetIcon(":/img/jet.png");
    QPixmap Jetresize = JetIcon.scaled(QSize(60,60) ,Qt::KeepAspectRatio);
    setPixmap(Jetresize);

    QTimer * Jtimer = new QTimer(this);
    connect(Jtimer,SIGNAL(timeout()),this,SLOT(move()));
    Jtimer->start(100);

    long randtime = time(NULL);
    int stime = (unsigned) randtime/2;
    srand(stime);

    direction=rand()%2;

}

Jet::~Jet(){

    scene()->removeItem(this);
    qDebug("delete");

}

void Jet::move(){

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
        setPos(x()+RiverRaid->Level*5,y()+RiverRaid->Level*5);
    }
    else{
        setPos(x()-RiverRaid->Level*5,y()+RiverRaid->Level*5);
    }


    if(pos().x()>450){
       direction=0;
    }
    else if (pos().x()<0){
        direction=1;
    }


    if (pos().y() > 700){
        delete this;
    }

}


