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
#include <QInputDialog>
#include <QDate>
using namespace std;

//Struct for book parts
struct book;

AuthorizedWindow::AuthorizedWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorizedWindow)
{
    ui->setupUi(this);
    ui->NewBook_Title->hide();
    ui->NewBook_Author->hide();
    ui->NewBook_ISBN->hide();
    ui->NewBook_Quantity->hide();
    ui->NewBook_Confirm->hide();
    ui->NewBook_Cancel->hide();
}

AuthorizedWindow::~AuthorizedWindow()
{
    delete ui;
}

QString AuthorizedWindow::concatenate(int lineNum)
{
    QString line = "";
    line = bookVector.at(lineNum).title;
    line.append("|");
    line.append(bookVector.at(lineNum).author);
    line.append("|");
    line.append(bookVector.at(lineNum).isbn);
    line.append("|");
    line.append(bookVector.at(lineNum).totNum);
    line.append("|");
    line.append(bookVector.at(lineNum).inStock);
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
                Titlelabel->setFixedWidth(200);

                //Tooltip for author and title, longer possible values
                Titlelabel->setToolTip(bookVector.at(i).title);
                AuthorLabel->setFixedWidth(150);
                AuthorLabel->setToolTip(bookVector.at(i).author);
                //Create Checkboxes

                QCheckBox *TempcheckBox=new QCheckBox();
                connect(TempcheckBox,SIGNAL(clicked(bool)),this,SLOT(on_Box_Checked()));
                TempcheckBox->setFixedWidth(30);
                bookVector.at(i).checkBox=TempcheckBox;

                hlayout->addWidget(TempcheckBox);
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
    QString bookList = "Members.txt";
    //Reading File

    bool dialogResult;
    QInputDialog *input = new QInputDialog();
    QString card = input->getText(0, "Rename Label", "New name:", QLineEdit::Normal, "Card Number", &dialogResult);
    input->show();
    qDebug()<<"Card: "<<card;
    if((card.toInt()>9999)&&(card.toInt()<100000)){

        int newCheckouts=0;
        for(int i = 0; i < bookVector.size(); i++){
            if(bookVector.at(i).isSelected){
                newCheckouts++;
                qDebug()<<"Selected"<<i;
            }
        }
        if(newCheckouts==0){
            //break;
        }

        vector<QString>users;
        QString line;
        QString cardNum="";
        QFile inputFile(bookList);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            qDebug()<<"read";
            QTextStream readIn(&inputFile);
            while (!readIn.atEnd())
            {
                line = readIn.readLine();
                users.push_back(line);
                qDebug()<<line;
            }
            inputFile.close();
            int CurrentCheckouts=-1;
            int userIndex=-1;
            for(int i=0;i<users.size();i++){
                QStringList pieces = users.at(i).split("|");
                if(pieces.at(1).toInt()==card.toInt()){
                    qDebug()<<i;
                    cardNum = pieces.at(1);
                    CurrentCheckouts++;
                    if(userIndex==-1){
                        userIndex=i;
                    }
                }
            }
            qDebug() << "Test: Read successfully";
            if(cardNum==""){
                QMessageBox *WarnBox = new QMessageBox();
                QString message="Please Enter a Valid Card Number";
                WarnBox->setText(message);
                WarnBox->show();
            }
            else{
                QStringList pieces = users.at(userIndex).split("|");
                int maxCheckouts=6;
                if(pieces.at(4)=="1"){
                    maxCheckouts=12;
                }
                if((CurrentCheckouts+newCheckouts)<(maxCheckouts)){
                    for(int i = 0; i < bookVector.size(); i++){
                        if(bookVector.at(i).isSelected){
                            QString temp=pieces.at(0);
                            temp.append("|");
                            temp.append(pieces.at(1));
                            temp.append("|");
                            temp.append(pieces.at(2));
                            temp.append("|");
                            temp.append(pieces.at(3));
                            temp.append("|");
                            temp.append(pieces.at(4));
                            temp.append("|");
                            temp.append(bookVector.at(i).isbn);
                            temp.append(";");
                            QDate *date=new QDate();
                            temp.append(date->currentDate().addDays(28).toString("MM-dd-yyyy"));
                            users.push_back(temp);
                            qDebug()<<users.at(userIndex);
                        }
                    }
                    QString file = "Members.txt";
                    QFile outputFile(file);
                    outputFile.resize(0);
                    if (outputFile.open(QIODevice::ReadWrite)){
                        QTextStream stream( &outputFile );
                        for(int i=0;i<users.size();i++){
                            stream << users.at(i) << endl;
                        }
                        outputFile.close();
                        qDebug() << "Test: write successfully";
                    }
                }
                else{
                    QMessageBox *WarnBox = new QMessageBox();
                    QString message="User Has Exceeded Maximum Checkout Number";
                    WarnBox->setText(message);
                    WarnBox->show();
                }
            }
        }

    }
    else{
        QMessageBox *WarnBox = new QMessageBox();
        QString message="Please Enter a Valid Card Number";
        WarnBox->setText(message);
        WarnBox->addButton(QString("OK") , QMessageBox::AcceptRole);
        WarnBox->show();
    }
}

void AuthorizedWindow::on_Add_Button_clicked()
{
    ui->NewBook_Title->show();
    ui->NewBook_Author->show();
    ui->NewBook_ISBN->show();
    ui->NewBook_Quantity->show();
    ui->NewBook_Confirm->show();
    ui->NewBook_Cancel->show();
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
                    if(bookVector.at(i).inStock.toInt()>=1){
                        bookVector.at(i).totNum=QString::number(bookVector.at(i).totNum.toInt()-1);
                        bookVector.at(i).inStock=QString::number(bookVector.at(i).inStock.toInt()-1);
                    }
                    else if((bookVector.at(i).inStock.toInt()==1)&&(bookVector.at(i).totNum.toInt()==1)){
                        bookVector.erase(bookVector.begin() + i);
                    }
                }
            }
        }//Confirm
        this->writeToFile();
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

void AuthorizedWindow::on_NewBook_Confirm_clicked()
{
    if((ui->NewBook_Quantity->displayText().toInt()>0)){
        book temp;
        temp.title=ui->NewBook_Title->displayText();
        temp.author = ui->NewBook_Author->displayText();
        temp.isbn = ui->NewBook_ISBN->displayText();
        temp.totNum = ui->NewBook_Quantity->displayText();
        temp.inStock = ui->NewBook_Quantity->displayText();
        temp.isSelected=false;
        temp.checkBox=NULL;
        bookVector.push_back(temp);
        ui->NewBook_Title->setText("Title");
        ui->NewBook_Author->setText("Author");
        ui->NewBook_ISBN->setText("ISBN");
        ui->NewBook_Quantity->setText("Quantity");
        this->writeToFile();
    }
    else{
        QMessageBox *WarnBox = new QMessageBox();
        QString message="Please Enter a Valid Quantity";
        WarnBox->setText(message);
        WarnBox->addButton(QString("OK") , QMessageBox::AcceptRole);
        WarnBox->show();
    }
}

void AuthorizedWindow::on_NewBook_Cancel_clicked()
{
    ui->NewBook_Title->setText("Title");
    ui->NewBook_Author->setText("Author");
    ui->NewBook_ISBN->setText("ISBN");
    ui->NewBook_Quantity->setText("Quantity");
    ui->NewBook_Confirm->hide();
    ui->NewBook_Cancel->hide();
    ui->NewBook_Title->hide();
    ui->NewBook_Author->hide();
    ui->NewBook_ISBN->hide();
    ui->NewBook_Quantity->hide();
}

void AuthorizedWindow::writeToFile()
{
    QString bookList = "booklist.txt";
    QFile outputFile(bookList);
    outputFile.resize(0);
    if (outputFile.open(QIODevice::ReadWrite)){
        QTextStream stream( &outputFile );
        for(int i=0;i<bookVector.size();i++){
            QString line=concatenate(i);
            stream << line << endl;
        }
        outputFile.close();
        qDebug() << "Test: write successfully";
    }
}


void AuthorizedWindow::on_NewBook_ISBN_cursorPositionChanged(int arg1, int arg2)
{
    if(ui->NewBook_ISBN->inputMask()==""){
        ui->NewBook_ISBN->setInputMask("999999999-9");
        ui->NewBook_ISBN->setCursorPosition(0);
    }
}
