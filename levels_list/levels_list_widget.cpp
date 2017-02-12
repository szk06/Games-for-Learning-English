/**
\file levels_list_widget.cpp
\brief This class represents the list of levels
*
The class contains different buttons to select the difficulty level of the game

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include "levels_list_widget.h"

/**
\brief levels_list_widget constructor
\param parent of tyoe QWidget

*
in this function, levels_list_widget is created

*/
levels_list_widget::levels_list_widget(QWidget *parent) :
    QWidget(parent)
{
    hello = new QLabel("List of levels");
    level_1_btn = new QPushButton("Level I");
    level_2_btn = new QPushButton("Level II");
    level_3_btn = new QPushButton("Level III");

    set_vertical_layout();
    setLayout(VLayout);
}
/**
\brief sets vertical layout
*
in this function, the buttons and the elements
of the class are added to the vertical layout

*/
void levels_list_widget::set_vertical_layout(){
    VLayout = new QVBoxLayout();
    VLayout->addWidget(hello);
    VLayout->addWidget(level_1_btn);
    VLayout->addWidget(level_2_btn);
    VLayout->addWidget(level_3_btn);
}
