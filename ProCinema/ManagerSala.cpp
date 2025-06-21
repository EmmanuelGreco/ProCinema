#include <iostream>
#include "ManagerSala.h"
#include "Sala.h"
#include "ArchivoSala.h"


using namespace std;

ArchivoSala archivoSalas("salas.dat");


void ManagerSala::cargarSala() {
    int idSala = archivoSalas.getUltimoId()+1, tipoSala, butacasTotales;
    bool estado = 1;

    cout << "Id: " << idSala << endl;

    cout << "Ingrese el tipo de Sala (1-Standard, 2-Premium, 3-3D, 4-4D, 5-IMAX): ";
    cin >> tipoSala;
    while (!validarNumero(tipoSala, 1, 5)) {
        cout << "Ingrese un id válido: ";
        cin >> tipoSala;
    }

    cout << "Ingrese la cantidad de Bucatas Totales: ";
    cin >> butacasTotales;
    while (!validarNumero(butacasTotales, 1)) {
        cout << "Ingrese una cantidad válida: ";
        cin >> butacasTotales;
    }

    if(archivoSalas.Guardar(Sala(idSala, tipoSala, butacasTotales, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void ManagerSala::listarSalas() {
    int cantidadRegistros = archivoSalas.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoSalas.Leer(i).mostrar() << endl;
    }
}

void ManagerSala::listarSalasActivas(bool activas) {
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
    int id, posicion;

    cout << "Ingrese el Id de la Sala a Modificar: ";
    cin >> id;
    while (!validarNumero(id, 0)) {
        cout << "Ingrese un id válido: ";
        cin >> id;
    }
    posicion = archivoSalas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    cout << "1. " << sala.getTipoSala() << endl;
    cout << "2. " << sala.getButacasTotales() << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 0)) {
        cout << "Ingrese una opción válida: ";
        cin >> opcion;
    }

    int num;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo Tipo de Sala: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "Ingrese una opción válida: ";
            cin >> num;
        }
        sala.setTipoSala(num);
        break;
    case 2:
        cout << "Elija la nueva Cantidad de Butacas: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "Ingrese una cantidad válida: ";
            cin >> num;
        }
        sala.setButacasTotales(num);
        break;
    }

    if(archivoSalas.Modificar(sala, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerSala::cambiarEstadoSala() {
    int id, posicion;

    cout << "Ingrese el Id de la Sala a Dar de baja / Restaurar: ";
    cin >> id;
    while (!validarNumero(id, 0)) {
        cout << "Ingrese un id válido: ";
        cin >> id;
    }
    posicion = archivoSalas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    sala.mostrar();
    cout << "Actualmente, esta Sala se encuentra: ";
    if (sala.getEstado()) cout << "EN FUNCIONAMIENTO";
    else cout << "FUERA DE SERVICIO";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        sala.setEstado(!sala.getEstado());
        archivoSalas.Modificar(sala, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
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
