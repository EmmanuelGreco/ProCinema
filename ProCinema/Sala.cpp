#include "Sala.h"
#include <cstring>
#include <string>

using namespace std;

Sala::Sala() {
    setIdSala(-1);
    setTipoSala(-1);
    setButacasTotales(-1);
    setEstado(1);
}


Sala::Sala(int idSala, int tipoSala, int butacasTotales, bool estado) {
    setIdSala(idSala);
    setTipoSala(tipoSala);
    setButacasTotales(butacasTotales);
    setEstado(estado);
}


int Sala::getIdSala() {
    return _idSala;
}
int Sala::getTipoSala() {
    return _tipoSala;
}
int Sala::getButacasTotales() {
    return _butacasTotales;
}
bool Sala::getEstado() {
    return _estado;
}


void Sala::setIdSala(int idSala) {
    _idSala = idSala;
}
void Sala::setTipoSala(int tipoSala) {
    _tipoSala = tipoSala;
}
void Sala::setButacasTotales(int butacasTotales) {
    _butacasTotales = butacasTotales;
}
void Sala::setEstado(bool estado) {
    _estado = estado;
}


std::string Sala::mostrar() {
    return to_string(getIdSala()) + "," + to_string(getTipoSala()) + ","
            + to_string(getButacasTotales()) + "," + to_string(getEstado());
}
