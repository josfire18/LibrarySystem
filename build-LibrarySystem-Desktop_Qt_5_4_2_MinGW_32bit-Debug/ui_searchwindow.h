/********************************************************************************
** Form generated from reading UI file 'searchwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

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

class Ui_SearchWindow
{
public:
    QLineEdit *txtSearch;
    QPushButton *btnSearch;
    QLabel *lblSearch;
    QLabel *lblTitle;
    QLabel *lblAuthor;
    QLabel *lblISBN;
    QLabel *lblTotAvail;
    QLabel *lblInStock;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(835, 555);
        txtSearch = new QLineEdit(SearchWindow);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));
        txtSearch->setGeometry(QRect(210, 60, 281, 21));
        btnSearch = new QPushButton(SearchWindow);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(490, 60, 91, 23));
        lblSearch = new QLabel(SearchWindow);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));
        lblSearch->setGeometry(QRect(300, 10, 311, 31));
        QFont font;
        font.setPointSize(18);
        lblSearch->setFont(font);
        lblTitle = new QLabel(SearchWindow);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(40, 100, 47, 13));
        lblAuthor = new QLabel(SearchWindow);
        lblAuthor->setObjectName(QStringLiteral("lblAuthor"));
        lblAuthor->setGeometry(QRect(150, 100, 47, 13));
        lblISBN = new QLabel(SearchWindow);
        lblISBN->setObjectName(QStringLiteral("lblISBN"));
        lblISBN->setGeometry(QRect(280, 100, 47, 13));
        lblTotAvail = new QLabel(SearchWindow);
        lblTotAvail->setObjectName(QStringLiteral("lblTotAvail"));
        lblTotAvail->setGeometry(QRect(440, 100, 47, 13));
        lblInStock = new QLabel(SearchWindow);
        lblInStock->setObjectName(QStringLiteral("lblInStock"));
        lblInStock->setGeometry(QRect(610, 100, 47, 13));
        scrollArea = new QScrollArea(SearchWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 130, 821, 421));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 819, 419));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchWindow)
    {
        SearchWindow->setWindowTitle(QApplication::translate("SearchWindow", "Form", 0));
        btnSearch->setText(QApplication::translate("SearchWindow", "Search", 0));
        lblSearch->setText(QApplication::translate("SearchWindow", "Local Library Search", 0));
        lblTitle->setText(QApplication::translate("SearchWindow", "Title", 0));
        lblAuthor->setText(QApplication::translate("SearchWindow", "Author", 0));
        lblISBN->setText(QApplication::translate("SearchWindow", "ISBN", 0));
        lblTotAvail->setText(QApplication::translate("SearchWindow", "# Avail", 0));
        lblInStock->setText(QApplication::translate("SearchWindow", "# Avail", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
