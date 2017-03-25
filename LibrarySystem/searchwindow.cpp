#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "QMessageBox"
#include "string"
#include "QFile"
#include "QDebug"
using namespace std;


/*Struct for containing the 5 separate parts of the book
struct book{
    QString title;
    QString author;
    QString isbn;
    QString totNum;
    QString inStock;
};*/
struct book;

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
    QString bookList = "booklist.txt";

    QString line = " ";
    QFile inputFile(bookList);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"read";
        QTextStream readIn(&inputFile);
        while (!readIn.atEnd())
        {
            QStringList pieces = line.split("|");
            line = readIn.readLine();
            book temp;
            temp.title = pieces.at(0);
            temp.author = pieces.at(1);
            temp.isbn = pieces.at(2);
            temp.totNum = pieces.at(3);
            temp.inStock = pieces.at(4);

            bookVector.push_back(temp);
        }
        inputFile.close();
    }
    //Check if search box is empty
    if(ui->txtSearch->text() == "")
    {
        QMessageBox errorMessage;
        errorMessage.setText("Please enter something to search.");
        errorMessage.exec();
    }



}
