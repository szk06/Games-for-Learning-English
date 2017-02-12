#include "hole.h"

hole::hole(/*QObject *parent*/int x)/* :
    QObject(parent)*/
{
    int xpos = 10+37*x;
    setPixmap(QPixmap("img2/ground2.png").scaled(37,590));
    setPos(xpos,300);
}
