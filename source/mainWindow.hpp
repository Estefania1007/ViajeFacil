//VENTANA PRINCIPAL
//AUTORES: Hugo Ferrando
#ifndef mainWindow_H
#define mainWindow_H

#include <QMainWindow>
#include <string>
#include "./pel_vector.hpp"
#include "./owner.hpp"

namespace Ui {
class mainWindow;
}

/**
 * @brief The mainWindow class
 */
class mainWindow : public QMainWindow {
    Q_OBJECT

 public:
     /**
      * @brief mainWindow
      * @param parent
      */
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

 private slots:
    /**
    * @brief on_pushButton_2_clicked
    */
    void on_pushButton_2_clicked();
    /**
     * @brief cambiarUsuario
     * @param nombre
     */
    void cambiarUsuario(std::string nombre);
    /**
     * @brief guardarEnArchivo
     */
    void guardarEnArchivo();
    /**
     * @brief on_listWidget_2_pressed
     * @param index
     */
    void on_listWidget_pressed(const QModelIndex &index);
    /**
     * @brief on_actionCrePeticion_triggered
     */
    void on_actionCrePeticion_triggered();
    /**
     * @brief on_actionCreNego_triggered
     */
    void on_actionCreNego_triggered();
    /**
     * @brief on_actionCreOwner_triggered
     */
    void on_actionCreOwner_triggered();
    /**
     * @brief on_actionCreUsuario_triggered
     */
    void on_actionCreUsuario_triggered();
    /**
     * @brief on_actionBorOwner_triggered
     */
    void on_actionBorOwner_triggered();
    /**
     * @brief on_actionModOwner_triggered
     */
    void on_actionModOwner_triggered();
    /**
     * @brief on_actionModNego_triggered
     */
    void on_actionModNego_triggered();
    /**
     * @brief on_actionBorNego_triggered
     */
    void on_actionBorNego_triggered();

    void on_actionCreOficina_triggered();

    void on_listWidget_3_pressed(const QModelIndex &index);

    void on_actionBorOficina_triggered();

    void on_actionBorPeticion_triggered();

    void on_actionModOficina_triggered();

    void on_actionModPeticion_triggered();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_listWidget_4_currentRowChanged(int currentRow);

 private:
    /**
     * @brief ui
     */
    Ui::mainWindow *ui;
    /**
     * @brief listaOw
     */
    pel::vector<Owner> listaOw;
};

#endif  // mainWindow_H