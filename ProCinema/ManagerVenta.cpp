#include <iostream>
#include <string>
#include "ManagerVenta.h"
#include "Venta.h"
#include "ArchivoVenta.h"
#include "Fecha.h"

#include "ArchivoFuncion.h"
#include "Funcion.h"
#include "ArchivoMembresia.h"
#include "Membresia.h"
#include "ArchivoPelicula.h"
#include "Pelicula.h"

using namespace std;


void ManagerVenta::cargarVenta() {
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoFuncion archivoFunciones("funciones.dat");
    ArchivoMembresia archivoMembresias("membresias.dat");
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idVenta = archivoVentas.getUltimoId()+1, idFuncion, idMembresia, cantidadEntradas;
    float importeTotal;
    bool estado = 1;
    Fecha fechaVenta;

    int posicion;
    Membresia membresia;


    cout << "Id de venta: " << idVenta << endl;
    //fecha se obtiene automaticamente
    cout << "Fecha y hora: ";
    fechaVenta.setFechaYHoraActual();
    cout << fechaVenta.toString(2) << endl;

    cout << "Ingrese el id de membresía (si el cliente no es miembro ingrese 0): ";
    cin >> idMembresia;
    if (idMembresia != 0) {
        posicion = archivoMembresias.Buscar(idMembresia);
        if (posicion == -1) {
            cout << "Id NO encontrado!" << endl;
            return;
        }
        membresia = archivoMembresias.Leer(posicion);
        idMembresia = membresia.getIdMembresia();
        cout << "Registrando venta para " << membresia.getNombreMiembro() << " " << membresia.getApellidoMiembro() <<
             " - " << membresia.getNombreMembresia() << endl;
    } else {
        cout << "Cliente no registrado." << endl;
    }

    cout << endl << "Ingrese el id de función: ";
    cin >> idFuncion;
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "Id NO encontrado!" << endl;
        return;
    }

    Funcion funcion = archivoFunciones.Leer(posicion);
    idFuncion = funcion.getIdFuncion();
    cout << "Película: " << archivoPeliculas.Leer(archivoPeliculas.Buscar(funcion.getIdPelicula())).getTitulo() << endl;
    cout << "Fecha de la función: " << funcion.getFechaFuncion().toString(1) << endl;


    cout << funcion.getButacasDisponibles() << " butacas disponibles." << endl;
    cout << "Ingrese la cantidad de entradas: ";
    cin >> cantidadEntradas;
    if(cantidadEntradas <= funcion.getButacasDisponibles()) {
        funcion.setButacasDisponibles(funcion.getButacasDisponibles() - cantidadEntradas);
    } else {
        cout << "No hay suficientes butacas disponibles!" << endl;
        return;
    }

    //importe se obtiene de cantidadEntradas * funcion._importeFuncion;
    importeTotal = funcion.getImporteFuncion() * cantidadEntradas;
    if(idMembresia != 0) {
        cout << "Subtotal: " << importeTotal << endl;
        cout << "Descuento: " << membresia.getDescuentoMembresia() << "%" << endl;
        importeTotal = (importeTotal * (100-membresia.getDescuentoMembresia())/ 100);
    }
    cout << "Total: " << importeTotal << endl;
    if(archivoVentas.Guardar(Venta(idVenta, idFuncion, idMembresia, cantidadEntradas, fechaVenta, importeTotal, estado)) &&
            archivoFunciones.Modificar(funcion, posicion)) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void ManagerVenta::listarVentas() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadRegistros = archivoVentas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoVentas.Leer(i).mostrar() << endl;
    }
}

void ManagerVenta::modificarVenta() {
    int id, posicionAModificar, posicion;
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoFuncion archivoFunciones("funciones.dat");
    ArchivoMembresia archivoMembresias("membresias.dat");
    ArchivoPelicula archivoPeliculas("peliculas.dat");

    cout << "Ingrese el Id de la Venta a Modificar: ";
    cin >> id;
    posicionAModificar = archivoVentas.Buscar(id);
    if (posicionAModificar == -1) {
        cout << "Id no encontrado!" << endl;
        return;
    }
    Venta venta = archivoVentas.Leer(posicionAModificar);
    cout << "1. " << venta.getIdFuncion() << endl;
    cout << "2. " << venta.getIdMembresia() << endl;
    cout << "3. " << venta.getCantidadEntradas() << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;

    int entero, idFuncion, importeTotal;
    float decimal;
    Fecha fechaVenta;
    Funcion funcion;
    Membresia membresia;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo id de función: ";
        cin >> entero;
        posicion = archivoFunciones.Buscar(entero);
        if (posicion == -1) {
            cout << "Id NO encontrado!" << endl;
            return;
        }

        funcion = archivoFunciones.Leer(posicion);
        entero = funcion.getIdFuncion();
        cout << "Película: " << archivoPeliculas.Leer(archivoPeliculas.Buscar(funcion.getIdPelicula())).getTitulo() << endl;
        cout << "Fecha de la función: " << funcion.getFechaFuncion().toString(1) << endl;
        venta.setIdFuncion(entero);
        break;
    case 2:
        cout << "Elija el nuevo id de membresía: ";
        cin >> entero;
        if (entero != 0) {
            posicion = archivoMembresias.Buscar(entero);
            if (posicion == -1) {
                cout << "Id NO encontrado!" << endl;
                return;
            }
            membresia = archivoMembresias.Leer(posicion);
            entero = membresia.getIdMembresia();
            cout << "Registrando venta para " << membresia.getNombreMiembro() << " " << membresia.getApellidoMiembro() <<
                 " - " << membresia.getNombreMembresia() << endl;
        }
        venta.setIdMembresia(entero);
        break;
    case 3:
        funcion = archivoFunciones.Leer(archivoFunciones.Buscar(venta.getIdFuncion()));
        cout << "Elija la nueva cantidad de entradas: ";
        cin >> entero;
        if(entero <= funcion.getButacasDisponibles()) {
            importeTotal = funcion.getImporteFuncion() * entero;
            membresia = archivoMembresias.Leer(archivoMembresias.Buscar(venta.getIdMembresia()));
            if(venta.getIdMembresia() != 0) {
                cout << "Subtotal: " << importeTotal << endl;
                cout << "Descuento: " << membresia.getDescuentoMembresia() << "%" << endl;
                importeTotal = (importeTotal * (100-membresia.getDescuentoMembresia())/ 100);
            }
            cout << "Total: " << importeTotal << endl;

            funcion.setButacasDisponibles(funcion.getButacasDisponibles() - entero);
            venta.setCantidadEntradas(entero);
            venta.setImporteTotal(importeTotal);
        } else {
            cout << "No hay suficientes butacas disponibles!" << endl;
            return;
        }

        break;
    }

    if(archivoVentas.Modificar(venta, posicionAModificar)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerVenta::cambiarEstadoVenta() {
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoFuncion archivoFunciones("funciones.dat");
    Funcion funcion;

    int id, posicion;

    cout << "Ingrese el Id de la venta a cancelar: ";
    cin >> id;
    posicion = archivoVentas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!" << endl;
        return;
    }
    Venta venta = archivoVentas.Leer(posicion);
    if (venta.getEstado() == 0) {
        cout << "Esta Venta ya fue dada de baja anteriormente." << endl;
        return;
    }
    venta.mostrar();
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        funcion = archivoFunciones.Leer(archivoFunciones.Buscar(venta.getIdFuncion()));
        funcion.setButacasDisponibles(funcion.getButacasDisponibles() + venta.getCantidadEntradas());
        archivoFunciones.Modificar(funcion, archivoFunciones.Buscar(venta.getIdFuncion()));
        venta.setEstado(0);
        archivoVentas.Modificar(venta, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
    cout << endl;
}
