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
        cout << "Ingrese una opción válida: ";
        cin >> input;
    }
    setOpcion(input);
}

bool Menu::opcionValida(int input, int maximo) {//no le asigné un minimo xq asumo que simepre va a ser 0, para volver atras o salir.
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
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------------- Ventas ---------------------" << endl;
    cout << "1.  Registrar Venta" << endl;
    cout << "2.  Dar de baja una Venta" << endl;
    cout << "3.  Modificar una Venta" << endl;
    cout << "4.  Listar todas las Ventas registradas" << endl;
    cout << "5.  Buscar Ventas por..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::BuscarVentasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar Ventas por ----------------" << endl;
    cout << "1.  ID de Venta" << endl;
    cout << "2.  Función" << endl;
    cout << "3.  DNI" << endl;
    cout << "4.  Número de Miembro" << endl;
    cout << "5.  Fecha de Venta" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::peliculas() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Películas --------------------" << endl;
    cout << "1.  Agregar Película" << endl;
    cout << "2.  Dar de baja / Restaurar Película" << endl;
    cout << "3.  Modificar una Película" << endl;
    cout << "4.  Listar Películas por..." << endl;
    cout << "5.  Buscar Películas por..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::listarPeliculasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Listar Películas por ---------------" << endl;
    cout << "1.  Todas las Películas" << endl;
    cout << "2.  Películas CARTELERA" << endl;
    cout << "3.  Películas FUERA DE CARTELERA" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::BuscarPeliculasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Buscar Películas por --------------" << endl;
    cout << "1.  ID de Película" << endl;
    cout << "2.  Título" << endl;
    cout << "3.  Género" << endl;
    cout << "4.  Apellido del Director" << endl;
    cout << "5.  Clasificación" << endl;
    cout << "6.  Fecha de Estreno" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::funciones() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------------- Funciones --------------------" << endl;
    cout << "1.  Agregar una Función" << endl;
    cout << "2.  Dar de baja / Restaurar una Función" << endl;
    cout << "3.  Modificar una Función" << endl;
    cout << "4.  Listar Funciones por..." << endl;
    cout << "5.  Buscar Funciones por..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::ListarFuncionPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Listar Función -----------------" << endl;
    cout << "1.  Todas las Funciones" << endl;
    cout << "2.  Funciones en CARTELERA" << endl;
    cout << "3.  Funciones AGOTADAS" << endl;
    cout << "4.  Funciones FUERA DE CARTELERA" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::BuscarFuncionPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Buscar Función por ---------------" << endl;
    cout << "1.  ID de la Función" << endl;
    cout << "2.  Título de Película" << endl;
    cout << "3.  Número de Sala" << endl;
    cout << "4.  Fecha de la Función" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::informes() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------------- Informes --------------------" << endl;
    cout << "1.  Top X Películas del Año" << endl;
    cout << "2.  Recaudación Total..." << endl;
    cout << "3.  Porcentaje de Compras de Miembros" << endl;
    cout << "4.  Miembros más Frecuentes" << endl;
    cout << "5.  Ocupación Promedio por Sala" << endl;
    cout << "6.  Funciones con Menor Ocupación" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(6);
    system("cls");
}

void Menu::RecaudacionTotalPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "----------------- Recaudación por -----------------" << endl;
    cout << "1.  Película" << endl;
    cout << "2.  Año" << endl;
    cout << "3.  Sala" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracion() {
    system("cls");
    cout << endl;
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
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracionMembresias() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------- Configurar Membresías --------------" << endl;
    string queMenuEs = "Membresía";
    configuracionOpciones(queMenuEs);
    recibirOpcion(4);
    system("cls");
}

void Menu::listarMembresiasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Listar Membresías por --------------" << endl;
    cout << "1.  Todas las Membresías" << endl;
    cout << "2.  Membresías ACTIVAS" << endl;
    cout << "3.  Membresías PAUSADAS" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracionOpciones(string queMenuEs) {
    cout << "1.  Listar " << queMenuEs << "s por..." << endl;
    cout << "2.  Agregar una " << queMenuEs << endl;
    cout << "3.  Dar de baja / Restaurar una " << queMenuEs << endl;
    cout << "4.  Modificar una " << queMenuEs << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la opción elegida: ";
}
