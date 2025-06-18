#pragma once
#include <string>
#include "Funcion.h"

class ArchivoFuncion{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoFuncion(std::string nombreArchivo);
        bool Guardar(Funcion funcion);
        bool Modificar(Funcion funcion, int posicion);
        int Buscar(int IdFuncion);
        int CantidadRegistros();
        Funcion Leer(int posicion);
        int getUltimoId();
        // Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
        // void Leer(int cantidadRegistros, Funcion *vector);
};
