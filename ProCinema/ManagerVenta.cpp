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



    cout << "Id: " << idVenta << endl;
    //fecha se obtiene automaticamente
    cout << "Fecha y hora: ";
    fechaVenta.setFechaYHoraActual();
    cout << fechaVenta.toString(2) << endl;

    cout << "Ingrese el id de función: ";
    cin >> idFuncion;
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    idFuncion = funcion.getIdFuncion();


    cout << "Ingrese la cantidad de entradas: ";
    cin >> cantidadEntradas;

    cout << "Ingrese el id de membresía (si el cliente no es miembro ingrese x (LUEGO ARREGLAMOS ESTA LOGICA)): ";
    cin >> idMembresia;
    posicion = archivoMembresias.Buscar(idMembresia);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    idMembresia = membresia.getIdMembresia();

    //importe se obtiene de cantidadEntradas * funcion._importeFuncion;

    importeTotal = funcion.getImporteFuncion() * cantidadEntradas;
    cout << "Importe final: " << importeTotal << endl;

    system("pause");

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

    cout << "Ingrese el Id de la Película a Modificar: ";
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

    cout << "Ingrese el Id de la venta a dar de baja / restaurar: ";
    cin >> id;
    posicion = archivoVentas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Venta venta = archivoVentas.Leer(posicion);
    venta.mostrar();
    cout << "Actualmente, esta venta se encuentra ";
    if (venta.getEstado()) cout << "DADA DE ALTA.";
    else cout << "DADA DE BAJA.";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        venta.setEstado(!venta.getEstado());
        archivoVentas.Modificar(venta, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
    cout << endl;
}
