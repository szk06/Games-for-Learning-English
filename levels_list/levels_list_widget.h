/**
\file levels_list_widget.cpp
\brief This class represents the list of levels
*
The class contains different buttons to select the difficulty level of the game

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef LEVELS_LIST_WIDGET_H
#define LEVELS_LIST_WIDGET_H

#include <QWidget>
#include <QtGui>
class levels_list_widget : public QWidget
{
    Q_OBJECT
public:
    explicit levels_list_widget(QWidget *parent = 0);
    QPushButton *level_1_btn;//!<button on the window
    QPushButton *level_2_btn;//!<button on the window
    QPushButton *level_3_btn;//!<button on the window

    QLabel *hello;//!<Label on the window

    QVBoxLayout *VLayout;//!<Vertical layout that aligns the elements

    void set_vertical_layout();
signals:
    
public slots:
    
};

#endif // LEVELS_LIST_WIDGET_H
