/**
*\file hole.cpp
*\brief This class represents the hole that the criminal will fall in
*
The class will set the position of the hole in the game scene
*\author Sami & Mohammad Ali

*/

#include "hole32.h"

/**
*\brief hole constructor sets the image and position
*\param x position of the hole
*/
hole32::hole32(/*QObject *parent*/int x)/* :
    QObject(parent)*/
{
    int xpos = 10+37*x;
    setPixmap(QPixmap("img2/ground2.png").scaled(37,590));
    setPos(xpos,300);
}
