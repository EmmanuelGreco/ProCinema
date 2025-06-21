#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

void Menu::setOpcion(int opcion) {
    _opcion = opcion;
}

int Menu::getOpcion() {
    return _opcion;
}

void Menu::recibirOpcion(int maximo) {
    int input;
    cin >> input;

    while (!opcionValida(input, maximo)) {
        cout << "Ingrese una opci�n v�lida: ";
        cin >> input;
    }
    setOpcion(input);
}

bool Menu::opcionValida(int input, int maximo) {//no le asign� un minimo xq asumo que simepre va a ser 0, para volver atras o salir.
    if (cin.fail()) {
        cin.clear();                            // Limpiar el estado de error
        while (cin.get() != '\n');              // Este LOOP descarta caracteres, no hace nada dentro del ciclo
        return false;
    } else {
        return (input >= 0 && input <= maximo);
    }
}

void Menu::principal() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Menu Principal -----------------" << endl;
    cout << "1.  Ventas..." << endl;
    cout << "2.  Pel�culas..." << endl;
    cout << "3.  Funciones..." << endl;
    cout << "4.  Informes..." << endl;
    cout << "5.  Configuraci�n..." << endl;
    cout << "0.  Salir del programa... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::ventas() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------------- Ventas ---------------------" << endl;
    cout << "1.  Registrar Venta" << endl;
    cout << "2.  Dar de baja una Venta" << endl;
    cout << "3.  Modificar una Venta" << endl;
    cout << "4.  Listar todas las Ventas registradas" << endl;
    cout << "5.  Buscar Ventas por..." << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::BuscarVentasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar Ventas por ----------------" << endl;
    cout << "1.  ID de Venta" << endl;
    cout << "2.  Funci�n" << endl;
    cout << "3.  DNI" << endl;
    cout << "4.  N�mero de Miembro" << endl;
    cout << "5.  Fecha de Venta" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::peliculas() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Pel�culas --------------------" << endl;
    cout << "1.  Agregar Pel�cula" << endl;
    cout << "2.  Dar de baja / Restaurar Pel�cula" << endl;
    cout << "3.  Modificar una Pel�cula" << endl;
    cout << "4.  Listar Pel�culas por..." << endl;
    cout << "5.  Buscar Pel�culas por..." << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::listarPeliculasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Listar Pel�culas por ---------------" << endl;
    cout << "1.  Todas las Pel�culas" << endl;
    cout << "2.  Pel�culas CARTELERA" << endl;
    cout << "3.  Pel�culas FUERA DE CARTELERA" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::BuscarPeliculasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Buscar Pel�culas por --------------" << endl;
    cout << "1.  ID de Pel�cula" << endl;
    cout << "2.  T�tulo" << endl;
    cout << "3.  G�nero" << endl;
    cout << "4.  Apellido del Director" << endl;
    cout << "5.  Clasificaci�n" << endl;
    cout << "6.  Fecha de Estreno" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::funciones() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Funciones --------------------" << endl;
    cout << "1.  Agregar una Funci�n" << endl;
    cout << "2.  Dar de baja / Restaurar una Funci�n" << endl;
    cout << "3.  Modificar una Funci�n" << endl;
    cout << "4.  Listar Funciones por..." << endl;
    cout << "5.  Buscar Funciones por..." << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::ListarFuncionPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Listar Funci�n -----------------" << endl;
    cout << "1.  Todas las Funciones" << endl;
    cout << "2.  Funciones en CARTELERA" << endl;
    cout << "3.  Funciones AGOTADAS" << endl;
    cout << "4.  Funciones FUERA DE CARTELERA" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::BuscarFuncionPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar Funci�n por ---------------" << endl;
    cout << "1.  ID de la Funci�n" << endl;
    cout << "2.  T�tulo de Pel�cula" << endl;
    cout << "3.  N�mero de Sala" << endl;
    cout << "4.  Fecha de la Funci�n" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::informes() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------------- Informes --------------------" << endl;
    cout << "1.  Top X Pel�culas del A�o" << endl;
    cout << "2.  Recaudaci�n Total..." << endl;
    cout << "3.  Porcentaje de Compras de Miembros" << endl;
    cout << "4.  Miembros m�s Frecuentes" << endl;
    cout << "5.  Ocupaci�n Promedio por Sala" << endl;
    cout << "6.  Funciones con Menor Ocupaci�n" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::RecaudacionTotalPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "----------------- Recaudaci�n por -----------------" << endl;
    cout << "1.  Pel�cula" << endl;
    cout << "2.  A�o" << endl;
    cout << "3.  Sala" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracion() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Configuraci�n ------------------" << endl;
    cout << "1.  Salas..." << endl;
    cout << "2.  Membres�as..." << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(2);
    system("cls");
}

void Menu::configuracionSalas() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Configurar Salas -----------------" << endl;
    string queMenuEs = "Sala";
    configuracionOpciones(queMenuEs);
    recibirOpcion(4);
    system("cls");
}

void Menu::listarSalasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "----------------- Listar Salas por ----------------" << endl;
    cout << "1.  Todas las Salas" << endl;
    cout << "2.  Salas EN FUNCIONAMIENTO" << endl;
    cout << "3.  Salas FUERA DE SERVICIO" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracionMembresias() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------- Configurar Membres�as --------------" << endl;
    string queMenuEs = "Membres�a";
    configuracionOpciones(queMenuEs);
    recibirOpcion(4);
    system("cls");
}

void Menu::listarMembresiasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Listar Membres�as por --------------" << endl;
    cout << "1.  Todas las Membres�as" << endl;
    cout << "2.  Membres�as ACTIVAS" << endl;
    cout << "3.  Membres�as PAUSADAS" << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracionOpciones(string queMenuEs) {
    cout << "1.  Listar " << queMenuEs << "s por..." << endl;
    cout << "2.  Agregar una " << queMenuEs << endl;
    cout << "3.  Dar de baja / Restaurar una " << queMenuEs << endl;
    cout << "4.  Modificar una " << queMenuEs << endl;
    cout << "0.  Volver atr�s... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
}
