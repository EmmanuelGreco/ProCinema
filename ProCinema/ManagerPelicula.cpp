#include <iostream>
#include <string>
#include "ManagerPelicula.h"
#include "Pelicula.h"
#include "ArchivoPelicula.h"
#include "Fecha.h"

using namespace std;

ArchivoPelicula archivoPeliculas("peliculas.dat");


void ManagerPelicula::cargarPelicula() {
    int idPelicula = archivoPeliculas.getUltimoId()+1, clasificacion;
    string titulo, genero, nombreDirector, apellidoDirector;
    bool estado = 1;
    Fecha fechaEstreno;

    cout << "Id: " << idPelicula << endl;

    cout << "Ingrese el Título: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Ingrese el Género: ";
    getline(cin, genero);

    cout << "Ingrese el Nombre del Director: ";
    getline(cin, nombreDirector);

    cout << "Ingrese el Apellido del Director: ";
    getline(cin, apellidoDirector);

    cout << "Ingrese la Clasificación: ";
    cin >> clasificacion;

    cout << "Ingrese la Fecha de Estreno: " << endl;
    //cin.ignore();
    fechaEstreno.cargar(1);

    if(archivoPeliculas.Guardar(Pelicula(idPelicula, titulo, genero, nombreDirector, apellidoDirector,
                                         clasificacion, fechaEstreno, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void ManagerPelicula::listarPeliculas() {
    int cantidadRegistros = archivoPeliculas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoPeliculas.Leer(i).mostrar() << endl;
    }
}

void ManagerPelicula::listarPeliculasActivas(bool activas) {
    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    Pelicula pelicula;

    for (int i = 0; i < cantidadRegistros; i++) {
        pelicula = archivoPeliculas.Leer(i);

        if (pelicula.getEstado() == activas){
            cout << pelicula.mostrar() << endl;
        }
    }
}

void ManagerPelicula::modificarPelicula() {
    int id, posicion;

    cout << "Ingrese el Id de la Película a Modificar: ";
    cin >> id;
    posicion = archivoPeliculas.Buscar(id);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    cout << "1. " << pelicula.getTitulo() << endl;
    cout << "2. " << pelicula.getGenero() << endl;
    cout << "3. " << pelicula.getNombreDirector() << endl;
    cout << "4. " << pelicula.getApellidoDirector() << endl;
    cout << "5. " << pelicula.getClasificacion() << endl;
    cout << "6. " << pelicula.getFechaEstreno().toString(1) << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;

    int num;
    string str;
    Fecha fechaEstreno;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo Título: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setTitulo(str);
        break;
    case 2:
        cout << "Elija el nuevo Género: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setGenero(str);
        break;
    case 3:
        cout << "Elija el nuevo Nombre del Director: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setNombreDirector(str);
        break;
    case 4:
        cout << "Elija el nuevo Apellido del Director: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setApellidoDirector(str);
        break;
    case 5:
        cout << "Elija la nueva Clasificación: ";
        cin >> num;
        pelicula.setClasificacion(num);
        break;
    case 6:
        cout << "Elija la nueva Fecha de Estreno: " << endl;
        fechaEstreno.cargar(1);
        pelicula.setFechaEstreno(fechaEstreno);
        break;
    }

    if(archivoPeliculas.Modificar(pelicula, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerPelicula::cambiarEstadoPelicula() {
    int id, posicion;

    cout << "Ingrese el Id de la Película a Dar de baja / Restaurar: ";
    cin >> id;
    posicion = archivoPeliculas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    pelicula.mostrar();
    cout << "Actualmente, esta Película se encuentra: ";
    if (pelicula.getEstado()) cout << "EN CARTELERA";
    else cout << "FUERA DE CARTELERA";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        pelicula.setEstado(!pelicula.getEstado());
        archivoPeliculas.Modificar(pelicula, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
    cout << endl;
}


///BUSCAR POR...

void ManagerPelicula::buscarPorId() {
    int idBuscado;

    cout << "Ingrese el Id de Película a buscar: ";
    cin >> idBuscado;

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoPeliculas.Leer(i).getIdPelicula() == idBuscado) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Película con el Id: " << idBuscado << "." << endl;
}

void ManagerPelicula::buscarPorTitulo() {
    char tituloBuscado[50];

    cout << "Ingrese el Título de la Película a buscar: ";
    cin.ignore();
    cin.getline(tituloBuscado, 50);

    for (int i = 0; tituloBuscado[i] != '\0'; i++) {
        tituloBuscado[i] = tolower(tituloBuscado[i]);
    }

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;

    for (int i = 0; i < cantidadRegistros; i++) {
        char tituloActual[50];
        strcpy(tituloActual, archivoPeliculas.Leer(i).getTitulo().c_str());

        for (int j = 0; tituloActual[j] != '\0'; j++) {
            tituloActual[j] = tolower(tituloActual[j]);
        }

        if (strstr(tituloActual, tituloBuscado) != nullptr) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Película con el Título: " << tituloBuscado << "." << endl;
}

void ManagerPelicula::buscarPorGenero() {
    char generoBuscado[20];

    cout << "Ingrese el Género de la Película a buscar: ";
    cin.ignore();
    cin.getline(generoBuscado, 20);

    for (int i = 0; generoBuscado[i] != '\0'; i++) {
        generoBuscado[i] = tolower(generoBuscado[i]);
    }

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;

    for (int i = 0; i < cantidadRegistros; i++) {
        char generoActual[20];
        strcpy(generoActual, archivoPeliculas.Leer(i).getGenero().c_str());

        for (int j = 0; generoActual[j] != '\0'; j++) {
            generoActual[j] = tolower(generoActual[j]);
        }

        if (strstr(generoActual, generoBuscado) != nullptr) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Película con el Género: " << generoBuscado << "." << endl;
}

void ManagerPelicula::buscarPorApellidoDirector() {
    char apellidoDirectorBuscado[50];

    cout << "Ingrese el Apellido del Director de la Película a buscar: ";
    cin.ignore();
    cin.getline(apellidoDirectorBuscado, 20);

    for (int i = 0; apellidoDirectorBuscado[i] != '\0'; i++) {
        apellidoDirectorBuscado[i] = tolower(apellidoDirectorBuscado[i]);
    }

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;

    for (int i = 0; i < cantidadRegistros; i++) {
        char apellidoDirectorActual[50];
        strcpy(apellidoDirectorActual, archivoPeliculas.Leer(i).getApellidoDirector().c_str());

        for (int j = 0; apellidoDirectorActual[j] != '\0'; j++) {
            apellidoDirectorActual[j] = tolower(apellidoDirectorActual[j]);
        }

        if (strstr(apellidoDirectorActual, apellidoDirectorBuscado) != nullptr) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Película con el Apellido del Director: " << apellidoDirectorBuscado << "." << endl;
}

void ManagerPelicula::buscarPorClasificacion() {
    int clasificacionBuscada;

    cout << "Ingrese el Tipo de Clasificación de Película a buscar: ";
    cin >> clasificacionBuscada;

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoPeliculas.Leer(i).getClasificacion() == clasificacionBuscada) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Película con el Tipo de Clasificación: " << clasificacionBuscada << "." << endl;
}

void ManagerPelicula::buscarPorFechaEstreno() {
    Fecha fechaEstrenoBuscada;

    cout << "Ingrese la Fecha de Estreno de la Película a buscar: " << endl;
    fechaEstrenoBuscada.cargar(1);

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoPeliculas.Leer(i).getFechaEstreno() == fechaEstrenoBuscada) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << "NO se encontró ningún registro de la Película con la Fecha de Estreno: " << fechaEstrenoBuscada.toString(1) << "." << endl;
}
