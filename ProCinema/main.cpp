#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include "Menu.h"

#define color SetConsoleTextAttribute

using namespace std;

int main() {
    Menu menu;
    setlocale(LC_ALL, "Spanish");
    SetConsoleTitle("ProCinema - EQUIPO 13");           // Nombre de la consola
    system("color 0c");                                 // Color consola y letras
    menu.menuBienvendidaImprimir();
    system("pause");

    while(true) {
        menu.principal();
        switch(menu.getOpcion()) {
        case 1:
            menu.menuVentas();
            break;
        case 2:
            menu.menuPeliculas();
            break;
        case 3:
            menu.menuFunciones();
            break;
        case 4:
            menu.menuMembresia();
            break;
        case 5:
            menu.menuInformes();
            break;
        case 6:
            menu.menuConfiguracion();
            break;
        case 7:
            menu.menuCreditos();
            break;
        case 0:
            system("cls");
            cout << "Gracias por usar ProCinema!" << endl << endl;
            return 0;
            break;
        }
        cout << endl;
        system("cls");
    }
    return 0;
}
