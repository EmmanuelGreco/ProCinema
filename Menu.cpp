#include <iostream>
using namespace std;

#include "Menu.h"

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
    system("cls");
}

bool Menu::opcionValida(int input, int maximo) {
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
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Menu principal -----------------" << endl;
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
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------------- Ventas ---------------------" << endl;
    cout << "1.  Registrar venta" << endl;
    cout << "2.  Listar todas las ventas" << endl;
    cout << "3.  Buscar ventas por..." << endl;
    cout << "4.  Cancelar venta" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::BuscarVentasPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar ventas por ----------------" << endl;
    cout << "1.  ID de venta" << endl;
    cout << "2.  Funci�n" << endl;
    cout << "3.  DNI" << endl;
    cout << "4.  N�mero de miembro" << endl;
    cout << "5.  Fecha de venta" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::peliculas() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Pel�culas --------------------" << endl;
    cout << "1.  Agregar pel�cula" << endl;
    cout << "2.  Eliminar pel�cula" << endl;
    cout << "3.  Modificar una pel�cula" << endl;
    cout << "4.  Listar todas las pel�culas en cartelera" << endl;
    cout << "5.  Buscar pel�culas por..." << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::BuscarPeliculasPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Buscar pel�culas por --------------" << endl;
    cout << "1.  ID de pel�cula" << endl;
    cout << "2.  T�tulo" << endl;
    cout << "3.  G�nero" << endl;
    cout << "4.  Apellido del director" << endl;
    cout << "5.  Clasificaci�n" << endl;
    cout << "6.  Fecha de estreno" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::funciones() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Funciones --------------------" << endl;
    cout << "1.  Agregar una funci�n" << endl;
    cout << "2.  Eliminar una funci�n" << endl;
    cout << "3.  Modificar una funci�n" << endl;
    cout << "4.  Listar funciones..." << endl;
    cout << "5.  Buscar funciones por..." << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::ListarFuncionPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Listar funcion -----------------" << endl;
    cout << "1.  Todas las funciones" << endl;
    cout << "2.  Funciones en venta" << endl;
    cout << "3.  Funciones agotadas" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::BuscarFuncionPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar funcion por ---------------" << endl;
    cout << "1.  ID de funcion" << endl;
    cout << "2.  T�tulo de pel�cula" << endl;
    cout << "3.  N�mero de sala" << endl;
    cout << "4.  Fecha" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::informes() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------------- Informes --------------------" << endl;
    cout << "1.  Top X pel�culas del a�o" << endl;
    cout << "2.  Recaudaci�n total..." << endl;
    cout << "3.  Porcentaje de compras de miembros" << endl;
    cout << "4.  Miembros m�s frecuentes" << endl;
    cout << "5.  Ocupaci�n promedio por sala" << endl;
    cout << "6.  Funciones con menor ocupaci�n" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::RecaudacionTotalPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "----------------- Recaudaci�n por -----------------" << endl;
    cout << "1.  Pel�cula" << endl;
    cout << "2.  D�a de la semana" << endl;
    cout << "3.  Mes" << endl;
    cout << "4.  A�o" << endl;
    cout << "5.  Sala" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::configuracion() {
    system("cls");
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
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Configurar salas -----------------" << endl;
    cout << "1.  Listar salas activas" << endl;
    cout << "2.  Agregar una sala" << endl;
    cout << "3.  Eliminar una sala" << endl;
    cout << "4.  Modificar una sala" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::configuracionMembresias() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------- Configurar membres�as --------------" << endl;
    cout << "1.  Listar tipos de membres�as activas" << endl;
    cout << "2.  Agregar un tipo de membres�a" << endl;
    cout << "3.  Eliminar un tipo de membres�a" << endl;
    cout << "4.  Modificar un tipo de membres�a" << endl;
    cout << "0.  Volver al men� principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opci�n elegida: ";
    recibirOpcion(4);
    system("cls");
}
