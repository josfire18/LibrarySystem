#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "authorizedwindow.h"
#include "employeemainmenu.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();
    bool loginSuccessful;

private slots:
    void on_cmdCancel_clicked();

    void on_cmdLogin_clicked();

private:
    Ui::LoginPage *ui;
    EmployeeMainMenu* openMainMenu;
};

#endif // LOGINPAGE_H
