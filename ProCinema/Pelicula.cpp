#include "Fecha.h"
#include "Pelicula.h"
#include <cstring>
#include <string>

using namespace std;

Pelicula::Pelicula() {
    setIdPelicula(-1);
    setTitulo("");
    setGenero("");
    setNombreDirector("");
    setApellidoDirector("");
    setClasificacion(-1);
    setFechaEstreno(Fecha());
    setEstado(1);
}


Pelicula::Pelicula(int idPelicula, string titulo, string genero, string nombreDirector, string apellidoDirector,
                   int clasificacion, Fecha fechaEstreno, bool estado) {
    setIdPelicula(idPelicula);
    setTitulo(titulo);
    setGenero(genero);
    setNombreDirector(nombreDirector);
    setApellidoDirector(apellidoDirector);
    setClasificacion(clasificacion);
    setFechaEstreno(fechaEstreno);
    setEstado(estado);
}


int Pelicula::getIdPelicula() {
    return _idPelicula;
}
string Pelicula::getTitulo() {
    return _titulo;
}
string Pelicula::getGenero() {
    return _genero;
}
string Pelicula::getNombreDirector() {
    return _nombreDirector;
}
string Pelicula::getApellidoDirector() {
    return _apellidoDirector;
}
int Pelicula::getClasificacion() {
    return _clasificacion;
}
Fecha Pelicula::getFechaEstreno() {
    return _fechaEstreno;
}
bool Pelicula::getEstado() {
    return _estado;
}


void Pelicula::setIdPelicula(int idPelicula) {
    _idPelicula = idPelicula;
}
void Pelicula::setTitulo(string titulo) {
    strcpy(_titulo, titulo.c_str());
}
void Pelicula::setGenero(string genero) {
    strcpy(_genero, genero.c_str());
}
void Pelicula::setNombreDirector(string nombreDirector) {
    strcpy(_nombreDirector, nombreDirector.c_str());
}
void Pelicula::setApellidoDirector(string apellidoDirector) {
    strcpy(_apellidoDirector, apellidoDirector.c_str());
}
void Pelicula::setClasificacion(int clasificacion) {
    _clasificacion = clasificacion;
}
void Pelicula::setFechaEstreno(Fecha fechaEstreno) {
    _fechaEstreno = fechaEstreno;
}
void Pelicula::setEstado(bool estado) {
    _estado = estado;
}


std::string Pelicula::mostrar() {
    // Harcodeado
    string estado;
    if (getEstado())
        estado = "EN CARTELERA";
    else
        estado = "FUERA DE CARTELERA";

    return "  ID de Pel�cula N�" + to_string(getIdPelicula()+1) + "\n" +
           "  T�tulo de la Pel�cula: " + getTitulo() + "\n" +
           "  G�nero de la Pel�cula: " + getGenero() + "\n" +
           "  Nombre del Director: " + getNombreDirector() + "\n" +
           "  Apellido del Director: " + getApellidoDirector() + "\n" +
           "  Clasificaci�n de la Pel�cula: " + to_string(getClasificacion()) + "\n" +
           "  Fecha de Estreno: " + getFechaEstreno().toString(1) + "\n" +
           "  Estado de la Pel�cula: " + estado + "\n" +
           "===================================================";
}

std::string Pelicula::mostrarCSV() {
    return getTitulo() + "," + getGenero() + "," + getNombreDirector() + ","
           + getApellidoDirector() + "," + to_string(getClasificacion()) + ","
           + getFechaEstreno().toString(1) + "," + to_string(getEstado());
}
