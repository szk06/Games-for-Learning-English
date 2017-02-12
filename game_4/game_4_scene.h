#ifndef GAME_4_SCENE_H
#define GAME_4_SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class game_4_scene : public QGraphicsScene
{
public:
    game_4_scene(QGraphicsScene *parent= 0);
    QChar char_to_move;

    QList<QList<int>*>* current_player_positions;
    QList<QPixmap>* previous_pixmap;

    QList<QList<QChar>*>* back_end_board_char;
    QList<QList<int>*>* back_end_board_score;

    QList<QList<QGraphicsPixmapItem*>*>* front_end_board;
    void initialize_board();
    void reset_turn();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};
#endif // GAME_4_SCENE_H
