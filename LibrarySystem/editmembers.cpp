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
}

EditMembers::~EditMembers()
{
    delete ui;
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
                temp.Address = pieces.at(1);
                temp.Phone = pieces.at(2);
                temp.Employee = pieces.at(3);
                temp.ISBN = pieces.at(4);
                temp.dateCheckedOut = pieces.at(5);

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
        QLabel *AddressLabel = new QLabel(memberVector.at(i).Address);
        QLabel *PhoneLabel = new QLabel(memberVector.at(i).Phone);
        QLabel *EmployeeLabel = new QLabel(memberVector.at(i).Employee);
        QLabel *ISBNLabel = new QLabel(memberVector.at(i).ISBN);
        QLabel *dateCheckedOutLabel = new QLabel(memberVector.at(i).dateCheckedOut);



        //Tooltip for author and title, longer possible values
        Namelabel->setToolTip(memberVector.at(i).Name);
        Namelabel->setFixedWidth(100);
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
        hlayout->addWidget(Namelabel);
        hlayout->addWidget(AddressLabel);
        hlayout->addWidget(PhoneLabel);
        hlayout->addWidget(EmployeeLabel);
        hlayout->addWidget(ISBNLabel);
        hlayout->addWidget(dateCheckedOutLabel);
        layout->addLayout(hlayout);


    }
}
