/**
*\file gamescene.cpp
*\brief the scene of the game

*
This class contains the whole elements of the game, the criminal, the barrier, the road, and
the destination

*/

#ifndef GAMESCENE3_H
#define GAMESCENE3_H

#include <QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QList>
#include"person.h"
#include"barrier.h"
#include"road.h"
#include "dest.h"

class gamescene3 : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit gamescene3();
    person *myperson;//!<Criminal
    road *myroad;//!<The road he walks into
    barrier *mybarrier;//!<The barrier he needs to pass
    dest *victory;//!<Destination he needs to reach
    QList<barrier *>list_b;//!<List of barriers
    void addLow();
    void addFirst();
    void addSecond();
    void addThird();
    void close_game2();
    void keyPressEvent(QKeyEvent *event);
signals:

    void open_game();
    void game_end(bool x);
public slots:
    void passed();


};

#endif // GAMESCENE3_H
