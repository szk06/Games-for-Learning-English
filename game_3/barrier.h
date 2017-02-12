/**
*\file barrier.cpp
*\brief This class reprsents the barrier
*
This is the barrier that will take the player into game2, he is obliged to win game2
to pass
*/

#ifndef BARRIER_H
#define BARRIER_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include "./game_3_2/lev32game.h"
#include "../game_2/lev2game.h"
class barrier : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit barrier(int x);
    int level_barrier;//!<Level of the barrier
    //lev32game *game2;//!<The game stored in the barrier
    lev2game *game2;
    bool passed;//!<Was the barrier passed
    bool is_lost;//!<Did the player lose in this barrier
    void start_game();
    void close_games();
signals:
    void barrier_pass(bool x);
public slots:
    void done_barrier(bool x);
};

#endif // BARRIER_H
