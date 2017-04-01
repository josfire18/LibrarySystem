/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBook
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Author;
    QLineEdit *ISBN;
    QLineEdit *inStock;
    QLineEdit *totNum;
    QLineEdit *Title;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AddBook)
    {
        if (AddBook->objectName().isEmpty())
            AddBook->setObjectName(QStringLiteral("AddBook"));
        AddBook->resize(400, 300);
        verticalLayoutWidget = new QWidget(AddBook);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 40, 160, 147));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Author = new QLineEdit(verticalLayoutWidget);
        Author->setObjectName(QStringLiteral("Author"));

        verticalLayout->addWidget(Author);

        ISBN = new QLineEdit(verticalLayoutWidget);
        ISBN->setObjectName(QStringLiteral("ISBN"));

        verticalLayout->addWidget(ISBN);

        inStock = new QLineEdit(verticalLayoutWidget);
        inStock->setObjectName(QStringLiteral("inStock"));

        verticalLayout->addWidget(inStock);

        totNum = new QLineEdit(verticalLayoutWidget);
        totNum->setObjectName(QStringLiteral("totNum"));

        verticalLayout->addWidget(totNum);

        Title = new QLineEdit(verticalLayoutWidget);
        Title->setObjectName(QStringLiteral("Title"));

        verticalLayout->addWidget(Title);

        pushButton = new QPushButton(AddBook);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 210, 113, 32));
        pushButton_2 = new QPushButton(AddBook);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 260, 113, 32));

        retranslateUi(AddBook);

        QMetaObject::connectSlotsByName(AddBook);
    } // setupUi

    void retranslateUi(QWidget *AddBook)
    {
        AddBook->setWindowTitle(QApplication::translate("AddBook", "Form", 0));
        Author->setText(QApplication::translate("AddBook", "Title", 0));
        ISBN->setText(QApplication::translate("AddBook", "Author", 0));
        inStock->setText(QApplication::translate("AddBook", "ISBN", 0));
        totNum->setText(QApplication::translate("AddBook", "Quantity Owned", 0));
        Title->setText(QApplication::translate("AddBook", "Quantity In Stock", 0));
        pushButton->setText(QApplication::translate("AddBook", "Add Book", 0));
        pushButton_2->setText(QApplication::translate("AddBook", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddBook: public Ui_AddBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
