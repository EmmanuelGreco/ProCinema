#include "Fecha.h"
#include "Funcion.h"
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

Funcion::Funcion() {
    setIdFuncion(-1);
    setIdPelicula(-1);
    setIdSala(-1);
    setButacasDisponibles(-1);
    setIdiomaFuncion(-1);
    setFechaFuncion(Fecha());
    setImporteFuncion(-1);
    setEstado(1);
}


Funcion::Funcion(int idFuncion, int idPelicula, int idSala, int butacasDisponibles, int idiomaFuncion,
                   Fecha fechaFuncion, float importeFuncion, bool estado) {
    setIdFuncion(idFuncion);
    setIdPelicula(idPelicula);
    setIdSala(idSala);
    setButacasDisponibles(butacasDisponibles);
    setIdiomaFuncion(idiomaFuncion);
    setFechaFuncion(fechaFuncion);
    setImporteFuncion(importeFuncion);
    setEstado(estado);
}


int Funcion::getIdFuncion() {
    return _idFuncion;
}
int Funcion::getIdPelicula() {
    return _idPelicula;
}
int Funcion::getIdSala() {
    return _idSala;
}
int Funcion::getButacasDisponibles() {
    return _butacasDisponibles;
}
int Funcion::getIdiomaFuncion() {
    return _idiomaFuncion;
}
Fecha Funcion::getFechaFuncion() {
    return _fechaFuncion;
}
float Funcion::getImporteFuncion() {
    return _importeFuncion;
}
bool Funcion::getEstado() {
    return _estado;
}


void Funcion::setIdFuncion(int idFuncion) {
    _idFuncion = idFuncion;
}
void Funcion::setIdPelicula(int idPelicula) {
    _idPelicula = idPelicula;
}
void Funcion::setIdSala(int idSala) {
    _idSala = idSala;
}
void Funcion::setButacasDisponibles(int butacasDisponibles) {
    _butacasDisponibles = butacasDisponibles;
}
void Funcion::setIdiomaFuncion(int idiomaFuncion) {
    _idiomaFuncion = idiomaFuncion;
}
void Funcion::setFechaFuncion(Fecha fechaFuncion) {
    _fechaFuncion = fechaFuncion;
}
void Funcion::setImporteFuncion(float importeFuncion) {
    _importeFuncion = importeFuncion;
}
void Funcion::setEstado(bool estado) {
    _estado = estado;
}


std::string Funcion::mostrar() {
    ostringstream redondeoImporteFuncion;
    redondeoImporteFuncion << fixed << setprecision(2) << getImporteFuncion();
    return to_string(getIdFuncion()) + "," + to_string(getIdPelicula()) + "," + to_string(getIdSala()) + ","
            + to_string(getButacasDisponibles()) + "," + to_string(getIdiomaFuncion()) + "," + getFechaFuncion().toString(1) + ","
            + redondeoImporteFuncion.str() + "," + to_string(getEstado());
}
