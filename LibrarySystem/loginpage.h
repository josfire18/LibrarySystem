#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

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
    void on_CancelButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H