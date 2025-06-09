#include <iostream>
#include <locale.h>

using namespace std;

#include "Menu.h"
#include "Fecha.h"
#include "Pelicula.h"
#include "Archivos.h"
#include "Manager.h"

int main() {
    setlocale(LC_ALL, "Spanish");
    Manager manager;
    Menu menu;

    while(true) {
        menu.principal();
        switch(menu.getOpcion()) {
        ///1. VENTAS
        case 1:
            menu.ventas();
            switch(menu.getOpcion()) {
            case 1:
                cout << "REGISTRAR VENTA" << endl;
                break;
            case 2:
                cout << "LISTAR VENTAS" << endl;
                break;
            case 3:
                menu.BuscarVentasPor();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "ID DE VENTA" << endl;
                    break;
                case 2:
                    cout << "FUNCION" << endl;
                    break;
                case 3:
                    cout << "DNI" << endl;
                    break;
                case 4:
                    cout << "ID DE MIEMBRO" << endl;
                    break;
                case 5:
                    cout << "FECHA DE VENTA" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 4:
                cout << "CANCELAR VENTA" << endl;
                break;
            case 0:
                cout << "VOLVER AL MENU PRINCIPAL" << endl;
                break;
            }
            break;


        ///2. PELICULAS
        case 2:
            menu.peliculas();
            switch(menu.getOpcion()) {
            case 1:
                manager.cargarPelicula();
                break;
            case 2:
                cout << "ELIMINAR PELICULA" << endl;
                break;
            case 3:
                manager.modificarPelicula();
                break;
            case 4:
                manager.listarPeliculas();
                break;
            case 5:
                menu.BuscarPeliculasPor();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "ID DE PELICULAS" << endl;
                    break;
                case 2:
                    cout << "TITULO" << endl;
                    break;
                case 3:
                    cout << "GENERO" << endl;
                    break;
                case 4:
                    cout << "APELLIDO DEL DIRECTOR" << endl;
                    break;
                case 5:
                    cout << "CLASIFICACIÓN" << endl;
                    break;
                case 6:
                    cout << "FECHA DE ESTRENO" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 0:
                cout << "VOLVER AL MENU PRINCIPAL" << endl;
                break;
            }
            break;


        ///3. FUNCIONES
        case 3:
            menu.funciones();
            switch(menu.getOpcion()) {
            case 1:
                cout << "AGREGAR FUNCION" << endl;
                break;
            case 2:
                cout << "ELIMINAR FUNCION" << endl;
                break;
            case 3:
                cout << "MODIFICAR FUNCION" << endl;
                break;
            case 4:
                menu.ListarFuncionPor();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "TODAS LAS FUNCIONES" << endl;
                    break;
                case 2:
                    cout << "FUNCIONES A LA VENTA" << endl;
                    break;
                case 3:
                    cout << "FUNCIONES AGOTADAS" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 5:
                menu.BuscarFuncionPor();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "ID DE FUNCION" << endl;
                    break;
                case 2:
                    cout << "TITULO DE PELICULA" << endl;
                    break;
                case 3:
                    cout << "NUMERO DE SALA" << endl;
                    break;
                case 4:
                    cout << "FECHA" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 0:
                cout << "VOLVER AL MENU PRINCIPAL" << endl;
                break;
            }
            break;


        ///4. INFORMES
        case 4:
            menu.informes();
            switch(menu.getOpcion()) {
            case 1:
                cout << "TOP X PELICULAS" << endl;
                break;
            case 2:
                menu.RecaudacionTotalPor();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "PELICULA" << endl;
                    break;
                case 2:
                    cout << "DIA DE LA SEMANA" << endl;
                    break;
                case 3:
                    cout << "MES" << endl;
                    break;
                case 4:
                    cout << "AÑO" << endl;
                    break;
                case 5:
                    cout << "SALA" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 3:
                cout << "PORCENTAJE" << endl;
                break;
            case 4:
                cout << "MIEMBROS MAS FRECUENTES" << endl;
                break;
            case 5:
                cout << "OCUPACION PROMEDIO" << endl;
                break;
            case 6:
                cout << "FUNCIONES CON MENOR OCUPACION" << endl;
                break;
            case 0:
                cout << "VOLVER AL MENU PRINCIPAL" << endl;
                break;
            }
            break;


        ///5. CONFIG
        case 5:
            menu.configuracion();
            switch(menu.getOpcion()) {
            case 1:
                menu.configuracionSalas();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "LISTAR SALAS" << endl;
                    break;
                case 2:
                    cout << "AGREGAR SALA" << endl;
                    break;
                case 3:
                    cout << "ELIMINAR SALA" << endl;
                    break;
                case 4:
                    cout << "MODIFICAR SALA" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 2:
                menu.configuracionMembresias();
                switch(menu.getOpcion()) {
                case 1:
                    cout << "LISTAR MEMBRESIA" << endl;
                    break;
                case 2:
                    cout << "AGREGAR MEMBRESÍA" << endl;
                    break;
                case 3:
                    cout << "ELIMINAR MEMBRESÍA" << endl;
                    break;
                case 4:
                    cout << "MODIFICAR MEMBRESÍA" << endl;
                    break;
                case 0:
                    cout << "VOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 0:
                cout << "VOLVER AL MENU PRINCIPAL" << endl;
                break;
            }


            break;
        case 0:
            system("cls");
            cout << "Gracias por usar ProCinema!" << endl << endl;
            exit(1);
            break;
        }
        system("pause");
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
