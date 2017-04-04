#ifndef EMPLOYEEMAINMENU_H
#define EMPLOYEEMAINMENU_H

#include <QWidget>
#include <editmembers.h>
#include <authorizedwindow.h>

namespace Ui {
class EmployeeMainMenu;
}

class EmployeeMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeMainMenu(QWidget *parent = 0);
    ~EmployeeMainMenu();

private slots:


    void on_cmdMembers_clicked();

    void on_cmdAuthSearch_clicked();

private:
    Ui::EmployeeMainMenu *ui;

    EditMembers* openEditMembers;

    AuthorizedWindow* openAuthWindow;
};

#endif // EMPLOYEEMAINMENU_H
