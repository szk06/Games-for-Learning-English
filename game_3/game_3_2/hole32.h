/**
*\file hole.cpp
*\brief This class represents the hole that the criminal will fall in
*
The class will set the position of the hole in the game scene
*\author Sami & Mohammad Ali

*/

#ifndef HOLE32_H
#define HOLE32_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class hole32 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit hole32(/*QObject *parent = 0*/int x);
    
signals:
    
public slots:
    
};

#endif // HOLE_H
