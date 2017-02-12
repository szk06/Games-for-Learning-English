/**
\file games_list_widget.cpp
\brief This class represent the panel where the user chooses which game he wants
to play
*
The class contains 4 buttons that correspond to each game, and this class inherits
from the QWidger. It aligns the buttons in a vertical layout

\author Sami Kanafani & Mohamad Ali Mahaidli

*/

#ifndef GAMES_LIST_WIDGET_H
#define GAMES_LIST_WIDGET_H

#include <QWidget>
#include <QtGui>

class games_list_widget : public QWidget
{
    Q_OBJECT
public:
    explicit games_list_widget(QWidget *parent = 0);

    QPushButton *game_1_btn;//!<button on the window
    QPushButton *game_2_btn;//!<button on the window
    QPushButton *game_3_btn;//!<button on the window
    QPushButton *game_4_btn;//!<button on the window

    QLabel *hello;//!<Label on the window

    QVBoxLayout *VLayout;//!<Vertical layout that aligns the elements

    void set_vertical_layout();
signals:

public slots:

};

#endif // GAMES_LIST_WIDGET_H
