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

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    //setlocale(LC_ALL, "es_ES.UTF-8");
    setlocale(LC_ALL, "Spanish");
    SetConsoleTitle("ProCinema - EQUIPO 13");           // Nombre de la consola
    system("color 0c");                            // Color consola y letras

    ManagerVenta managerVenta;
    ManagerPelicula managerPelicula;
    ManagerFuncion managerFuncion;
    ManagerMembresia managerMembresia;
    ManagerInformes managerInformes;
    ManagerSala managerSala;
    ManagerArchivoCSV managerArchivoCSV;
    Menu menu;

    while(true) {
        menu.principal();

        switch(menu.getOpcion()) {
        ///1. VENTAS
        case 1: {
        int opcionVentas, opcionBuscarVentas;

            while(true) {
                menu.ventas();
                opcionVentas = menu.getOpcion();

                switch(opcionVentas) {
                case 1: managerVenta.cargarVenta(); system("pause");
                    break;
                case 2: managerVenta.cambiarEstadoVenta(); system("pause");
                    break;
                case 3: managerVenta.modificarVenta(); system("pause");
                    break;
                case 4: managerVenta.listarVentas(); system("pause");
                    break;
                case 5:
                    menu.buscarVentasPor();
                    opcionBuscarVentas = menu.getOpcion();

                    switch(opcionBuscarVentas) {
                    case 1: managerVenta.buscarPorId(); system("pause");
                        break;
                    case 2: managerVenta.buscarPorFuncion(); system("pause");
                        break;
                    case 3: managerVenta.buscarPorDNI(); system("pause");
                        break;
                    case 4: managerVenta.buscarPorMiembro(); system("pause");
                        break;
                    case 5: managerVenta.buscarPorFecha(); system("pause");
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
            break;
        }


        ///2. PELÍCULAS
        case 2: {
            int opcionPeliculas, opcionBuscarPeliculas, opcionListarPeliculas;
            while(true) {
                menu.peliculas();
                opcionPeliculas = menu.getOpcion();

                switch(opcionPeliculas) {
                case 1: managerPelicula.cargarPelicula(); system("pause");
                    break;
                case 2: managerPelicula.cambiarEstadoPelicula(); system("pause");
                    break;
                case 3: managerPelicula.modificarPelicula(); system("pause");
                    break;
                case 4:
                    menu.listarPeliculasPor();
                    opcionListarPeliculas = menu.getOpcion();

                    switch(opcionListarPeliculas) {
                    case 1: managerPelicula.listarPeliculas(); system("pause");
                        break;
                    case 2: {
                        bool activas = true;
                        managerPelicula.listarPeliculasActivas(activas); system("pause");
                        break;
                    }
                    case 3: {
                        bool activas = false;
                        managerPelicula.listarPeliculasActivas(activas); system("pause");
                        break;
                    }
                    case 0: // "VOLVER AL MENU PELÍCULAS"
                        break;
                    }
                    break;
                case 5:
                    menu.buscarPeliculasPor();
                    opcionBuscarPeliculas = menu.getOpcion();

                    switch(opcionListarPeliculas) {
                    case 1: managerPelicula.buscarPorId(); system("pause");
                        break;
                    case 2: managerPelicula.buscarPorTitulo(); system("pause");
                        break;
                    case 3: managerPelicula.buscarPorGenero(); system("pause");
                        break;
                    case 4: managerPelicula.buscarPorApellidoDirector(); system("pause");
                        break;
                    case 5: managerPelicula.buscarPorClasificacion(); system("pause");
                        break;
                    case 6: managerPelicula.buscarPorFechaEstreno(); system("pause");
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
            break;
        }


        ///3. FUNCIONES
        case 3: {
            int opcionFunciones, opcionBuscarFunciones, opcionListarFunciones;

            while(true) {
                menu.funciones();
                opcionFunciones = menu.getOpcion();

                switch(opcionFunciones) {
                case 1: managerFuncion.cargarFuncion(); system("pause");
                    break;
                case 2: managerFuncion.cambiarEstadoFuncion(); system("pause");
                    break;
                case 3: managerFuncion.modificarFuncion(); system("pause");
                    break;
                case 4:
                    menu.listarFuncionPor();
                    opcionListarFunciones = menu.getOpcion();

                    switch(opcionListarFunciones) {
                    case 1: managerFuncion.listarFunciones(); system("pause");
                        break;
                    case 2: {
                        bool activas = true;
                        managerFuncion.listarFuncionesActivas(activas); system("pause");
                        break;
                    }
                    case 3: managerFuncion.listarFuncionesAgotadas(); system("pause");
                        break;
                    case 4: {
                        bool activas = false;
                        managerFuncion.listarFuncionesActivas(activas); system("pause");
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
                    case 1: managerFuncion.buscarPorId(); system("pause");
                        break;
                    case 2: managerFuncion.buscarPorTituloPelicula(); system("pause");
                        break;
                    case 3: managerFuncion.buscarPorNumeroSala(); system("pause");
                        break;
                    case 4: managerFuncion.buscarPorFechaFuncion(); system("pause");
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
            break;
        }


        ///4. MEMBRESÍAS
        case 4: {
            int opcionMembresias, opcionListarMembresias, opcionBuscarMembresias;

            while(true) {
                menu.membresias();
                opcionMembresias = menu.getOpcion();

                switch(opcionMembresias) {
                case 1: managerMembresia.cargarMembresia(); system("pause");
                    break;
                case 2: managerMembresia.cambiarEstadoMembresia(); system("pause");
                    break;
                case 3: managerMembresia.modificarMembresia(); system("pause");
                    break;
                case 4:
                    menu.listarMembresiasPor();
                    opcionListarMembresias = menu.getOpcion();

                    switch(opcionListarMembresias) {
                    case 1: managerMembresia.listarMembresias(); system("pause");
                        break;
                    case 2: {
                        bool activas = true;
                        managerMembresia.listarMembresiasActivas(activas); system("pause");
                        break;
                    }
                    case 3: {
                        bool activas = false;
                        managerMembresia.listarMembresiasActivas(activas); system("pause");
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
                    case 1: managerMembresia.buscarPorId(); system("pause");
                        break;
                    case 2: managerMembresia.buscarPorDNI(); system("pause");
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
            break;
        }


        ///4. INFORMES
        case 5: {
            int opcionInformes, opcionInformesRecaudacion;

            while(true) {
                menu.informes();
                opcionInformes = menu.getOpcion();

                switch(opcionInformes) {
                case 1: managerInformes.topCinco(); system("pause");
                    break;
                case 2:
                    menu.recaudacionTotalPor();
                    opcionInformesRecaudacion = menu.getOpcion();

                    switch(opcionInformesRecaudacion) {
                    case 1: managerInformes.recaudacionPorPelicula(); system("pause");
                        break;
                    case 2: managerInformes.recaudacionAnual(); system("pause");
                        break;
                    case 3: managerInformes.recaudacionPorSala(); system("pause");
                        break;
                    case 0: // "VOLVER AL MENU INFORMES"
                        break;
                    }
                    break;
                case 3: managerInformes.porcentajeMiembros(); system("pause");
                    break;
                case 4: cout << "MIEMBROS MAS FRECUENTES" << endl;
                    break;
                case 5: managerInformes.ocupacionPromedioSala(); system("pause");
                    break;
                case 6: managerInformes.ocupacionMenorFunciones(); system("pause");
                    break;
                case 0: // "VOLVER AL MENU PRINCIPAL"
                    break;
                }
                if(opcionInformes == 0) break;
            }
            break;
        }


        ///5. CONFIGURACIÓN
        case 6: {
            int opcionConfig;

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
                        case 1: managerSala.cargarSala(); system("pause");
                            break;
                        case 2: managerSala.cambiarEstadoSala(); system("pause");
                            break;
                        case 3: managerSala.modificarSala(); system("pause");
                            break;
                        case 4:
                            menu.listarSalasPor();
                            opcionListarSalas = menu.getOpcion();

                            switch(opcionListarSalas) {
                            case 1: managerSala.listarSalas(); system("pause");
                                break;
                            case 2: {
                                bool activas = true;
                                managerSala.listarSalasActivas(activas); system("pause");
                                break;
                            }
                            case 3: {
                                bool activas = false;
                                managerSala.listarSalasActivas(activas); system("pause");
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
                            menu.archivosCSV();
                            opcionArchivosCSV = menu.getOpcion();

                            switch(opcionArchivosCSV) {
                            case 1: managerArchivoCSV.listarPeliculasCSV(); system("pause");
                                break;
                            case 2: managerArchivoCSV.listarSalasCSV(); system("pause");
                                break;
                            case 3: managerArchivoCSV.listarFuncionesCSV(); system("pause");
                                break;
                            case 4: managerArchivoCSV.listarMembresiasCSV(); system("pause");
                                break;
                            case 5: managerArchivoCSV.listarVentasCSV(); system("pause");
                                break;
                            case 0: // "VOLVER AL MENU ARCHIVOS CSV"
                                break;
                            }
                            break;
                        case 2:
                            menu.archivosCSV();
                            opcionArchivosCSV = menu.getOpcion();

                            switch(opcionArchivosCSV) {
                            case 1: managerArchivoCSV.cargarPeliculasCSV(); system("pause");
                                break;
                            case 2: managerArchivoCSV.cargarSalasCSV(); system("pause");
                                break;
                            case 3: managerArchivoCSV.cargarFuncionesCSV(); system("pause");
                                break;
                            case 4: managerArchivoCSV.cargarMembresiasCSV(); system("pause");
                                break;
                            case 5: managerArchivoCSV.cargarVentasCSV(); system("pause");
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
            break;
        }


        ///0. SALIR
        case 0:
            system("cls");
            cout << "Gracias por usar ProCinema!" << endl << endl;
            return 0;
            break;
        }

        cout << endl;
        //system("pause");
        system("cls");

    }
    return 0;
}




///COUTS DE EJEMPLO PARA EL INFORME, SE PUEDEN BORRAR DSPS SI NO LOS VOLVEMOS A USAR

//    ///MENU PRINCIPAL
//    cout << "-------- ProCinema Manager --------" << endl;
//    cout << "---------- Menu principal ---------" << endl;
//    cout << "1.  Registrar..." << endl;
//    cout << "2.  Listar..." << endl;
//    cout << "3.  Informes..." << endl;
//    cout << "4.  Configuracion..." << endl;
//    cout << "0.  Salir del programa... " << endl;
//    cout << "-----------------------------------" << endl;
//    cout << endl << endl << endl;
//
//    ///MENU REGISTRAR
//    cout << "-------- ProCinema Manager --------" << endl;
//    cout << "----------- Registrar... ----------" << endl;
//    cout << "1.  Ventas" << endl;
//    cout << "2.  Peliculas" << endl;
//    cout << "3.  Funciones" << endl;
//    cout << "4.  Membresias" << endl;
//    cout << "0.  Volver al menu..." << endl;
//    cout << "-----------------------------------" << endl;
//    cout << endl << endl << endl;
//
//    ///MENU LISTAR
//    cout << "-------- ProCinema Manager --------" << endl;
//    cout << "------------ Listar... ------------" << endl;
//    cout << "1x  Ventas" << endl;
//    cout << " 1.   Ordenar por fecha" << endl;
//    cout << " 2.   Ordenar por monto" << endl;
//    cout << " 3.   Ordenar por pelicula" << endl;
//    cout << "2x  Peliculas" << endl;
//    cout << "3x  Directores" << endl;
//    cout << "4x  Funciones" << endl;
//    cout << "0.  Volver al menu..." << endl;
//    cout << "-----------------------------------" << endl;
//    cout << endl << endl << endl;

//    cout << "-------------------- ProCinema Manager --------------------" << endl;
//    cout << "Funciones entre el 01/05/25 y el 31/05/25:                 " << endl;
//    cout << "-----------------------------------------------------------" << endl;
//    cout << "  Título |    Día y fecha  |   Hora  |  Sala  |   Idioma   " << endl;
//    cout << "-----------------------------------------------------------" << endl;
//    cout << "Cars 4   | Martes 06/05    | 14:30hs | Sala 1 | Inglés     " << endl;
//    cout << "Avatar 3 | Miércoles 07/05 | 16:15hs | Sala 2 | Castellano " << endl;
//    cout << "Cars 4   | Jueves 08/05    | 14:30hs | Sala 1 | Castellano " << endl;
//    cout << "Cars 4   | Martes 13/05    | 14:30hs | Sala 1 | Inglés     " << endl;
//    cout << "Avatar 3 | Miércoles 14/05 | 16:15hs | Sala 2 | Castellano " << endl;
//    cout << "Cars 4   | Jueves 15/05    | 14:30hs | Sala 1 | Castellano " << endl;
//    cout << "Cars 4   | Martes 20/05    | 14:30hs | Sala 1 | Inglés     " << endl;
//    cout << "Avatar 3 | Miércoles 21/05 | 16:15hs | Sala 2 | Castellano " << endl;
//    cout << "Cars 4   | Jueves 22/05    | 14:30hs | Sala 1 | Castellano " << endl;
//    cout << "Cars 4   | Martes 27/05    | 14:30hs | Sala 1 | Inglés     " << endl;
//    cout << "Avatar 3 | Miércoles 28/05 | 16:15hs | Sala 2 | Castellano " << endl;
//    cout << "Cars 4   | Jueves 29/05    | 14:30hs | Sala 1 | Castellano " << endl;
//
//    cout << endl << endl << endl;
//
//    cout << "------------------------- ProCinema Manager -------------------------" << endl;
//    cout << "Consulta de ventas por DNI: 45013895                                 " << endl;
//    cout << "---------------------------------------------------------------------" << endl;
//    cout << "   DNI   |   Fecha  |   Hora  |          Título         |   Idioma   " << endl;
//    cout << "---------------------------------------------------------------------" << endl;
//    cout << "45013895 | 11/05/25 | 14:11hs | Cars 4                  | Inglés     " << endl;
//    cout << "45013895 | 12/04/25 | 11:26hs | Avatar 3                | Castellano " << endl;
//    cout << "45013895 | 29/03/25 | 18:54hs | Volver al Futuro        | Castellano " << endl;
//    cout << "45013895 | 01/03/25 | 21:24hs | Her                     | Inglés     " << endl;
//    cout << "45013895 | 15/01/25 | 02:26hs | 300                     | Castellano " << endl;
//    cout << "45013895 | 25/12/24 | 13:59hs | Barbie                  | Castellano " << endl;
//    cout << "45013895 | 26/09/24 | 16:05hs | Oppenheimer             | Inglés     " << endl;
//    cout << "45013895 | 12/04/24 | 08:06hs | Kung Fu Panda           | Castellano " << endl;
//    cout << "45013895 | 12/01/24 | 14:58hs | Parasite                | Inglés     " << endl;
//    cout << "45013895 | 14/08/23 | 17:46hs | La Sociedad de la Nieve | Castellano " << endl;
//    cout << "45013895 | 31/07/23 | 23:37hs | Mamma Mia               | Castellano " << endl;
//    cout << "45013895 | 15/04/23 | 09:42hs | Batman 2                | Castellano " << endl;
//
//    cout << endl << endl << endl;
//
//    cout << "------------------- ProCinema Manager -------------------" << endl;
//    cout << "Informe de ventas por película - Año: 2025               " << endl;
//    cout << "---------------------------------------------------------" << endl;
//    cout << "     Título      | Recaudación |  Estreno |    Estado    " << endl;
//    cout << "---------------------------------------------------------" << endl;
//    cout << "Cars 4           | $ 3.235.392 | 01/05/25 | En Cartelera " << endl;
//    cout << "Avatar 3         | $ 2.242.263 | 10/04/25 | En Cartelera " << endl;
//    cout << "Volver al Futuro | $ 2.126.278 | 15/03/25 | -            " << endl;
//    cout << "Her              | $ 1.565.217 | 15/02/25 | -            " << endl;
//    cout << "300              | $ 3.295.795 | 20/01/25 | -            " << endl;
//    cout << "Barbie           | $ 4.201.215 | 01/01/25 | -            " << endl;
