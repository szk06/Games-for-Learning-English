/**
*\file dest.cpp
*\brief Victory that player needs to reach
*The player needs to reach victory when colliding with this object

*/

#ifndef DEST_H
#define DEST_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QGraphicsItem>
class dest : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit dest(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DEST_H
