#include <iostream>
#include <string>
#include "ManagerFuncion.h"
#include "Funcion.h"
#include "ArchivoFuncion.h"
#include "Fecha.h"
#include "ArchivoPelicula.h"
#include "Pelicula.h"
#include "Sala.h"
#include "ArchivoSala.h"

using namespace std;

ArchivoFuncion archivoFunciones("funciones.dat");


void ManagerFuncion::cargarFuncion() {
    int idFuncion = archivoFunciones.getUltimoId()+1, idPelicula, idSala, butacasDisponibles, idiomaFuncion;
    float importeFuncion;
    bool estado = 1;
    Fecha fechaFuncion;
    int posicion;
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    ArchivoSala archivoSalas("salas.dat");

    cout << "Id: " << idFuncion << endl;

    // Me traigo el ID de la Pelicula y lo asigno al idPelicula de la Función
    cout << "Ingrese el ID de la Película: ";
    cin >> idPelicula;
    posicion = archivoPeliculas.Buscar(idPelicula);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    idPelicula = pelicula.getIdPelicula();

    // Me traigo el ID de la Sala y lo asigno al idSala de la Función
    cout << "Ingrese el ID de la Sala: ";
    cin >> idSala;
    posicion = archivoSalas.Buscar(idSala);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    idSala = sala.getIdSala();

    // Por ahora asigna la cantidad de butacas de la sala, se le debe restar las ventas
    butacasDisponibles = sala.getButacasTotales();

    cout << "Ingrese el Idioma de la Función (1-Inglés, 2-Castellano, 3-Subtitulado): ";
    cin >> idiomaFuncion;

    cout << "Ingrese la Fecha de la Función: " << endl;
    fechaFuncion.cargar(1);

    // Esto habría que automatizarlo, dependiendo del día y del tipo de sala
    cout << "Ingrese el importe de la Función: ";
    cin >> importeFuncion;


    if(archivoFunciones.Guardar(Funcion(idFuncion, idPelicula, idSala, butacasDisponibles, idiomaFuncion,
                                         fechaFuncion, importeFuncion, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void ManagerFuncion::listarFunciones() {
    int cantidadRegistros = archivoFunciones.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoFunciones.Leer(i).mostrar() << endl;
    }
}
