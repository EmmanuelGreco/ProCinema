#include <iostream>
#include <string>
#include <windows.h>
#include "Menu.h"
#include "ManagerVenta.h"
#include "ManagerPelicula.h"
#include "ManagerFuncion.h"
#include "ManagerMembresia.h"
#include "ManagerInformes.h"
#include "ManagerSala.h"
#include "ManagerArchivoCSV.h"

#define color SetConsoleTextAttribute

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
        cout << "Error! Ingrese una Opción válida: ";
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

//void Menu::menuPrincipal() {
//    menuBienvendidaImprimir();
//    system("pause");
//
//    while(true) {
//        principal();
//        switch(getOpcion()) {
//        case 1:
//            menuVentas();
//            break;
//        case 2:
//            menuPeliculas();
//            break;
//        case 3:
//            menuFunciones();
//            break;
//        case 4:
//            menuMembresia();
//            break;
//        case 5:
//            menuInformes();
//            break;
//        case 6:
//            menuConfiguracion();
//            break;
//        case 7:
//            menuCreditos();
//            break;
//        case 0:
//            system("cls");
//            cout << "Gracias por usar ProCinema!" << endl << endl;
//            return;
//            break;
//        }
//        cout << endl;
//        system("cls");
//    }
//}

void Menu::menuVentas() {
    ManagerVenta managerVenta;
    int opcionVentas, opcionBuscarVentas;

    while(true) {
        ventas();
        opcionVentas = getOpcion();

        switch(opcionVentas) {
        case 1:
            managerVenta.cargarVenta();
            system("pause");
            break;
        case 2:
            managerVenta.cambiarEstadoVenta();
            system("pause");
            break;
        case 3:
            managerVenta.modificarVenta();
            system("pause");
            break;
        case 4:
            managerVenta.listarVentas();
            system("pause");
            break;
        case 5:
            buscarVentasPor();
            opcionBuscarVentas = getOpcion();

            switch(opcionBuscarVentas) {
            case 1:
                managerVenta.buscarPorId();
                system("pause");
                break;
            case 2:
                managerVenta.buscarPorFuncion();
                system("pause");
                break;
            case 3:
                managerVenta.buscarPorDNI();
                system("pause");
                break;
            case 4:
                managerVenta.buscarPorMiembro();
                system("pause");
                break;
            case 5:
                managerVenta.buscarPorFecha();
                system("pause");
                break;
            case 0: // "VOLVER AL MENU VENTAS"
                break;
            }
            break;
        case 0: // "VOLVER AL MENU PRINCIPAL"
            break;
        }
        if(opcionVentas == 0) break;
    }
}
void Menu::menuPeliculas() {
    ManagerPelicula managerPelicula;
    int opcionPeliculas, opcionBuscarPeliculas, opcionListarPeliculas;
    while(true) {
        peliculas();
        opcionPeliculas = getOpcion();

        switch(opcionPeliculas) {
        case 1:
            managerPelicula.cargarPelicula();
            system("pause");
            break;
        case 2:
            managerPelicula.cambiarEstadoPelicula();
            system("pause");
            break;
        case 3:
            managerPelicula.modificarPelicula();
            system("pause");
            break;
        case 4:
            listarPeliculasPor();
            opcionListarPeliculas = getOpcion();

            switch(opcionListarPeliculas) {
            case 1:
                managerPelicula.listarPeliculas();
                system("pause");
                break;
            case 2: {
                bool activas = true;
                managerPelicula.listarPeliculas(activas);
                system("pause");
                break;
            }
            case 3: {
                bool activas = false;
                managerPelicula.listarPeliculas(activas);
                system("pause");
                break;
            }
            case 0: // "VOLVER AL MENU PELÍCULAS"
                break;
            }
            break;
        case 5:
            buscarPeliculasPor();
            opcionBuscarPeliculas = getOpcion();

            switch(opcionBuscarPeliculas) {
            case 1:
                managerPelicula.buscarPorId();
                system("pause");
                break;
            case 2:
                managerPelicula.buscarPorTitulo();
                system("pause");
                break;
            case 3:
                managerPelicula.buscarPorGenero();
                system("pause");
                break;
            case 4:
                managerPelicula.buscarPorApellidoDirector();
                system("pause");
                break;
            case 5:
                managerPelicula.buscarPorClasificacion();
                system("pause");
                break;
            case 6:
                managerPelicula.buscarPorFechaEstreno();
                system("pause");
                break;
            case 0: // "VOLVER AL MENU PELÍCULAS"
                break;
            }
            break;
        case 0: // "VOLVER AL MENU PRINCIPAL"
            break;
        }
        if(opcionPeliculas == 0) break;
    }
}
void Menu::menuFunciones() {
    ManagerFuncion managerFuncion;
    int opcionFunciones, opcionBuscarFunciones, opcionListarFunciones;

    while(true) {
        funciones();
        opcionFunciones = getOpcion();

        switch(opcionFunciones) {
        case 1:
            managerFuncion.cargarFuncion();
            system("pause");
            break;
        case 2:
            managerFuncion.cambiarEstadoFuncion();
            system("pause");
            break;
        case 3:
            managerFuncion.modificarFuncion();
            system("pause");
            break;
        case 4:
            listarFuncionPor();
            opcionListarFunciones = getOpcion();

            switch(opcionListarFunciones) {
            case 1:
                managerFuncion.listarFunciones();
                system("pause");
                break;
            case 2: {
                bool activas = true;
                managerFuncion.listarFunciones(activas);
                system("pause");
                break;
            }
            case 3:
                managerFuncion.listarFuncionesAgotadas();
                system("pause");
                break;
            case 4: {
                bool activas = false;
                managerFuncion.listarFunciones(activas);
                system("pause");
                break;
            }
            case 0: // "VOLVER AL MENU FUNCIONES"
                break;
            }
            break;
        case 5:
            buscarFuncionPor();
            opcionBuscarFunciones = getOpcion();

            switch(opcionBuscarFunciones) {
            case 1:
                managerFuncion.buscarPorId();
                system("pause");
                break;
            case 2:
                managerFuncion.buscarPorTituloPelicula();
                system("pause");
                break;
            case 3:
                managerFuncion.buscarPorNumeroSala();
                system("pause");
                break;
            case 4:
                managerFuncion.buscarPorFechaFuncion();
                system("pause");
                break;
            case 0: // "VOLVER AL MENU FUNCIONES"
                break;
            }
            break;
        case 0: // "VOLVER AL MENU PRINCIPAL"
            break;
        }
        if(opcionFunciones == 0) break;
    }
}
void Menu::menuMembresia() {
    ManagerMembresia managerMembresia;
    int opcionMembresias, opcionListarMembresias, opcionBuscarMembresias;

    while(true) {
        membresias();
        opcionMembresias = getOpcion();

        switch(opcionMembresias) {
        case 1:
            managerMembresia.cargarMembresia();
            system("pause");
            break;
        case 2:
            managerMembresia.cambiarEstadoMembresia();
            system("pause");
            break;
        case 3:
            managerMembresia.modificarMembresia();
            system("pause");
            break;
        case 4:
            listarMembresiasPor();
            opcionListarMembresias = getOpcion();

            switch(opcionListarMembresias) {
            case 1:
                managerMembresia.listarMembresias();
                system("pause");
                break;
            case 2: {
                bool activas = true;
                managerMembresia.listarMembresias(activas);
                system("pause");
                break;
            }
            case 3: {
                bool activas = false;
                managerMembresia.listarMembresias(activas);
                system("pause");
                break;
            }
            case 0: // "VOLVER AL MENU MEMBRESÍAS"
                break;
            }
            break;
        case 5:
            buscarMembresiasPor();
            opcionBuscarMembresias = getOpcion();

            switch(opcionBuscarMembresias) {
            case 1:
                managerMembresia.buscarPorId();
                system("pause");
                break;
            case 2:
                managerMembresia.buscarPorDNI();
                system("pause");
                break;
            case 0: // "VOLVER AL MENU MEMBRESÍAS"
                break;
            }
            break;
        case 0: // "VOLVER AL MENU PRINCIPAL"
            break;
        }
        if(opcionMembresias == 0) break;
    }
}
void Menu::menuInformes() {
    ManagerInformes managerInformes;
    int opcionInformes, opcionInformesRecaudacion;

    while(true) {
        informes();
        opcionInformes = getOpcion();

        switch(opcionInformes) {
        case 1:
            managerInformes.topCinco();
            system("pause");
            break;
        case 2:
            recaudacionTotalPor();
            opcionInformesRecaudacion = getOpcion();

            switch(opcionInformesRecaudacion) {
            case 1:
                managerInformes.recaudacionPorPelicula();
                system("pause");
                break;
            case 2:
                managerInformes.recaudacionAnual();
                system("pause");
                break;
            case 3:
                managerInformes.recaudacionPorSala();
                system("pause");
                break;
            case 0: // "VOLVER AL MENU INFORMES"
                break;
            }
            break;
        case 3:
            managerInformes.porcentajeMembresias();
            system("pause");
            break;
        case 4:
            managerInformes.ocupacionPromedioSala();
            system("pause");
            break;
        case 5:
            managerInformes.ocupacionMenorFunciones();
            system("pause");
            break;
        case 0: // "VOLVER AL MENU PRINCIPAL"
            break;
        }
        if(opcionInformes == 0) break;
    }
}
void Menu::menuConfiguracion() {
    ManagerSala managerSala;
    ManagerArchivoCSV managerArchivoCSV;
    int opcionConfig;
    string contrasena;
    bool accesoPermitido = false;

    // Validacion para acceder a Menu Configuracion
    while(contrasena != "0") {
        cout << endl;
        cout << "  Por favor, ingrese la contraseña para acceder al menú de configuración (Ingrese 0 para cancelar): ";
        cin >> contrasena;

        accesoPermitido = verificarContrasena(contrasena);

        if (accesoPermitido) {
            break;
        } else {
            cout << "  Contraseña Incorrecta! Intente nuevamente!" << endl;
        }
    }

    if(accesoPermitido) {
        while(true) {
            configuracion();
            opcionConfig = getOpcion();

            int opcionSalas, opcionListarSalas;
            switch(opcionConfig) {
            case 1:
                while(true) {
                    configuracionSalas();
                    opcionSalas = getOpcion();

                    switch(opcionSalas) {
                    case 1:
                        managerSala.cargarSala();
                        system("pause");
                        break;
                    case 2:
                        managerSala.cambiarEstadoSala();
                        system("pause");
                        break;
                    case 3:
                        managerSala.modificarSala();
                        system("pause");
                        break;
                    case 4:
                        listarSalasPor();
                        opcionListarSalas = getOpcion();

                        switch(opcionListarSalas) {
                        case 1:
                            managerSala.listarSalas();
                            system("pause");
                            break;
                        case 2: {
                            bool activas = true;
                            managerSala.listarSalas(activas);
                            system("pause");
                            break;
                        }
                        case 3: {
                            bool activas = false;
                            managerSala.listarSalas(activas);
                            system("pause");
                            break;
                        }
                        case 0: // "VOLVER AL MENU SALAS"
                            break;
                        }
                        break;
                    case 0: // "VOLVER AL MENU CONFIGURACIÓN"
                        break;
                    }
                    if(opcionSalas == 0) break;
                }
                break;

                int opcionCSV, opcionArchivosCSV;
            case 2:
                while(true) {
                    configuracionCSV();
                    opcionCSV = getOpcion();

                    switch(opcionCSV) {
                    case 1:
                        archivosCSVLeer();
                        opcionArchivosCSV = getOpcion();

                        switch(opcionArchivosCSV) {
                        case 1:
                            managerArchivoCSV.leerPeliculasCSV();
                            system("pause");
                            break;
                        case 2:
                            managerArchivoCSV.leerSalasCSV();
                            system("pause");
                            break;
                        case 3:
                            managerArchivoCSV.leerFuncionesCSV();
                            system("pause");
                            break;
                        case 4:
                            managerArchivoCSV.leerMembresiasCSV();
                            system("pause");
                            break;
                        case 5:
                            managerArchivoCSV.leerVentasCSV();
                            system("pause");
                            break;
                        case 0: // "VOLVER AL MENU ARCHIVOS CSV"
                            break;
                        }
                        break;
                    case 2:
                        archivosCSVCargar();
                        opcionArchivosCSV = getOpcion();

                        switch(opcionArchivosCSV) {
                        case 1:
                            managerArchivoCSV.cargarPeliculasCSV();
                            system("pause");
                            break;
                        case 2:
                            managerArchivoCSV.cargarSalasCSV();
                            system("pause");
                            break;
                        case 3:
                            managerArchivoCSV.cargarFuncionesCSV();
                            system("pause");
                            break;
                        case 4:
                            managerArchivoCSV.cargarMembresiasCSV();
                            system("pause");
                            break;
                        case 5:
                            managerArchivoCSV.cargarVentasCSV();
                            system("pause");
                            break;
                        case 0: // "VOLVER AL MENU ARCHIVOS CSV"
                            break;
                        }
                        break;
                    case 0: // "VOLVER AL MENU CONFIGURACIÓN"
                        break;
                    }
                    if(opcionCSV == 0) break;
                }
                break;
            case 0: // "VOLVER AL MENU PRINCIPAL"
                break;
            }
            if(opcionConfig == 0) break;
        }
    }
}
void Menu::menuCreditos() {
    creditosImprimir();
    system("pause");
}



void Menu::menuBienvendidaImprimir() {
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    cout << endl;
    cout << "                                       By LOS VECTORES®                          " << endl;
    cout << endl;
    cout << "                                   Bienvenido a...........                       " << endl;
    cout << endl;
    color(hConsole, 14);
    cout << "          ==============================================================          " << endl;
    cout << "  $$$$$$$                     $$$$$$  $$                                          " << endl;
    cout << "  $$  __$$                   $$  __$$  __                                         " << endl;
    cout << "  $$ |  $$  $$$$$$   $$$$$$  $$     __$$ $$$$$$$   $$$$$$  $$$$$$ $$$$   $$$$$$   " << endl;
    cout << "  $$$$$$$  $$  __$$ $$  __$$ $$ |     $$ $$  __$$ $$  __$$ $$  _$$  _$$   ____$$  " << endl;
    cout << "  $$  ____ $$ |   _|$$    $$ $$ |     $$ $$ |  $$ $$$$$$$$|$$   $$   $$  $$$$$$$ |" << endl;
    cout << "  $$ |     $$ |     $$ |  $$ $$ |  $$ $$ $$ |  $$ $$   ___|$$ | $$ | $$ $$  __$$ |" << endl;
    cout << "  $$ |     $$ |      $$$$$$   $$$$$$  $$ $$ |  $$  $$$$$$$ $$ | $$ | $$  $$$$$$$ |" << endl;
    cout << "   __|      __|       ______   ______  __ __|   __  ______| __|  __|  __  _______ " << endl;
    cout << "          ==============================================================          " << endl;
    color(hConsole, 12);
    cout << endl;
    cout << endl;
    cout << "  UTN|FRGP" << endl;
    cout << endl;
    cout << "  PROGRAMACION II - TUP - 2025 - 1C" << endl;
    cout << "  NOCHE - VIRTUAL - COMISION 102" << endl;
    cout << endl << endl;
    cout << "                             ~ INGRESAR ~                            " << endl;
    cout << endl << endl;

}

void Menu::principal() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Menu Principal -----------------" << endl;
    cout << "1.  Ventas..." << endl;
    cout << "2.  Películas..." << endl;
    cout << "3.  Funciones..." << endl;
    cout << "4.  Membresías..." << endl;
    cout << "5.  Informes..." << endl;
    cout << "6.  Configuración..." << endl;
    cout << "7.  Créditos..." << endl;
    cout << "0.  Salir del programa... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(7);
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::buscarVentasPor() {
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
    cout << "Ingrese la Opción elegida: ";
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
    cout << "Ingrese la Opción elegida: ";
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::buscarPeliculasPor() {
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
    cout << "Ingrese la Opción elegida: ";
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::listarFuncionPor() {
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::buscarFuncionPor() {
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(4);
    system("cls");
}

void Menu::membresias() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------- Configurar Membresías --------------" << endl;
    cout << "1.  Agregar una Membresía" << endl;
    cout << "2.  Pausar / Renovar una Membresía" << endl;
    cout << "3.  Modificar una Membresía" << endl;
    cout << "4.  Listar Membresías por..." << endl;
    cout << "5.  Buscar Membresías por..." << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(5);
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::buscarMembresiasPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "-------------- Buscar Membresías por --------------" << endl;
    cout << "1.  ID de la Membresía" << endl;
    cout << "2.  DNI del Miembro" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(2);
    system("cls");
}

void Menu::informes() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------------- Informes --------------------" << endl;
    //cout << "1.  Top 5 Películas del Año" << endl;
    cout << "1.  Top 5 Películas Históricas" << endl;
    cout << "2.  Recaudación Total por..." << endl;
    cout << "3.  Porcentaje de Compras de Tipos de Membresías" << endl;
    cout << "4.  Ocupación Promedio por Sala" << endl;
    cout << "5.  Funciones con Ocupación Menor al 50%" << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(5);
    system("cls");
}

void Menu::recaudacionTotalPor() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "----------------- Recaudación por -----------------" << endl;
    cout << "1.  Película" << endl;
    cout << "2.  Año" << endl;
    cout << "3.  Sala" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracion() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Configuración ------------------" << endl;
    cout << "1.  Salas..." << endl;
    cout << "2.  Archivos CSV..." << endl;
    cout << "0.  Volver al menú principal... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(2);
    system("cls");
}

void Menu::configuracionSalas() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Configurar Salas -----------------" << endl;
    cout << "1.  Agregar una Sala" << endl;
    cout << "2.  Dar de baja / Restaurar una Sala" << endl;
    cout << "3.  Modificar una Sala" << endl;
    cout << "4.  Listar Salas por..." << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
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
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(3);
    system("cls");
}

void Menu::configuracionCSV() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "------------------ Archivos CSV -------------------" << endl;
    cout << "1.  Leer CSV..." << endl;
    cout << "2.  Cargar CSV..." << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
    recibirOpcion(2);
    system("cls");
}

void Menu::archivosCSVLeer() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "---------------- Archivos CSV Leer -----------------" << endl;
    imprimirOpcionesCSV();
    recibirOpcion(5);
    system("cls");
}

void Menu::archivosCSVCargar() {
    system("cls");
    cout << endl;
    cout << "---------------- ProCinema Manager ----------------" << endl;
    cout << "--------------- Archivos CSV Cargar ----------------" << endl;
    imprimirOpcionesCSV();
    recibirOpcion(5);
    system("cls");
}

void Menu::imprimirOpcionesCSV() {
    cout << "1.  Películas" << endl;
    cout << "2.  Salas" << endl;
    cout << "3.  Funciones" << endl;
    cout << "4.  Membresías" << endl;
    cout << "5.  Ventas" << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
}

void Menu::creditosImprimir() {
    system("cls");
    cout << endl;
    cout << "                           By LOS VECTORES®                          " << endl;
    cout << endl;
    cout << "          =================================================          " << endl;
    cout << "                              EQUIPO 13                              " << endl;
    cout << "          =================================================          " << endl;
    cout << endl;
    cout << "  Legajo   | Apellido, Nombres" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << "  31714    | Greco, Emmanuel Antonio" << endl;
    cout << "  31768    | Taquino, Pedro" << endl;
    cout << "—————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;
}

bool Menu::verificarContrasena(const string &contrasenaIngresada) {
    const string contrasenaCorrecta = "admin1234";
    return contrasenaIngresada == contrasenaCorrecta;
}

/*void Menu::configuracionOpciones(string queMenuEs) {
    cout << "1.  Agregar una " << queMenuEs << endl;
    cout << "2.  Dar de baja / Restaurar una " << queMenuEs << endl;
    cout << "3.  Modificar una " << queMenuEs << endl;
    cout << "4.  Listar " << queMenuEs << "s por..." << endl;
    cout << "0.  Volver atrás... " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese la Opción elegida: ";
}*/
