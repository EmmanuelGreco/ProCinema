#include <iostream>
#include <string>
#include "ManagerMembresia.h"
#include "Membresia.h"
#include "ArchivoMembresia.h"


using namespace std;

ArchivoMembresia archivoMembresias("membresias.dat");


void ManagerMembresia::cargarMembresia() {
    int idMembresia = archivoMembresias.getUltimoId()+1, tipoMembresia, descuentoMembresia, dniMiembro;
    string nombreMembresia, nombreMiembro, apellidoMiembro, emailMiembro;
    bool estado = 1;


    cout << "Id: " << idMembresia << endl;

    cout << "Ingrese el Tipo de Membresía (1-Plus, 2-Premium, 3-VIP): ";
    //cin.ignore();
    cin >> tipoMembresia;
    while (tipoMembresia < 1 || tipoMembresia > 3) {
        cout << "Tipo de Membresía inválido! Ingrese un número correcto: ";
        cin >> tipoMembresia;
    }

    switch(tipoMembresia) {
    case 1:
        descuentoMembresia = 10;
        nombreMembresia = "Plus";
        break;
    case 2:
        descuentoMembresia = 25;
        nombreMembresia = "Premium";
        break;
    case 3:
        descuentoMembresia = 50;
        nombreMembresia = "VIP";
        break;
    }

    cout << nombreMembresia << ": " << descuentoMembresia << "% OFF." << endl;

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

    if(archivoMembresias.Guardar(Membresia(idMembresia, tipoMembresia, descuentoMembresia, nombreMembresia,
                                           nombreMiembro, apellidoMiembro, dniMiembro, emailMiembro, estado))) {
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

    cout << "Ingrese el Id de la Membresía a Modificar: ";
    cin >> id;
    posicion = archivoMembresias.Buscar(id);
    if (posicion == -1) {
        cout << "Id no encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    cout << "1. " << membresia.getNombreMembresia() << " - " << membresia.getDescuentoMembresia() << "%" << endl;
    cout << "2. " << membresia.getNombreMiembro() << endl;
    cout << "3. " << membresia.getApellidoMiembro() << endl;
    cout << "4. " << membresia.getDniMiembro() << endl;
    cout << "5. " << membresia.getEmailMiembro() << endl;
    //cout << "0. Volver al menu " << endl;
    cout << "Elija una opción: ";
    int opcion;
    cin >> opcion;

    int num;
    string str;
    switch(opcion) {
    case 1:
        int tipoMembresia;
        cout << "Ingrese el nuevo Tipo de Membresía (1-Plus, 2-Premium, 3-VIP): ";
        cin >> tipoMembresia;
        while (tipoMembresia < 1 || tipoMembresia > 3) {
            cout << "Tipo de Membresía inválido! Ingrese un número correcto: ";
            cin >> tipoMembresia;
        }

        switch(tipoMembresia) {
        case 1:
            num = 10;
            str = "Plus";
            break;
        case 2:
            num = 30;
            str = "Premium";
            break;
        case 3:
            num = 50;
            str = "VIP";
            break;
        }
        membresia.setTipoMembresia(tipoMembresia);
        membresia.setDescuentoMembresia(num);
        membresia.setNombreMembresia(str);
        break;
    case 2:
        cout << "Elija el nuevo Nombre del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setNombreMiembro(str);
        break;
    case 3:
        cout << "Elija el nuevo Apellido del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setApellidoMiembro(str);
        break;
    case 4:
        cout << "Elija el nuevo DNI del Miembro: ";
        cin >> num;
        membresia.setDniMiembro(num);
        break;
    case 5:
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

    cout << "Ingrese el Id de la Membresía a Dar de baja / Restaurar: ";
    cin >> id;
    posicion = archivoMembresias.Buscar(id);
    if (posicion == -1) {
        cout << "Id NO encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    membresia.mostrar();
    cout << "Actualmente, esta Membresía se encuentra: ";
    if (membresia.getEstado()) cout << "ACTIVA";
    else cout << "PAUSADA";
    cout << endl << "Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;
    if (toupper(yn) == 'Y') {
        membresia.setEstado(!membresia.getEstado());
        archivoMembresias.Modificar(membresia, posicion);
        cout << "Modificado Exitosamente!";
    } else {
        cout << "NO se ha modificado!";
    }
    cout << endl;
}
