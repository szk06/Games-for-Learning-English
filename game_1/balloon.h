/**
\file balloon.cpp
\brief This class represent the balloons
*
The class contains represents the bolloon and its movement

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef BALLOON_H
#define BALLOON_H

#include <QObject>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class balloon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit balloon(int level, QString color, QObject *parent = 0);

    int game_level;//!<level of difficulty
    QString balloon_color;//!<balloon color

    QTimer *balloon_timer;//!<timer to update balloon position

    void fly();
signals:
    
public slots:
    void update();

};

#endif // BALLOON_H
