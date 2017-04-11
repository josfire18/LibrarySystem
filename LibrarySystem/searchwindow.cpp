#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "QMessageBox"
#include "string"
#include "QFile"
#include "QDebug"
#include <QDir>
#include <QCoreApplication>
#include <qscrollarea.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
using namespace std;
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
                temp.numWeeks= pieces.at(5);
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
        QString searchInput = ui->txtSearch->text();

        ui->scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
        QVBoxLayout *layout = new QVBoxLayout();
        QWidget *widget = new QWidget();
        ui->scrollArea->setWidget( widget );
        layout->setAlignment(Qt::AlignTop);
        widget->setLayout( layout );

        for(int i = 0; i < bookVector.size(); i++)
        {
            if(bookVector.at(i).title.contains(searchInput, Qt::CaseInsensitive))
            {
                QHBoxLayout *hlayout=new QHBoxLayout();
                QLabel *Titlelabel = new QLabel(bookVector.at(i).title);
                QLabel *AuthorLabel = new QLabel(bookVector.at(i).author);
                QLabel *ISBNLabel = new QLabel(bookVector.at(i).isbn);
                QLabel *TotAvailLabel = new QLabel(bookVector.at(i).totNum);
                QLabel *InStockLabel = new QLabel(bookVector.at(i).inStock);
                QLabel *NumWeeksLabel = new QLabel(bookVector.at(i).numWeeks);
                Titlelabel->setFixedWidth(200);

                //Tooltip for author and title, longer possible values
                Titlelabel->setFixedWidth(200);
                Titlelabel->setToolTip(bookVector.at(i).title);
                AuthorLabel->setFixedWidth(150);
                AuthorLabel->setToolTip(bookVector.at(i).author);
                ISBNLabel->setFixedWidth(140);
                TotAvailLabel->setFixedWidth(80);
                InStockLabel->setFixedWidth(80);
                NumWeeksLabel->setFixedWidth(40);

                //Create Checkboxes
                QCheckBox *checkBox=new QCheckBox();
                checkBox->setFixedWidth(30);
                hlayout->addWidget(checkBox);

                //Create Row
                hlayout->addWidget(Titlelabel);
                hlayout->addWidget(AuthorLabel);
                hlayout->addWidget(ISBNLabel);
                hlayout->addWidget(TotAvailLabel);
                hlayout->addWidget(InStockLabel);
                hlayout->addWidget(NumWeeksLabel);
                layout->addLayout(hlayout);
            }
        }
    }
}
