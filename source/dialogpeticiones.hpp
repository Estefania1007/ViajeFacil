/*DESCRIPCION: las peticiones son elaboradas por todas las partes de este proyecto, es decir, cada
 * acción que se realice va a ser una petición que se quedará guardada en esta clase "peticiones"
 * AUTORES: Sergio Candel, ayuda David Jimenez y Hugo Ferrando
 */
#ifndef DIALOGPETICIONES_H
#define DIALOGPETICIONES_H

#include <QDialog>
#include <vector>
#include "./peticion.hpp"  //va a participar la cabecera de peticiones y la de owner
#include "./owner.hpp"  //encontraremos datos de owners

namespace Ui { //funcion que guardará la petición durante un periodo de tiempo, hasta que finalice el programa
class DialogPeticiones; //clase dialogpeticiones
}

//se define la clase cómo va a ser y su contenido.
/**
 * @brief The DialogPeticiones class
 */
class DialogPeticiones : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief DialogPeticiones
     * @param parent
     */
    explicit DialogPeticiones(QWidget *parent = 0);
    ~DialogPeticiones(); //Destructor
    /**
      * @brief setOw
      * @param own
      */
     void setOw(std::vector<Owner>& own); //va a pedir como parámetro owners se guardaran en el vector owners y se podrá mostrar modificado
     /**
      * @brief setPe
      * @param pet
      */
     void setPe(std::vector<Peticion>& pet); //pide parámetro peticiones, devuelve vector peticiones ->lista peticiones
     /**
      * @brief cargar
      */
     void cargar(); //función cargar, archivo donde se guardan las peticiones


private:
    /**
    * @brief ui
    */
    Ui::DialogPeticiones *ui; //parte gráfica, se modificará y se mostrará el resultado final
    /**
     * @brief ow
     */
    std::vector<Owner> *ow; //lista de owners
    /**
     * @brief pe
     */
    std::vector<Peticion> *pe; //vector peticiones

};

#endif // DIALOGPETICIONES_H
