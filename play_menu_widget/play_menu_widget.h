/**
\file play_menu_widget.cpp
\brief This class represents the play menu
*
The class contains resume, new and instructions options of the selected game

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef PLAY_MENU_WIDGET_H
#define PLAY_MENU_WIDGET_H

#include <QWidget>
#include <QtGui>

class play_menu_widget : public QWidget
{
    Q_OBJECT
public:
    explicit play_menu_widget(QString name, QWidget *parent = 0);

    QLabel *hello;//!<Label on the Screen

    QPushButton *resume_btn;//!<button on the window
    QPushButton *new_btn;//!<button on the window
    QPushButton *instructions_btn;//!<button on the window

    QVBoxLayout *VLayout;//!<Vertical layout where elements are stored

    QString name_of_game;//<!holds the name of the current game
    void set_vertical_layout();
signals:

public slots:
};


#endif // PLAY_MENU_WIDGET_H
