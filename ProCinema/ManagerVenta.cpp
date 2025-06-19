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

ArchivoVenta archivoVentas("ventas.dat");


void ManagerVenta::cargarVenta() {
    int idVenta = archivoVentas.getUltimoId()+1, idFuncion,
        idMembresia, cantidadEntradas;
    float importeTotal;
    bool estado = 1;
    Fecha fechaVenta;

    int posicion;
    ArchivoFuncion archivoFunciones("funciones.dat");
    ArchivoMembresia archivoMembresias("membresias.dat");
    Membresia membresia;
    ArchivoPelicula archivoPeliculas("peliculas.dat");



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
            cout << "Id no encontrado!";
            return;
        }
        membresia = archivoMembresias.Leer(posicion);
        idMembresia = membresia.getIdMembresia();
        cout << "Registrando venta para " << membresia.getNombreMiembro() << " " << membresia.getApellidoMiembro() << endl;
    }

    cout << "Ingrese el id de función: ";
    cin >> idFuncion;
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    idFuncion = funcion.getIdFuncion();
    cout << "Película: " << archivoPeliculas.Leer(archivoPeliculas.Buscar(funcion.getIdPelicula())).getTitulo() << endl;
    cout << "Fecha de la función: " << funcion.getFechaFuncion().toString(1) << endl;


    cout << "Ingrese la cantidad de entradas: ";
    cin >> cantidadEntradas;


    //importe se obtiene de cantidadEntradas * funcion._importeFuncion;
    importeTotal = funcion.getImporteFuncion() * cantidadEntradas;
    if(idMembresia != 0) {
        cout << "Subtotal: " << importeTotal << endl;
        importeTotal *= (1.00-((float)membresia.getDescuentoMembresia()/100));
    }
    cout << "Total: " << importeTotal << endl;
    if(archivoVentas.Guardar(Venta(idVenta, idFuncion, idMembresia, cantidadEntradas,
                                   fechaVenta, importeTotal, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void ManagerVenta::listarVentas() {
    int cantidadRegistros = archivoVentas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoVentas.Leer(i).mostrar() << endl;
    }
}

void ManagerVenta::modificarVenta() {
    int id, posicion;

    cout << "Ingrese el Id de la Venta a Modificar: ";
    cin >> id;
    posicion = archivoVentas.Buscar(id);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Venta venta = archivoVentas.Leer(posicion);
    cout << "1. " << venta.getIdFuncion() << endl;
    cout << "2. " << venta.getIdMembresia() << endl;
    cout << "3. " << venta.getCantidadEntradas() << endl;
    cout << "4. " << venta.getFechaVenta().toString(2) << endl;
    cout << "5. " << venta.getImporteTotal() << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;

    int entero;
    float decimal;
    Fecha fechaVenta;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo id de función: ";
        cin >> entero;
        venta.setIdFuncion(entero);
        break;
    case 2:
        cout << "Elija el nuevo id de membresía: ";
        cin >> entero;
        venta.setIdMembresia(entero);
        break;
    case 3:
        cout << "Elija la nueva cantidad de entradas: ";
        cin >> entero;
        venta.setCantidadEntradas(entero);
        break;
    case 4:
        cout << "Elija la nueva Fecha de venta: " << endl;
        fechaVenta.cargar(2);
        venta.setFechaVenta(fechaVenta);
        break;
    case 5:
        cout << "Elija el nuevo importe total: ";
        cin >> entero;
        venta.setImporteTotal(entero);
        break;
    }

    if(archivoVentas.Modificar(venta, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerVenta::cambiarEstadoVenta() {
    int id, posicion;

    cout << "Ingrese el Id de la venta a cancelar: ";
    cin >> id;
    posicion = archivoVentas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
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
        venta.setEstado(0);
        archivoVentas.Modificar(venta, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
    cout << endl;
}
