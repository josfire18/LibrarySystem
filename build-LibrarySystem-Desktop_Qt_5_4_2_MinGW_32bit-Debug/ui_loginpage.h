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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *cmdCancel;
    QPushButton *cmdLogin;
    QLabel *label;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QStringLiteral("LoginPage"));
        LoginPage->resize(386, 245);
        Username = new QLineEdit(LoginPage);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(130, 80, 113, 21));
        Password = new QLineEdit(LoginPage);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(130, 150, 113, 21));
        Password->setEchoMode(QLineEdit::Password);
        cmdCancel = new QPushButton(LoginPage);
        cmdCancel->setObjectName(QStringLiteral("cmdCancel"));
        cmdCancel->setGeometry(QRect(50, 200, 113, 32));
        cmdLogin = new QPushButton(LoginPage);
        cmdLogin->setObjectName(QStringLiteral("cmdLogin"));
        cmdLogin->setGeometry(QRect(210, 200, 113, 32));
        cmdLogin->setDefault(true);
        label = new QLabel(LoginPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 121, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QApplication::translate("LoginPage", "Employee Login", 0));
        Username->setText(QApplication::translate("LoginPage", "Username", 0));
        Password->setText(QApplication::translate("LoginPage", "Password", 0));
        cmdCancel->setText(QApplication::translate("LoginPage", "Cancel", 0));
        cmdLogin->setText(QApplication::translate("LoginPage", "Login", 0));
        label->setText(QApplication::translate("LoginPage", "Employee Login", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
