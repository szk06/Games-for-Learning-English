/**
\file arrow.cpp
\brief This class represent the arrow shot from the bow
*
The class contains represents the arrow and its movement

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>
#include <typeinfo>

#include "balloon.h"

class arrow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit arrow(QString color, qreal x, qreal y, int angle, QObject *parent = 0);
    QTimer* timer;//!<timer of update
    QString target_color;//!<color to target at time of launch
    int angle; //!<angle of arrow
    int step_x;//!<size of shift on x axis
    int step_y;//!<size of shift on y axis
    void shoot();

signals:
    void send_score_to_bow(bool correct); //!<signal to send on collision
public slots:
    void update();
};

#endif // ARROW_H
