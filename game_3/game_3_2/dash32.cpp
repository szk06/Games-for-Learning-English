#include "dash32.h"
/**
*\brief constructor sets the position of the dash in the scene
*\param x position of the dash

*/
dash32::dash32(/*QObject *parent*/int x)/* :
    QObject(parent)*/
{

     setPixmap(QPixmap("img2/dash.png").scaled(55,120));
     setPos(x,200);

}
