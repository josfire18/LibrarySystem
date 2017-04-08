#include "employeemainmenu.h"
#include "ui_employeemainmenu.h"
#include "QDebug"

EmployeeMainMenu::EmployeeMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeMainMenu)
{
    ui->setupUi(this);
    isManager=false;
    openEditMembers = NULL;
    openAuthWindow = NULL;
}

EmployeeMainMenu::~EmployeeMainMenu()
{
    delete ui;
}

void EmployeeMainMenu::setManager(bool manager)
{
    this->isManager=manager;
}

void EmployeeMainMenu::on_cmdMembers_clicked()
{
    if(openEditMembers != NULL)
    {
        delete openEditMembers;
    }
    openEditMembers = new EditMembers();
    openEditMembers->setManager(isManager);
    openEditMembers->show();
}

void EmployeeMainMenu::on_cmdAuthSearch_clicked()
{
    if(openAuthWindow != NULL)
    {
        delete openAuthWindow;
    }
    openAuthWindow = new AuthorizedWindow();
    openAuthWindow->setManager(isManager);
    openAuthWindow->show();
}
