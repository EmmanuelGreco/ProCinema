#include <iostream>
#include <string>
#include "ManagerPelicula.h"
#include "Pelicula.h"
#include "Archivos.h"
#include "Fecha.h"

using namespace std;

Archivos archivoPeliculas("peliculas.dat");


void ManagerPelicula::cargarPelicula() {
    int idPelicula = archivoPeliculas.getUltimoId()+1, clasificacion;
    string titulo, genero, nombreDirector, apellidoDirector;
    bool estado = 1;
    Fecha fechaEstreno;

    cout << "Id: " << idPelicula << endl;

    cout << "Ingrese el Titulo: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Ingrese el Genero: ";
    getline(cin, genero);

    cout << "Ingrese el Nombre del Director: ";
    getline(cin, nombreDirector);

    cout << "Ingrese el Apellido del Director: ";
    getline(cin, apellidoDirector);

    cout << "Ingrese la Clasificacion: ";
    cin >> clasificacion;

    cout << "Ingrese la Fecha de Estreno: " << endl;
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

void ManagerPelicula::modificarPelicula() {
    int id, posicion;

    cout << "Ingrese el Id de la Pelicula a Modificar: ";
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
    cout << "Elija una opcion: ";
    int opcion;
    cin >> opcion;

    int num;
    string str;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo Titulo: ";
        cin.ignore();
        getline(cin, str);
        pelicula.setTitulo(str);
        break;
    case 2:
        cout << "Elija el nuevo Genero: ";
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
        Fecha fechaEstreno;
        fechaEstreno.cargar(1);
        pelicula.setFechaEstreno(fechaEstreno);
        break;
    }

    if(archivoPeliculas.Modificar(pelicula, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerPelicula::cambiarEstadoPelicula() {
    int id, posicion;

    cout << "Ingrese el Id de la Pelicula a dar de baja: ";
    cin >> id;
    posicion = archivoPeliculas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Pelicula pelicula = archivoPeliculas.Leer(posicion);
    pelicula.mostrar();
    cout << "Actualmente, esta Pelicula se encuentra ";
    if (pelicula.getEstado()) cout << "EN CARTELERA.";
    else cout << "FUERA DE CARTELERA.";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        pelicula.setEstado(!pelicula.getEstado());
        archivoPeliculas.Modificar(pelicula, posicion);
        cout << "Modificado exitosamente!";
    } else {
        cout << "No se ha modificado!";
    }
    cout << endl;
}
