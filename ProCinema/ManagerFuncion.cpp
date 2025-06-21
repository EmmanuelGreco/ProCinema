#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
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
    //cin.ignore();
    cin >> idPelicula;
    while (!validarNumero(idPelicula, 0)) {
        cout << "Ingrese un id válido: ";
        cin >> idPelicula;
    }
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
    while (!validarNumero(idSala, 0)) {
        cout << "Ingrese un id válido: ";
        cin >> idSala;
    };
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
    while (!validarNumero(idiomaFuncion, 1, 3)) {
        cout << "Ingrese un idioma válido: ";
        cin >> idiomaFuncion;
    }

    cout << "Ingrese la Fecha de la Función: " << endl;
    //cin.ignore();
    fechaFuncion.cargar(1);

    // Esto habría que automatizarlo, dependiendo del día y del tipo de sala
    cout << "Ingrese el importe de la Función: ";
    cin >> importeFuncion;
    while (!validarNumero(importeFuncion, 0)) {
        cout << "Ingrese un importe válido: ";
        cin >> importeFuncion;
    }


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

void ManagerFuncion::listarFuncionesActivas(bool activas) {
    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    Funcion funcion;

    for (int i = 0; i < cantidadRegistros; i++) {
        funcion = archivoFunciones.Leer(i);

        if (funcion.getEstado() == activas) {
            listarFuncionesImprimir(funcion);
        }
    }
}

void ManagerFuncion::listarFuncionesAgotadas() {
    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    Funcion funcion;

    for (int i = 0; i < cantidadRegistros; i++) {
        funcion = archivoFunciones.Leer(i);

        if (funcion.getButacasDisponibles() <= 0) {
            listarFuncionesImprimir(funcion);
        }
    }
}

void ManagerFuncion::listarFuncionesImprimir(Funcion funcion) {
    // Harcodeado
    int opcion = funcion.getIdiomaFuncion();
    string idiomaFuncion;
    switch(opcion) {
    case 1:
        idiomaFuncion = "Inglés";
        break;
    case 2:
        idiomaFuncion = "Castellano";
        break;
    case 3:
        idiomaFuncion = "Subtitulado";
        break;
    }

    // Harcodeado
    string estado;
    if (funcion.getEstado())
        estado = "EN CARTELERA";
    else
        estado = "FUERA DE CARTELERA";


    ostringstream redondeoImporteFuncion;
    redondeoImporteFuncion << fixed << setprecision(2) << funcion.getImporteFuncion();

    cout <<
         "  ID de Función N°" + to_string(funcion.getIdFuncion()) + "\n" +
         "  ID de Película N°" + to_string(funcion.getIdPelicula()) + "\n" +
         "  ID de Sala N°" + to_string(funcion.getIdSala()) + "\n" +
         "  Cantidad de Butacas Disponibles: " + to_string(funcion.getButacasDisponibles()) + "\n" +
         "  Idioma de la Función: " + idiomaFuncion + "\n" +
         "  Fecha de la Función: " + funcion.getFechaFuncion().toString(1) + "\n" +
         "  Importe de la Función: $" + redondeoImporteFuncion.str() + "\n" +
         "  Estado de la Función: " + estado + "\n" +
         "===================================================" + "\n" ;
}

void ManagerFuncion::modificarFuncion() {
    int id, posicion;

    cout << "Ingrese el Id de la Función a Modificar: ";
    cin >> id;
    while (!validarNumero(id, 0)) {
        cout << "Ingrese un id válido: ";
        cin >> id;
    }
    posicion = archivoFunciones.Buscar(id);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    cout << "1. " << funcion.getIdPelicula() << endl;
    cout << "2. " << funcion.getIdSala() << endl;
    cout << "3. " << funcion.getButacasDisponibles() << endl;
    cout << "4. " << funcion.getIdiomaFuncion() << endl;
    cout << "5. " << funcion.getFechaFuncion().toString(1) << endl;
    cout << "6. " << funcion.getImporteFuncion() << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 0)) {
        cout << "Ingrese una opción válida: ";
        cin >> opcion;
    }
    int num;
    float numFloat;
    string str;
    Fecha fechaFuncion;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo Id de Película: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "Ingrese un id válido: ";
            cin >> num;
        }
        funcion.setIdPelicula(num);
        break;
    case 2:
        cout << "Elija el nuevo Id de Sala: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "Ingrese un id válido: ";
            cin >> num;
        }
        funcion.setIdSala(num);
        break;
    case 3:
        cout << "Elija la nueva Cantidad de Butacas Disponibles: ";
        cin >> num;
        while (!validarNumero(num, 1)) {
            cout << "Ingrese una cantidad válida: ";
            cin >> num;
        }
        funcion.setButacasDisponibles(num);
        break;
    case 4:
        cout << "Elija el nuevo Idioma de la Función: ";
        cin >> num;
        while (!validarNumero(num, 1, 3)) {
            cout << "Ingrese un idioma válido: ";
            cin >> num;
        }
        funcion.setIdiomaFuncion(num);
        break;
    case 5:
        cout << "Elija la nueva Fecha de la Función: " << endl;
        fechaFuncion.cargar(1);
        funcion.setFechaFuncion(fechaFuncion);
        break;
    case 6:
        cout << "Elija el nuevo Importe de la Función: ";
        cin >> numFloat;
        while (!validarNumero(numFloat, 0)) {
            cout << "Ingrese un importe válido: ";
            cin >> numFloat;
        }
        funcion.setImporteFuncion(numFloat);
        break;
    }

    if(archivoFunciones.Modificar(funcion, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerFuncion::cambiarEstadoFuncion() {
    int id, posicion;

    cout << "Ingrese el Id de la Función a Dar de baja / Restaurar: ";
    cin >> id;
    while (!validarNumero(id, 0)) {
            cout << "Ingrese un id válido: ";
            cin >> id;
        }
    posicion = archivoFunciones.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    funcion.mostrar();
    cout << "Actualmente, esta Función se encuentra: ";
    if (funcion.getEstado()) cout << "EN CARTELERA";
    else cout << "FUERA DE CARTELERA";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        funcion.setEstado(!funcion.getEstado());
        archivoFunciones.Modificar(funcion, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
    cout << endl;
}


///BUSCAR POR...

void ManagerFuncion::buscarPorId() {
    int idBuscado;

    cout << "Ingrese el Id de Función a buscar: ";
    cin >> idBuscado;
    while (!validarNumero(idBuscado, 0)) {
            cout << "Ingrese un id válido: ";
            cin >> idBuscado;
        }

    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoFunciones.Leer(i).getIdFuncion() == idBuscado) {
            cout << archivoFunciones.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Función con el Id: " << idBuscado << "." << endl;
}

void ManagerFuncion::buscarPorTituloPelicula() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");

    char tituloPeliculaBuscado[50];

    cout << "Ingrese el Título de la Película a buscar en la Función: ";
    cin.ignore();
    cin.getline(tituloPeliculaBuscado, 50);

    for (int i = 0; tituloPeliculaBuscado[i] != '\0'; i++) {
        tituloPeliculaBuscado[i] = tolower(tituloPeliculaBuscado[i]);
    }

    int cantidadFunciones = archivoFunciones.CantidadRegistros();
    int cantidadPeliculas = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;

    for (int i = 0; i < cantidadFunciones; i++) {
        int idPelicula = archivoFunciones.Leer(i).getIdPelicula();

        for (int j = 0; j < cantidadPeliculas; j++) {
            if (archivoPeliculas.Leer(j).getIdPelicula() == idPelicula) {
                char tituloActual[50];
                strncpy(tituloActual, archivoPeliculas.Leer(j).getTitulo().c_str(), sizeof(tituloActual));
                tituloActual[sizeof(tituloActual) - 1] = '\0';

                for (int k = 0; tituloActual[k] != '\0'; k++) {
                    tituloActual[k] = tolower(tituloActual[k]);
                }

                if (strstr(tituloActual, tituloPeliculaBuscado) != nullptr) {
                    cout << archivoFunciones.Leer(i).mostrar() << endl;
                    cantidadEncontrados++;
                }

                break;
            }
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Función con el Título de la Película: " << tituloPeliculaBuscado << "." << endl;
}

void ManagerFuncion::buscarPorNumeroSala() {
    int idSalaBuscado;

    cout << "Ingrese el Número de Sala de Función a buscar: ";
    cin >> idSalaBuscado;
    while (!validarNumero(idSalaBuscado, 0)) {
            cout << "Ingrese un id válido: ";
            cin >> idSalaBuscado;
        }

    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoFunciones.Leer(i).getIdSala() == idSalaBuscado-1) {
            cout << archivoFunciones.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Función con el Número de Sala: " << idSalaBuscado << "." << endl;
}

void ManagerFuncion::buscarPorFechaFuncion() {
    Fecha fechaFuncionBuscada;

    cout << "Ingrese la Fecha de Función a buscar: " << endl;
    fechaFuncionBuscada.cargar(1);

    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoFunciones.Leer(i).getFechaFuncion() == fechaFuncionBuscada) {
            cout << archivoFunciones.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Función con la Fecha de Función: " << fechaFuncionBuscada.toString(1) << "." << endl;
}

bool ManagerFuncion::validarNumero(int input, int minimo, int maximo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo && input <= maximo);
    }
}

bool ManagerFuncion::validarNumero(int input, int minimo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo);
    }
}
