#include "fuel.h"
#include <QFont>
#include "Game.h"

extern Game * RiverRaid;

Fuel::Fuel(QGraphicsItem *parent): QGraphicsTextItem(parent){

    fuel = 30;


    setPlainText(QString("fuel: ") + QString::number(fuel));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Fuel::decrease(){
    if(fuel<0){
        delete RiverRaid->player;
        setPlainText(QString("fuel: ") + QString::number(0));
        return;
    }
    fuel-=.05;
    setPlainText(QString("fuel: ") + QString::number(fuel));
}

int Fuel::getFuel(){
    fuel = 30;
    setPlainText(QString("fuel: ") + QString::number(fuel));
}

