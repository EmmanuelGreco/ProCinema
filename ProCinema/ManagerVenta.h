#pragma once


class ManagerVenta {
public:
    void cargarVenta();
    void listarVentas();
    void modificarVenta();
    void cambiarEstadoVenta();
    float calcularImporteTotal(int cantidadEntradas, int idFuncion, int idMembresia);

    void buscarPorId();
    void buscarPorFuncion();
    void buscarPorDNI();
    void buscarPorMiembro();
    void buscarPorFecha();

    bool validarNumero(int input, int minimo);
};
