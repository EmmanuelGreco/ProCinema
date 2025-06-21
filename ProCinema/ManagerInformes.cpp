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
