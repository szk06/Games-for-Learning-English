/**
\file balloon.cpp
\brief This class represent the balloons
*
The class contains represents the bolloon and its movement

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include "balloon.h"
/**
\brief Constructor of the balloon class
\param level of type int
\param parent of type QObject
\param QString color

*
In this function, the arrow's position is updated

*/
balloon::balloon(int level, QString color, QObject *parent) :
    QObject(parent)
{
    this->game_level = level;
    this->balloon_color = color;

    setPixmap(QPixmap("img/"+color+".png").scaled(100,100));

    this->balloon_timer = new QTimer(this);
    connect(balloon_timer, SIGNAL(timeout()), this, SLOT(update()));
}
/**
\brief fly of the balloon

*
In this function, the balloon's timer is started

*/
void balloon::fly()
{
    this->balloon_timer->start((3/game_level)*600);
}
/**
\brief update balloon position

*
In this function, the balloon's position is updated

*/
void balloon::update()
{

    if ( (y() - 50) < 0 )
    {
            scene()->removeItem(this);
            delete this;
    }
    else
    {
        setPos(x(), y() - 50);
    }
}
