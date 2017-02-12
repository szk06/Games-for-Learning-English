#include "game_4_scene.h"
#include "QDebug"
#include "QDir"
game_4_scene::game_4_scene(QGraphicsScene *parent):
    QGraphicsScene(parent)
{
    this->current_player_positions = new QList<QList<int>*>();
    this->previous_pixmap = new QList<QPixmap>();
    initialize_board();
}

void game_4_scene :: reset_turn()
{
    this->current_player_positions->clear();
    this->previous_pixmap->clear();
}

// assume the player will put letters in order
void game_4_scene :: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        // make sure a letter was selected
        if (this->char_to_move.isLetter() || this->char_to_move == '_')
        {
            // get position
            QPointF point =  event->scenePos();
            int x = point.x();
            int y = point.y();
            // check what rectangle // 35 is the dimension of the letter square
            x = x/35;
            y = y/35;

            QList<int>* temp = new QList<int>();
            temp->append(x);
            temp->append(y);
            this->current_player_positions->append(temp);

            // check if position already taken
            if (this->back_end_board_char->at(y)->at(x) != '-')
            {
                return;
            }
            // modify front end
            QString path_letter_sqr;
            if (this->char_to_move.isLetter())
                path_letter_sqr = "img4/tiles/Wood/letter_" + QString(this->char_to_move.toUpper())+".png";
            else
                path_letter_sqr = "img4/tiles/Wood/letter_" + QString(this->char_to_move)+".png";
            QImage letter_image(path_letter_sqr);
            previous_pixmap->append(this->front_end_board->at(y)->at(x)->pixmap());
            this->front_end_board->at(y)->at(x)->setPixmap(QPixmap::fromImage(letter_image).scaled(35,35));

            // modify back end
            this->back_end_board_char->at(y)->replace(x,this->char_to_move);

            // to prevent another press from putting a letter on the board
            this->char_to_move = '-';
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void game_4_scene:: initialize_board(){
    this->back_end_board_char = new QList<QList<QChar>*>();
    this->back_end_board_score = new QList<QList<int>*>();
    //this->front_end_board = new QList<QList<QGraphicsRectItem*>*>();
    this->front_end_board = new QList<QList<QGraphicsPixmapItem*>*>();
    int width = 35;
    int height = 35;

    QString path_empty_sqr = "img4/empty_tile.jpg";
    QImage image_empty(path_empty_sqr);

    QString path_star_sqr = "img4/star.png";
    QImage image_star(path_star_sqr);

    QString path_dw_sqr = "img4/double_word.png";
    QImage image_dw(path_dw_sqr);

    QString path_tw_sqr = "img4/triple_word.png";
    QImage image_tw(path_tw_sqr);

    QString path_dl_sqr = "img4/double_letter.png";
    QImage image_dl(path_dl_sqr);

    QString path_tl_sqr = "img4/triple_letter.png";
    QImage image_tl(path_tl_sqr);
    for (int i = 0; i < 15; i++)
    {
        //QList<QGraphicsRectItem*> *temp = new QList<QGraphicsRectItem*>();
        QList<QGraphicsPixmapItem*> *temp = new QList<QGraphicsPixmapItem*>();

        QList<int>* temp_score = new QList<int>();
        QList<QChar>* temp_char = new QList<QChar>();
        for (int j = 0; j < 15; j++)
        {
            //QGraphicsRectItem* temp_rect = this->addRect(j*width, i*height, width, height);
            //temp->append(temp_rect);
            QGraphicsPixmapItem* temp_item;
            if ( (i == 0 && (j == 0 || j == 7 || j == 14)) ||
                 (j == 0 && (i == 7 || i == 14)) ||
                 (j == 14 && ( i == 7 || i == 14))||
                 (i == 14 && (j == 7))){
                temp_item = new QGraphicsPixmapItem(QPixmap::fromImage(image_tw).scaled(35,35));
                temp_score->append(5);// = 5;
            }
            else
                if (i == 7 && j == 7){
                    temp_item = new QGraphicsPixmapItem(QPixmap::fromImage(image_star).scaled(35,35));
                    temp_score->append(4);// = 4;
                }
                else
                    if ( (i == j && (i > 0) && (i < 5)) || ((14-i) == j && (j > 0) && (j < 5)) || ((14-j) == i && (i > 0) && (i < 5)) || (i == j && (i > 9) && (i < 14)) ){
                        temp_item = new QGraphicsPixmapItem(QPixmap::fromImage(image_dw).scaled(35,35));
                        temp_score->append(4);// = 4;
                    }
                    else
                        if ( ((i == 1 || i == 13 ) && (j == 9 || j == 5)) || ( (i == 5 || i == 9)  && (j == 1 || j == 9 || j == 5 || j == 13))){
                            temp_item = new QGraphicsPixmapItem(QPixmap::fromImage(image_tl).scaled(35,35));
                            temp_score->append(3);// = 3;
                        }
                        else
                            if ( (i == 0 && (j == 3 || j == 11)) || ((14-i) == 0 && ((14-j) == 3 || (14-j) == 11))
                                 || ( (i == 6 || i == 8 )&& ( j == 2 || j == 6 || j == 8 || j == 12) ) || (i == 7 && (j == 3 || j == 11) ) ||
                                 ( (i == 2 || (14-i) == 2) && (j == 6 || j == 8)) || ((i == 3||(14-i)==3)&&(j == 0 || j == 7 || j == 14) )
                               ){
                                temp_item = new QGraphicsPixmapItem(QPixmap::fromImage(image_dl).scaled(35,35));
                                temp_score->append(2);// = 2;
                            }
                            else{
                                temp_item = new QGraphicsPixmapItem(QPixmap::fromImage(image_empty).scaled(35,35));
                                temp_score->append(1);// = 1;
                            }

            temp_item->setPos(j*width, i*height);
            this->addItem(temp_item);
            temp->append(temp_item);
            temp_char->append('-');
        }
        this->back_end_board_score->append(temp_score);
        this->back_end_board_char->append(temp_char);
        this->front_end_board->append(temp);
    }
}
