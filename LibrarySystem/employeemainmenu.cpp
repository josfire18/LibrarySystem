#include "employeemainmenu.h"
#include "ui_employeemainmenu.h"

EmployeeMainMenu::EmployeeMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeMainMenu)
{
    ui->setupUi(this);
    isManager=false;
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
    openEditMembers = new EditMembers();
    openEditMembers->setManager(isManager);
    openEditMembers->show();
}

void EmployeeMainMenu::on_cmdAuthSearch_clicked()
{
    openAuthWindow = new AuthorizedWindow();
    openAuthWindow->setManager(isManager);
    openAuthWindow->show();
}
