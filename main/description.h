#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QWidget>
#include<QtGui>

class description : public QWidget
{
    Q_OBJECT
public:
    explicit description(QString s);
    QLabel *game_name;
    QTextEdit *game_desc;
    QVBoxLayout *Vlayout;
    void setVertical();

signals:
    
public slots:
    
};

#endif // DESCRIPTION_H
