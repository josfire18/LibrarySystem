/********************************************************************************
** Form generated from reading UI file 'employeemainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEMAINMENU_H
#define UI_EMPLOYEEMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeMainMenu
{
public:
    QPushButton *cmdMembers;
    QPushButton *cmdAuthSearch;
    QLabel *label;

    void setupUi(QWidget *EmployeeMainMenu)
    {
        if (EmployeeMainMenu->objectName().isEmpty())
            EmployeeMainMenu->setObjectName(QStringLiteral("EmployeeMainMenu"));
        EmployeeMainMenu->resize(294, 185);
        cmdMembers = new QPushButton(EmployeeMainMenu);
        cmdMembers->setObjectName(QStringLiteral("cmdMembers"));
        cmdMembers->setGeometry(QRect(30, 90, 231, 31));
        cmdAuthSearch = new QPushButton(EmployeeMainMenu);
        cmdAuthSearch->setObjectName(QStringLiteral("cmdAuthSearch"));
        cmdAuthSearch->setGeometry(QRect(30, 140, 231, 31));
        label = new QLabel(EmployeeMainMenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 161, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(EmployeeMainMenu);

        QMetaObject::connectSlotsByName(EmployeeMainMenu);
    } // setupUi

    void retranslateUi(QWidget *EmployeeMainMenu)
    {
        EmployeeMainMenu->setWindowTitle(QApplication::translate("EmployeeMainMenu", "Main Menu", 0));
        cmdMembers->setText(QApplication::translate("EmployeeMainMenu", "Member List", 0));
        cmdAuthSearch->setText(QApplication::translate("EmployeeMainMenu", "Authorized Search/Checkout", 0));
        label->setText(QApplication::translate("EmployeeMainMenu", "Employee Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class EmployeeMainMenu: public Ui_EmployeeMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEMAINMENU_H
