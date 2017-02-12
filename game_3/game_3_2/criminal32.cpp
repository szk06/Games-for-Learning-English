/**

*\file criminal.cpp
*\brief This class represents the criminal
*
contains the methods of the criminal such as move

*\author Sami & Mohammad Ali
*/
#include "criminal32.h"
/**
\brief Constructor of the criminal, sets the image of the criminal

*/
criminal32::criminal32(QObject *parent) :
    QObject(parent)
{
    setPixmap(QPixmap("img2/criminal.png").scaled(37,120));
    setPos(10,410);
}
/**
\brief Sets the position of the criminal based on the answer of the player

*/
void criminal32::ChangePosition(int x){
    setPos(x,y());
}
