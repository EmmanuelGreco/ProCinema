#include <iostream>
#include <string>
#include <iomanip>


#include "ManagerInformes.h"

#include "ArchivoPelicula.h"
#include "Pelicula.h"
#include "ArchivoVenta.h"
#include "Venta.h"
#include "ArchivoFuncion.h"
#include "Funcion.h"


using namespace std;


void ManagerInformes::topCinco() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadPeliculas = archivoPeliculas.CantidadRegistros();
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");

    ///No se puede hacer un array bidimensional con new. Se harán dos vectores.
    ///En el primero se guarda el id de la pelicula, en el otro su recaudacion.
    float *totalesPeliculas = nullptr;
    int *idsPeliculas = nullptr;
    totalesPeliculas = new float[cantidadPeliculas] {0.0};
    idsPeliculas = new int[cantidadPeliculas] {0};
    if(totalesPeliculas == nullptr || idsPeliculas == nullptr) {
        cout << "No pudo solicitar memoria" << endl;
        exit(-1);
    }

    ///para cada película
    for (int i = 0; i < cantidadPeliculas; i++) {
        Pelicula pelicula = archivoPeliculas.Leer(i);
        idsPeliculas[i] = pelicula.getIdPelicula();
        ///encontrar ventas asociadas y sumar
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);
            Funcion funcion = archivoFunciones.Leer(venta.getIdFuncion());

            if (idsPeliculas[i] == funcion.getIdPelicula()) totalesPeliculas[i] += venta.getImporteTotal();
        }
    }

    ///ORDENAMIENTO DE VECTORES (BUBBLE)
    for (int i = 0; i < cantidadPeliculas - 1; i++) {
        for (int j = 0; j < cantidadPeliculas - i - 1; j++) {
            if (totalesPeliculas[j] < totalesPeliculas[j + 1]) {
                float temporalTotales = totalesPeliculas[j];
                int temporalIds = idsPeliculas[j];

                totalesPeliculas[j] = totalesPeliculas[j + 1];
                idsPeliculas[j] = idsPeliculas[j + 1];

                totalesPeliculas[j + 1] = temporalTotales;
                idsPeliculas[j + 1] = temporalIds;
            }
        }
    }


    cout << "Top 5 peliculas mas taquilleras de la historia:" << endl;
    if (cantidadPeliculas < 5) {
        for (int i = 0; i < cantidadPeliculas; i++) {
            cout << i + 1 << ". ";
            cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
            cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
        }
        for (int i = cantidadPeliculas; i < 5; i++) {
            cout << i + 1 << ". --- " << endl;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << " - ";
            cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
            cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
        }
    }

    delete []totalesPeliculas;
    delete []idsPeliculas;
}

void ManagerInformes::recaudacionPorPelicula() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadPeliculas = archivoPeliculas.CantidadRegistros();
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");

    ///No se puede hacer un array bidimensional con new. Se harán dos vectores.
    ///En el primero se guarda el id de la pelicula, en el otro su recaudacion.
    float *totalesPeliculas = nullptr;
    int *idsPeliculas = nullptr;
    totalesPeliculas = new float[cantidadPeliculas] {0.0};
    idsPeliculas = new int[cantidadPeliculas] {0};
    if(totalesPeliculas == nullptr || idsPeliculas == nullptr) {
        cout << "No pudo solicitar memoria" << endl;
        exit(-1);
    }

    ///para cada película
    for (int i = 0; i < cantidadPeliculas; i++) {
        Pelicula pelicula = archivoPeliculas.Leer(i);
        idsPeliculas[i] = pelicula.getIdPelicula();
        ///encontrar ventas asociadas y sumar
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);
            Funcion funcion = archivoFunciones.Leer(venta.getIdFuncion());

            if (idsPeliculas[i] == funcion.getIdPelicula()) totalesPeliculas[i] += venta.getImporteTotal();
        }
    }

    cout << "Recaudacion por pelicula:" << endl;
    for (int i = 0; i < cantidadPeliculas; i++) {
        cout << "ID: " << i + 1 << " - ";
        cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
        cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
    }
}

void ManagerInformes::recaudacionAnual() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();

    cout << "Ingrese un año para consultar: ";
    int anioAConsultar;
    cin >> anioAConsultar;
    while(anioAConsultar < 0 || anioAConsultar > 9999) {
        cout << "Ingrese un año valido: ";
        cin >> anioAConsultar;
    }


    int cantidadEncontrados = 0;
    int totales[13] {}; //en [0] se guarda el total anual, en los otros los de cada mes.
    string meses[12] = {"ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"};

    for (int i = 0; i < cantidadVentas; i++) {
        Venta venta = archivoVentas.Leer(i);
        if (venta.getFechaVenta().getAnio() == anioAConsultar) {
            totales[0] += venta.getImporteTotal();
            totales[venta.getFechaVenta().getMes()] += venta.getImporteTotal();
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) {
        cout << "No se encontraron ventas para el año " << anioAConsultar << "!" << endl;
    } else {
        for (int i = 0; i < 13; i++) {
            if (i==0) cout << "VENTAS DEL AÑO " << anioAConsultar << ":" << endl;
            else cout << meses[i-1] << ": " << totales[i] << endl;
        }
        cout << "TOTAL: " << totales[0] << endl;
    }
}
