#include <iostream>
#include <string>
#include <sstream>                  //para procesar csv
#include <algorithm>                //para poder convertir floats

#include "ManagerArchivoCSV.h"
#include "ArchivoPelicula.h"
#include "Pelicula.h"
#include "ArchivoSala.h"
#include "Sala.h"
#include "ArchivoFuncion.h"
#include "Funcion.h"
#include "ArchivoMembresia.h"
#include "Membresia.h"
#include "ArchivoVenta.h"
#include "Venta.h"
#include "Fecha.h"

using namespace std;


void ManagerArchivoCSV::leerPeliculasCSV() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadRegistros = archivoPeliculas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoPeliculas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarPeliculasCSV() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idPelicula;
//    clasificacion, dia, mes, anio;
//    string titulo, genero, nombreDirector, apellidoDirector;
//    bool estado;
//    Fecha fechaEstreno;

    string csv;
    string parseado[9];

    cout << "Ingrese la cadena CSV (o escriba \"0\" para finalizar la carga): " << endl;
    cin.ignore();

    while (getline(cin, csv)) {
        if (csv == "0" || csv == "") break;
        idPelicula = archivoPeliculas.getUltimoId()+1;
        cout << "ID: " << idPelicula + 1 << endl;

        stringstream ss(csv);
        string campo;

        int indice = 0;
        while (getline(ss, campo, ',')) {
            if (indice == 5) {
                stringstream fecha(campo);
                string campo_fecha;
                while (getline(fecha, campo_fecha, '/')) {
                    parseado[indice] = campo_fecha;
                    indice++;
                }
            } else {
                parseado[indice] = campo;
                indice++;
            }
        }


        if(archivoPeliculas.Guardar(Pelicula(idPelicula, parseado[0], parseado[1], parseado[2], parseado[3], stoi(parseado[4]),
                                             Fecha(stoi(parseado[5]), stoi(parseado[6]), stoi(parseado[7])), stoi(parseado[8])))) {
            cout << "La película \"" << parseado[0] << "\" se guardo Exitosamente!" << endl << endl;
        } else {
            cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
        }
    }
}

void ManagerArchivoCSV::leerSalasCSV() {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadRegistros = archivoSalas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoSalas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarSalasCSV() {
    ArchivoSala archivoSalas("salas.dat");
    int idSala;
//    tipoSala, butacasTotales;
//    bool estado;

    string csv;
    int parseado[3];

    cout << "Ingrese la cadena CSV (o escriba \"0\" para finalizar la carga): " << endl;
    cin.ignore();

    while (getline(cin, csv)) {
        if (csv == "0" || csv == "") break;
        idSala = archivoSalas.getUltimoId()+1;
        cout << "ID: " << idSala + 1<< endl;

        stringstream ss(csv);
        string campo;

        int indice = 0;
        while (getline(ss, campo, ',')) {
            parseado[indice] = stoi(campo);
            indice++;
        }

        if(archivoSalas.Guardar(Sala(idSala, parseado[0], parseado[1], parseado[2]))) {
            cout << "Se guardo Exitosamente!" << endl;
        } else {
            cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
        }
    }
}

void ManagerArchivoCSV::leerFuncionesCSV() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadRegistros = archivoFunciones.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoFunciones.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarFuncionesCSV() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idFuncion;
//    idPelicula, idSala, butacasDisponibles, idiomaFuncion;
//    float importeFuncion;
//    bool estado;
//    Fecha fechaFuncion;


    string csv;
    string parseado[11];

    cout << "Ingrese la cadena CSV (o escriba \"0\" para finalizar la carga): " << endl;
    cin.ignore();

    while (getline(cin, csv)) {
        if (csv == "0" || csv == "") break;
        idFuncion = archivoFunciones.getUltimoId()+1;
        cout << "ID: " << idFuncion + 1 << endl;

        stringstream ss(csv);
        string campo;

        int indice = 0;
        while (getline(ss, campo, ',')) {
            if (indice == 4) {
                stringstream fecha(campo);
                string campo_fecha;
                while (getline(fecha, campo_fecha, '/')) {
                    if (indice == 6) {
                        ///2026 - 00:00
                        ///[2026] - [00]:[00]
                        parseado[6] = campo_fecha.substr(0, 4);
                        parseado[7] = campo_fecha.substr(7, 2);
                        parseado[8] = campo_fecha.substr(10, 2);
                        indice += 2;
                    } else {
                        parseado[indice] = campo_fecha;
                    }
                    indice++;
                }
            } else {
                parseado[indice] = campo;
                indice++;
            }
        }
        replace(parseado[9].begin(), parseado[9].end(), '.', ',');      //permite parsear el float con stof();



        if(archivoFunciones.Guardar(Funcion(idFuncion, stoi(parseado[0]), stoi(parseado[1]), stoi(parseado[2]), stoi(parseado[3]),
                                            Fecha(stoi(parseado[4]), stoi(parseado[5]), stoi(parseado[6]),
                                                    stoi(parseado[7]), stoi(parseado[8])),
                                            stof(parseado[9]), stoi(parseado[10])))) {
            cout << "Se guardo Exitosamente!" << endl;
        } else {
            cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
        }
    }
}

void ManagerArchivoCSV::leerMembresiasCSV() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int cantidadRegistros = archivoMembresias.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoMembresias.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarMembresiasCSV() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idMembresia;
//    , tipoMembresia, descuentoMembresia, dniMiembro;
//    string nombreMembresia, nombreMiembro, apellidoMiembro, emailMiembro;
//    bool estado;


    string csv;
    string parseado[7];

    cout << "Ingrese la cadena CSV (o escriba \"0\" para finalizar la carga): " << endl;
    cin.ignore();

    while (getline(cin, csv)) {
        if (csv == "0" || csv == "") break;
        idMembresia = archivoMembresias.getUltimoId()+1;
        cout << "ID: " << idMembresia + 1 << endl;

        stringstream ss(csv);
        string campo;

        int indice = 0;
        while (getline(ss, campo, ',')) {
            parseado[indice] = campo;
            indice++;
        }

        if(archivoMembresias.Guardar(Membresia(idMembresia, stoi(parseado[0]), stoi(parseado[1]), parseado[2], parseado[3],
                                               parseado[4], stoi(parseado[5]), parseado[6], stoi(parseado[7])))) {
            cout << "Se guardo Exitosamente!" << endl;
        } else {
            cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
        }
    }
}

void ManagerArchivoCSV::leerVentasCSV() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadRegistros = archivoVentas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoVentas.Leer(i).mostrarCSV() << endl;
    }
}

void ManagerArchivoCSV::cargarVentasCSV() {
    ArchivoVenta archivoVentas("ventas.dat");
    int idVenta;
//    idFuncion, idMembresia, cantidadEntradas;
//    float importeTotal;
//    bool estado;
//    Fecha fechaVenta;

    string csv;
    string parseado[10];

    cout << "Ingrese la cadena CSV (o escriba \"0\" para finalizar la carga): " << endl;
    cin.ignore();

    while (getline(cin, csv)) {
        if (csv == "0" || csv == "") break;
        idVenta = archivoVentas.getUltimoId()+1;
        cout << "ID: " << idVenta + 1 << endl;

        stringstream ss(csv);
        string campo;

        int indice = 0;
        while (getline(ss, campo, ',')) {
            if (indice == 3) {
                stringstream fecha(campo);
                string campo_fecha;
                while (getline(fecha, campo_fecha, '/')) {
                    if (indice == 5) {
                        ///2026 - 00:00
                        ///[2026] - [00]:[00]
                        parseado[5] = campo_fecha.substr(0, 4);
                        parseado[6] = campo_fecha.substr(7, 2);
                        parseado[7] = campo_fecha.substr(10, 2);
                        indice += 2;
                    } else {
                        parseado[indice] = campo_fecha;
                    }
                    indice++;
                }
            } else {
                parseado[indice] = campo;
                indice++;
            }
        }

        replace(parseado[8].begin(), parseado[8].end(), '.', ',');      //permite parsear el float con stof();


        if(archivoVentas.Guardar(Venta(idVenta, stoi(parseado[0]), stoi(parseado[1]), stoi(parseado[2]),
                                       Fecha(stoi(parseado[3]), stoi(parseado[4]), stoi(parseado[5]), stoi(parseado[6]), stoi(parseado[7])),
                                       stof(parseado[8]), stoi(parseado[9])))) {
            cout << "Se guardo Exitosamente!" << endl;
        } else {
            cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
        }
    }
}
