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


void ManagerFuncion::cargarFuncion() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idFuncion = archivoFunciones.getUltimoId()+1, idPelicula, idSala, butacasDisponibles, idiomaFuncion;
    float importeFuncion;
    bool estado = 1;
    Fecha fechaFuncion;
    int posicion;
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    ArchivoSala archivoSalas("salas.dat");

    cout << "  ID: " << idFuncion << endl;

    // Me traigo el ID de la Pelicula y lo asigno al idPelicula de la Funci�n
    cout << "  Ingrese el ID de la Pel�cula: ";
    //cin.ignore();
    cin >> idPelicula;
    while (!validarNumero(idPelicula, 0)) {
        cout << "  Error! Ingrese un ID v�lido: ";
        cin >> idPelicula;
    }
    posicion = archivoPeliculas.Buscar(idPelicula);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    idPelicula = pelicula.getIdPelicula();

    // Me traigo el ID de la Sala y lo asigno al idSala de la Funci�n
    cout << "  Ingrese el ID de la Sala: ";
    cin >> idSala;
    idSala -= 1;
    while (!validarNumero(idSala, 0)) {
        cout << "  Error! Ingrese un ID v�lido: ";
        cin >> idSala;
        idSala -= 1;
    };
    posicion = archivoSalas.Buscar(idSala);
    if (posicion == -1) {
        cout << "  ID no encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    idSala = sala.getIdSala();

    // Por ahora asigna la cantidad de butacas de la sala, se le debe restar las ventas
    butacasDisponibles = sala.getButacasTotales();

    cout << "  Ingrese el Idioma de la Funci�n (1-Ingl�s, 2-Castellano, 3-Subtitulado): ";
    cin >> idiomaFuncion;
    while (!validarNumero(idiomaFuncion, 1, 3)) {
        cout << "  Error! Ingrese un Idioma v�lido (1-Ingl�s, 2-Castellano, 3-Subtitulado): ";
        cin >> idiomaFuncion;
    }

    cout << endl;
    cout << "  Ingrese la Fecha de la Funci�n: " << endl;
    //cin.ignore();
    fechaFuncion.cargar(2);

    // Esto habr�a que automatizarlo, dependiendo del d�a y del tipo de sala
    cout << endl;
    cout << "  Ingrese el importe de la Funci�n: ";
    cin >> importeFuncion;
    while (!validarNumero(importeFuncion, 0)) {
        cout << "  Ingrese un importe v�lido: ";
        cin >> importeFuncion;
    }


    cout << endl;
    if(archivoFunciones.Guardar(Funcion(idFuncion, idPelicula, idSala, butacasDisponibles, idiomaFuncion,
                                        fechaFuncion, importeFuncion, estado))) {
        cout << " Se guardo Exitosamente!" << endl;
    } else {
        cout << "  Hubo un error inesperado, llame al de sistemas..." << endl;
    }
    cout << endl;
}

void ManagerFuncion::listarFunciones() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadRegistros = archivoFunciones.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoFunciones.Leer(i).mostrar() << endl;
    }
}

void ManagerFuncion::listarFunciones(bool activas) {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    Funcion funcion;

    for (int i = 0; i < cantidadRegistros; i++) {
        funcion = archivoFunciones.Leer(i);

        if (funcion.getEstado() == activas) {
            cout << funcion.mostrar() << endl;
        }
    }
}

void ManagerFuncion::listarFuncionesAgotadas() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    Funcion funcion;

    for (int i = 0; i < cantidadRegistros; i++) {
        funcion = archivoFunciones.Leer(i);

        if (funcion.getButacasDisponibles() <= 0) {
            cout << funcion.mostrar() << endl;
        }
    }
}

    // Esto fue modificado para llamar al toStringNDO AL TOSTRING
/*void ManagerFuncion::listarFuncionesImprimir(Funcion funcion) {
    // Harcodeado
    int opcion = funcion.getIdiomaFuncion();
    string idiomaFuncion;
    switch(opcion) {
    case 1:
        idiomaFuncion = "Ingl�s";
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
         "  ID de Funci�n N�" + to_string(funcion.getIdFuncion()) + "\n" +
         "  ID de Pel�cula N�" + to_string(funcion.getIdPelicula()) + "\n" +
         "  ID de Sala N�" + to_string(funcion.getIdSala()) + "\n" +
         "  Cantidad de Butacas Disponibles: " + to_string(funcion.getButacasDisponibles()) + "\n" +
         "  Idioma de la Funci�n: " + idiomaFuncion + "\n" +
         "  Fecha de la Funci�n: " + funcion.getFechaFuncion().toString(1) + "\n" +
         "  Importe de la Funci�n: $" + redondeoImporteFuncion.str() + "\n" +
         "  Estado de la Funci�n: " + estado + "\n" +
         "===================================================" + "\n" ;
}*/

void ManagerFuncion::modificarFuncion() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idFuncion, posicion;

    cout << "  Ingrese el ID de la Funci�n a Modificar: ";
    cin >> idFuncion;
    idFuncion -= 1;
    while (!validarNumero(idFuncion, 0)) {
        cout << "  Error! Ingrese un ID v�lido: ";
        cin >> idFuncion;
        idFuncion -= 1;
    }
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "ID NO encontrado!";
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    cout << endl;
    cout << "  1. ID Pel�cula: " << funcion.getIdPelicula() << endl;
    cout << "  2. N� Sala: " << funcion.getIdSala() << endl;
    //cout << "  3. " << funcion.getButacasDisponibles() << endl;
    cout << "  3. Idioma de la Funci�n: " << funcion.getIdiomaFuncion() << endl;
    cout << "  4. Fecha de la Funci�n: " << funcion.getFechaFuncion().toString(2) << endl;
    cout << "  5. Importe de la Funci�n: " << funcion.getImporteFuncion() << endl;
    //cout << "  0. Volver al menu " << endl;
    cout << endl;
    cout << "  Elija una Opci�n: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 1, 5)) {
        cout << "  Error! Ingrese una Opci�n v�lida: ";
        cin >> opcion;
    }
    int num;
    float numFloat;
    string str;
    Fecha fechaFuncion;
    switch(opcion) {
    case 1:
        cout << "  Elija el nuevo ID de Pel�cula: ";
        cin >> num;
        num -= 1;
        while (!validarNumero(num, 0)) {
            cout << "  Error! Ingrese un ID v�lido: ";
            cin >> num;
            num -= 1;
        }
        funcion.setIdPelicula(num);
        break;
    case 2:
        cout << "  Elija el nuevo ID de la Sala: ";
        cin >> num;
        num -= 1;
        while (!validarNumero(num, 0)) {
            cout << "  Error! Ingrese un ID de la Sala v�lido: ";
            cin >> num;
            num -= 1;
        }
        funcion.setIdSala(num);
        break;
    /*case 3:
        cout << "Elija la nueva Cantidad de Butacas Disponibles: ";
        cin >> num;
        while (!validarNumero(num, 1)) {
            cout << "Error! Ingrese una cantidad de Butacas v�lida: ";
            cin >> num;
        }
        funcion.setButacasDisponibles(num);
        break;*/
    case 3:
        cout << "  Elija el nuevo Idioma de la Funci�n (1-Ingl�s, 2-Castellano, 3-Subtitulado): ";
        cin >> num;
        while (!validarNumero(num, 1, 3)) {
            cout << "  Error! Ingrese un Idioma v�lido (1-Ingl�s, 2-Castellano, 3-Subtitulado): ";
            cin >> num;
        }
        funcion.setIdiomaFuncion(num);
        break;
    case 4:
        cout << "  Elija la nueva Fecha de la Funci�n: " << endl;
        fechaFuncion.cargar(2);
        funcion.setFechaFuncion(fechaFuncion);
        break;
    case 5:
        cout << "  Elija el nuevo Importe de la Funci�n: ";
        cin >> numFloat;
        while (!validarNumero(numFloat, 0)) {
            cout << "  Error! Ingrese un Importe v�lido: ";
            cin >> numFloat;
        }
        funcion.setImporteFuncion(numFloat);
        break;
    }

    cout << endl;
    if(archivoFunciones.Modificar(funcion, posicion)) cout << "Modificado Exitosamente!" << endl;
    cout << endl;
}

void ManagerFuncion::cambiarEstadoFuncion() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idFuncion, posicion;

    cout << "  Ingrese el ID de la Funci�n a Dar de baja / Restaurar: ";
    cin >> idFuncion;
    idFuncion -= 1;
    while (!validarNumero(idFuncion, 0)) {
            cout << "  Error! Ingrese un ID v�lido: ";
            cin >> idFuncion;
            idFuncion -= 1;
        }
    posicion = archivoFunciones.Buscar(idFuncion);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Funcion funcion = archivoFunciones.Leer(posicion);
    funcion.mostrar();

    cout << endl;
    cout << "  Actualmente, esta Funci�n se encuentra: ";
    if (funcion.getEstado()) cout << "EN CARTELERA";
    else cout << "FUERA DE CARTELERA";
    cout << endl << "  Desea modificar su estado? (Y-N): ";
    char yn;

    cout << endl;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        funcion.setEstado(!funcion.getEstado());
        archivoFunciones.Modificar(funcion, posicion);
        cout << "  Modificado Exitosamente!";
    } else {
        cout << "  NO se ha podido Modificar!";
    }
    cout << endl;
    cout << endl;
}


///BUSCAR POR...

void ManagerFuncion::buscarPorId() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idBuscado;

    cout << "  Ingrese el ID de Funci�n a Buscar: ";
    cin >> idBuscado;
    idBuscado -= 1;
    while (!validarNumero(idBuscado, 0)) {
            cout << "  Error! Ingrese un ID v�lido: ";
            cin >> idBuscado;
            idBuscado -= 1;
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
        cout << endl << "  NO se encontr� ning�n registro con el ID: " << idBuscado+1 << "." << endl;
}

void ManagerFuncion::buscarPorTituloPelicula() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    ArchivoPelicula archivoPeliculas("peliculas.dat");

    char tituloPeliculaBuscado[50];

    cout << "  Ingrese el T�tulo de la Pel�cula a Buscar en la Funci�n: ";
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
        cout << endl << "  NO se encontr� ning�n registro con el T�tulo de la Pel�cula: " << tituloPeliculaBuscado << "." << endl;
}

void ManagerFuncion::buscarPorNumeroSala() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    int idSalaBuscado;

    cout << "  Ingrese el N� de Sala de Funci�n a Buscar: ";
    cin >> idSalaBuscado;
    idSalaBuscado -= 1;
    while (!validarNumero(idSalaBuscado, 0)) {
            cout << "  Error! Ingrese un N� de Sala v�lido: ";
            cin >> idSalaBuscado;
            idSalaBuscado -= 1;
        }

    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoFunciones.Leer(i).getIdSala() == idSalaBuscado) {
            cout << archivoFunciones.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "  NO se encontr� ning�n registro con el N� de Sala: " << idSalaBuscado+1 << "." << endl;
}

void ManagerFuncion::buscarPorFechaFuncion() {
    ArchivoFuncion archivoFunciones("funciones.dat");
    Fecha fechaFuncionBuscada;

    cout << "  Ingrese la Fecha de Funci�n a Buscar: " << endl;
    fechaFuncionBuscada.cargar(2);

    int cantidadRegistros = archivoFunciones.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoFunciones.Leer(i).getFechaFuncion() == fechaFuncionBuscada) {
            cout << archivoFunciones.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "  NO se encontr� ning�n registro con la Fecha de la Funci�n: " << fechaFuncionBuscada.toString(2) << "." << endl;
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
