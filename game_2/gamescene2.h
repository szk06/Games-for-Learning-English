/**
*\file gamescene2.h
*\brief Scene of the game

*
This class contains the holes and the grounds that the criminal will pass over.It also
contains the the crimnal and the dashes that the letters will be displayed on them


*\author Sami & Mohammad Ali
*/
#ifndef GAMESCENE2_H
#define GAMESCENE2_H

#include<QTextDocument>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include<QGraphicsItem>
#include<QGraphicsTextItem>
#include<QGraphicsPixmapItem>

#include<QList>
#include<QFont>

#include<QKeyEvent>
#include<QTimer>

#include<stdlib.h>

#include "ground.h"
#include "hole.h"
#include "dash.h"
#include "criminal.h"

class gamescene2 : public QGraphicsScene
{
    Q_OBJECT
public:
    gamescene2(int x,int y,int z);
    int mylevel;//!<Level
    int current_location;//!<The current location of the criminal
    int allowed_attempts;//!<allowed incorrect answers before falling in hole
    QGraphicsRectItem *rect;
    int numLetters;//!<number of letters of the word, depending on the level
    criminal *game_criminal;//!<The criminal
    ground *normal_ground;//!<A normal ground
    hole *trap_hole;//!<The hole the criminal will fall in
    QList<QGraphicsPixmapItem *> mylist;//!<array including the holes and the grounds
    QList <int> holes_index;//!<array containing the holes index
    QList <int> dash_place;
    dash *letter_dash;//!<dash on the scene
    int global_count;//!<used to index the array of QObjects
    QGraphicsTextItem *io;//!<letters to be displayed if correct or no
    QGraphicsTextItem *end_tag;//!<game over/game won
    QGraphicsTextItem *letter_eval;//!<evaluation of letter correct/incorrect
    void addground(int x);
    void addhole(int x);
    void move_criminal(bool w,QString a);
    void add_dash(int x);
signals:
    void Won(bool x);
};


#endif // GAMESCENE2_H
