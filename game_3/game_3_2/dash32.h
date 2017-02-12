#ifndef DASH32_H
#define DASH32_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class dash32 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit dash32(/*QObject *parent = 0*/int x);

signals:

public slots:

};

#endif // DASH_H
