#include "Membresia.h"
#include <cstring>
#include <string>


using namespace std;

Membresia::Membresia() {
    setIdMembresia(-1);
    setTipoMembresia(-1);
    setDescuentoMembresia(-1);
    setNombreMembresia("");
    setNombreMiembro("");
    setApellidoMiembro("");
    setDniMiembro(-1);
    setEmailMiembro("");
    setEstado(1);
}


Membresia::Membresia(int idMembresia, int tipoMembresia, int descuentoMembresia, std::string nombreMembresia, std::string nombreMiembro,
                     std::string apellidoMiembro, int dniMiembro, std::string emailMiembro, bool estado) {
    setIdMembresia(idMembresia);
    setTipoMembresia(tipoMembresia);
    setDescuentoMembresia(descuentoMembresia);
    setNombreMembresia(nombreMembresia);
    setNombreMiembro(nombreMiembro);
    setApellidoMiembro(apellidoMiembro);
    setDniMiembro(dniMiembro);
    setEmailMiembro(emailMiembro);
    setEstado(estado);
}


int Membresia::getIdMembresia() {
    return _idMembresia;
}
int Membresia::getTipoMembresia() {
    return _tipoMembresia;
}
int Membresia::getDescuentoMembresia() {
    return _descuentoMembresia;
}
string Membresia::getNombreMembresia() {
    return _nombreMembresia;
}
string Membresia::getNombreMiembro() {
    return _nombreMiembro;
}
string Membresia::getApellidoMiembro() {
    return _apellidoMiembro;
}
int Membresia::getDniMiembro() {
    return _dniMiembro;
}
string Membresia::getEmailMiembro() {
    return _emailMiembro;
}
bool Membresia::getEstado() {
    return _estado;
}


void Membresia::setIdMembresia(int idMembresia) {
    _idMembresia = idMembresia;
}
void Membresia::setTipoMembresia(int tipoMembresia) {
    _tipoMembresia = tipoMembresia;
}
void Membresia::setDescuentoMembresia(int descuentoMembresia) {
    _descuentoMembresia = descuentoMembresia;
}
void Membresia::setNombreMembresia(string nombreMembresia) {
    strcpy(_nombreMembresia, nombreMembresia.c_str());
}
void Membresia::setNombreMiembro(string nombreMiembro) {
    strcpy(_nombreMiembro, nombreMiembro.c_str());
}
void Membresia::setApellidoMiembro(string apellidoMiembro) {
    strcpy(_apellidoMiembro, apellidoMiembro.c_str());
}
void Membresia::setDniMiembro(int dniMiembro) {
    _dniMiembro = dniMiembro;
}
void Membresia::setEmailMiembro(string emailMiembro) {
    strcpy(_emailMiembro, emailMiembro.c_str());
}
void Membresia::setEstado(bool estado) {
    _estado = estado;
}


std::string Membresia::mostrar() {
    return to_string(getIdMembresia()) + "," + to_string(getTipoMembresia()) + "," + to_string(getDescuentoMembresia()) + ","
           + getNombreMembresia() + "," + getNombreMiembro() + "," + getApellidoMiembro() + "," + to_string(getDniMiembro()) + ","
           + getEmailMiembro() + "," + to_string(getEstado());
}
