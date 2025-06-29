#pragma once
#include "Funcion.h"

class ManagerFuncion {
public:
    void cargarFuncion();
    void listarFunciones();
    void listarFunciones(bool activas);
    void listarFuncionesAgotadas();
    //void listarFuncionesImprimir(Funcion funcion);
    void modificarFuncion();
    void cambiarEstadoFuncion();

    void buscarPorId();
    void buscarPorTituloPelicula();
    void buscarPorNumeroSala();
    void buscarPorFechaFuncion();

    bool validarNumero(int input, int minimo, int maximo);
    bool validarNumero(int input, int minimo);
};
