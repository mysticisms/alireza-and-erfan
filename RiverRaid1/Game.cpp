#include "Game.h"
#include <QBrush>
#include <QImage>
#include <QTimer>
#include "enemy.h"
#include "fueldepot.h"
#include "score.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
    Level =1;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,700);
    setBackgroundBrush(QBrush(QImage(":/img/1.jpg")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,700);

    player = new Player();
    player->setPos(200,580);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //enemy = new Enemy();
    //scene->addItem(enemy);



    fuel = new Fuel();
    fuel->setPos(fuel->x(),fuel->y()+25);
    scene->addItem(fuel);




    score = new Score();
    scene->addItem(score);


    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


    show();
}
