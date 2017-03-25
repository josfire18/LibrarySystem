#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "QMessageBox"
#include "iostream"
#include "cstdlib"
#include "fstream"
#include "sstream"
#include "string"
using namespace std;


//Struct for containing the address in 5 separate parts
struct book{
    string title;
    string author;
    string isbn;
    string totNum;
    string inStock;
};

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
    string bookList = "booklist.txt";
    //Open file
    ifstream file;
    file.open(bookList.c_str());
    book arr[1010];

    //Find File Size
    int arrSize;
    arrSize = lineCount(bookList);

    if (file.is_open()) {
        cout << endl << "File Opened Sucessfully \n" << endl;
        string line;
        while (file.good())
        {
            for (int i = 1; i <= arrSize; i++) {
                getline(file, line, '|');
                arr[i].title = line;
                getline(file, line, '|');
                arr[i].author = line;
                getline(file, line, '|');
                arr[i].isbn = line;
                getline(file, line, '|');
                arr[i].totNum = line;
                getline(file, line);
                arr[i].inStock = line;
            }
        }

        file.close();
    //Check if search box is empty
    if(ui->txtSearch->text() == "")
    {
        QMessageBox errorMessage;
        errorMessage.setText("Please enter something to search.");
        errorMessage.exec();
    }



}
