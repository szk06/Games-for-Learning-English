/**
\file game_1_widget.cpp
\brief This class represent game 1
*
The class represents the widget holding game 1

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef GAME_1_WIDGET_H
#define GAME_1_WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include<QFile>
#include<QDebug>
#include<QTime>


#include "game_1_scene.h"

class game_1_widget : public QWidget
{
    Q_OBJECT
public:
    explicit game_1_widget(int level, QWidget *parent = 0);

    int game_level;//!<game level flag

    int game_score;//!<game score counter
    QPushButton *save_game;//!<button for saving
    QLabel *game_label;//!<game label on widget
    QLabel *level_label;//!<level label on widget

    QLabel *score_label;//!<score label on widget
    QLabel *color_label;//!<color label on widget

    QString color_to_shoot;//!<correct color to shoot

    QVBoxLayout *VLayout;//!<vertical layout
    QGridLayout *GLayout;//!<grid layout

    QTimer *color_change_timer;//!<color change timer
    QTime *time_elapsed;
    game_1_scene *game_scene;//!<game scene

    QGraphicsView *game_1_view;//!<game view

    QMessageBox *message_box;//!<message box appearing at the end of game

    void set_grid_layout();
    void set_vertical_layout();
    void set_score_time(int myscore,int mytime);
    QTimer *game_timer;
signals:
    void change_target_color_bow(QString new_color);//!<signal to change target color
    void game_end_signal(int);//!<signal at end of game
    void repeat_1(int);//!<signal to repeat game 1
    void exit_1();//!<signal to exit game 1 and return to main
    void game_tomain_score(int,int);//!<Signal that will send the game number and the timer and the score to the main_Menu
    void save_data(int,int,int);//!<Signal to give the time and the score of the game for the resume


public slots:
    void game_end();
    void target_color_change();

    void update_score(bool);
    void save_toMain();
    
};

#endif // GAME_1_WIDGET_H
