#include <iostream>
#include <string>
#include "ManagerMembresia.h"
#include "Membresia.h"
#include "ArchivoMembresia.h"


using namespace std;


void ManagerMembresia::cargarMembresia() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idMembresia = archivoMembresias.getUltimoId()+1, tipoMembresia, descuentoMembresia, dniMiembro;
    string nombreMembresia, nombreMiembro, apellidoMiembro, emailMiembro;
    bool estado = 1;


    cout << "  ID: " << idMembresia << endl;

    cout << "  Ingrese el Tipo de Membresía (1-Plus, 2-Premium, 3-VIP): ";
    //cin.ignore();
    cin >> tipoMembresia;
    while (!validarNumero(tipoMembresia, 1, 3)) {
        cout << "  Error! Ingrese un tipo de Membresía válido: ";
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

    cout << "  Ingrese el Nombre del Miembro: ";
    cin.ignore();
    getline(cin, nombreMiembro);

    cout << "  Ingrese el Apellido del Miembro: ";
    getline(cin, apellidoMiembro);

    cout << "  Ingrese el DNI del Miembro: ";
    cin >> dniMiembro;
    while (!validarNumero(dniMiembro, 0)) {
        cout << "  Error! Ingrese un DNI válido: ";
        cin >> dniMiembro;
    }

    cout << "  Ingrese el Email del Miembro: ";
    cin.ignore();
    getline(cin, emailMiembro);

    cout << endl;
    if(archivoMembresias.Guardar(Membresia(idMembresia, tipoMembresia, descuentoMembresia, nombreMembresia,
                                           nombreMiembro, apellidoMiembro, dniMiembro, emailMiembro, estado))) {
        cout << "Se guardo Exitosamente!" << endl;
    } else {
        cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
    }
    cout << endl;
}

void ManagerMembresia::listarMembresias() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int cantidadRegistros = archivoMembresias.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        cout << archivoMembresias.Leer(i).mostrar() << endl;
    }
}

void ManagerMembresia::listarMembresias(bool activas) {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int cantidadRegistros = archivoMembresias.CantidadRegistros();
    Membresia membresia;

    for (int i = 0; i < cantidadRegistros; i++) {
        membresia = archivoMembresias.Leer(i);

        if (membresia.getEstado() == activas) {
            cout << membresia.mostrar() << endl;
        }
    }
}

void ManagerMembresia::modificarMembresia() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idMembresia, posicion;

    cout << "  Ingrese el ID de la Membresía a Modificar: ";
    cin >> idMembresia;
    //idMembresia -= 1;
    while (!validarNumero(idMembresia, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idMembresia;
        //idMembresia -= 1;
    }
    posicion = archivoMembresias.Buscar(idMembresia);
    if (posicion == -1) {
        cout << "ID NO encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    cout << endl;
    cout << "  1. Tipo de Membresía: " << membresia.getNombreMembresia() << " - " << membresia.getDescuentoMembresia() << "%" << endl;
    cout << "  2. Nombre: " << membresia.getNombreMiembro() << endl;
    cout << "  3. Apellido: " << membresia.getApellidoMiembro() << endl;
    cout << "  4. DNI: " << membresia.getDniMiembro() << endl;
    cout << "  5. Email: " << membresia.getEmailMiembro() << endl;
    //cout << "  0. Volver al menu " << endl;
    cout << endl;
    cout << "  Elija una Opción: ";
    int opcion;
    cin >> opcion;
    while (!validarNumero(opcion, 1, 5)) {
        cout << "  Error! Ingrese una Opcion válida: ";
        cin >> opcion;
    }

    int num;
    string str;
    switch(opcion) {
    case 1:
        int tipoMembresia;
        cout << "  Ingrese el nuevo Tipo de Membresía (1-Plus, 2-Premium, 3-VIP): ";
        cin >> tipoMembresia;
        while (!validarNumero(tipoMembresia, 1, 3)) {
            cout << "  Error! Ingrese un tipo de membresía válido: ";
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
        cout << "  Elija el nuevo Nombre del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setNombreMiembro(str);
        break;
    case 3:
        cout << "  Elija el nuevo Apellido del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setApellidoMiembro(str);
        break;
    case 4:
        cout << "  Elija el nuevo DNI del Miembro: ";
        cin >> num;
        while (!validarNumero(num, 0)) {
            cout << "  Error! Ingrese un DNI válido: ";
            cin >> num;
        }
        membresia.setDniMiembro(num);
        break;
    case 5:
        cout << "  Elija el nuevo Email del Miembro: ";
        cin.ignore();
        getline(cin, str);
        membresia.setEmailMiembro(str);
        break;
    }

    cout << endl;
    if(archivoMembresias.Modificar(membresia, posicion)) cout << "  Modificado Exitosamente!" << endl;
    cout << endl;
}

void ManagerMembresia::cambiarEstadoMembresia() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idMembresia, posicion;

    cout << "  Ingrese el ID de la Membresía a Pausar / Renovar: ";
    cin >> idMembresia;
    //idMembresia -= 1;
    while (!validarNumero(idMembresia, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idMembresia;
        //idMembresia -= 1;
    }
    posicion = archivoMembresias.Buscar(idMembresia);
    if (posicion == -1) {
        cout << "  ID NO encontrado!";
        return;
    }
    Membresia membresia = archivoMembresias.Leer(posicion);
    membresia.mostrar();

    cout << endl;
    cout << "  Actualmente, esta Membresía se encuentra: ";
    if (membresia.getEstado()) cout << "ACTIVA";
    else cout << "PAUSADA";
    cout << endl << "  Desea modificar su estado? (Y-N): ";
    char yn;
    cin >> yn;

    cout << endl;
    if (toupper(yn) == 'Y') {
        membresia.setEstado(!membresia.getEstado());
        archivoMembresias.Modificar(membresia, posicion);
        cout << "  Modificado Exitosamente!";
    } else {
        cout << "  NO se ha podido modificar!";
    }
    cout << endl;
    cout << endl;
}


///BUSCAR POR...

void ManagerMembresia::buscarPorId() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int idBuscado;

    cout << "  Ingrese el ID de la Membresia a Buscar: ";
    cin >> idBuscado;
    //idBuscado -= 1;
    while (!validarNumero(idBuscado, 0)) {
        cout << "  Error! Ingrese un ID válido: ";
        cin >> idBuscado;
        //idBuscado -= 1;
    }

    int cantidadRegistros = archivoMembresias.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoMembresias.Leer(i).getIdMembresia() == idBuscado) {
            cout << archivoMembresias.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "  NO se encontró ningún registro con el ID: " << idBuscado << "." << endl;
}

void ManagerMembresia::buscarPorDNI() {
    ArchivoMembresia archivoMembresias("membresias.dat");
    int dniBuscado;

    cout << "  Ingrese el DNI de la Membresia a Buscar: ";
    cin >> dniBuscado;
    while (!validarNumero(dniBuscado, 0)) {
        cout << "  Error! Ingrese un DNI válido: ";
        cin >> dniBuscado;
    }

    int cantidadRegistros = archivoMembresias.CantidadRegistros();
    int cantidadEncontrados = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (archivoMembresias.Leer(i).getDniMiembro() == dniBuscado) {
            cout << archivoMembresias.Leer(i).mostrar() << endl;
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0)
        cout << endl << "  NO se encontró ningún registro con el DNI: " << dniBuscado << "." << endl;
}

bool ManagerMembresia::validarNumero(int input, int minimo, int maximo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo && input <= maximo);
    }
}

bool ManagerMembresia::validarNumero(int input, int minimo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo);
    }
}
