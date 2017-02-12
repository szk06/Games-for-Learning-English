/**
*\file person.cpp
*\brief the criminal


*/

#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QList>
#include<QGraphicsItem>
#include "road.h"
#include "barrier.h"
#include "dest.h"
#include<typeinfo>
class person : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit person(QObject *parent = 0);
    void moveup();
    void movedown();
    void moveleft();
    void moveright();

signals:
    void on_barrier();
    void win_game(bool x);
public slots:

};

#endif // PERSON_H
