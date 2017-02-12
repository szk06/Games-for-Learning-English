/**
*\file road.cpp
*\brief road that the player will walk on

*/
#ifndef ROAD_H
#define ROAD_H

#include <QObject>
#include<QGraphicsPixmapItem>

class road : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit road(bool x);
    bool ishorizontal;
    
signals:
    
public slots:
    
};

#endif // ROAD_H
