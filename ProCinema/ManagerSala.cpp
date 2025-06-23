#include <iostream>
#include "ManagerSala.h"
#include "Sala.h"
#include "ArchivoSala.h"


using namespace std;


void ManagerSala::cargarSala() {
    ArchivoSala archivoSalas("salas.dat");
    int idSala = archivoSalas.getUltimoId()+1, tipoSala, butacasTotales;
    bool estado = 1;

    cout << "  ID: " << idSala + 1<< endl;

    cout << "  Ingrese el Tipo de Sala (1-Standard, 2-Premium, 3-3D, 4-4D, 5-IMAX): ";
    cin >> tipoSala;
    while (!validarNumero(tipoSala, 1, 5)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> tipoSala;
    }

    cout << "  Ingrese la cantidad de Bucatas Totales: ";
    cin >> butacasTotales;
    while (!validarNumero(butacasTotales, 1)) {
        cout << "  Error! Ingrese una cantidad de Butacas válida: ";
        cin >> butacasTotales;
    }

    cout << endl;
    if(archivoSalas.Guardar(Sala(idSala, tipoSala, butacasTotales, estado))) {
        cout << "  Se guardo Exitosamente!" << endl;
    } else {
        cout << "  Hubo un error inesperado, llame al de sistemas..." << endl;
    }
    cout << endl;
}

void ManagerSala::listarSalas() {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadRegistros = archivoSalas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoSalas.Leer(i).mostrar() << endl;
    }
}

void ManagerSala::listarSalas(bool activas) {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadRegistros = archivoSalas.CantidadRegistros();
    Sala sala;

    for (int i = 0; i < cantidadRegistros; i++) {
        sala = archivoSalas.Leer(i);

        if (sala.getEstado() == activas) {
            cout << sala.mostrar() << endl;
        }
    }
}

void ManagerSala::modificarSala() {
    ArchivoSala archivoSalas("salas.dat");
    int idSala, posicion;

    cout << "  Ingrese el ID de la Sala a Modificar: ";
    cin >> idSala;
    idSala -= 1;
    while (!validarNumero(idSala, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idSala;
        idSala -= 1;
    }
    posicion = archivoSalas.Buscar(idSala);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    cout << endl;
    cout << "  1. Tipo de Sala(1-Standard, 2-Premium, 3-3D, 4-4D, 5-IMAX): " << sala.getTipoSala() << endl;
    cout << "  2. Cantidad de Butacas Totales: " << sala.getButacasTotales() << endl;
    //cout << "0. Volver al menu " << endl;
    cout << endl;
    cout << "  Elija una Opción: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 0)) {
        cout << "  Ingrese una Opción válida: ";
        cin >> opcion;
    }

    int num;
    switch(opcion) {
    case 1:
        cout << " Elija el nuevo Tipo de Sala: (1-Standard, 2-Premium, 3-3D, 4-4D, 5-IMAX): ";
        cin >> num;
        while (!validarNumero(num, 1, 5)) {
            cout << "  Error! Ingrese una Opción válida (1-Standard, 2-Premium, 3-3D, 4-4D, 5-IMAX): : ";
            cin >> num;
        }
        sala.setTipoSala(num);
        break;
    case 2:
        cout << "  Elija la nueva cantidad de Butacas: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "  Error! Ingrese una cantidad de Butacas válida: ";
            cin >> num;
        }
        sala.setButacasTotales(num);
        break;
    }

    cout << endl;
    if(archivoSalas.Modificar(sala, posicion)) cout << "  Modificado Exitosamente!" << endl;
    cout << endl;
}

void ManagerSala::cambiarEstadoSala() {
    ArchivoSala archivoSalas("salas.dat");
    int idSala, posicion;

    cout << "  Ingrese el ID de la Sala a Dar de baja / Restaurar: ";
    cin >> idSala;
    idSala -= 1;
    while (!validarNumero(idSala, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idSala;
        idSala -= 1;
    }
    posicion = archivoSalas.Buscar(idSala);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    sala.mostrar();

    cout << endl;
    cout << "  Actualmente, esta Sala se encuentra: ";
    if (sala.getEstado()) cout << "EN FUNCIONAMIENTO";
    else cout << "FUERA DE SERVICIO";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;

    cout << endl;
    if (toupper(yn) == 'Y') {
        sala.setEstado(!sala.getEstado());
        archivoSalas.Modificar(sala, posicion);
        cout << "  Modificado Exitosamente!";
    } else {
        cout << "  NO se ha podido modificar!";
    }
    cout << endl;
    cout << endl;
}

bool ManagerSala::validarNumero(int input, int minimo, int maximo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo && input <= maximo);
    }
}

bool ManagerSala::validarNumero(int input, int minimo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo);
    }
}
