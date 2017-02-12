/**
\file account_widget.cpp
\brief This class represent the panel where the user chooses either to login
or to signup
*
The class contains 2 buttons to sign in and sign up and it inherits from QWidget
and uses Vertical Layout

\author Sami Kanafani & Mohamad Ali Mahaidli

*/
#ifndef account_widget_H
#define account_widget_H

#include <QWidget>
#include <QtGui>


class account_widget : public QWidget
{
    Q_OBJECT
public:
    explicit account_widget(QWidget *parent = 0);

    QPushButton *signin;//!<button on the window
    QPushButton *signout;//!<button on the window
    QPushButton *signup;//!<button on the window

    bool signed_in;//!<flag to mark if user is signed in

    QVBoxLayout *VLayout;//!<vertical layout that aligns elmts in the window

    void set_vertical_layout();



signals:

public slots:

};

#endif // account_widget_H
