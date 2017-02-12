/**
*\file plotter.cpp
*\brief this class represents the graph of the user's history, it takes the number of the game as an argument
*/

#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include"qcustomplot.h"
#include<QList>
#include<QtGui>
class plotter : public QWidget
{
    Q_OBJECT
public:
    explicit plotter(QString s, QList<int> mylist);

    QCustomPlot *customPlot;
    QLabel *game_name;
    QVBoxLayout *Vlayout;
    QLabel *sorry;


signals:
    
public slots:
    
};

#endif // PLOTTER_H
