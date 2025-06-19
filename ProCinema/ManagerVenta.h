#pragma once


class ManagerVenta {
public:
    void cargarVenta();
    void listarVentas();
    void modificarVenta();
    void cambiarEstadoVenta();
    int calcularImporteTotal(int cantidadEntradas, int idFuncion, int idMembresia);
};
