#ifndef EDITMEMBERS_H
#define EDITMEMBERS_H

#include <QWidget>
#include <QVector>
#include <QString>
using namespace std;
namespace Ui {
class EditMembers;
}

class EditMembers : public QWidget
{
    Q_OBJECT

public:
    explicit EditMembers(QWidget *parent = 0);
    ~EditMembers();

    //Struct for containing the 5 separate parts of the book
    struct member{
        QString Name;
        QString Address;
        QString Phone;
        QString Employee;
        QString ISBN;
        QString dateCheckedOut;
    };

    vector<member> memberVector;

private slots:
    void on_cmdListMems_clicked();

private:
    Ui::EditMembers *ui;
};

#endif // EDITMEMBERS_H
