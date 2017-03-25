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

QString SearchWindow::concatenate(int lineNum)
{
    QString line = "";
    line = bookVector.at(lineNum).title;
    line.append(", ");
    line.append(bookVector.at(lineNum).author);
    line.append(", ");
    line.append(bookVector.at(lineNum).isbn);
    line.append(", ");
    line.append(bookVector.at(lineNum).totNum);
    line.append(" | ");
    line.append(bookVector.at(lineNum).inStock);
    line.append(" | ");
    line.append("\n");
    return line;
}

void SearchWindow::on_btnSearch_clicked()
{
#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif
    QString bookList = "booklist.txt";

    QString line = " ";

    //Reading File
    if(bookVector.size() == 0)
    {
        QFile inputFile(bookList);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            qDebug()<<"read";
            QTextStream readIn(&inputFile);
            while (!readIn.atEnd())
            {
                line = readIn.readLine();
                QStringList pieces = line.split("|");
                qDebug() << pieces.length();
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
            qDebug() << "Test: Read successfully";
        }
    }

    //Check if search box is empty
    if(ui->txtSearch->text() == "")
    {
        QMessageBox errorMessage;
        errorMessage.setText("Please enter something to search.");
        errorMessage.exec();
    }
    else
    {
        QString results = "";
        QString searchInput = ui->txtSearch->text();
        for(int i = 0; i < bookVector.size(); i++)
        {
            if(bookVector.at(i).title.contains(searchInput, Qt::CaseInsensitive))
            {
                results.append(concatenate(i));
                results.append("\n");
            }
        }
        ui->txtSearchResults->setText(results);

    }



}
