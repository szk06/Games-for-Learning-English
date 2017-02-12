/**
*\file gamescene2.h
*\brief Scene of the game

*
This class contains the holes and the grounds that the criminal will pass over.It also
contains the the crimnal and the dashes that the letters will be displayed on them


*\author Sami & Mohammad Ali
*/
#include "gamescene2.h"
/**
*\brief Constructor of the scene, intializes the scene
*\param x the level of the game
*\param y the number of letters in the word to be guessed
*\param z allowed mistakes, which is number of grounds before each hole
*
The constructor starts the scnen and uses others functions to create grounds,holes, and
dashes
*/
gamescene2::gamescene2(int x,int y,int z)
{
    mylevel =x;
    numLetters =y;
    letter_eval= NULL;
    allowed_attempts = z;
    game_criminal = new criminal();
    addItem(game_criminal);
    game_criminal->setFlag(QGraphicsItem::ItemIsFocusable);
    game_criminal->setFocus();
    normal_ground = new ground(0);
    current_location =game_criminal->x();
    global_count =1;
    addItem(normal_ground);
    normal_ground->setFlag(QGraphicsItem::ItemIsFocusable);
    normal_ground->setFocus();

    int count=numLetters+numLetters*allowed_attempts+1;

    mylist.append(normal_ground);

    int counter =0;
    for(counter=1;counter<=count;counter++){

        if(counter%(allowed_attempts+1)==0){
            addhole(counter);
        }else{
            addground(counter);
        }

    }
    int m=0;
    for(counter=0;counter<numLetters;counter++){
        m = 20+60*counter;
        add_dash(m);
        dash_place.append(m);
    }


}

/**
*\brief add a ground in a certain x position
*\param x the x position to be set in

*/
void gamescene2::addground(int x){
    normal_ground = new ground(x);


    addItem(normal_ground);
    normal_ground->setFlag(QGraphicsItem::ItemIsFocusable);
    normal_ground->setFocus();
    mylist.append(normal_ground);
    //holes_index.append(global_count);
    global_count++;
}
/**

*\brief add a hole in a certain x position
*\param x the x position to be set in

*/
void gamescene2::addhole(int x){
    trap_hole = new hole(x);
    addItem(trap_hole);
    trap_hole->setFlag(QGraphicsItem::ItemIsFocusable);
    trap_hole->setFocus();
    mylist.append(normal_ground);
    holes_index.append(trap_hole->x());
    global_count++;
}
/**
*\brief add a dash in a certain x position
*\param x the x position to be set in

*/
void gamescene2::add_dash(int x){

    letter_dash = new dash(x);
    addItem(letter_dash);
    letter_dash->setFlag(QGraphicsItem::ItemIsFocusable);
    letter_dash->setFocus();


}

/**
*\brief move the criminal based on player's answer
*\param w boolean if correct guess or not
*\param a or player guess from letter's list

*
The function recives if the player made a correct guess or not, if yes it will jump
him over the next hole and print correct
If not it will take him 1 step forward and print incorrect
*/
void gamescene2::move_criminal(bool w,QString a){



    QFont correct_font;
    correct_font.setPixelSize(50);
    correct_font.setBold(true);
    io = new QGraphicsTextItem;
    io->setPlainText(a);

    int mm = dash_place.last()+60;
    if(w==true){
        //if he guessed the correct answer
        //check for the closest hole and pass it
        int kk = dash_place.takeFirst()+10;
        int index_next_hole = holes_index.takeFirst();
        int positon=index_next_hole+37;
        game_criminal->ChangePosition(positon);
        current_location = index_next_hole+37;

        delete letter_eval;

        io->setPos(kk,180);

        io->setDefaultTextColor("Green");
        io->setFont(correct_font);
        addItem(io);
        letter_eval = new QGraphicsTextItem;
        letter_eval->setPlainText("Correct");
        letter_eval->setPos(mm,220);
        letter_eval->setDefaultTextColor("Green");
        letter_eval->setFont(correct_font);
        addItem(letter_eval);
        if(holes_index.isEmpty()==true){
            //no more holes to pass, the game is WON


            end_tag = new QGraphicsTextItem;
            end_tag->setPlainText("You Won");
            end_tag->setPos(320,50);
            end_tag->setDefaultTextColor("Green");
            end_tag->setFont(correct_font);
            addItem(end_tag);
            emit Won(true);
        }

    }

    else{
        //the player made an incorrect guess
        delete letter_eval;
        int index_next_hole = holes_index.first();
        int position1 = game_criminal->x();//the current x coordinate of criminal
        game_criminal->ChangePosition(position1+37);
        current_location+37;

        letter_eval = new QGraphicsTextItem;
        letter_eval->setPlainText(a+": Incorrect");
        letter_eval->setPos(mm,220);
        letter_eval->setDefaultTextColor("Red");
        letter_eval->setFont(correct_font);
        addItem(letter_eval);
        if(game_criminal->x()==index_next_hole){
            game_criminal->setY(460);
            end_tag = new QGraphicsTextItem;
            end_tag->setPlainText("Game Over");
            end_tag->setPos(320,50);
            end_tag->setDefaultTextColor("Red");
            end_tag->setFont(correct_font);
            addItem(end_tag);
            emit Won(false);

        }
    }

}
