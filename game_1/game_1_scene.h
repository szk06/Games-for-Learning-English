/**
\file game_1_scene.cpp
\brief This class represent the scene of game 1
*
The class represents the scene and the different elements in it

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef GAME_1_SCENE_H
#define GAME_1_SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "bow.h"
#include "balloon.h"

class game_1_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit game_1_scene(int level, QGraphicsScene *parent= 0);
    int game_level;//!<game level flag
    int game_score;//!<game score counter

    bow* the_bow;//!<bow on screen

    QTimer *balloon_timer;//!<balloon population timer
    void game_start();
signals:
    
public slots:
    void pop_balloon();
    void end_game_scene(int);
};

#endif // GAME_1_SCENE_H
