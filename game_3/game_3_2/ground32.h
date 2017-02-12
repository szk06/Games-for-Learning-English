/**
*\file ground.cpp
*\brief This class represents the ground that the criminal will pass on
*
The class will set the position of the ground in the game scene
*\author Sami & Mohammad Ali

*/

#ifndef GROUND32_H
#define GROUND32_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class ground32 : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit ground32(/*QObject *parent = 0*/int x);
    
signals:
    
public slots:
    
};

#endif // GROUND_H
