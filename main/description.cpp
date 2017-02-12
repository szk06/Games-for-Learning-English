#include "description.h"

description::description(QString s)
{
    game_name = new QLabel(s);
    game_desc = new QTextEdit();
    if (s == "Balloon Shooting"){
        game_desc->setText("This game is about shooting balloons using a bow and\n an arrow. This game is composed of 3 levels");
    }else if(s=="Escape Hangman"){
        game_desc->setText("A hangman game where the player needs to guess a secrete word, the player can use hints\n. The game is composed of 3 levels");
    }else if (s == "Escape Maze"){
        game_desc->setText("A maze game, each obstacle in this maze is composed of a game of hangman game, the user should win the escape\n hangman to win the game");
    }else if(s=="Scrabble"){
        game_desc->setText("An ordinary scrabble game, the game can be played in 2,3,4 players");
    }
    Vlayout = new QVBoxLayout;
    setVertical();
    setLayout(Vlayout);

}
void description::setVertical(){
    Vlayout->addWidget(game_name);
    Vlayout->addWidget(game_desc);
}
