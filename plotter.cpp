#include "plotter.h"


plotter::plotter(QString s, QList<int> mylist)
{
    customPlot = new QCustomPlot();
    game_name = new QLabel("Game name: "+s);
    sorry = new QLabel("Sorry there is no available history for this game");
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<mylist.size(); ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = mylist.at(i); // let's plot a quadratic function
    }

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("Played times");
    customPlot->yAxis->setLabel("Player Score");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(0, mylist.size());
    customPlot->yAxis->setRange(0, 100);
    customPlot->replot();
    QWidget *temp_lay  = dynamic_cast<QWidget *>(customPlot);
    Vlayout = new QVBoxLayout;
    //Vlayout->addWidget(game_name);
    if(mylist.size()!=0){
        Vlayout->addWidget(temp_lay);
    }
    else{
        Vlayout->addWidget(sorry);
    }


    setFixedSize(600,500);
    setLayout(Vlayout);


}
