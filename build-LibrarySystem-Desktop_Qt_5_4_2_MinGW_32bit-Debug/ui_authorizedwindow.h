/********************************************************************************
** Form generated from reading UI file 'authorizedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZEDWINDOW_H
#define UI_AUTHORIZEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorizedWindow
{
public:
    QLabel *lblAuthor;
    QPushButton *btnSearch;
    QLabel *lblTitle;
    QLabel *lblTotAvail;
    QLineEdit *txtSearch;
    QLabel *lblSearch;
    QLabel *lblInStock;
    QLabel *lblISBN;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *Add_Button;
    QPushButton *Delete_Button;
    QPushButton *Checkout_Button;
    QLineEdit *NewBook_Title;
    QLineEdit *NewBook_Author;
    QLineEdit *NewBook_ISBN;
    QLineEdit *NewBook_Quantity;
    QPushButton *NewBook_Confirm;
    QPushButton *NewBook_Cancel;
    QLabel *lblNumWeek;
    QLineEdit *NewBook_Weeks;

    void setupUi(QWidget *AuthorizedWindow)
    {
        if (AuthorizedWindow->objectName().isEmpty())
            AuthorizedWindow->setObjectName(QStringLiteral("AuthorizedWindow"));
        AuthorizedWindow->resize(834, 562);
        lblAuthor = new QLabel(AuthorizedWindow);
        lblAuthor->setObjectName(QStringLiteral("lblAuthor"));
        lblAuthor->setGeometry(QRect(260, 120, 47, 13));
        btnSearch = new QPushButton(AuthorizedWindow);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(330, 40, 91, 31));
        btnSearch->setDefault(true);
        lblTitle = new QLabel(AuthorizedWindow);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(50, 120, 47, 13));
        lblTotAvail = new QLabel(AuthorizedWindow);
        lblTotAvail->setObjectName(QStringLiteral("lblTotAvail"));
        lblTotAvail->setGeometry(QRect(550, 120, 47, 13));
        txtSearch = new QLineEdit(AuthorizedWindow);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));
        txtSearch->setGeometry(QRect(40, 40, 281, 21));
        lblSearch = new QLabel(AuthorizedWindow);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));
        lblSearch->setGeometry(QRect(290, 10, 311, 31));
        QFont font;
        font.setPointSize(18);
        lblSearch->setFont(font);
        lblInStock = new QLabel(AuthorizedWindow);
        lblInStock->setObjectName(QStringLiteral("lblInStock"));
        lblInStock->setGeometry(QRect(630, 120, 60, 13));
        lblISBN = new QLabel(AuthorizedWindow);
        lblISBN->setObjectName(QStringLiteral("lblISBN"));
        lblISBN->setGeometry(QRect(420, 120, 47, 13));
        scrollArea = new QScrollArea(AuthorizedWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 140, 811, 411));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 794, 409));
        scrollArea->setWidget(scrollAreaWidgetContents);
        Add_Button = new QPushButton(AuthorizedWindow);
        Add_Button->setObjectName(QStringLiteral("Add_Button"));
        Add_Button->setGeometry(QRect(580, 40, 113, 32));
        Delete_Button = new QPushButton(AuthorizedWindow);
        Delete_Button->setObjectName(QStringLiteral("Delete_Button"));
        Delete_Button->setGeometry(QRect(700, 40, 113, 32));
        Checkout_Button = new QPushButton(AuthorizedWindow);
        Checkout_Button->setObjectName(QStringLiteral("Checkout_Button"));
        Checkout_Button->setGeometry(QRect(460, 40, 113, 32));
        NewBook_Title = new QLineEdit(AuthorizedWindow);
        NewBook_Title->setObjectName(QStringLiteral("NewBook_Title"));
        NewBook_Title->setGeometry(QRect(10, 80, 113, 21));
        NewBook_Author = new QLineEdit(AuthorizedWindow);
        NewBook_Author->setObjectName(QStringLiteral("NewBook_Author"));
        NewBook_Author->setGeometry(QRect(140, 80, 113, 21));
        NewBook_ISBN = new QLineEdit(AuthorizedWindow);
        NewBook_ISBN->setObjectName(QStringLiteral("NewBook_ISBN"));
        NewBook_ISBN->setGeometry(QRect(260, 80, 113, 21));
        NewBook_Quantity = new QLineEdit(AuthorizedWindow);
        NewBook_Quantity->setObjectName(QStringLiteral("NewBook_Quantity"));
        NewBook_Quantity->setGeometry(QRect(390, 80, 113, 21));
        NewBook_Confirm = new QPushButton(AuthorizedWindow);
        NewBook_Confirm->setObjectName(QStringLiteral("NewBook_Confirm"));
        NewBook_Confirm->setGeometry(QRect(660, 80, 81, 32));
        NewBook_Cancel = new QPushButton(AuthorizedWindow);
        NewBook_Cancel->setObjectName(QStringLiteral("NewBook_Cancel"));
        NewBook_Cancel->setGeometry(QRect(740, 80, 71, 32));
        lblNumWeek = new QLabel(AuthorizedWindow);
        lblNumWeek->setObjectName(QStringLiteral("lblNumWeek"));
        lblNumWeek->setGeometry(QRect(710, 120, 81, 16));
        NewBook_Weeks = new QLineEdit(AuthorizedWindow);
        NewBook_Weeks->setObjectName(QStringLiteral("NewBook_Weeks"));
        NewBook_Weeks->setGeometry(QRect(520, 80, 113, 21));

        retranslateUi(AuthorizedWindow);

        QMetaObject::connectSlotsByName(AuthorizedWindow);
    } // setupUi

    void retranslateUi(QWidget *AuthorizedWindow)
    {
        AuthorizedWindow->setWindowTitle(QApplication::translate("AuthorizedWindow", "Authorized Search", 0));
        lblAuthor->setText(QApplication::translate("AuthorizedWindow", "Author", 0));
        btnSearch->setText(QApplication::translate("AuthorizedWindow", "Search", 0));
        lblTitle->setText(QApplication::translate("AuthorizedWindow", "Title", 0));
        lblTotAvail->setText(QApplication::translate("AuthorizedWindow", "# Avail", 0));
        lblSearch->setText(QApplication::translate("AuthorizedWindow", "Local Library Search", 0));
        lblInStock->setText(QApplication::translate("AuthorizedWindow", "In Stock", 0));
        lblISBN->setText(QApplication::translate("AuthorizedWindow", "ISBN", 0));
        Add_Button->setText(QApplication::translate("AuthorizedWindow", "Add", 0));
        Delete_Button->setText(QApplication::translate("AuthorizedWindow", "Delete", 0));
        Checkout_Button->setText(QApplication::translate("AuthorizedWindow", "Checkout", 0));
        NewBook_Title->setText(QApplication::translate("AuthorizedWindow", "Title", 0));
        NewBook_Author->setText(QApplication::translate("AuthorizedWindow", "Author", 0));
        NewBook_ISBN->setText(QApplication::translate("AuthorizedWindow", "ISBN", 0));
        NewBook_ISBN->setPlaceholderText(QString());
        NewBook_Quantity->setText(QApplication::translate("AuthorizedWindow", "Quantity", 0));
        NewBook_Confirm->setText(QApplication::translate("AuthorizedWindow", "Confirm", 0));
        NewBook_Cancel->setText(QApplication::translate("AuthorizedWindow", "Cancel", 0));
        lblNumWeek->setText(QApplication::translate("AuthorizedWindow", "NumWeeks", 0));
        NewBook_Weeks->setText(QApplication::translate("AuthorizedWindow", "NumWeeks", 0));
    } // retranslateUi

};

namespace Ui {
    class AuthorizedWindow: public Ui_AuthorizedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZEDWINDOW_H
