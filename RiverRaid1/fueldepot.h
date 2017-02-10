#ifndef FUELDEPOT_H
#define FUELDEPOT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class FuelDepot: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FuelDepot(QGraphicsItem * parent=0);
    ~FuelDepot();
public slots:
    void move();
};

#endif // FUELDEPOT_H
