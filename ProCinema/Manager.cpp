#include <iostream>
#include <string>
#include "Manager.h"
#include "Pelicula.h"
#include "Archivos.h"
#include "Fecha.h"

using namespace std;

void Manager::cargarPelicula() {
    Archivos ArPel("peliculas.dat");

    int idPelicula = ArPel.getUltimoId()+1, clasificacion;
    string titulo, genero, nombreDirector, apellidoDirector;
    bool estado = 1;
    Fecha fecha;

    cout << "Id: " << idPelicula << endl;

    cout << "Ingrese el titulo: ";
    getline(cin, titulo);

    cout << "Ingrese el genero: ";
    getline(cin, genero);

    cout << "Ingrese el nombre del director: ";
    getline(cin, nombreDirector);

    cout << "Ingrese el genero del director: ";
    getline(cin, apellidoDirector);

    cout << "Ingrese la clasificacion: ";
    cin >> clasificacion;

    cout << "Ingrese la fecha: ";

    Pelicula peli(idPelicula, titulo, genero, nombreDirector, apellidoDirector, clasificacion, fecha, estado);

    if(ArPel.Guardar(peli)) {
        cout << "Se guardo correctamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}
//
//void Manager::mostrarCantidadRegistros() {
//    PostulanteArchivo pArchivo;
//
//    int cantidadRegistros = pArchivo.getCantidadRegistros();
//
//    cout << "La cantidad de registros son: " << cantidadRegistros << endl;
//}
//
void Manager::listarTodos() {
    Archivos ArPel("peliculas.dat");
    Pelicula peli;
    int cantidadRegistros = ArPel.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        peli = ArPel.Leer(i);

        cout << peli.toCSV() << endl;
    }
}
//
//void Manager::listarContratados() {
//    PostulanteArchivo pArchivo;
//    Postulante registro;
//
//    cout << "Los contratados son: " << endl;
//
//    int cantidad = pArchivo.getCantidadRegistros();
//
//    for (int i = 0; i < cantidad; i++) {
//        registro = pArchivo.leer(i);
//
//        if (registro.getContratado()) {
//            cout << "-----------" << endl;
//            cout << "Apellido:" << registro.getApellidos() << endl;
//            cout << "Nombre:" << registro.getNombres() << endl;
//            cout << endl;
//        }
//    }
//}
//
//void Manager::buscarPuestoExp() {
//    PostulanteArchivo pArchivo;
//    Postulante registro;
//
//    string puesto;
//    int exp;
//
//    cout << "Ingrese el puesto deseado: ";
//    cin.ignore();
//    getline(cin, puesto);
//    cout << "Ingrese los años de experiencia mínimos: ";
//    cin >> exp;
//
//    cout << "Los contratados son: " << endl;
//
//    int cantidad = pArchivo.getCantidadRegistros();
//
//    for (int i = 0; i < cantidad; i++) {
//        registro = pArchivo.leer(i);
//
//        if (registro.getPuesto() == puesto && registro.getAniosExperiencia() >= exp) {
//            cout << "-----------" << endl;
//            cout << "Apellido:" << registro.getApellidos() << endl;
//            cout << "Nombre:" << registro.getNombres() << endl;
//            cout << endl;
//        }
//    }
//
//}
