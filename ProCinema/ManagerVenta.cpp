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

    ///automáticamente seteo id de venta, y fecha y hora.
    cout << "Id de venta: " << idVenta << endl;
    cout << "Fecha y hora: ";                           //fecha se obtiene automaticamente
    fechaVenta.setFechaYHoraActual();
    cout << fechaVenta.toString(2) << endl;

    ///se pide el id del miembro y se valida
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

    ///se pide el id de la funcion y se valida
    cout << endl << "Ingrese el id de función: ";
    cin >> idFuncion;
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "Id NO encontrado!" << endl;
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    idFuncion = funcion.getIdFuncion();

    ///se muestra la pelicula y fecha correspondiente a esta función
    cout << "Película: " << archivoPeliculas.Leer(archivoPeliculas.Buscar(funcion.getIdPelicula())).getTitulo() << endl;
    cout << "Fecha de la función: " << funcion.getFechaFuncion().toString(1) << endl;

    ///se muestra cantidad de butacas libres, y se pide ingresar la cantidad a comprar.
    cout << funcion.getButacasDisponibles() << " butacas disponibles." << endl;
    cout << "Ingrese la cantidad de entradas: ";
    cin >> cantidadEntradas;
    ///si son demasiadas entradas para la capacidad, no se puede llevar a cabo.
    if(cantidadEntradas <= funcion.getButacasDisponibles()) {
        funcion -= cantidadEntradas;                                //funcion.setButacasDisponibles(funcion.getButacasDisponibles() - cantidadEntradas);
    } else {
        cout << "No hay suficientes butacas disponibles!" << endl;
        return;
    }
    ///se calcula el total llamando a la función correspondiente.
    importeTotal = calcularImporteTotal(cantidadEntradas, idFuncion, idMembresia);

    ///si se guardó bien, notificarlo.
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
    int idVenta, posicionAModificar;
    ArchivoVenta archivoVentas("ventas.dat");
    Venta venta;
    ArchivoFuncion archivoFunciones("funciones.dat");
    Funcion funcion;
    ArchivoMembresia archivoMembresias("membresias.dat");
    Membresia membresia;
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    Pelicula pelicula;

    cout << "Ingrese el Id de la Venta a Modificar: ";
    cin >> idVenta;
    posicionAModificar = archivoVentas.Buscar(idVenta);
    if (posicionAModificar == -1) {
        cout << "Id no encontrado!" << endl;
        return;
    }
    venta = archivoVentas.Leer(posicionAModificar);
    cout << "1. Modificar id de función: " << venta.getIdFuncion() << endl;
    cout << "2. Modificar id de miembro: " << venta.getIdMembresia() << endl;
    cout << "3. Modificar cantidad de entradas: " << venta.getCantidadEntradas() << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;

    int importeTotal, nuevoIdFuncion, posicionFuncion,
        nuevoIdMembresia, posicionMembresia,
        nuevaCantidad;
    switch(opcion) {
    case 1:
        cout << endl << "Ingrese el nuevo id de función: ";
        cin >> nuevoIdFuncion;
        posicionFuncion = archivoFunciones.Buscar(nuevoIdFuncion);
        if (posicionFuncion == -1) {
            cout << "Id NO encontrado!" << endl;
            return;
        }
        funcion = archivoFunciones.Leer(archivoFunciones.Buscar(venta.getIdFuncion()));
        funcion += venta.getCantidadEntradas();
        archivoFunciones.Modificar(funcion, funcion.getIdFuncion());

        funcion = archivoFunciones.Leer(archivoFunciones.Buscar(nuevoIdFuncion));
        funcion -= venta.getCantidadEntradas();
        archivoFunciones.Modificar(funcion, nuevoIdFuncion);

        importeTotal = calcularImporteTotal(venta.getCantidadEntradas(), nuevoIdFuncion, venta.getIdMembresia());

        venta.setIdFuncion(nuevoIdFuncion);
        venta.setImporteTotal(importeTotal);
        archivoVentas.Modificar(venta, posicionAModificar);
        break;
    case 2:
        cout << endl << "Ingrese el nuevo id de mimebro: ";
        cin >> nuevoIdMembresia;
        posicionMembresia = archivoMembresias.Buscar(nuevoIdMembresia);
        if (posicionMembresia == -1) {
            cout << "Id NO encontrado!" << endl;
            return;
        }
        importeTotal = calcularImporteTotal(venta.getCantidadEntradas(), venta.getIdFuncion(), nuevoIdMembresia);

        venta.setIdMembresia(nuevoIdMembresia);
        venta.setImporteTotal(importeTotal);
        archivoVentas.Modificar(venta, posicionAModificar);
        break;
    case 3:
        cout << endl << "Ingrese la nueva cantidad de entradas: ";
        cin >> nuevaCantidad;
        posicionFuncion = archivoFunciones.Buscar(venta.getIdFuncion());
        if (posicionFuncion == -1) {
            cout << "Id NO encontrado!" << endl;
            return;
        }

        funcion = archivoFunciones.Leer(archivoFunciones.Buscar(venta.getIdFuncion()));
        funcion -= nuevaCantidad - venta.getCantidadEntradas();
        archivoFunciones.Modificar(funcion, funcion.getIdFuncion());

        importeTotal = calcularImporteTotal(nuevaCantidad, venta.getIdFuncion(), venta.getIdMembresia());

        venta.setCantidadEntradas(nuevaCantidad);
        venta.setImporteTotal(importeTotal);
        archivoVentas.Modificar(venta, posicionAModificar);
        break;
    }

    if(archivoVentas.Modificar(venta, posicionAModificar)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerVenta::cambiarEstadoVenta() {
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoFuncion archivoFunciones("funciones.dat");
    Funcion funcion;

    int id, posicion;

    cout << "Ingrese el Id de la Venta a cancelar: ";
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

int ManagerVenta::calcularImporteTotal(int cantidadEntradas, int idFuncion, int idMembresia) {
    ArchivoFuncion archivoFunciones("funciones.dat");
    Funcion funcion = archivoFunciones.Leer(archivoFunciones.Buscar(idFuncion));
    ArchivoMembresia archivoMembresias("membresias.dat");
    Membresia membresia = archivoMembresias.Leer(archivoMembresias.Buscar(idMembresia));

    int importeTotal = funcion.getImporteFuncion() * cantidadEntradas;
    if(idMembresia != 0) {
        cout << "Subtotal: " << importeTotal << endl;
        cout << "Descuento: " << membresia.getDescuentoMembresia() << "%" << endl;
        importeTotal = (importeTotal * (100-membresia.getDescuentoMembresia())/ 100);
    }
    cout << "Total: " << importeTotal << endl;
    return importeTotal;
}


///BUSCAR POR...

void ManagerVenta::buscarPorId() {
    ArchivoVenta archivoVentas("ventas.dat");
    int idBuscado;

    cout << "Ingrese el id de venta a buscar: ";
    cin >> idBuscado;

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoVentas.Leer(i).getIdVenta() == idBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) cout << "no se encontro ningun registro con el id de venta " << idBuscado << "." << endl;
}

void ManagerVenta::buscarPorFuncion() {
    ArchivoVenta archivoVentas("ventas.dat");
    int idBuscado;

    cout << "Ingrese el id de funcion a buscar: ";
    cin >> idBuscado;

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoVentas.Leer(i).getIdFuncion() == idBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) cout << "no se encontro ningun registro con el id de funcion " << idBuscado << "." << endl;
}

void ManagerVenta::buscarPorDNI() {
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoMembresia archivoMembresias("membresias.dat");
    int dniBuscado;

    cout << "Ingrese el DNI a buscar: ";
    cin >> dniBuscado;

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        int idMem = archivoVentas.Leer(i).getIdMembresia();
        if (idMem != 0 && archivoMembresias.Leer(idMem - 1).getDniMiembro() == dniBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) cout << "no se encontro ningun registro con DNI " << dniBuscado << "." << endl;
}

void ManagerVenta::buscarPorMiembro() {
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idBuscado;

    cout << "Ingrese el id de miembro: ";
    cin >> idBuscado;

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        int idMem = archivoVentas.Leer(i).getIdMembresia();
        if (idMem != 0 && archivoMembresias.Leer(idMem - 1).getIdMembresia() == idBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        } else if (idMem == 0) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) cout << "no se encontro ningun registro con el id de miembro " << idBuscado << "." << endl;
}


void ManagerVenta::buscarPorFecha() {
    ArchivoVenta archivoVentas("ventas.dat");
    Fecha fechaBuscada;

    cout << "Ingrese una fecha a buscar: " << endl;
    fechaBuscada.cargar(1);

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoVentas.Leer(i).getFechaVenta().getAnio() == fechaBuscada.getAnio() &&
                archivoVentas.Leer(i).getFechaVenta().getMes() == fechaBuscada.getMes() &&
                archivoVentas.Leer(i).getFechaVenta().getDia() == fechaBuscada.getDia()) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) cout << "no se encontro ningun registro con fecha " << fechaBuscada.toString(1) << "." << endl;
}
