#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "owner.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector<Owner> &getOwners();


private slots:
    void on_pushButton_2_clicked();

    void on_actionUsuario_triggered();

    void on_actionOwner_triggered();

    void on_pushButton_3_clicked();

    void on_actionNego_triggered();

private:
    Ui::MainWindow *ui;
    std::vector<Owner> listaOw;

};

#endif // MAINWINDOW_H
