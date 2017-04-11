#include "editmembers.h"
#include "ui_editmembers.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QDir>
#include <QCoreApplication>
#include <qscrollarea.h>
#include <QInputDialog>
#include <QDate>

using namespace std;

EditMembers::EditMembers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditMembers)
{
    ui->setupUi(this);
    ui->lblCheckoutDueDate->hide();
    ui->lblCheckoutID->hide();
    ui->lblCheckoutISBN->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->cmdReturn->hide();
    ui->cmdEditMem->hide();
    ui->txtPassword->hide();
    ui->lblPassword->hide();

    qDebug() << "Mid Editmem Constructor";
    //edit members buttons - hide by default
    ui->txtName->hide();
    ui->txtID->hide();
    ui->txtAddress->hide();
    ui->txtPhone->hide();
    ui->txtEmployee->hide();
    ui->cmdConfirm->hide();
    ui->cmdCancelEdit->hide();
    ui->cmdDelete->hide();

    this->isManager=false;
    qDebug() << "End editmem constructor";
}

EditMembers::~EditMembers()
{
    delete ui;
}

QString EditMembers::concatenate(int lineNum)
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
    line.append("|");
    line.append(bookVector.at(lineNum).numWeeks);
    return line;
}

void EditMembers::setManager(bool manager)
{
    this->isManager=manager;
    if(isManager == true)
    {
        ui->cmdEditMem->show();
    }
}

void EditMembers::on_cmdListMems_clicked()
{
    QString checkoutList = "Checkouts.txt";

    QString line = " ";

    //Hide Unique Mem Labels/Show Checkout items
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();

    ui->lblCheckoutDueDate->show();
    ui->lblCheckoutID->show();
    ui->lblCheckoutISBN->show();
    ui->cmdReturn->show();


    //Reading File
    if(checkoutVector.size() == 0)
    {
        QFile inputFile(checkoutList);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            qDebug()<<"read file";
            QTextStream readIn(&inputFile);
            while (!readIn.atEnd())
            {
                line = readIn.readLine();
                QStringList pieces = line.split("|");
                //qDebug() << pieces.length();
                member temp;
                temp.ID = pieces.at(0);
                temp.ISBN = pieces.at(1);
                temp.dueDate = pieces.at(2);
                temp.checked=false;
                checkoutVector.push_back(temp);
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

    for(int i = 0; i < checkoutVector.size(); i++)
    {
        QHBoxLayout *hlayout=new QHBoxLayout();
        QLabel *IDlabel = new QLabel(checkoutVector.at(i).ID);
        QLabel *ISBNLabel = new QLabel(checkoutVector.at(i).ISBN);
        QLabel *dueDateLabel = new QLabel(checkoutVector.at(i).dueDate);

        //set widths of layouts
        IDlabel->setFixedWidth(150);
        ISBNLabel->setFixedWidth(100);
        dueDateLabel->setFixedWidth(60);
        QDate date;
        qDebug()<<"date"<<date.fromString(checkoutVector.at(i).dueDate,"MM-dd-yyyy");
        if(date.currentDate().operator >(date.fromString(checkoutVector.at(i).dueDate,"MM-dd-yyyy"))){
            dueDateLabel->setStyleSheet("QLabel {background-color:red}");
        }

        //Create Checkboxes
        QCheckBox *checkBox=new QCheckBox();
        connect(checkBox,SIGNAL(clicked(bool)),this,SLOT(on_Box_Checked()));
        checkBox->setFixedWidth(30);
        hlayout->addWidget(checkBox);
        checkoutVector.at(i).checkBox=checkBox;

        if(checkoutVector.at(i).ID != "")
        {
            //Create Row
            hlayout->addWidget(IDlabel);
            hlayout->addWidget(ISBNLabel);
            hlayout->addWidget(dueDateLabel);;
            layout->addLayout(hlayout);
        }

    }
}

void EditMembers::on_cmdUniqueMems_clicked()
{
    QString memberList = "Members.txt";

    QString line = " ";

    //Hide Unique Mem Labels/Show Checkout items
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();

    ui->lblCheckoutDueDate->hide();
    ui->lblCheckoutID->hide();
    ui->lblCheckoutISBN->hide();
    ui->cmdReturn->hide();

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
                temp.checked = false;
                temp.checkBox = NULL;
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


        //Tooltip for author and title, longer possible values
        Namelabel->setToolTip(memberVector.at(i).Name);
        Namelabel->setFixedWidth(200);
        IDlabel->setFixedWidth(70);
        AddressLabel->setFixedWidth(350);
        PhoneLabel->setFixedWidth(160);
        EmployeeLabel->setFixedWidth(10);
        AddressLabel->setToolTip(memberVector.at(i).Address);

        //Create Checkboxes
        QCheckBox *checkBox=new QCheckBox();
        connect(checkBox,SIGNAL(clicked(bool)),this,SLOT(on_Checked_Box()));
        checkBox->setFixedWidth(30);
        hlayout->addWidget(checkBox);
        memberVector.at(i).checkBox=checkBox;

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

void EditMembers::on_cmdReturn_clicked()
{
    if(bookVector.size() == 0)
    {
        QString bookList = "Booklist.txt";
        QString line = " ";
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
                temp.numWeeks= pieces.at(5);
                temp.isSelected=false;
                temp.checkBox=NULL;
                bookVector.push_back(temp);
            }
            inputFile.close();
            qDebug() << "Test: Read successfully";
        }
    }

    for (int i=(checkoutVector.size()-1);i>=0;i--){
        qDebug()<<i<< "CheckVec"<<checkoutVector.size();
        if(checkoutVector.at(i).checked){
            qDebug()<<"Selected";
            for(int j = 0; j < bookVector.size(); j++){
                if(checkoutVector.at(i).ISBN==bookVector.at(j).isbn){
                    bookVector.at(j).inStock=QString::number(bookVector.at(j).inStock.toInt()+1);
                    if(bookVector.at(j).checkBox!=NULL&&bookVector.at(j).checkBox->isChecked()){
                        bookVector.at(j).checkBox->setChecked(false);
                        bookVector.at(j).isSelected=false;
                    }
                }
            }
            checkoutVector.erase(checkoutVector.begin() + i);

            QString file = "Checkouts.txt";
            QFile outputFile(file);
            outputFile.resize(0);
            if (outputFile.open(QIODevice::ReadWrite)){
                QTextStream stream( &outputFile );
                for(int i=0;i<checkoutVector.size();i++){
                    qDebug() << checkoutVector.at(i).ISBN;
                    stream << checkoutVector.at(i).ID<<"|"<<checkoutVector.at(i).ISBN<<"|"<<checkoutVector.at(i).dueDate << endl;
                }
                outputFile.close();
                qDebug() << "Test: write successfully To Checkouts";
            }
            writeToFile();
        }
    }
    this->on_cmdListMems_clicked();
}

void EditMembers::on_Box_Checked()
{
    qDebug()<<"Selected"<<QObject::sender();
    for(int i = 0; i < checkoutVector.size(); i++){
        if(checkoutVector.at(i).checkBox==QObject::sender()){
            qDebug()<<"CheckVec Select";
            checkoutVector.at(i).checked=checkoutVector.at(i).checkBox->isChecked();
        }
    }
}

void EditMembers::on_cmdEditMem_clicked()
{
    this->on_cmdUniqueMems_clicked();
    ui->txtName->show();
    ui->txtID->show();
    ui->txtAddress->show();
    ui->txtPhone->show();
    ui->txtEmployee->show();
    ui->cmdConfirm->show();
    ui->cmdCancelEdit->show();
    ui->cmdDelete->show();
    ui->cmdReturn->hide();

    //Disable other buttons until edit is confirmed or cancelled
    ui->cmdListMems->setEnabled(false);
    ui->cmdReturn->setEnabled(false);
}

void EditMembers::on_cmdConfirm_clicked()
{
    QMessageBox editMemberWarning;

    //error check for filled  txtboxes
    if(ui->txtAddress->text() == "Address" ||ui->txtAddress->text() == "")
    {
        editMemberWarning.setText("Please enter your address");
        editMemberWarning.exec();
    }
    else if(ui->txtEmployee->text() == "Employee" ||ui->txtEmployee->text() == "")
    {
        editMemberWarning.setText("Please enter your Employee/Member status");
        editMemberWarning.exec();
    }
    else if(ui->txtID->text() == "ID" || ui->txtID->text() == "")
    {
        editMemberWarning.setText("Please enter your ID");
        editMemberWarning.exec();
    }
    else if(ui->txtName->text() == "Name" || ui->txtName->text() == "")
    {
        editMemberWarning.setText("Please enter your Name");
        editMemberWarning.exec();
    }
    else if(ui->txtPhone->text() == "Phone" ||ui->txtPhone->text() == "")
    {
        editMemberWarning.setText("Please enter your Phone Number");
        editMemberWarning.exec();
    }
    else
    {
        //Successfully entered data

        bool editExisting = false;
        for(int k = 0; k < memberVector.size();k++)
        {
            if(memberVector.at(k).checked == true)
            {
                editExisting = true;
                memberVector.at(k).Name = ui->txtName->text();
                memberVector.at(k).ID = ui->txtID->text();
                memberVector.at(k).Address = ui->txtAddress->text();
                memberVector.at(k).Phone = ui->txtPhone->text();
                memberVector.at(k).Employee = ui->txtEmployee->text();
            }
        }
        if(editExisting == false)
        {
            member newMember;

            //Read in data to a new member object to be pushed
            newMember.Name = ui->txtName->text();
            newMember.ID = ui->txtID->text();
            newMember.Address = ui->txtAddress->text();
            newMember.Phone = ui->txtPhone->text();
            newMember.Employee = ui->txtEmployee->text();
            memberVector.push_back(newMember);
        }
        ui->txtName->hide();
        ui->txtID->hide();
        ui->txtAddress->hide();
        ui->txtPhone->hide();
        ui->txtEmployee->hide();
        ui->cmdConfirm->hide();
        ui->cmdCancelEdit->hide();
        ui->cmdDelete->hide();
        ui->txtPassword->hide();
        ui->lblPassword->hide();

        //Write changes to file
        QString file = "Members.txt";
        QFile outputFile(file);
        outputFile.resize(0);
        if (outputFile.open(QIODevice::ReadWrite)){
            QTextStream stream( &outputFile );
            for(int i=0;i<memberVector.size();i++){
                qDebug() << memberVector.at(i).ISBN;
                stream << memberVector.at(i).Name<<"|"<<memberVector.at(i).ID<<"|"<<memberVector.at(i).Address<<"|"<<memberVector.at(i).Phone<<"|"<<memberVector.at(i).Employee<< endl;
            }
            outputFile.close();
            qDebug() << "Test: write successfully To members";
        }
        if(ui->txtEmployee->text() == "1" ||ui->txtEmployee->text() == "2")
        {
            QVector<QString> loginList;
            QString filename = "login.txt";
            QString line = " ";

            //Read from login for authentication
            QFile inputFile(filename);
            if (inputFile.open(QIODevice::ReadOnly))
            {
                qDebug()<<"read file";
                QTextStream readIn(&inputFile);
                while (!readIn.atEnd())
                {
                    line = readIn.readLine();
                    loginList.push_back(line);
                }
                inputFile.close();
                qDebug() << "Test: Read successfully";
            }

            //Check for preexisting logins
            QString temp = "";
            temp.append(ui->txtID->text());
            temp.append(" ");
            temp.append(ui->txtPassword->text());
            temp.append(" ");
            temp.append(ui->txtEmployee->text());

            for(int i = 0; i < loginList.size(); i++)
            {
                if(loginList.at(i).split(" ").first() == ui->txtID->text())
                {
                    loginList.erase(loginList.begin()+i);
                }
            }
                loginList.push_back(temp);

            //Write from login for authentication
            QString file = "login.txt";
            QFile outputFile(file);
            outputFile.resize(0);
            if (outputFile.open(QIODevice::ReadWrite)){
                QTextStream stream( &outputFile );
                for(int i=0;i<loginList.size();i++){
                    qDebug() << loginList.at(i);
                    stream << loginList.at(i) << endl;
                }
                outputFile.close();
                qDebug() << "Test: write successfully To members";
            }
        }

        //Enable other buttons
        ui->cmdListMems->setEnabled(true);
        ui->cmdUniqueMems->setEnabled(true);
        ui->cmdReturn->setEnabled(true);

        //Refresh list
        this->on_cmdUniqueMems_clicked();
    }
}

void EditMembers::on_cmdCancelEdit_clicked()
{
    //Enable other buttons
    ui->cmdListMems->setEnabled(true);
    ui->cmdUniqueMems->setEnabled(true);
    ui->cmdReturn->setEnabled(true);

    ui->txtName->hide();
    ui->txtID->hide();
    ui->txtAddress->hide();
    ui->txtPhone->hide();
    ui->txtEmployee->hide();
    ui->cmdConfirm->hide();
    ui->cmdCancelEdit->hide();
    ui->cmdDelete->hide();
    ui->txtPassword->hide();
    ui->lblPassword->hide();
}

void EditMembers::on_Checked_Box()
{
    qDebug()<<"Selected the member "<<QObject::sender();
    for(int i = 0; i < memberVector.size(); i++){
        if(memberVector.at(i).checkBox==QObject::sender()){
            memberVector.at(i).checked=memberVector.at(i).checkBox->isChecked();
            ui->txtName->setText(memberVector.at(i).Name);
            ui->txtID->setText(memberVector.at(i).ID);
            ui->txtAddress->setText(memberVector.at(i).Address);
            ui->txtPhone->setText(memberVector.at(i).Phone);
            ui->txtEmployee->setText(memberVector.at(i).Employee);
        }
        else
        {
            memberVector.at(i).checkBox->setChecked(false);
            memberVector.at(i).checked = false;
        }
    }
}


void EditMembers::writeToFile()
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

void EditMembers::on_cmdDelete_clicked()
{
    for(int i = 0; i < memberVector.size(); i++){
        if(memberVector.at(i).checked == true)
        {
            if(memberVector.at(i).Employee == "1" || memberVector.at(i).Employee == "2")
            {
                QVector<QString> loginList;
                QString filename = "login.txt";
                QString line = " ";

                //Read from login for authentication
                QFile inputFile(filename);
                if (inputFile.open(QIODevice::ReadOnly))
                {
                    qDebug()<<"read file";
                    QTextStream readIn(&inputFile);
                    while (!readIn.atEnd())
                    {
                        line = readIn.readLine();
                        loginList.push_back(line);
                    }
                    inputFile.close();
                    qDebug() << "Test: Read successfully";
                }

                for(int j = 0; j < loginList.size(); j++)
                {
                    //qDebug()<<loginList.at(j).split(" ").first()<<memberVector.at(i).ID;
                    if(loginList.at(j).split(" ").first() == memberVector.at(i).ID)
                    {
                        loginList.erase(loginList.begin()+j);
                    }
                }

                //Write from login for authentication
                QString file = "login.txt";
                QFile outputFile(file);
                outputFile.resize(0);
                if (outputFile.open(QIODevice::ReadWrite)){
                    QTextStream stream( &outputFile );
                    for(int i=0;i<loginList.size();i++){
                        qDebug() << loginList.at(i);
                        stream << loginList.at(i) << endl;
                    }
                    outputFile.close();
                    qDebug() << "Test: write successfully To members";
                }
            }
            memberVector.erase(memberVector.begin() + i);
        }
    }

    //Write Delete to File
    QString file = "Members.txt";
    QFile outputFile(file);
    outputFile.resize(0);
    if (outputFile.open(QIODevice::ReadWrite)){
        QTextStream stream( &outputFile );
        for(int i=0;i<memberVector.size();i++){
            qDebug() << memberVector.at(i).ISBN;
            stream << memberVector.at(i).Name<<"|"<<memberVector.at(i).ID<<"|"<<memberVector.at(i).Address<<"|"<<memberVector.at(i).Phone<<"|"<<memberVector.at(i).Employee<< endl;
        }
        outputFile.close();
        qDebug() << "Test: write successfully To members";
    }

    //Refresh list
    this->on_cmdUniqueMems_clicked();
}

void EditMembers::on_txtEmployee_textChanged(const QString &arg1)
{
    if((ui->txtEmployee->text() == "1" || ui->txtEmployee->text() == "2")&&!ui->cmdConfirm->isHidden())
    {
        ui->txtPassword->show();
        ui->lblPassword->show();
    }
    else
    {
        ui->txtPassword->hide();
        ui->lblPassword->hide();
    }
}
