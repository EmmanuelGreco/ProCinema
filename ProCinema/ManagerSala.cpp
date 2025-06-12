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
