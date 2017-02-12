#include "player.h"

player::player(int id, QObject *parent) :
    QObject(parent)
{
    this->id = id;
    this->score = 0;
    this->player_rack = new QList<QChar>();
}
