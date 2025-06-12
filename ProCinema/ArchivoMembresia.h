#pragma once
#include <string>
#include "Membresia.h"

class ArchivoMembresia{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoMembresia(std::string nombreArchivo);
        bool Guardar(Membresia membresia);
        bool Modificar(Membresia membresia, int posicion);
        int Buscar(int IdMembresia);
        int CantidadRegistros();
        Membresia Leer(int posicion);
        int getUltimoId();
        // Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
        // void Leer(int cantidadRegistros, Membresia *vector);
};
