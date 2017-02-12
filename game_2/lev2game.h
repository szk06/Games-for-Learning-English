/**
\file lev2game.cpp

\brief the game widget of the game2 that contains the gamescene

*
This class contains the level2game widget that contains the scene it has also the hints
menu which allow the user to know the next letter

\author Sami & Mohammad Ali
*/

#ifndef LEV2GAME_H
#define LEV2GAME_H

#include <QWidget>
#include <QtGui>
#include <QMap>

#include<stdlib.h>

#include "gamescene2.h"

class lev2game : public QWidget
{
    Q_OBJECT
public:
    explicit lev2game(/*QWidget *parent = 0,*/int x,bool y);
    bool from_game;
    gamescene2 *scene2;//!<scene that contains the game
    QGraphicsView *view2;//!<The view that will display the scene
    int counter_now;//!<Position of the letter the player reached, initially zero
    int level_now;//!<the level the player is currently playing
    int word_length;//!<Length of the word the player needs to guess
    QLabel *level_label;//!<level of the game displayed
    int hints_available;//!<number of hints available, decremnts as the player use one
    QLabel *hints_available_label;//!<label of hints
    int attempts_available;//!<number of attempts player have after, decremnts on each wrong
    QLabel *attempts_available_label;//!<label of attempts
    QVBoxLayout *VLayout;//!<Vertical Layout
    QGridLayout *mygrid;//!<Grid Layout
    QPushButton *hint_use;//!<The button that will display the hint
    QPushButton *save_game;//!<button that will save the game
    QComboBox *answer; //!<Text field where the player enters the letter
    QPushButton *submit_answer;//!<Button to Submit the answer
    QString correct_word;//!<Correct word that the player must guess
    QStringList correct_letters;//!<Split the correct word into letters
    QStringList all_words;//!<all the read words from the file
    void setGrid();
    void setVertical();

signals:

    void repeat_2(int);
    void exit_2();
    void score_toMain(int,int);
    void save_toMain(lev2game *);
    void endgame2(bool);


public slots:
    void submit_letter();
    void use_hint();
    void gameEnd(bool x);
    void save();
};

#endif // LEV2GAME_H
