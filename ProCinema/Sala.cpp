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
    // Harcodeado
    int opcion = getTipoSala();
    string tipoSala;
    switch(opcion) {
        case 1:
            tipoSala = "Standard";
            break;
        case 2:
            tipoSala = "Premium";
            break;
        case 3:
            tipoSala = "3D";
            break;
        case 4:
            tipoSala = "4D";
            break;
        case 5:
            tipoSala = "IMAX";
            break;
    }

    // Harcodeado
    string estado;
    if (getEstado())
        estado = "EN FUNCIONAMIENTO";
    else
        estado = "FUERA DE SERVICIO";

    return "  ID de Sala N°" + to_string(getIdSala()+1) + "\n" +
           "  Tipo de Sala: " + tipoSala + "\n" +
           "  Cantidad de Butacas Totales: " + to_string(getButacasTotales()) + "\n" +
           "  Estado de la Sala: " + estado + "\n" +
           "===================================================";
}

//std::string Sala::mostrarCSV() {
//    return to_string(getIdSala()) + "," + to_string(getTipoSala()) + ","
//            + to_string(getButacasTotales()) + "," + to_string(getEstado());
//}
