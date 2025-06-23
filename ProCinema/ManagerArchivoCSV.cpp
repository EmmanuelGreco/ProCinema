#include <iostream>
#include <string>
#include "ManagerArchivoCSV.h"
#include "ArchivoPelicula.h"
#include "ArchivoSala.h"
#include "ArchivoFuncion.h"
#include "ArchivoMembresia.h"
#include "ArchivoVenta.h"

using namespace std;


void ManagerArchivoCSV::listarPeliculasCSV() {
ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadRegistros = archivoPeliculas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoPeliculas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarPeliculasCSV() {
}


void ManagerArchivoCSV::listarSalasCSV() {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadRegistros = archivoSalas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoSalas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarSalasCSV() {
}


void ManagerArchivoCSV::listarFuncionesCSV() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadRegistros = archivoFunciones.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoFunciones.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarFuncionesCSV() {
}


void ManagerArchivoCSV::listarMembresiasCSV() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int cantidadRegistros = archivoMembresias.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoMembresias.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarMembresiasCSV() {
}


void ManagerArchivoCSV::listarVentasCSV() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadRegistros = archivoVentas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoVentas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarVentasCSV() {
}
