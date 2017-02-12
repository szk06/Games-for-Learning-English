/**
\file main_widget.cpp
\brief contains the Buttons and the labels of the main page that loads
at the beginning of the project

*
This class inherits from QWidget and it contains 3 buttons are History,Game,
and Account

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#include<QList>
#include<QDebug>
#include "main_widget.h"
#include<iostream>
using namespace std;
/**
\breif Constructor of the entrance class
\param parent of type QWidget

*
In this function, all the buttons of the entrance class are created, siganls are defined
and connected to the buttons, and the setLayout function is called

*/

main_widget::main_widget(QWidget *parent) :
    QWidget(parent)
{
    signed_in =false;
    current_game = "";
    Account = new QPushButton("Account");
    QObject::connect(Account,SIGNAL(clicked()),this,SLOT(account_click()));

    History = new QPushButton("History");
    History->setEnabled(false);

    QObject::connect(History,SIGNAL(clicked()),this,SLOT(history_click()));

    Games = new QPushButton("Games");
    //Game->setEnabled(false);
    QObject::connect(Games,SIGNAL(clicked()),this,SLOT(games_click()));

    Bacck = new QPushButton("Back");
    //Bacck->setEnabled(false);
    QObject::connect(Bacck,SIGNAL(clicked()),this,SLOT(back_click()));

    set_horizontal_layout();
    set_stacked_layout();
    set_vertical_layout();
    setLayout(VLayout);

}
/**
\brief sets stacked layout
*
In this function, the windows of the program are added to the stacked layout

*/
void main_widget::set_stacked_layout(){
    SLayout = new QStackedLayout();

    hello = new QLabel("Welcome to 435L Project!");
    SLayout->addWidget(hello);

    account = new account_widget();
    SLayout->addWidget(account);
    QObject::connect(account->signin, SIGNAL(clicked()), this, SLOT(signin_click()));
    QObject::connect(account->signup, SIGNAL(clicked()), this, SLOT(signup_click()));
    QObject::connect(account->signout, SIGNAL(clicked()), this, SLOT(signout_click()));
    history = new history_widget();
    SLayout->addWidget(history);

    games_list = new games_list_widget();
    SLayout->addWidget(games_list);

    QObject::connect(games_list->game_1_btn, SIGNAL(clicked()), this, SLOT(enter_play_menu()));
    QObject::connect(games_list->game_2_btn, SIGNAL(clicked()), this, SLOT(enter_play_menu()));
    QObject::connect(games_list->game_3_btn, SIGNAL(clicked()), this, SLOT(enter_play_menu()));
    QObject::connect(games_list->game_4_btn, SIGNAL(clicked()), this, SLOT(enter_play_menu()));

    //QObject::connect(SLayout, SIGNAL(currentChanged (int)), this, SLOT(slayout_change()));
}
/**
\brief sets the play menu
*
In this function, the play menu is created and set

*/
void main_widget::enter_play_menu()
{
    QPushButton *senderObj = (QPushButton*)sender();
    current_game = senderObj->text();
    play_menu = new play_menu_widget(current_game);
    if(signed_in==false){
        play_menu->resume_btn->setEnabled(false);
    }else{
        play_menu->resume_btn->setEnabled(true);
    }

    //connect the buttons
    QObject::connect(play_menu->new_btn, SIGNAL(clicked()), this, SLOT(enter_levels_menu()));
    qDebug()<<current_game;


    QObject::connect(play_menu->resume_btn, SIGNAL(clicked()), this,SLOT( enter_resume_levels_menu()));

    QObject::connect(play_menu->instructions_btn, SIGNAL(clicked()), this, SLOT(game_desc()));


    SLayout->addWidget(play_menu);
    SLayout->setCurrentWidget(play_menu);
}
/**
\brief sets the levels menu
*
In this function, the levels menu is created and set

*/
void main_widget::enter_levels_menu()
{
    levels_list = new levels_list_widget();
    QObject::connect(levels_list->level_1_btn, SIGNAL(clicked()), this, SLOT(launch_new_game()));
    QObject::connect(levels_list->level_2_btn, SIGNAL(clicked()), this, SLOT(launch_new_game()));
    QObject::connect(levels_list->level_3_btn, SIGNAL(clicked()), this, SLOT(launch_new_game()));

    SLayout->addWidget(levels_list);
    SLayout->setCurrentWidget(levels_list);
}

/**
\brief creates the game widget
*
In this function, the game widget is created and shown and the main window is hidden

*/
void main_widget::launch_new_game()
{
    QPushButton *senderObj = (QPushButton*)sender();
    QString level = senderObj->text();
    if (level == "Level I")
        current_game_level = 1;
    if (level == "Level II")
        current_game_level = 2;
    if (level == "Level III")
        current_game_level = 3;

    if (current_game == "Balloon Shooting")
    {
        game_1 = new game_1_widget(current_game_level);

        connect(game_1, SIGNAL(repeat_1(int)), this, SLOT(repeat_game_1(int)));
        connect(game_1, SIGNAL(exit_1()), this, SLOT(exit_game_1()));
        connect(game_1,SIGNAL(game_tomain_score(int,int)),this,SLOT(game_history(int,int)));
        connect(game_1,SIGNAL(save_data(int,int,int)),this,SLOT(game1_save(int,int,int)));
        game_1->show();
        this->hide();
    }

    if (current_game == "Escape Hangman")
    {

        game_2 = new lev2game(current_game_level,false);


        connect(game_2, SIGNAL(repeat_2(int)), this, SLOT(repeat_game_2(int)));
        connect(game_2, SIGNAL(exit_2()), this, SLOT(exit_game_2()));
        connect(game_2,SIGNAL(score_toMain(int,int)),this,SLOT(game_history(int,int)));
        connect(game_2,SIGNAL(save_toMain(lev2game*)),this,SLOT(game2_save(lev2game*)));
        game_2->show();
        this->hide();

    }

    if (current_game == "Escape Maze")
    {

        game_3 = new lev3game(current_game_level);


        connect(game_3, SIGNAL(repeat_3(int)), this, SLOT(repeat_game_3(int)));
        connect(game_3, SIGNAL(exit_3()), this, SLOT(exit_game_3()));
        connect(game_3,SIGNAL(score_toMain(int,int)),this,SLOT(game_history(int,int)));
        game_3->show();
        this->hide();

    }

    if(current_game == "Scrabble")
    {
        int nbr_plyrs = 0;

        while(nbr_plyrs < 2)
            nbr_plyrs = QInputDialog::getInt(0, "Scrabble","Number of players:", 1);

        game_4 = new game_4_widget(nbr_plyrs);

        connect(game_4, SIGNAL(repeat_4(int)), this, SLOT(repeat_game_4(int)));
        connect(game_4, SIGNAL(exit_4()), this, SLOT(exit_game_4()));
        connect(game_4,SIGNAL(score_toMain(int,int)),this,SLOT(game_history(int,int)));

        game_4->show();
        this->hide();
    }

}
/**
\brief handles the exit signal of game 4
*
In this function, the game window is closed and the main menu is shown

*/

void main_widget::exit_game_4()
{
    game_4->close();
    delete game_4;

    current_game_level = 0;
    current_game = "";

    SLayout->setCurrentWidget(hello);
    this->show();
}
/**
\brief handles the repeat signal of game 4
*
In this function, the game window is recreated

*/

void main_widget::repeat_game_4(int nbr_players)
{
    game_4->close();
    delete game_4;

    game_4 = new game_4_widget(nbr_players);

    connect(game_4, SIGNAL(repeat_4(int)), this, SLOT(repeat_game_4(int)));
    connect(game_4, SIGNAL(exit_4()), this, SLOT(exit_game_4()));

    game_4->show();
}
/**
\brief handles the exit signal of game 3
*
In this function, the game window is closed and the main menu is shown

*/

void main_widget::exit_game_3()
{
    game_3->close();
    delete game_3;

    current_game_level = 0;
    current_game = "";

    SLayout->setCurrentWidget(hello);
    this->show();
}
/**
\brief handles the repear signal of game 3
*
In this function, the game window is recreated

*/

void main_widget::repeat_game_3(int level)
{
    game_3->close();
    delete game_3;

    current_game_level = level;
    game_3 = new lev3game(level);

    connect(game_3, SIGNAL(repeat_3(int)), this, SLOT(repeat_game_3(int)));
    connect(game_3, SIGNAL(exit_3()), this, SLOT(exit_game_3()));

    game_3->show();
}
/**
\brief handles the exit signal of game 2
*
In this function, the game window is closed and the main menu is shown

*/

void main_widget::exit_game_2()
{
    game_2->close();
    delete game_2;

    current_game_level = 0;
    current_game = "";

    SLayout->setCurrentWidget(hello);
    this->show();
}
/**
\brief handles the repear signal of game 2
*
In this function, the game window is recreated

*/

void main_widget::repeat_game_2(int level)
{
    game_2->close();
    delete game_2;

    current_game_level = level;
    game_2 = new lev2game(level,false);

    connect(game_2, SIGNAL(repeat_2(int)), this, SLOT(repeat_game_2(int)));
    connect(game_2, SIGNAL(exit_2()), this, SLOT(exit_game_2()));

    game_2->show();
}
/**
\brief handles the exit signal of game 1
*
In this function, the game window is closed and the main menu is shown

*/
void main_widget::exit_game_1()
{
    game_1->close();
    delete game_1;

    current_game_level = 0;
    current_game = "";

    SLayout->setCurrentWidget(hello);
    this->show();
}
/**
\brief handles the repear signal of game 1
*
In this function, the game window is recreated

*/
void main_widget::repeat_game_1(int level)
{
    game_1->close();
    delete game_1;

    current_game_level = level;
    game_1 = new game_1_widget(level);

    connect(game_1, SIGNAL(repeat_1(int)), this, SLOT(repeat_game_1(int)));
    connect(game_1, SIGNAL(exit_1()), this, SLOT(exit_game_1()));
    game_1->show();

}

/**/
/**
\brief sets horizontal layout
*
in this function, the buttons and the elements
of the class are added to the horizontal layout

*/
void main_widget::set_horizontal_layout(){
    HLayout = new QHBoxLayout();
    HLayout->addWidget(Account);
    HLayout->addWidget(History);
    HLayout->addWidget(Games);
    HLayout->addWidget(Bacck);
}

/**
\brief sets vertical layout
*
in this function, the layersof the class are
added to the vertical layout

*/
void main_widget::set_vertical_layout(){
    VLayout = new QVBoxLayout();
    VLayout->addLayout(HLayout);
    VLayout->addLayout(SLayout);
}

/**
\brief slot when history button is clicked
*
This slot is called when the history button issues a signal, and the history menu is set
*/
void main_widget::history_click(){
    SLayout->setCurrentWidget(history);
    //Bacck->setEnabled(true);
    connect(history->game1,SIGNAL(clicked()),this,SLOT(game1_history()));
    connect(history->game2,SIGNAL(clicked()),this,SLOT(game2_history()));
    connect(history->game3,SIGNAL(clicked()),this,SLOT(game3_history()));
    connect(history->game4,SIGNAL(clicked()),this,SLOT(game4_history()));
    connect(history->overall,SIGNAL(clicked()),this,SLOT(overall_history()));

}

/**
\brief slot when account button is clicked
*
This slot is called when the account button issues a signal, and the account menu is set
*/
void main_widget::account_click(){
    SLayout->setCurrentWidget(account);
}
void main_widget::signin_click(){
    add_sign = new sign_in();
    add_sign->show();
    connect(add_sign,SIGNAL(signed_in(bool,QString)),this,SLOT(player_sign_in(bool,QString)));

}
void main_widget::signup_click(){
    new_user = new sign_up();
    new_user->show();

}
void main_widget::signout_click(){
    signed_in =false;
    user_name ="";
    account->signout->setEnabled(false);
    account->signin->setEnabled(true);
    account->signup->setEnabled(true);

}
/**
\brief slot when games button is clicked
*
This slot is called when the games button issues a signal, and the games menu is set
*/
void main_widget::games_click(){
    SLayout->setCurrentWidget(games_list);
}
/**/
/**
\brief slot when back button is clicked
*
This slot is called when the back button issues a signal, it is not implemented yet
*/
void main_widget::back_click(){
    //SLayout->setCurrentIndex(previous_window_index);
}

void main_widget::slayout_change(){
   // update the back button based on behavior
   // the back button has not been implemented yet
}
void main_widget::player_sign_in(bool x,QString s){
    if(x==true){
        History->setEnabled(true);
        account->signout->setEnabled(true);
        account->signin->setEnabled(false);
        account->signup->setEnabled(false);

        user_name = s;
        signed_in =true;
    }
}

void main_widget::game_history(int score, int game){
    if(signed_in==true){
        cout<<"I am in the slot";
        QString filename = "account/"+user_name+".txt";

        qDebug()<<user_name;
        qDebug()<<score;
        qDebug()<<game;
        QString toWrite = "game"+QString::number(game)+":"+QString::number(score);
        QFile file( filename );
        if ( file.open(QIODevice::Append) )
        {
            QTextStream stream( &file );
            stream <<toWrite << endl;

        }
        cout<<"Score is:"<<score<<endl;



        file.close();

    }
}
void main_widget::game1_history(){
    QString file_name= "account/"+user_name+".txt";
    QList<int> scores;
    QFile inputFile(file_name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QStringList sp = line.split(':');
          if(sp.at(0)=="game1"){
              scores.append(sp.at(1).toInt());
          }


       }

    }

       inputFile.close();
       myplot = new plotter(current_game,scores);
       myplot->show();
}
void main_widget::overall_history(){
    QString file_name= "account/"+user_name+".txt";
    QList<int> scores1;
    QList<int> scores2;
    QList<int> scores3;
    QList<int> scores4;
    int score1=0;
    int score2=0;
    int score3=0;
    int score4=0;

    QFile inputFile(file_name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       //For game1 history
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QStringList sp = line.split(':');
          if(sp.at(0)=="game1"){
              scores1.append(sp.at(1).toInt());
              score1 = score1 + sp.at(1).toInt();
          }else if(sp.at(0)=="game2"){
              scores2.append(sp.at(1).toInt());
              score2 = score2 + sp.at(1).toInt();
          }else if(sp.at(0)=="game3"){
              scores3.append(sp.at(1).toInt());
              score3 = score3 + sp.at(1).toInt();
          }else if(sp.at(0)=="game4"){
              scores4.append(sp.at(1).toInt());
              score4 = score4 + sp.at(1).toInt();
          }






       }
       if(scores1.size()!=0){
            score1 = score1/scores1.size();
       }
       if(scores2.size()!=0){
            score2 = score2/scores2.size();
       }
       if(scores3.size()!=0){
            score3 = score3/scores3.size();
       }
       if(scores4.size()!=0){
            score4 = score4/scores4.size();
       }


       qDebug()<<"Score1: "<<score1;
       qDebug()<<"Score2: "<<score2;
       qDebug()<<"Score3: "<<score3;
       qDebug()<<"Score4: "<<score4;

    }
    plot_overall = new overall_plotter(score1,score2,score3,score4);
    plot_overall->show();
    inputFile.close();

}
void main_widget::game2_history(){
    QString file_name= "account/"+user_name+".txt";
    QList<int> scores;
    QFile inputFile(file_name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QStringList sp = line.split(':');
          if(sp.at(0)=="game2"){
              scores.append(sp.at(1).toInt());
          }


       }

    }
    myplot = new plotter(current_game,scores);
    myplot->show();

    inputFile.close();
}
void main_widget::game3_history(){
    QString file_name= "account/"+user_name+".txt";
    QList<int> scores;
    QFile inputFile(file_name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QStringList sp = line.split(':');
          if(sp.at(0)=="game3"){
              scores.append(sp.at(1).toInt());
          }


       }

    }
    myplot = new plotter(current_game,scores);
    myplot->show();

       inputFile.close();
}
void main_widget::game4_history(){
    QString file_name= "account/"+user_name+".txt";
    QList<int> scores;
    QFile inputFile(file_name);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QStringList sp = line.split(':');
          if(sp.at(0)=="game4"){
              scores.append(sp.at(1).toInt());
          }


       }

    }
    myplot = new plotter(current_game,scores);
    myplot->show();

       inputFile.close();
}
void main_widget::game1_save(int score, int time,int level){

    if(signed_in==true){
        QFile file("account/game1"+user_name);
        if(!file.open(QIODevice::WriteOnly)){

            qDebug()<<"Error Writing the resume";
            return;
        }
        QDataStream out(&file);
        QString l = QString::number(level);
        QString s = QString::number(score);
        QString t = QString::number(time);
        qDebug()<<"time"<<t;
        qDebug()<<"score"<<s;
        qDebug()<<"level"<<l;
        out.setVersion(QDataStream::Qt_4_8);
        out<<s<<t<<l;
        file.flush();
        file.close();
    }
}

void main_widget::game2_save(lev2game *game){
    if(signed_in==true){
        QMap<qint64,lev2game *>map;
        map.insert(1,game);
        QString s="account/game2"+user_name;
        QFile file(s);
        if(!file.open(QIODevice::WriteOnly)){
            qDebug()<<"Couldn't open file";
            return;

        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_8);
        out<< map;
        file.flush();
        file.close();
    }

}
void main_widget::game3_save(lev3game *game){

}

void main_widget:: enter_resume_levels_menu(){
    QString s;
    if (current_game == "Balloon Shooting"){
        s="1";
        //loading game1 from disk
        QFile file("account/game1"+user_name);
        if(!file.open(QIODevice::ReadOnly)){

            qDebug()<<"Error Writing the resume";
            return;
        }
        QString time,score,level;
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_8);
        in>> score>>time>>level;
        file.close();
        qDebug()<<"Score: "<<score;
        qDebug()<<"Time: "<<time;
        qDebug()<<"Level: "<<level;
        int s = score.toInt();
        int t= time.toInt();
        int l=level.toInt();
        qDebug()<<s<<" "<<t<<" "<<l;

        game_1 = new game_1_widget(l);
        game_1->set_score_time(s,t);

        connect(game_1, SIGNAL(repeat_1(int)), this, SLOT(repeat_game_1(int)));
        connect(game_1, SIGNAL(exit_1()), this, SLOT(exit_game_1()));
        connect(game_1,SIGNAL(game_tomain_score(int,int)),this,SLOT(game_history(int,int)));
        connect(game_1,SIGNAL(save_data(int,int,int)),this,SLOT(game1_save(int,int,int)));
        game_1->show();



    }else if(current_game=="Escape Hangman"){
        s="2";
    }else if (current_game == "Escape Maze"){
        s="3";
    }else if(current_game=="Scrabble"){
        s="4";
    }


}

void main_widget::game_desc(){
    desc = new description(current_game);
    desc->show();
}
