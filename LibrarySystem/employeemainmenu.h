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
    void setManager(bool manager);
private slots:


    void on_cmdMembers_clicked();

    void on_cmdAuthSearch_clicked();

private:
    Ui::EmployeeMainMenu *ui;

    EditMembers* openEditMembers;

    AuthorizedWindow* openAuthWindow;

    bool isManager;
};

#endif // EMPLOYEEMAINMENU_H
