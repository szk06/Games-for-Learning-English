#ifndef GAME_4_WIDGET_H
#define GAME_4_WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QList>
#include <QGraphicsRectItem>

#include <vector>

#include "game_4_scene.h"
#include"player.h"

class game_4_widget : public QWidget
{
    Q_OBJECT
public:
    explicit game_4_widget(int nbr_plyrs, QWidget *parent = 0);
    int nbr_plyrs;
    //QLabel *score;//!<label on the window
    QList<QChar> *bag;

    QPushButton *pass_btn;//!<button on the window
    QPushButton *shuffle_btn;//!<button on the window
    QPushButton *exchange_btn;//!<button on the window
    QPushButton *submit_btn;
    QPushButton *reset_btn;

    QHBoxLayout *tiles_layout;
    QVBoxLayout *PLayout;

    QVBoxLayout *sub1VLayout;//!<vertical layout
    QVBoxLayout *sub2VLayout;//!<vertical layout

    QHBoxLayout *HLayout;

    game_4_scene *game_scene;//!<game scene

    QGraphicsView *game_4_view;//!<game view

    QList<player*> *list_of_players;

    player* current_player;
    int current_player_id;
    int current_pushed_button;
    int global_first_move;

    QList<QString>* dict;
    QList<QPushButton*>* tiles_btn;
    QList<QPushButton*>* currently_pushed_btns;
    int consecutive_pass_counter;

    void set_tiles_layout();
    void set_players_layout(int);
    void set_sub_1_layout();
    void set_sub_2_layout();
    void set_horizontal_layout();

    void game_over(int);
    int get_letter_score(QChar);
    void fill_player_rack(player *p, int nbr_lttrs);
    void initialize_players(int);
    void initialize_bag();
    void set_current_player(int i);
    void load_deck(player* p);
    void next_player_turn();
    int same_x_y(int);
    void bad_submission();
    int check_not_empty_vertical();
    int check_not_empty_horizontal();
    void build_dict();
    int check_player_won();
    int find_ending_index(int flag_direction, int);
    int find_starting_index(int flag_direction, int);
    int check_star();
    int no_empty_squares(int flag);
    int check_word_correctness(QString str);
    void build_word (int flag_direction, int starting, int ending, QString *str, int tile_index);
    int  compute_score (int flag_direction, int starting, int ending, int tile_index);
    int check_all_tiles_words(int word_orientation, int *temp_score, QString* temp_str, int nbr_tiles_put);
    void submit_success(int score, int);
    int check_single_tile_neighbors();
    void apply_penalty();
    void set_buttons(bool);

signals:
    void repeat_4(int);//!<signal to repeat game 4
    void exit_4();//!<signal to exit game 4 and return to main
    void score_toMain(int,int);//!<signal to send the score to main menu
public slots:
    void select_letter();
    void pass_btn_clicked();
    void shuffle_btn_clicked();
    void exchange_btn_clicked();
    void submit_btn_clicked();
    void reset_btn_clicked();
};


#endif // GAME_4_WIDGET_H
