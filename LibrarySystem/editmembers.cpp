#include "editmembers.h"
#include "ui_editmembers.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QLabel>
using namespace std;

EditMembers::EditMembers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditMembers)
{
    ui->setupUi(this);
    this->isManager=false;
}

EditMembers::~EditMembers()
{
    delete ui;
}

void EditMembers::setManager(bool manager)
{
    this->isManager=manager;
}

void EditMembers::on_cmdListMems_clicked()
{
    QString memberList = "Members.txt";

    QString line = " ";

    //Reading File
    if(memberVector.size() == 0)
    {
        QFile inputFile(memberList);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            qDebug()<<"read";
            QTextStream readIn(&inputFile);
            while (!readIn.atEnd())
            {
                line = readIn.readLine();
                QStringList pieces = line.split("|");
                qDebug() << pieces.length();
                member temp;
                temp.Name = pieces.at(0);
                temp.ID = pieces.at(1);
                temp.Address = pieces.at(2);
                temp.Phone = pieces.at(3);
                temp.Employee = pieces.at(4);
                temp.ISBN = pieces.at(5);
                temp.dateCheckedOut = pieces.at(6);

                memberVector.push_back(temp);
            }
            inputFile.close();
            qDebug() << "Test: Read successfully";
        }
    }

    //Display Members
    ui->scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *widget = new QWidget();
    ui->scrollArea->setWidget( widget );
    layout->setAlignment(Qt::AlignTop);
    widget->setLayout( layout );

    for(int i = 0; i < memberVector.size(); i++)
    {
        QHBoxLayout *hlayout=new QHBoxLayout();
        QLabel *Namelabel = new QLabel(memberVector.at(i).Name);
        QLabel *IDlabel = new QLabel(memberVector.at(i).ID);
        QLabel *AddressLabel = new QLabel(memberVector.at(i).Address);
        QLabel *PhoneLabel = new QLabel(memberVector.at(i).Phone);
        QLabel *EmployeeLabel = new QLabel(memberVector.at(i).Employee);
        QLabel *ISBNLabel = new QLabel(memberVector.at(i).ISBN);
        QLabel *dateCheckedOutLabel = new QLabel(memberVector.at(i).dateCheckedOut);
        if(memberVector.at(i).Employee == "1")



        //Tooltip for author and title, longer possible values
        Namelabel->setToolTip(memberVector.at(i).Name);
        Namelabel->setFixedWidth(100);
        IDlabel->setFixedWidth(70);
        AddressLabel->setFixedWidth(300);
        PhoneLabel->setFixedWidth(100);
        EmployeeLabel->setFixedWidth(10);
        ISBNLabel->setFixedWidth(80);
        dateCheckedOutLabel->setFixedWidth(50);
        AddressLabel->setToolTip(memberVector.at(i).Address);

        //Create Checkboxes
        QCheckBox *checkBox=new QCheckBox();
        checkBox->setFixedWidth(30);
        hlayout->addWidget(checkBox);

        if(memberVector.at(i).ISBN != "")
        {
            //Create Row
            hlayout->addWidget(Namelabel);
            hlayout->addWidget(IDlabel);
            hlayout->addWidget(AddressLabel);
            hlayout->addWidget(PhoneLabel);
            hlayout->addWidget(EmployeeLabel);
            hlayout->addWidget(ISBNLabel);
            hlayout->addWidget(dateCheckedOutLabel);
            layout->addLayout(hlayout);

        }

    }
}

void EditMembers::on_cmdUniqueMems_clicked()
{
    QString memberList = "Members.txt";

    QString line = " ";

    //Reading File
    if(memberVector.size() == 0)
    {
        QFile inputFile(memberList);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            qDebug()<<"read";
            QTextStream readIn(&inputFile);
            while (!readIn.atEnd())
            {
                line = readIn.readLine();
                QStringList pieces = line.split("|");
                qDebug() << pieces.length();
                member temp;
                temp.Name = pieces.at(0);
                temp.ID = pieces.at(1);
                temp.Address = pieces.at(2);
                temp.Phone = pieces.at(3);
                temp.Employee = pieces.at(4);
                temp.ISBN = pieces.at(5);
                temp.dateCheckedOut = pieces.at(6);

                memberVector.push_back(temp);
            }
            inputFile.close();
            qDebug() << "Test: Read successfully";
        }
    }

    //Display Members
    ui->scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *widget = new QWidget();
    ui->scrollArea->setWidget( widget );
    layout->setAlignment(Qt::AlignTop);
    widget->setLayout( layout );

    //Check for unique member ids
    vector<QString> uniqueID;

    for(int i = 0; i < memberVector.size(); i++)
    {
        QHBoxLayout *hlayout=new QHBoxLayout();
        QLabel *Namelabel = new QLabel(memberVector.at(i).Name);
        QLabel *IDlabel = new QLabel(memberVector.at(i).ID);
        QLabel *AddressLabel = new QLabel(memberVector.at(i).Address);
        QLabel *PhoneLabel = new QLabel(memberVector.at(i).Phone);
        QLabel *EmployeeLabel = new QLabel(memberVector.at(i).Employee);
        QLabel *ISBNLabel = new QLabel(memberVector.at(i).ISBN);
        QLabel *dateCheckedOutLabel = new QLabel(memberVector.at(i).dateCheckedOut);



        //Tooltip for author and title, longer possible values
        Namelabel->setToolTip(memberVector.at(i).Name);
        Namelabel->setFixedWidth(100);
        IDlabel->setFixedWidth(70);
        AddressLabel->setFixedWidth(300);
        PhoneLabel->setFixedWidth(100);
        EmployeeLabel->setFixedWidth(10);
        ISBNLabel->setFixedWidth(80);
        dateCheckedOutLabel->setFixedWidth(50);
        AddressLabel->setToolTip(memberVector.at(i).Address);

        //Create Checkboxes
        QCheckBox *checkBox=new QCheckBox();
        checkBox->setFixedWidth(30);
        hlayout->addWidget(checkBox);

        //Create Row
        bool exists = false;
        for(int j = 0; j < uniqueID.size(); j++)
        {
            if(uniqueID.at(j) == memberVector.at(i).ID)
            {
                exists = true;
            }
        }
        if(exists == false)
        {
            uniqueID.push_back(memberVector.at(i).ID);
            hlayout->addWidget(Namelabel);
            hlayout->addWidget(IDlabel);
            hlayout->addWidget(AddressLabel);
            hlayout->addWidget(PhoneLabel);
            hlayout->addWidget(EmployeeLabel);
            layout->addLayout(hlayout);
        }
    }
}
