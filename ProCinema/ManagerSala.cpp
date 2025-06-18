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

    cout << "Ingrese el tipo de Sala (1-standard, 2-premium, 3-3D, 4-4D, 5-IMAX): ";
    cin.ignore();
    cin >> tipoSala;

    cout << "Ingrese la cantidad de Bucatas Totales: ";
    cin >> butacasTotales;

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

void ManagerSala::modificarSala() {
    int id, posicion;

    cout << "Ingrese el Id de la Sala a Modificar: ";
    cin >> id;
    posicion = archivoSalas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    cout << "1. " << sala.getTipoSala() << endl;
    cout << "2. " << sala.getButacasTotales() << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opcion: ";
    int opcion;
    cin >> opcion;

    int num;
    switch(opcion) {
    case 1:
        cout << "Elija el nuevo Tipo de Sala: ";
        cin >> num;
        sala.setTipoSala(num);
        break;
    case 2:
        cout << "Elija la nueva Cantidad de Butacas: ";
        cin >> num;
        sala.setButacasTotales(num);
        break;
    }

    if(archivoSalas.Modificar(sala, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerSala::cambiarEstadoSala() {
    int id, posicion;

    cout << "Ingrese el Id de la Sala a dar de baja: ";
    cin >> id;
    posicion = archivoSalas.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Sala sala = archivoSalas.Leer(posicion);
    sala.mostrar();
    cout << "Actualmente, esta Sala se encuentra ";
    if (sala.getEstado()) cout << "EN FUNCIONAMIENTO.";
    else cout << "FUERA DE SERVICIO.";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        sala.setEstado(!sala.getEstado());
        archivoSalas.Modificar(sala, posicion);
        cout << "Modificado exitosamente!";
    } else {
        cout << "No se ha modificado!";
    }
    cout << endl;
}
