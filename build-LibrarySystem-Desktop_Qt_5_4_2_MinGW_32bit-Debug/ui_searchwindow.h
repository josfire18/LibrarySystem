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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        SearchWindow->resize(835, 555);
        txtSearchResults = new QTextBrowser(SearchWindow);
        txtSearchResults->setObjectName(QStringLiteral("txtSearchResults"));
        txtSearchResults->setGeometry(QRect(10, 120, 811, 421));
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
        label = new QLabel(SearchWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 100, 47, 13));
        label_2 = new QLabel(SearchWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 100, 47, 13));
        label_3 = new QLabel(SearchWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 100, 47, 13));
        label_4 = new QLabel(SearchWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 100, 47, 13));

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchWindow)
    {
        SearchWindow->setWindowTitle(QApplication::translate("SearchWindow", "Form", 0));
        btnSearch->setText(QApplication::translate("SearchWindow", "Search", 0));
        lblSearch->setText(QApplication::translate("SearchWindow", "Local Library Search", 0));
        label->setText(QApplication::translate("SearchWindow", "Title", 0));
        label_2->setText(QApplication::translate("SearchWindow", "Author", 0));
        label_3->setText(QApplication::translate("SearchWindow", "ISBN", 0));
        label_4->setText(QApplication::translate("SearchWindow", "# Avail", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
