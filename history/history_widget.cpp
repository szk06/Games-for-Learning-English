/**
\file history_widget.cpp
\brief This class represent the panel where the user can view his history_widget in each game
*

The class contains 4 buttons(corresponding to each game)and it inherits from QWidget
and uses Vertical Layout

\author Sami Kanafani & Mohamad Ali Mahaidli

*/

#include "history_widget.h"

/**
\breif Constructor of the my_history_widget class
\param parent of type QWidget

*
In this function, all the buttons of the ishistory_widget class are created,
and the setLayout function is called

*/
history_widget::history_widget(QWidget *parent) :
    QWidget(parent)
{
    hello = new QLabel("History");
    game1 = new QPushButton("Balloon Shooting");
    game2 = new QPushButton("Escape Hangman");
    game3 = new QPushButton("Escape Maze");
    game4 = new QPushButton("Scrabble");
    overall = new QPushButton("Overall");
    VLayout = new QVBoxLayout();
    set_vertical_layout();
    setLayout(VLayout);
}

/**
\brief sets vertical layout
*
in this function, the buttons and the elements
of the class are added to the vertical layout

*/
void history_widget::set_vertical_layout(){
    VLayout->addWidget(hello);
    VLayout->addWidget(game1);
    VLayout->addWidget(game2);
    VLayout->addWidget(game3);
    VLayout->addWidget(game4);
    VLayout->addWidget(overall);
}
