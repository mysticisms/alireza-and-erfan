#ifndef GAME_H
#define GAME_H

#include "Game.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "enemy.h"
#include "fuel.h"
#include "score.h"
#include <QMediaPlayer>

class Game : public QGraphicsView{
public:
    Game(QWidget * parent=0);
    int Level;
    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Fuel * fuel;
    Score * score;
    QMediaPlayer * music;



};

#endif // GAME_H
