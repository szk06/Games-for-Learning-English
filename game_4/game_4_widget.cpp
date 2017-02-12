#include "game_4_widget.h"
#include "QDebug"

using namespace std;

game_4_widget::game_4_widget(int nbr_plyrs, QWidget *parent) :
    QWidget(parent)
{
    //initialize variables
    this->consecutive_pass_counter = 0;
    this->current_player_id = -1;
    this->current_pushed_button = -1;
    this->currently_pushed_btns = new QList<QPushButton*>();
    this->global_first_move  = 1;

    // build dictionary
    build_dict();
    //create game frame
    this->game_scene= new game_4_scene();
    this->game_4_view = new QGraphicsView(game_scene);
    this->game_4_view->setFixedSize(530, 530);
    this->game_scene->setSceneRect(0, 0, 525, 525);
    this->game_4_view->show();

    initialize_bag();
    initialize_players(nbr_plyrs);
    set_players_layout(nbr_plyrs);

    set_sub_1_layout();
    set_tiles_layout();
    set_sub_2_layout();
    set_horizontal_layout();
    setLayout(HLayout);

    set_current_player(0);
}

void game_4_widget:: build_dict(){
    this->dict = new QList<QString>();
    QFile file("img4/dictionary.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //qDebug() << "dict!";
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        this->dict->append(line);
    }
}

void game_4_widget:: initialize_bag()
{
    bag = new QList<QChar>();
    QString alphabet = "abcdefghijklmnopqrstuvwxyz";
    int reps[26] = {9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1};
    for (int i = 0; i < 26; i ++)
    {
        for (int j = 0; j < reps[i]; j++)
        {
            bag->append(alphabet[i]);
        }
    }
    // append blanks
    bag->append('_');
    bag->append('_');
}

void game_4_widget:: initialize_players(int nbr_plyrs)
{
    // create players
    this->nbr_plyrs = nbr_plyrs;
    this->list_of_players = new QList<player*>();
    for (int i = 0; i < nbr_plyrs; i++)
    {
        this->list_of_players->append(new player(i));
        fill_player_rack(this->list_of_players->at(i), 7);

    }
}

void game_4_widget:: set_players_layout(int nbr_plyrs){
    this->PLayout = new QVBoxLayout();

    for (int i = 0; i < nbr_plyrs; i++)
    {
        player* p = this->list_of_players->at(i);
        p->player_label = new QLabel("Player ID: " + QString::number(p->id) + " Score: " + QString::number(p->score));
        this->PLayout->addWidget(p->player_label);
    }
}

void game_4_widget::set_sub_1_layout(){
    this->sub1VLayout = new QVBoxLayout();

    this->pass_btn = new QPushButton("PASS");
    this->shuffle_btn = new QPushButton("SHUFFLE");
    this->exchange_btn = new QPushButton("EXCHANGE");
    this->submit_btn = new QPushButton("SUBMIT");
    this->reset_btn = new QPushButton("RESET");

    sub1VLayout->addItem(PLayout);

    sub1VLayout->addWidget(pass_btn);
    sub1VLayout->addWidget(shuffle_btn);
    sub1VLayout->addWidget(exchange_btn);
    sub1VLayout->addWidget(submit_btn);
    sub1VLayout->addWidget(reset_btn);

    connect(pass_btn, SIGNAL(clicked()), this, SLOT(pass_btn_clicked()));
    connect(shuffle_btn, SIGNAL(clicked()), this, SLOT(shuffle_btn_clicked()));
    connect(exchange_btn, SIGNAL(clicked()), this, SLOT(exchange_btn_clicked()));
    connect(submit_btn, SIGNAL(clicked()), this, SLOT(submit_btn_clicked()));
    connect(reset_btn, SIGNAL(clicked()), this, SLOT(reset_btn_clicked()));
}

void game_4_widget:: set_tiles_layout(){
    this->tiles_layout = new QHBoxLayout();
    this->tiles_btn = new QList<QPushButton*>();
    for( int i = 0; i < 7; i++)
    {
        QPushButton *temp = new QPushButton();
        this->tiles_btn->append(temp);
        this->tiles_layout->addWidget(temp);
        temp->setEnabled(false);
        connect(temp, SIGNAL(clicked()), this, SLOT(select_letter()));
    }
}

void game_4_widget::set_sub_2_layout()
{
    this->sub2VLayout = new QVBoxLayout();
    sub2VLayout->addWidget(game_4_view);
    sub2VLayout->addItem(tiles_layout);
}

void game_4_widget:: set_horizontal_layout()
{
    this->HLayout = new QHBoxLayout();
    HLayout->addItem(sub1VLayout);
    HLayout->addItem(sub2VLayout);
}

void game_4_widget:: set_current_player(int i)
{
    // remove selection from old player
    if (this->current_player_id != -1)
    {
        this->list_of_players->at(this->current_player_id)->player_label->setStyleSheet("background-color: none;");
        this->list_of_players->at(this->current_player_id)->player_label->setAutoFillBackground(true);

    }
    // select new player
    this->current_player = this->list_of_players->at(i);
    this->current_player_id = i;

    this->current_player->player_label->setStyleSheet("background-color: red;");
    this->current_player->player_label->setAutoFillBackground(true);

    this->currently_pushed_btns->clear();
    //qDebug()<<"load before";
    load_deck(this->current_player);
    //qDebug()<<"load after";
}

void game_4_widget:: load_deck(player* p)
{
    // clean the buttons
    for (int j = 0; j < this->tiles_btn->size(); j++)
    {
        this->tiles_btn->at(j)->setText("");
        this->tiles_btn->at(j)->setEnabled(false);
    }
    // map the player's rack to the buttons
    int rack_size = p->player_rack->size();
    //qDebug() << "rack size: " << rack_size;
    for (int i = 0; i < rack_size; i++)
    {
        QChar c = p->player_rack->at(i);
        QString str = QString(c);
        this->tiles_btn->at(i)->setText(str);
        this->tiles_btn->at(i)->setEnabled(true);
    }
}

void game_4_widget:: set_buttons(bool b)
{
    this->exchange_btn->setEnabled(b);
    this->shuffle_btn->setEnabled(b);
    this->pass_btn->setEnabled(b);
}

void game_4_widget::select_letter()
{
    // disable pass exchange and shuffle
    set_buttons(false);

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    button->setEnabled(false);
    QChar temp = button->text().at(0);

    this->game_scene->char_to_move = temp;
    this->current_pushed_button = this->tiles_btn->indexOf(button);
    this->currently_pushed_btns->append(button);
}

void game_4_widget:: next_player_turn()
{
    // pass game to next player
    int next_player_id = this->current_player->id+1;
    if (next_player_id == this->nbr_plyrs)
        next_player_id = 0;

    //qDebug() << "game_scene before";
    this->game_scene->reset_turn();
    //qDebug() << "game_scene after";
    //qDebug() << next_player_id;
    set_current_player(next_player_id);
    //qDebug() << "set current player";
}

void game_4_widget:: exchange_btn_clicked(){
    int bag_size = this->bag->size();
    if (bag_size < 7)
        return;

    // extract the current letters
    int nbr_current_tiles = this->current_player->player_rack->size();
    vector<QChar>* temp_list = new vector<QChar>();
    for (int i = 0; i < nbr_current_tiles; i++)
    {
        temp_list->push_back(this->current_player->player_rack->at(i));
    }
    // clear the rack
    this->current_player->player_rack->clear();
    // draw from the bag
    fill_player_rack(this->current_player, nbr_current_tiles);
    // map the rack to the buttons
    load_deck(this->current_player);
    // return to bag
    for (int i = 0; i < nbr_current_tiles; i++)
    {
        bag->append(temp_list->at(i));
    }
    // reset the pass counter
    this->consecutive_pass_counter = 0;
    // pass turn to the next player
    next_player_turn();
}

void game_4_widget:: shuffle_btn_clicked(){
    // extract letters from player's rack
    vector<QChar>* temp_list = new vector<QChar>();
    int nbr_current_tiles = this->current_player->player_rack->size();
    for (int i = 0; i < nbr_current_tiles; i++)
    {
        temp_list->push_back(this->current_player->player_rack->at(i));
    }
    // shuffle the letters
    random_shuffle( temp_list->begin(), temp_list->end() );
    // replace the letters in the player's rack
    for (int i = 0; i < nbr_current_tiles; i++)
    {
        this->current_player->player_rack->replace(i, temp_list->at(i));
    }
    // load the deck from the rack - map the rack to the deck
    load_deck(this->current_player);
}

void game_4_widget:: pass_btn_clicked(){
    if (this->currently_pushed_btns->size() != 0)
        bad_submission();
    this->consecutive_pass_counter++;
    if (consecutive_pass_counter == 6)
    {
        game_over(0);
    }
    else
    {
        next_player_turn();
    }
}

void game_4_widget:: reset_btn_clicked()
{
    int nbr_tiles_put = this->game_scene->current_player_positions->size();
    int nbr_buttons_pushed = this->currently_pushed_btns->size();
    if (nbr_tiles_put != nbr_buttons_pushed)
        return;
    bad_submission();
}

void game_4_widget:: bad_submission()
{
    set_buttons(true);
    // remove all player letters from board
    int nbr_tiles_put = this->game_scene->current_player_positions->size();
    for (int i = 0; i < nbr_tiles_put; i++)
    {
        QList<int>* coord = this->game_scene->current_player_positions->at(i);
        int coord_x = coord->at(0); int coord_y = coord->at(1);
        this->game_scene->back_end_board_char->at(coord_y)->replace(coord_x,'-');
        this->game_scene->front_end_board->at(coord_y)->at(coord_x)->setPixmap(this->game_scene->previous_pixmap->at(i));
    }
    // re enable the buttons
    for (int j = 0; j < nbr_tiles_put; j++){
        this->currently_pushed_btns->at(j)->setEnabled(true);
    }
    this->game_scene->current_player_positions->clear();
    this->game_scene->previous_pixmap->clear();
    this->currently_pushed_btns->clear();
}

int game_4_widget:: same_x_y(int nbr_tiles_put)
{
    int flag_same_x = 1;
    int flag_same_y = 1;
    for (int i = 0; i < (nbr_tiles_put-1); i++)
    {
        QList<int>* coord_1 = this->game_scene->current_player_positions->at(i);
        QList<int>* coord_2 = this->game_scene->current_player_positions->at(i+1);
        int coord_1_x = coord_1->at(0); int coord_1_y = coord_1->at(1);
        int coord_2_x = coord_2->at(0); int coord_2_y = coord_2->at(1);
        if (coord_1_x != coord_2_x)
            flag_same_x = 0;
        if (coord_1_y != coord_2_y)
            flag_same_y = 0;
        if ((flag_same_x == 0) && (flag_same_y == 0))
            break;
    }
    if ((flag_same_x == 0) && (flag_same_y == 0))
        return -1;
    if (flag_same_x == 1)
        return 0;
    if (flag_same_y == 1)
        return 1;
    else
        return -1;
}

int game_4_widget:: no_empty_squares(int flag)
{
    if (flag == 0)
        return check_not_empty_vertical();
    else
        return check_not_empty_horizontal();
}

int game_4_widget:: check_not_empty_vertical()
{
    vector<int>* check_list  = new vector<int>();

    int nbr_tiles_put = this->game_scene->current_player_positions->size();
    for (int i = 0; i < nbr_tiles_put; i++)
    {
        QList<int>* coord = this->game_scene->current_player_positions->at(i);
        int coord_y = coord->at(1);
        check_list->push_back(coord_y);
    }

    sort(check_list->begin(), check_list->end());
    int coord_x = this->game_scene->current_player_positions->at(0)->at(0);
    int flag = 1;
    for (int i = check_list->at(0); i < check_list->at(check_list->size()-1); i++)
    {
        if (!(this->game_scene->back_end_board_char->at(i)->at(coord_x).isLetter() || this->game_scene->back_end_board_char->at(i)->at(coord_x) == '_'))
        {
            flag = -1;
            break;
        }
    }
    return flag;
}

int game_4_widget:: check_not_empty_horizontal(){
    // check if tiles are aligned on the board
    vector<int>* check_list  = new vector<int>();
    int nbr_tiles_put = this->game_scene->current_player_positions->size();

    for (int i = 0; i < nbr_tiles_put; i++)
    {
        QList<int>* coord = this->game_scene->current_player_positions->at(i);
        int coord_x = coord->at(0);
        check_list->push_back(coord_x);
    }

    sort(check_list->begin(), check_list->end());
    int coord_y = this->game_scene->current_player_positions->at(0)->at(1);
    int flag = 1;
    for (int i = check_list->at(0); i < check_list->at(check_list->size()-1); i++)
    {
        if (!(this->game_scene->back_end_board_char->at(coord_y)->at(i).isLetter()|| this->game_scene->back_end_board_char->at(coord_y)->at(i) == '_'))
        {
            flag = -1;
            break;
        }
    }
    return flag;
}

void game_4_widget:: build_word (int flag_direction, int starting, int ending, QString *str, int tile_index)
{
    QList<int>* coord = this->game_scene->current_player_positions->at(tile_index);
    int coord_x = coord->at(0);
    int coord_y = coord->at(1);
    if (flag_direction == 0)
    {
        for (int i = starting; i <= ending; i++)
        {
            str->append(this->game_scene->back_end_board_char->at(i)->at(coord_x));
        }
    }
    else
    {
        for (int i = starting; i <= ending; i++)
        {
            str->append(this->game_scene->back_end_board_char->at(coord_y)->at(i));
        }
    }
}

int game_4_widget:: compute_score (int flag_direction, int starting, int ending, int tile_index)
{
    int score = 0;
    QList<int>* coord = this->game_scene->current_player_positions->at(tile_index);
    int coord_x = coord->at(0); int coord_y = coord->at(1);
    if (flag_direction == 0)
    {
        int word_multp_3 = 0; int word_multp_2 = 0;
        for (int i = starting; i <= ending; i++)
        {
            int temp = (this->game_scene->back_end_board_score->at(i)->at(coord_x));
            int letter_score = get_letter_score(this->game_scene->back_end_board_char->at(i)->at(coord_x));

            if (temp == 1)
            {
                score += letter_score;
                this->game_scene->back_end_board_score->at(i)->replace(coord_x,1) ;

            }

            if (temp == 2 || temp == 3)
            {
                score += letter_score*temp;
                this->game_scene->back_end_board_score->at(i)->replace(coord_x,1) ;
            }

            if (temp == 4){
                score += letter_score;
                word_multp_2++;
                this->game_scene->back_end_board_score->at(i)->replace(coord_x,1) ;
            }
            if (temp == 5){
                score += letter_score;
                word_multp_3++;
                this->game_scene->back_end_board_score->at(i)->replace(coord_x,1) ;

            }
        }
        for (int m = 0; m < word_multp_2; m++)
            score *= 2;
        for (int n = 0; n < word_multp_3; n++)
            score *= 3;

        return score;
    }
    else
    {
        int word_multp_3 = 0; int word_multp_2 = 0; int score = 0;
        for (int i = starting; i <= ending; i++)
        {
            int temp = (this->game_scene->back_end_board_score->at(coord_y)->at(i));
            int letter_score = get_letter_score(this->game_scene->back_end_board_char->at(coord_y)->at(i));

            if (temp == 1)
            {
                score += letter_score;
                this->game_scene->back_end_board_score->at(coord_y)->replace(i,1);

            }

            if (temp == 2 || temp == 3)
            {
                score += letter_score*temp;
                this->game_scene->back_end_board_score->at(coord_y)->replace(i,1);
            }

            if (temp == 4){
                score += letter_score;
                word_multp_2++;
                this->game_scene->back_end_board_score->at(coord_y)->replace(i,1);

            }
            if (temp == 5){
                score += letter_score;
                word_multp_3++;
                this->game_scene->back_end_board_score->at(coord_y)->replace(i,1);
            }
        }
        for (int m = 0; m < word_multp_2; m++)
            score *= 2;
        for (int n = 0; n < word_multp_3; n++)
            score *= 3;
        return score;
    }
}

int game_4_widget:: check_star()
{
    int size_ = this->game_scene->current_player_positions->size();
    for (int i = 0; i < size_; i++)
    {
        int x = this->game_scene->current_player_positions->at(i)->at(0);
        int y = this->game_scene->current_player_positions->at(i)->at(1);
        if (x == y && x == 7){
            return 1;
        }
    }
    return -1;
}

int game_4_widget:: get_letter_score(QChar c){
    QString str;
    str.append("eaionrtlsu");
    int index = str.indexOf(c);
    if (index != -1)
        return 1;

    str.clear();
    str.append("_");
    index = str.indexOf(c);
    if (index != -1)
        return 0;

    str.clear();
    str .append("dg");
    index = str.indexOf(c);
    if (index != -1)
        return 2;

    str.clear();
    str .append("bcmp");
    index = str.indexOf(c);
    if (index != -1)
        return 3;

    str.clear();
    str.append("fhvwy");
    index = str.indexOf(c);
    if (index != -1)
        return 4;

    str.clear();
    str.append("k");
    index = str.indexOf(c);
    if (index != -1)
        return 5;

    str.clear();
    str.append("jx");
    index = str.indexOf(c);
    if (index != -1)
        return 8;

    str.clear();
    str.append("zq");
    index = str.indexOf(c);
    if (index != -1)
        return 10;

    return 0;
}

int game_4_widget:: check_word_correctness(QString str)
{
    // check if word contains blank element
    int flag = str.indexOf("_");
    if (flag == -1)
        return this->dict->indexOf(str);
    else
    {
        // check if only one blank
        int flag_2 = str.indexOf("_", flag);
        if (flag_2 == -1)
        {
            QString alpha = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < alpha.size(); i++)
            {
                str.replace(flag, 1, alpha.at(i));
                int correctness = this->dict->indexOf(str);
                if (correctness != -1)
                    return 1;
            }
        }
        else
        {
            // case two blank tiles
            QString alpha = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < alpha.size(); i++)
            {
                str.replace(flag, 1, alpha.at(i));
                for (int j = 0; j < alpha.size(); j++)
                {
                    str.replace(flag_2, 1, alpha.at(j));

                    int correctness = this->dict->indexOf(str);
                    if (correctness != -1)
                        return 1;
                }
            }
        }
    }
    return -1;
}

int game_4_widget :: find_starting_index(int flag_direction, int tile_index){
    if (flag_direction == 0)
    {
            QList<int>* coord = this->game_scene->current_player_positions->at(tile_index);
            int coord_x = coord->at(0);
            int coord_y = coord->at(1);
            int starting_y = coord_y;
            while(this->game_scene->back_end_board_char->at(starting_y)->at(coord_x) != '-')
            {
                starting_y -= 1;
                if (starting_y < 0)
                    break;
            }
            starting_y += 1;
            return starting_y;
    }
    else
    {
        QList<int>* coord = this->game_scene->current_player_positions->at(tile_index);
        int coord_x = coord->at(0); int coord_y = coord->at(1);
        int starting_x = coord_x;
        while(this->game_scene->back_end_board_char->at(coord_y)->at(starting_x) != '-')
        {
            starting_x -= 1;
            if (starting_x < 0)
                break;
        }
        starting_x += 1;
        return starting_x;
    }
}

int game_4_widget :: find_ending_index(int flag_direction, int tile_index)
{
    if (flag_direction == 0)
    {
        QList<int>* coord = this->game_scene->current_player_positions->at(tile_index);
        int coord_x = coord->at(0);
        int coord_y = coord->at(1);
        int ending_y = coord_y;
        while(this->game_scene->back_end_board_char->at(ending_y)->at(coord_x) != '-')
        {
            ending_y += 1;
            if (ending_y > 14)
                break;
        }
        ending_y -= 1;
        return ending_y;
    }

    else
    {
        QList<int>* coord = this->game_scene->current_player_positions->at(tile_index);
        int coord_x = coord->at(0);
        int coord_y = coord->at(1);
        int ending_x = coord_x;
        while(this->game_scene->back_end_board_char->at(coord_y)->at(ending_x) != '-')
        {
            ending_x += 1;
            if (ending_x > 14)
                break;
        }
        ending_x -= 1;
        return ending_x;
    }
}

int game_4_widget :: check_single_tile_neighbors()
{
    int coord_x = this->game_scene->current_player_positions->at(0)->at(0);
    int coord_y = this->game_scene->current_player_positions->at(0)->at(1);

    int up = this->game_scene->back_end_board_char->at(coord_y-1)->at(coord_x) == '-';
    int down = this->game_scene->back_end_board_char->at(coord_y+1)->at(coord_x) == '-';
    int right = this->game_scene->back_end_board_char->at(coord_y)->at(coord_x+1) == '-';
    int left = this->game_scene->back_end_board_char->at(coord_y)->at(coord_x-1) == '-';

    if ((up == 1) && (down == 1) && (right == 1) && (left == 1))
        return -1;
    return 1;
}

int game_4_widget :: check_all_tiles_words(int word_orientation, int *temp_score, QString* temp_str, int nbr_tiles_put)
{
    for (int i = 0; i < nbr_tiles_put; i++)
    {
        if (word_orientation == 0)
        {
            // check tile word horizontally
            int temp_start = find_starting_index(1, i);
            int temp_end = find_ending_index(1, i);
            if (temp_end != temp_start)
            {
                build_word(1, temp_start, temp_end, temp_str, i);
                int temp_correct_word = check_word_correctness(*temp_str);
                if (temp_correct_word == -1)
                {
                    temp_str->clear();
                    return -1;
                }
                *temp_score += compute_score(1, temp_start, temp_end, i);
                temp_str->clear();
            }
        }
        else
        {
            // check tile word vertically
            int temp_start = find_starting_index(0, i);
            int temp_end = find_ending_index(0, i);
            if (temp_end != temp_start)
            {
                build_word(0, temp_start, temp_end, temp_str, i);
                int temp_correct_word = check_word_correctness(*temp_str);
                if (temp_correct_word == -1)
                {
                    temp_str->clear();
                    return -1;
                }
                *temp_score += compute_score(0, temp_start, temp_end, i);
                temp_str->clear();
            }
        }
    }
    return 1;
}

void game_4_widget:: submit_btn_clicked()
{
    int nbr_tiles_put = this->game_scene->current_player_positions->size();
    int nbr_buttons_pushed = this->currently_pushed_btns->size();
    if (nbr_tiles_put != nbr_buttons_pushed)
        return;
    if (nbr_tiles_put != 1)
    {
        // make sure the tiles are aligned on the board
        int word_orientation  = same_x_y(nbr_tiles_put);
        if (word_orientation == -1)
        {

            bad_submission();
            return;
        }
        // make sure no empty squares between tiles on the board
        int empyt_squares_flag = no_empty_squares(word_orientation);
        if (empyt_squares_flag == -1)
        {

            bad_submission();
            return;
        }
        // look for starting and ending index of the word
        int starting = find_starting_index(word_orientation, 0);
        int ending = find_ending_index(word_orientation, 0);
        int nbr_letters = ending - starting + 1;

        // check if this is the first global move
        if (global_first_move == 0)
        {
            //means no existing letters were used
            if (nbr_letters <= nbr_tiles_put)
            {
                bad_submission();
                return;
            }
        }
        else
        {
            //case of first move in the whole game
            // check if it covers the star
            int star_flag = check_star();
            if (star_flag == -1)
            {

                bad_submission();
                return;
            }
        }

        // build word
        QString* str = new QString();
        build_word(word_orientation, starting, ending, str, 0);

        // check if word is in dictionary
        int correct_word = check_word_correctness(*str);
        if (correct_word == -1)
        {

            str->clear();
            bad_submission();
            return;
        }

        int score = compute_score(word_orientation, starting, ending, 0);

        // check that all tiles are part of correct words in the opposite orientation of word_orientation
        int temp_score = 0;
        QString *temp_str = new QString();
        int all_tiles_words_flag = check_all_tiles_words(word_orientation, &temp_score, temp_str, nbr_tiles_put);

        if (all_tiles_words_flag == -1)
        {

            temp_str->clear();
            bad_submission();
            return;
        }
        score += temp_score;

        // check for bingo
        if (nbr_tiles_put == 7)
            score+=50;

        submit_success(score, nbr_tiles_put);

        // check if game is over!
        int won_flag = check_player_won();
        if (won_flag == 1)
            game_over(1);
        else
        {
            // restore tiles to 7 on current player or less in case bag does not have as much
            fill_player_rack(this->current_player, nbr_tiles_put);
            next_player_turn();
        }
    }
    else
    {
        // check if it has neighbors
        int neighbors_flag = check_single_tile_neighbors();
        if (neighbors_flag == -1)
        {
            bad_submission();
            return;
        }
        int score = 0;
        // case where only 1 tile was added
        // check the words vertically and horizontally
        int score_1 = 0;
        int score_2 = 0;
        QString *temp_str = new QString();
        int all_tiles_words_flag_1 = check_all_tiles_words(0, &score_1, temp_str, nbr_tiles_put);
        temp_str->clear();
        int all_tiles_words_flag_2 = check_all_tiles_words(1, &score_2, temp_str, nbr_tiles_put);

        if (all_tiles_words_flag_1 == -1 || all_tiles_words_flag_2 == -1)
        {
            bad_submission();
            return;
        }
        score = score + score_1 + score_2;

        submit_success(score, 1);

        // check if game is over!
        int won_flag = check_player_won();
        if (won_flag == 1)
            game_over(1);
        else
        {
            // restore tiles to 7 on current player
            fill_player_rack(this->current_player, nbr_tiles_put);
            next_player_turn();
        }
    }
}

void game_4_widget:: submit_success(int score, int nbr_tiles_put)
{
    set_buttons(true);
    // change star flag // always not worth checking
    this->global_first_move = 0;

    // compute score add to player
    this->current_player->score += score;
    // update the label
    this->current_player->player_label->setText("Player ID: " + QString::number(this->current_player->id) + " Score: " + QString::number(this->current_player->score));
    // remove the letters used from the player's rack
    vector<int> *indices_to_remove = new vector<int>();
    for (int l=0; l < nbr_tiles_put; l++)
    {
        indices_to_remove->push_back(this->tiles_btn->indexOf(this->currently_pushed_btns->at(l)));
    }
    sort (indices_to_remove->begin(), indices_to_remove->end());
    for (int l = (indices_to_remove->size()-1); l > -1; l--)
    {
        this->current_player->player_rack->removeAt(indices_to_remove->at(l));
    }
    this->consecutive_pass_counter = 0;
}

void game_4_widget:: fill_player_rack(player *p, int nbr_lttrs)
{
    int bag_size = bag->size();
    int max = 0;
    if (bag_size >= nbr_lttrs)
        max = nbr_lttrs;
    else
        max = bag_size;

    for (int i = 0; i < max; i++)
    {
        // generate random number
        int random = qrand()%bag->size();;
        // draw random from bag
        QChar temp = bag->at(random);
        bag->removeAt(random);
        p->player_rack->append(temp);
    }
}

void game_4_widget:: game_over(int win_pass_flag)
{
    QList<int> winners_id;
    if (win_pass_flag == 1)
    {
        apply_penalty();

    }
    else
    {
        // look for player with highest score
        int temp_score = -1;
        for (int j = 0; j < this->list_of_players->size(); j++)
        {
            if (this->list_of_players->at(j)->score == temp_score)
            {
                winners_id.append(this->list_of_players->at(j)->id);

            }
            else
            {
                if (this->list_of_players->at(j)->score > temp_score)
                {
                    temp_score = this->list_of_players->at(j)->score;
                    winners_id.clear();
                    winners_id.append(this->list_of_players->at(j)->id);

                }
            }
        }
        emit score_toMain(this->list_of_players->at(0)->score,4);
    }

    // end game both cases: player won or 6 passes
    //messagebox
    QMessageBox* message_box = new QMessageBox();

    QPushButton* exit_btn = message_box->addButton("Exit",QMessageBox::YesRole);
    QPushButton* repeat_btn = message_box->addButton("Repeat",QMessageBox::YesRole);
    QString end_text;
    for (int k = 0; k < winners_id.size(); k++)
    {
        end_text.append("Winner is Player " + QString::number(winners_id.at(k))+"\n");
    }
    message_box->setText(end_text);
    message_box->exec();

    if(message_box->clickedButton() == exit_btn)
    {
        emit exit_4();
    }
    if(message_box->clickedButton() == repeat_btn)
    {
        emit repeat_4(this->list_of_players->size());
    }
}

int game_4_widget:: check_player_won()
{
    int bag_size = this->bag->size();
    if (bag_size == 0)
    {
        if (this->current_player->player_rack->size() == 0)
        {
            return 1;
        }
    }
    return -1;
}

void game_4_widget:: apply_penalty()
{
    int nbr_players = list_of_players->size();
    int total = 0;
    for (int i =0; i < nbr_players; i++)
    {
        player* p = this->list_of_players->at(i);
        if (p->id != this->current_player_id)
        {
            // loop over the rack
            int temp_rack_size = p->player_rack->size();
            int temp = 0;
            for (int j = 0; j < temp_rack_size; j++)
            {
                QChar temp_char = p->player_rack->at(j);
                temp += get_letter_score(temp_char);

            }
            // subtract from player's total
            p->score = p->score - temp;
            // update label
            p->player_label->setText("Player ID: " + QString::number(p->id) + " Score: " + QString::number(p->score));

            total += temp;
        }
    }
    this->current_player->score = this->current_player->score + total;
    this->current_player->player_label->setText("Player ID: " + QString::number(this->current_player->id) + " Score: " + QString::number(this->current_player->score));
}


