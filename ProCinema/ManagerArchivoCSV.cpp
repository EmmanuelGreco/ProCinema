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
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idPelicula = archivoPeliculas.getUltimoId()+1, clasificacion;
    string titulo, genero, nombreDirector, apellidoDirector;
    bool estado;
    Fecha fechaEstreno;

    cout << "ID: " << idPelicula << endl;

    cout << "Ingrese el Título: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Ingrese el Género: ";
    getline(cin, genero);

    cout << "Ingrese el Nombre del Director: ";
    getline(cin, nombreDirector);

    cout << "Ingrese el Apellido del Director: ";
    getline(cin, apellidoDirector);

    cout << "Ingrese la Clasificación: ";
    cin >> clasificacion;

    cout << "Ingrese la Fecha de Estreno: " << endl;
    //cin.ignore();
    fechaEstreno.cargar(1);

    cout << "Ingrese el Estado: ";
    cin >> estado;


    if(archivoPeliculas.Guardar(Pelicula(idPelicula, titulo, genero, nombreDirector, apellidoDirector,
                                         clasificacion, fechaEstreno, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}


void ManagerArchivoCSV::listarSalasCSV() {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadRegistros = archivoSalas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoSalas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarSalasCSV() {
    ArchivoSala archivoSalas("salas.dat");
    int idSala = archivoSalas.getUltimoId()+1, tipoSala, butacasTotales;
    bool estado;

    cout << "ID: " << idSala << endl;

    cout << "Ingrese el Tipo de Sala (1-Standard, 2-Premium, 3-3D, 4-4D, 5-IMAX): ";
    cin >> tipoSala;

    cout << "Ingrese la cantidad de Bucatas Totales: ";
    cin >> butacasTotales;

    cout << "Ingrese el Estado: ";
    cin >> estado;

    if(archivoSalas.Guardar(Sala(idSala, tipoSala, butacasTotales, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}


void ManagerArchivoCSV::listarFuncionesCSV() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadRegistros = archivoFunciones.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoFunciones.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarFuncionesCSV() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idFuncion = archivoFunciones.getUltimoId()+1, idPelicula, idSala, butacasDisponibles, idiomaFuncion;
    float importeFuncion;
    bool estado;
    Fecha fechaFuncion;

    cout << "ID: " << idFuncion << endl;

    cout << "Ingrese el ID de la Película: ";
    //cin.ignore();
    cin >> idPelicula;

    cout << "Ingrese el ID de la Sala: ";
    cin >> idSala;

    cout << "Ingrese las Butacas Disponibles de la Sala: ";
    cin >> butacasDisponibles;

    cout << "Ingrese el Idioma de la Función (1-Inglés, 2-Castellano, 3-Subtitulado): ";
    cin >> idiomaFuncion;

    cout << "Ingrese la Fecha de la Función: " << endl;
    //cin.ignore();
    fechaFuncion.cargar(1);

    cout << "Ingrese el importe de la Función: ";
    cin >> importeFuncion;

    cout << "Ingrese el Estado: ";
    cin >> estado;

    if(archivoFunciones.Guardar(Funcion(idFuncion, idPelicula, idSala, butacasDisponibles, idiomaFuncion,
                                        fechaFuncion, importeFuncion, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}


void ManagerArchivoCSV::listarMembresiasCSV() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int cantidadRegistros = archivoMembresias.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoMembresias.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarMembresiasCSV() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idMembresia = archivoMembresias.getUltimoId()+1, tipoMembresia, descuentoMembresia, dniMiembro;
    string nombreMembresia, nombreMiembro, apellidoMiembro, emailMiembro;
    bool estado;

    cout << "ID: " << idMembresia << endl;

    cout << "Ingrese el Tipo de Membresía (1-Plus, 2-Premium, 3-VIP): ";
    //cin.ignore();
    cin >> tipoMembresia;

    cout << "Ingrese el Descuento de Membresía";
    cin >> descuentoMembresia;

    cout << "Ingrese el Nombre de Membresía";
    cin.ignore();
    getline(cin, nombreMembresia);

    cout << "Ingrese el Nombre del Miembro: ";
    getline(cin, nombreMiembro);

    cout << "Ingrese el Apellido del Miembro: ";
    getline(cin, apellidoMiembro);

    cout << "Ingrese el DNI del Miembro: ";
    cin >> dniMiembro;

    cout << "Ingrese el Email del Miembro: ";
    cin.ignore();
    getline(cin, emailMiembro);

    cout << "Ingrese el Estado: ";
    cin >> estado;

    if(archivoMembresias.Guardar(Membresia(idMembresia, tipoMembresia, descuentoMembresia, nombreMembresia,
                                           nombreMiembro, apellidoMiembro, dniMiembro, emailMiembro, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}


void ManagerArchivoCSV::listarVentasCSV() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadRegistros = archivoVentas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoVentas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarVentasCSV() {
    ArchivoVenta archivoVentas("ventas.dat");
    int idVenta = archivoVentas.getUltimoId()+1, idFuncion, idMembresia, cantidadEntradas;
    float importeTotal;
    bool estado;
    Fecha fechaVenta;

    cout << "ID de Venta: " << idVenta << endl;

    cout << "Ingrese el ID de la Función: ";
    cin >> idFuncion;

    cout << "Ingrese el ID de Membresía (Si el cliente no es Miembro, Ingrese 0): ";
    cin >> idMembresia;

    cout << "Ingrese la Cantidad de Entradas: ";
    cin >> cantidadEntradas;

    cout << "Ingrese la Fecha de la Función: " << endl;
    //cin.ignore();
    fechaVenta.cargar(1);

    cout << "Ingrese el Importe Total: ";
    cin >> importeTotal;

    cout << "Ingrese el Estado: ";
    cin >> estado;

    if(archivoVentas.Guardar(Venta(idVenta, idFuncion, idMembresia, cantidadEntradas, fechaVenta, importeTotal, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}
