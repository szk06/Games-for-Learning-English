/**

*\file criminal.cpp
*\brief This class represents the criminal
*
contains the methods of the criminal such as move

*\author Sami & Mohammad Ali
*/

#ifndef CRIMINAL_H
#define CRIMINAL_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

class criminal : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit criminal(QObject *parent = 0);

    void ChangePosition(int x);

signals:

public slots:

};

#endif // CRIMINAL_H
