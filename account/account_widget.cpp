/**
\file account_widget.cpp
\brief This class represent the panel where the user chooses either to login
or to signup
*
The class contains 2 buttons to sign in and sign up and it inherits from QWidget
and uses Vertical Layout

\author Sami Kanafani & Mohamad Ali Mahaidli

*/

#include "account_widget.h"

/**
\brief Constructor of the account_widget class
\param parent of type QWidget

*
In this function, all the buttons of the myacccount class are created,and the setLayout function is called

*/

account_widget::account_widget(QWidget *parent) :
    QWidget(parent)
{
    signed_in = false;

    signin = new QPushButton("Sign in");

    signout = new QPushButton("Sign Out");
    signout->setEnabled(false);

    signup =  new QPushButton("Sign Up");

    VLayout = new QVBoxLayout;
    set_vertical_layout();
    setLayout(VLayout);

}

/**
\brief sets vertical layout
*
in this function, the buttons and the elements
of the class are added to the vertical layout

*/
void account_widget::set_vertical_layout(){
    VLayout->addWidget(signin);
    VLayout->addWidget(signout);
    VLayout->addWidget(signup);
}
