/**
\file games_list_widget.cpp
\brief This class represent the panel where the user chooses which game he wants
to play
*
The class contains 4 buttons that correspond to each game, and this class inherits
from the QWidger. It aligns the buttons in a vertical layout

\author Sami Kanafani & Mohamad Ali Mahaidli

*/

#include "games_list_widget.h"

/**
\breif Constructor of the mygame class
\param parent of type QWidget

*
In this function, all the buttons of the mygame class are created, siganls are
defined and connected to the buttons, and the setLayout function is called

*/

games_list_widget::games_list_widget( QWidget *parent) :
    QWidget(parent)
{
    hello = new QLabel("List of Games");
    game_1_btn = new QPushButton("Balloon Shooting");
    game_2_btn = new QPushButton("Escape Hangman");
    game_3_btn = new QPushButton("Escape Maze");
    game_4_btn = new QPushButton("Scrabble");


    set_vertical_layout();
    setLayout(VLayout);
}

/**
\brief sets vertical layout
*
in this function, the buttons and the elements
of the class are added to the vertical layout

*/
void games_list_widget::set_vertical_layout(){
    VLayout = new QVBoxLayout();
    VLayout->addWidget(hello);
    VLayout->addWidget(game_1_btn);
    VLayout->addWidget(game_2_btn);
    VLayout->addWidget(game_3_btn);
    VLayout->addWidget(game_4_btn);
}

