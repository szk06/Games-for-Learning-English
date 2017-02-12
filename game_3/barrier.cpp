//Hello, easy game
#include "barrier.h"
/**
*\brief Conctructor of the barrier
*\param level
*
Sets the barrier and its attributes to initial values

*/
barrier::barrier(int x)
{
    level_barrier =x;
    is_lost =false;
    passed=false;
    setPixmap(QPixmap("img3/barrier.png").scaled(80,80));
    //game2 = new lev32game(level_barrier);
    game2 = new lev2game(level_barrier,true);
    connect(game2,SIGNAL(endgame2(bool)),this,SLOT(done_barrier(bool)));

}

void barrier::start_game(){

    game2->show();
}
/**
*\brief player done with barrier

*\param boolean if won or not
*/
void barrier::done_barrier(bool x){
    if(x==true){
        passed =true;
        game2->close();

    }else{
        //is_lost =true;
        passed=false;
        game2->close();
        //delete game2;
        //game2= new lev32game(level_barrier);
        game2= new lev2game(level_barrier,true);
        connect(game2,SIGNAL(endgame2(bool)),this,SLOT(done_barrier(bool)));

    }

}
void barrier::close_games(){
    game2->close();
}
