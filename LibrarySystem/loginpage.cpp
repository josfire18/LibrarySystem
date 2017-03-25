#include "loginpage.h"
#include "ui_loginpage.h"
#include <qstring.h>
#include <qdebug.h>
#include <vector>
#include <qfile.h>
#include <QDir>
#include <QCoreApplication>
using namespace std;

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    loginSuccessful=false;
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_CancelButton_clicked()
{
        this->close();
}

void LoginPage::on_LoginButton_clicked()
{

#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif

    QString uname= ui->Username->text();
    QString pwd=ui->Password->text();
    qDebug()<<"User: "<<uname<<" Pwd: "<< pwd;

    vector<QString> Users;
    vector<QString> pwds;

    QString logins="login.txt";
    QString Credentials;
    QFile inputFile(logins);
    if (inputFile.open(QIODevice::ReadOnly)){
        qDebug()<<"read";
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            Credentials = in.readLine();
            QString tempUsr= Credentials.split(" ").first();
            QString tempPwd= Credentials.split(" ").last();
            Users.push_back(tempUsr);
            pwds.push_back(tempPwd);
        }
        inputFile.close();
    }
    for(int i=0;i<Users.size();i++){
        if(Users.at(i)==uname){
            if(pwds.at(i)==pwd){
                loginSuccessful=true;
                qDebug()<<"Login Successful";
                break;
            }
            else{
                qDebug()<<"Password Wrong";
            }
        }
    }
    if(loginSuccessful){
        this->close();
    }
    else{
        qDebug()<<"Not the right user";
    }
}
