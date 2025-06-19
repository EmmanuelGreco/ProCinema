#pragma once
#include <string>
#include "Venta.h"

class ArchivoVenta{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoVenta(std::string nombreArchivo);
        bool Guardar(Venta venta);
        bool Modificar(Venta venta, int posicion);
        int Buscar(int IdVenta);
        int CantidadRegistros();
        Venta Leer(int posicion);
        int getUltimoId();
};
