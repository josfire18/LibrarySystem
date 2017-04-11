#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>
#include <QVector>
#include <QString>
using namespace std;

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = 0);
    ~SearchWindow();

    //Struct for containing the 5 separate parts of the book
    struct book{
        QString title;
        QString author;
        QString isbn;
        QString totNum;
        QString inStock;
        QString numWeeks;
    };

    vector<book> bookVector;

private slots:
    void on_btnSearch_clicked();

private:
    Ui::SearchWindow *ui;
};

#endif // SEARCHWINDOW_H
