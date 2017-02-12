
/**
*\file ground.h
*\brief This class represents the ground that the criminal will pass on
*
The class will set the position of the ground in the game scene
*\author Sami & Mohammad Ali

*/
#include "ground32.h"


/**

*\brief Constructor of the Ground sets the position and the Image
*\param x coordinate of the ground

*/
ground32::ground32(/*QObject *parent*/int x) /*:
    QObject(parent)*/
{
    int xpos = 10+x*37;
    setPixmap(QPixmap("img2/ground2.png").scaled(37,320));
    setPos(xpos,370);
}
