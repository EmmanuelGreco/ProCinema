#pragma once
#include <string>
#include "Pelicula.h"

class ArchivoPelicula{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoPelicula(std::string nombreArchivo);
        bool Guardar(Pelicula pelicula);
        bool Modificar(Pelicula pelicula, int posicion);
        int Buscar(int IdPelicula);
        int CantidadRegistros();
        Pelicula Leer(int posicion);
        int getUltimoId();
        // Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
        // void Leer(int cantidadRegistros, Pelicula *vector);
};
