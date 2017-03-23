#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "QMessageBox"

SearchWindow::SearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_btnSearch_clicked()
{
    //Check if search box is empty
    if(ui->txtSearch->text() == "")
    {
        QMessageBox errorMessage;
        errorMessage.setText("Please enter something to search.");
        errorMessage.exec();
    }

}
