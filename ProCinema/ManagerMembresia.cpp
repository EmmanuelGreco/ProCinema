#include <iostream>
#include <string>
#include "ManagerMembresia.h"
#include "Membresia.h"
#include "ArchivoMembresia.h"


using namespace std;

ArchivoMembresia archivoMembresias("membresias.dat");


void ManagerMembresia::cargarMembresia() {
    int idMembresia = archivoMembresias.getUltimoId()+1, tipoMembresia, descuentoMembresia, dniMiembro;
    string nombreMiembro, apellidoMiembro, emailMiembro;
    bool estado = 1;


    cout << "Id: " << idMembresia << endl;

    cout << "Ingrese el Tipo de Membresia: ";
    cin.ignore();
    cin >> tipoMembresia;

    cout << "Ingrese el Descuento de la Membresia: ";
    cin >> descuentoMembresia;

    cout << "Ingrese el Nombre del Miembro: ";
    cin.ignore();
    getline(cin, nombreMiembro);

    cout << "Ingrese el Apellido del Miembro: ";
    getline(cin, apellidoMiembro);

    cout << "Ingrese el DNI del Miembro: ";
    cin >> dniMiembro;

    cout << "Ingrese el Email del Miembro: ";
    cin.ignore();
    getline(cin, emailMiembro);

    if(archivoMembresias.Guardar(Membresia(idMembresia, tipoMembresia, descuentoMembresia, nombreMiembro, apellidoMiembro,
                                          dniMiembro, emailMiembro, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
}

void ManagerMembresia::listarMembresias() {
    int cantidadRegistros = archivoMembresias.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoMembresias.Leer(i).mostrar() << endl;
    }
}
