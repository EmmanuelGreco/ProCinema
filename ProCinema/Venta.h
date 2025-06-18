#pragma once
#include <string>
#include "Fecha.h"

class Venta {
    private:
        int _idVenta;
        int _idFuncion;
        int _idMembresia;
        int _cantidadEntradas;
        Fecha _fechaVenta;
        float _importeTotal;
        bool _estado;

    public:
        Venta();
        Venta(int idVenta, int idFuncion, int idMembresia, int cantidadEntradas, Fecha fechaVenta,
                 float importeTotal, bool estado);

        int getIdVenta();
        int getIdFuncion();
        int getIdMembresia();
        int getCantidadEntradas();
        Fecha getFechaVenta();
        float getImporteTotal();
        bool getEstado();

        void setIdVenta(int idVenta);
        void setIdFuncion(int idFuncion);
        void setIdMembresia(int idMembresia);
        void setCantidadEntradas(int cantidadEntradas);
        void setFechaVenta(Fecha fechaVenta);
        void setImporteTotal(float importeTotal);
        void setEstado(bool estado);
};
