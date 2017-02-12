#include "ground.h"

ground::ground(/*QObject *parent*/int x) /*:
    QObject(parent)*/
{
    int xpos = 10+x*37;
    setPixmap(QPixmap("img2/ground2.png").scaled(37,320));
    setPos(xpos,370);
}
