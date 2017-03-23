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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QTextBrowser *txtSearchResults;
    QLineEdit *txtSearch;
    QPushButton *btnSearch;
    QLabel *lblSearch;

    void setupUi(QWidget *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(400, 300);
        txtSearchResults = new QTextBrowser(SearchWindow);
        txtSearchResults->setObjectName(QStringLiteral("txtSearchResults"));
        txtSearchResults->setGeometry(QRect(10, 90, 371, 192));
        txtSearch = new QLineEdit(SearchWindow);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));
        txtSearch->setGeometry(QRect(10, 60, 281, 21));
        btnSearch = new QPushButton(SearchWindow);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(290, 60, 91, 23));
        lblSearch = new QLabel(SearchWindow);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));
        lblSearch->setGeometry(QRect(90, 10, 311, 31));
        QFont font;
        font.setPointSize(18);
        lblSearch->setFont(font);

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchWindow)
    {
        SearchWindow->setWindowTitle(QApplication::translate("SearchWindow", "Form", 0));
        btnSearch->setText(QApplication::translate("SearchWindow", "Search", 0));
        lblSearch->setText(QApplication::translate("SearchWindow", "Local Library Search", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
