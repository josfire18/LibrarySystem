#include "authorizedwindow.h"
#include "ui_authorizedwindow.h"
#include "QMessageBox"
#include "string"
#include "QFile"
#include "QDebug"
#include <QDir>
#include <QCoreApplication>
#include <qscrollarea.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
using namespace std;

//Struct for book parts
struct book;

AuthorizedWindow::AuthorizedWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorizedWindow)
{
    ui->setupUi(this);
}

AuthorizedWindow::~AuthorizedWindow()
{
    delete ui;
}

QString AuthorizedWindow::concatenate(int lineNum)
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

void AuthorizedWindow::on_btnSearch_clicked()
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
                line = readIn.readLine();
                book temp;
                temp.title = pieces.at(0);
                temp.author = pieces.at(1);
                temp.isbn = pieces.at(2);
                temp.totNum = pieces.at(3);
                temp.inStock = pieces.at(4);
                temp.isSelected=false;
                temp.checkBox=NULL;
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
                Titlelabel->setFixedWidth(200);

                //Tooltip for author and title, longer possible values
                Titlelabel->setToolTip(bookVector.at(i).title);
                AuthorLabel->setFixedWidth(150);
                AuthorLabel->setToolTip(bookVector.at(i).author);
<<<<<<< HEAD

                //Create Checkboxes
                QCheckBox *checkBox=new QCheckBox();
                checkBox->setFixedWidth(30);
                hlayout->addWidget(checkBox);

                //Create Row
=======
                QCheckBox *TempcheckBox=new QCheckBox();
                connect(TempcheckBox,SIGNAL(clicked(bool)),this,SLOT(on_Box_Checked()));
                TempcheckBox->setFixedWidth(30);
                bookVector.at(i).checkBox=TempcheckBox;
                hlayout->addWidget(TempcheckBox);
>>>>>>> Sam_Branch
                hlayout->addWidget(Titlelabel);
                hlayout->addWidget(AuthorLabel);
                hlayout->addWidget(ISBNLabel);
                hlayout->addWidget(TotAvailLabel);
                hlayout->addWidget(InStockLabel);
                layout->addLayout(hlayout);
            }
        }
    }
}

void AuthorizedWindow::on_Checkout_Button_clicked()
{
    for(int i = 0; i < bookVector.size(); i++){
        if(bookVector.at(i).isSelected){
            qDebug()<<"Selected"<<i;
        }
        else{

        }
    }
}

void AuthorizedWindow::on_Add_Button_clicked()
{

}

void AuthorizedWindow::on_Delete_Button_clicked()
{
    int selected=0;
    for(int i = 0; i < bookVector.size(); i++){
        if(bookVector.at(i).isSelected){
            selected++;
        }
    }
    if(0==selected){
        //Nothing Selected
        QMessageBox *warning = new QMessageBox();
        warning->setText("Nothing Selected");
        warning->show();
    }
    else{
        //Warn before delete
        QMessageBox *DeleteBox = new QMessageBox();
        QString message="Are You Sure You Wish To Delete These ";
        message.append(QString::number(selected));
        message.append(" Entries?");
        DeleteBox->setText(message);
        DeleteBox->addButton(QString("Confirm") , QMessageBox::AcceptRole);
        DeleteBox->addButton(QString("Cancel") , QMessageBox::RejectRole);
        DeleteBox->show();
        if(DeleteBox->exec() == QMessageBox::RejectRole){
            DeleteBox->close();
        }//Cancel
        else {
            for(int i = 0; i < bookVector.size(); i++){
                if(bookVector.at(i).isSelected){
                    bookVector.erase(bookVector.begin() + i);
                }
            }
        }//Confirm
    }
}

void AuthorizedWindow::on_Box_Checked()
{
    qDebug()<<"Selected"<<QObject::sender();
    for(int i = 0; i < bookVector.size(); i++){
        if(bookVector.at(i).checkBox==QObject::sender()){
            bookVector.at(i).isSelected=bookVector.at(i).checkBox->isChecked();
        }
    }
}
