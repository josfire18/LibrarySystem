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
#include <QtWidgets/QTextEdit>
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
    QTextEdit *txtSearchResults;

    void setupUi(QWidget *AuthorizedWindow)
    {
        if (AuthorizedWindow->objectName().isEmpty())
            AuthorizedWindow->setObjectName(QStringLiteral("AuthorizedWindow"));
        AuthorizedWindow->resize(834, 562);
        lblAuthor = new QLabel(AuthorizedWindow);
        lblAuthor->setObjectName(QStringLiteral("lblAuthor"));
        lblAuthor->setGeometry(QRect(140, 100, 47, 13));
        btnSearch = new QPushButton(AuthorizedWindow);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(480, 60, 91, 23));
        lblTitle = new QLabel(AuthorizedWindow);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(30, 100, 47, 13));
        lblTotAvail = new QLabel(AuthorizedWindow);
        lblTotAvail->setObjectName(QStringLiteral("lblTotAvail"));
        lblTotAvail->setGeometry(QRect(430, 100, 47, 13));
        txtSearch = new QLineEdit(AuthorizedWindow);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));
        txtSearch->setGeometry(QRect(200, 60, 281, 21));
        lblSearch = new QLabel(AuthorizedWindow);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));
        lblSearch->setGeometry(QRect(290, 10, 311, 31));
        QFont font;
        font.setPointSize(18);
        lblSearch->setFont(font);
        lblInStock = new QLabel(AuthorizedWindow);
        lblInStock->setObjectName(QStringLiteral("lblInStock"));
        lblInStock->setGeometry(QRect(600, 100, 47, 13));
        lblISBN = new QLabel(AuthorizedWindow);
        lblISBN->setObjectName(QStringLiteral("lblISBN"));
        lblISBN->setGeometry(QRect(270, 100, 47, 13));
        txtSearchResults = new QTextEdit(AuthorizedWindow);
        txtSearchResults->setObjectName(QStringLiteral("txtSearchResults"));
        txtSearchResults->setGeometry(QRect(10, 140, 811, 411));

        retranslateUi(AuthorizedWindow);

        QMetaObject::connectSlotsByName(AuthorizedWindow);
    } // setupUi

    void retranslateUi(QWidget *AuthorizedWindow)
    {
        AuthorizedWindow->setWindowTitle(QApplication::translate("AuthorizedWindow", "Form", 0));
        lblAuthor->setText(QApplication::translate("AuthorizedWindow", "Author", 0));
        btnSearch->setText(QApplication::translate("AuthorizedWindow", "Search", 0));
        lblTitle->setText(QApplication::translate("AuthorizedWindow", "Title", 0));
        lblTotAvail->setText(QApplication::translate("AuthorizedWindow", "# Avail", 0));
        lblSearch->setText(QApplication::translate("AuthorizedWindow", "Local Library Search", 0));
        lblInStock->setText(QApplication::translate("AuthorizedWindow", "# Avail", 0));
        lblISBN->setText(QApplication::translate("AuthorizedWindow", "ISBN", 0));
    } // retranslateUi

};

namespace Ui {
    class AuthorizedWindow: public Ui_AuthorizedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZEDWINDOW_H
