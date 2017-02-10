#ifndef JET_H
#define JET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "gameover.h"


class Jet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Jet(QGraphicsItem * parent=0);
    ~Jet();
     GameOver * gameover;
    int direction;
public slots:
    void move();
};

#endif // JET_H
