#include "sign_in.h"
#include <QDebug>

sign_in::sign_in(QWidget *parent) :
    QWidget(parent)
{
    user_name = new QLineEdit();
    user_name->setPlaceholderText("Enter Username");
    password = new QLineEdit();
    password->setEchoMode(QLineEdit::Password);
    password->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    password->setPlaceholderText("Enter Password");

    submit = new QPushButton("Sign In");
    VLayout = new QVBoxLayout;
    connect(submit,SIGNAL(clicked()),this,SLOT(sign_clicked()));
    setvertical();
    setLayout(VLayout);

}
void sign_in::setvertical(){

    VLayout->addWidget(user_name);
    VLayout->addWidget(password);
    VLayout->addWidget(submit);
}
void sign_in::sign_clicked(){
    QString user = user_name->text();
    QString password_submitted = password->text();
    QFile inputFile("account/users.txt");

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QStringList sp = line.split('=');
          if(sp.at(0)==user){
              if(sp.at(1)==password_submitted){
                  emit signed_in(true,user);
                  this->close();
                  break;

              }

          }
       }
       cout<<"I am here"<<endl;
       inputFile.close();
    }



}
