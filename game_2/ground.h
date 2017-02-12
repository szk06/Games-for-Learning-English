#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class ground : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit ground(/*QObject *parent = 0*/int x);

signals:

public slots:

};

#endif // GROUND_H
