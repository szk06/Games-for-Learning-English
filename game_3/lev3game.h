/**
*\file lev3game.cpp
*\brief QWidget that contains the scene of the game
*
The Widget holds the score and displays the timer, in addition to that, the scene of the
game is added to it

*/

#ifndef LEV3GAME_H
#define LEV3GAME_H

#include <QWidget>
#include<QtGui>
#include<stdlib.h>
#include<QTimer>
#include "gamescene3.h"
class lev3game : public QWidget
{
    Q_OBJECT
public:
    explicit lev3game(int x);
    int time_ini;//!<Timer of the game
    QPushButton *save_game;
    int game_level;//!<Level of the game
    QTimer *game_time;//!<Timer
    QLabel *time_label;//!<Label of the time
    QGridLayout *mygrid;//!<Grid
    QVBoxLayout *VLayout;//!<vertical Layout
    gamescene3 *scene3;//!<Scene of the Game
    QGraphicsView *view3;//!<View of the Scene
    QLabel *game_num;//!<Label
    QLabel *resultofgame;//!<Label
    bool is_end;
    void setGrid();
    void setVertical();

    

signals:
    void lost(bool x);
    void repeat_3(int);
    void exit_3();
    void close_game2();
    void score_toMain(int,int);
    void save_toMain();
public slots:
    //void gameEnd(bool x);
    void time_decrement();
    void toClose();
    void toOpen();
    void gameEnd(bool x);
    void save_clicked();
};

#endif // LEV3GAME_H
