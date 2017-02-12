#ifndef OVERALL_PLOTTER_H
#define OVERALL_PLOTTER_H

#include <QWidget>
#include"qcustomplot.h"
#include<QList>
#include<QtGui>
class overall_plotter : public QWidget
{
    Q_OBJECT
public:
    explicit overall_plotter(int x1,int x2,int x3, int x4);
    QCustomPlot *customPlot;
    QVBoxLayout *Vlayout;
signals:
    
public slots:
    
};

#endif // OVERALL_PLOTTER_H
