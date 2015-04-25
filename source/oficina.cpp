#include "header.h"
#include "oficina.h"

Oficina::Oficina(){
	this->nombre_ = "";
	this->id_ = -1;
	this->pais_ = "";
	this->continente_ = "";
	this->peticiones_.resize(1);
}

Oficina::Oficina(QString nombre, size_t id, QString pais, QString continente , std::size_t tPeticiones){
	this->nombre_ = nombre;
	this->id_ = id;
	this->pais_ = pais;
	this->continente_ = continente;
	this->peticiones_.resize(tPeticiones);
}

Oficina::~Oficina(){

}

void Oficina::setNombre(QString nombre){
	this->nombre_ = nombre;
}

void Oficina::setId(size_t id){
	this->id_ = id;
}

void Oficina::setPais(QString pais){
	this->pais_ = pais;
}

void Oficina::setContinente(QString continente){
	this->continente_ = continente;
}

QString Oficina::getNombre(){
	return this->nombre_;
}

std::size_t Oficina::getId(){
    return this->id_;
}

QString Oficina::getPais(){
    return this->pais_;
}

QString Oficina::getContinente(){
    return this->continente_;
}

std::vector<Peticion> &Oficina::getPeticiones(){ return this->peticiones_; };

//Implementacion veija - quitar
void gestionarOficinas(owners *listaOwners){
	int opcion;
	do {
		system("CLS");
		std::cout << "********** Menu Oficinas **********" << std::endl << std::endl;
		std::cout << "Pulse 1 para crear oficinas" << std::endl;
		std::cout << "Pulse 2 para borrar oficinas" << std::endl;
		std::cout << "Pulse 3 para consultar la lista de oficinas" << std::endl;
		std::cout << "Pulse 0 para salir" << std::endl;
		std::cin >> opcion;

		switch (opcion){
		case 1:
			crearOficinas(&listaOwners[0]);
			break;

		case 2:
			borrarOficinas(&listaOwners[0]);
			break;

		case 3:
			consultarOficinas(&listaOwners[0]);
			break;
		case 4:
			break;
		}

	} while (opcion != 0);
}

void crearOficinas(owners *listaOwners){
	system("CLS");

	int idOwner;
	oficinas *sel = devolverOficinas(&listaOwners[0], &idOwner);
	int contOficinas = listaOwners[idOwner].contOficinas++; //Post incrementamos el contador
	
	std::cout << "Creando oficinas para Owner" << listaOwners[idOwner].nombre << std::endl;

	std::cout << "Introduce el nombre de la oficina: ";
	std::cin >> sel[contOficinas].nombre;
	std::cout << std::endl;

	sel[contOficinas].id = contOficinas;

	std::cout << "Introduce el pais: ";
	std::cin >> sel[contOficinas].pais;

	std::cout << "Introduce el continente: ";
	std::cin >> sel[contOficinas].continente;
	std::cout << std::endl;

	//Inicializamos su historial a -1
	std::fill_n(sel[contOficinas].historial, 1024, -1);

	system("Pause");
}

void borrarOficinas(owners *listaOwners){
	system("CLS");
	int opcion;

	int idOwner;
	oficinas *sel = devolverOficinas(&listaOwners[0], &idOwner);
	//TODO DECREMENTAR CONTADOR??

	//consultarOficinas(&listaOwners[0]);
	for (int i = 0; i < MAXOFICINAS; i++) {
		if (sel[i].id != -1){
			std::cout << "ID de la oficina: " << sel[i].id << std::endl;
			std::cout << "Nombre de la oficina: " << sel[i].nombre << std::endl;
			std::cout << "Pais: " << sel[i].pais << std::endl;
			std::cout << "Continente: " << sel[i].continente << std::endl << std::endl;
		}
	}

	std::cout << "Que oficina deseas borrar?" << std::endl;
	int idOficina;
	std::cin >> idOficina;

	sel[idOficina].nombre = "";
	sel[idOficina].id = -1;
	sel[idOficina].pais = "";
	sel[idOficina].continente = "";

	std::cout << "Enhorabuena, su oficina numero " << idOficina << " ha sido borrado correctamente, gracias." << std::endl;
	
	//Reordenamos el array
	for (int i = 1; i < MAXNEGOS; i++){
		if (sel[i].id != -1)
			if (sel[i - 1].id == -1){
				sel[i - 1] = sel[i];

				sel[i - 1].id--;

				sel[i].nombre = "";
				sel[i].id = -1;
				sel[i].pais = "";
				sel[i].continente = "";
				//Inicializamos su historial a -1
				std::fill_n(sel[i].historial, 1024, -1);

				i = 1;
			}
	}

	listaOwners[idOwner].contOficinas--;

	system("Pause");
}

void consultarOficinas(owners *listaOwners){
	system("CLS");
	int idOwner;
	oficinas *sel = devolverOficinas(&listaOwners[0], &idOwner);

	std::cout << "La lista de oficinas actual es:" << std::endl << std::endl;
	for (int i = 0; i < MAXOFICINAS; i++) {
		if (sel[i].id != -1){
			std::cout << "ID de la oficina: " << sel[i].id << std::endl;
			std::cout << "Nombre de la oficina: " << sel[i].nombre << std::endl;
			std::cout << "Pais: " << sel[i].pais << std::endl;
			std::cout << "Continente: " << sel[i].continente << std::endl << std::endl;
		}
	}
	system("Pause");
}
