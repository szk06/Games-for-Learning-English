/**
\file arrow.cpp
\brief This class represent the arrow shot from the bow
*
The class contains represents the arrow and its movement

\author Sami Kanafani & Mohamad Ali Mahaidli

*/

#include "arrow.h"

/**
\brief Constructor of the arrow class
\param parent of type QWidget
\param color of type QString
\param x coordinate of type qreal
\param y coordinate of type qreal
\param angle of type int
*
In this function, all the buttons of the myacccount class are created,and the setLayout function is called

*/
arrow::arrow(QString color, qreal x, qreal y, int angle, QObject *parent) :
    QObject(parent)
{
    setPixmap(QPixmap("img/arrow.png").scaled(50,50));

    timer= new QTimer(this);

    this->target_color = color;

    this->angle = angle;

    this->translate(25,25);
    this->rotate(angle);
    this->translate(-25, -25);

    this->step_x = -5*sin(angle*3.14159/180.0);
    this->step_y = 5*cos(angle*3.14159/180.0);

    setPos(x+25,y+25);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}
/**
\brief Constructor of the arrow class

*
In this function, the arrow's timer starts

*/
void arrow::shoot()
{
    timer->start(10);
}
/**
\brief Constructor of the arrow class

*
In this function, the arrow's position is updated

*/
void arrow::update()
{
    this->setPos(this->x()-step_x, this->y()-step_y);

    if (y() < 0 || x() < 0 || x() > 750)
    {
        scene()->removeItem(this);
        delete this;
    }
    else
    {
        bool remove = false;
        // check for collisions
        // check if it hit a balloon
        QList<QGraphicsItem *> colliding_items = this->scene()->collidingItems(this);
        for(int i=0;i<colliding_items.size();i++)
        {
            QGraphicsItem* temp = colliding_items.at(i);
             if(typeid(*temp)==typeid(balloon))
             {

                 balloon *hit_balloon  = dynamic_cast<balloon *>(temp);
                 if(hit_balloon->balloon_color == this->target_color)
                 {
                     emit send_score_to_bow(true);
                 }
                 else
                 {
                     emit send_score_to_bow(false);
                 }
                 // remove balloon and arrow
                 scene()->removeItem(temp);
                 delete temp;
                 remove = true;
                 break;
             }
         }
        if (remove)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
