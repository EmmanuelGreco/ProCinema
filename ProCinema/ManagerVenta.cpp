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
    int cantidadMiembros = archivoMembresias.CantidadRegistros();
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idVenta = archivoVentas.getUltimoId()+1, idFuncion, idMembresia, cantidadEntradas;
    float importeTotal;
    bool estado = 1;
    Fecha fechaVenta;

    int posicion;
    Membresia membresia;

    ///automáticamente seteo id de venta, y fecha y hora.
    cout << "ID de Venta: " << idVenta << endl;
    cout << "Fecha y Hora: ";                           ///fecha se obtiene automaticamente
    fechaVenta.setFechaYHoraActual();
    cout << fechaVenta.toString(2) << endl;

    ///se pide el id del miembro y se valida
    cout << "Ingrese el ID de Membresía (Si el cliente no es Miembro, Ingrese 0): ";
    cin >> idMembresia;
    while (!validarNumero(idMembresia, 0)) {
        cout << "Error! Ingrese un ID de Membresía válido: ";
        cin >> idMembresia;
    }

    if (idMembresia != 0) {
        posicion = archivoMembresias.Buscar(idMembresia);
        if (posicion == -1) {
            cout << "ID NO encontrado!" << endl;
            return;
        }
        membresia = archivoMembresias.Leer(posicion);
        idMembresia = membresia.getIdMembresia();
        cout << "Registrando Venta para " << membresia.getNombreMiembro() << " " << membresia.getApellidoMiembro() <<
             " - " << membresia.getNombreMembresia() << endl;
    } else {
        cout << "Cliente NO registrado!" << endl;
    }

    ///se pide el id de la funcion y se valida
    cout << endl << "Ingrese el ID de la Función: ";
    cin >> idFuncion;
    idFuncion -= 1;
    while (!validarNumero(idFuncion, 0)) {
        cout << "ERROR! Ingrese un ID válido: ";
        cin >> idFuncion;
        idFuncion -= 1;
    }
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "ID NO encontrado!" << endl;
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    idFuncion = funcion.getIdFuncion();

    ///se muestra la pelicula y fecha correspondiente a esta función
    cout << "Película: " << archivoPeliculas.Leer(archivoPeliculas.Buscar(funcion.getIdPelicula())).getTitulo() << endl;
    cout << "Fecha de la Función: " << funcion.getFechaFuncion().toString(1) << endl;

    ///se muestra cantidad de butacas libres, y se pide ingresar la cantidad a comprar.
    cout << funcion.getButacasDisponibles() << " butacas disponibles." << endl;
    cout << "Ingrese la Cantidad de Entradas: ";
    cin >> cantidadEntradas;
    while (!validarNumero(cantidadEntradas, 0)) {
        cout << "Error! Ingrese una Cantidad de Entradas válida: ";
        cin >> cantidadEntradas;
    }

    ///si son demasiadas entradas para la capacidad, no se puede llevar a cabo.
    if(cantidadEntradas <= funcion.getButacasDisponibles()) {
        funcion -= cantidadEntradas;                                //funcion.setButacasDisponibles(funcion.getButacasDisponibles() - cantidadEntradas);
    } else {
        cout << "Ups... No hay suficientes Butacas Disponibles!" << endl;
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
    ArchivoVenta archivoVentas("ventas.dat");
    Venta venta;
    ArchivoFuncion archivoFunciones("funciones.dat");
    Funcion funcion;
    ArchivoMembresia archivoMembresias("membresias.dat");
    Membresia membresia;
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    Pelicula pelicula;

    int idVenta, posicionAModificar;

    cout << "Ingrese el ID de la Venta a Modificar: ";
    cin >> idVenta;
    idVenta -= 1;
    while (!validarNumero(idVenta, 0)) {
        cout << "Error! Ingrese un ID válido: ";
        cin >> idVenta;
        idVenta -= 1;
    }
    posicionAModificar = archivoVentas.Buscar(idVenta);
    if (posicionAModificar == -1) {
        cout << "ID NO encontrado!" << endl;
        return;
    }
    venta = archivoVentas.Leer(posicionAModificar);
    cout << "1. Modificar ID de función: " << venta.getIdFuncion()+1 << endl;
    cout << "2. Modificar ID de miembro: " << venta.getIdMembresia() << endl;
    cout << "3. Modificar Cantidad de Entradas: " << venta.getCantidadEntradas() << endl;
    cout << "Elija una Opción: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 0)) {
        cout << "Error! Ingrese una Opción válida: ";
        cin >> opcion;
    }

    int importeTotal, nuevoIdFuncion, posicionFuncion,
        nuevoIdMembresia, posicionMembresia,
        nuevaCantidad;
    switch(opcion) {
    case 1:
        cout << endl << "Ingrese el nuevo ID de la Función: ";
        cin >> nuevoIdFuncion;
        nuevoIdFuncion -= 1;
        while (!validarNumero(nuevoIdFuncion, 0)) {
            cout << "Error! Ingrese un ID válido: ";
            cin >> nuevoIdFuncion;
            nuevoIdFuncion -= 1;
        }
        posicionFuncion = archivoFunciones.Buscar(nuevoIdFuncion);
        if (posicionFuncion == -1) {
            cout << "ID NO encontrado!" << endl;
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
        cout << endl << "Ingrese el nuevo ID de Miembro: ";
        cin >> nuevoIdMembresia;
        while (!validarNumero(nuevoIdMembresia, 0)) {
            cout << "Ingrese un ID Válido: ";
            cin >> nuevoIdMembresia;
        }
        posicionMembresia = archivoMembresias.Buscar(nuevoIdMembresia);
        if (posicionMembresia == -1) {
            cout << "ID NO encontrado!" << endl;
            return;
        }
        importeTotal = calcularImporteTotal(venta.getCantidadEntradas(), venta.getIdFuncion(), nuevoIdMembresia);

        venta.setIdMembresia(nuevoIdMembresia);
        venta.setImporteTotal(importeTotal);
        archivoVentas.Modificar(venta, posicionAModificar);
        break;
    case 3:
        cout << endl << "Ingrese la nueva Cantidad de Entradas: ";
        cin >> nuevaCantidad;
        while (!validarNumero(nuevaCantidad, 0)) {
            cout << "Error! Ingrese una Cantidad Válida: ";
            cin >> nuevaCantidad;
        }
        posicionFuncion = archivoFunciones.Buscar(venta.getIdFuncion());
        if (posicionFuncion == -1) {
            cout << "ID NO encontrado!" << endl;
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

    int idVenta, posicion;

    cout << "Ingrese el ID de la Venta a Cancelar: ";
    cin >> idVenta;
    idVenta -= 1;
    while (!validarNumero(idVenta, 0)) {
        cout << "Error! Ingrese un ID válido: ";
        cin >> idVenta;
        idVenta -= 1;
    }
    posicion = archivoVentas.Buscar(idVenta);
    if (posicion == -1) {
        cout << "ID NO encontrado!" << endl;
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
        cout << "NO se ha podido modificar!";
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

    cout << "Ingrese el ID de Venta a Buscar: ";
    cin >> idBuscado;
    idBuscado -= 1;
    while (!validarNumero(idBuscado, 0)) {
        cout << "Error! Ingrese un ID válido: ";
        cin >> idBuscado;
        idBuscado -= 1;
    }

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoVentas.Leer(i).getIdVenta() == idBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "NO se encontró ningún registro con el ID de Venta: " << idBuscado+1 << "." << endl;
}

void ManagerVenta::buscarPorFuncion() {
    ArchivoVenta archivoVentas("ventas.dat");
    int idBuscado;

    cout << "Ingrese el ID de la Función a Buscar: ";
    cin >> idBuscado;
    idBuscado -= 1;
    while (!validarNumero(idBuscado, 0)) {
        cout << "Error! Ingrese un ID válido: ";
        cin >> idBuscado;
        idBuscado -= 1;
    }

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoVentas.Leer(i).getIdFuncion() == idBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "NO se encontró ningún registro con el ID de Función: " << idBuscado+1 << "." << endl;
}

void ManagerVenta::buscarPorDNI() {
    ArchivoVenta archivoVentas("ventas.dat");
    ArchivoMembresia archivoMembresias("membresias.dat");
    int dniBuscado;

    cout << "Ingrese el DNI a Buscar: ";
    cin >> dniBuscado;
    while (!validarNumero(dniBuscado, 0)) {
        cout << "Error! Ingrese un DNI válido: ";
        cin >> dniBuscado;
    }

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        int idMem = archivoVentas.Leer(i).getIdMembresia();
        if (idMem != 0 && archivoMembresias.Leer(idMem - 1).getDniMiembro() == dniBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "NO se encontró ningún registro con el DNI de Miembro: " << dniBuscado << "." << endl;
}

void ManagerVenta::buscarPorMiembro() {
    ArchivoVenta archivoVentas("ventas.dat");
    int idBuscado;

    cout << "Ingrese el ID de Miembro a buscar: ";
    cin >> idBuscado;
    while (!validarNumero(idBuscado, 0)) {
        cout << "Error! Ingrese un ID válido: ";
        cin >> idBuscado;
    }

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoVentas.Leer(i).getIdMembresia() == idBuscado) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "NO se encontró ningún registro con el ID de Miembro: " << idBuscado << "." << endl;
}

void ManagerVenta::buscarPorFecha() {
    ArchivoVenta archivoVentas("ventas.dat");
    Fecha fechaBuscada;

    cout << "Ingrese una Fecha de Venta a Buscar: " << endl;
    fechaBuscada.cargar(1);

    int cantidadRegistros = archivoVentas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        ///FORMA VIEJA DE COMPARAR; REEMPLAZADO POR SOBRECARGA DE OPERADOR.
//        if (archivoVentas.Leer(i).getFechaVenta().getAnio() == fechaBuscada.getAnio() &&
//                archivoVentas.Leer(i).getFechaVenta().getMes() == fechaBuscada.getMes() &&
//                archivoVentas.Leer(i).getFechaVenta().getDia() == fechaBuscada.getDia()) {
        if(archivoVentas.Leer(i).getFechaVenta() == fechaBuscada) {
            cout << archivoVentas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "NO se encontró ningún registro con la Fecha de Venta: " << fechaBuscada.toString(1) << endl;
}


bool ManagerVenta::validarNumero(int input, int minimo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo);
    }
}
///SE USA ASI:
//    while (!validarNumero(input, minimo, maximo)) {
//        cout << "Ingrese una opción válida: ";
//        cin >> input;
//    }

