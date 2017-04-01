#include "loginpage.h"
#include "ui_loginpage.h"
#include <qstring.h>
#include <qdebug.h>
#include <vector>
#include <qfile.h>
#include <QDir>
#include <QCoreApplication>
#include "authorizedwindow.h"

using namespace std;

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    loginSuccessful=false;
    ui->cmdMember->hide();
    ui->cmdSearch->hide();
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_cmdLogin_clicked()
{

#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
    ui->Username->focusWidget();
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
       ui->cmdMember->show();
       ui->cmdSearch->show();
    }
    else{
        qDebug()<<"Not the right user";
    }
}

void LoginPage::on_cmdSearch_clicked()
{
    if(loginSuccessful){
        openAuthorizedWindow = new AuthorizedWindow();
        openAuthorizedWindow->show();
    }
}

void LoginPage::on_cmdMember_clicked()
{
    if(loginSuccessful){
        openEditMembers = new EditMembers();
        openEditMembers->show();
    }
    else{
        qDebug()<<"Not the right user";
    }
}

void LoginPage::on_cmdCancel_clicked()
{
    this->close();
}


