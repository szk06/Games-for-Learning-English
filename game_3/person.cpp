#include "person.h"
/**

*/

person::person(QObject *parent) :
    QObject(parent)
{
    setPixmap(QPixmap("img3/criminal.png").scaled(40,100));
    setPos(10,530);

}
void person::movedown(){

    setPos(x(),y()+10);
    bool m = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(road)){
            m=true;
        }
        if(typeid(*colliding_items[i])==typeid(barrier)){
            barrier *A = dynamic_cast<barrier *>(colliding_items[i]);

            if(A->passed==false){

                A->start_game();
                emit on_barrier();

            }else {
                m= true;
            }


        }
        if(typeid(*colliding_items[i])==typeid(dest)){
            emit win_game(true);

        }
    }

    if(m==false){
        setPos(x(),y()-10);
    }


}
void person::moveup(){
    setPos(x(),y()-10);
    bool m = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(road)){
            m=true;
        }
        if(typeid(*colliding_items[i])==typeid(barrier)){
            barrier *A = dynamic_cast<barrier *>(colliding_items[i]);
            if(A->passed==false){

                    A->start_game();
                    emit on_barrier();

            }else{

                m =true;
            }

        }
        if(typeid(*colliding_items[i])==typeid(dest)){
            emit win_game(true);

        }

    }

    if (m==false){


        setPos(x(),y()+10);

    }


}
void person::moveleft(){

    setPos(x()-10,y());
    bool m = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(road)){
            m=true;
        }
        if(typeid(*colliding_items[i])==typeid(barrier)){
            barrier *A = dynamic_cast<barrier *>(colliding_items[i]);
            if(A->passed==false){

                    A->start_game();
                    emit on_barrier();

            }
            else{
                m =true;
            }

        }
        if(typeid(*colliding_items[i])==typeid(dest)){
            emit win_game(true);

        }
    }
    if (m==false){
        setPos(x()+10,y());
    }

}
void person::moveright(){
    setPos(x()+10,y());
    bool m = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(road)){
            m=true;
        }
        if(typeid(*colliding_items[i])==typeid(barrier)){
            barrier *A = dynamic_cast<barrier *>(colliding_items[i]);
            if(A->passed==false){


                    A->start_game();
                    emit on_barrier();

            }else{

                m =true;
            }

        }
        if(typeid(*colliding_items[i])==typeid(dest)){
            emit win_game(true);

        }
    }
    if (m==false){
        setPos(x()-10,y());
    }



}
