#ifndef AUTHORIZEDWINDOW_H
#define AUTHORIZEDWINDOW_H

#include <QWidget>
#include <QVector>
#include <QString>
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
    };

    vector<book> bookVector;

    //Concatenation Function
    QString concatenate(int lineNum);

private slots:
    void on_btnSearch_clicked();

private:
    Ui::AuthorizedWindow *ui;
};

#endif // AUTHORIZEDWINDOW_H
