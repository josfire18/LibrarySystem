#ifndef AUTHORIZEDWINDOW_H
#define AUTHORIZEDWINDOW_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QCheckBox>
using namespace std;

namespace Ui {
class AuthorizedWindow;
}

class AuthorizedWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorizedWindow(QWidget *parent = 0);
    ~AuthorizedWindow();

    //Struct for containing the 5 separate parts of the book
    struct book{
        QString title;
        QString author;
        QString isbn;
        QString totNum;
        QString inStock;
        QString numWeeks;
        bool isSelected;
        QCheckBox *checkBox;
    };

    vector<book> bookVector;

    void setManager(bool manager);
    //Concatenation Function
    QString concatenate(int lineNum);

private slots:
    void on_btnSearch_clicked();

    void on_Checkout_Button_clicked();

    void on_Add_Button_clicked();

    void on_Delete_Button_clicked();

    void on_Box_Checked();

    void on_NewBook_Confirm_clicked();

    void on_NewBook_Cancel_clicked();

    void on_NewBook_ISBN_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::AuthorizedWindow *ui;
    void writeToFile();
    bool isManager;
};

#endif // AUTHORIZEDWINDOW_H
