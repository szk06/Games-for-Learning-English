#include "lev3game.h"
/**
*\brief Constructor of the Widget
*\param level of the game


*/
lev3game::lev3game(int x)
{
    game_level =x;
    if(game_level==1){
        time_ini = 150;

    }else if(game_level==2){
        time_ini = 100;

    }else if(game_level==3){
        time_ini =50;
    }
    QString s = QString::number(time_ini);
    time_label = new QLabel("Time Remainig: "+s);
    game_time = new QTimer(this);
    connect(game_time,SIGNAL(timeout()),this,SLOT(time_decrement()));
    game_time->start(1000);
    game_num =new QLabel("Game 3");
    scene3 = new gamescene3();
    scene3->setSceneRect(0,0,850,850);
    is_end =false;
    view3 = new QGraphicsView(scene3);
    view3->setBackgroundBrush(QBrush(QImage("img3/back.jpg")));
    view3->setFixedSize(850,900);
    resultofgame = new QLabel("Score: ");
    save_game = new QPushButton("Save");
    mygrid = new QGridLayout;
    VLayout = new QVBoxLayout;
    setGrid();
    setVertical();
    setLayout(VLayout);
    connect(save_game,SIGNAL(clicked()),this,SLOT(save_clicked()));





    //player wins when he reaches the destination
    connect(scene3->myperson,SIGNAL(win_game(bool)),this,SLOT(gameEnd(bool)));
    //player loses due to time
    connect(this,SIGNAL(lost(bool)),this,SLOT(gameEnd(bool)));


}
void lev3game::setGrid(){
    mygrid->addWidget(save_game,0,0);

    mygrid->addWidget(time_label,0,1);
    mygrid->addWidget(resultofgame,0,2);

}
void lev3game::setVertical(){
    VLayout->addItem(mygrid);
    VLayout->addWidget(view3);

}
/**
*\brief decremnts the time every second
*/
void lev3game::time_decrement(){

    if(time_ini==0){
        emit lost(false);
    }else if(is_end!=true){
        time_ini--;
        QString s = QString::number(time_ini);
        time_label->setText("Time Remainig: "+s);

    }
}
void lev3game::toClose(){
    //this->close();

}
void lev3game::toOpen(){
    this->show();
    game_num->setText("Open SIGNAL");
}
/*
void lev3game::gameEnd(bool x){
    if(x==true){
        QString s = QString::number(time_ini);
        resultofgame->setText("Score: "+s);
        time_label->setText("Congratulations, you won");
    }else{
        resultofgame->setText("Game Over, You Lost");
    }
    is_end =true;
}
*/
/**
*\brief waits for signal from gamescene
*\param x boolean true if won, false if lost
*/

void lev3game::gameEnd(bool x)
{

    QMessageBox* message_box = new QMessageBox();
    QString myscore;
    emit score_toMain(time_ini,3);

    QPushButton* exit_btn = message_box->addButton("Exit",QMessageBox::YesRole);
    QPushButton* repeat_btn = message_box->addButton("Repeat",QMessageBox::YesRole);
    QPushButton* nxt_btn;
    if(x == true)
        nxt_btn = message_box->addButton("Next Level",QMessageBox::YesRole);

    if (x == true){
        myscore = QString::number(time_ini);
        message_box->setText("Game Over!\nYou Won!\nYour Score is: "+myscore);
    }
    else
    {
        message_box->setText("Game Over!\nYou Lost!");
        scene3->close_game2();
    }
    message_box->exec();

    if(message_box->clickedButton() == exit_btn)
    {
        emit exit_3();
    }
    if(message_box->clickedButton() == repeat_btn)
    {
        emit repeat_3(this->game_level);
    }
    if (x == true)
    {
        if(message_box->clickedButton() == nxt_btn)
        {
            if(game_level < 3)
                emit repeat_3(this->game_level+1);
            else
                emit repeat_3(this->game_level);
        }
    }
    //delete message_box;
}
void lev3game::save_clicked(){
    emit save_toMain();
    emit exit_3();
}

