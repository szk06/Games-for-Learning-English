#include "gamescene3.h"
#include<QDebug>
/**
*\brief Constructor of the Scene


*/
gamescene3::gamescene3()
{
    addLow();
    addFirst();
    addSecond();
    addThird();
    myperson = new person();

    addItem(myperson);


}
/**
*\brief adds the roads and the barriers

*/
void gamescene3::addLow(){
    int counter;
    int num;
    bool horizontal = true;
    for(counter=0;counter<3;counter++){
        num=counter*100;
        myroad = new road(horizontal);
        myroad->setPos(num,430);
        addItem(myroad);
    }
    mybarrier = new barrier(1);
    num = num+103;
    mybarrier->setPos(num,600);
    addItem(mybarrier);
    num= num+80;
    list_b.append(mybarrier);

    for(counter=0;counter<1;counter++){
        num=num+counter*50;
        myroad = new road(horizontal);
        myroad->setPos(num,430);
        addItem(myroad);
        mybarrier = new barrier(1);
        num = num+103;
        mybarrier->setPos(num,600);
        addItem(mybarrier);
        num= num+80;
        list_b.append(mybarrier);
    }
    for(counter=0;counter<3;counter++){
        num=num+counter*50;
        myroad = new road(horizontal);
        myroad->setPos(num,430);
        addItem(myroad);
    }
    victory = new dest();
    addItem(victory);
    //connect(mybarrier,SIGNAL(barrier_pass(bool)),this,SLOT(passed()));
    //connect(myperson,SIGNAL(win_game()),this,SLOT(won()));
}
/**
*\brief adds the roads and the barriers

*/
void gamescene3::addFirst(){


    bool horizontal = false;
    int counter =0;
    int num=0;
    while(counter<2){
        myroad = new road(horizontal);
        num =num+ counter*100;

        myroad->setPos(100,450-num);
        addItem(myroad);

        mybarrier = new barrier(3);
        mybarrier->setPos(110,450-num-70);
        addItem(mybarrier);
        list_b.append(mybarrier);

        num =num+170;


        counter++;
    }

}
/**
*\brief adds the roads and the barriers

*/
void gamescene3::addSecond(){

    bool horizontal = false;
    int counter =0;
    int num=0;
    while(counter<2){
        myroad = new road(horizontal);
        num =num+ counter*100;

        myroad->setPos(370,450-num);
        addItem(myroad);

        mybarrier = new barrier(1);
        mybarrier->setPos(380,450-num-70);
        addItem(mybarrier);
        list_b.append(mybarrier);
        num =num+170;


        counter++;
    }

}
/**
*\brief adds the roads and the barriers

*/
void gamescene3::addThird(){

    bool horizontal = false;
    int counter =0;
    int num=0;

    while(counter<2){
        myroad = new road(horizontal);
        num =num+ counter*100;

        myroad->setPos(600,450-num);
        addItem(myroad);

        mybarrier = new barrier(1);
        mybarrier->setPos(610,450-num-70);
        addItem(mybarrier);
        list_b.append(mybarrier);

        num =num+170;


        counter++;
    }


}
/**
*\brief waits for the clicks of the player

*\param event from user

*
This function will control the movement of the criminal inside the allowed areas

*/
void gamescene3::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Right && myperson->x()<630){
        myperson->moveright();
    }else if(event->key()==Qt::Key_Left && myperson->x()>10){
        myperson->moveleft();

    }else if(event->key()==Qt::Key_Up){
        myperson->moveup();
    }else if(event->key()==Qt::Key_Down && myperson->y()<600){
        myperson->movedown();
    }

}
void gamescene3::passed(){

    emit open_game();
}


void gamescene3::close_game2(){
    int counter=0;
    qDebug()<<"Size is: "<<list_b.size();
    while(counter<list_b.size()){
        list_b.at(counter)->close_games();
        counter++;
    }

}
