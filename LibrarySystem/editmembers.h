#ifndef EDITMEMBERS_H
#define EDITMEMBERS_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QCheckBox>
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
        QString ID;
        QString Address;
        QString Phone;
        QString Employee;
        QString ISBN;
        QString dueDate;
        bool checked;
        QCheckBox *checkBox;
    };


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


    vector<member> memberVector;
    vector<member> checkoutVector;
    vector<book> bookVector;
    QString concatenate(int lineNum);


    void setManager(bool manager);
private slots:
    void on_cmdListMems_clicked();

    void on_cmdUniqueMems_clicked();

    void on_cmdReturn_clicked();

    void on_cmdEditMem_clicked();

    void on_cmdConfirm_clicked();

    void on_cmdCancelEdit_clicked();

    void on_Checked_Box();

    void on_Box_Checked();
    void on_cmdDelete_clicked();

    void on_txtEmployee_textChanged(const QString &arg1);

private:
    Ui::EditMembers *ui;
    void writeToFile();
    bool isManager;
};

#endif // EDITMEMBERS_H
