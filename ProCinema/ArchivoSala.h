#pragma once
#include <string>
#include "Sala.h"

class ArchivoSala{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoSala(std::string nombreArchivo);
        bool Guardar(Sala sala);
        bool Modificar(Sala sala, int posicion);
        int Buscar(int IdSala);
        int CantidadRegistros();
        Sala Leer(int posicion);
        int getUltimoId();
        // Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
        //void Leer(int cantidadRegistros, Pelicula *vector);
};
