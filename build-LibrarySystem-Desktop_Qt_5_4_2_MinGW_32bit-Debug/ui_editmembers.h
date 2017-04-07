/********************************************************************************
** Form generated from reading UI file 'editmembers.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMEMBERS_H
#define UI_EDITMEMBERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditMembers
{
public:
    QPushButton *cmdListMems;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *cmdUniqueMems;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lblCheckoutID;
    QLabel *lblCheckoutISBN;
    QLabel *lblCheckoutDueDate;
    QPushButton *cmdReturn;

    void setupUi(QWidget *EditMembers)
    {
        if (EditMembers->objectName().isEmpty())
            EditMembers->setObjectName(QStringLiteral("EditMembers"));
        EditMembers->resize(988, 480);
        cmdListMems = new QPushButton(EditMembers);
        cmdListMems->setObjectName(QStringLiteral("cmdListMems"));
        cmdListMems->setGeometry(QRect(10, 60, 81, 41));
        scrollArea = new QScrollArea(EditMembers);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 140, 961, 331));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 959, 329));
        scrollArea->setWidget(scrollAreaWidgetContents);
        cmdUniqueMems = new QPushButton(EditMembers);
        cmdUniqueMems->setObjectName(QStringLiteral("cmdUniqueMems"));
        cmdUniqueMems->setGeometry(QRect(100, 60, 81, 41));
        label = new QLabel(EditMembers);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 0, 181, 51));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(EditMembers);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(60, 110, 47, 13));
        label_3 = new QLabel(EditMembers);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(140, 110, 47, 13));
        label_4 = new QLabel(EditMembers);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(230, 110, 47, 13));
        label_5 = new QLabel(EditMembers);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(410, 110, 47, 13));
        label_6 = new QLabel(EditMembers);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        label_6->setGeometry(QRect(560, 110, 47, 13));
        lblCheckoutID = new QLabel(EditMembers);
        lblCheckoutID->setObjectName(QStringLiteral("lblCheckoutID"));
        lblCheckoutID->setEnabled(true);
        lblCheckoutID->setGeometry(QRect(60, 110, 16, 16));
        lblCheckoutISBN = new QLabel(EditMembers);
        lblCheckoutISBN->setObjectName(QStringLiteral("lblCheckoutISBN"));
        lblCheckoutISBN->setEnabled(true);
        lblCheckoutISBN->setGeometry(QRect(120, 110, 47, 13));
        lblCheckoutDueDate = new QLabel(EditMembers);
        lblCheckoutDueDate->setObjectName(QStringLiteral("lblCheckoutDueDate"));
        lblCheckoutDueDate->setEnabled(true);
        lblCheckoutDueDate->setGeometry(QRect(220, 110, 47, 13));
        cmdReturn = new QPushButton(EditMembers);
        cmdReturn->setObjectName(QStringLiteral("cmdReturn"));
        cmdReturn->setGeometry(QRect(190, 60, 75, 41));

        retranslateUi(EditMembers);

        QMetaObject::connectSlotsByName(EditMembers);
    } // setupUi

    void retranslateUi(QWidget *EditMembers)
    {
        EditMembers->setWindowTitle(QApplication::translate("EditMembers", "Member & Book Listings", 0));
        cmdListMems->setText(QApplication::translate("EditMembers", "List Checked\n"
"Out Books", 0));
        cmdUniqueMems->setText(QApplication::translate("EditMembers", "Unique\n"
"Members", 0));
        label->setText(QApplication::translate("EditMembers", "Member & Book Listings", 0));
        label_2->setText(QApplication::translate("EditMembers", "Name", 0));
        label_3->setText(QApplication::translate("EditMembers", "ID", 0));
        label_4->setText(QApplication::translate("EditMembers", "Address", 0));
        label_5->setText(QApplication::translate("EditMembers", "Phone", 0));
        label_6->setText(QApplication::translate("EditMembers", "Employee", 0));
        lblCheckoutID->setText(QApplication::translate("EditMembers", "ID", 0));
        lblCheckoutISBN->setText(QApplication::translate("EditMembers", "ISBN", 0));
        lblCheckoutDueDate->setText(QApplication::translate("EditMembers", "Due Date", 0));
        cmdReturn->setText(QApplication::translate("EditMembers", "Return\n"
"Books", 0));
    } // retranslateUi

};

namespace Ui {
    class EditMembers: public Ui_EditMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMEMBERS_H
