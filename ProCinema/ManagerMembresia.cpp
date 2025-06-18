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

void ManagerMembresia::modificarMembresia() {
    int id, posicion;

    cout << "Ingrese el Id de la Membresia a Modificar: ";
    cin >> id;
    posicion = archivoMembresias.Buscar(id);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    cout << "1. " << membresia.getTipoMembresia() << endl;
    cout << "2. " << membresia.getDescuentoMembresia() << endl;
    cout << "3. " << membresia.getNombreMiembro() << endl;
    cout << "4. " << membresia.getApellidoMiembro() << endl;
    cout << "5. " << membresia.getDniMiembro() << endl;
    cout << "6. " << membresia.getEmailMiembro() << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opcion: ";
    int opcion;
    cin >> opcion;

    int num;
    string str;
    switch(opcion) {
    case 1:
        cout << "Elija el Tipo de Membresia: ";
        cin >> num;
        membresia.setTipoMembresia(num);
        break;
    case 2:
        cout << "Elija el Descuento de Membresia: ";
        cin >> num;
        membresia.setDescuentoMembresia(num);
        break;
    case 3:
        cout << "Elija el nuevo Nombre del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setNombreMiembro(str);
        break;
    case 4:
        cout << "Elija el nuevo Apellido del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setApellidoMiembro(str);
        break;
    case 5:
        cout << "Elija el nuevo DNI del Miembro: ";
        cin >> num;
        membresia.setDniMiembro(num);
        break;
    case 6:
        cout << "Elija el nuevo Email del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setEmailMiembro(str);
        break;
    }

    if(archivoMembresias.Modificar(membresia, posicion)) cout << "Modificado Exitosamente!" << endl;
}

void ManagerMembresia::cambiarEstadoMembresia() {
    int id, posicion;

    cout << "Ingrese el Id de la Membresia a dar de baja: ";
    cin >> id;
    posicion = archivoMembresias.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    membresia.mostrar();
    cout << "Actualmente, esta Membresia se encuentra ";
    if (membresia.getEstado()) cout << "ACTIVA.";
    else cout << "PAUSADA.";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        membresia.setEstado(!membresia.getEstado());
        archivoMembresias.Modificar(membresia, posicion);
        cout << "Modificado exitosamente!";
    } else {
        cout << "No se ha modificado!";
    }
    cout << endl;
}
