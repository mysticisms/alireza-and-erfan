#ifndef FUEL_H
#define FUEL_H

#include <QGraphicsTextItem>
class Fuel: public QGraphicsTextItem
{
public:
    Fuel(QGraphicsItem * parent=0);
    int getFuel();
public slots:
    void decrease();
private:
    float fuel;
};

#endif // FUEL_H
