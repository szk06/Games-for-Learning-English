/**
*\file gamescene2.cpp
*\brief Scene of the game

*
This class contains the holes and the grounds that the criminal will pass over.It also
contains the the crimnal and the dashes that the letters will be displayed on them


*\author Sami & Mohammad Ali
*/

#ifndef GAMESCENE32_H
#define GAMESCENE32_H

#include<QTextDocument>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include<QKeyEvent>
#include<QTimer>
#include"stdlib.h"
#include"criminal32.h"
#include<QGraphicsItem>
#include"ground32.h"
#include"hole32.h"
#include"dash32.h"
#include<QList>
#include<QFont>
#include<QGraphicsTextItem>
#include<QGraphicsPixmapItem>
class gamescene32 : public QGraphicsScene
{
    Q_OBJECT
public:
    gamescene32(int x,int y,int z);
    int mylevel;//!<Level
    int current_location;//!<The current location of the criminal
    int allowed_attempts;//!<allowed incorrect answers before falling in hole
    QGraphicsRectItem *rect;
    int numLetters;//!<number of letters of the word, depending on the level
    criminal32 *game_criminal;//!<The criminal
    ground32 *normal_ground;//!<A normal ground
    hole32 *trap_hole;//!<The hole the criminal will fall in
    QList<QGraphicsPixmapItem *> mylist;//!<array including the holes and the grounds
    QList <int> holes_index;//!<array containing the holes index
    QList <int> dash_place;
    dash32 *letter_dash;//!<dash on the scene
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
