#pragma once
#include <string>
#include "Pelicula.h"

class Archivos{
    private:
        std::string _nombreArchivo;

    public:
        Archivos(std::string nombreArchivo);
        bool Guardar(Pelicula pelicula);
        bool Guardar(Pelicula pelicula, int posicion);
        int Buscar(int IdPelicula);
        Pelicula Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Pelicula *vector);
};
