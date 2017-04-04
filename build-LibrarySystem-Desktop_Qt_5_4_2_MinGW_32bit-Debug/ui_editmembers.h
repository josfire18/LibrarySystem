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

    void setupUi(QWidget *EditMembers)
    {
        if (EditMembers->objectName().isEmpty())
            EditMembers->setObjectName(QStringLiteral("EditMembers"));
        EditMembers->resize(988, 480);
        cmdListMems = new QPushButton(EditMembers);
        cmdListMems->setObjectName(QStringLiteral("cmdListMems"));
        cmdListMems->setGeometry(QRect(10, 40, 81, 41));
        scrollArea = new QScrollArea(EditMembers);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 110, 961, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 959, 359));
        scrollArea->setWidget(scrollAreaWidgetContents);
        cmdUniqueMems = new QPushButton(EditMembers);
        cmdUniqueMems->setObjectName(QStringLiteral("cmdUniqueMems"));
        cmdUniqueMems->setGeometry(QRect(100, 40, 61, 41));

        retranslateUi(EditMembers);

        QMetaObject::connectSlotsByName(EditMembers);
    } // setupUi

    void retranslateUi(QWidget *EditMembers)
    {
        EditMembers->setWindowTitle(QApplication::translate("EditMembers", "Form", 0));
        cmdListMems->setText(QApplication::translate("EditMembers", "List Checked\n"
"Out Books", 0));
        cmdUniqueMems->setText(QApplication::translate("EditMembers", "Unique\n"
"Members", 0));
    } // retranslateUi

};

namespace Ui {
    class EditMembers: public Ui_EditMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMEMBERS_H
