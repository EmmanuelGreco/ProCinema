#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
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

void menuVentas();
void menuPeliculas();
void menuFunciones();
void menuMembresia();
void menuInformes();
void menuConfiguracion();
void menuCreditos();
void menuPrincipal();

int main() {
    setlocale(LC_ALL, "Spanish");
    SetConsoleTitle("ProCinema - EQUIPO 13");           // Nombre de la consola
    system("color 0c");                            // Color consola y letras
    menuPrincipal();
    return 0;
}


void menuVentas() {
    Menu menu;
    ManagerVenta managerVenta;
    int opcionVentas, opcionBuscarVentas;

    while(true) {
        menu.ventas();
        opcionVentas = menu.getOpcion();

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
            menu.buscarVentasPor();
            opcionBuscarVentas = menu.getOpcion();

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
void menuPeliculas() {
    Menu menu;
    ManagerPelicula managerPelicula;
    int opcionPeliculas, opcionBuscarPeliculas, opcionListarPeliculas;
    while(true) {
        menu.peliculas();
        opcionPeliculas = menu.getOpcion();

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
            menu.listarPeliculasPor();
            opcionListarPeliculas = menu.getOpcion();

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
            menu.buscarPeliculasPor();
            opcionBuscarPeliculas = menu.getOpcion();

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
void menuFunciones() {
    Menu menu;
    ManagerFuncion managerFuncion;
    int opcionFunciones, opcionBuscarFunciones, opcionListarFunciones;

    while(true) {
        menu.funciones();
        opcionFunciones = menu.getOpcion();

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
            menu.listarFuncionPor();
            opcionListarFunciones = menu.getOpcion();

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
            menu.buscarFuncionPor();
            opcionBuscarFunciones = menu.getOpcion();

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
void menuMembresia() {
    Menu menu;
    ManagerMembresia managerMembresia;
    int opcionMembresias, opcionListarMembresias, opcionBuscarMembresias;

    while(true) {
        menu.membresias();
        opcionMembresias = menu.getOpcion();

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
            menu.listarMembresiasPor();
            opcionListarMembresias = menu.getOpcion();

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
            menu.buscarMembresiasPor();
            opcionBuscarMembresias = menu.getOpcion();

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

void menuInformes() {
    Menu menu;
    ManagerInformes managerInformes;
    int opcionInformes, opcionInformesRecaudacion;

    while(true) {
        menu.informes();
        opcionInformes = menu.getOpcion();

        switch(opcionInformes) {
        case 1:
            managerInformes.topCinco();
            system("pause");
            break;
        case 2:
            menu.recaudacionTotalPor();
            opcionInformesRecaudacion = menu.getOpcion();

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
void menuConfiguracion() {
    Menu menu;
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

        accesoPermitido = menu.verificarContrasena(contrasena);

        if (accesoPermitido) {
            break;
        } else {
            cout << "  Contraseña Incorrecta! Intente nuevamente!" << endl;
        }
    }

    if(accesoPermitido) {
        while(true) {
            menu.configuracion();
            opcionConfig = menu.getOpcion();

            int opcionSalas, opcionListarSalas;
            switch(opcionConfig) {
            case 1:
                while(true) {
                    menu.configuracionSalas();
                    opcionSalas = menu.getOpcion();

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
                        menu.listarSalasPor();
                        opcionListarSalas = menu.getOpcion();

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
                    menu.configuracionCSV();
                    opcionCSV = menu.getOpcion();

                    switch(opcionCSV) {
                    case 1:
                        menu.archivosCSVLeer();
                        opcionArchivosCSV = menu.getOpcion();

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
                        menu.archivosCSVCargar();
                        opcionArchivosCSV = menu.getOpcion();

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
void menuCreditos() {
    Menu menu;
    menu.creditosImprimir();
    system("pause");
}

void menuPrincipal() {
    Menu menu;
    menu.menuBienvendidaImprimir();
    system("pause");

    while(true) {
        menu.principal();
        switch(menu.getOpcion()) {
        case 1:
            menuVentas();
            break;
        case 2:
            menuPeliculas();
            break;
        case 3:
            menuFunciones();
            break;
        case 4:
            menuMembresia();
            break;
        case 5:
            menuInformes();
            break;
        case 6:
            menuConfiguracion();
            break;
        case 7:
            menuCreditos();
            break;
        case 0:
            system("cls");
            cout << "Gracias por usar ProCinema!" << endl << endl;
            break;
        }
        cout << endl;
        system("cls");
    }
}
