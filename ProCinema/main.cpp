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
    menu.menuPrincipal();
    return 0;
}
