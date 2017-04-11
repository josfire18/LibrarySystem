#include "loginpage.h"
#include "ui_loginpage.h"
#include <qstring.h>
#include <qDebug.h>
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
    //qDebug()<<"User: "<<uname<<" Pwd: "<< pwd;

    vector<QString> Users;
    vector<QString> pwds;
    vector<QString> mgrs;

    QString logins="login.txt";
    QString Credentials;
    QFile inputFile(logins);
    if (inputFile.open(QIODevice::ReadOnly)){
        //qDebug()<<"read";
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            Credentials = in.readLine();
            //qDebug() << Credentials;
            QStringList pieces = Credentials.split(" ");
            QString tempUsr= pieces.at(0);
            QString tempPwd= pieces.at(1);
            QString tempMgr= pieces.at(2);
            Users.push_back(tempUsr);
            pwds.push_back(tempPwd);
            mgrs.push_back(tempMgr);
        }
        inputFile.close();
    }
    bool isManager=false;
    for(int i=0;i<Users.size();i++){
        if(Users.at(i)==uname){
            if(pwds.at(i)==pwd){
                loginSuccessful=true;
                //qDebug()<<"Login Successful";
                if(mgrs.at(i).toInt()==2){
                    isManager=true;
                }
                break;
            }
            else{
                //qDebug()<<"Password Wrong";
            }
        }
    }
    //qDebug() << "Before successful Check";
    if(loginSuccessful){
       openMainMenu =  new EmployeeMainMenu();
       openMainMenu->setManager(isManager);
       openMainMenu->show();
       ui->Username->setText("Username");
       ui->Password->setText("Password");
       //qDebug() << "login closing...";
       this->close();
    }
    else{
        //qDebug()<<"Not the right user";
    }
}

void LoginPage::on_cmdCancel_clicked()
{
    this->close();
}


