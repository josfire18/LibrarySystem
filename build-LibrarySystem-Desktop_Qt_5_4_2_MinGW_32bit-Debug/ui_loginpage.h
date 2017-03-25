/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *CancelButton;
    QPushButton *LoginButton;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QStringLiteral("LoginPage"));
        LoginPage->resize(400, 300);
        Username = new QLineEdit(LoginPage);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(130, 80, 113, 21));
        Password = new QLineEdit(LoginPage);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(130, 150, 113, 21));
        Password->setEchoMode(QLineEdit::Password);
        CancelButton = new QPushButton(LoginPage);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(50, 230, 113, 32));
        LoginButton = new QPushButton(LoginPage);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(210, 230, 113, 32));

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QApplication::translate("LoginPage", "Form", 0));
        Username->setText(QApplication::translate("LoginPage", "Username", 0));
        Password->setText(QApplication::translate("LoginPage", "Password", 0));
        CancelButton->setText(QApplication::translate("LoginPage", "Cancel", 0));
        LoginButton->setText(QApplication::translate("LoginPage", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
