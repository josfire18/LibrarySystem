#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "authorizedwindow.h"
#include "editmembers.h"

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
    void on_cmdSearch_clicked();

    void on_cmdMember_clicked();

    void on_cmdCancel_clicked();

    void on_cmdLogin_clicked();

private:
    Ui::LoginPage *ui;
    AuthorizedWindow* openAuthorizedWindow;
    EditMembers* openEditMembers;
};

#endif // LOGINPAGE_H
