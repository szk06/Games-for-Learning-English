#ifndef DASH_H
#define DASH_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class dash : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit dash(/*QObject *parent = 0*/int x);

signals:

public slots:

};

#endif // DASH_H
