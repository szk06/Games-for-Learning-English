/**
\file bow.cpp
\brief This class represent the bow that shoots
*
The class contains represents the bow and its movement

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef BOW_H
#define BOW_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "arrow.h"

class bow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit bow(QObject *parent = 0);
    void keyPressEvent(QKeyEvent* event);//!<keypress event handler
    QString target_color;//!<correct target color to hit
    int angle;//!<bow's angle

signals:
    void update_widget_score(bool correct);//!<signal sent to update score on game widget
public slots:
    void update_bow_score(bool);
    void update_bow_color(QString);
    
};

#endif // BOW_H
