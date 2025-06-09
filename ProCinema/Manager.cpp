#include <iostream>
#include <string>
#include "Manager.h"
#include "Pelicula.h"
#include "Archivos.h"
#include "Fecha.h"

using namespace std;

Archivos ArPel("peliculas.dat");


void Manager::cargarPelicula() {
    int idPelicula = ArPel.getUltimoId()+1, clasificacion;
    string titulo, genero, nombreDirector, apellidoDirector;
    bool estado = 1;
    Fecha fechaEstreno;

    cout << "Id: " << idPelicula << endl;

    cout << "Ingrese el titulo: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Ingrese el genero: ";
    getline(cin, genero);

    cout << "Ingrese el nombre del director: ";
    getline(cin, nombreDirector);

    cout << "Ingrese el genero del director: ";
    getline(cin, apellidoDirector);

    cout << "Ingrese la clasificacion: ";
    cin >> clasificacion;

    cout << "Fecha: " << endl;
    fechaEstreno.cargar(1);

    if(ArPel.Guardar(Pelicula(idPelicula, titulo, genero, nombreDirector, apellidoDirector, clasificacion, fechaEstreno, estado))) {
        cout << "Se guardo correctamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void Manager::listarPeliculas() {
    int cantidadRegistros = ArPel.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << ArPel.Leer(i).mostrar() << endl;
    }
}

void Manager::modificarPelicula() {
    int id, pos;

    cout << "Ingrese el Id de la pelicula a modificar: ";
    cin >> id;
    pos = ArPel.Buscar(id);
    if (pos == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Pelicula peli = ArPel.Leer(pos);
    cout << "1. " << peli.getTitulo() << endl;
    cout << "2. " << peli.getGenero() << endl;
    cout << "3. " << peli.getNombreDirector() << endl;
    cout << "4. " << peli.getApellidoDirector() << endl;
    cout << "5. " << peli.getClasificacion() << endl;
    cout << "6. " << peli.getFechaEstreno().toString(1) << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opcion: ";
    int input;
    cin >> input;

    int num;
    string str;
    switch(input) {
    case 1:
        cout << "Elija el nuevo titulo: ";
        cin.ignore();
        getline(cin, str);
        peli.setTitulo(str);
        break;
    case 2:
        cout << "Elija el nuevo genero: ";
        cin.ignore();
        getline(cin, str);
        peli.setGenero(str);
        break;
    case 3:
        cout << "Elija el nuevo nombre del director: ";
        cin.ignore();
        getline(cin, str);
        peli.setNombreDirector(str);
        break;
    case 4:
        cout << "Elija el nuevo apellido del director: ";
        cin.ignore();
        getline(cin, str);
        peli.setApellidoDirector(str);
        break;
    case 5:
        cout << "Elija la nueva clasificación: ";
        cin >> num;
        peli.setClasificacion(num);
        break;
    case 6:
        cout << "Elija la nueva fecha de estreno: " << endl;
        Fecha fechaEstreno;
        fechaEstreno.cargar(1);
        peli.setFechaEstreno(fechaEstreno);
        break;
    }

    if(ArPel.Guardar(peli, pos)) cout << "Modificado correctamente!" << endl;




}
