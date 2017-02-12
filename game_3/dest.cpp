#include "dest.h"
/**
*\brief Conctructor of the destination and sets position

*/
dest::dest(QObject *parent) :
    QObject(parent)
{
    setPixmap(QPixmap("img3/vict.jpeg").scaled(700,90));
    setPos(50,35);

}
