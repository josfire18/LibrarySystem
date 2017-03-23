#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete login;
    delete Search;
}

void MainWindow::on_Search_clicked()
{
    Search = new SearchWindow(this);
    Search->show();
}

void MainWindow::on_Login_clicked()
{
    login = new Login(this);
    login->show();
}
