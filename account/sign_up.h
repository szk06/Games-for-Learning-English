#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QWidget>
#include <QtGui>
#include<QDebug>
class sign_up : public QWidget
{
    Q_OBJECT
public:
    explicit sign_up(QWidget *parent = 0);
    QLineEdit *user_name;
    QLineEdit *password;
    QPushButton *submit;
    QVBoxLayout *Vlayout;
    QLabel *error_msg;

    void setVertical();


signals:
    
public slots:
    void submit_request();
    
};

#endif // SIGN_UP_H
