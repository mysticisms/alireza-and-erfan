#include <QApplication>
#include "Game.h"

Game  * RiverRaid;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    RiverRaid = new Game();
    RiverRaid->show();

    return a.exec();
}
