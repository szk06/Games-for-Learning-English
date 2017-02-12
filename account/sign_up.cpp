#include "sign_up.h"
#include<iostream>
#include<fstream>
#include<string>
#include<QDebug>
using namespace std;
sign_up::sign_up(QWidget *parent) :
    QWidget(parent)
{
    password = new QLineEdit();
    password->setEchoMode(QLineEdit::Password);
    password->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    password->setPlaceholderText("Enter Password");
    user_name = new QLineEdit();
    user_name->setPlaceholderText("Enter Username");
    error_msg = new QLabel();
    submit = new QPushButton("Register");
    Vlayout = new QVBoxLayout;
    setVertical();
    setLayout(Vlayout);
    connect(submit,SIGNAL(clicked()),this,SLOT(submit_request()));
}
void sign_up::setVertical(){
    Vlayout->addWidget(user_name);
    Vlayout->addWidget(password);
    Vlayout->addWidget(error_msg);
    Vlayout->addWidget(submit);
}
void sign_up::submit_request(){
    QString user = user_name->text();
    QString password_submitted = password->text();
    QFile inputFile("account/users.txt");
    QString all_text="";
    bool found = false;
    error_msg->setText("");

    if (inputFile.open(QIODevice::ReadWrite))
    {
       QTextStream in(&inputFile);

       while (!in.atEnd())
       {
          QString line = in.readLine();
          all_text = all_text+line+"\n";
          QStringList sp = line.split('=');
          if(sp.at(0)==user){
             error_msg->setText("Error, user_name already available");
             found = true;

          }
       }

    }
    qDebug()<<"All text:"<<all_text;
    QTextStream stream( &inputFile );
    if(found==false && user.size()>3 && password_submitted.size()>3){
        all_text = user+"="+password_submitted;
        stream<<all_text<<endl;
        QString file_name = "account/"+user+".txt";
        QFile file;
        file.setFileName(file_name);//file_name is the QString, which I get as aparameter
        file.open(QIODevice::ReadWrite | QIODevice::Text);



        file.close();



    }
    inputFile.close();
    if(found!=true){
        this->close();
    }



}
