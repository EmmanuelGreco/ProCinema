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
        cout << "Ingrese una opción válida: ";
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
    cout << "2.  Películas..." << endl;
    cout << "3.  Funciones..." << endl;
    cout << "4.  Informes..." << endl;
    cout << "5.  Configuración..." << endl;
    cout << "0.  Salir del programa... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
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
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::BuscarVentasPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar ventas por ----------------" << endl;
    cout << "1.  ID de venta" << endl;
    cout << "2.  Función" << endl;
    cout << "3.  DNI" << endl;
    cout << "4.  Número de miembro" << endl;
    cout << "5.  Fecha de venta" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::peliculas() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Películas --------------------" << endl;
    cout << "1.  Agregar película" << endl;
    cout << "2.  Eliminar película" << endl;
    cout << "3.  Modificar una película" << endl;
    cout << "4.  Listar todas las películas en cartelera" << endl;
    cout << "5.  Buscar películas por..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::BuscarPeliculasPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Buscar películas por --------------" << endl;
    cout << "1.  ID de película" << endl;
    cout << "2.  Título" << endl;
    cout << "3.  Género" << endl;
    cout << "4.  Apellido del director" << endl;
    cout << "5.  Clasificación" << endl;
    cout << "6.  Fecha de estreno" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::funciones() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Funciones --------------------" << endl;
    cout << "1.  Agregar una función" << endl;
    cout << "2.  Eliminar una función" << endl;
    cout << "3.  Modificar una función" << endl;
    cout << "4.  Listar funciones..." << endl;
    cout << "5.  Buscar funciones por..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
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
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::BuscarFuncionPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar funcion por ---------------" << endl;
    cout << "1.  ID de funcion" << endl;
    cout << "2.  Título de película" << endl;
    cout << "3.  Número de sala" << endl;
    cout << "4.  Fecha" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::informes() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------------- Informes --------------------" << endl;
    cout << "1.  Top X películas del año" << endl;
    cout << "2.  Recaudación total..." << endl;
    cout << "3.  Porcentaje de compras de miembros" << endl;
    cout << "4.  Miembros más frecuentes" << endl;
    cout << "5.  Ocupación promedio por sala" << endl;
    cout << "6.  Funciones con menor ocupación" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::RecaudacionTotalPor() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "----------------- Recaudación por -----------------" << endl;
    cout << "1.  Película" << endl;
    cout << "2.  Día de la semana" << endl;
    cout << "3.  Mes" << endl;
    cout << "4.  Año" << endl;
    cout << "5.  Sala" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::configuracion() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Configuración ------------------" << endl;
    cout << "1.  Salas..." << endl;
    cout << "2.  Membresías..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
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
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::configuracionMembresias() {
    system("cls");
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------- Configurar membresías --------------" << endl;
    cout << "1.  Listar tipos de membresías activas" << endl;
    cout << "2.  Agregar un tipo de membresía" << endl;
    cout << "3.  Eliminar un tipo de membresía" << endl;
    cout << "4.  Modificar un tipo de membresía" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(4);
    system("cls");
}
