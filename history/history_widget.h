/**
\file history_widget.cpp
\brief This class represents the history of the user
*
The class contains the results of the current user for different games (not implemented yet)

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef HISTORY_WIDGET_H
#define HISTORY_WIDGET_H

#include <QWidget>
#include <QtGui>
class history_widget : public QWidget
{
    Q_OBJECT
public:
    explicit history_widget(QWidget *parent = 0);

    QLabel *hello;//!<label on the window

    QPushButton *game1;//!<button on the window
    QPushButton *game2;//!<button on the window
    QPushButton *game3;//!<button on the window
    QPushButton *game4;//!<button on the window
    QPushButton *overall;//!<button for the overall statistics
    QVBoxLayout *VLayout;//!<Vertical layout where elements are aligned

    void set_vertical_layout();
signals:

public slots:

};

#endif // HISTORY_WIDGET_H
