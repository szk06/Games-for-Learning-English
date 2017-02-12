/**
\file lev32game.cpp

\brief the game widget of the game2 that contains the gamescene

*
This class contains the level2game widget that contains the scene it has also the hints
menu which allow the user to know the next letter

\author Sami & Mohammad Ali
*/

#ifndef LEV32GAME_H
#define LEV32GAME_H

#include <QWidget>
#include<QTimer>
#include"stdlib.h"
#include"gamescene32.h"
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QGraphicsView>
#include<fstream>
#include<QFile>
#include<QTextStream>
#include<QComboBox>

#include<QStringList>
class lev32game : public QWidget
{
    Q_OBJECT
public:
    explicit lev32game(/*QWidget *parent = 0,*/int x);
    gamescene32 *scene2;//!<scene that contains the game
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
    QComboBox *answer; //!<Text field where the player enters the letter
    QPushButton *submit_answer;//!<Button to Submit the answer
    QString correct_word;//!<Correct word that the player must guess
    QStringList correct_letters;//!<Split the correct word into letters
    QStringList all_words;//!<all the read words from the file
    void setGrid();
    void setVertical();

signals:
    void endgame2(bool c);
public slots:
    void submit_letter();
    void use_hint();
    void gameEnd(bool x);


};

#endif // LEV2GAME_H
