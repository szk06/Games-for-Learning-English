/**

*\file criminal.cpp
*\brief This class represents the criminal
*
contains the methods of the criminal such as move

*\author Sami & Mohammad Ali
*/
#include "criminal.h"
/**
\brief Constructor of the criminal, sets the image of the criminal

*/
criminal::criminal(QObject *parent) :
    QObject(parent)
{
    setPixmap(QPixmap("img2/criminal.png").scaled(37,120));
    setPos(10,410);
}
/**
\brief Sets the position of the criminal based on the answer of the player

*/
void criminal::ChangePosition(int x){
    setPos(x,y());
}
