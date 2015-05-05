#include <vector>
#include <fstream>
#include "./mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "./login.hpp"
#include "./diagowner.hpp"
#include "./dialognego.hpp"
#include "./cereal/archives/json.hpp"
#include "./cereal/types/vector.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
    Login log;
    log.setEstado(0);
    log.setModal(true);
    // Signal & slot mechanism with new syntax http://wiki.qt.io/New_Signal_Slot_Syntax
    connect(&log, &Login::cambioDeUsuario, this, &MainWindow::cambiarUsuario);
    log.exec();
}

void MainWindow::on_actionUsuario_triggered() {
    Login log;
    log.setModal(true);
    log.setEstado(1);
    log.exec();
}

void MainWindow::on_actionOwner_triggered() {
    diagOwner ow;
    ow.setOw(this->listaOw);
    ow.setModal(true);
    ow.exec();

    this->ui->listWidget_2->clear();
    for (std::vector<Owner>::iterator it = this->listaOw.begin(); it != this->listaOw.end(); ++it) {
        this->ui->listWidget_2->addItem(it->getNombre());
    }

    std::ofstream myfile;
    myfile.open("../../data/data.json");
    cereal::JSONOutputArchive archive(myfile);
    archive(cereal::make_nvp("Owner", this->listaOw));
}

std::vector<Owner> &MainWindow::getOwners() { return this->listaOw; }

void MainWindow::on_actionNego_triggered() {
    DialogNego *ng = new DialogNego;
    ng->setOw(this->listaOw);
    ng->cargar();
    ng->setModal(true);
    ng->exec();
}

void MainWindow::cambiarUsuario(std::string nombre) {
    QString QNombre = QString::fromUtf8(nombre.c_str());
    this->ui->label_2->setText(QNombre);
}

void MainWindow::on_listWidget_2_pressed(const QModelIndex &index) {
    auto ow = this->listaOw.at(index.row());
    this->ui->listWidget->clear();
    for (std::vector<Nego>::iterator it = ow.getNegos().begin(); it != ow.getNegos().end(); ++it) {
        this->ui->listWidget->addItem(it->getOrigen());
    }
}
