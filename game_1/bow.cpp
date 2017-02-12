/**
\file bow.cpp
\brief This class represent the bow that shoots
*
The class contains represents the bow and its movement

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include "bow.h"
#include <QKeyEvent>

/**
\brief Constructor of the account_widget class
\param parent of type QWidget

*
In this function, all the buttons of the myacccount class are created,and the setLayout function is called

*/
bow::bow(QObject *parent) :
    QObject(parent)
{
    target_color = "Red";
    setPixmap(QPixmap("img/bow.png").scaled(100,100));
     angle = 0;
}

void bow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
    {
        if (angle < 30)
        {
            this->translate(50,50);
            this->rotate(10);
            this->translate(-50,-50);
            angle += 10;
        }
    }
    if (event->key() == Qt::Key_Down)
    {
        if (angle > -30)
        {
            this->translate(50,50);
            this->rotate(-10);
            this->translate(-50,-50);
            angle -= 10;
        }
    }
    if (event->key() == Qt::Key_Right)
    {
        if ((x() + 50) < 720 )
        {
            setPos(x() + 50, y());
        }
    }
    if (event->key() == Qt::Key_Left)
    {
        if ((x() - 50) > 0)
        {
            setPos(x() - 50, y());
        }
    }
    if (event->key() == Qt::Key_Space)
    {
        arrow *temp = new arrow(target_color, x(), y(), angle);
        connect(temp, SIGNAL(send_score_to_bow(bool)),this, SLOT(update_bow_score(bool)));
        scene()->addItem(temp);
        temp->shoot();
    }
}
void bow::update_bow_color(QString new_color)
{
    this->target_color = new_color;
}

void bow::update_bow_score(bool correct)
{
    emit update_widget_score(correct);
}
