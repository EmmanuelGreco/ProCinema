#pragma once
#include "Funcion.h"

class ManagerFuncion {
public:
    void cargarFuncion();
    void listarFunciones();
    void listarFuncionesActivas(bool activas);
    void listarFuncionesAgotadas();
    void listarFuncionesImprimir(Funcion funcion);
    void modificarFuncion();
    void cambiarEstadoFuncion();

    void buscarPorId();
    void buscarPorTituloPelicula();
    void buscarPorNumeroSala();
    void buscarPorFechaFuncion();
};
