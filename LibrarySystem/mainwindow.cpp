#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Search=NULL;
    login=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete login;
    delete Search;
}

void MainWindow::on_Search_clicked()
{
    if(Search!=NULL){
        delete Search;
    }
    Search = new SearchWindow();
    Search->show();
}

void MainWindow::on_Login_clicked()
{
    if(login!=NULL){
        delete login;
    }
    login = new LoginPage();
    login->show();
}
