#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "searchwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Search_clicked();

    void on_Login_clicked();

private:
    Ui::MainWindow *ui;
    Login* login;
    SearchWindow* Search;
};

#endif // MAINWINDOW_H
