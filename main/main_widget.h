/**
\file main_widget.cpp
\brief contains the Buttons and the labels of the main page that loads
at the beginning of the project

*

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QtGui>
#include "../plotter.h"
#include"../overall_plotter.h"
#include <QDebug>

#include "../account/account_widget.h"
#include "../account/sign_in.h"
#include "../account/sign_up.h"
#include "../history/history_widget.h"
#include "../games_list/games_list_widget.h"
#include "../play_menu_widget/play_menu_widget.h"
#include "../levels_list/levels_list_widget.h"
#include "../game_1/game_1_widget.h"
#include"description.h"
#include "../game_2/criminal.h"
#include "../game_2/dash.h"
#include "../game_2/gamescene2.h"
#include "../game_2/ground.h"
#include "../game_2/hole.h"
#include "../game_2/lev2game.h"

#include<QFile>
#include "../game_3/lev3game.h"
#include"../game_4/game_4_widget.h"

#include<QTimer>


/////
/*
#include "my_game.h"
#include "game_instance.h"
#include "game_widget.h"
*/
class main_widget : public QWidget
{
    Q_OBJECT
public:
    explicit main_widget(QWidget *parent = 0);
/*
    int previous_window_index;//!<holds the index of previous page
    int current_window_index;//!<holds the index of previous page
*/
    QString current_game;//!<holds the name of the current game
    int current_game_level;

    QPushButton *Account;//!<button on the window
    QPushButton *History;//!<button on the window
    QPushButton *Games;//!<button on the window
    QPushButton *Bacck;//!<button on the window

    QVBoxLayout *VLayout;//!<The vertical layout where elements are stored
    QHBoxLayout *HLayout;//!<The horizontal layout where elements are stored
    QStackedLayout *SLayout;//!<The stacked layout where different specific windows are stored

    QLabel *hello;//!<label on the window

    account_widget *account;//!<The account window that appears after button clicked
    games_list_widget *games_list;//!<The game window that appears after button clicked
    history_widget *history;//!<The history window that appears after button clicked

    play_menu_widget *play_menu;//!<the play menu of the selected game
    levels_list_widget* levels_list;//!<the levels list of the selected game

    game_1_widget *game_1;//!<widget of game 1
    game_1_widget *game_1_res;//!<widget of resumed game1
    lev2game* game_2;//!<widget of game 2

    lev3game* game_3;//!<widget of game 3

    game_4_widget* game_4; //!<widget of game 4

    description *desc;
    sign_in *add_sign;//!<Widget of the sign in form
    sign_up *new_user;//!<Widget of the sign UP form
    bool signed_in;//!<to know if the player is signed in
    plotter *myplot;
    overall_plotter *plot_overall;
    QString user_name;//!<Username of the signed in User
    void set_vertical_layout();
    void set_horizontal_layout();
    void set_stacked_layout();
signals:

public slots:

    void enter_resume_levels_menu();
    void account_click();
    void signin_click();
    void signup_click();
    void signout_click();
    void games_click();
    void history_click();
    void back_click();

    void slayout_change();

    void enter_play_menu();
    void enter_levels_menu();
    //Player entering the game
    void launch_new_game();
    void repeat_game_1(int level);
    void exit_game_1();
    void repeat_game_2(int level);
    void exit_game_2();
    void repeat_game_3(int level);
    void exit_game_3();
    void repeat_game_4(int nbr_players);
    void exit_game_4();

    //Player Accounts
    void player_sign_in(bool x,QString s);
    void game_history(int score,int game);

    void game1_history();
    void game2_history();
    void game3_history();
    void game4_history();
    void overall_history();

    //Resume
    void game1_save(int score,int time,int level);

    void game2_save(lev2game *game);
    void game3_save(lev3game *game);
    void game_desc();

};

#endif // MAIN_WIDGET_H
