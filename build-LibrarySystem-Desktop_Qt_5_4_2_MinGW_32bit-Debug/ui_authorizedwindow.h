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

    void setupUi(QWidget *AuthorizedWindow)
    {
        if (AuthorizedWindow->objectName().isEmpty())
            AuthorizedWindow->setObjectName(QStringLiteral("AuthorizedWindow"));
        AuthorizedWindow->resize(834, 562);
        lblAuthor = new QLabel(AuthorizedWindow);
        lblAuthor->setObjectName(QStringLiteral("lblAuthor"));
        lblAuthor->setGeometry(QRect(260, 100, 47, 13));
        btnSearch = new QPushButton(AuthorizedWindow);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(330, 60, 91, 31));
        btnSearch->setDefault(true);
        lblTitle = new QLabel(AuthorizedWindow);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(50, 100, 47, 13));
        lblTotAvail = new QLabel(AuthorizedWindow);
        lblTotAvail->setObjectName(QStringLiteral("lblTotAvail"));
        lblTotAvail->setGeometry(QRect(550, 100, 47, 13));
        txtSearch = new QLineEdit(AuthorizedWindow);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));
        txtSearch->setGeometry(QRect(40, 60, 281, 21));
        lblSearch = new QLabel(AuthorizedWindow);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));
        lblSearch->setGeometry(QRect(290, 10, 311, 31));
        QFont font;
        font.setPointSize(18);
        lblSearch->setFont(font);
        lblInStock = new QLabel(AuthorizedWindow);
        lblInStock->setObjectName(QStringLiteral("lblInStock"));
        lblInStock->setGeometry(QRect(670, 100, 60, 13));
        lblISBN = new QLabel(AuthorizedWindow);
        lblISBN->setObjectName(QStringLiteral("lblISBN"));
        lblISBN->setGeometry(QRect(420, 100, 47, 13));
        scrollArea = new QScrollArea(AuthorizedWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 130, 811, 421));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 792, 419));
        scrollArea->setWidget(scrollAreaWidgetContents);
        Add_Button = new QPushButton(AuthorizedWindow);
        Add_Button->setObjectName(QStringLiteral("Add_Button"));
        Add_Button->setGeometry(QRect(580, 60, 113, 32));
        Delete_Button = new QPushButton(AuthorizedWindow);
        Delete_Button->setObjectName(QStringLiteral("Delete_Button"));
        Delete_Button->setGeometry(QRect(700, 60, 113, 32));
        Checkout_Button = new QPushButton(AuthorizedWindow);
        Checkout_Button->setObjectName(QStringLiteral("Checkout_Button"));
        Checkout_Button->setGeometry(QRect(460, 60, 113, 32));

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
    } // retranslateUi

};

namespace Ui {
    class AuthorizedWindow: public Ui_AuthorizedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZEDWINDOW_H
