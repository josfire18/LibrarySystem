#include "employeemainmenu.h"
#include "ui_employeemainmenu.h"

EmployeeMainMenu::EmployeeMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeMainMenu)
{
    ui->setupUi(this);
}

EmployeeMainMenu::~EmployeeMainMenu()
{
    delete ui;
}

void EmployeeMainMenu::on_cmdMembers_clicked()
{
    openEditMembers = new EditMembers();
    openEditMembers->show();
}

void EmployeeMainMenu::on_cmdAuthSearch_clicked()
{
    openAuthWindow = new AuthorizedWindow();
    openAuthWindow->show();
}
