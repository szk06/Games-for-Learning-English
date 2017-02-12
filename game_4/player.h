#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QtGui>

class player : public QObject
{
    Q_OBJECT
public:
    explicit player(int x, QObject *parent = 0);
    QList <QChar> *player_rack;
    int id;
    int score;
    QLabel *player_label;


signals:

public slots:

};
#endif // PLAYER_H
