/**
\file game_1_widget.cpp
\brief This class represent game 1
*
The class represents the widget holding game 1

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include "game_1_widget.h"

/**
\brief Constructor of the game_1_widget class
\param parent of type QGWidget
\param level of type int

*
In this function, game_1_widget is created
*/
game_1_widget::game_1_widget(int level, QWidget *parent) :
    QWidget(parent)
{
    save_game = new QPushButton("Save Game");
    game_label = new QLabel("Game: Balloon Shooting");
    //qDebug() << level;
    game_level = level;
    level_label = new QLabel("Level: " + QString::number(level));

    this->color_to_shoot = "Red";
    color_label = new QLabel("Color: Red");

    game_score = 0;
    score_label = new QLabel("Score: " + QString::number(game_score));

    //create game scene
    game_scene= new game_1_scene(game_level);

    game_1_view = new QGraphicsView(game_scene);
    game_1_view->setFixedSize(800, 900);  //800 900
    // 850 900
    game_1_view->setBackgroundBrush(QImage("img/back.jpg"));

    game_scene->setSceneRect(0, 0, 750, 850); // 750 850
    // 850 850
    game_1_view->show();

    GLayout = new QGridLayout();
    VLayout = new QVBoxLayout();

    set_grid_layout();
    set_vertical_layout();

    setLayout(VLayout);

    color_change_timer = new QTimer(this);

    connect(game_scene->the_bow, SIGNAL(update_widget_score(bool)), this, SLOT(update_score(bool)));
    QObject::connect(color_change_timer, SIGNAL(timeout()), this, SLOT(target_color_change()));
    QObject::connect(this, SIGNAL(change_target_color_bow(QString)), game_scene->the_bow, SLOT(update_bow_color(QString)));

    game_timer = new QTimer(this);
    connect(game_timer, SIGNAL(timeout()), this, SLOT(game_end()));
    connect(this, SIGNAL(game_end_signal(int)), game_scene, SLOT(end_game_scene(int)));

    game_timer->start(60*1000);
    time_elapsed = new QTime();
    time_elapsed->start();
    // start the balloon timer
    game_scene->game_start();

    color_change_timer->start(5000);

    connect(save_game,SIGNAL(clicked()),this,SLOT(save_toMain()));
}
/**
\brief end of game handler

*
In this function, the end of game is handled
*/
void game_1_widget::game_end()
{
    //stop all timer
    game_timer->stop();
    color_change_timer->stop();

    //send signal to screen to stop
    emit game_end_signal(0);
    emit game_tomain_score(game_score,1);
    //messagebox
    message_box = new QMessageBox();

    QPushButton* exit_btn = message_box->addButton("Exit",QMessageBox::YesRole);
    QPushButton* repeat_btn = message_box->addButton("Repeat",QMessageBox::YesRole);
    QPushButton* nxt_btn;
    if(game_score > 30)
        nxt_btn = message_box->addButton("Next Level",QMessageBox::YesRole);

    message_box->setText("Game Over!\nYour Final Score: "+QString::number(game_score));
    message_box->exec();

    if(message_box->clickedButton() == exit_btn)
    {
        emit exit_1();
    }
    if(message_box->clickedButton() == repeat_btn)
    {
        emit repeat_1(this->game_level);
    }
    if (game_score > 30)
    {
        if(message_box->clickedButton() == nxt_btn)
        {
            if(game_level < 3)
                emit repeat_1(this->game_level+1);
            else
                emit repeat_1(this->game_level);
        }
    }
    //delete message_box;

}
/**
\brief change of color handler

*
In this function, the target color is changed randomly
*/
void game_1_widget:: target_color_change()
{
    QString colors[5] = {"Red", "Blue", "Yellow", "Green", "Orange"};
    int color_index = rand()%5;
    color_to_shoot = colors[color_index];
    color_label->setText("Color: " + color_to_shoot);

    // emit signal to bow
    emit change_target_color_bow(color_to_shoot);
}
/**
\brief score update handler
\param correct of type bool

*
In this function, the score of game is handled
*/
void game_1_widget:: update_score(bool correct)
{
    if (correct)
        this->game_score += 10;
    else
        this->game_score -= 10;

    score_label->setText("Score: " + QString::number(game_score));
}
/**
\brief grid layout handler

*
In this function, the grid layout is set
*/
void game_1_widget:: set_grid_layout(){
    GLayout->addWidget(game_label,0,0);
    GLayout->addWidget(level_label,1,0);
    GLayout->addWidget(save_game,1,1);
    GLayout->addWidget(score_label,0,1);
    GLayout->addWidget(color_label,0,2);

}
/**
\brief vertical layout handler

*
In this function, the vertical layout is set
*/
void game_1_widget::set_vertical_layout(){
    VLayout->addItem(GLayout);
    VLayout->addWidget(game_1_view);
}
/**
\brief this function will send the information needed to save the game in the main Window and will close the game
*/
void game_1_widget::save_toMain(){
    int x = time_elapsed->elapsed();
    emit save_data(game_score,x,game_level);
    qDebug()<<time_elapsed->elapsed();
    emit exit_1();

}
/**
\brief this function is used for resume game, sets the previous score and the previous elapsed time
\param myscore the previous score
\param mytime the previous timer
*/
void game_1_widget::set_score_time(int myscore,int mytime){
    game_score= game_score+myscore;
    score_label->setText("Score: " + QString::number(game_score));
    int x = (60*1000)-mytime;
    game_timer->start(x);
}

