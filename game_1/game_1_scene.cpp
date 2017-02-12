/**
\file game_1_scene.cpp
\brief This class represent the scene of game 1
*
The class represents the scene and the different elements in it

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include "game_1_scene.h"

/**
\brief Constructor of the game_1_scene class
\param parent of type QGraphicsScene
\param level of type int

*
In this function, game_1_scene is created
*/
game_1_scene::game_1_scene(int level, QGraphicsScene *parent) :
    QGraphicsScene(parent)
{
    this->game_level = level;
    game_score = 0;

    the_bow = new bow();
    addItem(the_bow);
    the_bow->setFlag(bow::ItemIsFocusable);
    the_bow->setFocus();
    //750 850
    the_bow->setPos(375, 550);

    balloon_timer = new QTimer(this);
    connect(balloon_timer, SIGNAL(timeout()), this, SLOT(pop_balloon()));

}
/**
\brief end of game handler
\param level of type int

*
In this function, the end of game is handled
*/
void game_1_scene::end_game_scene(int status)
{
    if (status == 0)
    {
        balloon_timer->stop();
        QList<QGraphicsItem*> list = this->items();
        for (int i = 0; i < list.size(); i++)
        {
            QGraphicsItem* temp = list.at(i);
            if (typeid(*temp) == typeid(balloon))
            {
                balloon *temp_balloon  = dynamic_cast<balloon *>(temp);
                temp_balloon->balloon_timer->stop();
            }
            else if (typeid(*temp) == typeid(arrow))
            {
                arrow *temp_arrow  = dynamic_cast<arrow *>(temp);
                temp_arrow->timer->stop();
            }
        }
    }
}
/**
\brief start of game handler

*
In this function, the balloon timer is started
*/
void game_1_scene::game_start()
{
    balloon_timer->start(2000);
}
/**
\brief start of balloon handler

*
In this function, a balloon is created
*/

void game_1_scene::pop_balloon()
{
    QString colors[5] = {"Red", "Blue", "Yellow", "Green", "Orange"};
    int color_index = rand()%5;
    balloon *the_balloon = new balloon(game_level, colors[color_index]);
    addItem(the_balloon);
    the_balloon->setPos(rand()%600, 450);
    the_balloon->fly();
}
