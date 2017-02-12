/**
*\file lev32game.cpp

*\brief the game widget of the game2 that contains the gamescene

*
This class contains the level2game widget that contains the scene it has also the hints
menu which allow the user to know the next letter

\author Sami & Mohammad Ali
*/

#include "lev32game.h";
/**
*\brief Constructor of the class, it sets the number of hints allowed according to the level
*\param x the level of the game
*
This Constructor takes the level of the game and based on that sets the allowed hints
and creates the scene and view of the game

*/
lev32game::lev32game(/*QWidget *parent,*/int x)/* :
    QWidget(parent)*/
{
    //ifstream inFile;
    QString file_name;
    counter_now =0;
    level_now = x;
    if (level_now==1){
        level_label = new QLabel("Level:1");
        attempts_available = 3;
        hints_available = 3;
        //attempts_available_label = new QLabel("Remaing attempts: 4");
        hints_available_label = new QLabel("Remaing hints: 3");
        //inFile.open("level1.txt");
        file_name="files/level1.txt";
        word_length =5;

    }else if (level_now==2){
        level_label = new QLabel("Level:2");
        attempts_available = 2;
        hints_available = 2;
        //attempts_available_label = new QLabel("Remaing attempts: 3");
        hints_available_label = new QLabel("Remaing hints: 2");

        word_length =6;
        file_name="files/level2.txt";

    }else if (level_now==3){

        level_label = new QLabel("Level:3");
        attempts_available = 1;
        hints_available = 1;
        //attempts_available_label = new QLabel("Remaing attempts: 2");
        hints_available_label = new QLabel("Remaing hints: 1");
        word_length =7;
        file_name="files/level3.txt";
        //inFile.open("level1.txt");
    }
    QFile file(file_name);
    if (!file.exists()) {
        correct_word="Not found file";
    }
    else{
        //QString errMsg;
        //QFileDevice::FileError err = QFileDevice::NoError;
        if (!file.open(QIODevice::ReadOnly)) {
            correct_word = "error opening";
        }
        else{
            QTextStream in(&file);
            QString s;
            while(!in.atEnd()){
                s = in.readLine();
                all_words.append(s);

            }

            int list_size = all_words.size();
            int rand_chose = qrand()%list_size;
            //level_label->setText(QString::number(rand_chose));
            correct_word = all_words.at(rand_chose);
        }
    }
    attempts_available_label = new QLabel("Hint: ");


    answer = new QComboBox();
    answer->addItem(tr("a"));
    answer->addItem(tr("b"));
    answer->addItem(tr("c"));
    answer->addItem(tr("d"));
    answer->addItem(tr("e"));
    answer->addItem(tr("f"));
    answer->addItem(tr("g"));
    answer->addItem(tr("h"));
    answer->addItem(tr("i"));
    answer->addItem(tr("j"));
    answer->addItem(tr("k"));
    answer->addItem(tr("l"));
    answer->addItem(tr("m"));
    answer->addItem(tr("n"));
    answer->addItem(tr("o"));
    answer->addItem(tr("p"));
    answer->addItem(tr("q"));
    answer->addItem(tr("r"));
    answer->addItem(tr("s"));
    answer->addItem(tr("t"));
    answer->addItem(tr("u"));
    answer->addItem(tr("v"));
    answer->addItem(tr("w"));
    answer->addItem(tr("x"));
    answer->addItem(tr("y"));
    answer->addItem(tr("z"));

    correct_letters = correct_word.split(' ');
    submit_answer = new QPushButton("Submit a Letter");
    hint_use=new QPushButton("Use a Hint");
    scene2 = new gamescene32(x,word_length,attempts_available);
    scene2->setSceneRect(0,0,850,850);


    view2 =  new QGraphicsView(scene2);
    view2->setBackgroundBrush(QBrush(QImage("img2/back.jpg")));
    view2->setFixedSize(850,900);

    mygrid = new QGridLayout;
    VLayout = new QVBoxLayout;
    connect(submit_answer,SIGNAL(clicked()),this,SLOT(submit_letter()));
    connect(hint_use,SIGNAL(clicked()),this,SLOT(use_hint()));
    setGrid();
    setVertical();
    setLayout(VLayout);
    connect(scene2,SIGNAL(Won(bool)),this,SLOT(gameEnd(bool)));



}
/**
*\brief sets the Grid Layout
*/

void lev32game::setGrid(){
    mygrid->addWidget(level_label,0,0);
    mygrid->addWidget(attempts_available_label,0,1);
    mygrid->addWidget(hints_available_label,0,2);
    mygrid->addWidget(answer,1,0);
    mygrid->addWidget(submit_answer,1,1);
    mygrid->addWidget(hint_use,1,2);
}
/**
*\brief sets the Vertical Layout
*/
void lev32game::setVertical(){
    VLayout->addItem(mygrid);
    VLayout->addWidget(view2);
}
/**
*\brief slot that submits the character from Combo box
*
This function takes a value from Combo Box after a click on the button and then checks
if the submitted character is correct or not
Then sends the command to the scene to move the criminal if the answer was correct or
wrong
*/
void lev32game::submit_letter(){
    QString s = answer->currentText();

    if(correct_letters.at(counter_now)==s){

        level_label->setText("Correct guess");
        counter_now++;
        scene2->move_criminal(true,s);

    }else{
       level_label->setText("Wrong guess");
       scene2->move_criminal(false,s);
    }


}
/**
*\brief Slot activated when player click on button show hint
*
This slot is activated on a button signal, when the signal is generated the function
if there is remaining hints or not
If yes it shows him the next letter


*/
void lev32game::use_hint(){
    if(hints_available>=1){
        QString toshow = correct_letters.at(counter_now);
        attempts_available_label->setText("Hint: "+toshow);
        hints_available--;
        QString s = QString::number(hints_available);
        hints_available_label->setText("Hints Remaining: "+s);

    }else{
        hints_available_label->setText("No hints Remaining");
    }
}
/**
*\brief waits for signal from gamescene
*\param x boolean true if won, false if lost
*/
void lev32game::gameEnd(bool x){
    if(x==true){
        level_label->setText("Game Won");
        emit endgame2(true);

    }else{
        level_label->setText("Lost");
        emit endgame2(false);
    }
    submit_answer->setEnabled(false);
    this->close();
}
