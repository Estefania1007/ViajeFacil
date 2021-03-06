/**
 *  Copyright 2015 ViajeFacil
 *  @author Hugo Ferrando Seage
 */

#include <string>
#include <iostream>
#include <sstream>
#include "entradaHistorial.hpp"

entradaHistorial::entradaHistorial() {}
entradaHistorial::~entradaHistorial() {}

bool entradaHistorial::getCreado() const { return creado; }
bool entradaHistorial::getModificado() const { return modificado; }
bool entradaHistorial::getBorrado() const { return borrado; }
std::size_t entradaHistorial::getAsientos() const { return asientos; }
std::string entradaHistorial::getOrigen() const { return origen; }
std::string entradaHistorial::getDestino() const { return destino; }
std::string entradaHistorial::getOficina() const { return oficina; }
std::string entradaHistorial::getPaisOficina() const { return paisOficina; }
std::string entradaHistorial::getContinenteOficina() const {
    return continenteOficina;
}
std::string entradaHistorial::getOwner() const { return owner; }

void entradaHistorial::setCreado(bool value) { creado = value; }
void entradaHistorial::setModificado(bool value) { modificado = value; }
void entradaHistorial::setBorrado(bool value) { borrado = value; }
void entradaHistorial::setAsientos(std::size_t value) { asientos = value; }
void entradaHistorial::setOrigen(const std::string &value) { origen = value; }
void entradaHistorial::setDestino(const std::string &value) { destino = value; }
void entradaHistorial::setOficina(const std::string &value) { oficina = value; }
void entradaHistorial::setPaisOficina(const std::string &value) {
    paisOficina = value;
}
void entradaHistorial::setContinenteOficina(const std::string &value) {
    continenteOficina = value;
}
void entradaHistorial::setOwner(const std::string &value) { owner = value; }

entradaHistorial::entradaHistorial(bool c, bool mo, bool bo, std::size_t as,
                                   std::string ori, std::string des,
                                   std::string own, std::string of,
                                   std::string paOf, std::string coOf) {
    creado = c;
    modificado = mo;
    borrado = bo;
    asientos = as;
    origen = ori;
    destino = des;
    owner = own;
    oficina = of;
    paisOficina = paOf;
    continenteOficina = coOf;
}

void entradaHistorial::writeToFile(std::ostream *f) {
    *f << creado << "\n" << modificado << "\n" << borrado << "\n"
      << asientos << "\n" << origen << "\n" << destino << "\n"
      << owner << "\n" << oficina << "\n" << paisOficina << "\n"
      << continenteOficina << "\n";
}

void entradaHistorial::readFromFile(std::istream *f) {
    std::string buffer;
    std::getline(*f, buffer);
    creado = (buffer == "1");
    std::getline(*f, buffer);
    modificado = (buffer == "1");
    std::getline(*f, buffer);
    borrado = (buffer == "1");
    std::getline(*f, buffer);
    std::istringstream(buffer) >> asientos;
    std::getline(*f, origen);
    std::getline(*f, destino);
    std::getline(*f, owner);
    std::getline(*f, oficina);
    std::getline(*f, paisOficina);
    std::getline(*f, continenteOficina);
}
