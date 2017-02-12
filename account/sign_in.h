#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QWidget>
#include<QtGui>
#include<QFile>
#include<iostream>
using namespace std;

class sign_in : public QWidget
{
    Q_OBJECT
public:
    explicit sign_in(QWidget *parent = 0);
    QLineEdit *user_name;
    QLineEdit *password;
    QPushButton *submit;
    QVBoxLayout *VLayout;
    void setvertical();
signals:
    void signed_in(bool x,QString s);
public slots:
    void sign_clicked();

};

#endif // SIGN_IN_H
