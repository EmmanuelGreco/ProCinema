#include <iostream>
#include <string>
#include "ManagerPelicula.h"
#include "Pelicula.h"
#include "ArchivoPelicula.h"
#include "Fecha.h"

using namespace std;


void ManagerPelicula::cargarPelicula() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idPelicula = archivoPeliculas.getUltimoId()+1, clasificacion;
    string titulo, genero, nombreDirector, apellidoDirector;
    bool estado = 1;
    Fecha fechaEstreno;

    cout << "  ID: " << idPelicula + 1<< endl;

    cout << "  Ingrese el Título: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "  Ingrese el Género: ";
    getline(cin, genero);

    cout << "  Ingrese el Nombre del Director: ";
    getline(cin, nombreDirector);

    cout << "  Ingrese el Apellido del Director: ";
    getline(cin, apellidoDirector);

    cout << "  Ingrese la Clasificación: ";
    cin >> clasificacion;
    while (!validarNumero(clasificacion, 0)) {
        cout << "  Error! Ingrese una Clasificación válida: ";
        cin >> clasificacion;
    }

    cout << endl;
    cout << "  Ingrese la Fecha de Estreno: " << endl;
    //cin.ignore();
    fechaEstreno.cargar(1);

    cout << endl;
    if(archivoPeliculas.Guardar(Pelicula(idPelicula, titulo, genero, nombreDirector, apellidoDirector,
                                         clasificacion, fechaEstreno, estado))) {
        cout << "  Se guardo Exitosamente!" << endl;
    } else {
        cout << "  Hubo un error inesperado, llame al de sistemas..." << endl;
    }
    cout << endl;
}

void ManagerPelicula::listarPeliculas() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadRegistros = archivoPeliculas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoPeliculas.Leer(i).mostrar() << endl;
    }
}

void ManagerPelicula::listarPeliculas(bool activas) {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    Pelicula pelicula;

    for (int i = 0; i < cantidadRegistros; i++) {
        pelicula = archivoPeliculas.Leer(i);

        if (pelicula.getEstado() == activas) {
            cout << pelicula.mostrar() << endl;
        }
    }
}

void ManagerPelicula::modificarPelicula() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idPelicula, posicion;

    cout << "  Ingrese el ID de la Película a Modificar: ";
    cin >> idPelicula;
    idPelicula -= 1;
    while (!validarNumero(idPelicula, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idPelicula;
        idPelicula -= 1;
    }
    posicion = archivoPeliculas.Buscar(idPelicula);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    cout << endl;
    cout << "  1. Título: " << pelicula.getTitulo() << endl;
    cout << "  2. Género: " << pelicula.getGenero() << endl;
    cout << "  3. Nombre del Director: " << pelicula.getNombreDirector() << endl;
    cout << "  4. Apellido del Director: " << pelicula.getApellidoDirector() << endl;
    cout << "  5. Clasifiación: " << pelicula.getClasificacion() << endl;
    cout << "  6. Fecha de Estreno: " << pelicula.getFechaEstreno().toString(1) << endl;
    cout << endl;
    cout << "  Elija una Opción: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 1, 6)) {
        cout << "Error! Ingrese una Opción válida: ";
        cin >> opcion;
    }

    int num;
    string str;
    Fecha fechaEstreno;
    switch(opcion) {
    case 1:
        cout << "  Elija el nuevo Título: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setTitulo(str);
        break;
    case 2:
        cout << "  Elija el nuevo Género: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setGenero(str);
        break;
    case 3:
        cout << "  Elija el nuevo Nombre del Director: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setNombreDirector(str);
        break;
    case 4:
        cout << "  Elija el nuevo Apellido del Director: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setApellidoDirector(str);
        break;
    case 5:
        cout << "  Elija la nueva Clasificación: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "  Error! Ingrese una Clasificación válida: ";
            cin >> num;
        }
        pelicula.setClasificacion(num);
        break;
    case 6:
        cout << "  Elija la nueva Fecha de Estreno: " << endl;
        fechaEstreno.cargar(1);
        pelicula.setFechaEstreno(fechaEstreno);
        break;
    }

    cout << endl;
    if(archivoPeliculas.Modificar(pelicula, posicion)) cout << "  Modificado Exitosamente!" << endl;
    cout << endl;
}

void ManagerPelicula::cambiarEstadoPelicula() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idPelicula, posicion;

    cout << "  Ingrese el ID de la Película a Dar de baja / Restaurar: ";
    cin >> idPelicula;
    idPelicula -= 1;
    while (!validarNumero(idPelicula, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idPelicula;
        idPelicula -= 1;
    }
    posicion = archivoPeliculas.Buscar(idPelicula);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    pelicula.mostrar();

    cout << endl;
    cout << "  Actualmente, esta Película se encuentra: ";
    if (pelicula.getEstado()) cout << "EN CARTELERA";
    else cout << "FUERA DE CARTELERA";
    cout << endl << "  Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;

    cout << endl;
    if (toupper(yn) == 'Y') {
        pelicula.setEstado(!pelicula.getEstado());
        archivoPeliculas.Modificar(pelicula, posicion);
        cout << "  Modificado Exitosamente!";
    } else {
        cout << "  NO se ha podido Modificar!";
    }
    cout << endl;
    cout << endl;
}


///BUSCAR POR...

void ManagerPelicula::buscarPorId() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int idBuscado;

    cout << "  Ingrese el ID de Película a Buscar: ";
    cin >> idBuscado;
    idBuscado -= 1;
    while (!validarNumero(idBuscado, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idBuscado;
        idBuscado -= 1;
    }

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoPeliculas.Leer(i).getIdPelicula() == idBuscado) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "  NO se encontró ningún registro con el ID: " << idBuscado+1 << "." << endl;
}

void ManagerPelicula::buscarPorTitulo() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    char tituloBuscado[50];

    cout << "  Ingrese el Título de la Película a Buscar: ";
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
        cout << endl << "  NO se encontró ningún registro con el Título: " << tituloBuscado << "." << endl;
}

void ManagerPelicula::buscarPorGenero() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    char generoBuscado[20];

    cout << "  Ingrese el Género de la Película a Buscar: ";
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
        cout << endl << "  NO se encontró ningún registro con el Género: " << generoBuscado << "." << endl;
}

void ManagerPelicula::buscarPorApellidoDirector() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    char apellidoDirectorBuscado[50];

    cout << "  Ingrese el Apellido del Director de la Película a Buscar: ";
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
        cout << endl << "  NO se encontró ningún registro con el Apellido del Director: " << apellidoDirectorBuscado << "." << endl;
}

void ManagerPelicula::buscarPorClasificacion() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int clasificacionBuscada;

    cout << "  Ingrese el Tipo de Clasificación de Película a Buscar: ";
    cin >> clasificacionBuscada;
    while (!validarNumero(clasificacionBuscada, 0)) {
        cout << "  Error! Ingrese una Clasificación válida: ";
        cin >> clasificacionBuscada;
    }

    int cantidadRegistros = archivoPeliculas.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoPeliculas.Leer(i).getClasificacion() == clasificacionBuscada) {
            cout << archivoPeliculas.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "  NO se encontró ningún registro con el Tipo de Clasificación: " << clasificacionBuscada << "." << endl;
}

void ManagerPelicula::buscarPorFechaEstreno() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    Fecha fechaEstrenoBuscada;

    cout << "  Ingrese la Fecha de Estreno de la Película a Buscar: " << endl;
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
        cout << endl << "  NO se encontró ningún registro con la Fecha de Estreno: " << fechaEstrenoBuscada.toString(1) << "." << endl;
}

bool ManagerPelicula::validarNumero(int input, int minimo, int maximo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo && input <= maximo);
    }
}

bool ManagerPelicula::validarNumero(int input, int minimo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo);
    }
}
