/**
 *  Copyright 2015 ViajeFacil
 *  @author Hugo Ferrando Seage
 *  @author David Jimenez
 *  @author Serigo Cander
 */

#include "./peticion.hpp"
#include "./fecha.hpp"


std::shared_ptr<Nego> Peticion::getNeg() const
{
    return neg;
}

void Peticion::setNeg(const std::shared_ptr<Nego> &value)
{
    neg = value;
}
Peticion::Peticion()
    : plazasPedidas_(0) {}

Peticion::Peticion(std::size_t plazasPedidas)
    : plazasPedidas_(plazasPedidas) {}

Peticion::~Peticion() {}

void Peticion::setPlazasPedidas(size_t plazasPedidas) {
    plazasPedidas_ = plazasPedidas;
}

size_t Peticion::getPlazasPedidas() { return plazasPedidas_; }
