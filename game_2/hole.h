/**
*\file hole.h
*\brief This class represents the hole that the criminal will fall in
*
The class will set the position of the hole in the game scene
*\author Sami & Mohammad Ali

*/

#ifndef HOLE_H
#define HOLE_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class hole : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit hole(/*QObject *parent = 0*/int x);

signals:

public slots:

};

#endif // HOLE_H
