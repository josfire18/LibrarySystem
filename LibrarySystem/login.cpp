#include "login.h"
#include "ui_login.h"
#include <qstring.h>
#include <qdebug.h>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    QString uname= ui->Username->text();
    QString pwd=ui->Password->text();
    qDebug()<<"User: "<<uname<<" Pwd: "<< pwd;
}

void Login::on_buttonBox_rejected()
{
    this->close();
}
