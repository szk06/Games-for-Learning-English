/**
\file play_menu_widget.cpp
\brief This class represent the panel where the user chooses either to resume
his old game, or to start a new game
*
The class contains 2 buttons to Start game and resume game and it inherits from QWidget
and uses Vertical Layout

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include "play_menu_widget.h"
/**
\breif Constructor of the gamestart class
\param parent of type QWidget

*
In this function, all the buttons of the gamestart class are created, siganls are
defined and connected to the buttons, and the setLayout function is called

*/
play_menu_widget::play_menu_widget(QString name, QWidget *parent) :
    QWidget(parent)
{
    name_of_game = name;
    hello = new QLabel("Welcome to "+ name_of_game);

    new_btn = new QPushButton("New Game");
    resume_btn = new QPushButton("Resume Game");
    instructions_btn = new QPushButton("Game Description");

    set_vertical_layout();
    setLayout(VLayout);
}

/**
\brief sets vertical layout
*
in this function, the buttons and the elements
of the class are added to the vertical layout

*/
void play_menu_widget::set_vertical_layout(){
    VLayout = new QVBoxLayout();
    VLayout->addWidget(hello);
    VLayout->addWidget(new_btn);
    VLayout->addWidget(resume_btn);
    VLayout->addWidget(instructions_btn);
}
