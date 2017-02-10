#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "Game.h"
#include "enemy.h"
#include <QMediaPlayer>


extern Game * RiverRaid;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    QPixmap playerIcon(":/img/bullet.png");
    QPixmap resize = playerIcon.scaled(QSize(60,60) ,Qt::KeepAspectRatio);
    setPixmap(resize);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    qDebug("constractor");


}

Bullet::~Bullet(){
    qDebug("destructor");
    scene()->removeItem(this);
}

void Bullet::move(){

    RiverRaid->Level=RiverRaid->score->score/800 +1;



    QList<QGraphicsItem *> colliding_items = scene()->collidingItems(this);
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Ship)){

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/img/bomb-02.mp3"));
            music->play();
            RiverRaid->score->increase(30);
            qDebug("destructor enemy");
            delete colliding_items[i];
            qDebug("destructor bullet");
            delete this;


            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Jet)){
            //scene()->removeItem(colliding_items[i]);
            //scene()->removeItem(this);
            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/img/bomb-02.mp3"));
            music->play();
            RiverRaid->score->increase(100);
            qDebug("destructor enemy");
            delete colliding_items[i];
            qDebug("destructor bullet");
            delete this;

            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Helicopter)){
            //scene()->removeItem(colliding_items[i]);
            //scene()->removeItem(this);
            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/img/bomb-02.mp3"));
            music->play();
            RiverRaid->score->increase(60);
            qDebug("destructor enemy");
            delete colliding_items[i];
            qDebug("destructor bullet");
            delete this;

            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(FuelDepot)){
            //scene()->removeItem(colliding_items[i]);
            //scene()->removeItem(this);
            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/img/bomb-02.mp3"));
            music->play();
            RiverRaid->score->increase(150);
            qDebug("destructor enemy");
            delete colliding_items[i];
            qDebug("destructor bullet");
            delete this;

            return;
        }


    }



    qDebug("move");
    setPos(x(),y()-10);
    if (pos().y() < 0){
        qDebug("if state");
        delete this;
    }
}
