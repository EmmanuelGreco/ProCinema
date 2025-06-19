#include "Fecha.h"
#include "Venta.h"
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

Venta::Venta() {
    setIdVenta(-1);
    setIdFuncion(0);
    setIdMembresia(0);
    setCantidadEntradas(0);
    setFechaVenta(Fecha());
    setImporteTotal(0.0);
    setEstado(1);
}


Venta::Venta(int idVenta, int idFuncion, int idMembresia, int cantidadEntradas, Fecha fechaVenta,
             float importeTotal, bool estado) {
    setIdVenta(idVenta);
    setIdFuncion(idFuncion);
    setIdMembresia(idMembresia);
    setCantidadEntradas(cantidadEntradas);
    setFechaVenta(fechaVenta);
    setImporteTotal(importeTotal);
    setEstado(estado);
}


int Venta::getIdVenta() {
    return _idVenta;
}
int Venta::getIdFuncion() {
    return _idFuncion;
}
int Venta::getIdMembresia() {
    return _idMembresia;
}
int Venta::getCantidadEntradas() {
    return _cantidadEntradas;
}
Fecha Venta::getFechaVenta() {
    return _fechaVenta;
}
float Venta::getImporteTotal() {
    return _importeTotal;
}
bool Venta::getEstado() {
    return _estado;
}


void Venta::setIdVenta(int idVenta) {
    _idVenta = idVenta;
}
void Venta::setIdFuncion(int idFuncion) {
    _idFuncion = idFuncion;
}
void Venta::setIdMembresia(int idMembresia) {
    _idMembresia = idMembresia;
}
void Venta::setCantidadEntradas(int cantidadEntradas) {
    _cantidadEntradas = cantidadEntradas;
}
void Venta::setFechaVenta(Fecha fechaVenta) {
    _fechaVenta = fechaVenta;
}
void Venta::setImporteTotal(float importeTotal) {
    _importeTotal = importeTotal;
}
void Venta::setEstado(bool estado) {
    _estado = estado;
}

std::string Venta::mostrar() {
    ostringstream redondeoImporteTotal;
    redondeoImporteTotal << fixed << setprecision(2) << getImporteTotal();
    return to_string(getIdVenta()) + "," + to_string(getIdFuncion()) + "," + to_string(getIdMembresia()) + "," +
    to_string(getCantidadEntradas()) + "," + getFechaVenta().toString(2) + "," + redondeoImporteTotal.str() +
    "," + to_string(getEstado());
}
